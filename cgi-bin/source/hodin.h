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
/*   2006-08-01a.D. | zmenené definície konštánt (jaz.mutácie) */
/*   2006-08-07a.D. | pridané sv. muov/ien, èo ili v man.  */
/*                                                             */
/*                                                             */
/***************************************************************/

#ifndef __HODIN_H
#define __HODIN_H

#include "liturgia.h"

const char *TEMPLAT[] =
{TEMPLAT_INVITATORIUM, TEMPLAT_RANNE_CHVALY, TEMPLAT_POSV_CITANIE,
 TEMPLAT_CEZ_DEN_9, TEMPLAT_CEZ_DEN_12, TEMPLAT_CEZ_DEN_3,
 TEMPLAT_VESPERY, TEMPLAT_KOMPLETORIUM};

/*
const char *nazov_modlitby[] =
{"invitatórium", "ranné chvály", "posvätné èítanie",
 "modlitba predpoludním", "modlitba napoludnie", "modlitba popoludní",
 "vešpery", "kompletórium", "neurèená",
 "prvé vešpery", "prvé kompletórium",
 "druhé vešpery", "druhé kompletórium",
 "detaily"};
*/

const char *nazov_modlitby_jazyk[POCET_MODLITIEB + 1][POCET_JAZYKOV + 1] = 
{{"invitatórium", "invitatoø", "Invitatory", "" }
, {"ranné chvály", "ranní chvály", "Laudes", "" }
, {"posvätné èítanie", "posvátné ètení", "Holy Reading", "" }
, {"modlitba predpoludním", "modlitba dopoledne", "", "" }
, {"modlitba napoludnie", "modlitba v poledne", "", "" }
, {"modlitba popoludní", "modlitba odpoledne", "", "" }
, {"vešpery", "nešpory", "Vesperae", "" }
, {"kompletórium", "kompletáø", "Completary", "" }
, {"neurèená", "neurèena", "not-defined", ""}
, {"prvé vešpery", "první nešpory", "", "" }
, {"prvé kompletórium", "první kompletáø", "", "" }
, {"druhé vešpery", "druhé nešpory", "", "" }
, {"druhé kompletórium", "druhı kompletáø", "", "" }
, {"detaily", "detaily", "Details", "" }
};

#define		nazov_modlitby(a)	nazov_modlitby_jazyk[a][_global_jazyk]

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

/*
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
*/
const char *nazov_spolc_jazyk[POCET_SPOL_CASTI + 1][POCET_JAZYKOV + 1] =
{{"neurèená", "neurèena", "not decided", ""}, 
 {"duchovnıch pastierov - pre kòazov", "duchovních pastıøù - o knìích", "", ""}, 
 {"duchovnıch pastierov - pre biskupov", "duchovních pastıøù - o biskupech", "", ""}, 
 {"duchovnıch pastierov - pre pápeov", "duchovních pastıøù - o papei", "", ""}, 
 {"uèite¾ov Cirkvi", "uèitelù církve", "", ""}, 
 {"apoštolov", "apoštolù", "", ""}, 
 {"jedného muèeníka", "jednoho muèedníka", "", ""}, 
 {"viacerıch muèeníkov", "více mùèedníkù", "", ""}, 
 {"Panny Márie", "Panny Marie", "", ""}, 
 {"svätıch muov - pre reho¾níkov", "svatıch muù - o øeholnících", "", ""}, 
 {"svätıch muov", "svatıch muù", "", ""}, 
 {"panien", "pannen", "", ""}, 
 {"svätıch ien - pre reho¾nice", "svatıch en - o øeholnicích", "", ""}, 
 {"svätıch ien", "svatıch en", "", ""}, 
 {"duchovnıch pastierov - pre viacerıch", "duchvních pastıøù - o více pastıøích", "", ""}, 
 {"jednej muèenice", "jedné muèednice", "", ""}, 
 {"svätıch ien - pre vychovávate¾ky", "svatıch en - o vychovatelce", "", ""}, 
 {"svätıch muov - pre vychovávate¾ov", "svatıch muù - o vychovatelıch", "", ""}, 
 {"svätıch ien - pre tie, èo konali skutky milosrdenstva", "svatıch en - o enì, která vynikala milosrdnımi skutky", "", ""}, 
 {"svätıch muov - pre tıch, èo konali skutky milosrdenstva", "svatıch muù - o mui, kterı vynikal milosrdnımi skutky", "", ""}, 
 {"svätıch ien - pre viaceré", "svatıch en - o více enách", "", ""}, 
 {"svätıch muov - pre viacerıch", "svatıch muù - o více muích", "", ""}, 
 {"viacerıch panien", "více pannen", "", ""}, 
 {"posviacky chrámu", "posvìcení kostela", "", ""}, 
 {"zosnulıch", "zemøelıch", "", ""}, 
 {"svätıch ien - pre tie, èo ili v manelstve", "svatıch en - o enì, která ila v manelství", "", ""}, 
 {"svätıch muov - pre tıch, èo ili v manelstve", "svatıch muù - o mui, kterı il v manelství", "", ""}, 
 {"nebra", "nevzít", "do not use", ""}
};

#ifndef		nazov_spolc
#define		nazov_spolc(a)	nazov_spolc_jazyk[a][_global_jazyk]
#endif

/* sc_rh == spolocna cast pre reholnikov / reholnice;
 * sc_skm == spolocna cast pre tych, co konali skutky milosrdenstva ;
 * sc_vv == spolocna cast pre vychovavatelov;
 * zosnuli == oficium za zosnulych;
 */
const char *nazov_spolc_htm[POCET_SPOL_CASTI + 1] =
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
 "sc_sz.htm",
 "sc_sm.htm",
 "000"
};

const char *nazov_spolc_ANCHOR[POCET_SPOL_CASTI + 1] =
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
 "SCSZM",
 "SCSMM",
 "000"
};

/* nazov_obdobia: string pre nazov liturgickeho obdobia */

