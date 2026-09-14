import Foundation

// The storyboard (shots.json): which shots exist, how each one is laid out,
// its captions per locale and how its raw captures are produced. The
// compositor uses the layout, caption and crop fields; capture.sh reads the
// launch arguments, URLs and actions.

struct Script: Decodable {
    var version: String
    var style: Style
    var devices: [String: DeviceSpec]
    var locales: [String: LocaleSpec]
    var defaults: CaptureDefaults?
    var shots: [Shot]
}

struct Style: Decodable {
    var background: [String]
    var title: String
    var subtitle: String
    var accent: String
    var chipFill: String
    var chipBorder: String
    var wallpaper: [String]
}

struct DeviceSpec: Decodable {
    /// Final image size in pixels (App Store requirement).
    var canvas: [Double]
    /// Pixel size of a raw simulator screenshot of this device.
    var capture: [Double]
    var margin: Double
    var bottomMargin: Double
    /// Fixed height of the caption area, so the device sits at the same place on every shot.
    var captionHeight: Double
    var titleSize: Double
    var subtitleSize: Double
    /// Corner radius of the screen, in capture pixels.
    var screenCornerRadius: Double
    /// Thickness of the drawn frame when no bezel image is available.
    var bezelThickness: Double
    /// File name of Apple's bezel PNG inside the bezels directory.
    var bezel: String?
    /// Widget widths as a fraction of the screen width, by widget family.
    var widgetWidths: [String: Double]
    var simDeviceType: String?
    var simName: String?

    var canvasSize: CGSize { CGSize(width: canvas[0], height: canvas[1]) }
    var captureWidth: Double { capture[0] }
    var captureAspect: Double { capture[0] / capture[1] }
    var contentWidth: Double { canvas[0] - 2 * margin }
}

struct LocaleSpec: Decodable {
    var launchArgs: [String: String]?
    /// Key of the scenario in widget-scenarios.json used for the widget shot.
    var widgetScenario: String?
}

struct CaptureDefaults: Decodable {
    var launchArgs: [String: String]?
    var settleSeconds: Double?
}

struct Shot: Decodable {
    var id: String
    var layout: ShotLayout
    var caption: [String: Caption]
    var captures: [String: Capture]?
    /// Widget role -> file name pattern in raw/widgets (without .png); `{widgetScenario}` is substituted.
    var widgets: [String: String]?
}

struct Caption: Decodable {
    var title: String
    var subtitle: String?
    var badge: String?
}

struct ShotLayout: Decodable {
    var type: String
    var device: String?
    var left: String?
    var right: String?
    var front: String?
    var back: String?
    var cards: [String]?
    var cardLabels: [String]?
    var chips: [Chip]?
    var widgets: [String]?
    var badgeSymbol: String?
    var seam: Double?
    var deviceWidthFraction: Double?
    var scale: Double?
}

struct Chip: Decodable {
    var emoji: String
    var text: String
}

struct Capture: Decodable {
    var url: String?
    var launchArgs: [String: String]?
    var appearance: String?
    var actions: [String]?
    /// Crop rectangle [x, y, width, height] in capture pixels, by device id.
    var crop: [String: [Double]]?
    /// Automatic crop: "celebrationCard" finds the selected celebration's card on the main screen.
    var cropMode: String?
}
