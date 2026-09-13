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

// MARK: - Layout Metrics

enum WidgetLayout {
    /// Insets applied inside the widget, replacing the default content margins.
    static let contentPadding = EdgeInsets(top: 10, leading: 14, bottom: 10, trailing: 14)
    /// Width of the leading column holding the day number / weekday name.
    static let leadingColumnWidth: CGFloat = 28
    static let leadingColumnSpacing: CGFloat = 5
    static let colorBarWidth: CGFloat = 4
    static let colorBarSpacing: CGFloat = 7
    /// Vertical gap between two days.
    static let daySpacing: CGFloat = 6
    /// Vertical gap between celebrations belonging to the same day.
    static let celebrationSpacing: CGFloat = 3
    static let textSpacing: CGFloat = 1
}

// MARK: - Widget Color Bar

/// A bar whose ends are rounded only where a day starts or ends, so the
/// celebrations of one day join into a single continuous line.
private struct WidgetColorBarShape: Shape {
    let roundsTop: Bool
    let roundsBottom: Bool

    func path(in rect: CGRect) -> Path {
        var corners: UIRectCorner = []
        if roundsTop {
            corners.formUnion([.topLeft, .topRight])
        }
        if roundsBottom {
            corners.formUnion([.bottomLeft, .bottomRight])
        }
        if corners.isEmpty {
            return Path(rect)
        }
        let radius = rect.width / 2
        let bezier = UIBezierPath(
            roundedRect: rect,
            byRoundingCorners: corners,
            cornerRadii: CGSize(width: radius, height: radius)
        )
        return Path(bezier.cgPath)
    }
}

struct WidgetCelebrationColorBar: View {
    let color: LiturgicalColor
    let width: CGFloat
    var roundsTop: Bool = true
    var roundsBottom: Bool = true

    var body: some View {
        let shape = WidgetColorBarShape(roundsTop: roundsTop, roundsBottom: roundsBottom)
        VStack(spacing: 0) {
            Rectangle()
                .fill(uiLiturgicalColors[color.firstColor()] ?? .gray)
            Rectangle()
                .fill(uiLiturgicalColors[color.secondColor()] ?? .gray)
        }
        .frame(width: width)
        .clipShape(shape)
        .overlay(shape.stroke(Color.primary.opacity(0.12), lineWidth: 0.5))
    }
}

// MARK: - Multi-Day System Widget View

/// One line of the widget: a single celebration of a single day.
private struct WidgetRowItem {
    let day: LiturgicalDay
    let celebration: Celebration
    let dayIndex: Int
    let celebrationIndex: Int
}

struct BreviarWidgetMultiDayView: View {
    @Environment(\.widgetFamily) var family
    let days: [LiturgicalDay]

    private static let maxRowsToConsider = 12

    private var isSmall: Bool { family == .systemSmall }

    private var rows: [WidgetRowItem] {
        var items: [WidgetRowItem] = []
        for (dIdx, lDay) in days.enumerated() {
            for (cIdx, cel) in lDay.celebrations.enumerated() {
                items.append(WidgetRowItem(
                    day: lDay, celebration: cel, dayIndex: dIdx, celebrationIndex: cIdx
                ))
                if items.count >= Self.maxRowsToConsider {
                    return items
                }
            }
        }
        return items
    }

    var body: some View {
        if days.isEmpty {
            Text(S.appName.S)
                .font(.headline)
                .frame(maxWidth: .infinity, maxHeight: .infinity)
        } else {
            let items = rows
            // Fitting per celebration rather than per day keeps the widget
            // filled even when the next day has several celebrations.
            ViewThatFits(in: .vertical) {
                ForEach(Array(stride(from: items.count, through: 1, by: -1)), id: \.self) { n in
                    listView(Array(items.prefix(n)), truncateFirst: false)
                }
                listView(Array(items.prefix(1)), truncateFirst: true)
            }
            .frame(maxWidth: .infinity, maxHeight: .infinity, alignment: .topLeading)
        }
    }

    @ViewBuilder
    private func listView(_ items: [WidgetRowItem], truncateFirst: Bool) -> some View {
        VStack(alignment: .leading, spacing: 0) {
            ForEach(Array(items.enumerated()), id: \.offset) { idx, item in
                let isCurrentDay = item.dayIndex == 0
                let isFirstOfDay = item.celebrationIndex == 0
                let isLastOfDay = idx == items.count - 1 || items[idx + 1].celebrationIndex == 0
                WidgetDayRow(
                    leadingLabel: leadingLabel(for: item),
                    showsDayNumber: isCurrentDay && isFirstOfDay,
                    isCurrentDay: isCurrentDay,
                    celebration: item.celebration,
                    isFirstOfDay: isFirstOfDay,
                    isLastOfDay: isLastOfDay,
                    titleLineLimit: truncateFirst ? nil : titleLineLimit(isCurrentDay: isCurrentDay, isFirstOfDay: isFirstOfDay),
                    subtitleLineLimit: truncateFirst ? nil : 1
                )
                .padding(.top, idx == 0 ? 0 : (isFirstOfDay ? WidgetLayout.daySpacing : WidgetLayout.celebrationSpacing))
            }
        }
    }

    private func leadingLabel(for item: WidgetRowItem) -> String {
        if item.celebrationIndex != 0 {
            return ""
        }
        if item.dayIndex == 0 {
            return "\(item.day.day.day)"
        }
        return currentLiturgicalLanguage.narrowWeekdayName(for: item.day.day.date)
    }