/*
const char *nazov_obdobia[] =
{"ve¾konoèná oktáva", "adventné obdobie", "adventné obdobie",
 "vianoèné obdobie", "vianoèné obdobie", "obdobie „cez rok“",
 "pôstne obdobie", "Ve¾kı tıdeò",
 "ve¾konoèné trojdnie", "ve¾konoèné obdobie", "ve¾konoèné obdobie",
 "oktáva Narodenia Pána"};
*/

const char *nazov_obdobia_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{{"ve¾konoèná oktáva", "velikonoèní oktáv", "", ""},
 {"adventné obdobie", "doba adventní", "", ""},
 {"adventné obdobie", "doba adventní", "", ""},
 {"vianoèné obdobie", "doba vánoèní", "", ""},
 {"vianoèné obdobie", "doba vánoèní", "", ""},
 {"cezroèné obdobie", "mezidobí", "", ""}, // obdobie „cez rok“
 {"pôstne obdobie", "doba postní", "", ""},
 {"Ve¾kı tıdeò", "Svatı tıden", "", ""},
 {"ve¾konoèné trojdnie", "Velikonoèní triduum", "", ""},
 {"ve¾konoèné obdobie", "doba velikonoèní", "", ""},
 {"ve¾konoèné obdobie", "doba velikonoèní", "", ""},
 {"oktáva Narodenia Pána", "oktáv Narození Pánì", "", ""}
};

#define		nazov_obdobia(a)	nazov_obdobia_jazyk[a][_global_jazyk]

const char *nazov_obdobia_[] = // debuggovacie - preto netreba preklada; 2006-08-03
{"ve¾konoèná oktáva", "adventné obdobie I", "adventné obdobie II",
 "vianoèné obdobie I", "vianoèné obdobie II", "obdobie „cez rok“",
 "pôstne obdobie I", "Ve¾kı tıdeò",
 "ve¾konoèné trojdnie", "ve¾konoèné obdobie I", "ve¾konoèné obdobie II",
 "oktáva Narodenia Pána"};

/* lokal == 6. pad, v kom/com */

/*
const char *nazov_obdobia_v[] =
{"vo ve¾konoènej oktáve", "v adventnom období", "v adventnom období",
 "vo vianoènom období", "vo vianoènom období", "v období „cez rok“",
 "v pôstnom období", "vo Ve¾kom tıdni",
 "vo ve¾konoènom trojdní", "vo ve¾konoènom období", "vo ve¾konoènom období",
 "v oktáve Narodenia Pána"};
*/
const char *nazov_obdobia_v_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{{"vo ve¾konoènej oktáve", "ve velikonoèním oktávu", "", ""},
 {"v adventnom období", "v dobì adventní", "", ""},
 {"v adventnom období", "v dobì adventní", "", ""},
 {"vo vianoènom období", "v dobì vánoèní", "", ""},
 {"vo vianoènom období", "v dobì vánoèní", "", ""},
 {"v cezroènom období", "v mezidobí", "", ""}, // obdobie „cez rok“
 {"v pôstnom období", "v dobì postní", "", ""},
 {"vo Ve¾kom tıdni", "ve Svatém tıdnu", "", ""},
 {"vo ve¾konoènom trojdní", "ve velikonoèním triduu", "", ""},
 {"vo ve¾konoènom období", "v dobì velikonoèní", "", ""},
 {"vo ve¾konoènom období", "v dobì velikonoèní", "", ""},
 {"v oktáve Narodenia Pána", "v oktávu Narození Pánì", "", ""}
};

#define		nazov_obdobia_v(a)	nazov_obdobia_v_jazyk[a][_global_jazyk]

/*
const char *nazov_OBDOBIA_V[] =
{"VO VE¼KONOÈNEJ OKTÁVE", "V ADVENTNOM OBDOBÍ", "V ADVENTNOM OBDOBÍ",
 "VO VIANOÈNOM OBDOBÍ", "VO VIANOÈNOM OBDOBÍ", "V OBDOBÍ „CEZ ROK“",
 "V PÔSTNOM OBDOBÍ", "VO VE¼KOM TİDNI",
 "VO VE¼KONOÈNOM TROJDNÍ", "VO VE¼KONOÈNOM OBDOBÍ", "VO VE¼KONOÈNOM OBDOBÍ",
 "V OKTÁVE NARODENIA PÁNA"};
*/
const char *nazov_OBDOBIA_V_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{{"VO VE¼KONOÈNEJ OKTÁVE", "VE VELIKONOÈNÍM OKTÁVU", "", ""},
 {"V ADVENTNOM OBDOBÍ", "V DOBÌ ADVENTNÍ", "", ""},
 {"V ADVENTNOM OBDOBÍ", "V DOBÌ ADVENTNÍ", "", ""},
 {"VO VIANOÈNOM OBDOBÍ", "V DOBÌ VÁNOÈNÍ", "", ""},
 {"VO VIANOÈNOM OBDOBÍ", "V DOBÌ VÁNOÈNÍ", "", ""},
 {"V CEZROÈNOM OBDOBÍ", "V MEZIDOBÍ", "", ""}, // OBDOBIE „CEZ ROK“
 {"V PÔSTNOM OBDOBÍ", "V DOBÌ POSTNÍ", "", ""},
 {"VO VE¼KOM TİDNI", "VE SVATÉM TİDNU", "", ""},
 {"VO VE¼KONOÈNOM TROJDNÍ", "VE VELIKONOÈNÍM TRIDUU", "", ""},
 {"VO VE¼KONOÈNOM OBDOBÍ", "V DOBÌ VELIKONOÈNÍ", "", ""},
 {"VO VE¼KONOÈNOM OBDOBÍ", "V DOBÌ VELIKONOÈNÍ", "", ""},
 {"V OKTÁVE NARODENIA PÁNA", "V OKTÁVU NAROZENÍ PÁNÌ", "", ""}
};

