/***************************************************************/
/*                                                             */
/* hodin.h                                                     */
/* (c)1999-2009 | Juraj Videky | videky@breviar.sk             */
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
/*   2006-08-18a.D. | zmena int na short int (staèí 32tis.)    */
/*   2006-08-19a.D. | pridanie liturgickej farby               */
/*   2006-09-07a.D. | dokonèená lokalizácia mesiacov JAN-AUG   */
/*   2006-09-12a.D. | dokonèená lokalizácia mesiaca SEP+opravy */
/*   2006-09-13a.D. | dokonèená lokalizácia mesiacov OKT+NOV   */
/*   2006-12-04a.D. | oprava: kompletáØ                        */
/*   2006-12-12a.D. | doplnenie latinèiny (la)                 */
/*   2008-01-03a.D. | doplnené text_DRUHA_NEDELA_PO_NAR_PANA[] */
/*   2008-01-05a.D. | doplnené text_PO_POPOLCOVEJ_STREDE[]     */
/*                  - a tie text_V_OKTAVE_NARODENIA[]         */
/*   2008-07-18a.D. | pridanı sviatok (text_JUL_24)            */
/*   2008-08-15a.D. | pridanı ïalší "jazyk" (cz-op)            */
/*   2009-01-29a.D. | pridanı ïalší jazyk - maïarèina (hu)     */
/*   2009-02-01a.D. | hungarian translation added by László    */
/*                                                             */
/*                                                             */
/***************************************************************/

#include "vstudio.h"

#ifndef __HODIN_H
#define __HODIN_H

#include "liturgia.h"

const char *TEMPLAT[] =
{TEMPLAT_INVITATORIUM, TEMPLAT_RANNE_CHVALY, TEMPLAT_POSV_CITANIE,
 TEMPLAT_CEZ_DEN_9, TEMPLAT_CEZ_DEN_12, TEMPLAT_CEZ_DEN_3,
 TEMPLAT_VESPERY, TEMPLAT_KOMPLETORIUM};

/* 2008-04-09: doplnené pre batch generovanie modlitieb */
const char char_modlitby[] =
{CHAR_MODL_INVITATORIUM, CHAR_MODL_RANNE_CHVALY, CHAR_MODL_POSV_CITANIE,
 CHAR_MODL_CEZ_DEN_9, CHAR_MODL_CEZ_DEN_12, CHAR_MODL_CEZ_DEN_3,
 CHAR_MODL_VESPERY, CHAR_MODL_KOMPLETORIUM};

const char *str_modlitby[] =
{STR_MODL_INVITATORIUM, STR_MODL_RANNE_CHVALY, STR_MODL_POSV_CITANIE,
 STR_MODL_PREDPOLUDNIM, STR_MODL_NAPOLUDNIE, STR_MODL_POPOLUDNI,
 STR_MODL_VESPERY, STR_MODL_KOMPLETORIUM};

/* the names of the prayers, lowercase (sample text) */
const char *nazov_modlitby_jazyk[POCET_MODLITIEB + 1][POCET_JAZYKOV + 1] = 
{{"invitatórium", "invitatoø", "Invitatory", "invitatorium", "", "Pozvání k modlitbì", "imádságra hívás" }
, {"ranné chvály", "ranní chvály", "Laudes", "laudes matutinae", "", "Ranní chvály", "reggeli dicséret" }
, {"posvätné èítanie", "modlitba se ètením", "Office of Readings", "officium lectionis", "", "Modlitba se ètením", "olvasmányos imaóra" }
, {"modlitba predpoludním", "modlitba dopoledne", "Terce", "tertia", "", "Tercie", "tertia" }
, {"modlitba napoludnie", "modlitba v poledne", "Sext", "sexta", "", "Sexta", "sexta" }
, {"modlitba popoludní", "modlitba odpoledne", "None", "nona", "", "Nona", "nona" }
, {"vešpery", "nešpory", "Vesperae", "vesper&#230;", "", "Veèerní chvály", "esti dicséret" }
, {"kompletórium", "kompletáø", "Completary", "completorio", "", "Kompletáø", "befejezõ imaóra" }
, {"neurèená", "neurèena", "not-defined", "no data", "", "neurèena", "nem azonosított"}
, {"prvé vešpery", "první nešpory", "1st Vesperae", "I vesper&#230;", "", "První veèerní chvály", "I. esti dicséret" }
	/* 2007-12-05: zmenené, kedysi bolo: "prvé kompletórium" */
, {"kompletórium po prvıch vešperách", "kompletáø po prvních nešporách", "1st Completary", "I completorio", "", "Kompletáø po prvních veèerních chválách", "I. esti dicséret után" }
, {"druhé vešpery", "druhé nešpory", "2nd Vesperae", "II vesper&#230;", "", "Druhé veèerní chvály", "II. esti dicséret" }
	/* 2007-12-05: zmenené, kedysi bolo: "druhé kompletórium" */
, {"kompletórium po druhıch vešperách", "kompletáø po druhıch nešporech", "2nd Completary", "II completorio", "", "Kompletáø po druhıch veèerních chválách", "II. esti dicséret után" }
, {"detaily", "detaily", "Details", "details", "", "detaily", "részletek" }
};

#define		nazov_modlitby(a)	nazov_modlitby_jazyk[a][_global_jazyk]

/* the names of the prayers, sentence case (Sample text) */
const char *nazov_Modlitby_jazyk[POCET_MODLITIEB + 1][POCET_JAZYKOV + 1] = 
{{"Invitatórium", "Invitatoø", "Invitatory", "Invitatorium", "", "Pozvání k modlitbì" , "Imádságra hívás" }
, {"Ranné chvály", "Ranní chvály", "Laudes", "Laudes matutinae", "", "Ranní chvály" , "Reggeli dicséret" }
, {"Posvätné èítanie", "Modlitba se ètením", "Office of Readings", "Officium lectionis", "", "Modlitba se ètením" , "Olvasmányos imaóra" }
, {"Modlitba predpoludním", "Modlitba dopoledne", "Terce", "Tertia", "", "Tercie" , "Tertia" }
, {"Modlitba napoludnie", "Modlitba v poledne", "Sext", "Sexta", "", "Sexta" , "Sexta" }
, {"Modlitba popoludní", "Modlitba odpoledne", "None", "Nona", "", "Nona" , "Nona" }
, {"Vešpery", "Nešpory", "Vesperae", "Vesper&#230;", "", "Veèerní chvály" , "Esti dicséret" }
, {"Kompletórium", "Kompletáø", "Completary", "Completorio", "", "Kompletáø" , "Befejezõ imaóra" }
, {"Neureená", "Neureena", "not-defined", "No data", "", "Neurèená" , "Nem azonosított"}
, {"Prvé vešpery", "První nešpory", "1st Vesperae", "I Vesper&#230;", "", "První veèerní chvály" , "I. Esti dicséret" }
, {"Kompletórium po prvıch vešperách", "Kompletáø po prvních nešporách", "1st Completary", "I Completorio", "", "Kompletáø po prvních veèerních chválách" , "I. Esti dicséret után" }
, {"Druhé vešpery", "Druhé nešpory", "2nd Vesperae", "II Vesper&#230;", "", "Druhé veèerní chvály" , "II. Esti dicséret" }
, {"Kompletórium po druhıch vešperách", "Kompletáø po druhıch nešporech", "2nd Completary", "II Completorio", "", "Kompletáø po druhıch veèerních chválách" , "II. Esti dicséret után" }
, {"Detaily", "Detaily", "Details", "Details", "", "Detaily", "Részletek" }
};

#define		nazov_Modlitby(a)	nazov_Modlitby_jazyk[a][_global_jazyk]

/* the names of the common texts (e.g.: for bishops, for saint men, for apostles...) */
const char *nazov_spolc_jazyk[POCET_SPOL_CASTI + 1][POCET_JAZYKOV + 1] =
{{"neurèená", "neurèena", "not decided", "", "", "", ""}, 
 {"duchovnıch pastierov - pre kòazov", "duchovních pastıøù - o knìích", "", "", "", "O duchovních pastıøích - o knìích", "lelkipásztorok - papok"}, 
 {"duchovnıch pastierov - pre biskupov", "duchovních pastıøù - o biskupech", "", "", "", "O duchovních pastıøích - o biskupech", "lelkipásztorok - püspökök"}, 
 {"duchovnıch pastierov - pre pápeov", "duchovních pastıøù - o papei", "", "", "", "O duchovních pastıøích - o papei", "pásztorok - pápa"}, 
 {"uèite¾ov Cirkvi", "uèitelù církve", "", "", "", "O uèitelích Církve", "egyháztanítók"}, 
 {"apoštolov", "apoštolù", "", "", "", "O apoštolech", "apostolok"}, 
 {"jedného muèeníka", "jednoho muèedníka", "", "", "", "O muèedníkovi", "vértanú"}, 
 {"viacerıch muèeníkov", "více muèedníkù", "", "", "", "O více muèednících", "vértanúk"}, 
 {"Panny Márie", "Panny Marie", "", "", "", "Panny Marie", "Szûz Mária"}, 
 {"svätıch muov - pre reho¾níkov", "svatıch muù - o øeholnících", "", "", "", "O øeholnících", "szerzetes"}, 
 {"svätıch muov", "svatıch muù", "", "", "","O svatıch muích", "szent férfiak"}, 
 {"panien", "panen", "", "", "","O pannách", "szûz"}, 
 {"svätıch ien - pre reho¾nice", "svatıch en - o øeholnicích", "", "", "", "O svatıch enách - o øeholnicích", "apáca"}, 
 {"svätıch ien", "svatıch en", "", "", "", "O svatıch enách", "szent asszonyok"}, 
 {"duchovnıch pastierov - pre viacerıch", "duchvních pastıøù - o více pastıøích", "", "", "", "O duchovních pastıøích", "több lelkipásztor"}, 
 {"jednej muèenice", "jedné muèednice", "", "", "", "O muèednici", "vértanú"}, 
 {"svätıch ien - pre vychovávate¾ky", "svatıch en - o vychovatelce", "", "", "", "O svatıch enách - o vychovatelkách", "egyháztanító férfiak"}, 
 {"svätıch muov - pre vychovávate¾ov", "svatıch muù - o vychovatelıch", "", "", "", "O svatıch muích - o vychovatelích", "egyháztanító asszonyok"}, 
 {"svätıch ien - pre tie, èo konali skutky milosrdenstva", "svatıch en - o enì, která vynikala milosrdnımi skutky", "", "", "", "O svatıch enách - o enì, která vynikala milosrdnımi skutky", "jótékonykodó asszonyok"}, 
 {"svätıch muov - pre tıch, èo konali skutky milosrdenstva", "svatıch muù - o mui, kterı vynikal milosrdnımi skutky", "", "", "", "O svatıch muích - o mui, kterı vynikal milosrdnımi skutky", "jótékonykodó férfiak"}, 
 {"svätıch ien - pre viaceré", "svatıch en - o více enách", "", "", "", "O svatıch enách", "több szent asszony"}, 
 {"svätıch muov - pre viacerıch", "svatıch muù - o více muích", "", "", "", "O svatıch muích", "több szent férfi"}, 
 {"viacerıch panien", "více pannen", "", "", "","O pannách", "szüzek"}, 
 {"posviacky chrámu", "posvìcení kostela", "", "", "", "Posvìcení kostela", "templomszentelés"}, 
 {"zosnulıch", "zemøelıch", "", "", "","Za zemøelé", "halottakért"}, 
 {"svätıch ien - pre tie, èo ili v manelstve", "svatıch en - o enì, která ila v manelství", "", "", "", "O svatıch enách - o enì, která ila v manelství", "házas szent asszonyok"}, 
 {"svätıch muov - pre tıch, èo ili v manelstve", "svatıch muù - o mui, kterı il v manelství", "", "", "", "O svatıch muích - o mui, kterı il v manelství", "házas szent férfiak"}, 
 {"nebra", "nevzít", "do not use", "", "", "nevzít", "mindent sajátból"}
};

#ifndef		nazov_spolc
#define		nazov_spolc(a)	nazov_spolc_jazyk[a][_global_jazyk]
#endif

/* filenames - same for all languages (based on Slovak) */
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

/* anchor names in files - same for all languages (based on Slovak) */
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

/* the names of liturgical periods (usually lowecase) / nazov_obdobia: string pre nazov liturgickeho obdobia */
const char *nazov_obdobia_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{{"ve¾konoèná oktáva", "velikonoèní oktáv", "", "octava paschae", "", "velikonoèní oktáv", "húsvét nyolcada"},
 {"adventné obdobie", "doba adventní", "", "tempus adventus", "", "doba adventní", "adventi idõ"},
 {"adventné obdobie", "doba adventní", "", "tempus adventus", "", "doba adventní", "adventi idõ"},
 {"vianoèné obdobie", "doba vánoèní", "", "tempus nativitatis", "", "doba vánoèní", "karácsonyi idõ"},
 {"vianoèné obdobie", "doba vánoèní", "", "tempus nativitatis", "", "doba vánoèní", "karácsonyi idõ"},
 	// obdobie „cez rok“
 {"cezroèné obdobie", "mezidobí", "", "tempus per annum", "", "mezidobí", "évközi idõ"},
 {"pôstne obdobie", "doba postní", "", "tempus quadragesimae", "", "doba postní", "nagyböjti idõ"},
 {"Ve¾kı tıdeò", "Svatı tıden", "", "hebdomada sancta", "", "Svatı tıden", "nagyhét"},
 {"ve¾konoèné trojdnie", "Velikonoèní triduum", "", "sacrum triduum paschale", "", "Velikonoèní triduum", "szent három nap"},
 {"ve¾konoèné obdobie", "doba velikonoèní", "", "tempus paschale", "", "doba velikonoèní", "húsvéti idõ"},
 {"ve¾konoèné obdobie", "doba velikonoèní", "", "tempus paschale", "", "doba velikonoèní", "húsvéti idõ"},
 {"oktáva Narodenia Pána", "oktáv Narození Pánì", "", "octava nativitatis", "", "oktáv Narození Pánì", "karácsony nyolcada"}
};

#define		nazov_obdobia(a)	nazov_obdobia_jazyk[a][_global_jazyk]

/* the names of liturgical periods for debugging, only in Slovak; no need to translate */
const char *nazov_obdobia_[] = // debuggovacie - preto netreba preklada; 2006-08-03
{"ve¾konoèná oktáva", "adventné obdobie I", "adventné obdobie II",
 "vianoèné obdobie I", "vianoèné obdobie II", "cezroèné obdobie", // obdobie „cez rok“
 "pôstne obdobie I", "Ve¾kı tıdeò",
 "ve¾konoèné trojdnie", "ve¾konoèné obdobie I", "ve¾konoèné obdobie II",
 "oktáva Narodenia Pána"};

/* the names of liturgical periods in local grammatically 6.th declination? (usually lowecase); in English: "IN liturgical period" or "OF liturgical period" /  lokal == 6. pad, v kom/com */
const char *nazov_obdobia_v_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{{"vo ve¾konoènej oktáve", "ve velikonoèním oktávu", "", "", "", "ve velikonoèním oktávu", "húsvét nyolcadában"},
 {"v adventnom období", "v dobì adventní", "", "", "", "v dobì adventní", "adventben"},
 {"v adventnom období", "v dobì adventní", "", "", "", "v dobì adventní", "adventben"},
 {"vo vianoènom období", "v dobì vánoèní", "", "", "", "v dobì vánoèní", "a karácsonyi idõben"},
 {"vo vianoènom období", "v dobì vánoèní", "", "", "", "v dobì vánoèní", "a karácsonyi idõben"},
 	// obdobie „cez rok“
 {"v cezroènom období", "v mezidobí", "", "per annum", "", "v mezidobí", "az évközi idõben"},
 {"v pôstnom období", "v dobì postní", "", "", "", "v dobì postní", "a nagyböjti idõben"},
 {"vo Ve¾kom tıdni", "ve Svatém tıdnu", "", "", "", "ve Svatém tıdnu", "a nagyhéten"},
 {"vo ve¾konoènom trojdní", "ve velikonoèním triduu", "", "", "", "ve velikonoèním triduu", "a szent három napban"},
 {"vo ve¾konoènom období", "v dobì velikonoèní", "", "", "", "v dobì velikonoèní", "a húsvéti idõben"},
 {"vo ve¾konoènom období", "v dobì velikonoèní", "", "", "", "v dobì velikonoèní", "a húsvéti idõben"},
 {"v oktáve Narodenia Pána", "v oktávu Narození Pánì", "", "", "", "v oktávu Narození Pánì", "húsvét nyolcadában"}
};

#define		nazov_obdobia_v(a)	nazov_obdobia_v_jazyk[a][_global_jazyk]

/* the names of liturgical periods in local grammatically 6.th declination? (uppercase) / nazov_obdobia: string pre nazov liturgickeho obdobia */
const char *nazov_OBDOBIA_V_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{{"VO VE¼KONOÈNEJ OKTÁVE", "VE VELIKONOÈNÍM OKTÁVU", "", "", "", "V OKTÁVU VELIKONOÈNÍM", "HÚSVÉT NYOLCACADÁBAN"},
 {"V ADVENTNOM OBDOBÍ", "V DOBÌ ADVENTNÍ", "", "", "", "V DOBÌ ADVENTNÍ", "ADVENTBEN"},
 {"V ADVENTNOM OBDOBÍ", "V DOBÌ ADVENTNÍ", "", "", "", "V DOBÌ ADVENTNÍ", "ADVENTBEN"},
 {"VO VIANOÈNOM OBDOBÍ", "V DOBÌ VÁNOÈNÍ", "", "", "", "V DOBÌ VÁNOÈNÍ", "A KARÁCSONYI IDÕBEN"},
 {"VO VIANOÈNOM OBDOBÍ", "V DOBÌ VÁNOÈNÍ", "", "", "", "V DOBÌ VÁNOÈNÍ", "A KARÁCSONYI IDÕBEN"},
 	// OBDOBIE „CEZ ROK“
 {"V CEZROÈNOM OBDOBÍ", "V MEZIDOBÍ", "", "", "", "BÌHEM ROKU", "AZ ÉVKÖZI IDÕBEN"},
 {"V PÔSTNOM OBDOBÍ", "V DOBÌ POSTNÍ", "", "", "", "V DOBÌ POSTNÍ", "A NAGYBÖJTI IDÕBEN"},
 {"VO VE¼KOM TİDNI", "VE SVATÉM TİDNU", "", "", "", "VE SVATÉM TİDNU", "A NAGYHÉTEN"},
 {"VO VE¼KONOÈNOM TROJDNÍ", "VE VELIKONOÈNÍM TRIDUU", "", "", "", "VE VELIKONOÈNÍM TRIDUU", "A SZENT HÁROM NAPBAN"},
 {"VO VE¼KONOÈNOM OBDOBÍ", "V DOBÌ VELIKONOÈNÍ", "", "", "", "V DOBÌ VELIKONOÈNÍ", "A HÚSVÉTI IDÕBEN"},
 {"VO VE¼KONOÈNOM OBDOBÍ", "V DOBÌ VELIKONOÈNÍ", "", "", "", "V DOBÌ VELIKONOÈNÍ", "A HÚSVÉTI IDÕBEN"},
 {"V OKTÁVE NARODENIA PÁNA", "V OKTÁVU NAROZENÍ PÁNÌ", "", "", "", "V OKTÁVU NAROZENÍ PÁNÌ", "A HÚSVÉT NYOLCADÁBAN"}
};

#define		nazov_OBDOBIA_V(a)	nazov_OBDOBIA_V_jazyk[a][_global_jazyk]

