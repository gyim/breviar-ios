import AppKit
import SwiftUI

// Composes the final App Store images from raw captures, see README.md.
//
//   compose <shots.json> <outdir> [--raw <dir>] [--bezels <dir>] [--devices a,b]
//           [--locales a,b] [--only id1,id2] [--contact-sheet]
//
// Raw captures are read from <raw>/<device>/<locale>/<shot>.<role>.png and
// <raw>/widgets/<name>.png (default <outdir>/raw); bezels from <bezels>
// (default <outdir>/../_bezels). Output: <outdir>/<device>/<locale>/<shot>.png.

struct Options {
    var scriptPath = ""
    var outDir = ""
    var rawDir: String?
    var bezelsDir: String?
    var devices: [String]?
    var locales: [String]?
    var only: [String]?
    var contactSheet = false

    static func parse(_ args: [String]) -> Options {
        var options = Options()
        var positional: [String] = []
        var i = 0
        while i < args.count {
            let arg = args[i]
            let value: String? = i + 1 < args.count ? args[i + 1] : nil
            switch arg {
            case "--raw": options.rawDir = value; i += 1
            case "--bezels": options.bezelsDir = value; i += 1
            case "--devices": options.devices = value?.split(separator: ",").map(String.init); i += 1
            case "--locales": options.locales = value?.split(separator: ",").map(String.init); i += 1
            case "--only": options.only = value?.split(separator: ",").map(String.init); i += 1
            case "--contact-sheet": options.contactSheet = true
            default: positional.append(arg)
            }
            i += 1
        }
        guard positional.count == 2 else {
            print("usage: compose <shots.json> <outdir> [--raw dir] [--bezels dir] [--devices a,b] [--locales a,b] [--only ids] [--contact-sheet]")
            exit(1)
        }
        options.scriptPath = positional[0]
        options.outDir = (positional[1] as NSString).standardizingPath
        return options
    }
}

func warn(_ message: String) {
    FileHandle.standardError.write(("warning: " + message + "\n").data(using: .utf8)!)
}

let options = Options.parse(Array(CommandLine.arguments.dropFirst()))
let script = try JSONDecoder().decode(Script.self, from: Data(contentsOf: URL(fileURLWithPath: options.scriptPath)))
let rawDir = options.rawDir ?? options.outDir + "/raw"
let bezelsDir = options.bezelsDir ?? (options.outDir as NSString).deletingLastPathComponent + "/_bezels"
let deviceIds = (options.devices ?? script.devices.keys.sorted()).filter { script.devices[$0] != nil }
let localeIds = (options.locales ?? script.locales.keys.sorted()).filter { script.locales[$0] != nil }
let shots = script.shots.filter { options.only?.contains($0.id) ?? true }

func captureImage(shot: Shot, role: String, device: String, locale: String) -> CGImage? {
    let path = "\(rawDir)/\(device)/\(locale)/\(shot.id).\(role).png"
    guard var image = Images.load(path) else {
        warn("missing capture \(path)")
        return nil
    }
    let capture = shot.captures?[role]
    if let crop = capture?.crop?[device] {
        image = Images.crop(image, to: crop)
    } else if capture?.cropMode == "celebrationCard" {
        if let rect = Images.detectCelebrationCard(in: image) {
            image = Images.crop(image, to: rect)
        } else {
            warn("no celebration card found in \(path)")
        }
    }
    return image
}

func widgetImage(shot: Shot, role: String, locale: LocaleSpec) -> CGImage? {
    guard let pattern = shot.widgets?[role] else {
        warn("shot \(shot.id) has no widget pattern for \(role)")
        return nil
    }
    let name = pattern.replacingOccurrences(of: "{widgetScenario}", with: locale.widgetScenario ?? "")
    let path = "\(rawDir)/widgets/\(name).png"
    guard let image = Images.load(path) else {
        warn("missing widget render \(path)")
        return nil
    }
    return image
}

