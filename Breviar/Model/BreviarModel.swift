//
//  BreviarModel.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 01. 17..
//

import SwiftUI

func getMonthForDay(_ day: Date) -> Date {
    let calendar = Calendar.current
    var comps = DateComponents()
    comps.year = calendar.component(.year, from: day)
    comps.month = calendar.component(.month, from: day)
    comps.day = 1
    return calendar.date(from: comps)!
}

func dateFrom(year: Int, month: Int, day: Int) -> Date {
    let calendar = Calendar.current
    var comps = DateComponents()
    comps.year = year
    comps.month = month
    comps.day = day
    return calendar.date(from: comps)!
}

class BreviarModel : ObservableObject {
    private var dataSource: BreviarDataSource
    @Published var dataSourceOptions: DataSourceOptions?
    @Published var dataSourceOptionsNeeded: Bool
    @Published var dataSourceOptionsWizardStage: DataSourceWizardState = .chooseLanguage
    
    @Published var day: Day
    @Published var dayState: LoadingState<LiturgicalDay> = .idle
    @Published var selectedCelebration: String = ""
    
    @Published var month: Month
    @Published var monthState: LoadingState<LiturgicalMonth> = .idle
    
    @Published var prayerText: LoadingState<String> = .idle
    
    @Published var settingsEntries: LoadingState<[SettingsEntry]> = .idle
    @Published var textOptions: TextOptions
    
    init(dataSource: BreviarDataSource) {
        let now = Date()
        self.dataSource = dataSource
        self.day = Day(fromDate: now)
        self.month = Month(fromDate: now)
        self.textOptions = TextOptions()
        
        let dataSourceOptions = DataSourceOptions.savedOptions
        self.dataSourceOptions = dataSourceOptions
        self.dataSourceOptionsNeeded = dataSourceOptions == nil
    }
    
    func setDataSourceOptions(_ options: DataSourceOptions) {
        options.save()
        self.dataSourceOptions = options
        self.dataSourceOptionsNeeded = false
        self.dataSource.setOptions(options)
        currentLanguage = options.language
        self.reload()
    }
    
    func reload() {
        self.dayState = .idle
        self.monthState = .idle
        self.settingsEntries = .idle
        _ = self.load()
    }
    
    func load() -> BreviarModel {
        switch self.dayState {
        case .idle:
            self.loadDay(self.day)
            self.loadMonth(self.month)
        default:
            break
        }
        
        switch self.settingsEntries {
        case .idle:
            self.loadSettingsEntries()
        default:
            break
        }
        
        return self
    }
    
    static func cgiModel() -> BreviarModel {
        return BreviarModel(dataSource: CGIDataSource()).load()
    }
    
    static func testModel() -> BreviarModel {
        return BreviarModel(dataSource: TestDataSource()).load()
    }
    
    func loadDay(_ day: Day) {
        self.day = day
        self.dayState = .loading
        self.selectedCelebration = ""
        self.prayerText = .idle
        
        self.dataSource.getLiturgicalDay(day: day) { (liturgicalDay, error) in
            if error == nil {
                if let liturgicalDay = liturgicalDay {
                    self.dayState = .loaded(liturgicalDay)
                    if liturgicalDay.celebrations.count > 0 {
                        self.selectedCelebration = liturgicalDay.celebrations[0].id
                    }
                }
            } else {
                self.dayState = .failed(error!)
            }
        }
    }
    
    func loadMonth(_ month: Month) {
        self.month = month
        self.monthState = .loading
        
        self.dataSource.getLiturgicalMonth(month: month) { (liturgicalMonth, error) in
            if error == nil {
                if let liturgicalMonth = liturgicalMonth {
                    self.monthState = .loaded(liturgicalMonth)
                }
            } else {
                self.monthState = .failed(error!)
            }
        }
    }
    
    func jumpTo(day: LiturgicalDay, celebration: Celebration) {
        self.day = day.day
        self.dayState = .loaded(day)
        self.selectedCelebration = celebration.id
        self.prayerText = .idle
    }
    
    func getCurrentCelebration() -> (LiturgicalDay, Celebration)? {
        switch self.dayState {
        case .loaded(let day):
            for celebration in day.celebrations {
                if celebration.id == self.selectedCelebration {
                    return (day, celebration)
                }
            }
            return nil
        default:
            return nil
        }
    }
    
    func getPrayersForSelectedCelebration() -> [Prayer] {
        if let (day, celebration) = getCurrentCelebration() {
            return [
                Prayer(day: day.day, celebration: celebration, type: .invitatory),
                Prayer(day: day.day, celebration: celebration, type: .officeOfReadings),
                Prayer(day: day.day, celebration: celebration, type: .morningPrayer),
                Prayer(day: day.day, celebration: celebration, type: .midMorningPrayer),
                Prayer(day: day.day, celebration: celebration, type: .midDayPrayer),
                Prayer(day: day.day, celebration: celebration, type: .midAfternoonPrayer),
                Prayer(day: day.day, celebration: celebration, type: .eveningPrayer),
                Prayer(day: day.day, celebration: celebration, type: .compline),
            ]
        } else {
            return []
        }
    }
    
    func loadPrayer(_ prayer: Prayer, opts: [String: String] = [:]) {
        if let (day, celebration) = self.getCurrentCelebration() {
            self.dataSource.getPrayerText(day: day, celebration: celebration, prayerType: prayer.type, opts: opts) { (text, error) in
                if error == nil {
                    self.prayerText = .loaded(text!)
                } else {
                    self.prayerText = .failed(error!)
                }
            }
        }
    }
    
    func handlePrayerLink(prayer: Prayer, url: URL) {
        let parsedLink = self.dataSource.parsePrayerLink(url: url)
        switch parsedLink {
        case .prayerTextLink(let opts):
            self.savePrayerOptions(opts)
            self.loadPrayer(prayer)
        default:
            break
        }
    }
    
    func savePrayerOptions(_ opts: [String: String]) {
        for optName in ["o0", "o1", "o3", "o4", "o5"] {
            guard let entry = getSettingsEntry(name: optName) else { continue }
            if let optVal = opts[optName], let optInt = Int(optVal) {
                print("Saving option: \(optName)=\(optInt)")
                entry.setUserSettings(optInt)
            } else {
                let defaultValue = entry.normalizedDefaultValue()
                print("Reverting option: \(optName)=\(defaultValue)")
                entry.setUserSettings(defaultValue)
            }
        }
    }
    
    func unloadPrayer() {
        self.prayerText = .idle
    }
    
    func loadSettingsEntries() {
        self.dataSource.getSettingsEntries { (entries, error) in
            if error == nil {
                // Save entries to UserDefaults
                for entry in entries! {
                    entry.setUserSettings(entry.getUserSettings())
                }
                
                self.settingsEntries = .loaded(entries!)
            } else {
                self.settingsEntries = .failed(error!)
            }
        }
    }

    func getSettingsEntry(name: String) -> SettingsEntry? {
        switch self.settingsEntries {
        case .loaded(let entries):
            for entry in entries {
                if entry.name == name {
                    return entry
                }
            }
            return nil
        default:
            return nil
        }
    }
    
}

enum LoadingState<Value> {
    case idle
    case loading
    case failed(Error)
    case loaded(Value)
}
