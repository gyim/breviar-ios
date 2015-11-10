#!/bin/bash
# Builds the Breviary app in all languages.

set -e

if [[ -z $1 ]]
then
	echo "Usage: build.sh <version>"
	exit 1
fi

version=$1

./buildno.sh

time (
	for lang in cs hu sk; do
		rm -rf build/Breviar-$lang-$version.xcarchive build/Breviar-$lang-$version.ipa
		xcrun xcodebuild -workspace Breviar.xcworkspace -scheme "Breviar-$lang" -configuration "Release-$lang" clean
		xcrun xcodebuild -workspace Breviar.xcworkspace -scheme "Breviar-$lang" -configuration "Release-$lang" archive -archivePath build/Breviar-$lang-$version
		xcrun xcodebuild -exportArchive -exportOptionsPlist adhoc-export.plist -archivePath "build/Breviar-$lang-$version.xcarchive" -exportPath build
		mv build/Breviar-$lang.ipa build/Breviar-$lang-$version.ipa
	done
)
