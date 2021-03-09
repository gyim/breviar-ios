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

struct LiturgicalDay {
    var date: Date
    var celebrations: [Celebration]
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

class BreviarModel : ObservableObject {
    private var dataSource: BreviarDataSource
    @Published var date: Date
    @Published var dayState: LoadingState<LiturgicalDay> = .idle
    @Published var selectedCelebration: String = ""
    
    init(dataSource: BreviarDataSource) {
        self.dataSource = dataSource
        self.date = Date()
    }
    
    func load() -> BreviarModel {
        switch self.dayState {
        case .idle:
            self.loadDate(Date())
        default:
            break
        }
        return self
    }
    
    func loadDate(_ date: Date) {
        self.date = date
        self.dayState = .loading
        self.selectedCelebration = ""
        
        self.dataSource.getLiturgicalDay(date: date) { (day, error) in
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
    
    func loadDateByAdding(days: Int) {
        switch self.dayState {
        case .idle:
            fallthrough
        case .failed(_):
            fallthrough
        case .loaded(_):
            if let newDate = Calendar.current.date(byAdding: .day, value: days, to: self.date) {
                self.loadDate(newDate)
            }
        default:
            break
        }
    }
}

enum LoadingState<Value> {
    case idle
    case loading
    case failed(Error)
    case loaded(Value)
}