/* used for Sundays - "which" Sunday for some of them, e.g. "dominica V paschae" for 5-th Sunday in that liturgical period (uppercase) */
/* 2008-12-20: doplnené - pouíva sa v init_global_string() pre nedele niektorıch období [zatia¾ iba v slovenèine] */
const char *nazov_OBDOBIA_AKA_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{{"VO VE¼KONOÈNEJ OKTÁVE", "VE VELIKONOÈNÍM OKTÁVU", "", "", "", "V OKTÁVU VELIKONOÈNÍM", "hu_"}, // not used / nepouíva sa
 {"ADVENTNÁ", "ADVENTNÍ", "", "", "", "ADVENTNÍ", "ADVENT"},
 {"ADVENTNÁ", "ADVENTNÍ", "", "", "", "ADVENTNÍ", "ADVENT"},
 {"VIANOÈNÁ", "VÁNOÈNÍ", "", "", "", "VÁNOÈNÍ", "KARÁCSONY"},
 {"VIANOÈNÁ", "VÁNOÈNÍ", "", "", "", "VÁNOÈNÍ", "KARÁCSONY"},
 {"CEZROÈNÁ", "V MEZIDOBÍ", "", "", "", "BÌHEM ROKU", "hu_"}, // not used / nepouíva sa
 {"PÔSTNA", "POSTNÍ", "", "", "", "POSTNÍ", "ÉVKÖZI"},
 {"VO VE¼KOM TİDNI", "VE SVATÉM TİDNU", "", "", "", "VE SVATÉM TİDNU", "hu_"}, // not used / nepouíva sa
 {"VO VE¼KONOÈNOM TROJDNÍ", "VE VELIKONOÈNÍM TRIDUU", "", "", "", "VE VELIKONOÈNÍM TRIDUU", "hu_"}, // not used / nepouíva sa
 {"VE¼KONOÈNÁ", "VELIKONOÈNÍ", "", "", "", "VELIKONOÈNÍ", "HÚSVÉT"},
 {"VE¼KONOÈNÁ", "VELIKONOÈNÍ", "", "", "", "VELIKONOÈNÍ", "HÚSVÉT"},
 {"V OKTÁVE NARODENIA PÁNA", "V OKTÁVU NAROZENÍ PÁNÌ", "", "", "", "V OKTÁVU NAROZENÍ PÁNÌ", "hu_"} // not used / nepouíva sa
};
#define		nazov_OBDOBIA_AKA(a)	nazov_OBDOBIA_AKA_jazyk[a][_global_jazyk]

/* filenames - same for all languages (based on Slovak) */
/* nazov_obdobia: string pre nazov suboru .htm liturgickeho obdobia */
const char *nazov_obd_htm[] =
{"vnokt.htm", "adv1.htm", "adv2.htm",
 "vian1.htm", "vian2.htm", "cezrok.htm",
 "post1.htm", "vtyz.htm",
 "vtroj.htm", "vn1.htm", "vn2.htm",
 "vian1.htm"};

/* anchor names in files - same for all languages (based on Slovak) */
/* nazov_obdobia: string pre nazov kotvy v .htm liturgickeho obdobia */
const char *nazov_OBD[] =
{"VNOKT", "ADV1", "ADV2",
 "VIAN1", "VIAN2", "OCR",
 "POST1", "VTYZ",
 "VTROJ", "VN1", "VN2",
 "OKTNAR"};

/* filenames - same for all languages (based on Slovak) */
/* nazov_obdobia pc: string pre nazov suboru .htm liturgickeho obdobia pre posvatne citania */
const char *nazov_obd_htm_pc[] =
{"vnokt_pc.htm", "adv1_pc.htm", "adv2_pc.htm",
 "vian1_pc.htm", "vian2_pc.htm", "cezrok_pc.htm",
 "post1_pc.htm", "vtyz_pc.htm",
 "vtroj_pc.htm", "vn1_pc.htm", "vn2_pc.htm",
 "vian1_pc.htm"};

/* anchor names in files used for 4 volumes of breviary - same for all languages (based on Slovak) */
/* 2005-08-05: Pridané. zväzok breviára (LH) pre spoloèné èasti svätıch v kotvách */
const char *zvazok_OBD[] =
{"ZVII", "ZVI", "ZVI",
 "ZVI", "ZVI", "OCR", /* OCR je ZVIII aj ZVIV */
 "ZVII", "ZVII",
 "ZVII", "ZVII", "ZVII",
 "ZVI"};

/* the name of celebration */
const char *nazov_slavenia_jazyk[POCET_SLAVENI + 1][POCET_JAZYKOV + 1] =
{{"___", "___", "___", "", ""}, 
 {"slávnos", "slavnost", "celebration", "sollemnitas", "","Slavnost", "fõünnep"},
 {"sviatok", "svátek", "", "festum", "","Svátek", "ünnep"},
 {"spomienka", "památka", "", "memoria", "","Památka", "emléknap"},
 {"¾ubovo¾ná spomienka", "nezávazná památka", "", "memoria ad libitum", "","nezávazná památka", "tetszés szerinti emléknap"},
 {"vlastné slávenie", "z vlastních textù", "", "textus proprius", "", "z vlastních textù", "saját szöveg"},
};

#define		nazov_slavenia(a)	nazov_slavenia_jazyk[a][_global_jazyk]

/* special "local" or "partial" characteristics of various celebrations - each in one language; no need to translate; special strings will be added */
/* 2005-07-27: doplnené
 * 2007-08-31: upravené TT -> BA-TT
 * 2008-06-23: upravené vzh¾adom k novému usporiadaniu diecéz (intuitívne)
 */
const char *nazov_slavenia_lokal[] =
{""
,"len v roòavskej katedrále"
,"hlavnı patrón Trnavskej arcidiecézy" /* "hlavnı patrón Bratislavsko-Trnavskej arcidiecézy" */
,"v Bratislavskej a Trnavskej arcidiecéze a v Banskobystrickej, Košickej, Nitrianskej a Roòavskej diecéze" /* "v Bratislavsko-Trnavskej arcidiecéze a v Banskobystrickej, Košickej, Nitrianskej a Roòavskej diecéze" */
,"v Nitrianskej diecéze sviatok hlavnıch patrónov"
,"len v Košickej diecéze"
,"len v Nitrianskej diecéze"
,"len v Banskobystrickej diecéze"
,"len v Spišskej diecéze"
,"len v Roòavskej diecéze"
,"len v Trnavskej arcidiecéze" /* "len v Bratislavsko-trnavskej arcidiecéze" */ /* LOKAL_SLAV_TRNAVA - pôvodne bolo "len v Trnavskej diecéze", upravené 2007-08-31*/
,"len v Dóme sv. Martina v Bratislave"
,"v Spišskej diecéze sviatok hlavného patróna"
,"v Banskobystrickej diecéze sviatok hlavného patróna"
,"v Bratislavskej a Trnavskej arcidiecéze a v Banskobystrickej, Nitrianskej a Roòavskej diecéze" /* "v Bratislavsko-Trnavskej arcidiecéze a v Banskobystrickej, Nitrianskej a Roòavskej diecéze" */
,"v Košickej diecéze sviatok hlavného patróna"
,"na Slovensku 5. júla, slávnos; v Európe sviatok"
,"v Roòavskej diecéze sviatok hlavného patróna"
,"len v konsekrovanıch kostoloch"
,"Druhá ve¾konoèná nede¾a - Boieho milosrdenstva"
,"koniec Oktávy narodenia Pána"
,"konec Oktávu Narození Pánì"
,"hlavního patrona praské arcidiecéze"
,"v praské arcidiecézi"
,"v brnìnské diecézi"
,"na Moravì památka"
,"Druhá nedìle velikonoèní - Boího milosrdenství"
,"v praské katedrále slavnost"
,"v èeskobudìjovické diecézi"
,"v olomoucké arcidiecézi"
,"v Èechách svátek"
,"v plzeòské diecézi svátek hlavního patrona"
,"v ostravsko-opavské diecézi"
,"v litomìøické diecézi"
,"v královéhradecké diecézi"
,"jen v posvìcenıch kostelích"
,"v plzeòské diecézi"
,"ve Slezsku svátek"
,"v èeskobudìjovické diecézi památka"
,"v Bratislavskej arcidiecéze a v Spišskej diecéze sviatok hlavného patróna" /* doplnené 2008-06-24 */
};

/* names of liturgical colors */
const char *nazov_farby_jazyk[POCET_FARIEB + 1][POCET_JAZYKOV + 1] =
{{"___", "___", "___", "___", "___", "___", "___"},
 {"èervená", "èervená", "red", "rosa", "", "èervená", "piros"},
 {"biela", "bílá", "white", "alba", "", "bílá", "fehér"},
 {"zelená", "zelená", "green", "___", "", "zelená", "zöld"},
 {"fialová", "fialová", "purple", "___", "", "fialová", "lila"},
 {"ruová", "rùová", "rose", "___", "", "rùová", "rózsaszín"},
};

#define		nazov_farby(a)	nazov_farby_jazyk[a][_global_jazyk]

/* codes for colors - HTML specific */
const char *html_farba_pozadie[POCET_FARIEB + 1] =
{"black", "red", "white", "green", "purple", "#FF6699" /* "fuchsia" */};

/* codes for colors - HTML specific */
const char *html_farba_popredie[POCET_FARIEB + 1] =
{"white", "white", "black", "white", "white", "blue"};

/* codes for number of the week from psaltery (psalterium per quattuor hebdomadas distributum) */
const char *rimskymi_tyzden_zaltara[] =
{"_", "I", "II", "III", "IV"};

/* const: ordinal number of the first day in specific month */
const short int prvy_den[12] =
	{1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};

/* const: number (count) of days in specific month */
short int pocet_dni[12] =
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* const: "the Sunday's letter" A--g */
const char char_nedelne_pismeno[7] =
	{'b', 'c', 'd', 'e', 'f', 'g', 'A'};

/* const: the Sunday's cycle A--C */
const char char_nedelny_cyklus[3] =
	{'A', 'B', 'C'};

/* names of the days in week, starting with Sunday (lowercase) / nazov_dna: string pre nazov dna; suhlasi s struct tm.tm_wday;
 * Weekday (0--6; Sunday/nedela = 0) */
const char *nazov_dna_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{ {"nede¾a", "nedìle", "Sunday", "domínica", "", "nedìle", "vasárnap"}
, {"pondelok" , "pondìlí", "Monday", "feria secúnda", "", "pondìlí", "hétfõ"}
, {"utorok" , "úterı", "Tuesday", "feria tértia", "", "úterı", "kedd"}
, {"streda" , "støeda", "Wednesday", "feria quarta", "", "støeda", "szerda"}
, {"štvrtok" , "ètvrtek", "Thursday", "feria quinta", "", "ètvrtek", "csütörtök"}
, {"piatok" , "pátek", "Friday", "feria sexta", "", "pátek", "péntek"}
, {"sobota" , "sobota", "Saturday", "sábbatum", "", "sobota", "szombat"}
, {"neznámy" , "neznámı", "unknown", "???", "", "neznámı", "ismeretlen"}
};

#define		nazov_dna(a)	nazov_dna_jazyk[a][_global_jazyk]

/* names of the days in week, starting with Sunday (lowercase without special characters - plain ASCII (0--128) only) */
const char *nazov_dna_asci_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{ {"nedela", "nedele", "Sunday", "Dominica", "", "nedele", "vasarnap"}
, {"pondelok" , "pondeli", "Monday", "Feria secunda", "", "pondeli", "hetfo"}
, {"utorok" , "utery", "Tuesday", "Feria tertia", "", "utery", "kedd"}
, {"streda" , "streda", "Wednesday", "Feria quarta", "", "streda", "szerda"}
, {"stvrtok" , "ctvrtek", "Thursday", "Feria quinta", "", "ctvrtek", "csutortok"}
, {"piatok" , "patek", "Friday", "Feria sexta", "", "patek", "pentek"}
, {"sobota" , "sobota", "Saturday", "Sabbatum", "", "sobota", "szombat"}
, {"neznamy" , "neznamy", "unknown", "???", "", "neznamy", "ismeretlen"}
};

#define		nazov_dna_asci(a)	nazov_dna_asci_jazyk[a][_global_jazyk]

/* names of the days in week, starting with Sunday (sentence case) */
const char *nazov_Dna_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{ {"Nede¾a", "Nedìle", "Sunday", "Domínica", "", "Nedìle", "Vasárnap"}
, {"Pondelok" , "Pondìlí", "Monday", "Feria secúnda", "", "Pondìlí", "Hétfõ"}
, {"Utorok" , "Úterı", "Tuesday", "Feria tértia", "", "Úterı", "Kedd"}
, {"Streda" , "Støeda", "Wednesday", "Feria quarta", "", "Støeda", "Szerda"}
, {"Štvrtok" , "Ètvrtek", "Thursday", "Feria quinta", "", "Ètvrtek", "Csütörtök"}
, {"Piatok" , "Pátek", "Friday", "Feria sexta", "", "Pátek", "Péntek"}
, {"Sobota" , "Sobota", "Saturday", "Sábbatum", "", "Sobota", "Szombat"}
, {"Neznámy" , "Neznámı", "unknown", "???", "", "Neznámı", "Ismeretlen"}
};

#define		nazov_Dna(a)	nazov_Dna_jazyk[a][_global_jazyk]

/* names of the days in week, starting with Sunday (uppercase) */
const char *nazov_DNA_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{ {"NEDE¼A", "NEDÌLE", "SUNDAY", "DOMÍNICA", "", "NEDÌLE", "VASÁRNAP"}
, {"PONDELOK" , "PONDÌLÍ", "MONDAY", "FERIA SECÚNDA", "", "PONDÌLÍ", "HÉTFÕ"}
, {"UTOROK" , "ÚTERİ", "TUESDAY", "FERIA TÉRTIA", "", "ÚTERİ", "KEDD"}
, {"STREDA" , "STØEDA", "WEDNESDAY", "FERIA QUARTA", "", "STØEDA", "SZERDA"}
, {"ŠTVRTOK" , "ÈTVRTEK", "THURSDAY", "FERIA QUINTA", "", "ÈTVRTEK", "CSÜTÖRTÖK"}
, {"PIATOK" , "PÁTEK", "FRIDAY", "FERIA SEXTA", "", "PÁTEK", "PÉNTEK"}
, {"SOBOTA" , "SOBOTA", "SATURDAY", "SÁBBATUM", "", "SOBOTA", "SZOMBAT"}
, {"NEZNÁMY" , "NEZNÁMİ", "UNKNOWN", "???", "", "NEZNÁMİ", "ISMERETLEN"}
};

#define		nazov_DNA(a)	nazov_DNA_jazyk[a][_global_jazyk]

/* two/three-letter abbreviations of the names of the days in week, starting with Sunday (sentence case) */
const char *nazov_Dn_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{ {"Ne" , "Ne", "Sun", "Do", "", "Ne", "V"}
, {"Po" , "Po", "Mon", "F2", "", "Po", "H"}
, {"Ut" , "Út", "Tue", "F3", "", "Út", "K"}
, {"St" , "St", "Wed", "F4", "", "St", "Sze"}
, {"Št" , "Èt", "Thu", "F5", "", "Èt", "Cs"}
, {"Pi" , "Pá", "Fri", "F6", "", "Pá", "P"}
, {"So" , "So", "Sat", "Sá", "", "So", "Szo"}
, {"??" , "??", "???", "", "", "??", "??"}
};

#define		nazov_Dn(a)	nazov_Dn_jazyk[a][_global_jazyk]

/* two/three-letter abbreviations of the names of the days in week, starting with Sunday used for anchors (uppercase, no need to translate; based on Slovak) */
/* 2006-08-01: pouíva sa pre HTML kotvy, ktoré nezávisia od jazykovej mutácie */
const char *nazov_DN_asci[] =
{"NE", "PO", "UT", "STR", "STV", "PI", "SO", "??"};

/* two/three-letter abbreviations of the names of the days in week, starting with Sunday used for debug info (lowercase, no need to translate; based on Slovak) */
const char *nazov_dn_asci[] =
{"ne", "po", "ut", "str", "stv", "pi", "so", "??"};

/* the names of the months (lowecase) / nazov_mesiaca: string pre nazov dna; suhlasi s struct tm.tm_mon;
 * Month (0--11) */
const char *nazov_mesiaca_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{ {"január", "leden", "January", "ianuárius", "", "leden", "január"}
, {"február" , "únor", "February", "feb", "", "únor", "február"}
, {"marec" , "bøezen", "March", "mar", "", "bøezen", "március"}
, {"apríl" , "duben", "April", "apr", "", "duben", "április"}
, {"máj" , "kvìten", "May", "mai", "", "kvìten", "május"}
, {"jún" , "èerven", "June", "iun", "", "èerven", "június"}
, {"júl" , "èervenec", "July", "iul", "", "èervenec", "július"}
, {"august" , "srpen", "August", "aug", "", "srpen", "augusztus"}
, {"september" , "záøí", "September", "sep", "", "záøí", "szeptember"}
, {"október" , "øíjen", "October", "oct", "", "øíjen", "október"}
, {"november" , "listopad", "November", "nov", "", "listopad", "november"}
, {"december" , "prosinec", "December", "dec", "", "prosinec", "december"}
, {"neznámy" , "neznámı", "unknown", "___", "", "neznámı", "ismeretlen"}
};

#define		nazov_mesiaca(a)	nazov_mesiaca_jazyk[a][_global_jazyk]

/* the names of the months (lowecase without special characters, plain ASCII 0--128) */
const char *nazov_mesiaca_asci_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{ {"januar", "leden", "January", "Ianuarius", "", "leden", "januar"}
, {"februar" , "unor", "February", "Februarius", "", "unor", "februar"}
, {"marec" , "brezen", "March", "Martius", "", "brezen", "marcius"}
, {"april" , "duben", "April", "Aprilis", "", "duben", "aprilis"}
, {"maj" , "kveten", "May", "Maius", "", "kveten", "majus"}
, {"jun" , "cerven", "June", "Iunius", "", "cerven", "junius"}
, {"jul" , "cervenec", "July", "Iulius", "", "cervenec", "julius"}
, {"august" , "srpen", "August", "Augustus", "", "srpen", "augusztus"}
, {"september" , "zari", "September", "September", "", "zari", "szeptember"}
, {"oktober" , "rijen", "October", "October", "", "rijen", "oktober"}
, {"november" , "listopad", "November", "November", "", "listopad", "november"}
, {"december" , "prosinec", "December", "December", "", "prosinec", "december"}
, {"neznamy" , "neznamy", "unknown", "___", "", "neznamy", "ismeretlen"}
};

#define		nazov_mesiaca_asci(a)	nazov_mesiaca_asci_jazyk[a][_global_jazyk]

/* the names of the months (sentence case) */
const char *nazov_Mesiaca_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{ {"Január", "Leden", "January", "Ianuárius", "", "Leden", "Január"}
, {"Február" , "Únor", "February", "Februárius", "", "Únor", "Február"}
, {"Marec", "Bøezen", "March", "Mártius", "", "Bøezen", "Március"}
, {"Apríl" , "Duben", "April", "Aprílis", "", "Duben", "Április"}
, {"Máj" , "Kvìten", "May", "Maius", "", "Kvìten", "Május"}
, {"Jún" , "Èerven", "June", "Iúnius", "", "Èerven", "Június"}
, {"Júl" , "Èervenec", "July", "Iúlius", "", "Èervenec", "Július"}
, {"August" , "Srpen", "August", "Augústus", "", "Srpen", "Augusztus"}
, {"September" , "Záøí", "September", "Septémber", "", "Záøí", "Szeptember"}
, {"Október" , "Øíjen", "October", "Octóber", "", "Øíjen", "Október"}
, {"November" , "Listopad", "November", "Novémber", "", "Listopad", "November"}
, {"December" , "Prosinec", "December", "Decémber", "", "Prosinec", "December"}
, {"Neznámy" , "Neznámı", "unknown", "???", "", "Neznámı", "Ismeretlen"}
};

#define		nazov_Mesiaca(a)	nazov_Mesiaca_jazyk[a][_global_jazyk]

/* the names of the months (uppercase) */
const char *nazov_MESIACA_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{ {"JANUÁR", "LEDEN", "JANUARY", "IANUÁRIUS", "", "LEDEN", "JANUÁR"}
, {"FEBRUÁR" , "ÚNOR", "FEBRUARY", "FEBRUÁRIUS", "", "ÚNOR", "FEBRUÁR"}
, {"MAREC", "BØEZEN", "MARCH", "MÁRTIUS", "", "BØEZEN", "MÁRCIUS"}
, {"APRÍL" , "DUBEN", "APRIL", "APRÍLIS", "", "DUBEN", "ÁPRILIS"}
, {"MÁJ" , "KVÌTEN", "MAY", "MAIUS", "", "KVÌTEN", "MÁJUS"}
, {"JÚN" , "ÈERVEN", "JUNE", "IÚNIUS", "", "ÈERVEN", "JÚNIUS"}
, {"JÚL" , "ÈERVENEC", "JULY", "IÚLIUS", "", "ÈERVENEC", "JÚLIUS"}
, {"AUGUST" , "SRPEN", "AUGUST", "AUGÚSTUS", "", "SRPEN", "AUGUSZTUS"}
, {"SEPTEMBER" , "ZÁØÍ", "SEPTEMBER", "SEPTÉMBER", "", "ZÁØÍ", "SZEPTEMBER"}
, {"OKTÓBER" , "ØÍJEN", "OCTOBER", "OCTÓBER", "", "ØÍJEN", "OKTÓBER"}
, {"NOVEMBER" , "LISTOPAD", "NOVEMBER", "NOVÉMBER", "", "LISTOPAD", "NOVEMBER"}
, {"DECEMBER" , "PROSINEC", "DECEMBER", "DECÉMBER", "", "PROSINEC", "DECEMBER"}
, {"NEZNÁMY" , "NEZNÁMİ", "UNKNOWN", "???", "", "NEZNÁMİ", "ISMERETLEN"}
};

