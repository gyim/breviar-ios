//
//  BreviarApp.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 01. 16..
//

import SwiftUI
import WebKit

@main
struct BreviarApp: App {
    @ObservedObject var model = BreviarModel.cgiModel()
    
    var body: some Scene {
        WindowGroup {
            MainScreen().environmentObject(model)
                .onAppear() {
                    // Set UI and liturgical languages
                    if let options = model.dataSourceOptions {
                        currentLiturgicalLanguage = options.language
                        currentUILanguage = options.uiLanguage
                    }
                    
                    // Set color scheme
                    let window = UIApplication.shared.windows.first
                    window?.overrideUserInterfaceStyle = model.textOptions.colorScheme.uikitColorScheme
                    
                    // Load an empty WKWebView so that it is faster to load on prayer screen
                    _ = WKWebView()
                }
                .fullScreenCover(isPresented: $model.dataSourceOptionsNeeded, content: {
                    DataSourceOptionsWizard().environmentObject(model)
                })
                .onOpenURL { url in
                    handleIncomingURL(url)
                }
        }
    }
    
    private func handleIncomingURL(_ url: URL) {
        print("Breviar app opened with URL: \(url)")
        
        guard url.scheme == "breviar" else { return }
        
        let host = url.host ?? ""
        let pathComponents = url.pathComponents.filter { $0 != "/" }
        
        if host.isEmpty && pathComponents.isEmpty {
            model.navigateToDay(Day(fromDate: Date()))
            return
        }
        
        if host == "today" && pathComponents.isEmpty {
            model.navigateToDay(Day(fromDate: Date()))
            return
        }
        
        if host == "today" && pathComponents.count == 1 {
            let prayerName = pathComponents[0]
            if let prayerType = prayerTypeFromName(prayerName) {
                model.navigateToPrayer(day: Day(fromDate: Date()), prayerType: prayerType)
            }
            return
        }
        
        if isValidDateString(host) {
            let day = dayFromDateString(host)
            if pathComponents.isEmpty {
                model.navigateToDay(day)
            } else if pathComponents.count == 1 {
                let prayerName = pathComponents[0]
                if let prayerType = prayerTypeFromName(prayerName) {
                    model.navigateToPrayer(day: day, prayerType: prayerType)
                }
            }
            return
        }
    }
    
    private func isValidDateString(_ dateString: String) -> Bool {
        let pattern = #"^\d{4}-\d{2}-\d{2}$"#
        return dateString.range(of: pattern, options: .regularExpression) != nil
    }
    
    private func dayFromDateString(_ dateString: String) -> Day {
        let components = dateString.split(separator: "-")
        if components.count == 3,
           let year = Int(components[0]),
           let month = Int(components[1]),
           let day = Int(components[2]) {
            return Day(year: year, month: month, day: day)
        }
        return Day(fromDate: Date())
    }
    
    private func prayerTypeFromName(_ name: String) -> PrayerType? {
        switch name.lowercased() {
        case "invitatory": return .invitatory
        case "officeofredings", "officeofreadings": return .officeOfReadings
        case "morningprayer": return .morningPrayer
        case "midmorningprayer": return .midMorningPrayer
        case "middayprayer": return .midDayPrayer
        case "midafternoonprayer": return .midAfternoonPrayer
        case "eveningprayer": return .eveningPrayer
        case "compline": return .compline
        default: return nil
        }
    }
}
