//
//  MainScreen.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 06..
//

import SwiftUI

struct MainScreen: View {
    @EnvironmentObject var model: BreviarModel
    @State var datePickerShown = false
    @State var activePrayerType: PrayerType? = nil
    
    func getTitle(day: Day) -> String {
        let today = Day(fromDate: Date())
        let dayDiff = abs(today.daysSinceEpoch - day.daysSinceEpoch)
        
        if dayDiff < 3 {
            let fmt = currentLiturgicalLanguage.dateFormatter(format: "EEEE")
            let dayName = fmt.string(from: day.date).capitalized
            
            if dayDiff == 0 {
                return "\(dayName) (\(S.today.S))"
            } else {
                return dayName
            }
        } else {
            if currentLiturgicalLanguage == .latin {
                // Use custom Latin date formatter
                let fmt = currentLiturgicalLanguage.dateFormatter(format: "d MMMM yyyy")
                return fmt.string(from: day.date)
            } else {
                let fmt = DateFormatter()
                fmt.locale = currentLiturgicalLanguage.locale
                fmt.dateStyle = .long
                return fmt.string(from: day.date)
            }
        }
    }
    
    var body: some View {
        let today = Day(fromDate: Date())
        NavigationView{
            MainScreenContent(activePrayerType: $activePrayerType)
                .navigationTitle(getTitle(day: model.day))
                .navigationBarItems(
                    leading: Button(
                        action: {
                            withAnimation {
                                datePickerShown = true
                            }
                        },
                        label: {Label("", systemImage: "calendar")})
                )
                .toolbar {
                    HStack{
                        // Today button
                        Button(
                            action: {
                                withAnimation {
                                    model.loadDay(today)
                                }
                            },
                            label: {Text(S.today.S)})
                            .disabled(model.day == today)
                            .opacity(model.day == today ? 0 : 1)
                            .padding()
                        
                        // Left button
                        Button(
                            action: {
                                withAnimation {
                                    model.loadDay(model.day.dayByAdding(days: -1))
                                }
                            },
                            label: {Label(S.previousDay.S,systemImage: "chevron.left")})
                        
                        Spacer(minLength: 20).fixedSize()
                        
                        // Right button
                        Button(
                            action: {
                                withAnimation {
                                    model.loadDay(model.day.dayByAdding(days: 1))
                                }
                            },
                            label: {Label(S.nextDay.S, systemImage: "chevron.right")})
                    }
                }
                .sheet(isPresented: $datePickerShown) {
                    DatePicker() {
                        datePickerShown = false
                    }.environmentObject(model)
                }
        }
        .navigationViewStyle(StackNavigationViewStyle())
        .onReceive(model.$navigationTrigger) { trigger in
            if case .prayer(let targetPrayer) = trigger {
                // Reset any active navigation first
                activePrayerType = nil
                
                // Then set the new navigation after a brief delay
                DispatchQueue.main.asyncAfter(deadline: .now() + 0.1) {
                    activePrayerType = targetPrayer.type
                    // Clear the trigger after navigation is set
                    DispatchQueue.main.asyncAfter(deadline: .now() + 0.1) {
                        model.navigationTrigger = nil
                    }
                }
            }
        }
    }
}

struct MainScreenContent: View {
    @EnvironmentObject var model: BreviarModel
    @Binding var activePrayerType: PrayerType?
    
    var body: some View {
        LoadingView(value: model.dayState) { day in
            List{
                Section() {
                    ForEach(day.celebrations) { celebration in
                        CelebrationRow(celebration: celebration, checked: (model.selectedCelebration == celebration.id))
                            .onTapGesture {
                                withAnimation {
                                    model.selectedCelebration = celebration.id
                                }
                            }
                    }
                }

                Section(header: Text(S.prayers.S)) {
                    ForEach(model.getPrayersForSelectedCelebration()) { prayer in
                        PrayerLink(prayer: prayer, activePrayerType: $activePrayerType)
                    }
                }
                
                Section(
                    header: Text(S.settings.S),
                    footer: HStack{
                        Spacer()
                        NavigationLink(S.aboutBreviary.S, destination: AboutScreen())
                            .multilineTextAlignment(.center)
                        Spacer()
                    }
                ) {
                    NavigationLink(destination: SettingsScreen(), label: { Label(S.settings.S, systemImage: "gearshape.fill") })
                }
            }
        }
        .id(model.day.id)
        .onAppear {
            // NOTE: due to a SwiftUI bug, this might be triggered even if we are on a different screen
            model.checkForLiturgicalDataReload()
        }
    }
}

struct CelebrationColorShape : Shape {
    var color: LiturgicalColor
    var width: CGFloat
    
    func path(in rect: CGRect) -> Path {
        var path = Path()
        path.addRect(CGRect(x: rect.minX, y: rect.minY, width: width, height: rect.height))
        return path
    }
}

struct CelebrationColorView : View {
    var color: LiturgicalColor
    var width: CGFloat
    
    var body: some View {
        VStack(spacing: 0){
            CelebrationColorShape(color: color, width: width)
                .foregroundColor(uiLiturgicalColors[color.firstColor()])
            CelebrationColorShape(color: color, width: width)
                .foregroundColor(uiLiturgicalColors[color.secondColor()])
        }
    }
    
}

struct CelebrationRow : View {
    var celebration: Celebration
    var checked: Bool

    var body: some View {
        HStack{
            VStack{
                HStack{
                    if celebration.subtitle == "" {
                        Text(celebration.title).bold().padding(.vertical, 10)
                    } else {
                        Text(celebration.title).bold()
                    }
                    Spacer()
                }
                if celebration.subtitle != "" {
                    HStack{
                        Text(celebration.subtitle)
                            .font(.system(size: 14))
                            .foregroundColor(.secondary)
                        Spacer()
                    }
                }
            }
            .padding(EdgeInsets(top: 0, leading: 15, bottom: 0, trailing: 0))
            .overlay(CelebrationColorView(color: celebration.liturgicalColor, width: 10))
            
            Image(systemName: "checkmark").resizable().frame(width: 20, height: 20)
                .foregroundColor(.accentColor)
                .padding(5)
                .opacity(checked ? 1 : 0)
        }
    }
}

struct PrayerLink: View {
    @EnvironmentObject var model: BreviarModel
    var prayer: Prayer
    @Binding var activePrayerType: PrayerType?
    
    let prayerIcons: [PrayerType: String] = [
        .invitatory: "sparkles",
        .officeOfReadings: "text.book.closed",
        .morningPrayer: "sunrise",
        .midMorningPrayer: "sun.min",
        .midDayPrayer: "sun.max.fill",
        .midAfternoonPrayer: "sun.min.fill",
        .eveningPrayer: "sunset.fill",
        .compline: "moon.stars.fill",
    ]
    
    var body: some View {
        NavigationLink(
            destination: PrayerScreen(prayer: prayer, prayerText: $model.prayerText, textOptions: $model.textOptions),
            isActive: Binding(
                get: { activePrayerType == prayer.type },
                set: { newValue in
                    if newValue {
                        activePrayerType = prayer.type
                    } else if activePrayerType == prayer.type {
                        activePrayerType = nil
                    }
                }
            ),
            label: { Label(prayer.name, systemImage: prayerIcons[prayer.type]!) })
    }
}

struct MainScreen_Previews: PreviewProvider {
    static var previews: some View {
        MainScreen().environmentObject(BreviarModel.testModel())
    }
}