#define		nazov_OBDOBIA_V(a)	nazov_OBDOBIA_V_jazyk[a][_global_jazyk]

/* gen[itiv] == 2. pad, koho/coho */

/* 2006-08-02: netreba preklada, pretoe sa nepouíva 
const char *nazov_obdobia_gen[] =
{"ve¾konoènej oktávy", "adventného obdobia", "adventného obdobia",
 "vianoèného obdobia", "vianoèného obdobia", "obdobia „cez rok“",
 "pôstneho obdobia", "Ve¾kého tıdòa",
 "ve¾konoèného trojdnia", "ve¾konoèného obdobia", "ve¾konoèného obdobia",
 "oktávy Narodenia Pána"};

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

/*
const char *nazov_slavenia[] =
{"___",
 "slávnos", "sviatok", "spomienka", "¾ubovo¾ná spomienka",
 "vlastné slávenie"};
*/
const char *nazov_slavenia_jazyk[POCET_SLAVENI + 1][POCET_JAZYKOV + 1] =
{{"___", "___", "___", ""}, 
 {"slávnos", "slavnost", "", ""}, 
 {"sviatok", "svátek", "", ""}, 
 {"spomienka", "památka", "", ""}, 
 {"¾ubovo¾ná spomienka", "nezávazná památka", "", ""}, 
 {"vlastné slávenie", "z vlastních textù", "", ""}, 
};

#define		nazov_slavenia(a)	nazov_slavenia_jazyk[a][_global_jazyk]

/* 2006-08-02: netreba preklada, pretoe sa nepouíva 
const char *nazov_Slavenia[] =
{"___",
 "Slávnos", "Sviatok", "Spomienka", "¼ubovo¾ná spomienka",
 "Vlastné slávenie"};
*/

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
,"konec Oktávu Narození Pánì"
,"hlavního patrona praské arcidiecéze"
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

/*
const char *nazov_dna[] =
{"nede¾a", "pondelok", "utorok", "streda",
 "štvrtok", "piatok", "sobota", "neznámy"};
*/
const char *nazov_dna_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{{"nede¾a", "nedìle", "Sunday", ""}
, {"pondelok" , "pondìlí", "Monday", ""}
, {"utorok" , "úterı", "Tuesday", ""}
, {"streda" , "støeda", "Wednesday", ""}
, {"štvrtok" , "ètvrtek", "Thursday", ""}
, {"piatok" , "pátek", "Friday", ""}
, {"sobota" , "sobota", "Saturday", ""}
, {"neznámy" , "neznámı", "unknown", ""}
};

#define		nazov_dna(a)	nazov_dna_jazyk[a][_global_jazyk]

/*
const char *nazov_dna_asci[] =
{"nedela", "pondelok", "utorok", "streda",
 "stvrtok", "piatok", "sobota", "neznamy"};
*/
const char *nazov_dna_asci_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{{"nedela", "nedele", "Sunday", ""}
, {"pondelok" , "pondeli", "Monday", ""}
, {"utorok" , "utery", "Tuesday", ""}
, {"streda" , "streda", "Wednesday", ""}
, {"stvrtok" , "ctvrtek", "Thursday", ""}
, {"piatok" , "patek", "Friday", ""}
, {"sobota" , "sobota", "Saturday", ""}
, {"neznamy" , "neznamy", "unknown", ""}
};

#define		nazov_dna_asci(a)	nazov_dna_asci_jazyk[a][_global_jazyk]

/*
const char *nazov_Dna[] =
{"Nede¾a", "Pondelok", "Utorok", "Streda",
 "Štvrtok", "Piatok", "Sobota", "Neznámy"};
*/
const char *nazov_Dna_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{{"Nede¾a", "Nedìle", "Sunday", ""}
, {"Pondelok" , "Pondìlí", "Monday", ""}
, {"Utorok" , "Úterı", "Tuesday", ""}
, {"Streda" , "Støeda", "Wednesday", ""}
, {"Štvrtok" , "Ètvrtek", "Thursday", ""}
, {"Piatok" , "Pátek", "Friday", ""}
, {"Sobota" , "Sobota", "Saturday", ""}
, {"Neznámy" , "Neznámı", "unknown", ""}
};

#define		nazov_Dna(a)	nazov_Dna_jazyk[a][_global_jazyk]

/*
const char *nazov_DNA[] =
{"NEDE¼A", "PONDELOK", "UTOROK", "STREDA",
 "ŠTVRTOK", "PIATOK", "SOBOTA", "NEZNÁMY"};
*/
const char *nazov_DNA_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{{"NEDE¼A", "NEDÌLE", "SUNDAY", ""}
, {"PONDELOK" , "PONDÌLÍ", "MONDAY", ""}
, {"UTOROK" , "ÚTERİ", "TUESDAY", ""}
, {"STREDA" , "STØEDA", "WEDNESDAY", ""}
, {"ŠTVRTOK" , "ÈTVRTEK", "THURSDAY", ""}
, {"PIATOK" , "PÁTEK", "FRIDAY", ""}
, {"SOBOTA" , "SOBOTA", "SATURDAY", ""}
, {"NEZNÁMY" , "NEZNÁMİ", "UNKNOWN", ""}
};

#define		nazov_DNA(a)	nazov_DNA_jazyk[a][_global_jazyk]

/*
const char *nazov_Dn[] =
{"Ne", "Po", "Ut", "St", "Št", "Pi", "So", "??"};
*/
const char *nazov_Dn_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{ {"Ne" , "Ne", "Sun", ""}
, {"Po" , "Po", "Mon", ""}
, {"Ut" , "Út", "Tue", ""}
, {"St" , "St", "Wed", ""}
, {"Št" , "Èt", "Thu", ""}
, {"Pi" , "Pá", "Fri", ""}
, {"So" , "So", "Sat", ""}
, {"??" , "??", "???", ""}
};

#define		nazov_Dn(a)	nazov_Dn_jazyk[a][_global_jazyk]

