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
    @Published var day: Day
    @Published var dayState: LoadingState<LiturgicalDay> = .idle
    @Published var selectedCelebration: String = ""
    
    @Published var month: Month
    @Published var monthState: LoadingState<LiturgicalMonth> = .idle
    @Published var datePickerShown: Bool = false
    
    @Published var prayerState: LoadingState<String> = .idle
    
    init(dataSource: BreviarDataSource) {
        let now = Date()
        self.dataSource = dataSource
        self.day = Day(fromDate: now)
        self.month = Month(fromDate: now)
    }
    
    func load() -> BreviarModel {
        switch self.dayState {
        case .idle:
            self.loadDay(self.day)
            self.loadMonth(self.month)
        default:
            break
        }
        return self
    }
    
    func loadDay(_ day: Day) {
        self.day = day
        self.dayState = .loading
        self.selectedCelebration = ""
        
        self.dataSource.getLiturgicalDay(day: day) { (liturgicalDay, error) in
            if error == nil {
                if let liturgicalDay = liturgicalDay {
                    self.dayState = .loaded(liturgicalDay)
                    if liturgicalDay.celebrations.count > 0 {
                        self.selectedCelebration = liturgicalDay.celebrations[0].id
                    }
                }
            } else {
                self.dayState = .failed(error!)
            }
        }
    }
    
    func loadMonth(_ month: Month) {
        self.month = month
        self.monthState = .loading
        
        self.dataSource.getLiturgicalMonth(month: month) { (liturgicalMonth, error) in
            if error == nil {
                if let liturgicalMonth = liturgicalMonth {
                    self.monthState = .loaded(liturgicalMonth)
                }
            } else {
                self.monthState = .failed(error!)
            }
        }
    }
    
    func loadPrayer(_ prayerType: PrayerType, day: LiturgicalDay, celebration: Celebration) {
        self.prayerState = .loading
        self.dataSource.getPrayerText(day: day, celebration: celebration, prayerType: prayerType) { (prayerText, error) in
            if let prayerText = prayerText {
                self.prayerState = .loaded(prayerText)
            } else {
                self.prayerState = .failed(error!)
            }
        }
    }
    
    func jumpTo(day: LiturgicalDay, celebration: Celebration) {
        self.day = day.day
        self.dayState = .loaded(day)
        self.selectedCelebration = celebration.id
        self.datePickerShown = false
    }
    
    func getCurrentCelebration() -> (LiturgicalDay, Celebration)? {
        switch self.dayState {
        case .loaded(let day):
            for celebration in day.celebrations {
                if celebration.id == self.selectedCelebration {
                    return (day, celebration)
                }
            }
            return nil
        default:
            return nil
        }
    }
}

enum LoadingState<Value> {
    case idle
    case loading
    case failed(Error)
    case loaded(Value)
}

