import Foundation

var checks = 0
func expect(_ condition: @autoclosure () -> Bool, _ message: String) {
    checks += 1
    guard condition() else { fatalError(message) }
}
let prefix = "https://breviar.sk/cgi-bin/l.cgi?"
let fixed = SharedPrayerLink(url: URL(string: prefix + "qt=pdt&d=13&m=11&r=2026&p=mrch&j=hu&k=husdb&o0=18446744073709551615&o2=18446744073709551615&f=PrivateFont&c1=123456")!)!
expect(fixed.parameters["f"] == nil && fixed.parameters["c1"] == nil, "Presentation must not travel")
expect(fixed.parameters["o0"] == String(SharedPrayerLink.content0), "Mask word 0")
expect(fixed.parameters["o2"] == String(SharedPrayerLink.content2), "Mask word 2")
expect(SharedPrayerLink(url: fixed.url) == fixed, "Public URL round trip")
for query in ["qt=pdnes", "qt=plo&lo=3&t=1&dvt=2&r=2026&p=mv", "qt=pst&st=2&p=mna"] {
    expect(SharedPrayerLink(query: query) != nil, "Supported reader query")
}
for invalid in [
    "https://evil.test/cgi-bin/l.cgi?qt=pdnes", "https://breviar.sk.evil.test/cgi-bin/l.cgi?qt=pdnes",
    "https://breviar.sk@evil.test/cgi-bin/l.cgi?qt=pdnes", "https://user@breviar.sk/cgi-bin/l.cgi?qt=pdnes",
    "https://breviar.sk:443/cgi-bin/l.cgi?qt=pdnes", "https://breviar.sk/docs/page.htm?qt=pdnes",
    "file:///cgi-bin/l.cgi?qt=pdnes", "javascript:alert(1)", prefix + "qt=pxml", prefix + "qt=pst&st=i",
    prefix + "qt=pdnes&qt=pdt", prefix + "qt=pdnes&j=sk%0A", prefix + "qt=pdnes&j=%22%3E", prefix + "qt=pdnes&o1=-1",
    prefix + "qt=pdnes&o6=18446744073709551616", prefix + "qt=pdnes&of1rub=notanumber",
    prefix + "qt=pdnes&unknown=a&unknown=b", prefix + "qt=pdnes&long=" + String(repeating: "a", count: 2000)
] {
    expect(SharedPrayerLink(url: URL(string: invalid)!) == nil, "Reject \(invalid)")
}
let plain = SharedPrayerLink(query: "qt=pdt&d=13&m=11&r=2026&p=mrch&j=sk")!
expect(plain.parameters["k"] == "", "Default calendar must be explicit")
let merged = fixed.request(local: ["f": "Local", "o0": "64", "o2": "256", "of0r": "0", "qt": "pdnes", "p": "mk"])
expect(merged["f"] == "Local", "Keep receiver font")
expect(merged["p"] == "mrch", "Imported selection wins")
expect(merged["o0"] == String(SharedPrayerLink.content0 | 64), "Retain noncontent bits in word 0")
expect(merged["o2"] == String(SharedPrayerLink.content2 | 256), "Retain night mode")
expect(merged["of0r"] == nil, "Remove stale local force flags")
let marked = "<span id=\"breviar-request\" hidden data-query=\"qt=pdt&amp;d=13&amp;m=11&amp;r=2026&amp;p=mrch&amp;o0=3&amp;j=sk\"></span>"
expect(SharedPrayerLink.rendered(in: marked)?.parameters["d"] == "13", "Use backend date")
expect(SharedPrayerLink.rendered(in: "<p>Old backend</p>") == nil, "Do not guess absent metadata")
expect(SharedPrayerLink.rendered(in: "<span id='breviar-request' data-query='qt=pdnes&amp;p=mv'></span>") == nil, "Do not share unresolved relative prayer")
expect(SharedPrayerLink.rendered(in: "<span hidden data-query='qt=pdnes&amp;j=sk' id='breviar-request'></span>") != nil, "Attribute order is immaterial")
expect(SharedPrayerLink.rendered(in: "<span id='breviar-request' data-query='qt=pdt&amp;p=mv'></span>") == nil, "Do not share unpinned date")
expect(SharedPrayerLink.following(URL(string: "file:///bundle/l.cgi?qt=pdt&d=13&m=11&r=2026&p=mk")!) != nil, "Local prayer navigation")
expect(SharedPrayerLink.following(URL(string: "https://evil.test/l.cgi?qt=pdnes")!) == nil, "No external CGI navigation")
let suite = "PrayerSharingTests-" + UUID().uuidString
let defaults = UserDefaults(suiteName: suite)!
defer { defaults.removePersistentDomain(forName: suite) }
defaults.set("PersonalFont", forKey: "textOptions.fontName")
defaults.set("sk", forKey: "j")
defaults.set(42, forKey: "o1")
let session = SharedPrayerSession(defaults: defaults)
session.open(fixed)
expect(SharedPrayerSession(defaults: defaults).link == fixed, "Temporary link survives session recreation")
session.open(plain)
expect(session.link == plain, "Subsequent link replaces only temporary query")
session.finish()
expect(session.link == nil, "Restore/Keep ends temporary state")
expect(defaults.string(forKey: "j") == "sk" && defaults.integer(forKey: "o1") == 42, "Restore never overwrites personal prayer settings")
expect(defaults.string(forKey: "textOptions.fontName") == "PersonalFont", "Local appearance survives")
let adopted = fixed.settingsToKeep(local: ["o0": "64", "o2": "256", "textOptions.fontName": "Personal", "ds": "alwaysNetwork", "ui_lang": "en"])!
expect(adopted["o0"] == String(SharedPrayerLink.content0 | 64), "Keep preserves local word-0 presentation")
expect(adopted["o2"] == String(SharedPrayerLink.content2 | 256), "Keep preserves local word-2 presentation")
expect(adopted["ds"] == nil, "CGI celebration ds must not overwrite iOS network policy ds")
expect(adopted["ui_lang"] == nil && adopted["textOptions.fontName"] == nil, "Keep does not import or rewrite UI/appearance preferences")
expect(SharedPrayerLink(query: "qt=pdnes&of5foo=1")!.settingsToKeep(local: [:]) == nil, "Do not permanently guess future force flags")
let canonical = SharedPrayerLink.rendered(in: "<span id='breviar-request' data-query='qt=pdnes&amp;o0=3&amp;of0v=0'></span>")!
expect(canonical.parameters["of0v"] == nil && canonical.parameters["o0"] == "3", "Resolved words win over stale overrides when sharing")
expect(SharedPrayerLink.rendered(in: "<span id='breviar-request' data-query='qt=plo&amp;lo=3&amp;p=mv'></span>") == nil, "Seasonal links require the backend reference year")
expect(SharedPrayerLink.rendered(in: "<span data-id='breviar-request' data-query='qt=pdnes'></span>") == nil, "Read the actual metadata ID, not a lookalike attribute")
let followed = SharedPrayerLink.following(URL(string: "file:///bundle/l.cgi?o1=123")!, relativeTo: plain)!
expect(followed.parameters["d"] == "13" && followed.parameters["p"] == "mrch" && followed.parameters["o1"] == "123", "Partial inline options retain selection")
expect(SharedPrayerLink.following(URL(string: "https://lh.kbs.sk/cgi-bin/l.cgi?qt=pdnes")!, rendererHost: "lh.kbs.sk") != nil, "Recognize the configured CGI renderer internally")
expect(SharedPrayerLink(url: URL(string: "https://lh.kbs.sk/cgi-bin/l.cgi?qt=pdnes")!) == nil, "Universal links stay restricted to breviar.sk")
expect(SharedPrayerLink.following(URL(string: "https://evil.test/cgi-bin/l.cgi?o1=123")!, relativeTo: plain, rendererHost: "lh.kbs.sk") == nil, "Untrusted CGI hosts cannot change shared content")
expect(SharedPrayerLink.following(URL(string: "file:///bundle/l.cgi?o1=1&o1=2")!, relativeTo: plain) == nil, "Reject duplicate inline options")
let highWord = SharedPrayerLink(query: "qt=pdnes&o6=18446744073709551615")!
expect(highWord.parameters["o6"] == String(UInt64.max), "Full-width content words round-trip")
defaults.set(NSNumber(value: UInt64.max), forKey: "o6")
expect((defaults.object(forKey: "o6") as? NSNumber)?.uint64Value == UInt64.max, "Native adoption preserves UInt64 in UserDefaults")
expect(NSNumber(value: Int64.min).uint64Value == UInt64(1) << 63, "Existing signed UI words retain their high bit")
let overview = SharedPrayerLink.following(URL(string: "file:///bundle/l.cgi?qt=pdnes")!, relativeTo: fixed)!
expect(overview.parameters["p"] == nil && overview.parameters["d"] == nil, "A complete request replaces the previous prayer selection")
expect(overview.parameters["j"] == "hu" && overview.parameters["k"] == "husdb", "Complete navigation still retains content settings")
print("Passed \(checks) total prayer-sharing checks")