/* 2006-08-01: pouíva sa pre HTML kotvy, ktoré nezávisia od jazykovej mutácie */
const char *nazov_DN_asci[] =
{"NE", "PO", "UT", "STR", "STV", "PI", "SO", "??"};

const char *nazov_dn_asci[] =
{"ne", "po", "ut", "str", "stv", "pi", "so", "??"};

/* nazov_mesiaca: string pre nazov dna; suhlasi s struct tm.tm_mon;
 * Month (0--11) */

/*
const char *nazov_mesiaca[] =
{"január", "február", "marec", "apríl", "máj", "jún", "júl",
 "august", "september", "október", "november", "december", "neznámy"};
*/

const char *nazov_mesiaca_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{{"január", "leden", "January", ""}
, {"február" , "únor", "February", ""}
, {"marec" , "bøezen", "March", ""}
, {"apríl" , "duben", "April", ""}
, {"máj" , "kvìten", "May", ""}
, {"jún" , "èerven", "June", ""}
, {"júl" , "èervenec", "July", ""}
, {"august" , "srpen", "August", ""}
, {"september" , "záøí", "September", ""}
, {"október" , "øíjen", "October", ""}
, {"november" , "listopad", "November", ""}
, {"december" , "prosinec", "December", ""}
, {"neznámy" , "neznámı", "unknown", ""}
};

#define		nazov_mesiaca(a)	nazov_mesiaca_jazyk[a][_global_jazyk]

/*
const char *nazov_mesiaca_asci[] =
{"januar", "februar", "marec", "april", "maj", "jun", "jul",
 "august", "september", "oktober", "november", "december", "neznamy"};
*/

const char *nazov_mesiaca_asci_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{{"januar", "leden", "January", ""}
, {"februar" , "unor", "February", ""}
, {"marec" , "brezen", "March", ""}
, {"april" , "duben", "April", ""}
, {"maj" , "kveten", "May", ""}
, {"jun" , "cerven", "June", ""}
, {"jul" , "cervenec", "July", ""}
, {"august" , "srpen", "August", ""}
, {"september" , "zari", "September", ""}
, {"oktober" , "rijen", "October", ""}
, {"november" , "listopad", "November", ""}
, {"december" , "prosinec", "December", ""}
, {"neznamy" , "neznamy", "unknown", ""}
};

#define		nazov_mesiaca_asci(a)	nazov_mesiaca_asci_jazyk[a][_global_jazyk]

/*
const char *nazov_Mesiaca[] =
{"Január", "Február", "Marec", "Apríl", "Máj", "Jún", "Júl",
 "August", "September", "Október", "November", "December", "Neznámy"};
*/
const char *nazov_Mesiaca_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{ {"Január", "Leden", "January", ""}
, {"Február" , "Únor", "February", ""}
, {"Marec" , "Bøezen", "March", ""}
, {"Apríl" , "Duben", "April", ""}
, {"Máj" , "Kvìten", "May", ""}
, {"Jún" , "Èerven", "June", ""}
, {"Júl" , "Èervenec", "July", ""}
, {"August" , "Srpen", "August", ""}
, {"September" , "Záøí", "September", ""}
, {"Október" , "Øíjen", "October", ""}
, {"November" , "Listopad", "November", ""}
, {"December" , "Prosinec", "December", ""}
, {"Neznámy" , "Neznámı", "unknown", ""}
};

#define		nazov_Mesiaca(a)	nazov_Mesiaca_jazyk[a][_global_jazyk]

/*
const char *nazov_MESIACA[] =
{"JANUÁR", "FEBRUÁR", "MAREC", "APRÍL", "MÁJ", "JÚN", "JÚL",
 "AUGUST", "SEPTEMBER", "OKTÓBER", "NOVEMBER", "DECEMBER", "NEZNÁMY"};
*/
const char *nazov_MESIACA_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{ {"JANUÁR", "LEDEN", "JANUARY", ""}
, {"FEBRUÁR" , "ÚNOR", "FEBRUARY", ""}
, {"MAREC" , "BØEZEN", "MARCH", ""}
, {"APRÍL" , "DUBEN", "APRIL", ""}
, {"MÁJ" , "KVÌTEN", "MAY", ""}
, {"JÚN" , "ÈERVEN", "JUNE", ""}
, {"JÚL" , "ÈERVENEC", "JULY", ""}
, {"AUGUST" , "SRPEN", "AUGUST", ""}
, {"SEPTEMBER" , "ZÁØÍ", "SEPTEMBER", ""}
, {"OKTÓBER" , "ØÍJEN", "OCTOBER", ""}
, {"NOVEMBER" , "LISTOPAD", "NOVEMBER", ""}
, {"DECEMBER" , "PROSINEC", "DECEMBER", ""}
, {"NEZNÁMY" , "NEZNÁMİ", "UNKNOWN", ""}
};

#define		nazov_MESIACA(a)	nazov_MESIACA_jazyk[a][_global_jazyk]

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

/* 2006-07-13 a 17: Pridané kvôli jazykovım mutáciám - postfix pre include adresár */
const char *postfix_jazyka[] =
{"", "cz", "en", ""};
/* Poznámka: Postfix nesmie obsahova na zaèiatku odde¾ovaè (slash resp. backslash);
 * musí sa jedna o podadresár pod include */

/* definície HTML prvkov upravené a presunuté z mydefs.h, 2006-08-01 */
const char *html_button_ranne_chvaly[] = {"Ranné chvály", "Ranní chvály", "Laudes", ""};
#ifndef HTML_BUTTON_RANNE_CHVALY
#define HTML_BUTTON_RANNE_CHVALY	html_button_ranne_chvaly[_global_jazyk]
#endif

const char *html_button_predpoludnim[] = {"9h", "9h", "9h", ""};
#ifndef HTML_BUTTON_PREDPOLUDNIM
#define HTML_BUTTON_PREDPOLUDNIM	html_button_predpoludnim[_global_jazyk]
#endif

