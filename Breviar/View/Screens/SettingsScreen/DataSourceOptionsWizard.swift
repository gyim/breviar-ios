//
//  DataSourceOptionsWizard.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 05. 22..
//

import SwiftUI

struct DataSourceOptionsWizard: View {
    var body: some View {
        NavigationView {
            LanguageChooserScreen()
        }.navigationViewStyle(StackNavigationViewStyle())
    }
}

struct LanguageChooserScreen: View {
    var body: some View {
        List {
            LanguageLink(name: "🇨🇿 Čeština", code: "cz")
            LanguageLink(name: "🇭🇺 Magyar", code: "hu")
            LanguageLink(name: "🇸🇰 Slovenčina", code: "sk")
        }
        .navigationTitle("Jazyk / Nyelv")
    }
}

struct LanguageLink: View {
    var name: String
    var code: String
    
    var body: some View {
        NavigationLink(destination: CalendarChooserScreen(language: code)) {
            HStack {
                Text(name)
                    .padding(.vertical)
            }
        }
    }
}

struct CalendarChooserScreen: View {
    var language: String
    
    var body: some View {
        switch language {
        case "cz":
            List {
                CalendarLink(language: "cz", calendar: "cz", label: "obecný [pro Čechy a Moravu]")
                CalendarLink(language: "czop", calendar: "czop", label: "dominikánský (OP)")
                CalendarLink(language: "cz", calendar: "opraem", label: "s vlastními texty premonstrátského řádu (OPraem)")
                CalendarLink(language: "cz", calendar: "ofmcap", label: "s vlastními kapucínskými texty (OFMCap.)")
                CalendarLink(language: "cz", calendar: "czsdb", label: "s vlastními texty pro salesiánskou rodinu")
                CalendarLink(language: "cz", calendar: "czofm", label: "s vlastními františkánskými texty (OFM)")
                CalendarLink(language: "cz", calendar: "czsj", label: "s vlastními texty jezuitského řádu (SJ)")
                CalendarLink(language: "cz", calendar: "czocd", label: "s vlastními texty bosých karmelitánů (OCD)")
            }.navigationTitle(S.liturgicalCalendar.forLanguage(.czech))
        case "hu":
            List {
                CalendarLink(language: "hu", calendar: "hu", label: "általános [Magyarország]")
                CalendarLink(language: "hu", calendar: "huofm", label: "ferences szentek és ünnepek zsolozsmája")
                CalendarLink(language: "hu", calendar: "husvd", label: "verbiták zsolozsmája")
                CalendarLink(language: "hu", calendar: "husj", label: "jezsuiták zsolozsmája (SJ)")
            }.navigationTitle(S.liturgicalCalendar.forLanguage(.hungarian))
        case "sk":
            List {
                ForEach([
                    CalendarLink(language: "sk", calendar: "sk", label: "všeobecný [pre Slovensko]"),
                    CalendarLink(language: "sk", calendar: "cssr", label: "pre Kongregáciu najsv. Vykupiteľa — redemptoristov (CSsR)"),
                    CalendarLink(language: "sk", calendar: "svd", label: "pre Spoločnosť Božieho Slova — verbistov (SVD)"),
                    CalendarLink(language: "sk", calendar: "ofm", label: "pre františkánsku rodinu"),
                    CalendarLink(language: "sk", calendar: "sdb", label: "pre saleziánsku rodinu — SDB, FMA, VDB"),
                    CalendarLink(language: "sk", calendar: "op", label: "pre Rehoľu kazateľov — dominikánov (OP)"),
                    CalendarLink(language: "sk", calendar: "sj", label: "pre Spoločnosť Ježišovu — jezuitov (SJ)"),
                    CalendarLink(language: "sk", calendar: "cm", label: "pre Misijnú spoločnosť sv. Vincenta de Paul — lazaristov (CM)"),
                    CalendarLink(language: "sk", calendar: "ocd", label: "pre bosých karmelitánov (OCD)"),
                    CalendarLink(language: "sk", calendar: "csa", label: "pre kanonisky sv. Augustína Notre Dame (CSA)"),
                    CalendarLink(language: "sk", calendar: "osu", label: "pre uršulínky Rímskej únie (OSU)")
                ]) { e in e}
            }.navigationTitle(S.liturgicalCalendar.forLanguage(.slovak))
        default:
            Text("Nothing here")
        }
    }
}

struct CalendarLink: View, Identifiable {
    var language: String
    var calendar: String
    var label: String
    
    var body: some View {
        NavigationLink(
            destination: NetworkSettingsScreen(language: language, calendar: calendar),
            label: {
                Text(label)
            })
    }
    
    var id: String {
        return calendar
    }
}

struct NetworkSettingsScreen: View {
    var language: String
    var calendar: String
    @State var dataSourceType: DataSourceType = .alwaysNetwork
    @EnvironmentObject var optionStore: DataSourceOptionsStore
    
    var body: some View {
        List {
            Section(header: Text(S.downloadLatestTexts.forLanguageCode(language))) {
                NetworkSettingsChoice(label: S.always.forLanguageCode(language), checked: dataSourceType == .alwaysNetwork)
                    .onTapGesture { withAnimation { dataSourceType = .alwaysNetwork } }
                NetworkSettingsChoice(label: S.onlyOnWifi.forLanguageCode(language), checked: dataSourceType == .networkOnWifi)
                    .onTapGesture { withAnimation { dataSourceType = .networkOnWifi } }
                NetworkSettingsChoice(label: S.never.forLanguageCode(language), checked: dataSourceType == .alwaysCGI)
                    .onTapGesture { withAnimation { dataSourceType = .alwaysCGI } }
            }
        }
        .navigationTitle(S.networkSettings.forLanguageCode(language))
        .toolbar(content: {
            Button(S.done.forLanguageCode(language)) {
                optionStore.dataSourceOptions = DataSourceOptions(dataSourceType: dataSourceType, language: Language(rawValue: language)!, calendar: calendar)
            }
        })
    }
}

struct NetworkSettingsChoice: View {
    var label: String
    var checked: Bool
    
    var body: some View {
        HStack {
            Text(label)
            Spacer()
            Image(systemName: "checkmark").foregroundColor(.accentColor).opacity(checked ? 1 : 0)
        }.contentShape(Rectangle())
    }
}

struct SetupWizardScreen_Previews: PreviewProvider {
    static var previews: some View {
        DataSourceOptionsWizard()
    }
}

struct CalendarChooserScreen_Previews: PreviewProvider {
    static var previews: some View {
        NavigationView {
            CalendarChooserScreen(language: "hu")
        }
    }
}

struct NetworkSettingsScreen_Previews: PreviewProvider {
    static var previews: some View {
        NavigationView {
            NetworkSettingsScreen(language: "hu", calendar: "hu")
                .environmentObject(DataSourceOptionsStore())
        }
    }
}