@MainActor
func compose(shot: Shot, ctx: ShotContext, device: String, localeId: String, locale: LocaleSpec) -> CGImage? {
    let layout = shot.layout
    func image(_ role: String?) -> CGImage? {
        guard let role else {
            warn("shot \(shot.id): layout \(layout.type) is missing a capture role")
            return nil
        }
        return captureImage(shot: shot, role: role, device: device, locale: localeId)
    }
    let view: AnyView
    switch layout.type {
    case "single":
        guard let screen = image(layout.device) else { return nil }
        view = AnyView(SingleLayout(ctx: ctx, screen: screen))
    case "singleChips":
        guard let screen = image(layout.device) else { return nil }
        view = AnyView(SingleLayout(ctx: ctx, screen: screen, chips: layout.chips ?? []))
    case "splitLightDark":
        guard let left = image(layout.left), let right = image(layout.right) else { return nil }
        view = AnyView(SplitLayout(ctx: ctx, left: left, right: right))
    case "twoOffset":
        guard let front = image(layout.front), let back = image(layout.back) else { return nil }
        view = AnyView(TwoOffsetLayout(ctx: ctx, front: front, back: back))
    case "hero":
        guard let screen = image(layout.device) else { return nil }
        let roles = layout.cards ?? []
        let cards = roles.compactMap { image($0) }
        guard cards.count == roles.count else { return nil }
        view = AnyView(HeroLayout(ctx: ctx, screen: screen, cards: cards, labels: layout.cardLabels ?? []))
    case "widgetHome":
        let widgets = (layout.widgets ?? []).compactMap { role in
            widgetImage(shot: shot, role: role, locale: locale).map { (role: role, image: $0) }
        }
        guard !widgets.isEmpty else { return nil }
        view = AnyView(WidgetHomeLayout(ctx: ctx, widgets: widgets))
    default:
        warn("shot \(shot.id): unknown layout type \(layout.type)")
        return nil
    }
    return Images.render(view, size: ctx.spec.canvasSize)
}

_ = NSApplication.shared

MainActor.assumeIsolated {
    var written = 0
    for deviceId in deviceIds {
        let spec = script.devices[deviceId]!
        var bezel: Bezel? = nil
        if let name = spec.bezel {
            bezel = Bezel.load("\(bezelsDir)/\(name)")
            if bezel == nil {
                warn("no bezel at \(bezelsDir)/\(name), drawing a plain frame for \(deviceId)")
            } else {
                print("\(deviceId): bezel \(name), screen \(Int(bezel!.screenRect.width))x\(Int(bezel!.screenRect.height)) px")
            }
        }
        for localeId in localeIds {
            let locale = script.locales[localeId]!
            var sheet: [(label: String, image: CGImage)] = []
            for shot in shots {
                guard let caption = shot.caption[localeId] ?? shot.caption["en-US"] else {
                    warn("shot \(shot.id) has no caption for \(localeId)")
                    continue
                }
                if shot.caption[localeId] == nil {
                    warn("shot \(shot.id): using the en-US caption for \(localeId)")
                }
                let ctx = ShotContext(spec: spec, style: script.style, bezel: bezel, caption: caption, layout: shot.layout)
                guard let image = compose(shot: shot, ctx: ctx, device: deviceId, localeId: localeId, locale: locale) else {
                    warn("skipped \(deviceId)/\(localeId)/\(shot.id)")
                    continue
                }
                let path = "\(options.outDir)/\(deviceId)/\(localeId)/\(shot.id).png"
                do {
                    try Images.writePNG(image, to: path)
                } catch {
                    warn("\(error)")
                    continue
                }
                if image.width != Int(spec.canvas[0]) || image.height != Int(spec.canvas[1]) {
                    warn("\(path) is \(image.width)x\(image.height), expected \(Int(spec.canvas[0]))x\(Int(spec.canvas[1]))")
                }
                sheet.append((shot.id, image))
                written += 1
            }
            if options.contactSheet && !sheet.isEmpty {
                let cellWidth: CGFloat = spec.canvas[0] > spec.canvas[1] * 0.6 ? 420 : 330
                if let image = Images.renderFitting(ContactSheet(items: sheet, columns: 4, cellWidth: cellWidth)) {
                    let path = "\(options.outDir)/contact-\(deviceId)-\(localeId).png"
                    try? Images.writePNG(image, to: path)
                    print("contact sheet: \(path)")
                }
            }
        }
    }
    print("wrote \(written) images to \(options.outDir)")
}
