//
//  BreviarModel.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 01. 17..
//

import Foundation

enum Language : String {
    case czech = "cz"
    case hungarian = "hu"
    case slovak = "sk"
}

func getMonthForDay(_ day: Date) -> Date {
    let calendar = Calendar.current
    var comps = DateComponents()
    comps.year = calendar.component(.year, from: day)
    comps.month = calendar.component(.month, from: day)
    comps.day = 1
    return calendar.date(from: comps)!
}

func dateFrom(year: Int, month: Int, day: Int) -> Date {
    let calendar = Calendar.current
    var comps = DateComponents()
    comps.year = year
    comps.month = month
    comps.day = day
    return calendar.date(from: comps)!
}

class BreviarModel : ObservableObject {
    private var dataSource: BreviarDataSource
    @Published var date: Date
    @Published var dayState: LoadingState<LiturgicalDay> = .idle
    @Published var selectedCelebration: String = ""
    
    @Published var month: Date
    @Published var monthState: LoadingState<[LiturgicalDay]> = .idle
    @Published var datePickerShown: Bool = false
    
    init(dataSource: BreviarDataSource) {
        let now = Date()
        self.dataSource = dataSource
        self.date = now
        self.month = getMonthForDay(now)
    }
    
    func load() -> BreviarModel {
        switch self.dayState {
        case .idle:
            self.loadDay(self.date)
            self.loadMonth(self.month)
        default:
            break
        }
        return self
    }
    
    func loadDay(_ date: Date) {
        self.date = date
        self.dayState = .loading
        self.selectedCelebration = ""
        
        self.dataSource.getDay(date: date) { (day, error) in
            if error == nil {
                if let day = day {
                    self.dayState = .loaded(day)
                    if day.celebrations.count > 0 {
                        self.selectedCelebration = day.celebrations[0].id
                    }
                }
            } else {
                self.dayState = .failed(error!)
            }
        }
    }
    
    func loadDayByAdding(days: Int) {
        switch self.dayState {
        case .idle:
            fallthrough
        case .failed(_):
            fallthrough
        case .loaded(_):
            if let newDate = Calendar.current.date(byAdding: .day, value: days, to: self.date) {
                self.loadDay(newDate)
            }
        default:
            break
        }
    }

    func loadMonth(_ date: Date) {
        self.date = date
        self.monthState = .loading
        
        self.dataSource.getMonth(date: date) { (days, error) in
            if error == nil {
                self.monthState = .loaded(days)
            } else {
                self.monthState = .failed(error!)
            }
        }
    }
}

enum LoadingState<Value> {
    case idle
    case loading
    case failed(Error)
    case loaded(Value)
}

