//
//  DataSourceOptionsWizard.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 05. 22..
//

import SwiftUI

struct DataSourceOptionsWizard: View {
    @EnvironmentObject var model: BreviarModel
    
    var body: some View {
        NavigationView {
            switch model.dataSourceOptionsWizardStage {
            case .chooseLanguage:
                LanguageChooserScreen()
            case .chooseCalendar:
                CalendarChooserScreen(language: model.dataSourceOptions!.language.rawValue)
            case .chooseDataSourceType:
                NetworkSettingsScreen(language: model.dataSourceOptions!.language.rawValue, calendar: model.dataSourceOptions!.calendar)
            }
        }.navigationViewStyle(StackNavigationViewStyle())
    }
}

struct LanguageChooserScreen: View {
    var body: some View {
        List {
            LanguageLink(name: "🇨🇿 Čeština", code: "cz")
            LanguageLink(name: "🇭🇺 Magyar", code: "hu")
            LanguageLink(name: "🇸🇰 Slovenčina", code: "sk")
            LanguageLink(name: "✝️ Latin", code: "la")
        }
        .navigationTitle("Choose Language")
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
                CalendarLink(language: "cz", calendar: "cz")
                CalendarLink(language: "cz", calendar: "czop")
                CalendarLink(language: "cz", calendar: "opraem")
                CalendarLink(language: "cz", calendar: "ofmcap")
                CalendarLink(language: "cz", calendar: "czsdb")
                CalendarLink(language: "cz", calendar: "czofm")
                CalendarLink(language: "cz", calendar: "czsj")
                CalendarLink(language: "cz", calendar: "czocd")
                CalendarLink(language: "cz", calendar: "czofmconv")
            }.navigationTitle(S.liturgicalCalendar.forLanguage(.czech))
        case "hu":
            List {
                CalendarLink(language: "hu", calendar: "hu")
                CalendarLink(language: "hu", calendar: "huofm")
                CalendarLink(language: "hu", calendar: "husvd")
                CalendarLink(language: "hu", calendar: "husj")
            }.navigationTitle(S.liturgicalCalendar.forLanguage(.hungarian))
        case "sk":
            List {
                ForEach([
                    CalendarLink(language: "sk", calendar: "sk"),
                    CalendarLink(language: "sk", calendar: "cssr"),
                    CalendarLink(language: "sk", calendar: "svd"),
                    CalendarLink(language: "sk", calendar: "ofm"),
                    CalendarLink(language: "sk", calendar: "sdb"),
                    CalendarLink(language: "sk", calendar: "op"),
                    CalendarLink(language: "sk", calendar: "sj"),
                    CalendarLink(language: "sk", calendar: "cm"),
                    CalendarLink(language: "sk", calendar: "ocd"),
                    CalendarLink(language: "sk", calendar: "csa"),
                    CalendarLink(language: "sk", calendar: "osu"),
                    CalendarLink(language: "sk", calendar: "skopraem"),
                ]) { e in e}
            }.navigationTitle(S.liturgicalCalendar.forLanguage(.slovak))
        case "la":
            List {
                CalendarLink(language: "la", calendar: "la")
            }.navigationTitle(S.liturgicalCalendar.forLanguage(.latin))
        default:
            Text("Nothing here")
        }
    }
}

struct CalendarLink: View, Identifiable {
    var language: String
    var calendar: String
    
    var body: some View {
        let label = CalendarNames[calendar]!
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
    @EnvironmentObject var model: BreviarModel
    
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
                let options = DataSourceOptions(dataSourceType: dataSourceType, language: Language(rawValue: language)!, calendar: calendar)
                model.setDataSourceOptions(options)
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
                .environmentObject(BreviarModel.testModel())
        }
    }
}
