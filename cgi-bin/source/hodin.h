/***************************************************************/
/*                                                             */
/* hodin.h                                                     */
/* (c)1999-2011 | Juraj Videky | videky@breviar.sk             */
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
/*   2009-03-24a.D. | úpravy liturgického kalendára pre czop   */
/*   2009-04-08a.D. | zakonèenie modlitby (pre modlitbu cezdeò */
/*                    a komplet. sa pouíva kratšie zakonèenie)*/
/*   2009-05-15a.D. | pridané text_PRO_OP[]                    */
/*   2009-08-26a.D. | pridané html_button_nazov_modlitby()     */
/*   2010-05-17a.D. | pridané niektoré maïarské slávenia       */
/*   2010-10-11a.D. | pridané nazov_slavenia_lokal_kalendar[]  */
/*   2011-01-14a.D. | pridané ZAKONCENIE_KTORY_JE              */
/*   2011-01-26a.D. | upravené poradie konštánt pre lit. obd.  */
/*                                                             */
/*                                                             */
/***************************************************************/

#include "vstudio.h"

#ifndef __HODIN_H
#define __HODIN_H

#include "liturgia.h"

const char *TEMPLAT[POCET_MODLITIEB /* + 1 */] =
{TEMPLAT_INVITATORIUM, TEMPLAT_RANNE_CHVALY, TEMPLAT_POSV_CITANIE,
 TEMPLAT_CEZ_DEN_9, TEMPLAT_CEZ_DEN_12, TEMPLAT_CEZ_DEN_3,
 TEMPLAT_VESPERY, TEMPLAT_KOMPLETORIUM};

/* 2008-04-09: doplnené pre batch generovanie modlitieb */
const char char_modlitby[POCET_MODLITIEB /* + 1 */] =
{CHAR_MODL_INVITATORIUM, CHAR_MODL_RANNE_CHVALY, CHAR_MODL_POSV_CITANIE,
 CHAR_MODL_CEZ_DEN_9, CHAR_MODL_CEZ_DEN_12, CHAR_MODL_CEZ_DEN_3,
 CHAR_MODL_VESPERY, CHAR_MODL_KOMPLETORIUM};

const char *str_modlitby[POCET_MODLITIEB /* + 1 */] =
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
 {"duchovnıch pastierov – pre kòazov", "duchovních pastıøù – o knìích", "", "", "", "O duchovních pastıøích – o knìích", "lelkipásztorok – papok"}, 
 {"duchovnıch pastierov – pre biskupov", "duchovních pastıøù – o biskupech", "", "", "", "O duchovních pastıøích – o biskupech", "lelkipásztorok – püspökök"}, 
 {"duchovnıch pastierov – pre pápeov", "duchovních pastıøù – o papei", "", "", "", "O duchovních pastıøích – o papei", "pásztorok – pápa"}, 
 {"uèite¾ov Cirkvi", "uèitelù církve", "", "", "", "O uèitelích Církve", "egyháztanítók"}, 
 {"apoštolov", "apoštolù", "", "", "", "O apoštolech", "apostolok"}, 
 {"jedného muèeníka", "jednoho muèedníka", "", "", "", "O muèedníkovi", "vértanú"}, 
 {"viacerıch muèeníkov", "více muèedníkù", "", "", "", "O více muèednících", "vértanúk"}, 
 {"Panny Márie", "Panny Marie", "", "", "", "Panny Marie", "Szûz Mária"}, 
 {"svätıch muov – pre reho¾níkov", "svatıch muù – o øeholnících", "", "", "", "O øeholnících", "szerzetes"}, 
 {"svätıch muov", "svatıch muù", "", "", "","O svatıch muích", "szent férfiak"}, 
 {"panien", "panen", "", "", "","O pannách", "szûz"}, 
 {"svätıch ien – pre reho¾nice", "svatıch en – o øeholnicích", "", "", "", "O svatıch enách - o øeholnicích", "apáca"}, 
 {"svätıch ien", "svatıch en", "", "", "", "O svatıch enách", "szent asszonyok"}, 
 {"duchovnıch pastierov - pre viacerıch", "duchvních pastıøù - o více pastıøích", "", "", "", "O duchovních pastıøích", "több lelkipásztor"}, 
 {"jednej muèenice", "jedné muèednice", "", "", "", "O muèednici", "vértanú"}, 
 {"svätıch ien - pre vychovávate¾ky", "svatıch en - o vychovatelce", "", "", "", "O svatıch enách - o vychovatelkách", "egyháztanító férfiak"}, 
 {"svätıch muov - pre vychovávate¾ov", "svatıch muù - o vychovatelıch", "", "", "", "O svatıch muích – o vychovatelích", "egyháztanító asszonyok"}, 
 {"svätıch ien – pre tie, èo konali skutky milosrdenstva", "svatıch en – o enì, která vynikala milosrdnımi skutky", "", "", "", "O svatıch enách – o enì, která vynikala milosrdnımi skutky", "jótékonykodó asszonyok"}, 
 {"svätıch muov – pre tıch, èo konali skutky milosrdenstva", "svatıch muù – o mui, kterı vynikal milosrdnımi skutky", "", "", "", "O svatıch muích – o mui, kterı vynikal milosrdnımi skutky", "jótékonykodó férfiak"}, 
 {"svätıch ien – pre viaceré", "svatıch en – o více enách", "", "", "", "O svatıch enách", "több szent asszony"}, 
 {"svätıch muov – pre viacerıch", "svatıch muù – o více muích", "", "", "", "O svatıch muích", "több szent férfi"}, 
 {"viacerıch panien", "více pannen", "", "", "","O pannách", "szüzek"}, 
 {"posviacky chrámu", "posvìcení kostela", "", "", "", "Posvìcení kostela", "templomszentelés"}, 
 {"zosnulıch", "zemøelıch", "", "", "","Za zemøelé", "halottakért"}, 
 {"svätıch ien – pre tie, èo ili v manelstve", "svatıch en – o enì, která ila v manelství", "", "", "", "O svatıch enách – o enì, která ila v manelství", "házas szent asszonyok"}, 
 {"svätıch muov – pre tıch, èo ili v manelstve", "svatıch muù – o mui, kterı il v manelství", "", "", "", "O svatıch muích – o mui, kterı il v manelství", "házas szent férfiak"}, 
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
{
 {"adventné obdobie", "doba adventní", "", "tempus adventus", "", "doba adventní", "adventi idõ"},
 {"adventné obdobie", "doba adventní", "", "tempus adventus", "", "doba adventní", "adventi idõ"},
 {"oktáva Narodenia Pána", "oktáv Narození Pánì", "", "octava nativitatis", "", "oktáv Narození Pánì", "Karácsony nyolcada"},
 {"vianoèné obdobie", "doba vánoèní", "", "tempus nativitatis", "", "doba vánoèní", "karácsonyi idõ"},
 {"vianoèné obdobie", "doba vánoèní", "", "tempus nativitatis", "", "doba vánoèní", "karácsonyi idõ"},
 {"cezroèné obdobie", "mezidobí", "", "tempus per annum", "", "mezidobí", "évközi idõ"},
 {"pôstne obdobie", "doba postní", "", "tempus quadragesimae", "", "doba postní", "nagyböjti idõ"},
 {"Ve¾kı tıdeò", "Svatı tıden", "", "hebdomada sancta", "", "Svatı tıden", "nagyhét"},
 {"ve¾konoèné trojdnie", "Velikonoèní triduum", "", "sacrum triduum paschale", "", "Velikonoèní triduum", "szent három nap"},
 {"ve¾konoèná oktáva", "velikonoèní oktáv", "", "octava paschae", "", "velikonoèní oktáv", "húsvét nyolcada"},
 {"ve¾konoèné obdobie", "doba velikonoèní", "", "tempus paschale", "", "doba velikonoèní", "húsvéti idõ"},
 {"ve¾konoèné obdobie", "doba velikonoèní", "", "tempus paschale", "", "doba velikonoèní", "húsvéti idõ"},
};

#define		nazov_obdobia(a)	nazov_obdobia_jazyk[a][_global_jazyk]

/* the names of liturgical periods (usually lowecase) / nazov_obdobia: string pre názov liturgického obdobia, rozšírenı */
const char *nazov_obdobia_ext_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{
 {"adventné obdobie I (do 16. decembra)", "doba adventní I", "", "tempus adventus I", "", "doba adventní I", "adventi idõ I"},
 {"adventné obdobie II (po 16. decembri)", "doba adventní II", "", "tempus adventus II", "", "doba adventní II", "adventi idõ II"},
 {"oktáva Narodenia Pána", "oktáv Narození Pánì", "", "octava nativitatis", "", "oktáv Narození Pánì", "Karácsony nyolcada"},
 {"vianoèné obdobie I (do Zjavenia Pána)", "doba vánoèní I", "", "tempus nativitatis I", "", "doba vánoèní II", "karácsonyi idõ I"},
 {"vianoèné obdobie II (po Zjavení Pána)", "doba vánoèní II", "", "tempus nativitatis II", "", "doba vánoèní II", "karácsonyi idõ II"},
 {"cezroèné obdobie", "mezidobí", "", "tempus per annum", "", "mezidobí", "évközi idõ"},
 {"pôstne obdobie I (do Kvetnej nedele)", "doba postní I", "", "tempus quadragesimae I", "", "doba postní I", "nagyböjti idõ I"},
 {"pôstne obdobie II (ve¾kı tıdeò)", "Svatı tıden", "", "hebdomada sancta", "", "Svatı tıden", "nagyhét"},
 {"ve¾konoèné trojdnie", "Velikonoèní triduum", "", "sacrum triduum paschale", "", "Velikonoèní triduum", "szent három nap"},
 {"ve¾konoèná oktáva", "velikonoèní oktáv", "", "octava paschae", "", "velikonoèní oktáv", "húsvét nyolcada"},
 {"ve¾konoèné obdobie I (do Nanebovstúpenia Pána)", "doba velikonoèní I", "", "tempus paschale I", "", "doba velikonoèní I", "húsvéti idõ I"},
 {"ve¾konoèné obdobie II (po Nanebovstúpení Pána)", "doba velikonoèní II", "", "tempus paschale II", "", "doba velikonoèní II", "húsvéti idõ II"},
};

#define		nazov_obdobia_ext(a)	nazov_obdobia_ext_jazyk[a][_global_jazyk]

/* the names of liturgical periods for debugging, only in Slovak; no need to translate */
const char *nazov_obdobia_[POCET_OBDOBI + 1] = // debuggovacie - preto netreba preklada; 2006-08-03
{
 "adventné obdobie I", "adventné obdobie II", "oktáva Narodenia Pána",
 "vianoèné obdobie I", "vianoèné obdobie II", "cezroèné obdobie", 
 "pôstne obdobie I", "pôstne obdobie II (Ve¾kı tıdeò)",
 "ve¾konoèné trojdnie", "ve¾konoèná oktáva", "ve¾konoèné obdobie I", "ve¾konoèné obdobie II",
};

/* the names of liturgical periods in local grammatically 6.th declination? (usually lowecase); in English: "IN liturgical period" or "OF liturgical period" /  lokal == 6. pad, v kom/com */
const char *nazov_obdobia_v_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{
 {"v adventnom období", "v dobì adventní", "", "", "", "v dobì adventní", "adventben"},
 {"v adventnom období", "v dobì adventní", "", "", "", "v dobì adventní", "adventben"},
 {"v oktáve Narodenia Pána", "v oktávu Narození Pánì", "", "", "", "v oktávu Narození Pánì", "Karácsony nyolcadában"},
 {"vo vianoènom období", "v dobì vánoèní", "", "", "", "v dobì vánoèní", "a karácsonyi idõben"},
 {"vo vianoènom období", "v dobì vánoèní", "", "", "", "v dobì vánoèní", "a karácsonyi idõben"},
 {"v cezroènom období", "v mezidobí", "", "per annum", "", "v mezidobí", "az évközi idõben"},
 {"v pôstnom období", "v dobì postní", "", "", "", "v dobì postní", "a nagyböjti idõben"},
 {"vo Ve¾kom tıdni", "ve Svatém tıdnu", "", "", "", "ve Svatém tıdnu", "a nagyhéten"},
 {"vo ve¾konoènom trojdní", "ve velikonoèním triduu", "", "", "", "ve velikonoèním triduu", "a szent három napban"},
 {"vo ve¾konoènej oktáve", "ve velikonoèním oktávu", "", "", "", "ve velikonoèním oktávu", "húsvét nyolcadában"},
 {"vo ve¾konoènom období", "v dobì velikonoèní", "", "", "", "v dobì velikonoèní", "a húsvéti idõben"},
 {"vo ve¾konoènom období", "v dobì velikonoèní", "", "", "", "v dobì velikonoèní", "a húsvéti idõben"},
};

#define		nazov_obdobia_v(a)	nazov_obdobia_v_jazyk[a][_global_jazyk]

/* the names of liturgical periods in local grammatically 6.th declination? (uppercase) / nazov_obdobia: string pre nazov liturgickeho obdobia */
const char *nazov_OBDOBIA_V_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{
 {"V ADVENTNOM OBDOBÍ", "V DOBÌ ADVENTNÍ", "", "", "", "V DOBÌ ADVENTNÍ", "ADVENTBEN"},
 {"V ADVENTNOM OBDOBÍ", "V DOBÌ ADVENTNÍ", "", "", "", "V DOBÌ ADVENTNÍ", "ADVENTBEN"},
 {"V OKTÁVE NARODENIA PÁNA", "V OKTÁVU NAROZENÍ PÁNÌ", "", "", "", "V OKTÁVU NAROZENÍ PÁNÌ", "A KARÁCSONY NYOLCADÁBAN"},
 {"VO VIANOÈNOM OBDOBÍ", "V DOBÌ VÁNOÈNÍ", "", "", "", "V DOBÌ VÁNOÈNÍ", "A KARÁCSONYI IDÕBEN"},
 {"VO VIANOÈNOM OBDOBÍ", "V DOBÌ VÁNOÈNÍ", "", "", "", "V DOBÌ VÁNOÈNÍ", "A KARÁCSONYI IDÕBEN"},
 {"V CEZROÈNOM OBDOBÍ", "V MEZIDOBÍ", "", "", "", "BÌHEM ROKU", "AZ ÉVKÖZI IDÕBEN"},
 {"V PÔSTNOM OBDOBÍ", "V DOBÌ POSTNÍ", "", "", "", "V DOBÌ POSTNÍ", "A NAGYBÖJTI IDÕBEN"},
 {"VO VE¼KOM TİDNI", "VE SVATÉM TİDNU", "", "", "", "VE SVATÉM TİDNU", "A NAGYHÉTEN"},
 {"VO VE¼KONOÈNOM TROJDNÍ", "VE VELIKONOÈNÍM TRIDUU", "", "", "", "VE VELIKONOÈNÍM TRIDUU", "A SZENT HÁROM NAPBAN"},
 {"VO VE¼KONOÈNEJ OKTÁVE", "VE VELIKONOÈNÍM OKTÁVU", "", "", "", "V OKTÁVU VELIKONOÈNÍM", "HÚSVÉT NYOLCACADÁBAN"},
 {"VO VE¼KONOÈNOM OBDOBÍ", "V DOBÌ VELIKONOÈNÍ", "", "", "", "V DOBÌ VELIKONOÈNÍ", "A HÚSVÉTI IDÕBEN"},
 {"VO VE¼KONOÈNOM OBDOBÍ", "V DOBÌ VELIKONOÈNÍ", "", "", "", "V DOBÌ VELIKONOÈNÍ", "A HÚSVÉTI IDÕBEN"},
};

#define		nazov_OBDOBIA_V(a)	nazov_OBDOBIA_V_jazyk[a][_global_jazyk]

/* used for Sundays - "which" Sunday for some of them, e.g. "dominica V paschae" for 5-th Sunday in that liturgical period (uppercase) */
/* 2008-12-20: doplnené - pouíva sa v init_global_string() pre nedele niektorıch období [zatia¾ iba v slovenèine] */
const char *nazov_OBDOBIA_AKA_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{
 {"ADVENTNÁ", "ADVENTNÍ", "", "", "", "ADVENTNÍ", "ADVENT"},
 {"ADVENTNÁ", "ADVENTNÍ", "", "", "", "ADVENTNÍ", "ADVENT"},
 {"V OKTÁVE NARODENIA PÁNA", "V OKTÁVU NAROZENÍ PÁNÌ", "", "", "", "V OKTÁVU NAROZENÍ PÁNÌ", "A KARÁCSONY NYOLCADÁBAN"}, // not used / nepouíva sa
 {"VIANOÈNÁ", "VÁNOÈNÍ", "", "", "", "VÁNOÈNÍ", "KARÁCSONY"},
 {"VIANOÈNÁ", "VÁNOÈNÍ", "", "", "", "VÁNOÈNÍ", "KARÁCSONY"},
 {"CEZROÈNÁ", "V MEZIDOBÍ", "", "", "", "BÌHEM ROKU", "hu_"}, // not used / nepouíva sa
 {"PÔSTNA", "POSTNÍ", "", "", "", "POSTNÍ", "ÉVKÖZI"},
 {"VO VE¼KOM TİDNI", "VE SVATÉM TİDNU", "", "", "", "VE SVATÉM TİDNU", "hu_"}, // not used / nepouíva sa
 {"VO VE¼KONOÈNOM TROJDNÍ", "VE VELIKONOÈNÍM TRIDUU", "", "", "", "VE VELIKONOÈNÍM TRIDUU", "hu_"}, // not used / nepouíva sa
 {"VO VE¼KONOÈNEJ OKTÁVE", "VE VELIKONOÈNÍM OKTÁVU", "", "", "", "V OKTÁVU VELIKONOÈNÍM", "HÚSVÉT NYOLCACADÁBAN"}, // not used / nepouíva sa
 {"VE¼KONOÈNÁ", "VELIKONOÈNÍ", "", "", "", "VELIKONOÈNÍ", "HÚSVÉT"},
 {"VE¼KONOÈNÁ", "VELIKONOÈNÍ", "", "", "", "VELIKONOÈNÍ", "HÚSVÉT"},
};
#define		nazov_OBDOBIA_AKA(a)	nazov_OBDOBIA_AKA_jazyk[a][_global_jazyk]

/* filenames - same for all languages (based on Slovak) */
/* nazov_obdobia: string pre nazov suboru .htm liturgickeho obdobia */
const char *nazov_obd_htm[POCET_OBDOBI + 1] =
{"adv1.htm", "adv2.htm", "vian1.htm",
 "vian1.htm", "vian2.htm", "cezrok.htm",
 "post1.htm", "vtyz.htm",
 "vtroj.htm", "vnokt.htm", "vn1.htm", "vn2.htm"
};

/* anchor names in files - same for all languages (based on Slovak) */
/* nazov_obdobia: string pre nazov kotvy v .htm liturgickeho obdobia */
const char *nazov_OBD[POCET_OBDOBI + 1] =
{"ADV1", "ADV2", "OKTNAR",
 "VIAN1", "VIAN2", "OCR",
 "POST1", "VTYZ", 
 "VTROJ", "VNOKT", "VN1", "VN2"
};

/* filenames - same for all languages (based on Slovak) */
/* nazov_obdobia pc: string pre nazov suboru .htm liturgickeho obdobia pre posvatne citania */
const char *nazov_obd_htm_pc[POCET_OBDOBI + 1] =
{"adv1_pc.htm", "adv2_pc.htm", "vian1_pc.htm",
 "vian1_pc.htm", "vian2_pc.htm", "cezrok_pc.htm",
 "post1_pc.htm", "vtyz_pc.htm",
 "vtroj_pc.htm", "vnokt_pc.htm", "vn1_pc.htm", "vn2_pc.htm"
};

/* anchor names in files used for 4 volumes of breviary - same for all languages (based on Slovak) */
/* 2005-08-05: Pridané. zväzok breviára (LH) pre spoloèné èasti svätıch v kotvách */
const char *zvazok_OBD[POCET_OBDOBI + 1] =
{"ZVI", "ZVI", "ZVI",
 "ZVI", "ZVI", "OCR", /* OCR je ZVIII aj ZVIV */
 "ZVII", "ZVII",
 "ZVII", "ZVII", "ZVII", "ZVII"
};

/* the name of celebration */
const char *nazov_slavenia_jazyk[POCET_SLAVENI + 1][POCET_JAZYKOV + 1] =
{{"___", "___", "___", "", ""}, 
 {"slávnos", "slavnost", "celebration", "sollemnitas", "","SLAVNOST", "fõünnep"},
 {"sviatok", "svátek", "", "festum", "","Svátek", "ünnep"},
 {"spomienka", "památka", "", "memoria", "","Památka", "emléknap"},
 {"¾ubovo¾ná spomienka", "nezávazná památka", "", "memoria ad libitum", "","nezávazná památka", "tetszés szerinti emléknap"},
 {"vlastné slávenie", "z vlastních textù", "", "textus proprius", "", "z vlastních textù", "saját szöveg"},
};

#define		nazov_slavenia(a)	nazov_slavenia_jazyk[a][_global_jazyk]

/* 2010-08-03: pridanı kalendár */
const char *nazov_kalendara[POCET_KALENDAROV + 1] =
{"neurèenı"
,"všeobecnı"
,"všeobecnı SK"
,"všeobecnı CZ"
,"CZOP"
,"SK CSSR"
,"všeobecnı HU"
,"SK SVD"
,"SK SJ"
,"SK SDB"
};

/* calendar codes; internal usage for HTTP requests */
const char *skratka_kalendara[POCET_KALENDAROV + 1] =
{"??", "la", "sk", "cz", "czop", "cssr", "hu", "svd", "sj", "sdb"};

/* filenames for special calendars / názov súbora pre kalendáre -- "pro" == propriá */
const char *nazov_htm_kalendar[POCET_KALENDAROV + 1] =
{"", "", "", "", "", "pro_cssr.htm", "", "pro_svd.htm", "pro_sj.htm", "pro_sdb.htm"};

/* doplnené 2010-10-11 */
const char *nazov_slavenia_lokal_kalendar[POCET_KALENDAROV + 1] =
{""
,""
,"všeobecnı [pre Slovensko]"
,""
,""
,"pre Kongregáciu najsvätejšieho Vykupite¾a — redemptoristov"
,""
,"pre Spoloènos Boieho Slova — verbistov"
,"pre Spoloènos Jeišovu — jezuitov"
,"pre Spoloènos svätého Františka Saleského — saleziánov dona Bosca"
};