#define		nazov_MESIACA(a)	nazov_MESIACA_jazyk[a][_global_jazyk]

/* the names of the months (lowercase) in genitive grammatically 2.th declination?; in English: "IN that month" or "OF that month" /  genitív == 2. pád, koho/èoho */
/* usage: when generated string for date, e.g. en: "1st January 2000", sk: "1. januára 2000" */
/* 2007-03-20: pridanı genitív názvu mesiaca kvôli latinèine */
const char *nazov_mesiaca_gen_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{ {"januára", "ledna", "January", "ianuárii", "", "ledna", "január"}
, {"februára" , "února", "February", "februárii", "", "února", "február"}
, {"marca" , "bøezna", "March", "mártii", "", "bøezna", "március"}
, {"apríla" , "dubna", "April", "aprílis", "", "dubna", "április"}
, {"mája" , "kvìtna", "May", "maii", "", "kvìtna", "május"}
, {"júna" , "èervna", "June", "iúnii", "", "èervna", "június"}
, {"júla" , "èervence", "July", "iúlii", "", "èervence", "július"}
, {"augusta" , "srpna", "August", "augústi", "", "srpna", "augusztus"}
, {"septembra" , "záøí", "September", "septémbris", "", "záøí", "szeptember"}
, {"októbra" , "øíjna", "October", "octóbris", "", "øíjna", "október"}
, {"novembra" , "listopadu", "November", "novémbris", "", "listopadu", "november"}
, {"decembra" , "prosince", "December", "decémbris", "", "prosince", "december"}
, {"neznámeho" , "neznámého", "unknown", "___", "", "neznámého", "ismeretlen"}
};

#define		nazov_mesiaca_gen(a)	nazov_mesiaca_gen_jazyk[a][_global_jazyk]

/* 2007-03-20: pridanı genitív názvu mesiaca kvôli latinèine */
const char *nazov_Mesiaca_gen_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{ {"Januára", "Ledna", "January", "Ianuárii", "", "Ledna", "Január"}
, {"Februára" , "Února", "February", "Februárii", "", "Února", "Február"}
, {"Marca" , "Bøezna", "March", "Mártii", "", "Bøezna", "Március"}
, {"Apríla" , "Dubna", "April", "Aprílis", "", "Dubna", "Április"}
, {"Mája" , "Kvìtna", "May", "Maii", "", "Kvìtna", "Május"}
, {"Júna" , "Èervna", "June", "Iúnii", "", "Èervna", "Június"}
, {"Júla" , "Èervence", "July", "Iúlii", "", "Èervence", "Július"}
, {"Augusta" , "Srpna", "August", "Augústi", "", "Srpna", "Augusztus"}
, {"Septembra" , "Záøí", "September", "Septémbris", "", "Záøí", "Szeptember"}
, {"Októbra" , "Øíjna", "October", "Octóbris", "", "Øíjna", "Október"}
, {"Novembra" , "Listopadu", "November", "Novémbris", "", "Listopadu", "November"}
, {"Decembra" , "Prosince", "December", "Decémbris", "", "Prosince", "December"}
, {"Neznámeho" , "Neznámého", "Unknown", "___", "", "Neznámého", "Ismeretlen"}
};

#define		nazov_Mesiaca_gen(a)	nazov_Mesiaca_gen_jazyk[a][_global_jazyk]

/* three-letter abbreviations of the names of the months used for anchors (uppercase, no need to translate; based on Slovak) */
const char *nazov_MES[] =
{"JAN", "FEB", "MAR", "APR", "MAJ", "JUN", "JUL", "AUG", "SEP", "OKT", "NOV", "DEC", "___"};

/* three-letter abbreviations of the names of the months used for anchors (lowercase, no need to translate; based on Slovak) */
const char *nazov_mes[] =
{"jan", "feb", "mar", "apr", "maj", "jun", "jul", "aug", "sep", "okt", "nov", "dec", "___"};

/* ordinal numbers for first few Sundays (sentence case) - used for special occasions currently only in Slovak; no need to change */
/* 2008-12-20: pridanı reazec pre poradové èíslo - pouíva sa v init_global_string() pre nedele niektorıch období [zatia¾ iba v slovenèine] */
const char *poradie_Slovom_jazyk[POCET_TYZDNOV + 1][POCET_JAZYKOV + 1] = 
{ {"Prvá", "První", "", "", "", "První", "1."}
, {"Druhá" , "Druhá", "", "", "", "Druhá", "2."}
, {"Tretia" , "Tøetí", "", "", "", "Tøetí", "3."}
, {"Štvrtá" , "Ètrvtá", "", "", "", "Ètrvtá", "4."}
, {"Piata" , "Pátá", "", "", "", "Pátá", "5."}
, {"Šiesta" , "Šestá", "", "", "", "Šestá", "6."}
, {"Siedma" , "Sedmá", "", "", "", "Sedmá", "7."}
, {"Ôsma" , "Osmá", "", "", "", "Osmá", "8."}
, {"Deviata" , "Devátá", "", "", "", "Devátá", "9."}
, {"Desiata" , "Desátá", "", "", "", "Desátá", "10."}
, {"11. ", "11", "11", "11", "11", "11", "11."}
, {"12. ", "12", "12", "12", "12", "12", "12."}
, {"13. ", "13", "13", "13", "13", "13", "13."}
, {"14. ", "14", "14", "14", "14", "14", "14."}
, {"15. ", "15", "15", "15", "15", "15", "15."}
, {"16. ", "16", "16", "16", "16", "16", "16."}
, {"17. ", "17", "17", "17", "17", "17", "17."}
, {"18. ", "18", "18", "18", "18", "18", "18."}
, {"19. ", "19", "19", "19", "19", "19", "19."}
, {"20. ", "20", "20", "20", "20", "20", "20."}
, {"21. ", "21", "21", "21", "21", "21", "21."}
, {"22. ", "22", "22", "22", "22", "22", "22."}
, {"23. ", "23", "23", "23", "23", "23", "23."}
, {"24. ", "24", "24", "24", "24", "24", "24."}
, {"25. ", "25", "25", "25", "25", "25", "25."}
, {"26. ", "26", "26", "26", "26", "26", "26."}
, {"27. ", "27", "27", "27", "27", "27", "27."}
, {"28. ", "28", "28", "28", "28", "28", "28."}
, {"29. ", "29", "29", "29", "29", "29", "29."}
, {"30. ", "30", "30", "30", "30", "30", "30."}
, {"31. ", "31", "31", "31", "31", "31", "31."}
, {"32. ", "32", "32", "32", "32", "32", "32."}
, {"33. ", "33", "33", "33", "33", "33", "33."}
, {"34. ", "34", "34", "34", "34", "34", "34."}
};

/* the same as "poradie_Slovom_jazyk" ordinal numbers for first few Sundays (uppercase) - used for special occasions currently only in Slovak; no need to change */
const char *poradie_SLOVOM_jazyk[POCET_TYZDNOV + 1][POCET_JAZYKOV + 1] = 
{ {"PRVÁ", "PRVNÍ", "", "", "", "PRVNÍ", "1."}
, {"DRUHÁ" , "DRUHÁ", "", "", "", "DRUHÁ", "2."}
, {"TRETIA" , "TØETÍ", "", "", "", "TØETÍ", "3."}
, {"ŠTVRTÁ" , "ÈTRVTÁ", "", "", "", "ÈTRVTÁ", "4."}
, {"PIATA" , "PÁTÁ", "", "", "", "PÁTÁ", "5."}
, {"ŠIESTA" , "ŠESTÁ", "", "", "", "ŠESTÁ", "6."}
, {"SIEDMA" , "SEDMÁ", "", "", "", "SEDMÁ", "7."}
, {"OSMA" , "OSMÁ", "", "", "", "OSMÁ", "8."}
, {"DEVIATA" , "DEVÁTÁ", "", "", "", "DEVÁTÁ", "9."}
, {"DESIATA" , "DESÁTÁ", "", "", "", "DESÁTÁ", "10."}
, {"11. ", "11", "11", "11", "11", "11", "11."}
, {"12. ", "12", "12", "12", "12", "12", "12."}
, {"13. ", "13", "13", "13", "13", "13", "13."}
, {"14. ", "14", "14", "14", "14", "14", "14."}
, {"15. ", "15", "15", "15", "15", "15", "15."}
, {"16. ", "16", "16", "16", "16", "16", "16."}
, {"17. ", "17", "17", "17", "17", "17", "17."}
, {"18. ", "18", "18", "18", "18", "18", "18."}
, {"19. ", "19", "19", "19", "19", "19", "19."}
, {"20. ", "20", "20", "20", "20", "20", "20."}
, {"21. ", "21", "21", "21", "21", "21", "21."}
, {"22. ", "22", "22", "22", "22", "22", "22."}
, {"23. ", "23", "23", "23", "23", "23", "23."}
, {"24. ", "24", "24", "24", "24", "24", "24."}
, {"25. ", "25", "25", "25", "25", "25", "25."}
, {"26. ", "26", "26", "26", "26", "26", "26."}
, {"27. ", "27", "27", "27", "27", "27", "27."}
, {"28. ", "28", "28", "28", "28", "28", "28."}
, {"29. ", "29", "29", "29", "29", "29", "29."}
, {"30. ", "30", "30", "30", "30", "30", "30."}
, {"31. ", "31", "31", "31", "31", "31", "31."}
, {"32. ", "32", "32", "32", "32", "32", "32."}
, {"33. ", "33", "33", "33", "33", "33", "33."}
, {"34. ", "34", "34", "34", "34", "34", "34."}
};

/* the names of languages */
/* 2006-07-11: Pridané kvôli jazykovım mutáciám */
const char *nazov_jazyka[POCET_JAZYKOV + 1] =
{"slovenèina", "èeština", "English", "lingua latina", "(neurèenı)", "èeština (dominikáni)", "magyarul"};

/* language codes; internal usage for HTTP requests */
const char *skratka_jazyka[POCET_JAZYKOV + 1] =
{"sk", "cz", "en", "la", "??", "c2", "hu"};

/* language codes; internal usage for include directories (postfix of directory/folder name); postfix MUST NOT contain slash/backslash */
/* 2006-07-13 a 17: Pridané kvôli jazykovım mutáciám - postfix pre include adresár */
const char *postfix_jazyka[POCET_JAZYKOV + 1] =
{"", "cz", "en", "la", "", "czop", "hu"};
/* Poznámka: Postfix nesmie obsahova na zaèiatku odde¾ovaè (slash resp. backslash); musí sa jedna o podadresár pod include */

/* filename of CSS file; the number of CSS does not directly correspond to the number of languages */
/* 2006-08-08: Pridané kvôli rôznym css */
const char *nazov_css[POCET_CSS + 1] =
{"(css neurèené)", "breviar.css", "breviar_kbd.css", "ebreviar_cz.css", "ebreviar_cz_op.css"};

const char *skratka_css[POCET_CSS + 1] =
{"__", "def", "kbd", "cz", "czop"};

/* strings of buttons - abbreviations of prayer names */
/* 2006-10-11: definovanie reazcov aj pre invitatórium a kompletórium */
const char *html_button_invitatorium[] = {"Inv.", "Inv.", "Inv.", "Inv.", "", "Inv.", "Inv."};
#ifndef HTML_BUTTON_INVITATORIUM
#define HTML_BUTTON_INVITATORIUM	html_button_invitatorium[_global_jazyk]
#endif

const char *html_button_kompletorium[] = {"Kompl.", "Kompl.", "Compl.", "Compl.", "", "Kompl.", "Kompl."};
#ifndef HTML_BUTTON_KOMPLETORIUM
#define HTML_BUTTON_KOMPLETORIUM	html_button_kompletorium[_global_jazyk]
#endif

/* definície HTML prvkov upravené a presunuté z mydefs.h, 2006-08-01 */
const char *html_button_ranne_chvaly[] = {"Ranné chvály", "Ranní chvály", "Morning prayer", "Laudes", "", "Ranní chvály", "Reggeli dicséret"};
#ifndef HTML_BUTTON_RANNE_CHVALY
#define HTML_BUTTON_RANNE_CHVALY	html_button_ranne_chvaly[_global_jazyk]
#endif

const char *html_button_predpoludnim[] = {"9h", "9h", "9h", "Tertia", "", "Tercie", "Tertia"};
#ifndef HTML_BUTTON_PREDPOLUDNIM
#define HTML_BUTTON_PREDPOLUDNIM	html_button_predpoludnim[_global_jazyk]
#endif

const char *html_button_napoludnie[] = {"12h", "12h", "12h", "Sexta", "", "Sexta", "Sexta"};
#ifndef HTML_BUTTON_NAPOLUDNIE
#define HTML_BUTTON_NAPOLUDNIE	html_button_napoludnie[_global_jazyk]
#endif

const char *html_button_popoludni[] = {"15h", "15h", "15h", "Nona", "", "Nona", "Nona"};
#ifndef HTML_BUTTON_POPOLUDNI
#define HTML_BUTTON_POPOLUDNI	html_button_popoludni[_global_jazyk]
#endif

const char *html_button_vespery[] = {"Vešpery", "Nešpory", "Vesperae", "Vésperae", "", "Veèerní chvály", "Esti dicséret"};
#ifndef HTML_BUTTON_VESPERY
#define HTML_BUTTON_VESPERY	html_button_vespery[_global_jazyk]
#endif

const char *html_button_posv_citanie[] = {"Posv. èít.", "Ètení", "Reading", "Off. lect.", "", "Ètení", "Olvasmányos imaóra"};
#ifndef HTML_BUTTON_POSV_CITANIE
#define HTML_BUTTON_POSV_CITANIE	html_button_posv_citanie[_global_jazyk]
#endif

/* special button: Details... */
const char *html_button_detaily[] = {"Detaily...", "Podrobnìji...", "Details...", "Optiónes...", "", "Podrobnìji...", "Részletek..."};
#ifndef HTML_BUTTON_DETAILY
#define HTML_BUTTON_DETAILY	html_button_detaily[_global_jazyk]
#endif

/* special button: Show prayer */
const char *html_button_det_show[] = {"Zobraz modlitbu", "Uka modlitbu", "Show prayer", "xxx", "", "Uka modlitbu", "Mutasd az imát"};
#ifndef HTML_BUTTON_DET_SHOW
#define HTML_BUTTON_DET_SHOW	html_button_det_show[_global_jazyk]
#endif

/* special button: Defaults */
const char *html_button_det_defaults[] = {"Pôvodné hodnoty", "Pùvodní hodnoty", "Defaults", "___", "", "Pùvodní hodnoty", "Alapértelmezett"};
#ifndef HTML_BUTTON_DET_DEFAULTS
#define HTML_BUTTON_DET_DEFAULTS	html_button_det_defaults[_global_jazyk]
#endif

/* special button (today): Show */
const char *html_button_dnes_show[] = {"Zobraz", "Uka", "Show", "___", "", "Uka", "Mutasd"};
#ifndef HTML_BUTTON_DNES_SHOW
#define HTML_BUTTON_DNES_SHOW	html_button_dnes_show[_global_jazyk]
#endif

/* special button (today): Defaults (clear form) */
const char *html_button_dnes_defaults[] = {"Vyèisti", "Vyèisti", "Clear", "???", "", "Vyèisti", "Töröl"};
#ifndef HTML_BUTTON_DNES_DEFAULTS
#define HTML_BUTTON_DNES_DEFAULTS	html_button_dnes_defaults[_global_jazyk]
#endif

/* special button (today): Morning prayer with canticum of Zekariah */
/* doplnené, 2007-09-13 */
const char *html_button_ranne_chvaly_benediktus[] = {"Ranné chvály + Benediktus", "Ranní chvály + Zach. kantikum", "Morning prayer with Benedictus", "Laudes + Benedictus", "", "Ranní chvály + Zach. kantikum", "Reggeli dicséret Benedictusszal"};
#ifndef HTML_BUTTON_RANNE_CHVALY_BENEDIKTUS
#define HTML_BUTTON_RANNE_CHVALY_BENEDIKTUS	html_button_ranne_chvaly_benediktus[_global_jazyk]
#endif

/* special button (today): Evening prayer with canticum of Mary */
const char *html_button_vespery_magnifikat[] = {"Vešpery + Magnifikat", "Nešpory + Mariino kant.", "Vesperae + Magnificat", "Vesperae + Magnificat", "", "Veèerní chvály + kant. Panny Marie", "Esti dicséret Magnificattal"};
#ifndef HTML_BUTTON_VESPERY_MAGNIFIKAT
#define HTML_BUTTON_VESPERY_MAGNIFIKAT	html_button_vespery_magnifikat[_global_jazyk]
#endif

/* special button (today): Completory prayer with canticum of Simeon; is currently used only in Slovak */
/* doplnené, 2008-12-20; nepouíva sa pre ostatné jazyky */
const char *html_button_kompletorium_nunkdim[] = {"Kompletórium + Nunk dimittis", "xxx", "xxx", "xxx", "", "xxx", "hu_xxx"};
#ifndef HTML_BUTTON_KOMPLETORIUM_NUNKDIM
#define HTML_BUTTON_KOMPLETORIUM_NUNKDIM	html_button_kompletorium_nunkdim[_global_jazyk]
#endif

/* navigation buttons/texts: previous, next, today */
const char *html_button_predchadzajuci_[] = {"Predchádzajúci", "Pøedchozí", "Previous", "Praecedénte", "", "Pøedchozí", "Elõzõ"};
const char *html_button_nasledujuci_[] = {"Nasledujúci", "Následující", "Next", "Successívo", "", "Následující", "Következõ"};
const char *html_button_dnes[] = {"Dnes", "Dnes", "Today", "Hódie", "", "Dnes", "Ma"};

/* basic words: day, month, year */
const char *html_text_den[] = {"deò", "den", "day", "die", "", "den", "nap"};
const char *html_text_mesiac[] = {"mesiac", "mìsíc", "month", "(mesiac)", "", "mìsíc", "hó"};
const char *html_text_rok[] = {"rok", "rok", "year", "anno", "", "rok", "év"};
const char *html_text_Rok[] = {"Rok", "Rok", "Year", "Anno", "", "Rok", "Év"};
/* in the following: you MUST keep all %d, %c, %s etc. variables - these are replaced by numbers, characters, strings, etc. respectively */
const char *html_text_Rok_x[] = {"Rok %d", "Rok %d", "Year %d", "Anno %d", "%d", "Rok %d", "Év %d"};

const char *html_text_zoznam_mesiacov[] = {"zoznam mesiacov", "seznam mìsícù", "list of months", "", "", "seznam mìsícù", "hónapok listája"};

const char *html_text_modlitba[] = {"modlitba", "modlitba", "prayer", "ora", "", "modlitba", "imádság"};
const char *html_text_modlitby_pre_den[] = {"modlitby pre deò", "modlitby pro den", "prayers for date", "", "", "modlitby pro den", "hu_prayers for date"};
const char *html_text_alebo_pre[] = {"alebo pre", "anebo pro", "or for", "vel per", "", "anebo pro", "hu_or for"};
const char *html_text_dnesok[] = {"dnešok", "dnešní den", "today", "hódie", "", "dnešní den", "ma"};

const char *html_text_Vysvetlivky[] = {"Vysvetlivky", "Vysvìtlivky", "Legenda", "Legenda", "", "Vysvìtlivky", "Jelmagyarázat"};

