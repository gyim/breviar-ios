//
//  DatePicker.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 09..
//

import SwiftUI

struct DatePicker: View {
    @EnvironmentObject var model: BreviarModel
    var onDaySelected: () -> Void

    func getTitle(month: Date) -> String {
        let fmt = currentLanguage.dateFormatter(format: "yyyy MMMM")
        return fmt.string(from: month)
    }
    
    var body: some View {
        NavigationView {
            DatePickerContent(onDaySelected: onDaySelected)
                .navigationTitle(getTitle(month: model.month.date))
                .navigationBarItems(
                    leading: Button(
                        action: {
                            withAnimation {
                                onDaySelected()
                            }
                        },
                        label: { Text(S.back.S) })
                )
                .toolbar {
                    HStack{
                        Button(
                            action: {
                                withAnimation {
                                    model.loadMonth(Month(fromDate: Date()))
                                    model.loadDay(Day(fromDate: Date()))
                                    onDaySelected()
                                }
                            },
                            label: {Text(S.today.S)})
                            .padding()
                        Button(
                            action: {
                                withAnimation {
                                    model.loadMonth(model.month.monthByAdding(months: -1))
                                }
                            },
                            label: {Label(S.previousMonth.S ,systemImage: "chevron.left")})
                        Spacer(minLength: 20.0)
                        Button(
                            action: {
                                withAnimation {
                                    model.loadMonth(model.month.monthByAdding(months: 1))
                                }
                            },
                            label: {Label(S.nextMonth.S, systemImage: "chevron.right")})
                    }
                }
        }
    }
}

struct DatePickerContent: View {
    @EnvironmentObject var model: BreviarModel
    var onDaySelected: () -> Void

    var body: some View {
        LoadingView(value: model.monthState) { month in
            DatePickerList(days: month.days, onDaySelected: onDaySelected)
        }
        .id(model.month.id)
    }
}

struct DatePickerList: View {
    @EnvironmentObject var model: BreviarModel
    var days: [LiturgicalDay]
    var onDaySelected: () -> Void
    
    var body: some View {
        let fmt = currentLanguage.dateFormatter(format: "MMMM dd (EE)")
        let today = Day.init(fromDate: Date())
        
        List {
            ForEach(days) { day in
                if day.day.weekday == .sunday && day != days[0] {
                    Divider()
                }
                Section(
                    header: HStack {
                        Text(fmt.string(from: day.day.date))
                            .font(.caption)
                            .fontWeight(.light)
                        if day.day == today {
                            Spacer()
                            Text(S.today.S)
                                .font(.caption)
                                .fontWeight(.bold)
                        }
                    }
                ) {
                    ForEach(day.celebrations) { celebration in
                        CelebrationRow(celebration: celebration, checked: false)
                            .onTapGesture {
                                model.jumpTo(day: day, celebration: celebration)
                                onDaySelected()
                            }
                    }
                }
            }
        }
    }
}

struct DatePicker_Previews: PreviewProvider {
    static var previews: some View {
        let days = [
            LiturgicalDay(
                day: Day(year: 2021, month: 1, day: 1),
                celebrations: [
                    Celebration(id: "0", title: "Red celebration", subtitle: "Celebration 1", liturgicalColor: .red),
                ]
            ),
            LiturgicalDay(
                day: Day(year: 2021, month: 1, day: 2),
                celebrations: [
                    Celebration(id: "0", title: "Green celebration", subtitle: "Celebration 1", liturgicalColor: .green),
                    Celebration(id: "1", title: "White celebration", subtitle: "", liturgicalColor: .white),
                ]
            ),
        ]
        
        NavigationView {
            DatePickerList(days: days) { }
                .navigationTitle("2021 January")
        }
    }
}