const char *html_button_napoludnie[] = {"12h", "12h", "12h", ""};
#ifndef HTML_BUTTON_NAPOLUDNIE
#define HTML_BUTTON_NAPOLUDNIE	html_button_napoludnie[_global_jazyk]
#endif

const char *html_button_popoludni[] = {"15h", "15h", "15h", ""};
#ifndef HTML_BUTTON_POPOLUDNI
#define HTML_BUTTON_POPOLUDNI	html_button_popoludni[_global_jazyk]
#endif

const char *html_button_vespery[] = {"Vešpery", "Nešpory", "Vesperae", ""};
#ifndef HTML_BUTTON_VESPERY
#define HTML_BUTTON_VESPERY	html_button_vespery[_global_jazyk]
#endif

const char *html_button_posv_citanie[] = {"Posv.èít.", "Ètení", "Reading", ""};
#ifndef HTML_BUTTON_POSV_CITANIE
#define HTML_BUTTON_POSV_CITANIE	html_button_posv_citanie[_global_jazyk]
#endif

const char *html_button_detaily[] = {"Detaily...", "Podrobnìji...", "Details...", ""};
#ifndef HTML_BUTTON_DETAILY
#define HTML_BUTTON_DETAILY	html_button_detaily[_global_jazyk]
#endif

const char *html_button_det_show[] = {"Zobraz modlitbu", "Uka modlitbu", "Show prayer", ""};
#ifndef HTML_BUTTON_DET_SHOW
#define HTML_BUTTON_DET_SHOW	html_button_det_show[_global_jazyk]
#endif

const char *html_button_det_defaults[] = {"Pôvodné hodnoty", "Pùvodní hodnoty", "Defaults", ""};
#ifndef HTML_BUTTON_DET_DEFAULTS
#define HTML_BUTTON_DET_DEFAULTS	html_button_det_defaults[_global_jazyk]
#endif

const char *html_button_dnes_show[] = {"Zobraz", "Uka", "Show", ""};
#ifndef HTML_BUTTON_DNES_SHOW
#define HTML_BUTTON_DNES_SHOW	html_button_dnes_show[_global_jazyk]
#endif

const char *html_button_dnes_defaults[] = {"Vyèisti", "Vyèisti", "Clear", ""};
#ifndef HTML_BUTTON_DNES_DEFAULTS
#define HTML_BUTTON_DNES_DEFAULTS	html_button_dnes_defaults[_global_jazyk]
#endif

const char *html_button_predchadzajuci_[] = {"Predchádzajúci", "Pøedchozí", "Previous", ""};
const char *html_button_nasledujuci_[] = {"Nasledujúci", "Následující", "Next", ""};
const char *html_text_den[] = {"deò", "den", "day", ""};
const char *html_text_mesiac[] = {"mesiac", "mìsíc", "month", ""};
const char *html_text_rok[] = {"rok", "rok", "year", ""};
const char *html_text_Rok[] = {"Rok", "Rok", "Year", ""};
const char *html_text_Rok_x[] = {"Rok %d", "Rok %d", "Year %d", ""};
const char *html_text_modlitba[] = {"modlitba", "modlitba", "prayer", ""};
const char *html_text_modlitby_pre_den[] = {"modlitby pre deò", "modlitby pro den", "prayers for date", ""};
const char *html_text_alebo_pre[] = {"alebo pre", "anebo pro", "or for", ""};
const char *html_text_dnesok[] = {"dnešok", "dnešní den", "today", ""};
const char *html_text_dalsie_moznosti[] = {"Vyberte si ïalšie monosti ", "Další monosti vıbìru ", "Choose from above (buttons) or from the following options: ", ""};
const char *html_text_prik_sviatky_atd[] = {"prikázané sviatky a slávnosti Pána v roku ", "pøikázané svátky a slávnosti Pánì v roku ", "obligatory celebrations in year ", ""};
const char *html_text_lit_kalendar[] = {"liturgickı kalendár pre", "liturgickı kalendáø pro", "liturgical calendar for", ""};
const char *html_text_roku[] = {"roku", "roku", "of year", ""};
const char *html_text_tabulka_pohyblive_od[] = {"tabu¾ka dátumov pohyblivıch slávení od roku", "tabulka s datumy promìnnıch slavností od roku", "table with dates of movable celebrations from year", ""};
const char *html_text_do_roku[] = {"do roku", "po rok", "till year", ""};
const char *html_text_zobrazit_linky[] = {"zobrazi tabu¾ku vrátane hypertextovıch odkazov na jednotlivé dni", "zobrazit tabulku s hypertextovımi odkazy pro jednotlivé dny", "display the table including hypertext links to each date", ""};
const char *html_text_pre_cezrocne_obd[] = {"pre cezroèné obdobie", "pro mezidobí", "for ...", ""};
const char *html_text_tyzden_zaltara[] = {". tıdeò altára", ". tıden altáøe", "week of Psaltary", ""};
const char *html_text_tyzden[] = {". tıdeò", ". tıden", "week", ""};
const char *html_text_v_tyzdni_zaltara[] = {". tıdni altára", ". tıdnu altáøe", "week of Psaltary", ""};
const char *html_text_dnes_je_atd[] = {"Dnes je %d. deò v roku, <a href=\"%s%s\">juliánsky dátum</a> JD = %ld.\n<br>\n", "Dnes je %d. den v roku, <a href=\"%s%s\">juliánské datum</a> JD = %ld.\n<br>\n", "Today is %d. day in the year, <a href=\"%s%s\">Julian date</a> JD = %ld.\n<br>\n", ""};
const char *html_text_zakladne_info[] = {"Základné informácie", "Základní informace", "Basic info", ""};
const char *html_text_je[] = {"je", "je", "is", ""};
const char *html_text_nie_je[] = {"nie je", "není", "is not", ""};
const char *html_text_prestupny[] = {"prestupnı", "pøestupnı", "...", ""};
const char *html_text_datumy_pohyblivych_slaveni[] = {"Dátumy pohyblivıch slávení", "Dáta promìnlivıch slávení", "Dates for movable celebrations", ""};
const char *html_text_Nedelne_pismeno[] = {"Nede¾né písmeno", "Nedelní písmeno", "Sunday letter", ""};
const char *html_text_Nedelne_pismena[] = {"Nede¾né písmená", "Nedelní písmena", "Sunday letters", ""};
const char *html_text_Od_prvej_adv_atd[] = {
	"Od prvej adventnej nedele v roku %d (%s) pokraèuje <a href=\"%s%s\">liturgickı rok</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"Od prní nedìle adventní v roku %d (%s) pokraèuje <a href=\"%s%s\">liturgickı rok</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"From the 1st Advent Sunday in the year %d (%s) continues <a href=\"%s%s\">liturgical year</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"Od prvej adventnej nedele v roku %d (%s) pokraèuje <a href=\"%s%s\">liturgickı rok</a> <"HTML_SPAN_BOLD">%c</span>.\n"
};

