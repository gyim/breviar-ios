//
//  BreviarDataSource.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 06..
//

import Foundation

protocol BreviarDataSource {
    func getLiturgicalDay(day: Day, handler: @escaping (LiturgicalDay?, Error?) -> Void)
    func getLiturgicalMonth(month: Month, handler: @escaping (LiturgicalMonth?, Error?) -> Void)
}

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
            for c in 1...(d % 3) {
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
}

enum DataSourceError : String, Error {
    case networkError = "Network error"
    case serverError = "Remote server returned an invalid response"
    case parseError = "Error parsing server response"
}

class LiturgicalDayParser : NSObject, XMLParserDelegate {
    var parser: XMLParser
    var days: [LiturgicalDay]
    var day: LiturgicalDay
    var celebration: Celebration
    var path: [String] = []
    var parseError: Error? = nil
    var parsedText: String = ""
    var afterNewline: Bool = false
    
    init(data: Data) {
        self.parser = XMLParser(data: data)
        self.days = []
        self.day = LiturgicalDay(day: Day(fromDate: Date.init()), celebrations: [])
        self.celebration = Celebration(id: "", title: "", subtitle: "", liturgicalColor: .green)
    }
    
    func parser(_ parser: XMLParser, didStartElement elementName: String, namespaceURI: String?, qualifiedName qName: String?, attributes attributeDict: [String : String] = [:]) {
        path.append(elementName)
        if elementName.lowercased() == "br" {
            // A <BR/> can occur in main celebrations like Eastern Sunday. We want to insert a single newline (we need to trim whitespaces at the next line)
            self.parsedText += "\n"
            self.afterNewline = true
        } else {
            self.parsedText = ""
            self.afterNewline = false
        }
        
        switch elementName {
        case "CalendarDay":
            self.day = LiturgicalDay(day: Day(fromDate: Date.init()), celebrations: [])
        case "Celebration":
            self.celebration = Celebration(id: "", title: "", subtitle: "", liturgicalColor: .green)
            if let celebrationId = attributeDict["Id"] {
                self.celebration.id = celebrationId
            }
        case "LiturgicalCelebrationColor":
            if path.count > 1 && path[path.count-2] == "Celebration" {
                if let cs = attributeDict["Id"],
                   let ci = Int(cs),
                   let color = LiturgicalColor(rawValue: ci) {
                    self.celebration.liturgicalColor = color
                }
            }
        default:
            break
        }
    }
    
    func parser(_ parser: XMLParser, didEndElement elementName: String, namespaceURI: String?, qualifiedName qName: String?) {
        let p = path.suffix(3)
        _ = path.popLast()

        switch p {
        case ["LHData", "CalendarDay"]:
            self.days.append(self.day)
        case ["LHData", "CalendarDay", "DateISO"]:
            let f = DateFormatter()
            f.dateFormat = "yyyy-MM-dd"
            if let date = f.date(from: self.parsedText) {
                self.day.day = Day(fromDate: date)
            }
        case ["Celebration", "StringTitle", "span"]:
            if self.celebration.title == "" {
                self.celebration.title = self.parsedText
            } else {
                self.celebration.subtitle = self.parsedText
            }
        default:
            break
        }
        
        if elementName == "Celebration" {
            self.day.celebrations.append(self.celebration)
        }
    }
    
    func parser(_ parser: XMLParser, foundCharacters s: String) {
        if self.afterNewline {
            // If a <BR/> occurs, we remove the normal white spaces in the next string
            var trimmedString = s
            while trimmedString.hasPrefix("\n") || trimmedString.hasPrefix(" ") || trimmedString.hasPrefix("\t") {
                trimmedString.removeFirst()
            }
            self.parsedText += trimmedString
            self.afterNewline = false
        } else {
            self.parsedText += s
        }
    }
    
    func parser(_ parser: XMLParser, parseErrorOccurred parseError: Error) {
        self.parseError = parseError
    }
    
    func parse() -> ([LiturgicalDay], Error?) {
        self.parser.delegate = self
        if self.parser.parse() {
            if self.days.count > 0 {
                return (self.days, nil)
            } else {
                return ([], DataSourceError.parseError)
            }
        } else {
            return ([], DataSourceError.parseError)
        }
    }
}

class RemoteDataSource : BreviarDataSource {
    func getLiturgicalDay(day: Day, handler: @escaping (LiturgicalDay?, Error?) -> Void) {
        let urlString = "https://lh.kbs.sk/cgi-bin/l.cgi?qt=pxml&d=\(day.day)&m=\(day.month)&r=\(day.year)&j=hu&k=hu"
        
        print("Getting liturgical day from URL: \(urlString)")
        guard let urlcomps = URLComponents(string: urlString) else {
            print("Cannot parse URL: \(urlString)")
            return
        }

        // Query XML
        let task = URLSession.shared.dataTask(with: urlcomps.url!) { (data, response, error) in
            if error != nil {
                DispatchQueue.main.async {
                    handler(nil, DataSourceError.networkError)
                }
                return
            }
            
            if let resp = response as? HTTPURLResponse {
                if !(200...299).contains(resp.statusCode) {
                    DispatchQueue.main.async {
                        handler(nil, DataSourceError.serverError)
                    }
                    return
                }
            }
            
            // Parse XML response
            guard let data = data else { return }
            let parser = LiturgicalDayParser(data: data)
            let (days, error) = parser.parse()
            DispatchQueue.main.async {
                handler(days[0], error)
            }
        }
        task.resume()
    }
    
    func getLiturgicalMonth(month: Month, handler: @escaping (LiturgicalMonth?, Error?) -> Void) {
        let urlString = "https://lh.kbs.sk/cgi-bin/l.cgi?qt=pxml&d=*&m=\(month.month)&r=\(month.year)&j=hu&k=hu"
        
        print("Getting liturgical month from URL: \(urlString)")
        guard let urlcomps = URLComponents(string: urlString) else {
            print("Cannot parse URL: \(urlString)")
            return
        }

        // Query XML
        let task = URLSession.shared.dataTask(with: urlcomps.url!) { (data, response, error) in
            if error != nil {
                DispatchQueue.main.async {
                    handler(nil, DataSourceError.networkError)
                }
                return
            }
            
            if let resp = response as? HTTPURLResponse {
                if !(200...299).contains(resp.statusCode) {
                    DispatchQueue.main.async {
                        handler(nil, DataSourceError.serverError)
                    }
                    return
                }
            }
            
            // Parse XML response
            guard let data = data else { return }
            let parser = LiturgicalDayParser(data: data)
            let (days, error) = parser.parse()
            DispatchQueue.main.async {
                handler(LiturgicalMonth(month: month, days: days), error)
            }
        }
        task.resume()
    }
}
