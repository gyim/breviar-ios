//
//  DatePicker.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 09..
//

import SwiftUI

struct DatePicker: View {
    @EnvironmentObject var model: BreviarModel
    
    func getTitle(month: Date) -> String {
        let fmt = DateFormatter()
        fmt.dateFormat = "yyyy MMMM"
        return fmt.string(from: month)
    }
    
    var body: some View {
        NavigationView {
            DatePickerContent()
                .navigationTitle(getTitle(month: model.month.date))
        }
    }
}

struct DatePickerContent: View {
    @EnvironmentObject var model: BreviarModel
    
    var body: some View {
        switch model.monthState {
        case .idle, .loading:
            Text("Loading...")
        case .failed(let error):
            Text(error.localizedDescription)
        case .loaded(let month):
            List {
                DatePickerList(days: month.days)
            }
        }
    }
}

struct DatePickerList: View {
    var days: [LiturgicalDay]
    
    func getDayFormatter() -> DateFormatter {
        let fmt = DateFormatter()
        fmt.dateFormat = "MMMM dd (EE)"
        return fmt
    }
    
    var body: some View {
        let fmt = getDayFormatter()
        
        List {
            ForEach(days) { day in
                Section(header: Text(fmt.string(from: day.day.date))) {
                    ForEach(day.celebrations) { celebration in
                        CelebrationRow(celebration: celebration, checked: false)
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
                    Celebration(id: "1", title: "White celebration", subtitle: "Celebration 2", liturgicalColor: .white),
                ]
            ),
        ]
        
        NavigationView {
            DatePickerList(days: days)
                .navigationTitle("2021 January")
        }
    }
}