    /// Long celebration names are common, so titles may wrap onto a second
    /// line everywhere except for the follow-up rows of the small widget.
    private func titleLineLimit(isCurrentDay: Bool, isFirstOfDay: Bool) -> Int {
        if isSmall {
            return isCurrentDay && isFirstOfDay ? 2 : 1
        }
        return 2
    }
}

struct WidgetDayRow: View {
    let leadingLabel: String
    let showsDayNumber: Bool
    let isCurrentDay: Bool
    let celebration: Celebration
    let isFirstOfDay: Bool
    let isLastOfDay: Bool
    let titleLineLimit: Int?
    let subtitleLineLimit: Int?

    var body: some View {
        HStack(alignment: showsDayNumber ? .center : .firstTextBaseline,
               spacing: WidgetLayout.leadingColumnSpacing) {
            leadingText
                .frame(width: WidgetLayout.leadingColumnWidth, alignment: .trailing)
            VStack(alignment: .leading, spacing: WidgetLayout.textSpacing) {
                Text(hyphenatedAttributedString(singleLine(celebration.title)))
                    .font(.footnote)
                    .fontWeight(.semibold)
                    .foregroundColor(isCurrentDay ? .primary : .secondary)
                    .lineLimit(titleLineLimit)
                if !celebration.subtitle.isEmpty {
                    Text(singleLine(celebration.subtitle))
                        .font(.caption2)
                        .foregroundColor(.secondary)
                        .lineLimit(subtitleLineLimit)
                }
            }
            .frame(maxWidth: .infinity, alignment: .leading)
            .padding(.leading, WidgetLayout.colorBarWidth + WidgetLayout.colorBarSpacing)
            .background(alignment: .leading) {
                WidgetCelebrationColorBar(
                    color: celebration.liturgicalColor,
                    width: WidgetLayout.colorBarWidth,
                    roundsTop: isFirstOfDay,
                    roundsBottom: isLastOfDay
                )
                // grow into the gap below so the day reads as one line
                .padding(.bottom, isLastOfDay ? 0 : -WidgetLayout.celebrationSpacing)
            }
        }
    }

    @ViewBuilder
    private var leadingText: some View {
        if showsDayNumber {
            Text(leadingLabel)
                .font(.title2)
                .fontWeight(.bold)
                .foregroundColor(.primary)
                .lineLimit(1)
                .minimumScaleFactor(0.7)
        } else {
            Text(leadingLabel)
                .font(.caption)
                .fontWeight(.semibold)
                .foregroundColor(.secondary)
                .lineLimit(1)
                .minimumScaleFactor(0.8)
        }
    }
}

/// The CGI wraps long titles with line breaks; the widget lays them out itself.
private func singleLine(_ s: String) -> String {
    return s.split(whereSeparator: { $0.isWhitespace }).joined(separator: " ")
}

private func hyphenatedAttributedString(_ s: String) -> AttributedString {
    let style = NSMutableParagraphStyle()
    style.hyphenationFactor = 1.0
    let ns = NSAttributedString(string: s, attributes: [.paragraphStyle: style])
    return AttributedString(ns)
}

// MARK: - Lock Screen Widgets

struct BreviarWidgetCircularView: View {
    let entry: BreviarWidgetEntry

    var body: some View {
        ZStack {
            AccessoryWidgetBackground()
            if let day = entry.liturgicalDay, let celebration = day.celebrations.first {
                Circle()
                    .strokeBorder(
                        uiLiturgicalColors[celebration.liturgicalColor.firstColor()] ?? .gray,
                        lineWidth: 3
                    )
                Text("\(day.day.day)")
                    .font(.title2)
                    .fontWeight(.medium)
                    .minimumScaleFactor(0.6)
                    .padding(6)
            } else {
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
            // The lock screen already shows the date, so all the space goes to
            // the celebration itself.
            VStack(alignment: .leading, spacing: 1) {
                Text(singleLine(celebration.title))
                    .font(.caption)
                    .fontWeight(.semibold)
                    .lineLimit(2)
                if !celebration.subtitle.isEmpty {
                    Text(singleLine(celebration.subtitle))
                        .font(.caption2)
                        .lineLimit(1)
                        .widgetAccentable()
                }
            }
            .frame(maxWidth: .infinity, maxHeight: .infinity, alignment: .leading)
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
            Text(singleLine(celebration.title))
        } else {
            Text(S.appName.S)
        }
    }
}

// MARK: - Widget Entry View

/// Replaces WidgetKit's default content margins with symmetric insets of our
/// own: the default margins are too wide to fit a celebration name next to the
/// date column in the small widget.
@available(iOS 17.0, *)
private struct SystemWidgetContent<Content: View>: View {
    @Environment(\.widgetContentMargins) private var margins
    let content: Content

    var body: some View {
        content
            .padding(EdgeInsets(
                top: -margins.top,
                leading: -margins.leading,
                bottom: -margins.bottom,
                trailing: -margins.trailing
            ))
            .padding(WidgetLayout.contentPadding)
    }
}

struct BreviarWidgetEntryView: View {
    @Environment(\.widgetFamily) var family
    var entry: BreviarWidgetEntry

    var body: some View {
        switch family {
        case .accessoryCircular:
            BreviarWidgetCircularView(entry: entry)
        case .accessoryRectangular:
            BreviarWidgetRectangularView(entry: entry)
        case .accessoryInline:
            BreviarWidgetInlineView(entry: entry)
        default:
            systemWidget
        }
    }

    @ViewBuilder
    private var systemWidget: some View {
        let content = BreviarWidgetMultiDayView(days: entry.upcomingDays)
        if #available(iOS 17.0, *) {
            SystemWidgetContent(content: content)
        } else {
            content.padding(WidgetLayout.contentPadding)
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
