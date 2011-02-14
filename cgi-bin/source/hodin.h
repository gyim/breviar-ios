/***************************************************************/
/*                                                             */
/* hodin.h                                                     */
/* (c)1999-2006 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | definovane stringove kontanty                 */
/* document history                                            */
/*   18/02/2000A.D. | created                                  */
/*   06/09/2001A.D. | tento popis                              */
/*   2003-08-07a.D. | pridane nazov_doplnkpsalm[]              */
/*   2003-08-13a.D. | zrusene nazov_doplnkpsalm[]              */
/*   2003-11-20a.D. | pridane nazov_obd_htm_pc[]               */
/*   2005-07-27a.D. | pridané nazov_slavenia_lokal[]           */
/*   2005-08-05a.D. | pridané zvazok_OBD[]                     */
/*   2006-07-11a.D. | prvé kroky k jazykovım mutáciám          */
/*                                                             */
/*                                                             */
/***************************************************************/

#include "liturgia.h"

const char *TEMPLAT[] =
{TEMPLAT_INVITATORIUM, TEMPLAT_RANNE_CHVALY, TEMPLAT_POSV_CITANIE,
 TEMPLAT_CEZ_DEN_9, TEMPLAT_CEZ_DEN_12, TEMPLAT_CEZ_DEN_3,
 TEMPLAT_VESPERY, TEMPLAT_KOMPLETORIUM};

const char *nazov_modlitby[] =
{"invitatórium", "ranné chvály", "posvätné èítanie",
 "modlitba predpoludním", "modlitba napoludnie", "modlitba popoludní",
 "vešpery", "kompletórium", "neurèená",
 "prvé vešpery", "prvé kompletórium",
 "druhé vešpery", "druhé kompletórium",
 "detaily"};

const char *nazov_Modlitby[] =
{"Invitatórium", "Ranné chvály", "Posvätné èítanie",
 "Modlitba predpoludním", "Modlitba napoludnie", "Modlitba popoludní",
 "Vešpery", "Kompletórium", "Neurèená",
 "Prvé vešpery", "Prvé kompletórium",
 "Druhé vešpery", "Druhé kompletórium",
 "Detaily"};
/*
const char *nazov_MODLITBY[] =
{"INVITATÓRIUM", "RANNÉ CHVÁLY", "POSVATNÉ ÈÍTANIE",
 "MODLITBA PREDPOLUDNÍM", "MODLITBA NAPOLUDNIE", "MODLITBA POPOLUDNÍ",
 "VEŠPERY", "KOMPLETÓRIUM", "NEURÈENÁ",
 "PRVÉ VEŠPERY", "PRVÉ KOMPLETÓRIUM",
 "DRUHÉ VEŠPERY", "DRUHÉ KOMPLETÓRIUM",
 "DETAILY"};
*/

const char *nazov_spolc[MODL_SPOL_CAST_NEBRAT + 1] =
{"neurèená",
 "duchovnıch pastierov - pre kòazov",
 "duchovnıch pastierov - pre biskupov",
 "duchovnıch pastierov - pre pápeov",
 "uèite¾ov Cirkvi",
 "apoštolov",
 "jedného muèeníka",
 "viacerıch muèeníkov",
 "Panny Márie",
 "svätıch muov - pre reho¾níkov",
 "svätıch muov",
 "panien",
 "svätıch ien - pre reho¾nice",
 "svätıch ien",
 "duchovnıch pastierov - pre viacerıch",
 "jednej muèenice",
 "svätıch ien - pre vychovávate¾ov",
 "svätıch muov - pre vychovávate¾ov",
 "svätıch ien - pre tıch, èo konali skutky milosrdenstva",
 "svätıch muov - pre tıch, èo konali skutky milosrdenstva",
 "svätıch ien - pre viaceré",
 "svätıch muov - pre viacerıch",
 "viacerıch panien",
 "posviacky chrámu",
 "zosnulıch",
 "nebra"
};

