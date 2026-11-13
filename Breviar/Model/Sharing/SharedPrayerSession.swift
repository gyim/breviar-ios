import Foundation

/// Keep the accepted request and its restore scope independent of the current import preference.
final class SharedPrayerSession {
    static let willOpen = Notification.Name("SharedPrayerWillOpen")
    static let appearancePreference = "sharedPrayer.acceptAppearance"
    private static let key = "sharedPrayer.session"
    private let defaults: UserDefaults
    init(defaults: UserDefaults = .standard) { self.defaults = defaults }

    private var state: [String: Any] { defaults.dictionary(forKey: Self.key) ?? [:] }

    var link: SharedPrayerLink? {
        guard let query = state["query"] as? String else { return nil }
        // This request has already been filtered and merged with local settings.
        return SharedPrayerLink(query: query, appearance: true)
    }

    var importsAppearance: Bool { state["appearance"] as? Bool ?? false }

    @discardableResult
    func open(_ link: SharedPrayerLink, local: [String: String] = [:], appearance: Bool = false) -> SharedPrayerLink {
        var saved = state
        if saved.isEmpty {
            saved["originalAppearance"] = ReaderAppearance.preferenceKeys.reduce(into: [String: Any]()) { result, key in
                result[key] = defaults.object(forKey: key)
            }
        }
        let accepted = link.resolving(local: local, appearance: appearance)
        saved["query"] = accepted.url.query
        saved["appearance"] = importsAppearance || (appearance && link.parameters.keys.contains {
            SharedPrayerLink.appearanceKeys.contains($0) || $0 == "o0" || $0 == "o2"
                || (SharedPrayerLink.isSetting($0) && !SharedPrayerLink.isContentSetting($0))
        })
        defaults.set(saved, forKey: Self.key)
        return accepted
    }

    func update(_ link: SharedPrayerLink) {
        var saved = state
        guard !saved.isEmpty else { return }
        saved["query"] = link.url.query
        defaults.set(saved, forKey: Self.key)
    }

    /// Content-only Restore preserves local appearance edits. Any appearance import restores the first snapshot.
    func restore() {
        if importsAppearance, let original = state["originalAppearance"] as? [String: Any] {
            for key in ReaderAppearance.preferenceKeys {
                if let value = original[key] { defaults.set(value, forKey: key) }
                else { defaults.removeObject(forKey: key) }
            }
        }
        finish()
    }

    func finish() { defaults.removeObject(forKey: Self.key) }
}
