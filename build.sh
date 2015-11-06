#!/bin/bash
# Builds the Breviary app in all languages.

set -e

./buildno.sh

time (
	for lang in cs hu sk; do
		rm -rf build/Breviar-$lang.xcarchive
		xctool -workspace Breviar.xcworkspace -scheme "Breviar-$lang" -configuration "Breviar-$lang" clean
		xctool -workspace Breviar.xcworkspace -scheme "Breviar-$lang" -configuration "Breviar-$lang" archive -archivePath build/Breviar-$lang
	done
)
