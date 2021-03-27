//
//  DatePicker.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 09..
//

import SwiftUI

struct DatePicker: View {
    @EnvironmentObject var model: CalendarModel
    var onDaySelected: () -> Void

    func getTitle(month: Date) -> String {
        let fmt = DateFormatter()
        fmt.dateFormat = "yyyy MMMM"
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
                        label: { Text("Back") })
                )
                .toolbar {
                    HStack{
                        Button(
                            action: {
                                withAnimation {
                                    model.loadMonth(model.month.monthByAdding(months: -1))
                                }
                            },
                            label: {Label("Previous Day",systemImage: "chevron.left")})
                            .padding()
                        Spacer()
                            .frame(width: 6.0)
                        Button(
                            action: {
                                withAnimation {
                                    model.loadMonth(model.month.monthByAdding(months: 1))
                                }
                            },
                            label: {Label("Next Day", systemImage: "chevron.right")})
                    }
                }
        }
    }
}

struct DatePickerContent: View {
    @EnvironmentObject var model: CalendarModel
    var onDaySelected: () -> Void

    var body: some View {
        switch model.monthState {
        case .idle, .loading:
            Text("Loading...")
        case .failed(let error):
            Text(error.localizedDescription)
        case .loaded(let month):
            DatePickerList(days: month.days, onDaySelected: onDaySelected)
        }
    }
}

struct DatePickerList: View {
    @EnvironmentObject var model: CalendarModel
    var days: [LiturgicalDay]
    var onDaySelected: () -> Void
    
    func getDayFormatter() -> DateFormatter {
        let fmt = DateFormatter()
        fmt.dateFormat = "MMMM dd (EE)"
        return fmt
    }
    
    var body: some View {
        let fmt = getDayFormatter()
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
                            Text("Today")
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
