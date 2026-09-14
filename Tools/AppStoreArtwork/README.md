# AppStoreArtwork

Produces the App Store screenshots and the store copy for a release: real
simulator screenshots of the app, composed with captions and device frames
into the sizes App Store Connect wants, for every locale and device.

```sh
ART=~/Projects/Breviar/appstore-artwork/v2.2        # any directory; never hard-coded

Tools/AppStoreArtwork/capture.sh "$ART"              # 1. build the app, capture raw screenshots (~1 min per locale and device)
Tools/AppStoreArtwork/widgets.sh "$ART"              # 2. render the widgets for the widget shot (~10 s)
Tools/AppStoreArtwork/compose.sh "$ART" --contact-sheet   # 3. compose the final images (~10 s)
Tools/AppStoreArtwork/text/export.sh "$ART"          # 4. check the store copy and export it per field and locale
```

Output:

- `$ART/iphone-6.9/<locale>/NN-<shot>.png` — 1320×2868, and `$ART/ipad-13/<locale>/…` — 2064×2752; upload these to App Store Connect, one folder per locale (`en-US`, `sk`, `cs`, `hu`), in file name order
- `$ART/contact-<device>-<locale>.png` — all shots of one set side by side, for review
- `$ART/raw/` — the captures and widget renders the images are made from; `$ART/logs/`, `$ART/manifest.json` — what was captured with which launch arguments
- `$ART/text/<locale>/NN-<field>.txt` — name, subtitle, promotional text, description, keywords and What's New, one file per App Store Connect field, ready to paste; the editable sources are `Tools/AppStoreArtwork/text/<locale>.md`

Useful options: `--devices iphone-6.9`, `--locales en-US,hu`, `--only 02-prayer` work on
all three scripts; `capture.sh` also takes `--skip-build` (reuse the last build) and
`--keep-app` (do not reinstall). Shots that were not captured are skipped with a warning,
so partial runs are fine.

## Prerequisites

- Xcode with an iOS 26 simulator runtime. The screenshot simulators (`Breviar-ShotsPhone`,
  an iPhone 17 Pro Max, and `Breviar-ShotsPad`, an iPad Pro 13-inch) are created on the
  newest installed runtime the first time; no extra runtime download is needed.
- `python3` (no packages), `xcrun`, `swiftc` — all part of Xcode / macOS.
- Optional: Apple's device bezels. Download the Product Bezels from
  https://developer.apple.com/design/resources/ and put the PNGs as
  `$ART/../_bezels/iphone-17-pro-max.png` and `ipad-pro-13.png` (the names are set in
  `shots.json`). The compositor finds the screen cutout from the alpha channel. Without
  them a plain black frame is drawn. The bezels are not committed: Apple's license allows
  their use in marketing, not redistribution.

## How it works

`shots.json` is the storyboard. It lists the devices (canvas size, type sizes, margins,
bezel name, simulator), the locales (launch arguments that select the breviary and UI
language, the widget scenario) and the shots. A shot has a layout, a caption per locale
and one or more *captures*, each described by the launch arguments, the `breviar://` URL
to navigate to and the actions to perform. The English set uses Latin texts with the
English UI, the native sets use their own language throughout.

**Capture** (`capture.py`, driven by `capture.sh`). The app is built once (Debug, the
hook below is compiled only in debug builds) and installed on the simulator. For every
capture the app is launched with `-key value` launch arguments, which iOS puts into
`UserDefaults` in front of the app's own settings: `j`, `ui_lang`, `k`, `ds` select the
language, calendar and data source (this also skips the first-launch wizard),
`colorScheme`, `textOptions.*` and `prayerScreenSettings.fullscreenMode` preset the text
options, `screenshotMode 1` enables the hook, `screenshotURL` and `screenshotActions`
tell it what to show. The script then waits for `SCREENSHOT_READY done` in
`Documents/screenshot-ready.log` of the app container and takes the screenshot with
`simctl io screenshot`. Appearance (`simctl ui … appearance`) and the status bar
(`simctl status_bar`, 9:41, full signal and battery) are set by the script.