/* special "local" or "partial" characteristics of various celebrations - each in one language; no need to translate; special strings will be added */
/* 2005-07-27: doplnené
 * 2007-08-31: upravené TT -> BA-TT
 * 2008-06-23: upravené vzh¾adom k novému usporiadaniu diecéz (intuitívne)
 * 2010-03-16: doplnené BA
 */
const char *nazov_slavenia_lokal[] =
{""
,"len v roòavskej katedrále"
,"hlavnı patrón Trnavskej arcidiecézy" /* "hlavnı patrón Bratislavsko-Trnavskej arcidiecézy" */
,"v Bratislavskej a Trnavskej arcidiecéze <br>a v Banskobystrickej, Košickej, Nitrianskej a Roòavskej diecéze" /* "v Bratislavsko-Trnavskej arcidiecéze a v Banskobystrickej, Košickej, Nitrianskej a Roòavskej diecéze" */
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
,"v Bratislavskej a Trnavskej arcidiecéze <br>a v Banskobystrickej, Nitrianskej a Roòavskej diecéze" /* "v Bratislavsko-Trnavskej arcidiecéze a v Banskobystrickej, Nitrianskej a Roòavskej diecéze" */
,"v Košickej diecéze sviatok hlavného patróna"
,"na Slovensku 5. júla, slávnos; v Európe sviatok"
,"v Roòavskej diecéze sviatok hlavného patróna"
,"len v konsekrovanıch kostoloch"
,"Druhá ve¾konoèná nede¾a — Boieho milosrdenstva"
,"koniec Oktávy narodenia Pána"
,"konec Oktávu Narození Pánì"
,"hlavního patrona praské arcidiecéze"
,"v praské arcidiecézi"
,"v brnìnské diecézi"
,"na Moravì památka"
,"Druhá nedìle velikonoèní – Boího milosrdenství"
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
,"v Bratislavskej arcidiecéze" /* doplnené 2010-03-16 */
,"Karácsony nyolcada-Kiskarácsony" /* doplnené 2010-05-17 */
,"len pre Kongregáciu milosrdnıch sestier Sv. kría" /* doplnené 2011-01-27 */
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

/* 2009-08-26: zmena na štandardné HTML elementy, aby sa dalo pouíva ako inline CSS style */
/* codes for colors - HTML specific */
const char *html_farba_pozadie[POCET_FARIEB + 1] =
{"#000000" /* "black" */, "#ff0000" /* "red" */, "#ffffff" /* "white" */, "#008000" /* "green" */, "#800080" /* "purple" */, "#FF6699" /* "fuchsia" */};

/* codes for colors - HTML specific */
const char *html_farba_popredie[POCET_FARIEB + 1] =
{"#ffffff" /* "white" */, "#ffffff" /* "white" */, "#000000" /* "black" */, "#ffffff" /* "white" */, "#ffffff" /* "white" */, "#0000ff" /* "blue" */};

/* codes for number of the week from psaltery (psalterium per quattuor hebdomadas distributum) */
const char *rimskymi_tyzden_zaltara[5] =
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
const char *nazov_DN_asci[POCET_DNI + 1] =
{"NE", "PO", "UT", "STR", "STV", "PI", "SO", "??"};

/* two/three-letter abbreviations of the names of the days in week, starting with Sunday used for debug info (lowercase, no need to translate; based on Slovak) */
const char *nazov_dn_asci[POCET_DNI + 1] =
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
const char *nazov_MES[POCET_MESIACOV + 1] =
{"JAN", "FEB", "MAR", "APR", "MAJ", "JUN", "JUL", "AUG", "SEP", "OKT", "NOV", "DEC", "___"};

/* three-letter abbreviations of the names of the months used for anchors (lowercase, no need to translate; based on Slovak) */
const char *nazov_mes[POCET_MESIACOV + 1] =
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
{"(css neurèené)", "breviar.css", "breviar_kbd.css", "ebreviar_cz.css", "ebreviar_cz_op.css"
	, "breviar-2003-07-16.css", "breviar-2005-10-13.css", "breviar-2007-08-10.css", "breviar-2008-05-07.css"
	, "breviar-jm-krize-cz.css"};

const char *skratka_css[POCET_CSS + 1] =
{"__", "def", "kbd", "cz", "czop"
	, "2003", "2005", "2007", "2008"
	, "jmkcz"};

/* strings of buttons - abbreviations of prayer names */
/* 2006-10-11: definovanie reazcov aj pre invitatórium a kompletórium */
const char *html_button_invitatorium[POCET_JAZYKOV + 1] = {"Inv.", "Inv.", "Inv.", "Inv.", "", "Inv.", "Imád."};
#ifndef HTML_BUTTON_INVITATORIUM
#define HTML_BUTTON_INVITATORIUM	html_button_invitatorium[_global_jazyk]
#endif

const char *html_button_kompletorium[POCET_JAZYKOV + 1] = {"Kompl.", "Kompl.", "Compl.", "Compl.", "", "Kompl.", "Bef."};
#ifndef HTML_BUTTON_KOMPLETORIUM
#define HTML_BUTTON_KOMPLETORIUM	html_button_kompletorium[_global_jazyk]
#endif

/* definície HTML prvkov upravené a presunuté z mydefs.h, 2006-08-01 */
const char *html_button_ranne_chvaly[POCET_JAZYKOV + 1] = {"Ranné chvály", "Ranní chvály", "Morning prayer", "Laudes", "", "Ranní chvály", "Reggeli dicséret"};
#ifndef HTML_BUTTON_RANNE_CHVALY
#define HTML_BUTTON_RANNE_CHVALY	html_button_ranne_chvaly[_global_jazyk]
#endif

const char *html_button_predpoludnim[POCET_JAZYKOV + 1] = {"9h", "9h", "9h", "Tertia", "", "Tercie", "Délelõtt"};
#ifndef HTML_BUTTON_PREDPOLUDNIM
#define HTML_BUTTON_PREDPOLUDNIM	html_button_predpoludnim[_global_jazyk]
#endif

const char *html_button_napoludnie[POCET_JAZYKOV + 1] = {"12h", "12h", "12h", "Sexta", "", "Sexta", "Délben"};
#ifndef HTML_BUTTON_NAPOLUDNIE
#define HTML_BUTTON_NAPOLUDNIE	html_button_napoludnie[_global_jazyk]
#endif

const char *html_button_popoludni[POCET_JAZYKOV + 1] = {"15h", "15h", "15h", "Nona", "", "Nona", "Délután"};
#ifndef HTML_BUTTON_POPOLUDNI
#define HTML_BUTTON_POPOLUDNI	html_button_popoludni[_global_jazyk]
#endif

const char *html_button_vespery[POCET_JAZYKOV + 1] = {"Vešpery", "Nešpory", "Vesperae", "Vésperae", "", "Veèerní chvály", "Esti dicséret"};
#ifndef HTML_BUTTON_VESPERY
#define HTML_BUTTON_VESPERY	html_button_vespery[_global_jazyk]
#endif

const char *html_button_posv_citanie[POCET_JAZYKOV + 1] = {"Posv. èít.", "Ètení", "Reading", "Off. lect.", "", "Ètení", "Olvasmányos imaóra"};
#ifndef HTML_BUTTON_POSV_CITANIE
#define HTML_BUTTON_POSV_CITANIE	html_button_posv_citanie[_global_jazyk]
#endif

const char *html_button_nazov_modlitby_jazyk[POCET_MODLITIEB + 1][POCET_JAZYKOV + 1] = 
{ {"Inv.", "Inv.", "Inv.", "Inv.", "", "Inv.", "Imád."}
, {"Ranné chvály", "Ranní chvály", "Morning prayer", "Laudes", "", "Ranní chvály", "Reggeli dicséret"}
, {"Posv. èít.", "Ètení", "Reading", "Off. lect.", "", "Ètení", "Olvasmányos imaóra"}
, {"9h", "9h", "9h", "Tertia", "", "Tercie", "Délelõtt"}
, {"12h", "12h", "12h", "Sexta", "", "Sexta", "Délben"}
, {"15h", "15h", "15h", "Nona", "", "Nona", "Délután"}
, {"Vešpery", "Nešpory", "Vesperae", "Vésperae", "", "Veèerní chvály", "Esti dicséret"}
, {"Kompl.", "Kompl.", "Compl.", "Compl.", "", "Kompl.", "Bef."}
// táto sa pre HTML buttony nepouíva
	, {"neurèená", "neurèena", "not-defined", "no data", "", "neurèena", "nem azonosított"}
, {"prvé vešpery", "první nešpory", "1st Vesperae", "I vesper&#230;", "", "První veèerní chvály", "I. esti dicséret" }
, {"Kompl.", "Kompl.", "Compl.", "Compl.", "", "Kompl.", "Kompl."}
// táto sa pre HTML buttony nepouíva
	, {"druhé vešpery", "druhé nešpory", "2nd Vesperae", "II vesper&#230;", "", "Druhé veèerní chvály", "II. esti dicséret" }
// táto sa pre HTML buttony nepouíva
	, {"kompletórium po druhıch vešperách", "kompletáø po druhıch nešporech", "2nd Completary", "II completorio", "", "Kompletáø po druhıch veèerních chválách", "II. esti dicséret után" }
, {"Vo¾ba detailov...", "Podrobnìji...", "Details...", "Optiónes...", "", "Podrobnìji...", "Részletek..."}
};

#define		html_button_nazov_modlitby(a)	html_button_nazov_modlitby_jazyk[a][_global_jazyk]

/* special button: Details... */
#ifndef HTML_BUTTON_DETAILY
#define HTML_BUTTON_DETAILY	html_button_nazov_modlitby_jazyk[MODL_DETAILY][_global_jazyk]
#endif

/* special button: Show prayer */
const char *html_button_det_show[POCET_JAZYKOV + 1] = {"Zobraz modlitbu", "Uka modlitbu", "Show prayer", "xxx", "", "Uka modlitbu", "Mutasd az imát"};
#ifndef HTML_BUTTON_DET_SHOW
#define HTML_BUTTON_DET_SHOW	html_button_det_show[_global_jazyk]
#endif

/* special button: Defaults */
const char *html_button_det_defaults[POCET_JAZYKOV + 1] = {"Pôvodné hodnoty", "Pùvodní hodnoty", "Defaults", "___", "", "Pùvodní hodnoty", "Alapértelmezett"};
#ifndef HTML_BUTTON_DET_DEFAULTS
#define HTML_BUTTON_DET_DEFAULTS	html_button_det_defaults[_global_jazyk]
#endif

/* special button (today): Show */
const char *html_button_dnes_show[POCET_JAZYKOV + 1] = {"Zobrazi", "Uka", "Show", "___", "", "Uka", "Mutasd"};
#ifndef HTML_BUTTON_DNES_SHOW
#define HTML_BUTTON_DNES_SHOW	html_button_dnes_show[_global_jazyk]
#endif

/* special button (today): Defaults (clear form) */
// const char *html_button_dnes_defaults[POCET_JAZYKOV + 1] = {"Vyèisti", "Vyèisti", "Clear", "???", "", "Vyèisti", "Töröl"};
#ifndef HTML_BUTTON_DNES_DEFAULTS
#define HTML_BUTTON_DNES_DEFAULTS	HTML_BUTTON_DET_DEFAULTS
#endif

/* special button (today): Apply setting options */
const char *html_button_dnes_apply[POCET_JAZYKOV + 1] = {"Potvrdi", "Potvrdit", "Apply", "___", "", "Potvrdit", "hu_apply"};
#ifndef HTML_BUTTON_DNES_APPLY
#define HTML_BUTTON_DNES_APPLY	html_button_dnes_apply[_global_jazyk]
#endif

/* special button (today): Morning prayer with canticum of Zekariah */
/* doplnené, 2007-09-13 */
const char *html_button_ranne_chvaly_benediktus[POCET_JAZYKOV + 1] = {"Ranné chvály + Benediktus", "Ranní chvály + Zach. kantikum", "Morning prayer with Benedictus", "Laudes + Benedictus", "", "Ranní chvály + Zach. kantikum", "Reggeli dicséret Benedictusszal"};
#ifndef HTML_BUTTON_RANNE_CHVALY_BENEDIKTUS
#define HTML_BUTTON_RANNE_CHVALY_BENEDIKTUS	html_button_ranne_chvaly_benediktus[_global_jazyk]
#endif

/* special button (today): Evening prayer with canticum of Mary */
const char *html_button_vespery_magnifikat[POCET_JAZYKOV + 1] = {"Vešpery + Magnifikat", "Nešpory + Mariino kant.", "Vesperae + Magnificat", "Vesperae + Magnificat", "", "Veèerní chvály + kant. Panny Marie", "Esti dicséret Magnificattal"};
#ifndef HTML_BUTTON_VESPERY_MAGNIFIKAT
#define HTML_BUTTON_VESPERY_MAGNIFIKAT	html_button_vespery_magnifikat[_global_jazyk]
#endif

/* special button (today): Completory prayer with canticum of Simeon; is currently used only in Slovak */
/* doplnené, 2008-12-20; nepouíva sa pre ostatné jazyky */
const char *html_button_kompletorium_nunkdim[POCET_JAZYKOV + 1] = {"Kompletórium + Nunk dimittis", "xxx", "xxx", "xxx", "", "xxx", "hu_xxx"};
#ifndef HTML_BUTTON_KOMPLETORIUM_NUNKDIM
#define HTML_BUTTON_KOMPLETORIUM_NUNKDIM	html_button_kompletorium_nunkdim[_global_jazyk]
#endif

/* html <title> element for generated pages */
/* doplnené, 2009-05-21 */
const char *html_title[POCET_JAZYKOV + 1] = {"Liturgia hodín", "Liturgie hodin", "Liturgy of Hours", "la_", "", "Liturgie hodin", "Az Imaórák Liturgiája"};
/* 2009-08-04: upravené pre batch mód */
// const char *html_title_batch_mode[POCET_JAZYKOV + 1] = {"Batch mód", "Dávkovı reim", "Batch mode", "la_", "", "Dávkovı reim", "hu_"};
const char *html_title_batch_mode[POCET_JAZYKOV + 1] = {"Liturgia hodín - statické texty", "Liturgie hodin - statické texty", "Liturgy of Hours - static texts", "la_", "", "Liturgie hodin - statické texty", "Az Imaórák Liturgiája - hu_"};

/* navigation buttons/texts: previous, next, today */
const char *html_button_predchadzajuci_[POCET_JAZYKOV + 1] = {"Predchádzajúci", "Pøedchozí", "Previous", "Praecedénte", "", "Pøedchozí", "Elõzõ"};
const char *html_button_nasledujuci_[POCET_JAZYKOV + 1] = {"Nasledujúci", "Následující", "Next", "Successívo", "", "Následující", "Következõ"};
const char *html_button_dnes[POCET_JAZYKOV + 1] = {"dnes", "dnes", "today", "hódie", "", "dnes", "ma"};
const char *html_button_Dnes[POCET_JAZYKOV + 1] = {"Dnes", "Dnes", "Today", "Hódie", "", "Dnes", "Ma"};

/* basic words: day, month, year */
const char *html_text_den[POCET_JAZYKOV + 1] = {"deò", "den", "day", "die", "", "den", "nap"};
const char *html_text_mesiac[POCET_JAZYKOV + 1] = {"mesiac", "mìsíc", "month", "(mesiac)", "", "mìsíc", "hó"};
const char *html_text_rok[POCET_JAZYKOV + 1] = {"rok", "rok", "year", "anno", "", "rok", "év"};
const char *html_text_Rok[POCET_JAZYKOV + 1] = {"Rok", "Rok", "Year", "Anno", "", "Rok", "Év"};
/* in the following: you MUST keep all %d, %c, %s etc. variables - these are replaced by numbers, characters, strings, etc. respectively */
const char *html_text_Rok_x[POCET_JAZYKOV + 1] = {"Rok %d", "Rok %d", "Year %d", "Anno %d", "%d", "Rok %d", "Év %d"};

const char *html_text_zoznam_mesiacov[POCET_JAZYKOV + 1] = {"zoznam mesiacov", "seznam mìsícù", "list of months", "", "", "seznam mìsícù", "hónapok listája"};

const char *html_text_modlitba[POCET_JAZYKOV + 1] = {"modlitba", "modlitba", "prayer", "ora", "", "modlitba", "imádság"};
const char *html_text_modlitby_pre_den[POCET_JAZYKOV + 1] = {"modlitby pre deò", "modlitby pro den", "prayers for date", "", "", "modlitby pro den", "hu_prayers for date"};
const char *html_text_alebo_pre[POCET_JAZYKOV + 1] = {"alebo pre", "anebo pro", "or for", "vel per", "", "anebo pro", "hu_or for"};
const char *html_text_dnesok[POCET_JAZYKOV + 1] = {"dnešok", "dnešní den", "today", "hódie", "", "dnešní den", "ma"};

/* 2010-02-15: pridané kvôli "zoznam.htm" batch mode */
const char *html_text_Breviar_dnes[POCET_JAZYKOV + 1] = {"Breviár dnes", "Breviáø dnes", "Breviary today", "Breviar hódie", "", "Breviáø dnes", "hu_"};
const char *html_text_Dnesne_modlitby[POCET_JAZYKOV + 1] = {"Dnešné modlitby", "Dnešní modlitby", "Today's prayers", "la_hódie", "", "Dnešní modlitby", "hu_"};
const char *html_text_Prehlad_mesiaca[POCET_JAZYKOV + 1] = {"Preh¾ad mesiaca", "Pøehled mìsíce", "Current month", "la_", "", "Pøehled mìsíce", "hu_"};

const char *html_text_Vysvetlivky[POCET_JAZYKOV + 1] = {"Vysvetlivky", "Vysvìtlivky", "Legenda", "Legenda", "", "Vysvìtlivky", "Jelmagyarázat"};

const char *html_text_dalsie_moznosti[POCET_JAZYKOV + 1] = {"Vıber ïalších moností", "Další monosti vıbìru ", "Choose from above (buttons) or from the following options: ", "", "", "Další monosti vıbìru", "Válassz egy imaórát vagy az alábbi lehetõségek közül"};

const char *html_text_dalsie_moznosti_1[POCET_JAZYKOV + 1] = {"Vo¾by vybranıch detailov (ovplyvnia všetky zvolené modlitby):", "Volby pro vybrané detaily (ovlivní všechny modlitby):", "Choose from above (buttons) or from the following options: ", "", "", "Volby pro vybrané detaily (ovlivní všechny modlitby):", "Válassz egy imaórát vagy az alábbi lehetõségek közül"};
const char *html_text_dalsie_moznosti_2[POCET_JAZYKOV + 1] = {"Vo¾by pre ïalšie zobrazenia:", "Volby pro další zobrazení:", "Choose from above (buttons) or from the following options: ", "", "", "Volby pro další zobrazení:", "Válassz egy imaórát vagy az alábbi lehetõségek közül"};

const char *html_text_prik_sviatky_atd[POCET_JAZYKOV + 1] = {"prikázané sviatky a slávnosti Pána v roku ", "zasvìcené svátky a slavnosti Pánì v roce ", "obligatory celebrations in year ", "", "", "zasvìcené svátky a slavnosti Pánì v roce", "kötelezõ ünnepek"};
const char *html_text_lit_kalendar[POCET_JAZYKOV + 1] = {"liturgickı kalendár pre", "liturgickı kalendáø pro", "liturgical calendar for", "", "", "liturgickı kalendáø pro", "liturgikus naptár"};
const char *html_text_roku[POCET_JAZYKOV + 1] = {"roku", "roku", "of year", "", "", "roku", ""};
const char *html_text_tabulka_pohyblive_od[POCET_JAZYKOV + 1] = {"tabu¾ka dátumov pohyblivıch slávení od roku", "tabulka s daty promìnnıch slavností od roku", "table with dates of movable celebrations from year", "", "", "tabulka s daty promìnnıch slavností od roku", "a változó ünnepek listája a következõ években"};
const char *html_text_do_roku[POCET_JAZYKOV + 1] = {"do roku", "po rok", "till year", "", "", "po rok", ""};
const char *html_text_zobrazit_linky[POCET_JAZYKOV + 1] = {"zobrazi tabu¾ku <i>vrátane hypertextovıch odkazov</i> na jednotlivé dni", "zobrazit tabulku s hypertextovımi odkazy pro jednotlivé dny", "display the table including hypertext links to each date", "", "", "zobrazit tabulku s hypertextovımi odkazy pro jednotlivé dny", "minden felirat mutasson a megfelelõ oldalunkra"};
const char *html_text_pre_cezrocne_obd[POCET_JAZYKOV + 1] = {"pre cezroèné obdobie", "pro mezidobí", "for ...", "", "", "pro dobu bìhem roku", ""};
const char *html_text_tyzden_zaltara[POCET_JAZYKOV + 1] = {". tıdeò altára", ". tıden altáøe", "week of Psaltary", "hebdomada", "", ". tıden altáøe", ". zsoltáros hét"};
const char *html_text_tyzden[POCET_JAZYKOV + 1] = {". tıdeò", ". tıden", ". week", ". hebdomada", "", ". tıden", ". hét"};
const char *html_text_v_tyzdni_zaltara[POCET_JAZYKOV + 1] = {". tıdni altára", ". tıdnu altáøe", "week of Psaltary", "hebdomada", "", ". tıdnu altáøe", ". zsoltáros hét"};
const char *html_text_pre[POCET_JAZYKOV + 1] = {"pre", "pro", "for", "per", "", "pro", ""};
/* in the following: you MUST keep all HTML elements, e.g. <a href...>, <br> etc. */
const char *html_text_dnes_je_atd[POCET_JAZYKOV + 1] = 
{"Dnes je %d. deò v roku%s, <a href=\"%s%s\">juliánsky dátum</a> JD = %ld%s.\n<br>\n",
 "Dnes je %d. den v roku%s, <a href=\"%s%s\">juliánské datum</a> JD = %ld%s.\n<br>\n",
 "Today is %d. day in the year%s, <a href=\"%s%s\">Julian date</a> JD = %ld%s.\n<br>\n",
 "Hodie est %d. die anno %s, <a href=\"%s%s\">Iulianus datum</a> JD = %ld%s.\n<br>\n",
 "%d/%s<a href=\"%s%s\">JD</a> = %ld%s.\n<br>\n",
 "Dnes je %d. den v roku%s, <a href=\"%s%s\">juliánské datum</a> JD = %ld%s.\n<br>\n",
 "Ma %s %d. napja van, <a href=\"%s%s\">Julián naptár</a> JD = %ld%s.\n<br>\n"};

const char *html_text_alebo[POCET_JAZYKOV + 1] = {"alebo:", "nebo:", "or:", "", "", "nebo:", ""};

const char *html_text_zakladne_info[POCET_JAZYKOV + 1] = {"Základné informácie", "Základní informace", "Basic info", "__info__", "", "Základní informace", "Alap információ"};
const char *html_text_je[POCET_JAZYKOV + 1] = {"je", "je", "is", "est", "", "je", "van"};
const char *html_text_nie_je[POCET_JAZYKOV + 1] = {"nie je", "není", "is not", "non est", "", "není", "nincs"};
const char *html_text_prestupny[POCET_JAZYKOV + 1] = {"prestupnı", "pøestupnı", "...", "...", "", "pøestupnı", "összekötés"};
const char *html_text_datumy_pohyblivych_slaveni[POCET_JAZYKOV + 1] = {"Dátumy pohyblivıch slávení", "Dáta promìnlivıch slávení", "Dates for movable celebrations", "", "", "Data promìnlivıch slavení", "A mozgó ünnepek dátumai"};

const char *html_text_den_v_roku[POCET_JAZYKOV + 1] = {"deò v roku", "den v roce", "day of the year", "", "", "den v roce", "az év napja"};
const char *html_text_zacina[POCET_JAZYKOV + 1] = {"zaèína", "zaèíná", "starts", "", "", "zaèíná", "kezdõdik"};
const char *html_text_liturgicky_rok[POCET_JAZYKOV + 1] = {"liturgickı rok", "liturgickı rok", "liturgical year", "", "", "liturgickı rok", "liturgikus év"};

const char *html_text_txt_export[POCET_JAZYKOV + 1] = {"Textovı vıstup: ", "Textovı vıstup: ", "Text export: ", "", "", "Textovı vıstup: ", "Text export: "};

const char *html_text_pohyblive1[POCET_JAZYKOV + 1] = {
	"<td align=center>Rok<br>Pána</td>\n",
	"<td align=center>Léto<br>Pánì</td>\n", 
	"<td align=center>Anno<br>Domini</td>\n",
	"<td align=center>Anno<br>Domini</td>\n",
	"",
	"<td align=center>Léto<br>Pánì</td>\n",
	"hu_<td align=center>Anno<br>Domini</td>\n"
};

const char *html_text_pohyblive2[POCET_JAZYKOV + 1] = {
	"<td align=center>Nede¾ná<br>litera</td>\n",
	"<td align=center>Nedìlní<br>písmeno</td>\n", 
	"<td align=center>Sunday<br>Letter</td>\n",
	"<td align=center>Let.<br>Dom.</td>\n",
	"",
	"<td align=center>Nedìlní<br>písmeno</td>\n",
	"hu_<td align=center>Sunday<br>Letter</td>\n"
};

const char *html_text_pohyblive3[POCET_JAZYKOV + 1] = {
	"<td align=center>Nede¾nı<br>cyklus</td>\n",
	"<td align=center>Nedìlní<br>cyklus</td>\n", 
	"<td align=center>Sunday<br>cycle</td>\n",
	"<td align=center>Cycl.<br>Dom.</td>\n",
	"",
	"<td align=center>Nedìlní<br>cyklus</td>\n",
	"hu_<td align=center>Sunday<br>cycle</td>\n"
};

const char *html_text_pohyblive4[POCET_JAZYKOV + 1] = {
	"<td align=center>Krst Krista<br>Pána</td>\n",
	"<td align=center>Køest Krista<br>Pánì</td>\n", 
	"<td align=center>Bapt. of<br>the Lord</td>\n",
	"<td align=center>Bapt.<br>Domini</td>\n",
	"",
	"<td align=center>Køest Krista<br>Pánì</td>\n",
	"hu_<td align=center>Bapt.<br>Domini</td>\n"
};

const char *html_text_pohyblive5[POCET_JAZYKOV + 1] = {
	"<td align=center><a href=\"#explain\">OCR<br>pred<br>PO</a></td>\n",
	"<td align=center><a href=\"#explain\">OCR<br>pøed<br>postem</a></td>\n", 
	"<td align=center>...</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center><a href=\"#explain\">OCR<br>pøed<br>postem</a></td>\n",
	"hu_<td align=center>PA before Fast</td>\n"
};

const char *html_text_pohyblive6[POCET_JAZYKOV + 1] = {
	"<td align=center>Popolcová<br>streda</td>\n",
	"<td align=center>Popeleèní<br>støeda</td>\n", 
	"<td align=center>...</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center>Popeleèní<br>støeda</td>\n",
	"hu_<td align=center>...</td>\n"
};

const char *html_text_pohyblive7[POCET_JAZYKOV + 1] = {
	"<td align=center>Ve¾ká<br>noc</td>\n",
	"<td align=center>Veliko-<br>noce</td>\n", 
	"<td align=center>Easter</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center>Veliko-<br>noce</td>\n",
	"hu_<td align=center>...</td>\n"
};

const char *html_text_pohyblive8[POCET_JAZYKOV + 1] = {
	"<td align=center>Nanebo-<br>vstúpenie<br>Pána</td>\n",
	"<td align=center>Nanebe-<br>vstoupení<br>Pánì</td>\n", 
	"<td align=center>...</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center>Nanebe-<br>vstoupení<br>Pánì</td>\n",
	"hu_<td align=center>...</td>\n"
};

const char *html_text_pohyblive9[POCET_JAZYKOV + 1] = {
	"<td align=center>Zoslanie<br>Ducha<br>Svätého</td>\n",
	"<td align=center>Seslání<br>Ducha<br>Svatého</td>\n", 
	"<td align=center>...</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center>Seslání<br>Ducha<br>Svatého</td>\n",
	"hu_<td align=center>...</td>\n"
};

const char *html_text_pohyblive10[POCET_JAZYKOV + 1] = {
	"<td align=center><a href=\"#explain\">OCR<br>po<br>VN</a></td>\n",
	"<td align=center><a href=\"#explain\">OCR<br>po<br>VN</a></td>\n", 
	"<td align=center>...</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center><a href=\"#explain\">OCR<br>po<br>VN</a></td>\n",
	"hu_<td align=center>...</td>\n"
};

const char *html_text_pohyblive11[POCET_JAZYKOV + 1] = {
	"<td align=center>Prvá<br>adventná<br>nede¾a</td>\n",
	"<td align=center>První<br>adventní<br>nedìle</td>\n", 
	"<td align=center>...</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center>První<br>adventní<br>nedìle</td>\n",
	"hu_<td align=center>...</td>\n"
};

const char *html_text_pohyblive12[POCET_JAZYKOV + 1] = {
	"<td align=center>Nede¾a Svätej<br>rodiny</td></tr>\n",
	"<td align=center>Nedìle Svaté<br>rodiny</td></tr>\n", 
	"<td align=center>...</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center>Nedìle Svaté<br>rodiny</td></tr>\n",
	"hu_<td align=center>...</td>\n"
};

const char *html_text_Nedelne_pismeno[POCET_JAZYKOV + 1] = {"Nede¾né písmeno", "Nedìlní písmeno", "Sunday letter", "", "", "Nedìlní písmeno", "hu_sunday-letter"};
const char *html_text_Nedelne_pismena[POCET_JAZYKOV + 1] = {"Nede¾né písmená", "Nedìlní písmena", "Sunday letters", "", "", "Nedìlní písmena", "hu_sunday-letters"};

const char *html_text_Od_prvej_adv_atd[POCET_JAZYKOV + 1] = {
	"Od prvej adventnej nedele v roku %d (%s) pokraèuje <a href=\"%s%s\">liturgickı rok</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"Od první nedìle adventní v roku %d (%s) pokraèuje <a href=\"%s%s\">liturgickı rok</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"From the 1st Advent Sunday in the year %d (%s) continues <a href=\"%s%s\">liturgical year</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"Od prvej adventnej nedele v roku %d (%s) pokraèuje <a href=\"%s%s\">liturgickı rok</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"",
	"Od první nedìle adventní v roce %d (%s) pokraèuje <a href=\"%s%s\">liturgickı rok</a> <"HTML_SPAN_BOLD">%c</span>.\n"
};

const char *html_text_Po_Velkej_noci_atd[POCET_JAZYKOV + 1] = {
	"Po Ve¾kej noci nasleduje %d. %s v cezroènom období.\n",
	"Po Velikonocích následuje %d. %s v mezibdobí.\n",
	"After Easter follows %d. %s per annum.\n",
	"Po Ve¾kej noci nasleduje %d. %s v období „cez rok“.\n",
	"Po Ve¾kej noci nasleduje %d. %s v období „cez rok“.\n",
	"Po Velikonocích následuje %d. %s v mezibdobí.\n",
	"Húsvét után évközi %d. %s következik.\n",
};

const char *html_text_Prikazane_sviatky_v_roku[POCET_JAZYKOV + 1] = {
	"<p><"HTML_SPAN_RED">Prikázané sviatky v roku %s:</span>\n",
	"<p><"HTML_SPAN_RED">Pøikázané svátky v roce %s:</span>\n",
	"<p><"HTML_SPAN_RED">Obliged celebrations in the year %s:</span>\n",
	"<p><"HTML_SPAN_RED">Prikázané sviatky v roku %s:</span>\n",
	"<p><"HTML_SPAN_RED">Prikázané sviatky v roku %s:</span>\n",
	"<p><"HTML_SPAN_RED">Pøikázané svátky v roce %s:</span>\n",
	"<p><"HTML_SPAN_RED">%s kötelezõ ünnepei:</span>\n",
};

const char *html_text_Jednotlive_mesiace_roku[POCET_JAZYKOV + 1] = {
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

const char *html_text_nemenne_sucasti[POCET_JAZYKOV + 1] = 
{"zobrazi <i>nemenné súèasti</i> modlitby?", 
 "zobrazit <i>nemìnné souèásti</i> modlitby?", 
 "display <i>non-changeable parts</i> prayer?", 
 "", 
 "", 
 "zobrazit <i>nemìnné souèásti</i> modlitby?",
 "hu_ (we will translate it later)"
};

const char *html_text_nemenne_sucasti_explain[POCET_JAZYKOV + 1] = 
{"Kadé ranné chvály obsahujú Benediktus, vešpery Magnifikat, obe modlitby obsahujú Otèenáš a zakonèenie modlitby, a napokon posvätné èítanie obsahuje niekedy hymnus Te Deum; tieto èasti modlitby nazıvame <i>nemenné súèasti</i>.", 
 "Kadé ranní chvály obsahují Zachariášovo kantikum, nešpory Mariin Magnifikat, obì modlitbu Pánì a zakonèení modlitby, a koneènì modlitba se ètením nìkdy obsahuje hymnus Te Deum; tyto èásti modliteb nazıváme <i>nemìnné souèásti</i>.", 
 "Each morning prayer contains Benedictus, vesperae contains Magnificat, both contain the Lord's Prayer and a conclusion of the prayer; finally, the holy reading sometimes contains the Te Deum hymnus; all these parts we call <i>un-changeable parts</i>.", 
 "",
 "", 
 "Kadé ranní chvály obsahují Zachariášovo kantikum, veèerní chvály kantikum Panny Marie, obì modlitbu Pánì a zakonèení modlitby, a koneènì modlitba se ètením nìkdy obsahuje hymnus Te Deum; tyto èásti modliteb nazıváme <i>nemìnné souèásti</i>.",
 "hu_ (we will translate it later)"
};

const char *html_text_popis_svaty[POCET_JAZYKOV + 1] = 
{"zobrazi <i>popis</i> k modlitbe svätého?", 
 "zobrazit <i>popis</i> pøi modlitbì ke cti svìtce?", 
 "display <i>description</i> for prayer for the saints?", 
 "", 
 "", 
 "zobrazit <i>popis</i> pøi modlitbì ke cti svìtce?",
 "hu_ (we will translate it later)"
};

const char *html_text_popis_svaty_explain[POCET_JAZYKOV + 1] = 
{"Modlitby zväèša obsahujú pred názvom modlitby ivotopis svätého, popis sviatku alebo podobnú struènú charakteristiku, ktorú pre jednoduchos nazıvame <i>popis</i>.", 
 "Modlitby ke cti svatıch obsahují struènı ivotopis svatého, pøi svátku je to struènı popis svátku a podobnì. Tyto charakteristiky pro struènost nazıváme <i>popis</i>.", 
 "xxx", 
 "",
 "", 
 "Modlitby ke cti svatıch obsahují struènı ivotopis svatého, u svátku je to struènı popis svátku a podobnì. Tyto charakteristiky pro struènost nazıváme <i>popis</i>.",
 "hu_ (we will translate it later)"
};

const char *html_text_zalmy_brat_zo[POCET_JAZYKOV + 1] = 
{"almy bra zo ", 
 "almy brát ze ", 
 "take psalmody from ", 
 "", 
 "", 
 "almy brát ze ",
 "zsoltárok a következõ helyrõl:"
};
const char *html_text_zalmy_brat_zo_okrem_mcd[POCET_JAZYKOV + 1] = 
{" (okrem modlitby cez deò)\n", 
 " (kromì modlitby pøes den)\n", 
 " (excluding the prayers during the day)\n", 
 "", 
 "", 
 " (kromì modlitby bìhem dne)\n",
 "hu_"
};
const char *html_text_zalmy_brat_zo_explain[POCET_JAZYKOV + 1] = 
{"V závislosti od typu svätenia sa berú alebo neberú na sviatok svätca/svätice almy a chválospevy z vlastnej èasti (na ranné chvály z nedele 1. tıdòa altára); je moné tieto almy vyiada.", 
 "V závislosti na typu slavení svátku svìtce/svìtice se berou nebo neberou almy a kantika z vlastní èásti (na ranní chvály z nedìle 1. tıdne altáøe); je mono tyto almy vyádat.", 
 "xxx", 
 "",
 "", 
 "V závislosti na typu slavení svátku svìtce/svìtice se berou nebo neberou almy a kantika z vlastní èásti (na ranní chvály z nedìle 1. tıdne altáøe); je mono tyto almy vyádat.",
 "hu_"
};

const char *html_text_spol_casti_vziat_zo[POCET_JAZYKOV + 1] = 
{"èasti modlitby zo spoloènej èasti ", 
 "èásti modlitby ze spoleèné èásti ", 
 "parts of prayer from the common part ", 
 "",
 "",
 "èásti modlitby ze spoleèné èásti ",
 "a közös részbõl"};
const char *html_text_spol_casti_vziat_zo_explain[POCET_JAZYKOV + 1] = 
{"Na sviatok svätca/svätice sa pod¾a liturgickıch pravidiel berú èasti, ktoré sa nenachádzajú vo vlastnej èasti altára, zo spoloènej èasti sviatku, niekedy je monos vybra si z viacerıch spoloènıch èastí; naviac je monos modli sa tieto èasti zo všedného dòa.", 
 "Na svátek ke cti svìtce/svìtice se podle liturgickıch pravidel berou èásti, které se nenachází ve vlastních textech, ze spoleènıch textù, nìkdy je moné vybrat si z více spoleènıch textù; navíc je monost modlit se tyto èásti ze všedního dne.", 
 "xxx", 
 "",
 "",
 "O svátku ke cti svìtce/svìtice se podle liturgickıch pravidel berou èásti, které se nenachází ve vlastních textech, ze spoleènıch textù, nìkdy je moné vybrat si z více spoleènıch textù; navíc je monost modlit se tyto èásti ze všedního dne.",
 "hu_"
};

const char *html_text_zalmy_pre_mcd[POCET_JAZYKOV + 1] = 
{"almy pre <i>modlitbu cez deò</i> bra z ", 
 "almy pro <i>modlitbu bìhem dne</i> brát ze ", 
 "take psalmody for the <i>prayer during the day</i> from ", 
 "",
 "",
 "almy pro <i>modlitbu bìhem dne</i> brát ze ",
 "hu_"
};
const char *html_text_zalmy_pre_mcd_explain[POCET_JAZYKOV + 1] = 
{"Doplnková psalmódia zahàòa 3 série tzv. graduálnych almov ( 120 – 129), ktoré mono bra namiesto almov zo altára.", 
 "Doplòovací cyklus almù obsahuje 3 série tzv. graduálních almù ( 120 – 129), které je mono brát místo almù ze altáøe.", 
 "xxx", 
 "",
 "", 
 "Doplòovací cyklus almù obsahuje 3 série tzv. graduálních almù ( 120 – 129), které je mono brát místo almù ze altáøe.",
 "hu_"
};

/* 2010-10-11: HTML option selected */
const char *html_option_selected = " selected";

/* 2010-09-14: doplnené */
const char *html_text_kalendar_miestny[POCET_JAZYKOV + 1] = 
{"kalendár Liturgie hodín poui: ", 
 "kalendáø obecní nebo místní: ", 
 "local or general calendar: ", 
 "",
 "",
 "kalendáø obecní nebo místní: ",
 "hu_"
};
const char *html_text_kalendar_explain[POCET_JAZYKOV + 1] = 
{"(Je moné zvoli miestny kalendár niektorej <i>reho¾nej rodiny, rádu, inštitútu</i>.)", 
 "xxx", 
 "xxx", 
 "",
 "", 
 "xxx", 
 "hu_"
};

const char *html_text_detaily_explain[POCET_JAZYKOV + 1] = 
{"Pokia¾ sú niektoré parametre pre vybranú modlitbu nepouite¾né, neberú sa do úvahy (môu by teda nastavené ¾ubovo¾ne).", 
 "Kdy jsou nìkteré vıše uvedené volby nepouitelné pro nìjakou modlitbu, neberou se v úvahu (mohou bıt nastaveny dle libovùle).", 
 "If any of described options are not applicable for a chosen prayer, they can be set anyhow.", 
 "",
 "", 
 "Kdy jsou nìkteré vıše uvedené volby nepouitelné pro nìjakou modlitbu, neberou se v úvahu (mohou bıt nastaveny dle libovùle).",
 "hu_"
};

/* 2010-06-04: doplnenı text pre popis do invitatória */
const char *html_text_inv_slavaotcu[POCET_JAZYKOV + 1] = 
{"<p>&nbsp;&nbsp;&nbsp; <font size=\"-1\"><font color=\"#ff0000\">Nasleduje </font>Sláva Otcu<font color=\"#ff0000\"> a opakuje sa antifóna.</font></font>", 
 "<p>&nbsp;&nbsp;&nbsp; <font size=\"-1\"><font color=\"#ff0000\">Následuje </font>Sláva Otci<font color=\"#ff0000\"> a opakuje se antifona.</font></font>", 
 "<p>&nbsp;&nbsp;&nbsp; <font size=\"-1\"><font color=\"#ff0000\">Nasleduje </font>Sláva Otcu<font color=\"#ff0000\"> a opakuje sa antifóna.</font></font>", 
 "<p>&nbsp;&nbsp;&nbsp; <font size=\"-1\"><font color=\"#ff0000\">Nasleduje </font>Sláva Otcu<font color=\"#ff0000\"> a opakuje sa antifóna.</font></font>", 
 "<p>&nbsp;&nbsp;&nbsp; <font size=\"-1\"><font color=\"#ff0000\">Nasleduje </font>Sláva Otcu<font color=\"#ff0000\"> a opakuje sa antifóna.</font></font>", 
 "<p>&nbsp;&nbsp;&nbsp; <font size=\"-1\"><font color=\"#ff0000\">Následuje </font>Sláva Otci<font color=\"#ff0000\"> a opakuje se antifona.</font></font>", 
 "<p>&nbsp;&nbsp;&nbsp; <font size=\"-1\"><font color=\"#ff0000\">Nasleduje </font>Sláva Otcu<font color=\"#ff0000\"> a opakuje sa antifóna.</font></font>", 
};

/* 2009-08-04, doplnené: pre batch mód */
const char *html_text_batch_Zoznam1[POCET_JAZYKOV + 1] = {"Zoznam modlitieb", "Seznam modliteb", "List of prayers", "", "", "Seznam modliteb", "hu_"};
const char *html_text_batch_Zoznam1m[POCET_JAZYKOV + 1] = {"Zoznam modlitieb po mesiacoch", "Seznam modliteb dle mìsícù", "List of prayers by months", "", "", "Seznam modliteb dle mìsícù", "hu_"};
const char *html_text_batch_obdobie1m[POCET_JAZYKOV + 1] = {"("/*obdobie */"od %d. %s %d do %d. %s %d)", "(pro období od %d. %s %d do %d. %s %d)", "(%d. %s %d -- %d. %s %d)", "(%d. %s %d -- %d. %s %d)", "(%d. %s %d -- %d. %s %d)", "(pro období od %d. %s %d do %d. %s %d)", "hu_(%d. %s %d -- %d. %s %d)"};
const char *html_text_batch_Zoznam2[POCET_JAZYKOV + 1] = {/* Zoznam modlitieb pre */"%s %d", "%s %d", "%s %d", "%s %d", "%s %d", "%s %d", "%s %d"};
const char *html_text_batch_Back[POCET_JAZYKOV + 1] = {"^ hore", "^ nahoru", "^ up", "", "", "^ nahoru", "^ hu_"};
const char *html_text_batch_Prev[POCET_JAZYKOV + 1] = {"&lt;&lt;", "&lt;&lt;", "&lt;&lt;", "&lt;&lt;", "&lt;&lt;", "&lt;&lt;", "&lt;&lt;"};
const char *html_text_batch_Next[POCET_JAZYKOV + 1] = {"&gt;&gt;", "&gt;&gt;", "&gt;&gt;", "&gt;&gt;", "&gt;&gt;", "&gt;&gt;", "&gt;&gt;"};

/* 2009-04-08, doplnené: zakonèenie modlitby trojaké, krátke resp. dlhé */
const char *text_ZAKONCENIE_SKRZE_dlhe[POCET_JAZYKOV + 1] = 
{"Skrze nášho Pána Jeiša Krista, tvojho Syna, ktorı je Boh a s tebou ije a kra¾uje v jednote s Duchom Svätım po všetky veky vekov.",
 "Skrze tvého Syna Jeíše Krista, našeho Pána, nebo on s tebou v jednotì Ducha svatého ije a kraluje po všechny vìky vìkù.",
 "",
 "",
 "Per Christum",
 "Skrze tvého Syna Jeíše Krista, našeho Pána, nebo on s tebou v jednotì Ducha Svatého ije a kraluje po všechny vìky vìkù.",
 "A mi Urunk, Jézus Krisztus, a te Fiad által, áld veled él és uralkodik a Szentlélekkel egységben, Isten mindörökkönörökké.",
 };
const char *text_ZAKONCENIE_SKRZE_kratke[POCET_JAZYKOV + 1] = 
{"Skrze Krista, nášho Pána.",
 "Skrze Krista, našeho Pána.",
 "",
 "",
 "Per Christum",
 "Skrze Krista, našeho Pána.",
 "Krisztus, a mi Urunk által.",
 };
const char *text_ZAKONCENIE_LEBO_ON_dlhe[POCET_JAZYKOV + 1] = 
{"Lebo on je Boh a s tebou ije a kra¾uje v jednote s Duchom Svätım po všetky veky vekov.",
 "Nebo on s tebou v jednotì Ducha svatého ije a kraluje po všechny vìky vìkù.",
 "",
 "",
 "Qui vivit",
 "Nebo on s tebou v jednotì Ducha Svatého ije a kraluje po všechny vìky vìkù.",
 "Aki veled él és uralkodik a Szentlélekkel egységben, Isten mindörökkön-örökké.",
 };
const char *text_ZAKONCENIE_LEBO_ON_kratke[POCET_JAZYKOV + 1] = 
{"Lebo on ije a kra¾uje na veky vekov.",
 "Nebo on s tebou ije a kraluje na vìky vìkù.",
 "",
 "",
 "Qui vivit",
 "Nebo on s tebou ije a kraluje na vìky vìkù.",
 "Aki él és uralkodik mindörökkön-örökké.",
 };
const char *text_ZAKONCENIE_LEBO_TY_dlhe[POCET_JAZYKOV + 1] = 
{"Lebo ty si Boh a iješ a kra¾uješ s Bohom Otcom v jednote s Duchom Svätım po všetky veky vekov.",
 "Nebo ty iješ a kraluješ s Bohem Otcem v jednotì Ducha svatého po všechny vìky vìkù.",
 "",
 "",
 "Qui vivis",
 "Nebo ty iješ a kraluješ s Bohem Otcem v jednotì Ducha Svatého po všechny vìky vìkù.",
 "Aki élsz és uralkodói az Atyaistennel és a Szentlélek­kel egységben, Isten mindörökkön-örökké.",
 };
const char *text_ZAKONCENIE_LEBO_TY_kratke[POCET_JAZYKOV + 1] = 
{"Lebo ty iješ a kra¾uješ na veky vekov.",
 "Nebo ty iješ a kraluješ na vìky vìkù.",
 "",
 "",
 "Qui vivis",
 "Nebo ty iješ a kraluješ na vìky vìkù.",
 "Aki élsz és uralkodói mindörökkön-örökké.",
 };
/* 2010-06-07: pridané len pre SK (POST1_MODLITBA5NE) */
const char *text_ZAKONCENIE_ON_JE_dlhe = "On je Boh a s tebou ije a kra¾uje v jednote s Duchom Svätım po všetky veky vekov.";
const char *text_ZAKONCENIE_ON_JE_kratke = "On ije a kra¾uje na veky vekov.";
/* 2011-01-14: pridané len pre SK 
		(04NOV_MODLITBA, 24APR2_MODLITBA, 11JUN_MODLITBA, 19OKT2_MODLITBA, VN1_MODLITBA3STR, ADV12PO_MODLITBA, ADV12STR_MODLITBA, 
		VTYZ_MODLITBA6PO, ADV12UT_MODLITBA, ADV12PI_MODLITBA, ADV13STV_MODLITBA, OZZ_MODLITBA, SCDP_MODLITBA, PMB_rMODLITBA, SCPM_MODLITBA, 
		SCSM_MODLITBA, 24APR_MODLITBA, 25APR_MODLITBA, 02AUG_MODLITBA, 05AUG_MODLITBA, 15AUG_1MODLITBA, 16JUL_MODLITBA, 30JUL2_MODLITBA, 
		24OKT_MODLITBA, VIAN2_MODLITBA11, VN1_MODLITBA4NE, SPMVSr_MODLITBA2, 24JUN_1MODLITBA, 
		VN1_MODLITBA6STV [nepouíva sa], VN1_rPROSBY6PI_pred_nan [nepouíva sa], VN1_vPROSBY6PI_pred_nan [nepouíva sa])
 */
const char *text_ZAKONCENIE_KTORY_JE_dlhe = "ktorı je Boh a s tebou ije a kra¾uje v jednote s Duchom Svätım po všetky veky vekov.";
const char *text_ZAKONCENIE_KTORY_JE_kratke = "ktorı ije a kra¾uje na veky vekov.";

/* 2009-05-15, doplnené: pre dominikánov */
const char *text_PRO_OP[POCET_JAZYKOV + 1] = 
{"Pre dominikánov (CZ_OP): ",
"Pro dominikány (OP CZ): ",
 "",
 "",
 "",
 "Pro OP CZ: ",
 "hu_",
 };

/* nasledujú názvy liturgickıch dní -- follow the names of special liturgical celebrations */

/* --------------- 00 pohyblivé slávenia --------------- */

const char *text_DRUHA_NEDELA_PO_NAR_PANA[POCET_JAZYKOV + 1] = 
{"2. nede¾a po Narodení Pána",
 "2. nedìle po Narození Pánì",
 "",
 "",
 "",
 "2. nedìle po Narození Pánì",
 "Karácsony Utáni II. Vasárnap",
 };

/* --------------- 01 január --------------- */

const char *text_JAN_01[POCET_JAZYKOV + 1] = 
{"Panny Márie Bohorodièky",
 "Matky Boí, Panny Marie",
 "",
 "Sanctae Dei Genetricis Mariae",
 "",
 "Matky Boí, Panny Marie",
 "Szûz Mária, Isten Anyja",
 };
const char *text_JAN_01_SJ[POCET_JAZYKOV + 1] = 
{"Panny Márie Bohorodièky a Mena Jeiš <br>(Titulárny sviatok Spoloènosti Jeišovej)", // titulárny sviatok Spoloènosti Jeišovej
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_02[POCET_JAZYKOV + 1] = 
{"Sv. Bazila Ve¾kého a Gregora Nazianského, biskupov a uèite¾ov Cirkvi",
 "Sv. Basila Velikého a Øehoøe Naziánského, biskupù a uèitelù církve",
 "",
 "Ss. Basilii Magni et Gregorii Nazianzeni, ep. et Eccl. doct.",
 "",
 "Sv. Basila Velikého a Øehoøe Naziánského, biskupù a uèitelù Církve",
 "Nagy Szent Vazul és Nazianzi Szent Gergely püspökök és egyháztanítók",
 };
const char *text_JAN_03[POCET_JAZYKOV + 1] = 
{"Najsvätejšieho mena Jeiš",
 "Nejsvìtìjšího jména Jeíš",
 "",
 "",
 "",
 "Nejsvìtìjšího Jména Jeíš",
 "(Najsvätejšieho mena Jeiš)",
 };
const char *text_JAN_05_CSSR[POCET_JAZYKOV + 1] = 
{"Sv. Jána Nepomuckého Neumanna, biskupa",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_06[POCET_JAZYKOV + 1] = 
{"Zjavenie Pána",
 "Zjevení Pánì",
 "",
 "In Epiphania Domini",
 "",
 "Zjevení Pánì",
 "Urunk Megjelenése (Vízkereszt)",
 };
const char *text_JAN_07[POCET_JAZYKOV + 1] = 
{"Sv. Rajmunda z Peòafortu, kòaza",
 "Sv. Rajmunda z Penafortu, knìze",
 "",
 "S. Raimundi de Penyafort, presb.",
 "",
 "Sv. Rajmunda z Peòafortu, knìze",
 "Penyaforti Szent Rajmund áldozópap",
 };
const char *text_JAN_KRST[POCET_JAZYKOV + 1] = 
{"Krst Krista Pána",
 "Køtu Pánì",
 "",
 "In Baptismate Domini",
 "",
 "Køtu Pánì",
 "Urunk Megkeresztelkedése",
 };
const char *text_JAN_13[POCET_JAZYKOV + 1] = 
{"Sv. Hilára, biskupa a uèite¾a Cirkvi",
 "Sv. Hilaria, biskupa a uèitele církve",
 "",
 "S. Hilarii, ep. et Eccl. doct.",
 "",
 "Sv. Hilaria, biskupa a uèitele Církve",
 "Szent Hiláriusz (Vidor) püspök és egyháztanító",
 };
const char *text_JAN_14_CSSR[POCET_JAZYKOV + 1] = 
{"Bl. Petra Dondersa, kòaza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_15[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Sv. Františka Fernándeze de Capillas, knìze, Petra Sanse, biskupa, a druhù, èínskıch muèedníkù",
 "Remete Szent Pál", // 2010-05-17: pozor, nieèo úplne iné ako pre czop!
 };
const char *text_JAN_15_SVD[POCET_JAZYKOV + 1] = 
{"Sv. Arnolda Janssena, kòaza a zakladate¾a troch misijnıch reho¾nıch spoloèností",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "",
 "",
 };
const char *text_JAN_15_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Alojza Variaru, kòaza",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "",
 "",
 };
const char *text_JAN_17[POCET_JAZYKOV + 1] = 
{"Sv. Antona, opáta",
 "Sv. Antonína, opata",
 "",
 "S. Antonii, abbatis",
 "",
 "Sv. Antonína, opata",
 "Szent Antal apát",
 };
const char *text_JAN_18_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Panny Marie, Matky jednoty køesanù",
 "",
 "(non est in Latina)",
 "",
 "Panny Marie, Matky jednoty køesanù",
 "(nincs Magyarországon)",
 };
const char *text_JAN_19[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Sv. Markéty Uherské, panny, mnišky",
 "Árpádházi Szent Margit szûz", // v maïarsku 18. januára
 };
const char *text_JAN_19_SJ[POCET_JAZYKOV + 1] = 
{"Bl. Jakuba Sal&egrave;sa a Viliama Saultemouchea, Ignáca de Azevedo a spoloèníkov, <br>Jakuba Bonnauda a spoloèníkov, muèeníkov",
 "cz_",
 "",
 "la_",
 "",
 "czop_",
 "hu_",
 };
const char *text_JAN_20_1[POCET_JAZYKOV + 1] = 
{"Sv. Fabiána, pápea a muèeníka",
 "Sv. Fabiána, papee a muèedníka",
 "",
 "S. Fabiani, papae et mart.",
 "",
 "Sv. Fabiána, papee a muèedníka",
 "Szent Fábián pápa év vértanú",
 };
const char *text_JAN_20_2[POCET_JAZYKOV + 1] = 
{"Sv. Šebastiána, muèeníka",
 "Sv. Šebestiána, muèedníka",
 "",
 "S. Sebastiani, mart.",
 "",
 "Sv. Šebestiána, muèedníka",
 "Szent Sebestyén vértanú",
 };
const char *text_JAN_21[POCET_JAZYKOV + 1] = 
{"Sv. Agnesy, panny a muèenice",
 "Sv. Aneky, panny a muèednice",
 "",
 "S. Agnetis, virg. et mart.",
 "",
 "Sv. Aneky, panny a muèednice",
 "Szent Ágnes szûz és vértanú",
 };
const char *text_JAN_22[POCET_JAZYKOV + 1] = 
{"Sv. Vincenta, diakona a muèeníka",
 "Sv. Vincence, jáhna a muèedníka",
 "",
 "S. Vincentii, diaconi et mart.",
 "",
 "Sv. Vincence, jáhna a muèedníka",
 "Szent Vince diakónus és vértanú",
 };
const char *text_JAN_22_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Laury Vicuòovej, panny a muèenice",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_23_SK[POCET_JAZYKOV + 1] = 
{"Sv. Jána Almuníka, biskupa",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "(non est in Latina)",
 "",
 "hu_name",
 "(nincs Magyarországon)",
 };
const char *text_JAN_24[POCET_JAZYKOV + 1] = 
{"Sv. Františka Saleského, biskupa a uèite¾a Cirkvi",
 "Sv. Františka Saleského, biskupa a uèitele církve",
 "",
 "S. Francisci de Sales, ep. et Eccl. doct.",
 "",
 "Sv. Františka Saleského, biskupa a uèitele Církve",
 "Szalézi Szent Ferenc püspök és egyháztanító",
 };
const char *text_JAN_24_SDB[POCET_JAZYKOV + 1] = 
{"Sv. Františka Saleského, biskupa a uèite¾a Cirkvi, <br>titulárneho patróna saleziánskej rodiny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_25[POCET_JAZYKOV + 1] = 
{"Obrátenie svätého Pavla, apoštola",
 "Obrácení svatého Pavla, apoštola",
 "",
 "In Conversione S. Pauli, Apostoli",
 "",
 "Obrácení svatého Pavla, apoštola",
 "Szent Pál apostol megtérése (Pál fordulása)",
 };
const char *text_JAN_26[POCET_JAZYKOV + 1] = 
{"Sv. Timoteja a Títa, biskupov",
 "Sv. Timoteje a Tita, biskupù",
 "",
 "Ss. Timothei et Titi, ep.",
 "",
 "Sv. Timoteje a Tita, biskupù",
 "Szent Timóteus és Szent Titusz püspökök",
 };
const char *text_JAN_27[POCET_JAZYKOV + 1] = 
{"Sv. Angely Merici, panny",
 "Sv. Andìly Mericiové, panny",
 "",
 "S. Angelae Merici, virg.",
 "",
 "Sv. Andìly Mericiové, panny",
 "Merici Szent Angéla szûz",
 };
const char *text_JAN_28[POCET_JAZYKOV + 1] = 
{"Sv. Tomáša Akvinského, kòaza a uèite¾a Cirkvi",
 "Sv. Tomáše Akvinského, knìze a uèitele církve",
 "",
 "S. Thomae de Aquino, presb. et Eccl. doct.",
 "",
 "Sv. Tomáše Akvinského, knìze a uèitele Církve",
 "Aquinói Szent Tamás áldozópap és egyháztanító",
 };
const char *text_JAN_29_SVD[POCET_JAZYKOV + 1] = 
{"Sv. Jozefa Freinademetza, kòaza",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "",
 "",
 };
const char *text_JAN_30_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Bronislava Markiewicza, kòaza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_31[POCET_JAZYKOV + 1] = 
{"Sv. Jána Boska, kòaza",
 "Sv. Jana Boska, knìze",
 "",
 "S. Ioannis Bosco, presb.",
 "",
 "Sv. Jana Boska, knìze",
 "Bosco Szent János áldozópap",
 };
const char *text_JAN_31_SDB[POCET_JAZYKOV + 1] = 
{"Sv. Jána Boska, kòaza, otca a uèite¾a mládee, <br>zakladate¾a Spoloènosti svätého Františka Saleského, <br>Inštitútu dcér Márie Pomocnice a saleziánskych spolupracovníkov",
 "",
 "",
 "",
 "",
 "",
 "",
 };

/* --------------- 02 február --------------- */

const char *text_FEB_01_SDB[POCET_JAZYKOV + 1] = 
{"Všetkıch nebohıch èlenov Spoloènosti svätého Františka Saleského",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_FEB_02[POCET_JAZYKOV + 1] = 
{"Obetovanie Pána",
 "Uvedení Pánì do chrámu",
 "",
 "In Praesentatione Domini",
 "",
 "Uvedení Pánì do chrámu",
 "Urunk bemutatása (Gyertyaszentelõ Boldogasszony)",
 };
const char *text_FEB_03_1[POCET_JAZYKOV + 1] = 
{"Sv. Blaeja, biskupa a muèeníka",
 "Sv. Blaeje, biskupa a muèedníka",
 "",
 "S. Blasii, ep. et mart.",
 "",
 "Sv. Blaeje, biskupa a muèedníka",
 "Szent Balázs püspök és vértanú",
 };
const char *text_FEB_03_2[POCET_JAZYKOV + 1] = 
{"Sv. Oskára, biskupa",
 "Sv. Ansgara, biskupa",
 "",
 "S. Ansgarii, ep.",
 "",
 "Sv. Ansgara, biskupa",
 "Szent Anszgár (Oszkár) püspök",
 };
const char *text_FEB_04_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Sv. Kateøiny z Ricci, panny, øeholnice",
 "hu_",
 };
const char *text_FEB_04_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Jána de Brito, kòaza, bl. Rudolfa Acquavivu, kòaza a jeho spoloèníkov; <br>bl. Františka Pacheca, Karola Spinolu, kòazov a spoloèníkov, muèeníkov; <br>bl. Jakuba Berthieu, kòaza, Leva Mangina, kòaza a spoloèníkov, muèeníkov",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "czop_",
 "hu_",
 };
const char *text_FEB_05[POCET_JAZYKOV + 1] = 
{"Sv. Agaty, panny a muèenice",
 "Sv. Agáty, panny a muèednice",
 "",
 "S.  Agathae, virg. et mart.",
 "",
 "Sv. Agáty, panny a muèednice",
 "Szent Ágota szûz és vértanú",
 };
const char *text_FEB_06[POCET_JAZYKOV + 1] = 
{"Sv. Pavla Mikiho a spoloèníkov, muèeníkov",
 "Sv. Pavla Mikiho a druhù, muèedníkù",
 "",
 "Ss.  Pauli Miki et sociorum, mart.",
 "",
 "Sv. Pavla Mikiho a druhù, muèedníkù",
 "Miki Szent Pál és társai vértanúk",
 };
const char *text_FEB_06_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Pavla Mikiho, reho¾níka, a jeho spoloèníkov, muèeníkov",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_FEB_07_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Vıroèní památka zemøelıch otcù a matek",
 "hu_",
 };
const char *text_FEB_07_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Pia IX., pápea",
 "",
 "",
 "la_",
 "",
 "",
 "hu_",
 };
