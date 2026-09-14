#!/bin/bash
# Checks the App Store text files against the character limits, see README.md.
#
#   Tools/AppStoreArtwork/text/check.sh [file.md ...]
exec python3 "$(dirname "$0")/store_text.py" check "$@"
