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
/*   2005-07-27a.D. | pridan� nazov_slavenia_lokal[]           */
/*   2005-08-05a.D. | pridan� zvazok_OBD[]                     */
/*   2006-07-11a.D. | prv� kroky k jazykov�m mut�ci�m          */
/*   2006-08-01a.D. | zmenen� defin�cie kon�t�nt (jaz.mut�cie) */
/*   2006-08-07a.D. | pridan� sv. mu�ov/�ien, �o �ili v man�.  */
/*   2006-08-18a.D. | zmena int na short int (sta�� 32tis.)    */
/*   2006-08-19a.D. | pridanie liturgickej farby               */
/*   2006-09-07a.D. | dokon�en� lokaliz�cia mesiacov JAN-AUG   */
/*   2006-09-12a.D. | dokon�en� lokaliz�cia mesiaca SEP+opravy */
/*   2006-09-13a.D. | dokon�en� lokaliz�cia mesiacov OKT+NOV   */
/*   2006-12-04a.D. | oprava: komplet��                        */
/*   2006-12-12a.D. | doplnenie latin�iny (la)                 */
/*   2008-01-03a.D. | doplnen� text_DRUHA_NEDELA_PO_NAR_PANA[] */
/*   2008-01-05a.D. | doplnen� text_PO_POPOLCOVEJ_STREDE[]     */
/*                  - a tie� text_V_OKTAVE_NARODENIA[]         */
/*   2008-07-18a.D. | pridan� sviatok (text_JUL_24)            */
/*   2008-08-15a.D. | pridan� �al�� "jazyk" (cz-op)            */
/*   2009-01-29a.D. | pridan� �al�� jazyk - ma�ar�ina (hu)     */
/*   2009-02-01a.D. | hungarian translation added by L�szl�    */
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

/* 2008-04-09: doplnen� pre batch generovanie modlitieb */
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
{{"invitat�rium", "invitato�", "Invitatory", "invitatorium", "", "Pozv�n� k modlitb�", "im�ds�gra h�v�s" }
, {"rann� chv�ly", "rann� chv�ly", "Laudes", "laudes matutinae", "", "Rann� chv�ly", "reggeli dics�ret" }
, {"posv�tn� ��tanie", "modlitba se �ten�m", "Office of Readings", "officium lectionis", "", "Modlitba se �ten�m", "olvasm�nyos ima�ra" }
, {"modlitba predpoludn�m", "modlitba dopoledne", "Terce", "tertia", "", "Tercie", "tertia" }
, {"modlitba napoludnie", "modlitba v poledne", "Sext", "sexta", "", "Sexta", "sexta" }
, {"modlitba popoludn�", "modlitba odpoledne", "None", "nona", "", "Nona", "nona" }
, {"ve�pery", "ne�pory", "Vesperae", "vesper&#230;", "", "Ve�ern� chv�ly", "esti dics�ret" }
, {"komplet�rium", "komplet��", "Completary", "completorio", "", "Komplet��", "befejez� ima�ra" }
, {"neur�en�", "neur�ena", "not-defined", "no data", "", "neur�ena", "nem azonos�tott"}
, {"prv� ve�pery", "prvn� ne�pory", "1st Vesperae", "I vesper&#230;", "", "Prvn� ve�ern� chv�ly", "I. esti dics�ret" }
	/* 2007-12-05: zmenen�, kedysi bolo: "prv� komplet�rium" */
, {"komplet�rium po prv�ch ve�per�ch", "komplet�� po prvn�ch ne�por�ch", "1st Completary", "I completorio", "", "Komplet�� po prvn�ch ve�ern�ch chv�l�ch", "I. esti dics�ret ut�n" }
, {"druh� ve�pery", "druh� ne�pory", "2nd Vesperae", "II vesper&#230;", "", "Druh� ve�ern� chv�ly", "II. esti dics�ret" }
	/* 2007-12-05: zmenen�, kedysi bolo: "druh� komplet�rium" */
, {"komplet�rium po druh�ch ve�per�ch", "komplet�� po druh�ch ne�porech", "2nd Completary", "II completorio", "", "Komplet�� po druh�ch ve�ern�ch chv�l�ch", "II. esti dics�ret ut�n" }
, {"detaily", "detaily", "Details", "details", "", "detaily", "r�szletek" }
};

#define		nazov_modlitby(a)	nazov_modlitby_jazyk[a][_global_jazyk]

/* the names of the prayers, sentence case (Sample text) */
const char *nazov_Modlitby_jazyk[POCET_MODLITIEB + 1][POCET_JAZYKOV + 1] = 
{{"Invitat�rium", "Invitato�", "Invitatory", "Invitatorium", "", "Pozv�n� k modlitb�" , "Im�ds�gra h�v�s" }
, {"Rann� chv�ly", "Rann� chv�ly", "Laudes", "Laudes matutinae", "", "Rann� chv�ly" , "Reggeli dics�ret" }
, {"Posv�tn� ��tanie", "Modlitba se �ten�m", "Office of Readings", "Officium lectionis", "", "Modlitba se �ten�m" , "Olvasm�nyos ima�ra" }
, {"Modlitba predpoludn�m", "Modlitba dopoledne", "Terce", "Tertia", "", "Tercie" , "Tertia" }
, {"Modlitba napoludnie", "Modlitba v poledne", "Sext", "Sexta", "", "Sexta" , "Sexta" }
, {"Modlitba popoludn�", "Modlitba odpoledne", "None", "Nona", "", "Nona" , "Nona" }
, {"Ve�pery", "Ne�pory", "Vesperae", "Vesper&#230;", "", "Ve�ern� chv�ly" , "Esti dics�ret" }
, {"Komplet�rium", "Komplet��", "Completary", "Completorio", "", "Komplet��" , "Befejez� ima�ra" }
, {"Neureen�", "Neureena", "not-defined", "No data", "", "Neur�en�" , "Nem azonos�tott"}
, {"Prv� ve�pery", "Prvn� ne�pory", "1st Vesperae", "I Vesper&#230;", "", "Prvn� ve�ern� chv�ly" , "I. Esti dics�ret" }
, {"Komplet�rium po prv�ch ve�per�ch", "Komplet�� po prvn�ch ne�por�ch", "1st Completary", "I Completorio", "", "Komplet�� po prvn�ch ve�ern�ch chv�l�ch" , "I. Esti dics�ret ut�n" }
, {"Druh� ve�pery", "Druh� ne�pory", "2nd Vesperae", "II Vesper&#230;", "", "Druh� ve�ern� chv�ly" , "II. Esti dics�ret" }
, {"Komplet�rium po druh�ch ve�per�ch", "Komplet�� po druh�ch ne�porech", "2nd Completary", "II Completorio", "", "Komplet�� po druh�ch ve�ern�ch chv�l�ch" , "II. Esti dics�ret ut�n" }
, {"Detaily", "Detaily", "Details", "Details", "", "Detaily", "R�szletek" }
};

#define		nazov_Modlitby(a)	nazov_Modlitby_jazyk[a][_global_jazyk]

