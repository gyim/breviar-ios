//
//  BreviarDataSource.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 06..
//

import Foundation
import Network

protocol BreviarDataSource {
    var networkStatus: NetworkStatus { get }
    func setOptions(_ options: DataSourceOptions)
    func getLiturgicalDay(day: Day, policy: DataSourcePolicy, handler: @escaping (LiturgicalDay?, Error?) -> Void)
    func getLiturgicalMonth(month: Month, policy: DataSourcePolicy, handler: @escaping (LiturgicalMonth?, Error?) -> Void)
    func getPrayerText(day: LiturgicalDay, celebration: Celebration, prayerType: PrayerType, opts: [String: String], policy: DataSourcePolicy, handler: @escaping (String?, Error?) -> Void)
    func getTTSPrayerText(day: LiturgicalDay, celebration: Celebration, prayerType: PrayerType, opts: [String: String], policy: DataSourcePolicy, handler: @escaping (String?, Error?) -> Void)
    func parsePrayerLink(url: URL) -> BreviarLink
    func getSettingsEntries(policy: DataSourcePolicy, handler: @escaping ([SettingsEntry]?, Error?) -> Void)
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
    case webLink(URL)
    case externalAppLink(URL)
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
            "2":       true, // Bible references (handled by BibleLinkMode)
            "4096":    true, // Bible references on bible.com (handled by BibleLinkMode)
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
    let networkStatus = NetworkStatus()
    var remoteCGIClient: RemoteCGIClient = RemoteCGIClient()
    var localCGIClient: CGIClient = LocalCGIClient()
    var options: DataSourceOptions? = nil
    var pathMonitor: NWPathMonitor
    private var pathSignature: String? = nil
    
    init() {
        self.options = DataSourceOptions.savedOptions
        self.networkStatus.setDataSourceType(self.options?.dataSourceType)

        self.pathMonitor = NWPathMonitor()
        self.pathMonitor.pathUpdateHandler = { [weak self] path in
            guard let self = self else { return }
            let connected = (path.status == .satisfied || path.status == .requiresConnection)
            let onWifi = connected && !path.usesInterfaceType(.cellular)
            let signature = CGIDataSource.signature(of: path)

            DispatchQueue.main.async {
                if self.pathSignature != signature {
                    // A different network may well reach the server again
                    self.pathSignature = signature
                    self.networkStatus.clearCooldown()
                }
                self.networkStatus.updatePath(isConnected: connected, isOnWifi: onWifi)
            }
        }
        self.pathMonitor.start(queue: DispatchQueue(label: "breviar-network-monitor", qos: .utility))
    }
    
    deinit {
        self.pathMonitor.cancel()
    }
    
    /// Describes the network the device is on, so that flapping updates of the same path
    /// do not clear the server cooldown.
    private static func signature(of path: NWPath) -> String {
        let interfaceTypes: [NWInterface.InterfaceType] = [.wifi, .cellular, .wiredEthernet, .other]
        let used = interfaceTypes.filter { path.usesInterfaceType($0) }.map { "\($0)" }
        return "\(path.status)|\(used.joined(separator: ","))"
    }
    
    func setOptions(_ options: DataSourceOptions) {
        self.options = options
        self.networkStatus.setDataSourceType(options.dataSourceType)
        self.networkStatus.clearCooldown()
    }

    private func shouldTryRemote(policy: DataSourcePolicy, mode: DataSourceType?) -> Bool {
        switch policy {
        case .forceLocal:
            return false
        case .forceRemote:
            return true
        case .automatic:
            guard mode == .alwaysNetwork || mode == .networkOnWifi else { return false }
            guard self.networkStatus.isConnected else { return false }
            guard mode == .alwaysNetwork || self.networkStatus.isOnWifi else { return false }
            return !self.networkStatus.isCooldownActive
        }
    }

    /// Runs one CGI query according to the policy, falling back to the local CGI whenever
    /// the server cannot deliver a usable response. Must be called on the main queue.
    private func load<T>(args: [String: String], policy: DataSourcePolicy, parse: @escaping (Data) -> Result<T, Error>, handler: @escaping (T?, Error?) -> Void) {
        let mode = self.options?.dataSourceType
        let tracksProvenance = (policy != .forceLocal && mode != .alwaysCGI)

        let deliverLocal = {
            self.loadLocal(args: args, parse: parse) { result in
                if tracksProvenance {
                    self.networkStatus.didFinishLoad(local: true)
                }
                switch result {
                case .success(let value):
                    handler(value, nil)
                case .failure(let error):
                    handler(nil, error)
                }
            }
        }

        guard self.shouldTryRemote(policy: policy, mode: mode) else {
            deliverLocal()
            return
        }

        let allowsCellular = (mode == .alwaysNetwork || policy == .forceRemote)
        self.loadRemote(args: args, allowsCellular: allowsCellular, parse: parse) { result in
            switch result {
            case .success(let value):
                self.networkStatus.clearCooldown()
                self.networkStatus.didFinishLoad(local: false)
                handler(value, nil)
            case .failure(let failure):
                if failure.startsCooldown && self.networkStatus.isConnected {
                    self.networkStatus.startCooldown()
                }
                print("Falling back to local CGI")
                deliverLocal()
            }
        }
    }

