//
//  Strings.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 05. 09..
//

import Foundation

struct S {
    // Loading screen
    static let loading = LS(en: "Loading...", sk: "Načítavam...", cz: "Načítávání...", hu: "Betöltés...", isl: "Hleð...")
    static let retryFromServer = LS(en: "Retry from server", sk: "Skúsiť znova načítať zo servera", cz: "Opakovat akci ze serveru", hu: "Újrapróbálás szerverről", isl: "Reyna aftur frá netþjóni")
    static let retryLocally = LS(en: "Try offline (locally)", sk: "Skúsiť offline (lokálne)", cz: "Zkusit offline (lokálně)", hu: "Újrapróbálás helyben", isl: "Reyna án nettengingar")
    
    // Prayers
    static let invitatory = LSLiturgical(sk: "Invitatórium", cz: "Uvedení do první modlitby dne", hu: "Imádságra hívás", isl: "Inngöngusöngur", lat: "Invitatorium")
    static let officeOfReadings = LSLiturgical(sk: "Posvätné čítanie", cz: "Modlitba se čtením", hu: "Olvasmányos imaóra", isl: "Óttusöngur hinn fyrri", lat: "Officium lectionis")
    static let morningPrayer = LSLiturgical(sk: "Ranné chvály", cz: "Ranní chvály", hu: "Reggeli dicséret", isl: "Efri óttusöngur", lat: "Laudes matutinæ")
    static let midMorningPrayer = LSLiturgical(sk: "Modlitba predpoludním", cz: "Modlitba dopoledne", hu: "Délelőtt", isl: "Miðdegisbæn fyrir hádegi", lat: "Tertia")
    static let midDayPrayer = LSLiturgical(sk: "Modlitba napoludnie", cz: "Modlitba v poledne", hu: "Délben", isl: "Miðdegisbæn", lat: "Sexta")
    static let midAfternoonPrayer = LSLiturgical(sk: "Modlitba popoludní", cz: "Modlitba odpoledne", hu: "Délután", isl: "Miðdegisbæn eftir hádegi", lat: "Nona")
    static let eveningPrayer = LSLiturgical(sk: "Vešpery", cz: "Nešpory", hu: "Esti dicséret", isl: "Aftansöngur", lat: "Vesperæ")
    static let compline = LSLiturgical(sk: "Kompletórium", cz: "Kompletář", hu: "Befejező imaóra", isl: "Náttsöngur", lat: "Completorium")
    
    // Main screen
    static let prayers = LS(en: "Prayers", sk: "Modlitby", cz: "Modlitby", hu: "Imák", isl: "Bænir")
    static let settings = LS(en: "Settings", sk: "Nastavenia", cz: "Nastavení", hu: "Beállítások", isl: "Stillingar")
    static let previousDay = LS(en: "Previous day", sk: "Predchádzajúci deň", cz: "Předchozí den", hu: "Előző nap", isl: "Fyrri dagur")
    static let nextDay = LS(en: "Next day", sk: "Ďalší deň", cz: "Další den", hu: "Következő nap", isl: "Næsti dagur")
    static let today = LSLiturgical(sk: "Dnes", cz: "Dnes", hu: "Ma", isl: "Í dag", lat: "Hodie")
    
    // Date picker
    static let back = LS(en: "Back", sk: "Späť", cz: "Zpátky", hu: "Vissza", isl: "Til baka")
    static let previousMonth = LS(en: "Previous month", sk: "Predchádzajúci mesiac", cz: "Předchozí měsíc", hu: "Előző hónap", isl: "Fyrri mánuður")
    static let nextMonth = LS(en: "Next month", sk: "Ďalší mesiac", cz: "Příští měsíc", hu: "Következő hónap", isl: "Næsti mánuður")
    
    // Prayer screen / text options
    static let textOptions = LS(en: "Text options", sk: "Možnosti textu", cz: "Možnosti textu", hu: "Szöveg beállításai", isl: "Textastillingar")
    static let font = LS(en: "Font", sk: "Písmo", cz: "Písmo", hu: "Betűtípus", isl: "Leturgerð")
    static let boldFont = LS(en: "Bold font", sk: "Tučné písmo", cz: "Tučné písmo", hu: "Félkövér betűtípus", isl: "Feitletur")
    static let automatic = LS(en: "Automatic", sk: "Automaticky", cz: "Automatický", hu: "Automatikus", isl: "Sjálfvirkt")
    static let light = LS(en: "Light", sk: "Svetlý", cz: "Světlý", hu: "Világos", isl: "Ljóst")
    static let dark = LS(en: "Dark", sk: "Tmavý", cz: "Tmavý", hu: "Sötét", isl: "Dökkt")
    static let startPlayback = LS(en: "Text reading", sk: "Čítanie textu", cz: "Čtení textu", hu: "Szöveg felolvasása", isl: "Lesa upp texta")
    
