//
//  WidgetDataReader.swift
//  BreviarWidget
//

import Foundation

struct WidgetDataReader {
    static func readCalendarData() -> [LiturgicalDay] {
        guard let url = BreviarSharedData.cachedCalendarURL,
              let data = try? Data(contentsOf: url),
              let calendarData = try? JSONDecoder().decode(WidgetCalendarData.self, from: data) else {
            return []
        }
        return calendarData.days.map { $0.toLiturgicalDay() }
    }

    static func readLanguageSettings() -> (Language, Language)? {
        guard let defaults = BreviarSharedData.sharedDefaults,
              let langRaw = defaults.string(forKey: BreviarSharedData.languageKey),
              let lang = Language(rawValue: langRaw),
              let uiLangRaw = defaults.string(forKey: BreviarSharedData.uiLanguageKey),
              let uiLang = Language(rawValue: uiLangRaw) else {
            return nil
        }
        return (lang, uiLang)
    }

    static func liturgicalDay(for date: Date) -> LiturgicalDay? {
        let target = Day(fromDate: date)
        let days = readCalendarData()
        return days.first { $0.day == target }
    }
}
