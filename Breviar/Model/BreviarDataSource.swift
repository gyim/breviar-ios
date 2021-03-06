//
//  BreviarDataSource.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 06..
//

import Foundation

protocol BreviarDataSource {
    func getLiturgicalDay(date: Date) -> LiturgicalDay
}

class TestDataSource : BreviarDataSource {
    func getLiturgicalDay(date: Date) -> LiturgicalDay {
        return LiturgicalDay(date: date, celebrations: [
            Celebration(id: "1", title: "Red celebration", subtitle: "This is a celebration with red color for day: \(date.description)", liturgicalColor: LiturgicalColor.red),
            Celebration(id: "2", title: "White celebration", subtitle: "This is a celebration with white color", liturgicalColor: LiturgicalColor.white),
            Celebration(id: "3", title: "Green celebration", subtitle: "This is a celebration with green color", liturgicalColor: LiturgicalColor.green),
            Celebration(id: "4", title: "Violet celebration", subtitle: "This is a celebration with violet color", liturgicalColor: LiturgicalColor.violet),
            Celebration(id: "5", title: "Rose celebration", subtitle: "This is a celebration with rose color", liturgicalColor: LiturgicalColor.rose),
            Celebration(id: "6", title: "Black celebration", subtitle: "This is a celebration with black color", liturgicalColor: LiturgicalColor.black),
            Celebration(id: "7", title: "Violet or Black celebration", subtitle: "This is a celebration with violet or black color", liturgicalColor: LiturgicalColor.violetOrBlack),
            Celebration(id: "8", title: "Violet or White celebration", subtitle: "This is a celebration with violet or white color", liturgicalColor: LiturgicalColor.violetOrWhite),
            Celebration(id: "9", title: "Rose or Violet celebration", subtitle: "This is a celebration with rose or violet color", liturgicalColor: LiturgicalColor.roseOrViolet),
        ])
    }
}
