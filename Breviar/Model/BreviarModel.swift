//
//  BreviarModel.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 01. 17..
//

import SwiftUI
import WidgetKit

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

class BreviarModel : NSObject, ObservableObject {
    private var dataSource: BreviarDataSource
    private var liturgicalDataNeedsReload = false
    private var isUpdatingFromPrayerLink = false
    @Published var dataSourceOptions: DataSourceOptions?
    @Published var dataSourceOptionsNeeded: Bool
    @Published var dataSourceOptionsWizardStage: DataSourceWizardState = .chooseLanguage
    @Published var dataSourceOptionsWizardContext: DataSourceWizardContext = .initialSetup
    
    @Published var day: Day
    @Published var dayState: LoadingState<LiturgicalDay> = .idle
    @Published var selectedCelebration: String = ""
    
    @Published var month: Month
    @Published var monthState: LoadingState<LiturgicalMonth> = .idle
    
    @Published var prayerText: LoadingState<String> = .idle
    @Published var ttsPrayerText: LoadingState<String> = .idle
    
    @Published var aboutPage: LoadingState<String> = .idle
    
    @Published var settingsEntries: LoadingState<[SettingsEntry]> = .idle
    @Published var textOptions: TextOptions
    @Published var prayerScreenSettings: PrayerScreenSettings
    
    @Published var navigationTrigger: NavigationTarget? = nil
    @Published var pendingNavigation: NavigationTarget? = nil

    @Published var externalLink: IdentifiableURL? = nil
    
    // Generation counters: a load started later always wins, even if an earlier one
    // (e.g. a slow remote attempt) delivers its result afterwards.
    private var dayLoadID = 0
    private var monthLoadID = 0
    private var prayerLoadID = 0
    private var ttsLoadID = 0
    private var settingsLoadID = 0

    var networkStatus: NetworkStatus {
        return self.dataSource.networkStatus
    }

    init(dataSource: BreviarDataSource) {
        let now = Date()
        self.dataSource = dataSource
        self.day = Day(fromDate: now)
        self.month = Month(fromDate: now)
        self.textOptions = TextOptions()
        self.prayerScreenSettings = PrayerScreenSettings()
        
        let dataSourceOptions = DataSourceOptions.savedOptions
        self.dataSourceOptions = dataSourceOptions
        self.dataSourceOptionsNeeded = dataSourceOptions == nil
        
        super.init()
        
        // Observe liturgical option changes in UserDefaults
        ["o0", "o1", "o3", BibleLinkMode.userDefaultsKey].forEach { key in
            UserDefaults.standard.addObserver(self, forKeyPath: key, options: .new, context: nil)
        }
    }
    
    func setDataSourceOptions(_ options: DataSourceOptions) {
        options.save()
        self.dataSourceOptions = options
        self.dataSourceOptionsNeeded = false
        self.dataSource.setOptions(options)
        
        // Set both liturgical and UI languages
        currentLiturgicalLanguage = options.language
        currentUILanguage = options.uiLanguage

        // The available modes depend on the language, so re-validate the stored one
        self.prayerScreenSettings.refreshBibleLinkMode()
        
        self.clearCalendarSettings()
        self.reload()
    }
    
    func reload(policy: DataSourcePolicy = .automatic) {
        self.dayState = .idle
        self.monthState = .idle
        self.settingsEntries = .idle
        self.aboutPage = .idle
        _ = self.load(policy: policy)
    }
    
    func reloadLiturgicalData() {
        self.dayState = .idle
        self.monthState = .idle
        self.prayerText = .idle
        self.ttsPrayerText = .idle
        _ = self.load()
    }
    
    func checkForLiturgicalDataReload() {
        if liturgicalDataNeedsReload {
            liturgicalDataNeedsReload = false
            reloadLiturgicalData()
        }
    }
    
    func load(policy: DataSourcePolicy = .automatic) -> BreviarModel {
        switch self.dayState {
        case .idle:
            self.loadDay(self.day, policy: policy)
            self.loadMonth(self.month, policy: policy)
            self.loadNextMonthForWidgetCache()
        default:
            break
        }

        switch self.settingsEntries {
        case .idle:
            self.loadSettingsEntries(policy: policy)
        default:
            break
        }

        return self
    }
    
    static func cgiModel() -> BreviarModel {
        return BreviarModel(dataSource: CGIDataSource()).load()
    }
    
    static func testModel() -> BreviarModel {
        #if DEBUG
        return BreviarModel(dataSource: TestDataSource()).load()
        #else
        return cgiModel()
        #endif
    }
    
