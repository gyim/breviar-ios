//
//  SettingsScreen.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 04. 18..
//

import SwiftUI

struct SettingsScreen : View {
    @EnvironmentObject var model: BreviarModel

    var body: some View {
        LoadingView(value: model.settingsEntries) { entries in
            List {
                GeneralSettingsView()
                PrayerScreenSettingsView(prayerScreenSettings: model.prayerScreenSettings)
                LiturgicalTextSettingsView(entries: entries)
            }
            .listStyle(GroupedListStyle())
        }
        .navigationTitle(S.settings.S)
        .navigationBarTitleDisplayMode(.inline)
    }
}

// MARK: - General settings

struct GeneralSettingsView : View {
    @EnvironmentObject var model: BreviarModel
    
    private func languageDisplayValue(for options: DataSourceOptions) -> String {
        if options.language == .latin {
            // Show "Latina / UI Language" for Latin
            let latinName = LatinLanguageName.forLanguage(options.uiLanguage)
            let uiLangName = LanguageNames[options.uiLanguage] ?? ""
            return "\(latinName) / \(uiLangName)"
        } else {
            return LanguageNames[options.language] ?? ""
        }
    }
    
    var body: some View {
        Section(header: Text(S.generalSettings.S)) {
            if let dataSourceOptions = model.dataSourceOptions {
                // Language (only show in multi-language mode)
                if !AppConfig.SINGLE_LANGUAGE_MODE {
                    SettingsStringLabel(name: S.language.S, value: languageDisplayValue(for: dataSourceOptions))
                        .contentShape(Rectangle())
                        .onTapGesture {
                            model.dataSourceOptionsWizardContext = .settingsModification
                            model.dataSourceOptionsWizardStage = .chooseLanguage
                            model.dataSourceOptionsNeeded = true
                        }
                }
                
                // Liturgical calendar
                // Show calendar cell if current language has multiple calendars
                if dataSourceOptions.language.hasMultipleCalendars,
                   let calendarName = CalendarNames[dataSourceOptions.calendar] {
                    SettingsStringLabel(name: S.liturgicalCalendar.S, value: calendarName)
                        .contentShape(Rectangle())
                        .onTapGesture {
                            model.dataSourceOptionsWizardContext = .settingsModification
                            model.dataSourceOptionsWizardStage = .chooseCalendar
                            model.dataSourceOptionsNeeded = true
                        }
                }
                
                // Download latest texts
                SettingsStringLabel(name: S.downloadLatestTexts.S, value: dataSourceOptions.dataSourceType.localizedDescription)
                    .contentShape(Rectangle())
                    .onTapGesture {
                        model.dataSourceOptionsWizardContext = .settingsModification
                        model.dataSourceOptionsWizardStage = .chooseDataSourceType
                        model.dataSourceOptionsNeeded = true
                    }
            }
        }
    }
}

// MARK: - Prayer screen settings

struct PrayerScreenSettingsView : View {
    @EnvironmentObject var model: BreviarModel
    @ObservedObject var prayerScreenSettings: PrayerScreenSettings
    
    init(prayerScreenSettings: PrayerScreenSettings) {
        self.prayerScreenSettings = prayerScreenSettings
    }
    
    var body: some View {
        Section(header: Text(S.prayerScreenSettings.S)) {
            NavigationLink(
                destination: FullscreenModeSettingsView(prayerScreenSettings: prayerScreenSettings),
                label: {
                    SettingsStringLabel(name: S.fullscreenMode.S, value: prayerScreenSettings.fullscreenMode.localizedDescription)
                })
        }
    }
}

struct FullscreenModeSettingsView : View {
    @ObservedObject var prayerScreenSettings: PrayerScreenSettings
    
