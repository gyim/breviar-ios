import Foundation

/// Personal settings are untouched until Keep. Persist only the temporary reader's query.
final class SharedPrayerSession {
    static let willOpen = Notification.Name("SharedPrayerWillOpen")
    private static let key = "sharedPrayer.query"
    private let defaults: UserDefaults
    init(defaults: UserDefaults = .standard) { self.defaults = defaults }

    var link: SharedPrayerLink? {
        guard let query = defaults.string(forKey: Self.key) else { return nil }
        return SharedPrayerLink(query: query)
    }

    func open(_ link: SharedPrayerLink) { defaults.set(link.url.query, forKey: Self.key) }
    func finish() { defaults.removeObject(forKey: Self.key) }
}
