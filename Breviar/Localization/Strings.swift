//
//  Strings.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 05. 09..
//

import Foundation

struct S {
    // Loading screen
    static let loading = LS(sk: "Načítavam...", cz: "Načítávání...", hu: "Betöltés...", isl: "Hleð...")
    static let retryFromServer = LS(sk: "Skúsiť znova načítať zo servera", cz: "Opakovat akci ze serveru", hu: "Újrapróbálás szerverről", isl: "Reyna aftur frá netþjóni")
    static let retryLocally = LS(sk: "Skúsiť offline (lokálne)", cz: "Zkusit offline (lokálně)", hu: "Újrapróbálás helyben", isl: "Reyna án nettengingar")
    
    // Prayers
    static let invitatory = LS(sk: "Invitatórium", cz: "Uvedení do první modlitby dne", hu: "Imádságra hívás", isl: "Inngöngusöngur")
    static let officeOfReadings = LS(sk: "Posvätné čítanie", cz: "Modlitba se čtením", hu: "Olvasmányos imaóra", isl: "Óttusöngur hinn fyrri")
    static let morningPrayer = LS(sk: "Ranné chvály", cz: "Ranní chvály", hu: "Reggeli dicséret", isl: "Efri óttusöngur")
    static let midMorningPrayer = LS(sk: "Modlitba predpoludním", cz: "Modlitba dopoledne", hu: "Délelőtt", isl: "Miðdegisbæn fyrir hádegi")
    static let midDayPrayer = LS(sk: "Modlitba napoludnie", cz: "Modlitba v poledne", hu: "Délben", isl: "Miðdegisbæn")
    static let midAfternoonPrayer = LS(sk: "Modlitba popoludní", cz: "Modlitba odpoledne", hu: "Délután", isl: "Miðdegisbæn eftir hádegi")
    static let eveningPrayer = LS(sk: "Vešpery", cz: "Nešpory", hu: "Esti dicséret", isl: "Aftansöngur")
    static let compline = LS(sk: "Kompletórium", cz: "Kompletář", hu: "Befejező imaóra", isl: "Náttsöngur")
    
    // Main screen
    static let prayers = LS(sk: "Modlitby", cz: "Modlitby", hu: "Imák", isl: "Bænir")
    static let settings = LS(sk: "Nastavenia", cz: "Nastavení", hu: "Beállítások", isl: "Stillingar")
    static let previousDay = LS(sk: "Predchádzajúci deň", cz: "Předchozí den", hu: "Előző nap", isl: "Fyrri dagur")
    static let nextDay = LS(sk: "Ďalší deň", cz: "Další den", hu: "Következő nap", isl: "Næsti dagur")
    static let today = LS(sk: "Dnes", cz: "Dnes", hu: "Ma", isl: "Í dag")
    
    // Date picker
    static let back = LS(sk: "Späť", cz: "Zpátky", hu: "Vissza", isl: "Til baka")
    static let previousMonth = LS(sk: "Predchádzajúci mesiac", cz: "Předchozí měsíc", hu: "Előző hónap", isl: "Fyrri mánuður")
    static let nextMonth = LS(sk: "Ďalší mesiac", cz: "Příští měsíc", hu: "Következő hónap", isl: "Næsti mánuður")
    
    // Prayer screen / text options
    static let textOptions = LS(sk: "Možnosti textu", cz: "Možnosti textu", hu: "Szöveg beállításai", isl: "Textastillingar")
    static let font = LS(sk: "Písmo", cz: "Písmo", hu: "Betűtípus", isl: "Leturgerð")
    static let boldFont = LS(sk: "Tučné písmo", cz: "Tučné písmo", hu: "Félkövér betűtípus", isl: "Feitletur")
    static let automatic = LS(sk: "Automaticky", cz: "Automatický", hu: "Automatikus", isl: "Sjálfvirkt")
    static let light = LS(sk: "Svetlý", cz: "Světlý", hu: "Világos", isl: "Ljóst")
    static let dark = LS(sk: "Tmavý", cz: "Tmavý", hu: "Sötét", isl: "Dökkt")
    static let startPlayback = LS(sk: "Čítanie textu", cz: "Čtení textu", hu: "Szöveg felolvasása", isl: "Lesa upp texta")
    
