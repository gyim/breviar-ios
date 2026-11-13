import Foundation

var checks = 0
func expect(_ condition: @autoclosure () -> Bool, _ message: String) {
    checks += 1
    guard condition() else { fatalError(message) }
}
let prefix = "https://breviar.sk/cgi-bin/l.cgi?"
let fixed = SharedPrayerLink(url: URL(string: prefix + "qt=pdt&d=13&m=11&r=2026&p=mrch&j=hu&k=husdb&o0=18446744073709551615&o2=18446744073709551615&f=PrivateFont&c1=123456")!)!
expect(fixed.parameters["f"] == nil && fixed.parameters["c1"] == nil, "Content-only recipients ignore presentation")
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
    prefix + "qt=pdnes&long=" + String(repeating: "a", count: 2000)
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
// Appearance travels in generated links, independently of the recipient's policy.
let fullQuery = "qt=pdt&d=13&m=11&r=2026&p=mv&j=sk&o0=65&o2=256&f=Noto%20Serif&ff=18&s=1&c=1&ct0=111111&cr0=abc&c0=ffffff&ct1=eeeeee&cr1=ffffcc&c1=000000&mm=15&lh=140&v=1"
let full = SharedPrayerLink(query: fullQuery, appearance: true)!
expect(full.parameters["o0"] == "65" && full.parameters["o2"] == "256", "Full imports retain visual bits")
expect(full.parameters["f"] == "Noto Serif", "Font names decode spaces")
expect(SharedPrayerLink(url: full.url, appearance: true) == full, "Full URL round trip")
let withoutAppearance = SharedPrayerLink(query: fullQuery)!
for key in SharedPrayerLink.appearanceKeys {
    expect(withoutAppearance.parameters[key] == nil, "Content-only import omits \(key)")
}
expect(withoutAppearance.parameters["o0"] == "1" && withoutAppearance.parameters["o2"] == "0", "Only content bits enter content-only imports")
let renderedFull = SharedPrayerLink.rendered(in: "<span id='breviar-request' data-query='" + fullQuery.replacingOccurrences(of: "&", with: "&amp;") + "&amp;dl=hu&amp;appPlatform=android'></span>")!
expect(renderedFull == full, "Outgoing metadata retains full appearance and excludes app/device parameters")
expect(SharedPrayerLink(query: "qt=pdnes&unknown=a&unknown=b") != nil, "Unused duplicate values do not reject a link")
for ignored in ["f=%3Cinvalid%3E", "ct1=bad-color", "of0fn=notanumber", "ff=999999999", "c=2", "v=other", "f=One&f=Two"] {
    expect(SharedPrayerLink(query: "qt=pdnes&" + ignored) != nil, "Unused appearance is filtered before validation")
    expect(SharedPrayerLink(query: "qt=pdnes&" + ignored, appearance: true) == nil, "Accepted appearance must be valid: \(ignored)")
}
let localDisplay = ["o0": "1088", "o2": "288", "f": "Georgia", "ff": "20", "c": "0", "cr1": "aabbcc", "lh": "150"]
let contentDisplay = full.request(local: localDisplay)
expect(contentDisplay["f"] == "Georgia" && contentDisplay["cr1"] == "aabbcc", "Filtering also applies when merging a full outgoing link")
expect(contentDisplay["o0"] == "1089" && contentDisplay["o2"] == "288", "Preserve recipient layout/bold/night bits")
let allDisplay = full.request(local: localDisplay, appearance: true)
expect(allDisplay["o0"] == "65" && allDisplay["o2"] == "256" && allDisplay["f"] == "Noto Serif", "Accepted settings replace whole words and font")
expect(allDisplay["cr1"] == "ffffcc" && allDisplay["lh"] == "140", "Accept palette and spacing")
let partialDisplay = SharedPrayerLink(query: "qt=pdnes&c=1", appearance: true)!.request(local: localDisplay, appearance: true)
expect(partialDisplay["ff"] == "20" && partialDisplay["f"] == "Georgia", "Absent settings retain current values")
let visualForce = SharedPrayerLink(query: "qt=pdnes&of0fn=1&of2nr=1", appearance: true)!
expect(ReaderAppearance.normalFont(in: visualForce.parameters) == true && ReaderAppearance.nightMode(in: visualForce.parameters) == true, "Force flags also control native appearance")
expect(ReaderAppearance.nightMode(in: ["c": "0", "o2": "256"]) == false, "Explicit theme takes priority over legacy night bit")
let nativeDisplay = ReaderAppearance.options(local: full.parameters, extra: ["cr1": "abc"], font: "Baskerville", scale: 125, bold: true, dark: false)
expect(nativeDisplay["f"] == "Baskerville" && nativeDisplay["ff"] == "20" && nativeDisplay["c"] == "0", "Outgoing links reflect native font, scale and actual appearance")
expect(nativeDisplay["o0"] == "1" && nativeDisplay["cr1"] == "abc", "Native bold overrides only its own bit; colors remain portable")
expect(nativeDisplay["d"] == "13" && nativeDisplay["p"] == "mv", "Native appearance never changes selection")
expect(ReaderAppearance.scale(in: ["ff": "18"]) == 112.5, "CGI points map to native scaling")
expect(ReaderAppearance.scale(in: ["s": "7"]) == 112.5, "CGI named sizes map to native scaling")
expect(ReaderAppearance.scale(in: [:]) == nil, "Missing size does not reset native settings")
let css = ReaderAppearance.css(full.parameters)
expect(css.contains("--prayer-rubric: #abc;") && css.contains("--prayer-rubric: #ffffcc;"), "Render both custom palettes")
expect(css.contains("prefers-color-scheme: dark") && css.contains("margin-left: 15px") && css.contains("line-height: 140%"), "Palettes follow native scheme; spacing is applied")
expect(ReaderAppearance.css(["cr0": "bad-color"]).contains("--prayer-rubric: initial;"), "Only validated colors become CSS")
let missingFont = full.resolvingFont { _ in nil }.resolving(local: localDisplay, appearance: true)
expect(missingFont.parameters["f"] == "Georgia", "Unavailable fonts retain the current font")
let knownFont = full.resolvingFont { $0 == "Noto Serif" ? "NotoSerif-Regular" : nil }
expect(knownFont.parameters["f"] == "NotoSerif-Regular", "Font resolution only substitutes an installed family")
let keptDisplay = full.settingsToKeep(local: localDisplay, appearance: true)!
expect(keptDisplay["o0"] == "65" && keptDisplay["cr1"] == "ffffcc", "Keep adopts accepted appearance")
let followedFull = SharedPrayerLink.following(URL(string: "file:///bundle/l.cgi?o1=9")!, relativeTo: full)!
expect(followedFull.parameters["f"] == "Noto Serif" && followedFull.parameters["cr1"] == "ffffcc", "Inline navigation retains accepted appearance")
let exactWord = SharedPrayerLink(query: "qt=pdnes&o0=18446744073709551615&o2=18446744073709551615", appearance: true)!
expect(exactWord.parameters["o0"] == String(UInt64.max) && exactWord.parameters["o2"] == String(UInt64.max), "Full visual words preserve all 64 bits")

