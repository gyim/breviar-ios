//
//  AppConfig.swift
//  Breviar
//
//  Single-language app configuration
//

import Foundation

struct AppConfig {
    static let SINGLE_LANGUAGE_MODE = true
    static let FIXED_LANGUAGE = Language.hungarian
    static let FIXED_UI_LANGUAGE = Language.hungarian
    static let FIXED_CALENDAR = "hu"
    static let MIGRATION_APP_STORE_URL = "https://apps.apple.com/sk/app/brevi%C3%A1r/id818787573"
    static let SHOW_MIGRATION_NOTICE = true
    
    // Migration banner text configuration - can be easily changed for different language versions
    static var migrationTitle: String { S.migrationTitle.forLanguage(FIXED_UI_LANGUAGE) }
    static var migrationMessage: String { S.migrationMessage.forLanguage(FIXED_UI_LANGUAGE) }
    static var migrationDownloadButton: String { S.migrationDownloadButton.forLanguage(FIXED_UI_LANGUAGE) }
}