    // Settings
    static let generalSettings = LS(sk: "Všeobecné nastavenia", cz: "Obecné nastavení", hu: "Általános beállítások", isl: "Almennar stillingar")
    static let liturgicalTexts = LS(sk: "Liturgické texty", cz: "Liturgické texty", hu: "Liturgikus szövegek", isl: "Helgisiðatextar")
    static let language = LS(sk: "Jazyk", cz: "Jazyk", hu: "Nyelv", isl: "Tungumál")
    
    // About
    static let aboutBreviary = LS(sk: "O aplikácii Breviár", cz: "O aplikaci Breviář", hu: "A Zsolozsma alkalmazásról", isl: "Um Tíðabænabók")
    static let webURL = LS(sk: "https://breviar.sk", cz: "https://breviar.cz", hu: "https://zsolozsma.katolikus.hu", isl: "https://breviar.sk")
    static let appName = LS(sk: "Breviár", cz: "Breviář", hu: "Zsolozsma", isl: "Tíðabænabók")
    
    // Setup Wizard
    static let liturgicalCalendar = LS(sk: "Liturgický kalendár", cz: "Liturgický kalendář", hu: "Liturgikus naptár", isl: "Helgisiðadagatal")
    static let networkSettings = LS(sk: "Nastavenia siete", cz: "Nastavení sítě", hu: "Hálózati beállítások", isl: "Netstillingar")
    static let downloadLatestTexts = LS(sk: "Online použitie (texty zo servera)", cz: "Online použití (texty ze serveru)", hu: "Friss szövegek letöltése", isl: "Sækja nýjustu texta")
    static let always = LS(sk: "Vždy", cz: "Vždy", hu: "Mindig", isl: "Alltaf")
    static let onlyOnWifi = LS(sk: "Iba v sieti Wi-Fi", cz: "Pouze v síti Wi-Fi", hu: "Csak Wi-Fi hálózaton", isl: "Aðeins á Wi-Fi")
    static let never = LS(sk: "Nikdy", cz: "Nikdy", hu: "Soha", isl: "Aldrei")
    static let done = LS(sk: "Hotovo", cz: "Hotovo", hu: "Kész", isl: "Lokið")
    
    // Prayer Screen Settings
    static let prayerScreenSettings = LS(sk: "Nastavenia obrazovky modlitby", cz: "Nastavení obrazovky modlitby", hu: "Ima képernyő beállításai", isl: "Stillingar bænaskjás")
    static let fullscreenMode = LS(sk: "Režim celej obrazovky", cz: "Režim celé obrazovky", hu: "Teljes képernyő", isl: "Allur skjár")
    static let oneTap = LS(sk: "1 klik", cz: "1 klik", hu: "1 klikk", isl: "1 snerting")
    static let doubleTap = LS(sk: "Dvojklik", cz: "Dvojklik", hu: "Dupla klikk", isl: "Tvísnerting")
    static let disabled = LS(sk: "Vypnuté", cz: "Vypnuto", hu: "Kikapcsolva", isl: "Slökkt")
    
    // Errors
    static let errNetworkError = LS(sk: "Chyba siete", cz: "Chyba sítě", hu: "Hálózati hiba", isl: "Netvilla")
    static let errServerError = LS(sk: "Neplatná odpoveď zo servera", cz: "Neplatná odpověď ze serveru", hu: "Hibás szerver válasz", isl: "Ógilt svar frá þjóni")
    static let errParseError = LS(sk: "Chyba pri analýze odpovede servera", cz: "Chyba při analýze odpovědi serveru", hu: "Hiba történt a szerver válaszának feldolgozása során", isl: "Villa við að greina svar þjóns")
    static let errEmptyResponse = LS(sk: "Prázdna odpoveď servera", cz: "Prázdná odpověď serveru", hu: "Üres szerver válasz", isl: "Tómt svar frá þjóni")
    static let errInternalError = LS(sk: "Vnútorná chyba", cz: "Interní chyba", hu: "Belső hiba", isl: "Innri villa")
}

let LanguageNames: [Language: String] = [
    .czech: "Čeština",
    .hungarian: "Magyar",
    .icelandic: "Íslenska",
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
]