// The durable session records the first appearance snapshot and the scope, not the live toggle.
expect(!defaults.bool(forKey: SharedPrayerSession.appearancePreference), "Appearance import defaults off")
defaults.set(125.0, forKey: "textOptions.fontSize")
defaults.set(true, forKey: "textOptions.isBold")
defaults.set("automatic", forKey: "colorScheme")
defaults.set(["cr0": "900000"], forKey: ReaderAppearance.storageKey)
let acceptedContent = session.open(withoutAppearance, local: localDisplay)
expect(acceptedContent.parameters["f"] == "Georgia" && !session.importsAppearance, "Initial content-only session retains recipient appearance")
defaults.set("LocalEdit", forKey: "textOptions.fontName")
let acceptedAll = session.open(full, local: acceptedContent.parameters, appearance: true)
expect(acceptedAll.parameters["f"] == "Noto Serif" && session.importsAppearance, "Subsequent full import widens the restore scope")
defaults.set("NotoSerif-Regular", forKey: "textOptions.fontName")
defaults.set(112.5, forKey: "textOptions.fontSize")
defaults.set(false, forKey: "textOptions.isBold")
defaults.set("dark", forKey: "colorScheme")
defaults.set(["cr1": "ffffcc"], forKey: ReaderAppearance.storageKey)
defaults.set(false, forKey: SharedPrayerSession.appearancePreference)
let recreated = SharedPrayerSession(defaults: defaults)
expect(recreated.link == acceptedAll && recreated.importsAppearance, "Restart preserves accepted query and restore scope")
let acceptedLater = recreated.open(plain, local: acceptedAll.parameters)
expect(acceptedLater.parameters["cr1"] == "ffffcc" && recreated.importsAppearance, "Later content-only link keeps current appearance and original scope")
recreated.update(followedFull)
expect(SharedPrayerSession(defaults: defaults).link == followedFull, "Renderer/inline updates never recapture the backup")
defaults.set("alwaysNetwork", forKey: "ds")
defaults.set("en", forKey: "ui_lang")
defaults.set("doubleTap", forKey: "prayerScreenSettings.fullscreenMode")
recreated.restore()
expect(defaults.string(forKey: "textOptions.fontName") == "PersonalFont", "Restore returns to the first font, before any intermediate edits")
expect(defaults.double(forKey: "textOptions.fontSize") == 125 && defaults.bool(forKey: "textOptions.isBold"), "Restore size and bold")
expect(defaults.string(forKey: "colorScheme") == "automatic", "Restore automatic theme, not a frozen day/night value")
expect(defaults.dictionary(forKey: ReaderAppearance.storageKey) as? [String: String] == ["cr0": "900000"], "Restore palette/spacing snapshot")
expect(defaults.string(forKey: "ds") == "alwaysNetwork" && defaults.string(forKey: "ui_lang") == "en", "Network policy and UI language always remain local")
expect(defaults.string(forKey: "prayerScreenSettings.fullscreenMode") == "doubleTap" && !defaults.bool(forKey: SharedPrayerSession.appearancePreference), "Restore never rewrites native device/import preferences")
expect(session.link == nil && !session.importsAppearance, "Restore ends the session")
session.open(plain, local: localDisplay)
defaults.set("LocalEdit", forKey: "textOptions.fontName")
SharedPrayerSession(defaults: defaults).restore()
expect(defaults.string(forKey: "textOptions.fontName") == "LocalEdit", "Content-only Restore preserves appearance edits")
session.open(full, local: localDisplay, appearance: true)
defaults.set("KeptFont", forKey: "textOptions.fontName")
session.finish()
expect(session.link == nil && defaults.string(forKey: "textOptions.fontName") == "KeptFont", "Keep leaves accepted appearance and clears the backup")
for key in ReaderAppearance.preferenceKeys { defaults.removeObject(forKey: key) }
session.open(full, appearance: true)
defaults.set("Temporary", forKey: "textOptions.fontName")
session.restore()
expect(defaults.object(forKey: "textOptions.fontName") == nil, "Restore removes values that were originally absent")
print("Passed \(checks) total prayer-sharing checks")
