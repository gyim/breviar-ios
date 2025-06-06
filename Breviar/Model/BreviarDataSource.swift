//
//  BreviarDataSource.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 06..
//

import Foundation
import Network

protocol BreviarDataSource {
    func setOptions(_ options: DataSourceOptions)
    func getLiturgicalDay(day: Day, forceLocal: Bool, handler: @escaping (LiturgicalDay?, Error?) -> Void)
    func getLiturgicalMonth(month: Month, forceLocal: Bool, handler: @escaping (LiturgicalMonth?, Error?) -> Void)
    func getPrayerText(day: LiturgicalDay, celebration: Celebration, prayerType: PrayerType, opts: [String: String], forceLocal: Bool, handler: @escaping (String?, Error?) -> Void)
    func getTTSPrayerText(day: LiturgicalDay, celebration: Celebration, prayerType: PrayerType, opts: [String: String], forceLocal: Bool, handler: @escaping (String?, Error?) -> Void)
    func parsePrayerLink(url: URL) -> BreviarLink
    func getSettingsEntries(forceLocal: Bool, handler: @escaping ([SettingsEntry]?, Error?) -> Void)
    func getAboutPage(handler: @escaping (String?, Error?) -> Void)
}

enum DataSourceError: LocalizedError {
    case parseError
    case emptyResponse
    
    public var errorDescription: String? {
        switch self {
        case .parseError:
            return S.errParseError.S
        case .emptyResponse:
            return S.errEmptyResponse.S
        }
    }
}

enum BreviarLink {
    case unknownLink
    case prayerTextLink([String: String])
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
            let f = currentLanguage.dateFormatter(format: "yyyy-MM-dd")
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
                return ([], DataSourceError.emptyResponse)
            }
        } else {
            return ([], DataSourceError.parseError)
        }
    }
}

class SettingsParser : NSObject, XMLParserDelegate {
    var parser: XMLParser
    var path: [String] = []
    
    // Settings entries
    let entryTags = ["Opt0Special", "Opt1PrayerPortions", "Opt2Export", "Opt3Communia", "Opt5Alternatives", "Opt6AlternativesMultivalue"]
    let hiddenEntryTags = ["Opt6AlternativesMultivalue"]
    let skipEntryLabels = ["hu_text", "sk_text", "cz_text", "is_text", "la_text", "", "/"]
    let skipOptions = [
        "o0": [ // liturgical calendar settings
            "64":      true, // use normal font instead of bold
            "128":     true, // show date chooser buttons after prayer selection buttons
            "256":     true, // only text for TTS
            "1024":    true, // show navigation lines (on right side)
            "262144":  true, // navigation arrows on the left
            "524288":  true, // navigation arrows
            "1048576": true, // show only navigation arrows pointing down
        ]
    ]
    var entry: SettingsEntry?
    var entries: [SettingsEntry] = []
    
    // Display options
    let displayOptionsName = "o2"
    
    // Communia options
    let communiaEntryName = "o3"
    let communiaOptionsListTag = "LiturgicalCelebrationCommuniaValues"
    let communiaOptionTag = "LiturgicalCelebrationCommunia"
    var communiaOptions: [SettingsEntryOption] = []
    var communiaOption: SettingsEntryOption = SettingsEntryOption(label: "", value: 0)
    
    init(data: Data) {
        self.parser = XMLParser(data: data)
    }
    
    func parser(_ parser: XMLParser, didStartElement elementName: String, namespaceURI: String?, qualifiedName qName: String?, attributes: [String : String] = [:]) {
        let parent = self.path.count > 0 ? self.path[self.path.count - 1] : ""
        self.path.append(elementName)

        if parent == "Options" && entryTags.contains(elementName) {
            // Parse settings entries (options are in this tag, execpt for communia)
            guard let name = attributes["Name"] else { return }
            guard let label = attributes["Text"] else { return }
            
            // Get default value
            guard let defaultValueS = attributes["Value"], let defaultValue = Int(defaultValueS) else { return }
            
            // Create settings entry
            let type: SettingsEntryType = name == communiaEntryName ? .stringChoice : .flagSet
            self.entry = SettingsEntry(name: name, label: normalizeLabel(label), type: type, defaultValue: defaultValue, options: [], visible: !hiddenEntryTags.contains(elementName))
        } else if self.entry != nil {
            // Parse settings entry options (flags only)
            guard let label = attributes["Text"] else { return }
            guard let valueS = attributes["Id"], let value = Int(valueS) else { return }
            if skipEntryLabels.contains(label) { return }
            if skipOptions[self.entry!.name]?[valueS] != nil { return }
            self.entry?.options.append(SettingsEntryOption(label: normalizeLabel(label), value: value))
        } else if elementName == communiaOptionTag {
            guard let valueS = attributes["Id"], let value = Int(valueS) else { return }
            self.communiaOption = SettingsEntryOption(label: "", value: value)
        }
    }