const char *text_FEB_08_1[POCET_JAZYKOV + 1] = 
{"Sv. Hieronyma Emilianiho",
 "Sv. Jeronıma Emilianiho",
 "",
 "S. Hieronymi Emiliani",
 "",
 "Sv. Jeronıma Emilianiho",
 "Emiliáni Szent Jeromos",
 };
const char *text_FEB_08_2[POCET_JAZYKOV + 1] = 
{"Sv. Jozefíny Bakhita, panny",
 "Sv. Josefíny Bakhity, panny",
 "",
 "",
 "",
 "Sv. Josefíny Bakhity, panny",
 "(Sv. Jozefíny Bakhita, panny)",
 };
const char *text_FEB_09_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Euzébie Palominovej Yenes, panny",
 "",
 "",
 "la_",
 "",
 "",
 "hu_",
 };
const char *text_FEB_10[POCET_JAZYKOV + 1] = 
{"Sv. Školastiky, panny",
 "Sv. Scholastiky, panny",
 "",
 "S.  Scholasticae, virg.",
 "",
 "Sv. Scholastiky, panny",
 "Szent Skolasztika szûz",
 };
const char *text_FEB_11[POCET_JAZYKOV + 1] = 
{"Prebl. Panny Márie Lurdskej",
 "Panny Marie Lurdské",
 "",
 "B. Mariae Virg. de Lourdes",
 "",
 "Panny Marie Lurdské",
 "A Lourdes-i Boldogságos Szûz Mária",
 };
