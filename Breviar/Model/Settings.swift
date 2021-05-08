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
        
        self.value = (FlagSetOptionState.userDefaultState(entry: entry) & option.value != 0)
    }
    
    @Published var value: Bool {
        didSet {
            var v = FlagSetOptionState.userDefaultState(entry: entry)
            if value {
                v |= option.value
            } else {
                v &= ~option.value
            }
            UserDefaults.standard.set(v, forKey: entry.name)
        }
    }
    
    static private func userDefaultState(entry: SettingsEntry) -> Int {
        if let v = UserDefaults.standard.object(forKey: entry.name), let vi = v as? Int {
            return vi
        } else {
            return entry.defaultValue
        }
    }
}

class StringChoiceState : ObservableObject {
    let entry: SettingsEntry
    
    init(entry: SettingsEntry) {
        self.entry = entry
        if let v = UserDefaults.standard.object(forKey: entry.name), let vi = v as? Int {
            self.value = vi
        } else {
            // Set either entry.defaultValue or first option value
            self.value = entry.options[0].value
            for option in entry.options {
                if option.value == entry.defaultValue {
                    self.value = entry.defaultValue
                }
            }
        }
    }
    
    @Published var value: Int {
        didSet {
            UserDefaults.standard.set(value, forKey: entry.name)
        }
    }
}
