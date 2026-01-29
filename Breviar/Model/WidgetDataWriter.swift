//
//  WidgetDataWriter.swift
//  Breviar
//

import Foundation
import WidgetKit

class WidgetDataWriter {
    static let shared = WidgetDataWriter()

    func writeLiturgicalMonth(_ liturgicalMonth: LiturgicalMonth) {
        guard let url = BreviarSharedData.cachedCalendarURL else { return }

        let newDays = liturgicalMonth.days.map { WidgetLiturgicalDay(from: $0) }
        let targetMonth = liturgicalMonth.month.month
        let targetYear = liturgicalMonth.month.year

        var existingDays: [WidgetLiturgicalDay] = []
        if let data = try? Data(contentsOf: url),
           let existing = try? JSONDecoder().decode(WidgetCalendarData.self, from: data) {
            existingDays = existing.days
        }

        existingDays.removeAll { $0.year == targetYear && $0.month == targetMonth }
        existingDays.append(contentsOf: newDays)

        let today = Day(fromDate: Date())
        existingDays.removeAll {
            let day = Day(year: $0.year, month: $0.month, day: $0.day)
            return day.daysSinceEpoch < today.daysSinceEpoch
        }

        existingDays.sort {
            let d1 = Day(year: $0.year, month: $0.month, day: $0.day)
            let d2 = Day(year: $1.year, month: $1.month, day: $1.day)
            return d1.daysSinceEpoch < d2.daysSinceEpoch
        }

        let calendarData = WidgetCalendarData(days: existingDays)
        if let encoded = try? JSONEncoder().encode(calendarData) {
            try? encoded.write(to: url, options: .atomic)
        }
    }

    func writeLanguageSettings(language: Language, uiLanguage: Language, calendar: String) {
        guard let defaults = BreviarSharedData.sharedDefaults else { return }
        defaults.set(language.rawValue, forKey: BreviarSharedData.languageKey)
        defaults.set(uiLanguage.rawValue, forKey: BreviarSharedData.uiLanguageKey)
        defaults.set(calendar, forKey: BreviarSharedData.calendarKey)
    }

    func reloadWidgets() {
        WidgetCenter.shared.reloadAllTimelines()
    }
}