const char *html_text_dalsie_moznosti[] = {"Vyberte si ïalšie monosti ", "Další monosti vıbìru ", "Choose from above (buttons) or from the following options: ", "", "", "Další monosti vıbìru", "Válassz egy imaórát vagy az alábbi lehetõségek közül"};
const char *html_text_prik_sviatky_atd[] = {"prikázané sviatky a slávnosti Pána v roku ", "zasvìcené svátky a slavnosti Pánì v roce ", "obligatory celebrations in year ", "", "", "zasvìcené svátky a slavnosti Pánì v roce", "kötelezõ ünnepek"};
const char *html_text_lit_kalendar[] = {"liturgickı kalendár pre", "liturgickı kalendáø pro", "liturgical calendar for", "", "", "liturgickı kalendáø pro", "liturgikus naptár"};
const char *html_text_roku[] = {"roku", "roku", "of year", "", "", "roku", ""};
const char *html_text_tabulka_pohyblive_od[] = {"tabu¾ka dátumov pohyblivıch slávení od roku", "tabulka s daty promìnnıch slavností od roku", "table with dates of movable celebrations from year", "", "", "tabulka s daty promìnnıch slavností od roku", "a változó ünnepek listája a következõ években"};
const char *html_text_do_roku[] = {"do roku", "po rok", "till year", "", "", "po rok", ""};
const char *html_text_zobrazit_linky[] = {"zobrazi tabu¾ku vrátane hypertextovıch odkazov na jednotlivé dni", "zobrazit tabulku s hypertextovımi odkazy pro jednotlivé dny", "display the table including hypertext links to each date", "", "", "zobrazit tabulku s hypertextovımi odkazy pro jednotlivé dny", "minden felirat mutasson a megfelelõ oldalunkra"};
const char *html_text_pre_cezrocne_obd[] = {"pre cezroèné obdobie", "pro mezidobí", "for ...", "", "", "pro dobu bìhem roku", ""};
const char *html_text_tyzden_zaltara[] = {". tıdeò altára", ". tıden altáøe", "week of Psaltary", "hebdomada", "", ". tıden altáøe", ". zsoltáros hét"};
const char *html_text_tyzden[] = {". tıdeò", ". tıden", "week", "hebdomada", "", ". tıden", "hét"};
const char *html_text_v_tyzdni_zaltara[] = {". tıdni altára", ". tıdnu altáøe", "week of Psaltary", "hebdomada", "", ". tıdnu altáøe", ". zsoltáros hét"};
/* in the following: you MUST keep all HTML elements, e.g. <a href...>, <br> etc. */
const char *html_text_dnes_je_atd[] = 
{"Dnes je %d. deò v roku%s, <a href=\"%s%s\">juliánsky dátum</a> JD = %ld%s.\n<br>\n",
 "Dnes je %d. den v roku%s, <a href=\"%s%s\">juliánské datum</a> JD = %ld%s.\n<br>\n",
 "Today is %d. day in the year%s, <a href=\"%s%s\">Julian date</a> JD = %ld%s.\n<br>\n",
 "Hodie est %d. die anno %s, <a href=\"%s%s\">Iulianus datum</a> JD = %ld%s.\n<br>\n",
 "%d/%s<a href=\"%s%s\">JD</a> = %ld%s.\n<br>\n",
 "Dnes je %d. den v roku%s, <a href=\"%s%s\">juliánské datum</a> JD = %ld%s.\n<br>\n",
 "Ma %s %d. napja van, <a href=\"%s%s\">Julián naptár</a> JD = %ld%s.\n<br>\n"};

const char *html_text_zakladne_info[] = {"Základné informácie", "Základní informace", "Basic info", "__info__", "", "Základní informace", "Alap információ"};
const char *html_text_je[] = {"je", "je", "is", "est", "", "je", "van"};
const char *html_text_nie_je[] = {"nie je", "není", "is not", "non est", "", "není", "nincs"};
const char *html_text_prestupny[] = {"prestupnı", "pøestupnı", "...", "...", "", "pøestupnı", "összekötés"};
const char *html_text_datumy_pohyblivych_slaveni[] = {"Dátumy pohyblivıch slávení", "Dáta promìnlivıch slávení", "Dates for movable celebrations", "", "", "Data promìnlivıch slavení", "A mozgó ünnepek dátumai"};

const char *html_text_den_v_roku[] = {"deò v roku", "den v roce", "day of the year", "", "", "den v roce", "az év napja"};
const char *html_text_zacina[] = {"zaèína", "zaèíná", "starts", "", "", "zaèíná", "kezdõdik"};
const char *html_text_liturgicky_rok[] = {"liturgickı rok", "liturgickı rok", "liturgical year", "", "", "liturgickı rok", "liturgikus év"};

const char *html_text_pohyblive1[] = {
	"<td align=center>Rok<br>Pána</td>\n",
	"<td align=center>Léto<br>Pánì</td>\n", 
	"<td align=center>Anno<br>Domini</td>\n",
	"<td align=center>Anno<br>Domini</td>\n",
	"",
	"<td align=center>Léto<br>Pánì</td>\n",
	"hu_<td align=center>Anno<br>Domini</td>\n"
};

const char *html_text_pohyblive2[] = {
	"<td align=center>Nede¾ná<br>litera</td>\n",
	"<td align=center>Nedìlní<br>písmeno</td>\n", 
	"<td align=center>Sunday<br>Letter</td>\n",
	"<td align=center>Let.<br>Dom.</td>\n",
	"",
	"<td align=center>Nedìlní<br>písmeno</td>\n",
	"hu_<td align=center>Sunday<br>Letter</td>\n"
};

const char *html_text_pohyblive3[] = {
	"<td align=center>Nede¾nı<br>cyklus</td>\n",
	"<td align=center>Nedìlní<br>cyklus</td>\n", 
	"<td align=center>Sunday<br>cycle</td>\n",
	"<td align=center>Cycl.<br>Dom.</td>\n",
	"",
	"<td align=center>Nedìlní<br>cyklus</td>\n",
	"hu_<td align=center>Sunday<br>cycle</td>\n"
};

const char *html_text_pohyblive4[] = {
	"<td align=center>Krst Krista<br>Pána</td>\n",
	"<td align=center>Køest Krista<br>Pánì</td>\n", 
	"<td align=center>Bapt. of<br>the Lord</td>\n",
	"<td align=center>Bapt.<br>Domini</td>\n",
	"",
	"<td align=center>Køest Krista<br>Pánì</td>\n",
	"hu_<td align=center>Bapt.<br>Domini</td>\n"
};

const char *html_text_pohyblive5[] = {
	"<td align=center><a href=\"#explain\">OCR<br>pred<br>PO</a></td>\n",
	"<td align=center><a href=\"#explain\">OCR<br>pøed<br>postem</a></td>\n", 
	"<td align=center>...</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center><a href=\"#explain\">OCR<br>pøed<br>postem</a></td>\n",
	"hu_<td align=center>PA before Fast</td>\n"
};

const char *html_text_pohyblive6[] = {
	"<td align=center>Popolcová<br>streda</td>\n",
	"<td align=center>Popeleèní<br>støeda</td>\n", 
	"<td align=center>...</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center>Popeleèní<br>støeda</td>\n",
	"hu_<td align=center>...</td>\n"
};

const char *html_text_pohyblive7[] = {
	"<td align=center>Ve¾ká<br>noc</td>\n",
	"<td align=center>Veliko-<br>noce</td>\n", 
	"<td align=center>Easter</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center>Veliko-<br>noce</td>\n",
	"hu_<td align=center>...</td>\n"
};

const char *html_text_pohyblive8[] = {
	"<td align=center>Nanebo-<br>vstúpenie<br>Pána</td>\n",
	"<td align=center>Nanebe-<br>vstoupení<br>Pánì</td>\n", 
	"<td align=center>...</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center>Nanebe-<br>vstoupení<br>Pánì</td>\n",
	"hu_<td align=center>...</td>\n"
};

const char *html_text_pohyblive9[] = {
	"<td align=center>Zoslanie<br>Ducha<br>Svätého</td>\n",
	"<td align=center>Seslání<br>Ducha<br>Svatého</td>\n", 
	"<td align=center>...</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center>Seslání<br>Ducha<br>Svatého</td>\n",
	"hu_<td align=center>...</td>\n"
};

const char *html_text_pohyblive10[] = {
	"<td align=center><a href=\"#explain\">OCR<br>po<br>VN</a></td>\n",
	"<td align=center><a href=\"#explain\">OCR<br>po<br>VN</a></td>\n", 
	"<td align=center>...</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center><a href=\"#explain\">OCR<br>po<br>VN</a></td>\n",
	"hu_<td align=center>...</td>\n"
};

const char *html_text_pohyblive11[] = {
	"<td align=center>Prvá<br>adventná<br>nede¾a</td>\n",
	"<td align=center>První<br>adventní<br>nedìle</td>\n", 
	"<td align=center>...</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center>První<br>adventní<br>nedìle</td>\n",
	"hu_<td align=center>...</td>\n"
};

const char *html_text_pohyblive12[] = {
	"<td align=center>Nede¾a Svätej<br>rodiny</td></tr>\n",
	"<td align=center>Nedìle Svaté<br>rodiny</td></tr>\n", 
	"<td align=center>...</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center>Nedìle Svaté<br>rodiny</td></tr>\n",
	"hu_<td align=center>...</td>\n"
};

const char *html_text_Nedelne_pismeno[] = {"Nede¾né písmeno", "Nedìlní písmeno", "Sunday letter", "", "", "Nedìlní písmeno", "hu_sunday-letter"};
const char *html_text_Nedelne_pismena[] = {"Nede¾né písmená", "Nedìlní písmena", "Sunday letters", "", "", "Nedìlní písmena", "hu_sunday-letters"};

const char *html_text_Od_prvej_adv_atd[] = {
	"Od prvej adventnej nedele v roku %d (%s) pokraèuje <a href=\"%s%s\">liturgickı rok</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"Od první nedìle adventní v roku %d (%s) pokraèuje <a href=\"%s%s\">liturgickı rok</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"From the 1st Advent Sunday in the year %d (%s) continues <a href=\"%s%s\">liturgical year</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"Od prvej adventnej nedele v roku %d (%s) pokraèuje <a href=\"%s%s\">liturgickı rok</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"",
	"Od první nedìle adventní v roce %d (%s) pokraèuje <a href=\"%s%s\">liturgickı rok</a> <"HTML_SPAN_BOLD">%c</span>.\n"
};

const char *html_text_Po_Velkej_noci_atd[] = {
	"Po Ve¾kej noci nasleduje %d. %s v cezroènom období.\n",
	"Po Velikonocích následuje %d. %s v mezibdobí.\n",
	"After Easter follows %d. %s per annum.\n",
	"Po Ve¾kej noci nasleduje %d. %s v období „cez rok“.\n",
	"Po Ve¾kej noci nasleduje %d. %s v období „cez rok“.\n",
	"Po Velikonocích následuje %d. %s v mezibdobí.\n",
	"Húsvét után évközi %d. %s következik.\n",
};

const char *html_text_Prikazane_sviatky_v_roku[] = {
	"<p><"HTML_SPAN_RED">Prikázané sviatky v roku %s:</span>\n",
	"<p><"HTML_SPAN_RED">Pøikázané svátky v roce %s:</span>\n",
	"<p><"HTML_SPAN_RED">Obliged celebrations in the year %s:</span>\n",
	"<p><"HTML_SPAN_RED">Prikázané sviatky v roku %s:</span>\n",
	"<p><"HTML_SPAN_RED">Prikázané sviatky v roku %s:</span>\n",
	"<p><"HTML_SPAN_RED">Pøikázané svátky v roce %s:</span>\n",
	"<p><"HTML_SPAN_RED">%s kötelezõ ünnepei:</span>\n",
};

const char *html_text_Jednotlive_mesiace_roku[] = {
	"<"HTML_SPAN_RED">Jednotlivé mesiace roku %s:</span>\n",
	"<"HTML_SPAN_RED">Jednotlivé mìsíce v roce %s:</span>\n",
	"<"HTML_SPAN_RED">Individual months of the year %s:</span>\n",
	"<"HTML_SPAN_RED">Jednotlivé mesiace roku %s:</span>\n",
	"<"HTML_SPAN_RED">Jednotlivé mesiace roku %s:</span>\n",
	"<"HTML_SPAN_RED">Jednotlivé mìsíce v roce %s:</span>\n",
	"hu_<"HTML_SPAN_RED">Individual months of the year %s:</span>\n",
};

const char *str_modl_cez_den_zalmy_zo_dna[POCET_JAZYKOV + 1] = 
	{"benej psalmódie", "bìné psalmodie", "ordinary psalmody", "___", "", "bìné psalmodie", "hu_ordinary-psalter"};
#define		STR_MODL_CEZ_DEN_ZALMY_ZO_DNA 	str_modl_cez_den_zalmy_zo_dna[_global_jazyk]

const char *str_modl_cez_den_doplnkova_psalmodia[POCET_JAZYKOV + 1] = 
	{"doplnkovej psalmódie", "doplòkové psalmodie", "supplementary psalmody", "psalmodia complementaris", "", "doplòkové psalmodie", "hu_suppl.-psalter"};
#define		STR_MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA 	str_modl_cez_den_doplnkova_psalmodia[_global_jazyk]

const char *str_modl_zalmy_zo_dna[POCET_JAZYKOV + 1] = 
	{"dòa", "dne", "day", "die", "", "dne", "naptól"};
#define		STR_MODL_ZALMY_ZO_DNA 	str_modl_zalmy_zo_dna[_global_jazyk]

const char *str_modl_zalmy_zo_sv[POCET_JAZYKOV + 1] = 
	{"sviatku", "svátku", "celebration", "___", "", "svátku", "ünneptõl"};
#define		STR_MODL_ZALMY_ZO_SV 	str_modl_zalmy_zo_sv[_global_jazyk]

const char *str_ano[POCET_JAZYKOV + 1] = 
	{"áno", "ano", "yes", "___", "___", "ano", "igen"};
#define		STR_ANO		str_ano[_global_jazyk]

const char *str_nie[POCET_JAZYKOV + 1] = 
	{"nie", "ne", "no", "non", "___", "ne", "nem"};
#define		STR_NIE		str_nie[_global_jazyk]

const char *html_text_detaily_uvod[POCET_JAZYKOV + 1] = 
{"Nasledovné monosti ovplyvnia vzh¾ad i obsah vygenerovanej modlitby.\nVyberte tie monosti, pod¾a ktorıch sa má modlitba vygenerova.", 
 "Následující monosti mají vliv na vzhled i obsah vygenerované modlitby.\nVyberte si monosti, podle kterıch má bıt modlitba vygenerována.", 
 "The following options apply to the resulting generated text of the prayer.\nChoose options which fit your needs to the resulting prayer text.", 
 "",
 "",
 "Následující monosti mají vliv na vzhled i obsah vygenerované modlitby.\nVyberte si monosti, podle kterıch má bıt modlitba vygenerována.",
 "hu_ (we will translate it later)"
};

const char *html_text_nemenne_sucasti[] = 
{"zobrazi <i>nemenné súèasti</i> modlitby?", 
 "zobrazit <i>nemìnné souèásti</i> modlitby?", 
 "display <i>non-changeable parts</i> prayer?", 
 "", 
 "", 
 "zobrazit <i>nemìnné souèásti</i> modlitby?",
 "hu_ (we will translate it later)"
};

const char *html_text_nemenne_sucasti_explain[] = 
{"Kadé ranné chvály obsahujú Benediktus, vešpery Magnifikat, obe modlitby obsahujú Otèenáš a zakonèenie modlitby, a napokon posvätné èítanie obsahuje niekedy hymnus Te Deum; tieto èasti modlitby nazıvame <i>nemenné súèasti</i>.", 
 "Kadé ranní chvály obsahují Zachariášovo kantikum, nešpory Mariin Magnifikat, obì modlitbu Pánì a zakonèení modlitby, a koneènì modlitba se ètením nìkdy obsahuje hymnus Te Deum; tyto èásti modliteb nazıváme <i>nemìnné souèásti</i>.", 
 "Each morning prayer contains Benedictus, vesperae contains Magnificat, both contain the Lord's Prayer and a conclusion of the prayer; finally, the holy reading sometimes contains the Te Deum hymnus; all these parts we call <i>un-changeable parts</i>.", 
 "",
 "", 
 "Kadé ranní chvály obsahují Zachariášovo kantikum, veèerní chvály kantikum Panny Marie, obì modlitbu Pánì a zakonèení modlitby, a koneènì modlitba se ètením nìkdy obsahuje hymnus Te Deum; tyto èásti modliteb nazıváme <i>nemìnné souèásti</i>.",
 "hu_ (we will translate it later)"
};

const char *html_text_popis_svaty[] = 
{"zobrazi <i>popis</i> k modlitbe svätého?", 
 "zobrazit <i>popis</i> pøi modlitbì ke cti svìtce?", 
 "display <i>description</i> for prayer for the saints?", 
 "", 
 "", 
 "zobrazit <i>popis</i> pøi modlitbì ke cti svìtce?",
 "hu_ (we will translate it later)"
};

const char *html_text_popis_svaty_explain[] = 
{"Modlitby zväèša obsahujú pred názvom modlitby ivotopis svätého, popis sviatku alebo podobnú struènú charakteristiku, ktorú pre jednoduchos nazıvame <i>popis</i>.", 
 "Modlitby ke cti svatıch obsahují struènı ivotopis svatého, pøi svátku je to struènı popis svátku a podobnì. Tyto charakteristiky pro struènost nazıváme <i>popis</i>.", 
 "xxx", 
 "",
 "", 
 "Modlitby ke cti svatıch obsahují struènı ivotopis svatého, u svátku je to struènı popis svátku a podobnì. Tyto charakteristiky pro struènost nazıváme <i>popis</i>.",
 "hu_ (we will translate it later)"
};

const char *html_text_zalmy_brat_zo[] = 
{"almy bra zo ", 
 "almy brát ze ", 
 "take psalmody from ", 
 "", 
 "", 
 "almy brát ze ",
 "zsoltárok a következõ helyrõl:"
};
const char *html_text_zalmy_brat_zo_okrem_mcd[] = 
{" (okrem modlitby cez deò)\n", 
 " (kromì modlitby pøes den)\n", 
 " (excluding the prayers during the day)\n", 
 "", 
 "", 
 " (kromì modlitby bìhem dne)\n",
 "hu_"
};
const char *html_text_zalmy_brat_zo_explain[] = 
{"V závislosti od typu svätenia sa berú alebo neberú na sviatok svätca/svätice almy a chválospevy z vlastnej èasti (na ranné chvály z nedele 1. tıdòa altára); je moné tieto almy vyiada.", 
 "V závislosti na typu slavení svátku svìtce/svìtice se berou nebo neberou almy a kantika z vlastní èásti (na ranní chvály z nedìle 1. tıdne altáøe); je mono tyto almy vyádat.", 
 "xxx", 
 "",
 "", 
 "V závislosti na typu slavení svátku svìtce/svìtice se berou nebo neberou almy a kantika z vlastní èásti (na ranní chvály z nedìle 1. tıdne altáøe); je mono tyto almy vyádat.",
 "hu_"
};

const char *html_text_spol_casti_vziat_zo[] = 
{"èasti modlitby zo spoloènej èasti ", 
 "èásti modlitby ze spoleèné èásti ", 
 "parts of prayer from the common part ", 
 "",
 "",
 "èásti modlitby ze spoleèné èásti ",
 "a közös részbõl"};
const char *html_text_spol_casti_vziat_zo_explain[] = 
{"Na sviatok svätca/svätice sa pod¾a liturgickıch pravidiel berú èasti, ktoré sa nenachádzajú vo vlastnej èasti altára, zo spoloènej èasti sviatku, niekedy je monos vybra si z viacerıch spoloènıch èastí; naviac je monos modli sa tieto èasti zo všedného dòa.", 
 "Na svátek ke cti svìtce/svìtice se podle liturgickıch pravidel berou èásti, které se nenachází ve vlastních textech, ze spoleènıch textù, nìkdy je moné vybrat si z více spoleènıch textù; navíc je monost modlit se tyto èásti ze všedního dne.", 
 "xxx", 
 "",
 "",
 "O svátku ke cti svìtce/svìtice se podle liturgickıch pravidel berou èásti, které se nenachází ve vlastních textech, ze spoleènıch textù, nìkdy je moné vybrat si z více spoleènıch textù; navíc je monost modlit se tyto èásti ze všedního dne.",
 "hu_"
};

const char *html_text_zalmy_pre_mcd[] = 
{"almy pre modlitbu cez deò bra z ", 
 "almy pro modlitbu pøes den brát ze ", 
 "take psalmody for the prayer during the day from ", 
 "",
 "",
 "almy pro modlitbu bìhem dne brát ze ",
 "hu_"
};
const char *html_text_zalmy_pre_mcd_explain[] = 
{"Doplnková psalmódia zahàòa 3 série tzv. graduálnych almov ( 120-129), ktoré mono bra namiesto almov zo altára.", 
 "Doplòovací cyklus almù obsahuje 3 série tzv. graduálních almù ( 120-129), které je mono brát místo almù ze altáøe.", 
 "xxx", 
 "",
 "", 
 "Doplòovací cyklus almù obsahuje 3 série tzv. graduálních almù ( 120-129), které je mono brát místo almù ze altáøe.",
 "hu_"
};

