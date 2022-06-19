//
//  Strings.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 05. 09..
//

import Foundation

struct S {
    // Loading screen
    static let loading = LS(sk: "Načítava", cz: "Načítání", hu: "Betöltés...", la: "Placet expectare...")
    static let retryFromServer = LS(sk: "Skúste to znova zo servera", cz: "Opakujte akci ze serveru", hu: "Újrapróbálás szerverről", la: "Iterum facite")
    static let retryLocally = LS(sk: "Skúste to miestne", cz: "Zkuste to znovu místně", hu: "Újrapróbálás helyben", la: "Quid iterum localiter")
    
    // Prayers
    static let invitatory = LS(sk: "Invitatórium", cz: "Uvedení do první modlitby dne", hu: "Imádságra hívás", la: "Invitatorium")
    static let officeOfReadings = LS(sk: "Posvätné čítanie", cz: "Modlitba se čtením", hu: "Olvasmányos imaóra", la: "Officium lectionis")
    static let morningPrayer = LS(sk: "Ranné chvály", cz: "Ranní chvály", hu: "Reggeli dicséret", la: "Ranní chvály")
    static let midMorningPrayer = LS(sk: "Modlitba predpoludním", cz: "Modlitba dopoledne", hu: "Délelőtt", la: "Tercie")
    static let midDayPrayer = LS(sk: "Modlitba napoludnie", cz: "Modlitba v poledne", hu: "Délben", la: "Sexta")
    static let midAfternoonPrayer = LS(sk: "Modlitba popoludní", cz: "Modlitba odpoledne", hu: "Délután", la: "Nona")
    static let eveningPrayer = LS(sk: "Vešpery", cz: "Nešpory", hu: "Esti dicséret", la: "Vesperæ")
    static let compline = LS(sk: "Kompletórium", cz: "Kompletář", hu: "Befejező imaóra", la: "Completorium")
    
    // Main screen
    static let prayers = LS(sk: "Modlitby", cz: "Modlitby", hu: "Imák", la: "Orationes")
    static let settings = LS(sk: "Nastavenia", cz: "Nastavení", hu: "Beállítások", la: "Instrumenta")
    static let previousDay = LS(sk: "Predchádzajúci deň", cz: "Předchozí den", hu: "Előző nap", la: "Prior dies")
    static let nextDay = LS(sk: "Ďalší deň", cz: "Další den", hu: "Következő nap", la: "Postero die")
    static let today = LS(sk: "Dnes", cz: "Dnes", hu: "Ma", la: "Hodie")
    
    // Date picker
    static let back = LS(sk: "Späť", cz: "Zpátky", hu: "Vissza", la: "Revertere")
    static let previousMonth = LS(sk: "Predchádzajúci mesiac", cz: "Předchozí měsíc", hu: "Előző hónap", la: "Prior mensis")
    static let nextMonth = LS(sk: "Ďalší mesiac", cz: "Příští měsíc", hu: "Következő hónap", la: "Deinde mensis")
    
    // Prayer screen / text options
    static let textOptions = LS(sk: "Možnosti textu", cz: "Možnosti textu", hu: "Szöveg beállításai", la: "Litterae occasus")
    static let font = LS(sk: "Písmo", cz: "Písmo", hu: "Betűtípus", la: "Lypus litterae")
    static let automatic = LS(sk: "Automaticky", cz: "Automatický", hu: "Automatikus", la: "Automaticus")
    static let light = LS(sk: "Svetelný", cz: "Světlý", hu: "Világos", la: "Levis")
    static let dark = LS(sk: "Tmavý", cz: "Tmavý", hu: "Sötét", la: "Obscurus")
    static let startPlayback = LS(sk: "Čítanie textu", cz: "Čtení textu", hu: "Szöveg felolvasása", la: "Legere orandi")
    
    // Settings
    static let generalSettings = LS(sk: "Všeobecné nastavenia", cz: "Obecné nastavení", hu: "Általános beállítások", la: "Genus occasus")
    static let liturgicalTexts = LS(sk: "Liturgické texty", cz: "Liturgické texty", hu: "Liturgikus szövegek", la: "Textus liturgici")
    static let language = LS(sk: "Jazyk", cz: "Jazyk", hu: "Nyelv", la: "Lingua")
    
    // About
    static let aboutBreviary = LS(sk: "O aplikácii Breviára", cz: "O aplikaci Breviáře", hu: "A Zsolozsma alkalmazásról", la: "De breviario")
    static let webURL = LS(sk: "https://breviar.sk", cz: "https://breviar.cz", hu: "https://zsolozsma.katolikus.hu", la: "https://breviar.sk")
    static let appName = LS(sk: "Breviár", cz: "Breviář", hu: "Zsolozsma", la: "Breviarium")
    
    // Setup Wizard
    static let liturgicalCalendar = LS(sk: "Liturgický kalendár", cz: "Liturgický kalendář", hu: "Liturgikus naptár", la: "Calendarium liturgicum pro")
    static let networkSettings = LS(sk: "Nastavenia siete", cz: "Nastavení sítě", hu: "Hálózati beállítások", la: "Nexum occasus")
    static let downloadLatestTexts = LS(sk: "Stiahnite si najnovšie texty", cz: "Stáhněte si nejnovější texty", hu: "Friss szövegek letöltése", la: "Novissima utuntur text")
    static let always = LS(sk: "Vždy", cz: "Vždy", hu: "Mindig", la: "Semper")
    static let onlyOnWifi = LS(sk: "Iba v sieti Wi-Fi", cz: "Pouze v síti Wi-Fi", hu: "Csak Wi-Fi hálózaton", la: "Modo si non pretiosa")
    static let never = LS(sk: "Nikdy", cz: "Nikdy", hu: "Soha", la: "Numquam")
    static let done = LS(sk: "Hotový", cz: "Hotový", hu: "Kész", la: "Completum est")
    
    // Errors
    static let errNetworkError = LS(sk: "Chyba siete", cz: "Chyba sítě", hu: "Hálózati hiba", la: "Responsum non accepit a servo")
    static let errServerError = LS(sk: "Neplatná odpoveď zo servera", cz: "Neplatná odpověď ze serveru", hu: "Hibás szerver válasz", la: "Invalidum responsum ab server")
    static let errParseError = LS(sk: "Chyba při analýze odpovědi serveru", cz: "Chyba pri analýze odpovede servera", hu: "Hiba történt a szerver válaszának feldolgozása során", la: "Potest aliquid server responsionis")
    static let errEmptyResponse = LS(sk: "Prázdna odpoveď servera", cz: "Prázdná odpověď serveru", hu: "Üres szerver válasz", la: "Accepistis inanis responsio")
    static let errInternalError = LS(sk: "Vnútorná chyba", cz: "Interní chyba", hu: "Belső hiba", la: "Sed error occurrit")
}

let LanguageNames: [Language: String] = [
    .czech: "Čeština",
    .hungarian: "Magyar",
    .slovak: "Slovenčina",
    .latin: "Latin",
]

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
    
    // Latin
    "la": "Breviarium latinum",
]