    func loadDay(_ day: Day, policy: DataSourcePolicy = .automatic) {
        self.day = day
        self.dayState = .loading
        self.selectedCelebration = ""
        self.prayerText = .idle
        
        self.dayLoadID += 1
        let loadID = self.dayLoadID

        let retry: (DataSourcePolicy) -> Void = { policy in
            self.dayState = .loading
            self.loadDay(day, policy: policy)
        }
        
        self.dataSource.getLiturgicalDay(day: day, policy: policy) { (liturgicalDay, error) in
            guard loadID == self.dayLoadID else { return }
            if error == nil {
                if let liturgicalDay = liturgicalDay {
                    self.dayState = .loaded(liturgicalDay)
                    if liturgicalDay.celebrations.count > 0 {
                        self.selectedCelebration = liturgicalDay.celebrations[0].id
                    }
                }
            } else {
                self.dayState = .failed(error!, retry)
            }
        }
    }
    
    func loadMonth(_ month: Month, policy: DataSourcePolicy = .automatic) {
        self.month = month
        self.monthState = .loading

        self.monthLoadID += 1
        let loadID = self.monthLoadID

        let retry: (DataSourcePolicy) -> Void = { policy in
            self.monthState = .loading
            self.loadMonth(month, policy: policy)
        }

        self.dataSource.getLiturgicalMonth(month: month, policy: policy) { (liturgicalMonth, error) in
            guard loadID == self.monthLoadID else { return }
            if error == nil {
                if let liturgicalMonth = liturgicalMonth {
                    self.monthState = .loaded(liturgicalMonth)
                    WidgetDataWriter.shared.writeLiturgicalMonth(liturgicalMonth)
                    WidgetDataWriter.shared.reloadWidgets()
                }
            } else {
                self.monthState = .failed(error!, retry)
            }
        }
    }
    