const char *text_FEB_12_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Bl. Reginalda z Orléansu, knìze",
 "hu_",
 };
const char *text_FEB_13_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Bl. Jordána Saského, knìze",
 "hu_",
 };
const char *text_FEB_14[POCET_JAZYKOV + 1] = 
{"Sv. Cyrila, mnícha, a sv. Metoda, biskupa, patrónov Európy", // (na Slovensku sa slávi 5. júla)
 "(slaví se 5. èervna)",
 "",
 "Ss. Cyrilli, monachi, et Methodii, ep.",
 "",
 "",
 "Szent Cirill szerzetes és Szent Metód püspök, Európa társ védõszentjei",
 };
const char *text_FEB_15_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Klaudia La Colombi&egrave;ra, kòaza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_FEB_17[POCET_JAZYKOV + 1] = 
{"Siedmich svätıch zakladate¾ov rehole Sluobníkov Panny Márie",
 "Sv. Alexia a druhù, øeholníkù",
 "",
 "Ss. Septem Fundatorum Ordinis Servorum B. Mariae Virg.",
 "",
 "Sv. Alexia a druhù, øeholníkù",
 "A szervita rend hét szent alapítója",
 };
const char *text_FEB_18_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Bl. Jana z Fiesole neboli fra Angelica, knìze",
 "hu_",
 };
const char *text_FEB_21[POCET_JAZYKOV + 1] = 
{"Sv. Petra Damianiho, biskupa a uèite¾a Cirkvi",
 "Sv. Petra Damianiho, biskupa a uèitele církve",
 "",
 "S. Petri Damiani, ep. et Eccl. doct.",
 "",
 "Sv. Petra Damianiho, biskupa a uèitele Církve",
 "Damiáni Szent Péter püspök és egyháztanító",
 };
const char *text_FEB_22[POCET_JAZYKOV + 1] = 
{"Katedra sv. Petra, apoštola",
 "Stolce svatého Petra, apoštola",
 "",
 "Cathedrae S. Petri, Apostoli",
 "",
 "Stolce svatého Petra, apoštola",
 "Szent Péter apostol székfoglalása",
 };
const char *text_FEB_23[POCET_JAZYKOV + 1] = 
{"Sv. Polykarpa, biskupa a muèeníka",
 "Sv. Polykarpa, biskupa a muèedníka",
 "",
 "S. Polycarpi, ep. et mart.",
 "",
 "Sv. Polykarpa, biskupa a muèedníka",
 "Szent Polikárp püspök és vértanú",
 };
