# QR prayer sharing (iOS)

The prayer reader's QR button creates a black-on-white QR code on-device using
Core Image, with a four-module quiet zone and no interpolation. The same sheet
provides Copy link and the native iOS share menu, anchored to the tapped button
on iPad. No camera permission, QR service or URL shortener is needed. Scanning
is done by the system Camera (or another scanner), which opens the HTTPS link.

## Link and renderer contract

The public format is `https://breviar.sk/cgi-bin/l.cgi?...`, compatible with
Android and browsers. Only that exact host/path is accepted for incoming public
links. Credentials, ports, unsupported query types, invalid accepted values and
queries of 2000 bytes or more are rejected. Only parameters the recipient uses
are checked for duplicate/invalid values. Generated links always include prayer
selection, language, calendar, Commons and all reader options, including fonts,
font size/weight, day/night mode, both palettes, margins and line spacing. There
is no format marker yet. Native device preferences, UI language, network policy
and pinch zoom are never shared.

**Settings → Prayer screen settings → Apply appearance from shared prayers** is
off by default. With it off, incoming links import only content options. With it
on, visual options are accepted as well. Unused visual values are discarded
before value validation and before the CGI request is built. Missing settings
retain current values. The content masks for words 0 and 2 match Android's
`PrayerLink`; update both clients together when those words gain content flags.
The preference is captured when opening each link; changing it does not alter
the current reader, its reloads/TTS, or the scope of Restore.

The native font, scale, bold setting and actual light/dark appearance are
included when sharing, even if changed since the last render. iOS font scale
maps to CGI point size using the 16 pt body size from `breviar.css`; outgoing
point sizes round to whole points, as required by the CGI format. Local font
resolution accepts the existing native choices, installed fonts/families and
CSS generic families. Unavailable fonts leave the current font unchanged; font
files and sender CSS are never downloaded. This uses UIKit font metadata, not
font-file enumeration/parsing. Palettes/spacing without native controls are
stored and rendered, so Keep and subsequent sharing retain them. Native
fullscreen, playback and network controls continue to use local preferences.

Sharing requires the core renderer's hidden metadata element:

```html
<span id="breviar-request" hidden
      data-query="qt=pdt&amp;d=13&amp;m=11&amp;r=2026&amp;p=mrch&amp;j=sk&amp;..."></span>
```

The query must contain the backend-resolved selection and effective option
words. Dated prayers must have explicit dates, and `qt=plo` must carry `r=`.
Daily overviews (`qt=pdnes` without `p=`) remain relative to today. The client
never substitutes the phone's date or reconstructs options from an older URL.
An old backend without metadata cannot create a QR code. Incoming links can
still be read; Keep remains disabled until a resolved response is available.

The marker lives in the HTML body and survives the existing `getHTMLBody`
extraction. No new C++/Objective-C bridge API is needed. Bundle the current
`breviar.css`, `breviar-invert-colors.css`, `breviar-normal-font.css` and
`breviar-rounded-corners.css` from the
updated core; custom palettes require their `--prayer-*` CSS variables. This patch deliberately
does **not** change the `breviar-cgi` submodule pin or any shared C++ files: the
backend date/metadata fixes are being integrated separately. When updating that
submodule, also register all translation units required by its current iOS
build instructions; this repository's older C++ source list is not updated by
this frontend patch.

## Temporary reader

Incoming links open a separate, offline-by-default reader which reuses the
existing prayer WebView, text controls and TTS. Explicit Retry from server still
uses the existing network retry path. A dedicated `sharedPrayer.session`
defaults dictionary persists the accepted temporary query, including subsequent
inline prayer choices, across app restarts. Personal content settings are
untouched until **Keep these settings** is chosen. Appearance imports use the
native text options, backed up once at the start of the session. Subsequent
links never replace that original snapshot. The CGI celebration field `ds`
never overwrites iOS's unrelated `ds` data-source preference.