/* sc_rh == spolocna cast pre reholnikov / reholnice;
 * sc_skm == spolocna cast pre tych, co konali skutky milosrdenstva ;
 * sc_vv == spolocna cast pre vychovavatelov;
 * zosnuli == oficium za zosnulych;
 */
const char *nazov_spolc_htm[MODL_SPOL_CAST_NEBRAT + 1] =
{"000",
 "sc_dp.htm",
 "sc_dp.htm",
 "sc_dp.htm",
 "sc_uc.htm",
 "sc_ap.htm",
 "sc_jm.htm",
 "sc_vm.htm",
 "sc_pm.htm",
 "sc_rh.htm",
 "sc_sm.htm",
 "sc_pn.htm",
 "sc_rh.htm",
 "sc_sz.htm",
 "sc_dp.htm",
 "sc_jm.htm",
 "sc_vv.htm",
 "sc_vv.htm",
 "sc_skm.htm",
 "sc_skm.htm",
 "sc_sz.htm",
 "sc_sm.htm",
 "sc_pn.htm",
 "vpchr.htm",
 "ozz.htm",
 "000"
};

const char *nazov_spolc_ANCHOR[MODL_SPOL_CAST_NEBRAT + 1] =
{"000",
 "SCDPKN",
 "SCDPBS",
 "SCDPPP",
 "SCUC",
 "SCAP",
 "SCMM",
 "SCVM",
 "SCPM",
 "SCSMRH",
 "SCSM",
 "SCPN",
 "SCSZRH",
 "SCSZ",
 "SCDPVI",
 "SCZM",
 "SCVV",
 "SCVV",
 "SCSKM",
 "SCSKM",
 "SCSZV",
 "SCSMV",
 "SCPNV",
 "VPCHR",
 "OZZ",
 "000"
};

/* nazov_obdobia: string pre nazov liturgickeho obdobia */
const char *nazov_obdobia[] =
{"ve¾konoèná oktáva", "adventné obdobie", "adventné obdobie",
 "vianoèné obdobie", "vianoèné obdobie", "obdobie „cez rok“",
 "pôstne obdobie", "Ve¾kı tıdeò",
 "ve¾konoèné trojdnie", "ve¾konoèné obdobie", "ve¾konoèné obdobie",
 "oktáva Narodenia Pána"};
const char *nazov_obdobia_[] = // debuggovacie
{"ve¾konoèná oktáva", "adventné obdobie I", "adventné obdobie II",
 "vianoèné obdobie I", "vianoèné obdobie II", "obdobie „cez rok“",
 "pôstne obdobie I", "Ve¾kı tıdeò",
 "ve¾konoèné trojdnie", "ve¾konoèné obdobie I", "ve¾konoèné obdobie II",
 "oktáva Narodenia Pána"};
/* lokal == 6. pad, v kom/com */
const char *nazov_obdobia_v[] =
{"vo ve¾konoènej oktáve", "v adventnom období", "v adventnom období",
 "vo vianoènom období", "vo vianoènom období", "v období „cez rok“",
 "v pôstnom období", "vo Ve¾kom tıdni",
 "vo ve¾konoènom trojdní", "vo ve¾konoènom období", "vo ve¾konoènom období",
 "v oktáve Narodenia Pána"};
const char *nazov_OBDOBIA_V[] =
{"VO VE¼KONOÈNEJ OKTÁVE", "V ADVENTNOM OBDOBÍ", "V ADVENTNOM OBDOBÍ",
 "VO VIANOÈNOM OBDOBÍ", "VO VIANOÈNOM OBDOBÍ", "V OBDOBÍ „CEZ ROK“",
 "V PÔSTNOM OBDOBÍ", "VO VE¼KOM TİDNI",
 "VO VE¼KONOÈNOM TROJDNÍ", "VO VE¼KONOÈNOM OBDOBÍ", "VO VE¼KONOÈNOM OBDOBÍ",
 "V OKTÁVE NARODENIA PÁNA"};
