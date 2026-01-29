//
//  WidgetDataModels.swift
//  Breviar
//

import Foundation

struct WidgetCelebration: Codable {
    var id: String
    var title: String
    var subtitle: String
    var liturgicalColorRawValue: Int
}

struct WidgetLiturgicalDay: Codable {
    var year: Int
    var month: Int
    var day: Int
    var celebrations: [WidgetCelebration]
}

struct WidgetCalendarData: Codable {
    var days: [WidgetLiturgicalDay]
}

extension WidgetCelebration {
    init(from celebration: Celebration) {
        self.id = celebration.id
        self.title = celebration.title
        self.subtitle = celebration.subtitle
        self.liturgicalColorRawValue = celebration.liturgicalColor.rawValue
    }

    func toLiturgicalColor() -> LiturgicalColor {
        return LiturgicalColor(rawValue: liturgicalColorRawValue) ?? .white
    }

    func toCelebration() -> Celebration {
        return Celebration(
            id: id,
            title: title,
            subtitle: subtitle,
            liturgicalColor: toLiturgicalColor()
        )
    }
}

extension WidgetLiturgicalDay {
    init(from liturgicalDay: LiturgicalDay) {
        self.year = liturgicalDay.day.year
        self.month = liturgicalDay.day.month
        self.day = liturgicalDay.day.day
        self.celebrations = liturgicalDay.celebrations.map { WidgetCelebration(from: $0) }
    }

    func toLiturgicalDay() -> LiturgicalDay {
        return LiturgicalDay(
            day: Day(year: year, month: month, day: day),
            celebrations: celebrations.map { $0.toCelebration() }
        )
    }
}

extension WidgetCalendarData {
    init(from liturgicalMonth: LiturgicalMonth) {
        self.days = liturgicalMonth.days.map { WidgetLiturgicalDay(from: $0) }
    }
}
