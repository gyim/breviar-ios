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
                // In single-language mode, don't show initial setup wizard
                if AppConfig.SINGLE_LANGUAGE_MODE {
                    EmptyView()
                } else {
                    initialSetupView
                }
            case .settingsModification:
                settingsModificationView
                    .toolbar {
                        ToolbarItem(placement: .navigationBarTrailing) {
                            Button(S.close.forLanguage(currentUILanguage)) {
                                model.dataSourceOptionsNeeded = false
                            }
                        }
                    }
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
            // In single-language mode, don't show language chooser
            if AppConfig.SINGLE_LANGUAGE_MODE {
                EmptyView()
            } else {
                LanguageChooserScreen(wizardContext: .settingsModification)
            }
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
    @EnvironmentObject var model: BreviarModel
    
    var body: some View {
        if let language = Language(rawValue: code), language.hasMultipleCalendars {
            // Languages with multiple calendars: navigate to calendar chooser
            NavigationLink(destination: CalendarChooserScreen(language: code, uiLanguage: code, wizardContext: wizardContext)) {
                HStack {
                    Text(name)
                    Spacer()
                    Image(systemName: "chevron.right")
                        .foregroundColor(.gray)
                        .font(.caption)
                }
                .contentShape(Rectangle())
            }
            .buttonStyle(PlainButtonStyle())
        } else if let language = Language(rawValue: code) {
            // Languages with single calendar: skip calendar chooser
            let defaultCalendar = language.defaultCalendar
            
            if wizardContext == .settingsModification {
                // Settings modification: apply changes directly
                HStack {
                    Text(name)
                    Spacer()
                    Image(systemName: "chevron.right")
                        .foregroundColor(.gray)
                        .font(.caption)
                }
                .contentShape(Rectangle())
                .onTapGesture {
                    let dataSourceType = model.dataSourceOptions?.dataSourceType ?? .alwaysNetwork
                    let uiLanguage = language.isUILanguage ? language : (model.dataSourceOptions?.uiLanguage ?? .hungarian)
                    let options = DataSourceOptions(dataSourceType: dataSourceType, language: language, uiLanguage: uiLanguage, calendar: defaultCalendar)
                    model.setDataSourceOptions(options)
                }
            } else {
                // Initial setup: navigate to network settings
                NavigationLink(destination: NetworkSettingsScreen(language: code, uiLanguage: code, calendar: defaultCalendar, wizardContext: wizardContext)) {
                    HStack {
                        Text(name)
                        Spacer()
                        Image(systemName: "chevron.right")
                            .foregroundColor(.gray)
                            .font(.caption)
                    }
                    .contentShape(Rectangle())
                }
                .buttonStyle(PlainButtonStyle())
            }
        } else {
            // Fallback for invalid language codes
            HStack {
                Text(name)
                Spacer()
                Text("Invalid")
                    .foregroundColor(.red)
            }
        }
    }
}

struct CalendarChooserScreen: View {
    var language: String
    var uiLanguage: String
    var wizardContext: DataSourceWizardContext
    
    var body: some View {
        if let currentLanguage = Language(rawValue: language) {
            let availableCalendars = currentLanguage.availableCalendars
            
            List {
                ForEach(availableCalendars, id: \.self) { calendarCode in
                    CalendarLink(language: language, uiLanguage: uiLanguage, calendar: calendarCode, wizardContext: wizardContext)
                }
            }.navigationTitle(S.liturgicalCalendar.forLanguage(currentLanguage))
        } else {
            Text("Invalid language")
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
            HStack {
                Text(label)
                Spacer()
            }
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
                    .onTapGesture { 
                        withAnimation { dataSourceType = .alwaysNetwork }
                        if wizardContext == .settingsModification {
                            applySettings()
                        }
                    }
                NetworkSettingsChoice(label: S.onlyOnWifi.forLanguageCode(uiLanguage), checked: dataSourceType == .networkOnWifi)
                    .onTapGesture { 
                        withAnimation { dataSourceType = .networkOnWifi }
                        if wizardContext == .settingsModification {
                            applySettings()
                        }
                    }
                NetworkSettingsChoice(label: S.never.forLanguageCode(uiLanguage), checked: dataSourceType == .alwaysCGI)
                    .onTapGesture { 
                        withAnimation { dataSourceType = .alwaysCGI }
                        if wizardContext == .settingsModification {
                            applySettings()
                        }
                    }
            }
        }
        .navigationTitle(S.networkSettings.forLanguageCode(uiLanguage))
        .toolbar(content: {
            if wizardContext == .initialSetup {
                Button(S.done.forLanguageCode(uiLanguage)) {
                    applySettings()
                }
            }
        })
        .onAppear {
            dataSourceType = model.dataSourceOptions?.dataSourceType ?? .alwaysNetwork
        }
    }
    
    private func applySettings() {
        let options = DataSourceOptions(dataSourceType: dataSourceType, language: Language(rawValue: language)!, uiLanguage: Language(rawValue: uiLanguage)!, calendar: calendar)
        model.setDataSourceOptions(options)
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
                    
                    ForEach([Language.english, Language.czech, Language.hungarian, Language.icelandic, Language.slovak], id: \.self) { lang in
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
        case .english: return "🇺🇸"
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
                    // For initial setup, skip calendar chooser since Latin has only one calendar
                    model.dataSourceOptions = DataSourceOptions(
                        dataSourceType: .alwaysNetwork,
                        language: .latin,
                        uiLanguage: language,
                        calendar: "la"
                    )
                    model.dataSourceOptionsWizardStage = .chooseDataSourceType
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
