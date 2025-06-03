//
//  Language.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 05. 10..
//

import Foundation

var currentLiturgicalLanguage = Language.hungarian
var currentUILanguage = Language.hungarian

// For backwards compatibility
var currentLanguage: Language {
    get { return currentUILanguage }
    set { 
        currentUILanguage = newValue
        if newValue != .latin {
            currentLiturgicalLanguage = newValue
        }
    }
}

enum Language : String {
    case czech = "cz"
    case hungarian = "hu"
    case icelandic = "is"
    case latin = "la"
    case slovak = "sk"

    var locale: Locale {
        switch self {
        case .czech:
            return Locale(identifier: "cs_CS")
        case .hungarian:
            return Locale(identifier: "hu_HU")
        case .icelandic:
            return Locale(identifier: "is_IS")
        case .latin:
            return Locale(identifier: "la")
        case .slovak:
            return Locale(identifier: "sk_SK")
        }
    }
    
    var isUILanguage: Bool {
        return self != .latin
    }
    
    var requiresUILanguageSelection: Bool {
        return self == .latin
    }
    
    func dateFormatter(format: String) -> DateFormatter {
        if self == .latin {
            return LatinDateFormatter(format: format)
        }
        let fmt = DateFormatter()
        fmt.dateFormat = format
        fmt.locale = self.locale
        return fmt
    }
}

struct LS {
    var sk: String
    var cz: String
    var hu: String
    var isl: String
    
    var S : String {
        return forLanguage(currentUILanguage)
    }
    
    func forLanguage(_ l: Language) -> String {
        switch l {
        case .slovak:
            return self.sk
        case .czech:
            return self.cz
        case .hungarian:
            return self.hu
        case .icelandic:
            return self.isl
        case .latin:
            // Latin shouldn't be used for UI strings, fall back to Slovak
            return self.sk
        }
    }
    
    func forLanguageCode(_ l: String) -> String {
        let lang = Language(rawValue: l)!
        return self.forLanguage(lang)
    }
}

struct LSLiturgical {
    var sk: String
    var cz: String
    var hu: String
    var isl: String
    var lat: String
    
    var S : String {
        return forLanguage(currentLiturgicalLanguage)
    }
    
    func forLanguage(_ l: Language) -> String {
        switch l {
        case .slovak:
            return self.sk
        case .czech:
            return self.cz
        case .hungarian:
            return self.hu
        case .icelandic:
            return self.isl
        case .latin:
            return self.lat
        }
    }
    
    func forLanguageCode(_ l: String) -> String {
        let lang = Language(rawValue: l)!
        return self.forLanguage(lang)
    }
}

class LatinDateFormatter: DateFormatter, @unchecked Sendable {
    private let latinMonths = [
        "Ianuarius", "Februarius", "Martius", "Aprilis",
        "Maius", "Iunius", "Iulius", "Augustus",
        "September", "October", "November", "December"
    ]
    
    private let latinDays = [
        "Dominica", "Feria II", "Feria III", "Feria IV",
        "Feria V", "Feria VI", "Sabbatum"
    ]
    
    override init() {
        super.init()
        self.locale = Locale(identifier: "la")
    }
    
    init(format: String) {
        super.init()
        self.dateFormat = format
        self.locale = Locale(identifier: "la")
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func string(from date: Date) -> String {
        let calendar = Calendar.current
        let components = calendar.dateComponents([.year, .month, .day, .weekday], from: date)
        
        // Handle different format patterns
        if let format = self.dateFormat {
            var result = format
            
            // Replace month names
            if format.contains("MMMM") {
                let monthName = latinMonths[components.month! - 1]
                result = result.replacingOccurrences(of: "MMMM", with: monthName)
            }
            
            // Replace day names
            if format.contains("EEEE") {
                let dayName = latinDays[components.weekday! - 1]
                result = result.replacingOccurrences(of: "EEEE", with: dayName)
            } else if format.contains("EE") {
                // Short day names for Latin
                let shortDays = ["Dom.", "Fer. II", "Fer. III", "Fer. IV", "Fer. V", "Fer. VI", "Sab."]
                let dayName = shortDays[components.weekday! - 1]
                result = result.replacingOccurrences(of: "EE", with: dayName)
            }
            
            // Replace day
            if format.contains("d") {
                result = result.replacingOccurrences(of: "dd", with: String(format: "%02d", components.day!))
                result = result.replacingOccurrences(of: "d", with: String(components.day!))
            }
            
            // Replace year
            if format.contains("yyyy") {
                result = result.replacingOccurrences(of: "yyyy", with: String(components.year!))
            }
            
            return result
        }
        
        // Default format: "Dies 25 Decembris 2024"
        let day = components.day!
        let month = latinMonths[components.month! - 1]
        let year = components.year!
        
        return "Dies \(day) \(month) \(year)"
    }
}
