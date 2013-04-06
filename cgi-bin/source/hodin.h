/***************************************************************/
/*                                                             */
/* hodin.h                                                     */
/* (c)1999-2013 | Juraj Vid�ky | videky@breviar.sk             */
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
/*   2009-03-24a.D. | �pravy liturgick�ho kalend�ra pre czop   */
/*   2009-04-08a.D. | zakon�enie modlitby (pre modlitbu cezde� */
/*                    a komplet. sa pou��va krat�ie zakon�enie)*/
/*   2009-05-15a.D. | pridan� text_PRO_OP[]                    */
/*   2009-08-26a.D. | pridan� html_button_nazov_modlitby()     */
/*   2010-05-17a.D. | pridan� niektor� ma�arsk� sl�venia       */
/*   2010-10-11a.D. | pridan� nazov_kalendara_long[]           */
/*   2011-01-14a.D. | pridan� ZAKONCENIE_KTORY_JE              */
/*   2011-01-26a.D. | upraven� poradie kon�t�nt pre lit. obd.  */
/*   2011-05-18a.D. | doplnen� charset_jazyka[]                */
/*                                                             */
/*                                                             */
/***************************************************************/

#include "vstudio.h"

#ifndef __HODIN_H_
#define __HODIN_H_

#include "liturgia.h"

const char *TEMPLAT[POCET_MODLITIEB + 1] =
{TEMPLAT_INVITATORIUM, TEMPLAT_POSV_CITANIE, TEMPLAT_RANNE_CHVALY,
 TEMPLAT_CEZ_DEN_9, TEMPLAT_CEZ_DEN_12, TEMPLAT_CEZ_DEN_3,
 TEMPLAT_VESPERY, TEMPLAT_KOMPLETORIUM, STR_EMPTY,
 TEMPLAT_VESPERY, TEMPLAT_KOMPLETORIUM, 
 TEMPLAT_VESPERY, TEMPLAT_KOMPLETORIUM, TEMPLAT_NEURCENY, TEMPLAT_NEURCENY};

// 2008-04-09: doplnen� pre batch generovanie modlitieb
const char char_modlitby[POCET_MODLITIEB + 1] =
{CHAR_MODL_INVITATORIUM, CHAR_MODL_POSV_CITANIE, CHAR_MODL_RANNE_CHVALY, 
 CHAR_MODL_CEZ_DEN_9, CHAR_MODL_CEZ_DEN_12, CHAR_MODL_CEZ_DEN_3,
 CHAR_MODL_VESPERY, CHAR_MODL_KOMPLETORIUM, 32 /* ' ' */,
 CHAR_MODL_PRVE_VESPERY, CHAR_MODL_PRVE_KOMPLETORIUM, 
 CHAR_MODL_VESPERY, CHAR_MODL_KOMPLETORIUM, CHAR_MODL_NEURCENA, CHAR_MODL_VSETKY};

const char *str_modlitby[POCET_MODLITIEB + 1] =
{STR_MODL_INVITATORIUM, STR_MODL_POSV_CITANIE, STR_MODL_RANNE_CHVALY,
 STR_MODL_PREDPOLUDNIM, STR_MODL_NAPOLUDNIE, STR_MODL_POPOLUDNI,
 STR_MODL_VESPERY, STR_MODL_KOMPLETORIUM, STR_EMPTY,
 STR_MODL_PRVE_VESPERY, STR_MODL_PRVE_KOMPLETORIUM, 
 STR_MODL_VESPERY, STR_MODL_KOMPLETORIUM, STR_MODL_DETAILY, STR_MODL_VSETKY};

// the names of the prayers, lowercase (sample text)
const char *nazov_modlitby_jazyk[POCET_MODLITIEB + 1][POCET_JAZYKOV + 1] = 
{{"invitat�rium", "uveden� do prvn� modlitby dne", "Invitatory", "invitatorium", "", "Pozv�n� k modlitb�", "im�ds�gra h�v�s" }
, {"posv�tn� ��tanie", "modlitba se �ten�m", "Office of Readings", "officium lectionis", "", "Modlitba se �ten�m", "olvasm�nyos ima�ra" }
, {"rann� chv�ly", "rann� chv�ly", "Laudes", "laudes matutinae", "", "Rann� chv�ly", "reggeli dics�ret" }
, {"modlitba predpoludn�m", "modlitba dopoledne", "Terce", "tertia", "", "Tercie", "d�lel�tt" }
, {"modlitba napoludnie", "modlitba v poledne", "Sext", "sexta", "", "Sexta", "d�lben" }
, {"modlitba popoludn�", "modlitba odpoledne", "None", "nona", "", "Nona", "d�lut�n" }
, {"ve�pery", "ne�pory", "Vesperae", "vesperae", "", "Ve�ern� chv�ly", "esti dics�ret" }
, {"komplet�rium", "komplet��", "Completary", "completorio", "", "Komplet��", "befejez� ima�ra" }
, {"neur�en�", "neur�ena", "not-defined", "no data", "", "neur�ena", "nem azonos�tott"}
, {"prv� ve�pery", "prvn� ne�pory", "1st Vesperae", "I vesperae", "", "Prvn� ve�ern� chv�ly", "I. esti dics�ret" }
	// 2007-12-05: zmenen�, kedysi bolo: "prv� komplet�rium"
, {"komplet�rium po prv�ch ve�per�ch", "komplet�� po prvn�ch ne�por�ch", "1st Completary", "I completorio", "", "Komplet�� po prvn�ch ve�ern�ch chv�l�ch", "befejez� ima�ra I.e.d.ut�n" }
, {"druh� ve�pery", "druh� ne�pory", "2nd Vesperae", "II vesperae", "", "Druh� ve�ern� chv�ly", "II. esti dics�ret" }
	// 2007-12-05: zmenen�, kedysi bolo: "druh� komplet�rium"
, {"komplet�rium po druh�ch ve�per�ch", "komplet�� po druh�ch ne�por�ch", "2nd Completary", "II completorio", "", "Komplet�� po druh�ch ve�ern�ch chv�l�ch", "befejez� ima�ra II.e.d.ut�n" }
, {"detaily", "detaily", "Details", "details", "", "detaily", "r�szletek" }
, {"v�etky", "v�echny", "all", "all", "", "v�echny", "�sszes" }
};

#define		nazov_modlitby(a)	nazov_modlitby_jazyk[a][_global_jazyk]

// the names of the prayers, sentence case (Sample text)
const char *nazov_Modlitby_jazyk[POCET_MODLITIEB + 1][POCET_JAZYKOV + 1] = 
{{"Invitat�rium", "Uveden� do prvn� modlitby dne", "Invitatory", "Invitatorium", "", "Pozv�n� k modlitb�" , "Im�ds�gra h�v�s" }
, {"Posv�tn� ��tanie", "Modlitba se �ten�m", "Office of Readings", "Officium lectionis", "", "Modlitba se �ten�m" , "Olvasm�nyos ima�ra" }
, {"Rann� chv�ly", "Rann� chv�ly", "Laudes", "Laudes matutinae", "", "Rann� chv�ly" , "Reggeli dics�ret" }
, {"Modlitba predpoludn�m", "Modlitba dopoledne", "Terce", "Tertia", "", "Tercie" , "D�lel�tt" }
, {"Modlitba napoludnie", "Modlitba v poledne", "Sext", "Sexta", "", "Sexta" , "D�lben" }
, {"Modlitba popoludn�", "Modlitba odpoledne", "None", "Nona", "", "Nona" , "D�lut�n" }
, {"Ve�pery", "Ne�pory", "Vesperae", "Vesperae", "", "Ve�ern� chv�ly" , "Esti dics�ret" }
, {"Komplet�rium", "Komplet��", "Completary", "Completorio", "", "Komplet��" , "Befejez� ima�ra" }
, {"Neur�en�", "Neur�ena", "not-defined", "No data", "", "Neur�en�" , "Nem azonos�tott"}
, {"Prv� ve�pery", "Prvn� ne�pory", "1st Vesperae", "I Vesperae", "", "Prvn� ve�ern� chv�ly" , "I. Esti dics�ret" }
, {"Komplet�rium po prv�ch ve�per�ch", "Komplet�� po prvn�ch ne�por�ch", "1st Completary", "I Completorio", "", "Komplet�� po prvn�ch ve�ern�ch chv�l�ch" , "Befejez� ima�ra I.e.d.ut�n" }
, {"Druh� ve�pery", "Druh� ne�pory", "2nd Vesperae", "II Vesperae", "", "Druh� ve�ern� chv�ly" , "II. Esti dics�ret" }
, {"Komplet�rium po druh�ch ve�per�ch", "Komplet�� po druh�ch ne�por�ch", "2nd Completary", "II Completorio", "", "Komplet�� po druh�ch ve�ern�ch chv�l�ch" , "Befejez� ima�ra II.e.d.ut�n" }
, {"Detaily", "Detaily", "Details", "Details", "", "Detaily", "R�szletek" }
, {"v�etky", "v�echny", "all", "all", "", "v�echny", "�sszes" }
};

#define		nazov_Modlitby(a)	nazov_Modlitby_jazyk[a][_global_jazyk]

// the names of the prayers, all caps case (SAMPLE TEXT)
const char *nazov_MODLITBY_jazyk[POCET_MODLITIEB + 1][POCET_JAZYKOV + 1] = 
{{"INVITAT�RIUM", "UVEDEN� DO PRVN� MODLITBY DNE", "INVITATORY", "INVITATORIUM", "", "POZV�N� K MODLITB�" , "IM�DS�GRA H�V�S" }
, {"POSV�TN� ��TANIE", "MODLITBA SE �TEN�M", "OFFICE OF READINGS", "OFFICIUM LECTIONIS", "", "MODLITBA SE �TEN�M" , "OLVASM�NYOS IMA�RA" }
, {"RANN� CHV�LY", "RANN� CHV�LY", "LAUDES", "LAUDES MATUTINAE", "", "RANN� CHV�LY" , "REGGELI DICS�RET" }
, {"MODLITBA PREDPOLUDN�M", "MODLITBA DOPOLEDNE", "TERCE", "TERTIA", "", "TERCIE" , "D�LEL�TT" }
, {"MODLITBA NAPOLUDNIE", "MODLITBA V POLEDNE", "SEXT", "SEXTA", "", "SEXTA" , "D�LBEN" }
, {"MODLITBA POPOLUDN�", "MODLITBA ODPOLEDNE", "NONE", "NONA", "", "NONA" , "D�LUT�N" }
, {"VE�PERY", "NE�PORY", "VESPERAE", "VESPERAE", "", "VE�ERN� CHV�LY" , "ESTI DICS�RET" }
, {"KOMPLET�RIUM", "KOMPLET��", "COMPLETARY", "COMPLETORIO", "", "KOMPLET��" , "BEFEJEZ� IMA�RA" }
, {"NEUR�EN�", "NEUR�ENA", "NOT-DEFINED", "NO DATA", "", "NEUR�EN�" , "NEM AZONOS�TOTT"}
, {"PRV� VE�PERY", "PRVN� NE�PORY", "1ST VESPERAE", "I VESPERAE", "", "PRVN� VE�ERN� CHV�LY" , "I. ESTI DICS�RET" }
, {"KOMPLET�RIUM PO PRV�CH VE�PER�CH", "KOMPLET�� PO PRVN�CH NE�POR�CH", "1ST COMPLETARY", "I COMPLETORIO", "", "KOMPLET�� PO PRVN�CH VE�ERN�CH CHV�L�CH" , "BEFEJEZ� IMA�RA I.E.D.UT�N" }
, {"DRUH� VE�PERY", "DRUH� NE�PORY", "2ND VESPERAE", "II VESPERAE", "", "DRUH� VE�ERN� CHV�LY" , "II. ESTI DICS�RET" }
, {"KOMPLET�RIUM PO DRUH�CH VE�PER�CH", "KOMPLET�� PO DRUH�CH NE�POR�CH", "2ND COMPLETARY", "II COMPLETORIO", "", "KOMPLET�� PO DRUH�CH VE�ERN�CH CHV�L�CH" , "BEFEJEZ� IMA�RA II.E.D.UT�N" }
, {"DETAILY", "DETAILY", "DETAILS", "DETAILS", "", "DETAILY", "R�SZLETEK" }
, {"V�ETKY", "V�ECHNY", "ALL", "ALL", "", "V�ECHNY", "�SSZES" }
};

#define		nazov_MODLITBY(a)	nazov_MODLITBY_jazyk[a][_global_jazyk]

// the prefix for common parts of celebration
const char *nazov_spolc_zospolc_jazyk[POCET_JAZYKOV + 1] =
{"Zo spolo�nej �asti", "Spole�n� texty", "", "", "", "Spole�n� texty", "k�z�s zsolozsm�ja"};

const char *nazov_spolc_oficiumza_jazyk[POCET_JAZYKOV + 1] =
{"Of�cium za", "Spole�n� texty", "", "", "", "Spole�n� texty", "k�z�s zsolozsm�ja"};

// the --CELEBRATION-- for common parts of celebration
const char *nazov_spolc_sviatky_jazyk[POCET_JAZYKOV + 1] =
{"na sviatky", "na sv�tky", "", "", "", "na sv�tky", ""};

// the --ANNIVERSARY-- for common parts of celebration
const char *nazov_spolc_vyrocie_jazyk[POCET_JAZYKOV + 1] =
{"na v�ro�ie", "na v�ro��", "", "", "", "na v�ro��", ""};

// the --OR-- (alternative) for common parts of celebration
const char *nazov_spolc_alebo_jazyk[POCET_JAZYKOV + 1] =
{HTML_LINE_BREAK"alebo", HTML_LINE_BREAK"nebo", HTML_LINE_BREAK"or", "", "", HTML_LINE_BREAK"nebo", HTML_LINE_BREAK"vagy"};

// the names of the common texts (e.g.: for bishops, for saint men, for apostles...)
const char *nazov_spolc_jazyk[POCET_SPOL_CASTI + 1][POCET_JAZYKOV + 1] =
{{"neur�en�", "neur�ena", "not decided", "", "", "", ""}, 
 {"duchovn�ch pastierov: pre k�azov", "o duchovn�ch past���ch (o kn��ch)", "", "", "", "O duchovn�ch past���ch � o kn��ch", "lelkip�sztorok � papok"}, 
 {"duchovn�ch pastierov: pre biskupov", "o duchovn�ch past���ch (o biskupech)", "", "", "", "O duchovn�ch past���ch � o biskupech", "lelkip�sztorok � p�sp�k�k"}, 
 {"duchovn�ch pastierov: pre p�pe�ov", "o duchovn�ch past���ch (o pape�i)", "", "", "", "O duchovn�ch past���ch � o pape�i", "p�sztorok � p�pa"}, 
 {"u�ite�ov Cirkvi", "o u�itel�ch c�rkve", "", "", "", "O u�itel�ch C�rkve", "egyh�ztan�t�k"}, 
 {"apo�tolov", "o apo�tolech", "", "", "", "O apo�tolech", "apostolok"}, 
 {"jedn�ho mu�en�ka", "o jednom mu�edn�kovi", "", "", "", "O mu�edn�kovi", "v�rtan�"}, 
 {"viacer�ch mu�en�kov", "o v�ce mu�edn�c�ch", "", "", "", "O v�ce mu�edn�c�ch", "v�rtan�k"}, 
 {"Panny M�rie", "o Pann� Marii", "", "", "", "O Pann� Marii", "Sz�z M�ria"}, 
 {"sv�t�ch mu�ov: pre reho�n�kov", "o svat�ch mu�ech (o �eholn�c�ch)", "", "", "", "O �eholn�c�ch", "szerzetes"}, 
 {"sv�t�ch mu�ov", "o svat�ch mu��ch", "", "", "","O svat�ch mu��ch", "szent f�rfiak"}, 
 {"panien", "o pann�ch", "", "", "","O pann�ch", "sz�z"}, 
 {"sv�t�ch �ien: pre reho�nice", "svat�ch �en�ch (o �eholnic�ch)", "", "", "", "O svat�ch �en�ch - o �eholnic�ch", "ap�ca"}, 
 {"sv�t�ch �ien", "o svat�ch �en�ch", "", "", "", "O svat�ch �en�ch", "szent asszonyok"}, 
 {"duchovn�ch pastierov: pre viacer�ch", "o duchovn�ch past���ch", "", "", "", "O duchovn�ch past���ch", "t�bb lelkip�sztor"}, 
 {"jednej mu�enice", "o jedn� mu�ednici", "", "", "", "O mu�ednici", "v�rtan�"}, 
 {"sv�t�ch �ien: pre vychov�vate�ky", "o svat�ch �en�ch (o vychovatelk�ch)", "", "", "", "O svat�ch �en�ch - o vychovatelk�ch", "egyh�ztan�t� f�rfiak"}, 
 {"sv�t�ch mu�ov: pre vychov�vate�ov", "o svat�ch mu��ch (o vychovatel�ch)", "", "", "", "O svat�ch mu��ch � o vychovatel�ch", "egyh�ztan�t� asszonyok"}, 
 {"sv�t�ch �ien: pre tie, �o konali skutky milosrdenstva", "o svat�ch �en�ch (kter� vynikaly milosrdn�mi skutky)", "", "", "", "O svat�ch �en�ch � o �en�, kter� vynikala milosrdn�mi skutky", "j�t�konykod� asszonyok"}, 
 {"sv�t�ch mu�ov: pre t�ch, �o konali skutky milosrdenstva", "o svat�ch mu��ch (kter� vynikali milosrdn�mi skutky)", "", "", "", "O svat�ch mu��ch � o mu�i, kter� vynikal milosrdn�mi skutky", "j�t�konykod� f�rfiak"}, 
 {"sv�t�ch �ien: pre viacer�", "o svat�ch �en�ch (o v�ce �en�ch)", "", "", "", "O svat�ch �en�ch", "t�bb szent asszony"}, 
 {"sv�t�ch mu�ov: pre viacer�ch", "svat�ch mu�� � o v�ce mu��ch", "", "", "", "O svat�ch mu��ch", "t�bb szent f�rfi"}, 
 {"viacer�ch panien", "o pann�ch", "", "", "","O pann�ch", "sz�zek"}, 
 {"posviacky chr�mu", "o posv�cen� kostela", "", "", "", "Posv�cen� kostela", "templomszentel�s"}, 
 {"zosnul�ch", "za zem�el�", "", "", "","Za zem�el�", "halottak�rt"}, 
 {"sv�t�ch �ien: pre tie, �o �ili v man�elstve", "o svat�ch �en�ch (kter� �ily v man�elstv�)", "", "", "", "O svat�ch �en�ch � o �en�, kter� �ila v man�elstv�", "h�zas szent asszonyok"}, 
 {"sv�t�ch mu�ov: pre t�ch, �o �ili v man�elstve", "svat�ch mu��ch (kter� �ili v man�elstv�)", "", "", "", "O svat�ch mu��ch � o mu�i, kter� �il v man�elstv�", "h�zas szent f�rfiak"}, 
 {"nebra�", "nepou��t", "do not use", "", "", "nepou��t", "mindent saj�tb�l"}
};

#define		nazov_spolc(a)	nazov_spolc_jazyk[a][_global_jazyk]

const char *nazov_bit_opt_1_spomienka_spol_cast_jazyk[POCET_JAZYKOV + 1] =
{"bola zvolen� mo�nos� niektor� �asti pri sl�ven� spomienky vzia� zo d�a pod�a V�eobecn�ch smern�c, �. 235 p�sm. b", 
 "byla zvolena mo�nost vz�t p�i slaven� pam�tky n�kter� �asti ze dne podle V�eobecn�ch pokyn� k denn� modlitb� c�rkve, �. 235 p�sm. b", 
 "", 
 "", 
 "", 
 "byla zvolena mo�nost vz�t p�i slaven� pam�tky n�kter� �asti ze dne podle V�eobecn�ch pokyn� k denn� modlitb� C�rkve, �. 235 p�sm. b", 
 "az a lehet�s�g volt v�lasztva, hogy az eml�knapokn�l bizonyos r�szek vehet�k a soros k�znapr�l; �ltal�nos Rendelkez�sek az Ima�r�k Liturgi�j�r�l, 235 b"
};

// filenames - same for all languages (based on Slovak)
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

// anchor names in files - same for all languages (based on Slovak)
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

// the names of liturgical periods (usually lowecase) / nazov_obdobia: string pre nazov liturgickeho obdobia
const char *nazov_obdobia_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{
 {"adventn� obdobie", "doba adventn�", "", "tempus adventus", "", "doba adventn�", "adventi id�"},
 {"adventn� obdobie", "doba adventn�", "", "tempus adventus", "", "doba adventn�", "adventi id�"},
 {"okt�va Narodenia P�na", "okt�v Narozen� P�n�", "", "octava nativitatis", "", "okt�v Narozen� P�n�", "kar�csony nyolcada"},
 {"viano�n� obdobie", "doba v�no�n�", "", "tempus nativitatis", "", "doba v�no�n�", "kar�csonyi id�"},
 {"viano�n� obdobie", "doba v�no�n�", "", "tempus nativitatis", "", "doba v�no�n�", "kar�csonyi id�"},
 {"cezro�n� obdobie", "mezidob�", "", "tempus per annum", "", "mezidob�", "�vk�zi id�"},
 {"p�stne obdobie", "doba postn�", "", "tempus quadragesimae", "", "doba postn�", "nagyb�jti id�"},
 {"Ve�k� t��de�", "Svat� t�den", "", "hebdomada sancta", "", "Svat� t�den", "nagyh�t"},
 {"ve�kono�n� trojdnie", "Velikono�n� triduum", "", "sacrum triduum paschale", "", "Velikono�n� triduum", "szent h�rom nap"},
 {"ve�kono�n� okt�va", "velikono�n� okt�v", "", "octava paschae", "", "velikono�n� okt�v", "h�sv�t nyolcada"},
 {"ve�kono�n� obdobie", "doba velikono�n�", "", "tempus paschale", "", "doba velikono�n�", "h�sv�ti id�"},
 {"ve�kono�n� obdobie", "doba velikono�n�", "", "tempus paschale", "", "doba velikono�n�", "h�sv�ti id�"},
};

#define		nazov_obdobia(a)	nazov_obdobia_jazyk[a][_global_jazyk]

// the names of liturgical periods (usually lowecase) / nazov_obdobia: string pre n�zov liturgick�ho obdobia, roz��ren�
const char *nazov_obdobia_ext_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{
 {"adventn� obdobie I (do 16. decembra)", "doba adventn� I", "", "tempus adventus I", "", "doba adventn� I", "adventi id� I (dec.16-ig)"},
 {"adventn� obdobie II (po 16. decembri)", "doba adventn� II", "", "tempus adventus II", "", "doba adventn� II", "adventi id� II (dec.16 ut�n)"},
 {"okt�va Narodenia P�na", "okt�v Narozen� P�n�", "", "octava nativitatis", "", "okt�v Narozen� P�n�", "kar�csony nyolcada"},
 {"viano�n� obdobie I (do Zjavenia P�na)", "doba v�no�n� I", "", "tempus nativitatis I", "", "doba v�no�n� II", "kar�csonyi id� I (Urunk megjelen�s�ig)"},
 {"viano�n� obdobie II (po Zjaven� P�na)", "doba v�no�n� II", "", "tempus nativitatis II", "", "doba v�no�n� II", "kar�csonyi id� II (Urunk megjelen�se ut�n)"},
 {"cezro�n� obdobie", "mezidob�", "", "tempus per annum", "", "mezidob�", "�vk�zi id�"},
 {"p�stne obdobie I (do Kvetnej nedele)", "doba postn� I", "", "tempus quadragesimae I", "", "doba postn� I", "nagyb�jti id� I (Vir�gvas�rnapig)"},
 {"p�stne obdobie II (ve�k� t��de�)", "Svat� t�den", "", "hebdomada sancta", "", "Svat� t�den", "nagyb�jti id� II (Nagyh�t)"},
 {"ve�kono�n� trojdnie", "Velikono�n� triduum", "", "sacrum triduum paschale", "", "Velikono�n� triduum", "szent h�rom nap"},
 {"ve�kono�n� okt�va", "velikono�n� okt�v", "", "octava paschae", "", "velikono�n� okt�v", "h�sv�t nyolcada"},
 {"ve�kono�n� obdobie I (do Nanebovst�penia P�na)", "doba velikono�n� I", "", "tempus paschale I", "", "doba velikono�n� I", "h�sv�ti id� I (Urunk mennybemenetel�ig)"},
 {"ve�kono�n� obdobie II (po Nanebovst�pen� P�na)", "doba velikono�n� II", "", "tempus paschale II", "", "doba velikono�n� II", "h�sv�ti id� II (Urunk mennybemenetele ut�n)"},
};

#define		nazov_obdobia_ext(a)	nazov_obdobia_ext_jazyk[a][_global_jazyk]

// the names of liturgical periods for debugging, only in Slovak; no need to translate
const char *nazov_obdobia_[POCET_OBDOBI + 1] = // debuggovacie - preto netreba preklada�; 2006-08-03
{
 "adventn� obdobie I", "adventn� obdobie II", "okt�va Narodenia P�na",
 "viano�n� obdobie I", "viano�n� obdobie II", "cezro�n� obdobie", 
 "p�stne obdobie I", "p�stne obdobie II (Ve�k� t��de�)",
 "ve�kono�n� trojdnie", "ve�kono�n� okt�va", "ve�kono�n� obdobie I", "ve�kono�n� obdobie II",
};

// the names of liturgical periods in local grammatically 6.th declination? (usually lowecase); in English: "IN liturgical period" or "OF liturgical period" / lokal == 6. pad, v kom/com
const char *nazov_obdobia_v_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{
 {"v adventnom obdob�", "v dob� adventn�", "", "", "", "v dob� adventn�", "adventben"},
 {"v adventnom obdob�", "v dob� adventn�", "", "", "", "v dob� adventn�", "adventben"},
 {"v okt�ve Narodenia P�na", "v okt�vu Narozen� P�n�", "", "", "", "v okt�vu Narozen� P�n�", "Kar�csony nyolcad�ban"},
 {"vo viano�nom obdob�", "v dob� v�no�n�", "", "", "", "v dob� v�no�n�", "a kar�csonyi id�ben"},
 {"vo viano�nom obdob�", "v dob� v�no�n�", "", "", "", "v dob� v�no�n�", "a kar�csonyi id�ben"},
 {"v cezro�nom obdob�", "v mezidob�", "", "per annum", "", "v mezidob�", "az �vk�zi id�ben"},
 {"v p�stnom obdob�", "v dob� postn�", "", "", "", "v dob� postn�", "a nagyb�jti id�ben"},
 {"vo Ve�kom t��dni", "ve Svat�m t�dnu", "", "", "", "ve Svat�m t�dnu", "a nagyh�ten"},
 {"vo ve�kono�nom trojdn�", "ve velikono�n�m triduu", "", "", "", "ve velikono�n�m triduu", "a szent h�rom napban"},
 {"vo ve�kono�nej okt�ve", "ve velikono�n�m okt�vu", "", "", "", "ve velikono�n�m okt�vu", "h�sv�t nyolcad�ban"},
 {"vo ve�kono�nom obdob�", "v dob� velikono�n�", "", "", "", "v dob� velikono�n�", "a h�sv�ti id�ben"},
 {"vo ve�kono�nom obdob�", "v dob� velikono�n�", "", "", "", "v dob� velikono�n�", "a h�sv�ti id�ben"},
};

#define		nazov_obdobia_v(a)	nazov_obdobia_v_jazyk[a][_global_jazyk]

// the names of liturgical periods in local grammatically 6.th declination? (uppercase) / nazov_obdobia: string pre nazov liturgickeho obdobia
const char *nazov_OBDOBIA_V_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{
 {"V ADVENTNOM OBDOB�", "V DOB� ADVENTN�", "", "", "", "V DOB� ADVENTN�", "ADVENTBEN"},
 {"V ADVENTNOM OBDOB�", "V DOB� ADVENTN�", "", "", "", "V DOB� ADVENTN�", "ADVENTBEN"},
 {"V OKT�VE NARODENIA P�NA", "V OKT�VU NAROZEN� P�N�", "", "", "", "V OKT�VU NAROZEN� P�N�", "A KAR�CSONY NYOLCAD�BAN"},
 {"VO VIANO�NOM OBDOB�", "V DOB� V�NO�N�", "", "", "", "V DOB� V�NO�N�", "A KAR�CSONYI ID�BEN"},
 {"VO VIANO�NOM OBDOB�", "V DOB� V�NO�N�", "", "", "", "V DOB� V�NO�N�", "A KAR�CSONYI ID�BEN"},
 {"V CEZRO�NOM OBDOB�", "V MEZIDOB�", "", "", "", "B�HEM ROKU", "AZ �VK�ZI ID�BEN"},
 {"V P�STNOM OBDOB�", "V DOB� POSTN�", "", "", "", "V DOB� POSTN�", "A NAGYB�JTI ID�BEN"},
 {"VO VE�KOM TݎDNI", "VE SVAT�M T�DNU", "", "", "", "VE SVAT�M T�DNU", "A NAGYH�TEN"},
 {"VO VE�KONO�NOM TROJDN�", "VE VELIKONO�N�M TRIDUU", "", "", "", "VE VELIKONO�N�M TRIDUU", "A SZENT H�ROM NAPBAN"},
 {"VO VE�KONO�NEJ OKT�VE", "VE VELIKONO�N�M OKT�VU", "", "", "", "V OKT�VU VELIKONO�N�M", "H�SV�T NYOLCACAD�BAN"},
 {"VO VE�KONO�NOM OBDOB�", "V DOB� VELIKONO�N�", "", "", "", "V DOB� VELIKONO�N�", "A H�SV�TI ID�BEN"},
 {"VO VE�KONO�NOM OBDOB�", "V DOB� VELIKONO�N�", "", "", "", "V DOB� VELIKONO�N�", "A H�SV�TI ID�BEN"},
};

#define		nazov_OBDOBIA_V(a)	nazov_OBDOBIA_V_jazyk[a][_global_jazyk]

// used for Sundays - "which" Sunday for some of them, e.g. "dominica V paschae" for 5-th Sunday in that liturgical period (uppercase)
// 2008-12-20: doplnen� - pou��va sa v init_global_string() pre nedele niektor�ch obdob� [zatia� iba v sloven�ine]
const char *nazov_OBDOBIA_AKA_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{
 {"ADVENTN�", "ADVENTN�", "", "", "", "ADVENTN�", "ADVENT"},
 {"ADVENTN�", "ADVENTN�", "", "", "", "ADVENTN�", "ADVENT"},
 {"V OKT�VE NARODENIA P�NA", "V OKT�VU NAROZEN� P�N�", "", "", "", "V OKT�VU NAROZEN� P�N�", "A KAR�CSONY NYOLCAD�BAN"}, // not used / nepou��va sa
 {"VIANO�N�", "V�NO�N�", "", "", "", "V�NO�N�", "KAR�CSONY"},
 {"VIANO�N�", "V�NO�N�", "", "", "", "V�NO�N�", "KAR�CSONY"},
 {"CEZRO�N�", "V MEZIDOB�", "", "", "", "B�HEM ROKU", "�VK�ZI"},
 {"P�STNA", "POSTN�", "", "", "", "POSTN�", "NAGYB�JT"},
 {"VO VE�KOM TݎDNI", "VE SVAT�M T�DNU", "", "", "", "VE SVAT�M T�DNU", "hu_"}, // not used / nepou��va sas
 {"VO VE�KONO�NOM TROJDN�", "VE VELIKONO�N�M TRIDUU", "", "", "", "VE VELIKONO�N�M TRIDUU", "hu_"}, // not used / nepou��va sa
 {"VO VE�KONO�NEJ OKT�VE", "VE VELIKONO�N�M OKT�VU", "", "", "", "V OKT�VU VELIKONO�N�M", "H�SV�T NYOLCACAD�BAN"}, // not used / nepou��va sa
 {"VE�KONO�N�", "VELIKONO�N�", "", "", "", "VELIKONO�N�", "H�SV�T"},
 {"VE�KONO�N�", "VELIKONO�N�", "", "", "", "VELIKONO�N�", "H�SV�T"},
};
#define		nazov_OBDOBIA_AKA(a)	nazov_OBDOBIA_AKA_jazyk[a][_global_jazyk]

// filenames - same for all languages (based on Slovak)
// nazov_obdobia: string pre nazov suboru .htm liturgickeho obdobia
const char *nazov_obd_htm[POCET_OBDOBI + 1] =
{"adv1.htm", "adv2.htm", "vian1.htm",
 "vian1.htm", "vian2.htm", "cezrok.htm",
 "post1.htm", "vtyz.htm",
 "vtroj.htm", "vnokt.htm", "vn1.htm", "vn2.htm"
};

// anchor names in files - same for all languages (based on Slovak)
// nazov_obdobia: string pre nazov kotvy v .htm liturgickeho obdobia
const char *nazov_OBD[POCET_OBDOBI + 1] =
{"ADV1", "ADV2", "OKTNAR",
 "VIAN1", "VIAN2", "OCR",
 "POST1", "VTYZ", 
 "VTROJ", "VNOKT", "VN1", "VN2"
};

// filenames - same for all languages (based on Slovak)
// nazov_obdobia pc: string pre nazov suboru .htm liturgickeho obdobia pre posvatne citania
const char *nazov_obd_htm_pc[POCET_OBDOBI + 1] =
{"adv1_pc.htm", "adv2_pc.htm", "vian1_pc.htm",
 "vian1_pc.htm", "vian2_pc.htm", "cezrok_pc.htm",
 "post1_pc.htm", "vtyz_pc.htm",
 "vtroj_pc.htm", "vnokt_pc.htm", "vn1_pc.htm", "vn2_pc.htm"
};

// anchor names in files used for 4 volumes of breviary - same for all languages (based on Slovak)
// 2005-08-05: Pridan�. zv�zok brevi�ra (LH) pre spolo�n� �asti sv�t�ch v kotv�ch
const char *zvazok_OBD[POCET_OBDOBI + 1] =
{"ZVI", "ZVI", "ZVI",
 "ZVI", "ZVI", "OCR", // OCR je ZVIII aj ZVIV
 "ZVII", "ZVII",
 "ZVII", "ZVII", "ZVII", "ZVII"
};

// the name of celebration
const char *nazov_slavenia_jazyk[POCET_SLAVENI + 1][POCET_JAZYKOV + 1] =
{{"f�ria", "f�rie", "feria", "feria", "f�rie", "f�ria", "f�ria"}, // zmenen� z "___", 2012-10-12
 {"sl�vnos�", "slavnost", "celebration", "sollemnitas", "","SLAVNOST", "f��nnep"},
 {"sviatok", "sv�tek", "", "festum", "","Sv�tek", "�nnep"},
 {"spomienka", "pam�tka", "", "memoria", "","Pam�tka", "eml�knap"},
 {"�ubovo�n� spomienka", "nez�vazn� pam�tka", "", "memoria ad libitum", "","nez�vazn� pam�tka", "tetsz�s szerinti eml�knap"},
 {"vlastn� sl�venie", "z vlastn�ch text�", "", "textus proprius", "", "z vlastn�ch text�", "saj�t sz�veg"},
};

#define		nazov_slavenia(a)	nazov_slavenia_jazyk[a][_global_jazyk]

// the name of celebration -- for memoria (in privileged days)
const char *nazov_slavenia_na_spomienku_jazyk[POCET_JAZYKOV + 1] =
{"na spomienku" /* Adam: lep�ie by bolo: pripomienka */, "pro p�ipom�nku", "", "in memoria", "","pro p�ipom�nku", "megeml�kez�s�l"};

// 2010-08-03: pridan� kalend�r

// calendar codes; internal usage for HTTP requests
const char *skratka_kalendara[POCET_KALENDAROV + 1] =
{"??", "la", "sk", "cz", "czop", "cssr", "hu", "svd", "sj", "sdb", "ofm", "op", "cm", "opraem"};

// filenames for special calendars / n�zov s�bora pre kalend�re -- "pro" == propri�
const char *nazov_htm_kalendar[POCET_KALENDAROV + 1] =
{"", "", "", "", "", "pro_cssr.htm", "", "pro_svd.htm", "pro_sj.htm", "pro_sdb.htm", "pro_ofm.htm", "pro_op.htm", "pro_cm.htm", "pro_opraem.htm"};

const char *nazov_kalendara_short[POCET_KALENDAROV + 1] =
{"neur�en�"
,"v�eobecn�"
,"v�eobecn� SK"
,"v�eobecn� CZ"
,"CZOP"
,"SK CSSR"
,"v�eobecn� HU"
,"SK SVD"
,"SK SJ"
,"SK SDB"
,"SK OFM"
,"SK OP"
,"SK CM"
,"CZ OPRAEM"
};

// doplnen� 2010-10-11
const char *nazov_kalendara_long[POCET_KALENDAROV + 1] =
{""
,""
,"v�eobecn� [pre Slovensko]"
,"obecn� [pro �echy a Moravu]"
,""
,"pre Kongreg�ciu najsv. Vykupite�a � redemptoristov (CSsR)" // bol ve�mi dlh� combo-box, ke� bolo: "pre Kongreg�ciu najsv�tej�ieho Vykupite�a � redemptoristov (CSsR)"
,""
,"pre Spolo�nos� Bo�ieho Slova � verbistov (SVD)"
,"pre Spolo�nos� Je�i�ovu � jezuitov (SJ)"
,"pre salezi�nsku rodinu � SDB, FMA, ASC" // bolo VDB -> ASC; salezi�ni spolupracovn�ci maj� skratku ASC - Associazione dei salesiani cooperatori - teda Zdruzenie salezianov spolupravovnikov (upozornil Ma�o Linhart, 2012-02-13)
// ,"pre franti�k�nsku rodinu � franti�k�nov<!-- (OFM)-->, kapuc�nov<!-- (OFMCap)-->, minoritov<!-- (OFMConv)-->" // 2011-03-21: nefungovalo porovnanie atokalendar lebo HTML odstr�nilo pozn�mky
// ,"pre franti�k�nsku rodinu � franti�k�nov, kapuc�nov, minoritov" // 2011-03-22: s� tam aj mnoh� �al�ie rehole a kongreg�cie, tak�e ma br. Jakub OFM poprosil, aby ostalo iba "pre franti�k�nsku rodinu"
,"pre franti�k�nsku rodinu"
,"pre Reho�u kazate�ov � dominik�nov (OP)"
,"pre Misijn� spolo�nos� sv. Vincenta de Paul � lazaristov (CM)"
,"s vlastn�mi texty premonstr�tsk�ho ��du (OPraem)" // "pro premonstr�ty (OPraem)"
};

// special "local" or "partial" characteristics of various celebrations - each in one language; no need to translate; special strings will be added
// 2007-08-31: upraven� TT -> BA-TT
// 2008-06-23: upraven� vzh�adom k nov�mu usporiadaniu diec�z (intuit�vne)
// 2010-03-16: doplnen� BA
// 2011-07-25: doplnen� n�zvy ��seln�ch kon�t�nt
const char *nazov_slavenia_lokal[] =
{""                                                                                                             // LOKAL_SLAV_NEURCENE
,"len v ro��avskej katedr�le"                                                                                   // LOKAL_SLAV_ROZNAVA_KATEDRALA
,"hlavn� patr�n Trnavskej arcidiec�zy"                                                                          // LOKAL_SLAV_TRNAVA_PATRON
,"v Bratislavskej, Trnavskej a Ko�ickej arcidiec�ze "HTML_LINE_BREAK"a v Banskobystrickej, Nitrianskej a Ro��avskej diec�ze" // LOKAL_SLAV_TT_BB_KE_NR_RO
,"v Nitrianskej diec�ze sviatok hlavn�ch patr�nov"                                                              // LOKAL_SLAV_NITRA_PATRON
,"len v Ko�ickej arcidiec�ze"                                                                                   // LOKAL_SLAV_KOSICE
,"len v Nitrianskej diec�ze"                                                                                    // LOKAL_SLAV_NITRA
,"len v Banskobystrickej diec�ze"                                                                               // LOKAL_SLAV_BYSTRICA
,"len v Spi�skej diec�ze"                                                                                       // LOKAL_SLAV_SPIS
,"len v Ro��avskej diec�ze"                                                                                     // LOKAL_SLAV_ROZNAVA
,"len v Trnavskej arcidiec�ze"                                                                                  // LOKAL_SLAV_TRNAVA
,"len v D�me sv. Martina v Bratislave"                                                                          // LOKAL_SLAV_DOM_SV_MARTINA
,"v Spi�skej diec�ze sviatok hlavn�ho patr�na"                                                                  // LOKAL_SLAV_SPIS_PATRON
,"v Banskobystrickej diec�ze sviatok hlavn�ho patr�na"                                                          // LOKAL_SLAV_BYSTRICA_PATRON
,"v Bratislavskej a Trnavskej arcidiec�ze "HTML_LINE_BREAK"a v Banskobystrickej, Nitrianskej a Ro��avskej diec�ze"           // LOKAL_SLAV_TT_BB_NR_RO
,"v Ko�ickej arcidiec�ze sviatok hlavn�ho patr�na"                                                              // LOKAL_SLAV_KOSICE_PATRON
,"v �ilinskej diec�ze sviatok hlavn�ch patr�nov; "HTML_LINE_BREAK"na Slovensku sa sl�vi 5. j�la, sl�vnos�; v Eur�pe sviatok" // LOKAL_SLAV_14_FEB_CYRIL_METOD
,"v Ro��avskej diec�ze sviatok hlavn�ho patr�na"                                                                // LOKAL_SLAV_ROZNAVA_PATRON
,"len v konsekrovan�ch kostoloch"                                                                               // LOKAL_SLAV_KONSEKR_KOSTOLY
,"Druh� ve�kono�n� nede�a � Bo�ieho milosrdenstva"                                                              // LOKAL_SLAV_DRUHA_VELK_NEDELA
,"koniec Okt�vy narodenia P�na"                                                                                 // LOKAL_SLAV_KONIEC_OKTAVY_NAR
,"konec Okt�vu Narozen� P�n�"                                                                                   // LOKAL_SLAV_KONIEC_OKTAVY_NAR_CZ
,"hlavn�ho patrona pra�sk� arcidiec�ze"                                                                         // LOKAL_SLAV_PRAHA_PATRON
,"v pra�sk� arcidiec�zi"                                                                                        // LOKAL_SLAV_PRAHA
,"v brn�nsk� diec�zi"                                                                                           // LOKAL_SLAV_BRNO
,"na Morav� pam�tka"                                                                                            // LOKAL_SLAV_MORAVA_SPOMIENKA
,"Druh� ned�le velikono�n� � Bo��ho milosrdenstv�"                                                              // LOKAL_SLAV_DRUHA_VELK_NEDELA_CZ
,"v pra�sk� katedr�le slavnost"                                                                                 // LOKAL_SLAV_PRAHA_KATEDRALA
,"v �eskobud�jovick� diec�zi"                                                                                   // LOKAL_SLAV_CESKE_BUDEJOVICE
,"v olomouck� arcidiec�zi"                                                                                      // LOKAL_SLAV_OLOMOUC
,"v �ech�ch sv�tek"                                                                                             // LOKAL_SLAV_CECHY_SPOMIENKA
,"v plze�sk� diec�zi sv�tek hlavn�ho patrona"                                                                   // LOKAL_SLAV_PLZEN_PATRON
,"v ostravsko-opavsk� diec�zi"                                                                                  // LOKAL_SLAV_OSTRAVA_OPAVA
,"v litom��ick� diec�zi"                                                                                        // LOKAL_SLAV_LITOMERICE
,"v kr�lov�hradeck� diec�zi"                                                                                    // LOKAL_SLAV_HRADEC_KRALOVE
,"jen v posv�cen�ch kostel�ch"                                                                                  // LOKAL_SLAV_KONSEKR_KOSTOLY_CZ 
,"v plze�sk� diec�zi"                                                                                           // LOKAL_SLAV_PLZEN 
,"ve Slezsku sv�tek"                                                                                            // LOKAL_SLAV_SLEZSKO_SVATEK
,"v �eskobud�jovick� diec�zi pam�tka"                                                                           // LOKAL_SLAV_CESKE_BUDEJOVICE_PAMATKA
,"v Bratislavskej arcidiec�ze a v Spi�skej diec�ze sviatok hlavn�ho patr�na"                                    // LOKAL_SLAV_SPIS_BA_PATRON
,"v Bratislavskej arcidiec�ze"                                                                                  // LOKAL_SLAV_BRATISLAVA
,"Kar�csony nyolcada-Kiskar�csony"                                                                              // LOKAL_SLAV_KONIEC_OKTAVY_NAR_HU
,"len pre Kongreg�ciu milosrdn�ch sestier Sv. kr�a"                                                            // LOKAL_SLAV_KONGREGACIA_SSK
,"pre OFMCap: spomienka"                                                                                        // LOKAL_SLAV_SPOMIENKA_OFMCAP
,"pre OFM: sviatok"                                                                                             // LOKAL_SLAV_SVIATOK_OFM
,"pre OFM: spomienka"                                                                                           // LOKAL_SLAV_SPOMIENKA_OFM
,"pre OFMCap: sviatok"                                                                                          // LOKAL_SLAV_SVIATOK_OFMCAP
,"pre FMA: spomienka"                                                                                           // LOKAL_SLAV_SPOMIENKA_FMA
,"pre FMA: sl�vnos�"                                                                                            // LOKAL_SLAV_SLAVNOST_FMA
,"pre SDB: sl�vnos�"                                                                                            // LOKAL_SLAV_SLAVNOST_SDB
,"pre ASC: sviatok"                                                                                             // LOKAL_SLAV_SVIATOK_VDB // VDB -> ASC
,"pre SCSC: sviatok"                                                                                            // LOKAL_SLAV_SVIATOK_SCSC
,"H�sv�t 2. vas�rnapja � Az Isteni Irgalmass�g vas�rnapja"                                                      // LOKAL_SLAV_DRUHA_VELK_NEDELA_HU
,"A Szombathelyi egyh�zmegy�ben"                                                                                // LOKAL_SLAV_SZOMBATHELYI_EGYH
,"Pozsonyi f�egyh�zmegye �s a Nagyszombati egyh�zmegye f�p�tronusa"                                             // LOKAL_SLAV_POZS_NAGYSZ_PATRON
,"A Szeged-Csan�di egyh�zmegye �szaki r�sz�ben: az egyh�zmegye v�d�szentje; f��nnep"                            // LOKAL_SLAV_SZEGED_CSAN_PATRON
,"A P�csi egyh�zmegy�ben"                                                                                       // LOKAL_SLAV_PECSI_EGYH
,"A P�csi egyh�zmegy�ben: az egyh�zmegye v�d�szentje; �nnep"                                                    // LOKAL_SLAV_PECSI_EGYH_PATRON
,"A Szeged-Csan�di egyh�zmegye �szaki r�sz�ben; �nnep"                                                          // LOKAL_SLAV_SZEGED_CSAN_EGYH
,"A Veszpr�mi egyh�zmegy�ben: Szent Anna, az egyh�zmegye v�d�szentje; �nnep"                                    // LOKAL_SLAV_VESZPREMI_EGYH_PATRON
,"A gy�ri �s sz�kesfeh�rv�ri egyh�zmegy�ben: az egyh�zmegye v�d�szentje"                                        // LOKAL_SLAV_GYORI_SZEKESFEH_EGYH
,"A Kaposv�ri egyh�zmegy�ben; �nnep"                                                                            // LOKAL_SLAV_KAPORSVAR_FELSZ
,"A V�ci egyh�zmegy�ben; �nnep"                                                                                 // LOKAL_SLAV_VACI_FELSZ
,"Kalocsa-Kecskem�t: a f�egyh�zmegye v�d�szentje; f��nnep"                                                      // LOKAL_SLAV_KAL_KECS_FOEGYH
,"A Esztergom-Budapest, a f�sz�kesegyh�zban; f��nnep"                                                           // LOKAL_SLAV_ESZTERGOM_BUDA_FOEGYH
,"A f�sz�kesegyh�zban; f��nnep"                                                                                 // LOKAL_SLAV_KAL_KECS_FELSZ
,"A Gy�ri egyh�zmegy�ben: sz�kesegyh�z felszentel�se; �nnep"                                                    // LOKAL_SLAV_GYORI_SZEKESEGYH_FELSZ
,"A V�ci egyh�zmegy�ben: Szent Mih�ly f�angyal, az egyh�zmegye v�d�szentje"                                     // LOKAL_SLAV_VACI_PATRON
,"A Szeged-Csan�d: az egyh�zmegye v�d�szentje; f��nnep"                                                         // LOKAL_SLAV_SZEGED_CSAN_PATRON2
,"A Veszpr�m, a f�sz�kesegyh�zban; f��nnep"															            // LOKAL_SLAV_VESZPREM_FOEGYH
,"csak a felszentelt templomokban"                                                                              // LOKAL_SLAV_KONSEKR_KOSTOLY_HU
,"A Szeged-Csan�d: A sz�kesegyh�zban; f��nnep"                                                                  // LOKAL_SLAV_SZEGED_CSAN_EGYH2
,"A P�csi egyh�zmegy�ben: A P�csi egyh�zmegye t�rsv�d�szentje; f��nnep"                                         // LOKAL_SLAV_PECS_PATRON
,"Szombathely: Az egyh�zmegye v�d�szentje; f��nnep"                                                             // LOKAL_SLAV_SZOMBATHELYI_PATRON
,"Sz�kesfeh�rv�r: A sz�kesegyh�zban; f��nnep"                                                                   // LOKAL_SLAV_SZEKESFEHERVAR_EGYH
,"Az Egri f�egyh�zmegy�ben: A f�egyh�zmegye v�d�szentje; �nnep"                                                 // LOKAL_SLAV_EGER_FOEGYH
,"Az Esztergomi f�egyh�zmegy�ben; eml�knap"                                                                     // LOKAL_SLAV_ESZTERGOM_EML
,"A Gy�ri egyh�zmegy�ben"                                                                                       // LOKAL_SLAV_GYOR_EGYH
,"Az Esztergomi f�egyh�zmegy�ben"                                                                               // LOKAL_SLAV_ESZTERGOM_FOEGYH
,"Az Egri f�egyh�zmegy�ben"                                                                                     // LOKAL_SLAV_EGER_FOEGYH2
,"A Veszpr�m, a f�egyh�zmegye t�rsv�d�szentje; f��nnep"                                                         // LOKAL_SLAV_VESZPREM_FOEGYH_T
,"A Szatm�ri egyh�zmegy�ben; eml�knap"                                                                          // LOKAL_SLAV_SZATMAR
,"v ostatn�ch �esk�ch diec�z�ch a v brn�nsk� diec�zi: pam�tka; "HTML_LINE_BREAK"na Morav� mimo brn�nskou diec�zi: nez�vazn� pam�tka" // LOKAL_SLAV_CESKO_BRNO
,"sviatok hlavnej patr�nky "HTML_LINE_BREAK"(slovenskej) Kongreg�cie sestier dominik�nok bl. Imeldy"            // LOKAL_SLAV_SVIATOK_OP_ZENY
,"len v �ilinskej diec�ze"                                                                                      // LOKAL_SLAV_ZILINA
,"na Strahov�: sv�tek, Nov� ��e: pam�tka"                                                                      // LOKAL_SLAV_OPRAEM_SVIATOK_STRAHOV
,"kanonie Tepl�: slavnost"                                                                                      // LOKAL_SLAV_OPRAEM_SLAVNOST_TEPLA
,"jen kanonie Nov� ��e"                                                                                        // LOKAL_SLAV_OPRAEM_NOVA_RISE
,"jen kanonie Strahov a Nov� ��e"                                                                              // LOKAL_SLAV_OPRAEM_STRAHOV_NOVA_RISE
,"jen kanonie �eliv"                                                                                            // LOKAL_SLAV_OPRAEM_ZELIV
,"jen kanonie Strahov"                                                                                          // LOKAL_SLAV_OPRAEM_STRAHOV
};

// names of liturgical colors
const char *nazov_farby_jazyk[POCET_FARIEB_REALNYCH + 1][POCET_JAZYKOV + 1] =
{{"___", "___", "___", "___", "___", "___", "___"},
 {"�erven�", "�erven�", "red", "ruber", "", "�erven�", "piros"},
 {"biela", "b�l�", "white", "albus", "", "b�l�", "feh�r"},
 {"zelen�", "zelen�", "green", "viridis", "", "zelen�", "z�ld"},
 {"fialov�", "fialov�", "purple", "violaceus", "", "fialov�", "lila"},
 {"ru�ov�", "r��ov�", "rose", "rosaceus", "", "r��ov�", "r�zsasz�n"},
 {"�ierna", "�ern�", "black", "niger", "", "�ern�", "fekete"},
};

#define		nazov_farby(a)	nazov_farby_jazyk[a][_global_jazyk]

// 2009-08-26: zmena na �tandardn� HTML elementy, aby sa dalo pou��va� ako inline CSS style
// codes for colors - HTML specific
const char *html_farba_pozadie[POCET_FARIEB_REALNYCH + 1] =
{"#000000" /* "black" */, "#ff0000" /* "red" */, "#ffffff" /* "white" */, "#008000" /* "green" */, "#800080" /* "purple" */, "#FF6699" /* "fuchsia" */, "#000000" /* black */};

// codes for colors - HTML specific
const char *html_farba_popredie[POCET_FARIEB_REALNYCH + 1] =
{"#ffffff" /* "white" */, "#ffffff" /* "white" */, "#000000" /* "black" */, "#ffffff" /* "white" */, "#ffffff" /* "white" */, "#0000ff" /* "blue" */, "#ffffff" /* "white" */};

// codes for colors - HTML specific
const char *html_farba_okraj[POCET_FARIEB_REALNYCH + 1] =
{"#000000" /* "black" */, "#000000" /* "black" */, "#000000" /* "black" */, "#000000" /* "black" */, "#000000" /* "black" */, "#000000" /* "black" */, "#000000" /* black */};

// 2011-03-24: pridan� pre kalend�rik
const char *html_farba_pozadie_cal = "#000000";
const char *html_farba_popredie_cal = "#ffffff";

// codes for number of the week from psaltery (psalterium per quattuor hebdomadas distributum)
const char *rimskymi_tyzden_zaltara[ZVAZKY_LH + 1] =
{"_", "I", "II", "III", "IV"};

// const: ordinal number of the first day in specific month
const short int prvy_den[12] =
	{1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};

// const: number (count) of days in specific month
short int pocet_dni[12] =
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// const: "the Sunday's letter" A--g
const char char_nedelne_pismeno[POCET_DNI] =
	{'b', 'c', 'd', 'e', 'f', 'g', 'A'};

// const: the Sunday's cycle A--C
const char char_nedelny_cyklus[POCET_NEDELNY_CYKLUS] =
	{'A', 'B', 'C'};

// names of the days in week, starting with Sunday (lowercase) / nazov_dna: string pre nazov dna; suhlasi s struct tm.tm_wday; 
// Weekday (0--6; Sunday/nedela = 0)
const char *nazov_dna_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{ {"nede�a", "ned�le", "Sunday", "dominica", "", "ned�le", "vas�rnap"}
, {"pondelok" , "pond�l�", "Monday", "feria secunda", "", "pond�l�", "h�tf�"}
, {"utorok" , "�ter�", "Tuesday", "feria tertia", "", "�ter�", "kedd"}
, {"streda" , "st�eda", "Wednesday", "feria quarta", "", "st�eda", "szerda"}
, {"�tvrtok" , "�tvrtek", "Thursday", "feria quinta", "", "�tvrtek", "cs�t�rt�k"}
, {"piatok" , "p�tek", "Friday", "feria sexta", "", "p�tek", "p�ntek"}
, {"sobota" , "sobota", "Saturday", "sabbatum", "", "sobota", "szombat"}
, {"nezn�my" , "nezn�m�", "unknown", "???", "", "nezn�m�", "ismeretlen"}
};

#define		nazov_dna(a)	nazov_dna_jazyk[a][_global_jazyk]

// names of the days in week, starting with Sunday (lowercase without special characters - plain ASCII (0--128) only)
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

// names of the days in week, starting with Sunday (sentence case)
const char *nazov_Dna_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{ {"Nede�a", "Ned�le", "Sunday", "Dominica", "", "Ned�le", "Vas�rnap"}
, {"Pondelok" , "Pond�l�", "Monday", "Feria secunda", "", "Pond�l�", "H�tf�"}
, {"Utorok" , "�ter�", "Tuesday", "Feria tertia", "", "�ter�", "Kedd"}
, {"Streda" , "St�eda", "Wednesday", "Feria quarta", "", "St�eda", "Szerda"}
, {"�tvrtok" , "�tvrtek", "Thursday", "Feria quinta", "", "�tvrtek", "Cs�t�rt�k"}
, {"Piatok" , "P�tek", "Friday", "Feria sexta", "", "P�tek", "P�ntek"}
, {"Sobota" , "Sobota", "Saturday", "Sabbatum", "", "Sobota", "Szombat"}
, {"Nezn�my" , "Nezn�m�", "unknown", "???", "", "Nezn�m�", "Ismeretlen"}
};

#define		nazov_Dna(a)	nazov_Dna_jazyk[a][_global_jazyk]

// names of the days in week, starting with Sunday (uppercase)
const char *nazov_DNA_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{ {"NEDE�A", "NED�LE", "SUNDAY", "DOMINICA", "", "NED�LE", "VAS�RNAP"}
, {"PONDELOK" , "POND�L�", "MONDAY", "FERIA SECUNDA", "", "POND�L�", "H�TF�"}
, {"UTOROK" , "�TER�", "TUESDAY", "FERIA TERTIA", "", "�TER�", "KEDD"}
, {"STREDA" , "ST�EDA", "WEDNESDAY", "FERIA QUARTA", "", "ST�EDA", "SZERDA"}
, {"�TVRTOK" , "�TVRTEK", "THURSDAY", "FERIA QUINTA", "", "�TVRTEK", "CS�T�RT�K"}
, {"PIATOK" , "P�TEK", "FRIDAY", "FERIA SEXTA", "", "P�TEK", "P�NTEK"}
, {"SOBOTA" , "SOBOTA", "SATURDAY", "SABBATUM", "", "SOBOTA", "SZOMBAT"}
, {"NEZN�MY" , "NEZN�M�", "UNKNOWN", "???", "", "NEZN�M�", "ISMERETLEN"}
};

#define		nazov_DNA(a)	nazov_DNA_jazyk[a][_global_jazyk]

// 2011-05-17: doplnen�
#define KONCOVKA_DNA_HU "JA" // vas�rnapja
#define KONCOVKA_DNA_HU_SMALL "ja"

// two/three-letter abbreviations of the names of the days in week, starting with Sunday (sentence case)
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

// two/three-letter abbreviations of the names of the days in week, starting with Sunday used for anchors (uppercase, no need to translate; based on Slovak)
// 2006-08-01: pou��va sa pre HTML kotvy, ktor� nez�visia od jazykovej mut�cie
const char *nazov_DN_asci[POCET_DNI + 1] =
{"NE", "PO", "UT", "STR", "STV", "PI", "SO", "??"};

// two/three-letter abbreviations of the names of the days in week, starting with Sunday used for debug info (lowercase, no need to translate; based on Slovak)
const char *nazov_dn_asci[POCET_DNI + 1] =
{"ne", "po", "ut", "str", "stv", "pi", "so", "??"};

// the names of the months (lowecase) / nazov_mesiaca: string pre nazov dna; suhlasi s struct tm.tm_mon;
// Month (0--11)
const char *nazov_mesiaca_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{ {"janu�r", "leden", "January", "ianuarius", "", "leden", "janu�r"}
, {"febru�r" , "�nor", "February", "februarius", "", "�nor", "febru�r"}
, {"marec" , "b�ezen", "March", "martius", "", "b�ezen", "m�rcius"}
, {"apr�l" , "duben", "April", "aprilis", "", "duben", "�prilis"}
, {"m�j" , "kv�ten", "May", "maius", "", "kv�ten", "m�jus"}
, {"j�n" , "�erven", "June", "iunius", "", "�erven", "j�nius"}
, {"j�l" , "�ervenec", "July", "iulius", "", "�ervenec", "j�lius"}
, {"august" , "srpen", "August", "augustus", "", "srpen", "augusztus"}
, {"september" , "z���", "September", "september", "", "z���", "szeptember"}
, {"okt�ber" , "��jen", "October", "october", "", "��jen", "okt�ber"}
, {"november" , "listopad", "November", "november", "", "listopad", "november"}
, {"december" , "prosinec", "December", "december", "", "prosinec", "december"}
, {"nezn�my" , "nezn�m�", "unknown", "___", "", "nezn�m�", "ismeretlen"}
};

#define		nazov_mesiaca(a)	nazov_mesiaca_jazyk[a][_global_jazyk]

// the names of the months (lowecase without special characters, plain ASCII 0--128)
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

// the names of the months (sentence case)
const char *nazov_Mesiaca_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{ {"Janu�r", "Leden", "January", "Ianuarius", "", "Leden", "Janu�r"}
, {"Febru�r" , "�nor", "February", "Februarius", "", "�nor", "Febru�r"}
, {"Marec", "B�ezen", "March", "Martius", "", "B�ezen", "M�rcius"}
, {"Apr�l" , "Duben", "April", "Aprilis", "", "Duben", "�prilis"}
, {"M�j" , "Kv�ten", "May", "Maius", "", "Kv�ten", "M�jus"}
, {"J�n" , "�erven", "June", "Iunius", "", "�erven", "J�nius"}
, {"J�l" , "�ervenec", "July", "Iulius", "", "�ervenec", "J�lius"}
, {"August" , "Srpen", "August", "Augustus", "", "Srpen", "Augusztus"}
, {"September" , "Z���", "September", "September", "", "Z���", "Szeptember"}
, {"Okt�ber" , "��jen", "October", "October", "", "��jen", "Okt�ber"}
, {"November" , "Listopad", "November", "November", "", "Listopad", "November"}
, {"December" , "Prosinec", "December", "December", "", "Prosinec", "December"}
, {"Nezn�my" , "Nezn�m�", "unknown", "???", "", "Nezn�m�", "Ismeretlen"}
};

#define		nazov_Mesiaca(a)	nazov_Mesiaca_jazyk[a][_global_jazyk]

// the names of the months (uppercase)
const char *nazov_MESIACA_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{ {"JANU�R", "LEDEN", "JANUARY", "IANUARIUS", "", "LEDEN", "JANU�R"}
, {"FEBRU�R" , "�NOR", "FEBRUARY", "FEBRUARIUS", "", "�NOR", "FEBRU�R"}
, {"MAREC", "B�EZEN", "MARCH", "MARTIUS", "", "B�EZEN", "M�RCIUS"}
, {"APR�L" , "DUBEN", "APRIL", "APRILIS", "", "DUBEN", "�PRILIS"}
, {"M�J" , "KV�TEN", "MAY", "MAIUS", "", "KV�TEN", "M�JUS"}
, {"J�N" , "�ERVEN", "JUNE", "IUNIUS", "", "�ERVEN", "J�NIUS"}
, {"J�L" , "�ERVENEC", "JULY", "IULIUS", "", "�ERVENEC", "J�LIUS"}
, {"AUGUST" , "SRPEN", "AUGUST", "AUGUSTUS", "", "SRPEN", "AUGUSZTUS"}
, {"SEPTEMBER" , "Z���", "SEPTEMBER", "SEPTEMBER", "", "Z���", "SZEPTEMBER"}
, {"OKT�BER" , "��JEN", "OCTOBER", "OCTOBER", "", "��JEN", "OKT�BER"}
, {"NOVEMBER" , "LISTOPAD", "NOVEMBER", "NOVEMBER", "", "LISTOPAD", "NOVEMBER"}
, {"DECEMBER" , "PROSINEC", "DECEMBER", "DECEMBER", "", "PROSINEC", "DECEMBER"}
, {"NEZN�MY" , "NEZN�M�", "UNKNOWN", "???", "", "NEZN�M�", "ISMERETLEN"}
};

#define		nazov_MESIACA(a)	nazov_MESIACA_jazyk[a][_global_jazyk]

// the names of the months (lowercase) in genitive grammatically 2.th declination?; in English: "IN that month" or "OF that month" / genit�v == 2. p�d, koho/�oho
// usage: when generated string for date, e.g. en: "1st January 2000", sk: "1. janu�ra 2000"
// 2007-03-20: pridan� genit�v n�zvu mesiaca kv�li latin�ine
const char *nazov_mesiaca_gen_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{ {"janu�ra", "ledna", "January", "ianuarii", "", "ledna", "janu�r"}
, {"febru�ra" , "�nora", "February", "februarii", "", "�nora", "febru�r"}
, {"marca" , "b�ezna", "March", "martii", "", "b�ezna", "m�rcius"}
, {"apr�la" , "dubna", "April", "aprilis", "", "dubna", "�prilis"}
, {"m�ja" , "kv�tna", "May", "maii", "", "kv�tna", "m�jus"}
, {"j�na" , "�ervna", "June", "iunii", "", "�ervna", "j�nius"}
, {"j�la" , "�ervence", "July", "iulii", "", "�ervence", "j�lius"}
, {"augusta" , "srpna", "August", "augusti", "", "srpna", "augusztus"}
, {"septembra" , "z���", "September", "septembris", "", "z���", "szeptember"}
, {"okt�bra" , "��jna", "October", "octobris", "", "��jna", "okt�ber"}
, {"novembra" , "listopadu", "November", "novembris", "", "listopadu", "november"}
, {"decembra" , "prosince", "December", "decembris", "", "prosince", "december"}
, {"nezn�meho" , "nezn�m�ho", "unknown", "___", "", "nezn�m�ho", "ismeretlen"}
};

#define		nazov_mesiaca_gen(a)	nazov_mesiaca_gen_jazyk[a][_global_jazyk]

// 2007-03-20: pridan� genit�v n�zvu mesiaca kv�li latin�ine
const char *nazov_Mesiaca_gen_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{ {"Janu�ra", "Ledna", "January", "Ianuarii", "", "Ledna", "Janu�r"}
, {"Febru�ra" , "�nora", "February", "Februarii", "", "�nora", "Febru�r"}
, {"Marca" , "B�ezna", "March", "Martii", "", "B�ezna", "M�rcius"}
, {"Apr�la" , "Dubna", "April", "Aprilis", "", "Dubna", "�prilis"}
, {"M�ja" , "Kv�tna", "May", "Maii", "", "Kv�tna", "M�jus"}
, {"J�na" , "�ervna", "June", "Iunii", "", "�ervna", "J�nius"}
, {"J�la" , "�ervence", "July", "Iulii", "", "�ervence", "J�lius"}
, {"Augusta" , "Srpna", "August", "Augusti", "", "Srpna", "Augusztus"}
, {"Septembra" , "Z���", "September", "Septembris", "", "Z���", "Szeptember"}
, {"Okt�bra" , "��jna", "October", "Octobris", "", "��jna", "Okt�ber"}
, {"Novembra" , "Listopadu", "November", "Novembris", "", "Listopadu", "November"}
, {"Decembra" , "Prosince", "December", "Decembris", "", "Prosince", "December"}
, {"Nezn�meho" , "Nezn�m�ho", "Unknown", "___", "", "Nezn�m�ho", "Ismeretlen"}
};

#define		nazov_Mesiaca_gen(a)	nazov_Mesiaca_gen_jazyk[a][_global_jazyk]

// three-letter abbreviations of the names of the months used for anchors (uppercase, no need to translate; based on Slovak)
const char *nazov_MES[POCET_MESIACOV + 1] =
{"JAN", "FEB", "MAR", "APR", "MAJ", "JUN", "JUL", "AUG", "SEP", "OKT", "NOV", "DEC", "___"};

// three-letter abbreviations of the names of the months used for anchors (lowercase, no need to translate; based on Slovak)
const char *nazov_mes[POCET_MESIACOV + 1] =
{"jan", "feb", "mar", "apr", "maj", "jun", "jul", "aug", "sep", "okt", "nov", "dec", "___"};

// ordinal numbers for first few Sundays (sentence case) - used for special occasions currently only in Slovak; no need to change
// 2008-12-20: pridan� re�azec pre poradov� ��slo - pou��va sa v init_global_string() pre nedele niektor�ch obdob� [zatia� iba v sloven�ine]
const char *poradie_Slovom_jazyk[POCET_TYZDNOV + 1][POCET_JAZYKOV + 1] = 
{ {"Prv�", "Prvn�", "", "", "", "Prvn�", "1."}
, {"Druh�" , "Druh�", "", "", "", "Druh�", "2."}
, {"Tretia" , "T�et�", "", "", "", "T�et�", "3."}
, {"�tvrt�" , "�tvrt�", "", "", "", "�tvrt�", "4."}
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

// the same as "poradie_Slovom_jazyk" ordinal numbers for first few Sundays (uppercase) - used for special occasions currently only in Slovak; no need to change
const char *poradie_SLOVOM_jazyk[POCET_TYZDNOV + 1][POCET_JAZYKOV + 1] = 
{ {"PRV�", "PRVN�", "", "", "", "PRVN�", "1."}
, {"DRUH�" , "DRUH�", "", "", "", "DRUH�", "2."}
, {"TRETIA" , "T�ET�", "", "", "", "T�ET�", "3."}
, {"�TVRT�" , "�TVRT�", "", "", "", "�TVRT�", "4."}
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

// the names of languages
// 2006-07-11: Pridan� kv�li jazykov�m mut�ci�m
const char *nazov_jazyka[POCET_JAZYKOV + 1] =
{"sloven�ina", "�e�tina", "English", "lingua latina", "(neur�en�)", "�e�tina (dominik�ni)", "magyarul"};

// language codes; internal usage for HTTP requests
const char *skratka_jazyka[POCET_JAZYKOV + 1] =
{"sk", "cz", "en", "la", "??", "c2", "hu"};

// language codes; internal usage for include directories (postfix of directory/folder name); postfix MUST NOT contain slash/backslash
// 2006-07-13 a 17: Pridan� kv�li jazykov�m mut�ci�m - postfix pre include adres�r
const char *postfix_jazyka[POCET_JAZYKOV + 1] =
{"", "cz", "en", "la", "", "czop", "hu"};
// Pozn�mka: Postfix nesmie obsahova� na za�iatku odde�ova� (slash resp. backslash); mus� sa jedna� o podadres�r pod include

const short int format_datumu[POCET_JAZYKOV + 1] = {
	/* sk */ FORMAT_DATUMU_DEN_MESIAC_ROK, /* cz */ FORMAT_DATUMU_DEN_MESIAC_ROK, /* en */ FORMAT_DATUMU_MESIAC_DEN_ROK,
	/* la */ FORMAT_DATUMU_DEN_MESIAC_ROK, /* ?? */ FORMAT_DATUMU_DEN_MESIAC_ROK, /* czop */ FORMAT_DATUMU_DEN_MESIAC_ROK,
	/* hu */ FORMAT_DATUMU_ROK_MESIAC_DEN,
};

// filename of CSS file; the number of CSS does not directly correspond to the number of languages
// 2006-08-08: Pridan� kv�li r�znym css
const char *nazov_css[POCET_CSS + 1] =
{"(css neur�en�)", "breviar.css", "breviar-invert.css", "breviar-kbd.css", "ebreviar-cz.css", "breviar-cz-op.css"
	, "breviar-2003-07-16.css", "breviar-2005-10-13.css", "breviar-2007-08-10.css", "breviar-2008-05-07.css"
	, "breviar-jm-krize-cz.css", "breviar-kbs.css"};

const char *skratka_css[POCET_CSS + 1] =
{"__", "def", "invert", "kbd", "cz", "czop"
	, "2003", "2005", "2007", "2008"
	, "jmkcz", "kbs"};

// 2012-04-03: Pridan� kv�li jazykov�m mut�ci�m -- default CSS pre dan� jazyk | mo�no do bud�cnosti mo�nos� default nastavenia v config (konfigura�nom s�bore)
const short int default_css_jazyk[POCET_JAZYKOV + 1] =
{CSS_breviar_sk, CSS_ebreviar_cz, CSS_breviar_sk, CSS_breviar_sk, CSS_breviar_sk, CSS_breviar_cz_op, CSS_breviar_sk};

// CSS obsahujuci invertovane farby
const char *nazov_css_invert_colors = "breviar-invert-colors.css";

// language charset (encoding); used for HTML heading
const char *charset_jazyka[POCET_JAZYKOV + 1] =
{"windows-1250", "windows-1250", "windows-1251", "windows-1251", "utf-8", "windows-1250", "windows-1250"};

// 2011-05-06: pridan� kv�li mo�nosti vo�by p�sma
const char *nazov_fontu[POCET_FONTOV + 1] =
{"", "pod�a CSS", "pod�a v�beru", "Cambria", "Candara", "Georgia", "Tahoma", "Helvetica", "serif", "sans-serif"};
const char *nazov_fontu_CHECKBOX[POCET_JAZYKOV + 1] =
{"pod�a v�beru", "podle v�b�ru", "according to checkbox above", "checkbox", "", "podle v�b�ru", "checkbox"};
const char *nazov_fontu_CSS[POCET_FONTOV + 1] =
{"pod�a CSS", "podle CSS", "according to CSS", "CSS", "CSS", "podle CSS", "CSS szerint"};
// 2011-05-13: pridan� kv�li mo�nosti vo�by ve�kosti p�sma
const char *nazov_font_size_jazyk[POCET_FONT_SIZE + 1][POCET_JAZYKOV + 1] = {
{"", "", "", "", "", "", ""},
{"pod�a CSS", "podle CSS", "according to CSS", "CSS", "", "podle CSS", "CSS szerint"},
{"malilink�", "malinkat�", "xx-small", "xx-small", "", "malinkat�", "apr�"},
{"ve�mi mal�", "velmi mal�", "extra small", "extra small", "", "velmi mal�", "nagyon kicsi"},
{"mal�", "mal�", "small", "small", "", "mal�", "kicsi"},
{"stredn�", "st�edn�", "medium", "medium", "", "st�edn�", "k�zepes"},
{"ve�k�", "velik�", "large", "large", "", "velik�", "nagy"},
{"ve�mi ve�k�", "velmi velik�", "extra large", "extra large", "", "velmi velik�", "nagyon nagy"},
{"obrovsk�", "obrovsk�", "xx-large", "xx-large", "", "obrovsk�", "�ri�si"}
};
#define nazov_font_size(a) nazov_font_size_jazyk[a][_global_jazyk]
const char *nazov_font_size_css[POCET_FONT_SIZE + 1] = 
{"", "inherit", "xx-small", "x-small", "small", "medium", "large", "x-large", "xx-large"};

// strings of buttons - abbreviations of prayer names // shortened because of usage on mobile devices (Android)
const char *html_button_nazov_modlitby_jazyk[POCET_MODLITIEB + 1][POCET_JAZYKOV + 1] = 
{ {"Inv.", "Inv.", "Inv.", "Inv.", "", "Inv.", "Im�d."}
, {"Posv. ��t.", "�ten�", "Reading", "Off. lect.", "", "�ten�", "Olvasm. i."}
, {"Rann� chv.", "Rann� chv.", "Morning pr.", "Laudes", "", "Rann� chv.", "Reggeli dics."}
, {"9h", "9h", "9h", "Tertia", "", "Tercie", "D�lel�tt"}
, {"12h", "12h", "12h", "Sexta", "", "Sexta", "D�lben"}
, {"15h", "15h", "15h", "Nona", "", "Nona", "D�lut�n"}
, {"Ve�pery", "Ne�pory", "Vesperae", "Vesperae", "", "Ve�ern� chv.", "Esti dics."}
, {"Kompl.", "Kompl.", "Compl.", "Compl.", "", "Kompl.", "Befejez� i."}
// t�to sa pre HTML buttony nepou��va
	, {"neur�en�", "neur�ena", "not-defined", "no data", "", "neur�ena", "nem azonos�tott"}
, {"Prv� ve�p.", "Prvn� ne�p.", "1st Vesperae", "I vesperae", "", "Prvn� v. chv.", "I. esti dics." }
, {"Prv� kompl.", "Prvn� kompl.", "Compl.", "Compl.", "", "Prvn� kompl.", "Bef. i. I.e.d.ut�n"}
, {"Druh� ve�p.", "Druh� ne�pory", "2nd Vesperae", "II vesperae", "", "Druh� ve�ern� chv.", "II. esti dics." }
, {"Druh� kompl.", "Druh� kompl.", "2nd Completary", "II completorio", "", "Druh� kompl.", "Bef. i. II.e.d.ut�n" }
// , {"Vo�ba detailov...", "Podrobn�ji...", "Details...", "Opti�nes...", "", "Podrobn�ji...", "R�szletek..."} // 2011-10-03: prakticky je to teraz len o v�bere spolo�n�ch �ast�
, {"v�ber spolo�nej �asti...", "v�b�r spole�n� ��sti...", "common texts...", "opti�nes...", "", "v�b�r spole�n� ��sti...", "k�z�s r�sz kiv�laszt�sa..."}
, {"v�etky", "v�echny", "all", "all", "", "v�echny", "�sszes" }
};

#define		html_button_nazov_modlitby(a)	html_button_nazov_modlitby_jazyk[a][_global_jazyk]

// special button: Details...
#ifndef HTML_BUTTON_DETAILY
#define HTML_BUTTON_DETAILY	html_button_nazov_modlitby_jazyk[MODL_DETAILY][_global_jazyk]
#endif

// special button: Show prayer
const char *html_button_det_show[POCET_JAZYKOV + 1] = {"Zobraz modlitbu", "Uka� modlitbu", "Show prayer", "xxx", "", "Uka� modlitbu", "Mutasd az im�t"};
#ifndef HTML_BUTTON_DET_SHOW
#define HTML_BUTTON_DET_SHOW	html_button_det_show[_global_jazyk]
#endif

// special button: Defaults
const char *html_button_det_defaults[POCET_JAZYKOV + 1] = {"P�vodn� hodnoty", "P�vodn� hodnoty", "Defaults", "___", "", "P�vodn� hodnoty", "Alap�rtelmezett"};
#ifndef HTML_BUTTON_DET_DEFAULTS
#define HTML_BUTTON_DET_DEFAULTS	html_button_det_defaults[_global_jazyk]
#endif

// special button (today): Show
const char *html_button_dnes_show[POCET_JAZYKOV + 1] = {"Zobrazi�", "Uka�", "Show", "___", "", "Uka�", "Mutasd"};
#ifndef HTML_BUTTON_DNES_SHOW
#define HTML_BUTTON_DNES_SHOW	html_button_dnes_show[_global_jazyk]
#endif

// special button (today): Defaults (clear form)
// const char *html_button_dnes_defaults[POCET_JAZYKOV + 1] = {"Vy�isti", "Vy�isti", "Clear", "???", "", "Vy�isti", "T�r�l"};
#ifndef HTML_BUTTON_DNES_DEFAULTS
#define HTML_BUTTON_DNES_DEFAULTS	HTML_BUTTON_DET_DEFAULTS
#endif

// special button (today): Apply settings/options
const char *html_button_dnes_apply[POCET_JAZYKOV + 1] = {"Potvrdi�", "Potvrdit", "Apply", "___", "", "Potvrdit", "Alkalmaz"};
#ifndef HTML_BUTTON_DNES_APPLY_SETTINGS
#define HTML_BUTTON_DNES_APPLY_SETTINGS	html_button_dnes_apply[_global_jazyk]
#endif

// special button (today): Apply options 2 (various choices)
const char *html_button_dnes_apply2[POCET_JAZYKOV + 1] = {"Ulo�i�", "Ulo�it", "Save", "___", "", "Ulo�it", "Alkalmaz"};
#ifndef HTML_BUTTON_DNES_APPLY_CHOICES
#define HTML_BUTTON_DNES_APPLY_CHOICES html_button_dnes_apply2[_global_jazyk]
#endif

// special button (today): Morning prayer with canticum of Zekariah
// doplnen�, 2007-09-13
const char *html_button_ranne_chvaly_benediktus[POCET_JAZYKOV + 1] = {"Rann� chv�ly + Benediktus", "Rann� chv�ly + Zach. kantikum", "Morning prayer with Benedictus", "Laudes + Benedictus", "", "Rann� chv�ly + Zach. kantikum", "Reggeli dics�ret Benedictusszal"};
#ifndef HTML_BUTTON_RANNE_CHVALY_BENEDIKTUS
#define HTML_BUTTON_RANNE_CHVALY_BENEDIKTUS	html_button_ranne_chvaly_benediktus[_global_jazyk]
#endif

// special button (today): Evening prayer with canticum of Mary
const char *html_button_vespery_magnifikat[POCET_JAZYKOV + 1] = {"Ve�pery + Magnifikat", "Ne�pory + Mariino kant.", "Vesperae + Magnificat", "Vesperae + Magnificat", "", "Ve�ern� chv�ly + kant. Panny Marie", "Esti dics�ret Magnificattal"};
#ifndef HTML_BUTTON_VESPERY_MAGNIFIKAT
#define HTML_BUTTON_VESPERY_MAGNIFIKAT	html_button_vespery_magnifikat[_global_jazyk]
#endif

// special button (today): Completory prayer with canticum of Simeon; is currently used only in Slovak
// doplnen�, 2008-12-20; nepou��va sa pre ostatn� jazyky
const char *html_button_kompletorium_nunkdim[POCET_JAZYKOV + 1] = {"Komplet�rium + Nunk dimittis", "xxx", "xxx", "xxx", "", "xxx", "hu_xxx"};
#ifndef HTML_BUTTON_KOMPLETORIUM_NUNKDIM
#define HTML_BUTTON_KOMPLETORIUM_NUNKDIM	html_button_kompletorium_nunkdim[_global_jazyk]
#endif

// html <title> element for generated pages
// doplnen�, 2009-05-21
const char *html_title[POCET_JAZYKOV + 1] = {"Liturgia hod�n", "Liturgie hodin", "Liturgy of Hours", "Liturgia horarum", "", "Liturgie hodin", "Az Ima�r�k Liturgi�ja"};
// 2009-08-04: upraven� pre batch m�d
// const char *html_title_batch_mode[POCET_JAZYKOV + 1] = {"Batch m�d", "D�vkov� re�im", "Batch mode", "la_", "", "D�vkov� re�im", "K�tegelt m�d"};
const char *html_title_batch_mode[POCET_JAZYKOV + 1] = {"Liturgia hod�n - statick� texty", "Liturgie hodin - statick� texty", "Liturgy of Hours - static texts", "la_", "", "Liturgie hodin - statick� texty", "Az Ima�r�k Liturgi�ja - �lland� sz�vegek"};

// doplnen�, 2011-05-16
const char *html_error_template[POCET_JAZYKOV + 1] = {"�abl�na pre modlitbu sa nena�la. Zrejme neexistuje s�bor `%s'.", "�ablona pro modlitbu se nena�la. Patrn� neexistuje soubor `%s'.", "Template for prayer not found. File `%s' does not exist.", "Template for prayer not found. File `%s' does not exist.", "", "�ablona pro modlitbu se nena�la. Patrn� neexistuje soubor `%s'.", "Template for prayer not found. File `%s' does not exist."};

// navigation buttons/texts: previous, next, today
const char *html_button_predchadzajuci_[POCET_JAZYKOV + 1] = {"Predch�dzaj�ci", "P�edchoz�", "Previous", "Praeced�nte", "", "P�edchoz�", "El�z�"};
const char *html_button_nasledujuci_[POCET_JAZYKOV + 1] = {"Nasleduj�ci", "N�sleduj�c�", "Next", "Success�vo", "", "N�sleduj�c�", "K�vetkez�"};
const char *html_button_dnes[POCET_JAZYKOV + 1] = {"dnes", "dnes", "today", "hodie", "", "dnes", "ma"};
const char *html_button_Dnes[POCET_JAZYKOV + 1] = {"Dnes", "Dnes", "Today", "Hodie", "", "Dnes", "Ma"};
const char *html_button_hore[POCET_JAZYKOV + 1] = {"^ ", "^ ", "^ ", "^ ", "^ ", "^ ", "^ "};

const char *html_button_tento_den[POCET_JAZYKOV + 1] = {"tento de�", "tento den", "this day", "hodie", "", "tento den", "ez a nap"};

// basic words: day, month, year
const char *html_text_den[POCET_JAZYKOV + 1] = {"de�", "den", "day", "die", "", "den", "nap"};
const char *html_text_mesiac[POCET_JAZYKOV + 1] = {"mesiac", "m�s�c", "month", "mensis", "", "m�s�c", "h�"};
const char *html_text_rok[POCET_JAZYKOV + 1] = {"rok", "rok", "year", "anno", "", "rok", "�v"};
const char *html_text_Rok[POCET_JAZYKOV + 1] = {"Rok", "Rok", "Year", "Anno", "", "Rok", "�v"};
// in the following: you MUST keep all %d, %c, %s etc. variables - these are replaced by numbers, characters, strings, etc. respectively
const char *html_text_Rok_x[POCET_JAZYKOV + 1] = {"Rok %d", "Rok %d", "Year %d", "Anno %d", "%d", "Rok %d", "�v %d"};

const char *html_text_zoznam_mesiacov[POCET_JAZYKOV + 1] = {"zoznam mesiacov", "seznam m�s�c�", "list of months", "", "", "seznam m�s�c�", "h�napok list�ja"};

const char *html_text_modlitba[POCET_JAZYKOV + 1] = {"modlitba", "modlitba", "prayer", "ora", "", "modlitba", "im�ds�g"};
const char *html_text_modlitby_pre_den[POCET_JAZYKOV + 1] = {"modlitby pre de�", "modlitby pro den", "prayers for date", "", "", "modlitby pro den", ""};
const char *html_text_alebo_pre[POCET_JAZYKOV + 1] = {"alebo pre", "anebo pro", "or for", "vel per", "", "anebo pro", "vagy"};
const char *html_text_dnesok[POCET_JAZYKOV + 1] = {"dne�ok", "dne�n� den", "today", "hodie", "", "dne�n� den", "a mai nap ima�r�i"};

// 2010-02-15: pridan� kv�li "zoznam.htm" batch mode
const char *html_text_Breviar_dnes[POCET_JAZYKOV + 1] = {"Brevi�r dnes", "Brevi�� dnes", "Breviary today", "Liturgia horarum hodie", "", "Brevi�� dnes", "A mai nap ima�r�ja"};
const char *html_text_Dnesne_modlitby[POCET_JAZYKOV + 1] = {"Dne�n� modlitby", "Dne�n� modlitby", "Today's prayers", "la_hodie", "", "Dne�n� modlitby", "A mai nap im�i"};
const char *html_text_Prehlad_mesiaca[POCET_JAZYKOV + 1] = {"Preh�ad mesiaca", "P�ehled m�s�ce", "Current month", "la_", "", "P�ehled m�s�ce", "A h�nap �ttekint�se"};
// 2011-03-18: pridan� do "zoznam.htm" batch mode -- kalend�re a hlavn� nadpis
const char *html_text_batch_mode_h1[POCET_JAZYKOV + 1] = {"Liturgia hod�n � Predgenerovan� modlitby", "Liturgie hodin � P�edgenerovan� modlitby", "Liturgy of Hours � Pregenerated prayers", "la_", "", "Liturgie hodin � P�edgenerovan� modlitby", "Az Ima�r�k Liturgi�ja � El�re gener�lt im�k"};
const char *html_text_Kalendar[POCET_JAZYKOV + 1] = {"Kalend�r", "Kalend��", "Proprietary calendary", "Propria", "", "Kalend��", "Napt�r"};

const char *html_text_Vysvetlivky[POCET_JAZYKOV + 1] = 
{"Vysvetlivky", 
 "Vysv�tlivky", 
 "Legenda", 
 "Legenda", 
 "", 
 "Vysv�tlivky", 
 "Jelmagyar�zat"};

const char *html_text_dalsie_moznosti[POCET_JAZYKOV + 1] = 
{"V�ber �al��ch mo�nost�", 
 "Dal�� mo�nosti v�b�ru ", 
 "Choose from above (buttons) or from the following options: ", 
 "", 
 "", 
 "Dal�� mo�nosti v�b�ru", 
 "Tov�bbi lehet�s�gek v�laszt�sa:"};

const char *html_text_dalsie_moznosti_1[POCET_JAZYKOV + 1] = 
{"Nastavenia", 
 "Nastaven�", 
 "Settings", 
 "", 
 "", 
 "Nastaven�", 
 "Be�ll�t�sok"};

const char *html_text_dalsie_moznosti_2[POCET_JAZYKOV + 1] = 
{"�al�ie zobrazenia", 
 "Dal�� zobrazen�", 
 "Other options", 
 "", 
 "", 
 "Dal�� zobrazen�", 
 "M�s megjelen�t�si lehet�s�gek"};

const char *html_text_prik_sviatky_atd[POCET_JAZYKOV + 1] = {"prik�zan� sviatky a sl�vnosti P�na v roku ", "zasv�cen� sv�tky a slavnosti P�n� v roce ", "obligatory celebrations in year ", "", "", "zasv�cen� sv�tky a slavnosti P�n� v roce", "k�telez� �nnepek"};
const char *html_text_lit_kalendar[POCET_JAZYKOV + 1] = {"liturgick� kalend�r pre", "liturgick� kalend�� pro", "liturgical calendar for", "", "", "liturgick� kalend�� pro", "liturgikus napt�r"};
const char *html_text_roku[POCET_JAZYKOV + 1] = {"roku", "roku", "of year", "anno", "", "roku", ""};
const char *html_text_tabulka_pohyblive_od[POCET_JAZYKOV + 1] = {"tabu�ka d�tumov pohybliv�ch sl�ven� od roku", "tabulka s daty prom�nn�ch slavnost� od roku", "table with dates of movable celebrations from year", "", "", "tabulka s daty prom�nn�ch slavnost� od roku", "a mozg� (v�ltoz�) �nnepek t�bl�zata a k�vetkez� �vekben"};
const char *html_text_do_roku[POCET_JAZYKOV + 1] = {"do roku", "po rok", "till year", "", "", "po rok", ""};
const char *html_text_zobrazit_linky[POCET_JAZYKOV + 1] = {"zobrazi� tabu�ku vr�tane hypertextov�ch odkazov na jednotliv� dni", "zobrazit tabulku s hypertextov�mi odkazy pro jednotliv� dny", "display the table including hypertext links to each date", "", "", "zobrazit tabulku s hypertextov�mi odkazy pro jednotliv� dny", "A t�bl�zat megjelen�t�se az egyes napokhoz tartoz� hiperhivatkoz�sokkal egy�tt."};
const char *html_text_pre_cezrocne_obd[POCET_JAZYKOV + 1] = {"pre cezro�n� obdobie", "pro mezidob�", "for ...", "per annum", "", "pro dobu b�hem roku", ""};
const char *html_text_tyzden_zaltara_cislo[POCET_JAZYKOV + 1] = {"%d. t��de� �alt�ra", "%d. t�den �alt��e", "%d. week of Psaltary", "hebdomada %d psalterii", "%d", "%d. t�den �alt��e", "%d. zsolt�ros h�t"};
const char *html_text_tyzden_cislo[POCET_JAZYKOV + 1] = {"%d. t��de�", "%d. t�den", "%d. week", "hebdomada %d", "%d", "%d. t�den", "%d. h�t"};
const char *html_text_tyzden[POCET_JAZYKOV + 1] = {". t��de�", ". t�den", ". week", "hebdomada ", "", ". t�den", ". h�t"};
const char *html_text_v_tyzdni_zaltara[POCET_JAZYKOV + 1] = {". t��dni �alt�ra", ". t�dnu �alt��e", "week of Psaltary", "hebdomada", "", ". t�dnu �alt��e", ". zsolt�ros h�t"};
const char *html_text_pre[POCET_JAZYKOV + 1] = {"pre", "pro", "for", "per", "", "pro", ""};
// in the following: you MUST keep all HTML elements, e.g. <a href...>, <br/> etc.
const char *html_text_dnes_je_atd[POCET_JAZYKOV + 1] = 
{"Dnes je %d. de� v roku%s, <a href=\"%s%s\">juli�nsky d�tum</a> JD = %ld%s.\n"HTML_LINE_BREAK"\n",
 "Dnes je %d. den v roku%s, <a href=\"%s%s\">juli�nsk� datum</a> JD = %ld%s.\n"HTML_LINE_BREAK"\n",
 "Today is %d. day in the year%s, <a href=\"%s%s\">Julian date</a> JD = %ld%s.\n"HTML_LINE_BREAK"\n",
 "Hodie est %d. die anno %s, <a href=\"%s%s\">Iulianus datum</a> JD = %ld%s.\n"HTML_LINE_BREAK"\n",
 "%d/%s<a href=\"%s%s\">JD</a> = %ld%s.\n"HTML_LINE_BREAK"\n",
 "Dnes je %d. den v roku%s, <a href=\"%s%s\">juli�nsk� datum</a> JD = %ld%s.\n"HTML_LINE_BREAK"\n",
 "Ma %s %d. napja van, <a href=\"%s%s\">Juli�n napt�r</a> JD = %ld%s.\n"HTML_LINE_BREAK"\n"};

const char *html_text_alebo[POCET_JAZYKOV + 1] = {"alebo:", "nebo:", "or:", "", "", "nebo:", ""};

const char *html_text_zakladne_info[POCET_JAZYKOV + 1] = {"Z�kladn� inform�cie", "Z�kladn� informace", "Basic info", "__info__", "", "Z�kladn� informace", "Alapvet� inform�ci�k"};
const char *html_text_je[POCET_JAZYKOV + 1] = {"je", "je", "is", "est", "", "je", /* HU: van, ale nie pre prestupn� */ ""};
const char *html_text_nie_je[POCET_JAZYKOV + 1] = {"nie je", "nen�", "is not", "non est", "", "nen�", /* HU: nincs, ale nie pre prestupn� */ "nem"};
const char *html_text_prestupny[POCET_JAZYKOV + 1] = {"prestupn�", "p�estupn�", "...", "...", "", "p�estupn�", "sz�k��v"};
const char *html_text_datumy_pohyblivych_slaveni[POCET_JAZYKOV + 1] = {"D�tumy pohybliv�ch sl�ven�", "D�ta prom�nliv�ch sl�ven�", "Dates for movable celebrations", "", "", "Data prom�nliv�ch slaven�", "A mozg� (v�ltoz�) �nnepek d�tumai"};

const char *html_text_den_v_roku[POCET_JAZYKOV + 1] = {"%d. de� v roku", "%d. den v roce", "%d. day of the year", "%d. ", "%d. ", "%d. den v roce", "az �v %d. napja"};

const char *html_text_zacina[POCET_JAZYKOV + 1] = {"za��na", "za��n�", "starts", "", "", "za��n�", "kezd�dik"};
const char *html_text_liturgicky_rok[POCET_JAZYKOV + 1] = {"liturgick� rok", "liturgick� rok", "liturgical year", "anno liturgico", "", "liturgick� rok", "liturgikus �v"};

const char *html_text_txt_export[POCET_JAZYKOV + 1] = {"Textov� v�stup: ", "Textov� v�stup: ", "Text export: ", "Text export:", "", "Textov� v�stup: ", "Text export: "};

const char *html_text_pohyblive1[POCET_JAZYKOV + 1] = {
	"<td "HTML_ALIGN_CENTER">Rok"HTML_LINE_BREAK"P�na</td>\n",
	"<td "HTML_ALIGN_CENTER">L�to"HTML_LINE_BREAK"P�n�</td>\n", 
	"<td "HTML_ALIGN_CENTER">Anno"HTML_LINE_BREAK"Domini</td>\n",
	"<td "HTML_ALIGN_CENTER">Anno"HTML_LINE_BREAK"Domini</td>\n",
	"",
	"<td "HTML_ALIGN_CENTER">L�to"HTML_LINE_BREAK"P�n�</td>\n",
	"<td "HTML_ALIGN_CENTER">Napt�ri"HTML_LINE_BREAK"�v</td>\n"
};

const char *html_text_pohyblive2[POCET_JAZYKOV + 1] = {
	"<td "HTML_ALIGN_CENTER">Nede�n�"HTML_LINE_BREAK"litera</td>\n",
	"<td "HTML_ALIGN_CENTER">Ned�ln�"HTML_LINE_BREAK"p�smeno</td>\n", 
	"<td "HTML_ALIGN_CENTER">Sunday"HTML_LINE_BREAK"Letter</td>\n",
	"<td "HTML_ALIGN_CENTER">Let."HTML_LINE_BREAK"Dom.</td>\n",
	"",
	"<td "HTML_ALIGN_CENTER">Ned�ln�"HTML_LINE_BREAK"p�smeno</td>\n",
	"<td "HTML_ALIGN_CENTER">Vas�rnap"HTML_LINE_BREAK"bet�je</td>\n"
};

const char *html_text_pohyblive3[POCET_JAZYKOV + 1] = {
	"<td "HTML_ALIGN_CENTER">Nede�n�"HTML_LINE_BREAK"cyklus</td>\n",
	"<td "HTML_ALIGN_CENTER">Ned�ln�"HTML_LINE_BREAK"cyklus</td>\n", 
	"<td "HTML_ALIGN_CENTER">Sunday"HTML_LINE_BREAK"cycle</td>\n",
	"<td "HTML_ALIGN_CENTER">Cycl."HTML_LINE_BREAK"Dom.</td>\n",
	"",
	"<td "HTML_ALIGN_CENTER">Ned�ln�"HTML_LINE_BREAK"cyklus</td>\n",
	"<td "HTML_ALIGN_CENTER">Vas�rnapi"HTML_LINE_BREAK"ciklus</td>\n"
};

const char *html_text_pohyblive3b[POCET_JAZYKOV + 1] = {
	"<td "HTML_ALIGN_CENTER">Zjavenie"HTML_LINE_BREAK"P�na</td>\n",
	"<td "HTML_ALIGN_CENTER">Zjeven�"HTML_LINE_BREAK"P�n�</td>\n", 
	"<td "HTML_ALIGN_CENTER">Epiphany</td>\n",
	"<td "HTML_ALIGN_CENTER">Epiphania"HTML_LINE_BREAK"Domini</td>\n",
	"",
	"<td "HTML_ALIGN_CENTER">Zjeven�"HTML_LINE_BREAK"P�n�</td>\n",
	"<td "HTML_ALIGN_CENTER">Urunk"HTML_LINE_BREAK"megjelen�se"HTML_LINE_BREAK"(V�zkereszt)</td>\n"
};

const char *html_text_pohyblive4[POCET_JAZYKOV + 1] = {
	"<td "HTML_ALIGN_CENTER">Krst Krista"HTML_LINE_BREAK"P�na</td>\n",
	"<td "HTML_ALIGN_CENTER">K�est Krista"HTML_LINE_BREAK"P�n�</td>\n", 
	"<td "HTML_ALIGN_CENTER">Bapt. of"HTML_LINE_BREAK"the Lord</td>\n",
	"<td "HTML_ALIGN_CENTER">Bapt."HTML_LINE_BREAK"Domini</td>\n",
	"",
	"<td "HTML_ALIGN_CENTER">K�est Krista"HTML_LINE_BREAK"P�n�</td>\n",
	"<td "HTML_ALIGN_CENTER">Urunk"HTML_LINE_BREAK"megkeresztel-"HTML_LINE_BREAK"ked�se</td>\n"
};

const char *html_text_pohyblive5[POCET_JAZYKOV + 1] = {
	"<td "HTML_ALIGN_CENTER"><a href=\"#explain\">OCR"HTML_LINE_BREAK"pred"HTML_LINE_BREAK"PO</a></td>\n",
	"<td "HTML_ALIGN_CENTER"><a href=\"#explain\">OCR"HTML_LINE_BREAK"p�ed"HTML_LINE_BREAK"postem</a></td>\n", 
	"<td "HTML_ALIGN_CENTER">...</td>\n",
	"<td "HTML_ALIGN_CENTER">PA fest.</td>\n",
	"",
	"<td "HTML_ALIGN_CENTER"><a href=\"#explain\">OCR"HTML_LINE_BREAK"p�ed"HTML_LINE_BREAK"postem</a></td>\n",
	"<td "HTML_ALIGN_CENTER">EK a HSZ el�tt</td>\n"
};

const char *html_text_pohyblive6[POCET_JAZYKOV + 1] = {
	"<td "HTML_ALIGN_CENTER">Popolcov�"HTML_LINE_BREAK"streda</td>\n",
	"<td "HTML_ALIGN_CENTER">Popele�n�"HTML_LINE_BREAK"st�eda</td>\n", 
	"<td "HTML_ALIGN_CENTER">...</td>\n",
	"<td "HTML_ALIGN_CENTER">...</td>\n",
	"",
	"<td "HTML_ALIGN_CENTER">Popele�n�"HTML_LINE_BREAK"st�eda</td>\n",
	"<td "HTML_ALIGN_CENTER">Hamvaz�-"HTML_LINE_BREAK"szerda</td>\n"
};

const char *html_text_pohyblive7[POCET_JAZYKOV + 1] = {
	"<td "HTML_ALIGN_CENTER">Ve�k�"HTML_LINE_BREAK"noc</td>\n",
	"<td "HTML_ALIGN_CENTER">Veliko-"HTML_LINE_BREAK"noce</td>\n", 
	"<td "HTML_ALIGN_CENTER">Easter</td>\n",
	"<td "HTML_ALIGN_CENTER">Pascha</td>\n",
	"",
	"<td "HTML_ALIGN_CENTER">Veliko-"HTML_LINE_BREAK"noce</td>\n",
	"<td "HTML_ALIGN_CENTER">H�sv�t</td>\n"
};

const char *html_text_pohyblive8[POCET_JAZYKOV + 1] = {
	"<td "HTML_ALIGN_CENTER">Nanebo-"HTML_LINE_BREAK"vst�penie"HTML_LINE_BREAK"P�na</td>\n",
	"<td "HTML_ALIGN_CENTER">Nanebe-"HTML_LINE_BREAK"vstoupen�"HTML_LINE_BREAK"P�n�</td>\n", 
	"<td "HTML_ALIGN_CENTER">...</td>\n",
	"<td "HTML_ALIGN_CENTER">...</td>\n",
	"",
	"<td "HTML_ALIGN_CENTER">Nanebe-"HTML_LINE_BREAK"vstoupen�"HTML_LINE_BREAK"P�n�</td>\n",
	"<td "HTML_ALIGN_CENTER">Urunk"HTML_LINE_BREAK"menny-"HTML_LINE_BREAK"bemenetele</td>\n"
};

const char *html_text_pohyblive9[POCET_JAZYKOV + 1] = {
	"<td "HTML_ALIGN_CENTER">Zoslanie"HTML_LINE_BREAK"Ducha"HTML_LINE_BREAK"Sv�t�ho</td>\n",
	"<td "HTML_ALIGN_CENTER">Sesl�n�"HTML_LINE_BREAK"Ducha"HTML_LINE_BREAK"Svat�ho</td>\n", 
	"<td "HTML_ALIGN_CENTER">...</td>\n",
	"<td "HTML_ALIGN_CENTER">...</td>\n",
	"",
	"<td "HTML_ALIGN_CENTER">Sesl�n�"HTML_LINE_BREAK"Ducha"HTML_LINE_BREAK"Svat�ho</td>\n",
	"<td "HTML_ALIGN_CENTER">P�nk�sd</td>\n"
};

const char *html_text_pohyblive10[POCET_JAZYKOV + 1] = {
	"<td "HTML_ALIGN_CENTER"><a href=\"#explain\">OCR"HTML_LINE_BREAK"po"HTML_LINE_BREAK"VN</a></td>\n",
	"<td "HTML_ALIGN_CENTER"><a href=\"#explain\">OCR"HTML_LINE_BREAK"po"HTML_LINE_BREAK"VN</a></td>\n", 
	"<td "HTML_ALIGN_CENTER">...</td>\n",
	"<td "HTML_ALIGN_CENTER">...</td>\n",
	"",
	"<td "HTML_ALIGN_CENTER"><a href=\"#explain\">OCR"HTML_LINE_BREAK"po"HTML_LINE_BREAK"VN</a></td>\n",
	"<td "HTML_ALIGN_CENTER">EK a HU ut�n</td>\n"
};

const char *html_text_pohyblive11[POCET_JAZYKOV + 1] = {
	"<td "HTML_ALIGN_CENTER">Prv�"HTML_LINE_BREAK"adventn�"HTML_LINE_BREAK"nede�a</td>\n",
	"<td "HTML_ALIGN_CENTER">Prvn�"HTML_LINE_BREAK"adventn�"HTML_LINE_BREAK"ned�le</td>\n", 
	"<td "HTML_ALIGN_CENTER">...</td>\n",
	"<td "HTML_ALIGN_CENTER">...</td>\n",
	"",
	"<td "HTML_ALIGN_CENTER">Prvn�"HTML_LINE_BREAK"adventn�"HTML_LINE_BREAK"ned�le</td>\n",
	"<td "HTML_ALIGN_CENTER">Advent els�"HTML_LINE_BREAK"vas�rnapja</td>\n"
};

const char *html_text_pohyblive12[POCET_JAZYKOV + 1] = {
	"<td "HTML_ALIGN_CENTER">Nede�a Sv�tej"HTML_LINE_BREAK"rodiny</td></tr>\n",
	"<td "HTML_ALIGN_CENTER">Ned�le Svat�"HTML_LINE_BREAK"rodiny</td></tr>\n", 
	"<td "HTML_ALIGN_CENTER">...</td>\n",
	"<td "HTML_ALIGN_CENTER">...</td>\n",
	"",
	"<td "HTML_ALIGN_CENTER">Ned�le Svat�"HTML_LINE_BREAK"rodiny</td></tr>\n",
	"<td "HTML_ALIGN_CENTER">Szent"HTML_LINE_BREAK"Csal�d"HTML_LINE_BREAK"�nnepe</td>\n"
};

const char *html_text_Nedelne_pismeno[POCET_JAZYKOV + 1] = {"Nede�n� p�smeno", "Ned�ln� p�smeno", "Sunday letter", "", "", "Ned�ln� p�smeno", "A vas�rnap bet�je"};
const char *html_text_Nedelne_pismena[POCET_JAZYKOV + 1] = {"Nede�n� p�smen�", "Ned�ln� p�smena", "Sunday letters", "", "", "Ned�ln� p�smena", "A vas�rnap bet�je"};

const char *html_text_Od_prvej_adv_atd[POCET_JAZYKOV + 1] = {
	"Od prvej adventnej nedele v roku %d (%s) pokra�uje <a href=\"%s%s\">liturgick� rok</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"Od prvn� ned�le adventn� v roku %d (%s) pokra�uje <a href=\"%s%s\">liturgick� rok</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"From the 1st Advent Sunday in the year %d (%s) continues <a href=\"%s%s\">liturgical year</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"Od prvej adventnej nedele v roku %d (%s) pokra�uje <a href=\"%s%s\">liturgick� rok</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"",
	"Od prvn� ned�le adventn� v roce %d (%s) pokra�uje <a href=\"%s%s\">liturgick� rok</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"%d (%s) advent els� vas�rnapj�t�l az <"HTML_SPAN_BOLD">%c</span> <a href=\"%s%s\">liturgikus �v</a> folytat�dik.\n",
};

const char *html_text_Po_Velkej_noci_atd[POCET_JAZYKOV + 1] = {
	"Po Ve�kej noci nasleduje %d. %s v cezro�nom obdob�.\n",
	"Po Velikonoc�ch n�sleduje %d. %s v mezibdob�.\n",
	"After Easter follows %d. %s per annum.\n",
	"Po Ve�kej noci nasleduje %d. %s per annum.\n",
	"Po Ve�kej noci nasleduje %d. %s v cezro�nom obdob�.\n", // v obdob� �cez rok�
	"Po Velikonoc�ch n�sleduje %d. %s v mezibdob�.\n",
	"H�sv�t ut�n az �vk�zi id� %d. %sja k�vetkezik.\n", // vas�rnapja, nede�a = vas�rnap
};

const char *html_text_Prikazane_sviatky_v_roku[POCET_JAZYKOV + 1] = {
	"<p><"HTML_SPAN_RED">Prik�zan� sviatky v roku %s:</span>\n",
	"<p><"HTML_SPAN_RED">P�ik�zan� sv�tky v roce %s:</span>\n",
	"<p><"HTML_SPAN_RED">Obliged celebrations in the year %s:</span>\n",
	"<p><"HTML_SPAN_RED">Prik�zan� sviatky v roku %s:</span>\n",
	"<p><"HTML_SPAN_RED">Prik�zan� sviatky v roku %s:</span>\n",
	"<p><"HTML_SPAN_RED">P�ik�zan� sv�tky v roce %s:</span>\n",
	"<p><"HTML_SPAN_RED">%s k�telez� �nnepei:</span>\n",
};

const char *html_text_Jednotlive_mesiace_roku[POCET_JAZYKOV + 1] = {
	"<"HTML_SPAN_RED">Jednotliv� mesiace roku %s:</span>\n",
	"<"HTML_SPAN_RED">Jednotliv� m�s�ce v roce %s:</span>\n",
	"<"HTML_SPAN_RED">Individual months of the year %s:</span>\n",
	"<"HTML_SPAN_RED">Jednotliv� mesiace roku %s:</span>\n",
	"<"HTML_SPAN_RED">Jednotliv� mesiace roku %s:</span>\n",
	"<"HTML_SPAN_RED">Jednotliv� m�s�ce v roce %s:</span>\n",
	"<"HTML_SPAN_RED">Egyes h�napok %s-ben(-ban):</span>\n",
};

const char *str_doplnkova_psalmodia[POCET_JAZYKOV + 1] = 
{"doplnkov� psalm�dia", "�almy z dopl�ovac�ho cyklu", "supplementary psalmody", "psalmodia complementaris", "", "doplnkov� psalmodie", "kieg�sz�t� zsolt�rok" };

const char *str_modl_cez_den_zalmy_zo_dna[POCET_JAZYKOV + 1] = 
	{"be�nej psalm�die", "b�n� psalmodie", "ordinary psalmody", "___", "", "b�n� psalmodie", "soros zsolt�r�ssze�ll�t�st"};
#define		STR_MODL_CEZ_DEN_ZALMY_ZO_DNA 	str_modl_cez_den_zalmy_zo_dna[_global_jazyk]

const char *str_modl_cez_den_doplnkova_psalmodia[POCET_JAZYKOV + 1] = 
	{"doplnkovej psalm�die", "dopl�ovac�ho cyklu", "supplementary psalmody", "psalmodia complementaris", "", "dopl�kov� psalmodie", "kieg�sz�t� zsolt�rok"};
#define		STR_MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA 	str_modl_cez_den_doplnkova_psalmodia[_global_jazyk]

const char *str_modl_zalmy_zo_dna[POCET_JAZYKOV + 1] = 
	{"d�a", "dne", "day", "die", "", "dne", "napt�l"};
#define		STR_MODL_ZALMY_ZO_DNA 	str_modl_zalmy_zo_dna[_global_jazyk]

const char *str_modl_zalmy_zo_sv[POCET_JAZYKOV + 1] = 
	{"sviatku", "sv�tku", "celebration", "___", "", "sv�tku", "�nnept�l"};
#define		STR_MODL_ZALMY_ZO_SV 	str_modl_zalmy_zo_sv[_global_jazyk]

#define STR_VALUE_TRUE  "1"
#define STR_VALUE_FALSE "0"
#define STR_VALUE_ZERO  "0"

const char *str_ano[POCET_JAZYKOV + 1] = 
	{"�no", "ano", "yes", "sic", "___", "ano", "igen"};
#define		STR_ANO		str_ano[_global_jazyk]

const char *str_nie[POCET_JAZYKOV + 1] = 
	{"nie", "ne", "no", "non", "___", "ne", "nem"};
#define		STR_NIE		str_nie[_global_jazyk]

const char *html_text_jazyk_android = "SK/CZ/HU:";

const char *html_text_jazyk[POCET_JAZYKOV + 1] = 
{"Liturgia hod�n v jazyku:",
 "Liturgie hodin pro jazyk:",
 "Liturgy of hours in language:",
 "LH in lingua:",
 "",
 "Liturgie hodin pro jazyk:",
 ""
};

const char *html_text_jazyk_explain[POCET_JAZYKOV + 1] = 
{"Liturgia hod�n pre in� jazyk.",
 "Liturgie hodin pro jin� jazyk.",
 "Liturgy of hours in other languages.",
 "LH in lingua...",
 "",
 "Liturgie hodin pro jin� jazyk.",
 ""
};

const char *html_text_detaily_uvod[POCET_JAZYKOV + 1] = 
{"Nasledovn� mo�nosti ovplyvnia vzh�ad i obsah vygenerovanej modlitby.\nVyberte tie mo�nosti, pod�a ktor�ch sa m� modlitba vygenerova�.", 
 "N�sleduj�c� mo�nosti maj� vliv na vzhled i obsah vygenerovan� modlitby.\nVyberte si mo�nosti, podle kter�ch m� b�t modlitba vygenerov�na.", 
 "The following options apply to the resulting generated text of the prayer.\nChoose options which fit your needs to the resulting prayer text.", 
 "",
 "",
 "N�sleduj�c� mo�nosti maj� vliv na vzhled i obsah vygenerovan� modlitby.\nVyberte si mo�nosti, podle kter�ch m� b�t modlitba vygenerov�na.",
 "Ez a v�laszt�si lehet�s�g befoly�solja a megszerkesztett ima megjelen�t�s�t �s tartalm�t.\nV�lassz a szerkeszthet� lehet�s�gek k�z�l."
};

const char *html_text_option1_kalendar[POCET_JAZYKOV + 1] = 
{"nastavenia pre liturgick� kalend�r",
 "volby pro liturgick� kalend��",
 "options for liturgical calendar",
 "", 
 "", 
 "volby pro liturgick� kalend��",
 "a liturgikus napt�r be�ll�t�sai"
};

const char *html_text_option1_kalendar_explain[POCET_JAZYKOV + 1] = 
{"Liturgia hod�n pon�ka mo�nos� sl�venia niektor�ch sl�ven� dvojak�m sp�sobom; z�vis� od danej krajiny, ako rozhodla pr�slu�n� konferencia biskupov.",
 "Volby pro liturgick� kalend�� ovliv�uj� datumy n�kter�ch slaven�.",
 "Options for liturgical calendar...",
 "", 
 "", 
 "Volby pro liturgick� kalend�� ovliv�uj� datumy n�kter�ch slaven�.",
 "Az Ima�r�k liturgi�ja megadja a lehet�s�get, hogy n�mely �nnepek k�tf�le k�pen legyenek meg�nnepelve; az adott orsz�gt�l f�gg, ahogy az adott p�sp�ki konferencia d�nt�tt."
};

const char *html_text_option1_nemenne_sucasti[POCET_JAZYKOV + 1] = 
{"zobrazi� nasledovn� s��asti modlitby?",
 "zobrazit <i>nem�nn� sou��sti</i> modlitby?",
 "display <i>non-changeable parts</i> prayer?",
 "", 
 "", 
 "zobrazit <i>nem�nn� sou��sti</i> modlitby?",
 "jelenjenek meg az ima�ra k�vetkez� elemei:"
};

const char *html_text_option1_nemenne_sucasti_explain[POCET_JAZYKOV + 1] = 
{"Ka�d� rann� chv�ly obsahuj� Benediktus, ve�pery Magnifikat, obe modlitby obsahuj� Ot�en� a zakon�enie modlitby, a napokon posv�tn� ��tanie obsahuje niekedy hymnus Te Deum; tieto �asti modlitby mo�no zobrazi� alebo skry�.", 
 "Ka�d� rann� chv�ly obsahuj� Zachari�ovo kantikum, ne�pory Mariin Magnifikat, ob� modlitbu P�n� a zakon�en� modlitby, a kone�n� modlitba se �ten�m n�kdy obsahuje hymnus Te Deum; tyto ��sti modliteb je mo�n� zobrazit/skr�t.", 
 "Each morning prayer contains Benedictus, vesperae contains Magnificat, both contain the Lord's Prayer and a conclusion of the prayer; finally, the holy reading sometimes contains the Te Deum hymnus; all these parts can be shown/hidden.", 
 "",
 "", 
 "Ka�d� rann� chv�ly obsahuj� Zachari�ovo kantikum, ve�ern� chv�ly kantikum Panny Marie, ob� modlitbu P�n� a zakon�en� modlitby, a kone�n� modlitba se �ten�m n�kdy obsahuje hymnus Te Deum; tyto ��sti je mo�n� zobrazit/skr�t.",
 ""
};

const char *html_text_option1_dalsie_prepinace[POCET_JAZYKOV + 1] = 
{"mo�nosti pre v�sledn� modlitby",
 "mo�nosti pro v�sledn� modlitby",
 "options for generated prayers",
 "", 
 "", 
 "mo�nosti pro v�sledn� modlitby",
 "egy�b v�laszt�si lehet�s�gek:"
};

const char *html_text_option1_dalsie_prepinace_explain[POCET_JAZYKOV + 1] = 
{"Rozli�n� mo�nosti/v�bery pre v�sledn� modlitby.", 
 "", 
 "", 
 "",
 "", 
 "",
 ""
};

const char *html_text_zalmy_brat_zo[POCET_JAZYKOV + 1] = 
{"�almy pou�i� zo ", 
 "�almy pou��t ze ", 
 "take psalmody from ", 
 "", 
 "", 
 "�almy pou��t ze ",
 "zsolt�rok a k�vetkez� helyr�l:"
};
const char *html_text_zalmy_brat_zo_okrem_mcd[POCET_JAZYKOV + 1] = 
{" (okrem modlitby cez de�)\n", 
 " (krom� modlitby p�es den)\n", 
 " (excluding the prayers during the day)\n", 
 "", 
 "", 
 " (krom� modlitby b�hem dne)\n",
 " (a Napk�zi im�t kiv�ve)"
};

const char *html_text_spol_casti_vziat_zo[POCET_JAZYKOV + 1] = 
{"�asti modlitby zo spolo�nej �asti ", 
 "��sti modlitby ze spole�n� ��sti ", 
 "parts of prayer from the common part ", 
 "",
 "",
 "��sti modlitby ze spole�n� ��sti ",
 "a k�z�s r�szb�l"};
const char *html_text_spol_casti_vziat_zo_explain[POCET_JAZYKOV + 1] = 
{"Na sviatok sv�tca/sv�tice sa pod�a liturgick�ch pravidiel ber� �asti, ktor� sa nenach�dzaj� vo vlastnej �asti �alt�ra, zo spolo�nej �asti sviatku, niekedy je mo�nos� vybra� si z viacer�ch spolo�n�ch �ast�; naviac je mo�nos� modli� sa tieto �asti zo v�edn�ho d�a.", 
 "Na sv�tek ke cti sv�tce/sv�tice se podle liturgick�ch pravidel berou ��sti, kter� se nenach�z� ve vlastn�ch textech, ze spole�n�ch text�, n�kdy je mo�n� vybrat si z v�ce spole�n�ch text�; nav�c je mo�nost modlit se tyto ��sti ze v�edn�ho dne.", 
 "", 
 "",
 "",
 "O sv�tku ke cti sv�tce/sv�tice se podle liturgick�ch pravidel berou ��sti, kter� se nenach�z� ve vlastn�ch textech, ze spole�n�ch text�, n�kdy je mo�n� vybrat si z v�ce spole�n�ch text�; nav�c je mo�nost modlit se tyto ��sti ze v�edn�ho dne.",
 "A szentek �nnep�n, a liturgikus el��r�sok szerint, azok az ima r�szek, amelyek nem tal�lhat�k meg a zsolozsma saj�t r�sz�ben,  tetsz�s szerint vehet�k vagy a  k�z�s r�szb�l, n�ha t�bb k�z�s r�szb�l lehet v�lasztani, vagy a k�znapr�l."
};

const char *html_text_option0_specialne[POCET_JAZYKOV + 1] = 
{"v texte modlitieb zobrazi�",
 "v textu modliteb zobrazit",
 "in the text of prayers display",
 "",
 "",
 "v textu modliteb zobrazit",
 "az ima�ra sz�veg�ben jelenjen meg:"
};

const char *html_text_option0_specialne_explain[POCET_JAZYKOV + 1] = 
{"Mo�nos� zobrazi� �al�ie �daje v texte modlitieb (��sla ver�ov, referencie a pod.).",
 "",
 "",
 "",
 "",
 "",
 ""
};

const char *html_text_option0_verse[POCET_JAZYKOV + 1] = 
{"��slovanie (��sla) ver�ov",
 "��slov�n� ver��",
 "verse numbering",
 "verse numbers",
 "",
 "��slov�n� ver��",
 "a versek sz�ma"
};

const char *html_text_option0_verse_explain[POCET_JAZYKOV + 1] = 
{"Liturgia hod�n (latinsk� typick� vydanie) zobrazuje ��slovanie ver�ov v r�mci �almu, chv�lospevu alebo dlh�ieho biblick�ho ��tania; niektor� vydania tieto ��sla ver�ov neuv�dzaj�.", 
 "Liturgie hodin uv�d� jako horn� indexy ��sla ver�� biblick�ch text� (�alm�, chvalozp�v� a prvn�ch �ten�), kter� m��e program zobrazit.", 
 "xxx", 
 "",
 "", 
 "Liturgie hodin uv�d� jako horn� indexy ��sla ver�� biblick�ch text� (�alm�, chvalozp�v� a prvn�ch �ten�), kter� m��e program zobrazit.", 
 "Az ima�r�k liturgi�ja (latin tipikus kiad�s) megjelen�ti a zsolt�rokban, kantikumokban �s hosszabb szent�r�si olvasm�nyokban a versek sz�moz�s�t. Egyes kiad�sok e sz�moz�st nem tartalmazz�k."
};

const char *html_text_option0_referencie[POCET_JAZYKOV + 1] = 
{"biblick� odkazy na dkc.kbs.sk",
 "biblick� odkazy",
 "biblical references",
 "Bible references",
 "",
 "biblick� odkazy",
 "Bibliai hivatkoz�sok a kereszteny.hu oldalon"
};

const char *html_text_option0_referencie_explain[POCET_JAZYKOV + 1] = 
{"V�etky biblick� odkazy (napr. Jn 3, 16) v modlitbe bud� akt�vnymi odkazmi na text katol�ckeho prekladu Biblie na adrese dkc.kbs.sk.", 
 "", 
 "", 
 "",
 "", 
 "", 
 "Az im�k sz�veg�ben minden bibliai utal�s (p�ld�ul Jn 3, 16) akt�v linkk�nt a kereszteny.hu katolikus bibliaford�t�s�nak megfell� r�sz�re mutat. (A Szent Istv�n T�rsulat ford�t�s�t haszn�ljuk.)"
};

const char *html_text_option0_citania[POCET_JAZYKOV + 1] = 
{"liturgick� ��tania",
 "liturgick� �ten�",
 "liturgical readings",
 "liturgical readings",
 "",
 "liturgick� �ten�",
 "liturgikus olvasm�nyok"
};

const char *html_text_option0_citania_explain[POCET_JAZYKOV + 1] = 
{"Zobraz� odkaz na liturgick� ��tania (lc.kbs.sk).", 
 "Zobraz� odkaz na liturgick� �ten� (katolik.cz).", 
 "", 
 "",
 "", 
 "Zobraz� odkaz na liturgick� �ten� (katolik.cz).", 
 "Liturgikus olvasm�nyok (katolikus.hu)."
};

const char *html_text_option0_zjv_ne[POCET_JAZYKOV + 1] = 
{"Zjavenie P�na sl�vi� v nede�u medzi 2. a 8. janu�rom",
 "Zjeven� P�n� slavit v ned�li mezi 2. a 8. lednem",
 "",
 "",
 "",
 "Zjeven� P�n� slavit v ned�li mezi 2. a 8. lednem",
 "Urunk megjelen�se (V�zkereszt) meg�nnepl�se vas�rnap, janu�r 2. �s 8. k�z�tt"
};

const char *html_text_option0_zjv_ne_explain[POCET_JAZYKOV + 1] = 
{"Zjavenie P�na sa sl�vi d�a 6. janu�ra; v niektor�ch krajin�ch sa sl�vi v nede�u medzi 2. a 8. janu�rom.", 
 "", 
 "", 
 "",
 "", 
 "", 
 "Urunk megjelen�se (V�zkereszt) janu�r 6.-�n van; egyes orsz�gokban azonban vas�rnap, janu�r 2. �s 8. k�z�tt �nneplik."
};

const char *html_text_option0_nan_ne[POCET_JAZYKOV + 1] = 
{"Nanebovst�penie P�na sl�vi� v nede�u",
 "Nanebevstoupen� P�n� slavit v ned�li",
 "",
 "",
 "",
 "Nanebevstoupen� P�n� slavit v ned�li",
 "Urunk mennybemenetel�t vas�rnap �nnepelni"
};

const char *html_text_option0_nan_ne_explain[POCET_JAZYKOV + 1] = 
{"Nanebovst�penie P�na sa sl�vi 40. de� po Ve�kej noci (teda vo �tvrtok); v niektor�ch krajin�ch sa sl�venie preklad� na najbli��iu nede�u (nahr�dza 7. ve�kono�n� nede�u).", 
 "", 
 "", 
 "",
 "", 
 "", 
 "Urunk mennybemenetele h�sv�t ut�n a 40. napon van (teh�t cs�t�rt�k�n); egyes orsz�gokban azonban a legk�zelebbi vas�rnapon �nneplik (vagyis H�sv�t 7. vas�rnapj�n)."
};

const char *html_text_option0_tk_ne[POCET_JAZYKOV + 1] = 
{"Najsv. Kristovho tela a krvi sl�vi� v nede�u",
 "T�la a krve P�n� slavit v ned�li",
 "",
 "",
 "",
 "T�la a krve P�n� slavit v ned�li",
 "Krisztus Szent Teste �s V�re �nnepe vas�rnapra t�ve"
};

const char *html_text_option0_tk_ne_explain[POCET_JAZYKOV + 1] = 
{"Najsv. Kristovho tela a krvi sa sl�vi 11. de� po Zoslan� Ducha Sv�t�ho (teda vo �tvrtok po Najsv. Trojici); v niektor�ch krajin�ch sa sl�venie preklad� na najbli��iu nede�u.", 
 "", 
 "", 
 "",
 "", 
 "", 
 "Krisztus Szent Teste �s V�re P�nk�sd ut�n a 11. napon van (teh�t Szenth�roms�g ut�ni cs�t�rt�k�n); egyes orsz�gokban azonban a legk�zelebbi vas�rnapon �nneplik."
};

const char *html_text_option1_chvalospevy[POCET_JAZYKOV + 1] = 
{"evanjeliov� chv�lospevy (Benediktus, Magnifikat, Nunk dimittis)", 
 "evangelijn� kantika (Mariino, Zachari�ovo, Simeonovo)", 
 "Gospel canticles (Benedictus, Magnificat, Nunc dimittis)", 
 "",
 "",
 "evangelijn� chvalozp�vy (Benedictus, Magnificat, Nunc dimittis)", 
 "evang�liumi kantikumok (Benedictus, Magnificat, Nunc dimittis)"
};
const char *html_text_option1_chvalospevy_explain[POCET_JAZYKOV + 1] = 
{"Liturgia hod�n �tandardne tieto evanjeliov� chv�lospevy neuv�dza.", 
 "Liturgie hodin evangelijn� kantika v pln�m zn�n� obvykle neuv�d�.", 
 "", 
 "",
 "", 
 "Liturgie hodin evangelijn� chvalozp�vy v pln�m zn�n� obvykle neuv�d�.", 
 "Az ima�r�k liturgi�ja ezeket az evang�liumi kantikumokat alaphelyzetben nem mutatja."
};

const char *html_text_option1_slava_otcu[POCET_JAZYKOV + 1] = 
{"Sl�va Otcu" /*[na konci �almov a chv�lospevov]*/, 
 "Sl�va Otci" /*[na konci �alm� a kantik]*/, 
 "Gloria to the Father" /*at the end of psalms and canticles]*/, 
 "",
 "",
 "Sl�va Otci" /*[na konci �alm� a chvalozp�v�]*/, 
 "Dics�s�g az Aty�nak" /*[a zsolt�rok �s kantikumok v�g�n]*/
};
const char *html_text_option1_slava_otcu_explain[POCET_JAZYKOV + 1] = 
{"Liturgia hod�n �tandardne Sl�va Otcu na konci �almov a chv�lospevov neuv�dza.", 
 "Liturgie hodin modlitbu Sl�va Otci na konci �alm� a chvalozp�v� neuv�d�.", 
 "", 
 "",
 "", 
 "Liturgie hodin modlitbu Sl�va Otci na konci �alm� a chvalozp�v� neuv�d�.", 
 "Az ima�r�k liturgi�ja a Dics�s�g az Aty�nak ... dics��t� verset a zsolt�rok �s kantikumok v�g�n alaphelyzetben nem mutatja."
};

const char *html_text_option1_rubriky[POCET_JAZYKOV + 1] = 
{"rubriky" /*(napr. z�vere�n� po�ehnanie)*/, 
 "rubriky" /*(nap�. z�v�re�n� po�ehn�n�)*/, 
 "rubrics", 
 "",
 "",
 "rubriky" /*(nap�. z�v�re�n� po�ehn�n�)*/, 
 "rubrik�k" /*(pl. z�r� �ld�s)*/
};
const char *html_text_option1_rubriky_explain[POCET_JAZYKOV + 1] = 
{"Liturgia hod�n zobrazuje �erven�m p�smom rozli�n� zvy�ajne vysvet�uj�ce pokyny k modlitbe (pod�a V�eobecn�ch smern�c o LH).", 
 "Liturgie hodin uv�d� �erven�m p�smem rozli�n� pokyny k modlitb� (�asto podle V�eobecn�ch pokyn� k denn� modlitb� c�rkve).", 
 "", 
 "",
 "", 
 "Liturgie hodin uv�d� �erven�m p�smem rozli�n� pokyny k modlitb� (�asto podle V�eobecn�ch pokyn� k denn� modlitb� C�rkve).", 
 "Az ima�r�k liturgi�ja piros bet�vel k�l�nb�z� t�bbnyire magyar�z� vagy az ima�r�t (az ��ltal�nos rendelkez�sek Az ima�r�k liturgi�j�r�l� szerint) szab�lyoz� sz�vegeket jelen�t meg. Alaphelyzetben nem mutatja."
};

const char *html_text_option1_otcenas[POCET_JAZYKOV + 1] = 
{"modlitba P�na (Ot�en�)", 
 "modlitba P�n� (Ot�en�)", 
 "Lord's Prayer (Our Father)", 
 "",
 "",
 "modlitba P�n� (Ot�en�)", 
 "az �r im�ds�ga (Miaty�nk)"
};
const char *html_text_option1_otcenas_explain[POCET_JAZYKOV + 1] = 
{"Liturgia hod�n �tandardne modlitbu P�na (Ot�en�) v rann�ch chv�lach a ve�per�ch v plnom znen� neuv�dza.", 
 "Liturgie hodin modlitbu P�n� (Ot�en�) na p��slu�n�ch m�stech v pln�m zn�n� neuv�d�.", 
 "", 
 "",
 "", 
 "Liturgie hodin modlitbu P�n� (Ot�en�) na p��slu�n�ch m�stech v pln�m zn�n� neuv�d�.", 
 "Az ima�r�k liturgi�ja az �r im�ds�g�t (Miaty�nkot) a Reggeli �s Esti dics�retben alaphelyzetben nem mutatja."
};

const char *html_text_option1_tedeum[POCET_JAZYKOV + 1] = 
{"hymnus Te Deum", 
 "hymnus Te Deum", 
 "hymnus Te Deum", 
 "",
 "",
 "hymnus Te Deum", 
 "T�ged, Isten, dics�r�nk ... himnusz"
};
const char *html_text_option1_tedeum_explain[POCET_JAZYKOV + 1] = 
{"Liturgia hod�n hymnus Te Deum v posv�tnom ��tan� v plnom znen� neuv�dza.", 
 "Liturgie hodin hymnus Te Deum na p��slu�n�ch m�stech v pln�m zn�n� neuv�d�.", 
 "", 
 "",
 "", 
 "Liturgie hodin hymnus Te Deum na p��slu�n�ch m�stech v pln�m zn�n� neuv�d�.", 
 "Az ima�r�k liturgi�ja a T�ged, Isten, dics�r�nk ... himnuszt az Olvasm�nyos ima�r�ban alaphelyzetben nem mutatja."
};

const char *html_text_option1_plne_resp[POCET_JAZYKOV + 1] = 
{"pln� znenie responz�ri� pre posv�tn� ��tania", 
 "pln� zn�n� kr�tk�ch zp�v� v modlitb� se �ten�m", 
 "", 
 "",
 "",
 "pln� zn�n� responsori� v modlitb� se �ten�m", 
 "a v�laszos �nekek teljes sz�vege"
};
const char *html_text_option1_plne_resp_explain[POCET_JAZYKOV + 1] = 
{"Liturgia hod�n responz�ri� po ��taniach v posv�tnom ��tan� v plnom znen� neuv�dza (druh�, opakuj�ca sa �as�, je v tla�enej LH skr�ten�).", 
 "Liturgie hodin responsoria po �ten�ch v modlitbe se �ten�m neuv�d� v druh�, opakuj�c� se ��sti, pln� zn�n�.", 
 "", 
 "",
 "", 
 "Liturgie hodin responsoria po �ten�ch v modlitbe se �ten�m neuv�d� v druh�, opakuj�c� se ��sti, pln� zn�n�.", 
 "Az Ima�r�k Liturgi�ja az olvasm�nyos ima�r�k v�laszos �nekeinek teljes sz�veg�t nem mutatja (a m�sodik ism�tl�d� r�sz nyomtatott kiad�sban r�vid�tett)."
};

const char *html_text_option_zobrazit[POCET_JAZYKOV + 1] = 
{"zobrazi�", 
 "zobrazit", 
 "xxx", 
 "show",
 "",
 "zobrazit", 
 "megmutatni"
};
const char *html_text_option_skryt[POCET_JAZYKOV + 1] = 
{"skry�", 
 "skr�t", 
 "xxx", 
 "hide",
 "",
 "skr�t", 
 "elrejt�s"
};

const char *html_text_option1_mcd_zalmy_nie_ine[POCET_JAZYKOV + 1] = 
{"pre modlitbu cez de� pou�i� psalm�diu zo d�a", 
 "pro modlitbu b�hem dne pou��t �almy z b�n�ho dne", 
 "xxx", 
 "psalmodia from ordinary day",
 "",
 "pro modlitbu b�hem dne pou��t psalmodii z b�n�ho dne", 
 "a Napk�zi ima�r�ban az adott napi zsolt�roz�st venni"
};
const char *html_text_option1_mcd_zalmy_ine[POCET_JAZYKOV + 1] = 
{"pre modlitbu cez de� pou�i� doplnkov� psalm�diu", 
 "pro modlitbu b�hem dne pou��t �almy z dopl�ovac�ho cyklu", 
 "xxx", 
 "psalmodia from ordinary day",
 "",
 "pro modlitbu b�hem dne pou��t dopl�kovou psalmodii", 
 "a Napk�zi ima�r�ban a kieg�sz�t� zsolt�rokat venni"
};
const char *html_text_option1_mcd_zalmy_ine_explain[POCET_JAZYKOV + 1] = 
{"Pokia� sa niekto modl� viac modlitieb cez de�, v prvej vezme be�n� psalm�diu; v ostatn�ch sa pou�ije doplnkov� psalm�dia. Zah��a 3 s�rie tzv. gradu�lnych �almov (� 120 � 129).", 
 "Dopl�ovac� cyklus �alm� obsahuje 3 s�rie tzv. gradu�ln�ch �alm� (� 120 � 129), kter� je mo�no pou��t m�sto �alm� ze �alt��e.", 
 "", 
 "",
 "", 
 "Dopl�ovac� cyklus �alm� obsahuje 3 s�rie tzv. gradu�ln�ch �alm� (� 120 � 129), kter� je mo�no pou��t m�sto �alm� ze �alt��e.", 
 "Aki t�bb Napk�zi ima�r�t mond, az egyik ima�r�ban a soros zsolt�r�ssze�ll�t�st veszi, a t�bbin a kieg�sz�t�t. Ez az �gynevezett �zar�ndokzsolt�rokb�l� vett h�rom-h�rom zsolt�rb�l �ll (Zsolt 119 � 127)."
};

const char *html_text_option1_zalm95[POCET_JAZYKOV + 1] = 
{"namiesto �almov 24, 67 resp. 100 pou�i� �alm 95", 
 "m�sto �alm� 24, 67 resp. 100 pou��t �alm 95", 
 "xxx", 
 "psalm 95",
 "",
 "m�sto �alm� 24, 67 resp. 100 pou��t �alm 95", 
 "a 23., 66. illetve a 99.  zsolt�r helyett legyen a 94."
};
const char *html_text_option1_zalm95_explain[POCET_JAZYKOV + 1] = 
{"Ak sa v rann�ch chv�lach, ve�per�ch alebo posv�tnom ��tan� vyskytne �alm 24, 67 resp. 100, ktor� bol pou�it� pre invitat�rium, nahrad� sa v pr�slu�nej modlitbe �almom 95.", 
 "Kdy� se v rann�ch chv�l�ch, modlitb� se �ten�m nebo ne�por�ch vyskytne �alm 24, 67 resp. 100, kter� se pou�il pro uveden� do prvn� modlitby dne, nahrad� se v p��slu�n� modlitb� �almem 95.", 
 "xxx", 
 "xxx",
 "xxx", 
 "Kdy� se v rann�ch chv�l�ch, modlitb� se �ten�m nebo ve�ern�ch chv�l�ch vyskytne �alm 24, 67 resp. 100, kter� se pou�il pro invitatorium, nahrad� se v p��slu�n� modlitb� �almem 95.", 
 "Ha a reggeli �s az esti dics�retben, vagy az olvasm�nyos ima�r�ban el�fordul a 23., 66. illetve 99. zsolt�r, amely az Im�ds�gra h�v�sban m�r im�dkozva volt, akkor az adott im�ds�gban a 94. zsolt�r ker�l hely�be."
};

const char *html_text_option_zobrazit_zvolania[POCET_JAZYKOV + 1] = 
{"opakova� zvolanie po ka�dej prosbe", 
 "zopakovat zvol�n� po ka�d� prosb�", 
 "xxx", 
 "repeat invocation after each appeal",
 "",
 "zopakovat zvol�n� po ka�d� prosb�", 
 "megism�telni a v�laszt minden k�ny�rg�s ut�n"
};
const char *html_text_option_skryt_zvolania[POCET_JAZYKOV + 1] = 
{"skry� zvolanie po ka�dej prosbe", 
 "skr�t zvol�n� po ka�d� prosb�", 
 "xxx", 
 "hide invocation after each appeal",
 "",
 "skr�t zvol�n� po ka�d� prosb�", 
 "elrejteni a v�laszt minden k�ny�rg�s ut�n"
};

const char *html_text_option_zobrazit_kratsie_prosby[POCET_JAZYKOV + 1] = 
{"pou�i� krat�ie prosby z dodatku", 
 "zobrazit krat�� prosby z dodatku", 
 "xxx", 
 "use shorten prayers",
 "",
 "zobrazit krat�� prosby z dodatku", 
 "haszn�lja a r�videbb k�ny�rg�seket a f�ggel�kb�l"
};
const char *html_text_option_skryt_kratsie_prosby[POCET_JAZYKOV + 1] = 
{"nepou�i� krat�ie prosby z dodatku", 
 "nezobrazit krat�� prosby z dodatku", 
 "xxx", 
 "do not use shorten prayers",
 "",
 "nezobrazit krat�� prosby z dodatku", 
 "ne haszn�lja a r�videbb k�ny�rg�seket a f�ggel�kb�l"
};

const char *html_text_option1_prosby_zvolanie[POCET_JAZYKOV + 1] = 
{"zvolanie v prosb�ch opakova� po ka�dej prosbe", 
 "zvol�n� v prosb�ch zopakovat po ka�d� prosb�", 
 "xxx", 
 "invocation repeat after each appeal",
 "",
 "zvol�n� v prosb�ch zopakovat po ka�d� prosb�", 
 "minden foh�sz ut�n ism�telni a v�laszt"
};
const char *html_text_option1_prosby_zvolanie_explain[POCET_JAZYKOV + 1] = 
{"V rann�ch chv�lach a ve�per�ch opakova� zvolanie v prosb�ch po ka�dej prosbe.", 
 "V rann�ch chv�l�ch a ne�por�ch opakovat svol�n� v prosb�ch po ka�d� prosb�.", 
 "xxx", 
 "In morning and evening prayer repeat invocation after each appeal.",
 "xxx", 
 "V rann�ch a ve�ern�ch chv�l�ch opakovat svol�n� v prosb�ch po ka�d� prosb�.", 
 "A reggeli �s az esti dics�retben minden foh�sz ut�n ism�telni a v�laszt."
};

const char *html_text_option1_skryt_popis_svaty[POCET_JAZYKOV + 1] = 
{"nezobrazi� popis k modlitbe sv�t�ho", 
 "nezobrazit popis p�i modlitb� ke cti sv�tce", 
 "do not display description for prayer for the saints", 
 "", 
 "", 
 "nezobrazit popis p�i modlitb� ke cti sv�tce",
 "a szent ima�r�j�ban ne mutatkozzon le�r�s"
};

const char *html_text_option1_skryt_popis_svaty_explain[POCET_JAZYKOV + 1] = 
{"Modlitby zv��a obsahuj� pred n�zvom modlitby �ivotopis sv�t�ho, popis sviatku alebo podobn� stru�n� charakteristiku, ktor� pre jednoduchos� naz�vame popis.", 
 "Modlitby ke cti svat�ch obsahuj� stru�n� �ivotopis svat�ho, p�i sv�tku je to stru�n� popis sv�tku a podobn�. Tyto charakteristiky pro stru�nost naz�v�me popis.", 
 "xxx", 
 "",
 "", 
 "Modlitby ke cti svat�ch obsahuj� stru�n� �ivotopis svat�ho, u sv�tku je to stru�n� popis sv�tku a podobn�. Tyto charakteristiky pro stru�nost naz�v�me popis.",
 "T�bbnyire az im�k az ima�ra elnevez�se el�tt a szent �letrajz�t, az �nnep le�r�s�t vagy m�s r�vid jegyzetet tartalmaznak, amit az egyszer�s�g kedv��rt le�r�snak nevez�nk."
};

const char *html_text_option1_spolc_svaty[POCET_JAZYKOV + 1] = 
{"zobrazi�, odkia� sa ber� �asti zo spolo�nej �asti k modlitbe sv�t�ho", 
 "zobrazit, odkud se berou spole�n� texty", 
 "display communia info", 
 "", 
 "", 
 "zobrazit, odkud se berou spole�n� texty",
 "megmutatni, honnan lettek v�ve a k�z�s r�szek a szentek zsolozsm�j�hoz"
};

const char *html_text_option1_spolc_svaty_explain[POCET_JAZYKOV + 1] = 
{"Rubrika obsahuj�ca inform�ciu, z akej spolo�nej �asti sa ber� �asti zo spolo�nej �asti k modlitbe sv�t�ho.", 
 "Rubrika, kter� pro modlitby svat�ch informuje, kter� spole�n� texty jsou u�ity.", 
 "Displays communia info.", 
 "", 
 "", 
 "Rubrika, kter� pro modlitby svat�ch informuje, kter� spole�n� texty jsou u�ity.",
 "Rubrika, amely azt az inform�ci�t tartalmazza, hogy melyik k�z�s r�szb�l vannak v�ve a szentek zsolozsm�j�hoz tartoz� k�z�s r�szek."
};

const char *html_text_option1_vesp_kratsie_prosby[POCET_JAZYKOV + 1] = 
{"pre ve�pery pou�i� krat�ie prosby z dodatku", 
 "pro ne�pory pou��t krat�� prosby z dodatku", 
 "use shorten prayers for vespers", 
 "", 
 "", 
 "pro ve�ern� chv�ly pou��t krat�� prosby z dodatku", 
 "Esti dics�retre haszn�lja a r�videbb k�zbenj�r� foh�szokat a f�ggel�kb�l"
};

const char *html_text_option1_vesp_kratsie_prosby_explain[POCET_JAZYKOV + 1] = 
{"Pre ve�pery pou�i� krat�ie prosby z dodatku namiesto t�ch, ktor� s� ur�en� pre ve�pery dan�ho d�a.", 
 "Pro ne�pory pou��t krat�� prosby z dodatku m�sto ur�en�ch pro p��slu�n� den.", 
 "Use shorten prayers for vespers instead of those prescribed for the day.", 
 "", 
 "", 
 "Pro ve�ern� chv�ly pou��t krat�� prosby z dodatku m�sto ur�en�ch pro p��slu�n� den.",
 "Esti dics�retre haszn�lja a r�videbb k�zbenj�r� foh�szokat a f�ggel�kb�l, a napra meghat�rozott helyett."
};

const char *html_text_option1_vigilia[POCET_JAZYKOV + 1] = 
{"pred�en� sl�venie vig�lie pre posv�tn� ��tanie" /*(na nedele, sl�vnosti a sviatky)*/, 
 "prodlou�en� slaven� vigilie pro modlitbu se �ten�m" /*(pro ned�le, slavnosti a sv�tky)*/, 
 "celebrating of vigily for prayer with readings" /*(for Sundays, solemnitas and festivus)*/, 
 "",
 "",
 "prodlou�en� slaven� vigilie pro modlitbu se �ten�m" /*(pro ned�le, slavnosti a sv�tky)*/, 
 "hosszabb vig�li�s �nnepl�s Olvasm�nyos ima�r�val" /*(vas�rnap, f��nnep �s �nnep el�tt)*/
};
const char *html_text_option1_vigilia_explain[POCET_JAZYKOV + 1] = 
{"T�, �o chc� pod�a trad�cie pred�i� vig�liu nedele, sl�vnosti alebo sviatku, �o sa ve�mi odpor��a, najprv recituj� posv�tn� ��tanie; po oboch ��taniach, pred hymnom Te Deum, prid�vaj� sa chv�lospevy a evanjelium.", 
 "Ti, kte�� cht�j� podle tradice prodlou�it vigilii ned�le, slavnosti nebo sv�tku, co� se velmi doporu�uje, recituj� nejprve �ten�; po obou �ten�ch, p�ed hymnem Te Deum, se p�id�vaj� chvalozp�vy a evangelium.", 
 "For Sundays, solemnitas and festivus: celebrating of vigily for prayer with readings.", 
 "",
 "", 
 "Ti, kte�� cht�j� podle tradice prodlou�it vigilii ned�le, slavnosti nebo sv�tku, co� se velmi doporu�uje, recituj� nejprve �ten�; po obou �ten�ch, p�ed hymnem Te Deum, se p�id�vaj� chvalozp�vy a evangelium.", 
 "Akik a hagyom�nyokhoz h�ven vas�rnap, f��nnep �s �nnep el�tt hosszabb vig�li�s �nnepl�st akarnak tartani, el�sz�r v�gezz�k el az Olvasm�nyos ima�r�t, a k�t olvasm�ny ut�n �s a T�ged, Isten, dics�r�nk himnusz el�tt vegy�k hozz� a kantikumokat �s ut�na az evang�liumot."
};

const char *html_text_option1_spomienka_spolcast[POCET_JAZYKOV + 1] = 
{"na spomienky pou�i� �asti zo spolo�n�ch �ast�", 
 "na pam�tky pou��t ��sti ze spole�n�ch ��st�", 
 "take parts from celebration -- commmons", 
 "", 
 "", 
 "na pam�tky pou��t ��sti ze spole�n�ch ��st�", 
 "eml�knapon a jelzett r�szeket a k�z�s r�szb�l venni"
};

const char *html_text_option1_spomienka_spolcast_explain[POCET_JAZYKOV + 1] = 
{"Zvoli�, �i sa antif�na na invitat�rium, hymnus, kr�tke ��tanie, antif�ny na Benediktus a Magnifikat a prosby, ak nie s� vlastn� ber� zo spolo�nej �asti (in�� z be�n�ho v�edn�ho d�a); �. 235 b) v�eobecn�ch smern�c.", 
 "", 
 "", 
 "",
 "", 
 "",
 "Kiv�lasztani, hogy az im�ds�gra h�v�s antif�n�ja, himnusz, r�vid olvasm�ny, a Benedictus �s a Magnifikat antif�n�ja �s a foh�szok a k�z�s r�szb�l legyenek v�ve (egy�bk�nt a k�znapr�l) a 235 b) �ltal�nos rendelkez�s szerint."
};

const char *html_text_option1_spomienka_spolcast_NIE[POCET_JAZYKOV + 1] = 
{"na spomienky pou�i� �asti zo d�a, nie zo spolo�n�ch �ast�", 
 "na pam�tky pou��t ��sti z b�n�ho dne, ne ze spole�n�ch ��st�", 
 "take parts from feria -- not commmons", 
 "", 
 "", 
 "na pam�tky pou��t ��sti z b�n�ho dne, ne ze spole�n�ch ��st�", 
 "eml�knapon a jelzett r�szeket az adott napr�l venni, nem a k�z�s r�szb�l"
};

const char *html_text_option2_html_export[POCET_JAZYKOV + 1] = 
{"mo�nosti zobrazenia str�nok",
 "mo�nosti zobrazen� str�nek",
 "display options",
 "",
 "",
 "mo�nosti zobrazen� str�nek",
 "az oldalak megjelen�t�s�nek lehet�s�gei:"
};

const char *html_text_option2_html_export_explain[POCET_JAZYKOV + 1] = 
{"Tieto mo�nosti ovplyvnia rozli�n� zobrazenia, nemaj� vplyv na obsah (text) modlitieb.",
 "Mo�nosti ovlivn� rozli�n� zobrazen�, neovlivn� obsah (text) modliteb.",
 "These various options have no influence to generated text of prayers, used only for visualization.",
 "",
 "",
 "Mo�nosti ovlivn� rozli�n� zobrazen�, neovlivn� obsah (text) modliteb.",
 "Ezek a be�ll�t�sok hat�ssal vannak a formai megjelen�t�sre, de az imasz�veg nem v�ltozik."
};

const char *html_text_option2_prve_vespery[POCET_JAZYKOV + 1] = 
{"zobrazi� tla�idlo pre prv� ve�pery <!--(a komplet�rium po nich)--> pre nedele a sl�vnosti v de� sl�venia",
 "zobrazit tla��tko pro prvn� ne�pory <!--(a komplet�� po nich)--> pro ned�le a slavnosti v den slaven�",
 "display button for first vesperas <!--(and completory after them)--> for Sundays and solemnitas for the day of celebration",
 "",
 "",
 "zobrazit tla��tko pro prvn� ve�ern� chv�ly <!--(a komplet�� po nich)--> pro ned�le a slavnosti v den slaven�",
 "vas�rnapok �s f��nnepek eset�n az I. Esti dics�ret gombja az �nnepl�s napj�n jelenjen meg"
};
const char *html_text_option2_prve_vespery_explain[POCET_JAZYKOV + 1] = 
{"Ke�e z�kladn�m krit�riom pre zobrazovanie modlitieb dan�ho d�a je d�tum, form�lne prv� ve�pery nedie� a sl�vnost� (a tie� komplet�rium po nich) nespadaj� pod dan� d�tum, ale pre predo�l� de�, kde sa zobrazuj� ako be�n� ve�pery. Pre sobotn� sl�venie sa nebude tla�idlo pre ve�pery (a komplet�rium) zobrazova�.", 
 "Jeliko� z�kladn�m krit�riem pro zobrazov�n� ponuky modliteb dan�ho dne je datum, prvn� ne�pory ned�l a slavnost� (a tak� komplet�� po nich) nespadaj� pod dan� datum, n�br� pro p�edch�zej�c� den, kde jsou zobrazeny jako b�n� ne�pory. Pro sobotn� slaven� se tla��tko pro ne�pory (a komplet��) nebude zobrazovat.", 
 "xxx", 
 "",
 "", 
 "Jeliko� z�kladn�m krit�riem pro zobrazov�n� ponuky modliteb dan�ho dne je datum, prvn� ve�ern� chv�ly ned�l a slavnost� (a tak� komplet�� po nich) nespadaj� pod dan� datum, n�br� pro p�edch�zej�c� den, kde jsou zobrazeny jako b�n� prvn� ve�ern� chv�ly. Pro sobotn� slaven� se tla��tko pro ve�ern� chv�ly (a komplet��) nebude zobrazovat.", 
 "Mivel az ima�r�k megjelen�t�se els�sorban a d�tumt�l f�gg, a vas�rnapok �s f��nnepek I. Esti dics�rete (valamint az ut�nuk k�vetkez� Befejez� ima�ra) form�lisan nem tartozik az adott d�tumhoz, hanem az el�z� naphoz. Itt mint k�znapi Esti dics�ret jelenik meg. Az I. Esti dics�ret (�s Befejez� ima�ra) gombja nem fog megjelenni szombati v�gz�shez."
};

const char *html_text_option2_iso_datum[POCET_JAZYKOV + 1] = 
{"zobrazi� d�tum v ISO 8601 form�te (RRRR-MM-DD)", 
 "zobrazit datum v ISO 8601 form�tu (RRRR-MM-DD)", 
 "display date in ISO 8601 format (RRRR-MM-DD)", 
 "",
 "",
 "zobrazit datum v ISO 8601 form�tu (RRRR-MM-DD)", 
 "a d�tum ISO 8601 form�tumban (����-HH-NN) jelenjen meg"
};
const char *html_text_option2_iso_datum_explain[POCET_JAZYKOV + 1] = 
{"", 
 "", 
 "", 
 "",
 "", 
 "", 
 ""
};

const char *html_text_option2_font_family[POCET_JAZYKOV + 1] = 
{"pou�i� bezp�tkov� p�smo? (in�� p�tkov�)", 
 "pou��t bezpatkov� p�smo? (jinak patkov�)", 
 "use Sans Serif font? (otherwise, Serif is used)", 
 "",
 "",
 "pou��t bezpatkov� p�smo? (jinak patkov�)", 
 "talp n�lk�li bet�k haszn�lata"
};
const char *html_text_option2_font_family_explain[POCET_JAZYKOV + 1] = 
{"Zvo�te si p�tkov� p�smo (Serif) resp. bezp�tkov� p�smo (Sans Serif) pod�a toho, �o v�m viac vyhovuje pre komfort modlitby. Pou�ije sa predvolen� p�smo prehliada�a.", 
 "", 
 "", 
 "",
 "", 
 "", 
 "V�lasszon talpas (Serif) vagy talp n�lk�li (Sans Serif) bet�t, k�nyelem szerint. A b�ng�sz� ablakban mutatott bet�t�pus az alap�rtelmezett."
};

const char *html_text_navig_buttons[POCET_JAZYKOV + 1] = 
{"navig�ciu", 
 "navigaci", 
 "navigation buttons", 
 "",
 "",
 "navigaci", 
 "navig�ci�"
};
const char *html_text_option2_navigation[POCET_JAZYKOV + 1] = 
{"zobrazi� navig�ciu v textoch modlitieb",
 "zobrazit navigaci v textech modliteb", 
 "display navigation buttons in prayer", 
 "",
 "",
 "zobrazit navigaci v textech modliteb", 
 "a navig�ci� mutat�sa az imasz�vegben", 
};
const char *html_text_option2_navigation_explain[POCET_JAZYKOV + 1] = 
{"�i sa maj� zobrazova� hypertextov� odkazy na ostatn� modlitby dan�ho d�a, pr�p. predo�l�/nasledovn� de� priamo v texte modlitby.", 
 "Zda zobrazit hypertextov� odkazy na ostatn� modlitby dan�ho dne, resp. p�ede�l�/n�sleduj�c� den p��mo v textu modlitby.", 
 "Whether hypertext links (as buttons) to other prayers of the selected celebration should be displayed.", 
 "",
 "", 
 "Zda zobrazit hypertextov� odkazy na ostatn� modlitby dan�ho dne, resp. p�ede�l�/n�sleduj�c� den p��mo v textu modlitby.", 
 "Legyen-e hiperhivatkoz�s a nap t�bbi ima�r�j�ra is,  illetve mutassa-e az el�z� �s k�vetkez� nap ima�r�it is k�zvetlen�l a sz�vegben.", 
};

const char *html_text_option2_moznosti[POCET_JAZYKOV + 1] = 
{"zobrazi� rozli�n� mo�nosti priamo v textoch modlitieb",
 "zobrazit rozli�n� volby v textech modliteb", 
 "display various options in prayers", 
 "",
 "",
 "zobrazit rozli�n� volby v textech modliteb", 
 "az im�k sz�veg�ben megmutatni a k�l�nb�z� lehet�s�geket", 
};
const char *html_text_option2_moznosti_explain[POCET_JAZYKOV + 1] = 
{"�i sa maj� zobrazova� hypertextov� odkazy na in� zobrazenie tej istej modlitby priamo v texte modlitby (napr. pre modlitbu cez de� na verziu s doplnkovou psalm�diou).", // Vtedy nie je potrebn�, aby boli zobrazen� prep�na�e na titulnej str�nke.
 "Zda zobrazit hypertextov� odkazy na jin� zobrazen� modlitby dan�ho dne p��mo v textu modlitby (nap�. pro modlitbu uprostr�d dne verzi se �almy z dopl�uj�c�ho cyklu).", 
 "Whether various options should be displayed directly in the prayer's texts.", 
 "",
 "", 
 "Zda zobrazit hypertextov� odkazy na jin� zobrazen� modlitby dan�ho dne p��mo v textu modlitby (nap�. pro modlitbu uprostr�d dne verzi se �almy z dopl�uj�c�ho cyklu).", 
 "Hogy mutatkozzanak-e a hipertextus utal�sok a jelenlegi ima m�sabb �br�zol�s�ra k�zvetlen�l az ima sz�veg�ben (pld. a napk�zi im�hoz a kieg�sz�t� zsolt�rral val� verzi�ra is.", 
};

const char *html_text_option2_textwrap[POCET_JAZYKOV + 1] = 
{"zalamova� dlh� riadky ako v tla�enom vydan� (poetick� �asti)",
 "zalomit dlouh� ��dky poetick�ch text� jako v ti�t�n�m vyd�n�", 
 "xxx", 
 "",
 "",
 "zalomit dlouh� ��dky poetick�ch text� jako v ti�t�n�m vyd�n�", 
 "hossz� sorok t�rdel�se, mint a nyomtatott kiad�sban (versr�szek)", 
};
const char *html_text_option2_textwrap_explain[POCET_JAZYKOV + 1] = 
{"�i sa maj� v texte modlitby dlh� riadky �almov, chv�lospevov a in�ch poetick�ch �ast� zalamova� ako v tla�enom vydan�.", 
 "Zda zalomit dlouh� ��dky poetick�ch text� jako v ti�t�n�m vyd�n� (norm�ln�: nezalamovat).", 
 "xxx", 
 "",
 "", 
 "Zda zalomit dlouh� ��dky poetick�ch text� jako v ti�t�n�m vyd�n� (norm�ln�: nezalamovat).", 
 "Legyenek-e t�rdelve az ima�r�k sz�veg�ben  a zsolt�rok, kantikumok �s m�s versr�szek hossz� sorai, mint a nyomtatott kiad�sban.", 
};

const char *html_text_option2_buttons_usporne[POCET_JAZYKOV + 1] = 
{"tla�idl� pre modlitby zobrazi� �sporne",
 "tla��tka pro modlitby zobrazit �sporn�", 
 "xxx", 
 "",
 "",
 "tla��tka pro modlitby zobrazit �sporn�", 
 "az ima�r�k gombjainak gazdas�gos elhelyez�se", 
};
const char *html_text_option2_buttons_usporne_explain[POCET_JAZYKOV + 1] = 
{"�i sa maj� tla�idl� pre modlitby zobrazi� �sporne, v tabu�ke (men�ia ��rka) kv�li mobiln�m zariadeniam.", 
 "Zda se maj� tla��tka pro modlitby zobrazit �sporn�, v tabulce (men�� ���ka) pro mobiln� za��zen�.", 
 "xxx", 
 "",
 "", 
 "Zda se maj� tla��tka pro modlitby zobrazit �sporn�, v tabulce (men�� ���ka) pro mobiln� za��zen�.", 
 "Legyenek-e az ima�r�k gombjai gazdas�gosan elhelyezve, t�bl�zatban (kisebb sz�less�g) a mobli k�sz�l�kek c�lj�b�l.", 
};

const char *html_text_option2_nocny_rezim[POCET_JAZYKOV + 1] = 
{"no�n� re�im",
 "no�n� re�im",
 "xxx", 
 "",
 "",
 "no�n� re�im",
 "�jszakai m�d", 
};
const char *html_text_option2_nocny_rezim_explain[POCET_JAZYKOV + 1] = 
{"Zobraz� svetl� text na tmavom pozad�."
 "Zobraz� sv�tl� text na tmav�m pozad�.",
 "xxx", 
 "",
 "", 
 "Zobraz� sv�tl� text na tmav�m pozad�.",
 "Megmutatja vil�gos sz�veg s�t�t h�tt�r.",
};

const char *html_text_option2_alternatives[POCET_JAZYKOV + 1] = 
{"alternat�vy",
 "alternativy",
 "alternatives", 
 "",
 "",
 "alternativy",
 "alternat�v�k", 
};
const char *html_text_option2_alternatives_explain[POCET_JAZYKOV + 1] = 
{"Zobraz� v texte modlitieb iba jednu mo�nos�, napr. hymnus pre komplet�rium (d� sa prep�na�).",
 "Zobraz� v textu modliteb jenom jedno mo�nost (je mo�n� p�ep�nat).",
 "xxx", 
 "",
 "", 
 "Zobraz� v textu modliteb jenom jedno mo�nost (je mo�n� p�ep�nat).",
 "Megmutatja ...",
};

const char *html_text_option5_KomplHymnusA[POCET_JAZYKOV + 1] = 
{"hymnus A: Na sklonku d�a �a �primne",
 "hymnus A: Na sklonku dne t� up��mn�",
 "hymnus A", 
 "",
 "",
 "hymnus A: Na sklonku dne t� up��mn�",
 "himnusz A: Imm�r a nap le�ldozott", 
};

const char *html_text_option5_KomplHymnusB[POCET_JAZYKOV + 1] = 
{"hymnus B: Kriste, ty svetlo a n� de�",
 "hymnus B: Ty, Kriste, sv�tlo, jasn� dni",
 "hymnus B", 
 "",
 "",
 "hymnus B: Ty, Kriste, sv�tlo, jasn� dni",
 "himnusz B: Krisztus, t�nd�kl� nappalunk", 
};

const char *html_text_option5_PCHymnusI[POCET_JAZYKOV + 1] = 
{"hymnus I. [Ak je posv�tn� ��tanie v noci alebo v�asr�no]",
 "hymnus I. [V noci a �asn� r�no]",
 "hymnus I.",
 "",
 "",
 "hymnus I. [V noci a �asn� r�no]",
 "himnusz I. [Amikor az ima�r�t �jszaka vagy kora hajnalban mondj�k]",
};

const char *html_text_option5_PCHymnusII[POCET_JAZYKOV + 1] = 
{"hymnus II. [Ak je posv�tn� ��tanie cez de�]",
 "hymnus II. [B�hem dne]",
 "hymnus II.",
 "",
 "",
 "hymnus II. [B�hem dne]",
 "himnusz II. [Amikor az ima�r�t a nap nem reggeli �r�j�ban v�gzik]",
};

const char *html_text_option5_MCDPredHymnus1[POCET_JAZYKOV + 1] = 
{"hymnus Pr��, Duchu Sv�t�",
 "hymnus K n�m, Duchu Svat�, nyn� sp�j",
 "hymnus 1",
 "",
 "",
 "hymnus K n�m, Duchu Svat�, nyn� sp�j",
 "himnusz Most j�jj, Szentl�lek, sz�llj k�z�nk",
};

const char *html_text_option5_MCDPredHymnus2[POCET_JAZYKOV + 1] = 
{"hymnus Deviata je u� hodina",
 "hymnus Je t�et� denn� hodina",
 "hymnus 2",
 "",
 "",
 "hymnus Je t�et� denn� hodina",
 "himnusz Id�k rendj�t megtartva most",
};

const char *html_text_option5_MCDNaHymnus1[POCET_JAZYKOV + 1] = 
{"hymnus Mocn� Vl�dca, vern� Bo�e",
 "hymnus Jsi mocn� Vl�dce, v�rn� B�h",
 "hymnus 1",
 "",
 "",
 "hymnus Jsi mocn� Vl�dce, v�rn� B�h",
 "himnusz Urunk, fels�ges Isten�nk",
};

const char *html_text_option5_MCDNaHymnus2[POCET_JAZYKOV + 1] = 
{"hymnus Na nebi slnko vrchol�",
 "hymnus Te� P�nu chv�ly zp�vejme",
 "hymnus 2",
 "",
 "",
 "hymnus Te� P�nu chv�ly zp�vejme",
 "himnusz Dics�rj�k dallal az Urat",
};

const char *html_text_option5_MCDPoHymnus1[POCET_JAZYKOV + 1] = 
{"hymnus Cel� svet v pohyb uv�dza�",
 "hymnus Sv�t cel� v pohyb uv�d�",
 "hymnus 1",
 "",
 "",
 "hymnus Sv�t cel� v pohyb uv�d�",
 "himnusz Vil�gfenntart� Isten�nk",
};

const char *html_text_option5_MCDPoHymnus2[POCET_JAZYKOV + 1] = 
{"hymnus Z Bo�ej milosti tret� raz",
 "hymnus Hodina t�et� z poledne",
 "hymnus 2",
 "",
 "",
 "hymnus Hodina t�et� z poledne",
 "himnusz H�romszor h�rom �ra m�r",
};

const char *html_text_option5_DPsalmZ122_129[POCET_JAZYKOV + 1] = 
{"namiesto �almu 122 bra� �alm 129",
 "m�sto �almu 122 vz�t �alm 129",
 "",
 "",
 "",
 "m�sto �almu 122 vz�t �alm 129",
 "a 121. helyett vehet� a 128. zsolt�r",
};

const char *html_text_option5_DPsalmZ127_131[POCET_JAZYKOV + 1] = 
{"namiesto �almu 127 bra� �alm 131",
 "m�sto �almu 127 vz�t �alm 131",
 "",
 "",
 "",
 "m�sto �almu 127 vz�t �alm 131",
 "a 126. helyett vehet� a 130. zsolt�r",
};

const char *html_text_option5_DPsalmZ122_NORMAL[POCET_JAZYKOV + 1] = 
{"bra� �alm 122 z doplnkovej psalm�die",
 "vz�t �alm 122 z dopl�ovac�ho cyklu",
 "",
 "",
 "",
 "vz�t �alm 122 z dopl�ovac�ho cyklu",
 "hu_take 121. zsolt�r from kieg�sz�t� zsolt�rokn�l",
};

const char *html_text_option5_DPsalmZ127_NORMAL[POCET_JAZYKOV + 1] = 
{"bra� �alm 127 z doplnkovej psalm�die",
 "vz�t �alm 127 z dopl�ovac�ho cyklu",
 "",
 "",
 "",
 "vz�t �alm 127 z dopl�ovac�ho cyklu",
 "hu_take 126. zsolt�r from kieg�sz�t� zsolt�rokn�l",
};

const char *html_text_option5_DPsalmZ122_129_explain[POCET_JAZYKOV + 1] = 
{"V doplnkovej psalm�dii namiesto �almu 122 mo�no bra� �alm 129.",
 "Pro dopl�ovac� cyklus �alm� m�sto �almu 122 (121) vz�t �alm 129 (128).",
 "",
 "",
 "",
 "Pro dopl�ovac� cyklus �alm� m�sto �almu 122 (121) vz�t �alm 129 (128).",
 "A kieg�sz�t� zsolt�rokn�l a 121. helyett vehet� a 128. zsolt�r.",
};

const char *html_text_option5_DPsalmZ127_131_explain[POCET_JAZYKOV + 1] = 
{"V doplnkovej psalm�dii namiesto �almu 127 mo�no bra� �alm 131.",
 "Pro dopl�ovac� cyklus �alm� m�sto �almu 127 (126) vz�t �alm 131 (130).",
 "",
 "",
 "",
 "Pro dopl�ovac� cyklus �alm� m�sto �almu 127 (126) vz�t �alm 131 (130).",
 "A kieg�sz�t� zsolt�rokn�l a 126. helyett vehet� a 130. zsolt�r.",
};


// 2011-05-06
const char *html_text_font_name[POCET_JAZYKOV + 1] = 
{"alebo pou�i p�smo", 
 "nebo pou�ij p�smo", 
 "or use font", 
 "vel font",
 "",
 "nebo pou�ij p�smo", 
 "bet�t�pus v�laszt�sa"
};
const char *html_text_font_name_explain[POCET_JAZYKOV + 1] = 
{"Ak nie je zvolen� konkr�tne p�smo, pou�ije sa predvolen� p�smo prehliada�a (p�tkov� alebo bezp�tkov� pod�a predch�dzaj�cej vo�by za�krt�vacieho pol��ka).", 
 "", 
 "", 
 "",
 "", 
 "", 
 "Ha nem v�lasztunk bet�t�pust, akkor a b�ng�sz� ablakban l�that� az alap�rtelmezett (talpas vagy talpatlan az el�z� kiv�laszt�s szerint)."
};

// 2011-05-13
const char *html_text_font_size[POCET_JAZYKOV + 1] = 
{"ve�kos� p�sma", 
 "velikost p�sma", 
 "font size", 
 "font size",
 "",
 "velikost p�sma", 
 "bet�m�ret"
};
const char *html_text_font_size_explain[POCET_JAZYKOV + 1] = 
{"Ve�kos� p�sma", 
 "", 
 "", 
 "",
 "", 
 "", 
 "bet�m�ret"
};

// 2010-10-11: HTML option selected
const char *html_option_selected = " selected";

// 2011-04-11: HTML option checked (pre checkboxy)
const char *html_option_checked = " checked";

const char *html_text_kalendar[POCET_JAZYKOV + 1] = 
{"kalend�r", 
 "kalend��", 
 "calendar", 
 "calendario",
 "",
 "kalend��",
 "a napt�rat"
};
// 2010-09-14
const char *html_text_kalendar_miestny[POCET_JAZYKOV + 1] = 
{"kalend�r Liturgie hod�n: ",
 "kalend�� Liturgie hodin: ",
 "local or general calendar: ", 
 "calendario per Liturgia horarum: ",
 "",
 "kalend�� Liturgie hodin: ",
 "Az ima�r�k liturgi�ja (AK SA D�, DA� V�BER SEM) napt�r�t haszn�lj�k"
};
const char *html_text_kalendar_miestny_explain[POCET_JAZYKOV + 1] = 
{"Je mo�n� zvoli� miestny kalend�r (propri�) reho�nej rodiny, r�du, kongreg�cie, in�tit�tu...", 
 "Je mo�n� vz�t m�stn� kalend�� �eholn� rodiny, ��du, kongregace, institutu...", 
 "", 
 "",
 "", 
 "", // not applicable for CZOP
 "Lehets�ges a helyi napt�rt v�lasztani, szerzetesrend�t, kongreg�ci��t, int�zm�ny�t..."
};

const char *html_text_detaily_explain[POCET_JAZYKOV + 1] = 
{"Ostatn� nastavenia sa pou�ij� z predch�dzaj�cej (hlavnej) str�nky. <p>Pokia� s� niektor� parametre pre vybran� modlitbu nepou�ite�n�, neber� sa do �vahy (m��u by� teda nastaven� �ubovo�ne).", 
 "Kdy� jsou n�kter� v��e uveden� volby nepou�iteln� pro n�jakou modlitbu, neberou se v �vahu (mohou b�t nastaveny dle libov�le).", 
 "If any of described options are not applicable for a chosen prayer, they can be set anyhow.", 
 "",
 "", 
 "Kdy� jsou n�kter� v��e uveden� volby nepou�iteln� pro n�jakou modlitbu, neberou se v �vahu (mohou b�t nastaveny dle libov�le).",
 "A t�bbi be�ll�t�si lehet�s�g a f�oldalon tal�lhat�. <p>Amennyiben valamelyik kiv�lasztott param�ter nem m�k�dik, figyelmen k�v�l kell hagyni (vagyis tetsz�legesen �ll�that�k)."
};

// 2010-06-04: text pre popis do invitat�ria
const char *html_text_inv_slavaotcu[POCET_JAZYKOV + 1] = 
{"<p>&nbsp;&nbsp;&nbsp; <"HTML_SPAN_RED_SMALL">Nasleduje</span> <span class=\"small\">Sl�va Otcu</span> <"HTML_SPAN_RED_SMALL">a opakuje sa antif�na.</span>", 
 "<p>&nbsp;&nbsp;&nbsp; <"HTML_SPAN_RED_SMALL">N�sleduje</span> <span class=\"small\">Sl�va Otci</span> <"HTML_SPAN_RED_SMALL">a opakuje se antifona.</span>", 
 "<p>&nbsp;&nbsp;&nbsp; <"HTML_SPAN_RED_SMALL">Follows</span> <span class=\"small\">Glory...</span> <"HTML_SPAN_RED_SMALL">a opakuje sa antif�na.</span>", 
 "<p>&nbsp;&nbsp;&nbsp; <"HTML_SPAN_RED_SMALL">Nasleduje</span> <span class=\"small\">Gloria Patri</span> <"HTML_SPAN_RED_SMALL">a opakuje sa antif�na.</span>", 
 "<p>&nbsp;&nbsp;&nbsp; <"HTML_SPAN_RED_SMALL">Nasleduje</span> <span class=\"small\">Sl�va Otcu</span> <"HTML_SPAN_RED_SMALL">a opakuje sa antif�na.</span>", 
 "<p>&nbsp;&nbsp;&nbsp; <"HTML_SPAN_RED_SMALL">N�sleduje</span> <span class=\"small\">Sl�va Otci</span> <"HTML_SPAN_RED_SMALL">a opakuje se antifona.</span>", 
 "<p>&nbsp;&nbsp;&nbsp; <"HTML_SPAN_RED_SMALL">K�vetkezik a</span> <span class=\"small\">Dics�s�g az Aty�nak</span> <"HTML_SPAN_RED_SMALL">�s megism�telj�k az antif�n�t.</span>", 
};

// 2013-02-22: page navigation (top, bottom)
const char *html_text_top[POCET_JAZYKOV + 1] = {"&uarr; navrch", "&uarr; nahoru", "&uarr; top", "", "", "&uarr; nahoru", "&uarr; fel"}; // HU: to up -> felfel� | up -> fel | Andy: fent | top -> eleje | to top -> elej�re
const char *html_text_bottom[POCET_JAZYKOV + 1] = {"&darr; naspodok", "&darr; dol�", "&darr; bottom", "", "", "&darr; dol�", "&darr; le"}; // HU: to down -> lefel� | down -> le | Andy: lent | bottom -> v�ge | to bottom -> v�g�re

// 2009-08-04: pre batch m�d
const char *html_text_batch_Zoznam1[POCET_JAZYKOV + 1] = {"Zoznam modlitieb", "Seznam modliteb", "List of prayers", "", "", "Seznam modliteb", "Az im�k jegyz�ke"};
const char *html_text_batch_Zoznam1m[POCET_JAZYKOV + 1] = {"Zoznam modlitieb po mesiacoch", "Seznam modliteb dle m�s�c�", "List of prayers by months", "", "", "Seznam modliteb dle m�s�c�", "Az im�k jegyz�ke h�napok szerint"};
const char *html_text_batch_obdobie1m[POCET_JAZYKOV + 1] = {"("/*obdobie */"od %d. %s %d do %d. %s %d)", "(pro obdob� od %d. %s %d do %d. %s %d)", "(%d. %s %d -- %d. %s %d)", "(%d. %s %d -- %d. %s %d)", "(%d. %s %d -- %d. %s %d)", "(pro obdob� od %d. %s %d do %d. %s %d)", "(%d. %s %d -- %d. %s %d)"};
const char *html_text_batch_Zoznam2[POCET_JAZYKOV + 1] = {/* Zoznam modlitieb pre */"%s %d", "%s %d", "%s %d", "%s %d", "%s %d", "%s %d", "%s %d"};
const char *html_text_batch_Back[POCET_JAZYKOV + 1] = {"^ hore", "^ nahoru", "^ up", "", "", "^ nahoru", "^ felfel�"};
const char *html_text_batch_Prev[POCET_JAZYKOV + 1] = {"&lt;&lt;", "&lt;&lt;", "&lt;&lt;", "&lt;&lt;", "&lt;&lt;", "&lt;&lt;", "&lt;&lt;"};
const char *html_text_batch_Next[POCET_JAZYKOV + 1] = {"&gt;&gt;", "&gt;&gt;", "&gt;&gt;", "&gt;&gt;", "&gt;&gt;", "&gt;&gt;", "&gt;&gt;"};

// 2009-04-08: zakon�enie modlitby trojak�, kr�tke resp. dlh�
const char *text_ZAKONCENIE_SKRZE_dlhe[POCET_JAZYKOV + 1] = 
{"Skrze n�ho P�na Je�i�a Krista, tvojho Syna, ktor� je Boh a_s_tebou �ije a_kra�uje v_jednote s_Duchom Sv�t�m po v�etky veky vekov.",
 "Skrze tv�ho Syna Je��e Krista, na�eho P�na, nebo� on s_tebou v_jednot� Ducha svat�ho �ije a_kraluje po v�echny v�ky v�k�.",
 "",
 "Per D�minum nostrum Iesum Christum, F�lium tuum, qui tecum vivit et regnat in unit�te Sp�ritus Sancti, Deus, per �mnia saecula saecul�rum.",
 "",
 "Skrze tv�ho Syna Je��e Krista, na�eho P�na, nebo� on s tebou v jednot� Ducha Svat�ho �ije a kraluje po v�echny v�ky v�k�.",
 "A mi Urunk, J�zus Krisztus, a te Fiad �ltal, aki veled �l �s uralkodik a Szentl�lekkel egys�gben, Isten mind�r�kk�n-�r�kk�.",
 };
const char *text_ZAKONCENIE_SKRZE_kratke[POCET_JAZYKOV + 1] = 
{"Skrze Krista, n�ho P�na.",
 "Skrze Krista, na�eho P�na.",
 "",
 "Per Christum D�minum nostrum.",
 "",
 "Skrze Krista, na�eho P�na.",
 "Krisztus, a mi Urunk �ltal.",
 };
const char *text_ZAKONCENIE_LEBO_ON_dlhe[POCET_JAZYKOV + 1] = 
{"Lebo on je Boh a_s_tebou �ije a_kra�uje v_jednote s_Duchom Sv�t�m po v�etky veky vekov.",
 "Nebo� on s_tebou v_jednot� Ducha svat�ho �ije a_kraluje po v�echny v�ky v�k�.",
 "",
 "Qui tecum vivit et regnat in unit�te Sp�ritus Sancti, Deus, per �mnia saecula saecul�rum.",
 "",
 "Nebo� on s tebou v jednot� Ducha Svat�ho �ije a kraluje po v�echny v�ky v�k�.",
 "Aki veled �l �s uralkodik a Szentl�lekkel egys�gben, Isten mind�r�kk�n-�r�kk�.",
 };
const char *text_ZAKONCENIE_LEBO_ON_kratke[POCET_JAZYKOV + 1] = 
{"Lebo on �ije a_kra�uje na veky vekov.",
 "Nebo� on s_tebou �ije a_kraluje na v�ky v�k�.",
 "",
 "Qui vivit et regnat in saecula saecul�rum.",
 "",
 "Nebo� on s tebou �ije a kraluje na v�ky v�k�.",
 "Aki �l �s uralkodik mind�r�kk�n-�r�kk�.",
 };
const char *text_ZAKONCENIE_LEBO_TY_dlhe[POCET_JAZYKOV + 1] = 
{"Lebo ty si Boh a_�ije� a_kra�uje� s Bohom Otcom v_jednote s_Duchom Sv�t�m po v�etky veky vekov.",
 "Nebo� ty �ije� a_kraluje� s_Bohem Otcem v_jednot� Ducha svat�ho po v�echny v�ky v�k�.",
 "",
 "Qui vivis et regnas cum Deo Patre in unit�te Sp�ritus Sancti, Deus, per �mnia saecula saecul�rum.",
 "",
 "Nebo� ty �ije� a kraluje� s Bohem Otcem v jednot� Ducha Svat�ho po v�echny v�ky v�k�.",
 "Aki �lsz �s uralkodol az Atyaistennel �s a Szentl�lek�kel egys�gben, Isten mind�r�kk�n-�r�kk�.",
 };
const char *text_ZAKONCENIE_LEBO_TY_kratke[POCET_JAZYKOV + 1] = 
{"Lebo ty �ije� a_kra�uje� na veky vekov.",
 "Nebo� ty �ije� a_kraluje� na v�ky v�k�.",
 "",
 "Qui vivis et regnas in saecula saecul�rum.",
 "",
 "Nebo� ty �ije� a kraluje� na v�ky v�k�.",
 "Aki �lsz �s uralkodol mind�r�kk�n-�r�kk�.",
 };
// 2010-06-07: len pre SK (POST1_MODLITBA5NE)
const char *text_ZAKONCENIE_ON_JE_dlhe = "On je Boh a_s_tebou �ije a_kra�uje v_jednote s_Duchom Sv�t�m po v�etky veky vekov.";
const char *text_ZAKONCENIE_ON_JE_kratke = "On �ije a_kra�uje na veky vekov.";
/* 2011-01-14: pridan� len pre SK 
		(04NOV_MODLITBA, 24APR2_MODLITBA, 11JUN_MODLITBA, 19OKT2_MODLITBA, VN1_MODLITBA3STR, ADV12PO_MODLITBA, ADV12STR_MODLITBA, 
		VTYZ_MODLITBA6PO, ADV12UT_MODLITBA, ADV12PI_MODLITBA, ADV13STV_MODLITBA, OZZ_MODLITBA, SCDP_MODLITBA, PMB_rMODLITBA, SCPM_MODLITBA, 
		SCSM_MODLITBA, 24APR_MODLITBA, 25APR_MODLITBA, 02AUG_MODLITBA, 05AUG_MODLITBA, 15AUG_1MODLITBA, 16JUL_MODLITBA, 30JUL2_MODLITBA, 
		24OKT_MODLITBA, VIAN2_MODLITBA11, VN1_MODLITBA4NE, SPMVSr_MODLITBA2, 24JUN_1MODLITBA, 
		VN1_MODLITBA6STV [nepou��va sa], VN1_rPROSBY6PI_pred_nan [nepou��va sa], VN1_vPROSBY6PI_pred_nan [nepou��va sa])
 */
const char *text_ZAKONCENIE_KTORY_JE_dlhe = "ktor� je Boh a_s_tebou �ije a_kra�uje v_jednote s_Duchom Sv�t�m po v�etky veky vekov.";
const char *text_ZAKONCENIE_KTORY_JE_kratke = "ktor� �ije a_kra�uje na veky vekov.";

const char *text_ZAKONCENIE_O_TO_TA_PROSIME[POCET_JAZYKOV + 1] = 
{"O_to �a pros�me",
 "Pros�me o_to",
 "",
 "",
 "",
 "Pros�me o_to",
 "",
 };


// 2009-05-15: pre dominik�nov
const char *text_PRO_OP[POCET_JAZYKOV + 1] = 
{"Pre dominik�nov (CZ_OP): ",
"Pro dominik�ny (OP CZ): ",
 "",
 "",
 "",
 "Pro OP CZ: ",
 "",
 };

// nasleduj� n�zvy liturgick�ch dn� -- follow the names of special liturgical celebrations

// --------------- 00 pohybliv� sl�venia ---------------

const char *text_DRUHA_NEDELA_PO_NAR_PANA[POCET_JAZYKOV + 1] = 
{"2. nede�a po Naroden� P�na",
 "2. ned�le po Narozen� P�n�",
 "",
 "",
 "",
 "2. ned�le po Narozen� P�n�",
 "Kar�csony Ut�ni 2. Vas�rnap",
 };

// --------------- 01 janu�r ---------------

const char *text_JAN_01[POCET_JAZYKOV + 1] = 
{"Panny M�rie Bohorodi�ky",
 "Matky Bo��, Panny Marie",
 "",
 "Sanctae Dei Genetricis Mariae",
 "",
 "Matky Bo��, Panny Marie",
 "Sz�z M�ria, Isten Anyja (�j�v)",
 };
const char *text_JAN_01_SJ[POCET_JAZYKOV + 1] = 
{"Panny M�rie Bohorodi�ky a Mena Je�i� "HTML_LINE_BREAK"(Titul�rny sviatok Spolo�nosti Je�i�ovej)", // titul�rny sviatok Spolo�nosti Je�i�ovej
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_02[POCET_JAZYKOV + 1] = 
{"Sv. Bazila Ve�k�ho a Gregora Nazianzsk�ho,"HTML_LINE_BREAK"biskupov a u�ite�ov Cirkvi",
 "Sv. Basila Velik�ho a �eho�e Nazi�nsk�ho,"HTML_LINE_BREAK"biskup� a u�itel� c�rkve",
 "",
 "Ss. Basilii Magni et Gregorii Nazianzeni, ep. et Eccl. doct.",
 "",
 "Sv. Basila Velik�ho a �eho�e Nazi�nsk�ho,"HTML_LINE_BREAK"biskup� a u�itel� C�rkve",
 "Nagy Szent Vazul �s Nazianzi Szent Gergely p�sp�k�k �s egyh�ztan�t�k",
 };
const char *text_JAN_03[POCET_JAZYKOV + 1] = 
{"Najsv�tej�ieho mena Je�i�",
 "Nejsv�t�j��ho jm�na Je��",
 "",
 "",
 "",
 "Nejsv�t�j��ho Jm�na Je��",
 "J�zus szent neve",
 };
const char *text_JAN_04_OFM[POCET_JAZYKOV + 1] = 
{"Bl. Angely z Foligna, reho�n��ky, �lenky 3. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_05_CSSR[POCET_JAZYKOV + 1] = 
{"Sv. J�na Nepomuck�ho Neumanna, biskupa",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_05_OFM[POCET_JAZYKOV + 1] = 
{"Bl. Didaka Jozefa z C�dizu, k�aza, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_06[POCET_JAZYKOV + 1] = // 6. janu�ra | alebo nede�u medzi 2. a 8. janu�rom
{"Zjavenie P�na",
 "Zjeven� P�n�",
 "",
 "In Epiphania Domini",
 "",
 "Zjeven� P�n�",
 "Urunk megjelen�se (V�zkereszt)",
 };
const char *text_JAN_07[POCET_JAZYKOV + 1] = 
{"Sv. Rajmunda z Pe�afortu, k�aza",
 "Sv. Rajmunda z Penafortu, kn�ze",
 "",
 "S. Raimundi de Penyafort, presb.",
 "",
 "Sv. Rajmunda z Pe�afortu, kn�ze",
 "Penyaforti Szent Rajmund �ldoz�pap",
 };
const char *text_JAN_10_1_OP[POCET_JAZYKOV + 1] = 
{"Bl. Gundislava z Amarante, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_10_2_OP[POCET_JAZYKOV + 1] = 
{"Bl. Anny Monteagudovej, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_11_OP[POCET_JAZYKOV + 1] = 
{"Bl. Bernarda Scammaccu, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_KRST[POCET_JAZYKOV + 1] = // v nede�u po 6. janu�ri | (v nede�u po Zjaven� P�na) alebo: ak v�ak t�to nede�a (zrejme Zjavenia P�na) padne na de� 7. alebo 8. janu�ra, of�cium sa sl�vi v nasleduj�ci de�
{"Krst Krista P�na",
 "K�tu P�n�",
 "",
 "In Baptismate Domini",
 "",
 "K�tu P�n�",
 "Urunk megkeresztelked�se",
 };
const char *text_JAN_12_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Bernarda z Corleone, reho�n�ka, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_13[POCET_JAZYKOV + 1] = 
{"Sv. Hil�ra, biskupa a u�ite�a Cirkvi",
 "Sv. Hilaria, biskupa a u�itele c�rkve",
 "",
 "S. Hilarii, ep. et Eccl. doct.",
 "",
 "Sv. Hilaria, biskupa a u�itele C�rkve",
 "Szent Hil�riusz (Vidor) p�sp�k �s egyh�ztan�t�",
 };
const char *text_JAN_14_CSSR[POCET_JAZYKOV + 1] = 
{"Bl. Petra Dondersa, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_14_OFM[POCET_JAZYKOV + 1] = 
{"Bl. Odorika z Pordenone, k�aza, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_14_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Gotfr�da, �eholn�ka z�premonstr�tsk�ho ��du",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_15_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Remete Szent P�l szerzetes",
 };
const char *text_JAN_15_OP[POCET_JAZYKOV + 1] = 
{"Sv. Franti�ka Fern�ndeza de Capillas, k�aza, "HTML_LINE_BREAK"sv. Petra Sansa, biskupa, a spolo�n�kov, mu�en�kov",
 "",
 "",
 "",
 "",
 "Sv. Franti�ka Fern�ndeze de Capillas, kn�ze, "HTML_LINE_BREAK"Petra Sanse, biskupa, a druh�, ��nsk�ch mu�edn�k�",
 "",
 };
const char *text_JAN_15_SVD[POCET_JAZYKOV + 1] = 
{"Sv. Arnolda Janssena, k�aza a�zakladate�a troch misijn�ch reho�n�ch spolo�nost�",
 "",
 "",
 "la_",
 "",
 "",
 "",
 };
const char *text_JAN_15_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Alojza Variaru, k�aza",
 "",
 "",
 "la_",
 "",
 "",
 "",
 };
const char *text_JAN_16_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Berarda, k�aza, a spolo�n�kov, prv�ch franti�k�nskych mu�en�kov",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_17[POCET_JAZYKOV + 1] = 
{"Sv. Antona, op�ta",
 "Sv. Anton�na, opata",
 "",
 "S. Antonii, abbatis",
 "",
 "Sv. Anton�na, opata",
 "Szent Antal ap�t",
 };
const char *text_JAN_18_CZ[POCET_JAZYKOV + 1] = 
{"",
 "Panny Marie, Matky jednoty k�es�an�",
 "",
 "",
 "",
 "Panny Marie, Matky jednoty k�es�an�",
 "",
 };
const char *text_JAN_18[POCET_JAZYKOV + 1] = 
{"Sv. Margity Uhorskej, panny",
 "",
 "",
 "la_",
 "",
 "Sv. Mark�ty Uhersk�, panny, mni�ky", // CZOP 19. janu�ra kv�li text_JAN_18_CZ
 "�rp�dh�zi Szent Margit sz�z",
 };
const char *text_JAN_19_OP[POCET_JAZYKOV + 1] = 
{"Bl. Andreja z Peschiera, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_19_SJ[POCET_JAZYKOV + 1] = 
{"Bl. Jakuba Sal&egrave;sa a Viliama Saultemouchea, Ign�ca de Azevedo a spolo�n�kov, "HTML_LINE_BREAK"Jakuba Bonnauda a spolo�n�kov, mu�en�kov",
 "",
 "",
 "",
 "",
 "_",
 "",
 };
const char *text_JAN_20_1[POCET_JAZYKOV + 1] = 
{"Sv. Fabi�na, p�pe�a a mu�en�ka",
 "Sv. Fabi�na, pape�e a mu�edn�ka",
 "",
 "S. Fabiani, papae et mart.",
 "",
 "Sv. Fabi�na, pape�e a mu�edn�ka",
 "Szent F�bi�n p�pa �v v�rtan�",
 };
const char *text_JAN_20_2[POCET_JAZYKOV + 1] = 
{"Sv. �ebasti�na, mu�en�ka",
 "Sv. �ebesti�na, mu�edn�ka",
 "",
 "S. Sebastiani, mart.",
 "",
 "Sv. �ebesti�na, mu�edn�ka",
 "Szent Sebesty�n v�rtan�",
 };
const char *text_JAN_20_OFM[POCET_JAZYKOV + 1] = 
{"Bl. J�na Krstite�a Triquerie, k�aza a mu�en�ka, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_20_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Esztergomi boldog �zs�b �ldoz�pap",
 };
const char *text_JAN_21[POCET_JAZYKOV + 1] = 
{"Sv. Agnesy, panny a mu�enice",
 "Sv. Ane�ky, panny a mu�ednice",
 "",
 "S. Agnetis, virg. et mart.",
 "",
 "Sv. Ane�ky, panny a mu�ednice",
 "Szent �gnes sz�z �s v�rtan�",
 };
const char *text_JAN_22[POCET_JAZYKOV + 1] = 
{"Sv. Vincenta, diakona a mu�en�ka",
 "Sv. Vincence, j�hna a mu�edn�ka",
 "",
 "S. Vincentii, diaconi et mart.",
 "",
 "Sv. Vincence, j�hna a mu�edn�ka",
 "Szent Vince diak�nus �s v�rtan�",
 };
const char *text_JAN_22_OP[POCET_JAZYKOV + 1] = 
{"Bl. Antona della Chiesa, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_22_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Boldog Batthy�ny-Stratmann L�szl� csal�dapa",
 };
const char *text_JAN_22_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Laury Vicu�ovej, panny a mu�enice",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_23_SK[POCET_JAZYKOV + 1] = 
{"Sv. J�na Almu�n�ka, biskupa",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_23_OP[POCET_JAZYKOV + 1] = 
{"Bl. Henricha Suzu, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_24[POCET_JAZYKOV + 1] = 
{"Sv. Franti�ka Salesk�ho, biskupa a u�ite�a Cirkvi",
 "Sv. Franti�ka Salesk�ho, biskupa a u�itele c�rkve",
 "",
 "S. Francisci de Sales, ep. et Eccl. doct.",
 "",
 "Sv. Franti�ka Salesk�ho, biskupa a u�itele C�rkve",
 "Szal�zi Szent Ferenc p�sp�k �s egyh�ztan�t�",
 };
const char *text_JAN_24_SDB[POCET_JAZYKOV + 1] = 
{"Sv. Franti�ka Salesk�ho, biskupa a u�ite�a Cirkvi,"HTML_LINE_BREAK"titul�rneho patr�na salezi�nskej rodiny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_25[POCET_JAZYKOV + 1] = 
{"Obr�tenie sv�t�ho Pavla, apo�tola",
 "Obr�cen� svat�ho Pavla, apo�tola",
 "",
 "In Conversione S. Pauli, Apostoli",
 "",
 "Obr�cen� svat�ho Pavla, apo�tola",
 "Szent P�l apostol megt�r�se (P�l fordul�sa)",
 };
const char *text_JAN_26[POCET_JAZYKOV + 1] = 
{"Sv. Timoteja a T�ta, biskupov",
 "Sv. Timoteje a Tita, biskup�",
 "",
 "Ss. Timothei et Titi, ep.",
 "",
 "Sv. Timoteje a Tita, biskup�",
 "Szent Tim�teus �s Szent Titusz p�sp�k�k",
 };
const char *text_JAN_27[POCET_JAZYKOV + 1] = 
{"Sv. Angely Merici, panny",
 "Sv. And�ly Mericiov�, panny",
 "",
 "S. Angelae Merici, virg.",
 "",
 "Sv. And�ly Mericiov�, panny",
 "Merici Szent Ang�la sz�z",
 };
const char *text_JAN_27_OP[POCET_JAZYKOV + 1] = 
{"Bl. Markol�na z Forl&igrave;, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_28[POCET_JAZYKOV + 1] = 
{"Sv. Tom�a Akvinsk�ho, k�aza a u�ite�a Cirkvi",
 "Sv. Tom�e Akvinsk�ho, kn�ze a u�itele c�rkve",
 "",
 "S. Thomae de Aquino, presb. et Eccl. doct.",
 "",
 "Sv. Tom�e Akvinsk�ho, kn�ze a u�itele C�rkve",
 "Aquin�i Szent Tam�s �ldoz�pap �s egyh�ztan�t�",
 };
const char *text_JAN_29_SVD[POCET_JAZYKOV + 1] = 
{"Sv. Jozefa Freinademetza, k�aza",
 "",
 "",
 "la_",
 "",
 "",
 "",
 };
const char *text_JAN_29_OP[POCET_JAZYKOV + 1] = 
{"Bl. Villany delle Botti, matky rodiny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_30_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Bronislava Markiewicza, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_30_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Hyacinty Mariscottiovej, panny, �lenky 3. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JAN_31[POCET_JAZYKOV + 1] = 
{"Sv. J�na Boska, k�aza", // Direkt�rium 2012, str. 72, m�: 'Bosca'
 "Sv. Jana Boska, kn�ze",
 "",
 "S. Ioannis Bosco, presb.",
 "",
 "Sv. Jana Boska, kn�ze",
 "Bosco Szent J�nos �ldoz�pap",
 };
const char *text_JAN_31_SDB[POCET_JAZYKOV + 1] = 
{"Sv. J�na Boska, k�aza, otca a u�ite�a ml�de�e,"HTML_LINE_BREAK"zakladate�a Spolo�nosti sv�t�ho Franti�ka Salesk�ho,"HTML_LINE_BREAK"In�tit�tu dc�r M�rie Pomocnice"HTML_LINE_BREAK"a salezi�nov spolupracovn�kov",
 "",
 "",
 "",
 "",
 "",
 "",
 };

// --------------- 02 febru�r ---------------

const char *text_FEB_01_SDB[POCET_JAZYKOV + 1] = 
{"V�etk�ch neboh�ch �lenov Spolo�nosti sv�t�ho Franti�ka Salesk�ho",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_FEB_02[POCET_JAZYKOV + 1] = 
{"Obetovanie P�na",
 "Uveden� P�n� do chr�mu",
 "",
 "In Praesentatione Domini",
 "",
 "Uveden� P�n� do chr�mu",
 "Urunk bemutat�sa (Gyertyaszentel� Boldogasszony)",
 };
const char *text_FEB_03_1[POCET_JAZYKOV + 1] = 
{"Sv. Bla�eja, biskupa a mu�en�ka",
 "Sv. Bla�eje, biskupa a mu�edn�ka",
 "",
 "S. Blasii, ep. et mart.",
 "",
 "Sv. Bla�eje, biskupa a mu�edn�ka",
 "Szent Bal�zs p�sp�k �s v�rtan�",
 };
const char *text_FEB_03_2[POCET_JAZYKOV + 1] = 
{"Sv. Osk�ra, biskupa",
 "Sv. Ansgara, biskupa",
 "",
 "S. Ansgarii, ep.",
 "",
 "Sv. Ansgara, biskupa",
 "Szent Anszg�r (Oszk�r) p�sp�k",
 };
const char *text_FEB_03_1_OP[POCET_JAZYKOV + 1] = 
{"Bl. Petra z Ruff&igrave;a, k�aza a mu�en�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_FEB_03_2_OP[POCET_JAZYKOV + 1] = 
{"Bl. Antona Pavoniho, k�aza a mu�en�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_FEB_03_3_OP[POCET_JAZYKOV + 1] = 
{"Bl. Bartolomeja Cerveriho, k�aza a mu�en�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_FEB_04_OP[POCET_JAZYKOV + 1] = 
{"Sv. Katar�ny de� Ricci, panny",
 "",
 "",
 "",
 "",
 "Sv. Kate�iny z Ricci, panny, �eholnice",
 "",
 };
const char *text_FEB_04_SJ[POCET_JAZYKOV + 1] = 
{"Sv. J�na de Brito, k�aza, bl. Rudolfa Acquavivu, k�aza a jeho spolo�n�kov; "HTML_LINE_BREAK"bl. Franti�ka Pacheca, Karola Spinolu, k�azov a spolo�n�kov, mu�en�kov; "HTML_LINE_BREAK"bl. Jakuba Berthieu, k�aza, Leva Mangina, k�aza a spolo�n�kov, mu�en�kov",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_FEB_04_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Jozefa z Leonissy, k�aza, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_FEB_04_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Bed�icha, opata z premonstr�tsk�ho ��du",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_FEB_05[POCET_JAZYKOV + 1] = 
{"Sv. Agaty, panny a mu�enice",
 "Sv. Ag�ty, panny a mu�ednice",
 "",
 "S. Agathae, virg. et mart.",
 "",
 "Sv. Ag�ty, panny a mu�ednice",
 "Szent �gota sz�z �s v�rtan�",
 };
const char *text_FEB_06[POCET_JAZYKOV + 1] = 
{"Sv. Pavla Mikiho a spolo�n�kov, mu�en�kov",
 "Sv. Pavla Mikiho a druh�, mu�edn�k�",
 "",
 "Ss. Pauli Miki et sociorum, mart.",
 "",
 "Sv. Pavla Mikiho a druh�, mu�edn�k�",
 "Miki Szent P�l �s t�rsai v�rtan�k",
 };
const char *text_FEB_06_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Pavla Mikiho, reho�n�ka, a jeho spolo�n�kov, mu�en�kov",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_FEB_06_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Petra Baptistu, k�aza, a spolo�n�kov, franti�k�nskych mu�en�kov",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_FEB_07_OP[POCET_JAZYKOV + 1] = 
{"Spomienka na zosnul�ch otcov a matky �lenov rehole",
 "",
 "",
 "",
 "",
 "V�ro�n� pam�tka zem�el�ch otc� a matek",
 "",
 };
const char *text_FEB_07_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Pia IX., p�pe�a",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_FEB_07_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Kolety z Corbie, panny, �lenky 2. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_FEB_08_1[POCET_JAZYKOV + 1] = 
{"Sv. Hieronyma Emilianiho",
 "Sv. Jeron�ma Emilianiho",
 "",
 "S. Hieronymi Emiliani",
 "",
 "Sv. Jeron�ma Emilianiho",
 "Emili�ni Szent Jeromos",
 };
const char *text_FEB_08_2[POCET_JAZYKOV + 1] = 
{"Sv. Jozef�ny Bakhity, panny",
 "Sv. Josefiny Bakhity, panny",
 "",
 "",
 "",
 "Sv. Josefiny Bakhity, panny",
 "Bakhita Szent Jozefina sz�z",
 };
const char *text_FEB_09_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Euz�bie Palominovej Yenes, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_FEB_10[POCET_JAZYKOV + 1] = 
{"Sv. �kolastiky, panny",
 "Sv. Scholastiky, panny",
 "",
 "S. Scholasticae, virg.",
 "",
 "Sv. Scholastiky, panny",
 "Szent Skolasztika sz�z",
 };
const char *text_FEB_10_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "Bl. Huga, opata z premonstr�tsk�ho ��du",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_FEB_11[POCET_JAZYKOV + 1] = 
{"Prebl. Panny M�rie Lurdskej",
 "Panny Marie Lurdsk�",
 "",
 "B. Mariae Virg. de Lourdes",
 "",
 "Panny Marie Lurdsk�",
 "A Lourdes-i Boldogs�gos Sz�z M�ria",
 };
const char *text_FEB_12_OP[POCET_JAZYKOV + 1] = 
{"Bl. Reginalda Orle�nskeho, k�aza",
 "",
 "",
 "",
 "",
 "Bl. Reginalda z Orl�ansu, kn�ze",
 "",
 };
const char *text_FEB_13_OP[POCET_JAZYKOV + 1] = 
{"Bl. Jord�na Sask�ho, k�aza",
 "",
 "",
 "",
 "",
 "Bl. Jord�na Sask�ho, kn�ze",
 "",
 };
const char *text_FEB_14[POCET_JAZYKOV + 1] = 
{"Sv. Cyrila, mn�cha, a sv. Metoda, biskupa,"HTML_LINE_BREAK"patr�nov Eur�py", // (na Slovensku sa sl�vi 5. j�la)
 "(slav� se 5. �ervna)",
 "",
 "Ss. Cyrilli, monachi, et Methodii, ep.",
 "",
 "",
 "Szent Cirill szerzetes �s Szent Met�d p�sp�k,"HTML_LINE_BREAK"Eur�pa t�rsv�d�szentjei",
 };
const char *text_FEB_15_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Klaudia La Colombi&egrave;ra, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_FEB_15_CZ[POCET_JAZYKOV + 1] = 
{"",
 "Bl. Bed�icha Bachsteina a druh�, mu�edn�k�",
 "",
 "",
 "",
 "Bl. Bed�icha Bachsteina a druh�, mu�edn�k�",
 "",
 };
const char *text_FEB_16_OP[POCET_JAZYKOV + 1] = 
{"Bl. Mikul�a Pagliu, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_FEB_17[POCET_JAZYKOV + 1] = 
{"Siedmich sv�t�ch zakladate�ov"HTML_LINE_BREAK"rehole Slu�obn�kov Panny M�rie",
 "Sv. Alexia a druh�, �eholn�k�",
 "",
 "Ss. Septem Fundatorum Ordinis Servorum B. Mariae Virg.",
 "",
 "Sv. Alexia a druh�, �eholn�k�",
 "A szervita rend h�t szent alap�t�ja",
 };
const char *text_FEB_17_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Evermoda, biskupa z premonstr�tsk�ho ��du",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_FEB_18_OP[POCET_JAZYKOV + 1] = 
{"Bl. J�na (Angelika) z Fiesole, k�aza",
 "",
 "",
 "",
 "",
 "Bl. Jana z Fiesole neboli fra Angelica, kn�ze",
 "",
 };
const char *text_FEB_19_OP[POCET_JAZYKOV + 1] = 
{"Bl. Alvara z Kordovy, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_FEB_20_OP[POCET_JAZYKOV + 1] = 
{"Bl. Kri�tofa z Mil�na, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_FEB_21[POCET_JAZYKOV + 1] = 
{"Sv. Petra Damianiho, biskupa a u�ite�a Cirkvi",
 "Sv. Petra Damianiho, biskupa a u�itele c�rkve",
 "",
 "S. Petri Damiani, ep. et Eccl. doct.",
 "",
 "Sv. Petra Damianiho, biskupa a u�itele C�rkve",
 "Dami�ni Szent P�ter p�sp�k �s egyh�ztan�t�",
 };
const char *text_FEB_22[POCET_JAZYKOV + 1] = 
{"Katedra sv. Petra, apo�tola",
 "Stolce svat�ho Petra, apo�tola",
 "",
 "Cathedrae S. Petri, Apostoli",
 "",
 "Stolce svat�ho Petra, apo�tola",
 "Szent P�ter apostol sz�kfoglal�sa",
 };
const char *text_FEB_23[POCET_JAZYKOV + 1] = 
{"Sv. Polykarpa, biskupa a mu�en�ka",
 "Sv. Polykarpa, biskupa a mu�edn�ka",
 "",
 "S. Polycarpi, ep. et mart.",
 "",
 "Sv. Polykarpa, biskupa a mu�edn�ka",
 "Szent Polik�rp p�sp�k �s v�rtan�",
 };
const char *text_FEB_24_OP[POCET_JAZYKOV + 1] = 
{"Bl. Kon�tanca z Fabriana, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_FEB_25_SDB[POCET_JAZYKOV + 1] = 
{"Sv. Alojza Versigliu, biskupa, a Kalixta Caravaria, k�aza, "HTML_LINE_BREAK"prv�ch salezi�nskych mu�en�kov",
 "",
 "",
 "",
 "",
 "",
 "",
 };

// --------------- 00 pohybliv� sl�venia ---------------

const char *text_POPOLCOVA_STREDA[POCET_JAZYKOV + 1] = 
{"Popolcov� streda",
 "Popele�n� st�eda",
 "",
 "",
 "",
 "Popele�n� st�eda",
 "Hamvaz�szerda",
 };

// --------------- 03 marec ---------------

const char *text_MAR_02_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Ane�ky �eskej, panny, �lenky 2. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAR_04[POCET_JAZYKOV + 1] = 
{"Sv. Kazim�ra",
 "Sv. Kazim�ra",
 "",
 "S. Casimiri",
 "",
 "Sv. Kazim�ra",
 "Szent K�zm�r",
 };
const char *text_MAR_04_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Boldog Meszl�nyi Zolt�n p�sp�k �s v�rtan�",
 };
const char *text_MAR_07[POCET_JAZYKOV + 1] = 
{"Sv. Perpetuy a Felicity, mu�en�c",
 "Sv. Perpetuy a Felicity, mu�ednic",
 "",
 "Ss. Perpetuae et Felicitatis, mart.",
 "",
 "Sv. Perpetuy a Felicity, mu�ednic",
 "Szent Perp�tua �s Felicit�sz v�rtan�k",
 };
const char *text_MAR_08[POCET_JAZYKOV + 1] = 
{"Sv. J�na z Boha, reho�n�ka",
 "Sv. Jana z Boha, �eholn�ka",
 "",
 "S. Ioannis a Deo, relig.",
 "",
 "Sv. Jana z Boha, �eholn�ka",
 "Istenes Szent J�nos szerzetes",
 };
const char *text_MAR_09[POCET_JAZYKOV + 1] = 
{"Sv. Franti�ky R�mskej, reho�n��ky",
 "Sv. Franti�ky ��msk�, �eholnice",
 "",
 "S. Franciscae Romanae, relig.",
 "",
 "Sv. Franti�ky ��msk�, �eholnice",
 "R�mai Szent Franciska szerzetesn�",
 };
const char *text_MAR_10_SK[POCET_JAZYKOV + 1] = 
{"V�ro�ie posviacky katedr�lneho chr�mu v Bratislave", // ToDo: 'sv. Martina z Tours', pod�a Direkt�ria 2012, str. 93
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAR_10_CZ[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Jana Ogilvie, kn�ze a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Jana Ogilvie, kn�ze a mu�edn�ka",
 "",
 };
const char *text_MAR_12_OFM[POCET_JAZYKOV + 1] = 
{"Bl. Angely Salawovej, panny, �lenky 3. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAR_15_CSSR[POCET_JAZYKOV + 1] = 
{"Sv. Klementa M�rie Hofbauera, k�aza",
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
 "Szent Patrik p�sp�k",
 };
const char *text_MAR_17_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "A Gy�ri k�nnyez� Sz�z M�ria",
 };
const char *text_MAR_18[POCET_JAZYKOV + 1] = 
{"Sv. Cyrila Jeruzalemsk�ho, biskupa a u�ite�a Cirkvi",
 "Sv. Cyrila Jeruzal�msk�ho, biskupa a u�itele c�rkve",
 "",
 "S. Cyrilli Hierosolymitani, ep. et Eccl. doct.",
 "",
 "Sv. Cyrila Jeruzal�msk�ho, biskupa a u�itele C�rkve",
 "Jeruzs�lemi Szent Cirill p�sp�k �s egyh�ztan�t�",
 };
const char *text_MAR_18_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Salvatora z Horty, k�aza, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAR_19[POCET_JAZYKOV + 1] = 
{"Sv. Jozefa, �en�cha Panny M�rie",
 "Sv. Josefa, Snoubence Panny Marie",
 "",
 "S. Ioseph, Sponsi B. Mariae V.",
 "",
 "Sv. Josefa, Snoubence Panny Marie",
 "Szent J�zsef, a Boldogs�gos Sz�z M�ria jegyese",
 };
const char *text_MAR_23[POCET_JAZYKOV + 1] = 
{"Sv. Turibia de Mongrovejo, biskupa",
 "Sv. Turibia z Mongroveja, biskupa",
 "",
 "S. Turibii de Mogrovejo, ep.",
 "",
 "Sv. Turibia z Mongroveja, biskupa",
 "Mongrovej�i Szent Turibiusz p�sp�k",
 };
const char *text_MAR_25[POCET_JAZYKOV + 1] = 
{"Zvestovanie P�na",
 "Zv�stov�n� P�n�",
 "",
 "In Annuntiatione Domini",
 "",
 "Zv�stov�n� P�n�",
 "Urunk sz�let�s�nek h�r�lad�sa (Gy�m�lcsolt� Boldogasszony)",
 };

// --------------- 04 apr�l ---------------

const char *text_APR_02[POCET_JAZYKOV + 1] = 
{"Sv. Franti�ka z Paoly, pustovn�ka",
 "Sv. Franti�ka z Pauly, poustevn�ka",
 "",
 "S. Francisci de Paola, eremitai",
 "",
 "Sv. Franti�ka z Pauly, poustevn�ka",
 "Paolai Szent Ferenc remete",
 };
const char *text_APR_04[POCET_JAZYKOV + 1] = 
{"Sv. Izidora, biskupa a u�ite�a Cirkvi",
 "Sv. Izidora, biskupa a u�itele c�rkve",
 "",
 "S. Isidori, ep. et Eccl. doct.",
 "",
 "Sv. Izidora, biskupa a u�itele C�rkve",
 "Szent Izidor p�sp�k �s egyh�ztan�t�",
 };
const char *text_APR_05[POCET_JAZYKOV + 1] = 
{"Sv. Vincenta Ferrera, k�aza",
 "Sv. Vincence Ferrersk�ho, kn�ze",
 "",
 "S. Vincentii Ferrer, presb.",
 "",
 "Sv. Vincence Ferrersk�ho, kn�ze",
 "Ferrer Szent Vince �ldoz�pap",
 };
const char *text_APR_07[POCET_JAZYKOV + 1] = 
{"Sv. J�na Krstite�a de la Salle, k�aza",
 "Sv. Jana K�titele de la Salle, kn�ze",
 "",
 "S. Ioannis Baptistae de la Salle, presb.",
 "",
 "Sv. Jana K�titele de la Salle, kn�ze",
 "De la Salle Szent J�nos �ldoz�pap",
 };
const char *text_APR_10_OP[POCET_JAZYKOV + 1] = 
{"Bl. Antona Neyrota, k�aza a mu�en�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_APR_11[POCET_JAZYKOV + 1] = 
{"Sv. Stanislava, biskupa a mu�en�ka",
 "Sv. Stanislava, biskupa a mu�edn�ka",
 "",
 "S. Stanislai, ep. et mart.",
 "",
 "Sv. Stanislava, biskupa a mu�edn�ka",
 "Szent Szaniszl� p�sp�k �s v�rtan�",
 };
const char *text_APR_13[POCET_JAZYKOV + 1] = 
{"Sv. Martina I., p�pe�a a mu�en�ka",
 "Sv. Martina I., pape�e a mu�edn�ka",
 "",
 "S. Martini I, papae et mart.",
 "",
 "Sv. Martina I., pape�e a mu�edn�ka",
 "Szent I. M�rton p�pa �s v�rtan�",
 };
const char *text_APR_13_OP[POCET_JAZYKOV + 1] = 
{"Bl. Margity z Citt&agrave; di Castello, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_APR_14_OP[POCET_JAZYKOV + 1] = 
{"Bl. Petra Gonz�leza, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_APR_16[POCET_JAZYKOV + 1] = 
{"Sv. M�rie Bernadety Soubirousovej, panny",
 "Sv. Marie Bernadetty Soubirous, panny",
 "",
 "S. Marii Bernadette Soubirous, virg.",
 "",
 "Sv. Marie Bernadetty Soubirous, panny",
 "Soubirous szent M�ria Bernadett sz�z",
 };
const char *text_APR_17_1_OP[POCET_JAZYKOV + 1] = 
{"Bl. Kl�ry Gambacortovej, reho�n��ky",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_APR_17_2_OP[POCET_JAZYKOV + 1] = 
{"Bl. M�rie Manciniovej, reho�n��ky",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_APR_19_1_OP[POCET_JAZYKOV + 1] = 
{"Bl. Isnarda z Chiampa, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_APR_19_2_OP[POCET_JAZYKOV + 1] = 
{"Bl. Sybiliny Biscossiovej, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_APR_20_OP[POCET_JAZYKOV + 1] = 
{"Sv. Agnesy z Montepulciana, panny",
 "",
 "",
 "",
 "",
 "Sv. Ane�ky z Montepulciana, panny, mni�ky",
 "",
 };
const char *text_APR_21[POCET_JAZYKOV + 1] = 
{"Sv. Anzelma, biskupa a u�ite�a Cirkvi",
 "Sv. Anselma, biskupa a u�itele c�rkve",
 "",
 "S. Anselmi, ep. et Eccl. doct.",
 "",
 "Sv. Anselma, biskupa a u�itele C�rkve",
 "Szent Anzelm p�sp�k �s egyh�ztan�t�",
 };
const char *text_APR_21_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Konr�da z Parzhamu, reho�n�ka, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_APR_22_SJ[POCET_JAZYKOV + 1] = 
{"Prebl. Panny M�rie, Matky Spolo�nosti Je�i�ovej",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_APR_23[POCET_JAZYKOV + 1] = 
{"Sv. Vojtecha, biskupa a mu�en�ka",
 "Sv. Vojt�cha, biskupa a mu�edn�ka",
 "",
 "S. Adalberti, ep. et mart.",
 "",
 "Sv. Vojt�cha, biskupa a mu�edn�ka",
 "Szent Adalbert (B�la) p�sp�k �s v�rtan�",
 };
const char *text_APR_23_HU[POCET_JAZYKOV + 1] = 
{"Sv. Vojtecha, biskupa a mu�en�ka",
 "Sv. Vojt�cha, biskupa a mu�edn�ka",
 "",
 "S. Adalberti, ep. et mart.",
 "",
 "Sv. Vojt�cha, biskupa a mu�edn�ka",
 "Szent Adalbert (B�la) p�sp�k �s v�rtan�, az Esztergomi f�egyh�zmegye v�d�szentje",
 };
const char *text_APR_23_OFM[POCET_JAZYKOV + 1] = 
{"Bl. Egida z Assisi, reho�n�ka, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_APR_24_1[POCET_JAZYKOV + 1] = 
{"Sv. Juraja, mu�en�ka",
 "Sv. Ji��, mu�edn�ka",
 "",
 "S. Georgii, mart.",
 "",
 "Sv. Ji��, mu�edn�ka",
 "Szent Gy�rgy v�rtan�",
 };
const char *text_APR_24_2[POCET_JAZYKOV + 1] = 
{"Sv. Fid�la zo Sigmaringenu, k�aza a mu�en�ka",
 "Sv. Fidela ze Sigmaringy, kn�ze a mu�edn�ka",
 "",
 "S. Fidelis a Sigmaringen, presb. et mart.",
 "",
 "Sv. Fidela ze Sigmaringy, kn�ze a mu�edn�ka",
 "Sigmaringeni Szent Fid�l �ldoz�pap �s v�rtan�",
 };
const char *text_APR_24_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Fidela zo Sigmaringenu, k�aza a mu�en�ka, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_APR_24_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "Obr�cen� na�eho otce svat�ho Augustina, biskupa a u�itele c�rkve",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_APR_25[POCET_JAZYKOV + 1] = 
{"Sv. Marka, evanjelistu",
 "Sv. Marka, evangelisty",
 "",
 "S. Marci, evangelistae",
 "",
 "Sv. Marka, evangelisty",
 "Szent M�rk evangelista",
 };
const char *text_APR_26_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Ludolfa, biskupa a mu�edn�ka "HTML_LINE_BREAK"z premonstr�tsk�ho ��du",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_APR_27_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Petra Kan�zia, k�aza a u�ite�a Cirkvi",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_APR_27_OP[POCET_JAZYKOV + 1] = 
{"Bl. Hosanny Kotorskej, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_APR_28_1[POCET_JAZYKOV + 1] = 
{"Sv. Petra Chanela, k�aza a mu�en�ka",
 "Sv. Petra Chanela, kn�ze a mu�edn�ka",
 "",
 "S. Petri Chanel, presb. et mart.",
 "",
 "Sv. Petra Chanela, kn�ze a mu�edn�ka",
 "Chanel Szent P�ter �ldoz�pap �s v�rtan�",
 };
const char *text_APR_28_2[POCET_JAZYKOV + 1] = 
{"Sv. �udov�ta M�rie Grignion de Montfort, k�aza",
 "Sv. Ludv�ka Marie Grignona z Montfortu, kn�ze",
 "",
 "S. Ludovici M. Grignion de Montfort, presb.",
 "",
 "Sv. Ludv�ka Marie Grignona z Montfortu, kn�ze, terci��e",
 "Montforti Grignion Szent Lajos M�ria �ldoz�pap",
 };
const char *text_APR_29[POCET_JAZYKOV + 1] = 
{"Sv. Katar�ny Sienskej, panny a u�ite�ky Cirkvi,"HTML_LINE_BREAK"patr�nky Eur�py",
 "Sv. Kate�iny Siensk�, panny a u�itelky c�rkve,"HTML_LINE_BREAK"patronky Evropy",
 "",
 "S. Catharinae Senensis, virg. et Eccl. doct.",
 "",
 "Sv. Kate�iny Siensk�, panny a u�itelky C�rkve,"HTML_LINE_BREAK"patronky Evropy, terci��ky",
 "Sienai Szent Katalin sz�z �s egyh�ztan�t�",
 };
const char *text_APR_30[POCET_JAZYKOV + 1] = 
{"Sv. Pia V., p�pe�a",
 "Sv. Pia V., pape�e",
 "",
 "S. Pii V, papae",
 "",
 "Sv. Pia V., pape�e",
 "Szent V. Piusz p�pa",
 };
const char *text_APR_30_CZ[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Zikmunda, mu�edn�ka",
 "",
 "",
 "",
 "Sv. Zikmunda, mu�edn�ka",
 "",
 };
const char *text_APR_30_OFM[POCET_JAZYKOV + 1] = 
{"Bl. Benedikta z Urbina, k�aza, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };

// --------------- 05 m�j ---------------

const char *text_MAJ_01[POCET_JAZYKOV + 1] = 
{"Sv. Jozefa, robotn�ka",
 "Sv. Josefa, D�ln�ka",
 "",
 "S. loseph Opificis",
 "",
 "Sv. Josefa, D�ln�ka",
 "Munk�s Szent J�zsef",
 };
const char *text_MAJ_02[POCET_JAZYKOV + 1] = 
{"Sv. Atan�za, biskupa a u�ite�a Cirkvi",
 "Sv. Atan�e, biskupa a u�itele c�rkve",
 "",
 "S. Athanasii, ep. et Eccl. doct.",
 "",
 "Sv. Atan�e, biskupa a u�itele C�rkve",
 "Szent Atan�z p�sp�k �s egyh�ztan�t�",
 };
const char *text_MAJ_02_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "P�enesen� sv. Norberta, na�eho otce", // iba na Stahove
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_03[POCET_JAZYKOV + 1] = 
{"Sv. Filipa a Jakuba, apo�tolov",
 "Sv. Filipa a Jakuba, apo�tol�",
 "",
 "Ss. Philippi et Iacobi, apostolorum",
 "",
 "Sv. Filipa a Jakuba, apo�tol�",
 "Szent F�l�p �s Szent Jakab apostol",
 };
const char *text_MAJ_04_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Szent Fl�ri�n v�rtan�",
 };
const char *text_MAJ_04_SJ[POCET_JAZYKOV + 1] = 
{"Bl. Jozefa M�rie Rubia, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_04_OP[POCET_JAZYKOV + 1] = 
{"Bl. Em�lie Bicchieriovej, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_06_CZ[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Jana Sarkandra, kn�ze a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Jana Sarkandra, kn�ze a mu�edn�ka",
 "",
 };
const char *text_MAJ_06_SDB[POCET_JAZYKOV + 1] = 
{"Sv. Dominika Savia, mlad�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_07_OP[POCET_JAZYKOV + 1] = 
{"Bl. Alberta z Bergama, otca rodiny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_07_HU_1[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Boldog Gizella kir�lyn�",
 };
const char *text_MAJ_07_HU_2[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Az Egri bazilika-f�sz�kesegyh�z",
 };
const char *text_MAJ_08_CZ[POCET_JAZYKOV + 1] = 
{"",
 "Panny Marie, Prost�ednice v�ech milost�",
 "",
 "",
 "",
 "Panny Marie, Prost�ednice v�ech milost�",
 "",
 };
const char *text_MAJ_08_OP[POCET_JAZYKOV + 1] = 
{"Bl. Panny M�rie, patr�nky Rehole kazate�ov",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_08_OFM[POCET_JAZYKOV + 1] = 
{"Preblahoslavenej Panny M�rie, Matky a Sprostredkovate�ky milost�",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_08_2_OFM[POCET_JAZYKOV + 1] = 
{"Bl. Ulriky Nischovej, panny, reho�n��ky, �lenky 3. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_08_3_OFM[POCET_JAZYKOV + 1] = 
{"Bl. Jeremi�a z Vala�ska, reho�n�ka, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_09_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Katar�ny z Bologne, panny, �lenky 2. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_10_OP[POCET_JAZYKOV + 1] = 
{"Sv. Anton�na Florentsk�ho, biskupa",
 "",
 "",
 "",
 "",
 "Sv. Anton�na Pierozziho neboli Florentsk�ho, biskupa",
 "",
 };
const char *text_MAJ_11_SK[POCET_JAZYKOV + 1] = 
{"Bl. S�ry Salkah�ziovej, panny a mu�enice",
 "",
 "",
 "",
 "",
 "",
 "Boldog Salkah�zi S�ra sz�z �s v�rtan�",
 };
const char *text_MAJ_11_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Ign�ca z Laconie, reho�n�ka, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_11_OP[POCET_JAZYKOV + 1] = // vo v�eobecnom kalend�ri pre OP sa sl�vi 13. m�ja
{"Bl. Imeldy Lambertiniovej, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_12_1[POCET_JAZYKOV + 1] = 
{"Sv. Nerea a Achila, mu�en�kov",
 "Sv. Nerea a Achillea, mu�edn�k�",
 "",
 "Ss. Nerei et Achillei, mart.",
 "",
 "Sv. Nerea a Achillea, mu�edn�k�",
 "Szent N�reusz �s Szent Achilleusz v�rtan�k",
 };
const char *text_MAJ_12_2[POCET_JAZYKOV + 1] = 
{"Sv. Pankr�ca, mu�en�ka",
 "Sv. Pankr�ce, mu�edn�ka",
 "",
 "S. Pancratii, mart.",
 "",
 "Sv. Pankr�ce, mu�edn�ka",
 "Szent Pongr�c v�rtan�",
 };
const char *text_MAJ_12_CZ[POCET_JAZYKOV + 1] = 
{"",
 "V�ro�� posv�cen� katedr�ly sv. V�ta",
 "",
 "",
 "",
 "V�ro�� posv�cen� katedr�ly sv. V�ta",
 "",
 };
const char *text_MAJ_12_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Leopolda Mandi�a, k�aza, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_12_OP[POCET_JAZYKOV + 1] = 
{"Bl. Jany Portugalskej, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_13[POCET_JAZYKOV + 1] = 
{"Panny M�rie Fatimskej",
 "Panny Marie Fatimsk�",
 "",
 "",
 "",
 "Panny Marie Fatimsk�",
 "A Fatimai Boldogs�gos Sz�z M�ria",
 };
const char *text_MAJ_13_SDB[POCET_JAZYKOV + 1] = 
{"Sv. M�rie Dominiky Mazzarellovej, panny, "HTML_LINE_BREAK"spoluzakladate�ky In�tit�tu dc�r M�rie Pomocnice",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_13_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Petra Regalada, k�aza, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_14[POCET_JAZYKOV + 1] = 
{"Sv. Mateja, apo�tola",
 "Sv. Mat�je, apo�tola",
 "",
 "S. Matthiae, apostoli",
 "",
 "Sv. Mat�je, apo�tola",
 "Szent M�ty�s apostol", // v HU sa sl�vi 24.2.
 };
const char *text_MAJ_15_CZOP[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "Panny Marie, ochr�nkyn� ��du brat�� kazatel�",
 "",
 };
const char *text_MAJ_15_1_OP[POCET_JAZYKOV + 1] = 
{"Bl. Eg�da z Vauzela, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_15_2_OP[POCET_JAZYKOV + 1] = 
{"Bl. Andreja Abellona, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_16_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Andreja Bobolu, k�aza a mu�en�ka", // text_MAJ_15_SJ: na Slovensku sa sl�vi 15. m�ja
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_16[POCET_JAZYKOV + 1] = 
{"Sv. J�na Nepomuck�ho, k�aza a mu�en�ka",
 "Sv. Jana Nepomuck�ho, kn�ze a mu�edn�ka, "HTML_LINE_BREAK"hlavn�ho patrona �ech",
 "",
 "",
 "",
 "Sv. Jana Nepomuck�ho, kn�ze a mu�edn�ka, "HTML_LINE_BREAK"hlavn�ho patrona �ech",
 "Nepomuki Szent J�nos �ldoz�pap �s v�rtan�",
 };
const char *text_MAJ_16_SDB[POCET_JAZYKOV + 1] = 
{"Sv. Alojza Orioneho, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_16_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Margity z Cortony, kaj�cnice, �lenky 3. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_17_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Paschala Baylona, reho�n�ka, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_17_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Boldog Scheffler J�nos p�sp�k �s v�rtan�",
 };
const char *text_MAJ_18[POCET_JAZYKOV + 1] = 
{"Sv. J�na I., p�pe�a a mu�en�ka",
 "Sv. Jana I., pape�e a mu�edn�ka",
 "",
 "S. Ioannis I, papae et mart.",
 "",
 "Sv. Jana I., pape�e a mu�edn�ka",
 "Szent I. J�nos p�pa �s v�rtan�",
 };
const char *text_MAJ_18_SDB[POCET_JAZYKOV + 1] = 
{"Sv. Leonarda Murialda, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_18_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Felixa z Cantalicie, reho�n�ka, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_19_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Kri�p�na z Viterba, reho�n�ka, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_19_OP[POCET_JAZYKOV + 1] = 
{"Bl. Franti�ka Colla Guitarta, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_20_CZ[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Klementa Marie Hofbauera, kn�ze",
 "",
 "",
 "",
 "Sv. Klementa Marie Hofbauera, kn�ze",
 "",
 };
const char *text_MAJ_20[POCET_JAZYKOV + 1] = 
{"Sv. Bernard�na Siensk�ho, k�aza",
 "Sv. Bernardina Siensk�ho, kn�ze",
 "",
 "S. Bernardini Senensis, presb.",
 "",
 "Sv. Bernardina Siensk�ho, kn�ze",
 "Sienai Szent Bernardin �ldoz�pap",
 };
const char *text_MAJ_20_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Bernard�na Siensk�ho, k�aza, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_20_OP[POCET_JAZYKOV + 1] = 
{"Bl. Kolumby z Rieti, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_21_CZ[POCET_JAZYKOV + 1] = 
{"",
 "V�ro�� posv�cen� katedr�ly sv. Petra a Pavla",
 "",
 "",
 "",
 "V�ro�� posv�cen� katedr�ly sv. Petra a Pavla",
 "",
 };
const char *text_MAJ_21[POCET_JAZYKOV + 1] = 
{"Sv. Kri�tofa Magallanesa, k�aza, a spolo�n�kov, mu�en�kov",
 "Sv. Kry�tofa Magallanese, kn�ze a druh�, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Kry�tofa Magallanese, kn�ze a druh�, mu�edn�k�",
 "Magall�n Szent Krist�f �ldoz�pap �s t�rsai, mexik�i v�rtan�k",
 };
const char *text_MAJ_21_OP[POCET_JAZYKOV + 1] = 
{"Bl. Hyacinta M�rie Cormiera, k�aza",
 "",
 "",
 "",
 "",
 "Bl. Hyacinta Marie Cormiera, kn�ze",
 "",
 };
const char *text_MAJ_22[POCET_JAZYKOV + 1] = 
{"Sv. Rity z Kassie, reho�n��ky",
 "Sv. Rity z Cascie, �eholnice",
 "",
 "",
 "",
 "Sv. Rity z Cascie, �eholnice",
 "Szent Rita szerzetesn�",
 };
const char *text_MAJ_23_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Boldog Apor Vilmos p�sp�k �s v�rtan�",
 };
const char *text_MAJ_24_OP[POCET_JAZYKOV + 1] = 
{"Prenesenie pozostatkov sv. otca Dominika",
 "",
 "",
 "",
 "",
 "P�enesen� ostatk� sv. Otce Dominika",
 "",
 };
const char *text_MAJ_24_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "Sv. He�mana Josefa, kn�ze z premonstr�tsk�ho ��du",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_24_OFM[POCET_JAZYKOV + 1] = 
{"V�ro�ie posviacky Baziliky sv. Franti�ka v Assisi",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_24[POCET_JAZYKOV + 1] = 
{"Panny M�rie, Pomocnice kres�anov, "HTML_LINE_BREAK"hlavnej patr�nky In�tit�tu dc�r M�rie Pomocnice "HTML_LINE_BREAK"a celej salezi�nskej rodiny",
 "",
 "",
 "",
 "",
 "",
 "Sz�z M�ria, a kereszt�nyek seg�ts�ge",
 };
const char *text_MAJ_25_1[POCET_JAZYKOV + 1] = 
{"Sv. B�du Ctihodn�ho, k�aza a u�ite�a Cirkvi",
 "Sv. Bedy Ctihodn�ho, kn�ze a u�itele c�rkve",
 "",
 "S. Bedae Venerdbilis, presb. et Ecci. doct.",
 "",
 "Sv. Bedy Ctihodn�ho, kn�ze a u�itele C�rkve",
 "Tiszteletrem�lt� Szent B�da �ldoz�pap �s egyh�ztan�t�",
 };
const char *text_MAJ_25_2[POCET_JAZYKOV + 1] = 
{"Sv. Gregora VII., p�pe�a",
 "Sv. �eho�e VII., pape�e",
 "",
 "S. Gregorii VII, papae",
 "",
 "Sv. �eho�e VII., pape�e",
 "Szent VII. Gergely p�pa",
 };
const char *text_MAJ_25_3[POCET_JAZYKOV + 1] = 
{"Sv. M�rie Magdal�ny de� Pazzi, panny",
 "Sv. Marie Magdal�ny de� Pazzi, panny",
 "",
 "S. Mariae Magdalenae de� Pazzi, virg.",
 "",
 "Sv. Marie Magdal�ny de� Pazzi, panny",
 "Pazzi Szent M�ria Magdolna Sz�z",
 };
const char *text_MAJ_26[POCET_JAZYKOV + 1] = 
{"Sv. Filipa Neriho, k�aza",
 "Sv. Filipa Neriho, kn�ze",
 "",
 "S. Philippi Neri, presb.",
 "",
 "Sv. Filipa Neriho, kn�ze",
 "N�ri Szent F�l�p �ldoz�pap",
 };
const char *text_MAJ_27[POCET_JAZYKOV + 1] = 
{"Sv. August�na z Canterbury, biskupa",
 "Sv. Augustina z Canterbury, biskupa",
 "",
 "S. Augustini Cantuariensis, ep.",
 "",
 "Sv. Augustina z Canterbury, biskupa",
 "Canterbury Szent �goston p�sp�k",
 };
const char *text_MAJ_27_OP[POCET_JAZYKOV + 1] = 
{"Bl. Andreja Franchiho, biskupa",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_28_OP[POCET_JAZYKOV + 1] = 
{"Bl. M�rie Bartolomey Bagnesiovej, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_29_OP[POCET_JAZYKOV + 1] = 
{"Bl. Viliama Arnauda, k�aza, a spolo�n�kov, mu�en�kov",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_29_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Jozefa Kowalsk�ho, mu�en�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_30_OP[POCET_JAZYKOV + 1] = 
{"Bl. Jakuba Salomoniho, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_MAJ_30_CZ[POCET_JAZYKOV + 1] = 
{"Sv. Zdislavy, matky rodiny", // SK OP
 "Sv. Zdislavy",
 "",
 "",
 "",
 "Sv. Zdislavy z Lemberka, matky rodiny, terci��ky,"HTML_LINE_BREAK"spolupatronky provincie",
 "",
 };
const char *text_MAJ_30_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Szent Istv�n kir�ly erekly�inek �tvitele",
 };
const char *text_MAJ_31[POCET_JAZYKOV + 1] = 
{"Nav�t�venie prebl. Panny M�rie",
 "Nav�t�ven� Panny Marie",
 "",
 "",
 "",
 "Nav�t�ven� Panny Marie",
 "Sz�z M�ria l�togat�sa Erzs�betn�l"HTML_LINE_BREAK"(Sarl�s Boldogasszony)",
 };

// --------------- 00 pohybliv� sl�venia ---------------

const char *text_NANEBOVSTUPENIE_PANA[POCET_JAZYKOV + 1] = 
{"Nanebovst�penie P�na",
 "Nanebevstoupen� P�n�",
 "",
 "",
 "",
 "Nanebevstoupen� P�n�",
 "Urunk mennybemenetele",
 };
const char *text_VELKONOCNA_NEDELA[POCET_JAZYKOV + 1] = 
{"Ve�kono�n� nede�a",
 "Ned�le Zmrtv�chvst�n� P�n�",
 "",
 "",
 "",
 "Ned�le Zmrtv�chvst�n� P�n�",
 "H�sv�tvas�rnap",
 };
const char *text_NEDELA_PANOVHO_ZMRTVYCHVSTANIA[POCET_JAZYKOV + 1] = // 2012-12-13: XML nepodporuje &mdash; -- pou�it� ��seln� k�d &#8212; http://en.wikipedia.org/wiki/List_of_XML_and_HTML_character_entity_references
{HTML_LINE_BREAK" &#8212; Nede�a P�novho zm�tvychvstania",
 "",
 "",
 "",
 "",
 "",
 ", Krisztus felt�mad�sa",
 };
const char *text_NEDELA_VO_VELKONOCNEJ_OKTAVE[POCET_JAZYKOV + 1] = 
{"Nede�a vo Ve�kono�nej okt�ve",
 "Ned�le v okt�vu velikono�n�m",
 "",
 "",
 "",
 "Ned�le v okt�vu velikono�n�m",
 "Vas�rnap H�sv�t nyolcad�ban",
 };
const char *text_DEN_VO_VELKONOCNEJ_OKTAVE[POCET_JAZYKOV + 1] = 
{"Ve�kono�n%c %s",
 "%s velikono�n�",
 "",
 "",
 "",
 "%s velikono�n�",
 "%s H�sv�t nyolcad�ban",
 };

const char *text_HU_VELKONOCNY_PONDELOK = "H�sv�th�tf�"; // pre HU �peci�lny n�zov ve�kono�n�ho pondelka

const char *text_HU_VELKY_TYZDEN_PREFIX = "Nagy"; // pre HU �peci�lne n�zvy dn� ve�kn�ho t��d�a (pondelok a� streda)

const char *text_NAJSVATEJSEJ_TROJICE[POCET_JAZYKOV + 1] = 
{"Najsv�tej�ej Trojice",
 "Nejsv�t�j�� Trojice",
 "",
 "",
 "",
 "Nejsv�t�j�� Trojice",
 "Szenth�roms�gvas�rnap",
 };
const char *text_KRISTA_KRALA[POCET_JAZYKOV + 1] = 
{"Krista Kr�a",
 "Je��e Krista Kr�le",
 "",
 "",
 "",
 "Je��e Krista Kr�le",
 "Krisztus Kir�ly",
 };
const char *text_NAJSV_KRISTOVHO_TELA_A_KRVI[POCET_JAZYKOV + 1] = 
{"Najsv�tej�ieho Kristovho tela a krvi",
 "T�la a krve P�n�",
 "",
 "",
 "",
 "T�la a krve P�n�",
 "Krisztus Szent Teste �s V�re",
 };
const char *text_NAJSV_SRDCA_JEZISOVHO[POCET_JAZYKOV + 1] = 
{"Najsv�tej�ieho Srdca Je�i�ovho",
 "Nejsv�t�j��ho Srdce Je��ova",
 "",
 "",
 "",
 "Nejsv�t�j��ho Srdce Je��ova",
 "J�zus Szent Sz�ve",
 };
const char *text_NEPOSKVRNENEHO_SRDCA_PM[POCET_JAZYKOV + 1] = 
{"Nepo�kvrnen�ho Srdca Panny M�rie", // 2010-06-16: opraven� n�zov pod�a brevi�ra i direkt�ria
 "Neposkvrn�n�ho Srdce Panny Marie",
 "",
 "",
 "",
 "Neposkvrn�n�ho Srdce Panny Marie",
 "A Boldogs�gos Sz�z M�ria Szepl�telen Sz�ve",
 };
const char *text_NEPOSKVRNENEHO_SRDCA_PM_OFM[POCET_JAZYKOV + 1] = 
{"Nepo�kvrnen�ho Srdca Panny M�rie, "HTML_LINE_BREAK"patr�nky slovenskej provincie R�du men��ch bratov kapuc�nov",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NARODENIE_PANA[POCET_JAZYKOV + 1] = 
{"Narodenie P�na",
 "Narozen� P�n�",
 "",
 "",
 "",
 "Narozen� P�n�",
 "Urunk sz�let�se (Kar�csony)",
 };
const char *text_ZOSLANIE_DUCHA_SVATEHO[POCET_JAZYKOV + 1] = 
{"Zoslanie Ducha Sv�t�ho",
 "Sesl�n� Ducha svat�ho",
 "",
 "",
 "",
 "Sesl�n� Ducha Svat�ho",
 "P�nk�sd",
 };
const char *text_PRVA_ADVENTNA_NEDELA[POCET_JAZYKOV + 1] = 
{"Prv� adventn� nede�a",
 "Prvn� ned�le adventn�",
 "",
 "",
 "",
 "Prvn� ned�le adventn�",
 "Advent els� vas�rnapja",
 };
const char *text_NEDELA_SV_RODINY[POCET_JAZYKOV + 1] = 
{"Sv�tej rodiny Je�i�a, M�rie a Jozefa",
 "Sv. Rodiny Je��e, Marie a Josefa",
 "",
 "",
 "",
 "Sv. Rodiny Je��e, Marie a Josefa",
 "A Szent csal�d: J�zus, M�ria �s J�zsef", // "Szent Csal�d �nnepe"
 };
const char *text_SPOMIENKA_PM_V_SOBOTU[POCET_JAZYKOV + 1] = 
{"Spomienka Panny M�rie v sobotu",
 "Sobotn� pam�tka Panny Marie",
 "",
 "Memoria S. Mariae in sabbato",
 "",
 "Sobotn� pam�tka Panny Marie",
 "Sz�z M�ria szombati eml�knapja",
 };

// --------------- 06 j�n ---------------

const char *text_JUN_01[POCET_JAZYKOV + 1] = 
{"Sv. Just�na, mu�en�ka",
 "Sv. Justina, mu�edn�ka",
 "",
 "",
 "",
 "Sv. Justina, mu�edn�ka",
 "Szent Juszt�nusz v�rtan�",
 };
const char *text_JUN_02[POCET_JAZYKOV + 1] = 
{"Sv. Marcel�na a Petra, mu�en�kov",
 "Sv. Marcelina a Petra, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Marcelina a Petra, mu�edn�k�",
 "Szent Marcell�nusz �s Szent P�ter v�rtan�k",
 };
const char *text_JUN_02_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Felixa z Nik�zie, reho�n�ka, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_02_OP[POCET_JAZYKOV + 1] = 
{"Bl. Sadoka, k�aza, a spolo�n�kov, mu�en�kov",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_03[POCET_JAZYKOV + 1] = 
{"Sv. Karola Lwangu a spolo�n�kov, mu�en�kov",
 "Sv. Karla Lwangy a druh�, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Karla Lwangy a druh�, mu�edn�k�",
 "Lwanga Szent K�roly �s t�rsai, v�rtan�k",
 };
const char *text_JUN_04_OP[POCET_JAZYKOV + 1] = 
{"Sv. Petra Veronsk�ho, k�aza a mu�en�ka",
 "",
 "",
 "",
 "",
 "Sv. Petra Veronsk�ho, kn�ze a mu�edn�ka",
 "",
 };
const char *text_JUN_04_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Szent Quirinus (Ker�ny) p�sp�k �s v�rtan�",
 };
const char *text_JUN_05[POCET_JAZYKOV + 1] = 
{"Sv. Bonif�ca, biskupa a mu�en�ka",
 "Sv. Bonif�ce, biskupa a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Bonif�ce, biskupa a mu�edn�ka",
 "Szent Bonif�c p�sp�k �s v�rtan�",
 };
const char *text_JUN_06[POCET_JAZYKOV + 1] = 
{"Sv. Norberta, biskupa",
 "Sv. Norberta, biskupa",
 "",
 "",
 "",
 "Sv. Norberta, biskupa",
 "Szent Norbert p�sp�k",
 };
const char *text_JUN_06_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "Na�eho otce sv. Norberta, biskupa "HTML_LINE_BREAK"a zakladatele premonstr�tsk�ho ��du",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_08_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Pr�gai szent �gnes sz�z",
 };
const char *text_JUN_08_OFM[POCET_JAZYKOV + 1] = 
{"Bl. Mikul�a z Gesturi, reho�n�ka, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_08_OP[POCET_JAZYKOV + 1] = 
{"Bl. Diany a Cec�lie, panien",
 "",
 "",
 "",
 "",
 "Bl. Diany Andalo a Cec�lie, panen, mni�ek",
 "",
 };
const char *text_JUN_09[POCET_JAZYKOV + 1] = 
{"Sv. Efr�ma, diakona a u�ite�a Cirkvi",
 "Sv. Efr�ma Syrsk�ho, j�hna a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Efr�ma Syrsk�ho, j�hna a u�itele C�rkve",
 "Szent Efr�m diak�nus �s egyh�ztan�t�",
 };
const char *text_JUN_09_SJ[POCET_JAZYKOV + 1] = 
{"Bl. Jozefa de Anchieta, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_10_OP[POCET_JAZYKOV + 1] = 
{"Bl. J�na Dominiciho, biskupa",
 "",
 "",
 "",
 "",
 "Bl. Jana Dominiciho, biskupa",
 "",
 };
const char *text_JUN_11[POCET_JAZYKOV + 1] = 
{"Sv. Barnab�a, apo�tola",
 "Sv. Barnab�e, apo�tola",
 "",
 "",
 "",
 "Sv. Barnab�e, apo�tola",
 "Szent Barnab�s apostol",
 };
const char *text_JUN_12_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Franti�ka K&#281;syho a spolo�n�kov, mu�en�kov", // Bl. Franti�ka Kesyho a spolo�n�kov, mu�en�kov (small latin letter e with ogonek)
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_12_OP[POCET_JAZYKOV + 1] = 
{"Bl. �tefana Bandelliho, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_12_OFM[POCET_JAZYKOV + 1] = 
{"Bl. Jolandy Uhorskej, reho�n��ky, �lenky 2. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_12_2_OFM[POCET_JAZYKOV + 1] = 
{"Bl. Floridy Cevoliovej, panny, �lenky 2. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_12_3_OFM[POCET_JAZYKOV + 1] = 
{"Bl. Antona Bajewsk�ho a spolo�n�kov, mu�en�kov: "HTML_LINE_BREAK"Pia Barto�ika, Inocenta Guza, Achilla Puchalu, Hermana St&#281;npie&nacute;a, k�azov; "HTML_LINE_BREAK"Timoteja Trojanowsk�ho, Bonif�ca &#379;ukowsk�ho, reho�n�kov, �lenov 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_13_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Antona Padu�nskeho, k�aza a u�ite�a Cirkvi, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_13[POCET_JAZYKOV + 1] = 
{"Sv. Antona Padu�nskeho, k�aza a u�ite�a Cirkvi",
 "Sv. Anton�na z Padovy, kn�ze a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Anton�na z Padovy, kn�ze a u�itele C�rkve",
 "P�duai Szent Antal �ldoz�pap �s egyh�ztan�t�",
 };
const char *text_JUN_14_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "A Szombathelyi sz�kesegyh�z felszentel�se",
 };
const char *text_JUN_15_CZ[POCET_JAZYKOV + 1] = 
{"",
 "Sv. V�ta, mu�edn�ka",
 "",
 "",
 "",
 "Sv. V�ta, mu�edn�ka",
 "",
 };
const char *text_JUN_15_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "�rp�d-h�zi boldog Jol�n szerzetesn�",
 };
const char *text_JUN_16_SK[POCET_JAZYKOV + 1] = 
{"Sv. Neita, mu�en�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_16_OFM[POCET_JAZYKOV + 1] = 
{"Bl. M�rie Ter�zie Schererovej, panny, reho�n��ky, �lenky 3. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_16_2_OFM[POCET_JAZYKOV + 1] = 
{"Bl. Aniceta Koplina, k�aza, a spolo�n�kov, mu�en�kov, �lenov 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_16_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Isfr�da, biskupa z premonstr�tsk�ho ��du",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_16_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Tours-i szent M�rton p�sp�k erekly�inek �tvitele",
 };
const char *text_JUN_17_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Alberta Chmielowsk�ho, reho�n�ka, �lena 3. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_18_OP[POCET_JAZYKOV + 1] = 
{"Bl. Hosanny z Mantovy, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_19[POCET_JAZYKOV + 1] = 
{"Sv. Romualda, op�ta",
 "Sv. Romualda, opata",
 "",
 "",
 "",
 "Sv. Romualda, opata",
 "Szent Romuald ap�t",
 };
const char *text_JUN_19_CZ[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Jana Nepomuck�ho Neumanna, biskupa",
 "",
 "",
 "",
 "Sv. Jana Nepomuck�ho Neumanna, biskupa",
 "",
 };
const char *text_JUN_21[POCET_JAZYKOV + 1] = 
{"Sv. Alojza Gonz�gu, reho�n�ka",
 "Sv. Aloise Gonzagy, �eholn�ka",
 "",
 "",
 "",
 "Sv. Aloise Gonzagy, �eholn�ka",
 "Gonz�ga Szent Alajos szerzetes",
 };
const char *text_JUN_21_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Alojza Gonzagu, reho�n�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_22_2[POCET_JAZYKOV + 1] = 
{"Sv. Pavl�na z Noly, biskupa",
 "Sv. Paulina Nol�nsk�ho, biskupa",
 "",
 "",
 "",
 "Sv. Paulina Nol�nsk�ho, biskupa",
 "Nolai Szent Paul�nusz p�sp�k",
 };
const char *text_JUN_22_1[POCET_JAZYKOV + 1] = 
{"Sv. J�na Fishera, biskupa,"HTML_LINE_BREAK"a sv. Tom�a Morusa, mu�en�kov", // kedysi: M�rusa; Direkt�rium 2012, str. 156, uv�dza u� iba s kr�tkym "o"
 "Sv. Jana Fishera, biskupa,"HTML_LINE_BREAK"a Tom�e Mora, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Jana Fishera, biskupa,"HTML_LINE_BREAK"a Tom�e Mora, mu�edn�k�",
 "Fisher Szent J�nos p�sp�k"HTML_LINE_BREAK"�s Morus Szent Tam�s v�rtan�k",
 };
const char *text_JUN_22_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "A P�csi sz�kesegyh�z felszentel�se",
 };
const char *text_JUN_23_SDB[POCET_JAZYKOV + 1] = 
{"Sv. Jozefa Cafassa, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_23_OP[POCET_JAZYKOV + 1] = 
{"Bl. Inocenta V., p�pe�a",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_24[POCET_JAZYKOV + 1] = 
{"Narodenie sv. J�na Krstite�a",
 "Narozen� svat�ho Jana K�titele",
 "",
 "",
 "",
 "Narozen� svat�ho Jana K�titele",
 "Keresztel� Szent J�nos sz�let�se",
 };
const char *text_JUN_26_OFM[POCET_JAZYKOV + 1] = 
{"Bl. Andreja Hyacinta Longina, biskupa, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_27[POCET_JAZYKOV + 1] = 
{"Sv. Cyrila Alexandrijsk�ho, biskupa a u�ite�a Cirkvi",
 "Sv. Cyrila Alexandrijsk�ho, biskupa a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Cyrila Alexandrijsk�ho, biskupa a u�itele c�rkve",
 "Alexandriai szent Cirill p�sp�k �s egyh�ztan�t�", // HU: 26JUN
 };
const char *text_JUN_27_SK_HU[POCET_JAZYKOV + 1] = 
{"Sv. Ladislava",
 "",
 "",
 "",
 "",
 "",
 "Szent L�szl� kir�ly",
 };
const char *text_JUN_27_CSSR[POCET_JAZYKOV + 1] = 
{"Panny M�rie, Matky ustavi�nej pomoci",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUN_28[POCET_JAZYKOV + 1] = 
{"Sv. Ireneja, biskupa a mu�en�ka",
 "Sv. Ireneje, biskupa a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Ireneje, biskupa a mu�edn�ka",
 "Szent Ir�neusz p�sp�k �s v�rtan�",
 };
const char *text_JUN_29[POCET_JAZYKOV + 1] = 
{"Sv. Petra a Pavla, apo�tolov",
 "Sv. Petra a Pavla, apo�tol�",
 "",
 "",
 "",
 "Sv. Petra a Pavla, apo�tol�",
 "Szent P�ter �s Szent P�l apostolok",
 };
const char *text_JUN_30[POCET_JAZYKOV + 1] = 
{"Prv�ch sv�t�ch mu�en�kov Cirkvi v R�me",
 "Svat�ch prvomu�edn�k� ��msk�ch",
 "",
 "",
 "",
 "Svat�ch prvomu�edn�k� ��msk�ch",
 "A r�mai Egyh�z els� szent v�rtan�i",
 };
const char *text_JUN_30_CZ[POCET_JAZYKOV + 1] = 
{"",
 "V�ro�� posv�cen� katedr�ly sv. V�clava",
 "",
 "",
 "",
 "V�ro�� posv�cen� katedr�ly sv. V�clava",
 "",
 };
const char *text_JUN_30_CSSR[POCET_JAZYKOV + 1] = 
{"Bl. Janu�ra M�rie Sarnelliho, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };

// --------------- 07 j�l ---------------

const char *text_JUL_02_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Bernard�na Realina, sv. J�na Franti�ka R�gisa, sv. Franti�ka de Geronimo, "HTML_LINE_BREAK"bl. Juli�na Maunoira, bl. Antona Baldinucciho, k�azov", // text_JUL_01_SJ: na Slovensku sa sl�vi 1. j�la
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUL_03[POCET_JAZYKOV + 1] = 
{"Sv. Tom�a, apo�tola",
 "Sv. Tom�e, apo�tola",
 "",
 "",
 "",
 "Sv. Tom�e, apo�tola",
 "Szent Tam�s apostol",
 };
const char *text_JUL_04[POCET_JAZYKOV + 1] = 
{"Sv. Al�bety Portugalskej",
 "Sv. Al�b�ty Portugalsk�",
 "",
 "",
 "",
 "Sv. Al�b�ty Portugalsk�",
 "Portug�liai Szent Erzs�bet",
 };
const char *text_JUL_04_CZ[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Prokopa, opata",
 "",
 "",
 "",
 "Sv. Prokopa, opata",
 "",
 };
const char *text_JUL_04_1_OP[POCET_JAZYKOV + 1] = 
{"Bl. Katar�ny Jarrigeovej, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUL_04_2_OP[POCET_JAZYKOV + 1] = 
{"Bl. Petra Juraja Frassatiho, laika",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUL_05[POCET_JAZYKOV + 1] = 
{"Sv. Cyrila a Metoda, slovansk�ch vierozvestov",
 "Sv. Cyrila, mnicha, a Metod�je, biskupa, "HTML_LINE_BREAK"patron� Evropy, hlavn�ch patron� Moravy",
 "",
 "",
 "",
 "Sv. Cyrila, mnicha, a Metod�je, biskupa, "HTML_LINE_BREAK"patron� Evropy, hlavn�ch patron� Moravy",
 "",
 };
const char *text_JUL_06[POCET_JAZYKOV + 1] = 
{"Sv. M�rie Goretti, panny a mu�enice",
 "Sv. Marie Gorettiov�, panny a mu�ednice",
 "",
 "",
 "",
 "Sv. Marie Gorettiov�, panny a mu�ednice",
 "Goretti Szent M�ria sz�z �s v�rtan�",
 };
const char *text_JUL_06_CZOP[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "Blaholaven�ho Pier Giorgio Frassatiho, laika OP",
 "",
 };
const char *text_JUL_07_SK[POCET_JAZYKOV + 1] = // vo v�eobecnom kalend�ri sa sl�vi 5. j�la
{"Sv. Antona M�rie Zaccariu, k�aza",
 "",
 "",
 "",
 "",
 "",
 "Zaccaria szent Antal M�ria �ldoz�pap",
 };
const char *text_JUL_07_SDB[POCET_JAZYKOV + 1] = 
{"Bl. M�rie Romerovej Meneses, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUL_07_OP[POCET_JAZYKOV + 1] = 
{"Bl. Benedikta XI., p�pe�a",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUL_08_OP[POCET_JAZYKOV + 1] = 
{"Bl. Hadri�na Fortescuea, otca rodiny a mu�en�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUL_08_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "A Sz�kesegyh�z felszentel�se",
 };
const char *text_JUL_09[POCET_JAZYKOV + 1] = 
{"Sv. August�na Zhao Rong, k�aza,"HTML_LINE_BREAK"a spolo�n�kov, mu�en�kov",
 "Sv. Augustina �ao Ronga, kn�ze"HTML_LINE_BREAK"a jeho druh�, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Augustina �ao Ronga, kn�ze"HTML_LINE_BREAK"a jeho druh�, mu�edn�k�",
 "Szent Zhao Rong �goston �ldoz�pap �s t�rsai, k�nai v�rtan�k",
 };
const char *text_JUL_09_OP[POCET_JAZYKOV + 1] = 
{"Sv. J�na Kol�nskeho, k�aza, a spolo�n�kov, mu�en�kov",
 "",
 "",
 "",
 "",
 "Sv. Jana Kol�nsk�ho, kn�ze, a druh�, mu�edn�k�",
 "",
 };
const char *text_JUL_09_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Mikul�a Picka, Antona von Willehada a spolo�n�kov, "HTML_LINE_BREAK"mu�en�kov v Holandsku, �lenov 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUL_09_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Adri�na a Jakuba, kn�� premonstr�tsk�ho ��du, "HTML_LINE_BREAK"a jejich druh�, mu�edn�k� Gorkumsk�ch",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUL_10_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Veroniky Giulianiovej, panny, �lenky 2. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUL_11[POCET_JAZYKOV + 1] = 
{"Sv. Benedikta, op�ta,"HTML_LINE_BREAK"patr�na Eur�py",
 "Sv. Benedikta, opata,"HTML_LINE_BREAK"patrona Evropy",
 "",
 "",
 "",
 "Sv. Benedikta, opata,"HTML_LINE_BREAK"patrona Evropy",
 "Szent Benedek ap�t,"HTML_LINE_BREAK"Eur�pa f�v�d�szentje",
 };
const char *text_JUL_13[POCET_JAZYKOV + 1] = 
{"Sv. Henricha",
 "Sv. Jind�icha",
 "",
 "",
 "",
 "Sv. Jind�icha",
 "Szent Henrik",
 };
const char *text_JUL_13_OP[POCET_JAZYKOV + 1] = 
{"Bl. Jakuba z Varazze, biskupa",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUL_14[POCET_JAZYKOV + 1] = 
{"Sv. Kamila de Lellis, k�aza",
 "Sv. Kamila de Lellis, kn�ze",
 "",
 "",
 "",
 "Sv. Kamila de Lellis, kn�ze",
 "Lellisi Szent Kamill �ldoz�pap",
 };
const char *text_JUL_14_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Franti�ka Solansk�ho, k�aza, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUL_14_CZ[POCET_JAZYKOV + 1] = 
{"",
 "Bl. Hroznaty, mu�edn�ka",
 "",
 "",
 "",
 "Bl. Hroznaty, mu�edn�ka",
 "",
 };
const char *text_JUL_14_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "Bl. Hroznaty, mu�edn�ka z premonstr�tsk�ho ��du",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUL_15[POCET_JAZYKOV + 1] = 
{"Sv. Bonavent�ru, biskupa a u�ite�a Cirkvi",
 "Sv. Bonaventury, biskupa a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Bonaventury, biskupa a u�itele C�rkve",
 "Szent Bonaventura p�sp�k �s egyh�ztan�t�",
 };
const char *text_JUL_15_OFM[POCET_JAZYKOV + 1] = 
{"Sv. Bonavent�ru z Bagnoregia, biskupa a u�ite�a Cirkvi, �lena 1. r�du",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUL_16[POCET_JAZYKOV + 1] = 
{"Prebl. Panny M�rie Karmelskej",
 "Panny Marie Karmelsk�",
 "",
 "",
 "",
 "Panny Marie Karmelsk�",
 "K�rmel-hegyi Boldogasszony",
 };
const char *text_JUL_16_CZ[POCET_JAZYKOV + 1] = 
{"",
 "V�ro�� posv�cen� katedr�ly Bo�sk�ho Spasitele",
 "",
 "",
 "",
 "V�ro�� posv�cen� katedr�ly Bo�sk�ho Spasitele",
 "",
 };
const char *text_JUL_17_SK[POCET_JAZYKOV + 1] = 
{"Sv. Andreja-Svorada a Benedikta, pustovn�kov",
 "",
 "",
 "",
 "",
 "",
 "Szent Zoer�rd-Andr�s �s Benedek remet�k",
 };
const char *text_JUL_17_CZ[POCET_JAZYKOV + 1] = 
{"",
 "Bl. �eslava a sv. Hyacinta, kn��",
 "",
 "",
 "",
 "Bl. �eslava a sv. Hyacinta, kn��",
 "",
 };
const char *text_JUL_17_OP[POCET_JAZYKOV + 1] = 
{"Bl. �eslava Po�sk�ho, k�aza",
 "",
 "",
 "",
 "",
 "Bl. �eslava z Polska, kn�ze",
 "",
 };
const char *text_JUL_18_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Szent Hedvig kir�lyn�",
 };
const char *text_JUL_18_OP[POCET_JAZYKOV + 1] = 
{"Bl. Bartolomeja od Mu�en�kov, biskupa",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUL_20[POCET_JAZYKOV + 1] = 
{"Sv. Apolin�ra, biskupa a mu�en�ka",
 "Sv. Apolin��e, biskupa a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Apolin��e, biskupa a mu�edn�ka",
 "Szent Apollinaris p�sp�k �s v�rtan�",
 };
const char *text_JUL_21[POCET_JAZYKOV + 1] = 
{"Sv. Vavrinca z Brindisi, k�aza a u�ite�a Cirkvi",
 "Sv. Vav�ince z Brindisi, kn�ze a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Vav�ince z Brindisi, kn�ze a u�itele C�rkve",
 "Brindisi Szent L�rinc �ldoz�pap �s egyh�ztan�t�",
 };
const char *text_JUL_22[POCET_JAZYKOV + 1] = 
{"Sv. M�rie Magdal�ny",
 "Sv. Marie Magdal�ny",
 "",
 "",
 "",
 "Sv. Marie Magdal�ny",
 "Szent M�ria Magdolna",
 };
const char *text_JUL_23[POCET_JAZYKOV + 1] = 
{"Sv. Brigity, reho�n��ky,"HTML_LINE_BREAK"patr�nky Eur�py",
 "Sv. Brigity, �eholnice,"HTML_LINE_BREAK"patronky Evropy",
 "",
 "",
 "",
 "Sv. Brigity, �eholnice,"HTML_LINE_BREAK"patronky Evropy",
 "Szent Brigitta szerzetesn�",
 };
const char *text_JUL_24[POCET_JAZYKOV + 1] = 
{"Sv. Sarbela Makhlufa, k�aza", // 2009-07-15: direkt�rium (2012, str. 171) m� "Sarbel", predt�m bolo "Charbel" a zrejme sa ��ta "�arbel"
 "Sv. �arbela Makhl�fa, kn�ze",
 "",
 "",
 "",
 "Sv. �arbela Makhl�fa, kn�ze",
 "Szent Charbel Makhlouf �ldoz�pap",
 };
const char *text_JUL_24_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "�rp�d-h�zi szent Kinga sz�z", // 2011-07-05: sv. Sarbela v HU maj� 27. j�la
 };
const char *text_JUL_24_1_OP[POCET_JAZYKOV + 1] = 
{"Bl. Jany z Orvieta, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUL_24_2_OP[POCET_JAZYKOV + 1] = 
{"Bl. August�na z Biella, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUL_25[POCET_JAZYKOV + 1] = 
{"Sv. Jakuba, apo�tola",
 "Sv. Jakuba, apo�tola",
 "",
 "",
 "",
 "Sv. Jakuba, apo�tola",
 "Szent Jakab apostol",
 };
const char *text_JUL_26[POCET_JAZYKOV + 1] = 
{"Sv. Joachima a Anny, rodi�ov Panny M�rie",
 "Sv. J�chyma a Anny, rodi�� Panny Marie",
 "",
 "",
 "",
 "Sv. J�chyma a Anny, rodi�� Panny Marie",
 "Szent Joakim �s Szent Anna, a Boldogs�gos Sz�z M�ria sz�lei",
 };
const char *text_JUL_27[POCET_JAZYKOV + 1] = 
{"Sv. Gorazda a spolo�n�kov",
 "Sv. Gorazda a druh�",
 "",
 "",
 "",
 "Sv. Gorazda a druh�",
 "",
 };
const char *text_JUL_27_OP[POCET_JAZYKOV + 1] = // SK OP: 28JUL
{"Bl. R�berta Nuttera, k�aza a mu�en�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUL_29[POCET_JAZYKOV + 1] = 
{"Sv. Marty",
 "Sv. Marty",
 "",
 "",
 "",
 "Sv. Marty",
 "Szent M�rta",
 };
const char *text_JUL_30[POCET_JAZYKOV + 1] = 
{"Sv. Petra Chryzol�ga, biskupa a u�ite�a Cirkvi",
 "Sv. Petra Chryzologa, biskupa a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Petra Chryzologa, biskupa a u�itele c�rkve",
 "Aranyszav� (Krizologosz) Szent P�ter p�sp�k �s egyh�ztan�t�",
 };
const char *text_JUL_30_SK[POCET_JAZYKOV + 1] = 
{"Bl. Zdenky, panny a mu�enice", // Direkt�rium 2012, str. 173, neuv�dza priezvisko ('Schelingovej')
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_JUL_31[POCET_JAZYKOV + 1] = 
{"Sv. Ign�ca z Loyoly, k�aza",
 "Sv. Ign�ce z Loyoly, kn�ze",
 "",
 "",
 "",
 "Sv. Ign�ce z Loyoly, kn�ze",
 "Loyolai Szent Ign�c �ldoz�pap",
 };
const char *text_JUL_31_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Ign�ca Loyolsk�ho, k�aza a zakladate�a Spolo�nosti Je�i�ovej",
 "",
 "",
 "",
 "",
 "",
 "",
 };

// --------------- 00 pohybliv� sl�venia ---------------

const char *text_CSSR_TITUL_KONGREGACIE[POCET_JAZYKOV + 1] = 
{"Najsv�tej�ieho Vykupite�a, titul Kongreg�cie", // 3. nede�a v j�li
 "",
 "",
 "",
 "",
 "",
 "",
 };

// --------------- 08 august ---------------

const char *text_AUG_01[POCET_JAZYKOV + 1] = 
{"Sv. Alfonza M�rie de� Liguori, biskupa a u�ite�a Cirkvi",
 "Sv. Alfonsa z Liguori, biskupa a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Alfonsa z Liguori, biskupa a u�itele C�rkve",
 "Liguori Szent Alfonz M�ria p�sp�k �s egyh�ztan�t�",
 };
const char *text_AUG_01_CSSR[POCET_JAZYKOV + 1] = 
{"Sv. Alfonza M�rie de� Liguori, biskupa a u�ite�a Cirkvi, zakladate�a kongreg�cie",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_AUG_02_1[POCET_JAZYKOV + 1] = 
{"Sv. Euz�bia Vercellsk�ho, biskupa",
 "Sv. Eusebia z Vercelli, biskupa",
 "",
 "",
 "",
 "Sv. Eusebia z Vercelli, biskupa",
 "Vercelli Szent �zs�b p�sp�k",
 };
const char *text_AUG_02_2[POCET_JAZYKOV + 1] = 
{"Sv. Petra Juli�na Eymarda, k�aza",
 "Sv. Petra Juli�na Eymarda, kn�ze",
 "",
 "",
 "",
 "Sv. Petra Juli�na Eymarda, kn�ze",
 "Szent Eymard Juli�n P�ter �ldoz�pap",
 };
const char *text_AUG_02_OP[POCET_JAZYKOV + 1] = 
{"Bl. Jany z Azy, matky sv. otca Dominika",
 "",
 "",
 "",
 "",
 "Bl. Jany, matky sv. Otce Dominika",
 "",
 };
const char *text_AUG_03_OP[POCET_JAZYKOV + 1] = 
{"Bl. August�na Kazoti�a, biskupa",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_AUG_02_SDB[POCET_JAZYKOV + 1] = 
{"Bl. August�na Czartorysk�ho, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_AUG_02_SJ[POCET_JAZYKOV + 1] = 
{"Bl. Petra Favra, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_AUG_04[POCET_JAZYKOV + 1] = 
{"Sv. J�na M�rie Vianneyho, k�aza", // 'Vianneyho' pod�a Direkt�ria 2012, str. 176
 "Sv. Jana Marie Vianneye, kn�ze",
 "",
 "",
 "",
 "Sv. Jana Marie Vianneye, kn�ze",
 "Vianney Szent J�nos M�ria �ldoz�pap",
 };
const char *text_AUG_05[POCET_JAZYKOV + 1] = 
{"V�ro�ie posviacky Hlavnej mari�nskej baziliky v R�me",
 "Posv�cen� ��msk� baziliky Panny Marie",
 "",
 "",
 "",
 "Posv�cen� ��msk� baziliky Panny Marie",
 "Sz�z M�ria r�mai f�templom�nak felszentel�se (Havas Boldogasszony)",
 };
const char *text_AUG_06[POCET_JAZYKOV + 1] = 
{"Premenenie P�na",
 "Prom�n�n� P�n�",
 "",
 "",
 "",
 "Prom�n�n� P�n�",
 "Urunk Sz�nev�ltoz�sa",
 };
const char *text_AUG_07_1[POCET_JAZYKOV + 1] = 
{"Sv. Sixta II., p�pe�a, a jeho spolo�n�kov, mu�en�kov",
 "Sv. Sixta II., pape�e, a druh�, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Sixta II., pape�e, a druh�, mu�edn�k�",
 "Szent II. Szixtusz p�pa �s t�rsai v�rtan�k",
 };
const char *text_AUG_07_2[POCET_JAZYKOV + 1] = 
{"Sv. Kajet�na, k�aza",
 "Sv. Kajet�na, kn�ze",
 "",
 "",
 "",
 "Sv. Kajet�na, kn�ze",
 "Szent Kajet�n �ldoz�pap",
 };
const char *text_AUG_08[POCET_JAZYKOV + 1] = 
{"Sv. Dominika, k�aza",
 "Sv. Dominika, kn�ze",
 "",
 "",
 "",
 "Sv. Otce Dominika, kn�ze",
 "Szent Domonkos �ldoz�pap",
 };
const char *text_AUG_08_OP[POCET_JAZYKOV + 1] = 
{"Sv. Dominika, k�aza, zakladate�a rehole",
 "Sv. Dominika, kn�ze",
 "",
 "",
 "",
 "Sv. Otce Dominika, kn�ze",
 "Szent Domonkos �ldoz�pap",
 };
const char *text_AUG_09[POCET_JAZYKOV + 1] = 
{"Sv. Ter�zie Benedikty z Kr�a"HTML_LINE_BREAK"(Edity Steinovej), panny a mu�enice,"HTML_LINE_BREAK"patr�nky Eur�py", // pod�a Direkt�ria 2012, str. 178
 "Sv. Terezie Benedikty, panny a mu�ednice,"HTML_LINE_BREAK"patronky Evropy",
 "",
 "",
 "",
 "Sv. Terezie Benedikty, panny a mu�ednice,"HTML_LINE_BREAK"patronky Evropy",
 "A keresztr�l nevezett Szent Ter�z Benedikta (Edith Stein) "HTML_LINE_BREAK"sz�z �s v�rtan�, Eur�pa t�rsv�d�szentje",
 };
const char *text_AUG_10[POCET_JAZYKOV + 1] = 
{"Sv. Vavrinca, diakona a mu�en�ka",
 "Sv. Vav�ince, mu�edn�ka",
 "",
 "",
 "",
 "Sv. Vav�ince, mu�edn�ka",
 "Szent L�rinc diak�nus �s v�rtan�",
 };
const char *text_AUG_11[POCET_JAZYKOV + 1] = 
{"Sv. Kl�ry, panny",
 "Sv. Kl�ry, panny",
 "",
 "",
 "",
 "Sv. Kl�ry, panny",
 "Szent Kl�ra sz�z",
 };
const char *text_AUG_12[POCET_JAZYKOV + 1] = 
{"Sv. Jany Franti�ky de Chantal, reho�n��ky", // kedysi sa sl�vil 12. decembra
 "Sv. Jany Franti�ky de Chantal, �eholnice",
 "",
 "",
 "",
 "Sv. Jany Franti�ky de Chantal, �eholnice",
 "Chantal szent Johanna Franciska szerzetesn�",
 };
const char *text_AUG_12_1_OP[POCET_JAZYKOV + 1] = 
{"Bl. J�na zo Salerna, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_AUG_12_2_OP[POCET_JAZYKOV + 1] = 
{"Bl. Aimona Taparelliho, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_AUG_12_3_OP[POCET_JAZYKOV + 1] = 
{"Bl. J�na Juraja Rehma, k�aza a mu�en�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_AUG_13[POCET_JAZYKOV + 1] = 
{"Sv. Ponci�na, p�pe�a, a sv. Hypolita, k�aza, mu�en�kov",
 "Sv. Ponci�na, pape�e, a Hippolyta, kn�ze, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Ponci�na, pape�e, a Hippolyta, kn�ze, mu�edn�k�",
 "Szent Ponci�nusz p�pa �s szent Hippolitusz �ldoz�pap �s v�rtan�k", // HU: 16AUG
 };
const char *text_AUG_13_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Boldog XI. Ince p�pa", // HU
 };
const char *text_AUG_13_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "Bl. Gertrudy, panny z premonstr�tsk�ho ��du",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_AUG_14[POCET_JAZYKOV + 1] = 
{"Sv. Maximili�na M�rie Kolbeho, k�aza a mu�en�ka", // pod�a Direkt�ria 2012, str. 180
 "Sv. Maxmili�na Marie Kolbeho, kn�ze a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Maxmili�na Marie Kolbeho, kn�ze a mu�edn�ka",
 "Szent Maximili�n M�ria Kolbe �ldoz�pap �s v�rtan�",
 };
const char *text_AUG_15[POCET_JAZYKOV + 1] = 
{"Nanebovzatie prebl. Panny M�rie",
 "Nanebevzet� Panny Marie",
 "",
 "",
 "",
 "Nanebevzet� Panny Marie",
 "Sz�z M�ria mennybev�tele (Nagyboldogasszony)",
 };
const char *text_AUG_16[POCET_JAZYKOV + 1] = 
{"Sv. �tefana Uhorsk�ho",
 "Sv. �t�p�na Uhersk�ho",
 "",
 "",
 "",
 "Sv. �t�p�na Uhersk�ho",
 "Szent Istv�n kir�ly, Magyarorsz�g f�v�d�szentje",
 };
const char *text_AUG_17_OP[POCET_JAZYKOV + 1] = 
{"Sv. Hyacinta Po�sk�ho, k�aza",
 "",
 "",
 "",
 "",
 "Sv. Hyacinta z Polska, kn�ze",
 "",
 };
const char *text_AUG_17_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Kaposv�r: A sz�kesegyh�z felszentel�se",
 };
const char *text_AUG_18_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "V�c: A sz�kesegyh�z felszentel�se",
 };
const char *text_AUG_18_SJ[POCET_JAZYKOV + 1] = 
{"Bl. Alberta Hurtada Cruchagu, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_AUG_18_OP[POCET_JAZYKOV + 1] = 
{"Bl. Manesa, k�aza, brata sv. otca Dominika",
 "",
 "",
 "",
 "",
 "Bl. Mannesa neboli Mamesa, kn�ze, bratra sv. Otce Dominika",
 "",
 };
const char *text_AUG_19[POCET_JAZYKOV + 1] = 
{"Sv. J�na Eudes, k�aza",
 "Sv. Jana Eudese, kn�ze",
 "",
 "",
 "",
 "Sv. Jana Eudese, kn�ze",
 "Eudes Szent J�nos �ldoz�pap",
 };
const char *text_AUG_19_OP[POCET_JAZYKOV + 1] = 
{"Bl. Jord�na z Pisy, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_AUG_20[POCET_JAZYKOV + 1] = 
{"Sv. Bernarda, op�ta a u�ite�a Cirkvi",
 "Sv. Bernarda, opata a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Bernarda, opata a u�itele C�rkve",
 "Szent Bern�t ap�t �s egyh�ztan�t�", // HU 19AUG
 };
const char *text_AUG_21[POCET_JAZYKOV + 1] = 
{"Sv. Pia X., p�pe�a",
 "Sv. Pia X., pape�e",
 "",
 "",
 "",
 "Sv. Pia X., pape�e",
 "Szent X. Piusz p�pa",
 };
const char *text_AUG_22[POCET_JAZYKOV + 1] = 
{"Panny M�rie Kr�ovnej", // pod�a Direkt�ria 2012, str. 183, tam nie je 'Prebl.'
 "Panny Marie Kr�lovny",
 "",
 "",
 "",
 "Panny Marie Kr�lovny",
 "Boldogs�gos Sz�z M�ria Kir�lyn�",
 };
const char *text_AUG_23[POCET_JAZYKOV + 1] = 
{"Sv. Ru�eny Limskej, panny",
 "Sv. R��eny z Limy, panny",
 "",
 "",
 "",
 "Sv. R��eny Floresov� neboli z Limy, panny, terci��ky",
 "Limai Szent R�za sz�z",
 };
const char *text_AUG_24[POCET_JAZYKOV + 1] = 
{"Sv. Bartolomeja, apo�tola",
 "Sv. Bartolom�je, apo�tola",
 "",
 "",
 "",
 "Sv. Bartolom�je, apo�tola",
 "Szent Bertalan apostol",
 };
const char *text_AUG_25_1[POCET_JAZYKOV + 1] = 
{"Sv. Jozefa de Calasanz, k�aza",
 "Sv. Josefa Kalasansk�ho, kn�ze",
 "",
 "",
 "",
 "Sv. Josefa Kalasansk�ho, kn�ze",
 "Kalazanci Szent J�zsef �ldoz�pap",
 };
const char *text_AUG_25_2[POCET_JAZYKOV + 1] = 
{"Sv. �udov�ta",
 "Sv. Ludv�ka",
 "",
 "",
 "",
 "Sv. Ludv�ka",
 "Szent Lajos",
 };
const char *text_AUG_25_CZ[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Benedikta, Jana, Matou�e, Iz�ka a Kristina, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Benedikta, Jana, Matou�e, Iz�ka a Kristina, mu�edn�k�",
 "",
 };
const char *text_AUG_25_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Kalocsa-Kecskem�t: A f�sz�kesegyh�z felszentel�se",
 };
const char *text_AUG_26_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Zefir�na Namuncur�, mlad�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_AUG_26_OP[POCET_JAZYKOV + 1] = 
{"Bl. Jakuba z Bevagna, k�aza",
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
 "Szent M�nika",
 };
const char *text_AUG_27_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Moniky, matky na�eho otce sv. Augustina",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_AUG_28_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "Na�eho otce sv. Augustina, biskupa a u�itele c�rkve",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_AUG_28[POCET_JAZYKOV + 1] = 
{"Sv. August�na, biskupa a u�ite�a Cirkvi",
 "Sv. Augustina, biskupa a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Augustina, biskupa a u�itele C�rkve",
 "Szent �goston p�sp�k �s egyh�ztan�t�",
 };
const char *text_AUG_29[POCET_JAZYKOV + 1] = 
{"Mu�en�cka smr� sv. J�na Krstite�a",
 "Umu�en� svat�ho Jana K�titele",
 "",
 "",
 "",
 "Umu�en� svat�ho Jana K�titele",
 "Keresztel� Szent J�nos v�rtan�s�ga",
 };
const char *text_AUG_30_SK[POCET_JAZYKOV + 1] = 
{"V�ro�ie posviacky katedr�lneho chr�mu v Trnave", // ToDo: 'sv. J�na Krstite�a', pod�a Direkt�ria 2012, str. 186
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_AUG_31_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Esztergom-Budapest: A pr�m�si bazilika-"HTML_LINE_BREAK"f�sz�kesegyh�z felszentel�se",
 };
const char *text_AUG_30_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "Bl. Bronislavy, panny z premonstr�tsk�ho ��du",
 "",
 "",
 "",
 "",
 "",
 };

// --------------- 09 september ---------------

const char *text_SEP_02_1_OP[POCET_JAZYKOV + 1] = 
{"Bl. Gualu z Bergama, biskupa",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_02_2_OP[POCET_JAZYKOV + 1] = 
{"Bl. Ingridy zo Sk�nninge, reho�n��ky",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_03[POCET_JAZYKOV + 1] = 
{"Sv. Gregora Ve�k�ho, p�pe�a a u�ite�a Cirkvi",
 "Sv. �eho�e Velik�ho, pape�e a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. �eho�e Velik�ho, pape�e a u�itele C�rkve",
 "Nagy Szent Gergely p�pa �s egyh�ztan�t�",
 };
const char *text_SEP_04_OP[POCET_JAZYKOV + 1] = 
{"Bl. Katar�ny z Racconigi, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_05[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Kalkuttai Boldog Ter�z sz�z",
 };
const char *text_SEP_06_SK[POCET_JAZYKOV + 1] = 
{"V�ro�ie posviacky katedr�lneho chr�mu v Ko�iciach", // ToDo: 'sv. Al�bety', pod�a Direkt�ria 2012, str. 190
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_06_1_OP[POCET_JAZYKOV + 1] = 
{"Bl. Bertranda z Garrigue, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_06_2_OP[POCET_JAZYKOV + 1] = 
{"Bl. Michala (J�na Franti�ka) Czartorysk�ho, k�aza,"HTML_LINE_BREAK"a bl. J�lie (Stanislavy) Rodzi�skej, panny a reho�n��ky,"HTML_LINE_BREAK"mu�en�kov",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_07[POCET_JAZYKOV + 1] = 
{"Sv. Marka Kri�ina, Melichara Grodzieck�ho"HTML_LINE_BREAK"a �tefana Pongr�cza, k�azov a mu�en�kov",
 "Sv. Melichara Grodeck�ho, kn�ze a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Melichara Grodeck�ho, kn�ze a mu�edn�ka",
 "Szent M�rk, Istv�n �s Menyh�rt �ldoz�papok, kassai v�rtan�k",
 };
const char *text_SEP_07_SJ[POCET_JAZYKOV + 1] = 
{"Sv. ko�ick�ch mu�en�kov: �tefana Pongr�cza a Melichara Grodzieck�ho, k�azov Spolo�nosti Je�i�ovej; "HTML_LINE_BREAK"Marka Kri�ina, ostrihomsk�ho kanonika, patr�nov Slovenskej provincie Spolo�nosti Je�i�ovej",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_08[POCET_JAZYKOV + 1] = 
{"Narodenie Panny M�rie", // pod�a Direkt�ria 2012, str. 191, tam nie je 'prebl.'
 "Narozen� Panny Marie",
 "",
 "",
 "",
 "Narozen� Panny Marie",
 "Sz�z M�ria Sz�let�se (Kisboldogasszony)",
 };
const char *text_SEP_09[POCET_JAZYKOV + 1] = 
{"Sv. Petra Clavera, k�aza",
 "Sv. Petra Klavera, kn�ze",
 "",
 "",
 "",
 "Sv. Petra Klavera, kn�ze",
 "Claver Szent P�ter �ldoz�pap",
 };
const char *text_SEP_09_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Petra Clavera, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_10_SJ[POCET_JAZYKOV + 1] = 
{"Bl. Franti�ka G�rateho, reho�n�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_10_CZ[POCET_JAZYKOV + 1] = 
{"",
 "Bl. Karla Spinoly, kn�ze a mu�edn�ka",
 "",
 "",
 "",
 "Bl. Karla Spinoly, kn�ze a mu�edn�ka",
 "",
 };
const char *text_SEP_11_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "V�ro�� posv�cen� opatsk�ho kostela",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_12[POCET_JAZYKOV + 1] = 
{"Najsv. mena Panny M�rie", // pod�a Direkt�ria 2012, str. 192; p�vodne bolo: 'Mena prebl. Panny M�rie'
 "Jm�na Panny Marie",
 "",
 "",
 "",
 "Jm�na Panny Marie",
 "Sz�z M�ria Szent Neve",
 };
const char *text_SEP_12_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "Nejsv�t�j��ho jm�na Panny Marie",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_13[POCET_JAZYKOV + 1] = 
{"Sv. J�na Zlato�steho, biskupa a u�ite�a Cirkvi",
 "Sv. Jana Zlato�st�ho, biskupa a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Jana Zlato�st�ho, biskupa a u�itele c�rkve",
 "Aranysz�j� (Krizosztomosz) Szent J�nos p�sp�k �s egyh�ztan�t�",
 };
const char *text_SEP_13_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Gy�r: A sz�kesegyh�z felszentel�se",
 };
const char *text_SEP_14[POCET_JAZYKOV + 1] = 
{"Pov��enie sv�t�ho kr�a",
 "Pov��en� svat�ho k��e",
 "",
 "",
 "",
 "Pov��en� svat�ho k��e",
 "A Szent Kereszt felmagasztal�sa",
 };
const char *text_SEP_15[POCET_JAZYKOV + 1] = 
{"Sedembolestnej Panny M�rie, patr�nky Slovenska",
 "Panny Marie Bolestn�",
 "",
 "",
 "",
 "Panny Marie Bolestn�",
 "A F�jdalmas Sz�zanya",
 };
const char *text_SEP_16_CZ[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Ludmily, mu�ednice",
 "",
 "",
 "",
 "Sv. Ludmily, mu�ednice",
 "",
 };
const char *text_SEP_16[POCET_JAZYKOV + 1] = 
{"Sv. Korn�lia, p�pe�a, a sv. Cypri�na, biskupa, mu�en�kov",
 "Sv. Korn�lia, pape�e, a Cypri�na, biskupa, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Korn�lia, pape�e, a Cypri�na, biskupa, mu�edn�k�",
 "Szent Korn�l p�pa �s Szent Cipri�n p�sp�k �s v�rtan�k",
 };
const char *text_SEP_17[POCET_JAZYKOV + 1] = 
{"Sv. R�berta Bellarm�na, biskupa a u�ite�a Cirkvi",
 "Sv. Roberta Bellarmina, biskupa a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Roberta Bellarmina, biskupa a u�itele C�rkve",
 "Bellarmin Szent R�bert p�sp�k �s egyh�ztan�t�",
 };
const char *text_SEP_17_SJ[POCET_JAZYKOV + 1] = 
{"Sv. R�berta Bellarmina, biskupa a u�ite�a Cirkvi",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_18_OP[POCET_JAZYKOV + 1] = 
{"Sv. J�na Mac�asa, reho�n�ka",
 "",
 "",
 "",
 "",
 "Sv. Jana Maciase, �eholn�ka",
 "",
 };
const char *text_SEP_19[POCET_JAZYKOV + 1] = 
{"Sv. Janu�ra, biskupa a mu�en�ka",
 "Sv. Janu�ria, biskupa a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Janu�ria, biskupa a mu�edn�ka",
 "Szent Janu�riusz p�sp�k �s v�rtan�",
 };
const char *text_SEP_20[POCET_JAZYKOV + 1] = 
{"Sv. Andreja Kim Taegona, k�aza,"HTML_LINE_BREAK"a sv. Pavla Chong Hasanga a spolo�n�kov, mu�en�kov",
 "Sv. Ond�eje Kim Taegona, kn�ze, Pavla Chong Hasanga a druh�, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Ond�eje Kim Taegona, kn�ze, Pavla Chong Hasanga a druh�, mu�edn�k�",
 "Kim Taegon Szent Andr�s �ldoz�pap, Csong Haszang Szent P�l �s t�rsaik, v�rtan�k",
 };
const char *text_SEP_20_CZ[POCET_JAZYKOV + 1] = 
{"",
 "V�ro�� posv�cen� katedr�ly sv. �t�p�na",
 "",
 "",
 "",
 "V�ro�� posv�cen� katedr�ly sv. �t�p�na",
 "",
 };
const char *text_SEP_21[POCET_JAZYKOV + 1] = 
{"Sv. Mat��a, apo�tola a evanjelistu",
 "Sv. Matou�e, apo�tola a evangelisty",
 "",
 "",
 "",
 "Sv. Matou�e, apo�tola a evangelisty",
 "Szent M�t� apostol �s evangelista",
 };
const char *text_SEP_22[POCET_JAZYKOV + 1] = 
{"Sv. Emer�ma, biskupa a mu�en�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_22_1_OP[POCET_JAZYKOV + 1] = 
{"Bl. Franti�ka de Posadas, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_22_2_OP[POCET_JAZYKOV + 1] = 
{"Bl. Hyacinta Serrana L�peza, k�aza, a spolo�n�kov, mu�en�kov",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_22_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Jozefa Calasanza a Enrica Saiz Aparicio, k�azov, "HTML_LINE_BREAK"a 93 spolo�n�kov, mu�en�kov",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_23[POCET_JAZYKOV + 1] = 
{"Sv. Pia z Pietrel�iny, k�aza",
 "Sv. Pia z Pietrelciny, kn�ze",
 "",
 "",
 "",
 "Sv. Pia z Pietrelciny, kn�ze",
 "Pietrelcinai Szent Pio �ldoz�pap",
 };
const char *text_SEP_24_SK[POCET_JAZYKOV + 1] = 
{"V�ro�ie posviacky katedr�lneho chr�mu v Banskej Bystrici", // ToDo: 'sv. Franti�ka Xaversk�ho', pod�a Direkt�ria 2012, str. 198
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_24_OP[POCET_JAZYKOV + 1] = 
{"Bl. Dalm�ca Monera, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_24_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Szent Gell�rt p�sp�k �s v�rtan�",
 };
const char *text_SEP_25_OP[POCET_JAZYKOV + 1] = 
{"Bl. Dalm�ca Monera, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_26[POCET_JAZYKOV + 1] = 
{"Sv. Kozmu a Dami�na, mu�en�kov",
 "Sv. Kosmy a Dami�na, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Kosmy a Dami�na, mu�edn�k�",
 "Szent Kozma �s Damj�n v�rtan�k",
 };
const char *text_SEP_26_CSSR[POCET_JAZYKOV + 1] = 
{"Bl. Ga�para Stanggassingera, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_26_OP[POCET_JAZYKOV + 1] = 
{"Bl. Vavrinca z Ripafratta, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_SEP_27[POCET_JAZYKOV + 1] = 
{"Sv. Vincenta de Paul, k�aza",
 "Sv. Vincence z Paula, kn�ze",
 "",
 "",
 "",
 "Sv. Vincence z Paula, kn�ze",
 "P�li Szent Vince �ldoz�pap",
 };
const char *text_SEP_28[POCET_JAZYKOV + 1] = 
{"Sv. V�clava, mu�en�ka",
 "Sv. V�clava, mu�edn�ka, hlavn�ho patrona �esk�ho n�roda",
 "",
 "",
 "",
 "Sv. V�clava, mu�edn�ka, hlavn�ho patrona �esk�ho n�roda, hlavn�ho patrona provincie",
 "Szent Vencel v�rtan�",
 };
const char *text_SEP_28_2[POCET_JAZYKOV + 1] = 
{"Sv. Vavrinca Ruiza a spolo�n�kov, mu�en�kov",
 "",
 "",
 "",
 "",
 "",
 "Ruiz Szent L�rinc �s t�rsai, F�l�p-szigeteki v�rtan�k",
 };
const char *text_SEP_28_OP[POCET_JAZYKOV + 1] = 
{"Sv. Vavrinca Ruiza z Manily, laika, a spolo�n�kov, mu�en�kov",
 "",
 "",
 "",
 "",
 "Sv. Dominika Iban�ze z Erquicia, Jakuba Kyu�ei Tomonagy, kn��,"HTML_LINE_BREAK"Vav�ince Ruize, otce rodiny, a druh�, japonsk�ch mu�edn�k�", // CZOP kv�li sv. V�clavovi sl�via 26SEP
 "",
 };
const char *text_SEP_29[POCET_JAZYKOV + 1] = 
{"Sv. Michala, Gabriela a Rafaela, archanjelov",
 "Sv. Michaela, Gabriela a Rafaela, archand�l�",
 "",
 "",
 "",
 "Sv. Michaela, Gabriela a Rafaela, archand�l�",
 "Szent Mih�ly, Szent G�bor �s Szent Rafael f�angyalok",
 };
const char *text_SEP_30[POCET_JAZYKOV + 1] = 
{"Sv. Hieronyma, k�aza a u�ite�a Cirkvi",
 "Sv. Jeron�ma, kn�ze a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Jeron�ma, kn�ze a u�itele C�rkve",
 "Szent Jeromos �ldoz�pap �s egyh�ztan�t�",
 };

// --------------- 10 okt�ber ---------------

const char *text_OKT_01[POCET_JAZYKOV + 1] = 
{"Sv. Ter�zie z Lisieux, panny a u�ite�ky Cirkvi",
 "Sv. Terezie od D�t�te Je��e, panny",
 "",
 "",
 "",
 "Sv. Terezie od D�t�te Je��e, panny",
 "A Gyermek J�zusr�l nevezett (Lisieux-i) Szent Ter�z Sz�z",
 };
const char *text_OKT_02[POCET_JAZYKOV + 1] = 
{"Sv�t�ch anjelov str�cov",
 "Svat�ch and�l� str�n�ch",
 "",
 "",
 "",
 "Svat�ch and�l� str�n�ch",
 "Szent �rz�angyalok",
 };
const char *text_OKT_03_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Franti�ka de Borja, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_03_OP[POCET_JAZYKOV + 1] = 
{"Bl. Dominika Spadaforu, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_04[POCET_JAZYKOV + 1] = 
{"Sv. Franti�ka Assisk�ho",
 "Sv. Franti�ka z Assisi",
 "",
 "",
 "",
 "Sv. Franti�ka z Assisi, j�hna",
 "Assisi Szent Ferenc",
 };
const char *text_OKT_04_OP[POCET_JAZYKOV + 1] = 
{"Sv. Franti�ka Assisk�ho, diakona",
 "",
 "",
 "",
 "",
 "Sv. Franti�ka z Assisi, j�hna",
 "",
 };
const char *text_OKT_05_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Alberta Marvelliho",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_05_CSSR[POCET_JAZYKOV + 1] = 
{"Bl. Franti�ka Xaversk�ho Seelosa, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_05_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Veszpr�m: A bazilika-f�sz�kesegyh�z felszentel�se",
 };
const char *text_OKT_05_OP[POCET_JAZYKOV + 1] = 
{"Bl. Rajmunda z Kapuy, k�aza",
 "",
 "",
 "",
 "",
 "Bl. Rajmunda delle Vigne neboli z Kapuy, kn�ze",
 "",
 };
const char *text_OKT_06[POCET_JAZYKOV + 1] = 
{"Sv. Bruna, k�aza",
 "Sv. Bruna, kn�ze",
 "",
 "",
 "",
 "Sv. Bruna, kn�ze",
 "Szent Br�n� �ldoz�pap",
 };
const char *text_OKT_06_SJ[POCET_JAZYKOV + 1] = 
{"Bl. Diega Alojza de san Vitores, k�aza a mu�en�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_06_OP[POCET_JAZYKOV + 1] = 
{"Bl. Bartolomeja Longu, laika",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_07[POCET_JAZYKOV + 1] = 
{"Ru�encovej Panny M�rie", // pod�a Direkt�ria 2012, str. 206, nie je 'prebl.'
 "Panny Marie R��encov�",
 "",
 "",
 "",
 "Panny Marie R��encov�",
 "R�zsaf�z�r Kir�lyn�je",
 };
const char *text_OKT_07_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "V�ro�� posv�cen� opatsk�ho kostela",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_08_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Sz�z M�ria, Magyarok nagyaszszonya, Magyarorsz�g f�p�tron�ja",
 };
const char *text_OKT_08_1_OP[POCET_JAZYKOV + 1] = 
{"Bl. Ambr�za Sansedoniho, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_08_2_OP[POCET_JAZYKOV + 1] = 
{"Bl. Mat��a Carreriho, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_09_1[POCET_JAZYKOV + 1] = 
{"Sv. Dion�zia, biskupa, a spolo�n�kov, mu�en�kov",
 "Sv. Dion�sia, biskupa, a druh�, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Dion�sia, biskupa, a druh�, mu�edn�k�",
 "Szent D�nes p�sp�k �s t�rsai v�rtan�k",
 };
const char *text_OKT_09_2[POCET_JAZYKOV + 1] = 
{"Sv. J�na Leonardiho, k�aza",
 "Sv. Jana Leonardiho, kn�ze",
 "",
 "",
 "",
 "Sv. Jana Leonardiho, kn�ze",
 "Leonardi Szent J�nos �ldoz�pap",
 };
const char *text_OKT_09_OP[POCET_JAZYKOV + 1] = 
{"Sv. �udov�ta Bertr�na, k�aza",
 "",
 "",
 "",
 "",
 "Sv. Ludv�ka Bertr�na, kn�ze",
 "",
 };
const char *text_OKT_10_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Gereona a druh�, mu�edn�k�",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_11[POCET_JAZYKOV + 1] = 
{"Bl. J�na XXIII., p�pe�a",
 "",
 "",
 "",
 "",
 "",
 "Boldog XXIII. J�nos p�pa",
 };
const char *text_OKT_11_SK[POCET_JAZYKOV + 1] = 
{"V�ro�ie posviacky katedr�lneho chr�mu v �iline", // ToDo: 'Najsv�tej�ej Trojice', pod�a Direkt�ria 2012, str. 207
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_11_OP[POCET_JAZYKOV + 1] = 
{"Bl. Jakuba z Ulmu, reho�n�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_12_CZ[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Radima, biskupa",
 "",
 "",
 "",
 "Sv. Radima, biskupa",
 "",
 };
const char *text_OKT_13_OP[POCET_JAZYKOV + 1] = 
{"Bl. Magdal�ny Panatieriovej, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_13_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Alexandry M�rie da Costovej",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_13_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "Bl. Petra Adri�na Toulorge, kn�ze a mu�edn�ka "HTML_LINE_BREAK"z premonstr�tsk�ho ��du",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_14[POCET_JAZYKOV + 1] = 
{"Sv. Kalixta I., p�pe�a a mu�en�ka",
 "Sv. Kalista I., pape�e a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Kalista I., pape�e a mu�edn�ka",
 "Szent I. Kallixtusz p�pa �s v�rtan�",
 };
const char *text_OKT_14_SJ[POCET_JAZYKOV + 1] = 
{"Sv. J�na Ogilvieho, k�aza a mu�en�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_14_OP[POCET_JAZYKOV + 1] = 
{"Bl. M�rie Poussepinovej, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_15[POCET_JAZYKOV + 1] = 
{"Sv. Ter�zie od Je�i�a, panny a u�ite�ky Cirkvi", // 'z Avily' upraven� pod�a Direkt�ria 2012, str. 209
 "Sv. Terezie od Je��e, panny a u�itelky c�rkve",
 "",
 "",
 "",
 "Sv. Terezie od Je��e, panny a u�itelky C�rkve",
 "A J�zusr�l nevezett (Avilai) Szent Ter�z sz�z �s egyh�ztan�t�",
 };
const char *text_OKT_16_1[POCET_JAZYKOV + 1] = 
{"Sv. Margity M�rie Alacoque, panny",
 "Sv. Mark�ty Marie Alacoque, panny",
 "",
 "",
 "",
 "Sv. Mark�ty Marie Alacoque, panny",
 "Alacoque Szent Margit M�ria sz�z",
 };
const char *text_OKT_16_2[POCET_JAZYKOV + 1] = 
{"Sv. Hedvigy, reho�n��ky",
 "Sv. Hedviky, �eholnice, hlavn� patronky Slezska",
 "",
 "",
 "",
 "Sv. Hedviky, �eholnice, hlavn� patronky Slezska",
 "Szent Hedvig szerzetesn�",
 };
const char *text_OKT_16_CSSR[POCET_JAZYKOV + 1] = 
{"Sv. Gerarda Majellu, reho�n�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_17[POCET_JAZYKOV + 1] = 
{"Sv. Ign�ca Antiochijsk�ho, biskupa a mu�en�ka",
 "Sv. Ign�ce Antiochijsk�ho, biskupa a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Ign�ce Antiochijsk�ho, biskupa a mu�edn�ka",
 "Antiochiai Szent Ign�c p�sp�k �s v�rtan�",
 };
const char *text_OKT_18[POCET_JAZYKOV + 1] = 
{"Sv. Luk�a, evanjelistu",
 "Sv. Luk�e, evangelisty",
 "",
 "",
 "",
 "Sv. Luk�e, evangelisty",
 "Szent Luk�cs evangelista",
 };
const char *text_OKT_19_1[POCET_JAZYKOV + 1] = 
{"Sv. J�na de Br�beuf a Iz�ka Jogues, k�azov,"HTML_LINE_BREAK"a spolo�n�kov, mu�en�kov", //  // 'sv. Iz�ka', pod�a Direkt�ria 2012, str. 210 nie je 'sv.'
 "Sv. Jana de Br�beuf a Iz�ka Joguese, kn��, a druh�, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Jana de Br�beuf a Iz�ka Joguese, kn��, a druh�, mu�edn�k�",
 "De Br�beuf Szent J�nos �s Jogues Szent Izs�k �ldoz�pap �s t�rsaik v�rtan�k",
 };
const char *text_OKT_19_2[POCET_JAZYKOV + 1] = 
{"Sv. Pavla z Kr�a, k�aza",
 "Sv. Pavla od K��e, kn�ze",
 "",
 "",
 "",
 "Sv. Pavla od K��e, kn�ze",
 "Keresztes Szent P�l �ldoz�pap",
 };
const char *text_OKT_19_SJ[POCET_JAZYKOV + 1] = 
{"Sv. J�na de Br�beuf, Iz�ka Joguesa, k�azov, a spolo�n�kov, mu�en�kov",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_19_OP[POCET_JAZYKOV + 1] = 
{"Bl. Agnesy Galandovej de Langeac, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_20_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Jakuba Kerna, kn�ze z premonstr�tsk�ho ��du",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_21_CZ[POCET_JAZYKOV + 1] = 
{"",
 "Bl. Karla Rakousk�ho",
 "",
 "",
 "",
 "Bl. Karla Rakousk�ho",
 "",
 };
const char *text_OKT_21_OP[POCET_JAZYKOV + 1] = 
{"Bl. Petra z Citt&agrave; di Castello, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_22_OP[POCET_JAZYKOV + 1] = 
{"V�ro�ie posviacky konventn�ho kostola,"HTML_LINE_BREAK"ktor�ho de� posviacky nie je zn�my",
 "",
 "",
 "",
 "",
 "V�ro�� posv�cen� kl�tern�ho kostela",
 "",
 };
const char *text_OKT_22[POCET_JAZYKOV + 1] = 
{"",
 "Bl. Jana Pavla II., pape�e",
 "",
 "",
 "",
 "Bl. Jana Pavla II., pape�e",
 "Boldog II. J�nos P�l p�pa",
 };
const char *text_OKT_23[POCET_JAZYKOV + 1] = 
{"Sv. J�na Kapistr�nskeho, k�aza",
 "Sv. Jana Kapistr�nsk�ho, kn�ze",
 "",
 "",
 "",
 "Sv. Jana Kapistr�nsk�ho, kn�ze",
 "Kapisztr�n Szent J�nos �ldoz�pap",
 };
const char *text_OKT_24[POCET_JAZYKOV + 1] = 
{"Sv. Antona M�rie Clareta, biskupa",
 "Sv. Anton�na Marie Klareta, biskupa",
 "",
 "",
 "",
 "Sv. Anton�na Marie Klareta, biskupa",
 "Claret Szent Antal M�ria p�sp�k",
 };
const char *text_OKT_24_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Alojza Guanellu, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_24_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "A Sz�kesegyh�z felszentel�se",
 };
const char *text_OKT_25_SK[POCET_JAZYKOV + 1] = 
{"V�ro�ie posviacky katedr�lneho chr�mu v Spi�skom Podhrad�", // ToDo: 'sv. Martina z Tours', pod�a Direkt�ria 2012, str. 213
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_25_SDB[POCET_JAZYKOV + 1] = 
{"V�ro�ie posviacky vlastn�ho chr�mu (ke� sa nepozn� d�tum posviacky)",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_25_OP[POCET_JAZYKOV + 1] = 
{"Bl. Petra Geremiu, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_25_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Szent M�r p�sp�k",
 };
const char *text_OKT_26[POCET_JAZYKOV + 1] = 
{"V�ro�ie posviacky chr�mov,"HTML_LINE_BREAK"ktor�ch de� posviacky nie je zn�my",  // 'je nezn�my' opraven� pod�a Direkt�ria 2012, str. 214
 "V�ro�� posv�cen� chr�mu,"HTML_LINE_BREAK"jejich� den dedikace nen� zn�m�",
 "",
 "",
 "",
 "V�ro�� posv�cen� chr�mu,"HTML_LINE_BREAK"jejich� den dedikace nen� zn�m�",
 "A saj�t templom felszentel�se "HTML_LINE_BREAK"(amennyiben annak napja nem ismeretes)", // A felszentelt templomokban: A saj�t templom felszentel�se
 };
const char *text_OKT_26_OP[POCET_JAZYKOV + 1] = 
{"Bl. Dami�na z Finale, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_26_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Gilberta, opata z premonstr�tsk�ho ��du",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_27_SK[POCET_JAZYKOV + 1] = 
{"V�ro�ie posviacky katedr�lneho chr�mu v Ro��ave", // ToDo: 'Nanebovzatia Panny M�rie', pod�a Direkt�ria 2012, str. 214
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_27_OP[POCET_JAZYKOV + 1] = 
{"Bl. Bartolomeja z Vicenze, biskupa",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_28[POCET_JAZYKOV + 1] = 
{"Sv. �imona a J�du, apo�tolov",
 "Sv. �imona a Judy, apo�tol�",
 "",
 "",
 "",
 "Sv. �imona a Judy, apo�tol�",
 "Szent Simon �s Szent J�d�s apostol",
 };
const char *text_OKT_29_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Michala Ruu, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_29_CZ[POCET_JAZYKOV + 1] = 
{"",
 "Bl. Marie Restituty Kafkov�, panny a mu�ednice",
 "",
 "",
 "",
 "Bl. Marie Restituty Kafkov�, panny a mu�ednice",
 "",
 };
const char *text_OKT_30_SJ[POCET_JAZYKOV + 1] = 
{"Bl. Dominika Collinsa, mu�en�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_30_1_OP[POCET_JAZYKOV + 1] = 
{"Bl. Benvenuty Boianiovej, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_30_2_OP[POCET_JAZYKOV + 1] = 
{"Bl. Terenca Alberta O�Brien, biskupa,"HTML_LINE_BREAK"a bl. Petra Higginsa, k�aza, mu�en�kov",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_30_CZ[POCET_JAZYKOV + 1] = 
{"",
 "V�ro�� posv�cen� katedr�ly Svat�ho Ducha",
 "",
 "",
 "",
 "V�ro�� posv�cen� katedr�ly Svat�ho Ducha",
 "",
 };
const char *text_OKT_31_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Alfonza Rodr�gueza, reho�n�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_OKT_31_CZ[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Wolfganga, biskupa",
 "",
 "",
 "",
 "Sv. Wolfganga, biskupa",
 "",
 };
const char *text_OKT_31_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Boldog Romzsa T�dor p�sp�k �s v�rtan�",
 };

// --------------- 11 november ---------------

const char *text_NOV_01[POCET_JAZYKOV + 1] = 
{"V�etk�ch sv�t�ch",
 "V�ech svat�ch",
 "",
 "",
 "",
 "V�ech svat�ch",
 "Mindenszentek",
 };
const char *text_NOV_02[POCET_JAZYKOV + 1] = 
{"Spomienka na v�etk�ch vern�ch zosnul�ch", // pod�a Direkt�ria 2012, str. 218
 "Vzpom�nka na v�echny v�rn� zem�el�",
 "",
 "",
 "",
 "Vzpom�nka na v�echny v�rn� zem�el�",
 "Halottak napja",
 };
const char *text_NOV_03[POCET_JAZYKOV + 1] = 
{"Sv. Martina Porres, reho�n�ka", // 'de Porres': pod�a Direkt�ria 2012, str. 218, nie je 'de'
 "Sv. Martina de Porres, �eholn�ka",
 "",
 "",
 "",
 "Sv. Martina de Porres, �eholn�ka",
 "Porres Szent M�rton szerzetes",
 };
const char *text_NOV_03_SJ[POCET_JAZYKOV + 1] = 
{"Bl. Ruperta Mayera, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_04[POCET_JAZYKOV + 1] = 
{"Sv. Karola Borromea, biskupa",
 "Sv. Karla Boromejsk�ho, biskupa",
 "",
 "",
 "",
 "Sv. Karla Boromejsk�ho, biskupa",
 "Borromeo Szent K�roly p�sp�k",
 };
const char *text_NOV_05_SK[POCET_JAZYKOV + 1] = 
{"Sv. Imricha",
 "",
 "",
 "",
 "",
 "",
 "Szent Imre herceg",
 };
const char *text_NOV_05_SJ[POCET_JAZYKOV + 1] = 
{"V�etk�ch sv�t�ch a blahoslaven�ch zo Spolo�nosti Je�i�ovej",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_05_SDB[POCET_JAZYKOV + 1] = 
{"V�etk�ch zomrel�ch dobrodincov Salezi�nskej rodiny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_05_OP[POCET_JAZYKOV + 1] = 
{"Bl. �imona Ballacchiho, reho�n�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_06_OP[POCET_JAZYKOV + 1] = 
{"Bl. Alfonza de Navarrete, k�aza, a spolo�n�kov, mu�en�kov",
 "",
 "",
 "",
 "",
 "Sv. Alfonse Navarrety, kn�ze a druh�, japonsk�ch mu�edn�k�",
 "",
 };
const char *text_NOV_07_OP[POCET_JAZYKOV + 1] = 
{"V�etk�ch sv�t�ch Rehole kazate�ov",
 "",
 "",
 "",
 "",
 "V�ech svat�ch ��du brat�� kazatel�",
 "",
 };
const char *text_NOV_08_OP[POCET_JAZYKOV + 1] = 
{"Spomienka na v�etk�ch zosnul�ch"HTML_LINE_BREAK"bratov a sestry Rehole kazate�ov",
 "",
 "",
 "",
 "",
 "V�ech zem�el�ch brat�� a sester"HTML_LINE_BREAK"��du brat�� kazatel�",
 "",
 };
const char *text_NOV_08_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "V�ech svat�ch premonstr�tsk�ho ��du "HTML_LINE_BREAK"a v�ech svat�ch z ��d� �eholn�ch kanovn�k�",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_09[POCET_JAZYKOV + 1] = 
{"V�ro�ie posviacky Later�nskej baziliky",
 "Posv�cen� later�nsk� baziliky",
 "",
 "",
 "",
 "Posv�cen� later�nsk� baziliky",
 "A later�ni-bazilika felszentel�se",
 };
const char *text_NOV_10[POCET_JAZYKOV + 1] = 
{"Sv. Leva Ve�k�ho, p�pe�a a u�ite�a Cirkvi",
 "Sv. Lva Velik�ho, pape�e a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Lva Velik�ho, pape�e a u�itele c�rkve",
 "Nagy Szent Le� p�pa �s egyh�ztan�t�",
 };
const char *text_NOV_11[POCET_JAZYKOV + 1] = 
{"Sv. Martina z Tours, biskupa",
 "Sv. Martina, biskupa",
 "",
 "",
 "",
 "Sv. Martina, biskupa",
 "Tours-i Szent M�rton p�sp�k",
 };
const char *text_NOV_12[POCET_JAZYKOV + 1] = 
{"Sv. Jozaf�ta, biskupa a mu�en�ka",
 "Sv. Josafata, biskupa a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Josafata, biskupa a mu�edn�ka",
 "Szent Jozaf�t p�sp�k �s v�rtan�",
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
{"Sv. Stanislava Kostku, reho�n�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_13_CZ[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Ane�ky �esk�, panny",
 "",
 "",
 "",
 "Sv. Ane�ky �esk�, panny",
 "",
 };
const char *text_NOV_13_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "Magyar szentek �s boldogok",
 };
const char *text_NOV_14_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Jozefa Pignatelliho, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_14_OPRAEM[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Siarda, opata z premonstr�tsk�ho ��du",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_14_1_OP[POCET_JAZYKOV + 1] = 
{"Bl. J�na Licciu, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_14_2_OP[POCET_JAZYKOV + 1] = 
{"Bl. Lucie z Narni, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_15[POCET_JAZYKOV + 1] = 
{"Sv. Alberta Ve�k�ho, biskupa a u�ite�a Cirkvi",
 "Sv. Alberta Velik�ho, biskupa a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Alberta Velik�ho, biskupa a u�itele C�rkve",
 "Nagy Szent Albert p�sp�k �s egyh�ztan�t�",
 };
const char *text_NOV_15_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Magdal�ny Moranovej, panny",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_16_1[POCET_JAZYKOV + 1] = 
{"Sv. Margity �k�tskej",
 "Sv. Mark�ty Skotsk�",
 "",
 "",
 "",
 "Sv. Mark�ty Skotsk�",
 "Sk�ciai Szent Margit",
 };
const char *text_NOV_16_2[POCET_JAZYKOV + 1] = 
{"Sv. Gertr�dy, panny",
 "Sv. Gertrudy, panny",
 "",
 "",
 "",
 "Sv. Gertrudy, panny",
 "Nagy Szent Gertr�d sz�z", // HU 17NOV
 };
const char *text_NOV_16_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Rocha Gonz�leza, Alfonza Rodr�gueza a J�na del Castillo, k�azov a mu�en�kov",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_17[POCET_JAZYKOV + 1] = 
{"Sv. Al�bety Uhorskej, reho�n��ky",
 "Sv. Al�b�ty Uhersk�, �eholnice",
 "",
 "",
 "",
 "Sv. Al�b�ty Uhersk�, �eholnice",
 "�rp�d-h�zi Szent Erzs�bet", // HU 19NOV
 };
const char *text_NOV_18[POCET_JAZYKOV + 1] = 
{"V�ro�ie posviacky bazil�k sv. Petra a sv. Pavla, apo�tolov",
 "Posv�cen� ��msk�ch bazilik svat�ch apo�tol� Petra a Pavla",
 "",
 "",
 "",
 "Posv�cen� ��msk�ch bazilik svat�ch apo�tol� Petra a Pavla",
 "Szent P�ter- �s Szent P�l-bazilik�k felszentel�se",
 };
const char *text_NOV_19_OP[POCET_JAZYKOV + 1] = 
{"Bl. Jakuba Benfattiho, biskupa",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_20_SK[POCET_JAZYKOV + 1] = 
{"V�ro�ie posviacky katedr�lneho chr�mu v Nitre", // ToDo: 'sv. Emer�ma', pod�a Direkt�ria 2012, str. 226
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_21[POCET_JAZYKOV + 1] = 
{"Obetovanie Panny M�rie", // pod�a Direkt�ria 2012, str. 226, nie je 'prebl.'
 "Zasv�cen� Panny Marie v Jeruzal�m�",
 "",
 "",
 "",
 "Zasv�cen� Panny Marie v Jeruzal�m�",
 "A Boldogs�gos Sz�z M�ria bemutat�sa a templomban",
 };
const char *text_NOV_22[POCET_JAZYKOV + 1] = 
{"Sv. Cec�lie, panny a mu�enice",
 "Sv. Cecilie, panny a mu�ednice",
 "",
 "",
 "",
 "Sv. Cecilie, panny a mu�ednice",
 "Szent Cec�lia sz�z �s v�rtan�",
 };
const char *text_NOV_23_1[POCET_JAZYKOV + 1] = 
{"Sv. Klementa I. p�pe�a a mu�en�ka",
 "Sv. Klementa I., pape�e a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Klementa I., pape�e a mu�edn�ka",
 "Szent I. Kelemen p�pa �s v�rtan�",
 };
const char *text_NOV_23_2[POCET_JAZYKOV + 1] = 
{"Sv. Kolumb�na, op�ta",
 "Sv. Kolumb�na, opata",
 "",
 "",
 "",
 "Sv. Kolumb�na, opata",
 "Szent Kolumb�n ap�t",
 };
const char *text_NOV_23_SJ[POCET_JAZYKOV + 1] = 
{"Bl. Michala August�na Pro, k�aza a mu�en�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_24[POCET_JAZYKOV + 1] = 
{"Sv. Ondreja Dung-Laka, k�aza,"HTML_LINE_BREAK"a spolo�n�kov, mu�en�kov",
 "Sv. Ond�eje Dung-Laca, kn�ze, a druh�, mu�edn�k�",
 "",
 "",
 "",
 "Sv. Ign�ce Delgada, biskupa, Vincence Liema, kn�ze, "HTML_LINE_BREAK"Dominika An-Khama, otce rodiny, a druh�, vietnamsk�ch mu�edn�k�",
 "Dung-Lac Szent Andr�s �ldoz�pap �s t�rsai v�rtan�k",
 };
const char *text_NOV_24_OP[POCET_JAZYKOV + 1] = 
{"Sv. Ign�ca Klementa Delgadu, biskupa, "HTML_LINE_BREAK"Vincenta Le Quang Liem a Pace, k�aza, "HTML_LINE_BREAK"Dominika Pham Trong (An) Khama, laika, "HTML_LINE_BREAK"a spolo�n�kov, mu�en�kov",
 "Sv. Ign�ce Delgada, biskupa, Vincence Liema, kn�ze, "HTML_LINE_BREAK"Dominika An-Khama, otce rodiny, a druh�, vietnamsk�ch mu�edn�k�",
 "",
 "",
 "",
 "Sv. Ign�ce Delgada, biskupa, Vincence Liema, kn�ze, "HTML_LINE_BREAK"Dominika An-Khama, otce rodiny, a druh�, vietnamsk�ch mu�edn�k�",
 "",
 };
const char *text_NOV_25[POCET_JAZYKOV + 1] = 
{"Sv. Katar�ny Alexandrijskej, panny a mu�enice",
 "Sv. Kate�iny Alexandrijsk�, panny a mu�ednice",
 "",
 "",
 "",
 "Sv. Kate�iny Alexandrijsk�, panny a mu�ednice",
 "Alexandriai Szent Katalin sz�z �s v�rtan�",
 };
const char *text_NOV_25_HU[POCET_JAZYKOV + 1] = 
{"",
 "",
 "",
 "",
 "",
 "",
 "A bazilika-sz�kesegyh�z felszentel�se",
 };
const char *text_NOV_25_SDB[POCET_JAZYKOV + 1] = 
{"V�etk�ch zomrel�ch rodi�ov salezi�nov",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_26_SJ[POCET_JAZYKOV + 1] = 
{"Sv. J�na Berchmansa, reho�n�ka",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_27_OP[POCET_JAZYKOV + 1] = 
{"Bl. Margity Savojskej, matky rodiny a reho�n��ky",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_NOV_30[POCET_JAZYKOV + 1] = 
{"Sv. Ondreja, apo�tola",
 "Sv. Ond�eje, apo�tola",
 "",
 "",
 "",
 "Sv. Ond�eje, apo�tola",
 "Szent Andr�s apostol",
 };

// --------------- 12 december ---------------

const char *text_DEC_01_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Edmunda Campiona, R�berta Southwella a ich spolo�n�kov, mu�en�kov",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_DEC_01_OP[POCET_JAZYKOV + 1] = 
{"Bl. J�na Vercellsk�ho, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_DEC_01_CZ[POCET_JAZYKOV + 1] = 
{"",
 "Sv. Edmunda Kampi�na, kn�ze a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Edmunda Kampi�na, kn�ze a mu�edn�ka",
 "",
 };
const char *text_DEC_02_CZ[POCET_JAZYKOV + 1] = 
{"",
 "V�ro�� posv�cen� katedr�ly sv. Bartolom�je",
 "",
 "",
 "",
 "V�ro�� posv�cen� katedr�ly sv. Bartolom�je",
 "",
 };
const char *text_DEC_03[POCET_JAZYKOV + 1] = 
{"Sv. Franti�ka Xaversk�ho, k�aza",
 "Sv. Franti�ka Xaversk�ho, kn�ze",
 "",
 "",
 "",
 "Sv. Franti�ka Xaversk�ho, kn�ze",
 "Xav�ri Szent Ferenc �ldoz�pap",
 };
const char *text_DEC_03_SJ[POCET_JAZYKOV + 1] = 
{"Sv. Franti�ka Xav�rskeho, mision�ra",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_DEC_04[POCET_JAZYKOV + 1] = 
{"Sv. J�na Damasc�nskeho, k�aza a u�ite�a Cirkvi",
 "Sv. Jana Dama�sk�ho, kn�ze a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Jana Dama�sk�ho, kn�ze a u�itele C�rkve",
 "Damaszkuszi Szent J�nos �ldoz�pap �s egyh�ztan�t�",
 };
const char *text_DEC_05_SDB[POCET_JAZYKOV + 1] = 
{"Bl. Filipa Rinaldiho, k�aza, "HTML_LINE_BREAK"zakladate�a Sekul�rneho in�tit�tu dobrovo�n��ok dona Bosca",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_DEC_06[POCET_JAZYKOV + 1] = 
{"Sv. Mikul�a, biskupa",
 "Sv. Mikul�e, biskupa",
 "",
 "",
 "",
 "Sv. Mikul�e, biskupa",
 "Szent Mikl�s p�sp�k",
 };
const char *text_DEC_07[POCET_JAZYKOV + 1] = 
{"Sv. Ambr�za, biskupa a u�ite�a Cirkvi",
 "Sv. Ambro�e, biskupa a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Ambro�e, biskupa a u�itele C�rkve",
 "Szent Ambrus p�sp�k �s egyh�ztan�t�",
 };
const char *text_DEC_08[POCET_JAZYKOV + 1] = 
{"Nepo�kvrnen� po�atie Panny M�rie",
 "Panny Marie, po�at� bez poskvrny prvotn�ho h��chu",
 "",
 "",
 "",
 "Neposkvrn�n�ho po�et� Panny Marie",
 "A Boldogs�gos Sz�z M�ria szepl�telen fogantat�sa",
 };
const char *text_DEC_09[POCET_JAZYKOV + 1] = 
{"Sv. J�na Didaka Cuauhtlatoatzin",
 "Sv. Jana Didaka Cuauhtlatoatzina",
 "",
 "",
 "",
 "Sv. Jana Didaka Cuauhtlatoatzina",
 "Szent Juan Diego Cuauhtlatoatzin, Guadalupei l�tnok",
 };
const char *text_DEC_11[POCET_JAZYKOV + 1] = 
{"Sv. Damaza I., p�pe�a",
 "Sv. Damasa I., pape�e",
 "",
 "",
 "",
 "Sv. Damasa I., pape�e",
 "Szent I. Damazusz p�pa",
 };
const char *text_DEC_12[POCET_JAZYKOV + 1] = 
{"Panny M�rie Guadalupskej", // pod�a Direkt�ria 2012, str. 232, nie je 'Prebl.'
 "Panny Marie Guadalupsk�",
 "",
 "",
 "",
 "Panny Marie Guadalupsk�",
 "A Guadalupei Boldogs�gos Sz�z M�ria",
 };
const char *text_DEC_13[POCET_JAZYKOV + 1] = 
{"Sv. Lucie, panny a mu�enice",
 "Sv. Lucie, panny a mu�ednice",
 "",
 "",
 "",
 "Sv. Lucie, panny a mu�ednice",
 "Szent L�cia sz�z �s v�rtan�",
 };
const char *text_DEC_14[POCET_JAZYKOV + 1] = 
{"Sv. J�na z Kr�a, k�aza a u�ite�a Cirkvi",
 "Sv. Jana od K��e, kn�ze a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Jana od K��e, kn�ze a u�itele C�rkve",
 "Keresztes Szent J�nos �ldoz�pap �s egyh�ztan�t�",
 };
const char *text_DEC_16_OP[POCET_JAZYKOV + 1] = 
{"Bl. �ebasti�na Maggiho, k�aza",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_DEC_21[POCET_JAZYKOV + 1] = 
{"Sv. Petra Kan�zia, k�aza a u�ite�a Cirkvi",
 "Sv. Petra Kanisia, kn�ze a u�itele c�rkve",
 "",
 "",
 "",
 "Sv. Petra Kanisia, kn�ze a u�itele C�rkve",
 "Kan�ziusz Szent P�ter �ldoz�pap �s egyh�zta�nt�",
 };
const char *text_DEC_22_CZ[POCET_JAZYKOV + 1] = 
{"",
 "V�ro�� posv�cen� katedr�ly Sv. Mikul�e",
 "",
 "",
 "",
 "V�ro�� posv�cen� katedr�ly Sv. Mikul�e",
 "",
 };
const char *text_DEC_22_OP[POCET_JAZYKOV + 1] = 
{"V�ro�ie potvrdenia Rehole kazate�ov (1216)",
 "",
 "",
 "",
 "",
 "",
 "",
 };
const char *text_DEC_23[POCET_JAZYKOV + 1] = 
{"Sv. J�na Kentsk�ho, k�aza",
 "Sv. Jana Kentsk�ho, kn�ze",
 "",
 "",
 "",
 "Sv. Jana Kentsk�ho, kn�ze",
 "K&#281;ty Szent J�nos �ldoz�pap",
 };
const char *text_DEC_26[POCET_JAZYKOV + 1] = 
{"Sv. �tefana, prv�ho mu�en�ka",
 "Sv. �t�p�na, prvomu�edn�ka",
 "",
 "",
 "",
 "Sv. �t�p�na, prvomu�edn�ka",
 "Szent Istv�n els� v�rtan�",
 };
const char *text_DEC_27[POCET_JAZYKOV + 1] = 
{"Sv. J�na, apo�tola a evanjelistu",
 "Sv. Jana, apo�tola a evangelisty",
 "",
 "",
 "",
 "Sv. Jana, apo�tola a evangelisty",
 "Szent J�nos apostol �s evangelista",
 };
const char *text_DEC_28[POCET_JAZYKOV + 1] = 
{"Sv�t�ch Neviniatok, mu�en�kov",
 "Svat�ch Ml���tek, mu�edn�k�",
 "",
 "",
 "",
 "Svat�ch Ml���tek, mu�edn�k�",
 "Apr�szentek",
 };
const char *text_DEC_29[POCET_JAZYKOV + 1] = 
{"Sv. Tom�a Becketa, biskupa a mu�en�ka",
 "Sv. Tom�e Becketa, biskupa a mu�edn�ka",
 "",
 "",
 "",
 "Sv. Tom�e Becketa, biskupa a mu�edn�ka",
 "Becket Szent Tam�s p�sp�k �s v�rtan�",
 };
const char *text_DEC_31[POCET_JAZYKOV + 1] = 
{"Sv. Silvestra I., p�pe�a",
 "Sv. Silvestra I., pape�e",
 "",
 "",
 "",
 "Sv. Silvestra I., pape�e",
 "Szent I. Szilveszter p�pa",
 };

// --------------- 00 pohybliv� sl�venia ---------------

const char *text_ZELENY_STVRTOK[POCET_JAZYKOV + 1] = 
{"Zelen� (ve�k�) �tvrtok � Pamiatka P�novej ve�ere",
 "Zelen� �tvrtek - Pam�tka Ve�e�e P�n�",
 "",
 "",
 "",
 "Zelen� �tvrtek - Pam�tka Ve�e�e P�n�",
 "Nagycs�t�rt�k",
 };
const char *text_VELKY_PIATOK[POCET_JAZYKOV + 1] = 
{"Ve�k� piatok",
 "Velk� p�tek",
 "",
 "",
 "",
 "Velk� p�tek",
 "Nagyp�ntek",
 };
const char *text_BIELA_SOBOTA[POCET_JAZYKOV + 1] = 
{"Biela (ve�k�) sobota",
 "B�l� sobota",
 "",
 "",
 "",
 "B�l� sobota",
 "Nagyszombat",
 };
const char *text_KVETNA_NEDELA[POCET_JAZYKOV + 1] = 
{"Kvetn� nede�a",
 "Kv�tn� ned�le",
 "",
 "",
 "",
 "Kv�tn� ned�le",
 "Vir�gvas�rnap, vagyis az �r szenved�s�nek vas�rnapja",
 };
const char *text_PO_POPOLCOVEJ_STREDE[POCET_JAZYKOV + 1] = 
{"po Popolcovej strede",
 "po Popele�n� st�ed�",
 "",
 "",
 "",
 "po Popele�n� st�ed�",
 "Hamvaz�szerda ut�n",
 };
const char *text_V_OKTAVE_NARODENIA[POCET_JAZYKOV + 1] = 
{"v okt�ve Narodenia P�na",
 "v okt�vu Narozen� P�n�",
 "",
 "",
 "",
 "v okt�vu Narozen� P�n�",
 "Kar�csony nyolcad�ban",
 };

#endif // __HODIN_H_