const char *str_modl_cez_den_zalmy_zo_dna[POCET_JAZYKOV + 1] = 
	{"benej psalmódie", "bìné psalmodie", "ordinary psalmody", ""};
#define		STR_MODL_CEZ_DEN_ZALMY_ZO_DNA 	str_modl_cez_den_zalmy_zo_dna[_global_jazyk]

const char *str_modl_cez_den_doplnkova_psalmodia[POCET_JAZYKOV + 1] = 
	{"doplnkovej psalmódie", "doplòkové psalmodie", "supplementary psalmody", ""};
#define		STR_MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA 	str_modl_cez_den_doplnkova_psalmodia[_global_jazyk]

const char *str_modl_zalmy_zo_dna[POCET_JAZYKOV + 1] = 
	{"dòa", "dne", "day", ""};
#define		STR_MODL_ZALMY_ZO_DNA 	str_modl_zalmy_zo_dna[_global_jazyk]

const char *str_modl_zalmy_zo_sv[POCET_JAZYKOV + 1] = 
	{"sviatku", "svátku", "celebration", ""};
#define		STR_MODL_ZALMY_ZO_SV 	str_modl_zalmy_zo_sv[_global_jazyk]

const char *str_ano[POCET_JAZYKOV + 1] = 
	{"áno", "ano", "yes", ""};
#define		STR_ANO		str_ano[_global_jazyk]

const char *str_nie[POCET_JAZYKOV + 1] = 
	{"nie", "ne", "no", ""};
#define		STR_NIE		str_nie[_global_jazyk]

const char *html_text_detaily_uvod[POCET_JAZYKOV + 1] = 
{"Nasledovné monosti ovplyvnia vzh¾ad i obsah vygenerovanej modlitby.\nVyberte tie monosti, pod¾a ktorıch sa má modlitba vygenerova.", 
 "Následující monosti mají vliv na vzhled i obsah vygenerované modlitby.\nVyberte si monosti, podle kterıch má bıt modlitba vygenerována.", 
 "The following options apply to the resulting generated text of the prayer.\nChoose options which fit your needs to the resulting prayer text.", 
 ""};

const char *html_text_nemenne_sucasti[] = {"zobrazi <i>nemenné súèasti</i> modlitby?", "zobrazit <i>nemìnné souèásti</i> modlitby?", "display <i>non-changeable parts</i> prayer?", ""};
const char *html_text_nemenne_sucasti_explain[] = 
{"Kadé ranné chvály obsahujú Benediktus, vešpery Magnifikat, obe modlitby obsahujú Otèenáš a zakonèenie modlitby, a napokon posvätné èítanie obsahuje niekedy hymnus Te Deum; tieto èasti modlitby nazıvame <i>nemenné súèasti</i>.", 
 "Kadé ranní chvály obsahují Zachariášovo kantikum, nešpory Mariin Magnifikat, obì modlitbu Pánì a zakonèení modlitby, a koneènì modlitba se ètením nìkdy obsahuje hymnus Te Deum; tyto èásti modliteb nazıváme <i>nemìnné souèásti</i>.", 
 "Each morning prayer contains Benedictus, vesperae contains Magnificat, both contain the Lord's Prayer and a conclusion of the prayer; finally, the holy reading sometimes contains the Te Deum hymnus; all these parts we call <i>un-changeable parts</i>.", 
 ""};

const char *html_text_popis_svaty[] = {"zobrazi <i>popis</i> k modlitbe svätého?", "zobrazit <i>popis</i> pøi modlitbì ke cti svìtce?", "display <i>description</i> for prayer for the saints?", ""};
const char *html_text_popis_svaty_explain[] = 
{"Modlitby zväèša obsahujú pred názvom modlitby ivotopis svätého, popis sviatku alebo podobnú struènú charakteristiku, ktorú pre jednoduchos nazıvame <i>popis</i>.", 
 "Modlitby ke cti svatıch obsahují struènı ivotopis svatého, pøi svátku je to struènı popis svátku a podobnì. Tyto charakteristiky pro struènost nazıváme <i>popis</i>.", 
 "xxx", 
 ""};

const char *html_text_zalmy_brat_zo[] = {"almy bra zo ", "almy brát ze ", "take psalmody from ", ""};
const char *html_text_zalmy_brat_zo_okrem_mcd[] = {" (okrem modlitby cez deò)\n", " (kromì modlitby pøes den)\n", " (excluding the prayers during the day)\n", ""};
const char *html_text_zalmy_brat_zo_explain[] = 
{"V závislosti od typu svätenia sa berú alebo neberú na sviatok svätca/svätice almy a chválospevy z vlastnej èasti (na ranné chvály z nedele 1. tıdòa altára); je moné tieto almy vyiada.", 
 "V závislosti na typu slavení svátku svìtce/svìtice se berou nebo neberou almy a kantika z vlastní èásti (na ranní chvály z nedìle 1. tıdne altáøe); je mono tyto almy vyádat.", 
 "xxx", 
 ""};

