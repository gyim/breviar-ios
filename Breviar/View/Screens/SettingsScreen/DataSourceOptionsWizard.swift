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
            switch model.dataSourceOptionsWizardContext {
            case .initialSetup:
                initialSetupView
            case .settingsModification:
                settingsModificationView
            }
        }.navigationViewStyle(StackNavigationViewStyle())
    }
    
    @ViewBuilder
    private var initialSetupView: some View {
        switch model.dataSourceOptionsWizardStage {
        case .chooseLanguage:
            LanguageChooserScreen(wizardContext: .initialSetup)
        case .chooseCalendar:
            CalendarChooserScreen(language: model.dataSourceOptions!.language.rawValue, wizardContext: .initialSetup)
        case .chooseDataSourceType:
            NetworkSettingsScreen(language: model.dataSourceOptions!.language.rawValue, calendar: model.dataSourceOptions!.calendar, wizardContext: .initialSetup)
        }
    }
    
    @ViewBuilder
    private var settingsModificationView: some View {
        switch model.dataSourceOptionsWizardStage {
        case .chooseLanguage:
            LanguageChooserScreen(wizardContext: .settingsModification)
        case .chooseCalendar:
            CalendarChooserScreen(language: model.dataSourceOptions!.language.rawValue, wizardContext: .settingsModification)
        case .chooseDataSourceType:
            NetworkSettingsScreen(language: model.dataSourceOptions!.language.rawValue, calendar: model.dataSourceOptions!.calendar, wizardContext: .settingsModification)
        }
    }
}

struct LanguageChooserScreen: View {
    var wizardContext: DataSourceWizardContext
    
    var body: some View {
        VStack {
            Image("PlaybackIcon")
                .resizable()
                .aspectRatio(contentMode: .fit)

            List {
                LanguageLink(name: "🇨🇿 Breviář", code: "cz", wizardContext: wizardContext)
                LanguageLink(name: "🇭🇺 Zsolozsma", code: "hu", wizardContext: wizardContext)
                LanguageLink(name: "🇮🇸 Tíðabænabók", code: "is", wizardContext: wizardContext)
                LanguageLink(name: "🇸🇰 Breviár", code: "sk", wizardContext: wizardContext)
            }
        }
    }
}

struct LanguageLink: View {
    var name: String
    var code: String
    var wizardContext: DataSourceWizardContext
    
    var body: some View {
        NavigationLink(destination: CalendarChooserScreen(language: code, wizardContext: wizardContext)) {
            HStack {
                Text(name)
                    .padding(.vertical)
            }
        }
    }
}

struct CalendarChooserScreen: View {
    var language: String
    var wizardContext: DataSourceWizardContext
    
    var body: some View {
        switch language {
        case "cz":
            List {
                CalendarLink(language: "cz", calendar: "cz", wizardContext: wizardContext)
                CalendarLink(language: "cz", calendar: "czop", wizardContext: wizardContext)
                CalendarLink(language: "cz", calendar: "opraem", wizardContext: wizardContext)
                CalendarLink(language: "cz", calendar: "ofmcap", wizardContext: wizardContext)
                CalendarLink(language: "cz", calendar: "czsdb", wizardContext: wizardContext)
                CalendarLink(language: "cz", calendar: "czofm", wizardContext: wizardContext)
                CalendarLink(language: "cz", calendar: "czsj", wizardContext: wizardContext)
                CalendarLink(language: "cz", calendar: "czocd", wizardContext: wizardContext)
                CalendarLink(language: "cz", calendar: "czofmconv", wizardContext: wizardContext)
            }.navigationTitle(S.liturgicalCalendar.forLanguage(.czech))
        case "hu":
            List {
                CalendarLink(language: "hu", calendar: "hu", wizardContext: wizardContext)
                CalendarLink(language: "hu", calendar: "huofm", wizardContext: wizardContext)
                CalendarLink(language: "hu", calendar: "husvd", wizardContext: wizardContext)
                CalendarLink(language: "hu", calendar: "husj", wizardContext: wizardContext)
            }.navigationTitle(S.liturgicalCalendar.forLanguage(.hungarian))
        case "sk":
            List {
                ForEach([
                    CalendarLink(language: "sk", calendar: "sk", wizardContext: wizardContext),
                    CalendarLink(language: "sk", calendar: "cssr", wizardContext: wizardContext),
                    CalendarLink(language: "sk", calendar: "svd", wizardContext: wizardContext),
                    CalendarLink(language: "sk", calendar: "ofm", wizardContext: wizardContext),
                    CalendarLink(language: "sk", calendar: "sdb", wizardContext: wizardContext),
                    CalendarLink(language: "sk", calendar: "op", wizardContext: wizardContext),
                    CalendarLink(language: "sk", calendar: "sj", wizardContext: wizardContext),
                    CalendarLink(language: "sk", calendar: "cm", wizardContext: wizardContext),
                    CalendarLink(language: "sk", calendar: "ocd", wizardContext: wizardContext),
                    CalendarLink(language: "sk", calendar: "csa", wizardContext: wizardContext),
                    CalendarLink(language: "sk", calendar: "osu", wizardContext: wizardContext),
                    CalendarLink(language: "sk", calendar: "skopraem", wizardContext: wizardContext),
                ]) { e in e}
            }.navigationTitle(S.liturgicalCalendar.forLanguage(.slovak))
        case "is":
            List {
                CalendarLink(language: "is", calendar: "is", wizardContext: wizardContext)
            }.navigationTitle(S.liturgicalCalendar.forLanguage(.icelandic))
        default:
            Text("Nothing here")
        }
    }
}

struct CalendarLink: View, Identifiable {
    var language: String
    var calendar: String
    var wizardContext: DataSourceWizardContext
    @EnvironmentObject var model: BreviarModel
    
    var body: some View {
        let label = CalendarNames[calendar]!
        
        if wizardContext == .settingsModification {
            Text(label)
                .contentShape(Rectangle())
                .onTapGesture {
                    let dataSourceType = model.dataSourceOptions?.dataSourceType ?? .alwaysNetwork
                    let options = DataSourceOptions(dataSourceType: dataSourceType, language: Language(rawValue: language)!, calendar: calendar)
                    model.setDataSourceOptions(options)
                }
        } else {
            NavigationLink(
                destination: NetworkSettingsScreen(language: language, calendar: calendar, wizardContext: wizardContext),
                label: {
                    Text(label)
                })
        }
    }
    
    var id: String {
        return calendar
    }
}

struct NetworkSettingsScreen: View {
    var language: String
    var calendar: String
    var wizardContext: DataSourceWizardContext
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
        .onAppear {
            dataSourceType = model.dataSourceOptions?.dataSourceType ?? .alwaysNetwork
        }
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
            CalendarChooserScreen(language: "hu", wizardContext: .initialSetup)
        }
    }
}

struct NetworkSettingsScreen_Previews: PreviewProvider {
    static var previews: some View {
        NavigationView {
            NetworkSettingsScreen(language: "hu", calendar: "hu", wizardContext: .initialSetup)
                .environmentObject(BreviarModel.testModel())
        }
    }
}