    // Settings
    static let generalSettings = LS(en: "General settings", sk: "Všeobecné nastavenia", cz: "Obecné nastavení", hu: "Általános beállítások", isl: "Almennar stillingar")
    static let liturgicalTexts = LS(en: "Liturgical texts", sk: "Liturgické texty", cz: "Liturgické texty", hu: "Liturgikus szövegek", isl: "Helgisiðatextar")
    static let language = LS(en: "Language", sk: "Jazyk", cz: "Jazyk", hu: "Nyelv", isl: "Tungumál")
    
    // About
    static let aboutBreviary = LS(en: "About Breviary", sk: "O aplikácii Breviár", cz: "O aplikaci Breviář", hu: "A Zsolozsma alkalmazásról", isl: "Um Tíðabænabók")
    static let webURL = LS(en: "https://breviar.sk", sk: "https://breviar.sk", cz: "https://breviar.cz", hu: "https://zsolozsma.katolikus.hu", isl: "https://breviar.sk")
    static let appName = LSLiturgical(sk: "Breviár", cz: "Breviář", hu: "Zsolozsma", isl: "Tíðabænabók", lat: "Breviarium")
    
    // Setup Wizard
    static let liturgicalCalendar = LS(en: "Liturgical calendar", sk: "Liturgický kalendár", cz: "Liturgický kalendář", hu: "Liturgikus naptár", isl: "Helgisiðadagatal")
    static let networkSettings = LS(en: "Network settings", sk: "Nastavenia siete", cz: "Nastavení sítě", hu: "Hálózati beállítások", isl: "Netstillingar")
    static let downloadLatestTexts = LS(en: "Download latest texts", sk: "Online použitie (texty zo servera)", cz: "Online použití (texty ze serveru)", hu: "Friss szövegek letöltése", isl: "Sækja nýjustu texta")
    static let always = LS(en: "Always", sk: "Vždy", cz: "Vždy", hu: "Mindig", isl: "Alltaf")
    static let onlyOnWifi = LS(en: "Only on Wi-Fi", sk: "Iba v sieti Wi-Fi", cz: "Pouze v síti Wi-Fi", hu: "Csak Wi-Fi hálózaton", isl: "Aðeins á Wi-Fi")
    static let never = LS(en: "Never", sk: "Nikdy", cz: "Nikdy", hu: "Soha", isl: "Aldrei")
    static let done = LS(en: "Done", sk: "Hotovo", cz: "Hotovo", hu: "Kész", isl: "Lokið")
    static let close = LS(en: "Close", sk: "Zavrieť", cz: "Zavřít", hu: "Bezár", isl: "Loka")
    
    // Prayer Screen Settings
    static let prayerScreenSettings = LS(en: "Prayer screen settings", sk: "Nastavenia obrazovky modlitby", cz: "Nastavení obrazovky modlitby", hu: "Ima képernyő beállításai", isl: "Stillingar bænaskjás")
    static let fullscreenMode = LS(en: "Fullscreen mode", sk: "Režim celej obrazovky", cz: "Režim celé obrazovky", hu: "Teljes képernyő", isl: "Allur skjár")
    static let oneTap = LS(en: "1 tap", sk: "1 klik", cz: "1 klik", hu: "1 klikk", isl: "1 snerting")
    static let doubleTap = LS(en: "Double tap", sk: "Dvojklik", cz: "Dvojklik", hu: "Dupla klikk", isl: "Tvísnerting")
    static let disabled = LS(en: "Disabled", sk: "Vypnuté", cz: "Vypnuto", hu: "Kikapcsolva", isl: "Slökkt")
    
