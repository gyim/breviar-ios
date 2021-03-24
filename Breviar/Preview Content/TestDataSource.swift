//
//  TestDataSource.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 24..
//

import Foundation

class TestDataSource : BreviarDataSource {
    func getLiturgicalDay(day: Day, handler: (LiturgicalDay?, Error?) -> Void) {
        let day = LiturgicalDay(day: day, celebrations: [
            Celebration(id: "1", title: "Red celebration", subtitle: "This is a celebration with red color for day: \(day.date.description)", liturgicalColor: LiturgicalColor.red),
            Celebration(id: "2", title: "White celebration", subtitle: "This is a celebration with white color", liturgicalColor: LiturgicalColor.white),
            Celebration(id: "3", title: "Green celebration", subtitle: "This is a celebration with green color", liturgicalColor: LiturgicalColor.green),
            Celebration(id: "4", title: "Violet celebration", subtitle: "This is a celebration with violet color", liturgicalColor: LiturgicalColor.violet),
            Celebration(id: "5", title: "Rose celebration", subtitle: "This is a celebration with rose color", liturgicalColor: LiturgicalColor.rose),
            Celebration(id: "6", title: "Black celebration", subtitle: "This is a celebration with black color", liturgicalColor: LiturgicalColor.black),
            Celebration(id: "7", title: "Violet or Black celebration", subtitle: "This is a celebration with violet or black color", liturgicalColor: LiturgicalColor.violetOrBlack),
            Celebration(id: "8", title: "Violet or White celebration", subtitle: "This is a celebration with violet or white color", liturgicalColor: LiturgicalColor.violetOrWhite),
            Celebration(id: "9", title: "Rose or Violet celebration", subtitle: "This is a celebration with rose or violet color", liturgicalColor: LiturgicalColor.roseOrViolet),
        ])
        handler(day, nil)
    }
    
    func getLiturgicalMonth(month: Month, handler: @escaping (LiturgicalMonth?, Error?) -> Void) {
        var days : [LiturgicalDay] = []
        for d in 1...10 {
            var day = LiturgicalDay(day: Day(year: month.year, month: month.month, day: d), celebrations: [])
            for c in 1...(d % 3 + 1) {
                day.celebrations.append(Celebration(
                    id: "\(c)",
                    title: "Day \(d) celebration \(c)",
                    subtitle: "This is a test celebration.",
                    liturgicalColor: LiturgicalColor(rawValue: (d+c) % 9 + 1)!
                ))
            }
            
            days.append(day)
        }
        handler(LiturgicalMonth(month: month, days: days), nil)
    }
    
    func getPrayerText(day: LiturgicalDay, celebration: Celebration, prayerType: PrayerType, handler: @escaping (String?, Error?) -> Void) {
        handler("<b>Hello world</b>", nil)
    }
}