const char *html_text_detaily_explain[] = 
{"Pokia¾ sú niektoré parametre pre vybranú modlitbu nepouite¾né, neberú sa do úvahy (môu by teda nastavené ¾ubovo¾ne).", 
 "Kdy jsou nìkteré vıše uvedené volby nepouitelné pro nìjakou modlitbu, neberou se v úvahu (mohou bıt nastaveny dle libovùle).", 
 "If any of described options are not applicable for a chosen prayer, they can be set anyhow.", 
 "",
 "", 
 "Kdy jsou nìkteré vıše uvedené volby nepouitelné pro nìjakou modlitbu, neberou se v úvahu (mohou bıt nastaveny dle libovùle).",
 "hu_"
};

const char *text_DRUHA_NEDELA_PO_NAR_PANA[] = 
{"2. nede¾a po Narodení Pána",
 "2. nedìle po Narození Pánì",
 "",
 "",
 "",
 "2. nedìle po Narození Pánì",
 "hu_",
 };
const char *text_JAN_01[] = 
{"Panny Márie Bohorodièky",
 "Matky Boí, Panny Marie",
 "",
 "Sanctae Dei Genetricis Mariae",
 "",
 "Matky Boí, Panny Marie",
 "Szûz Mária, Isten Anyja",
 };
const char *text_JAN_02[] = 
{"Sv. Bazila Ve¾kého a Gregora Nazianského, biskupov a uèite¾ov Cirkvi",
 "Sv. Basila Velikého a Øehoøe Naziánského, biskupù a uèitelù církve",
 "",
 "Ss. Basilii Magni et Gregorii Nazianzeni, ep. et Eccl. doct.",
 "",
 "Sv. Basila Velikého a Øehoøe Naziánského, biskupù a uèitelù Církve",
 "Nagy Szent Vazul és Nazianzi Szent Gergely püspökök és egyháztanítók",
 };
const char *text_JAN_03[] = 
{"(nie je)",
 "(není)",
 "",
 "",
 "",
 "Nejsvìtìjšího Jména Jeíš ",
 "(nincs Magyarországon)",
 };
const char *text_JAN_06[] = 
{"Zjavenie Pána",
 "Zjevení Pánì",
 "",
 "In Epiphania Domini",
 "",
 "Zjevení Pánì",
 "Urunk Megjelenése",
 };
const char *text_JAN_07[] = 
{"Sv. Rajmunda z Peòafortu, kòaza",
 "Sv. Rajmunda z Penafortu, knìze",
 "",
 "S. Raimundi de Penyafort, presb.",
 "",
 "Sv. Rajmunda z Penafortu, knìze",
 "Penyaforti Szent Rajmund áldozópap",
 };
const char *text_JAN_KRST[] = 
{"Krst Krista Pána",
 "Køtu Pánì",
 "",
 "In Baptismate Domini",
 "",
 "Køtu Pánì",
 "Urunk Megkeresztelkedése",
 };
const char *text_JAN_13[] = 
{"Sv. Hilára, biskupa a uèite¾a Cirkvi",
 "Sv. Hilaria, biskupa a uèitele církve",
 "",
 "S. Hilarii, ep. et Eccl. doct.",
 "",
 "Sv. Hilaria, biskupa a uèitele Církve",
 "Szent Hiláriusz (Vidor) püspök és egyháztanító",
 };
const char *text_JAN_17[] = 
{"Sv. Antona, opáta",
 "Sv. Antonína, opata",
 "",
 "S. Antonii, abbatis",
 "",
 "Sv. Antonína, opata",
 "Szent Antal apát",
 };
const char *text_JAN_18[] = 
{"(na Slovensku nie je)",
 "Panny Marie, Matky jednoty køesanù",
 "",
 "(non est in Latina)",
 "",
 "Panny Marie, Matky jednoty køesanù",
 "(nincs Magyarországon)",
 };
const char *text_JAN_20_1[] = 
{"Sv. Fabiána, pápea a muèeníka",
 "Sv. Fabiána, papee a muèedníka",
 "",
 "S. Fabiani, papae et mart.",
 "",
 "Sv. Fabiána, papee a muèedníka",
 "Szent Fábián pápa év vértanú",
 };
const char *text_JAN_20_2[] = 
{"Sv. Šebastiána, muèeníka",
 "Sv. Šebestiána, muèedníka",
 "",
 "S. Sebastiani, mart.",
 "",
 "Sv. Šebestiána, muèedníka",
 "Szent Sebestyén vértanú",
 };
const char *text_JAN_21[] = 
{"Sv. Agnesy, panny a muèenice",
 "Sv. Aneky, panny a muèednice",
 "",
 "S. Agnetis, virg. et mart.",
 "",
 "Sv. Aneky, panny a muèednice",
 "Szent Ágnes szûz és vértanú",
 };
const char *text_JAN_22[] = 
{"Sv. Vincenta, diakona a muèeníka",
 "Sv. Vincence, jáhna a muèedníka",
 "",
 "S. Vincentii, diaconi et mart.",
 "",
 "Sv. Vincence, jáhna a muèedníka",
 "Szent Vince diakónus és vértanú",
 };
const char *text_JAN_23[] = 
{"Sv. Jána Almuníka, biskupa",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "(non est in Latina)",
 "",
 "hu_name",
 "(nincs Magyarországon)",
 };
const char *text_JAN_24[] = 
{"Sv. Františka Saleského, biskupa a uèite¾a Cirkvi",
 "Sv. Františka Saleského, biskupa a uèitele církve",
 "",
 "S. Francisci de Sales, ep. et Eccl. doct.",
 "",
 "Sv. Františka Saleského, biskupa a uèitele Církve",
 "Szalézi Szent Ferenc püspök és egyháztanító",
 };
const char *text_JAN_25[] = 
{"Obrátenie svätého Pavla, apoštola",
 "Obrácení svatého Pavla, apoštola",
 "",
 "In Conversione S. Pauli, Apostoli",
 "",
 "Obrácení svatého Pavla, apoštola",
 "Szent Pál apostol megtérése (Pál fordulása)",
 };
const char *text_JAN_26[] = 
{"Sv. Timoteja a Títa, biskupov",
 "Sv. Timoteje a Tita, biskupù",
 "",
 "Ss. Timothei et Titi, ep.",
 "",
 "Sv. Timoteje a Tita, biskupù",
 "Szent Timóteus és Szent Titusz püspökök",
 };
const char *text_JAN_27[] = 
{"Sv. Angely Merici, panny",
 "Sv. Andìly Mericiové, panny",
 "",
 "S. Angelae Merici, virg.",
 "",
 "Sv. Andìly Mericiové, panny",
 "Merici Szent Angéla szûz",
 };
const char *text_JAN_28[] = 
{"Sv. Tomáša Akvinského, kòaza a uèite¾a Cirkvi",
 "Sv. Tomáše Akvinského, knìze a uèitele církve",
 "",
 "S. Thomae de Aquino, presb. et Eccl. doct.",
 "",
 "Sv. Tomáše Akvinského, knìze a uèitele Církve",
 "Aquinói Szent Tamás áldozópap és egyháztanító",
 };
const char *text_JAN_31[] = 
{"Sv. Jána Boska, kòaza",
 "Sv. Jana Boska, knìze",
 "",
 "S. Ioannis Bosco, presb.",
 "",
 "Sv. Jana Boska, knìze",
 "Bosco Szent János",
 };
const char *text_FEB_02[] = 
{"Obetovanie Pána",
 "Uvedení Pánì do chrámu",
 "",
 "In Praesentatione Domini",
 "",
 "Uvedení Pánì do chrámu",
 "Urunk bemutatása (Gyertyaszentelõ Boldogasszony)",
 };
const char *text_FEB_03_1[] = 
{"Sv. Blaeja, biskupa a muèeníka",
 "Sv. Blaeje, biskupa a muèedníka",
 "",
 "S. Blasii, ep. et mart.",
 "",
 "Sv. Blaeje, biskupa a muèedníka",
 "Szent Balázs püspök és vértanú",
 };
const char *text_FEB_03_2[] = 
{"Sv. Oskára, biskupa",
 "Sv. Ansgara, biskupa",
 "",
 "S. Ansgarii, ep.",
 "",
 "Sv. Ansgara, biskupa",
 "Szent Anszgár (Oszkár) püspök",
 };
const char *text_FEB_05[] = 
{"Sv. Agaty, panny a muèenice",
 "Sv. Agáty, panny a muèednice",
 "",
 "S.  Agathae, virg. et mart.",
 "",
 "Sv. Agáty, panny a muèednice",
 "Szent Ágota szûz és vértanú",
 };
const char *text_FEB_06[] = 
{"Sv. Pavla Mikiho a spoloèníkov, muèeníkov",
 "Sv. Pavla Mikiho a druhù, muèedníkù",
 "",
 "Ss.  Pauli Miki et sociorum, mart.",
 "",
 "Sv. Pavla Mikiho a druhù, muèedníkù",
 "Miki Szent Pál és társai vértanúk",
 };
const char *text_FEB_08[] = 
{"Sv. Hieronyma Emilianiho",
 "Sv. Jeronıma Emilianiho",
 "",
 "S. Hieronymi Emiliani",
 "",
 "Sv. Jeronıma Emilianiho",
 "Emiliáni Szent Jeromos",
 };
const char *text_FEB_08_2[] = 
{"Sv. Jozefíny Bakhita, panny",
 "Sv. Josefíny Bakhity, panny",
 "",
 "",
 "",
 "Sv. Josefíny Bakhity, panny",
 "(nincs Magyarországon)",
 };
const char *text_FEB_10[] = 
{"Sv. Školastiky, panny",
 "Sv. Scholastiky, panny",
 "",
 "S.  Scholasticae, virg.",
 "",
 "Sv. Scholastiky, panny",
 "Szent Skolasztika szûz",
 };
const char *text_FEB_11[] = 
{"Prebl. Panny Márie Lurdskej",
 "Panny Marie Lurdské",
 "",
 "B. Mariae Virg. de Lourdes",
 "",
 "Panny Marie Lurdské",
 "A Lourdes-i Boldogságos Szûz Mária",
 };
const char *text_FEB_14[] = 
{"(na Slovensku sa slávi 5. júla)",
 "(slaví se 5. èervna)",
 "",
 "Ss. Cyrilli, monachi, et Methodii, ep.",
 "",
 "hu_name",
 "Szent Cirill szerzetes és Szent Metód püspök, Európa társvédõszentjei",
 };
const char *text_FEB_17[] = 
{"Siedmich svätıch zakladate¾ov rehole Sluobníkov Panny Márie",
 "Sv. Alexia a druhù, øeholníkù",
 "",
 "Ss. Septem Fundatorum Ordinis Servorum B. Mariae Virg.",
 "",
 "Sv. Alexia a druhù, øeholníkù",
 "A szervita rend hét szent alapítója",
 };
const char *text_FEB_21[] = 
{"Sv. Petra Damianiho, biskupa a uèite¾a Cirkvi",
 "Sv. Petra Damianiho, biskupa a uèitele církve",
 "",
 "S. Petri Damiani, ep. et Eccl. doct.",
 "",
 "Sv. Petra Damianiho, biskupa a uèitele Církve",
 "Damiáni Szent Péter püspök és egyháztanító",
 };
const char *text_FEB_22[] = 
{"Katedra sv. Petra, apoštola",
 "Stolce svatého Petra, apoštola",
 "",
 "Cathedrae S. Petri, Apostoli",
 "",
 "Stolce svatého Petra, apoštola",
 "Szent Péter apostol székfoglalása",
 };
const char *text_FEB_23[] = 
{"Sv. Polykarpa, biskupa a muèeníka",
 "Sv. Polykarpa, biskupa a muèedníka",
 "",
 "S. Polycarpi, ep. et mart.",
 "",
 "Sv. Polykarpa, biskupa a muèedníka",
 "Szent Polikárp püspök és vértanú",
 };
const char *text_POPOLCOVA_STREDA[] = 
{"Popolcová streda",
 "Popeleèní støeda",
 "",
 "",
 "",
 "Popeleèní støeda",
 "hu_name",
 };
const char *text_MAR_04[] = 
{"Sv. Kazimíra",
 "Sv. Kazimíra",
 "",
 "S. Casimiri",
 "",
 "Sv. Kazimíra",
 "Szent Kázmér",
 };
const char *text_MAR_07[] = 
{"Sv. Perpetuy a Felicity, muèeníc",
 "Sv. Perpetuy a Felicity, muèednic",
 "",
 "Ss.   Perpetuae et  Felicitatis, mart.",
 "",
 "Sv. Perpetuy a Felicity, muèednic",
 "Szent Perpétua és Felicitász vértanúk",
 };
const char *text_MAR_08[] = 
{"Sv. Jána z Boha, reho¾níka",
 "Sv. Jana z Boha, øeholníka",
 "",
 "S. Ioannis a Deo, relig.",
 "",
 "Sv. Jana z Boha, øeholníka",
 "Istenes Szent János szerzetes",
 };
const char *text_MAR_09[] = 
{"Sv. Františky Rímskej, reho¾níèky",
 "Sv. Františky Øímské, øeholnice",
 "",
 "S. Franciscae Romanae, relig.",
 "",
 "Sv. Františky Øímské, øeholnice",
 "Római Szent Franciska szerzetesnõ",
 };
const char *text_MAR_10[] = 
{"(na Slovensku nie je)",
 "Sv. Jana Ogilvie, knìze a muèedníka",
 "",
 "(non est in Latina)",
 "",
 "Sv. Jana Ogilvie, knìze a muèedníka",
 "(nincs Magyarországon)",
 };
const char *text_MAR_17[] = 
{"Sv. Patrika, biskupa",
 "Sv. Patrika, biskupa",
 "",
 "S. Patricii, ep.",
 "",
 "Sv. Patrika, biskupa",
 "Szent Patrik püspök",
 };
const char *text_MAR_18[] = 
{"Sv. Cyrila Jeruzalemského, biskupa a uèite¾a Cirkvi",
 "Sv. Cyrila Jeruzalémského, biskupa a uèitele církve",
 "",
 "S. Cyrilli Hierosolymitani, ep. et Eccl. doct.",
 "",
 "Sv. Cyrila Jeruzalémského, biskupa a uèitele Církve",
 "Jeruzsálemi Szent Cirill püspök és egyháztanító",
 };
const char *text_MAR_19[] = 
{"Sv. Jozefa, enícha Panny Márie",
 "Sv. Josefa, Snoubence Panny Marie",
 "",
 "S. Ioseph, Sponsi B. Mariae V.",
 "",
 "Sv. Josefa, Snoubence Panny Marie",
 "Szent József, a Boldogságos Szûz Mária jegyese",
 };
const char *text_MAR_23[] = 
{"Sv. Turibia de Mongrovejo, biskupa",
 "Sv. Turibia z Mongroveja, biskupa",
 "",
 "S. Turibii de Mogrovejo, ep.",
 "",
 "Sv. Turibia z Mongroveja, biskupa",
 "Mongrovejói Szent Turibiusz püspök",
 };
const char *text_MAR_25[] = 
{"Zvestovanie Pána",
 "Zvìstování Pánì",
 "",
 "In Annuntiatione Domini",
 "",
 "Zvìstování Pánì",
 "Urunk születésének hírüladása (Gyümölcsoltó Boldogasszony)",
 };
const char *text_APR_02[] = 
{"Sv. Františka z Pauly, pustovníka",
 "Sv. Františka z Pauly, poustevníka",
 "",
 "S. Francisci de Paola, eremitai",
 "",
 "Sv. Františka z Pauly, poustevníka",
 "Paolai Szent Ferenc remete",
 };
const char *text_APR_04[] = 
{"Sv. Izidora, biskupa a uèite¾a Cirkvi",
 "Sv. Izidora, biskupa a uèitele církve",
 "",
 "S. Isidori, ep. et Eccl. doct.",
 "",
 "Sv. Izidora, biskupa a uèitele Církve",
 "Szent Izidor püspök és egyháztanító",
 };
const char *text_APR_05[] = 
{"Sv. Vincenta Ferrera, kòaza",
 "Sv. Vincence Ferrerského, knìze",
 "",
 "S.  Vincentii Ferrer, presb.",
 "",
 "Sv. Vincence Ferrerského, knìze",
 "Ferrer Szent Vince áldozópap",
 };
const char *text_APR_07[] = 
{"Sv. Jána Krstite¾a de la Salle, kòaza",
 "Sv. Jana Køtitele de la Salle, knìze",
 "",
 "S.  Ioannis Baptistae de la Salle, presb.",
 "",
 "Sv. Jana Køtitele de la Salle, knìze",
 "De la Salle Szent János áldozópap",
 };
const char *text_APR_11[] = 
{"Sv. Stanislava, biskupa a muèeníka",
 "Sv. Stanislava, biskupa a muèedníka",
 "",
 "S.  Stanislai, ep.  et mart.",
 "",
 "Sv. Stanislava, biskupa a muèedníka",
 "Szent Szaniszló püspök és vértanú",
 };
const char *text_APR_13[] = 
{"Sv. Martina I., pápea a muèeníka",
 "Sv. Martina I., papee a muèedníka",
 "",
 "S. Martini I, papae et mart.",
 "",
 "Sv. Martina I., papee a muèedníka",
 "Szent I. Márton pápa és vértanú",
 };
const char *text_APR_21[] = 
{"Sv. Anzelma, biskupa a uèite¾a Cirkvi",
 "Sv. Anselma, biskupa a uèitele církve",
 "",
 "S. Anselmi, ep. et Eccl. doct.",
 "",
 "Sv. Anselma, biskupa a uèitele Církve",
 "Szent Anzelm püspök és egyháztanító",
 };
const char *text_APR_23[] = 
{"Sv. Vojtecha, biskupa a muèeníka",
 "Sv. Vojtìcha, biskupa a muèedníka",
 "",
 "S. Adalberti, ep. et mart.",
 "",
 "Sv. Vojtìcha, biskupa a muèedníka",
 "Szent Adalbert (Béla) püspök és vértanú",
 };
const char *text_APR_24_1[] = 
{"Sv. Juraja, muèeníka",
 "Sv. Jiøí, muèedníka",
 "",
 "S. Georgii, mart.",
 "",
 "Sv. Jiøí, muèedníka",
 "Szent György vértanú",
 };
const char *text_APR_24_2[] = 
{"Sv. Fidéla zo Sigmaringenu, kòaza a muèeníka",
 "Sv. Fidela ze Sigmaringy, knìze a muèedníka",
 "",
 "S. Fidelis a Sigmaringen, presb. et mart.",
 "",
 "Sv. Fidela ze Sigmaringy, knìze a muèedníka",
 "Sigmaringeni Szent Fidél áldozópap és vértanú",
 };
const char *text_APR_25[] = 
{"Sv. Marka, evanjelistu",
 "Sv. Marka, evangelisty",
 "",
 "S. Marci, evangelistae",
 "",
 "Sv. Marka, evangelisty",
 "Szent Márk evangelista",
 };
const char *text_APR_28_1[] = 
{"Sv. Petra Chanela, kòaza a muèeníka",
 "Sv. Petra Chanela, knìze a muèedníka",
 "",
 "S. Petri Chanel, presb. et mart.",
 "",
 "Sv. Petra Chanela, knìze a muèedníka",
 "Chanel Szent Péter áldozópap és vértanú",
 };
const char *text_APR_28_2[] = 
{"Sv. ¼udovíta Márie Grignion de Montfort, kòaza",
 "Sv. Ludvíka Marie Grignona z Montfortu, knìze",
 "",
 "S. Ludovici M. Grignion de Montfort, presb.",
 "",
 "Sv. Ludvíka Marie Grignona z Montfortu, knìze",
 "(nincs Magyarországon)",
 };
const char *text_APR_29[] = 
{"Sv. Kataríny Sienskej, panny a uèite¾ky Cirkvi, spolupatrónky Európy",
 "Sv. Kateøiny Sienské, panny a uèitelky církve, spolupatronky Evropy",
 "",
 "S. Catharinae Senensis, virg. et Eccl. doct.",
 "",
 "Sv. Kateøiny Sienské, panny a uèitelky Církve, spolupatronky Evropy",
 "Sienai Szent Katalin szûz és egyháztanító",
 };
const char *text_APR_30_1[] = 
{"Sv. Pia V., pápea",
 "Sv. Pia V., papee",
 "",
 "S. Pii V, papae",
 "",
 "Sv. Pia V., papee",
 "Szent V. Piusz pápa",
 };
const char *text_APR_30_2[] = 
{"(na Slovensku nie je)",
 "Sv. Zikmunda, muèedníka",
 "",
 "(non est in Latina)",
 "",
 "Sv. Zikmunda, muèedníka",
 "(nincs Magyarországon)",
 };