const char *text_FEB_25_SDB[POCET_JAZYKOV + 1] = 
{"Sv. Alojza Versigliu, biskupa, a Kalixta Caravaria, kòaza, <br>prvıch saleziánskych muèeníkov",
 "",
 "",
 "la_",
 "",
 "",
 "hu_",
 };

/* --------------- 00 pohyblivé slávenia --------------- */

const char *text_POPOLCOVA_STREDA[POCET_JAZYKOV + 1] = 
{"Popolcová streda",
 "Popeleèní støeda",
 "",
 "",
 "",
 "Popeleèní støeda",
 "hu_name",
 };

/* --------------- 03 marec --------------- */

const char *text_MAR_04[POCET_JAZYKOV + 1] = 
{"Sv. Kazimíra",
 "Sv. Kazimíra",
 "",
 "S. Casimiri",
 "",
 "Sv. Kazimíra",
 "Szent Kázmér",
 };
const char *text_MAR_07[POCET_JAZYKOV + 1] = 
{"Sv. Perpetuy a Felicity, muèeníc",
 "Sv. Perpetuy a Felicity, muèednic",
 "",
 "Ss.   Perpetuae et  Felicitatis, mart.",
 "",
 "Sv. Perpetuy a Felicity, muèednic",
 "Szent Perpétua és Felicitász vértanúk",
 };
const char *text_MAR_08[POCET_JAZYKOV + 1] = 
{"Sv. Jána z Boha, reho¾níka",
 "Sv. Jana z Boha, øeholníka",
 "",
 "S. Ioannis a Deo, relig.",
 "",
 "Sv. Jana z Boha, øeholníka",
 "Istenes Szent János szerzetes",
 };
const char *text_MAR_08_SK[POCET_JAZYKOV + 1] = 
{"Vıroèie posviacky katedrálneho chrámu v Bratislave",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "(nincs Magyarországon)",
 };
const char *text_MAR_09[POCET_JAZYKOV + 1] = 
{"Sv. Františky Rímskej, reho¾níèky",
 "Sv. Františky Øímské, øeholnice",
 "",
 "S. Franciscae Romanae, relig.",
 "",
 "Sv. Františky Øímské, øeholnice",
 "Római Szent Franciska szerzetesnõ",
 };
const char *text_MAR_10_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Sv. Jana Ogilvie, knìze a muèedníka",
 "",
 "(non est in Latina)",
 "",
 "Sv. Jana Ogilvie, knìze a muèedníka",
 "(nincs Magyarországon)",
 };
const char *text_MAR_15_CSSR[POCET_JAZYKOV + 1] = 
{"Sv. Klementa Márie Hofbauera, kòaza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAR_17[POCET_JAZYKOV + 1] = 
{"Sv. Patrika, biskupa",
 "Sv. Patrika, biskupa",
 "",
 "S. Patricii, ep.",
 "",
 "Sv. Patrika, biskupa",
 "Szent Patrik püspök",
 };
const char *text_MAR_18[POCET_JAZYKOV + 1] = 
{"Sv. Cyrila Jeruzalemského, biskupa a uèite¾a Cirkvi",
 "Sv. Cyrila Jeruzalémského, biskupa a uèitele církve",
 "",
 "S. Cyrilli Hierosolymitani, ep. et Eccl. doct.",
 "",
 "Sv. Cyrila Jeruzalémského, biskupa a uèitele Církve",
 "Jeruzsálemi Szent Cirill püspök és egyháztanító",
 };
const char *text_MAR_19[POCET_JAZYKOV + 1] = 
{"Sv. Jozefa, enícha Panny Márie",
 "Sv. Josefa, Snoubence Panny Marie",
 "",
 "S. Ioseph, Sponsi B. Mariae V.",
 "",
 "Sv. Josefa, Snoubence Panny Marie",
 "Szent József, a Boldogságos Szûz Mária jegyese",
 };
const char *text_MAR_23[POCET_JAZYKOV + 1] = 
{"Sv. Turibia de Mongrovejo, biskupa",
 "Sv. Turibia z Mongroveja, biskupa",
 "",
 "S. Turibii de Mogrovejo, ep.",
 "",
 "Sv. Turibia z Mongroveja, biskupa",
 "Mongrovejói Szent Turibiusz püspök",
 };
const char *text_MAR_25[POCET_JAZYKOV + 1] = 
{"Zvestovanie Pána",
 "Zvìstování Pánì",
 "",
 "In Annuntiatione Domini",
 "",
 "Zvìstování Pánì",
 "Urunk születésének hírüladása (Gyümölcsoltó Boldogasszony)",
 };

/* --------------- 04 apríl --------------- */

const char *text_APR_02[POCET_JAZYKOV + 1] = 
{"Sv. Františka z Pauly, pustovníka",
 "Sv. Františka z Pauly, poustevníka",
 "",
 "S. Francisci de Paola, eremitai",
 "",
 "Sv. Františka z Pauly, poustevníka",
 "Paolai Szent Ferenc remete",
 };
const char *text_APR_04[POCET_JAZYKOV + 1] = 
{"Sv. Izidora, biskupa a uèite¾a Cirkvi",
 "Sv. Izidora, biskupa a uèitele církve",
 "",
 "S. Isidori, ep. et Eccl. doct.",
 "",
 "Sv. Izidora, biskupa a uèitele Církve",
 "Szent Izidor püspök és egyháztanító",
 };
const char *text_APR_05[POCET_JAZYKOV + 1] = 
{"Sv. Vincenta Ferrera, kòaza",
 "Sv. Vincence Ferrerského, knìze",
 "",
 "S.  Vincentii Ferrer, presb.",
 "",
 "Sv. Vincence Ferrerského, knìze",
 "Ferrer Szent Vince áldozópap",
 };
const char *text_APR_07[POCET_JAZYKOV + 1] = 
{"Sv. Jána Krstite¾a de la Salle, kòaza",
 "Sv. Jana Køtitele de la Salle, knìze",
 "",
 "S.  Ioannis Baptistae de la Salle, presb.",
 "",
 "Sv. Jana Køtitele de la Salle, knìze",
 "De la Salle Szent János áldozópap",
 };
const char *text_APR_11[POCET_JAZYKOV + 1] = 
{"Sv. Stanislava, biskupa a muèeníka",
 "Sv. Stanislava, biskupa a muèedníka",
 "",
 "S.  Stanislai, ep.  et mart.",
 "",
 "Sv. Stanislava, biskupa a muèedníka",
 "Szent Szaniszló püspök és vértanú",
 };
const char *text_APR_13[POCET_JAZYKOV + 1] = 
{"Sv. Martina I., pápea a muèeníka",
 "Sv. Martina I., papee a muèedníka",
 "",
 "S. Martini I, papae et mart.",
 "",
 "Sv. Martina I., papee a muèedníka",
 "Szent I. Márton pápa és vértanú",
 };
const char *text_APR_20[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Sv. Aneky z Montepulciana, panny, mnišky",
 "hu_",
 };
const char *text_APR_21[POCET_JAZYKOV + 1] = 
{"Sv. Anzelma, biskupa a uèite¾a Cirkvi",
 "Sv. Anselma, biskupa a uèitele církve",
 "",
 "S. Anselmi, ep. et Eccl. doct.",
 "",
 "Sv. Anselma, biskupa a uèitele Církve",
 "Szent Anzelm püspök és egyháztanító",
 };
const char *text_APR_22_SJ[POCET_JAZYKOV + 1] = 
{"Prebl. Panny Márie, Matky Spoloènosti Jeišovej",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_APR_23[POCET_JAZYKOV + 1] = 
{"Sv. Vojtecha, biskupa a muèeníka",
 "Sv. Vojtìcha, biskupa a muèedníka",
 "",
 "S. Adalberti, ep. et mart.",
 "",
 "Sv. Vojtìcha, biskupa a muèedníka",
 "Szent Adalbert (Béla) püspök és vértanú",
 };
const char *text_APR_24_1[POCET_JAZYKOV + 1] = 
{"Sv. Juraja, muèeníka",
 "Sv. Jiøí, muèedníka",
 "",
 "S. Georgii, mart.",
 "",
 "Sv. Jiøí, muèedníka",
 "Szent György vértanú",
 };
const char *text_APR_24_2[POCET_JAZYKOV + 1] = 
{"Sv. Fidéla zo Sigmaringenu, kòaza a muèeníka",
 "Sv. Fidela ze Sigmaringy, knìze a muèedníka",
 "",
 "S. Fidelis a Sigmaringen, presb. et mart.",
 "",
 "Sv. Fidela ze Sigmaringy, knìze a muèedníka",
 "Sigmaringeni Szent Fidél áldozópap és vértanú",
 };
const char *text_APR_25[POCET_JAZYKOV + 1] = 
{"Sv. Marka, evanjelistu",
 "Sv. Marka, evangelisty",
 "",
 "S. Marci, evangelistae",
 "",
 "Sv. Marka, evangelisty",
 "Szent Márk evangelista",
 };
const char *text_APR_27_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Petra Kanízia, kòaza a uèite¾a Cirkvi",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_APR_28_1[POCET_JAZYKOV + 1] = 
{"Sv. Petra Chanela, kòaza a muèeníka",
 "Sv. Petra Chanela, knìze a muèedníka",
 "",
 "S. Petri Chanel, presb. et mart.",
 "",
 "Sv. Petra Chanela, knìze a muèedníka",
 "Chanel Szent Péter áldozópap és vértanú",
 };
const char *text_APR_28_2[POCET_JAZYKOV + 1] = 
{"Sv. ¼udovíta Márie Grignion de Montfort, kòaza",
 "Sv. Ludvíka Marie Grignona z Montfortu, knìze",
 "",
 "S. Ludovici M. Grignion de Montfort, presb.",
 "",
 "Sv. Ludvíka Marie Grignona z Montfortu, knìze, terciáøe",
 "(nincs Magyarországon)",
 };
const char *text_APR_29[POCET_JAZYKOV + 1] = 
{"Sv. Kataríny Sienskej, panny a uèite¾ky Cirkvi, spolupatrónky Európy",
 "Sv. Kateøiny Sienské, panny a uèitelky církve, spolupatronky Evropy",
 "",
 "S. Catharinae Senensis, virg. et Eccl. doct.",
 "",
 "Sv. Kateøiny Sienské, panny a uèitelky Církve, spolupatronky Evropy, terciáøky",
 "Sienai Szent Katalin szûz és egyháztanító",
 };
const char *text_APR_30_1[POCET_JAZYKOV + 1] = 
{"Sv. Pia V., pápea",
 "Sv. Pia V., papee",
 "",
 "S. Pii V, papae",
 "",
 "Sv. Pia V., papee",
 "Szent V. Piusz pápa",
 };
const char *text_APR_30_2[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Sv. Zikmunda, muèedníka",
 "",
 "(non est in Latina)",
 "",
 "Sv. Zikmunda, muèedníka",
 "(nincs Magyarországon)",
 };

/* --------------- 05 máj --------------- */

const char *text_MAJ_01[POCET_JAZYKOV + 1] = 
{"Sv. Jozefa, robotníka",
 "Sv. Josefa, Dìlníka",
 "",
 "S. loseph Opificis",
 "",
 "Sv. Josefa, Dìlníka",
 "Munkás Szent József",
 };
const char *text_MAJ_02[POCET_JAZYKOV + 1] = 
{"Sv. Atanáza, biskupa a uèite¾a Cirkvi",
 "Sv. Atanáše, biskupa a uèitele církve",
 "",
 "S. Athanasii, ep. et Eccl. doct.",
 "",
 "Sv. Atanáše, biskupa a uèitele Církve",
 "Szent Atanáz püspök és egyháztanító",
 };
const char *text_MAJ_03[POCET_JAZYKOV + 1] = 
{"Sv. Filipa a Jakuba, apoštolov",
 "Sv. Filipa a Jakuba, apoštolù",
 "",
 "Ss. Philippi et Iacobi, apostolorum",
 "",
 "Sv. Filipa a Jakuba, apoštolù",
 "Szent Fülöp és Szent Jakab apostol",
 };
const char *text_MAJ_04_SJ[POCET_JAZYKOV + 1] = 
{"Bl. Jozefa Márie Rubia, kòaza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_06[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Sv. Jana Sarkandra, knìze a muèedníka",
 "",
 "(non est in Latina)",
 "",
 "Sv. Jana Sarkandra, knìze a muèedníka",
 "(nincs Magyarországon)",
 };
const char *text_MAJ_06_SDB[POCET_JAZYKOV + 1] = 
{"Sv. Dominika Savia, mladíka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_08_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Panny Marie, Prostøednice všech milostí",
 "",
 "(non est in Latina)",
 "",
 "Panny Marie, Prostøednice všech milostí",
 "(nincs Magyarországon)",
 };
const char *text_MAJ_10_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Sv. Antonína Pierozziho neboli Florentského, biskupa",
 "hu_",
 };
const char *text_MAJ_11_SK[POCET_JAZYKOV + 1] = 
{"Bl. Sáry Salkaháziovej, panny a muèenice",
 "",
 "",
 "(non est in Latina)",
 "",
 "",
 "(nincs Magyarországon)",
 };
const char *text_MAJ_12_1[POCET_JAZYKOV + 1] = 
{"Sv. Nerea a Achila, muèeníkov",
 "Sv. Nerea a Achillea, muèedníkù",
 "",
 "Ss. Nerei et Achillei, mart.",
 "",
 "Sv. Nerea a Achillea, muèedníkù",
 "Szent Néreusz és Szent Achilleusz vértanúk",
 };
const char *text_MAJ_12_2[POCET_JAZYKOV + 1] = 
{"Sv. Pankráca, muèeníka",
 "Sv. Pankráce, muèedníka",
 "",
 "S. Pancratii, mart.",
 "",
 "Sv. Pankráce, muèedníka",
 "Szent Pongrác vértanú",
 };
const char *text_MAJ_12_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Vıroèí posvìcení katedrály sv. Víta",
 "",
 "(non est in Latina)",
 "",
 "Vıroèí posvìcení katedrály sv. Víta",
 "(nincs Magyarországon)",
 };
const char *text_MAJ_13[POCET_JAZYKOV + 1] = 
{"Panny Márie Fatimskej",
 "Panny Marie Fatimské",
 "",
 "",
 "",
 "Panny Marie Fatimské",
 "(nincs Magyarországon)",
 };
const char *text_MAJ_13_SDB[POCET_JAZYKOV + 1] = 
{"Sv. Márie Dominiky Mazzarellovej, panny, <br>spoluzakladate¾ky Inštitútu dcér Márie Pomocnice",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_14[POCET_JAZYKOV + 1] = 
{"Sv. Mateja, apoštola",
 "Sv. Matìje, apoštola",
 "",
 "S. Matthiae, apostoli",
 "",
 "Sv. Matìje, apoštola",
 "(nincs Magyarországon)",
 };
const char *text_MAJ_15_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Panny Marie, ochránkynì Øádu bratøí kazatelù",
 "hu_",
 };
const char *text_MAJ_16_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Andreja Bobolu, kòaza a  muèeníka", // text_MAJ_15_SJ: na Slovensku sa slávi 15. mája
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_16[POCET_JAZYKOV + 1] = 
{"Sv. Jána Nepomuckého, kòaza a muèeníka",
 "Sv. Jana Nepomuckého, knìze a muèedníka, hlavního patrona Èech",
 "",
 "(non est in Latina)",
 "",
 "Sv. Jana Nepomuckého, knìze a muèedníka, hlavního patrona Èech",
 "Nepomuki Szent János áldozópap és vértanú",
 };
const char *text_MAJ_16_SDB[POCET_JAZYKOV + 1] = 
{"Sv. Alojza Orioneho, kòaza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_18[POCET_JAZYKOV + 1] = 
{"Sv. Jána I., pápea a muèeníka",
 "Sv. Jana I., papee a muèedníka",
 "",
 "S. Ioannis I, papae et mart.",
 "",
 "Sv. Jana I., papee a muèedníka",
 "Szent I. János pápa és vértanú",
 };
const char *text_MAJ_18_SDB[POCET_JAZYKOV + 1] = 
{"Sv. Leonarda Murialda, kòaza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_20_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Sv. Klementa Marie Hofbauera, knìze",
 "",
 "",
 "",
 "Sv. Klementa Marie Hofbauera, knìze",
 "(nincs Magyarországon)",
 };
const char *text_MAJ_20[POCET_JAZYKOV + 1] = 
{"Sv. Bernardína Sienského, kòaza",
 "Sv. Bernardina Sienského, knìze",
 "",
 "S. Bernardini Senensis, presb.",
 "",
 "Sv. Bernardina Sienského, knìze",
 "Sienai Szent Bernardin áldozópap",
 };
const char *text_MAJ_21_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Vıroèí posvìcení katedrály sv. Petra a Pavla",
 "",
 "(non est in Latina)",
 "",
 "Vıroèí posvìcení katedrály sv. Petra a Pavla",
 "(nincs Magyarországon)",
 };
const char *text_MAJ_21[POCET_JAZYKOV + 1] = 
{"Sv. Krištofa Magallanesa, kòaza a spoloèníkov, muèeníkov",
 "Sv. Kryštofa Magallanese, knìze a druhù, muèedníkù",
 "",
 "",
 "",
 "Sv. Kryštofa Magallanese, knìze a druhù, muèedníkù",
 "hu_",
 };
const char *text_MAJ_21_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Bl. Hyacinta Marie Cormiera, knìze",
 "hu_",
 };
const char *text_MAJ_22[POCET_JAZYKOV + 1] = 
{"Sv. Rity z Kassie, reho¾níèky",
 "Sv. Rity z Cascie, øeholnice",
 "",
 "la_",
 "",
 "Sv. Rity z Cascie, øeholnice",
 "Szent Rita özvegy",
 };
const char *text_MAJ_24_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Pøenesení ostatkù sv. Otce Dominika",
 "hu_",
 };
const char *text_MAJ_24_SDB[POCET_JAZYKOV + 1] = 
{"Panny Márie, Pomocnice kresanov, <br>hlavnej patrónky Inštitútu dcér Márie Pomocnice a celej saleziánskej rodiny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_25_1[POCET_JAZYKOV + 1] = 
{"Sv. Bédu Ctihodného, kòaza a uèite¾a Cirkvi",
 "Sv. Bedy Ctihodného, knìze a uèitele církve",
 "",
 "S. Bedae Venerdbilis, presb. et Ecci. doct.",
 "",
 "Sv. Bedy Ctihodného, knìze a uèitele Církve",
 "Tiszteletreméltó Szent Béda áldozópap és egyháztanító",
 };
const char *text_MAJ_25_2[POCET_JAZYKOV + 1] = 
{"Sv. Gregora VII., pápea",
 "Sv. Øehoøe VII., papee",
 "",
 "S. Gregorii VII, papae",
 "",
 "Sv. Øehoøe VII., papee",
 "Szent VII. Gergely pápa",
 };
const char *text_MAJ_25_3[POCET_JAZYKOV + 1] = 
{"Sv. Márie Magdalény de Pazzi, panny",
 "Sv. Marie Magdalény de Pazzi, panny",
 "",
 "S. Mariae Magdalenae de Pazzi, virg.",
 "",
 "Sv. Marie Magdalény de Pazzi, panny",
 "Pazzi Szent Mária Magdolna Szûz",
 };
const char *text_MAJ_26[POCET_JAZYKOV + 1] = 
{"Sv. Filipa Neriho, kòaza",
 "Sv. Filipa Neriho, knìze",
 "",
 "S. Philippi Neri, presb.",
 "",
 "Sv. Filipa Neriho, knìze",
 "Néri Szent Fülöp áldozópap",
 };
const char *text_MAJ_27[POCET_JAZYKOV + 1] = 
{"Sv. Augustína z Canterbury, biskupa",
 "Sv. Augustina z Canterbury, biskupa",
 "",
 "S. Augustini Cantuariensis, ep.",
 "",
 "Sv. Augustina z Canterbury, biskupa",
 "Canterbury Szent Ágoston püspök",
 };
const char *text_MAJ_29_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Jozefa Kowalského, muèeníka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_30_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Sv. Zdislavy",
 "",
 "(non est in Latina)",
 "",
 "Sv. Zdislavy z Lemberka, matky rodiny, terciáøky, spolupatronky provincie",
 "(nincs Magyarországon)",
 };
const char *text_MAJ_31[POCET_JAZYKOV + 1] = 
{"Navštívenie prebl. Panny Márie",
 "Navštívení Panny Marie",
 "",
 "",
 "",
 "Navštívení Panny Marie",
 "(nincs Magyarországon)",
 };

/* --------------- 00 pohyblivé slávenia --------------- */

const char *text_NANEBOVSTUPENIE_PANA[POCET_JAZYKOV + 1] = 
{"Nanebovstúpenie Pána",
 "Nanebevstoupení Pánì",
 "",
 "",
 "",
 "Nanebevstoupení Pánì",
 "hu_name",
 };
const char *text_VELKONOCNA_NEDELA[POCET_JAZYKOV + 1] = 
{"Ve¾konoèná nede¾a",
 "Nedìle Zmrtvıchvstání Pánì",
 "",
 "",
 "",
 "Nedìle Zmrtvıchvstání Pánì",
 "hu_name",
 };
const char *text_NEDELA_PANOVHO_ZMRTVYCHVSTANIA[POCET_JAZYKOV + 1] = 
{" &mdash; Nede¾a Pánovho zmàtvychvstania",
 "",
 "",
 "",
 "",
 "",
 "hu_name",
 };
const char *text_NEDELA_VO_VELKONOCNEJ_OKTAVE[POCET_JAZYKOV + 1] = 
{"Nede¾a vo Ve¾konoènej oktáve",
 "Nedìle v oktávu velikonoèním",
 "",
 "",
 "",
 "Nedìle v oktávu velikonoèním",
 "hu_name",
 };
const char *text_DEN_VO_VELKONOCNEJ_OKTAVE[POCET_JAZYKOV + 1] = 
{"Ve¾konoèn%c %s",
 "%s velikonoèní",
 "",
 "",
 "",
 "%s velikonoèní",
 "hu_name",
 };
const char *text_NAJSVATEJSEJ_TROJICE[POCET_JAZYKOV + 1] = 
{"Najsvätejšej Trojice",
 "Nejsvìtìjší Trojice",
 "",
 "",
 "",
 "Nejsvìtìjší Trojice",
 "hu_name",
 };