    var body: some View {
        List {
            ForEach(FullscreenMode.allCases, id: \.rawValue) { mode in
                let checked = (mode == prayerScreenSettings.fullscreenMode)
                Button(action: {
                    prayerScreenSettings.fullscreenMode = mode
                }) {
                    HStack {
                        Text(mode.localizedDescription)
                            .foregroundColor(.primary)
                        Spacer()
                        if checked {
                            Image(systemName: "checkmark")
                                .foregroundColor(.accentColor)
                        }
                    }
                }
            }
        }
        .navigationTitle(S.fullscreenMode.S)
    }
}

// MARK: - Liturgical text settings

struct LiturgicalTextSettingsView : View {
    @EnvironmentObject var model: BreviarModel
    var entries: [SettingsEntry]
    
    var body: some View {
        Section(header: Text(S.liturgicalTexts.S)) {
            ForEach(entries) { entry in
                if entry.visible {
                    switch entry.type {
                    case .flagSet:
                        NavigationLink(entry.label, destination: SettingsFlagSetView(entry: entry))
                    case .stringChoice:
                        SettingsStringChoiceListEntry(entry: entry)
                    }
                }
            }
        }
    }
}

// MARK: - String choice

struct SettingsStringChoiceListEntry : View {
    var entry: SettingsEntry
    @ObservedObject var choiceState: StringChoiceState
    
    init(entry: SettingsEntry) {
        self.entry = entry
        self.choiceState = StringChoiceState(entry: entry)
    }
    
    var body: some View {
        NavigationLink(
            destination: SettingsStringChoiceView(entry: entry, value: $choiceState.value),
            label: {
                SettingsStringChoiceLabel(entry: entry, value: $choiceState.value)
            })
    }
}

struct SettingsStringChoiceLabel : View {
    var entry: SettingsEntry
    @Binding var value: Int

    var body: some View {
        SettingsStringLabel(name: entry.label, value: self.labelForValue(self.value))
    }
    
    func labelForValue(_ v: Int) -> String {
        for option in entry.options {
            if option.value == v {
                return option.label
            }
        }
        return ""
    }
}

struct SettingsStringLabel : View {
    var name: String
    var value: String

    var body: some View {
        HStack {
            Text(name)
                .layoutPriority(1)
            Spacer()
            Text(value)
                .lineLimit(1)
                .layoutPriority(0.2)
                .foregroundColor(.accentColor)
        }
    }
}


struct SettingsStringChoiceView : View {
    var entry: SettingsEntry
    @Binding var value: Int
    
    var body: some View {
        List {
            ForEach(entry.options) { option in
                let checked = (option.value == self.value)
                Button(action: {
                    self.value = option.value
                }) {
                    HStack {
                        Text(option.label)
                            .foregroundColor(.primary)
                        Spacer()
                        if checked {
                            Image(systemName: "checkmark")
                                .foregroundColor(.accentColor)
                        }
                    }
                }
            }
        }
        .navigationTitle(entry.label)
    }
}

// MARK: - Flag set

struct SettingsFlagSetView : View {
    var entry: SettingsEntry
    
    var body: some View {
        List {
            ForEach(entry.options) { option in
                SettingsFlagSetToggle(entry: entry, option: option)
            }
        }
        .navigationTitle(entry.label)
    }
}

struct SettingsFlagSetToggle : View {
    var entry: SettingsEntry
    var option: SettingsEntryOption
    @ObservedObject var isOn: FlagSetOptionState
    
    init(entry: SettingsEntry, option: SettingsEntryOption) {
        self.entry = entry
        self.option = option
        self.isOn = FlagSetOptionState(entry: entry, option: option)
    }
    
    var body: some View {
        Toggle(option.label, isOn: $isOn.value)
    }
}

// MARK: - Preview

struct SettingsScreen_Previews: PreviewProvider {
    static var previews: some View {
        Group {
            NavigationView {
                SettingsScreen()
                    .environmentObject(BreviarModel.testModel())
                    .navigationTitle(S.settings.S)
                    .navigationBarTitleDisplayMode(.inline)
            }
        }
    }
}
