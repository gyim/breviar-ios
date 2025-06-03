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
            CalendarChooserScreen(language: model.dataSourceOptions!.language.rawValue, uiLanguage: model.dataSourceOptions!.uiLanguage.rawValue, wizardContext: .initialSetup)
        case .chooseDataSourceType:
            NetworkSettingsScreen(language: model.dataSourceOptions!.language.rawValue, uiLanguage: model.dataSourceOptions!.uiLanguage.rawValue, calendar: model.dataSourceOptions!.calendar, wizardContext: .initialSetup)
        }
    }
    
    @ViewBuilder
    private var settingsModificationView: some View {
        switch model.dataSourceOptionsWizardStage {
        case .chooseLanguage:
            LanguageChooserScreen(wizardContext: .settingsModification)
        case .chooseCalendar:
            CalendarChooserScreen(language: model.dataSourceOptions!.language.rawValue, uiLanguage: model.dataSourceOptions!.uiLanguage.rawValue, wizardContext: .settingsModification)
        case .chooseDataSourceType:
            NetworkSettingsScreen(language: model.dataSourceOptions!.language.rawValue, uiLanguage: model.dataSourceOptions!.uiLanguage.rawValue, calendar: model.dataSourceOptions!.calendar, wizardContext: .settingsModification)
        }
    }
}

struct LanguageChooserScreen: View {
    var wizardContext: DataSourceWizardContext
    
    var body: some View {
        ScrollView {
            VStack(spacing: 20) {
                Image("PlaybackIcon")
                    .resizable()
                    .aspectRatio(contentMode: .fit)
                    .frame(maxHeight: 120)
                    .padding(.top)
                
                Text(NSLocalizedString("Choose Language", comment: ""))
                    .font(.title2)
                    .fontWeight(.medium)
                    .padding(.horizontal)

                VStack(spacing: 0) {
                    LanguageLink(name: "🇨🇿 Breviář", code: "cz", wizardContext: wizardContext)
                        .padding(.horizontal)
                        .padding(.vertical, 12)
                        .background(Color(.systemBackground))
                    
                    Divider()
                    
                    LanguageLink(name: "🇭🇺 Zsolozsma", code: "hu", wizardContext: wizardContext)
                        .padding(.horizontal)
                        .padding(.vertical, 12)
                        .background(Color(.systemBackground))
                    
                    Divider()
                    
                    LanguageLink(name: "🇮🇸 Tíðabænabók", code: "is", wizardContext: wizardContext)
                        .padding(.horizontal)
                        .padding(.vertical, 12)
                        .background(Color(.systemBackground))
                    
                    Divider()
                    
                    LanguageLink(name: "🇸🇰 Breviár", code: "sk", wizardContext: wizardContext)
                        .padding(.horizontal)
                        .padding(.vertical, 12)
                        .background(Color(.systemBackground))
                    
                    Divider()
                    
                    LatinLanguageSection(wizardContext: wizardContext)
                        .padding(.horizontal)
                        .background(Color(.systemBackground))
                }
                .background(Color(.systemGray6))
                .cornerRadius(10)
                .padding(.horizontal)
                
                Spacer(minLength: 50)
            }
        }
    }
}

struct LanguageLink: View {
    var name: String
    var code: String
    var wizardContext: DataSourceWizardContext
    
    var body: some View {
        NavigationLink(destination: CalendarChooserScreen(language: code, uiLanguage: code, wizardContext: wizardContext)) {
            HStack {
                Text(name)
                Spacer()
                Image(systemName: "chevron.right")
                    .foregroundColor(.gray)
                    .font(.caption)
            }
        }
        .buttonStyle(PlainButtonStyle())
    }
}

struct CalendarChooserScreen: View {
    var language: String
    var uiLanguage: String
    var wizardContext: DataSourceWizardContext
    
