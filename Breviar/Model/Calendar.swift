//
//  Date.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 10..
//

import Foundation

var calendar = Calendar(identifier: .gregorian)

struct Day : Hashable, Identifiable {
    var year: Int
    var month: Int
    var day: Int
    
    init(year: Int, month: Int, day: Int) {
        self.year = year
        self.month = month
        self.day = day
    }
    
    init(fromDate date: Date) {
        self.year = calendar.component(.year, from: date)
        self.month = calendar.component(.month, from: date)
        self.day = calendar.component(.day, from: date)
    }
    
    var id : String {
        return "\(year)-\(month)-\(day)"
    }
    
    var date: Date {
        var comps = DateComponents()
        comps.year = year
        comps.month = month
        comps.day = day
        return calendar.date(from: comps)!
    }
    
    var daysSinceEpoch: Int {
        return calendar.ordinality(of: .day, in: .era, for: self.date)!
    }
    
    func dayByAdding(days: Int) -> Day {
        let newDate = calendar.date(byAdding: .day, value: days, to: self.date)!
        return Day(fromDate: newDate)
    }
    
    var weekday : Weekday {
        return Weekday(rawValue: calendar.component(.weekday, from: self.date))!
    }
}

enum Weekday : Int {
    case sunday = 1
    case monday = 2
    case tuesday = 3
    case wednesday = 4
    case thursday = 5
    case friday = 6
    case saturday = 7
}

struct Month {
    var year: Int
    var month: Int
    
    init(year: Int, month: Int, day: Int) {
        self.year = year
        self.month = month
    }
    
    init(fromDate date: Date) {
        self.year = calendar.component(.year, from: date)
        self.month = calendar.component(.month, from: date)
    }
    
    var id : String {
        return "\(year)-\(month)"
    }
    
    var date: Date {
        get {
            var comps = DateComponents()
            comps.year = year
            comps.month = month
            comps.day = 1
            return calendar.date(from: comps)!
        }
    }
    
    func monthByAdding(months: Int) -> Month {
        let newDate = calendar.date(byAdding: .month, value: months, to: self.date)!
        return Month(fromDate: newDate)
    }
}

struct LiturgicalDay : Hashable, Identifiable {
    var day: Day
    var celebrations: [Celebration]

    var id : String {
        return day.id
    }
}

struct LiturgicalMonth: Identifiable {
    var month: Month
    var days: [LiturgicalDay]
    
    var id : String {
        return month.id
    }
}

struct Celebration : Hashable, Identifiable {
    var id: String
    var title: String
    var subtitle: String
    var liturgicalColor: LiturgicalColor
}

enum LiturgicalColor : Int {
    case red = 1
    case white = 2
    case green = 3
    case violet = 4
    case rose = 5
    case black = 6
    case violetOrBlack = 7
    case violetOrWhite = 8
    case roseOrViolet = 9
    
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
}

enum PrayerType: String {
    case invitatory = "mi"
    case officeOfReadings = "mpc"
    case morningPrayer = "mrch"
    case midMorningPrayer = "mpred"
    case midDayPrayer = "mna"
    case midAfternoonPrayer = "mpo"
    case eveningPrayer = "mv"
    case compline = "mk"
    
    var name: String {
        switch self {
        case .invitatory: return S.invitatory.S
        case .officeOfReadings: return S.officeOfReadings.S
        case .morningPrayer: return S.morningPrayer.S
        case .midMorningPrayer: return S.midMorningPrayer.S
        case .midDayPrayer: return S.midDayPrayer.S
        case .midAfternoonPrayer: return S.midAfternoonPrayer.S
        case .eveningPrayer: return S.eveningPrayer.S
        case .compline: return S.compline.S
        }
    }
}

struct Prayer: Identifiable {
    let day: Day
    let celebration: Celebration
    let type: PrayerType
    
    var id : String {
        return "\(day.year)-\(day.month)-\(day.day)/\(celebration.id)/\(type)"
    }
    
    var name: String {
        return self.type.name
    }
}
