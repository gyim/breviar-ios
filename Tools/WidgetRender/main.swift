import SwiftUI
import WidgetKit

// Renders the home screen widgets for a set of scenarios, see README.md.
//
//   render <scenarios.json> <outdir> [--families small,medium,large]
//          [--schemes light,dark] [--only key1,key2]
//
// Writes one PNG per scenario x family x scheme into <outdir>/individual and
// one contact sheet per family into <outdir>.

struct Scenario: Decodable {
    let key: String
    let label: String
    let lang: String
    let days: [WidgetLiturgicalDay]

    var language: Language { Language(rawValue: lang) ?? .hungarian }

    var entry: BreviarWidgetEntry {
        BreviarWidgetEntry(date: Date(), upcomingDays: days.map { $0.toLiturgicalDay() })
    }
}

/// Widget sizes on the iPhone 16 Pro simulator, measured from screenshots.
let widgetSizes: [WidgetFamily: CGSize] = [
    .systemSmall: CGSize(width: 164, height: 164),
    .systemMedium: CGSize(width: 350, height: 164),
    .systemLarge: CGSize(width: 350, height: 365),
]

let familiesByName: [String: WidgetFamily] = [
    "small": .systemSmall,
    "medium": .systemMedium,
    "large": .systemLarge,
]

struct Options {
    var scenariosPath = ""
    var outDir = ""
    var families: [(name: String, family: WidgetFamily)] = ["small", "medium", "large"].map { ($0, familiesByName[$0]!) }
    var schemes: [ColorScheme] = [.light, .dark]
    var only: [String]? = nil

    static func parse(_ args: [String]) -> Options {
        var options = Options()
        var positional: [String] = []
        var i = 0
        while i < args.count {
            let arg = args[i]
            let value: String? = i + 1 < args.count ? args[i + 1] : nil
            switch arg {
            case "--families":
                options.families = (value ?? "").split(separator: ",").compactMap { name in
                    familiesByName[String(name)].map { (String(name), $0) }
                }
                i += 1
            case "--schemes":
                options.schemes = (value ?? "").split(separator: ",").map { $0 == "dark" ? .dark : .light }
                i += 1
            case "--only":
                options.only = (value ?? "").split(separator: ",").map(String.init)
                i += 1
            default:
                positional.append(arg)
            }
            i += 1
        }
        guard positional.count == 2 else {
            print("usage: render <scenarios.json> <outdir> [--families small,medium,large] [--schemes light,dark] [--only key1,key2]")
            exit(1)
        }
        options.scenariosPath = positional[0]
        options.outDir = positional[1]
        return options
    }
}

let options = Options.parse(Array(CommandLine.arguments.dropFirst()))
let allScenarios = try! JSONDecoder().decode([Scenario].self, from: Data(contentsOf: URL(fileURLWithPath: options.scenariosPath)))
let scenarios = allScenarios.filter { options.only?.contains($0.key) ?? true }

func schemeName(_ scheme: ColorScheme) -> String {
    return scheme == .dark ? "dark" : "light"
}

/// Stands in for the widget container: a flat fill instead of the material.
struct WidgetMock: View {
    let scenario: Scenario
    let family: WidgetFamily
    let scheme: ColorScheme

    var body: some View {
        let size = widgetSizes[family]!
        BreviarWidgetSystemView(entry: scenario.entry, family: family, language: scenario.language)
            .frame(width: size.width, height: size.height)
            .background(scheme == .dark ? Color(white: 0.11) : Color(white: 0.98))
            .clipShape(RoundedRectangle(cornerRadius: 24, style: .continuous))
            .environment(\.colorScheme, scheme)
    }
}

struct SheetCell: View {
    let scenario: Scenario
    let family: WidgetFamily
    let scheme: ColorScheme

    var body: some View {
        VStack(spacing: 4) {
            WidgetMock(scenario: scenario, family: family, scheme: scheme)
            Text(scenario.label)
                .font(.system(size: 9))
                .foregroundColor(Color(white: 0.25))
                .lineLimit(1)
                .frame(width: widgetSizes[family]!.width)
        }
    }
}

/// All scenarios of one family: light rows first, then dark rows.
struct FamilySheet: View {
    let name: String
    let family: WidgetFamily

    private var columns: Int {
        return max(1, Int(1000 / (widgetSizes[family]!.width + 10)))
    }

    var body: some View {
        VStack(alignment: .leading, spacing: 10) {
            Text(name)
                .font(.system(size: 15, weight: .bold))
                .foregroundColor(.black)
            ForEach(options.schemes, id: \.self) { scheme in
                ForEach(Array(stride(from: 0, to: scenarios.count, by: columns)), id: \.self) { start in
                    HStack(alignment: .top, spacing: 10) {
                        ForEach(Array(scenarios[start..<min(start + columns, scenarios.count)].enumerated()), id: \.offset) { _, scenario in
                            SheetCell(scenario: scenario, family: family, scheme: scheme)
                        }
                    }
                }
            }
        }
        .padding(14)
        .background(Color(white: 0.86))
        .environment(\.colorScheme, .light)
    }
}

@MainActor
func writePNG<V: View>(_ view: V, scale: CGFloat, to path: String) {
    let renderer = ImageRenderer(content: view)
    renderer.scale = scale
    guard let data = renderer.uiImage?.pngData() else {
        print("failed to render", path)
        return
    }
    try! data.write(to: URL(fileURLWithPath: path))
}

try? FileManager.default.createDirectory(atPath: options.outDir + "/individual", withIntermediateDirectories: true)

MainActor.assumeIsolated {
    for (name, family) in options.families {
        for scenario in scenarios {
            for scheme in options.schemes {
                writePNG(WidgetMock(scenario: scenario, family: family, scheme: scheme), scale: 3,
                         to: "\(options.outDir)/individual/\(name)-\(scenario.key)-\(schemeName(scheme)).png")
            }
        }
        writePNG(FamilySheet(name: name, family: family), scale: 2, to: "\(options.outDir)/\(name).png")
        print("rendered", name)
    }
    print("output:", options.outDir)
}