const char *html_text_spol_casti_vziat_zo[] = {"èasti modlitby zo spoloènej èasti ", "èásti modlitby ze spoleèné èásti ", "parts of prayer from the common part ", ""};
const char *html_text_spol_casti_vziat_zo_explain[] = 
{"Na sviatok svätca/svätice sa pod¾a liturgickıch pravidiel berú èasti, ktoré sa nenachádzajú vo vlastnej èasti altára, zo spoloènej èasti sviatku, niekedy je monos vybra si z viacerıch spoloènıch èastí; naviac je monos modli sa tieto èasti zo všedného dòa.", 
 "Na svátek ke cti svìtce/svìtice se podle liturgickıch pravidel berou èásti, které se nenachází ve vlastních textech, ze spoleènıch textù, nìkdy je moné vybrat si z více spoleènıch textù; navíc je monost modlit se tyto èásti ze všedního dne.", 
 "xxx", 
 ""};

const char *html_text_zalmy_pre_mcd[] = {"almy pre modlitbu cez deò bra z ", "almy pro modlitbu pøes den brát ze ", "take psalmody for the prayer during the day from ", ""};
const char *html_text_zalmy_pre_mcd_explain[] = 
{"Doplnková psalmódia zahàòa 3 série tzv. graduálnych almov ( 120-129), ktoré mono bra namiesto almov zo altára.", 
 "Doplòovací cyklus almù obsahuje 3 série tzv. graduálních almù ( 120-129), které je mono brát místo almù ze altáøe.", 
 "xxx", 
 ""};

const char *html_text_detaily_explain[] = 
{"Pokia¾ sú niektoré parametre pre vybranú modlitbu nepouite¾né, neberú sa do úvahy (môu by teda nastavené ¾ubovo¾ne).", 
 "Kdy jsou nìkteré vıše uvedené volby nepouitelné pro nìjakou modlitbu, neberou se v úvahu (mohou bıt nastaveny dle libovùle).", 
 "If any of described options are not applicable for a chosen prayer, they can be set anyhow.", 
 ""};

const char *text_JAN_01[] =
{"Panny Márie Bohorodièky",
 "Matky Boí, Panny Marie",
 "", ""};
const char *text_JAN_02[] =
{"Sv. Bazila Ve¾kého a Gregora Nazianského, biskupov a uèite¾ov Cirkvi",
 "Sv. Basila Velikého a Øehoøe Naziánského, biskupù a uèitelù církve",
 "", ""};
const char *text_JAN_06[] =
{"Zjavenie Pána",
 "Zjevení Pánì",
 "", ""};
const char *text_JAN_07[] =
{"Sv. Rajmunda z Peòafortu, kòaza",
 "Sv. Rajmunda z Penafortu, knìze",
 "", ""};
const char *text_JAN_KRST[] =
{"Krst Krista Pána",
 "Køtu Pánì",
 "", ""};
const char *text_JAN_13[] =
{"Sv. Hilára, biskupa a uèite¾a Cirkvi",
 "Sv. Hilaria, biskupa a uèitele církve",
 "", ""};
const char *text_JAN_17[] =
{"Sv. Antona, opáta",
 "Sv. Antonína, opata",
 "", ""};
const char *text_JAN_18[] =
{"(na Slovensku nie je)",
 "Panny Marie, Matky jednoty køesanù",
 "", ""};
const char *text_JAN_20_1[] =
{"Sv. Fabiána, pápea a muèeníka",
 "Sv. Fabiána, papee a muèedníka",
 "", ""};
const char *text_JAN_20_2[] =
{"Sv. Šebastiána, muèeníka",
 "Sv. Šebestiána, muèedníka",
 "", ""};
const char *text_JAN_21[] =
{"Sv. Agnesy, panny a muèenice",
 "Sv. Aneky, panny a muèednice",
 "", ""};
const char *text_JAN_22[] =
{"Sv. Vincenta, diakona a muèeníka",
 "Sv. Vincence, jáhna a muèedníka",
 "", ""};
const char *text_JAN_23[] =
{"Sv. Jána Almuníka, biskupa",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "", ""};
const char *text_JAN_24[] =
{"Sv. Františka Saleského, biskupa a uèite¾a Cirkvi",
 "Sv. Františka Saleského, biskupa a uèitele církve",
 "", ""};
const char *text_JAN_25[] =
{"Obrátenie svätého Pavla, apoštola",
 "Obrácení svatého Pavla, apoštola",
 "", ""};
const char *text_JAN_26[] =
{"Sv. Timoteja a Títa, biskupov",
 "Sv. Timoteje a Tita, biskupù",
 "", ""};
const char *text_JAN_27[] =
{"Sv. Angely Merici, panny",
 "Sv. Andìly Mericiové, panny",
 "", ""};
const char *text_JAN_28[] =
{"Sv. Tomáška Akvinského, kòaza a uèite¾a Cirkvi",
 "Sv. Tomáše Akvinského, knìze a uèitele církve",
 "", ""};
const char *text_JAN_31[] =
{"Sv. Jána Boska, kòaza",
 "Sv. Jana Boska, knìze",
 "", ""};

const char *text_FEB_02[] =
{"Obetovanie Pána",
 "Uvedení Pánì do chrámu",
 "", ""};
const char *text_FEB_03_1[] =
{"Sv. Blaeja, biskupa a muèeníka",
 "Sv. Blaeje, biskupa a muèedníka",
 "", ""};
const char *text_FEB_03_2[] =
{"Sv. Oskára, biskupa",
 "Sv. Ansgara, biskupa",
 "", ""};
const char *text_FEB_05[] =
{"Sv. Agaty, panny a muèenice",
 "Sv. Agáty, panny a muèednice",
 "", ""};
