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
    /// Insets applied inside the multi-day widgets, replacing the default
    /// content margins.
    static let contentPadding = EdgeInsets(top: 10, leading: 14, bottom: 10, trailing: 14)
    /// Insets applied inside the single-day widget.
    static let singleDayPadding = EdgeInsets(top: 12, leading: 12, bottom: 12, trailing: 12)
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

    // Single-day widget
    static let cornerRadius: CGFloat = 8
    /// Vertical gap between the date band and the first card.
    static let bandSpacing: CGFloat = 8
    static let cardSpacing: CGFloat = 5
    static let cardBarWidth: CGFloat = 3
    /// Width of one additional color stripe at the end of the date band.
    static let bandStripeWidth: CGFloat = 11
    /// Horizontal offset between the top and the bottom of a stripe edge.
    static let bandStripeSlant: CGFloat = 10
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

// MARK: - Celebration Text

struct WidgetCelebrationText: View {
    let celebration: Celebration
    let titleColor: Color
    let titleLineLimit: Int?
    let showsSubtitle: Bool
    let subtitleLineLimit: Int?

    var body: some View {
        VStack(alignment: .leading, spacing: WidgetLayout.textSpacing) {
            Text(hyphenatedAttributedString(singleLine(celebration.title)))
                .font(.footnote)
                .fontWeight(.semibold)
                .foregroundColor(titleColor)
                .lineLimit(titleLineLimit)
            if showsSubtitle && !celebration.subtitle.isEmpty {
                Text(singleLine(celebration.subtitle))
                    .font(.caption2)
                    .foregroundColor(.secondary)
                    .lineLimit(subtitleLineLimit)
            }
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

// MARK: - Multi-Day Widget (medium, large)

/// One line of the widget: a single celebration of a single day.
private struct WidgetRowItem {
    let day: LiturgicalDay
    let celebration: Celebration
    let dayIndex: Int
    let celebrationIndex: Int
}

struct BreviarWidgetMultiDayView: View {
    let days: [LiturgicalDay]
    let language: Language

    private static let maxRowsToConsider = 12
    /// Long celebration names are common, so titles may wrap onto a second line.
    private static let titleLineLimit = 2

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
                    titleLineLimit: truncateFirst ? nil : Self.titleLineLimit,
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
        return language.narrowWeekdayName(for: item.day.day.date)
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
            WidgetCelebrationText(
                celebration: celebration,
                titleColor: isCurrentDay ? .primary : .secondary,
                titleLineLimit: titleLineLimit,
                showsSubtitle: true,
                subtitleLineLimit: subtitleLineLimit
            )
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

// MARK: - Single-Day Widget (small)

private extension LiturgicalColor {
    /// Both halves of a dual color, or just the color itself.
    var parts: [LiturgicalColor] {
        let first = firstColor()
        let second = secondColor()
        return first == second ? [first] : [first, second]
    }

    /// Light liturgical colors need dark text on top of them.
    var textColorOnTop: Color {
        switch firstColor() {
        case .white, .green, .rose:
            return Color.black.opacity(0.8)
        default:
            return .white
        }
    }
}

/// Distinct colors of the day in order of appearance, dual colors expanded.
private func distinctColors(of day: LiturgicalDay) -> [LiturgicalColor] {
    var colors: [LiturgicalColor] = []
    for celebration in day.celebrations {
        for part in celebration.liturgicalColor.parts where !colors.contains(part) {
            colors.append(part)
        }
    }
    return colors.isEmpty ? [.white] : colors
}

/// "Május 16. (P)", "16. května (Pá)": month and day in the order used by the
/// language, followed by the weekday abbreviation.
private func singleDayTitle(_ day: Day, language: Language) -> String {
    let formatter: DateFormatter
    if language == .latin {
        formatter = language.dateFormatter(format: "d MMMM")
    } else {
        formatter = DateFormatter()
        formatter.locale = language.locale
        formatter.setLocalizedDateFormatFromTemplate("MMMMd")
    }
    let text = formatter.string(from: day.date)
    let capitalized = text.prefix(1).uppercased() + text.dropFirst()
    return "\(capitalized) (\(language.narrowWeekdayName(for: day.date)))"
}

/// The first color fills the band; further colors appear as slanted stripes
/// at its trailing end.
private struct WidgetColorBandBackground: View {
    let colors: [LiturgicalColor]

    var body: some View {
        GeometryReader { geo in
            let width = geo.size.width
            let height = geo.size.height
            let stripes = Array(colors.dropFirst())
            let slant = WidgetLayout.bandStripeSlant / 2
            ZStack(alignment: .leading) {
                Rectangle()
                    .fill(uiLiturgicalColors[colors[0]] ?? .gray)
                ForEach(Array(stripes.enumerated()), id: \.offset) { index, color in
                    let x = width - CGFloat(stripes.count - index) * WidgetLayout.bandStripeWidth
                    Path { path in
                        path.move(to: CGPoint(x: x + slant, y: 0))
                        path.addLine(to: CGPoint(x: width, y: 0))
                        path.addLine(to: CGPoint(x: width, y: height))
                        path.addLine(to: CGPoint(x: x - slant, y: height))
                        path.closeSubpath()
                    }
                    .fill(uiLiturgicalColors[color] ?? .gray)
                }
            }
        }
    }
}

struct WidgetDateBand: View {
    let title: String
    let colors: [LiturgicalColor]

    var body: some View {
        let shape = RoundedRectangle(cornerRadius: WidgetLayout.cornerRadius, style: .continuous)
        let stripesWidth = CGFloat(colors.count - 1) * WidgetLayout.bandStripeWidth
        Text(title)
            .font(.subheadline)
            .fontWeight(.bold)
            .lineLimit(1)
            .minimumScaleFactor(0.7)
            .foregroundColor(colors[0].textColorOnTop)
            .padding(.leading, 9)
            .padding(.trailing, 9 + stripesWidth + WidgetLayout.bandStripeSlant / 2)
            .padding(.vertical, 4)
            .frame(maxWidth: .infinity, alignment: .leading)
            .background(WidgetColorBandBackground(colors: colors))
            .clipShape(shape)
            .overlay(shape.stroke(Color.primary.opacity(0.12), lineWidth: 0.5))
    }
}

/// How much of a celebration a card shows; tried from the most to the least
/// detailed until all cards fit.
struct WidgetCardDetail: Hashable {
    let titleLineLimit: Int
    let showsSubtitle: Bool

    static let levels = [
        WidgetCardDetail(titleLineLimit: 4, showsSubtitle: true),
        WidgetCardDetail(titleLineLimit: 3, showsSubtitle: true),
        WidgetCardDetail(titleLineLimit: 2, showsSubtitle: true),
        WidgetCardDetail(titleLineLimit: 1, showsSubtitle: true),
        WidgetCardDetail(titleLineLimit: 2, showsSubtitle: false),
        WidgetCardDetail(titleLineLimit: 1, showsSubtitle: false),
    ]
}

struct WidgetCelebrationCard: View {
    @Environment(\.colorScheme) private var colorScheme
    let celebration: Celebration
    let detail: WidgetCardDetail

    var body: some View {
        WidgetCelebrationText(
            celebration: celebration,
            titleColor: .primary,
            titleLineLimit: detail.titleLineLimit,
            showsSubtitle: detail.showsSubtitle,
            subtitleLineLimit: 1
        )
        .frame(maxWidth: .infinity, alignment: .leading)
        .padding(.leading, 13)
        .padding(.trailing, 8)
        .padding(.vertical, 5)
        .background(alignment: .leading) {
            WidgetCelebrationColorBar(color: celebration.liturgicalColor, width: WidgetLayout.cardBarWidth)
                .padding(.vertical, 5)
                .padding(.leading, 5)
        }
        .background(
            RoundedRectangle(cornerRadius: WidgetLayout.cornerRadius, style: .continuous)
                .fill(Color.primary.opacity(colorScheme == .dark ? 0.09 : 0.05))
        )
    }
}

/// Shows as many celebrations as fit, reducing detail before dropping cards.
struct WidgetCelebrationCards: View {
    let celebrations: [Celebration]

    private struct Candidate: Hashable {
        let count: Int
        let detail: WidgetCardDetail
    }

    private var candidates: [Candidate] {
        var result: [Candidate] = []
        for count in stride(from: celebrations.count, through: 1, by: -1) {
            for detail in WidgetCardDetail.levels {
                result.append(Candidate(count: count, detail: detail))
            }
        }
        return result
    }

    var body: some View {
        ViewThatFits(in: .vertical) {
            ForEach(candidates, id: \.self) { candidate in
                cards(count: candidate.count, detail: candidate.detail)
            }
            cards(count: 1, detail: WidgetCardDetail.levels.last!)
        }
        .frame(maxWidth: .infinity, maxHeight: .infinity, alignment: .top)
    }

    private func cards(count: Int, detail: WidgetCardDetail) -> some View {
        VStack(alignment: .leading, spacing: WidgetLayout.cardSpacing) {
            ForEach(0..<min(count, celebrations.count), id: \.self) { index in
                WidgetCelebrationCard(celebration: celebrations[index], detail: detail)
            }
            if count < celebrations.count {
                // Zero height: hangs below the last card without taking part
                // in the fitting, so the indicator never costs a card.
                Text("+\(celebrations.count - count)")
                    .font(.caption2)
                    .fontWeight(.semibold)
                    .foregroundColor(.secondary)
                    .padding(.trailing, 4)
                    .frame(maxWidth: .infinity, alignment: .trailing)
                    .frame(height: 0, alignment: .top)
            }
        }
    }
}

struct BreviarWidgetSingleDayView: View {
    let day: LiturgicalDay
    let language: Language

    var body: some View {
        VStack(alignment: .leading, spacing: WidgetLayout.bandSpacing) {
            WidgetDateBand(
                title: singleDayTitle(day.day, language: language),
                colors: distinctColors(of: day)
            )
            WidgetCelebrationCards(celebrations: day.celebrations)
        }
    }
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

/// Replaces WidgetKit's default content margins with insets of our own: the
/// default margins are too wide for the amount of text the widgets show.
@available(iOS 17.0, *)
private struct SystemWidgetContent<Content: View>: View {
    @Environment(\.widgetContentMargins) private var margins
    let content: Content
    let padding: EdgeInsets

    var body: some View {
        content
            .padding(EdgeInsets(
                top: -margins.top,
                leading: -margins.leading,
                bottom: -margins.bottom,
                trailing: -margins.trailing
            ))
            .padding(padding)
    }
}

/// Content of the home screen widgets. The family is a parameter rather than
/// read from the environment so that Tools/WidgetRender can lay out any size
/// outside of WidgetKit.
struct BreviarWidgetSystemView: View {
    let entry: BreviarWidgetEntry
    let family: WidgetFamily
    let language: Language

    var body: some View {
        if family == .systemSmall {
            padded(singleDay, WidgetLayout.singleDayPadding)
        } else {
            padded(
                BreviarWidgetMultiDayView(days: entry.upcomingDays, language: language),
                WidgetLayout.contentPadding
            )
        }
    }

    @ViewBuilder
    private var singleDay: some View {
        if let day = entry.liturgicalDay {
            BreviarWidgetSingleDayView(day: day, language: language)
        } else {
            Text(S.appName.S)
                .font(.headline)
                .frame(maxWidth: .infinity, maxHeight: .infinity)
        }
    }

    @ViewBuilder
    private func padded<Content: View>(_ content: Content, _ padding: EdgeInsets) -> some View {
        if #available(iOS 17.0, *) {
            SystemWidgetContent(content: content, padding: padding)
        } else {
            content.padding(padding)
        }
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
            BreviarWidgetSystemView(entry: entry, family: family, language: currentLiturgicalLanguage)
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