const char *text_KRISTA_KRALA[POCET_JAZYKOV + 1] = 
{"Krista Krá¾a",
 "Jeíše Krista Krále",
 "",
 "",
 "",
 "Jeíše Krista Krále",
 "hu_name",
 };
const char *text_NAJSV_KRISTOVHO_TELA_A_KRVI[POCET_JAZYKOV + 1] = 
{"Najsvätejšieho Kristovho tela a krvi",
 "Tìla a krve Pánì",
 "",
 "",
 "",
 "Tìla a krve Pánì",
 "hu_name",
 };
const char *text_NAJSV_SRDCA_JEZISOVHO[POCET_JAZYKOV + 1] = 
{"Najsvätejšieho Srdca Jeišovho",
 "Nejsvìtìjšího Srdce Jeíšova",
 "",
 "",
 "",
 "Nejsvìtìjšího Srdce Jeíšova",
 "hu_name",
 };
const char *text_NEPOSKVRNENEHO_SRDCA_PM[POCET_JAZYKOV + 1] = 
{"Nepoškvrneného Srdca Panny Márie", // 2010-06-16: opravenı názov pod¾a breviára i direktória
 "Neposkvrnìného Srdce Panny Marie",
 "",
 "",
 "",
 "Neposkvrnìného Srdce Panny Marie",
 "hu_name",
 };
const char *text_NARODENIE_PANA[POCET_JAZYKOV + 1] = 
{"Narodenie Pána",
 "Narození Pánì",
 "",
 "",
 "",
 "Narození Pánì",
 "Urunk Születése (Karácsony)",
 };
const char *text_ZOSLANIE_DUCHA_SVATEHO[POCET_JAZYKOV + 1] = 
{"Zoslanie Ducha Svätého",
 "Seslání Ducha svatého",
 "",
 "",
 "",
 "Seslání Ducha Svatého",
 "hu_name",
 };
const char *text_PRVA_ADVENTNA_NEDELA[POCET_JAZYKOV + 1] = 
{"Prvá adventná nede¾a",
 "První nedìle adventní",
 "",
 "",
 "",
 "První nedìle adventní",
 "hu_name",
 };
const char *text_NEDELA_SV_RODINY[POCET_JAZYKOV + 1] = 
{"Svätej rodiny Jeiša, Márie a Jozefa",
 "Sv. Rodiny Jeíše, Marie a Josefa",
 "",
 "",
 "",
 "Sv. Rodiny Jeíše, Marie a Josefa",
 "A Szent család: Jézus, Mária és József",
 };
const char *text_SPOMIENKA_PM_V_SOBOTU[POCET_JAZYKOV + 1] = 
{"Spomienka Panny Márie v sobotu",
 "Sobotní památka Panny Marie",
 "()",
 "Memoria S. Mariae in sabbato",
 "",
 "Sobotní památka Panny Marie",
 "hu_name",
 };

/* --------------- 06 jún --------------- */

const char *text_JUN_01[POCET_JAZYKOV + 1] = 
{"Sv. Justína, muèeníka",
 "Sv. Justina, muèedníka",
 "",
 "",
 "",
 "Sv. Justina, muèedníka",
 "Szent Jusztínusz vértanú",
 };
const char *text_JUN_02[POCET_JAZYKOV + 1] = 
{"Sv. Marcelína a Petra, muèeníkov",
 "Sv. Marcelina a Petra, muèedníkù",
 "",
 "",
 "",
 "Sv. Marcelina a Petra, muèedníkù",
 "Szent Marcellínusz és Szent Péter vértanúk",
 };
const char *text_JUN_03[POCET_JAZYKOV + 1] = 
{"Sv. Karola Lwangu a spoloèníkov, muèeníkov",
 "Sv. Karla Lwangy a druhù, muèedníkù",
 "",
 "",
 "",
 "Sv. Karla Lwangy a druhù, muèedníkù",
 "Lwanga Szent Károly és társai, vértanúk",
 };
const char *text_JUN_04_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Sv. Petra Veronského, knìze a muèedníka",
 "hu_",
 };
const char *text_JUN_05[POCET_JAZYKOV + 1] = 
{"Sv. Bonifáca, biskupa a muèeníka",
 "Sv. Bonifáce, biskupa a muèedníka",
 "",
 "",
 "",
 "Sv. Bonifáce, biskupa a muèedníka",
 "Szent Bonifác püspök és vértanú",
 };
const char *text_JUN_06[POCET_JAZYKOV + 1] = 
{"Sv. Norberta, biskupa",
 "Sv. Norberta, biskupa",
 "",
 "",
 "",
 "Sv. Norberta, biskupa",
 "Szent Norbert püspök",
 };
const char *text_JUN_08_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Bl. Diany Andalo a Cecílie, panen, mnišek",
 "hu_",
 };
const char *text_JUN_09[POCET_JAZYKOV + 1] = 
{"Sv. Efréma, diakona a uèite¾a Cirkvi",
 "Sv. Efréma Syrského, jáhna a uèitele církve",
 "",
 "",
 "",
 "Sv. Efréma Syrského, jáhna a uèitele Církve",
 "Szent Efrém diakónus és egyháztanító",
 };
const char *text_JUN_09_SJ[POCET_JAZYKOV + 1] = 
{"Bl. Jozefa de Anchieta, kòaza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_10_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Bl. Jana Dominiciho, biskupa",
 "hu_",
 };
const char *text_JUN_11[POCET_JAZYKOV + 1] = 
{"Sv. Barnabáša, apoštola",
 "Sv. Barnabáše, apoštola",
 "",
 "",
 "",
 "Sv. Barnabáše, apoštola",
 "Szent Barnabás apostol",
 };
const char *text_JUN_12_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Františka K&#553;syho a spoloèníkov, muèeníkov", // Bl. Františka Kesyho a spoloèníkov, muèeníkov (small latin letter e with cedilla)
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_13[POCET_JAZYKOV + 1] = 
{"Sv. Antona Paduánskeho, kòaza a uèite¾a Cirkvi",
 "Sv. Antonína z Padovy, knìze a uèitele církve",
 "",
 "",
 "",
 "Sv. Antonína z Padovy, knìze a uèitele Církve",
 "Páduai Szent Antal áldozópap és egyháztanító",
 };
const char *text_JUN_15_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Sv. Víta, muèedníka",
 "",
 "",
 "",
 "Sv. Víta, muèedníka",
 "(nincs Magyarországon)",
 };
const char *text_JUN_16_SK[POCET_JAZYKOV + 1] = 
{"Sv. Neita, muèeníka",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "(nincs Magyarországon)",
 };
const char *text_JUN_19[POCET_JAZYKOV + 1] = 
{"Sv. Romualda, opáta",
 "Sv. Romualda, opata",
 "",
 "",
 "",
 "Sv. Romualda, opata",
 "Szent Romuald apát",
 };
const char *text_JUN_19_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Sv. Jana Nepomuckého Neumanna, biskupa",
 "",
 "",
 "",
 "Sv. Jana Nepomuckého Neumanna, biskupa",
 "(nincs Magyarországon)",
 };
const char *text_JUN_21[POCET_JAZYKOV + 1] = 
{"Sv. Alojza Gonzágu, reho¾níka",
 "Sv. Aloise Gonzagy, øeholníka",
 "",
 "",
 "",
 "Sv. Aloise Gonzagy, øeholníka",
 "Gonzága Szent Alajos szerzetes",
 };
const char *text_JUN_21_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Alojza Gonzagu, reho¾níka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_22_2[POCET_JAZYKOV + 1] = 
{"Sv. Pavlína z Noly, biskupa",
 "Sv. Paulina Nolánského, biskupa",
 "",
 "",
 "",
 "Sv. Paulina Nolánského, biskupa",
 "Nolai Szent Paulínusz püspök",
 };
const char *text_JUN_22_1[POCET_JAZYKOV + 1] = 
{"Sv. Jána Fishera, biskupa, a sv. Tomáša Mórusa, muèeníkov",
 "Sv. Jana Fishera, biskupa, a Tomáše Mora, muèedníkù",
 "",
 "",
 "",
 "Sv. Jana Fishera, biskupa, a Tomáše Mora, muèedníkù",
 "Fisher Szent János püspök és Morus Szent Tamás vértanúk",
 };
const char *text_JUN_23_SDB[POCET_JAZYKOV + 1] = 
{"Sv. Jozefa Cafassa, kòaza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_24[POCET_JAZYKOV + 1] = 
{"Narodenie sv. Jána Krstite¾a",
 "Narození svatého Jana Køtitele",
 "",
 "",
 "",
 "Narození svatého Jana Køtitele",
 "Keresztelõ Szent János születése",
 };
const char *text_JUN_27[POCET_JAZYKOV + 1] = 
{"Sv. Cyrila Alexandrijského, biskupa a uèite¾a Cirkvi",
 "Sv. Cyrila Alexandrijského, biskupa a uèitele církve",
 "",
 "",
 "",
 "Sv. Cyrila Alexandrijského, biskupa a uèitele církve",
 "(nincs Magyarországon)",
 };
const char *text_JUN_27_SK_HU[POCET_JAZYKOV + 1] = 
{"Sv. Ladislava",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "Szent László király",
 };
const char *text_JUN_27_CSSR[POCET_JAZYKOV + 1] = 
{"Panny Márie, Matky ustaviènej pomoci",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "",
 };
const char *text_JUN_28[POCET_JAZYKOV + 1] = 
{"Sv. Ireneja, biskupa a muèeníka",
 "Sv. Ireneje, biskupa a muèedníka",
 "",
 "",
 "",
 "Sv. Ireneje, biskupa a muèedníka",
 "Szent Iréneusz püspök és vértanú",
 };
const char *text_JUN_29[POCET_JAZYKOV + 1] = 
{"Sv. Petra a Pavla, apoštolov",
 "Sv. Petra a Pavla, apoštolù",
 "",
 "",
 "",
 "Sv. Petra a Pavla, apoštolù",
 "Szent Péter és Szent Pál apostolok",
 };
const char *text_JUN_30[POCET_JAZYKOV + 1] = 
{"Prvıch svätıch muèeníkov Cirkvi v Ríme",
 "Svatıch prvomuèedníkù øímskıch",
 "",
 "",
 "",
 "Svatıch prvomuèedníkù øímskıch",
 "A római Egyház elsõ szent vértanúi",
 };
const char *text_JUN_30_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Vıroèí posvìcení katedrály sv. Václava",
 "",
 "",
 "",
 "Vıroèí posvìcení katedrály sv. Václava",
 "(nincs Magyarországon)",
 };
const char *text_JUN_30_CSSR[POCET_JAZYKOV + 1] = 
{"Bl. Januára Márie Sarnelliho, kòaza",
 "",
 "",
 "",
 "",
 "",
 "(nincs Magyarországon)",
 };

/* --------------- 07 júl --------------- */

const char *text_JUL_02_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Bernardína Realina, sv. Jána Františka Régisa, sv. Františka de Geronimo, <br>bl. Juliána Maunoira, bl. Antona Baldinucciho, kòazov", // text_JUL_01_SJ: na Slovensku sa slávi 1. júla
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUL_03[POCET_JAZYKOV + 1] = 
{"Sv. Tomáša, apoštola",
 "Sv. Tomáše, apoštola",
 "",
 "",
 "",
 "Sv. Tomáše, apoštola",
 "Szent Tamás apostol",
 };
const char *text_JUL_04[POCET_JAZYKOV + 1] = 
{"Sv. Albety Portugalskej",
 "Sv. Albìty Portugalské",
 "",
 "",
 "",
 "Sv. Albìty Portugalské",
 "Portugáliai Szent Erzsébet",
 };
const char *text_JUL_04_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Sv. Prokopa, opata",
 "",
 "",
 "",
 "Sv. Prokopa, opata",
 "(nincs Magyarországon)",
 };
const char *text_JUL_05[POCET_JAZYKOV + 1] = 
{"Sv. Cyrila a Metoda, slovanskıch vierozvestov, apoštolov",
 "Sv. Cyrila, mnicha, a Metodìje, biskupa, patronù Evropy, hlavních patronù Moravy",
 "",
 "",
 "",
 "Sv. Cyrila, mnicha, a Metodìje, biskupa, patronù Evropy, hlavních patronù Moravy",
 "(nincs Magyarországon)",
 };
const char *text_JUL_06[POCET_JAZYKOV + 1] = 
{"Sv. Márie Goretti, panny a muèenice",
 "Sv. Marie Gorettiové, panny a muèednice",
 "",
 "",
 "",
 "Sv. Marie Gorettiové, panny a muèednice",
 "Goretti Szent Mária szûz és vértanú",
 };
const char *text_JUL_06_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "Blaholaveného Pier Giorgio Frassatiho, laika OP",
 "nincs Magyarországon)",
 };
const char *text_JUL_07[POCET_JAZYKOV + 1] = 
{"Sv. Antona Márie Zaccariu, kòaza",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "(nincs Magyarországon)",
 };
const char *text_JUL_07_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Márie Romerovej Meneses, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUL_09[POCET_JAZYKOV + 1] = 
{"Sv. Augustína Zhao Rong, kòaza, a spoloèníkov, muèeníkov",
 "Sv. Augustina ao Ronga, knìze a jeho druhù, muèedníkù",
 "",
 "",
 "",
 "Sv. Augustina ao Ronga, knìze a jeho druhù, muèedníkù",
 "",
 };
const char *text_JUL_09_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "Sv. Jana Kolínského, knìze, a druhù, muèedníkù",
 "(nincs Magyarországon)",
 };
const char *text_JUL_11[POCET_JAZYKOV + 1] = 
{"Sv. Benedikta, opáta, patróna Európy",
 "Sv. Benedikta, opata, patrona Evropy",
 "",
 "",
 "",
 "Sv. Benedikta, opata, patrona Evropy",
 "Szent Benedek apát, Európa fõvédõszentje",
 };
const char *text_JUL_13[POCET_JAZYKOV + 1] = 
{"Sv. Henricha",
 "Sv. Jindøicha",
 "",
 "",
 "",
 "Sv. Jindøicha",
 "Szent Henrik",
 };
const char *text_JUL_14[POCET_JAZYKOV + 1] = 
{"Sv. Kamila de Lellis, kòaza",
 "Sv. Kamila de Lellis, knìze",
 "",
 "",
 "",
 "Sv. Kamila de Lellis, knìze",
 "Lellisi Szent Kamill áldozópap",
 };
const char *text_JUL_14_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Bl. Hroznaty, muèedníka",
 "",
 "",
 "",
 "Bl. Hroznaty, muèedníka",
 "(nincs Magyarországon)",
 };
const char *text_JUL_15[POCET_JAZYKOV + 1] = 
{"Sv. Bonaventúru, biskupa a uèite¾a Cirkvi",
 "Sv. Bonaventury, biskupa a uèitele církve",
 "",
 "",
 "",
 "Sv. Bonaventury, biskupa a uèitele Církve",
 "Szent Bonaventúra püspök és egyháztanító",
 };
const char *text_JUL_16[POCET_JAZYKOV + 1] = 
{"Prebl. Panny Márie Karmelskej",
 "Panny Marie Karmelské",
 "",
 "",
 "",
 "Panny Marie Karmelské",
 "Kármel-hegyi Boldogasszony",
 };
const char *text_JUL_16_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Vıroèí posvìcení katedrály Boského Spasitele",
 "",
 "",
 "",
 "Vıroèí posvìcení katedrály Boského Spasitele",
 "(nincs Magyarországon)",
 };
const char *text_JUL_17_SK[POCET_JAZYKOV + 1] = 
{"Sv. Andreja-Svorada a Benedikta, pustovníkov",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "Szent Zoerárd-András és Benedek remeték",
 };
const char *text_JUL_17_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Bl. Èeslava a sv. Hyacinta, knìí",
 "",
 "",
 "",
 "Bl. Èeslava a sv. Hyacinta, knìí",
 "(nincs Magyarországon)",
 };
const char *text_JUL_17_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Bl. Èeslava z Polska, knìze",
 "hu_",
 };
const char *text_JUL_20[POCET_JAZYKOV + 1] = 
{"Sv. Apolinára, biskupa a muèeníka",
 "Sv. Apolináøe, biskupa a muèedníka",
 "",
 "",
 "",
 "Sv. Apolináøe, biskupa a muèedníka",
 "(nincs Magyarországon)",
 };
const char *text_JUL_21[POCET_JAZYKOV + 1] = 
{"Sv. Vavrinca z Brindisi, kòaza a uèite¾a Cirkvi",
 "Sv. Vavøince z Brindisi, knìze a uèitele církve",
 "",
 "",
 "",
 "Sv. Vavøince z Brindisi, knìze a uèitele Církve",
 "Brindisi Szent Lõrinc Áldozópap és egyháztanító",
 };
const char *text_JUL_22[POCET_JAZYKOV + 1] = 
{"Sv. Márie Magdalény",
 "Sv. Marie Magdalény",
 "",
 "",
 "",
 "Sv. Marie Magdalény",
 "Szent Mária Magdolna",
 };
const char *text_JUL_23[POCET_JAZYKOV + 1] = 
{"Sv. Brigity, reho¾níèky, spolupatrónky Európy",
 "Sv. Brigity, øeholnice patronky Evropy",
 "",
 "",
 "",
 "Sv. Brigity, øeholnice patronky Evropy",
 "Szent Brigitta szerzetesnõ",
 };
const char *text_JUL_24[POCET_JAZYKOV + 1] = 
{"Sv. Sarbela Makhlufa, kòaza", /* 2009-07-15: direktórium má "Sarbel", predtım bolo "Charbel" a asi sa èíta "Šarbel" */
 "Sv. Šarbela Makhlúfa, knìze",
 "",
 "",
 "",
 "Sv. Šarbela Makhlúfa, knìze",
 "",
 };
const char *text_JUL_25[POCET_JAZYKOV + 1] = 
{"Sv. Jakuba, apoštola",
 "Sv. Jakuba, apoštola",
 "",
 "",
 "",
 "Sv. Jakuba, apoštola",
 "Szent Jakab apostol",
 };
const char *text_JUL_26[POCET_JAZYKOV + 1] = 
{"Sv. Joachima a Anny, rodièov Panny Márie",
 "Sv. Jáchyma a Anny, rodièù Panny Marie",
 "",
 "",
 "",
 "Sv. Jáchyma a Anny, rodièù Panny Marie",
 "Szent Joakim és Szent Anna, a Boldogságos Szûz Mária szülei",
 };
const char *text_JUL_27[POCET_JAZYKOV + 1] = 
{"Sv. Gorazda a spoloèníkov",
 "Sv. Gorazda a druhù",
 "",
 "",
 "",
 "Sv. Gorazda a druhù",
 "(nincs Magyarországon)",
 };
const char *text_JUL_29[POCET_JAZYKOV + 1] = 
{"Sv. Marty",
 "Sv. Marty",
 "",
 "",
 "",
 "Sv. Marty",
 "Szent Márta",
 };
const char *text_JUL_30[POCET_JAZYKOV + 1] = 
{"Sv. Petra Chryzológa, biskupa a uèite¾a Cirkvi",
 "Sv. Petra Chryzologa, biskupa a uèitele církve",
 "",
 "",
 "",
 "Sv. Petra Chryzologa, biskupa a uèitele církve",
 "Aranyszavú (Krizologosz) Szent Péter püspök és egyháztanító",
 };
const char *text_JUL_30_SK[POCET_JAZYKOV + 1] = 
{"Bl. Zdenky Schelingovej, panny a muèenice",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "(nincs Magyarországon)",
 };
const char *text_JUL_31[POCET_JAZYKOV + 1] = 
{"Sv. Ignáca z Loyoly, kòaza",
 "Sv. Ignáce z Loyoly, knìze",
 "",
 "",
 "",
 "Sv. Ignáce z Loyoly, knìze",
 "Loyolai Szent Ignác áldozópap",
 };
const char *text_JUL_31_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Ignáca Loyolského, kòaza a zakladate¾a Spoloènosti Jeišovej",
 "",
 "",
 "",
 "",
 "",
 "",
 };

/* --------------- 00 pohyblivé slávenia --------------- */

const char *text_CSSR_TITUL_KONGREGACIE[POCET_JAZYKOV + 1] = 
{"Najsvätejšieho Vykupite¾a, titul Kongregácie", //  3. nede¾a v júli
 "",
 "",
 "",
 "",
 "",
 "",
 };

/* --------------- 08 august --------------- */

const char *text_AUG_01[POCET_JAZYKOV + 1] = 
{"Sv. Alfonza Márie de Liguori, biskupa a uèite¾a Cirkvi",
 "Sv. Alfonsa z Liguori, biskupa a uèitele církve",
 "",
 "",
 "",
 "Sv. Alfonsa z Liguori, biskupa a uèitele Církve",
 "Liguori Szent Alfonz Mária püspök és egyháztanító",
 };
const char *text_AUG_01_CSSR[POCET_JAZYKOV + 1] = 
{"Sv. Alfonza Márie de Liguori, biskupa a uèite¾a Cirkvi, zakladate¾a kongregácie",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_AUG_02_1[POCET_JAZYKOV + 1] = 
{"Sv. Euzébia Vercellského, biskupa",
 "Sv. Eusebia z Vercelli, biskupa",
 "",
 "",
 "",
 "Sv. Eusebia z Vercelli, biskupa",
 "Vercelli Szent Özséb püspök",
 };
const char *text_AUG_02_2[POCET_JAZYKOV + 1] = 
{"Sv. Petra Juliána Eymard, kòaza",
 "Sv. Petra Juliána Eymarda, knìze",
 "",
 "",
 "",
 "Sv. Petra Juliána Eymarda, knìze",
 "(nincs Magyarországon)",
 };
const char *text_AUG_02_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Bl. Jany, matky sv. Otce Dominika",
 "hu_",
 };
