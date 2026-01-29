//
//  SharedConstants.swift
//  Breviar
//

import Foundation

struct BreviarSharedData {
    static let appGroupIdentifier = "group.sk.breviar.breviar-sk"

    static var sharedDefaults: UserDefaults? {
        return UserDefaults(suiteName: appGroupIdentifier)
    }

    static var sharedContainerURL: URL? {
        return FileManager.default.containerURL(forSecurityApplicationGroupIdentifier: appGroupIdentifier)
    }

    static var cachedCalendarURL: URL? {
        return sharedContainerURL?.appendingPathComponent("cached_liturgical_calendar.json")
    }

    static let languageKey = "widget_language"
    static let uiLanguageKey = "widget_ui_language"
    static let calendarKey = "widget_calendar"
}
