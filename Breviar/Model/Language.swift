//
//  Language.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 05. 10..
//

import Foundation

var currentLanguage = Language.hungarian

enum Language : String {
    case czech = "cz"
    case hungarian = "hu"
    case slovak = "sk"
    
    var locale: Locale {
        switch self {
        case .czech:
            return Locale(identifier: "cs_CS")
        case .hungarian:
            return Locale(identifier: "hu_HU")
        case .slovak:
            return Locale(identifier: "sk_SK")
        }
    }
    
    func dateFormatter(format: String) -> DateFormatter {
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
    
    var S : String {
        return forLanguage(l: currentLanguage)
    }
    
    func forLanguage(l: Language) -> String {
        switch l {
        case .slovak:
            return self.sk
        case .czech:
            return self.cz
        case .hungarian:
            return self.hu
        }
    }
}
