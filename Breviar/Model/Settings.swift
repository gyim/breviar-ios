//
//  Settings.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 04. 16..
//

import SwiftUI

// MARK: - Text options

class TextOptions: ObservableObject {
    static let notificationName = NSNotification.Name.init(rawValue: "BreviarTextOptionsChanged")
    
    @Published var fontName = fontNames[0] {
        didSet {
            NotificationCenter.default.post(name: TextOptions.notificationName, object: self)
        }
    }
    
    @Published var fontSize = 100.0 {
        didSet {
            NotificationCenter.default.post(name: TextOptions.notificationName, object: self)
        }
    }
    
    @Published var colorScheme = ColorScheme.automatic {
        // SwiftUI workaround: there is no reliable way to set color scheme to .unspecified, so we use UIKit instead
        didSet {
            let window = UIApplication.shared.windows.first
            
            switch colorScheme {
            case .automatic:
                window?.overrideUserInterfaceStyle = .unspecified
            case .light:
                window?.overrideUserInterfaceStyle = .light
            case .dark:
                window?.overrideUserInterfaceStyle = .dark
            }
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
