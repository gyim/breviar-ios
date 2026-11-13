#!/bin/sh
set -eu
script_dir=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
repo_dir=$(CDPATH= cd -- "$script_dir/../.." && pwd)
output_dir=$(mktemp -d)
trap 'rm -rf "$output_dir"' EXIT HUP INT TERM
"${SWIFTC:-swiftc}" -swift-version 5 \
    "$repo_dir/Breviar/Model/Sharing/SharedPrayerLink.swift" \
    "$repo_dir/Breviar/Model/Sharing/ReaderAppearance.swift" \
    "$repo_dir/Breviar/Model/Sharing/SharedPrayerSession.swift" \
    "$script_dir/main.swift" -o "$output_dir/sharing-tests"
"$output_dir/sharing-tests"
