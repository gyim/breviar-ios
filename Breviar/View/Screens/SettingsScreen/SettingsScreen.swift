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
                if let calendar = model.dataSourceOptions?.calendar,
                   let calendarName = CalendarNames[calendar] {
                    SettingsStringLabel(name: S.liturgicalCalendar.S, value: calendarName)
                        .onTapGesture {
                            model.dataSourceOptionsNeeded = true
                        }
                }
                ForEach(entries) { entry in
                    switch entry.type {
                    case .flagSet:
                        NavigationLink(entry.label, destination: SettingsFlagSetView(entry: entry))
                    case .stringChoice:
                        SettingsStringChoiceListEntry(entry: entry)
                    }
                }
            }
        }
        .navigationTitle(S.settings.S)
        .navigationBarTitleDisplayMode(.inline)
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
                HStack {
                    Text(option.label)
                    Spacer()
                    Image(systemName: "checkmark")
                        .foregroundColor(.accentColor)
                        .padding(5)
                        .opacity(checked ? 1 : 0)
                }
                .onTapGesture {
                    withAnimation {
                        self.value = option.value
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
