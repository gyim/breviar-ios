#!/usr/bin/env python3
"""Checks and exports the App Store copy kept in text/<locale>.md, see README.md.

    store_text.py check [file.md ...]
    store_text.py export <artwork-dir>/<version> [file.md ...]

A text file has one "## Heading (limit)" section per App Store Connect field, in
the fixed order name, subtitle, promotional text, description, keywords and
What's New. `check` measures every section against its limit; `export` writes
each section as <artwork-dir>/<version>/text/<locale>/NN-<field>.txt (ready to
paste into App Store Connect) and copies the Markdown source next to them.
"""
import glob
import os
import re
import shutil
import sys

FIELDS = ["name", "subtitle", "promotional-text", "description", "keywords", "whats-new"]


def sections(path):
    text = open(path, encoding="utf-8").read()
    result = []
    for section in re.split(r"^## ", text, flags=re.M)[1:]:
        heading, _, body = section.partition("\n")
        match = re.search(r"\((\d+)\)\s*$", heading)
        if match:
            result.append((heading.strip(), int(match.group(1)), body.strip()))
    return result


def check(files):
    status = 0
    for path in files:
        print(path)
        for heading, limit, body in sections(path):
            over = len(body) > limit
            status |= over
            print(f"  {'OVER' if over else 'ok '} {len(body):5d}/{limit:<5d} {heading}")
    return status


def export(outdir, files):
    status = check(files)
    if status:
        print("not exported: some fields are over their limit", file=sys.stderr)
        return status
    root = os.path.join(os.path.abspath(os.path.expanduser(outdir)), "text")
    for path in files:
        locale = os.path.splitext(os.path.basename(path))[0]
        target = os.path.join(root, locale)
        os.makedirs(target, exist_ok=True)
        parts = sections(path)
        if len(parts) != len(FIELDS):
            print(f"{path}: expected {len(FIELDS)} fields, found {len(parts)}", file=sys.stderr)
            return 1
        for index, (field, (_, _, body)) in enumerate(zip(FIELDS, parts), start=1):
            with open(os.path.join(target, f"{index:02d}-{field}.txt"), "w", encoding="utf-8") as f:
                f.write(body + "\n")
        shutil.copy(path, os.path.join(root, os.path.basename(path)))
    with open(os.path.join(root, "README.txt"), "w", encoding="utf-8") as f:
        f.write("App Store Connect copy, one folder per locale.\n"
                "Paste each NN-<field>.txt into the field of the same name; the limits are\n"
                "name 30, subtitle 30, promotional text 170, description 4000, keywords 100,\n"
                "What's New 4000 characters. The <locale>.md files are the editable sources\n"
                "(Tools/AppStoreArtwork/text in the repository).\n")
    print(f"exported {len(files)} locales to {root}")
    return 0


def main():
    here = os.path.dirname(os.path.abspath(__file__))
    args = sys.argv[1:]
    if not args or args[0] not in ("check", "export"):
        print(__doc__)
        sys.exit(2)
    command = args.pop(0)
    outdir = args.pop(0) if command == "export" and args and not args[0].endswith(".md") else None
    if command == "export" and outdir is None:
        print("export needs <artwork-dir>/<version>", file=sys.stderr)
        sys.exit(2)
    files = args or sorted(glob.glob(os.path.join(here, "*.md")))
    sys.exit(check(files) if command == "check" else export(outdir, files))


if __name__ == "__main__":
    main()