const char *text_MAJ_01[] = 
{"Sv. Jozefa, robotníka",
 "Sv. Josefa, Dìlníka",
 "",
 "S. loseph Opificis",
 "",
 "Sv. Josefa, Dìlníka",
 "Munkás Szent József",
 };
const char *text_MAJ_02[] = 
{"Sv. Atanáza, biskupa a uèite¾a Cirkvi",
 "Sv. Atanáše, biskupa a uèitele církve",
 "",
 "S. Athanasii, ep. et Eccl. doct.",
 "",
 "Sv. Atanáše, biskupa a uèitele Církve",
 "Szent Atanáz püspök és egyháztanító",
 };
const char *text_MAJ_03[] = 
{"Sv. Filipa a Jakuba, apoštolov",
 "Sv. Filipa a Jakuba, apoštolù",
 "",
 "Ss. Philippi et Iacobi, apostolorum",
 "",
 "Sv. Filipa a Jakuba, apoštolù",
 "Szent Fülöp és Szent Jakab apostol",
 };
const char *text_MAJ_06[] = 
{"(na Slovensku nie je)",
 "Sv. Jana Sarkandra, knìze a muèedníka",
 "",
 "(non est in Latina)",
 "",
 "Sv. Jana Sarkandra, knìze a muèedníka",
 "(nincs Magyarországon)",
 };
const char *text_MAJ_08[] = 
{"(na Slovensku nie je)",
 "Panny Marie, Prostøednice všech milostí",
 "",
 "(non est in Latina)",
 "",
 "Panny Marie, Prostøednice všech milostí",
 "(nincs Magyarországon)",
 };
const char *text_MAJ_12_1[] = 
{"Sv. Nerea a Achila, muèeníkov",
 "Sv. Nerea a Achillea, muèedníkù",
 "",
 "Ss. Nerei et Achillei, mart.",
 "",
 "Sv. Nerea a Achillea, muèedníkù",
 "Szent Néreusz és Szent Achilleusz vértanúk",
 };
const char *text_MAJ_12_2[] = 
{"Sv. Pankráca, muèeníka",
 "Sv. Pankráce, muèedníka",
 "",
 "S. Pancratii, mart.",
 "",
 "Sv. Pankráce, muèedníka",
 "Szent Pongrác vértanú",
 };
const char *text_MAJ_12_3[] = 
{"(na Slovensku nie je)",
 "Vıroèí posvìcení katedrály sv. Víta",
 "",
 "(non est in Latina)",
 "",
 "Vıroèí posvìcení katedrály sv. Víta",
 "(nincs Magyarországon)",
 };
const char *text_MAJ_13[] = 
{"Panny Márie Fatimskej",
 "Panny Marie Fatimské",
 "",
 "",
 "",
 "Panny Marie Fatimské",
 "(nincs Magyarországon)",
 };
const char *text_MAJ_14[] = 
{"Sv. Mateja, apoštola",
 "Sv. Matìje, apoštola",
 "",
 "S. Matthiae, apostoli",
 "",
 "Sv. Matìje, apoštola",
 "(nincs Magyarországon)",
 };
const char *text_MAJ_16[] = 
{"Sv. Jána Nepomuckého, kòaza a muèeníka",
 "Sv. Jana Nepomuckého, knìze a muèedníka, hlavního patrona Èech",
 "",
 "(non est in Latina)",
 "",
 "Sv. Jana Nepomuckého, knìze a muèedníka, hlavního patrona Èech",
 "Nepomuki Szent János áldozópap és vértanú",
 };
const char *text_MAJ_18[] = 
{"Sv. Jána I., pápea a muèeníka",
 "Sv. Jana I., papee a muèedníka",
 "",
 "S. Ioannis I, papae et mart.",
 "",
 "Sv. Jana I., papee a muèedníka",
 "Szent I. János pápa és vértanú",
 };
const char *text_MAJ_20_1[] = 
{"(na Slovensku nie je)",
 "Sv. Klementa Marie Hofbauera, knìze",
 "",
 "",
 "",
 "Sv. Klementa Marie Hofbauera, knìze",
 "(nincs Magyarországon)",
 };
const char *text_MAJ_20_2[] = 
{"Sv. Bernardína Sienského, kòaza",
 "Sv. Bernardina Sienského, knìze",
 "",
 "S. Bernardini Senensis, presb.",
 "",
 "Sv. Bernardina Sienského, knìze",
 "Sienai Szent Bernardin áldozópap",
 };
const char *text_MAJ_21[] = 
{"(na Slovensku nie je)",
 "Vıroèí posvìcení katedrály sv. Petra a Pavla",
 "",
 "(non est in Latina)",
 "",
 "Vıroèí posvìcení katedrály sv. Petra a Pavla",
 "(nincs Magyarországon)",
 };
const char *text_MAJ_22[] = 
{"(na Slovensku nie je)",
 "Sv. Rity z Cascie, øeholnice",
 "",
 "(non est in Latina)",
 "",
 "Sv. Rity z Cascie, øeholnice",
 "Szent Rita özvegy",
 };
const char *text_MAJ_25_1[] = 
{"Sv. Bédu Ctihodného, kòaza a uèite¾a Cirkvi",
 "Sv. Bedy Ctihodného, knìze a uèitele církve",
 "",
 "S. Bedae Venerdbilis, presb. et Ecci. doct.",
 "",
 "Sv. Bedy Ctihodného, knìze a uèitele Církve",
 "Tiszteletreméltó Szent Béda áldozópap és egyháztanító",
 };
const char *text_MAJ_25_2[] = 
{"Sv. Gregora VII., pápea",
 "Sv. Øehoøe VII., papee",
 "",
 "S. Gregorii VII, papae",
 "",
 "Sv. Øehoøe VII., papee",
 "Szent VII. Gergely pápa",
 };
const char *text_MAJ_25_3[] = 
{"Sv. Márie Magdalény de Pazzi, panny",
 "Sv. Marie Magdalény de Pazzi, panny",
 "",
 "S. Mariae Magdalenae de Pazzi, virg.",
 "",
 "Sv. Marie Magdalény de Pazzi, panny",
 "Pazzi Szent Mária Magdolna Szûz",
 };
const char *text_MAJ_26[] = 
{"Sv. Filipa Neriho, kòaza",
 "Sv. Filipa Neriho, knìze",
 "",
 "S. Philippi Neri, presb.",
 "",
 "Sv. Filipa Neriho, knìze",
 "Néri Szent Fülöp áldozópap",
 };
const char *text_MAJ_27[] = 
{"Sv. Augustína z Canterbury, biskupa",
 "Sv. Augustina z Canterbury, biskupa",
 "",
 "S. Augustini Cantuariensis, ep.",
 "",
 "Sv. Augustina z Canterbury, biskupa",
 "Canterbury Szent Ágoston püspök",
 };
const char *text_MAJ_30[] = 
{"(na Slovensku nie je)",
 "Sv. Zdislavy",
 "",
 "(non est in Latina)",
 "",
 "Sv. Zdislavy",
 "(nincs Magyarországon)",
 };
const char *text_MAJ_31[] = 
{"Navštívenie prebl. Panny Márie",
 "Navštívení Panny Marie",
 "",
 "",
 "",
 "Navštívení Panny Marie",
 "(nincs Magyarországon)",
 };
const char *text_NANEBOVSTUPENIE_PANA[] = 
{"Nanebovstúpenie Pána",
 "Nanebevstoupení Pánì",
 "",
 "",
 "",
 "Nanebevstoupení Pánì",
 "hu_name",
 };
const char *text_VELKONOCNA_NEDELA[] = 
{"Ve¾konoèná nede¾a",
 "Nedìle Zmrtvıchvstání Pánì",
 "",
 "",
 "",
 "Nedìle Zmrtvıchvstání Pánì",
 "hu_name",
 };
const char *text_NEDELA_PANOVHO_ZMRTVYCHVSTANIA[] = 
{" - Nede¾a Pánovho zmàtvychvstania",
 "",
 "",
 "",
 "",
 "(pro dominikány není)",
 "hu_name",
 };
const char *text_NEDELA_VO_VELKONOCNEJ_OKTAVE[] = 
{"Nede¾a vo Ve¾konoènej oktáve",
 "Nedìle v oktávu velikonoèním",
 "",
 "",
 "",
 "Nedìle v oktávu velikonoèním",
 "hu_name",
 };
const char *text_DEN_VO_VELKONOCNEJ_OKTAVE[] = 
{"Ve¾konoèn%c %s",
 "%s velikonoèní",
 "",
 "",
 "",
 "%s velikonoèní",
 "hu_name",
 };
const char *text_NAJSVATEJSEJ_TROJICE[] = 
{"Najsvätejšej Trojice",
 "Nejsvìtìjší Trojice",
 "",
 "",
 "",
 "Nejsvìtìjší Trojice",
 "hu_name",
 };
const char *text_KRISTA_KRALA[] = 
{"Krista Krá¾a",
 "Jeíše Krista Krále",
 "",
 "",
 "",
 "Jeíše Krista Krále",
 "hu_name",
 };
const char *text_NAJSV_KRISTOVHO_TELA_A_KRVI[] = 
{"Najsvätejšieho Kristovho tela a krvi",
 "Tìla a krve Pánì",
 "",
 "",
 "",
 "Tìla a krve Pánì",
 "hu_name",
 };
const char *text_NAJSV_SRDCA_JEZISOVHO[] = 
{"Najsvätejšieho Srdca Jeišovho",
 "Nejsvìtìjšího Srdce Jeíšova",
 "",
 "",
 "",
 "Nejsvìtìjšího Srdce Jeíšova",
 "hu_name",
 };
const char *text_NEPOSKVRNENEHO_SRDCA_PM[] = 
{"Nepoškvrneného Srdca prebl. Panny Márie",
 "Neposkvrnìného Srdce Panny Marie",
 "",
 "",
 "",
 "Neposkvrnìného Srdce Panny Marie",
 "hu_name",
 };
const char *text_NARODENIE_PANA[] = 
{"Narodenie Pána",
 "Narození Pánì",
 "",
 "",
 "",
 "Narození Pánì",
 "hu_name",
 };
const char *text_ZOSLANIE_DUCHA_SVATEHO[] = 
{"Zoslanie Ducha Svätého",
 "Seslání Ducha svatého",
 "",
 "",
 "",
 "Seslání Ducha Svatého",
 "hu_name",
 };
const char *text_PRVA_ADVENTNA_NEDELA[] = 
{"Prvá adventná nede¾a",
 "První nedìle adventní",
 "",
 "",
 "",
 "První nedìle adventní",
 "hu_name",
 };
const char *text_NEDELA_SV_RODINY[] = 
{"Svätej rodiny Jeiša, Márie a Jozefa",
 "Sv. Rodiny Jeíše, Marie a Josefa",
 "",
 "",
 "",
 "Sv. Rodiny Jeíše, Marie a Josefa",
 "hu_name",
 };
const char *text_SPOMIENKA_PM_V_SOBOTU[] = 
{"Spomienka Panny Márie v sobotu",
 "Sobotní památka Panny Marie",
 "()",
 "Memoria S. Mariae in sabbato",
 "",
 "Sobotní památka Panny Marie",
 "hu_name",
 };
const char *text_JUN_01[] = 
{"Sv. Justína, muèeníka",
 "Sv. Justina, muèedníka",
 "",
 "",
 "",
 "Sv. Justina, muèedníka",
 "Szent Jusztínusz vértanú",
 };
const char *text_JUN_02[] = 
{"Sv. Marcelína a Petra, muèeníkov",
 "Sv. Marcelina a Petra, muèedníkù",
 "",
 "",
 "",
 "Sv. Marcelina a Petra, muèedníkù",
 "Szent Marcellínusz és Szent Péter vértanúk",
 };
const char *text_JUN_03[] = 
{"Sv. Karola Lwangu a spoloèníkov, muèeníkov",
 "Sv. Karla Lwangy a druhù, muèedníkù",
 "",
 "",
 "",
 "Sv. Karla Lwangy a druhù, muèedníkù",
 "Lwanga Szent Károly és társai, vértanúk",
 };
const char *text_JUN_05[] = 
{"Sv. Bonifáca, biskupa a muèeníka",
 "Sv. Bonifáce, biskupa a muèedníka",
 "",
 "",
 "",
 "Sv. Bonifáce, biskupa a muèedníka",
 "Szent Bonifác püspök és vértanú",
 };
const char *text_JUN_06[] = 
{"Sv. Norberta, biskupa",
 "Sv. Norberta, biskupa",
 "",
 "",
 "",
 "Sv. Norberta, biskupa",
 "Szent Norbert püspök",
 };
const char *text_JUN_09[] = 
{"Sv. Efréma, diakona a uèite¾a Cirkvi",
 "Sv. Efréma Syrského, jáhna a uèitele církve",
 "",
 "",
 "",
 "Sv. Efréma Syrského, jáhna a uèitele Církve",
 "Szent Efrém diakónus és egyháztanító",
 };
const char *text_JUN_11[] = 
{"Sv. Barnabáša, apoštola",
 "Sv. Barnabáše, apoštola",
 "",
 "",
 "",
 "Sv. Barnabáše, apoštola",
 "Szent Barnabás apostol",
 };
const char *text_JUN_13[] = 
{"Sv. Antona Paduánskeho, kòaza a uèite¾a Cirkvi",
 "Sv. Antonína z Padovy, knìze a uèitele církve",
 "",
 "",
 "",
 "Sv. Antonína z Padovy, knìze a uèitele Církve",
 "Páduai Szent Antal áldozópap és egyháztanító",
 };
const char *text_JUN_15[] = 
{"(na Slovensku nie je)",
 "Sv. Víta, muèedníka",
 "",
 "",
 "",
 "Sv. Víta, muèedníka",
 "(nincs Magyarországon)",
 };
const char *text_JUN_16[] = 
{"Sv. Neita, muèeníka",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "(nincs Magyarországon)",
 };
const char *text_JUN_19[] = 
{"Sv. Romualda, opáta",
 "Sv. Romualda, opata",
 "",
 "",
 "",
 "Sv. Romualda, opata",
 "Szent Romuald apát",
 };
const char *text_JUN_19_1[] = 
{"(na Slovensku nie je)",
 "Sv. Jana Nepomuckého Neumanna, biskupa",
 "",
 "",
 "",
 "Sv. Jana Nepomuckého Neumanna, biskupa",
 "(nincs Magyarországon)",
 };
const char *text_JUN_21[] = 
{"Sv. Alojza Gonzágu, reho¾níka",
 "Sv. Aloise Gonzagy, øeholníka",
 "",
 "",
 "",
 "Sv. Aloise Gonzagy, øeholníka",
 "Gonzága Szent Alajos szerzetes",
 };
const char *text_JUN_22_2[] = 
{"Sv. Pavlína z Noly, biskupa",
 "Sv. Paulina Nolánského, biskupa",
 "",
 "",
 "",
 "Sv. Paulina Nolánského, biskupa",
 "Nolai Szent Paulínusz püspök",
 };
const char *text_JUN_22_1[] = 
{"Sv. Jána Fishera, biskupa, a sv. Tomáša Mórusa, muèeníkov",
 "Sv. Jana Fishera, biskupa, a Tomáše Mora, muèedníkù",
 "",
 "",
 "",
 "Sv. Jana Fishera, biskupa, a Tomáše Mora, muèedníkù",
 "Fisher Szent János püspök és Morus Szent Tamás vértanúk",
 };
const char *text_JUN_24[] = 
{"Narodenie sv. Jána Krstite¾a",
 "Narození svatého Jana Køtitele",
 "",
 "",
 "",
 "Narození svatého Jana Køtitele",
 "Keresztelõ Szent János születése",
 };
const char *text_JUN_27[] = 
{"Sv. Cyrila Alexandrijského, biskupa a uèite¾a Cirkvi",
 "Sv. Cyrila Alexandrijského, biskupa a uèitele církve",
 "",
 "",
 "",
 "Sv. Cyrila Alexandrijského, biskupa a uèitele církve",
 "(nincs Magyarországon)",
 };
const char *text_JUN_27_1[] = 
{"Sv. Ladislava",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "Szent László király",
 };
const char *text_JUN_28[] = 
{"Sv. Ireneja, biskupa a muèeníka",
 "Sv. Ireneje, biskupa a muèedníka",
 "",
 "",
 "",
 "Sv. Ireneje, biskupa a muèedníka",
 "Szent Iréneusz püspök és vértanú",
 };
const char *text_JUN_29[] = 
{"Sv. Petra a Pavla, apoštolov",
 "Sv. Petra a Pavla, apoštolù",
 "",
 "",
 "",
 "Sv. Petra a Pavla, apoštolù",
 "Szent Péter és Szent Pál apostolok",
 };
const char *text_JUN_30[] = 
{"Prvıch svätıch muèeníkov Cirkvi v Ríme",
 "Svatıch prvomuèedníkù øímskıch",
 "",
 "",
 "",
 "Svatıch prvomuèedníkù øímskıch",
 "A római Egyház elsõ szent vértanúi",
 };
const char *text_JUN_30_1[] = 
{"(na Slovensku nie je)",
 "Vıroèí posvìcení katedrály sv. Václava",
 "",
 "",
 "",
 "Vıroèí posvìcení katedrály sv. Václava",
 "(nincs Magyarországon)",
 };
const char *text_JUL_03[] = 
{"Sv. Tomáša, apoštola",
 "Sv. Tomáše, apoštola",
 "",
 "",
 "",
 "Sv. Tomáše, apoštola",
 "Szent Tamás apostol",
 };
const char *text_JUL_04[] = 
{"Sv. Albety Portugalskej",
 "Sv. Albìty Portugalské",
 "",
 "",
 "",
 "Sv. Albìty Portugalské",
 "Portugáliai Szent Erzsébet",
 };
const char *text_JUL_04_1[] = 
{"(na Slovensku nie je)",
 "Sv. Prokopa, opata",
 "",
 "",
 "",
 "Sv. Prokopa, opata",
 "(nincs Magyarországon)",
 };
const char *text_JUL_05[] = 
{"Sv. Cyrila a Metoda, slovanskıch vierozvestov, apoštolov",
 "Sv. Cyrila, mnicha, a Metodìje, biskupa, patronù Evropy, hlavních patronù Moravy",
 "",
 "",
 "",
 "Sv. Cyrila, mnicha, a Metodìje, biskupa, patronù Evropy, hlavních patronù Moravy",
 "(nincs Magyarországon)",
 };
const char *text_JUL_06[] = 
{"Sv. Márie Goretti, panny a muèenice",
 "Sv. Marie Gorettiové, panny a muèednice",
 "",
 "",
 "",
 "Sv. Marie Gorettiové, panny a muèednice",
 "Goretti Szent Mária szûz és vértanú",
 };
const char *text_JUL_07[] = 
{"Sv. Antona Márie Zaccariu, kòaza",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "(nincs Magyarországon)",
 };
const char *text_JUL_09[] = 
{"Sv. Augustína Zhao Rong, kòaza, a spoloèníkov, muèeníkov",
 "Sv. Augustina ao Ronga, knìze a jeho druhù, muèedníkù",
 "",
 "",
 "",
 "Sv. Augustina ao Ronga, knìze a jeho druhù, muèedníkù",
 "(nincs Magyarországon)",
 };
const char *text_JUL_11[] = 
{"Sv. Benedikta, opáta, patróna Európy",
 "Sv. Benedikta, opata, patrona Evropy",
 "",
 "",
 "",
 "Sv. Benedikta, opata, patrona Evropy",
 "Szent Benedek apát, Európa fõvédõszentje",
 };
const char *text_JUL_13[] = 
{"Sv. Henricha",
 "Sv. Jindøicha",
 "",
 "",
 "",
 "Sv. Jindøicha",
 "Szent Henrik",
 };
const char *text_JUL_14[] = 
{"Sv. Kamila de Lellis, kòaza",
 "Sv. Kamila de Lellis, knìze",
 "",
 "",
 "",
 "Sv. Kamila de Lellis, knìze",
 "Lellisi Szent Kamill áldozópap",
 };
const char *text_JUL_14_1[] = 
{"(na Slovensku nie je)",
 "Bl. Hroznaty, muèedníka",
 "",
 "",
 "",
 "Bl. Hroznaty, muèedníka",
 "(nincs Magyarországon)",
 };
const char *text_JUL_15[] = 
{"Sv. Bonaventúru, biskupa a uèite¾a Cirkvi",
 "Sv. Bonaventury, biskupa a uèitele církve",
 "",
 "",
 "",
 "Sv. Bonaventury, biskupa a uèitele Církve",
 "Szent Bonaventúra püspök és egyháztanító",
 };
