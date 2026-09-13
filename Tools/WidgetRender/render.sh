#!/bin/bash
# Renders the home screen widgets to PNG files without building the app.
#
# The widget views are compiled for the simulator SDK together with the model
# files they depend on, and the resulting binary runs inside the booted
# simulator, where ImageRenderer draws the views with the real iOS fonts.
# A full run takes about ten seconds.
#
#   Tools/WidgetRender/render.sh [scenarios.json] [renderer options]
#
# Renderer options are documented in main.swift (--families, --schemes, --only).
# Environment: SIM (simulator UDID, default: the booted one), OUT (output dir).
set -e
cd "$(dirname "$0")/../.."

TOOL=Tools/WidgetRender
BUILD=${TMPDIR:-/tmp}/breviar-widget-render
OUT=${OUT:-$BUILD/out}
SDK=$(xcrun --sdk iphonesimulator --show-sdk-path)

if [ -z "$SIM" ]; then
  SIM=$(xcrun simctl list devices booted -j | python3 -c \
    'import json,sys; print(next(d["udid"] for ds in json.load(sys.stdin)["devices"].values() for d in ds if d["state"] == "Booted"))')
fi

SCENARIOS=$TOOL/scenarios.json
if [ $# -gt 0 ] && [ "${1#--}" = "$1" ]; then
  SCENARIOS=$1
  shift
fi

# the spawned process does not inherit our working directory
mkdir -p "$BUILD" "$OUT"
SCENARIOS=$(cd "$(dirname "$SCENARIOS")" && pwd)/$(basename "$SCENARIOS")
OUT=$(cd "$OUT" && pwd)
xcrun swiftc -sdk "$SDK" -target arm64-apple-ios16.0-simulator -swift-version 5 -Onone \
  -module-name BreviarWidgetRender -o "$BUILD/render" \
  Breviar/Model/Calendar.swift \
  Breviar/Model/Language.swift \
  Breviar/Localization/Strings.swift \
  Breviar/View/Util/Constants.swift \
  Breviar/Model/SharedConstants.swift \
  Breviar/Model/WidgetDataModels.swift \
  BreviarWidget/WidgetDataReader.swift \
  BreviarWidget/BreviarWidget.swift \
  "$TOOL/main.swift"

xcrun simctl spawn "$SIM" "$BUILD/render" "$SCENARIOS" "$OUT" "$@"
