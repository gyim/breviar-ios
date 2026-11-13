# QR prayer sharing (iOS)

The prayer reader's QR button creates a black-on-white QR code on-device using
Core Image, with a four-module quiet zone and no interpolation. The same sheet
provides Copy link and the native iOS share menu, anchored to the tapped button
on iPad. No camera permission, QR service or URL shortener is needed. Scanning
is done by the system Camera (or another scanner), which opens the HTTPS link.

## Link and renderer contract

The public format is `https://breviar.sk/cgi-bin/l.cgi?...`, compatible with
Android and browsers. Only that exact host/path is accepted for incoming public
links. Duplicate parameters, credentials, ports, unsupported query types,
invalid option words and queries of 2000 bytes or more are rejected. Prayers,
language, calendar, Commons and content options are shared; fonts, night mode,
palettes, device preferences and app identification parameters are excluded.
The content masks for words 0 and 2 match Android's `PrayerLink`; update both
clients together when those words gain content flags.

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
extraction. No new C++/Objective-C bridge API is needed. This patch deliberately
does **not** change the `breviar-cgi` submodule pin or any shared C++ files: the
backend date/metadata fixes are being integrated separately. When updating that
submodule, also register all translation units required by its current iOS
build instructions; this repository's older C++ source list is not updated by
this frontend patch.

## Temporary reader

Incoming links open a separate, offline-by-default reader which reuses the
existing prayer WebView, text controls and TTS. Explicit Retry from server still
uses the existing network retry path. A dedicated `sharedPrayer.query` defaults
key persists the temporary query, including subsequent inline prayer choices,
across app restarts. The user's personal prayer settings are untouched until
**Keep these settings** is chosen, so there is no backup that a second link
could accidentally overwrite. The CGI celebration field `ds` never overwrites
iOS's unrelated `ds` data-source preference.

The ellipsis menu offers Restore, Keep and Back. Back hides the shared reader
without ending the temporary session; its controls remain on the main screen.
Restore closes the session and returns to the underlying reader in a running
app, or to the user's own main screen after a cold start. Font/size/color-scheme
changes made while reading are local and survive Restore. Keep adopts resolved
prayer settings while retaining native presentation bits, UI language and
network policy. Subsequent inline content choices in the kept reader are also
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
canonical metadata, fixed/relative dates, masks and UInt64 values, duplicate or
malicious links, local appearance, partial inline navigation, session recreation,
and keeping content without overwriting the `ds` preference. The Xcode project
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
4. Follow prayer links/options, use TTS, change the font, hide with Back and
   resume. Restore must retain personal settings and local appearance; Keep must
   affect content only. Unsupported Keep must make no preference changes.
5. Rapidly receive two different links while a local/remote load is pending;
   only the last shared request may update the reader.
