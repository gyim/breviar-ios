# WidgetRender

Renders the home screen widgets (small, medium, large) to PNG files in about
ten seconds, without building or installing the app. Useful for iterating on
the widget layout and for checking many calendar situations at once.

```sh
Tools/WidgetRender/render.sh                       # all scenarios, all families, light + dark
Tools/WidgetRender/render.sh --families small --schemes light --only hu-long3
Tools/WidgetRender/render.sh my-scenarios.json     # custom scenario file
```

Output goes to `$TMPDIR/breviar-widget-render/out` (override with `OUT=...`):

- `small.png`, `medium.png`, `large.png` — contact sheets with every scenario
- `individual/<family>-<scenario>-<light|dark>.png` — 3x renders of a single widget

## How it works

`render.sh` compiles `BreviarWidget/BreviarWidget.swift` and the model files it
depends on with `swiftc` for the iOS simulator SDK, together with `main.swift`
as the entry point. The binary is then started *inside* the booted simulator
with `xcrun simctl spawn`, so SwiftUI lays out the views with the real iOS fonts
and metrics, and `ImageRenderer` writes the PNGs straight to the host file
system. A simulator must be booted; the first booted one is used unless `SIM`
is set to a UDID.

The tool renders `BreviarWidgetSystemView`, the same view the widget extension
shows, with the family passed in explicitly (WidgetKit's `widgetFamily`
environment value cannot be set from outside). What it cannot reproduce is the
widget container: a flat fill stands in for the translucent `.fill.tertiary`
material, and the lock screen families are not rendered. Sizes are those of the
iPhone 16 Pro.

## Scenarios

`scenarios.json` is a list of `{ key, label, lang, days }` objects, where `days`
uses the same JSON shape as the widget cache (`WidgetLiturgicalDay`). The small
widget shows the first day, the medium and large ones as many of the following
days as fit. The bundled scenarios were generated from CGI output and cover
long names, days with several celebrations, dual liturgical colors and all
three main languages. To render what the app has actually cached, wrap the
`days` array of `cached_liturgical_calendar.json` from the app group container
into a scenario object.