const char *text_JUL_16[] = 
{"Prebl. Panny Márie Karmelskej",
 "Panny Marie Karmelské",
 "",
 "",
 "",
 "Panny Marie Karmelské",
 "Kármel-hegyi Boldogasszony",
 };
const char *text_JUL_16_1[] = 
{"(na Slovensku nie je)",
 "Vıroèí posvìcení katedrály Boského Spasitele",
 "",
 "",
 "",
 "Vıroèí posvìcení katedrály Boského Spasitele",
 "(nincs Magyarországon)",
 };
const char *text_JUL_17_1[] = 
{"Sv. Andreja-Svorada a Benedikta, pustovníkov",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "Szent Zoerárd-András és Benedek remeték",
 };
const char *text_JUL_17_2[] = 
{"(na Slovensku nie je)",
 "Bl. Èeslava a sv. Hyacinta, knìí",
 "",
 "",
 "",
 "Bl. Èeslava a sv. Hyacinta, knìí",
 "(nincs Magyarországon)",
 };
const char *text_JUL_20[] = 
{"(na Slovensku nie je)",
 "Sv. Apolináøe, biskupa a muèedníka",
 "",
 "",
 "",
 "Sv. Apolináøe, biskupa a muèedníka",
 "(nincs Magyarországon)",
 };
const char *text_JUL_21[] = 
{"Sv. Vavrinca z Brindisi, kòaza a uèite¾a Cirkvi",
 "Sv. Vavøince z Brindisi, knìze a uèitele církve",
 "",
 "",
 "",
 "Sv. Vavøince z Brindisi, knìze a uèitele Církve",
 "Brindisi Szent Lõrinc Áldozópap és egyháztanító",
 };
const char *text_JUL_22[] = 
{"Sv. Márie Magdalény",
 "Sv. Marie Magdalény",
 "",
 "",
 "",
 "Sv. Marie Magdalény",
 "Szent Mária Magdolna",
 };
const char *text_JUL_23[] = 
{"Sv. Brigity, reho¾níèky, spolupatrónky Európy",
 "Sv. Brigity, øeholnice patronky Evropy",
 "",
 "",
 "",
 "Sv. Brigity, øeholnice patronky Evropy",
 "Szent Brigitta szerzetesnõ",
 };
const char *text_JUL_24[] = 
{"Sv. Charbela Makhlufa, kòaza",
 "Sv. Šarbela Makhlúfa, knìze",
 "",
 "",
 "",
 "Sv. Šarbela Makhlúfa, knìze",
 "(nincs Magyarországon)",
 };
const char *text_JUL_25[] = 
{"Sv. Jakuba, apoštola",
 "Sv. Jakuba, apoštola",
 "",
 "",
 "",
 "Sv. Jakuba, apoštola",
 "Szent Jakab apostol",
 };
const char *text_JUL_26[] = 
{"Sv. Joachima a Anny, rodièov Panny Márie",
 "Sv. Jáchyma a Anny, rodièù Panny Marie",
 "",
 "",
 "",
 "Sv. Jáchyma a Anny, rodièù Panny Marie",
 "Szent Joakim és Szent Anna, a Boldogságos Szûz Mária szülei",
 };
const char *text_JUL_27[] = 
{"Sv. Gorazda a spoloèníkov",
 "Sv. Gorazda a druhù",
 "",
 "",
 "",
 "Sv. Gorazda a druhù",
 "(nincs Magyarországon)",
 };
const char *text_JUL_29[] = 
{"Sv. Marty",
 "Sv. Marty",
 "",
 "",
 "",
 "Sv. Marty",
 "Szent Márta",
 };
const char *text_JUL_30[] = 
{"Sv. Petra Chryzológa, biskupa a uèite¾a Cirkvi",
 "Sv. Petra Chryzologa, biskupa a uèitele církve",
 "",
 "",
 "",
 "Sv. Petra Chryzologa, biskupa a uèitele církve",
 "Aranyszavú (Krizologosz) Szent Péter püspök és egyháztanító",
 };
const char *text_JUL_30_1[] = 
{"Bl. Zdenky Schelingovej, panny a muèenice",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "(nincs Magyarországon)",
 };
const char *text_JUL_31[] = 
{"Sv. Ignáca z Loyoly, kòaza",
 "Sv. Ignáce z Loyoly, knìze",
 "",
 "",
 "",
 "Sv. Ignáce z Loyoly, knìze",
 "Loyolai Szent Ignác áldozópap",
 };
const char *text_AUG_01[] = 
{"Sv. Alfonza Márie de Ligouri, biskupa a uèite¾a Cirkvi",
 "Sv. Alfonsa z Liguori, biskupa a uèitele církve",
 "",
 "",
 "",
 "Sv. Alfonsa z Liguori, biskupa a uèitele Církve",
 "Liguori Szent Alfonz Mária püspök és egyháztanító",
 };
const char *text_AUG_02_1[] = 
{"Sv. Euzébia Vercellského, biskupa",
 "Sv. Eusebia z Vercelli, biskupa",
 "",
 "",
 "",
 "Sv. Eusebia z Vercelli, biskupa",
 "Vercelli Szent Özséb püspök",
 };
const char *text_AUG_02_2[] = 
{"Sv. Petra Juliána Eymard, kòaza",
 "Sv. Petra Juliána Eymarda, knìze",
 "",
 "",
 "",
 "Sv. Petra Juliána Eymarda, knìze",
 "(nincs Magyarországon)",
 };
const char *text_AUG_04[] = 
{"Sv. Jána Márie Vianneya, kòaza",
 "Sv. Jana Marie Vianneye, knìze",
 "",
 "",
 "",
 "Sv. Jana Marie Vianneye, knìze",
 "Vianney Szent János Mária áldozópap",
 };
const char *text_AUG_05[] = 
{"Vıroèie posviacky hlavnej mariánskej baziliky v Ríme",
 "Posvìcení øímské baziliky Panny Marie",
 "",
 "",
 "",
 "Posvìcení øímské baziliky Panny Marie",
 "Szûz Mária római fõtemplomának felszentelése (Havas Boldogasszony)",
 };
const char *text_AUG_06[] = 
{"Premenenie Pána",
 "Promìnìní Pánì",
 "",
 "",
 "",
 "Promìnìní Pánì",
 "Urunk Színeváltozása",
 };
const char *text_AUG_07_1[] = 
{"Sv. Sixta II., pápea, a jeho spoloèníkov, muèeníkov",
 "Sv. Sixta II., papee, a druhù, muèedníkù",
 "",
 "",
 "",
 "Sv. Sixta II., papee, a druhù, muèedníkù",
 "Szent II. Szixtusz pápa és társai vértanúk",
 };
const char *text_AUG_07_2[] = 
{"Sv. Kajetána, kòaza",
 "Sv. Kajetána, knìze",
 "",
 "",
 "",
 "Sv. Kajetána, knìze",
 "Szent Kajetán áldozópap",
 };
const char *text_AUG_08[] = 
{"Sv. Dominika, kòaza",
 "Sv. Dominika, knìze",
 "",
 "",
 "",
 "Sv. Dominika, knìze",
 "Szent Domonkos áldozópap",
 };
const char *text_AUG_09[] = 
{"Sv. Terézie Benedikty, reho¾níèky a muèenice, spolupatrónky Európy",
 "Sv. Terezie Benedikty, panny a muèednice, patronky Evropy",
 "",
 "",
 "",
 "Sv. Terezie Benedikty, panny a muèednice, patronky Evropy",
 "(nincs Magyarországon)",
 };
const char *text_AUG_10[] = 
{"Sv. Vavrinca, diakona a muèeníka",
 "Sv. Vavøince, muèedníka",
 "",
 "",
 "",
 "Sv. Vavøince, muèedníka",
 "Szent Lõrinc diakónus és vértanú",
 };
const char *text_AUG_11[] = 
{"Sv. Kláry, panny",
 "Sv. Kláry, panny",
 "",
 "",
 "",
 "Sv. Kláry, panny",
 "Szent Klára szûz",
 };
const char *text_AUG_12[] = 
{"Sv. Jany Františky de Chantal, reho¾níèky",
 "Sv. Jany Františky de Chantal, øeholnice",
 "",
 "",
 "",
 "Sv. Jany Františky de Chantal, øeholnice",
 "(nincs Magyarországon)",
 };
const char *text_AUG_13[] = 
{"Sv. Ponciána, pápea, a sv. Hypolita, kòaza, muèeníkov",
 "Sv. Ponciána, papee, a Hippolyta, knìze, muèedníkù",
 "",
 "",
 "",
 "Sv. Ponciána, papee, a Hippolyta, knìze, muèedníkù",
 "Szent Ponciánusz pápa és szent Hippolitusz áldozópap és vértanúk",
 };
const char *text_AUG_14[] = 
{"Sv. Maximiliána Kolbeho, kòaza a muèeníka",
 "Sv. Maxmiliána Marie Kolbeho, knìze a muèedníka",
 "",
 "",
 "",
 "Sv. Maxmiliána Marie Kolbeho, knìze a muèedníka",
 "Szent Maximilián Mária Kolbe áldozópap és vértanú",
 };
const char *text_AUG_15[] = 
{"Nanebovzatie prebl. Panny Márie",
 "Nanebevzetí Panny Marie",
 "",
 "",
 "",
 "Nanebevzetí Panny Marie",
 "Szûz Mária Mennybevétele (Nagyboldogasszony)",
 };
const char *text_AUG_16[] = 
{"Sv. Štefana Uhorského",
 "Sv. Štìpána Uherského",
 "",
 "",
 "",
 "Sv. Štìpána Uherského",
 "(nincs Magyarországon)",
 };
const char *text_AUG_19[] = 
{"Sv. Jána Eudes, kòaza",
 "Sv. Jana Eudese, knìze",
 "",
 "",
 "",
 "Sv. Jana Eudese, knìze",
 "Eudes Szent János áldozópap",
 };
const char *text_AUG_20[] = 
{"Sv. Bernarda, opáta a uèite¾a Cirkvi",
 "Sv. Bernarda, opata a uèitele církve",
 "",
 "",
 "",
 "Sv. Bernarda, opata a uèitele Církve",
 "(nincs Magyarországon)",
 };
const char *text_AUG_21[] = 
{"Sv. Pia X., pápea",
 "Sv. Pia X., papee",
 "",
 "",
 "",
 "Sv. Pia X., papee",
 "Szent X. Piusz pápa",
 };
const char *text_AUG_22[] = 
{"Prebl. Panny Márie Krá¾ovnej",
 "Panny Marie Královny",
 "",
 "",
 "",
 "Panny Marie Královny",
 "Boldogságos Szûz Mária Királynõ",
 };
const char *text_AUG_23[] = 
{"Sv. Rueny Limskej, panny",
 "Sv. Rùeny z Limy, panny",
 "",
 "",
 "",
 "Sv. Rùeny z Limy, panny",
 "Limai Szent Róza szûz",
 };
const char *text_AUG_24[] = 
{"Sv. Bartolomeja, apoštola",
 "Sv. Bartolomìje, apoštola",
 "",
 "",
 "",
 "Sv. Bartolomìje, apoštola",
 "Szent Bertalan apostol",
 };
const char *text_AUG_25_1[] = 
{"Sv. Jozefa de Calasanz, kòaza",
 "Sv. Josefa Kalasanského, knìze",
 "",
 "",
 "",
 "Sv. Josefa Kalasanského, knìze",
 "Kalazanci Szent József áldozópap",
 };
const char *text_AUG_25_2[] = 
{"Sv. ¼udovíta",
 "Sv. Ludvíka",
 "",
 "",
 "",
 "Sv. Ludvíka",
 "Szent Lajos",
 };
const char *text_AUG_25_3[] = 
{"(na Slovensku nie je)",
 "Sv. Benedikta, Jana, Matouše, Izáka a Kristina, muèedníkù",
 "",
 "",
 "",
 "Sv. Benedikta, Jana, Matouše, Izáka a Kristina, muèedníkù",
 "(nincs Magyarországon)",
 };
const char *text_AUG_27[] = 
{"Sv. Moniky",
 "Sv. Moniky",
 "",
 "",
 "",
 "Sv. Moniky",
 "Szent Mónika",
 };
const char *text_AUG_28[] = 
{"Sv. Augustína, biskupa a uèite¾a Cirkvi",
 "Sv. Augustina, biskupa a uèitele církve",
 "",
 "",
 "",
 "Sv. Augustina, biskupa a uèitele Církve",
 "Szent Ágoston püspök és egyháztanító",
 };
const char *text_AUG_29[] = 
{"Muèenícka smr sv. Jána Krstite¾a",
 "Umuèení svatého Jana Køtitele",
 "",
 "",
 "",
 "Umuèení svatého Jana Køtitele",
 "Keresztelõ Szent János vértanúsága",
 };
const char *text_AUG_30[] = 
{"Vıroèie posviacky katedrálneho chrámu v Trnave",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "(nincs Magyarországon)",
 };
const char *text_SEP_03[] = 
{"Sv. Gregora Ve¾kého, pápea a uèite¾a Cirkvi",
 "Sv. Øehoøe Velikého, papee a uèitele církve",
 "",
 "",
 "",
 "Sv. Øehoøe Velikého, papee a uèitele Církve",
 "Nagy Szent Gergely pápa és egyháztanító",
 };
const char *text_SEP_06[] = 
{"Vıroèie posviacky katedrálneho chrámu v Košiciach",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "(nincs Magyarországon)",
 };
const char *text_SEP_07[] = 
{"Sv. Marka Kriina, Melichara Grodzieckého a Štefana Pongrácza, kòazov a muèeníkov",
 "Sv. Melichara Grodeckého, knìze a muèedníka",
 "",
 "",
 "",
 "Sv. Melichara Grodeckého, knìze a muèedníka",
 "(nincs Magyarországon)",
 };
const char *text_SEP_08[] = 
{"Narodenie prebl. Panny Márie",
 "Narození Panny Marie",
 "",
 "",
 "",
 "Narození Panny Marie",
 "Szûz Mária Születése (Kisboldogasszony)",
 };
const char *text_SEP_09[] = 
{"Sv. Petra Clavera, kòaza",
 "Sv. Petra Klavera, knìze",
 "",
 "",
 "",
 "Sv. Petra Klavera, knìze",
 "(nincs Magyarországon)",
 };
const char *text_SEP_10[] = 
{"(na Slovensku nie je)",
 "Bl. Karla Spinoly, knìze a muèedníka",
 "",
 "",
 "",
 "Bl. Karla Spinoly, knìze a muèedníka",
 "(nincs Magyarországon)",
 };
const char *text_SEP_12[] = 
{"Mena prebl. Panny Márie",
 "Jména Panny Marie",
 "",
 "",
 "",
 "Jména Panny Marie",
 "Szûz Mária Szent Neve",
 };
const char *text_SEP_13[] = 
{"Sv. Jána Zlatoústeho, biskupa a uèite¾a Cirkvi",
 "Sv. Jana Zlatoústého, biskupa a uèitele církve",
 "",
 "",
 "",
 "Sv. Jana Zlatoústého, biskupa a uèitele církve",
 "Aranyszájú (Krizosztomosz) Szent János püspök és egyháztanító",
 };
const char *text_SEP_14[] = 
{"Povıšenie svätého kría",
 "Povıšení svatého køíe",
 "",
 "",
 "",
 "Povıšení svatého køíe",
 "A Szent Kereszt felmagasztalása",
 };
const char *text_SEP_15[] = 
{"Sedembolestnej Panny Márie, patrónky Slovenska",
 "Panny Marie Bolestné",
 "",
 "",
 "",
 "Panny Marie Bolestné",
 "A Fájdalmas Szûzanya",
 };
const char *text_SEP_16_CZ[] = 
{"(na Slovensku nie je)",
 "Sv. Ludmily, muèednice",
 "",
 "",
 "",
 "Sv. Ludmily, muèednice",
 "(nincs Magyarországon)",
 };
const char *text_SEP_16[] = 
{"Sv. Kornélia, pápea, a sv. Cypriána, biskupa, muèeníkov",
 "Sv. Kornélia, papee, a Cypriána, biskupa, muèedníkù",
 "",
 "",
 "",
 "Sv. Kornélia, papee, a Cypriána, biskupa, muèedníkù",
 "Szent Kornél pápa és Szent Ciprián püspök és vértanúk",
 };
const char *text_SEP_17[] = 
{"Sv. Róberta Bellarmína, biskupa a uèite¾a Cirkvi",
 "Sv. Roberta Bellarmina, biskupa a uèitele církve",
 "",
 "",
 "",
 "Sv. Roberta Bellarmina, biskupa a uèitele Církve",
 "Bellarmin Szent Róbert püspök és egyháztanító",
 };
const char *text_SEP_19[] = 
{"Sv. Januára, biskupa a muèeníka",
 "Sv. Januária, biskupa a muèedníka",
 "",
 "",
 "",
 "Sv. Januária, biskupa a muèedníka",
 "Szent Januáriusz püspök és vértanú",
 };
const char *text_SEP_20[] = 
{"Sv. Andreja Kim Taegona, kòaza, a sv. Pavla Chong Hasanga a spoloèníkov, muèeníkov",
 "Sv. Ondøeje Kim Taegona, knìze, Pavla Chong Hasanga a druhù, muèedníkù",
 "",
 "",
 "",
 "Sv. Ondøeje Kim Taegona, knìze, Pavla Chong Hasanga a druhù, muèedníkù",
 "Kim Taegon Szent András áldozópap, Csong Haszang Szent Pál és társaik, vértanúk",
 };
const char *text_SEP_20_2[] = 
{"(na Slovensku nie je)",
 "Vıroèí posvìcení katedrály sv. Štìpána",
 "",
 "",
 "",
 "Vıroèí posvìcení katedrály sv. Štìpána",
 "(nincs Magyarországon)",
 };
const char *text_SEP_21[] = 
{"Sv. Matúša, apoštola a evanjelistu",
 "Sv. Matouše, apoštola a evangelisty",
 "",
 "",
 "",
 "Sv. Matouše, apoštola a evangelisty",
 "Szent Máté apostol és evangelista",
 };
const char *text_SEP_22[] = 
{"Sv. Emeráma, biskupa a muèeníka",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "(nincs Magyarországon)",
 };
const char *text_SEP_23[] = 
{"Sv. Pia z Pietrelèiny, kòaza",
 "Sv. Pia z Pietrelciny, knìze",
 "",
 "",
 "",
 "Sv. Pia z Pietrelciny, knìze",
 "(nincs Magyarországon)",
 };
const char *text_SEP_24[] = 
{"Vıroèie posviacky katedrálneho chrámu v Banskej Bystrici",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "(nincs Magyarországon)",
 };
const char *text_SEP_26[] = 
{"Sv. Kozmu a Damiána, muèeníkov",
 "Sv. Kosmy a Damiána, muèedníkù",
 "",
 "",
 "",
 "Sv. Kosmy a Damiána, muèedníkù",
 "Szent Kozma és Damján vértanúk",
 };
const char *text_SEP_27[] = 
{"Sv. Vincenta de Paul, kòaza",
 "Sv. Vincence z Paula, knìze",
 "",
 "",
 "",
 "Sv. Vincence z Paula, knìze",
 "Páli Szent Vince áldozópap",
 };
const char *text_SEP_28[] = 
{"Sv. Václava, muèeníka",
 "Sv. Václava, muèedníka, hlavního patrona èeského národa",
 "",
 "",
 "",
 "Sv. Václava, muèedníka, hlavního patrona èeského národa",
 "Szent Vencel vértanú",
 };
const char *text_SEP_28_2[] = 
{"Sv. Vavrinca Ruiza a spoloèníkov, muèeníkov",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "(nincs Magyarországon)",
 };
const char *text_SEP_29[] = 
{"Sv. Michala, Gabriela a Rafaela, archanjelov",
 "Sv. Michaela, Gabriela a Rafaela, archandìlù",
 "",
 "",
 "",
 "Sv. Michaela, Gabriela a Rafaela, archandìlù",
 "Szent Mihály, Szent Gábor és Szent Rafael fõangyalok",
 };
const char *text_SEP_30[] = 
{"Sv. Hieronyma, kòaza a uèite¾a Cirkvi",
 "Sv. Jeronıma, knìze a uèitele církve",
 "",
 "",
 "",
 "Sv. Jeronıma, knìze a uèitele Církve",
 "Szent Jeromos áldozópap és egyháztanító",
 };