    /// First remote attempt plus retries with exponential backoff, all within
    /// `NetworkConstants.onlineAttemptBudget`. Must be called on the main queue.
    private func loadRemote<T>(args: [String: String], allowsCellular: Bool, parse: @escaping (Data) -> Result<T, Error>, completion: @escaping (Result<T, RemoteFailure>) -> Void) {
        self.networkStatus.beginRemoteRequest()
        let deadline = Date().addingTimeInterval(NetworkConstants.onlineAttemptBudget)

        // The only exit of this function: it balances the request counter exactly once
        let finish: (Result<T, RemoteFailure>) -> Void = { result in
            self.networkStatus.endRemoteRequest()
            completion(result)
        }

        func attempt(_ attemptNumber: Int, retryDelay: TimeInterval) {
            let timeout = max(deadline.timeIntervalSinceNow, NetworkConstants.minimumAttemptTime)
            self.remoteCGIClient.fetch(args, allowsCellularAccess: allowsCellular, timeout: timeout) { result in
                // Parsing runs on the session's queue, everything below on the main queue
                let parsed: Result<T, RemoteFailure> = result.flatMap { data in
                    // A response that cannot be parsed did not come from the breviary server
                    // (captive portals answer with their own HTML and HTTP 200)
                    switch parse(data) {
                    case .success(let value):
                        return .success(value)
                    case .failure:
                        return .failure(.invalidContent)
                    }
                }

                DispatchQueue.main.async {
                    guard case .failure(let failure) = parsed else {
                        finish(parsed)
                        return
                    }

                    let hasTimeLeft = Date().addingTimeInterval(retryDelay + NetworkConstants.minimumAttemptTime) < deadline
                    if failure.isRetryable && self.networkStatus.isConnected && hasTimeLeft {
                        print("Remote attempt \(attemptNumber) failed: \(failure), retrying in \(retryDelay) s")
                        DispatchQueue.main.asyncAfter(deadline: .now() + retryDelay) {
                            attempt(attemptNumber + 1, retryDelay: retryDelay * 2)
                        }
                    } else {
                        print("Remote attempt \(attemptNumber) failed: \(failure)")
                        finish(parsed)
                    }
                }
            }
        }

        attempt(1, retryDelay: NetworkConstants.initialRetryDelay)
    }

    /// Runs the CGI built into the app. Reports the result on the main queue.
    private func loadLocal<T>(args: [String: String], parse: @escaping (Data) -> Result<T, Error>, completion: @escaping (Result<T, Error>) -> Void) {
        self.localCGIClient.makeRequest(args) { data, error in
            let result: Result<T, Error>
            if let data = data {
                result = parse(data)
            } else {
                result = .failure(error ?? CGIError.emptyResponse)
            }
            DispatchQueue.main.async {
                completion(result)
            }
        }
    }

    private static func parseLiturgicalDays(_ data: Data) -> Result<[LiturgicalDay], Error> {
        let parser = LiturgicalDayParser(data: data)
        let (days, error) = parser.parse()
        if let error = error {
            return .failure(error)
        }
        return .success(days)
    }

    private static func parseSettings(_ data: Data) -> Result<[SettingsEntry], Error> {
        let parser = SettingsParser(data: data)
        let (entries, error) = parser.parse()
        if let error = error {
            return .failure(error)
        }
        guard let entries = entries else {
            return .failure(DataSourceError.parseError)
        }
        return .success(entries)
    }

    private static func parsePrayerHTML(_ data: Data) -> Result<String, Error> {
        guard let response = String(data: data, encoding: .utf8) else {
            print("Cannot parse UTF-8 string from server")
            return .failure(DataSourceError.parseError)
        }
        return .success(getHTMLBody(response))
    }
    
    var cgiLanguageCode: String {
        if self.options?.calendar == "czop" {
            return "c2"
        } else {
            return self.options?.language.rawValue ?? ""
        }
    }
    
