//
//  Strings.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 05. 09..
//

import Foundation

struct S {
    // Common strings
    static let loading = LS(sk: "", cz: "", hu: "Betöltés...")
    
    // Prayers
    static let invitatory = LS(sk: "Invitatórium", cz: "Uvedení do první modlitby dne", hu: "Imádságra hívás")
    static let officeOfReadings = LS(sk: "Posvätné čítanie", cz: "Modlitba se čtením", hu: "Olvasmányos imaóra")
    static let morningPrayer = LS(sk: "Ranné chvály", cz: "Ranní chvály", hu: "Reggeli dicséret")
    static let midMorningPrayer = LS(sk: "Modlitba predpoludním", cz: "Modlitba dopoledne", hu: "Délelőtt")
    static let midDayPrayer = LS(sk: "Modlitba napoludnie", cz: "Modlitba v poledne", hu: "Délben")
    static let midAfternoonPrayer = LS(sk: "Modlitba popoludní", cz: "Modlitba odpoledne", hu: "Délután")
    static let eveningPrayer = LS(sk: "Vešpery", cz: "Nešpory", hu: "Esti dicséret")
    static let compline = LS(sk: "Kompletórium", cz: "Kompletář", hu: "Befejező imaóra")
    
    // Main screen
    static let prayers = LS(sk: "Modlitby", cz: "Modlitby", hu: "Imák")
    static let settings = LS(sk: "Nastavenia", cz: "Nastavení", hu: "Beállítások")
    static let previousDay = LS(sk: "Predchádzajúci deň", cz: "Předchozí den", hu: "Előző nap")
    static let nextDay = LS(sk: "Ďalší deň", cz: "Další den", hu: "Következő nap")
    static let today = LS(sk: "Dnes", cz: "Dnes", hu: "Ma")
    
    // Date picker
    static let back = LS(sk: "Späť", cz: "Zpátky", hu: "Vissza")
    static let previousMonth = LS(sk: "Predchádzajúci mesiac", cz: "Předchozí měsíc", hu: "Előző hónap")
    static let nextMonth = LS(sk: "Ďalší mesiac", cz: "Příští měsíc", hu: "Következő hónap")
    
    // Prayer screen / text options
    static let textOptions = LS(sk: "Možnosti textu", cz: "Možnosti textu", hu: "Szöveg beállításai")
    static let font = LS(sk: "Písmo", cz: "Písmo", hu: "Betűtípus")
    static let automatic = LS(sk: "Automaticky", cz: "Automatický", hu: "Automatikus")
    static let light = LS(sk: "Svetelný", cz: "Světlý", hu: "Világos")
    static let dark = LS(sk: "Tmavý", cz: "Tmavý", hu: "Sötét")
    
    // Settings
    static let generalSettings = LS(sk: "Všeobecné nastavenia", cz: "Obecné nastavení", hu: "Általános beállítások")
    static let liturgicalTexts = LS(sk: "Liturgické texty", cz: "Liturgické texty", hu: "Liturgikus szövegek")
    static let language = LS(sk: "Jazyk", cz: "Jazyk", hu: "Nyelv")
    
    // Setup Wizard
    static let liturgicalCalendar = LS(sk: "Liturgický kalendár", cz: "Liturgický kalendář", hu: "Liturgikus naptár")
    static let networkSettings = LS(sk: "Nastavenia siete", cz: "Nastavení sítě", hu: "Hálózati beállítások")
    static let downloadLatestTexts = LS(sk: "Stiahnite si najnovšie texty", cz: "Stáhněte si nejnovější texty", hu: "Friss szövegek letöltése")
    static let always = LS(sk: "Vždy", cz: "Vždy", hu: "Mindig")
    static let onlyOnWifi = LS(sk: "Iba v sieti Wi-Fi", cz: "Pouze v síti Wi-Fi", hu: "Csak Wi-Fi hálózaton")
    static let never = LS(sk: "Nikdy", cz: "Nikdy", hu: "Soha")
    static let done = LS(sk: "Hotový", cz: "Hotový", hu: "Kész")
    
    // Errors
    static let errParseError = LS(sk: "Chyba při analýze odpovědi serveru", cz: "Chyba pri analýze odpovede servera", hu: "Hiba történt a szerver válaszának feldolgozása során")
    static let errEmptyResponse = LS(sk: "Prázdna odpoveď servera", cz: "Prázdná odpověď serveru", hu: "Üres szerver válasz")
}

let LanguageNames: [Language: String] = [
    .czech: "Čeština",
    .hungarian: "Magyar",
    .slovak: "Slovenčina",
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
]
