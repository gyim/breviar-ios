//
//  Settings.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 04. 16..
//

import SwiftUI
import WidgetKit

// MARK: - Data source options

enum DataSourceWizardContext {
    case initialSetup
    case settingsModification
}

enum DataSourceWizardState {
    case chooseLanguage
    case chooseCalendar
    case chooseDataSourceType
}

enum DataSourceType: String {
    case alwaysCGI = "alwaysCGI"
    case alwaysNetwork = "alwaysNetwork"
    case networkOnWifi = "networkOnWifi"
    
    var localizedDescription: String {
        switch self {
        case .alwaysCGI:
            return S.never.S
        case .alwaysNetwork:
            return S.always.S
        case .networkOnWifi:
            return S.onlyOnWifi.S
        }
    }
}

struct DataSourceOptions {
    var dataSourceType: DataSourceType
    var language: Language
    var uiLanguage: Language
    var calendar: String
    
    static var savedOptions: DataSourceOptions? {
        let userDefaults = UserDefaults.standard
        
        if let languageS = userDefaults.string(forKey: "j"),
           let language = Language(rawValue: languageS),
           let uiLanguageS = userDefaults.string(forKey: "ui_lang"),
           let uiLanguage = Language(rawValue: uiLanguageS),
           let calendar = userDefaults.string(forKey: "k"),
           let dataSourceTypeS = userDefaults.string(forKey: "ds"),
           let dataSourceType = DataSourceType(rawValue: dataSourceTypeS) {
            
            var validatedCalendar = calendar
            
            // Verify the saved calendar is valid for the current language
            if !language.availableCalendars.contains(calendar) {
                // Invalid calendar for this language, use default
                validatedCalendar = language.defaultCalendar
                
                // Save the corrected settings
                var correctedOptions = DataSourceOptions(dataSourceType: dataSourceType, language: language, uiLanguage: uiLanguage, calendar: validatedCalendar)
                correctedOptions.save()
            }
            
            return DataSourceOptions(dataSourceType: dataSourceType, language: language, uiLanguage: uiLanguage, calendar: validatedCalendar)
        } else {
            return nil
        }
    }
    
    func save() {
        let userDefaults = UserDefaults.standard

        userDefaults.setValue(language.rawValue, forKey: "j")
        userDefaults.setValue(calendar, forKey: "k")
        userDefaults.setValue(dataSourceType.rawValue, forKey: "ds")
        userDefaults.setValue(uiLanguage.rawValue, forKey: "ui_lang")

        WidgetDataWriter.shared.writeLanguageSettings(
            language: language,
            uiLanguage: uiLanguage,
            calendar: calendar
        )
        WidgetCenter.shared.reloadAllTimelines()
    }
}

// MARK: - Bible reference links

enum BibleLinkMode: String, CaseIterable {
    case off = "off"
    case website = "website"
    case bibleCom = "bibleCom"

    static let userDefaultsKey = "bibleLinkMode"

    // Bits of the CGI option "o0" that control Bible references
    static let referencesFlag = 2
    static let bibleComFlag = 4096

    var localizedDescription: String {
        switch self {
        case .off:
            return S.disabled.S
        case .website:
            return currentLiturgicalLanguage.bibleWebsiteHost ?? S.disabled.S
        case .bibleCom:
            return "bible.com"
        }
    }

    // Force parameters that make the CGI generate the matching links
    var cgiOptions: [String: String] {
        switch self {
        case .off:
            return ["of0r": "0"]
        case .website:
            return ["of0r": "1", "of0bc": "0"]
        case .bibleCom:
            return ["of0r": "1", "of0bc": "1"]
        }
    }

    // What the user chose, regardless of whether the current language supports it. Installations
    // that predate this setting are migrated from the CGI option bits they used before.
    static var preference: BibleLinkMode {
        return storedMode() ?? migratedMode(for: currentLanguage())
    }

    // The mode in effect for the selected breviary language
    static var current: BibleLinkMode {
        let language = currentLanguage()
        let mode = preference
        return language.availableBibleLinkModes.contains(mode) ? mode : language.defaultBibleLinkMode
    }

    static func save(_ mode: BibleLinkMode) {
        UserDefaults.standard.setValue(mode.rawValue, forKey: userDefaultsKey)
    }

