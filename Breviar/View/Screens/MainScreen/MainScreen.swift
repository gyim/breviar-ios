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
    
    func getTitle(day: Day) -> String {
        let today = Day(fromDate: Date())
        let dayDiff = abs(today.daysSinceEpoch - day.daysSinceEpoch)
        
        if dayDiff < 3 {
            let fmt = currentLanguage.dateFormatter(format: "EEEE")
            let dayName = fmt.string(from: day.date).capitalized
            
            if dayDiff == 0 {
                return "\(dayName) (\(S.today.S))"
            } else {
                return dayName
            }
        } else {
            let fmt = DateFormatter()
            fmt.locale = currentLanguage.locale
            fmt.dateStyle = .long
            return fmt.string(from: day.date)
        }
    }
    
    var body: some View {
        let today = Day(fromDate: Date())
        NavigationView{
            MainScreenContent()
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
    }
}

struct MainScreenContent: View {
    @EnvironmentObject var model: BreviarModel
    
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
                        PrayerLink(prayer: prayer)
                    }
                }
                
                Section(header: Text(S.settings.S)) {
                    NavigationLink(destination: SettingsScreen(), label: { Label(S.settings.S, systemImage: "gearshape.fill") })
                }
            }
        }
        .id(model.day.id)
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
            label: { Label(prayer.name, systemImage: prayerIcons[prayer.type]!) })
    }
}

struct MainScreen_Previews: PreviewProvider {
    static var previews: some View {
        MainScreen().environmentObject(BreviarModel.testModel())
    }
}
