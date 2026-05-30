//
//  BreviarWidget.swift
//  BreviarWidget
//

import WidgetKit
import SwiftUI
import UIKit

// MARK: - Timeline Entry

struct BreviarWidgetEntry: TimelineEntry {
    let date: Date
    let upcomingDays: [LiturgicalDay]

    var liturgicalDay: LiturgicalDay? { upcomingDays.first }
}

// MARK: - Timeline Provider

private let maxUpcomingDaysPerEntry = 14

struct BreviarWidgetProvider: TimelineProvider {
    func placeholder(in context: Context) -> BreviarWidgetEntry {
        BreviarWidgetEntry(date: Date(), upcomingDays: [])
    }

    func getSnapshot(in context: Context, completion: @escaping (BreviarWidgetEntry) -> Void) {
        configureLanguage()
        let today = Day(fromDate: Date())
        let upcoming = WidgetDataReader.readCalendarData()
            .drop(while: { $0.day.daysSinceEpoch < today.daysSinceEpoch })
            .prefix(maxUpcomingDaysPerEntry)
        completion(BreviarWidgetEntry(date: Date(), upcomingDays: Array(upcoming)))
    }

    func getTimeline(in context: Context, completion: @escaping (Timeline<BreviarWidgetEntry>) -> Void) {
        configureLanguage()
        let allDays = WidgetDataReader.readCalendarData()

        var entries: [BreviarWidgetEntry] = []
        let cal = Calendar.current

        for i in allDays.indices {
            let day = allDays[i].day
            var comps = DateComponents()
            comps.year = day.year
            comps.month = day.month
            comps.day = day.day
            comps.hour = 0
            comps.minute = 0
            comps.second = 0
            if let entryDate = cal.date(from: comps) {
                let slice = Array(allDays[i...].prefix(maxUpcomingDaysPerEntry))
                entries.append(BreviarWidgetEntry(date: entryDate, upcomingDays: slice))
            }
        }

        if entries.isEmpty {
            entries.append(BreviarWidgetEntry(date: Date(), upcomingDays: []))
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

// MARK: - Multi-Day System Widget View

struct BreviarWidgetMultiDayView: View {
    @Environment(\.widgetFamily) var family
    let days: [LiturgicalDay]

    private static let maxDaysToConsider = 8
    private let weekdayColumnWidth: CGFloat = 30

    private var isSmall: Bool { family == .systemSmall }

    var body: some View {
        if days.isEmpty {
            Text(S.appName.S)
                .font(.headline)
        } else {
            ViewThatFits(in: .vertical) {
                ForEach(
                    Array(stride(from: min(days.count, Self.maxDaysToConsider), through: 1, by: -1)),
                    id: \.self
                ) { n in
                    listView(Array(days.prefix(n)), truncateFirst: false)
                }
                listView(Array(days.prefix(1)), truncateFirst: true)
            }
            .padding(.vertical, 4)
            .padding(.leading, -16)
        }
    }

    @ViewBuilder
    private func listView(_ slice: [LiturgicalDay], truncateFirst: Bool) -> some View {
        VStack(spacing: 0) {
            ForEach(Array(slice.enumerated()), id: \.offset) { dIdx, lDay in
                ForEach(Array(lDay.celebrations.enumerated()), id: \.offset) { cIdx, cel in
                    let isCurrentDay = dIdx == 0
                    let isFirstOfDay = cIdx == 0
                    let titleLines: Int? = {
                        if truncateFirst { return nil }
                        if isSmall && isCurrentDay && isFirstOfDay { return 3 }
                        return 1
                    }()
                    let subtitleLines: Int? = truncateFirst ? nil : 1
                    WidgetDayRow(
                        weekday: isFirstOfDay && !isCurrentDay
                            ? currentLiturgicalLanguage.narrowWeekdayName(for: lDay.day.date)
                            : "",
                        dayNumber: isCurrentDay && isFirstOfDay ? lDay.day.day : nil,
                        isCurrentDay: isCurrentDay,
                        celebration: cel,
                        columnWidth: weekdayColumnWidth,
                        titleLineLimit: titleLines,
                        subtitleLineLimit: subtitleLines
                    )
                }
            }
        }
    }
}

struct WidgetDayRow: View {
    let weekday: String
    let dayNumber: Int?
    let isCurrentDay: Bool
    let celebration: Celebration
    let columnWidth: CGFloat
    let titleLineLimit: Int?
    let subtitleLineLimit: Int?

    var body: some View {
        HStack(alignment: dayNumber != nil ? .center : .top, spacing: 4) {
            leadingLabel
                .frame(width: columnWidth, alignment: .trailing)
            WidgetCellColorBar(color: celebration.liturgicalColor, width: 5)
            VStack(alignment: .leading, spacing: 1) {
                Text(hyphenatedAttributedString(celebration.title))
                    .font(.footnote)
                    .fontWeight(.bold)
                    .foregroundColor(isCurrentDay ? .primary : .secondary)
                    .lineLimit(titleLineLimit)
                if !celebration.subtitle.isEmpty {
                    Text(celebration.subtitle)
                        .font(.caption2)
                        .foregroundColor(.secondary)
                        .lineLimit(subtitleLineLimit)
                }
            }
            .padding(.leading, 2)
            Spacer(minLength: 0)
        }
    }

    @ViewBuilder
    private var leadingLabel: some View {
        if let n = dayNumber {
            Text("\(n)")
                .font(.title2)
                .fontWeight(.bold)
                .foregroundColor(.primary)
                .lineLimit(1)
                .minimumScaleFactor(0.7)
        } else {
            Text(weekday)
                .font(.footnote)
                .fontWeight(.bold)
                .foregroundColor(isCurrentDay ? .primary : .secondary)
                .lineLimit(1)
        }
    }
}

private func hyphenatedAttributedString(_ s: String) -> AttributedString {
    let style = NSMutableParagraphStyle()
    style.hyphenationFactor = 1.0
    let ns = NSAttributedString(string: s, attributes: [.paragraphStyle: style])
    return AttributedString(ns)
}

struct WidgetCellColorBar: View {
    let color: LiturgicalColor
    let width: CGFloat

    var body: some View {
        VStack(spacing: 0) {
            Rectangle().fill(uiLiturgicalColors[color.firstColor()] ?? .gray)
            Rectangle().fill(uiLiturgicalColors[color.secondColor()] ?? .gray)
        }
        .frame(width: width)
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
        case .systemSmall, .systemMedium, .systemLarge:
            BreviarWidgetMultiDayView(days: entry.upcomingDays)
        case .accessoryCircular:
            BreviarWidgetCircularView(entry: entry)
        case .accessoryRectangular:
            BreviarWidgetRectangularView(entry: entry)
        case .accessoryInline:
            BreviarWidgetInlineView(entry: entry)
        default:
            BreviarWidgetMultiDayView(days: entry.upcomingDays)
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