    var body: some View {
        switch language {
        case "cz":
            List {
                CalendarLink(language: "cz", uiLanguage: uiLanguage, calendar: "cz", wizardContext: wizardContext)
                CalendarLink(language: "cz", uiLanguage: uiLanguage, calendar: "czop", wizardContext: wizardContext)
                CalendarLink(language: "cz", uiLanguage: uiLanguage, calendar: "opraem", wizardContext: wizardContext)
                CalendarLink(language: "cz", uiLanguage: uiLanguage, calendar: "ofmcap", wizardContext: wizardContext)
                CalendarLink(language: "cz", uiLanguage: uiLanguage, calendar: "czsdb", wizardContext: wizardContext)
                CalendarLink(language: "cz", uiLanguage: uiLanguage, calendar: "czofm", wizardContext: wizardContext)
                CalendarLink(language: "cz", uiLanguage: uiLanguage, calendar: "czsj", wizardContext: wizardContext)
                CalendarLink(language: "cz", uiLanguage: uiLanguage, calendar: "czocd", wizardContext: wizardContext)
                CalendarLink(language: "cz", uiLanguage: uiLanguage, calendar: "czofmconv", wizardContext: wizardContext)
            }.navigationTitle(S.liturgicalCalendar.forLanguage(.czech))
        case "hu":
            List {
                CalendarLink(language: "hu", uiLanguage: uiLanguage, calendar: "hu", wizardContext: wizardContext)
                CalendarLink(language: "hu", uiLanguage: uiLanguage, calendar: "huofm", wizardContext: wizardContext)
                CalendarLink(language: "hu", uiLanguage: uiLanguage, calendar: "husvd", wizardContext: wizardContext)
                CalendarLink(language: "hu", uiLanguage: uiLanguage, calendar: "husj", wizardContext: wizardContext)
            }.navigationTitle(S.liturgicalCalendar.forLanguage(.hungarian))
        case "sk":
            List {
                ForEach([
                    CalendarLink(language: "sk", uiLanguage: uiLanguage, calendar: "sk", wizardContext: wizardContext),
                    CalendarLink(language: "sk", uiLanguage: uiLanguage, calendar: "cssr", wizardContext: wizardContext),
                    CalendarLink(language: "sk", uiLanguage: uiLanguage, calendar: "svd", wizardContext: wizardContext),
                    CalendarLink(language: "sk", uiLanguage: uiLanguage, calendar: "ofm", wizardContext: wizardContext),
                    CalendarLink(language: "sk", uiLanguage: uiLanguage, calendar: "sdb", wizardContext: wizardContext),
                    CalendarLink(language: "sk", uiLanguage: uiLanguage, calendar: "op", wizardContext: wizardContext),
                    CalendarLink(language: "sk", uiLanguage: uiLanguage, calendar: "sj", wizardContext: wizardContext),
                    CalendarLink(language: "sk", uiLanguage: uiLanguage, calendar: "cm", wizardContext: wizardContext),
                    CalendarLink(language: "sk", uiLanguage: uiLanguage, calendar: "ocd", wizardContext: wizardContext),
                    CalendarLink(language: "sk", uiLanguage: uiLanguage, calendar: "csa", wizardContext: wizardContext),
                    CalendarLink(language: "sk", uiLanguage: uiLanguage, calendar: "osu", wizardContext: wizardContext),
                    CalendarLink(language: "sk", uiLanguage: uiLanguage, calendar: "skopraem", wizardContext: wizardContext),
                ]) { e in e}
            }.navigationTitle(S.liturgicalCalendar.forLanguage(.slovak))
        case "is":
            List {
                CalendarLink(language: "is", uiLanguage: uiLanguage, calendar: "is", wizardContext: wizardContext)
            }.navigationTitle(S.liturgicalCalendar.forLanguage(.icelandic))
        case "la":
            List {
                CalendarLink(language: "la", uiLanguage: uiLanguage, calendar: "la", wizardContext: wizardContext)
            }.navigationTitle(S.liturgicalCalendar.forLanguage(.latin))
        default:
            Text("Nothing here")
        }
    }
}

