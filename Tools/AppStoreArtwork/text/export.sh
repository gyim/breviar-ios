#!/bin/bash
# Exports the App Store copy into <artwork-dir>/<version>/text, one file per
# App Store Connect field and locale, see README.md.
#
#   Tools/AppStoreArtwork/text/export.sh <artwork-dir>/<version> [file.md ...]
if [ -z "$1" ]; then
  echo "usage: $0 <artwork-dir>/<version> [file.md ...]"
  exit 1
fi
exec python3 "$(dirname "$0")/store_text.py" export "$@"