The ellipsis menu offers Restore, Keep and Back. Back hides the shared reader
without ending the temporary session; its controls remain on the main screen.
Restore closes the session and returns to the underlying reader in a running
app, or to the user's own main screen after a cold start. In content-only
sessions, local appearance edits survive Restore. If any link imported
appearance, Restore instead restores the original font, size, weight, scheme
(including Automatic) and palettes/spacing, even after a restart or after the
import preference was turned off. Keep adopts resolved accepted content and
appearance and clears the backup. Both actions leave native device settings
and pinch zoom alone. Subsequent inline content choices in the kept reader are also
saved; if a later choice is unsupported it becomes temporary again. A language
or calendar that the native settings model does not support can still be read
if available in the bundled CGI (or through Retry from server), but cannot be
kept. It never corrupts the saved configuration or substitutes another calendar.

The app uses one root presentation slot for initial setup and the shared reader,
so a link received on first launch does not stack two full-screen covers. The
existing `breviar://today/...` and dated custom URLs remain supported.

## Universal Links: deployment needed

The app entitlement adds `applinks:breviar.sk`. In Xcode enable Associated
Domains for the app ID and update provisioning/signing as needed. Publish
`https://breviar.sk/.well-known/apple-app-site-association` as JSON with HTTP 200,
valid HTTPS, no authentication and **no redirects**:

```json
{
  "applinks": {
    "details": [{
      "appIDs": ["REPLACE_WITH_ACTUAL_APPLICATION_IDENTIFIER"],
      "components": [{"/": "/cgi-bin/l.cgi"}]
    }]
  }
}
```

Obtain the identifier from the signed app's `application-identifier` entitlement
(`codesign -d --entitlements :- /path/to/Breviar.app`). It is the actual App ID
prefix plus bundle ID, not an assumed Team ID; include every distributed app
variant that should accept the links. Merge with any existing association file.
Install a newly provisioned build, then tap a link in Notes/Messages or scan a QR;
typing a URL into Safari's address bar is not a Universal Links test. Apple's
association CDN may cache changes.

References:
- https://developer.apple.com/documentation/xcode/supporting-associated-domains
- https://developer.apple.com/documentation/coreimage/cifilter-swift.class/qrcodegenerator()

## Verification

`Tools/PrayerSharingTests/run.sh` compiles/runs the Foundation-only URL and
session checks with `swiftc` (Linux or macOS; set `SWIFTC` if needed). It covers
canonical metadata, full outgoing appearance, both import policies, fixed/relative
dates, masks and UInt64 values, ignored/invalid visual parameters, local font
fallback, native scale/weight/theme mapping, palette CSS, partial inline
navigation, session recreation, repeated links, restoration after preference
changes, and keeping content without overwriting the `ds` preference. The Xcode project
registers all new Swift sources in the app target, not the widget target.

From the repository root:

```sh
Tools/PrayerSharingTests/run.sh
swift Tools/PrayerSharingTests/validate-project.swift
```

The portable tests and Swift syntax parsing have been run on Linux. They do not
replace an Xcode type-check/build or exercise UIKit, SwiftUI presentation, Core
Image rendering or the installed app's Universal Links. An Apple SDK/device
build is still required. Check on iPhone and iPad:

1. Build with the updated CGI and signing profile. Show QR in light/dark mode,
   scan in both directions between Android and iOS, copy and share the URL.
2. A dated prayer still opens on its original date; a daily overview stays today.
   Check Christmas `qt=plo`, a Commons choice and Ordinarium `qt=pst&st=2`.
3. Receive a link while running, while another shared reader is open, after force
   quit and on first launch with no configured data source. Also receive a link
   with text options, TTS, the date picker or the share sheet open. Existing custom URL
   schemes must still navigate normally.
4. With appearance import off, receive a link with a different font, bold flag,
   night mode and palettes. Personal appearance must remain unchanged, including
   local text-option edits after Restore. Repeat with import on: the sender's
   appearance must display, and Keep must retain it in ordinary prayers and QR
   links. Test an unavailable font and a family containing spaces.
5. Import full appearance, hide with Back, change the import preference and
   receive another content-only link. Restart before Restore: it must restore the
   first appearance snapshot, including Automatic mode. Repeat with Keep. UI
   language, network policy, fullscreen gesture, TTS preferences and zoom stay
   local. Test palette colors on text, rubrics and generated R/V markers.
6. Follow prayer links/options, use TTS, change font/size/theme while reading,
   hide with Back and resume. Switching theme must select the matching palette
   immediately, without requiring a CGI reload. Unsupported Keep must not change
   personal content settings.
7. Rapidly receive two different links while a local/remote load is pending;
   only the last shared request may update the reader.