const char *text_FEB_06[] =
{"Sv. Pavla Mikiho a spoloèníkov, muèeníkov",
 "Sv. Pavla Mikiho a druhù, muèedníkù",
 "", ""};
const char *text_FEB_08[] =
{"Sv. Hieronyma Emilianiho",
 "Sv. Jeronıma Emilianiho",
 "", ""};
const char *text_FEB_10[] =
{"Sv. Školastiky, panny",
 "Sv. Scholastiky, panny",
 "", ""};
const char *text_FEB_11[] =
{"Prebl. Panny Márie Lurdskej",
 "Panny Marie Lurdské",
 "", ""};
const char *text_FEB_17[] =
{"Siedmich svätıch zakladate¾ov rehole Sluobníkov Panny Márie",
 "Sv. Alexia a druhù, øeholníkù",
 "", ""};
const char *text_FEB_21[] =
{"Sv. Petra Damianiho, biskupa a uèite¾a Cirkvi",
 "Sv. Petra Damianiho, biskupa a uèitele církve",
 "", ""};
const char *text_FEB_22[] =
{"Katedra sv. Petra, apoštola",
 "Stolce svatého Petra, apoštola",
 "", ""};
const char *text_FEB_23[] =
{"Sv. Polykarpa, biskupa a muèeníka",
 "Sv. Polykarpa, biskupa a muèedníka",
 "", ""};

const char *text_POPOLCOVA_STREDA[] =
{"Popolcová streda",
 "Popeleèní søeda",
 "", ""};

const char *text_MAR_04[] =
{"Sv. Kazimíra",
 "Sv. Kazimíra",
 "", ""};
const char *text_MAR_07[] =
{"Sv. Perpetuy a Felicity, muèeníc",
 "Sv. Perpetuy a Felicity, muèednic",
 "", ""};
const char *text_MAR_08[] =
{"Sv. Jána z Boha, reho¾níka",
 "Sv. Jana z Boha, øeholníka",
 "", ""};
const char *text_MAR_09[] =
{"Sv. Františky Rímskej, reho¾níèky",
 "Sv. Františky Øímské, øeholnice",
 "", ""};
const char *text_MAR_10[] =
{"(na Slovensku nie je)",
 "Sv. Jana Ogilvie, knìze a muèedníka",
 "", ""};
const char *text_MAR_17[] =
{"Sv. Patrika, biskupa",
 "Sv. Patrika, biskupa",
 "", ""};
const char *text_MAR_18[] =
{"Sv. Cyrila Jeruzalemského, biskupa a uèite¾a Cirkvi",
 "Sv. Cyrila Jeruzalémského, biskupa a uèitele církve",
 "", ""};
const char *text_MAR_19[] =
{"Sv. Jozefa, enícha Panny Márie",
 "Sv. Josefa, Snoubence Panny Marie",
 "", ""};
const char *text_MAR_23[] =
{"Sv. Turibia de Mongrovejo, biskupa",
 "Sv. Turibia z Mongroveja, biskupa",
 "", ""};
const char *text_MAR_25[] =
{"Zvestovanie Pána",
 "Zvìstování Pánì",
 "", ""};

const char *text_APR_02[] =
{"Sv. Františka z Pauly, pustovníka",
 "Sv. Františka z Pauly, poustevníka",
 "", ""};
const char *text_APR_04[] =
{"Sv. Izidora, biskupa a uèite¾a Cirkvi",
 "Sv. Izidora, biskupa a uèitele církve",
 "", ""};
const char *text_APR_05[] =
{"Sv. Vincenta Ferrera, kòaza",
 "Sv. Vincence Ferrerského, knìze",
 "", ""};
const char *text_APR_07[] =
{"Sv. Jána Krstite¾a de la Salle, kòaza",
 "Sv. Jana Køtitele de la Salle, knìze",
 "", ""};
const char *text_APR_11[] =
{"Sv. Stanislava, biskupa a muèeníka",
 "Sv. Stanislava, biskupa a muèedníka",
 "", ""};
const char *text_APR_13[] =
{"Sv. Martina I., pápea a muèeníka",
 "Sv. Martina I., papee a muèedníka",
 "", ""};
const char *text_APR_21[] =
{"Sv. Anzelma, biskupa a uèite¾a Cirkvi",
 "Sv. Anselma, biskupa a uèitele církve",
 "", ""};
const char *text_APR_23[] =
{"Sv. Vojtecha, biskupa a muèeníka",
 "Sv. Vojtìcha, biskupa a muèedníka",
 "", ""};
const char *text_APR_24_1[] =
{"Sv. Juraja, muèeníka",
 "Sv. Jiøí, muèedníka",
 "", ""};
const char *text_APR_24_2[] =
{"Sv. Fidéla zo Sigmaringenu, kòaza a muèeníka",
 "Sv. Fidela ze Sigmaringy, knìze a muèedníka",
 "", ""};
const char *text_APR_25[] =
{"Sv. Marka, evanjelistu",
 "Sv. Marka, evangelisty",
 "", ""};
const char *text_APR_28_1[] =
{"Sv. Petra Chanela, kòaza a muèeníka",
 "Sv. Petra Chanela, knìze a muèedníka",
 "", ""};
const char *text_APR_28_2[] =
{"Sv. ¼udovíta Márie Grignion de Montfort, kòaza",
 "Sv. Ludvíka Marie Grignona z Montfortu, knìze",
 "", ""};
const char *text_APR_29[] =
{"Sv. Kataríny Sienskej, panny a uèite¾ky Cirkvi, spolupatrónky Európy",
 "Sv. Kateøiny Sienské, panny a uèitelky církve, spolupatronky Evropy",
 "", ""};
const char *text_APR_30_1[] =
{"Sv. Pia V., pápea",
 "Sv. Pia V., papee",
 "", ""};
const char *text_APR_30_2[] =
{"(na Slovensku nie je)",
 "Sv. Zikmunda, muèedníka",
 "", ""};


#endif /* __HODIN_H */