    func getLiturgicalDay(day: Day, policy: DataSourcePolicy, handler: @escaping (LiturgicalDay?, Error?) -> Void) {
        let args = [
            "qt": "pxml",
            "d": day.day.description,
            "m": day.month.description,
            "r": day.year.description,
            "j": self.cgiLanguageCode,
            "k": self.options?.calendar ?? "",
            "o0": valueForOption("o0"),
            "o1": valueForOption("o1"),
            "o3": valueForOption("o3"),
        ]
        
        self.load(args: args, policy: policy, parse: { data -> Result<LiturgicalDay, Error> in
            switch CGIDataSource.parseLiturgicalDays(data) {
            case .success(let days):
                guard let day = days.first else {
                    return .failure(DataSourceError.emptyResponse)
                }
                return .success(day)
            case .failure(let error):
                return .failure(error)
            }
        }, handler: handler)
    }
    
    func getLiturgicalMonth(month: Month, policy: DataSourcePolicy, handler: @escaping (LiturgicalMonth?, Error?) -> Void) {
        let args = [
            "qt": "pxml",
            "d": "*",
            "m": month.month.description,
            "r": month.year.description,
            "j": self.cgiLanguageCode,
            "k": self.options?.calendar ?? "",
            "o0": valueForOption("o0"),
            "o1": valueForOption("o1"),
            "o3": valueForOption("o3"),
        ]

        self.load(args: args, policy: policy, parse: { data -> Result<LiturgicalMonth, Error> in
            return CGIDataSource.parseLiturgicalDays(data).map { days in
                LiturgicalMonth(month: month, days: days)
            }
        }, handler: handler)
    }
    
    let removeFlags = [
        "o0": 256    | // only text for TTS
              1024   | // show navigation lines (on right side)
              524288 | // navigation arrows
              BibleLinkMode.referencesFlag |
              BibleLinkMode.bibleComFlag
    ]
    func valueForOption(_ key: String) -> String {
        var option = UserDefaults.standard.integer(forKey: key);
        if let flags = removeFlags[key] {
            option &= ~flags;
        }
        return String(option);
    }
    
    func getPrayerText(day: LiturgicalDay, celebration: Celebration, prayerType: PrayerType, opts: [String: String], policy: DataSourcePolicy, handler: @escaping (String?, Error?) -> Void) {
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
        for (k, v) in BibleLinkMode.current.cgiOptions {
            args[k] = v
        }
        for (k, v) in opts {
            args[k] = v
        }
        
        self.load(args: args, policy: policy, parse: CGIDataSource.parsePrayerHTML, handler: handler)
    }
    
    func getTTSPrayerText(day: LiturgicalDay, celebration: Celebration, prayerType: PrayerType, opts: [String: String], policy: DataSourcePolicy, handler: @escaping (String?, Error?) -> Void) {
        var ttsOpts = opts
        ttsOpts["of0bf"] = "1"
        ttsOpts["of2rm"] = "0"
        ttsOpts["of0r"] = "0"
        getPrayerText(day: day, celebration: celebration, prayerType: prayerType, opts: ttsOpts, policy: policy, handler: handler)
    }
    
    private static func getHTMLBody(_ html: String) -> String {
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
            return parseExternalLink(url: url)
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

    private func parseExternalLink(url: URL) -> BreviarLink {
        // Relative hrefs (such as Bible references for languages where the CGI has no website
        // configured) resolve against the bundle, so only absolute web links can be opened
        guard let scheme = url.scheme?.lowercased(), scheme == "http" || scheme == "https" else {
            return .unknownLink
        }

        // bible.com links have to leave the app so that iOS can hand them to the Bible app
        if let host = url.host?.lowercased(), host == "bible.com" || host.hasSuffix(".bible.com") {
            return .externalAppLink(url)
        }

        return .webLink(url)
    }
    
    func getSettingsEntries(policy: DataSourcePolicy, handler: @escaping ([SettingsEntry]?, Error?) -> Void) {
        let args = [
            "qt": "pxml",
            "j": self.cgiLanguageCode,
            "k": self.options?.calendar ?? "",
        ]
        
        self.load(args: args, policy: policy, parse: CGIDataSource.parseSettings, handler: handler)
    }
    
    func getAboutPage(handler: @escaping (String?, Error?) -> Void) {
        let args = [
            "qt": "pst",
            "st": "i",
            "p": "0",
            "j": self.cgiLanguageCode,
        ]

        self.loadLocal(args: args, parse: CGIDataSource.parsePrayerHTML) { result in
            switch result {
            case .success(let text):
                handler(text, nil)
            case .failure(let error):
                handler(nil, error)
            }
        }
    }
}
