import Foundation

/// Public CGI URLs are the cross-platform sharing format, not an iOS URL scheme.
struct SharedPrayerLink: Equatable, Identifiable {
    static let host = "breviar.sk"
    static let path = "/cgi-bin/l.cgi"
    static let content0: UInt64 = 1 | 2 | 4 | 8 | 16 | 32 | 512 | 2048 | 4096 | 8192 | 16384 | 32768 | 65536 | 131072
    static let content2: UInt64 = 2 | 64 | 512 | 16384
    static let selection: Set<String> = ["qt", "p", "d", "m", "r", "ds", "lo", "t", "dvt", "lr", "sv", "mr", "rr", "st"]
    private static let forces: Set<String> = [
        "of0v", "of0r", "of0cit", "of0zjvne", "of0nanne", "of0tkne", "of0ff", "of0zft", "of0bc",
        "of0ic", "of0pe", "of0u2rc", "of02rcinv", "of0uac", "of2pv", "of2tw", "of2rm", "of2a"
    ]
    let parameters: [String: String]
    var id: String { url.absoluteString }

    var url: URL {
        var components = URLComponents()
        components.scheme = "https"
        components.host = Self.host
        components.path = Self.path
        components.queryItems = parameters.keys.sorted().map { URLQueryItem(name: $0, value: parameters[$0]) }
        return components.url!
    }

    init?(url: URL) {
        guard let c = URLComponents(url: url, resolvingAgainstBaseURL: false),
              ["https", "http"].contains(c.scheme?.lowercased() ?? ""), c.host?.lowercased() == Self.host,
              c.path == Self.path, c.user == nil, c.password == nil, c.port == nil,
              let query = c.percentEncodedQuery else { return nil }
        self.init(query: query)
    }

