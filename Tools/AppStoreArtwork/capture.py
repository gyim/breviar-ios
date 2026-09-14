#!/usr/bin/env python3
"""Captures the raw simulator screenshots described in shots.json, see README.md.

    capture.py <shots.json> <artwork-dir>/<version> --app <Breviar.app>
               [--devices a,b] [--locales a,b] [--only id1,id2] [--keep-app]

For every device x locale x shot x capture the app is launched with the merged
launch arguments (defaults, locale, capture) plus the capture's URL and actions
(-screenshotURL, -screenshotActions), which ScreenshotMode.swift executes inside
the app. The script waits for the `SCREENSHOT_READY done` line in
Documents/screenshot-ready.log of the app container and then photographs the
simulator with `simctl io screenshot`.

Output: <artwork-dir>/<version>/raw/<device>/<locale>/<shot>.<role>.png,
logs in <artwork-dir>/<version>/logs, and a manifest.json next to raw/.
"""
import argparse
import json
import os
import subprocess
import sys
import time

BUNDLE_ID = "sk.breviar.breviar-sk"
READY_TIMEOUT = 60


def simctl(*args, check=True):
    return subprocess.run(["xcrun", "simctl", *args], check=check, capture_output=True, text=True)


def find_device(name):
    data = json.loads(simctl("list", "devices", "-j").stdout)
    for devices in data["devices"].values():
        for device in devices:
            if device["name"] == name and device.get("isAvailable", True):
                return device["udid"], device["state"]
    return None, None


def newest_ios_runtime():
    data = json.loads(simctl("list", "runtimes", "-j").stdout)
    runtimes = [r for r in data["runtimes"] if r["platform"] == "iOS" and r.get("isAvailable", True)]
    runtimes.sort(key=lambda r: [int(x) for x in r["version"].split(".")])
    return runtimes[-1]["identifier"]


def ensure_device(spec):
    """Finds or creates the simulator named in the device spec and boots it."""
    udid, state = find_device(spec["simName"])
    if udid is None:
        udid = simctl("create", spec["simName"], spec["simDeviceType"], newest_ios_runtime()).stdout.strip()
        state = "Shutdown"
        print(f"created simulator {spec['simName']} ({udid})")
    if state != "Booted":
        simctl("boot", udid)
    simctl("bootstatus", udid, "-b")
    return udid


def set_status_bar(udid):
    simctl("status_bar", udid, "override", "--time", "9:41",
           "--dataNetwork", "wifi", "--wifiMode", "active", "--wifiBars", "3",
           "--cellularMode", "active", "--cellularBars", "4", "--operatorName", "",
           "--batteryState", "discharging", "--batteryLevel", "100")


def ready_file(udid):
    container = simctl("get_app_container", udid, BUNDLE_ID, "data").stdout.strip()
    return os.path.join(container, "Documents", "screenshot-ready.log")


def wait_for_done(path, timeout):
    deadline = time.time() + timeout
    while time.time() < deadline:
        if os.path.exists(path):
            with open(path, errors="replace") as f:
                if "SCREENSHOT_READY done" in f.read():
                    return
        time.sleep(0.2)
    reached = open(path).read().strip().replace("\n", ", ") if os.path.exists(path) else "nothing"
    raise TimeoutError(f"app did not report done within {timeout}s (reached: {reached})")


def merged_launch_args(*sources):
    args = {}
    for source in sources:
        args.update(source or {})
    return args


def capture(udid, ready_path, device_id, locale_id, locale, shot, role, spec, defaults, raw_dir, log_dir):
    args = merged_launch_args(defaults.get("launchArgs"), locale.get("launchArgs"), spec.get("launchArgs"))
    if spec.get("url"):
        args["screenshotURL"] = spec["url"]
    if spec.get("actions"):
        args["screenshotActions"] = ",".join(spec["actions"])
    appearance = spec.get("appearance", "light")
    log = os.path.join(log_dir, f"{device_id}-{locale_id}-{shot['id']}.{role}.log")
    for path in (log, ready_path):
        if os.path.exists(path):
            os.remove(path)

    simctl("terminate", udid, BUNDLE_ID, check=False)
    simctl("ui", udid, "appearance", appearance)
    launch = ["launch", "--terminate-running-process", f"--stderr={log}", udid, BUNDLE_ID]
    for key, value in args.items():
        launch += [f"-{key}", str(value)]
    simctl(*launch)
    wait_for_done(ready_path, READY_TIMEOUT)

    time.sleep(defaults.get("settleSeconds", 1.0))
    out = os.path.join(raw_dir, device_id, locale_id, f"{shot['id']}.{role}.png")
    os.makedirs(os.path.dirname(out), exist_ok=True)
    simctl("io", udid, "screenshot", "--type=png", "--mask=ignored", out)
    return out, args


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("script")
    parser.add_argument("outdir")
    parser.add_argument("--app", help="Breviar.app built for the simulator; installed on every device")
    parser.add_argument("--devices")
    parser.add_argument("--locales")
    parser.add_argument("--only", help="comma separated shot ids")
    parser.add_argument("--keep-app", action="store_true", help="do not reinstall the app")
    options = parser.parse_args()

    with open(options.script) as f:
        script = json.load(f)
    outdir = os.path.abspath(os.path.expanduser(options.outdir))
    raw_dir = os.path.join(outdir, "raw")
    log_dir = os.path.join(outdir, "logs")
    os.makedirs(log_dir, exist_ok=True)
    defaults = script.get("defaults", {})

    device_ids = options.devices.split(",") if options.devices else sorted(script["devices"])
    locale_ids = options.locales.split(",") if options.locales else sorted(script["locales"])
    shots = [s for s in script["shots"] if not options.only or s["id"] in options.only.split(",")]

    manifest = []
    failures = []
    for device_id in device_ids:
        device = script["devices"][device_id]
        udid = ensure_device(device)
        if options.app and not options.keep_app:
            simctl("uninstall", udid, BUNDLE_ID, check=False)
            simctl("install", udid, options.app)
            print(f"installed {options.app} on {device['simName']}")
        set_status_bar(udid)
        ready_path = ready_file(udid)
        for locale_id in locale_ids:
            locale = script["locales"][locale_id]
            for shot in shots:
                for role, spec in (shot.get("captures") or {}).items():
                    label = f"{device_id}/{locale_id}/{shot['id']}.{role}"
                    try:
                        out, args = capture(udid, ready_path, device_id, locale_id, locale, shot, role, spec, defaults, raw_dir, log_dir)
                        print(f"captured {label}")
                        manifest.append({"device": device_id, "locale": locale_id, "shot": shot["id"], "role": role,
                                         "file": os.path.relpath(out, outdir), "launchArgs": args})
                    except (subprocess.CalledProcessError, TimeoutError) as error:
                        detail = error.stderr.strip() if isinstance(error, subprocess.CalledProcessError) else str(error)
                        print(f"FAILED {label}: {detail}", file=sys.stderr)
                        failures.append(label)
        simctl("terminate", udid, BUNDLE_ID, check=False)

    with open(os.path.join(outdir, "manifest.json"), "w") as f:
        json.dump({"capturedAt": time.strftime("%Y-%m-%dT%H:%M:%S"), "captures": manifest}, f, indent=2, ensure_ascii=False)
    print(f"{len(manifest)} captures in {raw_dir}" + (f", {len(failures)} failed" if failures else ""))
    sys.exit(1 if failures else 0)


if __name__ == "__main__":
    main()