    // Freezes the migrated value, so that it cannot drift once "o0" is rewritten
    static func savePreferenceIfMissing() {
        if storedMode() == nil {
            save(preference)
        }
    }

    private static func currentLanguage() -> Language {
        return DataSourceOptions.savedOptions?.language ?? currentLiturgicalLanguage
    }

    private static func storedMode() -> BibleLinkMode? {
        guard let s = UserDefaults.standard.string(forKey: userDefaultsKey) else { return nil }
        return BibleLinkMode(rawValue: s)
    }

    private static func migratedMode(for language: Language) -> BibleLinkMode {
        guard let o0 = UserDefaults.standard.object(forKey: "o0") as? Int else {
            return language.defaultBibleLinkMode
        }
        if o0 & referencesFlag == 0 {
            return .off
        }
        return o0 & bibleComFlag != 0 ? .bibleCom : .website
    }
}

extension Language {
    // Host of the national Bible website the CGI links to, or nil if it has none for this
    // language. Mirrors bible_references_default[] in breviar-cgi/source/bible.h: Czech has no
    // URL configured there, and the Latin one (vatican.va) no longer resolves.
    var bibleWebsiteHost: String? {
        switch self {
        case .slovak:
            return "dkc.kbs.sk"
        case .hungarian:
            return "szentiras.eu"
        default:
            return nil
        }
    }

    // Icelandic has no book abbreviations in the CGI, so bible.com references cannot be built
    var supportsBibleCom: Bool {
        return self != .icelandic
    }

    var availableBibleLinkModes: [BibleLinkMode] {
        var modes: [BibleLinkMode] = [.off]
        if bibleWebsiteHost != nil {
            modes.append(.website)
        }
        if supportsBibleCom {
            modes.append(.bibleCom)
        }
        return modes
    }

    var defaultBibleLinkMode: BibleLinkMode {
        if bibleWebsiteHost != nil {
            return .website
        }
        return supportsBibleCom ? .bibleCom : .off
    }
}

// MARK: - Fullscreen mode options

enum FullscreenMode: String, CaseIterable {
    case singleTap = "singleTap"
    case doubleTap = "doubleTap"
    case disabled = "disabled"
    
    var localizedDescription: String {
        switch self {
        case .singleTap:
            return S.oneTap.S
        case .doubleTap:
            return S.doubleTap.S
        case .disabled:
            return S.disabled.S
        }
    }
}

class PrayerScreenSettings: ObservableObject {
    @Published var fullscreenMode = FullscreenMode.singleTap {
        didSet {
            UserDefaults.standard.setValue(fullscreenMode.rawValue, forKey: "prayerScreenSettings.fullscreenMode")
        }
    }
    
    // Only explicit user choices are stored: a language that does not support the chosen mode
    // falls back to its default without overwriting the preference
    @Published private(set) var bibleLinkMode = BibleLinkMode.current

    func setBibleLinkMode(_ mode: BibleLinkMode) {
        BibleLinkMode.save(mode)
        self.bibleLinkMode = mode
    }

    func refreshBibleLinkMode() {
        self.bibleLinkMode = BibleLinkMode.current
    }

    init() {
        if let fullscreenModeString = UserDefaults.standard.string(forKey: "prayerScreenSettings.fullscreenMode"),
           let fullscreenMode = FullscreenMode(rawValue: fullscreenModeString) {
            self.fullscreenMode = fullscreenMode
        }

        BibleLinkMode.savePreferenceIfMissing()
    }
}

// MARK: - Text options

class TextOptions: ObservableObject {
    static let notificationName = NSNotification.Name.init(rawValue: "BreviarTextOptionsChanged")
    
    @Published var fontName = fontNames[0] {
        didSet {
            NotificationCenter.default.post(name: TextOptions.notificationName, object: self)
            UserDefaults.standard.setValue(fontName.systemName, forKey: "textOptions.fontName")
        }
    }
    
    @Published var fontSize = 100.0 {
        didSet {
            NotificationCenter.default.post(name: TextOptions.notificationName, object: self)
            UserDefaults.standard.setValue(fontSize, forKey: "textOptions.fontSize")
        }
    }
    
