//
//  BreviarWidget.swift
//  BreviarWidget
//

import WidgetKit
import SwiftUI

// MARK: - Timeline Entry

struct BreviarWidgetEntry: TimelineEntry {
    let date: Date
    let liturgicalDay: LiturgicalDay?
}

// MARK: - Timeline Provider

struct BreviarWidgetProvider: TimelineProvider {
    func placeholder(in context: Context) -> BreviarWidgetEntry {
        BreviarWidgetEntry(date: Date(), liturgicalDay: nil)
    }

    func getSnapshot(in context: Context, completion: @escaping (BreviarWidgetEntry) -> Void) {
        configureLanguage()
        let entry = BreviarWidgetEntry(
            date: Date(),
            liturgicalDay: WidgetDataReader.liturgicalDay(for: Date())
        )
        completion(entry)
    }

    func getTimeline(in context: Context, completion: @escaping (Timeline<BreviarWidgetEntry>) -> Void) {
        configureLanguage()
        let allDays = WidgetDataReader.readCalendarData()

        var entries: [BreviarWidgetEntry] = []
        let cal = Calendar.current

        for liturgicalDay in allDays {
            let day = liturgicalDay.day
            var comps = DateComponents()
            comps.year = day.year
            comps.month = day.month
            comps.day = day.day
            comps.hour = 0
            comps.minute = 0
            comps.second = 0
            if let entryDate = cal.date(from: comps) {
                entries.append(BreviarWidgetEntry(date: entryDate, liturgicalDay: liturgicalDay))
            }
        }

        if entries.isEmpty {
            entries.append(BreviarWidgetEntry(date: Date(), liturgicalDay: nil))
        }

        let timeline = Timeline(entries: entries, policy: .atEnd)
        completion(timeline)
    }

    private func configureLanguage() {
        if let (lang, uiLang) = WidgetDataReader.readLanguageSettings() {
            currentLiturgicalLanguage = lang
            currentUILanguage = uiLang
        }
    }
}

// MARK: - Widget Color Bar

struct WidgetCelebrationColorBar: View {
    let color: LiturgicalColor
    let width: CGFloat

    var body: some View {
        VStack(spacing: 0) {
            Rectangle()
                .fill(uiLiturgicalColors[color.firstColor()] ?? .gray)
            Rectangle()
                .fill(uiLiturgicalColors[color.secondColor()] ?? .gray)
        }
        .frame(width: width)
        .clipShape(RoundedRectangle(cornerRadius: width / 2))
    }
}

// MARK: - System Small Widget View

struct BreviarWidgetSmallView: View {
    let entry: BreviarWidgetEntry

    var body: some View {
        if let day = entry.liturgicalDay, let celebration = day.celebrations.first {
            HStack(spacing: 6) {
                WidgetCelebrationColorBar(color: celebration.liturgicalColor, width: 5)
                VStack(alignment: .leading, spacing: 4) {
                    Text(celebration.title)
                        .font(.footnote)
                        .fontWeight(.bold)
                        .lineLimit(3)
                    if !celebration.subtitle.isEmpty {
                        Text(celebration.subtitle)
                            .font(.caption2)
                            .foregroundColor(.secondary)
                            .lineLimit(2)
                    }
                }
                Spacer(minLength: 0)
            }
            .padding(4)
        } else {
            Text(S.appName.S)
                .font(.headline)
        }
    }
}

// MARK: - System Medium Widget View

struct BreviarWidgetMediumView: View {
    let entry: BreviarWidgetEntry

    var body: some View {
        if let day = entry.liturgicalDay, !day.celebrations.isEmpty {
            VStack(alignment: .leading, spacing: 4) {
                ForEach(day.celebrations.prefix(3)) { celebration in
                    HStack(spacing: 6) {
                        WidgetCelebrationColorBar(color: celebration.liturgicalColor, width: 5)
                        VStack(alignment: .leading, spacing: 1) {
                            Text(celebration.title)
                                .font(.footnote)
                                .fontWeight(.bold)
                                .lineLimit(1)
                            if !celebration.subtitle.isEmpty {
                                Text(celebration.subtitle)
                                    .font(.caption2)
                                    .foregroundColor(.secondary)
                                    .lineLimit(1)
                            }
                        }
                        Spacer(minLength: 0)
                    }
                }
            }
            .padding(4)
        } else {
            Text(S.appName.S)
                .font(.headline)
        }
    }
}

// MARK: - System Large Widget View

struct BreviarWidgetLargeView: View {
    let entry: BreviarWidgetEntry

