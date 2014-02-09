#!/bin/bash
# Builds the Breviary app in all languages.

set -e

./buildno.sh

time (
	for lang in cs hu sk; do
		xcodebuild -project Breviar.xcodeproj  -scheme "Breviar-$lang" -configuration "Breviar-$lang" clean
		xcodebuild -project Breviar.xcodeproj  -scheme "Breviar-$lang" -configuration "Breviar-$lang" archive
	done
)