    @Published var colorScheme = ColorScheme.automatic {
        // SwiftUI workaround: there is no reliable way to set color scheme to .unspecified, so we use UIKit instead
        didSet {
            let window = UIApplication.shared.windows.first
            window?.overrideUserInterfaceStyle = colorScheme.uikitColorScheme
            UserDefaults.standard.setValue(colorScheme.rawValue, forKey: "colorScheme")
        }
    }
    
    @Published var isBold = false {
        didSet {
            NotificationCenter.default.post(name: TextOptions.notificationName, object: self)
            UserDefaults.standard.setValue(isBold, forKey: "textOptions.isBold")
        }
    }
    
    init() {
        let userDefaults = UserDefaults.standard
        
        if let fontSystemName = userDefaults.string(forKey: "textOptions.fontName") {
            for fontName in fontNames {
                if fontName.systemName == fontSystemName {
                    self.fontName = fontName
                }
            }
        }
        
        let fontSize = userDefaults.double(forKey: "textOptions.fontSize")
        if fontSize > 0 {
            self.fontSize = fontSize
        }
        
        self.isBold = userDefaults.bool(forKey: "textOptions.isBold")
        
        if let colorSchemeName = userDefaults.string(forKey: "colorScheme"),
           let colorScheme = ColorScheme(rawValue: colorSchemeName) {
            self.colorScheme = colorScheme
        }
    }
}

struct FontName : Identifiable {
    var name: String
    var systemName: String
    
    var id : String {
        return name
    }
}

let fontNames = [
    FontName(name: "Georgia", systemName: "Georgia"),
    FontName(name: "Helvetica", systemName: "HelveticaNeue"),
    FontName(name: "Helvetica Light", systemName: "HelveticaNeue-Light"),
    FontName(name: "Times", systemName: "TimesNewRomanPSMT"),
    FontName(name: "Baskerville", systemName: "Baskerville"),
    FontName(name: "Didot", systemName: "Didot"),
    FontName(name: "Gill Sans", systemName: "GillSans"),
    FontName(name: "Hoefler Text", systemName: "HoeflerText-Regular"),
    FontName(name: "Palatino", systemName: "Palatino-Roman"),
    FontName(name: "Trebuchet MS", systemName: "TrebuchetMS"),
    FontName(name: "Verdana", systemName: "Verdana"),
]

// MARK: - Settings entries

enum SettingsEntryType {
    case flagSet
    case stringChoice
}

struct SettingsEntry: Identifiable {
    var name: String
    var label: String
    var type: SettingsEntryType
    var defaultValue: Int
    var options: [SettingsEntryOption]
    var visible: Bool
    
    var id: String {
        return name
    }
    
    func getUserSettings() -> Int {
        if let v = UserDefaults.standard.object(forKey: self.name), let vi = v as? Int {
            return vi
        } else {
            return self.normalizedDefaultValue()
        }
    }
    
    func setUserSettings(_ value: Int) {
        UserDefaults.standard.set(value, forKey: self.name)
    }
    
    func clearUserSettings() {
        UserDefaults.standard.removeObject(forKey: self.name)
    }
    
    func normalizedDefaultValue() -> Int {
        switch type {
        case .flagSet:
            return self.defaultValue
        case .stringChoice:
            // Set either default value or first option value
            var v = self.defaultValue
            if self.options.count > 0 {
                v = self.options[0].value
                for option in self.options {
                    if option.value == self.defaultValue {
                        v = self.defaultValue
                    }
                }
            }
            return v
        }
    }
}

struct SettingsEntryOption: Identifiable {
    var label: String
    var value: Int
    
    var id: String {
        return String(value)
    }
}

// MARK: - Handling user defaults

class FlagSetOptionState : ObservableObject {
    let entry: SettingsEntry
    let option: SettingsEntryOption
    
    init(entry: SettingsEntry, option: SettingsEntryOption) {
        self.entry = entry
        self.option = option
        
        self.value = (entry.getUserSettings() & option.value != 0)
    }
    
    @Published var value: Bool {
        didSet {
            var v = self.entry.getUserSettings()
            if value {
                v |= option.value
            } else {
                v &= ~option.value
            }
            self.entry.setUserSettings(v)
        }
    }
}

class StringChoiceState : ObservableObject {
    let entry: SettingsEntry
    
    init(entry: SettingsEntry) {
        self.entry = entry
        self.value = entry.getUserSettings()
    }
    
    @Published var value: Int {
        didSet {
            self.entry.setUserSettings(value)
        }
    }
}