const char *text_OKT_01[] = 
{"Sv. Terézie z Lisieux, panny a uèite¾ky Cirkvi",
 "Sv. Terezie od Dítìte Jeíše, panny",
 "",
 "",
 "",
 "Sv. Terezie od Dítìte Jeíše, panny",
 "A Gyermek Jézusról nevezett (Lisieux-i) Szent Teréz Szûz",
 };
const char *text_OKT_02[] = 
{"Svätıch anjelov strácov",
 "Svatıch andìlù stránıch",
 "",
 "",
 "",
 "Svatıch andìlù stránıch",
 "Szent Õrzõangyalok",
 };
const char *text_OKT_04[] = 
{"Sv. Františka Assiského",
 "Sv. Františka z Assisi",
 "",
 "",
 "",
 "Sv. Františka z Assisi",
 "Assisi Szent Ferenc",
 };
const char *text_OKT_06[] = 
{"Sv. Bruna, kòaza",
 "Sv. Bruna, knìze",
 "",
 "",
 "",
 "Sv. Bruna, knìze",
 "Szent Brúnó áldozópap",
 };
const char *text_OKT_07[] = 
{"Ruencovej prebl. Panny Márie",
 "Panny Marie Rùencové",
 "",
 "",
 "",
 "Panny Marie Rùencové",
 "Rózsafûzér Királynõje",
 };
const char *text_OKT_09_1[] = 
{"Sv. Dionızia, biskupa, a spoloèníkov, muèeníka",
 "Sv. Dionısia, biskupa, a druhù, muèedníkù",
 "",
 "",
 "",
 "Sv. Dionısia, biskupa, a druhù, muèedníkù",
 "Szent Dénes püspök és társai vértanúk",
 };
const char *text_OKT_09_2[] = 
{"Sv. Jána Leonardiho, kòaza",
 "Sv. Jana Leonardiho, knìze",
 "",
 "",
 "",
 "Sv. Jana Leonardiho, knìze",
 "Leonardi Szent János áldozópap",
 };
const char *text_OKT_12[] = 
{"(na Slovensku nie je)",
 "Sv. Radima, biskupa",
 "",
 "",
 "",
 "Sv. Radima, biskupa",
 "(nincs Magyarországon)",
 };
const char *text_OKT_14[] = 
{"Sv. Kalixta I., pápea a muèeníka",
 "Sv. Kalista I., papee a muèedníka",
 "",
 "",
 "",
 "Sv. Kalista I., papee a muèedníka",
 "Szent I. Kallixtusz pápa és vértanú",
 };
const char *text_OKT_15[] = 
{"Sv. Terézie z Avily, panny a uèite¾ky Cirkvi",
 "Sv. Terezie od Jeíše, panny a uèitelky církve",
 "",
 "",
 "",
 "Sv. Terezie od Jeíše, panny a uèitelky Církve",
 "A Jézusról nevezett (Avilai) Szent Teréz szûz és egyháztanító",
 };
const char *text_OKT_16_2[] = 
{"Sv. Hedvigy, reho¾níèky",
 "Sv. Hedviky, øeholnice, hlavní patronky Slezska",
 "",
 "",
 "",
 "Sv. Hedviky, øeholnice, hlavní patronky Slezska",
 "Szent Hedvig szerzetesnõ",
 };
const char *text_OKT_16_1[] = 
{"Sv. Margity Márie Alacoque, panny",
 "Sv. Markéty Marie Alacoque, panny",
 "",
 "",
 "",
 "Sv. Markéty Marie Alacoque, panny",
 "Alacoque Szent Margit Mária szûz",
 };
const char *text_OKT_17[] = 
{"Sv. Ignáca Antiochijského, biskupa a muèeníka",
 "Sv. Ignáce Antiochijského, biskupa a muèedníka",
 "",
 "",
 "",
 "Sv. Ignáce Antiochijského, biskupa a muèedníka",
 "Antiochiai Szent Ignác püspök és vértanú",
 };
const char *text_OKT_18[] = 
{"Sv. Lukáša, evanjelistu",
 "Sv. Lukáše, evangelisty",
 "",
 "",
 "",
 "Sv. Lukáše, evangelisty",
 "Szent Lukács evangelista",
 };
const char *text_OKT_19_1[] = 
{"Sv. Jána de Brébeuf a sv. Izáka Jogues, kòazov, a ich spoloèníkov, muèeníkov",
 "Sv. Jana de Brébeuf a Izáka Joguese, knìí, a druhù, muèedníkù",
 "",
 "",
 "",
 "Sv. Jana de Brébeuf a Izáka Joguese, knìí, a druhù, muèedníkù",
 "De Brébeuf Szent János és Jogues Szent Izsák áldozópap és társaik vértanúk",
 };
const char *text_OKT_19_2[] = 
{"Sv. Pavla z Kría, kòaza",
 "Sv. Pavla od Køíe, knìze",
 "",
 "",
 "",
 "Sv. Pavla od Køíe, knìze",
 "Keresztes Szent Pál áldozópap",
 };
const char *text_OKT_23[] = 
{"Sv. Jána Kapistránskeho, kòaza",
 "Sv. Jana Kapistránského, knìze",
 "",
 "",
 "",
 "Sv. Jana Kapistránského, knìze",
 "Kapisztrán Szent János áldozópap",
 };
const char *text_OKT_24[] = 
{"Sv. Antona Márie Clareta, biskupa",
 "Sv. Antonína Marie Klareta, biskupa",
 "",
 "",
 "",
 "Sv. Antonína Marie Klareta, biskupa",
 "Claret Szent Antal Mária püspök",
 };
const char *text_OKT_25[] = 
{"Vıroèie posviacky katedrálneho chrámu v Spišskom Podhradí",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "(nincs Magyarországon)",
 };
const char *text_OKT_26[] = 
{"Vıroèie posviacky chrámov, ktorıch deò posviacky je neznámy",
 "Vıroèí posvìcení chrámu, jejich den dedikace není známı",
 "",
 "",
 "",
 "Vıroèí posvìcení chrámu, jejich den dedikace není známı",
 "(nincs Magyarországon)",
 };
const char *text_OKT_27[] = 
{"Vıroèie posviacky katedrálneho chrámu v Roòave",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "(nincs Magyarországon)",
 };
const char *text_OKT_28[] = 
{"Sv. Šimona a Júdu, apoštolov",
 "Sv. Šimona a Judy, apoštolù",
 "",
 "",
 "",
 "Sv. Šimona a Judy, apoštolù",
 "Szent Simon és Szent Júdás apostol",
 };
const char *text_OKT_29[] = 
{"(na Slovensku nie je)",
 "Bl. Marie Restituty Kafkové, panny a muèednice",
 "",
 "",
 "",
 "Bl. Marie Restituty Kafkové, panny a muèednice",
 "(nincs Magyarországon)",
 };
const char *text_OKT_30[] = 
{"(na Slovensku nie je)",
 "Vıroèí posvìcení katedrály Svatého Ducha",
 "",
 "",
 "",
 "Vıroèí posvìcení katedrály Svatého Ducha",
 "(nincs Magyarországon)",
 };
const char *text_OKT_31[] = 
{"(na Slovensku nie je)",
 "Sv. Wolfganga, biskupa",
 "",
 "",
 "",
 "Sv. Wolfganga, biskupa",
 "(nincs Magyarországon)",
 };
const char *text_NOV_01[] = 
{"Všetkıch svätıch",
 "Všech svatıch",
 "",
 "",
 "",
 "Všech svatıch",
 "Mindenszentek",
 };
const char *text_NOV_02[] = 
{"Všetkıch vernıch zosnulıch",
 "Vzpomínka na všechny vìrné zemøelé",
 "",
 "",
 "",
 "Vzpomínka na všechny vìrné zemøelé",
 "Halottak napja",
 };
const char *text_NOV_03[] = 
{"Sv. Martina de Porres, reho¾níka",
 "Sv. Martina de Porres, øeholníka",
 "",
 "",
 "",
 "Sv. Martina de Porres, øeholníka",
 "Porres Szent Márton szerzetes",
 };
const char *text_NOV_04[] = 
{"Sv. Karola Borromea, biskupa",
 "Sv. Karla Boromejského, biskupa",
 "",
 "",
 "",
 "Sv. Karla Boromejského, biskupa",
 "Borromeo Szent Károly püspök",
 };
const char *text_NOV_05[] = 
{"Sv. Imricha",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "Szent Imre herceg",
 };
const char *text_NOV_09[] = 
{"Vıroèie posviacky Lateránskej baziliky",
 "Posvìcení lateránské baziliky",
 "",
 "",
 "",
 "Posvìcení lateránské baziliky",
 "A lateráni-bazilika felszentelése",
 };
const char *text_NOV_10[] = 
{"Sv. Leva Ve¾kého, pápea a uèite¾a Cirkvi",
 "Sv. Lva Velikého, papee a uèitele církve",
 "",
 "",
 "",
 "Sv. Lva Velikého, papee a uèitele církve",
 "Nagy Szent Leó pápa és egyháztanító",
 };
const char *text_NOV_11[] = 
{"Sv. Martina z Tours, biskupa",
 "Sv. Martina, biskupa",
 "",
 "",
 "",
 "Sv. Martina, biskupa",
 "Tours-i Szent Márton püspök",
 };
const char *text_NOV_12[] = 
{"Sv. Jozafáta, biskupa a muèeníka",
 "Sv. Josafata, biskupa a muèedníka",
 "",
 "",
 "",
 "Sv. Josafata, biskupa a muèedníka",
 "Szent Jozafát püspök és vértanú",
 };
const char *text_NOV_13[] = 
{"(na Slovensku nie je)",
 "Sv. Aneky Èeské, panny",
 "",
 "",
 "",
 "Sv. Aneky Èeské, panny",
 "(nincs Magyarországon)",
 };
const char *text_NOV_15[] = 
{"Sv. Alberta Ve¾kého, biskupa a uèite¾a Cirkvi",
 "Sv. Alberta Velikého, biskupa a uèitele církve",
 "",
 "",
 "",
 "Sv. Alberta Velikého, biskupa a uèitele Církve",
 "Nagy Szent Albert püspök és egyháztanító",
 };
const char *text_NOV_16_1[] = 
{"Sv. Margity Škótskej",
 "Sv. Markéty Skotské",
 "",
 "",
 "",
 "Sv. Markéty Skotské",
 "Skóciai Szent Margit",
 };
const char *text_NOV_16_2[] = 
{"Sv. Gertrúdy, panny",
 "Sv. Gertrudy, panny",
 "",
 "",
 "",
 "Sv. Gertrudy, panny",
 "(nincs Magyarországon)",
 };
const char *text_NOV_17[] = 
{"Sv. Albety Uhorskej, reho¾níèky",
 "Sv. Albìty Uherské, øeholnice",
 "",
 "",
 "",
 "Sv. Albìty Uherské, øeholnice",
 "(nincs Magyarországon)",
 };
const char *text_NOV_18[] = 
{"Vıroèie posviacky bazilík sv. Petra a sv. Pavla, apoštolov",
 "Posvìcení øímskıch bazilik svatıch apoštolù Petra a Pavla",
 "",
 "",
 "",
 "Posvìcení øímskıch bazilik svatıch apoštolù Petra a Pavla",
 "Szent Péter- és Szent Pál-Bazilikák felszentelése",
 };
const char *text_NOV_20[] = 
{"Vıroèie posviacky katedrálneho chrámu v Nitre",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "(nincs Magyarországon)",
 };
const char *text_NOV_21[] = 
{"Obetovanie prebl. Panny Márie",
 "Zasvìcení Panny Marie v Jeruzalémì",
 "",
 "",
 "",
 "Zasvìcení Panny Marie v Jeruzalémì",
 "A Boldogságos Szûz Mária bemutatása a templomban",
 };
const char *text_NOV_22[] = 
{"Sv. Cecílie, panny a muèenice",
 "Sv. Cecilie, panny a muèednice",
 "",
 "",
 "",
 "Sv. Cecilie, panny a muèednice",
 "Szent Cecília szûz és vértanú",
 };
const char *text_NOV_23_1[] = 
{"Sv. Klementa I. pápea a muèeníka",
 "Sv. Klementa I., papee a muèedníka",
 "",
 "",
 "",
 "Sv. Klementa I., papee a muèedníka",
 "Szent I. Kelemen pápa és vértanú",
 };
const char *text_NOV_23_2[] = 
{"Sv. Kolumbána, opáta",
 "Sv. Kolumbána, opata",
 "",
 "",
 "",
 "Sv. Kolumbána, opata",
 "Szent Kolumbán apát",
 };
const char *text_NOV_24[] = 
{"Sv. Ondreja Dung-Laca a spoloèníkov, muèeníkov",
 "Sv. Ondøeje Dung-Laca, knìze, a druhù, muèedníkù",
 "",
 "",
 "",
 "Sv. Ondøeje Dung-Laca, knìze, a druhù, muèedníkù",
 "Dung-Lac Szent András áldozópap és társai vértanúk",
 };
const char *text_NOV_25[] = 
{"Sv. Kataríny Alexandrijskej, panny a muèenice",
 "Sv. Kateøiny Alexandrijské, panny a muèednice",
 "",
 "",
 "",
 "Sv. Kateøiny Alexandrijské, panny a muèednice",
 "(nincs Magyarországon)",
 };
const char *text_NOV_30[] = 
{"Sv. Ondreja, apoštola",
 "Sv. Ondøeje, apoštola",
 "",
 "",
 "",
 "Sv. Ondøeje, apoštola",
 "Szent András apostol",
 };
const char *text_DEC_01[] = 
{"(na Slovensku nie je)",
 "Sv. Edmunda Kampiána, knìze a muèedníka",
 "",
 "",
 "",
 "Sv. Edmunda Kampiána, knìze a muèedníka",
 "(nincs Magyarországon)",
 };
const char *text_DEC_02[] = 
{"(na Slovensku nie je)",
 "Vıroèí posvìcení katedrály sv. Bartolomìje",
 "",
 "",
 "",
 "Vıroèí posvìcení katedrály sv. Bartolomìje",
 "(nincs Magyarországon)",
 };
const char *text_DEC_03[] = 
{"Sv. Františka Xaverského, kòaza",
 "Sv. Františka Xaverského, knìze",
 "",
 "",
 "",
 "Sv. Františka Xaverského, knìze",
 "Xavéri Szent Ferenc áldozópap",
 };
const char *text_DEC_04[] = 
{"Sv. Jána Damascénskeho, kòaza a uèite¾a Cirkvi",
 "Sv. Jana Damašského, knìze a uèitele církve",
 "",
 "",
 "",
 "Sv. Jana Damašského, knìze a uèitele Církve",
 "Damaszkuszi Szent János áldozópap és egyháztanító",
 };
const char *text_DEC_06[] = 
{"Sv. Mikuláša, biskupa",
 "Sv. Mikuláše, biskupa",
 "",
 "",
 "",
 "Sv. Mikuláše, biskupa",
 "Szent Miklós püspök",
 };
const char *text_DEC_07[] = 
{"Sv. Ambróza, biskupa a uèite¾a Cirkvi",
 "Sv. Ambroe, biskupa a uèitele církve",
 "",
 "",
 "",
 "Sv. Ambroe, biskupa a uèitele Církve",
 "Szent Ambrus püspök és egháztanító",
 };
const char *text_DEC_08[] = 
{"Nepoškvrnené poèatie Panny Márie",
 "Panny Marie, poèaté bez poskvrny prvotního høíchu",
 "",
 "",
 "",
 "Panny Marie, poèaté bez poskvrny prvotního høíchu",
 "A Boldogságos Szûz Mária szeplõtelen fogantatása",
 };
const char *text_DEC_09[] = 
{"(nie je)",
 "(není)",
 "",
 "",
 "",
 "Sv. Jana Didaka Cuauhtlatoazina",
 "(nincs Magyarországon)",
 };
const char *text_DEC_11[] = 
{"Sv. Damaza I., pápea",
 "Sv. Damasa I., papee",
 "",
 "",
 "",
 "Sv. Damasa I., papee",
 "Szent I. Damazusz pápa",
 };
const char *text_DEC_12[] = 
{"(nie je)",
 "Panny Marie Guadalupské",
 "",
 "",
 "",
 "Panny Marie Guadalupské",
 "(nincs Magyarországon)",
 };
const char *text_DEC_13[] = 
{"Sv. Lucie, panny a muèenice",
 "Sv. Lucie, panny a muèednice",
 "",
 "",
 "",
 "Sv. Lucie, panny a muèednice",
 "Szent Lúcia szûz és vértanú",
 };
const char *text_DEC_14[] = 
{"Sv. Jána z Kría, kòaza a uèite¾a Cirkvi",
 "Sv. Jana od Køíe, knìze a uèitele církve",
 "",
 "",
 "",
 "Sv. Jana od Køíe, knìze a uèitele Církve",
 "Keresztes Szent János áldozópap és egyháztanító",
 };
const char *text_DEC_21[] = 
{"Sv. Petra Kanízia, kòaza a uèite¾a Cirkvi",
 "Sv. Petra Kanisia, knìze a uèitele církve",
 "",
 "",
 "",
 "Sv. Petra Kanisia, knìze a uèitele Církve",
 "Kaníziusz Szent Péter áldozópap és egyháztaíntó",
 };
const char *text_DEC_22[] = 
{"(na Slovensku nie je)",
 "Vıroèí posvìcení katedrály Sv. Mikuláše",
 "",
 "",
 "",
 "Vıroèí posvìcení katedrály Sv. Mikuláše",
 "(nincs Magyarországon)",
 };
const char *text_DEC_23[] = 
{"Sv. Jána Kentského, kòaza",
 "Sv. Jana Kentského, knìze",
 "",
 "",
 "",
 "Sv. Jana Kentského, knìze",
 "Kety Szent János áldozópap",
 };
const char *text_DEC_26[] = 
{"Sv. Štefana, prvého muèeníka",
 "Sv. Štìpána, prvomuèedníka",
 "",
 "",
 "",
 "Sv. Štìpána, prvomuèedníka",
 "Szent István elsõ vértanú",
 };
const char *text_DEC_27[] = 
{"Sv. Jána, apoštola a evanjelistu",
 "Sv. Jana, apoštola a evangelisty",
 "",
 "",
 "",
 "Sv. Jana, apoštola a evangelisty",
 "Szent János apostol és evangelista",
 };
const char *text_DEC_28[] = 
{"Svätıch Neviniatok, muèeníkov",
 "Svatıch Mláïátek, muèedníkù",
 "",
 "",
 "",
 "Svatıch Mláïátek, muèedníkù",
 "(nincs Magyarországon)",
 };
const char *text_DEC_29[] = 
{"Sv. Tomáša Becketa, biskupa a muèeníka",
 "Sv. Tomáše Becketa, biskupa a muèedníka",
 "",
 "",
 "",
 "Sv. Tomáše Becketa, biskupa a muèedníka",
 "Becket Szent Tamás püspök és vértanú",
 };
const char *text_DEC_31[] = 
{"Sv. Silvestra I., pápea",
 "Sv. Silvestra I., papee",
 "",
 "",
 "",
 "Sv. Silvestra I., papee",
 "Szent I. Szilveszter pápa",
 };
const char *text_ZELENY_STVRTOK[] = 
{"Zelenı (ve¾kı) štvrtok - Pamiatka Pánovej veèere",
 "Zelenı ètvrtek - Památka Veèeøe Pánì",
 "",
 "",
 "",
 "Zelenı ètvrtek - Památka Veèeøe Pánì",
 "Nagycsütörtök",
 };
const char *text_VELKY_PIATOK[] = 
{"Ve¾kı piatok",
 "Velkı pátek",
 "",
 "",
 "",
 "Velkı pátek",
 "Nagypéntek",
 };
const char *text_BIELA_SOBOTA[] = 
{"Biela (ve¾ká) sobota",
 "Bílá sobota",
 "",
 "",
 "",
 "Bílá sobota",
 "Nagyszombat",
 };
const char *text_KVETNA_NEDELA[] = 
{"Kvetná nede¾a",
 "Kvìtná nedìle",
 "",
 "",
 "",
 "Kvìtná nedìle",
 "Virágvasárnap, vagyis az Úr szenvedésének vasárnapja",
 };
const char *text_PO_POPOLCOVEJ_STREDE[] = 
{"po Popolcovej strede",
 "po Popeleèní støedì",
 "",
 "",
 "",
 "po Popeleèní støedì",
 "hu_name",
 };
const char *text_V_OKTAVE_NARODENIA[] = 
{"v oktáve Narodenia Pána",
 "v oktávu Narození Pánì",
 "",
 "",
 "",
 "v oktávu Narození Pánì",
 "hu_name",
 };

#endif /* __HODIN_H */