    func parser(_ parser: XMLParser, foundCharacters s: String) {
        let elementName = self.path.count > 0 ? self.path[self.path.count-1] : ""
        if elementName == communiaOptionTag {
            self.communiaOption.label += s
        }
    }

    func parser(_ parser: XMLParser, didEndElement elementName: String, namespaceURI: String?, qualifiedName qName: String?) {
        _ = self.path.popLast()
        let parent = self.path.count > 0 ? self.path[self.path.count - 1] : ""
        
        if parent == "Options", let entry = self.entry {
            if entry.name != displayOptionsName {
                self.entries.append(entry)
            }
            self.entry = nil
        } else if elementName == communiaOptionTag {
            self.communiaOption.label = normalizeLabel(self.communiaOption.label)
            if self.communiaOption.label != "" {
                self.communiaOptions.append(self.communiaOption)
            }
            self.communiaOption = SettingsEntryOption(label: "", value: 0)
        } else if elementName == communiaOptionsListTag {
            // Update options in already existing entry
            for i in (0..<entries.count) {
                if entries[i].name == communiaEntryName {
                    entries[i].options = communiaOptions
                }
            }
        }
    }
    
    func parse() -> ([SettingsEntry]?, Error?) {
        self.parser.delegate = self
        if !self.parser.parse() {
            if let error = self.parser.parserError {
                print("Error parsing settings XML: \(error)")
                return (nil, error)
            }
        }
        
        return (self.entries, nil)
    }
    
    func normalizeLabel(_ inputString: String) -> String {
        var s = inputString
        s = s.prefix(1).capitalized + s.dropFirst() // Capitalize first word
        s = s.trimmingCharacters(in: .whitespaces)
        s = s.trimmingCharacters(in: CharacterSet(charactersIn: ":"))
        return s
    }
}

class CGIDataSource : BreviarDataSource {
    var remoteCGIClient: RemoteCGIClient = RemoteCGIClient()
    var localCGIClient: CGIClient = LocalCGIClient()
    var options: DataSourceOptions? = nil
    var pathMonitor: NWPathMonitor
    var onWifi: Bool = false
    
    init() {
        self.options = DataSourceOptions.savedOptions
        self.remoteCGIClient.allowsCellularAccess = (options?.dataSourceType == .alwaysNetwork)

        self.pathMonitor = NWPathMonitor()
        self.pathMonitor.start(queue: .global(qos: .background))
        self.pathMonitor.pathUpdateHandler = { path in
            self.onWifi = (path.status == .satisfied && !path.usesInterfaceType(.cellular));
        }
    }
    
    deinit {
        self.pathMonitor.cancel()
    }
    
    func cgiClient(forceLocal: Bool) -> CGIClient {
        if forceLocal {
            return self.localCGIClient
        }
        
        switch self.options?.dataSourceType {
        case .alwaysCGI:
            return self.localCGIClient
        case .alwaysNetwork:
            return self.remoteCGIClient
        case .networkOnWifi:
            return self.onWifi ? self.remoteCGIClient : self.localCGIClient
        default:
            return self.localCGIClient
        }
    }
    
    func setOptions(_ options: DataSourceOptions) {
        self.options = options
        self.remoteCGIClient.allowsCellularAccess = (options.dataSourceType == .alwaysNetwork)
    }
    
    var cgiLanguageCode: String {
        if self.options?.calendar == "czop" {
            return "c2"
        } else {
            return self.options?.language.rawValue ?? ""
        }
    }
    
    var cgiUILanguageCode: String {
        if self.options?.calendar == "czop" {
            return "c2"
        } else {
            return self.options?.uiLanguage.rawValue ?? ""
        }
    }
    
    func getLiturgicalDay(day: Day, forceLocal: Bool, handler: @escaping (LiturgicalDay?, Error?) -> Void) {
        let args = [
            "qt": "pxml",
            "d": day.day.description,
            "m": day.month.description,
            "r": day.year.description,
            "j": self.cgiLanguageCode,
            "k": self.options?.calendar ?? "",
        ]
        
        self.cgiClient(forceLocal: forceLocal).makeRequest(args) { data, error in
            if let data = data {
                let parser = LiturgicalDayParser(data: data)
                let (days, error) = parser.parse()
                DispatchQueue.main.async {
                    if error == nil {
                        handler(days[0], nil )
                    } else {
                        handler(nil, error)
                    }
                }
            } else {
                DispatchQueue.main.async {
                    handler(nil, error)
                }
            }
        }
    }
    
    func getLiturgicalMonth(month: Month, forceLocal: Bool, handler: @escaping (LiturgicalMonth?, Error?) -> Void) {
        let args = [
            "qt": "pxml",
            "d": "*",
            "m": month.month.description,
            "r": month.year.description,
            "j": self.cgiLanguageCode,
            "k": self.options?.calendar ?? "",
        ]

        self.cgiClient(forceLocal: forceLocal).makeRequest(args) { data, error in
            if let data = data {
                let parser = LiturgicalDayParser(data: data)
                let (days, error) = parser.parse()
                DispatchQueue.main.async {
                    if error == nil {
                        handler(LiturgicalMonth(month: month, days: days), nil )
                    } else {
                        handler(nil, error)
                    }
                }
            } else {
                DispatchQueue.main.async {
                    handler(nil, error)
                }
            }
        }
    }
    