/* gen[itiv] == 2. pad, koho/coho */
const char *nazov_obdobia_gen[] =
{"ve¾konoènej oktávy", "adventného obdobia", "adventného obdobia",
 "vianoèného obdobia", "vianoèného obdobia", "obdobia „cez rok“",
 "pôstneho obdobia", "Ve¾kého tıdòa",
 "ve¾konoèného trojdnia", "ve¾konoèného obdobia", "ve¾konoèného obdobia",
 "oktávy Narodenia Pána"};
/*
const char *nazov_Obdobia[] =
{"Ve¾konoèná oktáva", "Adventné obdobie", "Adventné obdobie",
 "Vianoèné obdobie", "Vianoèné obdobie", "Obdobie „cez rok“",
 "Pôstne obdobie", "Ve¾kı tıdeò",
 "Ve¾konoèné trojdnie", "Ve¾konoèné obdobie", "Ve¾konoèné obdobie",
 "Oktáva Narodenia Pána"};
*/
/* nazov_obdobia: string pre nazov suboru .htm liturgickeho obdobia */
const char *nazov_obd_htm[] =
{"vnokt.htm", "adv1.htm", "adv2.htm",
 "vian1.htm", "vian2.htm", "cezrok.htm",
 "post1.htm", "vtyz.htm",
 "vtroj.htm", "vn1.htm", "vn2.htm",
 "vian1.htm"};
/* nazov_obdobia: string pre nazov kotvy v .htm liturgickeho obdobia */
const char *nazov_OBD[] =
{"VNOKT", "ADV1", "ADV2",
 "VIAN1", "VIAN2", "OCR",
 "POST1", "VTYZ",
 "VTROJ", "VN1", "VN2",
 "OKTNAR"};
/* nazov_obdobia pc: string pre nazov suboru .htm liturgickeho obdobia pre posvatne citania */
const char *nazov_obd_htm_pc[] =
{"vnokt_pc.htm", "adv1_pc.htm", "adv2_pc.htm",
 "vian1_pc.htm", "vian2_pc.htm", "cezrok_pc.htm",
 "post1_pc.htm", "vtyz_pc.htm",
 "vtroj_pc.htm", "vn1_pc.htm", "vn2_pc.htm",
 "vian1_pc.htm"};

/* 2005-08-05: Pridané. zväzok breviára (LH) pre spoloèné èasti svätıch v kotvách */
const char *zvazok_OBD[] =
{"ZVII", "ZVI", "ZVI",
 "ZVI", "ZVI", "OCR", /* OCR je ZVIII aj ZVIV */
 "ZVII", "ZVII",
 "ZVII", "ZVII", "ZVII",
 "ZVI"};

const char *nazov_slavenia[] =
{"___",
 "slávnos", "sviatok", "spomienka", "¾ubovo¾ná spomienka",
 "vlastné slávenie"};
const char *nazov_Slavenia[] =
{"___",
 "Slávnos", "Sviatok", "Spomienka", "¼ubovo¾ná spomienka",
 "Vlastné slávenie"};

/* 2005-07-27: doplnené */
const char *nazov_slavenia_lokal[] =
{""
,"len v roòavskej katedrále"
,"hlavnı patrón Bratislavsko-Trnavskej arcidiecézy"
,"v Bratislavsko-Trnavskej arcidiecéze a v Banskobystrickej, Košickej, Nitrianskej a Roòavskej diecéze"
,"v Nitrianskej diecéze sviatok hlavnıch patrónov"
,"len v Košickej diecéze"
,"len v Nitrianskej diecéze"
,"len v Banskobystrickej diecéze"
,"len v Spišskej diecéze"
,"len v Roòavskej diecéze"
,"len v Trnavskej diecéze"
,"len v Dóme sv. Martina v Bratislave"
,"v Spišskej diecéze sviatok hlavného patróna"
,"v Banskobystrickej diecéze sviatok hlavného patróna"
,"v Bratislavsko-Trnavskej arcidiecéze a v Banskobystrickej, Nitrianskej a Roòavskej diecéze"
,"v Košickej diecéze sviatok hlavného patróna"
,"na Slovensku 5. júla, slávnos; v Európe sviatok"
,"v Roòavskej diecéze sviatok hlavného patróna"
,"len v konsekrovanıch kostoloch"
,"Druhá ve¾konoèná nede¾a"
,"koniec Oktávy narodenia Pána"
};

