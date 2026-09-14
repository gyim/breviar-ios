#!/bin/bash
# Composes the final App Store images from the raw captures, see README.md.
#
#   Tools/AppStoreArtwork/compose.sh <artwork-dir>/<version> [compose options]
#
# The compositor is a macOS command line tool (SwiftUI + ImageRenderer); it is
# rebuilt only when a source file is newer than the binary. Options are
# documented in Compositor/main.swift (--raw, --bezels, --devices, --locales,
# --only, --contact-sheet).
set -e
cd "$(dirname "$0")/../.."

TOOL=Tools/AppStoreArtwork
BUILD=${TMPDIR:-/tmp}/breviar-appstore-artwork
mkdir -p "$BUILD"

if [ ! -x "$BUILD/compose" ] || [ -n "$(find "$TOOL/Compositor" -newer "$BUILD/compose" -name '*.swift')" ]; then
  xcrun swiftc -sdk "$(xcrun --sdk macosx --show-sdk-path)" -target arm64-apple-macos14.0 -swift-version 5 -O \
    -module-name BreviarArtworkCompose -o "$BUILD/compose" "$TOOL"/Compositor/*.swift
fi

"$BUILD/compose" "$TOOL/shots.json" "$@"