const char *text_AUG_02_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Augustína Czartoryského, kòaza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_AUG_02_SJ[POCET_JAZYKOV + 1] = 
{"Bl. Petra Favra, kòaza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_AUG_04[POCET_JAZYKOV + 1] = 
{"Sv. Jána Márie Vianneya, kòaza",
 "Sv. Jana Marie Vianneye, knìze",
 "",
 "",
 "",
 "Sv. Jana Marie Vianneye, knìze",
 "Vianney Szent János Mária áldozópap",
 };
const char *text_AUG_05[POCET_JAZYKOV + 1] = 
{"Vıroèie posviacky hlavnej mariánskej baziliky v Ríme",
 "Posvìcení øímské baziliky Panny Marie",
 "",
 "",
 "",
 "Posvìcení øímské baziliky Panny Marie",
 "Szûz Mária római fõtemplomának felszentelése (Havas Boldogasszony)",
 };
const char *text_AUG_06[POCET_JAZYKOV + 1] = 
{"Premenenie Pána",
 "Promìnìní Pánì",
 "",
 "",
 "",
 "Promìnìní Pánì",
 "Urunk Színeváltozása",
 };
const char *text_AUG_07_1[POCET_JAZYKOV + 1] = 
{"Sv. Sixta II., pápea, a jeho spoloèníkov, muèeníkov",
 "Sv. Sixta II., papee, a druhù, muèedníkù",
 "",
 "",
 "",
 "Sv. Sixta II., papee, a druhù, muèedníkù",
 "Szent II. Szixtusz pápa és társai vértanúk",
 };
const char *text_AUG_07_2[POCET_JAZYKOV + 1] = 
{"Sv. Kajetána, kòaza",
 "Sv. Kajetána, knìze",
 "",
 "",
 "",
 "Sv. Kajetána, knìze",
 "Szent Kajetán áldozópap",
 };
const char *text_AUG_08[POCET_JAZYKOV + 1] = 
{"Sv. Dominika, kòaza",
 "Sv. Dominika, knìze",
 "",
 "",
 "",
 "Sv. Otce Dominika, knìze",
 "Szent Domonkos áldozópap",
 };
const char *text_AUG_09[POCET_JAZYKOV + 1] = 
{"Sv. Terézie Benedikty, reho¾níèky a muèenice, spolupatrónky Európy",
 "Sv. Terezie Benedikty, panny a muèednice, patronky Evropy",
 "",
 "",
 "",
 "Sv. Terezie Benedikty, panny a muèednice, patronky Evropy",
 "",
 };
const char *text_AUG_10[POCET_JAZYKOV + 1] = 
{"Sv. Vavrinca, diakona a muèeníka",
 "Sv. Vavøince, muèedníka",
 "",
 "",
 "",
 "Sv. Vavøince, muèedníka",
 "Szent Lõrinc diakónus és vértanú",
 };
const char *text_AUG_11[POCET_JAZYKOV + 1] = 
{"Sv. Kláry, panny",
 "Sv. Kláry, panny",
 "",
 "",
 "",
 "Sv. Kláry, panny",
 "Szent Klára szûz",
 };
const char *text_AUG_12[POCET_JAZYKOV + 1] = 
{"Sv. Jany Františky de Chantal, reho¾níèky", // kedysi sa slávil 12. decembra
 "Sv. Jany Františky de Chantal, øeholnice",
 "",
 "",
 "",
 "Sv. Jany Františky de Chantal, øeholnice",
 "",
 };
const char *text_AUG_13[POCET_JAZYKOV + 1] = 
{"Sv. Ponciána, pápea, a sv. Hypolita, kòaza, muèeníkov",
 "Sv. Ponciána, papee, a Hippolyta, knìze, muèedníkù",
 "",
 "",
 "",
 "Sv. Ponciána, papee, a Hippolyta, knìze, muèedníkù",
 "Szent Ponciánusz pápa és szent Hippolitusz áldozópap és vértanúk",
 };
const char *text_AUG_14[POCET_JAZYKOV + 1] = 
{"Sv. Maximiliána Kolbeho, kòaza a muèeníka",
 "Sv. Maxmiliána Marie Kolbeho, knìze a muèedníka",
 "",
 "",
 "",
 "Sv. Maxmiliána Marie Kolbeho, knìze a muèedníka",
 "Szent Maximilián Mária Kolbe áldozópap és vértanú",
 };
const char *text_AUG_15[POCET_JAZYKOV + 1] = 
{"Nanebovzatie prebl. Panny Márie",
 "Nanebevzetí Panny Marie",
 "",
 "",
 "",
 "Nanebevzetí Panny Marie",
 "Szûz Mária Mennybevétele (Nagyboldogasszony)",
 };
const char *text_AUG_16[POCET_JAZYKOV + 1] = 
{"Sv. Štefana Uhorského",
 "Sv. Štìpána Uherského",
 "",
 "",
 "",
 "Sv. Štìpána Uherského",
 "(nincs Magyarországon)",
 };
const char *text_AUG_17_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Sv. Hyacinta z Polska, knìze",
 "hu_",
 };
const char *text_AUG_18_SJ[POCET_JAZYKOV + 1] = 
{"Bl. Alberta Hurtada Cruchagu, kòaza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_AUG_18_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Bl. Mannesa neboli Mamesa, knìze, bratra sv. Otce Dominika",
 "hu_",
 };
const char *text_AUG_19[POCET_JAZYKOV + 1] = 
{"Sv. Jána Eudes, kòaza",
 "Sv. Jana Eudese, knìze",
 "",
 "",
 "",
 "Sv. Jana Eudese, knìze",
 "Eudes Szent János áldozópap",
 };
const char *text_AUG_20[POCET_JAZYKOV + 1] = 
{"Sv. Bernarda, opáta a uèite¾a Cirkvi",
 "Sv. Bernarda, opata a uèitele církve",
 "",
 "",
 "",
 "Sv. Bernarda, opata a uèitele Církve",
 "",
 };
const char *text_AUG_21[POCET_JAZYKOV + 1] = 
{"Sv. Pia X., pápea",
 "Sv. Pia X., papee",
 "",
 "",
 "",
 "Sv. Pia X., papee",
 "Szent X. Piusz pápa",
 };
const char *text_AUG_22[POCET_JAZYKOV + 1] = 
{"Prebl. Panny Márie Krá¾ovnej",
 "Panny Marie Královny",
 "",
 "",
 "",
 "Panny Marie Královny",
 "Boldogságos Szûz Mária Királynõ",
 };
const char *text_AUG_23[POCET_JAZYKOV + 1] = 
{"Sv. Rueny Limskej, panny",
 "Sv. Rùeny z Limy, panny",
 "",
 "",
 "",
 "Sv. Rùeny Floresové neboli z Limy, panny, terciáøky",
 "Limai Szent Róza szûz",
 };
const char *text_AUG_24[POCET_JAZYKOV + 1] = 
{"Sv. Bartolomeja, apoštola",
 "Sv. Bartolomìje, apoštola",
 "",
 "",
 "",
 "Sv. Bartolomìje, apoštola",
 "Szent Bertalan apostol",
 };
const char *text_AUG_25_1[POCET_JAZYKOV + 1] = 
{"Sv. Jozefa de Calasanz, kòaza",
 "Sv. Josefa Kalasanského, knìze",
 "",
 "",
 "",
 "Sv. Josefa Kalasanského, knìze",
 "Kalazanci Szent József áldozópap",
 };
const char *text_AUG_25_2[POCET_JAZYKOV + 1] = 
{"Sv. ¼udovíta",
 "Sv. Ludvíka",
 "",
 "",
 "",
 "Sv. Ludvíka",
 "Szent Lajos",
 };
const char *text_AUG_25_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Sv. Benedikta, Jana, Matouše, Izáka a Kristina, muèedníkù",
 "",
 "",
 "",
 "Sv. Benedikta, Jana, Matouše, Izáka a Kristina, muèedníkù",
 "(nincs Magyarországon)",
 };
const char *text_AUG_26_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Zefirína Namuncurá, mladíka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_AUG_27[POCET_JAZYKOV + 1] = 
{"Sv. Moniky",
 "Sv. Moniky",
 "",
 "",
 "",
 "Sv. Moniky",
 "Szent Mónika",
 };
const char *text_AUG_28[POCET_JAZYKOV + 1] = 
{"Sv. Augustína, biskupa a uèite¾a Cirkvi",
 "Sv. Augustina, biskupa a uèitele církve",
 "",
 "",
 "",
 "Sv. Augustina, biskupa a uèitele Církve",
 "Szent Ágoston püspök és egyháztanító",
 };
const char *text_AUG_29[POCET_JAZYKOV + 1] = 
{"Muèenícka smr sv. Jána Krstite¾a",
 "Umuèení svatého Jana Køtitele",
 "",
 "",
 "",
 "Umuèení svatého Jana Køtitele",
 "Keresztelõ Szent János vértanúsága",
 };
const char *text_AUG_30_SK[POCET_JAZYKOV + 1] = 
{"Vıroèie posviacky katedrálneho chrámu v Trnave",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "(nincs Magyarországon)",
 };

/* --------------- 09 september --------------- */

const char *text_SEP_03[POCET_JAZYKOV + 1] = 
{"Sv. Gregora Ve¾kého, pápea a uèite¾a Cirkvi",
 "Sv. Øehoøe Velikého, papee a uèitele církve",
 "",
 "",
 "",
 "Sv. Øehoøe Velikého, papee a uèitele Církve",
 "Nagy Szent Gergely pápa és egyháztanító",
 };
const char *text_SEP_06_SK[POCET_JAZYKOV + 1] = 
{"Vıroèie posviacky katedrálneho chrámu v Košiciach",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "(nincs Magyarországon)",
 };
const char *text_SEP_07[POCET_JAZYKOV + 1] = 
{"Sv. Marka Kriina, Melichara Grodzieckého a Štefana Pongrácza, kòazov a muèeníkov",
 "Sv. Melichara Grodeckého, knìze a muèedníka",
 "",
 "",
 "",
 "Sv. Melichara Grodeckého, knìze a muèedníka",
 "(nincs Magyarországon)",
 };
const char *text_SEP_07_SJ[POCET_JAZYKOV + 1] = 
{"Sv. košickıch muèeníkov: Štefana Pongrácza a Melichara Grodzieckého, kòazov Spoloènosti Jeišovej; <br>Marka Kriina, ostrihomského kanonika, patrónov Slovenskej provincie Spoloènosti Jeišovej",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_08[POCET_JAZYKOV + 1] = 
{"Narodenie prebl. Panny Márie",
 "Narození Panny Marie",
 "",
 "",
 "",
 "Narození Panny Marie",
 "Szûz Mária Születése (Kisboldogasszony)",
 };
const char *text_SEP_09[POCET_JAZYKOV + 1] = 
{"Sv. Petra Clavera, kòaza",
 "Sv. Petra Klavera, knìze",
 "",
 "",
 "",
 "Sv. Petra Klavera, knìze",
 "(nincs Magyarországon)",
 };
const char *text_SEP_09_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Petra Clavera, kòaza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_10_SJ[POCET_JAZYKOV + 1] = 
{"Bl. Františka Gárateho, reho¾níka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_10_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Bl. Karla Spinoly, knìze a muèedníka",
 "",
 "",
 "",
 "Bl. Karla Spinoly, knìze a muèedníka",
 "(nincs Magyarországon)",
 };
const char *text_SEP_12[POCET_JAZYKOV + 1] = 
{"Mena prebl. Panny Márie",
 "Jména Panny Marie",
 "",
 "",
 "",
 "Jména Panny Marie",
 "Szûz Mária Szent Neve",
 };
const char *text_SEP_13[POCET_JAZYKOV + 1] = 
{"Sv. Jána Zlatoústeho, biskupa a uèite¾a Cirkvi",
 "Sv. Jana Zlatoústého, biskupa a uèitele církve",
 "",
 "",
 "",
 "Sv. Jana Zlatoústého, biskupa a uèitele církve",
 "Aranyszájú (Krizosztomosz) Szent János püspök és egyháztanító",
 };
const char *text_SEP_14[POCET_JAZYKOV + 1] = 
{"Povıšenie svätého kría",
 "Povıšení svatého køíe",
 "",
 "",
 "",
 "Povıšení svatého køíe",
 "A Szent Kereszt felmagasztalása",
 };
const char *text_SEP_15[POCET_JAZYKOV + 1] = 
{"Sedembolestnej Panny Márie, patrónky Slovenska",
 "Panny Marie Bolestné",
 "",
 "",
 "",
 "Panny Marie Bolestné",
 "A Fájdalmas Szûzanya",
 };
const char *text_SEP_16_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Sv. Ludmily, muèednice",
 "",
 "",
 "",
 "Sv. Ludmily, muèednice",
 "(nincs Magyarországon)",
 };
const char *text_SEP_16[POCET_JAZYKOV + 1] = 
{"Sv. Kornélia, pápea, a sv. Cypriána, biskupa, muèeníkov",
 "Sv. Kornélia, papee, a Cypriána, biskupa, muèedníkù",
 "",
 "",
 "",
 "Sv. Kornélia, papee, a Cypriána, biskupa, muèedníkù",
 "Szent Kornél pápa és Szent Ciprián püspök és vértanúk",
 };
const char *text_SEP_17[POCET_JAZYKOV + 1] = 
{"Sv. Róberta Bellarmína, biskupa a uèite¾a Cirkvi",
 "Sv. Roberta Bellarmina, biskupa a uèitele církve",
 "",
 "",
 "",
 "Sv. Roberta Bellarmina, biskupa a uèitele Církve",
 "Bellarmin Szent Róbert püspök és egyháztanító",
 };
const char *text_SEP_17_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Róberta Bellarmina, biskupa a uèite¾a Cirkvi",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_18_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Sv. Jana Maciase, øeholníka",
 "hu_",
 };
const char *text_SEP_19[POCET_JAZYKOV + 1] = 
{"Sv. Januára, biskupa a muèeníka",
 "Sv. Januária, biskupa a muèedníka",
 "",
 "",
 "",
 "Sv. Januária, biskupa a muèedníka",
 "Szent Januáriusz püspök és vértanú",
 };
const char *text_SEP_20[POCET_JAZYKOV + 1] = 
{"Sv. Andreja Kim Taegona, kòaza, a sv. Pavla Chong Hasanga a spoloèníkov, muèeníkov",
 "Sv. Ondøeje Kim Taegona, knìze, Pavla Chong Hasanga a druhù, muèedníkù",
 "",
 "",
 "",
 "Sv. Ondøeje Kim Taegona, knìze, Pavla Chong Hasanga a druhù, muèedníkù",
 "Kim Taegon Szent András áldozópap, Csong Haszang Szent Pál és társaik, vértanúk",
 };
const char *text_SEP_20_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Vıroèí posvìcení katedrály sv. Štìpána",
 "",
 "",
 "",
 "Vıroèí posvìcení katedrály sv. Štìpána",
 "(nincs Magyarországon)",
 };
const char *text_SEP_21[POCET_JAZYKOV + 1] = 
{"Sv. Matúša, apoštola a evanjelistu",
 "Sv. Matouše, apoštola a evangelisty",
 "",
 "",
 "",
 "Sv. Matouše, apoštola a evangelisty",
 "Szent Máté apostol és evangelista",
 };
const char *text_SEP_22[POCET_JAZYKOV + 1] = 
{"Sv. Emeráma, biskupa a muèeníka",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "(nincs Magyarországon)",
 };
const char *text_SEP_22_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Jozefa Calasanza a Enrica Saiz Aparicio, kòazov, <br>a 93 spoloèníkov, muèeníkov",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_23[POCET_JAZYKOV + 1] = 
{"Sv. Pia z Pietrelèiny, kòaza",
 "Sv. Pia z Pietrelciny, knìze",
 "",
 "",
 "",
 "Sv. Pia z Pietrelciny, knìze",
 "(nincs Magyarországon)",
 };
const char *text_SEP_24_SK[POCET_JAZYKOV + 1] = 
{"Vıroèie posviacky katedrálneho chrámu v Banskej Bystrici",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "(nincs Magyarországon)",
 };
const char *text_SEP_26[POCET_JAZYKOV + 1] = 
{"Sv. Kozmu a Damiána, muèeníkov",
 "Sv. Kosmy a Damiána, muèedníkù",
 "",
 "",
 "",
 "Sv. Kosmy a Damiána, muèedníkù",
 "Szent Kozma és Damján vértanúk",
 };
const char *text_SEP_26_CSSR[POCET_JAZYKOV + 1] = 
{"Bl. Gašpara Stanggassingera, kòaza",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "hu_",
 };
const char *text_SEP_26_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Sv. Dominika Ibanìze z Erquicia, Jakuba Kyušei Tomonagy, knìí, <br>Vavøince Ruize, otce rodiny, a druhù, japonskıch muèedníkù",
 "hu_",
 };
const char *text_SEP_27[POCET_JAZYKOV + 1] = 
{"Sv. Vincenta de Paul, kòaza",
 "Sv. Vincence z Paula, knìze",
 "",
 "",
 "",
 "Sv. Vincence z Paula, knìze",
 "Páli Szent Vince áldozópap",
 };
const char *text_SEP_28[POCET_JAZYKOV + 1] = 
{"Sv. Václava, muèeníka",
 "Sv. Václava, muèedníka, hlavního patrona èeského národa",
 "",
 "",
 "",
 "Sv. Václava, muèedníka, hlavního patrona èeského národa, hlavního patrona provincie",
 "Szent Vencel vértanú",
 };
const char *text_SEP_28_2[POCET_JAZYKOV + 1] = 
{"Sv. Vavrinca Ruiza a spoloèníkov, muèeníkov",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není - 26.9.)",
 "(nincs Magyarországon)",
 };
const char *text_SEP_29[POCET_JAZYKOV + 1] = 
{"Sv. Michala, Gabriela a Rafaela, archanjelov",
 "Sv. Michaela, Gabriela a Rafaela, archandìlù",
 "",
 "",
 "",
 "Sv. Michaela, Gabriela a Rafaela, archandìlù",
 "Szent Mihály, Szent Gábor és Szent Rafael fõangyalok",
 };
const char *text_SEP_30[POCET_JAZYKOV + 1] = 
{"Sv. Hieronyma, kòaza a uèite¾a Cirkvi",
 "Sv. Jeronıma, knìze a uèitele církve",
 "",
 "",
 "",
 "Sv. Jeronıma, knìze a uèitele Církve",
 "Szent Jeromos áldozópap és egyháztanító",
 };

/* --------------- 10 október --------------- */

const char *text_OKT_01[POCET_JAZYKOV + 1] = 
{"Sv. Terézie z Lisieux, panny a uèite¾ky Cirkvi",
 "Sv. Terezie od Dítìte Jeíše, panny",
 "",
 "",
 "",
 "Sv. Terezie od Dítìte Jeíše, panny",
 "A Gyermek Jézusról nevezett (Lisieux-i) Szent Teréz Szûz",
 };
const char *text_OKT_02[POCET_JAZYKOV + 1] = 
{"Svätıch anjelov strácov",
 "Svatıch andìlù stránıch",
 "",
 "",
 "",
 "Svatıch andìlù stránıch",
 "Szent Õrzõangyalok",
 };
const char *text_OKT_03_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Františka de Borja, kòaza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_04[POCET_JAZYKOV + 1] = 
{"Sv. Františka Assiského",
 "Sv. Františka z Assisi",
 "",
 "",
 "",
 "Sv. Františka z Assisi, jáhna",
 "Assisi Szent Ferenc",
 };
const char *text_OKT_05_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Alberta Marvelliho",
 "",
 "",
 "la_",
 "",
 "",
 "hu_",
 };
const char *text_OKT_05_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Bl. Rajmunda delle Vigne neboli z Kapuy, knìze",
 "hu_",
 };
const char *text_OKT_06[POCET_JAZYKOV + 1] = 
{"Sv. Bruna, kòaza",
 "Sv. Bruna, knìze",
 "",
 "",
 "",
 "Sv. Bruna, knìze",
 "Szent Brúnó áldozópap",
 };
const char *text_OKT_06_SJ[POCET_JAZYKOV + 1] = 
{"Bl. Diega Alojza de san Vitores, kòaza a muèeníka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_07[POCET_JAZYKOV + 1] = 
{"Ruencovej prebl. Panny Márie",
 "Panny Marie Rùencové",
 "",
 "",
 "",
 "Panny Marie Rùencové",
 "Rózsafûzér Királynõje",
 };
const char *text_OKT_09_1[POCET_JAZYKOV + 1] = 
{"Sv. Dionızia, biskupa, a spoloèníkov, muèeníka",
 "Sv. Dionısia, biskupa, a druhù, muèedníkù",
 "",
 "",
 "",
 "Sv. Dionısia, biskupa, a druhù, muèedníkù",
 "Szent Dénes püspök és társai vértanúk",
 };
const char *text_OKT_09_2[POCET_JAZYKOV + 1] = 
{"Sv. Jána Leonardiho, kòaza",
 "Sv. Jana Leonardiho, knìze",
 "",
 "",
 "",
 "Sv. Jana Leonardiho, knìze",
 "Leonardi Szent János áldozópap",
 };
const char *text_OKT_09_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Sv. Ludvíka Bertrána, knìze",
 "hu_",
 };
const char *text_OKT_12_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Sv. Radima, biskupa",
 "",
 "",
 "",
 "Sv. Radima, biskupa",
 "(nincs Magyarországon)",
 };
const char *text_OKT_13_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Alexandry Márie da Costovej",
 "",
 "",
 "la_",
 "",
 "",
 "hu_",
 };
const char *text_OKT_14[POCET_JAZYKOV + 1] = 
{"Sv. Kalixta I., pápea a muèeníka",
 "Sv. Kalista I., papee a muèedníka",
 "",
 "",
 "",
 "Sv. Kalista I., papee a muèedníka",
 "Szent I. Kallixtusz pápa és vértanú",
 };
const char *text_OKT_14_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Jána Ogilvieho, kòaza a muèeníka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_15[POCET_JAZYKOV + 1] = 
{"Sv. Terézie z Avily, panny a uèite¾ky Cirkvi",
 "Sv. Terezie od Jeíše, panny a uèitelky církve",
 "",
 "",
 "",
 "Sv. Terezie od Jeíše, panny a uèitelky Církve",
 "A Jézusról nevezett (Avilai) Szent Teréz szûz és egyháztanító",
 };
const char *text_OKT_16_1[POCET_JAZYKOV + 1] = 
{"Sv. Margity Márie Alacoque, panny",
 "Sv. Markéty Marie Alacoque, panny",
 "",
 "",
 "",
 "Sv. Markéty Marie Alacoque, panny",
 "Alacoque Szent Margit Mária szûz",
 };