**The hook** (`Breviar/View/Util/ScreenshotMode.swift`, `#if DEBUG`). Once the first day has
loaded, `ScreenshotMode.Runner` navigates to the URL through the app's normal URL
handling, waits until the day or the prayer text is loaded, then dispatches the actions
one by one as notifications. The screens observe them with `.onScreenshotAction` and flip
their own state: `textOptions`, `playback` (the sheet shows a fixed 35 % progress instead
of speaking), `fullscreen`, `datePicker`, `settings`, `settingsFlagSet[:n]` (the n-th flag
set entry of the settings screen) and `scroll:<0…1>` (the prayer web view). Every step
reports back; a step that does not is skipped after a timeout, so a capture cannot hang.
In screenshot mode the main screen title always shows the full date instead of
"Monday (Today)", so the result does not depend on the day the script runs.

**Widgets** (`widgets.sh`). The widget shot does not use screenshots: `Tools/WidgetRender`
renders the real widget views from `widget-scenarios.json` (one scenario per locale, real
calendar data for a week with several celebrations and colours) at the 6.9" widget sizes,
and the compositor places them on a plain wallpaper inside the device frame.

**Compose** (`Compositor/`, built by `compose.sh`). A macOS command line tool using SwiftUI
and `ImageRenderer`: each shot is laid out in pixel units on the canvas and written as an
opaque PNG. Layout types: `single`, `singleChips` (a row of language chips under the
caption), `splitLightDark` (left half of one capture, right half of another),
`twoOffset` (two devices), `hero` (a staircase of celebration cards cropped from main
screen captures, plus a device rising from the bottom edge) and `widgetHome`. Captures
with `"cropMode": "celebrationCard"` are cropped automatically to the white card below the
title. Output sizes are checked; a mismatch is reported as a warning.

## Changing things

- **Captions**: edit `caption.<locale>` in `shots.json`; `\n` breaks the title line.
  Titles are limited to two lines and shrink a little if needed. Then run `compose.sh`.
- **A different day, prayer or state**: edit the capture's `url` and `actions`, run
  `capture.sh … --skip-build --keep-app --only <shot>`, then `compose.sh`.
- **A new shot**: add an entry to `shots`; use an existing layout type or add one in
  `Compositor/Layouts.swift` and the `switch` in `Compositor/main.swift`. Raw captures are
  named `<shot>.<role>.png`, so any layout can refer to its captures by role.
- **A new action**: add a case to `ScreenshotMode.Action`, parse it in
  `ScreenshotMode.action(from:)` and handle it in the screen that owns the state.
- **The hero**: `01-hero` (celebration cards in five languages) and `01b-hero-chips`
  (one phone, language chips) are two variants of the first screenshot; delete the one
  that is not used before uploading.
- **Widget data**: `widget-scenarios.json` was generated from the CGI (see
  `Tools/WidgetRender/README.md` for the format). The keys are referenced as
  `widgetScenario` in the locales of `shots.json`.
- **Store copy**: `text/<locale>.md`, one `## Field (limit)` section per App Store Connect
  field in the fixed order name, subtitle, promotional text, description, keywords, What's
  New. `text/check.sh` fails if a section is over its limit; `text/export.sh <artdir>`
  checks and writes the fields into `<artdir>/text/`.
- **Locales and search**: App Store search indexes name, subtitle, keywords and category
  only, per storefront: Slovakia, Czechia and Hungary index the local language *and*
  English (U.K.), Iceland indexes English (U.K.) only, and the primary localization
  (English (US)) is indexed everywhere as a fallback. Hence five text sets: the native
  ones carry the plain native app names (`Breviár`, `Breviář`, `Zsolozsma`, which are
  free on the store), `en-GB` shows and indexes those names in its subtitle for English
  phones in those countries, and `en-US` keeps the native names in its keywords for
  everyone else. `en-GB` has no screenshots of its own: upload the `en-US` images.

## Things learned the hard way

- `simctl openurl` is useless for automation on iOS 26: it shows an "Open in Breviary?"
  confirmation for every custom URL, even with the app in the foreground, and the alert
  stays on screen across launches (reboot the simulator to get rid of it). Navigation is
  therefore passed as launch arguments and performed inside the app.
- stderr redirected with `simctl launch --stderr=` is only flushed when the process
  exits; live progress has to go through a file in the app container.
- `simctl io <udid> screenshot -` writes a file literally named `-`; always pass a path.
- Never launch with `-j en`: English is a UI language only and has no calendar.
- `simctl status_bar --time` wants a plain `9:41`; the ISO form is rejected on this Xcode.
- The status bar override must use `--batteryState discharging`, otherwise a charging
  bolt is shown.