    init?(query: String) {
        guard !query.isEmpty, query.utf8.count < 2000,
              let items = URLComponents(string: "https://\(Self.host)\(Self.path)?\(query)")?.queryItems else { return nil }
        var values: [String: String] = [:]
        var seen = Set<String>()
        for item in items {
            guard seen.insert(item.name).inserted else { return nil }
            guard Self.selection.contains(item.name) || Self.isSetting(item.name) else { continue }
            let value = item.value ?? ""
            guard value.range(of: #"\A[a-zA-Z0-9_-]{0,64}\z"#, options: .regularExpression) != nil else { return nil }
            if Self.isWord(item.name) || item.name.hasPrefix("of") {
                guard value.isEmpty || (value.range(of: #"\A[0-9]{1,20}\z"#, options: .regularExpression) != nil && UInt64(value) != nil) else { return nil }
            }
            values[item.name] = value
        }
        guard ["pdnes", "pdt", "plo", "pcr", "psv", "pmr"].contains(values["qt"] ?? "")
                || (values["qt"] == "pst" && values["st"] == "2") else { return nil }
        values["j"] = values["j"] ?? "sk"
        values["k"] = values["k"] ?? ""
        for (key, mask) in [("o0", Self.content0), ("o2", Self.content2)] {
            if let value = values[key] { values[key] = String((UInt64(value) ?? 0) & mask) }
        }
        parameters = values
    }

    private init(validated parameters: [String: String]) { self.parameters = parameters }

    /// Never infer a prayer's date in the client. Older backends simply cannot share it yet.
    static func rendered(in html: String) -> SharedPrayerLink? {
        let tagPattern = #"<span\b[^>]*\sid\s*=\s*["']breviar-request["'][^>]*>"#
        guard let range = html.range(of: tagPattern, options: [.regularExpression, .caseInsensitive]) else { return nil }
        let tag = String(html[range])
        guard let regex = try? NSRegularExpression(pattern: #"\sdata-query\s*=\s*(["'])(.*?)\1"#, options: [.caseInsensitive]),
              let match = regex.firstMatch(in: tag, range: NSRange(tag.startIndex..., in: tag)),
              let value = Range(match.range(at: 2), in: tag) else { return nil }
        let query = String(tag[value]).replacingOccurrences(of: "&quot;", with: "\"")
            .replacingOccurrences(of: "&#39;", with: "'").replacingOccurrences(of: "&apos;", with: "'")
            .replacingOccurrences(of: "&lt;", with: "<").replacingOccurrences(of: "&gt;", with: ">")
            .replacingOccurrences(of: "&amp;", with: "&")
        guard let link = SharedPrayerLink(query: query) else { return nil }
        if link.parameters["qt"] == "pdnes", !(link.parameters["p"] ?? "").isEmpty { return nil }
        if link.parameters["qt"] == "pdt", ["d", "m", "r"].contains(where: { link.parameters[$0]?.isEmpty != false }) { return nil }
        if link.parameters["qt"] == "plo", link.parameters["r"]?.isEmpty != false { return nil }
        // The renderer's effective words supersede any stale per-bit overrides.
        let canonical = link.parameters.filter { key, _ in
            guard key.hasPrefix("of"), key.count >= 3 else { return true }
            let word = "o" + String(key.dropFirst(2).prefix(1))
            return link.parameters[word] == nil
        }
        let result = SharedPrayerLink(validated: canonical)
        return result.url.query!.utf8.count < 2000 ? result : nil
    }

    static func isWord(_ key: String) -> Bool {
        key.range(of: #"\Ao[0-6]\z"#, options: .regularExpression) != nil
    }

    static func isSetting(_ key: String) -> Bool {
        key == "j" || key == "k" || isWord(key) || forces.contains(key)
            || key.range(of: #"\Aof[13456][a-z0-9]*\z"#, options: .regularExpression) != nil
    }

    /// Retain local presentation bits while importing only the sender's content choices.
    func request(local: [String: String]) -> [String: String] {
        var result = local.filter { !Self.selection.contains($0.key) && !$0.key.hasPrefix("of") }
        for (key, value) in parameters {
            if key == "o0" || key == "o2" {
                let mask = key == "o0" ? Self.content0 : Self.content2
                result[key] = String(((UInt64(local[key] ?? "") ?? 0) & ~mask) | ((UInt64(value) ?? 0) & mask))
            } else { result[key] = value }
        }
        return result
    }

    /// Native settings cannot persist an unresolved future force flag safely.
    func settingsToKeep(local: [String: String]) -> [String: String]? {
        guard !parameters.keys.contains(where: { $0.hasPrefix("of") }) else { return nil }
        return request(local: local).filter { Self.isSetting($0.key) }
    }

    /// Generated links may be partial and resolve against the app bundle or its CGI server.
    static func following(_ url: URL, relativeTo current: SharedPrayerLink? = nil, rendererHost: String? = nil) -> SharedPrayerLink? {
        guard let components = URLComponents(url: url, resolvingAgainstBaseURL: false),
              components.user == nil, components.password == nil, components.port == nil else { return nil }
        let local = url.isFileURL && url.lastPathComponent == "l.cgi"
        let web = ["http", "https"].contains(components.scheme?.lowercased() ?? "")
            && [host, "www." + host, rendererHost].compactMap { $0 }.contains(components.host?.lowercased() ?? "")
            && components.path == path
        guard local || web, let items = components.queryItems else { return nil }
        var values = current?.parameters ?? [:]
        // A complete CGI request replaces the selection; only a partial options
        // link inherits it. In particular, an overview must not retain old p/ds.
        if items.contains(where: { $0.name == "qt" }) {
            values = values.filter { !selection.contains($0.key) }
        }
        var seen = Set<String>()
        for item in items {
            guard seen.insert(item.name).inserted else { return nil }
            if isWord(item.name) {
                let prefix = "of" + item.name.dropFirst()
                values = values.filter { !$0.key.hasPrefix(prefix) }
            }
            values[item.name] = item.value ?? ""
        }
        var merged = URLComponents()
        merged.queryItems = values.keys.sorted().map { URLQueryItem(name: $0, value: values[$0]) }
        return merged.percentEncodedQuery.flatMap { SharedPrayerLink(query: $0) }
    }
}
