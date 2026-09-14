#!/bin/bash
# Builds the app for the simulator and captures the raw screenshots, see README.md.
#
#   Tools/AppStoreArtwork/capture.sh <artwork-dir>/<version> [--skip-build] [capture.py options]
#
# The app is built once (Debug, iOS Simulator) into $TMPDIR/breviar-appstore-artwork
# and installed on the screenshot simulators by capture.py. Pass --skip-build to
# reuse the last build. Further options (--devices, --locales, --only, --keep-app)
# are documented in capture.py.
set -eo pipefail
cd "$(dirname "$0")/../.."

TOOL=Tools/AppStoreArtwork
BUILD=${TMPDIR:-/tmp}/breviar-appstore-artwork
OUT=$1
shift
if [ -z "$OUT" ]; then
  echo "usage: $0 <artwork-dir>/<version> [--skip-build] [capture.py options]"
  exit 1
fi

SKIP_BUILD=0
if [ "$1" = "--skip-build" ]; then
  SKIP_BUILD=1
  shift
fi

APP="$BUILD/DerivedData/Build/Products/Debug-iphonesimulator/Breviar.app"
if [ "$SKIP_BUILD" = 0 ] || [ ! -d "$APP" ]; then
  xcodebuild -project Breviar.xcodeproj -scheme Breviar -configuration Debug \
    -destination 'generic/platform=iOS Simulator' -derivedDataPath "$BUILD/DerivedData" \
    -quiet build
fi

python3 "$TOOL/capture.py" "$TOOL/shots.json" "$OUT" --app "$APP" "$@"