const char *rimskymi_tyzden_zaltara[] =
{"_", "I", "II", "III", "IV"};

const int prvy_den[12] =
	{1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};

int pocet_dni[12] =
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const char char_nedelne_pismeno[7] =
	{'b', 'c', 'd', 'e', 'f', 'g', 'A'};

const char char_nedelny_cyklus[3] =
	{'A', 'B', 'C'};

/* nazov_dna: string pre nazov dna; suhlasi s struct tm.tm_wday;
 * Weekday (0--6; Sunday/nedela = 0) */
const char *nazov_dna[] =
{"nede¾a", "pondelok", "utorok", "streda",
 "štvrtok", "piatok", "sobota", "neznámy"};
const char *nazov_dna_asci[] =
{"nedela", "pondelok", "utorok", "streda",
 "stvrtok", "piatok", "sobota", "neznamy"};
const char *nazov_Dna[] =
{"Nede¾a", "Pondelok", "Utorok", "Streda",
 "Štvrtok", "Piatok", "Sobota", "Neznámy"};
const char *nazov_DNA[] =
{"NEDE¼A", "PONDELOK", "UTOROK", "STREDA",
 "ŠTVRTOK", "PIATOK", "SOBOTA", "NEZNÁMY"};
const char *nazov_Dn[] =
{"Ne", "Po", "Ut", "St", "Št", "Pi", "So", "??"};
const char *nazov_DN_asci[] =
{"NE", "PO", "UT", "STR", "STV", "PI", "SO", "??"};
const char *nazov_dn_asci[] =
{"ne", "po", "ut", "str", "stv", "pi", "so", "??"};

/* nazov_mesiaca: string pre nazov dna; suhlasi s struct tm.tm_mon;
 * Month (0--11) */
const char *nazov_mesiaca[] =
{"január", "február", "marec", "apríl", "máj", "jún", "júl",
 "august", "september", "október", "november", "december", "neznámy"};
const char *nazov_mesiaca_asci[] =
{"januar", "februar", "marec", "april", "maj", "jun", "jul",
 "august", "september", "oktober", "november", "december", "neznamy"};
const char *nazov_Mesiaca[] =
{"Január", "Február", "Marec", "Apríl", "Máj", "Jún", "Júl",
 "August", "September", "Október", "November", "December", "Neznámy"};
const char *nazov_MESIACA[] =
{"JANUÁR", "FEBRUÁR", "MAREC", "APRÍL", "MÁJ", "JÚN", "JÚL",
 "AUGUST", "SEPTEMBER", "OKTÓBER", "NOVEMBER", "DECEMBER", "NEZNÁMY"};
const char *nazov_MES[] =
{"JAN", "FEB", "MAR", "APR", "MAJ", "JUN", "JUL",
 "AUG", "SEP", "OKT", "NOV", "DEC", "___"};
const char *nazov_mes[] =
{"jan", "feb", "mar", "apr", "maj", "jun", "jul",
 "aug", "sep", "okt", "nov", "dec", "___"};

/* 2006-07-11: Pridané kvôli jazykovım mutáciám */
const char *nazov_jazyka[] =
{"slovenèina", "èeština", "English", "(neurèenı)"};

const char *skratka_jazyka[] =
{"sk", "cz", "en", "??"};