const char *text_OKT_16_2[POCET_JAZYKOV + 1] = 
{"Sv. Hedvigy, reho¾níèky",
 "Sv. Hedviky, øeholnice, hlavní patronky Slezska",
 "",
 "",
 "",
 "Sv. Hedviky, øeholnice, hlavní patronky Slezska",
 "Szent Hedvig szerzetesnõ",
 };
const char *text_OKT_16_CSSR[POCET_JAZYKOV + 1] = 
{"Sv. Gerarda Majellu, reho¾níka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_17[POCET_JAZYKOV + 1] = 
{"Sv. Ignáca Antiochijského, biskupa a muèeníka",
 "Sv. Ignáce Antiochijského, biskupa a muèedníka",
 "",
 "",
 "",
 "Sv. Ignáce Antiochijského, biskupa a muèedníka",
 "Antiochiai Szent Ignác püspök és vértanú",
 };
const char *text_OKT_18[POCET_JAZYKOV + 1] = 
{"Sv. Lukáša, evanjelistu",
 "Sv. Lukáše, evangelisty",
 "",
 "",
 "",
 "Sv. Lukáše, evangelisty",
 "Szent Lukács evangelista",
 };
const char *text_OKT_19_1[POCET_JAZYKOV + 1] = 
{"Sv. Jána de Brébeuf a sv. Izáka Jogues, kòazov, a spoloèníkov, muèeníkov",
 "Sv. Jana de Brébeuf a Izáka Joguese, knìí, a druhù, muèedníkù",
 "",
 "",
 "",
 "Sv. Jana de Brébeuf a Izáka Joguese, knìí, a druhù, muèedníkù",
 "De Brébeuf Szent János és Jogues Szent Izsák áldozópap és társaik vértanúk",
 };
const char *text_OKT_19_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Jána de Brébeuf, Izáka Joguesa, kòazov, a spoloèníkov, muèeníkov",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_19_2[POCET_JAZYKOV + 1] = 
{"Sv. Pavla z Kría, kòaza",
 "Sv. Pavla od Køíe, knìze",
 "",
 "",
 "",
 "Sv. Pavla od Køíe, knìze",
 "Keresztes Szent Pál áldozópap",
 };
const char *text_OKT_22_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Vıroèí posvìcení klášterního kostela",
 "hu_",
 };
const char *text_OKT_23[POCET_JAZYKOV + 1] = 
{"Sv. Jána Kapistránskeho, kòaza",
 "Sv. Jana Kapistránského, knìze",
 "",
 "",
 "",
 "Sv. Jana Kapistránského, knìze",
 "Kapisztrán Szent János áldozópap",
 };
const char *text_OKT_24[POCET_JAZYKOV + 1] = 
{"Sv. Antona Márie Clareta, biskupa",
 "Sv. Antonína Marie Klareta, biskupa",
 "",
 "",
 "",
 "Sv. Antonína Marie Klareta, biskupa",
 "Claret Szent Antal Mária püspök",
 };
const char *text_OKT_24_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Alojza Guanellu, kòaza",
 "",
 "",
 "la_",
 "",
 "",
 "hu_",
 };
const char *text_OKT_25_SK[POCET_JAZYKOV + 1] = 
{"Vıroèie posviacky katedrálneho chrámu v Spišskom Podhradí",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "(nincs Magyarországon)",
 };
const char *text_OKT_25_SDB[POCET_JAZYKOV + 1] = 
{"Vıroèie posviacky vlastného chrámu (keï sa nepozná dátum posviacky)",
 "",
 "",
 "la_",
 "",
 "",
 "hu_",
 };
const char *text_OKT_26[POCET_JAZYKOV + 1] = 
{"Vıroèie posviacky chrámov, ktorıch deò posviacky je neznámy",
 "Vıroèí posvìcení chrámu, jejich den dedikace není známı",
 "",
 "",
 "",
 "Vıroèí posvìcení chrámu, jejich den dedikace není známı",
 "hu_",
 };
const char *text_OKT_27_SK[POCET_JAZYKOV + 1] = 
{"Vıroèie posviacky katedrálneho chrámu v Roòave",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "(nincs Magyarországon)",
 };
const char *text_OKT_28[POCET_JAZYKOV + 1] = 
{"Sv. Šimona a Júdu, apoštolov",
 "Sv. Šimona a Judy, apoštolù",
 "",
 "",
 "",
 "Sv. Šimona a Judy, apoštolù",
 "Szent Simon és Szent Júdás apostol",
 };
const char *text_OKT_29_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Michala Ruu, kòaza",
 "",
 "",
 "la_",
 "",
 "",
 "hu_",
 };
const char *text_OKT_29_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Bl. Marie Restituty Kafkové, panny a muèednice",
 "",
 "",
 "",
 "Bl. Marie Restituty Kafkové, panny a muèednice",
 "(nincs Magyarországon)",
 };
const char *text_OKT_30_SJ[POCET_JAZYKOV + 1] = 
{"Bl. Dominika Collinsa, muèeníka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_30_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Vıroèí posvìcení katedrály Svatého Ducha",
 "",
 "",
 "",
 "Vıroèí posvìcení katedrály Svatého Ducha",
 "(nincs Magyarországon)",
 };
const char *text_OKT_31_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Alfonza Rodrígueza, reho¾níka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_31_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Sv. Wolfganga, biskupa",
 "",
 "",
 "",
 "Sv. Wolfganga, biskupa",
 "(nincs Magyarországon)",
 };

/* --------------- 11 november --------------- */

const char *text_NOV_01[POCET_JAZYKOV + 1] = 
{"Všetkıch svätıch",
 "Všech svatıch",
 "",
 "",
 "",
 "Všech svatıch",
 "Mindenszentek",
 };
const char *text_NOV_02[POCET_JAZYKOV + 1] = 
{"Všetkıch vernıch zosnulıch",
 "Vzpomínka na všechny vìrné zemøelé",
 "",
 "",
 "",
 "Vzpomínka na všechny vìrné zemøelé",
 "Halottak napja",
 };
const char *text_NOV_03[POCET_JAZYKOV + 1] = 
{"Sv. Martina de Porres, reho¾níka",
 "Sv. Martina de Porres, øeholníka",
 "",
 "",
 "",
 "Sv. Martina de Porres, øeholníka",
 "Porres Szent Márton szerzetes",
 };
const char *text_NOV_03_SJ[POCET_JAZYKOV + 1] = 
{"Bl. Ruperta Mayera, kòaza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_04[POCET_JAZYKOV + 1] = 
{"Sv. Karola Borromea, biskupa",
 "Sv. Karla Boromejského, biskupa",
 "",
 "",
 "",
 "Sv. Karla Boromejského, biskupa",
 "Borromeo Szent Károly püspök",
 };
const char *text_NOV_05_SK[POCET_JAZYKOV + 1] = 
{"Sv. Imricha",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "Szent Imre herceg",
 };
const char *text_NOV_05_SJ[POCET_JAZYKOV + 1] = 
{"Všetkıch svätıch a blahoslavenıch zo Spoloènosti Jeišovej",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_06_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Sv. Alfonse Navarrety, knìze a druhù, japonskıch muèedníkù",
 "hu_",
 };
const char *text_NOV_07_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Všech svatıch Øádu bratøí kazatelù",
 "hu_",
 };
const char *text_NOV_08_CZOP[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "(v Èechách, na Moravì a ve Slezsku není)",
 "",
 "la_",
 "",
 "Všech zemøelıch bratøí a sester Øádu bratøí kazatelù",
 "hu_",
 };
const char *text_NOV_09[POCET_JAZYKOV + 1] = 
{"Vıroèie posviacky Lateránskej baziliky",
 "Posvìcení lateránské baziliky",
 "",
 "",
 "",
 "Posvìcení lateránské baziliky",
 "A lateráni-bazilika felszentelése",
 };
const char *text_NOV_10[POCET_JAZYKOV + 1] = 
{"Sv. Leva Ve¾kého, pápea a uèite¾a Cirkvi",
 "Sv. Lva Velikého, papee a uèitele církve",
 "",
 "",
 "",
 "Sv. Lva Velikého, papee a uèitele církve",
 "Nagy Szent Leó pápa és egyháztanító",
 };
const char *text_NOV_11[POCET_JAZYKOV + 1] = 
{"Sv. Martina z Tours, biskupa",
 "Sv. Martina, biskupa",
 "",
 "",
 "",
 "Sv. Martina, biskupa",
 "Tours-i Szent Márton püspök",
 };
const char *text_NOV_12[POCET_JAZYKOV + 1] = 
{"Sv. Jozafáta, biskupa a muèeníka",
 "Sv. Josafata, biskupa a muèedníka",
 "",
 "",
 "",
 "Sv. Josafata, biskupa a muèedníka",
 "Szent Jozafát püspök és vértanú",
 };
const char *text_NOV_13_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Artemida Zattiho",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_13_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Stanislava Kostku, reho¾níka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_13_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Sv. Aneky Èeské, panny",
 "",
 "",
 "",
 "Sv. Aneky Èeské, panny",
 "(nincs Magyarországon)",
 };
const char *text_NOV_14_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Jozefa Pignatelliho, kòaza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_15[POCET_JAZYKOV + 1] = 
{"Sv. Alberta Ve¾kého, biskupa a uèite¾a Cirkvi",
 "Sv. Alberta Velikého, biskupa a uèitele církve",
 "",
 "",
 "",
 "Sv. Alberta Velikého, biskupa a uèitele Církve",
 "Nagy Szent Albert püspök és egyháztanító",
 };
const char *text_NOV_15_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Magdalény Moranovej, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_16_1[POCET_JAZYKOV + 1] = 
{"Sv. Margity Škótskej",
 "Sv. Markéty Skotské",
 "",
 "",
 "",
 "Sv. Markéty Skotské",
 "Skóciai Szent Margit",
 };
const char *text_NOV_16_2[POCET_JAZYKOV + 1] = 
{"Sv. Gertrúdy, panny",
 "Sv. Gertrudy, panny",
 "",
 "",
 "",
 "Sv. Gertrudy, panny",
 "(nincs Magyarországon)",
 };
const char *text_NOV_16_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Rocha Gonzáleza, Alfonza Rodrígueza a Jána del Castillo, kòazov a muèeníkov",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_17[POCET_JAZYKOV + 1] = 
{"Sv. Albety Uhorskej, reho¾níèky",
 "Sv. Albìty Uherské, øeholnice",
 "",
 "",
 "",
 "Sv. Albìty Uherské, øeholnice",
 "hu_",
 };
const char *text_NOV_18[POCET_JAZYKOV + 1] = 
{"Vıroèie posviacky bazilík sv. Petra a sv. Pavla, apoštolov",
 "Posvìcení øímskıch bazilik svatıch apoštolù Petra a Pavla",
 "",
 "",
 "",
 "Posvìcení øímskıch bazilik svatıch apoštolù Petra a Pavla",
 "Szent Péter- és Szent Pál-Bazilikák felszentelése",
 };
const char *text_NOV_20_SK[POCET_JAZYKOV + 1] = 
{"Vıroèie posviacky katedrálneho chrámu v Nitre",
 "(v Èechách, na Moravì a na Slezsku není)",
 "",
 "",
 "",
 "(pro dominikány není)",
 "(nincs Magyarországon)",
 };
const char *text_NOV_21[POCET_JAZYKOV + 1] = 
{"Obetovanie prebl. Panny Márie",
 "Zasvìcení Panny Marie v Jeruzalémì",
 "",
 "",
 "",
 "Zasvìcení Panny Marie v Jeruzalémì",
 "A Boldogságos Szûz Mária bemutatása a templomban",
 };
const char *text_NOV_22[POCET_JAZYKOV + 1] = 
{"Sv. Cecílie, panny a muèenice",
 "Sv. Cecilie, panny a muèednice",
 "",
 "",
 "",
 "Sv. Cecilie, panny a muèednice",
 "Szent Cecília szûz és vértanú",
 };
const char *text_NOV_23_1[POCET_JAZYKOV + 1] = 
{"Sv. Klementa I. pápea a muèeníka",
 "Sv. Klementa I., papee a muèedníka",
 "",
 "",
 "",
 "Sv. Klementa I., papee a muèedníka",
 "Szent I. Kelemen pápa és vértanú",
 };
const char *text_NOV_23_2[POCET_JAZYKOV + 1] = 
{"Sv. Kolumbána, opáta",
 "Sv. Kolumbána, opata",
 "",
 "",
 "",
 "Sv. Kolumbána, opata",
 "Szent Kolumbán apát",
 };
const char *text_NOV_23_SJ[POCET_JAZYKOV + 1] = 
{"Bl. Michala Augustína Pro, kòaza a muèeníka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_24[POCET_JAZYKOV + 1] = 
{"Sv. Ondreja Dung-Laca a spoloèníkov, muèeníkov",
 "Sv. Ondøeje Dung-Laca, knìze, a druhù, muèedníkù",
 "",
 "",
 "",
 "Sv. Ignáce Delgada, biskupa, Vincence Liema, knìze, <br>Dominika An-Khama, otce rodiny, a druhù, vietnamskıch muèedníkù",
 "Dung-Lac Szent András áldozópap és társai vértanúk",
 };
const char *text_NOV_25[POCET_JAZYKOV + 1] = 
{"Sv. Kataríny Alexandrijskej, panny a muèenice",
 "Sv. Kateøiny Alexandrijské, panny a muèednice",
 "",
 "",
 "",
 "Sv. Kateøiny Alexandrijské, panny a muèednice",
 "(nincs Magyarországon)",
 };
const char *text_NOV_26_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Jána Berchmansa, reho¾níka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_30[POCET_JAZYKOV + 1] = 
{"Sv. Ondreja, apoštola",
 "Sv. Ondøeje, apoštola",
 "",
 "",
 "",
 "Sv. Ondøeje, apoštola",
 "Szent András apostol",
 };

/* --------------- 12 december --------------- */

const char *text_DEC_01_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Edmunda Campiona, Róberta Southwella a ich spoloèníkov, muèeníkov",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_DEC_01_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Sv. Edmunda Kampiána, knìze a muèedníka",
 "",
 "",
 "",
 "Sv. Edmunda Kampiána, knìze a muèedníka",
 "(nincs Magyarországon)",
 };
const char *text_DEC_02_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Vıroèí posvìcení katedrály sv. Bartolomìje",
 "",
 "",
 "",
 "Vıroèí posvìcení katedrály sv. Bartolomìje",
 "(nincs Magyarországon)",
 };
const char *text_DEC_03[POCET_JAZYKOV + 1] = 
{"Sv. Františka Xaverského, kòaza",
 "Sv. Františka Xaverského, knìze",
 "",
 "",
 "",
 "Sv. Františka Xaverského, knìze",
 "Xavéri Szent Ferenc áldozópap",
 };
const char *text_DEC_03_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Františka Xavérskeho, misionára",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_DEC_04[POCET_JAZYKOV + 1] = 
{"Sv. Jána Damascénskeho, kòaza a uèite¾a Cirkvi",
 "Sv. Jana Damašského, knìze a uèitele církve",
 "",
 "",
 "",
 "Sv. Jana Damašského, knìze a uèitele Církve",
 "Damaszkuszi Szent János áldozópap és egyháztanító",
 };
const char *text_DEC_05_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Filipa Rinaldiho, kòaza, <br>zakladate¾a Sekulárneho inštitútu dobrovo¾níèok dona Bosca",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_DEC_06[POCET_JAZYKOV + 1] = 
{"Sv. Mikuláša, biskupa",
 "Sv. Mikuláše, biskupa",
 "",
 "",
 "",
 "Sv. Mikuláše, biskupa",
 "Szent Miklós püspök",
 };
const char *text_DEC_07[POCET_JAZYKOV + 1] = 
{"Sv. Ambróza, biskupa a uèite¾a Cirkvi",
 "Sv. Ambroe, biskupa a uèitele církve",
 "",
 "",
 "",
 "Sv. Ambroe, biskupa a uèitele Církve",
 "Szent Ambrus püspök és egháztanító",
 };
const char *text_DEC_08[POCET_JAZYKOV + 1] = 
{"Nepoškvrnené poèatie Panny Márie",
 "Panny Marie, poèaté bez poskvrny prvotního høíchu",
 "",
 "",
 "",
 "Neposkvrnìného poèetí Panny Marie",
 "A Boldogságos Szûz Mária szeplõtelen fogantatása",
 };
const char *text_DEC_09[POCET_JAZYKOV + 1] = 
{"Sv. Jána Didaka Cuauhtlatoatzina",
 "Sv. Jana Didaka Cuauhtlatoatzina",
 "",
 "",
 "",
 "Sv. Jana Didaka Cuauhtlatoatzina",
 "hu_",
 };
const char *text_DEC_11[POCET_JAZYKOV + 1] = 
{"Sv. Damaza I., pápea",
 "Sv. Damasa I., papee",
 "",
 "",
 "",
 "Sv. Damasa I., papee",
 "Szent I. Damazusz pápa",
 };
const char *text_DEC_12[POCET_JAZYKOV + 1] = 
{"Prebl. Panny Márie Guadalupskej",
 "Panny Marie Guadalupské",
 "",
 "",
 "",
 "Panny Marie Guadalupské",
 "hu_",
 };
const char *text_DEC_13[POCET_JAZYKOV + 1] = 
{"Sv. Lucie, panny a muèenice",
 "Sv. Lucie, panny a muèednice",
 "",
 "",
 "",
 "Sv. Lucie, panny a muèednice",
 "Szent Lúcia szûz és vértanú",
 };
const char *text_DEC_14[POCET_JAZYKOV + 1] = 
{"Sv. Jána z Kría, kòaza a uèite¾a Cirkvi",
 "Sv. Jana od Køíe, knìze a uèitele církve",
 "",
 "",
 "",
 "Sv. Jana od Køíe, knìze a uèitele Církve",
 "Keresztes Szent János áldozópap és egyháztanító",
 };
const char *text_DEC_21[POCET_JAZYKOV + 1] = 
{"Sv. Petra Kanízia, kòaza a uèite¾a Cirkvi",
 "Sv. Petra Kanisia, knìze a uèitele církve",
 "",
 "",
 "",
 "Sv. Petra Kanisia, knìze a uèitele Církve",
 "Kaníziusz Szent Péter áldozópap és egyháztaíntó",
 };
const char *text_DEC_22_CZ[POCET_JAZYKOV + 1] = 
{"(na Slovensku nie je)",
 "Vıroèí posvìcení katedrály Sv. Mikuláše",
 "",
 "",
 "",
 "Vıroèí posvìcení katedrály Sv. Mikuláše",
 "(nincs Magyarországon)",
 };
const char *text_DEC_23[POCET_JAZYKOV + 1] = 
{"Sv. Jána Kentského, kòaza",
 "Sv. Jana Kentského, knìze",
 "",
 "",
 "",
 "Sv. Jana Kentského, knìze",
 "Kety Szent János áldozópap",
 };
const char *text_DEC_26[POCET_JAZYKOV + 1] = 
{"Sv. Štefana, prvého muèeníka",
 "Sv. Štìpána, prvomuèedníka",
 "",
 "",
 "",
 "Sv. Štìpána, prvomuèedníka",
 "Szent István elsõ vértanú",
 };
const char *text_DEC_27[POCET_JAZYKOV + 1] = 
{"Sv. Jána, apoštola a evanjelistu",
 "Sv. Jana, apoštola a evangelisty",
 "",
 "",
 "",
 "Sv. Jana, apoštola a evangelisty",
 "Szent János apostol és evangelista",
 };
const char *text_DEC_28[POCET_JAZYKOV + 1] = 
{"Svätıch Neviniatok, muèeníkov",
 "Svatıch Mláïátek, muèedníkù",
 "",
 "",
 "",
 "Svatıch Mláïátek, muèedníkù",
 "hu_",
 };
const char *text_DEC_29[POCET_JAZYKOV + 1] = 
{"Sv. Tomáša Becketa, biskupa a muèeníka",
 "Sv. Tomáše Becketa, biskupa a muèedníka",
 "",
 "",
 "",
 "Sv. Tomáše Becketa, biskupa a muèedníka",
 "Becket Szent Tamás püspök és vértanú",
 };
const char *text_DEC_31[POCET_JAZYKOV + 1] = 
{"Sv. Silvestra I., pápea",
 "Sv. Silvestra I., papee",
 "",
 "",
 "",
 "Sv. Silvestra I., papee",
 "Szent I. Szilveszter pápa",
 };

/* --------------- 00 pohyblivé slávenia --------------- */

const char *text_ZELENY_STVRTOK[POCET_JAZYKOV + 1] = 
{"Zelenı (ve¾kı) štvrtok - Pamiatka Pánovej veèere",
 "Zelenı ètvrtek - Památka Veèeøe Pánì",
 "",
 "",
 "",
 "Zelenı ètvrtek - Památka Veèeøe Pánì",
 "Nagycsütörtök",
 };
const char *text_VELKY_PIATOK[POCET_JAZYKOV + 1] = 
{"Ve¾kı piatok",
 "Velkı pátek",
 "",
 "",
 "",
 "Velkı pátek",
 "Nagypéntek",
 };
const char *text_BIELA_SOBOTA[POCET_JAZYKOV + 1] = 
{"Biela (ve¾ká) sobota",
 "Bílá sobota",
 "",
 "",
 "",
 "Bílá sobota",
 "Nagyszombat",
 };
const char *text_KVETNA_NEDELA[POCET_JAZYKOV + 1] = 
{"Kvetná nede¾a",
 "Kvìtná nedìle",
 "",
 "",
 "",
 "Kvìtná nedìle",
 "Virágvasárnap, vagyis az Úr szenvedésének vasárnapja",
 };
const char *text_PO_POPOLCOVEJ_STREDE[POCET_JAZYKOV + 1] = 
{"po Popolcovej strede",
 "po Popeleèní støedì",
 "",
 "",
 "",
 "po Popeleèní støedì",
 "hu_name",
 };
const char *text_V_OKTAVE_NARODENIA[POCET_JAZYKOV + 1] = 
{"v oktáve Narodenia Pána",
 "v oktávu Narození Pánì",
 "",
 "",
 "",
 "v oktávu Narození Pánì",
 "hu_name",
 };

#endif /* __HODIN_H */
