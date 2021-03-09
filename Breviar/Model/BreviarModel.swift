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
    @Published var dayState: LoadingState<LiturgicalDay> = .idle
    @Published var celebrationIndex: Int = 0
    
    init(dataSource: BreviarDataSource) {
        self.dataSource = dataSource
    }
    
    func load() -> BreviarModel {
        switch self.dayState {
        case .idle:
            self.loadDate(Date.init())
        default:
            break
        }
        return self
    }
    
    func loadDate(_ date: Date) {
        let now = Date.init()
        self.dayState = .loading
        self.celebrationIndex = 0
        
        self.dataSource.getLiturgicalDay(date: now) { (day, error) in
            if error == nil {
                self.dayState = .loaded(day!)
            } else {
                self.dayState = .failed(error!)
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