/* the names of the common texts (e.g.: for bishops, for saint men, for apostles...) */
const char *nazov_spolc_jazyk[POCET_SPOL_CASTI + 1][POCET_JAZYKOV + 1] =
{{"neur�en�", "neur�ena", "not decided", "", "", "", ""}, 
 {"duchovn�ch pastierov - pre k�azov", "duchovn�ch past��� - o kn��ch", "", "", "", "O duchovn�ch past���ch - o kn��ch", "lelkip�sztorok - papok"}, 
 {"duchovn�ch pastierov - pre biskupov", "duchovn�ch past��� - o biskupech", "", "", "", "O duchovn�ch past���ch - o biskupech", "lelkip�sztorok - p�sp�k�k"}, 
 {"duchovn�ch pastierov - pre p�pe�ov", "duchovn�ch past��� - o pape�i", "", "", "", "O duchovn�ch past���ch - o pape�i", "p�sztorok - p�pa"}, 
 {"u�ite�ov Cirkvi", "u�itel� c�rkve", "", "", "", "O u�itel�ch C�rkve", "egyh�ztan�t�k"}, 
 {"apo�tolov", "apo�tol�", "", "", "", "O apo�tolech", "apostolok"}, 
 {"jedn�ho mu�en�ka", "jednoho mu�edn�ka", "", "", "", "O mu�edn�kovi", "v�rtan�"}, 
 {"viacer�ch mu�en�kov", "v�ce mu�edn�k�", "", "", "", "O v�ce mu�edn�c�ch", "v�rtan�k"}, 
 {"Panny M�rie", "Panny Marie", "", "", "", "Panny Marie", "Sz�z M�ria"}, 
 {"sv�t�ch mu�ov - pre reho�n�kov", "svat�ch mu�� - o �eholn�c�ch", "", "", "", "O �eholn�c�ch", "szerzetes"}, 
 {"sv�t�ch mu�ov", "svat�ch mu��", "", "", "","O svat�ch mu��ch", "szent f�rfiak"}, 
 {"panien", "panen", "", "", "","O pann�ch", "sz�z"}, 
 {"sv�t�ch �ien - pre reho�nice", "svat�ch �en - o �eholnic�ch", "", "", "", "O svat�ch �en�ch - o �eholnic�ch", "ap�ca"}, 
 {"sv�t�ch �ien", "svat�ch �en", "", "", "", "O svat�ch �en�ch", "szent asszonyok"}, 
 {"duchovn�ch pastierov - pre viacer�ch", "duchvn�ch past��� - o v�ce past���ch", "", "", "", "O duchovn�ch past���ch", "t�bb lelkip�sztor"}, 
 {"jednej mu�enice", "jedn� mu�ednice", "", "", "", "O mu�ednici", "v�rtan�"}, 
 {"sv�t�ch �ien - pre vychov�vate�ky", "svat�ch �en - o vychovatelce", "", "", "", "O svat�ch �en�ch - o vychovatelk�ch", "egyh�ztan�t� f�rfiak"}, 
 {"sv�t�ch mu�ov - pre vychov�vate�ov", "svat�ch mu�� - o vychovatel�ch", "", "", "", "O svat�ch mu��ch - o vychovatel�ch", "egyh�ztan�t� asszonyok"}, 
 {"sv�t�ch �ien - pre tie, �o konali skutky milosrdenstva", "svat�ch �en - o �en�, kter� vynikala milosrdn�mi skutky", "", "", "", "O svat�ch �en�ch - o �en�, kter� vynikala milosrdn�mi skutky", "j�t�konykod� asszonyok"}, 
 {"sv�t�ch mu�ov - pre t�ch, �o konali skutky milosrdenstva", "svat�ch mu�� - o mu�i, kter� vynikal milosrdn�mi skutky", "", "", "", "O svat�ch mu��ch - o mu�i, kter� vynikal milosrdn�mi skutky", "j�t�konykod� f�rfiak"}, 
 {"sv�t�ch �ien - pre viacer�", "svat�ch �en - o v�ce �en�ch", "", "", "", "O svat�ch �en�ch", "t�bb szent asszony"}, 
 {"sv�t�ch mu�ov - pre viacer�ch", "svat�ch mu�� - o v�ce mu��ch", "", "", "", "O svat�ch mu��ch", "t�bb szent f�rfi"}, 
 {"viacer�ch panien", "v�ce pannen", "", "", "","O pann�ch", "sz�zek"}, 
 {"posviacky chr�mu", "posv�cen� kostela", "", "", "", "Posv�cen� kostela", "templomszentel�s"}, 
 {"zosnul�ch", "zem�el�ch", "", "", "","Za zem�el�", "halottak�rt"}, 
 {"sv�t�ch �ien - pre tie, �o �ili v man�elstve", "svat�ch �en - o �en�, kter� �ila v man�elstv�", "", "", "", "O svat�ch �en�ch - o �en�, kter� �ila v man�elstv�", "h�zas szent asszonyok"}, 
 {"sv�t�ch mu�ov - pre t�ch, �o �ili v man�elstve", "svat�ch mu�� - o mu�i, kter� �il v man�elstv�", "", "", "", "O svat�ch mu��ch - o mu�i, kter� �il v man�elstv�", "h�zas szent f�rfiak"}, 
 {"nebra�", "nevz�t", "do not use", "", "", "nevz�t", "mindent saj�tb�l"}
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
{{"ve�kono�n� okt�va", "velikono�n� okt�v", "", "octava paschae", "", "velikono�n� okt�v", "h�sv�t nyolcada"},
 {"adventn� obdobie", "doba adventn�", "", "tempus adventus", "", "doba adventn�", "adventi id�"},
 {"adventn� obdobie", "doba adventn�", "", "tempus adventus", "", "doba adventn�", "adventi id�"},
 {"viano�n� obdobie", "doba v�no�n�", "", "tempus nativitatis", "", "doba v�no�n�", "kar�csonyi id�"},
 {"viano�n� obdobie", "doba v�no�n�", "", "tempus nativitatis", "", "doba v�no�n�", "kar�csonyi id�"},
 	// obdobie �cez rok�
 {"cezro�n� obdobie", "mezidob�", "", "tempus per annum", "", "mezidob�", "�vk�zi id�"},
 {"p�stne obdobie", "doba postn�", "", "tempus quadragesimae", "", "doba postn�", "nagyb�jti id�"},
 {"Ve�k� t��de�", "Svat� t�den", "", "hebdomada sancta", "", "Svat� t�den", "nagyh�t"},
 {"ve�kono�n� trojdnie", "Velikono�n� triduum", "", "sacrum triduum paschale", "", "Velikono�n� triduum", "szent h�rom nap"},
 {"ve�kono�n� obdobie", "doba velikono�n�", "", "tempus paschale", "", "doba velikono�n�", "h�sv�ti id�"},
 {"ve�kono�n� obdobie", "doba velikono�n�", "", "tempus paschale", "", "doba velikono�n�", "h�sv�ti id�"},
 {"okt�va Narodenia P�na", "okt�v Narozen� P�n�", "", "octava nativitatis", "", "okt�v Narozen� P�n�", "kar�csony nyolcada"}
};

#define		nazov_obdobia(a)	nazov_obdobia_jazyk[a][_global_jazyk]

/* the names of liturgical periods for debugging, only in Slovak; no need to translate */
const char *nazov_obdobia_[] = // debuggovacie - preto netreba preklada�; 2006-08-03
{"ve�kono�n� okt�va", "adventn� obdobie I", "adventn� obdobie II",
 "viano�n� obdobie I", "viano�n� obdobie II", "cezro�n� obdobie", // obdobie �cez rok�
 "p�stne obdobie I", "Ve�k� t��de�",
 "ve�kono�n� trojdnie", "ve�kono�n� obdobie I", "ve�kono�n� obdobie II",
 "okt�va Narodenia P�na"};

/* the names of liturgical periods in local grammatically 6.th declination? (usually lowecase); in English: "IN liturgical period" or "OF liturgical period" /  lokal == 6. pad, v kom/com */
const char *nazov_obdobia_v_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{{"vo ve�kono�nej okt�ve", "ve velikono�n�m okt�vu", "", "", "", "ve velikono�n�m okt�vu", "h�sv�t nyolcad�ban"},
 {"v adventnom obdob�", "v dob� adventn�", "", "", "", "v dob� adventn�", "adventben"},
 {"v adventnom obdob�", "v dob� adventn�", "", "", "", "v dob� adventn�", "adventben"},
 {"vo viano�nom obdob�", "v dob� v�no�n�", "", "", "", "v dob� v�no�n�", "a kar�csonyi id�ben"},
 {"vo viano�nom obdob�", "v dob� v�no�n�", "", "", "", "v dob� v�no�n�", "a kar�csonyi id�ben"},
 	// obdobie �cez rok�
 {"v cezro�nom obdob�", "v mezidob�", "", "per annum", "", "v mezidob�", "az �vk�zi id�ben"},
 {"v p�stnom obdob�", "v dob� postn�", "", "", "", "v dob� postn�", "a nagyb�jti id�ben"},
 {"vo Ve�kom t��dni", "ve Svat�m t�dnu", "", "", "", "ve Svat�m t�dnu", "a nagyh�ten"},
 {"vo ve�kono�nom trojdn�", "ve velikono�n�m triduu", "", "", "", "ve velikono�n�m triduu", "a szent h�rom napban"},
 {"vo ve�kono�nom obdob�", "v dob� velikono�n�", "", "", "", "v dob� velikono�n�", "a h�sv�ti id�ben"},
 {"vo ve�kono�nom obdob�", "v dob� velikono�n�", "", "", "", "v dob� velikono�n�", "a h�sv�ti id�ben"},
 {"v okt�ve Narodenia P�na", "v okt�vu Narozen� P�n�", "", "", "", "v okt�vu Narozen� P�n�", "h�sv�t nyolcad�ban"}
};

#define		nazov_obdobia_v(a)	nazov_obdobia_v_jazyk[a][_global_jazyk]

/* the names of liturgical periods in local grammatically 6.th declination? (uppercase) / nazov_obdobia: string pre nazov liturgickeho obdobia */
const char *nazov_OBDOBIA_V_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{{"VO VE�KONO�NEJ OKT�VE", "VE VELIKONO�N�M OKT�VU", "", "", "", "V OKT�VU VELIKONO�N�M", "H�SV�T NYOLCACAD�BAN"},
 {"V ADVENTNOM OBDOB�", "V DOB� ADVENTN�", "", "", "", "V DOB� ADVENTN�", "ADVENTBEN"},
 {"V ADVENTNOM OBDOB�", "V DOB� ADVENTN�", "", "", "", "V DOB� ADVENTN�", "ADVENTBEN"},
 {"VO VIANO�NOM OBDOB�", "V DOB� V�NO�N�", "", "", "", "V DOB� V�NO�N�", "A KAR�CSONYI ID�BEN"},
 {"VO VIANO�NOM OBDOB�", "V DOB� V�NO�N�", "", "", "", "V DOB� V�NO�N�", "A KAR�CSONYI ID�BEN"},
 	// OBDOBIE �CEZ ROK�
 {"V CEZRO�NOM OBDOB�", "V MEZIDOB�", "", "", "", "B�HEM ROKU", "AZ �VK�ZI ID�BEN"},
 {"V P�STNOM OBDOB�", "V DOB� POSTN�", "", "", "", "V DOB� POSTN�", "A NAGYB�JTI ID�BEN"},
 {"VO VE�KOM TݎDNI", "VE SVAT�M T�DNU", "", "", "", "VE SVAT�M T�DNU", "A NAGYH�TEN"},
 {"VO VE�KONO�NOM TROJDN�", "VE VELIKONO�N�M TRIDUU", "", "", "", "VE VELIKONO�N�M TRIDUU", "A SZENT H�ROM NAPBAN"},
 {"VO VE�KONO�NOM OBDOB�", "V DOB� VELIKONO�N�", "", "", "", "V DOB� VELIKONO�N�", "A H�SV�TI ID�BEN"},
 {"VO VE�KONO�NOM OBDOB�", "V DOB� VELIKONO�N�", "", "", "", "V DOB� VELIKONO�N�", "A H�SV�TI ID�BEN"},
 {"V OKT�VE NARODENIA P�NA", "V OKT�VU NAROZEN� P�N�", "", "", "", "V OKT�VU NAROZEN� P�N�", "A H�SV�T NYOLCAD�BAN"}
};

#define		nazov_OBDOBIA_V(a)	nazov_OBDOBIA_V_jazyk[a][_global_jazyk]

/* used for Sundays - "which" Sunday for some of them, e.g. "dominica V paschae" for 5-th Sunday in that liturgical period (uppercase) */
/* 2008-12-20: doplnen� - pou��va sa v init_global_string() pre nedele niektor�ch obdob� [zatia� iba v sloven�ine] */
const char *nazov_OBDOBIA_AKA_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{{"VO VE�KONO�NEJ OKT�VE", "VE VELIKONO�N�M OKT�VU", "", "", "", "V OKT�VU VELIKONO�N�M", "hu_"}, // not used / nepou��va sa
 {"ADVENTN�", "ADVENTN�", "", "", "", "ADVENTN�", "ADVENT"},
 {"ADVENTN�", "ADVENTN�", "", "", "", "ADVENTN�", "ADVENT"},
 {"VIANO�N�", "V�NO�N�", "", "", "", "V�NO�N�", "KAR�CSONY"},
 {"VIANO�N�", "V�NO�N�", "", "", "", "V�NO�N�", "KAR�CSONY"},
 {"CEZRO�N�", "V MEZIDOB�", "", "", "", "B�HEM ROKU", "hu_"}, // not used / nepou��va sa
 {"P�STNA", "POSTN�", "", "", "", "POSTN�", "�VK�ZI"},
 {"VO VE�KOM TݎDNI", "VE SVAT�M T�DNU", "", "", "", "VE SVAT�M T�DNU", "hu_"}, // not used / nepou��va sa
 {"VO VE�KONO�NOM TROJDN�", "VE VELIKONO�N�M TRIDUU", "", "", "", "VE VELIKONO�N�M TRIDUU", "hu_"}, // not used / nepou��va sa
 {"VE�KONO�N�", "VELIKONO�N�", "", "", "", "VELIKONO�N�", "H�SV�T"},
 {"VE�KONO�N�", "VELIKONO�N�", "", "", "", "VELIKONO�N�", "H�SV�T"},
 {"V OKT�VE NARODENIA P�NA", "V OKT�VU NAROZEN� P�N�", "", "", "", "V OKT�VU NAROZEN� P�N�", "hu_"} // not used / nepou��va sa
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
/* 2005-08-05: Pridan�. zv�zok brevi�ra (LH) pre spolo�n� �asti sv�t�ch v kotv�ch */
const char *zvazok_OBD[] =
{"ZVII", "ZVI", "ZVI",
 "ZVI", "ZVI", "OCR", /* OCR je ZVIII aj ZVIV */
 "ZVII", "ZVII",
 "ZVII", "ZVII", "ZVII",
 "ZVI"};

/* the name of celebration */
const char *nazov_slavenia_jazyk[POCET_SLAVENI + 1][POCET_JAZYKOV + 1] =
{{"___", "___", "___", "", ""}, 
 {"sl�vnos�", "slavnost", "celebration", "sollemnitas", "","Slavnost", "f��nnep"},
 {"sviatok", "sv�tek", "", "festum", "","Sv�tek", "�nnep"},
 {"spomienka", "pam�tka", "", "memoria", "","Pam�tka", "eml�knap"},
 {"�ubovo�n� spomienka", "nez�vazn� pam�tka", "", "memoria ad libitum", "","nez�vazn� pam�tka", "tetsz�s szerinti eml�knap"},
 {"vlastn� sl�venie", "z vlastn�ch text�", "", "textus proprius", "", "z vlastn�ch text�", "saj�t sz�veg"},
};

#define		nazov_slavenia(a)	nazov_slavenia_jazyk[a][_global_jazyk]

/* special "local" or "partial" characteristics of various celebrations - each in one language; no need to translate; special strings will be added */
/* 2005-07-27: doplnen�
 * 2007-08-31: upraven� TT -> BA-TT
 * 2008-06-23: upraven� vzh�adom k nov�mu usporiadaniu diec�z (intuit�vne)
 */
const char *nazov_slavenia_lokal[] =
{""
,"len v ro��avskej katedr�le"
,"hlavn� patr�n Trnavskej arcidiec�zy" /* "hlavn� patr�n Bratislavsko-Trnavskej arcidiec�zy" */
,"v Bratislavskej a Trnavskej arcidiec�ze a v Banskobystrickej, Ko�ickej, Nitrianskej a Ro��avskej diec�ze" /* "v Bratislavsko-Trnavskej arcidiec�ze a v Banskobystrickej, Ko�ickej, Nitrianskej a Ro��avskej diec�ze" */
,"v Nitrianskej diec�ze sviatok hlavn�ch patr�nov"
,"len v Ko�ickej diec�ze"
,"len v Nitrianskej diec�ze"
,"len v Banskobystrickej diec�ze"
,"len v Spi�skej diec�ze"
,"len v Ro��avskej diec�ze"
,"len v Trnavskej arcidiec�ze" /* "len v Bratislavsko-trnavskej arcidiec�ze" */ /* LOKAL_SLAV_TRNAVA - p�vodne bolo "len v Trnavskej diec�ze", upraven� 2007-08-31*/
,"len v D�me sv. Martina v Bratislave"
,"v Spi�skej diec�ze sviatok hlavn�ho patr�na"
,"v Banskobystrickej diec�ze sviatok hlavn�ho patr�na"
,"v Bratislavskej a Trnavskej arcidiec�ze a v Banskobystrickej, Nitrianskej a Ro��avskej diec�ze" /* "v Bratislavsko-Trnavskej arcidiec�ze a v Banskobystrickej, Nitrianskej a Ro��avskej diec�ze" */
,"v Ko�ickej diec�ze sviatok hlavn�ho patr�na"
,"na Slovensku 5. j�la, sl�vnos�; v Eur�pe sviatok"
,"v Ro��avskej diec�ze sviatok hlavn�ho patr�na"
,"len v konsekrovan�ch kostoloch"
,"Druh� ve�kono�n� nede�a - Bo�ieho milosrdenstva"
,"koniec Okt�vy narodenia P�na"
,"konec Okt�vu Narozen� P�n�"
,"hlavn�ho patrona pra�sk� arcidiec�ze"
,"v pra�sk� arcidiec�zi"
,"v brn�nsk� diec�zi"
,"na Morav� pam�tka"
,"Druh� ned�le velikono�n� - Bo��ho milosrdenstv�"
,"v pra�sk� katedr�le slavnost"
,"v �eskobud�jovick� diec�zi"
,"v olomouck� arcidiec�zi"
,"v �ech�ch sv�tek"
,"v plze�sk� diec�zi sv�tek hlavn�ho patrona"
,"v ostravsko-opavsk� diec�zi"
,"v litom��ick� diec�zi"
,"v kr�lov�hradeck� diec�zi"
,"jen v posv�cen�ch kostel�ch"
,"v plze�sk� diec�zi"
,"ve Slezsku sv�tek"
,"v �eskobud�jovick� diec�zi pam�tka"
,"v Bratislavskej arcidiec�ze a v Spi�skej diec�ze sviatok hlavn�ho patr�na" /* doplnen� 2008-06-24 */
};

/* names of liturgical colors */
const char *nazov_farby_jazyk[POCET_FARIEB + 1][POCET_JAZYKOV + 1] =
{{"___", "___", "___", "___", "___", "___", "___"},
 {"�erven�", "�erven�", "red", "rosa", "", "�erven�", "piros"},
 {"biela", "b�l�", "white", "alba", "", "b�l�", "feh�r"},
 {"zelen�", "zelen�", "green", "___", "", "zelen�", "z�ld"},
 {"fialov�", "fialov�", "purple", "___", "", "fialov�", "lila"},
 {"ru�ov�", "r��ov�", "rose", "___", "", "r��ov�", "r�zsasz�n"},
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
{ {"nede�a", "ned�le", "Sunday", "dom�nica", "", "ned�le", "vas�rnap"}
, {"pondelok" , "pond�l�", "Monday", "feria sec�nda", "", "pond�l�", "h�tf�"}
, {"utorok" , "�ter�", "Tuesday", "feria t�rtia", "", "�ter�", "kedd"}
, {"streda" , "st�eda", "Wednesday", "feria quarta", "", "st�eda", "szerda"}
, {"�tvrtok" , "�tvrtek", "Thursday", "feria quinta", "", "�tvrtek", "cs�t�rt�k"}
, {"piatok" , "p�tek", "Friday", "feria sexta", "", "p�tek", "p�ntek"}
, {"sobota" , "sobota", "Saturday", "s�bbatum", "", "sobota", "szombat"}
, {"nezn�my" , "nezn�m�", "unknown", "???", "", "nezn�m�", "ismeretlen"}
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
{ {"Nede�a", "Ned�le", "Sunday", "Dom�nica", "", "Ned�le", "Vas�rnap"}
, {"Pondelok" , "Pond�l�", "Monday", "Feria sec�nda", "", "Pond�l�", "H�tf�"}
, {"Utorok" , "�ter�", "Tuesday", "Feria t�rtia", "", "�ter�", "Kedd"}
, {"Streda" , "St�eda", "Wednesday", "Feria quarta", "", "St�eda", "Szerda"}
, {"�tvrtok" , "�tvrtek", "Thursday", "Feria quinta", "", "�tvrtek", "Cs�t�rt�k"}
, {"Piatok" , "P�tek", "Friday", "Feria sexta", "", "P�tek", "P�ntek"}
, {"Sobota" , "Sobota", "Saturday", "S�bbatum", "", "Sobota", "Szombat"}
, {"Nezn�my" , "Nezn�m�", "unknown", "???", "", "Nezn�m�", "Ismeretlen"}
};

#define		nazov_Dna(a)	nazov_Dna_jazyk[a][_global_jazyk]

/* names of the days in week, starting with Sunday (uppercase) */
const char *nazov_DNA_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{ {"NEDE�A", "NED�LE", "SUNDAY", "DOM�NICA", "", "NED�LE", "VAS�RNAP"}
, {"PONDELOK" , "POND�L�", "MONDAY", "FERIA SEC�NDA", "", "POND�L�", "H�TF�"}
, {"UTOROK" , "�TER�", "TUESDAY", "FERIA T�RTIA", "", "�TER�", "KEDD"}
, {"STREDA" , "ST�EDA", "WEDNESDAY", "FERIA QUARTA", "", "ST�EDA", "SZERDA"}
, {"�TVRTOK" , "�TVRTEK", "THURSDAY", "FERIA QUINTA", "", "�TVRTEK", "CS�T�RT�K"}
, {"PIATOK" , "P�TEK", "FRIDAY", "FERIA SEXTA", "", "P�TEK", "P�NTEK"}
, {"SOBOTA" , "SOBOTA", "SATURDAY", "S�BBATUM", "", "SOBOTA", "SZOMBAT"}
, {"NEZN�MY" , "NEZN�M�", "UNKNOWN", "???", "", "NEZN�M�", "ISMERETLEN"}
};

#define		nazov_DNA(a)	nazov_DNA_jazyk[a][_global_jazyk]

/* two/three-letter abbreviations of the names of the days in week, starting with Sunday (sentence case) */
const char *nazov_Dn_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{ {"Ne" , "Ne", "Sun", "Do", "", "Ne", "V"}
, {"Po" , "Po", "Mon", "F2", "", "Po", "H"}
, {"Ut" , "�t", "Tue", "F3", "", "�t", "K"}
, {"St" , "St", "Wed", "F4", "", "St", "Sze"}
, {"�t" , "�t", "Thu", "F5", "", "�t", "Cs"}
, {"Pi" , "P�", "Fri", "F6", "", "P�", "P"}
, {"So" , "So", "Sat", "S�", "", "So", "Szo"}
, {"??" , "??", "???", "", "", "??", "??"}
};

#define		nazov_Dn(a)	nazov_Dn_jazyk[a][_global_jazyk]

/* two/three-letter abbreviations of the names of the days in week, starting with Sunday used for anchors (uppercase, no need to translate; based on Slovak) */
/* 2006-08-01: pou��va sa pre HTML kotvy, ktor� nez�visia od jazykovej mut�cie */
const char *nazov_DN_asci[] =
{"NE", "PO", "UT", "STR", "STV", "PI", "SO", "??"};

/* two/three-letter abbreviations of the names of the days in week, starting with Sunday used for debug info (lowercase, no need to translate; based on Slovak) */
const char *nazov_dn_asci[] =
{"ne", "po", "ut", "str", "stv", "pi", "so", "??"};

/* the names of the months (lowecase) / nazov_mesiaca: string pre nazov dna; suhlasi s struct tm.tm_mon;
 * Month (0--11) */
const char *nazov_mesiaca_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{ {"janu�r", "leden", "January", "ianu�rius", "", "leden", "janu�r"}
, {"febru�r" , "�nor", "February", "feb", "", "�nor", "febru�r"}
, {"marec" , "b�ezen", "March", "mar", "", "b�ezen", "m�rcius"}
, {"apr�l" , "duben", "April", "apr", "", "duben", "�prilis"}
, {"m�j" , "kv�ten", "May", "mai", "", "kv�ten", "m�jus"}
, {"j�n" , "�erven", "June", "iun", "", "�erven", "j�nius"}
, {"j�l" , "�ervenec", "July", "iul", "", "�ervenec", "j�lius"}
, {"august" , "srpen", "August", "aug", "", "srpen", "augusztus"}
, {"september" , "z���", "September", "sep", "", "z���", "szeptember"}
, {"okt�ber" , "��jen", "October", "oct", "", "��jen", "okt�ber"}
, {"november" , "listopad", "November", "nov", "", "listopad", "november"}
, {"december" , "prosinec", "December", "dec", "", "prosinec", "december"}
, {"nezn�my" , "nezn�m�", "unknown", "___", "", "nezn�m�", "ismeretlen"}
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
{ {"Janu�r", "Leden", "January", "Ianu�rius", "", "Leden", "Janu�r"}
, {"Febru�r" , "�nor", "February", "Febru�rius", "", "�nor", "Febru�r"}
, {"Marec", "B�ezen", "March", "M�rtius", "", "B�ezen", "M�rcius"}
, {"Apr�l" , "Duben", "April", "Apr�lis", "", "Duben", "�prilis"}
, {"M�j" , "Kv�ten", "May", "Maius", "", "Kv�ten", "M�jus"}
, {"J�n" , "�erven", "June", "I�nius", "", "�erven", "J�nius"}
, {"J�l" , "�ervenec", "July", "I�lius", "", "�ervenec", "J�lius"}
, {"August" , "Srpen", "August", "Aug�stus", "", "Srpen", "Augusztus"}
, {"September" , "Z���", "September", "Sept�mber", "", "Z���", "Szeptember"}
, {"Okt�ber" , "��jen", "October", "Oct�ber", "", "��jen", "Okt�ber"}
, {"November" , "Listopad", "November", "Nov�mber", "", "Listopad", "November"}
, {"December" , "Prosinec", "December", "Dec�mber", "", "Prosinec", "December"}
, {"Nezn�my" , "Nezn�m�", "unknown", "???", "", "Nezn�m�", "Ismeretlen"}
};

#define		nazov_Mesiaca(a)	nazov_Mesiaca_jazyk[a][_global_jazyk]

/* the names of the months (uppercase) */
const char *nazov_MESIACA_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{ {"JANU�R", "LEDEN", "JANUARY", "IANU�RIUS", "", "LEDEN", "JANU�R"}
, {"FEBRU�R" , "�NOR", "FEBRUARY", "FEBRU�RIUS", "", "�NOR", "FEBRU�R"}
, {"MAREC", "B�EZEN", "MARCH", "M�RTIUS", "", "B�EZEN", "M�RCIUS"}
, {"APR�L" , "DUBEN", "APRIL", "APR�LIS", "", "DUBEN", "�PRILIS"}
, {"M�J" , "KV�TEN", "MAY", "MAIUS", "", "KV�TEN", "M�JUS"}
, {"J�N" , "�ERVEN", "JUNE", "I�NIUS", "", "�ERVEN", "J�NIUS"}
, {"J�L" , "�ERVENEC", "JULY", "I�LIUS", "", "�ERVENEC", "J�LIUS"}
, {"AUGUST" , "SRPEN", "AUGUST", "AUG�STUS", "", "SRPEN", "AUGUSZTUS"}
, {"SEPTEMBER" , "Z���", "SEPTEMBER", "SEPT�MBER", "", "Z���", "SZEPTEMBER"}
, {"OKT�BER" , "��JEN", "OCTOBER", "OCT�BER", "", "��JEN", "OKT�BER"}
, {"NOVEMBER" , "LISTOPAD", "NOVEMBER", "NOV�MBER", "", "LISTOPAD", "NOVEMBER"}
, {"DECEMBER" , "PROSINEC", "DECEMBER", "DEC�MBER", "", "PROSINEC", "DECEMBER"}
, {"NEZN�MY" , "NEZN�M�", "UNKNOWN", "???", "", "NEZN�M�", "ISMERETLEN"}
};

#define		nazov_MESIACA(a)	nazov_MESIACA_jazyk[a][_global_jazyk]

/* the names of the months (lowercase) in genitive grammatically 2.th declination?; in English: "IN that month" or "OF that month" /  genit�v == 2. p�d, koho/�oho */
/* usage: when generated string for date, e.g. en: "1st January 2000", sk: "1. janu�ra 2000" */
/* 2007-03-20: pridan� genit�v n�zvu mesiaca kv�li latin�ine */
const char *nazov_mesiaca_gen_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{ {"janu�ra", "ledna", "January", "ianu�rii", "", "ledna", "janu�r"}
, {"febru�ra" , "�nora", "February", "febru�rii", "", "�nora", "febru�r"}
, {"marca" , "b�ezna", "March", "m�rtii", "", "b�ezna", "m�rcius"}
, {"apr�la" , "dubna", "April", "apr�lis", "", "dubna", "�prilis"}
, {"m�ja" , "kv�tna", "May", "maii", "", "kv�tna", "m�jus"}
, {"j�na" , "�ervna", "June", "i�nii", "", "�ervna", "j�nius"}
, {"j�la" , "�ervence", "July", "i�lii", "", "�ervence", "j�lius"}
, {"augusta" , "srpna", "August", "aug�sti", "", "srpna", "augusztus"}
, {"septembra" , "z���", "September", "sept�mbris", "", "z���", "szeptember"}
, {"okt�bra" , "��jna", "October", "oct�bris", "", "��jna", "okt�ber"}
, {"novembra" , "listopadu", "November", "nov�mbris", "", "listopadu", "november"}
, {"decembra" , "prosince", "December", "dec�mbris", "", "prosince", "december"}
, {"nezn�meho" , "nezn�m�ho", "unknown", "___", "", "nezn�m�ho", "ismeretlen"}
};

#define		nazov_mesiaca_gen(a)	nazov_mesiaca_gen_jazyk[a][_global_jazyk]

/* 2007-03-20: pridan� genit�v n�zvu mesiaca kv�li latin�ine */
const char *nazov_Mesiaca_gen_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{ {"Janu�ra", "Ledna", "January", "Ianu�rii", "", "Ledna", "Janu�r"}
, {"Febru�ra" , "�nora", "February", "Febru�rii", "", "�nora", "Febru�r"}
, {"Marca" , "B�ezna", "March", "M�rtii", "", "B�ezna", "M�rcius"}
, {"Apr�la" , "Dubna", "April", "Apr�lis", "", "Dubna", "�prilis"}
, {"M�ja" , "Kv�tna", "May", "Maii", "", "Kv�tna", "M�jus"}
, {"J�na" , "�ervna", "June", "I�nii", "", "�ervna", "J�nius"}
, {"J�la" , "�ervence", "July", "I�lii", "", "�ervence", "J�lius"}
, {"Augusta" , "Srpna", "August", "Aug�sti", "", "Srpna", "Augusztus"}
, {"Septembra" , "Z���", "September", "Sept�mbris", "", "Z���", "Szeptember"}
, {"Okt�bra" , "��jna", "October", "Oct�bris", "", "��jna", "Okt�ber"}
, {"Novembra" , "Listopadu", "November", "Nov�mbris", "", "Listopadu", "November"}
, {"Decembra" , "Prosince", "December", "Dec�mbris", "", "Prosince", "December"}
, {"Nezn�meho" , "Nezn�m�ho", "Unknown", "___", "", "Nezn�m�ho", "Ismeretlen"}
};

#define		nazov_Mesiaca_gen(a)	nazov_Mesiaca_gen_jazyk[a][_global_jazyk]

/* three-letter abbreviations of the names of the months used for anchors (uppercase, no need to translate; based on Slovak) */
const char *nazov_MES[] =
{"JAN", "FEB", "MAR", "APR", "MAJ", "JUN", "JUL", "AUG", "SEP", "OKT", "NOV", "DEC", "___"};

/* three-letter abbreviations of the names of the months used for anchors (lowercase, no need to translate; based on Slovak) */
const char *nazov_mes[] =
{"jan", "feb", "mar", "apr", "maj", "jun", "jul", "aug", "sep", "okt", "nov", "dec", "___"};

/* ordinal numbers for first few Sundays (sentence case) - used for special occasions currently only in Slovak; no need to change */
/* 2008-12-20: pridan� re�azec pre poradov� ��slo - pou��va sa v init_global_string() pre nedele niektor�ch obdob� [zatia� iba v sloven�ine] */
const char *poradie_Slovom_jazyk[POCET_TYZDNOV + 1][POCET_JAZYKOV + 1] = 
{ {"Prv�", "Prvn�", "", "", "", "Prvn�", "1."}
, {"Druh�" , "Druh�", "", "", "", "Druh�", "2."}
, {"Tretia" , "T�et�", "", "", "", "T�et�", "3."}
, {"�tvrt�" , "�trvt�", "", "", "", "�trvt�", "4."}
, {"Piata" , "P�t�", "", "", "", "P�t�", "5."}
, {"�iesta" , "�est�", "", "", "", "�est�", "6."}
, {"Siedma" , "Sedm�", "", "", "", "Sedm�", "7."}
, {"�sma" , "Osm�", "", "", "", "Osm�", "8."}
, {"Deviata" , "Dev�t�", "", "", "", "Dev�t�", "9."}
, {"Desiata" , "Des�t�", "", "", "", "Des�t�", "10."}
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
{ {"PRV�", "PRVN�", "", "", "", "PRVN�", "1."}
, {"DRUH�" , "DRUH�", "", "", "", "DRUH�", "2."}
, {"TRETIA" , "T�ET�", "", "", "", "T�ET�", "3."}
, {"�TVRT�" , "�TRVT�", "", "", "", "�TRVT�", "4."}
, {"PIATA" , "P�T�", "", "", "", "P�T�", "5."}
, {"�IESTA" , "�EST�", "", "", "", "�EST�", "6."}
, {"SIEDMA" , "SEDM�", "", "", "", "SEDM�", "7."}
, {"OSMA" , "OSM�", "", "", "", "OSM�", "8."}
, {"DEVIATA" , "DEV�T�", "", "", "", "DEV�T�", "9."}
, {"DESIATA" , "DES�T�", "", "", "", "DES�T�", "10."}
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
/* 2006-07-11: Pridan� kv�li jazykov�m mut�ci�m */
const char *nazov_jazyka[POCET_JAZYKOV + 1] =
{"sloven�ina", "�e�tina", "English", "lingua latina", "(neur�en�)", "�e�tina (dominik�ni)", "magyarul"};

/* language codes; internal usage for HTTP requests */
const char *skratka_jazyka[POCET_JAZYKOV + 1] =
{"sk", "cz", "en", "la", "??", "c2", "hu"};

/* language codes; internal usage for include directories (postfix of directory/folder name); postfix MUST NOT contain slash/backslash */
/* 2006-07-13 a 17: Pridan� kv�li jazykov�m mut�ci�m - postfix pre include adres�r */
const char *postfix_jazyka[POCET_JAZYKOV + 1] =
{"", "cz", "en", "la", "", "czop", "hu"};
/* Pozn�mka: Postfix nesmie obsahova� na za�iatku odde�ova� (slash resp. backslash); mus� sa jedna� o podadres�r pod include */

/* filename of CSS file; the number of CSS does not directly correspond to the number of languages */
/* 2006-08-08: Pridan� kv�li r�znym css */
const char *nazov_css[POCET_CSS + 1] =
{"(css neur�en�)", "breviar.css", "breviar_kbd.css", "ebreviar_cz.css", "ebreviar_cz_op.css"};

const char *skratka_css[POCET_CSS + 1] =
{"__", "def", "kbd", "cz", "czop"};

/* strings of buttons - abbreviations of prayer names */
/* 2006-10-11: definovanie re�azcov aj pre invitat�rium a komplet�rium */
const char *html_button_invitatorium[] = {"Inv.", "Inv.", "Inv.", "Inv.", "", "Inv.", "Inv."};
#ifndef HTML_BUTTON_INVITATORIUM
#define HTML_BUTTON_INVITATORIUM	html_button_invitatorium[_global_jazyk]
#endif

const char *html_button_kompletorium[] = {"Kompl.", "Kompl.", "Compl.", "Compl.", "", "Kompl.", "Kompl."};
#ifndef HTML_BUTTON_KOMPLETORIUM
#define HTML_BUTTON_KOMPLETORIUM	html_button_kompletorium[_global_jazyk]
#endif

/* defin�cie HTML prvkov upraven� a presunut� z mydefs.h, 2006-08-01 */
const char *html_button_ranne_chvaly[] = {"Rann� chv�ly", "Rann� chv�ly", "Morning prayer", "Laudes", "", "Rann� chv�ly", "Reggeli dics�ret"};
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

const char *html_button_vespery[] = {"Ve�pery", "Ne�pory", "Vesperae", "V�sperae", "", "Ve�ern� chv�ly", "Esti dics�ret"};
#ifndef HTML_BUTTON_VESPERY
#define HTML_BUTTON_VESPERY	html_button_vespery[_global_jazyk]
#endif

const char *html_button_posv_citanie[] = {"Posv. ��t.", "�ten�", "Reading", "Off. lect.", "", "�ten�", "Olvasm�nyos ima�ra"};
#ifndef HTML_BUTTON_POSV_CITANIE
#define HTML_BUTTON_POSV_CITANIE	html_button_posv_citanie[_global_jazyk]
#endif

/* special button: Details... */
const char *html_button_detaily[] = {"Detaily...", "Podrobn�ji...", "Details...", "Opti�nes...", "", "Podrobn�ji...", "R�szletek..."};
#ifndef HTML_BUTTON_DETAILY
#define HTML_BUTTON_DETAILY	html_button_detaily[_global_jazyk]
#endif

/* special button: Show prayer */
const char *html_button_det_show[] = {"Zobraz modlitbu", "Uka� modlitbu", "Show prayer", "xxx", "", "Uka� modlitbu", "Mutasd az im�t"};
#ifndef HTML_BUTTON_DET_SHOW
#define HTML_BUTTON_DET_SHOW	html_button_det_show[_global_jazyk]
#endif

/* special button: Defaults */
const char *html_button_det_defaults[] = {"P�vodn� hodnoty", "P�vodn� hodnoty", "Defaults", "___", "", "P�vodn� hodnoty", "Alap�rtelmezett"};
#ifndef HTML_BUTTON_DET_DEFAULTS
#define HTML_BUTTON_DET_DEFAULTS	html_button_det_defaults[_global_jazyk]
#endif

/* special button (today): Show */
const char *html_button_dnes_show[] = {"Zobraz", "Uka�", "Show", "___", "", "Uka�", "Mutasd"};
#ifndef HTML_BUTTON_DNES_SHOW
#define HTML_BUTTON_DNES_SHOW	html_button_dnes_show[_global_jazyk]
#endif

/* special button (today): Defaults (clear form) */
const char *html_button_dnes_defaults[] = {"Vy�isti", "Vy�isti", "Clear", "???", "", "Vy�isti", "T�r�l"};
#ifndef HTML_BUTTON_DNES_DEFAULTS
#define HTML_BUTTON_DNES_DEFAULTS	html_button_dnes_defaults[_global_jazyk]
#endif

/* special button (today): Morning prayer with canticum of Zekariah */
/* doplnen�, 2007-09-13 */
const char *html_button_ranne_chvaly_benediktus[] = {"Rann� chv�ly + Benediktus", "Rann� chv�ly + Zach. kantikum", "Morning prayer with Benedictus", "Laudes + Benedictus", "", "Rann� chv�ly + Zach. kantikum", "Reggeli dics�ret Benedictusszal"};
#ifndef HTML_BUTTON_RANNE_CHVALY_BENEDIKTUS
#define HTML_BUTTON_RANNE_CHVALY_BENEDIKTUS	html_button_ranne_chvaly_benediktus[_global_jazyk]
#endif

/* special button (today): Evening prayer with canticum of Mary */
const char *html_button_vespery_magnifikat[] = {"Ve�pery + Magnifikat", "Ne�pory + Mariino kant.", "Vesperae + Magnificat", "Vesperae + Magnificat", "", "Ve�ern� chv�ly + kant. Panny Marie", "Esti dics�ret Magnificattal"};
#ifndef HTML_BUTTON_VESPERY_MAGNIFIKAT
#define HTML_BUTTON_VESPERY_MAGNIFIKAT	html_button_vespery_magnifikat[_global_jazyk]
#endif

/* special button (today): Completory prayer with canticum of Simeon; is currently used only in Slovak */
/* doplnen�, 2008-12-20; nepou��va sa pre ostatn� jazyky */
const char *html_button_kompletorium_nunkdim[] = {"Komplet�rium + Nunk dimittis", "xxx", "xxx", "xxx", "", "xxx", "hu_xxx"};
#ifndef HTML_BUTTON_KOMPLETORIUM_NUNKDIM
#define HTML_BUTTON_KOMPLETORIUM_NUNKDIM	html_button_kompletorium_nunkdim[_global_jazyk]
#endif

/* navigation buttons/texts: previous, next, today */
const char *html_button_predchadzajuci_[] = {"Predch�dzaj�ci", "P�edchoz�", "Previous", "Praeced�nte", "", "P�edchoz�", "El�z�"};
const char *html_button_nasledujuci_[] = {"Nasleduj�ci", "N�sleduj�c�", "Next", "Success�vo", "", "N�sleduj�c�", "K�vetkez�"};
const char *html_button_dnes[] = {"Dnes", "Dnes", "Today", "H�die", "", "Dnes", "Ma"};

/* basic words: day, month, year */
const char *html_text_den[] = {"de�", "den", "day", "die", "", "den", "nap"};
const char *html_text_mesiac[] = {"mesiac", "m�s�c", "month", "(mesiac)", "", "m�s�c", "h�"};
const char *html_text_rok[] = {"rok", "rok", "year", "anno", "", "rok", "�v"};
const char *html_text_Rok[] = {"Rok", "Rok", "Year", "Anno", "", "Rok", "�v"};
/* in the following: you MUST keep all %d, %c, %s etc. variables - these are replaced by numbers, characters, strings, etc. respectively */
const char *html_text_Rok_x[] = {"Rok %d", "Rok %d", "Year %d", "Anno %d", "%d", "Rok %d", "�v %d"};

const char *html_text_zoznam_mesiacov[] = {"zoznam mesiacov", "seznam m�s�c�", "list of months", "", "", "seznam m�s�c�", "h�napok list�ja"};

const char *html_text_modlitba[] = {"modlitba", "modlitba", "prayer", "ora", "", "modlitba", "im�ds�g"};
const char *html_text_modlitby_pre_den[] = {"modlitby pre de�", "modlitby pro den", "prayers for date", "", "", "modlitby pro den", "hu_prayers for date"};
const char *html_text_alebo_pre[] = {"alebo pre", "anebo pro", "or for", "vel per", "", "anebo pro", "hu_or for"};
const char *html_text_dnesok[] = {"dne�ok", "dne�n� den", "today", "h�die", "", "dne�n� den", "ma"};

const char *html_text_Vysvetlivky[] = {"Vysvetlivky", "Vysv�tlivky", "Legenda", "Legenda", "", "Vysv�tlivky", "Jelmagyar�zat"};

const char *html_text_dalsie_moznosti[] = {"Vyberte si �al�ie mo�nosti ", "Dal�� mo�nosti v�b�ru ", "Choose from above (buttons) or from the following options: ", "", "", "Dal�� mo�nosti v�b�ru", "V�lassz egy ima�r�t vagy az al�bbi lehet�s�gek k�z�l"};
const char *html_text_prik_sviatky_atd[] = {"prik�zan� sviatky a sl�vnosti P�na v roku ", "zasv�cen� sv�tky a slavnosti P�n� v roce ", "obligatory celebrations in year ", "", "", "zasv�cen� sv�tky a slavnosti P�n� v roce", "k�telez� �nnepek"};
const char *html_text_lit_kalendar[] = {"liturgick� kalend�r pre", "liturgick� kalend�� pro", "liturgical calendar for", "", "", "liturgick� kalend�� pro", "liturgikus napt�r"};
const char *html_text_roku[] = {"roku", "roku", "of year", "", "", "roku", ""};
const char *html_text_tabulka_pohyblive_od[] = {"tabu�ka d�tumov pohybliv�ch sl�ven� od roku", "tabulka s daty prom�nn�ch slavnost� od roku", "table with dates of movable celebrations from year", "", "", "tabulka s daty prom�nn�ch slavnost� od roku", "a v�ltoz� �nnepek list�ja a k�vetkez� �vekben"};
const char *html_text_do_roku[] = {"do roku", "po rok", "till year", "", "", "po rok", ""};
const char *html_text_zobrazit_linky[] = {"zobrazi� tabu�ku vr�tane hypertextov�ch odkazov na jednotliv� dni", "zobrazit tabulku s hypertextov�mi odkazy pro jednotliv� dny", "display the table including hypertext links to each date", "", "", "zobrazit tabulku s hypertextov�mi odkazy pro jednotliv� dny", "minden felirat mutasson a megfelel� oldalunkra"};
const char *html_text_pre_cezrocne_obd[] = {"pre cezro�n� obdobie", "pro mezidob�", "for ...", "", "", "pro dobu b�hem roku", ""};
const char *html_text_tyzden_zaltara[] = {". t��de� �alt�ra", ". t�den �alt��e", "week of Psaltary", "hebdomada", "", ". t�den �alt��e", ". zsolt�ros h�t"};
const char *html_text_tyzden[] = {". t��de�", ". t�den", "week", "hebdomada", "", ". t�den", "h�t"};
const char *html_text_v_tyzdni_zaltara[] = {". t��dni �alt�ra", ". t�dnu �alt��e", "week of Psaltary", "hebdomada", "", ". t�dnu �alt��e", ". zsolt�ros h�t"};
/* in the following: you MUST keep all HTML elements, e.g. <a href...>, <br> etc. */
const char *html_text_dnes_je_atd[] = 
{"Dnes je %d. de� v roku%s, <a href=\"%s%s\">juli�nsky d�tum</a> JD = %ld%s.\n<br>\n",
 "Dnes je %d. den v roku%s, <a href=\"%s%s\">juli�nsk� datum</a> JD = %ld%s.\n<br>\n",
 "Today is %d. day in the year%s, <a href=\"%s%s\">Julian date</a> JD = %ld%s.\n<br>\n",
 "Hodie est %d. die anno %s, <a href=\"%s%s\">Iulianus datum</a> JD = %ld%s.\n<br>\n",
 "%d/%s<a href=\"%s%s\">JD</a> = %ld%s.\n<br>\n",
 "Dnes je %d. den v roku%s, <a href=\"%s%s\">juli�nsk� datum</a> JD = %ld%s.\n<br>\n",
 "Ma %s %d. napja van, <a href=\"%s%s\">Juli�n napt�r</a> JD = %ld%s.\n<br>\n"};

const char *html_text_zakladne_info[] = {"Z�kladn� inform�cie", "Z�kladn� informace", "Basic info", "__info__", "", "Z�kladn� informace", "Alap inform�ci�"};
const char *html_text_je[] = {"je", "je", "is", "est", "", "je", "van"};
const char *html_text_nie_je[] = {"nie je", "nen�", "is not", "non est", "", "nen�", "nincs"};
const char *html_text_prestupny[] = {"prestupn�", "p�estupn�", "...", "...", "", "p�estupn�", "�sszek�t�s"};
const char *html_text_datumy_pohyblivych_slaveni[] = {"D�tumy pohybliv�ch sl�ven�", "D�ta prom�nliv�ch sl�ven�", "Dates for movable celebrations", "", "", "Data prom�nliv�ch slaven�", "A mozg� �nnepek d�tumai"};

const char *html_text_den_v_roku[] = {"de� v roku", "den v roce", "day of the year", "", "", "den v roce", "az �v napja"};
const char *html_text_zacina[] = {"za��na", "za��n�", "starts", "", "", "za��n�", "kezd�dik"};
const char *html_text_liturgicky_rok[] = {"liturgick� rok", "liturgick� rok", "liturgical year", "", "", "liturgick� rok", "liturgikus �v"};

const char *html_text_pohyblive1[] = {
	"<td align=center>Rok<br>P�na</td>\n",
	"<td align=center>L�to<br>P�n�</td>\n", 
	"<td align=center>Anno<br>Domini</td>\n",
	"<td align=center>Anno<br>Domini</td>\n",
	"",
	"<td align=center>L�to<br>P�n�</td>\n",
	"hu_<td align=center>Anno<br>Domini</td>\n"
};

const char *html_text_pohyblive2[] = {
	"<td align=center>Nede�n�<br>litera</td>\n",
	"<td align=center>Ned�ln�<br>p�smeno</td>\n", 
	"<td align=center>Sunday<br>Letter</td>\n",
	"<td align=center>Let.<br>Dom.</td>\n",
	"",
	"<td align=center>Ned�ln�<br>p�smeno</td>\n",
	"hu_<td align=center>Sunday<br>Letter</td>\n"
};

const char *html_text_pohyblive3[] = {
	"<td align=center>Nede�n�<br>cyklus</td>\n",
	"<td align=center>Ned�ln�<br>cyklus</td>\n", 
	"<td align=center>Sunday<br>cycle</td>\n",
	"<td align=center>Cycl.<br>Dom.</td>\n",
	"",
	"<td align=center>Ned�ln�<br>cyklus</td>\n",
	"hu_<td align=center>Sunday<br>cycle</td>\n"
};

const char *html_text_pohyblive4[] = {
	"<td align=center>Krst Krista<br>P�na</td>\n",
	"<td align=center>K�est Krista<br>P�n�</td>\n", 
	"<td align=center>Bapt. of<br>the Lord</td>\n",
	"<td align=center>Bapt.<br>Domini</td>\n",
	"",
	"<td align=center>K�est Krista<br>P�n�</td>\n",
	"hu_<td align=center>Bapt.<br>Domini</td>\n"
};

const char *html_text_pohyblive5[] = {
	"<td align=center><a href=\"#explain\">OCR<br>pred<br>PO</a></td>\n",
	"<td align=center><a href=\"#explain\">OCR<br>p�ed<br>postem</a></td>\n", 
	"<td align=center>...</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center><a href=\"#explain\">OCR<br>p�ed<br>postem</a></td>\n",
	"hu_<td align=center>PA before Fast</td>\n"
};

const char *html_text_pohyblive6[] = {
	"<td align=center>Popolcov�<br>streda</td>\n",
	"<td align=center>Popele�n�<br>st�eda</td>\n", 
	"<td align=center>...</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center>Popele�n�<br>st�eda</td>\n",
	"hu_<td align=center>...</td>\n"
};

const char *html_text_pohyblive7[] = {
	"<td align=center>Ve�k�<br>noc</td>\n",
	"<td align=center>Veliko-<br>noce</td>\n", 
	"<td align=center>Easter</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center>Veliko-<br>noce</td>\n",
	"hu_<td align=center>...</td>\n"
};

const char *html_text_pohyblive8[] = {
	"<td align=center>Nanebo-<br>vst�penie<br>P�na</td>\n",
	"<td align=center>Nanebe-<br>vstoupen�<br>P�n�</td>\n", 
	"<td align=center>...</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center>Nanebe-<br>vstoupen�<br>P�n�</td>\n",
	"hu_<td align=center>...</td>\n"
};

const char *html_text_pohyblive9[] = {
	"<td align=center>Zoslanie<br>Ducha<br>Sv�t�ho</td>\n",
	"<td align=center>Sesl�n�<br>Ducha<br>Svat�ho</td>\n", 
	"<td align=center>...</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center>Sesl�n�<br>Ducha<br>Svat�ho</td>\n",
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
	"<td align=center>Prv�<br>adventn�<br>nede�a</td>\n",
	"<td align=center>Prvn�<br>adventn�<br>ned�le</td>\n", 
	"<td align=center>...</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center>Prvn�<br>adventn�<br>ned�le</td>\n",
	"hu_<td align=center>...</td>\n"
};

const char *html_text_pohyblive12[] = {
	"<td align=center>Nede�a Sv�tej<br>rodiny</td></tr>\n",
	"<td align=center>Ned�le Svat�<br>rodiny</td></tr>\n", 
	"<td align=center>...</td>\n",
	"<td align=center>...</td>\n",
	"",
	"<td align=center>Ned�le Svat�<br>rodiny</td></tr>\n",
	"hu_<td align=center>...</td>\n"
};

const char *html_text_Nedelne_pismeno[] = {"Nede�n� p�smeno", "Ned�ln� p�smeno", "Sunday letter", "", "", "Ned�ln� p�smeno", "hu_sunday-letter"};
const char *html_text_Nedelne_pismena[] = {"Nede�n� p�smen�", "Ned�ln� p�smena", "Sunday letters", "", "", "Ned�ln� p�smena", "hu_sunday-letters"};

const char *html_text_Od_prvej_adv_atd[] = {
	"Od prvej adventnej nedele v roku %d (%s) pokra�uje <a href=\"%s%s\">liturgick� rok</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"Od prvn� ned�le adventn� v roku %d (%s) pokra�uje <a href=\"%s%s\">liturgick� rok</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"From the 1st Advent Sunday in the year %d (%s) continues <a href=\"%s%s\">liturgical year</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"Od prvej adventnej nedele v roku %d (%s) pokra�uje <a href=\"%s%s\">liturgick� rok</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"",
	"Od prvn� ned�le adventn� v roce %d (%s) pokra�uje <a href=\"%s%s\">liturgick� rok</a> <"HTML_SPAN_BOLD">%c</span>.\n"
};

const char *html_text_Po_Velkej_noci_atd[] = {
	"Po Ve�kej noci nasleduje %d. %s v cezro�nom obdob�.\n",
	"Po Velikonoc�ch n�sleduje %d. %s v mezibdob�.\n",
	"After Easter follows %d. %s per annum.\n",
	"Po Ve�kej noci nasleduje %d. %s v obdob� �cez rok�.\n",
	"Po Ve�kej noci nasleduje %d. %s v obdob� �cez rok�.\n",
	"Po Velikonoc�ch n�sleduje %d. %s v mezibdob�.\n",
	"H�sv�t ut�n �vk�zi %d. %s k�vetkezik.\n",
};

const char *html_text_Prikazane_sviatky_v_roku[] = {
	"<p><"HTML_SPAN_RED">Prik�zan� sviatky v roku %s:</span>\n",
	"<p><"HTML_SPAN_RED">P�ik�zan� sv�tky v roce %s:</span>\n",
	"<p><"HTML_SPAN_RED">Obliged celebrations in the year %s:</span>\n",
	"<p><"HTML_SPAN_RED">Prik�zan� sviatky v roku %s:</span>\n",
	"<p><"HTML_SPAN_RED">Prik�zan� sviatky v roku %s:</span>\n",
	"<p><"HTML_SPAN_RED">P�ik�zan� sv�tky v roce %s:</span>\n",
	"<p><"HTML_SPAN_RED">%s k�telez� �nnepei:</span>\n",
};

const char *html_text_Jednotlive_mesiace_roku[] = {
	"<"HTML_SPAN_RED">Jednotliv� mesiace roku %s:</span>\n",
	"<"HTML_SPAN_RED">Jednotliv� m�s�ce v roce %s:</span>\n",
	"<"HTML_SPAN_RED">Individual months of the year %s:</span>\n",
	"<"HTML_SPAN_RED">Jednotliv� mesiace roku %s:</span>\n",
	"<"HTML_SPAN_RED">Jednotliv� mesiace roku %s:</span>\n",
	"<"HTML_SPAN_RED">Jednotliv� m�s�ce v roce %s:</span>\n",
	"hu_<"HTML_SPAN_RED">Individual months of the year %s:</span>\n",
};

const char *str_modl_cez_den_zalmy_zo_dna[POCET_JAZYKOV + 1] = 
	{"be�nej psalm�die", "b�n� psalmodie", "ordinary psalmody", "___", "", "b�n� psalmodie", "hu_ordinary-psalter"};
#define		STR_MODL_CEZ_DEN_ZALMY_ZO_DNA 	str_modl_cez_den_zalmy_zo_dna[_global_jazyk]

const char *str_modl_cez_den_doplnkova_psalmodia[POCET_JAZYKOV + 1] = 
	{"doplnkovej psalm�die", "dopl�kov� psalmodie", "supplementary psalmody", "psalmodia complementaris", "", "dopl�kov� psalmodie", "hu_suppl.-psalter"};
#define		STR_MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA 	str_modl_cez_den_doplnkova_psalmodia[_global_jazyk]

const char *str_modl_zalmy_zo_dna[POCET_JAZYKOV + 1] = 
	{"d�a", "dne", "day", "die", "", "dne", "napt�l"};
#define		STR_MODL_ZALMY_ZO_DNA 	str_modl_zalmy_zo_dna[_global_jazyk]

const char *str_modl_zalmy_zo_sv[POCET_JAZYKOV + 1] = 
	{"sviatku", "sv�tku", "celebration", "___", "", "sv�tku", "�nnept�l"};
#define		STR_MODL_ZALMY_ZO_SV 	str_modl_zalmy_zo_sv[_global_jazyk]

const char *str_ano[POCET_JAZYKOV + 1] = 
	{"�no", "ano", "yes", "___", "___", "ano", "igen"};
#define		STR_ANO		str_ano[_global_jazyk]

const char *str_nie[POCET_JAZYKOV + 1] = 
	{"nie", "ne", "no", "non", "___", "ne", "nem"};
#define		STR_NIE		str_nie[_global_jazyk]

const char *html_text_detaily_uvod[POCET_JAZYKOV + 1] = 
{"Nasledovn� mo�nosti ovplyvnia vzh�ad i obsah vygenerovanej modlitby.\nVyberte tie mo�nosti, pod�a ktor�ch sa m� modlitba vygenerova�.", 
 "N�sleduj�c� mo�nosti maj� vliv na vzhled i obsah vygenerovan� modlitby.\nVyberte si mo�nosti, podle kter�ch m� b�t modlitba vygenerov�na.", 
 "The following options apply to the resulting generated text of the prayer.\nChoose options which fit your needs to the resulting prayer text.", 
 "",
 "",
 "N�sleduj�c� mo�nosti maj� vliv na vzhled i obsah vygenerovan� modlitby.\nVyberte si mo�nosti, podle kter�ch m� b�t modlitba vygenerov�na.",
 "hu_ (we will translate it later)"
};

const char *html_text_nemenne_sucasti[] = 
{"zobrazi� <i>nemenn� s��asti</i> modlitby?", 
 "zobrazit <i>nem�nn� sou��sti</i> modlitby?", 
 "display <i>non-changeable parts</i> prayer?", 
 "", 
 "", 
 "zobrazit <i>nem�nn� sou��sti</i> modlitby?",
 "hu_ (we will translate it later)"
};

const char *html_text_nemenne_sucasti_explain[] = 
{"Ka�d� rann� chv�ly obsahuj� Benediktus, ve�pery Magnifikat, obe modlitby obsahuj� Ot�en� a zakon�enie modlitby, a napokon posv�tn� ��tanie obsahuje niekedy hymnus Te Deum; tieto �asti modlitby naz�vame <i>nemenn� s��asti</i>.", 
 "Ka�d� rann� chv�ly obsahuj� Zachari�ovo kantikum, ne�pory Mariin Magnifikat, ob� modlitbu P�n� a zakon�en� modlitby, a kone�n� modlitba se �ten�m n�kdy obsahuje hymnus Te Deum; tyto ��sti modliteb naz�v�me <i>nem�nn� sou��sti</i>.", 
 "Each morning prayer contains Benedictus, vesperae contains Magnificat, both contain the Lord's Prayer and a conclusion of the prayer; finally, the holy reading sometimes contains the Te Deum hymnus; all these parts we call <i>un-changeable parts</i>.", 
 "",
 "", 
 "Ka�d� rann� chv�ly obsahuj� Zachari�ovo kantikum, ve�ern� chv�ly kantikum Panny Marie, ob� modlitbu P�n� a zakon�en� modlitby, a kone�n� modlitba se �ten�m n�kdy obsahuje hymnus Te Deum; tyto ��sti modliteb naz�v�me <i>nem�nn� sou��sti</i>.",
 "hu_ (we will translate it later)"
};

const char *html_text_popis_svaty[] = 
{"zobrazi� <i>popis</i> k modlitbe sv�t�ho?", 
 "zobrazit <i>popis</i> p�i modlitb� ke cti sv�tce?", 
 "display <i>description</i> for prayer for the saints?", 
 "", 
 "", 
 "zobrazit <i>popis</i> p�i modlitb� ke cti sv�tce?",
 "hu_ (we will translate it later)"
};

const char *html_text_popis_svaty_explain[] = 
{"Modlitby zv��a obsahuj� pred n�zvom modlitby �ivotopis sv�t�ho, popis sviatku alebo podobn� stru�n� charakteristiku, ktor� pre jednoduchos� naz�vame <i>popis</i>.", 
 "Modlitby ke cti svat�ch obsahuj� stru�n� �ivotopis svat�ho, p�i sv�tku je to stru�n� popis sv�tku a podobn�. Tyto charakteristiky pro stru�nost naz�v�me <i>popis</i>.", 
 "xxx", 
 "",
 "", 
 "Modlitby ke cti svat�ch obsahuj� stru�n� �ivotopis svat�ho, u sv�tku je to stru�n� popis sv�tku a podobn�. Tyto charakteristiky pro stru�nost naz�v�me <i>popis</i>.",
 "hu_ (we will translate it later)"
};

const char *html_text_zalmy_brat_zo[] = 
{"�almy bra� zo ", 
 "�almy br�t ze ", 
 "take psalmody from ", 
 "", 
 "", 
 "�almy br�t ze ",
 "zsolt�rok a k�vetkez� helyr�l:"
};
const char *html_text_zalmy_brat_zo_okrem_mcd[] = 
{" (okrem modlitby cez de�)\n", 
 " (krom� modlitby p�es den)\n", 
 " (excluding the prayers during the day)\n", 
 "", 
 "", 
 " (krom� modlitby b�hem dne)\n",
 "hu_"
};
const char *html_text_zalmy_brat_zo_explain[] = 
{"V z�vislosti od typu sv�tenia sa ber� alebo neber� na sviatok sv�tca/sv�tice �almy a chv�lospevy z vlastnej �asti (na rann� chv�ly z nedele 1. t��d�a �alt�ra); je mo�n� tieto �almy vy�iada�.", 
 "V z�vislosti na typu slaven� sv�tku sv�tce/sv�tice se berou nebo neberou �almy a kantika z vlastn� ��sti (na rann� chv�ly z ned�le 1. t�dne �alt��e); je mo�no tyto �almy vy��dat.", 
 "xxx", 
 "",
 "", 
 "V z�vislosti na typu slaven� sv�tku sv�tce/sv�tice se berou nebo neberou �almy a kantika z vlastn� ��sti (na rann� chv�ly z ned�le 1. t�dne �alt��e); je mo�no tyto �almy vy��dat.",
 "hu_"
};

const char *html_text_spol_casti_vziat_zo[] = 
{"�asti modlitby zo spolo�nej �asti ", 
 "��sti modlitby ze spole�n� ��sti ", 
 "parts of prayer from the common part ", 
 "",
 "",
 "��sti modlitby ze spole�n� ��sti ",
 "a k�z�s r�szb�l"};
const char *html_text_spol_casti_vziat_zo_explain[] = 
{"Na sviatok sv�tca/sv�tice sa pod�a liturgick�ch pravidiel ber� �asti, ktor� sa nenach�dzaj� vo vlastnej �asti �alt�ra, zo spolo�nej �asti sviatku, niekedy je mo�nos� vybra� si z viacer�ch spolo�n�ch �ast�; naviac je mo�nos� modli� sa tieto �asti zo v�edn�ho d�a.", 
 "Na sv�tek ke cti sv�tce/sv�tice se podle liturgick�ch pravidel berou ��sti, kter� se nenach�z� ve vlastn�ch textech, ze spole�n�ch text�, n�kdy je mo�n� vybrat si z v�ce spole�n�ch text�; nav�c je mo�nost modlit se tyto ��sti ze v�edn�ho dne.", 
 "xxx", 
 "",
 "",
 "O sv�tku ke cti sv�tce/sv�tice se podle liturgick�ch pravidel berou ��sti, kter� se nenach�z� ve vlastn�ch textech, ze spole�n�ch text�, n�kdy je mo�n� vybrat si z v�ce spole�n�ch text�; nav�c je mo�nost modlit se tyto ��sti ze v�edn�ho dne.",
 "hu_"
};

const char *html_text_zalmy_pre_mcd[] = 
{"�almy pre modlitbu cez de� bra� z ", 
 "�almy pro modlitbu p�es den br�t ze ", 
 "take psalmody for the prayer during the day from ", 
 "",
 "",
 "�almy pro modlitbu b�hem dne br�t ze ",
 "hu_"
};
const char *html_text_zalmy_pre_mcd_explain[] = 
{"Doplnkov� psalm�dia zah��a 3 s�rie tzv. gradu�lnych �almov (� 120-129), ktor� mo�no bra� namiesto �almov zo �alt�ra.", 
 "Dopl�ovac� cyklus �alm� obsahuje 3 s�rie tzv. gradu�ln�ch �alm� (� 120-129), kter� je mo�no br�t m�sto �alm� ze �alt��e.", 
 "xxx", 
 "",
 "", 
 "Dopl�ovac� cyklus �alm� obsahuje 3 s�rie tzv. gradu�ln�ch �alm� (� 120-129), kter� je mo�no br�t m�sto �alm� ze �alt��e.",
 "hu_"
};

const char *html_text_detaily_explain[] = 
{"Pokia� s� niektor� parametre pre vybran� modlitbu nepou�ite�n�, neber� sa do �vahy (m��u by� teda nastaven� �ubovo�ne).", 
 "Kdy� jsou n�kter� v��e uveden� volby nepou�iteln� pro n�jakou modlitbu, neberou se v �vahu (mohou b�t nastaveny dle libov�le).", 
 "If any of described options are not applicable for a chosen prayer, they can be set anyhow.", 
 "",
 "", 
 "Kdy� jsou n�kter� v��e uveden� volby nepou�iteln� pro n�jakou modlitbu, neberou se v �vahu (mohou b�t nastaveny dle libov�le).",
 "hu_"
};

const char *text_DRUHA_NEDELA_PO_NAR_PANA[] = 
{"2. nede�a po Naroden� P�na",
 "2. ned�le po Narozen� P�n�",
 "",
 "",
 "",
 "2. ned�le po Narozen� P�n�",
 "hu_",
 };
const char *text_JAN_01[] = 
{"Panny M�rie Bohorodi�ky",
 "Matky Bo��, Panny Marie",
 "",
 "Sanctae Dei Genetricis Mariae",
 "",
 "Matky Bo��, Panny Marie",
 "Sz�z M�ria, Isten Anyja",
 };
const char *text_JAN_02[] = 
{"Sv. Bazila Ve�k�ho a Gregora Naziansk�ho, biskupov a u�ite�ov Cirkvi",
 "Sv. Basila Velik�ho a �eho�e Nazi�nsk�ho, biskup� a u�itel� c�rkve",
 "",
 "Ss. Basilii Magni et Gregorii Nazianzeni, ep. et Eccl. doct.",
 "",
 "Sv. Basila Velik�ho a �eho�e Nazi�nsk�ho, biskup� a u�itel� C�rkve",
 "Nagy Szent Vazul �s Nazianzi Szent Gergely p�sp�k�k �s egyh�ztan�t�k",
 };
const char *text_JAN_03[] = 
{"(nie je)",
 "(nen�)",
 "",
 "",
 "",
 "Nejsv�t�j��ho Jm�na Je�� ",
 "(nincs Magyarorsz�gon)",
 };
const char *text_JAN_06[] = 
{"Zjavenie P�na",
 "Zjeven� P�n�",
 "",
 "In Epiphania Domini",
 "",
 "Zjeven� P�n�",
 "Urunk Megjelen�se",
 };
const char *text_JAN_07[] = 
{"Sv. Rajmunda z Pe�afortu, k�aza",
 "Sv. Rajmunda z Penafortu, kn�ze",
 "",
 "S. Raimundi de Penyafort, presb.",
 "",
 "Sv. Rajmunda z Penafortu, kn�ze",
 "Penyaforti Szent Rajmund �ldoz�pap",
 };
const char *text_JAN_KRST[] = 
{"Krst Krista P�na",
 "K�tu P�n�",
 "",
 "In Baptismate Domini",
 "",
 "K�tu P�n�",
 "Urunk Megkeresztelked�se",
 };
const char *text_JAN_13[] = 
{"Sv. Hil�ra, biskupa a u�ite�a Cirkvi",
 "Sv. Hilaria, biskupa a u�itele c�rkve",
 "",
 "S. Hilarii, ep. et Eccl. doct.",
 "",
 "Sv. Hilaria, biskupa a u�itele C�rkve",
 "Szent Hil�riusz (Vidor) p�sp�k �s egyh�ztan�t�",
 };
const char *text_JAN_17[] = 
{"Sv. Antona, op�ta",
 "Sv. Anton�na, opata",
 "",
 "S. Antonii, abbatis",
 "",
 "Sv. Anton�na, opata",
 "Szent Antal ap�t",
 };
const char *text_JAN_18[] = 
{"(na Slovensku nie je)",
 "Panny Marie, Matky jednoty k�es�an�",
 "",
 "(non est in Latina)",
 "",
 "Panny Marie, Matky jednoty k�es�an�",
 "(nincs Magyarorsz�gon)",
 };
const char *text_JAN_20_1[] = 
{"Sv. Fabi�na, p�pe�a a mu�en�ka",
 "Sv. Fabi�na, pape�e a mu�edn�ka",
 "",
 "S. Fabiani, papae et mart.",
 "",
 "Sv. Fabi�na, pape�e a mu�edn�ka",
 "Szent F�bi�n p�pa �v v�rtan�",
 };
const char *text_JAN_20_2[] = 
{"Sv. �ebasti�na, mu�en�ka",
 "Sv. �ebesti�na, mu�edn�ka",
 "",
 "S. Sebastiani, mart.",
 "",
 "Sv. �ebesti�na, mu�edn�ka",
 "Szent Sebesty�n v�rtan�",
 };
const char *text_JAN_21[] = 
{"Sv. Agnesy, panny a mu�enice",
 "Sv. Ane�ky, panny a mu�ednice",
 "",
 "S. Agnetis, virg. et mart.",
 "",
 "Sv. Ane�ky, panny a mu�ednice",
 "Szent �gnes sz�z �s v�rtan�",
 };
const char *text_JAN_22[] = 
{"Sv. Vincenta, diakona a mu�en�ka",
 "Sv. Vincence, j�hna a mu�edn�ka",
 "",
 "S. Vincentii, diaconi et mart.",
 "",
 "Sv. Vincence, j�hna a mu�edn�ka",
 "Szent Vince diak�nus �s v�rtan�",
 };
const char *text_JAN_23[] = 
{"Sv. J�na Almu�n�ka, biskupa",
 "(v �ech�ch, na Morav� a ve Slezsku nen�)",
 "",
 "(non est in Latina)",
 "",
 "hu_name",
 "(nincs Magyarorsz�gon)",
 };
const char *text_JAN_24[] = 
{"Sv. Franti�ka Salesk�ho, biskupa a u�ite�a Cirkvi",
 "Sv. Franti�ka Salesk�ho, biskupa a u�itele c�rkve",
 "",
 "S. Francisci de Sales, ep. et Eccl. doct.",
 "",
 "Sv. Franti�ka Salesk�ho, biskupa a u�itele C�rkve",
 "Szal�zi Szent Ferenc p�sp�k �s egyh�ztan�t�",
 };
const char *text_JAN_25[] = 
{"Obr�tenie sv�t�ho Pavla, apo�tola",
 "Obr�cen� svat�ho Pavla, apo�tola",
 "",
 "In Conversione S. Pauli, Apostoli",
 "",
 "Obr�cen� svat�ho Pavla, apo�tola",
 "Szent P�l apostol megt�r�se (P�l fordul�sa)",
 };
const char *text_JAN_26[] = 
{"Sv. Timoteja a T�ta, biskupov",
 "Sv. Timoteje a Tita, biskup�",
 "",
 "Ss. Timothei et Titi, ep.",
 "",
 "Sv. Timoteje a Tita, biskup�",
 "Szent Tim�teus �s Szent Titusz p�sp�k�k",
 };
const char *text_JAN_27[] = 
{"Sv. Angely Merici, panny",
 "Sv. And�ly Mericiov�, panny",
 "",
 "S. Angelae Merici, virg.",
 "",
 "Sv. And�ly Mericiov�, panny",
 "Merici Szent Ang�la sz�z",
 };
const char *text_JAN_28[] = 
{"Sv. Tom�a Akvinsk�ho, k�aza a u�ite�a Cirkvi",
 "Sv. Tom�e Akvinsk�ho, kn�ze a u�itele c�rkve",
 "",
 "S. Thomae de Aquino, presb. et Eccl. doct.",
 "",
 "Sv. Tom�e Akvinsk�ho, kn�ze a u�itele C�rkve",
 "Aquin�i Szent Tam�s �ldoz�pap �s egyh�ztan�t�",
 };
const char *text_JAN_31[] = 
{"Sv. J�na Boska, k�aza",
 "Sv. Jana Boska, kn�ze",
 "",
 "S. Ioannis Bosco, presb.",
 "",
 "Sv. Jana Boska, kn�ze",
 "Bosco Szent J�nos",
 };
const char *text_FEB_02[] = 
{"Obetovanie P�na",
 "Uveden� P�n� do chr�mu",
 "",
 "In Praesentatione Domini",
 "",
 "Uveden� P�n� do chr�mu",
 "Urunk bemutat�sa (Gyertyaszentel� Boldogasszony)",
 };
const char *text_FEB_03_1[] = 
{"Sv. Bla�eja, biskupa a mu�en�ka",
 "Sv. Bla�eje, biskupa a mu�edn�ka",
 "",
 "S. Blasii, ep. et mart.",
 "",
 "Sv. Bla�eje, biskupa a mu�edn�ka",
 "Szent Bal�zs p�sp�k �s v�rtan�",
 };
const char *text_FEB_03_2[] = 
{"Sv. Osk�ra, biskupa",
 "Sv. Ansgara, biskupa",
 "",
 "S. Ansgarii, ep.",
 "",
 "Sv. Ansgara, biskupa",
 "Szent Anszg�r (Oszk�r) p�sp�k",
 };
const char *text_FEB_05[] = 
{"Sv. Agaty, panny a mu�enice",
 "Sv. Ag�ty, panny a mu�ednice",
 "",
 "S.  Agathae, virg. et mart.",
 "",
 "Sv. Ag�ty, panny a mu�ednice",
 "Szent �gota sz�z �s v�rtan�",
 };
const char *text_FEB_06[] = 
{"Sv. Pavla Mikiho a spolo�n�kov, mu�en�kov",
 "Sv. Pavla Mikiho a druh�, mu�edn�k�",
 "",
 "Ss.  Pauli Miki et sociorum, mart.",
 "",
 "Sv. Pavla Mikiho a druh�, mu�edn�k�",
 "Miki Szent P�l �s t�rsai v�rtan�k",
 };
const char *text_FEB_08[] = 
{"Sv. Hieronyma Emilianiho",
 "Sv. Jeron�ma Emilianiho",
 "",
 "S. Hieronymi Emiliani",
 "",
 "Sv. Jeron�ma Emilianiho",
 "Emili�ni Szent Jeromos",
 };
const char *text_FEB_08_2[] = 
{"Sv. Jozef�ny Bakhita, panny",
 "Sv. Josef�ny Bakhity, panny",
 "",
 "",
 "",
 "Sv. Josef�ny Bakhity, panny",
 "(nincs Magyarorsz�gon)",
 };
const char *text_FEB_10[] = 
{"Sv. �kolastiky, panny",
 "Sv. Scholastiky, panny",
 "",
 "S.  Scholasticae, virg.",
 "",
 "Sv. Scholastiky, panny",
 "Szent Skolasztika sz�z",
 };
const char *text_FEB_11[] = 
{"Prebl. Panny M�rie Lurdskej",
 "Panny Marie Lurdsk�",
 "",
 "B. Mariae Virg. de Lourdes",
 "",
 "Panny Marie Lurdsk�",
 "A Lourdes-i Boldogs�gos Sz�z M�ria",
 };
const char *text_FEB_14[] = 
{"(na Slovensku sa sl�vi 5. j�la)",
 "(slav� se 5. �ervna)",
 "",
 "Ss. Cyrilli, monachi, et Methodii, ep.",
 "",
 "hu_name",
 "Szent Cirill szerzetes �s Szent Met�d p�sp�k, Eur�pa t�rsv�d�szentjei",
 };
const char *text_FEB_17[] = 
{"Siedmich sv�t�ch zakladate�ov rehole Slu�obn�kov Panny M�rie",
 "Sv. Alexia a druh�, �eholn�k�",
 "",
 "Ss. Septem Fundatorum Ordinis Servorum B. Mariae Virg.",
 "",
 "Sv. Alexia a druh�, �eholn�k�",
 "A szervita rend h�t szent alap�t�ja",
 };
const char *text_FEB_21[] = 
{"Sv. Petra Damianiho, biskupa a u�ite�a Cirkvi",
 "Sv. Petra Damianiho, biskupa a u�itele c�rkve",
 "",
 "S. Petri Damiani, ep. et Eccl. doct.",
 "",
 "Sv. Petra Damianiho, biskupa a u�itele C�rkve",
 "Dami�ni Szent P�ter p�sp�k �s egyh�ztan�t�",
 };
const char *text_FEB_22[] = 
{"Katedra sv. Petra, apo�tola",
 "Stolce svat�ho Petra, apo�tola",
 "",
 "Cathedrae S. Petri, Apostoli",
 "",
 "Stolce svat�ho Petra, apo�tola",
 "Szent P�ter apostol sz�kfoglal�sa",
 };
const char *text_FEB_23[] = 
{"Sv. Polykarpa, biskupa a mu�en�ka",
 "Sv. Polykarpa, biskupa a mu�edn�ka",
 "",
 "S. Polycarpi, ep. et mart.",
 "",
 "Sv. Polykarpa, biskupa a mu�edn�ka",
 "Szent Polik�rp p�sp�k �s v�rtan�",
 };
const char *text_POPOLCOVA_STREDA[] = 
{"Popolcov� streda",
 "Popele�n� st�eda",
 "",
 "",
 "",
 "Popele�n� st�eda",
 "hu_name",
 };
const char *text_MAR_04[] = 
{"Sv. Kazim�ra",
 "Sv. Kazim�ra",
 "",
 "S. Casimiri",
 "",
 "Sv. Kazim�ra",
 "Szent K�zm�r",
 };
const char *text_MAR_07[] = 
{"Sv. Perpetuy a Felicity, mu�en�c",
 "Sv. Perpetuy a Felicity, mu�ednic",
 "",
 "Ss.   Perpetuae et  Felicitatis, mart.",
 "",
 "Sv. Perpetuy a Felicity, mu�ednic",
 "Szent Perp�tua �s Felicit�sz v�rtan�k",
 };
const char *text_MAR_08[] = 
{"Sv. J�na z Boha, reho�n�ka",
 "Sv. Jana z Boha, �eholn�ka",
 "",
 "S. Ioannis a Deo, relig.",
 "",
 "Sv. Jana z Boha, �eholn�ka",
 "Istenes Szent J�nos szerzetes",
 };
const char *text_MAR_09[] = 
{"Sv. Franti�ky R�mskej, reho�n��ky",
 "Sv. Franti�ky ��msk�, �eholnice",
 "",
 "S. Franciscae Romanae, relig.",
 "",
 "Sv. Franti�ky ��msk�, �eholnice",
 "R�mai Szent Franciska szerzetesn�",
 };
const char *text_MAR_10[] = 
{"(na Slovensku nie je)",
 "Sv. Jana Ogilvie, kn�ze a mu�edn�ka",
 "",
 "(non est in Latina)",
 "",
 "Sv. Jana Ogilvie, kn�ze a mu�edn�ka",
 "(nincs Magyarorsz�gon)",
 };
const char *text_MAR_17[] = 
{"Sv. Patrika, biskupa",
 "Sv. Patrika, biskupa",
 "",
 "S. Patricii, ep.",
 "",
 "Sv. Patrika, biskupa",
 "Szent Patrik p�sp�k",
 };
const char *text_MAR_18[] = 
{"Sv. Cyrila Jeruzalemsk�ho, biskupa a u�ite�a Cirkvi",
 "Sv. Cyrila Jeruzal�msk�ho, biskupa a u�itele c�rkve",
 "",
 "S. Cyrilli Hierosolymitani, ep. et Eccl. doct.",
 "",
 "Sv. Cyrila Jeruzal�msk�ho, biskupa a u�itele C�rkve",
 "Jeruzs�lemi Szent Cirill p�sp�k �s egyh�ztan�t�",
 };
const char *text_MAR_19[] = 
{"Sv. Jozefa, �en�cha Panny M�rie",
 "Sv. Josefa, Snoubence Panny Marie",
 "",
 "S. Ioseph, Sponsi B. Mariae V.",
 "",
 "Sv. Josefa, Snoubence Panny Marie",
 "Szent J�zsef, a Boldogs�gos Sz�z M�ria jegyese",
 };
const char *text_MAR_23[] = 
{"Sv. Turibia de Mongrovejo, biskupa",
 "Sv. Turibia z Mongroveja, biskupa",
 "",
 "S. Turibii de Mogrovejo, ep.",
 "",
 "Sv. Turibia z Mongroveja, biskupa",
 "Mongrovej�i Szent Turibiusz p�sp�k",
 };
const char *text_MAR_25[] = 
{"Zvestovanie P�na",
 "Zv�stov�n� P�n�",
 "",
 "In Annuntiatione Domini",
 "",
 "Zv�stov�n� P�n�",
 "Urunk sz�let�s�nek h�r�lad�sa (Gy�m�lcsolt� Boldogasszony)",
 };
const char *text_APR_02[] = 
{"Sv. Franti�ka z Pauly, pustovn�ka",
 "Sv. Franti�ka z Pauly, poustevn�ka",
 "",
 "S. Francisci de Paola, eremitai",
 "",
 "Sv. Franti�ka z Pauly, poustevn�ka",
 "Paolai Szent Ferenc remete",
 };
const char *text_APR_04[] = 
{"Sv. Izidora, biskupa a u�ite�a Cirkvi",
 "Sv. Izidora, biskupa a u�itele c�rkve",
 "",
 "S. Isidori, ep. et Eccl. doct.",
 "",
 "Sv. Izidora, biskupa a u�itele C�rkve",
 "Szent Izidor p�sp�k �s egyh�ztan�t�",
 };
const char *text_APR_05[] = 
{"Sv. Vincenta Ferrera, k�aza",
 "Sv. Vincence Ferrersk�ho, kn�ze",
 "",
 "S.  Vincentii Ferrer, presb.",
 "",
 "Sv. Vincence Ferrersk�ho, kn�ze",
 "Ferrer Szent Vince �ldoz�pap",
 };
const char *text_APR_07[] = 
{"Sv. J�na Krstite�a de la Salle, k�aza",
 "Sv. Jana K�titele de la Salle, kn�ze",
 "",
 "S.  Ioannis Baptistae de la Salle, presb.",
 "",
 "Sv. Jana K�titele de la Salle, kn�ze",
 "De la Salle Szent J�nos �ldoz�pap",
 };
const char *text_APR_11[] = 
{"Sv. Stanislava, biskupa a mu�en�ka",
 "Sv. Stanislava, biskupa a mu�edn�ka",
 "",
 "S.  Stanislai, ep.  et mart.",
 "",
 "Sv. Stanislava, biskupa a mu�edn�ka",
 "Szent Szaniszl� p�sp�k �s v�rtan�",
 };
const char *text_APR_13[] = 
{"Sv. Martina I., p�pe�a a mu�en�ka",
 "Sv. Martina I., pape�e a mu�edn�ka",
 "",
 "S. Martini I, papae et mart.",
 "",
 "Sv. Martina I., pape�e a mu�edn�ka",
 "Szent I. M�rton p�pa �s v�rtan�",
 };
const char *text_APR_21[] = 
{"Sv. Anzelma, biskupa a u�ite�a Cirkvi",
 "Sv. Anselma, biskupa a u�itele c�rkve",
 "",
 "S. Anselmi, ep. et Eccl. doct.",
 "",
 "Sv. Anselma, biskupa a u�itele C�rkve",
 "Szent Anzelm p�sp�k �s egyh�ztan�t�",
 };
const char *text_APR_23[] = 
{"Sv. Vojtecha, biskupa a mu�en�ka",
 "Sv. Vojt�cha, biskupa a mu�edn�ka",
 "",
 "S. Adalberti, ep. et mart.",
 "",
 "Sv. Vojt�cha, biskupa a mu�edn�ka",
 "Szent Adalbert (B�la) p�sp�k �s v�rtan�",
 };
const char *text_APR_24_1[] = 
{"Sv. Juraja, mu�en�ka",
 "Sv. Ji��, mu�edn�ka",
 "",
 "S. Georgii, mart.",
 "",
 "Sv. Ji��, mu�edn�ka",
 "Szent Gy�rgy v�rtan�",
 };
const char *text_APR_24_2[] = 
{"Sv. Fid�la zo Sigmaringenu, k�aza a mu�en�ka",
 "Sv. Fidela ze Sigmaringy, kn�ze a mu�edn�ka",
 "",
 "S. Fidelis a Sigmaringen, presb. et mart.",
 "",
 "Sv. Fidela ze Sigmaringy, kn�ze a mu�edn�ka",
 "Sigmaringeni Szent Fid�l �ldoz�pap �s v�rtan�",
 };
const char *text_APR_25[] = 
{"Sv. Marka, evanjelistu",
 "Sv. Marka, evangelisty",
 "",
 "S. Marci, evangelistae",
 "",
 "Sv. Marka, evangelisty",
 "Szent M�rk evangelista",
 };
const char *text_APR_28_1[] = 
{"Sv. Petra Chanela, k�aza a mu�en�ka",
 "Sv. Petra Chanela, kn�ze a mu�edn�ka",
 "",
 "S. Petri Chanel, presb. et mart.",
 "",
 "Sv. Petra Chanela, kn�ze a mu�edn�ka",
 "Chanel Szent P�ter �ldoz�pap �s v�rtan�",
 };
const char *text_APR_28_2[] = 
{"Sv. �udov�ta M�rie Grignion de Montfort, k�aza",
 "Sv. Ludv�ka Marie Grignona z Montfortu, kn�ze",
 "",
 "S. Ludovici M. Grignion de Montfort, presb.",
 "",
 "Sv. Ludv�ka Marie Grignona z Montfortu, kn�ze",
 "(nincs Magyarorsz�gon)",
 };
const char *text_APR_29[] = 
{"Sv. Katar�ny Sienskej, panny a u�ite�ky Cirkvi, spolupatr�nky Eur�py",
 "Sv. Kate�iny Siensk�, panny a u�itelky c�rkve, spolupatronky Evropy",
 "",
 "S. Catharinae Senensis, virg. et Eccl. doct.",
 "",
 "Sv. Kate�iny Siensk�, panny a u�itelky C�rkve, spolupatronky Evropy",
 "Sienai Szent Katalin sz�z �s egyh�ztan�t�",
 };
const char *text_APR_30_1[] = 
{"Sv. Pia V., p�pe�a",
 "Sv. Pia V., pape�e",
 "",
 "S. Pii V, papae",
 "",
 "Sv. Pia V., pape�e",
 "Szent V. Piusz p�pa",
 };
const char *text_APR_30_2[] = 
{"(na Slovensku nie je)",
 "Sv. Zikmunda, mu�edn�ka",
 "",
 "(non est in Latina)",
 "",
 "Sv. Zikmunda, mu�edn�ka",
 "(nincs Magyarorsz�gon)",
 };
const char *text_MAJ_01[] = 
{"Sv. Jozefa, robotn�ka",
 "Sv. Josefa, D�ln�ka",
 "",
 "S. loseph Opificis",
 "",
 "Sv. Josefa, D�ln�ka",
 "Munk�s Szent J�zsef",
 };
const char *text_MAJ_02[] = 
{"Sv. Atan�za, biskupa a u�ite�a Cirkvi",
 "Sv. Atan�e, biskupa a u�itele c�rkve",
 "",
 "S. Athanasii, ep. et Eccl. doct.",
 "",
 "Sv. Atan�e, biskupa a u�itele C�rkve",
 "Szent Atan�z p�sp�k �s egyh�ztan�t�",
 };
const char *text_MAJ_03[] = 
{"Sv. Filipa a Jakuba, apo�tolov",
 "Sv. Filipa a Jakuba, apo�tol�",
 "",
 "Ss. Philippi et Iacobi, apostolorum",
 "",
 "Sv. Filipa a Jakuba, apo�tol�",
 "Szent F�l�p �s Szent Jakab apostol",
 };
const char *text_MAJ_06[] = 
{"(na Slovensku nie je)",
 "Sv. Jana Sarkandra, kn�ze a mu�edn�ka",
 "",
 "(non est in Latina)",
 "",
 "Sv. Jana Sarkandra, kn�ze a mu�edn�ka",
 "(nincs Magyarorsz�gon)",
 };
const char *text_MAJ_08[] = 
{"(na Slovensku nie je)",
 "Panny Marie, Prost�ednice v�ech milost�",
 "",
 "(non est in Latina)",
 "",
 "Panny Marie, Prost�ednice v�ech milost�",
 "(nincs Magyarorsz�gon)",
 };
const char *text_MAJ_12_1[] = 
{"Sv. Nerea a Achila, mu�en�kov",
 "Sv. Nerea a Achillea, mu�edn�k�",
 "",
 "Ss. Nerei et Achillei, mart.",
 "",
 "Sv. Nerea a Achillea, mu�edn�k�",
 "Szent N�reusz �s Szent Achilleusz v�rtan�k",
 };
const char *text_MAJ_12_2[] = 
{"Sv. Pankr�ca, mu�en�ka",
 "Sv. Pankr�ce, mu�edn�ka",
 "",
 "S. Pancratii, mart.",
 "",
 "Sv. Pankr�ce, mu�edn�ka",
 "Szent Pongr�c v�rtan�",
 };
const char *text_MAJ_12_3[] = 
{"(na Slovensku nie je)",
 "V�ro�� posv�cen� katedr�ly sv. V�ta",
 "",
 "(non est in Latina)",
 "",
 "V�ro�� posv�cen� katedr�ly sv. V�ta",
 "(nincs Magyarorsz�gon)",
 };
const char *text_MAJ_13[] = 
{"Panny M�rie Fatimskej",
 "Panny Marie Fatimsk�",
 "",
 "",
 "",
 "Panny Marie Fatimsk�",
 "(nincs Magyarorsz�gon)",
 };
const char *text_MAJ_14[] = 
{"Sv. Mateja, apo�tola",
 "Sv. Mat�je, apo�tola",
 "",
 "S. Matthiae, apostoli",
 "",
 "Sv. Mat�je, apo�tola",
 "(nincs Magyarorsz�gon)",
 };
const char *text_MAJ_16[] = 
{"Sv. J�na Nepomuck�ho, k�aza a mu�en�ka",
 "Sv. Jana Nepomuck�ho, kn�ze a mu�edn�ka, hlavn�ho patrona �ech",
 "",
 "(non est in Latina)",
 "",
 "Sv. Jana Nepomuck�ho, kn�ze a mu�edn�ka, hlavn�ho patrona �ech",
 "Nepomuki Szent J�nos �ldoz�pap �s v�rtan�",
 };
const char *text_MAJ_18[] = 
{"Sv. J�na I., p�pe�a a mu�en�ka",
 "Sv. Jana I., pape�e a mu�edn�ka",
 "",
 "S. Ioannis I, papae et mart.",
 "",
 "Sv. Jana I., pape�e a mu�edn�ka",
 "Szent I. J�nos p�pa �s v�rtan�",
 };
const char *text_MAJ_20_1[] = 
{"(na Slovensku nie je)",
 "Sv. Klementa Marie Hofbauera, kn�ze",
 "",
 "",
 "",
 "Sv. Klementa Marie Hofbauera, kn�ze",
 "(nincs Magyarorsz�gon)",
 };
const char *text_MAJ_20_2[] = 
{"Sv. Bernard�na Siensk�ho, k�aza",
 "Sv. Bernardina Siensk�ho, kn�ze",
 "",
 "S. Bernardini Senensis, presb.",
 "",
 "Sv. Bernardina Siensk�ho, kn�ze",
 "Sienai Szent Bernardin �ldoz�pap",
 };
const char *text_MAJ_21[] = 
{"(na Slovensku nie je)",
 "V�ro�� posv�cen� katedr�ly sv. Petra a Pavla",
 "",
 "(non est in Latina)",
 "",
 "V�ro�� posv�cen� katedr�ly sv. Petra a Pavla",
 "(nincs Magyarorsz�gon)",
 };
const char *text_MAJ_22[] = 
{"(na Slovensku nie je)",
 "Sv. Rity z Cascie, �eholnice",
 "",
 "(non est in Latina)",
 "",
 "Sv. Rity z Cascie, �eholnice",
 "Szent Rita �zvegy",
 };
const char *text_MAJ_25_1[] = 
{"Sv. B�du Ctihodn�ho, k�aza a u�ite�a Cirkvi",
 "Sv. Bedy Ctihodn�ho, kn�ze a u�itele c�rkve",
 "",
 "S. Bedae Venerdbilis, presb. et Ecci. doct.",
 "",
 "Sv. Bedy Ctihodn�ho, kn�ze a u�itele C�rkve",
 "Tiszteletrem�lt� Szent B�da �ldoz�pap �s egyh�ztan�t�",
 };
const char *text_MAJ_25_2[] = 
{"Sv. Gregora VII., p�pe�a",
 "Sv. �eho�e VII., pape�e",
 "",
 "S. Gregorii VII, papae",
 "",
 "Sv. �eho�e VII., pape�e",
 "Szent VII. Gergely p�pa",
 };
const char *text_MAJ_25_3[] = 
{"Sv. M�rie Magdal�ny de Pazzi, panny",
 "Sv. Marie Magdal�ny de Pazzi, panny",
 "",
 "S. Mariae Magdalenae de Pazzi, virg.",
 "",
 "Sv. Marie Magdal�ny de Pazzi, panny",
 "Pazzi Szent M�ria Magdolna Sz�z",
 };
const char *text_MAJ_26[] = 
{"Sv. Filipa Neriho, k�aza",
 "Sv. Filipa Neriho, kn�ze",
 "",
 "S. Philippi Neri, presb.",
 "",
 "Sv. Filipa Neriho, kn�ze",
 "N�ri Szent F�l�p �ldoz�pap",
 };
const char *text_MAJ_27[] = 
{"Sv. August�na z Canterbury, biskupa",
 "Sv. Augustina z Canterbury, biskupa",
 "",
 "S. Augustini Cantuariensis, ep.",
 "",
 "Sv. Augustina z Canterbury, biskupa",
 "Canterbury Szent �goston p�sp�k",
 };
const char *text_MAJ_30[] = 
{"(na Slovensku nie je)",
 "Sv. Zdislavy",
 "",
 "(non est in Latina)",
 "",
 "Sv. Zdislavy",
 "(nincs Magyarorsz�gon)",
 };
const char *text_MAJ_31[] = 
{"Nav�t�venie prebl. Panny M�rie",
 "Nav�t�ven� Panny Marie",
 "",
 "",
 "",
 "Nav�t�ven� Panny Marie",
 "(nincs Magyarorsz�gon)",
 };
const char *text_NANEBOVSTUPENIE_PANA[] = 
{"Nanebovst�penie P�na",
 "Nanebevstoupen� P�n�",
 "",
 "",
 "",
 "Nanebevstoupen� P�n�",
 "hu_name",
 };
const char *text_VELKONOCNA_NEDELA[] = 
{"Ve�kono�n� nede�a",
 "Ned�le Zmrtv�chvst�n� P�n�",
 "",
 "",
 "",
 "Ned�le Zmrtv�chvst�n� P�n�",
 "hu_name",
 };
const char *text_NEDELA_PANOVHO_ZMRTVYCHVSTANIA[] = 
{" - Nede�a P�novho zm�tvychvstania",
 "",
 "",
 "",
 "",
 "(pro dominik�ny nen�)",
 "hu_name",
 };
const char *text_NEDELA_VO_VELKONOCNEJ_OKTAVE[] = 
{"Nede�a vo Ve�kono�nej okt�ve",
 "Ned�le v okt�vu velikono�n�m",
 "",
 "",
 "",
 "Ned�le v okt�vu velikono�n�m",
 "hu_name",
 };
const char *text_DEN_VO_VELKONOCNEJ_OKTAVE[] = 
{"Ve�kono�n%c %s",
 "%s velikono�n�",
 "",
 "",
 "",
 "%s velikono�n�",
 "hu_name",
 };
const char *text_NAJSVATEJSEJ_TROJICE[] = 
{"Najsv�tej�ej Trojice",
 "Nejsv�t�j�� Trojice",
 "",
 "",
 "",
 "Nejsv�t�j�� Trojice",
 "hu_name",
 };
const char *text_KRISTA_KRALA[] = 
{"Krista Kr�a",
 "Je��e Krista Kr�le",
 "",
 "",
 "",
 "Je��e Krista Kr�le",
 "hu_name",
 };
const char *text_NAJSV_KRISTOVHO_TELA_A_KRVI[] = 
{"Najsv�tej�ieho Kristovho tela a krvi",
 "T�la a krve P�n�",
 "",
 "",
 "",
 "T�la a krve P�n�",
 "hu_name",
 };
const char *text_NAJSV_SRDCA_JEZISOVHO[] = 
{"Najsv�tej�ieho Srdca Je�i�ovho",
 "Nejsv�t�j��ho Srdce Je��ova",
 "",
 "",
 "",
 "Nejsv�t�j��ho Srdce Je��ova",
 "hu_name",
 };
const char *text_NEPOSKVRNENEHO_SRDCA_PM[] = 
{"Nepo�kvrnen�ho Srdca prebl. Panny M�rie",
 "Neposkvrn�n�ho Srdce Panny Marie",
 "",
 "",
 "",
 "Neposkvrn�n�ho Srdce Panny Marie",
 "hu_name",
 };
const char *text_NARODENIE_PANA[] = 
{"Narodenie P�na",
 "Narozen� P�n�",
 "",
 "",
 "",
 "Narozen� P�n�",
 "hu_name",
 };
const char *text_ZOSLANIE_DUCHA_SVATEHO[] = 
{"Zoslanie Ducha Sv�t�ho",
 "Sesl�n� Ducha svat�ho",
 "",
 "",
 "",
 "Sesl�n� Ducha Svat�ho",
 "hu_name",
 };
const char *text_PRVA_ADVENTNA_NEDELA[] = 
{"Prv� adventn� nede�a",
 "Prvn� ned�le adventn�",
 "",
 "",
 "",
 "Prvn� ned�le adventn�",
 "hu_name",
 };
const char *text_NEDELA_SV_RODINY[] = 
{"Sv�tej rodiny Je�i�a, M�rie a Jozefa",
 "Sv. Rodiny Je��e, Marie a Josefa",
 "",
 "",
 "",
 "Sv. Rodiny Je��e, Marie a Josefa",
 "hu_name",
 };
const char *text_SPOMIENKA_PM_V_SOBOTU[] = 
{"Spomienka Panny M�rie v sobotu",
 "Sobotn� pam�tka Panny Marie",
 "()",
 "Memoria S. Mariae in sabbato",
 "",
 "Sobotn� pam�tka Panny Marie",
 "hu_name",
 };
const char *text_JUN_01[] = 
{"Sv. Just�na, mu�en�ka",
 "Sv. Justina, mu�edn�ka",
 "",
 "",
 "",
 "Sv. Justina, mu�edn�ka",
 "Szent Juszt�nusz v�rtan�",
 };
const char *text_JUN_02[] = 
{"Sv. Marcel�na a Petra, mu�en�kov",
 "Sv. Marcelina a Petra, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Marcelina a Petra, mu�edn�k�",
 "Szent Marcell�nusz �s Szent P�ter v�rtan�k",
 };
const char *text_JUN_03[] = 
{"Sv. Karola Lwangu a spolo�n�kov, mu�en�kov",
 "Sv. Karla Lwangy a druh�, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Karla Lwangy a druh�, mu�edn�k�",
 "Lwanga Szent K�roly �s t�rsai, v�rtan�k",
 };
const char *text_JUN_05[] = 
{"Sv. Bonif�ca, biskupa a mu�en�ka",
 "Sv. Bonif�ce, biskupa a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Bonif�ce, biskupa a mu�edn�ka",
 "Szent Bonif�c p�sp�k �s v�rtan�",
 };
const char *text_JUN_06[] = 
{"Sv. Norberta, biskupa",
 "Sv. Norberta, biskupa",
 "",
 "",
 "",
 "Sv. Norberta, biskupa",
 "Szent Norbert p�sp�k",
 };
const char *text_JUN_09[] = 
{"Sv. Efr�ma, diakona a u�ite�a Cirkvi",
 "Sv. Efr�ma Syrsk�ho, j�hna a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Efr�ma Syrsk�ho, j�hna a u�itele C�rkve",
 "Szent Efr�m diak�nus �s egyh�ztan�t�",
 };
const char *text_JUN_11[] = 
{"Sv. Barnab�a, apo�tola",
 "Sv. Barnab�e, apo�tola",
 "",
 "",
 "",
 "Sv. Barnab�e, apo�tola",
 "Szent Barnab�s apostol",
 };
const char *text_JUN_13[] = 
{"Sv. Antona Padu�nskeho, k�aza a u�ite�a Cirkvi",
 "Sv. Anton�na z Padovy, kn�ze a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Anton�na z Padovy, kn�ze a u�itele C�rkve",
 "P�duai Szent Antal �ldoz�pap �s egyh�ztan�t�",
 };
const char *text_JUN_15[] = 
{"(na Slovensku nie je)",
 "Sv. V�ta, mu�edn�ka",
 "",
 "",
 "",
 "Sv. V�ta, mu�edn�ka",
 "(nincs Magyarorsz�gon)",
 };
const char *text_JUN_16[] = 
{"Sv. Neita, mu�en�ka",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "",
 "",
 "",
 "(pro dominik�ny nen�)",
 "(nincs Magyarorsz�gon)",
 };
const char *text_JUN_19[] = 
{"Sv. Romualda, op�ta",
 "Sv. Romualda, opata",
 "",
 "",
 "",
 "Sv. Romualda, opata",
 "Szent Romuald ap�t",
 };
const char *text_JUN_19_1[] = 
{"(na Slovensku nie je)",
 "Sv. Jana Nepomuck�ho Neumanna, biskupa",
 "",
 "",
 "",
 "Sv. Jana Nepomuck�ho Neumanna, biskupa",
 "(nincs Magyarorsz�gon)",
 };
const char *text_JUN_21[] = 
{"Sv. Alojza Gonz�gu, reho�n�ka",
 "Sv. Aloise Gonzagy, �eholn�ka",
 "",
 "",
 "",
 "Sv. Aloise Gonzagy, �eholn�ka",
 "Gonz�ga Szent Alajos szerzetes",
 };
const char *text_JUN_22_2[] = 
{"Sv. Pavl�na z Noly, biskupa",
 "Sv. Paulina Nol�nsk�ho, biskupa",
 "",
 "",
 "",
 "Sv. Paulina Nol�nsk�ho, biskupa",
 "Nolai Szent Paul�nusz p�sp�k",
 };
const char *text_JUN_22_1[] = 
{"Sv. J�na Fishera, biskupa, a sv. Tom�a M�rusa, mu�en�kov",
 "Sv. Jana Fishera, biskupa, a Tom�e Mora, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Jana Fishera, biskupa, a Tom�e Mora, mu�edn�k�",
 "Fisher Szent J�nos p�sp�k �s Morus Szent Tam�s v�rtan�k",
 };
const char *text_JUN_24[] = 
{"Narodenie sv. J�na Krstite�a",
 "Narozen� svat�ho Jana K�titele",
 "",
 "",
 "",
 "Narozen� svat�ho Jana K�titele",
 "Keresztel� Szent J�nos sz�let�se",
 };
const char *text_JUN_27[] = 
{"Sv. Cyrila Alexandrijsk�ho, biskupa a u�ite�a Cirkvi",
 "Sv. Cyrila Alexandrijsk�ho, biskupa a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Cyrila Alexandrijsk�ho, biskupa a u�itele c�rkve",
 "(nincs Magyarorsz�gon)",
 };
const char *text_JUN_27_1[] = 
{"Sv. Ladislava",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "",
 "",
 "",
 "(pro dominik�ny nen�)",
 "Szent L�szl� kir�ly",
 };
const char *text_JUN_28[] = 
{"Sv. Ireneja, biskupa a mu�en�ka",
 "Sv. Ireneje, biskupa a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Ireneje, biskupa a mu�edn�ka",
 "Szent Ir�neusz p�sp�k �s v�rtan�",
 };
const char *text_JUN_29[] = 
{"Sv. Petra a Pavla, apo�tolov",
 "Sv. Petra a Pavla, apo�tol�",
 "",
 "",
 "",
 "Sv. Petra a Pavla, apo�tol�",
 "Szent P�ter �s Szent P�l apostolok",
 };
const char *text_JUN_30[] = 
{"Prv�ch sv�t�ch mu�en�kov Cirkvi v R�me",
 "Svat�ch prvomu�edn�k� ��msk�ch",
 "",
 "",
 "",
 "Svat�ch prvomu�edn�k� ��msk�ch",
 "A r�mai Egyh�z els� szent v�rtan�i",
 };
const char *text_JUN_30_1[] = 
{"(na Slovensku nie je)",
 "V�ro�� posv�cen� katedr�ly sv. V�clava",
 "",
 "",
 "",
 "V�ro�� posv�cen� katedr�ly sv. V�clava",
 "(nincs Magyarorsz�gon)",
 };
const char *text_JUL_03[] = 
{"Sv. Tom�a, apo�tola",
 "Sv. Tom�e, apo�tola",
 "",
 "",
 "",
 "Sv. Tom�e, apo�tola",
 "Szent Tam�s apostol",
 };
const char *text_JUL_04[] = 
{"Sv. Al�bety Portugalskej",
 "Sv. Al�b�ty Portugalsk�",
 "",
 "",
 "",
 "Sv. Al�b�ty Portugalsk�",
 "Portug�liai Szent Erzs�bet",
 };
const char *text_JUL_04_1[] = 
{"(na Slovensku nie je)",
 "Sv. Prokopa, opata",
 "",
 "",
 "",
 "Sv. Prokopa, opata",
 "(nincs Magyarorsz�gon)",
 };
const char *text_JUL_05[] = 
{"Sv. Cyrila a Metoda, slovansk�ch vierozvestov, apo�tolov",
 "Sv. Cyrila, mnicha, a Metod�je, biskupa, patron� Evropy, hlavn�ch patron� Moravy",
 "",
 "",
 "",
 "Sv. Cyrila, mnicha, a Metod�je, biskupa, patron� Evropy, hlavn�ch patron� Moravy",
 "(nincs Magyarorsz�gon)",
 };
const char *text_JUL_06[] = 
{"Sv. M�rie Goretti, panny a mu�enice",
 "Sv. Marie Gorettiov�, panny a mu�ednice",
 "",
 "",
 "",
 "Sv. Marie Gorettiov�, panny a mu�ednice",
 "Goretti Szent M�ria sz�z �s v�rtan�",
 };
const char *text_JUL_07[] = 
{"Sv. Antona M�rie Zaccariu, k�aza",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "",
 "",
 "",
 "(pro dominik�ny nen�)",
 "(nincs Magyarorsz�gon)",
 };
const char *text_JUL_09[] = 
{"Sv. August�na Zhao Rong, k�aza, a spolo�n�kov, mu�en�kov",
 "Sv. Augustina �ao Ronga, kn�ze a jeho druh�, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Augustina �ao Ronga, kn�ze a jeho druh�, mu�edn�k�",
 "(nincs Magyarorsz�gon)",
 };
const char *text_JUL_11[] = 
{"Sv. Benedikta, op�ta, patr�na Eur�py",
 "Sv. Benedikta, opata, patrona Evropy",
 "",
 "",
 "",
 "Sv. Benedikta, opata, patrona Evropy",
 "Szent Benedek ap�t, Eur�pa f�v�d�szentje",
 };
const char *text_JUL_13[] = 
{"Sv. Henricha",
 "Sv. Jind�icha",
 "",
 "",
 "",
 "Sv. Jind�icha",
 "Szent Henrik",
 };
const char *text_JUL_14[] = 
{"Sv. Kamila de Lellis, k�aza",
 "Sv. Kamila de Lellis, kn�ze",
 "",
 "",
 "",
 "Sv. Kamila de Lellis, kn�ze",
 "Lellisi Szent Kamill �ldoz�pap",
 };
const char *text_JUL_14_1[] = 
{"(na Slovensku nie je)",
 "Bl. Hroznaty, mu�edn�ka",
 "",
 "",
 "",
 "Bl. Hroznaty, mu�edn�ka",
 "(nincs Magyarorsz�gon)",
 };
const char *text_JUL_15[] = 
{"Sv. Bonavent�ru, biskupa a u�ite�a Cirkvi",
 "Sv. Bonaventury, biskupa a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Bonaventury, biskupa a u�itele C�rkve",
 "Szent Bonavent�ra p�sp�k �s egyh�ztan�t�",
 };
const char *text_JUL_16[] = 
{"Prebl. Panny M�rie Karmelskej",
 "Panny Marie Karmelsk�",
 "",
 "",
 "",
 "Panny Marie Karmelsk�",
 "K�rmel-hegyi Boldogasszony",
 };
const char *text_JUL_16_1[] = 
{"(na Slovensku nie je)",
 "V�ro�� posv�cen� katedr�ly Bo�sk�ho Spasitele",
 "",
 "",
 "",
 "V�ro�� posv�cen� katedr�ly Bo�sk�ho Spasitele",
 "(nincs Magyarorsz�gon)",
 };
const char *text_JUL_17_1[] = 
{"Sv. Andreja-Svorada a Benedikta, pustovn�kov",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "",
 "",
 "",
 "(pro dominik�ny nen�)",
 "Szent Zoer�rd-Andr�s �s Benedek remet�k",
 };
const char *text_JUL_17_2[] = 
{"(na Slovensku nie je)",
 "Bl. �eslava a sv. Hyacinta, kn��",
 "",
 "",
 "",
 "Bl. �eslava a sv. Hyacinta, kn��",
 "(nincs Magyarorsz�gon)",
 };
const char *text_JUL_20[] = 
{"(na Slovensku nie je)",
 "Sv. Apolin��e, biskupa a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Apolin��e, biskupa a mu�edn�ka",
 "(nincs Magyarorsz�gon)",
 };
const char *text_JUL_21[] = 
{"Sv. Vavrinca z Brindisi, k�aza a u�ite�a Cirkvi",
 "Sv. Vav�ince z Brindisi, kn�ze a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Vav�ince z Brindisi, kn�ze a u�itele C�rkve",
 "Brindisi Szent L�rinc �ldoz�pap �s egyh�ztan�t�",
 };
const char *text_JUL_22[] = 
{"Sv. M�rie Magdal�ny",
 "Sv. Marie Magdal�ny",
 "",
 "",
 "",
 "Sv. Marie Magdal�ny",
 "Szent M�ria Magdolna",
 };
const char *text_JUL_23[] = 
{"Sv. Brigity, reho�n��ky, spolupatr�nky Eur�py",
 "Sv. Brigity, �eholnice patronky Evropy",
 "",
 "",
 "",
 "Sv. Brigity, �eholnice patronky Evropy",
 "Szent Brigitta szerzetesn�",
 };
const char *text_JUL_24[] = 
{"Sv. Charbela Makhlufa, k�aza",
 "Sv. �arbela Makhl�fa, kn�ze",
 "",
 "",
 "",
 "Sv. �arbela Makhl�fa, kn�ze",
 "(nincs Magyarorsz�gon)",
 };
const char *text_JUL_25[] = 
{"Sv. Jakuba, apo�tola",
 "Sv. Jakuba, apo�tola",
 "",
 "",
 "",
 "Sv. Jakuba, apo�tola",
 "Szent Jakab apostol",
 };
const char *text_JUL_26[] = 
{"Sv. Joachima a Anny, rodi�ov Panny M�rie",
 "Sv. J�chyma a Anny, rodi�� Panny Marie",
 "",
 "",
 "",
 "Sv. J�chyma a Anny, rodi�� Panny Marie",
 "Szent Joakim �s Szent Anna, a Boldogs�gos Sz�z M�ria sz�lei",
 };
const char *text_JUL_27[] = 
{"Sv. Gorazda a spolo�n�kov",
 "Sv. Gorazda a druh�",
 "",
 "",
 "",
 "Sv. Gorazda a druh�",
 "(nincs Magyarorsz�gon)",
 };
const char *text_JUL_29[] = 
{"Sv. Marty",
 "Sv. Marty",
 "",
 "",
 "",
 "Sv. Marty",
 "Szent M�rta",
 };
const char *text_JUL_30[] = 
{"Sv. Petra Chryzol�ga, biskupa a u�ite�a Cirkvi",
 "Sv. Petra Chryzologa, biskupa a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Petra Chryzologa, biskupa a u�itele c�rkve",
 "Aranyszav� (Krizologosz) Szent P�ter p�sp�k �s egyh�ztan�t�",
 };
const char *text_JUL_30_1[] = 
{"Bl. Zdenky Schelingovej, panny a mu�enice",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "",
 "",
 "",
 "(pro dominik�ny nen�)",
 "(nincs Magyarorsz�gon)",
 };
const char *text_JUL_31[] = 
{"Sv. Ign�ca z Loyoly, k�aza",
 "Sv. Ign�ce z Loyoly, kn�ze",
 "",
 "",
 "",
 "Sv. Ign�ce z Loyoly, kn�ze",
 "Loyolai Szent Ign�c �ldoz�pap",
 };
const char *text_AUG_01[] = 
{"Sv. Alfonza M�rie de Ligouri, biskupa a u�ite�a Cirkvi",
 "Sv. Alfonsa z Liguori, biskupa a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Alfonsa z Liguori, biskupa a u�itele C�rkve",
 "Liguori Szent Alfonz M�ria p�sp�k �s egyh�ztan�t�",
 };
const char *text_AUG_02_1[] = 
{"Sv. Euz�bia Vercellsk�ho, biskupa",
 "Sv. Eusebia z Vercelli, biskupa",
 "",
 "",
 "",
 "Sv. Eusebia z Vercelli, biskupa",
 "Vercelli Szent �zs�b p�sp�k",
 };
const char *text_AUG_02_2[] = 
{"Sv. Petra Juli�na Eymard, k�aza",
 "Sv. Petra Juli�na Eymarda, kn�ze",
 "",
 "",
 "",
 "Sv. Petra Juli�na Eymarda, kn�ze",
 "(nincs Magyarorsz�gon)",
 };
const char *text_AUG_04[] = 
{"Sv. J�na M�rie Vianneya, k�aza",
 "Sv. Jana Marie Vianneye, kn�ze",
 "",
 "",
 "",
 "Sv. Jana Marie Vianneye, kn�ze",
 "Vianney Szent J�nos M�ria �ldoz�pap",
 };
const char *text_AUG_05[] = 
{"V�ro�ie posviacky hlavnej mari�nskej baziliky v R�me",
 "Posv�cen� ��msk� baziliky Panny Marie",
 "",
 "",
 "",
 "Posv�cen� ��msk� baziliky Panny Marie",
 "Sz�z M�ria r�mai f�templom�nak felszentel�se (Havas Boldogasszony)",
 };
const char *text_AUG_06[] = 
{"Premenenie P�na",
 "Prom�n�n� P�n�",
 "",
 "",
 "",
 "Prom�n�n� P�n�",
 "Urunk Sz�nev�ltoz�sa",
 };
const char *text_AUG_07_1[] = 
{"Sv. Sixta II., p�pe�a, a jeho spolo�n�kov, mu�en�kov",
 "Sv. Sixta II., pape�e, a druh�, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Sixta II., pape�e, a druh�, mu�edn�k�",
 "Szent II. Szixtusz p�pa �s t�rsai v�rtan�k",
 };
const char *text_AUG_07_2[] = 
{"Sv. Kajet�na, k�aza",
 "Sv. Kajet�na, kn�ze",
 "",
 "",
 "",
 "Sv. Kajet�na, kn�ze",
 "Szent Kajet�n �ldoz�pap",
 };
const char *text_AUG_08[] = 
{"Sv. Dominika, k�aza",
 "Sv. Dominika, kn�ze",
 "",
 "",
 "",
 "Sv. Dominika, kn�ze",
 "Szent Domonkos �ldoz�pap",
 };
const char *text_AUG_09[] = 
{"Sv. Ter�zie Benedikty, reho�n��ky a mu�enice, spolupatr�nky Eur�py",
 "Sv. Terezie Benedikty, panny a mu�ednice, patronky Evropy",
 "",
 "",
 "",
 "Sv. Terezie Benedikty, panny a mu�ednice, patronky Evropy",
 "(nincs Magyarorsz�gon)",
 };
const char *text_AUG_10[] = 
{"Sv. Vavrinca, diakona a mu�en�ka",
 "Sv. Vav�ince, mu�edn�ka",
 "",
 "",
 "",
 "Sv. Vav�ince, mu�edn�ka",
 "Szent L�rinc diak�nus �s v�rtan�",
 };
const char *text_AUG_11[] = 
{"Sv. Kl�ry, panny",
 "Sv. Kl�ry, panny",
 "",
 "",
 "",
 "Sv. Kl�ry, panny",
 "Szent Kl�ra sz�z",
 };
const char *text_AUG_12[] = 
{"Sv. Jany Franti�ky de Chantal, reho�n��ky",
 "Sv. Jany Franti�ky de Chantal, �eholnice",
 "",
 "",
 "",
 "Sv. Jany Franti�ky de Chantal, �eholnice",
 "(nincs Magyarorsz�gon)",
 };
const char *text_AUG_13[] = 
{"Sv. Ponci�na, p�pe�a, a sv. Hypolita, k�aza, mu�en�kov",
 "Sv. Ponci�na, pape�e, a Hippolyta, kn�ze, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Ponci�na, pape�e, a Hippolyta, kn�ze, mu�edn�k�",
 "Szent Ponci�nusz p�pa �s szent Hippolitusz �ldoz�pap �s v�rtan�k",
 };
const char *text_AUG_14[] = 
{"Sv. Maximili�na Kolbeho, k�aza a mu�en�ka",
 "Sv. Maxmili�na Marie Kolbeho, kn�ze a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Maxmili�na Marie Kolbeho, kn�ze a mu�edn�ka",
 "Szent Maximili�n M�ria Kolbe �ldoz�pap �s v�rtan�",
 };
const char *text_AUG_15[] = 
{"Nanebovzatie prebl. Panny M�rie",
 "Nanebevzet� Panny Marie",
 "",
 "",
 "",
 "Nanebevzet� Panny Marie",
 "Sz�z M�ria Mennybev�tele (Nagyboldogasszony)",
 };
const char *text_AUG_16[] = 
{"Sv. �tefana Uhorsk�ho",
 "Sv. �t�p�na Uhersk�ho",
 "",
 "",
 "",
 "Sv. �t�p�na Uhersk�ho",
 "(nincs Magyarorsz�gon)",
 };
const char *text_AUG_19[] = 
{"Sv. J�na Eudes, k�aza",
 "Sv. Jana Eudese, kn�ze",
 "",
 "",
 "",
 "Sv. Jana Eudese, kn�ze",
 "Eudes Szent J�nos �ldoz�pap",
 };
const char *text_AUG_20[] = 
{"Sv. Bernarda, op�ta a u�ite�a Cirkvi",
 "Sv. Bernarda, opata a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Bernarda, opata a u�itele C�rkve",
 "(nincs Magyarorsz�gon)",
 };
const char *text_AUG_21[] = 
{"Sv. Pia X., p�pe�a",
 "Sv. Pia X., pape�e",
 "",
 "",
 "",
 "Sv. Pia X., pape�e",
 "Szent X. Piusz p�pa",
 };
const char *text_AUG_22[] = 
{"Prebl. Panny M�rie Kr�ovnej",
 "Panny Marie Kr�lovny",
 "",
 "",
 "",
 "Panny Marie Kr�lovny",
 "Boldogs�gos Sz�z M�ria Kir�lyn�",
 };
const char *text_AUG_23[] = 
{"Sv. Ru�eny Limskej, panny",
 "Sv. R��eny z Limy, panny",
 "",
 "",
 "",
 "Sv. R��eny z Limy, panny",
 "Limai Szent R�za sz�z",
 };
const char *text_AUG_24[] = 
{"Sv. Bartolomeja, apo�tola",
 "Sv. Bartolom�je, apo�tola",
 "",
 "",
 "",
 "Sv. Bartolom�je, apo�tola",
 "Szent Bertalan apostol",
 };
const char *text_AUG_25_1[] = 
{"Sv. Jozefa de Calasanz, k�aza",
 "Sv. Josefa Kalasansk�ho, kn�ze",
 "",
 "",
 "",
 "Sv. Josefa Kalasansk�ho, kn�ze",
 "Kalazanci Szent J�zsef �ldoz�pap",
 };
const char *text_AUG_25_2[] = 
{"Sv. �udov�ta",
 "Sv. Ludv�ka",
 "",
 "",
 "",
 "Sv. Ludv�ka",
 "Szent Lajos",
 };
const char *text_AUG_25_3[] = 
{"(na Slovensku nie je)",
 "Sv. Benedikta, Jana, Matou�e, Iz�ka a Kristina, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Benedikta, Jana, Matou�e, Iz�ka a Kristina, mu�edn�k�",
 "(nincs Magyarorsz�gon)",
 };
const char *text_AUG_27[] = 
{"Sv. Moniky",
 "Sv. Moniky",
 "",
 "",
 "",
 "Sv. Moniky",
 "Szent M�nika",
 };
const char *text_AUG_28[] = 
{"Sv. August�na, biskupa a u�ite�a Cirkvi",
 "Sv. Augustina, biskupa a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Augustina, biskupa a u�itele C�rkve",
 "Szent �goston p�sp�k �s egyh�ztan�t�",
 };
const char *text_AUG_29[] = 
{"Mu�en�cka smr� sv. J�na Krstite�a",
 "Umu�en� svat�ho Jana K�titele",
 "",
 "",
 "",
 "Umu�en� svat�ho Jana K�titele",
 "Keresztel� Szent J�nos v�rtan�s�ga",
 };
const char *text_AUG_30[] = 
{"V�ro�ie posviacky katedr�lneho chr�mu v Trnave",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "",
 "",
 "",
 "(pro dominik�ny nen�)",
 "(nincs Magyarorsz�gon)",
 };
const char *text_SEP_03[] = 
{"Sv. Gregora Ve�k�ho, p�pe�a a u�ite�a Cirkvi",
 "Sv. �eho�e Velik�ho, pape�e a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. �eho�e Velik�ho, pape�e a u�itele C�rkve",
 "Nagy Szent Gergely p�pa �s egyh�ztan�t�",
 };
const char *text_SEP_06[] = 
{"V�ro�ie posviacky katedr�lneho chr�mu v Ko�iciach",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "",
 "",
 "",
 "(pro dominik�ny nen�)",
 "(nincs Magyarorsz�gon)",
 };
const char *text_SEP_07[] = 
{"Sv. Marka Kri�ina, Melichara Grodzieck�ho a �tefana Pongr�cza, k�azov a mu�en�kov",
 "Sv. Melichara Grodeck�ho, kn�ze a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Melichara Grodeck�ho, kn�ze a mu�edn�ka",
 "(nincs Magyarorsz�gon)",
 };
const char *text_SEP_08[] = 
{"Narodenie prebl. Panny M�rie",
 "Narozen� Panny Marie",
 "",
 "",
 "",
 "Narozen� Panny Marie",
 "Sz�z M�ria Sz�let�se (Kisboldogasszony)",
 };
const char *text_SEP_09[] = 
{"Sv. Petra Clavera, k�aza",
 "Sv. Petra Klavera, kn�ze",
 "",
 "",
 "",
 "Sv. Petra Klavera, kn�ze",
 "(nincs Magyarorsz�gon)",
 };
const char *text_SEP_10[] = 
{"(na Slovensku nie je)",
 "Bl. Karla Spinoly, kn�ze a mu�edn�ka",
 "",
 "",
 "",
 "Bl. Karla Spinoly, kn�ze a mu�edn�ka",
 "(nincs Magyarorsz�gon)",
 };
const char *text_SEP_12[] = 
{"Mena prebl. Panny M�rie",
 "Jm�na Panny Marie",
 "",
 "",
 "",
 "Jm�na Panny Marie",
 "Sz�z M�ria Szent Neve",
 };
const char *text_SEP_13[] = 
{"Sv. J�na Zlato�steho, biskupa a u�ite�a Cirkvi",
 "Sv. Jana Zlato�st�ho, biskupa a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Jana Zlato�st�ho, biskupa a u�itele c�rkve",
 "Aranysz�j� (Krizosztomosz) Szent J�nos p�sp�k �s egyh�ztan�t�",
 };
const char *text_SEP_14[] = 
{"Pov��enie sv�t�ho kr�a",
 "Pov��en� svat�ho k��e",
 "",
 "",
 "",
 "Pov��en� svat�ho k��e",
 "A Szent Kereszt felmagasztal�sa",
 };
const char *text_SEP_15[] = 
{"Sedembolestnej Panny M�rie, patr�nky Slovenska",
 "Panny Marie Bolestn�",
 "",
 "",
 "",
 "Panny Marie Bolestn�",
 "A F�jdalmas Sz�zanya",
 };
const char *text_SEP_16_CZ[] = 
{"(na Slovensku nie je)",
 "Sv. Ludmily, mu�ednice",
 "",
 "",
 "",
 "Sv. Ludmily, mu�ednice",
 "(nincs Magyarorsz�gon)",
 };
const char *text_SEP_16[] = 
{"Sv. Korn�lia, p�pe�a, a sv. Cypri�na, biskupa, mu�en�kov",
 "Sv. Korn�lia, pape�e, a Cypri�na, biskupa, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Korn�lia, pape�e, a Cypri�na, biskupa, mu�edn�k�",
 "Szent Korn�l p�pa �s Szent Cipri�n p�sp�k �s v�rtan�k",
 };
const char *text_SEP_17[] = 
{"Sv. R�berta Bellarm�na, biskupa a u�ite�a Cirkvi",
 "Sv. Roberta Bellarmina, biskupa a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Roberta Bellarmina, biskupa a u�itele C�rkve",
 "Bellarmin Szent R�bert p�sp�k �s egyh�ztan�t�",
 };
const char *text_SEP_19[] = 
{"Sv. Janu�ra, biskupa a mu�en�ka",
 "Sv. Janu�ria, biskupa a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Janu�ria, biskupa a mu�edn�ka",
 "Szent Janu�riusz p�sp�k �s v�rtan�",
 };
const char *text_SEP_20[] = 
{"Sv. Andreja Kim Taegona, k�aza, a sv. Pavla Chong Hasanga a spolo�n�kov, mu�en�kov",
 "Sv. Ond�eje Kim Taegona, kn�ze, Pavla Chong Hasanga a druh�, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Ond�eje Kim Taegona, kn�ze, Pavla Chong Hasanga a druh�, mu�edn�k�",
 "Kim Taegon Szent Andr�s �ldoz�pap, Csong Haszang Szent P�l �s t�rsaik, v�rtan�k",
 };
const char *text_SEP_20_2[] = 
{"(na Slovensku nie je)",
 "V�ro�� posv�cen� katedr�ly sv. �t�p�na",
 "",
 "",
 "",
 "V�ro�� posv�cen� katedr�ly sv. �t�p�na",
 "(nincs Magyarorsz�gon)",
 };
const char *text_SEP_21[] = 
{"Sv. Mat��a, apo�tola a evanjelistu",
 "Sv. Matou�e, apo�tola a evangelisty",
 "",
 "",
 "",
 "Sv. Matou�e, apo�tola a evangelisty",
 "Szent M�t� apostol �s evangelista",
 };
const char *text_SEP_22[] = 
{"Sv. Emer�ma, biskupa a mu�en�ka",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "",
 "",
 "",
 "(pro dominik�ny nen�)",
 "(nincs Magyarorsz�gon)",
 };
const char *text_SEP_23[] = 
{"Sv. Pia z Pietrel�iny, k�aza",
 "Sv. Pia z Pietrelciny, kn�ze",
 "",
 "",
 "",
 "Sv. Pia z Pietrelciny, kn�ze",
 "(nincs Magyarorsz�gon)",
 };
const char *text_SEP_24[] = 
{"V�ro�ie posviacky katedr�lneho chr�mu v Banskej Bystrici",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "",
 "",
 "",
 "(pro dominik�ny nen�)",
 "(nincs Magyarorsz�gon)",
 };
const char *text_SEP_26[] = 
{"Sv. Kozmu a Dami�na, mu�en�kov",
 "Sv. Kosmy a Dami�na, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Kosmy a Dami�na, mu�edn�k�",
 "Szent Kozma �s Damj�n v�rtan�k",
 };
const char *text_SEP_27[] = 
{"Sv. Vincenta de Paul, k�aza",
 "Sv. Vincence z Paula, kn�ze",
 "",
 "",
 "",
 "Sv. Vincence z Paula, kn�ze",
 "P�li Szent Vince �ldoz�pap",
 };
const char *text_SEP_28[] = 
{"Sv. V�clava, mu�en�ka",
 "Sv. V�clava, mu�edn�ka, hlavn�ho patrona �esk�ho n�roda",
 "",
 "",
 "",
 "Sv. V�clava, mu�edn�ka, hlavn�ho patrona �esk�ho n�roda",
 "Szent Vencel v�rtan�",
 };
const char *text_SEP_28_2[] = 
{"Sv. Vavrinca Ruiza a spolo�n�kov, mu�en�kov",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "",
 "",
 "",
 "(pro dominik�ny nen�)",
 "(nincs Magyarorsz�gon)",
 };
const char *text_SEP_29[] = 
{"Sv. Michala, Gabriela a Rafaela, archanjelov",
 "Sv. Michaela, Gabriela a Rafaela, archand�l�",
 "",
 "",
 "",
 "Sv. Michaela, Gabriela a Rafaela, archand�l�",
 "Szent Mih�ly, Szent G�bor �s Szent Rafael f�angyalok",
 };
const char *text_SEP_30[] = 
{"Sv. Hieronyma, k�aza a u�ite�a Cirkvi",
 "Sv. Jeron�ma, kn�ze a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Jeron�ma, kn�ze a u�itele C�rkve",
 "Szent Jeromos �ldoz�pap �s egyh�ztan�t�",
 };
const char *text_OKT_01[] = 
{"Sv. Ter�zie z Lisieux, panny a u�ite�ky Cirkvi",
 "Sv. Terezie od D�t�te Je��e, panny",
 "",
 "",
 "",
 "Sv. Terezie od D�t�te Je��e, panny",
 "A Gyermek J�zusr�l nevezett (Lisieux-i) Szent Ter�z Sz�z",
 };
const char *text_OKT_02[] = 
{"Sv�t�ch anjelov str�cov",
 "Svat�ch and�l� str�n�ch",
 "",
 "",
 "",
 "Svat�ch and�l� str�n�ch",
 "Szent �rz�angyalok",
 };
const char *text_OKT_04[] = 
{"Sv. Franti�ka Assisk�ho",
 "Sv. Franti�ka z Assisi",
 "",
 "",
 "",
 "Sv. Franti�ka z Assisi",
 "Assisi Szent Ferenc",
 };
const char *text_OKT_06[] = 
{"Sv. Bruna, k�aza",
 "Sv. Bruna, kn�ze",
 "",
 "",
 "",
 "Sv. Bruna, kn�ze",
 "Szent Br�n� �ldoz�pap",
 };
const char *text_OKT_07[] = 
{"Ru�encovej prebl. Panny M�rie",
 "Panny Marie R��encov�",
 "",
 "",
 "",
 "Panny Marie R��encov�",
 "R�zsaf�z�r Kir�lyn�je",
 };
const char *text_OKT_09_1[] = 
{"Sv. Dion�zia, biskupa, a spolo�n�kov, mu�en�ka",
 "Sv. Dion�sia, biskupa, a druh�, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Dion�sia, biskupa, a druh�, mu�edn�k�",
 "Szent D�nes p�sp�k �s t�rsai v�rtan�k",
 };
const char *text_OKT_09_2[] = 
{"Sv. J�na Leonardiho, k�aza",
 "Sv. Jana Leonardiho, kn�ze",
 "",
 "",
 "",
 "Sv. Jana Leonardiho, kn�ze",
 "Leonardi Szent J�nos �ldoz�pap",
 };
const char *text_OKT_12[] = 
{"(na Slovensku nie je)",
 "Sv. Radima, biskupa",
 "",
 "",
 "",
 "Sv. Radima, biskupa",
 "(nincs Magyarorsz�gon)",
 };
const char *text_OKT_14[] = 
{"Sv. Kalixta I., p�pe�a a mu�en�ka",
 "Sv. Kalista I., pape�e a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Kalista I., pape�e a mu�edn�ka",
 "Szent I. Kallixtusz p�pa �s v�rtan�",
 };
const char *text_OKT_15[] = 
{"Sv. Ter�zie z Avily, panny a u�ite�ky Cirkvi",
 "Sv. Terezie od Je��e, panny a u�itelky c�rkve",
 "",
 "",
 "",
 "Sv. Terezie od Je��e, panny a u�itelky C�rkve",
 "A J�zusr�l nevezett (Avilai) Szent Ter�z sz�z �s egyh�ztan�t�",
 };
const char *text_OKT_16_2[] = 
{"Sv. Hedvigy, reho�n��ky",
 "Sv. Hedviky, �eholnice, hlavn� patronky Slezska",
 "",
 "",
 "",
 "Sv. Hedviky, �eholnice, hlavn� patronky Slezska",
 "Szent Hedvig szerzetesn�",
 };
const char *text_OKT_16_1[] = 
{"Sv. Margity M�rie Alacoque, panny",
 "Sv. Mark�ty Marie Alacoque, panny",
 "",
 "",
 "",
 "Sv. Mark�ty Marie Alacoque, panny",
 "Alacoque Szent Margit M�ria sz�z",
 };
const char *text_OKT_17[] = 
{"Sv. Ign�ca Antiochijsk�ho, biskupa a mu�en�ka",
 "Sv. Ign�ce Antiochijsk�ho, biskupa a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Ign�ce Antiochijsk�ho, biskupa a mu�edn�ka",
 "Antiochiai Szent Ign�c p�sp�k �s v�rtan�",
 };
const char *text_OKT_18[] = 
{"Sv. Luk�a, evanjelistu",
 "Sv. Luk�e, evangelisty",
 "",
 "",
 "",
 "Sv. Luk�e, evangelisty",
 "Szent Luk�cs evangelista",
 };
const char *text_OKT_19_1[] = 
{"Sv. J�na de Br�beuf a sv. Iz�ka Jogues, k�azov, a ich spolo�n�kov, mu�en�kov",
 "Sv. Jana de Br�beuf a Iz�ka Joguese, kn��, a druh�, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Jana de Br�beuf a Iz�ka Joguese, kn��, a druh�, mu�edn�k�",
 "De Br�beuf Szent J�nos �s Jogues Szent Izs�k �ldoz�pap �s t�rsaik v�rtan�k",
 };
const char *text_OKT_19_2[] = 
{"Sv. Pavla z Kr�a, k�aza",
 "Sv. Pavla od K��e, kn�ze",
 "",
 "",
 "",
 "Sv. Pavla od K��e, kn�ze",
 "Keresztes Szent P�l �ldoz�pap",
 };
const char *text_OKT_23[] = 
{"Sv. J�na Kapistr�nskeho, k�aza",
 "Sv. Jana Kapistr�nsk�ho, kn�ze",
 "",
 "",
 "",
 "Sv. Jana Kapistr�nsk�ho, kn�ze",
 "Kapisztr�n Szent J�nos �ldoz�pap",
 };
const char *text_OKT_24[] = 
{"Sv. Antona M�rie Clareta, biskupa",
 "Sv. Anton�na Marie Klareta, biskupa",
 "",
 "",
 "",
 "Sv. Anton�na Marie Klareta, biskupa",
 "Claret Szent Antal M�ria p�sp�k",
 };
const char *text_OKT_25[] = 
{"V�ro�ie posviacky katedr�lneho chr�mu v Spi�skom Podhrad�",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "",
 "",
 "",
 "(pro dominik�ny nen�)",
 "(nincs Magyarorsz�gon)",
 };
const char *text_OKT_26[] = 
{"V�ro�ie posviacky chr�mov, ktor�ch de� posviacky je nezn�my",
 "V�ro�� posv�cen� chr�mu, jejich� den dedikace nen� zn�m�",
 "",
 "",
 "",
 "V�ro�� posv�cen� chr�mu, jejich� den dedikace nen� zn�m�",
 "(nincs Magyarorsz�gon)",
 };
const char *text_OKT_27[] = 
{"V�ro�ie posviacky katedr�lneho chr�mu v Ro��ave",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "",
 "",
 "",
 "(pro dominik�ny nen�)",
 "(nincs Magyarorsz�gon)",
 };
const char *text_OKT_28[] = 
{"Sv. �imona a J�du, apo�tolov",
 "Sv. �imona a Judy, apo�tol�",
 "",
 "",
 "",
 "Sv. �imona a Judy, apo�tol�",
 "Szent Simon �s Szent J�d�s apostol",
 };
const char *text_OKT_29[] = 
{"(na Slovensku nie je)",
 "Bl. Marie Restituty Kafkov�, panny a mu�ednice",
 "",
 "",
 "",
 "Bl. Marie Restituty Kafkov�, panny a mu�ednice",
 "(nincs Magyarorsz�gon)",
 };
const char *text_OKT_30[] = 
{"(na Slovensku nie je)",
 "V�ro�� posv�cen� katedr�ly Svat�ho Ducha",
 "",
 "",
 "",
 "V�ro�� posv�cen� katedr�ly Svat�ho Ducha",
 "(nincs Magyarorsz�gon)",
 };
const char *text_OKT_31[] = 
{"(na Slovensku nie je)",
 "Sv. Wolfganga, biskupa",
 "",
 "",
 "",
 "Sv. Wolfganga, biskupa",
 "(nincs Magyarorsz�gon)",
 };
const char *text_NOV_01[] = 
{"V�etk�ch sv�t�ch",
 "V�ech svat�ch",
 "",
 "",
 "",
 "V�ech svat�ch",
 "Mindenszentek",
 };
const char *text_NOV_02[] = 
{"V�etk�ch vern�ch zosnul�ch",
 "Vzpom�nka na v�echny v�rn� zem�el�",
 "",
 "",
 "",
 "Vzpom�nka na v�echny v�rn� zem�el�",
 "Halottak napja",
 };
const char *text_NOV_03[] = 
{"Sv. Martina de Porres, reho�n�ka",
 "Sv. Martina de Porres, �eholn�ka",
 "",
 "",
 "",
 "Sv. Martina de Porres, �eholn�ka",
 "Porres Szent M�rton szerzetes",
 };
const char *text_NOV_04[] = 
{"Sv. Karola Borromea, biskupa",
 "Sv. Karla Boromejsk�ho, biskupa",
 "",
 "",
 "",
 "Sv. Karla Boromejsk�ho, biskupa",
 "Borromeo Szent K�roly p�sp�k",
 };
const char *text_NOV_05[] = 
{"Sv. Imricha",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "",
 "",
 "",
 "(pro dominik�ny nen�)",
 "Szent Imre herceg",
 };
const char *text_NOV_09[] = 
{"V�ro�ie posviacky Later�nskej baziliky",
 "Posv�cen� later�nsk� baziliky",
 "",
 "",
 "",
 "Posv�cen� later�nsk� baziliky",
 "A later�ni-bazilika felszentel�se",
 };
const char *text_NOV_10[] = 
{"Sv. Leva Ve�k�ho, p�pe�a a u�ite�a Cirkvi",
 "Sv. Lva Velik�ho, pape�e a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Lva Velik�ho, pape�e a u�itele c�rkve",
 "Nagy Szent Le� p�pa �s egyh�ztan�t�",
 };
const char *text_NOV_11[] = 
{"Sv. Martina z Tours, biskupa",
 "Sv. Martina, biskupa",
 "",
 "",
 "",
 "Sv. Martina, biskupa",
 "Tours-i Szent M�rton p�sp�k",
 };
const char *text_NOV_12[] = 
{"Sv. Jozaf�ta, biskupa a mu�en�ka",
 "Sv. Josafata, biskupa a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Josafata, biskupa a mu�edn�ka",
 "Szent Jozaf�t p�sp�k �s v�rtan�",
 };
const char *text_NOV_13[] = 
{"(na Slovensku nie je)",
 "Sv. Ane�ky �esk�, panny",
 "",
 "",
 "",
 "Sv. Ane�ky �esk�, panny",
 "(nincs Magyarorsz�gon)",
 };
const char *text_NOV_15[] = 
{"Sv. Alberta Ve�k�ho, biskupa a u�ite�a Cirkvi",
 "Sv. Alberta Velik�ho, biskupa a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Alberta Velik�ho, biskupa a u�itele C�rkve",
 "Nagy Szent Albert p�sp�k �s egyh�ztan�t�",
 };
const char *text_NOV_16_1[] = 
{"Sv. Margity �k�tskej",
 "Sv. Mark�ty Skotsk�",
 "",
 "",
 "",
 "Sv. Mark�ty Skotsk�",
 "Sk�ciai Szent Margit",
 };
const char *text_NOV_16_2[] = 
{"Sv. Gertr�dy, panny",
 "Sv. Gertrudy, panny",
 "",
 "",
 "",
 "Sv. Gertrudy, panny",
 "(nincs Magyarorsz�gon)",
 };
const char *text_NOV_17[] = 
{"Sv. Al�bety Uhorskej, reho�n��ky",
 "Sv. Al�b�ty Uhersk�, �eholnice",
 "",
 "",
 "",
 "Sv. Al�b�ty Uhersk�, �eholnice",
 "(nincs Magyarorsz�gon)",
 };
const char *text_NOV_18[] = 
{"V�ro�ie posviacky bazil�k sv. Petra a sv. Pavla, apo�tolov",
 "Posv�cen� ��msk�ch bazilik svat�ch apo�tol� Petra a Pavla",
 "",
 "",
 "",
 "Posv�cen� ��msk�ch bazilik svat�ch apo�tol� Petra a Pavla",
 "Szent P�ter- �s Szent P�l-Bazilik�k felszentel�se",
 };
const char *text_NOV_20[] = 
{"V�ro�ie posviacky katedr�lneho chr�mu v Nitre",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "",
 "",
 "",
 "(pro dominik�ny nen�)",
 "(nincs Magyarorsz�gon)",
 };
const char *text_NOV_21[] = 
{"Obetovanie prebl. Panny M�rie",
 "Zasv�cen� Panny Marie v Jeruzal�m�",
 "",
 "",
 "",
 "Zasv�cen� Panny Marie v Jeruzal�m�",
 "A Boldogs�gos Sz�z M�ria bemutat�sa a templomban",
 };
const char *text_NOV_22[] = 
{"Sv. Cec�lie, panny a mu�enice",
 "Sv. Cecilie, panny a mu�ednice",
 "",
 "",
 "",
 "Sv. Cecilie, panny a mu�ednice",
 "Szent Cec�lia sz�z �s v�rtan�",
 };
const char *text_NOV_23_1[] = 
{"Sv. Klementa I. p�pe�a a mu�en�ka",
 "Sv. Klementa I., pape�e a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Klementa I., pape�e a mu�edn�ka",
 "Szent I. Kelemen p�pa �s v�rtan�",
 };
const char *text_NOV_23_2[] = 
{"Sv. Kolumb�na, op�ta",
 "Sv. Kolumb�na, opata",
 "",
 "",
 "",
 "Sv. Kolumb�na, opata",
 "Szent Kolumb�n ap�t",
 };
const char *text_NOV_24[] = 
{"Sv. Ondreja Dung-Laca a spolo�n�kov, mu�en�kov",
 "Sv. Ond�eje Dung-Laca, kn�ze, a druh�, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Ond�eje Dung-Laca, kn�ze, a druh�, mu�edn�k�",
 "Dung-Lac Szent Andr�s �ldoz�pap �s t�rsai v�rtan�k",
 };
const char *text_NOV_25[] = 
{"Sv. Katar�ny Alexandrijskej, panny a mu�enice",
 "Sv. Kate�iny Alexandrijsk�, panny a mu�ednice",
 "",
 "",
 "",
 "Sv. Kate�iny Alexandrijsk�, panny a mu�ednice",
 "(nincs Magyarorsz�gon)",
 };
const char *text_NOV_30[] = 
{"Sv. Ondreja, apo�tola",
 "Sv. Ond�eje, apo�tola",
 "",
 "",
 "",
 "Sv. Ond�eje, apo�tola",
 "Szent Andr�s apostol",
 };
const char *text_DEC_01[] = 
{"(na Slovensku nie je)",
 "Sv. Edmunda Kampi�na, kn�ze a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Edmunda Kampi�na, kn�ze a mu�edn�ka",
 "(nincs Magyarorsz�gon)",
 };
const char *text_DEC_02[] = 
{"(na Slovensku nie je)",
 "V�ro�� posv�cen� katedr�ly sv. Bartolom�je",
 "",
 "",
 "",
 "V�ro�� posv�cen� katedr�ly sv. Bartolom�je",
 "(nincs Magyarorsz�gon)",
 };
const char *text_DEC_03[] = 
{"Sv. Franti�ka Xaversk�ho, k�aza",
 "Sv. Franti�ka Xaversk�ho, kn�ze",
 "",
 "",
 "",
 "Sv. Franti�ka Xaversk�ho, kn�ze",
 "Xav�ri Szent Ferenc �ldoz�pap",
 };
const char *text_DEC_04[] = 
{"Sv. J�na Damasc�nskeho, k�aza a u�ite�a Cirkvi",
 "Sv. Jana Dama�sk�ho, kn�ze a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Jana Dama�sk�ho, kn�ze a u�itele C�rkve",
 "Damaszkuszi Szent J�nos �ldoz�pap �s egyh�ztan�t�",
 };
const char *text_DEC_06[] = 
{"Sv. Mikul�a, biskupa",
 "Sv. Mikul�e, biskupa",
 "",
 "",
 "",
 "Sv. Mikul�e, biskupa",
 "Szent Mikl�s p�sp�k",
 };
const char *text_DEC_07[] = 
{"Sv. Ambr�za, biskupa a u�ite�a Cirkvi",
 "Sv. Ambro�e, biskupa a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Ambro�e, biskupa a u�itele C�rkve",
 "Szent Ambrus p�sp�k �s egh�ztan�t�",
 };
const char *text_DEC_08[] = 
{"Nepo�kvrnen� po�atie Panny M�rie",
 "Panny Marie, po�at� bez poskvrny prvotn�ho h��chu",
 "",
 "",
 "",
 "Panny Marie, po�at� bez poskvrny prvotn�ho h��chu",
 "A Boldogs�gos Sz�z M�ria szepl�telen fogantat�sa",
 };
const char *text_DEC_09[] = 
{"(nie je)",
 "(nen�)",
 "",
 "",
 "",
 "Sv. Jana Didaka Cuauhtlatoazina",
 "(nincs Magyarorsz�gon)",
 };
const char *text_DEC_11[] = 
{"Sv. Damaza I., p�pe�a",
 "Sv. Damasa I., pape�e",
 "",
 "",
 "",
 "Sv. Damasa I., pape�e",
 "Szent I. Damazusz p�pa",
 };
const char *text_DEC_12[] = 
{"(nie je)",
 "Panny Marie Guadalupsk�",
 "",
 "",
 "",
 "Panny Marie Guadalupsk�",
 "(nincs Magyarorsz�gon)",
 };
const char *text_DEC_13[] = 
{"Sv. Lucie, panny a mu�enice",
 "Sv. Lucie, panny a mu�ednice",
 "",
 "",
 "",
 "Sv. Lucie, panny a mu�ednice",
 "Szent L�cia sz�z �s v�rtan�",
 };
const char *text_DEC_14[] = 
{"Sv. J�na z Kr�a, k�aza a u�ite�a Cirkvi",
 "Sv. Jana od K��e, kn�ze a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Jana od K��e, kn�ze a u�itele C�rkve",
 "Keresztes Szent J�nos �ldoz�pap �s egyh�ztan�t�",
 };
const char *text_DEC_21[] = 
{"Sv. Petra Kan�zia, k�aza a u�ite�a Cirkvi",
 "Sv. Petra Kanisia, kn�ze a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Petra Kanisia, kn�ze a u�itele C�rkve",
 "Kan�ziusz Szent P�ter �ldoz�pap �s egyh�zta�nt�",
 };
const char *text_DEC_22[] = 
{"(na Slovensku nie je)",
 "V�ro�� posv�cen� katedr�ly Sv. Mikul�e",
 "",
 "",
 "",
 "V�ro�� posv�cen� katedr�ly Sv. Mikul�e",
 "(nincs Magyarorsz�gon)",
 };
const char *text_DEC_23[] = 
{"Sv. J�na Kentsk�ho, k�aza",
 "Sv. Jana Kentsk�ho, kn�ze",
 "",
 "",
 "",
 "Sv. Jana Kentsk�ho, kn�ze",
 "Kety Szent J�nos �ldoz�pap",
 };
const char *text_DEC_26[] = 
{"Sv. �tefana, prv�ho mu�en�ka",
 "Sv. �t�p�na, prvomu�edn�ka",
 "",
 "",
 "",
 "Sv. �t�p�na, prvomu�edn�ka",
 "Szent Istv�n els� v�rtan�",
 };
const char *text_DEC_27[] = 
{"Sv. J�na, apo�tola a evanjelistu",
 "Sv. Jana, apo�tola a evangelisty",
 "",
 "",
 "",
 "Sv. Jana, apo�tola a evangelisty",
 "Szent J�nos apostol �s evangelista",
 };
const char *text_DEC_28[] = 
{"Sv�t�ch Neviniatok, mu�en�kov",
 "Svat�ch Ml���tek, mu�edn�k�",
 "",
 "",
 "",
 "Svat�ch Ml���tek, mu�edn�k�",
 "(nincs Magyarorsz�gon)",
 };
const char *text_DEC_29[] = 
{"Sv. Tom�a Becketa, biskupa a mu�en�ka",
 "Sv. Tom�e Becketa, biskupa a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Tom�e Becketa, biskupa a mu�edn�ka",
 "Becket Szent Tam�s p�sp�k �s v�rtan�",
 };
const char *text_DEC_31[] = 
{"Sv. Silvestra I., p�pe�a",
 "Sv. Silvestra I., pape�e",
 "",
 "",
 "",
 "Sv. Silvestra I., pape�e",
 "Szent I. Szilveszter p�pa",
 };
const char *text_ZELENY_STVRTOK[] = 
{"Zelen� (ve�k�) �tvrtok - Pamiatka P�novej ve�ere",
 "Zelen� �tvrtek - Pam�tka Ve�e�e P�n�",
 "",
 "",
 "",
 "Zelen� �tvrtek - Pam�tka Ve�e�e P�n�",
 "Nagycs�t�rt�k",
 };
const char *text_VELKY_PIATOK[] = 
{"Ve�k� piatok",
 "Velk� p�tek",
 "",
 "",
 "",
 "Velk� p�tek",
 "Nagyp�ntek",
 };
const char *text_BIELA_SOBOTA[] = 
{"Biela (ve�k�) sobota",
 "B�l� sobota",
 "",
 "",
 "",
 "B�l� sobota",
 "Nagyszombat",
 };
const char *text_KVETNA_NEDELA[] = 
{"Kvetn� nede�a",
 "Kv�tn� ned�le",
 "",
 "",
 "",
 "Kv�tn� ned�le",
 "Vir�gvas�rnap, vagyis az �r szenved�s�nek vas�rnapja",
 };
const char *text_PO_POPOLCOVEJ_STREDE[] = 
{"po Popolcovej strede",
 "po Popele�n� st�ed�",
 "",
 "",
 "",
 "po Popele�n� st�ed�",
 "hu_name",
 };
const char *text_V_OKTAVE_NARODENIA[] = 
{"v okt�ve Narodenia P�na",
 "v okt�vu Narozen� P�n�",
 "",
 "",
 "",
 "v okt�vu Narozen� P�n�",
 "hu_name",
 };

#endif /* __HODIN_H */