    // Errors
    static let errNetworkError = LS(en: "Network error", sk: "Chyba siete", cz: "Chyba sítě", hu: "Hálózati hiba", isl: "Netvilla")
    static let errServerError = LS(en: "Invalid server response", sk: "Neplatná odpoveď zo servera", cz: "Neplatná odpověď ze serveru", hu: "Hibás szerver válasz", isl: "Ógilt svar frá þjóni")
    static let errParseError = LS(en: "Error parsing server response", sk: "Chyba pri analýze odpovede servera", cz: "Chyba při analýze odpovědi serveru", hu: "Hiba történt a szerver válaszának feldolgozása során", isl: "Villa við að greina svar þjóns")
    static let errEmptyResponse = LS(en: "Empty server response", sk: "Prázdna odpoveď servera", cz: "Prázdná odpověď serveru", hu: "Üres szerver válasz", isl: "Tómt svar frá þjóni")
    static let errInternalError = LS(en: "Internal error", sk: "Vnútorná chyba", cz: "Interní chyba", hu: "Belső hiba", isl: "Innri villa")
    
    // Migration banner
    static let migrationTitle = LS(en: "Final Update", sk: "Posledná aktualizácia", cz: "Poslední aktualizace", hu: "Utolsó frissítés", isl: "Síðasta uppfærsla")
    static let migrationMessage = LS(en: "This is the final update for this application. Please switch to the new, multi-language app.", sk: "Toto je posledná aktualizácia tejto aplikácie. Prosím, prejdite na novú, viacjazyčnú aplikáciu.", cz: "Toto je poslední aktualizace této aplikace. Prosím, přejděte na novou, vícejazyčnou aplikaci.", hu: "Ez az alkalmazás utolsó frissítése. Kérjük, váltson át az új, többnyelvű alkalmazásra.", isl: "Þetta er síðasta uppfærsla fyrir þetta forrit. Vinsamlegast skiptu yfir í nýja, fjöltyngda appið.")
    static let migrationDownloadButton = LS(en: "Download New App", sk: "Stiahnuť novú aplikáciu", cz: "Stáhnout novou aplikaci", hu: "Új alkalmazás letöltése", isl: "Sækja nýja appið")
}

let LanguageNames: [Language: String] = [
    .czech: "Čeština",
    .english: "English",
    .hungarian: "Magyar",
    .icelandic: "Íslenska",
    .latin: "Latina",
    .slovak: "Slovenčina",
]

// Language name "Latin" in each UI language
let LatinLanguageName = LS(en: "Latin", sk: "Latinčina", cz: "Latina", hu: "Latin", isl: "Latína")

let CalendarNames: [String: String] = [
    // Czech
    "cz": "obecný [pro Čechy a Moravu]",
    "czop": "dominikánský (OP)",
    "opraem": "s vlastními texty premonstrátského řádu (OPraem)",
    "ofmcap": "s vlastními kapucínskými texty (OFMCap.)",
    "czsdb": "s vlastními texty pro salesiánskou rodinu",
    "czofm": "s vlastními františkánskými texty (OFM)",
    "czsj": "s vlastními texty jezuitského řádu (SJ)",
    "czocd": "s vlastními texty bosých karmelitánů (OCD)",
    "czofmconv": "s vlastními minoritskými texty (OFMConv.)",

    // Hungarian
    "hu": "általános [Magyarország]",
    "huofm": "ferences szentek és ünnepek zsolozsmája",
    "husvd": "verbiták zsolozsmája",
    "husj": "jezsuiták zsolozsmája (SJ)",

    // Slovak
    "sk": "všeobecný [pre Slovensko]",
    "cssr": "pre Kongregáciu najsv. Vykupiteľa — redemptoristov (CSsR)",
    "svd": "pre Spoločnosť Božieho Slova — verbistov (SVD)",
    "ofm": "pre františkánsku rodinu",
    "sdb": "pre saleziánsku rodinu — SDB, FMA, VDB",
    "op": "pre Rehoľu kazateľov — dominikánov (OP)",
    "sj": "pre Spoločnosť Ježišovu — jezuitov (SJ)",
    "cm": "pre Misijnú spoločnosť sv. Vincenta de Paul — lazaristov (CM)",
    "ocd": "pre bosých karmelitánov (OCD)",
    "csa": "pre kanonisky sv. Augustína Notre Dame (CSA)",
    "osu": "pre uršulínky Rímskej únie (OSU)",
    "skopraem": "pre premonštrátov (OPraem)",
    
    // Icelandic
    "is": "almennur",
    
    // Latin
    "la": "universalis",
]