    private func loadNextMonthForWidgetCache() {
        let nextMonth = self.month.monthByAdding(months: 1)
        self.dataSource.getLiturgicalMonth(month: nextMonth, policy: .forceLocal) { (liturgicalMonth, _) in
            if let liturgicalMonth = liturgicalMonth {
                WidgetDataWriter.shared.writeLiturgicalMonth(liturgicalMonth)
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
    
    func loadPrayer(_ prayer: Prayer, opts: [String: String] = [:], policy: DataSourcePolicy = .automatic) {
        self.prayerLoadID += 1
        let loadID = self.prayerLoadID

        let retry: (DataSourcePolicy) -> Void = { policy in
            self.prayerText = .loading
            self.loadPrayer(prayer, opts: opts, policy: policy)
        }

        if let (day, celebration) = self.getCurrentCelebration() {
            self.dataSource.getPrayerText(day: day, celebration: celebration, prayerType: prayer.type, opts: opts, policy: policy) { (text, error) in
                guard loadID == self.prayerLoadID else { return }
                if error == nil {
                    self.prayerText = .loaded(text!)
                } else {
                    self.prayerText = .failed(error!, retry)
                }
            }
        }
    }
    
    func loadTTSPrayer(_ prayer: Prayer, opts: [String: String] = [:], policy: DataSourcePolicy = .automatic) {
        self.ttsLoadID += 1
        let loadID = self.ttsLoadID

        let retry: (DataSourcePolicy) -> Void = { policy in
            self.ttsPrayerText = .loading
            self.loadTTSPrayer(prayer, opts: opts, policy: policy)
        }

        if let (day, celebration) = self.getCurrentCelebration() {
            self.dataSource.getTTSPrayerText(day: day, celebration: celebration, prayerType: prayer.type, opts: opts, policy: policy) { (text, error) in
                guard loadID == self.ttsLoadID else { return }
                if error == nil {
                    self.ttsPrayerText = .loaded(text!)
                } else {
                    self.ttsPrayerText = .failed(error!, retry)
                }
            }
        }
    }
    
    func loadAboutPage() {
        self.dataSource.getAboutPage { text, error in
            let txt = text!
                .replacingOccurrences(of: "[VERSION]", with: Bundle.main.infoDictionary?["CFBundleShortVersionString"] as! String)
                .replacingOccurrences(of: "[PROJECT-URL]", with: S.webURL.S)
                .replacingOccurrences(of: "[E-MAIL]", with: "apple@breviar.sk")
                .replacingOccurrences(of: "[APP-NAME]", with: S.appName.S)
                .replacingOccurrences(of: "[PROJECT-SOURCE-STORAGE]", with: "GitHub")
                .replacingOccurrences(of: "[PROJECT-SOURCE-URL]", with: "https://github.com/gyim/breviar-ios")
                .replacingOccurrences(of: "[SPECIAL-CREDITS]", with: "")
                .replacingOccurrences(of: "[PLATFORM-ANDROID]", with: "")
                .replacingOccurrences(of: "[PLATFORM-IOS]", with: "iOS")
            self.aboutPage = .loaded(txt)
        }
    }
    
    func handlePrayerLink(prayer: Prayer, url: URL) {
        // Set flag to prevent KVO observers from triggering deferred reload
        // while prayer link is handling its own immediate reload
        isUpdatingFromPrayerLink = true
        defer { isUpdatingFromPrayerLink = false }
        
        let parsedLink = self.dataSource.parsePrayerLink(url: url)
        switch parsedLink {
        case .prayerTextLink(let opts):
            self.savePrayerOptions(opts)
            self.loadPrayer(prayer)
        case .externalAppLink(let url):
            UIApplication.shared.open(url)
        case .webLink(let url):
            self.externalLink = IdentifiableURL(url: url)
        case .unknownLink:
            break
        }
    }
    
    func savePrayerOptions(_ opts: [String: String]) {
        for optName in ["o0", "o1", "o3", "o4", "o5", "o6"] {
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
    
    func clearCalendarSettings() {
        for optName in ["o0", "o1", "o3", "o4", "o5", "o6"] {
            guard let entry = getSettingsEntry(name: optName) else { continue }
            entry.clearUserSettings()
        }
    }
    
    func unloadPrayer() {
        self.prayerText = .idle
        self.ttsPrayerText = .idle
    }
    
    func loadSettingsEntries(policy: DataSourcePolicy = .automatic) {
        self.settingsLoadID += 1
        let loadID = self.settingsLoadID

        let retry: (DataSourcePolicy) -> Void = { policy in
            self.settingsEntries = .loading
            self.loadSettingsEntries(policy: policy)
        }

        self.dataSource.getSettingsEntries(policy: policy) { (entries, error) in
            guard loadID == self.settingsLoadID else { return }
            if error == nil {
                // Save entries to UserDefaults
                for entry in entries! {
                    entry.setUserSettings(entry.getUserSettings())
                }
                
                self.settingsEntries = .loaded(entries!)
            } else {
                self.settingsEntries = .failed(error!, retry)
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
    
    /// Reloads the currently shown data from the server, bypassing the Wi-Fi gate and
    /// the server cooldown.
    func retryOnline() {
        self.loadDay(self.day, policy: .forceRemote)
        self.loadMonth(self.month, policy: .forceRemote)
        self.loadSettingsEntries(policy: .forceRemote)
    }

    func navigateToDay(_ day: Day) {
        self.loadDay(day)
    }
    
    func navigateToPrayer(day: Day, prayerType: PrayerType) {
        // Clear any existing prayer text
        self.unloadPrayer()
        
        // Create the pending navigation
        let createNavigation = {
            if let (liturgicalDay, celebration) = self.getCurrentCelebration() {
                let prayer = Prayer(day: liturgicalDay.day, celebration: celebration, type: prayerType)
                self.pendingNavigation = .prayer(prayer)
                
                // Trigger navigation dismissal first
                self.navigationTrigger = nil
                
                // Then trigger actual navigation after a delay
                DispatchQueue.main.asyncAfter(deadline: .now() + 0.3) {
                    self.navigationTrigger = self.pendingNavigation
                    self.pendingNavigation = nil
                }
            }
        }
        
        // If we're already on the correct day, create navigation directly
        if self.day == day {
            createNavigation()
        } else {
            // Load the new day and then navigate
            self.loadDay(day)
            
            DispatchQueue.main.asyncAfter(deadline: .now() + 0.5) {
                createNavigation()
            }
        }
    }
    
    override func observeValue(forKeyPath keyPath: String?, of object: Any?, change: [NSKeyValueChangeKey : Any]?, context: UnsafeMutableRawPointer?) {
        if let keyPath = keyPath, ["o0", "o1", "o3", BibleLinkMode.userDefaultsKey].contains(keyPath) {
            print("observed settings change: \(keyPath)")
            // Only set the deferred reload flag if we're not in a prayer link context.
            // This prevents the MainScreen.onAppear handler to be triggered incorrectly,
            // which would bring the user back to the main screen.
            if !isUpdatingFromPrayerLink {
                liturgicalDataNeedsReload = true
            }
        }
    }
    
    deinit {
        ["o0", "o1", "o3", BibleLinkMode.userDefaultsKey].forEach { key in
            UserDefaults.standard.removeObserver(self, forKeyPath: key)
        }
    }
}

enum LoadingState<Value> {
    case idle
    case loading
    case failed(Error, (_ policy: DataSourcePolicy) -> Void)
    case loaded(Value)
}

enum NavigationTarget: Equatable {
    case prayer(Prayer)
    
    static func == (lhs: NavigationTarget, rhs: NavigationTarget) -> Bool {
        switch (lhs, rhs) {
        case (.prayer(let p1), .prayer(let p2)):
            return p1.type == p2.type && p1.day == p2.day
        }
    }
}
