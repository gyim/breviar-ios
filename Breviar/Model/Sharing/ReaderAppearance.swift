import Foundation

/// The portable part of native text options. No sender-supplied CSS or font files are used.
enum ReaderAppearance {
    static let storageKey = "textOptions.rendererAppearance"
    static let defaultPointSize = 16.0 // body font size in breviar.css
    static let preferenceKeys = [
        "textOptions.fontName", "textOptions.fontSize", "textOptions.isBold", "colorScheme", storageKey
    ]

    static func options(local: [String: String], extra: [String: String], font: String,
                        scale: Double, bold: Bool, dark: Bool) -> [String: String] {
        var result = local.merging(extra.filter { SharedPrayerLink.appearanceKeys.contains($0.key) }) { _, new in new }
        result["f"] = font
        if extra["ff"] == nil && extra["s"] == nil {
            result["ff"] = String(Int((defaultPointSize * scale / 100).rounded()))
            result["s"] = ""
        }
        result["c"] = dark ? "1" : "0"
        let word = UInt64(result["o0"] ?? "") ?? 0
        result["o0"] = String(bold ? word & ~64 : word | 64)
        result.removeValue(forKey: "of0fn")
        return result
    }

    static func scale(in parameters: [String: String]) -> Double? {
        if let value = parameters["ff"], let size = Double(value), size > 0 {
            return size / defaultPointSize * 100
        }
        guard let value = parameters["s"] else {
            return parameters["ff"] != nil ? 100 : nil
        }
        let sizes: [String: Double] = [
            "2": 6.75, "3": 7.5, "4": 9.75, "5": 12, "6": 13.5, "7": 18, "8": 24,
            "xx-small": 6.75, "x-small": 7.5, "small": 9.75, "medium": 12,
            "large": 13.5, "x-large": 18, "xx-large": 24
        ]
        return (sizes[value] ?? defaultPointSize) / defaultPointSize * 100
    }

    static func normalFont(in parameters: [String: String]) -> Bool? {
        if let value = parameters["of0fn"] { return value != "0" && !value.isEmpty }
        return parameters["o0"].map { (UInt64($0) ?? 0) & 64 != 0 }
    }

    static func nightMode(in parameters: [String: String]) -> Bool? {
        if let value = parameters["c"], !value.isEmpty { return value == "1" }
        if let value = parameters["of2nr"] { return value != "0" && !value.isEmpty }
        return parameters["o2"].map { (UInt64($0) ?? 0) & 256 != 0 }
    }

    /// Both palettes follow native/system appearance immediately, without a CGI round trip.
    static func css(_ parameters: [String: String]) -> String {
        func palette(_ mode: String) -> String {
            let fields = [("ct", "text"), ("cr", "rubric"), ("c", "background")]
            return fields.map { key, property in
                let value = parameters[key + mode] ?? ""
                let valid = value.range(of: #"\A(?:[a-fA-F0-9]{3}|[a-fA-F0-9]{6})\z"#, options: .regularExpression) != nil
                return "--prayer-\(property): \(valid ? "#" + value : "initial");"
            }.joined(separator: " ")
        }
        var body: [String] = []
        if let value = parameters["mm"], let margin = Int(value) {
            let pixels = max(0, min(1024, margin))
            body.append("margin-left: \(pixels)px; margin-right: \(pixels)px;")
        }
        if let value = parameters["lh"], let height = Int(value), height > 0 {
            body.append("line-height: \(min(512, height))%;")
        }
        return """
            :root { \(palette("0")) }
            html, body { background-color: var(--prayer-background, #fff) !important; }
            body { \(body.joined(separator: " ")) }
            @media (prefers-color-scheme: dark) {
                :root { \(palette("1")) }
                html, body { background-color: var(--prayer-background, #000) !important; }
            }
            """
    }
}