    private var dateString: String {
        guard let day = entry.liturgicalDay else { return "" }
        let date = day.day.date
        let fmt = currentLiturgicalLanguage.dateFormatter(format: "EEEE, d MMMM")
        return fmt.string(from: date).capitalized
    }

    var body: some View {
        if let day = entry.liturgicalDay, !day.celebrations.isEmpty {
            VStack(alignment: .leading, spacing: 8) {
                Text(dateString)
                    .font(.caption)
                    .foregroundColor(.secondary)
                ForEach(day.celebrations) { celebration in
                    HStack(spacing: 8) {
                        WidgetCelebrationColorBar(color: celebration.liturgicalColor, width: 5)
                        VStack(alignment: .leading, spacing: 2) {
                            Text(celebration.title)
                                .font(.subheadline)
                                .fontWeight(.bold)
                                .lineLimit(2)
                            if !celebration.subtitle.isEmpty {
                                Text(celebration.subtitle)
                                    .font(.caption)
                                    .foregroundColor(.secondary)
                                    .lineLimit(2)
                            }
                        }
                        Spacer(minLength: 0)
                    }
                }
                Spacer(minLength: 0)
            }
            .padding(4)
        } else {
            Text(S.appName.S)
                .font(.headline)
        }
    }
}

// MARK: - Lock Screen Widgets

struct BreviarWidgetCircularView: View {
    let entry: BreviarWidgetEntry

    var body: some View {
        if let day = entry.liturgicalDay, let celebration = day.celebrations.first {
            ZStack {
                AccessoryWidgetBackground()
                Circle()
                    .fill(uiLiturgicalColors[celebration.liturgicalColor.firstColor()] ?? .gray)
                    .padding(4)
            }
        } else {
            ZStack {
                AccessoryWidgetBackground()
                Image(systemName: "book.closed")
                    .font(.title3)
            }
        }
    }
}

struct BreviarWidgetRectangularView: View {
    let entry: BreviarWidgetEntry

    var body: some View {
        if let day = entry.liturgicalDay, let celebration = day.celebrations.first {
            HStack(spacing: 4) {
                WidgetCelebrationColorBar(color: celebration.liturgicalColor, width: 3)
                VStack(alignment: .leading, spacing: 1) {
                    Text(celebration.title)
                        .font(.headline)
                        .lineLimit(1)
                    if !celebration.subtitle.isEmpty {
                        Text(celebration.subtitle)
                            .font(.caption)
                            .lineLimit(1)
                    }
                }
                Spacer(minLength: 0)
            }
        } else {
            Text(S.appName.S)
                .font(.headline)
        }
    }
}

struct BreviarWidgetInlineView: View {
    let entry: BreviarWidgetEntry

    var body: some View {
        if let day = entry.liturgicalDay, let celebration = day.celebrations.first {
            Text(celebration.title)
        } else {
            Text(S.appName.S)
        }
    }
}

// MARK: - Widget Entry View

struct BreviarWidgetEntryView: View {
    @Environment(\.widgetFamily) var family
    var entry: BreviarWidgetEntry

    var body: some View {
        switch family {
        case .systemSmall:
            BreviarWidgetSmallView(entry: entry)
        case .systemMedium:
            BreviarWidgetMediumView(entry: entry)
        case .systemLarge:
            BreviarWidgetLargeView(entry: entry)
        case .accessoryCircular:
            BreviarWidgetCircularView(entry: entry)
        case .accessoryRectangular:
            BreviarWidgetRectangularView(entry: entry)
        case .accessoryInline:
            BreviarWidgetInlineView(entry: entry)
        default:
            BreviarWidgetSmallView(entry: entry)
        }
    }
}

// MARK: - Widget Configuration

struct BreviarWidget: Widget {
    let kind: String = "BreviarWidget"

    var body: some WidgetConfiguration {
        StaticConfiguration(kind: kind, provider: BreviarWidgetProvider()) { entry in
            if #available(iOS 17.0, *) {
                BreviarWidgetEntryView(entry: entry)
                    .widgetURL(URL(string: "breviar://today"))
                    .containerBackground(.fill.tertiary, for: .widget)
            } else {
                BreviarWidgetEntryView(entry: entry)
                    .widgetURL(URL(string: "breviar://today"))
                    .padding()
                    .background()
            }
        }
        .configurationDisplayName(S.appName.S)
        .description(S.liturgicalCalendar.S)
        .supportedFamilies([
            .systemSmall,
            .systemMedium,
            .systemLarge,
            .accessoryCircular,
            .accessoryRectangular,
            .accessoryInline,
        ])
    }
}
