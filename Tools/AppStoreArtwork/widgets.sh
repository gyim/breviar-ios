#!/bin/bash
# Renders the widgets used by the widget shot into <artwork-dir>/<version>/raw/widgets,
# see README.md.
#
#   Tools/AppStoreArtwork/widgets.sh <artwork-dir>/<version> [render options]
#
# Uses Tools/WidgetRender with widget-scenarios.json (one scenario per locale, the
# keys are referenced by shots.json as widgetScenario) and the widget sizes of the
# 6.9" iPhone. A booted simulator is required (see Tools/WidgetRender/README.md).
set -eo pipefail
cd "$(dirname "$0")/../.."

TOOL=Tools/AppStoreArtwork
OUT=$1
shift
if [ -z "$OUT" ]; then
  echo "usage: $0 <artwork-dir>/<version> [render options]"
  exit 1
fi
OUT=$(python3 -c 'import os,sys; print(os.path.abspath(os.path.expanduser(sys.argv[1])))' "$OUT")
RENDER_OUT=${TMPDIR:-/tmp}/breviar-appstore-artwork/widgets

OUT="$RENDER_OUT" Tools/WidgetRender/render.sh "$TOOL/widget-scenarios.json" \
  --schemes light --sizes small=170x170,medium=364x170,large=364x382 "$@"

mkdir -p "$OUT/raw/widgets"
cp "$RENDER_OUT"/individual/*.png "$OUT/raw/widgets/"
echo "widgets: $OUT/raw/widgets"
