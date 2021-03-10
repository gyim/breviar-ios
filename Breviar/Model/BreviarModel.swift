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

struct LiturgicalDay : Identifiable {
    var id: String
    var date: Date
    var celebrations: [Celebration]
    
    init(date: Date, celebrations: [Celebration]) {
        self.id = UUID().description
        self.date = date
        self.celebrations = celebrations
    }
}

struct Celebration : Hashable, Identifiable {
    var id: String
    var title: String
    var subtitle: String
    var liturgicalColor: LiturgicalColor
}

enum LiturgicalColor : String {
    case red
    case white
    case green
    case violet
    case rose
    case black
    case violetOrBlack
    case violetOrWhite
    case roseOrViolet
    
    func firstColor() -> LiturgicalColor {
        switch self {
        case .violetOrBlack:
            return .violet
        case .violetOrWhite:
            return .violet
        case .roseOrViolet:
            return .rose
        default:
            return self
        }
    }
    
    func secondColor() -> LiturgicalColor {
        switch self {
        case .violetOrBlack:
            return .black
        case .violetOrWhite:
            return .white
        case .roseOrViolet:
            return .violet
        default:
            return self
        }
    }
    
    static func colorFromId(colorId: Int) -> LiturgicalColor? {
        switch colorId {
        case 1: return .red;
        case 2: return .white;
        case 3: return .green;
        case 4: return .violet;
        case 5: return .rose;
        case 6: return .black;
        case 7: return .violetOrBlack;
        case 8: return .violetOrWhite;
        case 9: return .roseOrViolet;
        default: return nil
        }
    }
}

enum PrayerType {
    case invitatory
    case officeOfReadings
    case morningPrayer
    case midMorningPrayer
    case midDayPrayer
    case midAfternoonPrayer
    case eveningPrayer
    case compline
}

struct Prayer {
    let date: Date
    let type: PrayerType
    let celebration: Celebration
    let body: String
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