struct CalendarLink: View, Identifiable {
    var language: String
    var uiLanguage: String
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
                    let options = DataSourceOptions(dataSourceType: dataSourceType, language: Language(rawValue: language)!, uiLanguage: Language(rawValue: uiLanguage)!, calendar: calendar)
                    model.setDataSourceOptions(options)
                }
        } else {
            NavigationLink(
                destination: NetworkSettingsScreen(language: language, uiLanguage: uiLanguage, calendar: calendar, wizardContext: wizardContext),
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
    var uiLanguage: String
    var calendar: String
    var wizardContext: DataSourceWizardContext
    @State var dataSourceType: DataSourceType = .alwaysNetwork
    @EnvironmentObject var model: BreviarModel
    
    var body: some View {
        List {
            Section(header: Text(S.downloadLatestTexts.forLanguageCode(uiLanguage))) {
                NetworkSettingsChoice(label: S.always.forLanguageCode(uiLanguage), checked: dataSourceType == .alwaysNetwork)
                    .onTapGesture { withAnimation { dataSourceType = .alwaysNetwork } }
                NetworkSettingsChoice(label: S.onlyOnWifi.forLanguageCode(uiLanguage), checked: dataSourceType == .networkOnWifi)
                    .onTapGesture { withAnimation { dataSourceType = .networkOnWifi } }
                NetworkSettingsChoice(label: S.never.forLanguageCode(uiLanguage), checked: dataSourceType == .alwaysCGI)
                    .onTapGesture { withAnimation { dataSourceType = .alwaysCGI } }
            }
        }
        .navigationTitle(S.networkSettings.forLanguageCode(uiLanguage))
        .toolbar(content: {
            Button(S.done.forLanguageCode(uiLanguage)) {
                let options = DataSourceOptions(dataSourceType: dataSourceType, language: Language(rawValue: language)!, uiLanguage: Language(rawValue: uiLanguage)!, calendar: calendar)
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

struct LatinLanguageSection: View {
    var wizardContext: DataSourceWizardContext
    @State private var expandedLatin = false
    @State private var selectedUILanguage: Language?
    @EnvironmentObject var model: BreviarModel
    
    var body: some View {
        VStack(spacing: 0) {
            HStack {
                Text("✝️ Breviarium (Latin)")
                    .padding(.vertical, 12)
                Spacer()
                Image(systemName: expandedLatin ? "chevron.up" : "chevron.right")
                    .foregroundColor(.gray)
                    .font(.caption)
            }
            .contentShape(Rectangle())
            .onTapGesture {
                withAnimation(.easeInOut(duration: 0.3)) {
                    expandedLatin.toggle()
                    if !expandedLatin {
                        selectedUILanguage = nil
                    }
                }
            }
            
            if expandedLatin {
                VStack(alignment: .leading, spacing: 10) {
                    Text(NSLocalizedString("Choose user interface language", comment: ""))
                        .font(.caption)
                        .foregroundColor(.secondary)
                        .padding(.horizontal)
                    
                    ForEach([Language.czech, Language.hungarian, Language.icelandic, Language.slovak], id: \.self) { lang in
                        UILanguageRow(
                            language: lang,
                            selectedUILanguage: $selectedUILanguage,
                            wizardContext: wizardContext
                        )
                    }
                }
                .padding(.top, 10)
                .clipped()
            }
        }
    }
}

struct UILanguageRow: View {
    var language: Language
    @Binding var selectedUILanguage: Language?
    var wizardContext: DataSourceWizardContext
    @EnvironmentObject var model: BreviarModel
    
    private var languageEmoji: String {
        switch language {
        case .czech: return "🇨🇿"
        case .hungarian: return "🇭🇺"
        case .icelandic: return "🇮🇸"
        case .slovak: return "🇸🇰"
        default: return ""
        }
    }
    
    var body: some View {
        HStack {
            Text("\(languageEmoji) \(LanguageNames[language] ?? "")")
                .padding(.horizontal)
                .padding(.vertical, 8)
            Spacer()
        }
        .contentShape(Rectangle())
        .background(selectedUILanguage == language ? Color.accentColor.opacity(0.1) : Color.clear)
        .onTapGesture {
            selectedUILanguage = language
            // Navigate to calendar chooser with Latin and selected UI language
            DispatchQueue.main.asyncAfter(deadline: .now() + 0.2) {
                if wizardContext == .settingsModification {
                    // For settings modification, directly update the language
                    let dataSourceType = model.dataSourceOptions?.dataSourceType ?? .alwaysNetwork
                    let options = DataSourceOptions(
                        dataSourceType: dataSourceType,
                        language: .latin,
                        uiLanguage: language,
                        calendar: "la"
                    )
                    model.setDataSourceOptions(options)
                } else {
                    // For initial setup, navigate to calendar chooser
                    model.dataSourceOptions = DataSourceOptions(
                        dataSourceType: .alwaysNetwork,
                        language: .latin,
                        uiLanguage: language,
                        calendar: "la"
                    )
                    model.dataSourceOptionsWizardStage = .chooseCalendar
                }
            }
        }
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
            CalendarChooserScreen(language: "hu", uiLanguage: "hu", wizardContext: .initialSetup)
        }
    }
}

struct NetworkSettingsScreen_Previews: PreviewProvider {
    static var previews: some View {
        NavigationView {
            NetworkSettingsScreen(language: "hu", uiLanguage: "hu", calendar: "hu", wizardContext: .initialSetup)
                .environmentObject(BreviarModel.testModel())
        }
    }
}
