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

struct SettingsEntry {
    var name: String
    var label: String
    var type: SettingsEntryType
    var defaultValue: Int
    var options: [SettingsEntryOption]
}

struct SettingsEntryOption {
    var label: String
    var value: Int
}
