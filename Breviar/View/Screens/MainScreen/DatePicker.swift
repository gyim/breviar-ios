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
        let fmt = currentLiturgicalLanguage.dateFormatter(format: "yyyy MMMM")
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

enum DatePickerCellType: Identifiable {
    case weekSeparator(id: String)
    case dateHeader(day: LiturgicalDay, isToday: Bool)
    case celebration(day: LiturgicalDay, celebration: Celebration)
    
    var id: String {
        switch self {
        case .weekSeparator(let id):
            return "separator_\(id)"
        case .dateHeader(let day, _):
            return "header_\(day.id)"
        case .celebration(let day, let celebration):
            return "celebration_\(day.id)_\(celebration.id)"
        }
    }
}

struct DatePickerList: View {
    @EnvironmentObject var model: BreviarModel
    var days: [LiturgicalDay]
    var onDaySelected: () -> Void
    
    var body: some View {
        let today = Day.init(fromDate: Date())
        let cells = buildCells(days: days, today: today)
        
        List {
            ForEach(cells) { cell in
                switch cell {
                case .weekSeparator:
                    WeekSeparatorCell()
                case .dateHeader(let day, let isToday):
                    DateHeaderCell(day: day, isToday: isToday)
                case .celebration(let day, let celebration):
                    CelebrationRow(celebration: celebration, checked: false)
                        .onTapGesture {
                            model.jumpTo(day: day, celebration: celebration)
                            onDaySelected()
                        }
                }
            }
        }
    }
    
    private func buildCells(days: [LiturgicalDay], today: Day) -> [DatePickerCellType] {
        var cells: [DatePickerCellType] = []
        
        for (index, day) in days.enumerated() {
            // Add week separator before Sunday (except for first day)
            if day.day.weekday == .sunday && index > 0 {
                cells.append(.weekSeparator(id: day.id))
            }
            
            // Add date header
            let isToday = day.day == today
            cells.append(.dateHeader(day: day, isToday: isToday))
            
            // Add celebrations
            for celebration in day.celebrations {
                cells.append(.celebration(day: day, celebration: celebration))
            }
        }
        
        return cells
    }
}

struct DateHeaderCell: View {
    var day: LiturgicalDay
    var isToday: Bool
    
    var body: some View {
        let fmt = currentLiturgicalLanguage.dateFormatter(format: "MMMM dd (EE)")
        
        HStack {
            Text(fmt.string(from: day.day.date).capitalized)
                .font(.subheadline)
                .fontWeight(.medium)
                .foregroundColor(.primary)
            if isToday {
                Spacer()
                Text(S.today.S)
                    .font(.subheadline)
                    .fontWeight(.bold)
                    .foregroundColor(.accentColor)
            }
        }
        .padding(.top, 16)
        .padding(.bottom, 2)
        .listRowBackground(Color.clear)
    }
}

struct WeekSeparatorCell: View {
    var body: some View {
        Color.clear
            .frame(height: 8)
            .listRowBackground(Color.clear)
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