    let removeFlags = [
        "o0": 256    | // only text for TTS
              1024   | // show navigation lines (on right side)
              524288   // navigation arrows
    ]
    func valueForOption(_ key: String) -> String {
        var option = UserDefaults.standard.integer(forKey: key);
        if let flags = removeFlags[key] {
            option &= ~flags;
        }
        return String(option);
    }
    
    func getPrayerText(day: LiturgicalDay, celebration: Celebration, prayerType: PrayerType, opts: [String: String], forceLocal: Bool, handler: @escaping (String?, Error?) -> Void) {
        let d = day.day
        var args = [
            "qt": "pdt",
            "d": d.day.description,
            "m": d.month.description,
            "r": d.year.description,
            "p": prayerType.rawValue.description,
            "ds": celebration.id,
            "o0": valueForOption("o0"),
            "o1": valueForOption("o1"),
            "o2": "16896", // Override display settings
            "o3": valueForOption("o3"),
            "o4": valueForOption("o4"),
            "o5": valueForOption("o5"),
            "o6": valueForOption("o6"),
            "j": self.cgiLanguageCode,
            "k": self.options?.calendar ?? "",
        ]
        for (k, v) in opts {
            args[k] = v
        }
        
        self.cgiClient(forceLocal: forceLocal).makeRequest(args) { data, error in
            if let data = data {
                if let response = String(data: data, encoding: .utf8) {
                    DispatchQueue.main.async {
                        handler(self.getHTMLBody(response), nil)
                    }
                } else {
                    DispatchQueue.main.async {
                        print("Cannot parse UTF-8 string from server")
                        handler(nil, DataSourceError.parseError)
                    }
                }
            } else {
                DispatchQueue.main.async {
                    handler(nil, error)
                }
            }
        }
    }
    
    func getTTSPrayerText(day: LiturgicalDay, celebration: Celebration, prayerType: PrayerType, opts: [String: String], forceLocal: Bool, handler: @escaping (String?, Error?) -> Void) {
        var ttsOpts = opts
        ttsOpts["of0bf"] = "1"
        ttsOpts["of2rm"] = "0"
        getPrayerText(day: day, celebration: celebration, prayerType: prayerType, opts: ttsOpts, forceLocal: forceLocal, handler: handler)
    }
    
    private func getHTMLBody(_ html: String) -> String {
        // Find body start
        var body: String.SubSequence = html[html.startIndex...]
        if let r = html.range(of: "<body") {
            let b = html[r.upperBound...]
            if let r = b.range(of:">") {
                body = b[r.upperBound...].dropFirst()
            }
        }
        
        // Find body end
        if let r = body.range(of: "</body") {
            body = body[body.startIndex..<r.lowerBound]
        }
        
        // Make sure that body can be put into JS template expression
        return String(body.replacingOccurrences(of: "`", with: "'").replacingOccurrences(of: "$", with: "_"))
    }
    
    func parsePrayerLink(url: URL) -> BreviarLink {
        let s = url.absoluteString
        if !s.contains("l.cgi?") {
            return .unknownLink
        }
        guard let query = url.query else { return .unknownLink }
        
        var opts: [String: String] = [:]
        for kv in query.split(separator: "&") {
            let arg = kv.split(separator: "=", maxSplits: 2, omittingEmptySubsequences: false)
            if arg.count == 2 {
                opts[String(arg[0])] = String(arg[1])
            }
        }
        
        return .prayerTextLink(opts)
    }
    
    func getSettingsEntries(forceLocal: Bool, handler: @escaping ([SettingsEntry]?, Error?) -> Void) {
        let args = [
            "qt": "pxml",
            "j": self.cgiLanguageCode,
            "k": self.options?.calendar ?? "",
        ]
        
        self.cgiClient(forceLocal: forceLocal).makeRequest(args) { data, error in
            if let data = data {
                let parser = SettingsParser(data: data)
                let (entries, error) = parser.parse()
                DispatchQueue.main.async {
                    if error == nil {
                        handler(entries, nil )
                    } else {
                        handler(nil, error)
                    }
                }
            } else {
                DispatchQueue.main.async {
                    handler(nil, error)
                }
            }
        }
    }
    
    func getAboutPage(handler: @escaping (String?, Error?) -> Void) {
        let args = [
            "qt": "pst",
            "st": "i",
            "p": "0",
            "j": self.cgiUILanguageCode,
        ]
        self.cgiClient(forceLocal: true).makeRequest(args) { data, error in
            let response = String(data: data!, encoding: .utf8)
            DispatchQueue.main.async {
                handler(self.getHTMLBody(response!), nil)
            }
        }
    }
}
