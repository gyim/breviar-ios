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
{"invitat�rium", "rann� chv�ly", "posv�tn� ��tanie",
 "modlitba predpoludn�m", "modlitba napoludnie", "modlitba popoludn�",
 "ve�pery", "komplet�rium", "neur�en�",
 "prv� ve�pery", "prv� komplet�rium",
 "druh� ve�pery", "druh� komplet�rium",
 "detaily"};
*/

const char *nazov_modlitby_jazyk[POCET_MODLITIEB + 1][POCET_JAZYKOV + 1] = 
{{"invitat�rium", "invitato�", "Invitatory", "" }
, {"rann� chv�ly", "rann� chv�ly", "Laudes", "" }
, {"posv�tn� ��tanie", "posv�tn� �ten�", "Holy Reading", "" }
, {"modlitba predpoludn�m", "modlitba dopoledne", "", "" }
, {"modlitba napoludnie", "modlitba v poledne", "", "" }
, {"modlitba popoludn�", "modlitba odpoledne", "", "" }
, {"ve�pery", "ne�pory", "Vesperae", "" }
, {"komplet�rium", "komplet��", "Completary", "" }
, {"neur�en�", "neur�ena", "not-defined", ""}
, {"prv� ve�pery", "prvn� ne�pory", "", "" }
, {"prv� komplet�rium", "prvn� komplet��", "", "" }
, {"druh� ve�pery", "druh� ne�pory", "", "" }
, {"druh� komplet�rium", "druh� komplet��", "", "" }
, {"detaily", "detaily", "Details", "" }
};

#define		nazov_modlitby(a)	nazov_modlitby_jazyk[a][_global_jazyk]

const char *nazov_Modlitby[] =
{"Invitat�rium", "Rann� chv�ly", "Posv�tn� ��tanie",
 "Modlitba predpoludn�m", "Modlitba napoludnie", "Modlitba popoludn�",
 "Ve�pery", "Komplet�rium", "Neur�en�",
 "Prv� ve�pery", "Prv� komplet�rium",
 "Druh� ve�pery", "Druh� komplet�rium",
 "Detaily"};
/*
const char *nazov_MODLITBY[] =
{"INVITAT�RIUM", "RANN� CHV�LY", "POSVATN� ��TANIE",
 "MODLITBA PREDPOLUDN�M", "MODLITBA NAPOLUDNIE", "MODLITBA POPOLUDN�",
 "VE�PERY", "KOMPLET�RIUM", "NEUR�EN�",
 "PRV� VE�PERY", "PRV� KOMPLET�RIUM",
 "DRUH� VE�PERY", "DRUH� KOMPLET�RIUM",
 "DETAILY"};
*/

/*
const char *nazov_spolc[MODL_SPOL_CAST_NEBRAT + 1] =
{"neur�en�",
 "duchovn�ch pastierov - pre k�azov",
 "duchovn�ch pastierov - pre biskupov",
 "duchovn�ch pastierov - pre p�pe�ov",
 "u�ite�ov Cirkvi",
 "apo�tolov",
 "jedn�ho mu�en�ka",
 "viacer�ch mu�en�kov",
 "Panny M�rie",
 "sv�t�ch mu�ov - pre reho�n�kov",
 "sv�t�ch mu�ov",
 "panien",
 "sv�t�ch �ien - pre reho�nice",
 "sv�t�ch �ien",
 "duchovn�ch pastierov - pre viacer�ch",
 "jednej mu�enice",
 "sv�t�ch �ien - pre vychov�vate�ov",
 "sv�t�ch mu�ov - pre vychov�vate�ov",
 "sv�t�ch �ien - pre t�ch, �o konali skutky milosrdenstva",
 "sv�t�ch mu�ov - pre t�ch, �o konali skutky milosrdenstva",
 "sv�t�ch �ien - pre viacer�",
 "sv�t�ch mu�ov - pre viacer�ch",
 "viacer�ch panien",
 "posviacky chr�mu",
 "zosnul�ch",
 "nebra�"
};
*/
const char *nazov_spolc_jazyk[POCET_SPOL_CASTI + 1][POCET_JAZYKOV + 1] =
{{"neur�en�", "neur�ena", "not decided", ""}, 
 {"duchovn�ch pastierov - pre k�azov", "duchovn�ch past��� - o kn��ch", "", ""}, 
 {"duchovn�ch pastierov - pre biskupov", "duchovn�ch past��� - o biskupech", "", ""}, 
 {"duchovn�ch pastierov - pre p�pe�ov", "duchovn�ch past��� - o pape�i", "", ""}, 
 {"u�ite�ov Cirkvi", "u�itel� c�rkve", "", ""}, 
 {"apo�tolov", "apo�tol�", "", ""}, 
 {"jedn�ho mu�en�ka", "jednoho mu�edn�ka", "", ""}, 
 {"viacer�ch mu�en�kov", "v�ce m��edn�k�", "", ""}, 
 {"Panny M�rie", "Panny Marie", "", ""}, 
 {"sv�t�ch mu�ov - pre reho�n�kov", "svat�ch mu�� - o �eholn�c�ch", "", ""}, 
 {"sv�t�ch mu�ov", "svat�ch mu��", "", ""}, 
 {"panien", "pannen", "", ""}, 
 {"sv�t�ch �ien - pre reho�nice", "svat�ch �en - o �eholnic�ch", "", ""}, 
 {"sv�t�ch �ien", "svat�ch �en", "", ""}, 
 {"duchovn�ch pastierov - pre viacer�ch", "duchvn�ch past��� - o v�ce past���ch", "", ""}, 
 {"jednej mu�enice", "jedn� mu�ednice", "", ""}, 
 {"sv�t�ch �ien - pre vychov�vate�ky", "svat�ch �en - o vychovatelce", "", ""}, 
 {"sv�t�ch mu�ov - pre vychov�vate�ov", "svat�ch mu�� - o vychovatel�ch", "", ""}, 
 {"sv�t�ch �ien - pre tie, �o konali skutky milosrdenstva", "svat�ch �en - o �en�, kter� vynikala milosrdn�mi skutky", "", ""}, 
 {"sv�t�ch mu�ov - pre t�ch, �o konali skutky milosrdenstva", "svat�ch mu�� - o mu�i, kter� vynikal milosrdn�mi skutky", "", ""}, 
 {"sv�t�ch �ien - pre viacer�", "svat�ch �en - o v�ce �en�ch", "", ""}, 
 {"sv�t�ch mu�ov - pre viacer�ch", "svat�ch mu�� - o v�ce mu��ch", "", ""}, 
 {"viacer�ch panien", "v�ce pannen", "", ""}, 
 {"posviacky chr�mu", "posv�cen� kostela", "", ""}, 
 {"zosnul�ch", "zem�el�ch", "", ""}, 
 {"sv�t�ch �ien - pre tie, �o �ili v man�elstve", "svat�ch �en - o �en�, kter� �ila v man�elstv�", "", ""}, 
 {"sv�t�ch mu�ov - pre t�ch, �o �ili v man�elstve", "svat�ch mu�� - o mu�i, kter� �il v man�elstv�", "", ""}, 
 {"nebra�", "nevz�t", "do not use", ""}
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
{"ve�kono�n� okt�va", "adventn� obdobie", "adventn� obdobie",
 "viano�n� obdobie", "viano�n� obdobie", "obdobie �cez rok�",
 "p�stne obdobie", "Ve�k� t��de�",
 "ve�kono�n� trojdnie", "ve�kono�n� obdobie", "ve�kono�n� obdobie",
 "okt�va Narodenia P�na"};
*/

const char *nazov_obdobia_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{{"ve�kono�n� okt�va", "velikono�n� okt�v", "", ""},
 {"adventn� obdobie", "doba adventn�", "", ""},
 {"adventn� obdobie", "doba adventn�", "", ""},
 {"viano�n� obdobie", "doba v�no�n�", "", ""},
 {"viano�n� obdobie", "doba v�no�n�", "", ""},
 {"cezro�n� obdobie", "mezidob�", "", ""}, // obdobie �cez rok�
 {"p�stne obdobie", "doba postn�", "", ""},
 {"Ve�k� t��de�", "Svat� t�den", "", ""},
 {"ve�kono�n� trojdnie", "Velikono�n� triduum", "", ""},
 {"ve�kono�n� obdobie", "doba velikono�n�", "", ""},
 {"ve�kono�n� obdobie", "doba velikono�n�", "", ""},
 {"okt�va Narodenia P�na", "okt�v Narozen� P�n�", "", ""}
};

#define		nazov_obdobia(a)	nazov_obdobia_jazyk[a][_global_jazyk]

const char *nazov_obdobia_[] = // debuggovacie - preto netreba preklada�; 2006-08-03
{"ve�kono�n� okt�va", "adventn� obdobie I", "adventn� obdobie II",
 "viano�n� obdobie I", "viano�n� obdobie II", "obdobie �cez rok�",
 "p�stne obdobie I", "Ve�k� t��de�",
 "ve�kono�n� trojdnie", "ve�kono�n� obdobie I", "ve�kono�n� obdobie II",
 "okt�va Narodenia P�na"};

/* lokal == 6. pad, v kom/com */

/*
const char *nazov_obdobia_v[] =
{"vo ve�kono�nej okt�ve", "v adventnom obdob�", "v adventnom obdob�",
 "vo viano�nom obdob�", "vo viano�nom obdob�", "v obdob� �cez rok�",
 "v p�stnom obdob�", "vo Ve�kom t��dni",
 "vo ve�kono�nom trojdn�", "vo ve�kono�nom obdob�", "vo ve�kono�nom obdob�",
 "v okt�ve Narodenia P�na"};
*/
const char *nazov_obdobia_v_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{{"vo ve�kono�nej okt�ve", "ve velikono�n�m okt�vu", "", ""},
 {"v adventnom obdob�", "v dob� adventn�", "", ""},
 {"v adventnom obdob�", "v dob� adventn�", "", ""},
 {"vo viano�nom obdob�", "v dob� v�no�n�", "", ""},
 {"vo viano�nom obdob�", "v dob� v�no�n�", "", ""},
 {"v cezro�nom obdob�", "v mezidob�", "", ""}, // obdobie �cez rok�
 {"v p�stnom obdob�", "v dob� postn�", "", ""},
 {"vo Ve�kom t��dni", "ve Svat�m t�dnu", "", ""},
 {"vo ve�kono�nom trojdn�", "ve velikono�n�m triduu", "", ""},
 {"vo ve�kono�nom obdob�", "v dob� velikono�n�", "", ""},
 {"vo ve�kono�nom obdob�", "v dob� velikono�n�", "", ""},
 {"v okt�ve Narodenia P�na", "v okt�vu Narozen� P�n�", "", ""}
};

#define		nazov_obdobia_v(a)	nazov_obdobia_v_jazyk[a][_global_jazyk]

/*
const char *nazov_OBDOBIA_V[] =
{"VO VE�KONO�NEJ OKT�VE", "V ADVENTNOM OBDOB�", "V ADVENTNOM OBDOB�",
 "VO VIANO�NOM OBDOB�", "VO VIANO�NOM OBDOB�", "V OBDOB� �CEZ ROK�",
 "V P�STNOM OBDOB�", "VO VE�KOM TݎDNI",
 "VO VE�KONO�NOM TROJDN�", "VO VE�KONO�NOM OBDOB�", "VO VE�KONO�NOM OBDOB�",
 "V OKT�VE NARODENIA P�NA"};
*/
const char *nazov_OBDOBIA_V_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1] =
{{"VO VE�KONO�NEJ OKT�VE", "VE VELIKONO�N�M OKT�VU", "", ""},
 {"V ADVENTNOM OBDOB�", "V DOB� ADVENTN�", "", ""},
 {"V ADVENTNOM OBDOB�", "V DOB� ADVENTN�", "", ""},
 {"VO VIANO�NOM OBDOB�", "V DOB� V�NO�N�", "", ""},
 {"VO VIANO�NOM OBDOB�", "V DOB� V�NO�N�", "", ""},
 {"V CEZRO�NOM OBDOB�", "V MEZIDOB�", "", ""}, // OBDOBIE �CEZ ROK�
 {"V P�STNOM OBDOB�", "V DOB� POSTN�", "", ""},
 {"VO VE�KOM TݎDNI", "VE SVAT�M T�DNU", "", ""},
 {"VO VE�KONO�NOM TROJDN�", "VE VELIKONO�N�M TRIDUU", "", ""},
 {"VO VE�KONO�NOM OBDOB�", "V DOB� VELIKONO�N�", "", ""},
 {"VO VE�KONO�NOM OBDOB�", "V DOB� VELIKONO�N�", "", ""},
 {"V OKT�VE NARODENIA P�NA", "V OKT�VU NAROZEN� P�N�", "", ""}
};

#define		nazov_OBDOBIA_V(a)	nazov_OBDOBIA_V_jazyk[a][_global_jazyk]

/* gen[itiv] == 2. pad, koho/coho */

/* 2006-08-02: netreba preklada�, preto�e sa nepou��va 
const char *nazov_obdobia_gen[] =
{"ve�kono�nej okt�vy", "adventn�ho obdobia", "adventn�ho obdobia",
 "viano�n�ho obdobia", "viano�n�ho obdobia", "obdobia �cez rok�",
 "p�stneho obdobia", "Ve�k�ho t��d�a",
 "ve�kono�n�ho trojdnia", "ve�kono�n�ho obdobia", "ve�kono�n�ho obdobia",
 "okt�vy Narodenia P�na"};

const char *nazov_Obdobia[] =
{"Ve�kono�n� okt�va", "Adventn� obdobie", "Adventn� obdobie",
 "Viano�n� obdobie", "Viano�n� obdobie", "Obdobie �cez rok�",
 "P�stne obdobie", "Ve�k� t��de�",
 "Ve�kono�n� trojdnie", "Ve�kono�n� obdobie", "Ve�kono�n� obdobie",
 "Okt�va Narodenia P�na"};
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

/* 2005-08-05: Pridan�. zv�zok brevi�ra (LH) pre spolo�n� �asti sv�t�ch v kotv�ch */
const char *zvazok_OBD[] =
{"ZVII", "ZVI", "ZVI",
 "ZVI", "ZVI", "OCR", /* OCR je ZVIII aj ZVIV */
 "ZVII", "ZVII",
 "ZVII", "ZVII", "ZVII",
 "ZVI"};

/*
const char *nazov_slavenia[] =
{"___",
 "sl�vnos�", "sviatok", "spomienka", "�ubovo�n� spomienka",
 "vlastn� sl�venie"};
*/
const char *nazov_slavenia_jazyk[POCET_SLAVENI + 1][POCET_JAZYKOV + 1] =
{{"___", "___", "___", ""}, 
 {"sl�vnos�", "slavnost", "", ""}, 
 {"sviatok", "sv�tek", "", ""}, 
 {"spomienka", "pam�tka", "", ""}, 
 {"�ubovo�n� spomienka", "nez�vazn� pam�tka", "", ""}, 
 {"vlastn� sl�venie", "z vlastn�ch text�", "", ""}, 
};

#define		nazov_slavenia(a)	nazov_slavenia_jazyk[a][_global_jazyk]

/* 2006-08-02: netreba preklada�, preto�e sa nepou��va 
const char *nazov_Slavenia[] =
{"___",
 "Sl�vnos�", "Sviatok", "Spomienka", "�ubovo�n� spomienka",
 "Vlastn� sl�venie"};
*/

/* 2005-07-27: doplnen� */
const char *nazov_slavenia_lokal[] =
{""
,"len v ro��avskej katedr�le"
,"hlavn� patr�n Bratislavsko-Trnavskej arcidiec�zy"
,"v Bratislavsko-Trnavskej arcidiec�ze a v Banskobystrickej, Ko�ickej, Nitrianskej a Ro��avskej diec�ze"
,"v Nitrianskej diec�ze sviatok hlavn�ch patr�nov"
,"len v Ko�ickej diec�ze"
,"len v Nitrianskej diec�ze"
,"len v Banskobystrickej diec�ze"
,"len v Spi�skej diec�ze"
,"len v Ro��avskej diec�ze"
,"len v Trnavskej diec�ze"
,"len v D�me sv. Martina v Bratislave"
,"v Spi�skej diec�ze sviatok hlavn�ho patr�na"
,"v Banskobystrickej diec�ze sviatok hlavn�ho patr�na"
,"v Bratislavsko-Trnavskej arcidiec�ze a v Banskobystrickej, Nitrianskej a Ro��avskej diec�ze"
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
};

const char *nazov_farby_jazyk[POCET_FARIEB + 1][POCET_JAZYKOV + 1] =
{{"___", "___", "___", ""}, 
 {"�erven�", "�erven�", "red", ""}, 
 {"biela", "b�l�", "white", ""}, 
 {"zelen�", "zelen�", "green", ""}, 
 {"fialov�", "fialov�", "purple", ""}, 
 {"ru�ov�", "r��ov�", "rose", ""}, 
};

#define		nazov_farby(a)	nazov_farby_jazyk[a][_global_jazyk]

const char *html_farba_pozadie[POCET_FARIEB + 1] =
{"black", "red", "white", "green", "purple", "#FF6699" /*"fuchsia" */};

const char *html_farba_popredie[POCET_FARIEB + 1] =
{"white", "white", "black", "white", "white", "blue"};

const char *rimskymi_tyzden_zaltara[] =
{"_", "I", "II", "III", "IV"};

const short int prvy_den[12] =
	{1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};

short int pocet_dni[12] =
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const char char_nedelne_pismeno[7] =
	{'b', 'c', 'd', 'e', 'f', 'g', 'A'};

const char char_nedelny_cyklus[3] =
	{'A', 'B', 'C'};

/* nazov_dna: string pre nazov dna; suhlasi s struct tm.tm_wday;
 * Weekday (0--6; Sunday/nedela = 0) */

/*
const char *nazov_dna[] =
{"nede�a", "pondelok", "utorok", "streda",
 "�tvrtok", "piatok", "sobota", "nezn�my"};
*/
const char *nazov_dna_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{{"nede�a", "ned�le", "Sunday", ""}
, {"pondelok" , "pond�l�", "Monday", ""}
, {"utorok" , "�ter�", "Tuesday", ""}
, {"streda" , "st�eda", "Wednesday", ""}
, {"�tvrtok" , "�tvrtek", "Thursday", ""}
, {"piatok" , "p�tek", "Friday", ""}
, {"sobota" , "sobota", "Saturday", ""}
, {"nezn�my" , "nezn�m�", "unknown", ""}
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
{"Nede�a", "Pondelok", "Utorok", "Streda",
 "�tvrtok", "Piatok", "Sobota", "Nezn�my"};
*/
const char *nazov_Dna_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{{"Nede�a", "Ned�le", "Sunday", ""}
, {"Pondelok" , "Pond�l�", "Monday", ""}
, {"Utorok" , "�ter�", "Tuesday", ""}
, {"Streda" , "St�eda", "Wednesday", ""}
, {"�tvrtok" , "�tvrtek", "Thursday", ""}
, {"Piatok" , "P�tek", "Friday", ""}
, {"Sobota" , "Sobota", "Saturday", ""}
, {"Nezn�my" , "Nezn�m�", "unknown", ""}
};

#define		nazov_Dna(a)	nazov_Dna_jazyk[a][_global_jazyk]

/*
const char *nazov_DNA[] =
{"NEDE�A", "PONDELOK", "UTOROK", "STREDA",
 "�TVRTOK", "PIATOK", "SOBOTA", "NEZN�MY"};
*/
const char *nazov_DNA_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{{"NEDE�A", "NED�LE", "SUNDAY", ""}
, {"PONDELOK" , "POND�L�", "MONDAY", ""}
, {"UTOROK" , "�TER�", "TUESDAY", ""}
, {"STREDA" , "ST�EDA", "WEDNESDAY", ""}
, {"�TVRTOK" , "�TVRTEK", "THURSDAY", ""}
, {"PIATOK" , "P�TEK", "FRIDAY", ""}
, {"SOBOTA" , "SOBOTA", "SATURDAY", ""}
, {"NEZN�MY" , "NEZN�M�", "UNKNOWN", ""}
};

#define		nazov_DNA(a)	nazov_DNA_jazyk[a][_global_jazyk]

/*
const char *nazov_Dn[] =
{"Ne", "Po", "Ut", "St", "�t", "Pi", "So", "??"};
*/
const char *nazov_Dn_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1] = 
{ {"Ne" , "Ne", "Sun", ""}
, {"Po" , "Po", "Mon", ""}
, {"Ut" , "�t", "Tue", ""}
, {"St" , "St", "Wed", ""}
, {"�t" , "�t", "Thu", ""}
, {"Pi" , "P�", "Fri", ""}
, {"So" , "So", "Sat", ""}
, {"??" , "??", "???", ""}
};

#define		nazov_Dn(a)	nazov_Dn_jazyk[a][_global_jazyk]

/* 2006-08-01: pou��va sa pre HTML kotvy, ktor� nez�visia od jazykovej mut�cie */
const char *nazov_DN_asci[] =
{"NE", "PO", "UT", "STR", "STV", "PI", "SO", "??"};

const char *nazov_dn_asci[] =
{"ne", "po", "ut", "str", "stv", "pi", "so", "??"};

/* nazov_mesiaca: string pre nazov dna; suhlasi s struct tm.tm_mon;
 * Month (0--11) */

/*
const char *nazov_mesiaca[] =
{"janu�r", "febru�r", "marec", "apr�l", "m�j", "j�n", "j�l",
 "august", "september", "okt�ber", "november", "december", "nezn�my"};
*/

const char *nazov_mesiaca_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{{"janu�r", "leden", "January", ""}
, {"febru�r" , "�nor", "February", ""}
, {"marec" , "b�ezen", "March", ""}
, {"apr�l" , "duben", "April", ""}
, {"m�j" , "kv�ten", "May", ""}
, {"j�n" , "�erven", "June", ""}
, {"j�l" , "�ervenec", "July", ""}
, {"august" , "srpen", "August", ""}
, {"september" , "z���", "September", ""}
, {"okt�ber" , "��jen", "October", ""}
, {"november" , "listopad", "November", ""}
, {"december" , "prosinec", "December", ""}
, {"nezn�my" , "nezn�m�", "unknown", ""}
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
{"Janu�r", "Febru�r", "Marec", "Apr�l", "M�j", "J�n", "J�l",
 "August", "September", "Okt�ber", "November", "December", "Nezn�my"};
*/
const char *nazov_Mesiaca_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{ {"Janu�r", "Leden", "January", ""}
, {"Febru�r" , "�nor", "February", ""}
, {"Marec" , "B�ezen", "March", ""}
, {"Apr�l" , "Duben", "April", ""}
, {"M�j" , "Kv�ten", "May", ""}
, {"J�n" , "�erven", "June", ""}
, {"J�l" , "�ervenec", "July", ""}
, {"August" , "Srpen", "August", ""}
, {"September" , "Z���", "September", ""}
, {"Okt�ber" , "��jen", "October", ""}
, {"November" , "Listopad", "November", ""}
, {"December" , "Prosinec", "December", ""}
, {"Nezn�my" , "Nezn�m�", "unknown", ""}
};

#define		nazov_Mesiaca(a)	nazov_Mesiaca_jazyk[a][_global_jazyk]

/*
const char *nazov_MESIACA[] =
{"JANU�R", "FEBRU�R", "MAREC", "APR�L", "M�J", "J�N", "J�L",
 "AUGUST", "SEPTEMBER", "OKT�BER", "NOVEMBER", "DECEMBER", "NEZN�MY"};
*/
const char *nazov_MESIACA_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1] = 
{ {"JANU�R", "LEDEN", "JANUARY", ""}
, {"FEBRU�R" , "�NOR", "FEBRUARY", ""}
, {"MAREC" , "B�EZEN", "MARCH", ""}
, {"APR�L" , "DUBEN", "APRIL", ""}
, {"M�J" , "KV�TEN", "MAY", ""}
, {"J�N" , "�ERVEN", "JUNE", ""}
, {"J�L" , "�ERVENEC", "JULY", ""}
, {"AUGUST" , "SRPEN", "AUGUST", ""}
, {"SEPTEMBER" , "Z���", "SEPTEMBER", ""}
, {"OKT�BER" , "��JEN", "OCTOBER", ""}
, {"NOVEMBER" , "LISTOPAD", "NOVEMBER", ""}
, {"DECEMBER" , "PROSINEC", "DECEMBER", ""}
, {"NEZN�MY" , "NEZN�M�", "UNKNOWN", ""}
};

#define		nazov_MESIACA(a)	nazov_MESIACA_jazyk[a][_global_jazyk]

const char *nazov_MES[] =
{"JAN", "FEB", "MAR", "APR", "MAJ", "JUN", "JUL",
 "AUG", "SEP", "OKT", "NOV", "DEC", "___"};

const char *nazov_mes[] =
{"jan", "feb", "mar", "apr", "maj", "jun", "jul",
 "aug", "sep", "okt", "nov", "dec", "___"};

/* 2006-07-11: Pridan� kv�li jazykov�m mut�ci�m */
const char *nazov_jazyka[] =
{"sloven�ina", "�e�tina", "English", "(neur�en�)"};

const char *skratka_jazyka[] =
{"sk", "cz", "en", "??"};

/* 2006-07-13 a 17: Pridan� kv�li jazykov�m mut�ci�m - postfix pre include adres�r */
const char *postfix_jazyka[] =
{"", "cz", "en", ""};
/* Pozn�mka: Postfix nesmie obsahova� na za�iatku odde�ova� (slash resp. backslash);
 * mus� sa jedna� o podadres�r pod include */

/* defin�cie HTML prvkov upraven� a presunut� z mydefs.h, 2006-08-01 */
const char *html_button_ranne_chvaly[] = {"Rann� chv�ly", "Rann� chv�ly", "Laudes", ""};
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

const char *html_button_vespery[] = {"Ve�pery", "Ne�pory", "Vesperae", ""};
#ifndef HTML_BUTTON_VESPERY
#define HTML_BUTTON_VESPERY	html_button_vespery[_global_jazyk]
#endif

const char *html_button_posv_citanie[] = {"Posv.��t.", "�ten�", "Reading", ""};
#ifndef HTML_BUTTON_POSV_CITANIE
#define HTML_BUTTON_POSV_CITANIE	html_button_posv_citanie[_global_jazyk]
#endif

const char *html_button_detaily[] = {"Detaily...", "Podrobn�ji...", "Details...", ""};
#ifndef HTML_BUTTON_DETAILY
#define HTML_BUTTON_DETAILY	html_button_detaily[_global_jazyk]
#endif

const char *html_button_det_show[] = {"Zobraz modlitbu", "Uka� modlitbu", "Show prayer", ""};
#ifndef HTML_BUTTON_DET_SHOW
#define HTML_BUTTON_DET_SHOW	html_button_det_show[_global_jazyk]
#endif

const char *html_button_det_defaults[] = {"P�vodn� hodnoty", "P�vodn� hodnoty", "Defaults", ""};
#ifndef HTML_BUTTON_DET_DEFAULTS
#define HTML_BUTTON_DET_DEFAULTS	html_button_det_defaults[_global_jazyk]
#endif

const char *html_button_dnes_show[] = {"Zobraz", "Uka�", "Show", ""};
#ifndef HTML_BUTTON_DNES_SHOW
#define HTML_BUTTON_DNES_SHOW	html_button_dnes_show[_global_jazyk]
#endif

const char *html_button_dnes_defaults[] = {"Vy�isti", "Vy�isti", "Clear", ""};
#ifndef HTML_BUTTON_DNES_DEFAULTS
#define HTML_BUTTON_DNES_DEFAULTS	html_button_dnes_defaults[_global_jazyk]
#endif

const char *html_button_predchadzajuci_[] = {"Predch�dzaj�ci", "P�edchoz�", "Previous", ""};
const char *html_button_nasledujuci_[] = {"Nasleduj�ci", "N�sleduj�c�", "Next", ""};
const char *html_text_den[] = {"de�", "den", "day", ""};
const char *html_text_mesiac[] = {"mesiac", "m�s�c", "month", ""};
const char *html_text_rok[] = {"rok", "rok", "year", ""};
const char *html_text_Rok[] = {"Rok", "Rok", "Year", ""};
const char *html_text_Rok_x[] = {"Rok %d", "Rok %d", "Year %d", ""};

const char *html_text_zoznam_mesiacov[] = {"zoznam mesiacov", "seznam m�s�c�", "list of months", ""};

const char *html_text_modlitba[] = {"modlitba", "modlitba", "prayer", ""};
const char *html_text_modlitby_pre_den[] = {"modlitby pre de�", "modlitby pro den", "prayers for date", ""};
const char *html_text_alebo_pre[] = {"alebo pre", "anebo pro", "or for", ""};
const char *html_text_dnesok[] = {"dne�ok", "dne�n� den", "today", ""};

const char *html_text_Vysvetlivky[] = {"Vysvetlivky", "Vysv�tlivky", "Legenda", ""};

const char *html_text_dalsie_moznosti[] = {"Vyberte si �al�ie mo�nosti ", "Dal�� mo�nosti v�b�ru ", "Choose from above (buttons) or from the following options: ", ""};
const char *html_text_prik_sviatky_atd[] = {"prik�zan� sviatky a sl�vnosti P�na v roku ", "p�ik�zan� sv�tky a sl�vnosti P�n� v roku ", "obligatory celebrations in year ", ""};
const char *html_text_lit_kalendar[] = {"liturgick� kalend�r pre", "liturgick� kalend�� pro", "liturgical calendar for", ""};
const char *html_text_roku[] = {"roku", "roku", "of year", ""};
const char *html_text_tabulka_pohyblive_od[] = {"tabu�ka d�tumov pohybliv�ch sl�ven� od roku", "tabulka s datumy prom�nn�ch slavnost� od roku", "table with dates of movable celebrations from year", ""};
const char *html_text_do_roku[] = {"do roku", "po rok", "till year", ""};
const char *html_text_zobrazit_linky[] = {"zobrazi� tabu�ku vr�tane hypertextov�ch odkazov na jednotliv� dni", "zobrazit tabulku s hypertextov�mi odkazy pro jednotliv� dny", "display the table including hypertext links to each date", ""};
const char *html_text_pre_cezrocne_obd[] = {"pre cezro�n� obdobie", "pro mezidob�", "for ...", ""};
const char *html_text_tyzden_zaltara[] = {". t��de� �alt�ra", ". t�den �alt��e", "week of Psaltary", ""};
const char *html_text_tyzden[] = {". t��de�", ". t�den", "week", ""};
const char *html_text_v_tyzdni_zaltara[] = {". t��dni �alt�ra", ". t�dnu �alt��e", "week of Psaltary", ""};
const char *html_text_dnes_je_atd[] = 
{"Dnes je %d. de� v roku%s, <a href=\"%s%s\">juli�nsky d�tum</a> JD = %ld%s.\n<br>\n",
 "Dnes je %d. den v roku%s, <a href=\"%s%s\">juli�nsk� datum</a> JD = %ld%s.\n<br>\n",
 "Today is %d. day in the year%s, <a href=\"%s%s\">Julian date</a> JD = %ld%s.\n<br>\n",
 ""};

const char *html_text_zakladne_info[] = {"Z�kladn� inform�cie", "Z�kladn� informace", "Basic info", ""};
const char *html_text_je[] = {"je", "je", "is", ""};
const char *html_text_nie_je[] = {"nie je", "nen�", "is not", ""};
const char *html_text_prestupny[] = {"prestupn�", "p�estupn�", "...", ""};
const char *html_text_datumy_pohyblivych_slaveni[] = {"D�tumy pohybliv�ch sl�ven�", "D�ta prom�nliv�ch sl�ven�", "Dates for movable celebrations", ""};

const char *html_text_Nedelne_pismeno[] = {"Nede�n� p�smeno", "Nedeln� p�smeno", "Sunday letter", ""};
const char *html_text_Nedelne_pismena[] = {"Nede�n� p�smen�", "Nedeln� p�smena", "Sunday letters", ""};
const char *html_text_Od_prvej_adv_atd[] = {
	"Od prvej adventnej nedele v roku %d (%s) pokra�uje <a href=\"%s%s\">liturgick� rok</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"Od prn� ned�le adventn� v roku %d (%s) pokra�uje <a href=\"%s%s\">liturgick� rok</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"From the 1st Advent Sunday in the year %d (%s) continues <a href=\"%s%s\">liturgical year</a> <"HTML_SPAN_BOLD">%c</span>.\n",
	"Od prvej adventnej nedele v roku %d (%s) pokra�uje <a href=\"%s%s\">liturgick� rok</a> <"HTML_SPAN_BOLD">%c</span>.\n"
};

const char *str_modl_cez_den_zalmy_zo_dna[POCET_JAZYKOV + 1] = 
	{"be�nej psalm�die", "b�n� psalmodie", "ordinary psalmody", ""};
#define		STR_MODL_CEZ_DEN_ZALMY_ZO_DNA 	str_modl_cez_den_zalmy_zo_dna[_global_jazyk]

const char *str_modl_cez_den_doplnkova_psalmodia[POCET_JAZYKOV + 1] = 
	{"doplnkovej psalm�die", "dopl�kov� psalmodie", "supplementary psalmody", ""};
#define		STR_MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA 	str_modl_cez_den_doplnkova_psalmodia[_global_jazyk]

const char *str_modl_zalmy_zo_dna[POCET_JAZYKOV + 1] = 
	{"d�a", "dne", "day", ""};
#define		STR_MODL_ZALMY_ZO_DNA 	str_modl_zalmy_zo_dna[_global_jazyk]

const char *str_modl_zalmy_zo_sv[POCET_JAZYKOV + 1] = 
	{"sviatku", "sv�tku", "celebration", ""};
#define		STR_MODL_ZALMY_ZO_SV 	str_modl_zalmy_zo_sv[_global_jazyk]

const char *str_ano[POCET_JAZYKOV + 1] = 
	{"�no", "ano", "yes", ""};
#define		STR_ANO		str_ano[_global_jazyk]

const char *str_nie[POCET_JAZYKOV + 1] = 
	{"nie", "ne", "no", ""};
#define		STR_NIE		str_nie[_global_jazyk]

const char *html_text_detaily_uvod[POCET_JAZYKOV + 1] = 
{"Nasledovn� mo�nosti ovplyvnia vzh�ad i obsah vygenerovanej modlitby.\nVyberte tie mo�nosti, pod�a ktor�ch sa m� modlitba vygenerova�.", 
 "N�sleduj�c� mo�nosti maj� vliv na vzhled i obsah vygenerovan� modlitby.\nVyberte si mo�nosti, podle kter�ch m� b�t modlitba vygenerov�na.", 
 "The following options apply to the resulting generated text of the prayer.\nChoose options which fit your needs to the resulting prayer text.", 
 ""};

const char *html_text_nemenne_sucasti[] = {"zobrazi� <i>nemenn� s��asti</i> modlitby?", "zobrazit <i>nem�nn� sou��sti</i> modlitby?", "display <i>non-changeable parts</i> prayer?", ""};
const char *html_text_nemenne_sucasti_explain[] = 
{"Ka�d� rann� chv�ly obsahuj� Benediktus, ve�pery Magnifikat, obe modlitby obsahuj� Ot�en� a zakon�enie modlitby, a napokon posv�tn� ��tanie obsahuje niekedy hymnus Te Deum; tieto �asti modlitby naz�vame <i>nemenn� s��asti</i>.", 
 "Ka�d� rann� chv�ly obsahuj� Zachari�ovo kantikum, ne�pory Mariin Magnifikat, ob� modlitbu P�n� a zakon�en� modlitby, a kone�n� modlitba se �ten�m n�kdy obsahuje hymnus Te Deum; tyto ��sti modliteb naz�v�me <i>nem�nn� sou��sti</i>.", 
 "Each morning prayer contains Benedictus, vesperae contains Magnificat, both contain the Lord's Prayer and a conclusion of the prayer; finally, the holy reading sometimes contains the Te Deum hymnus; all these parts we call <i>un-changeable parts</i>.", 
 ""};

const char *html_text_popis_svaty[] = {"zobrazi� <i>popis</i> k modlitbe sv�t�ho?", "zobrazit <i>popis</i> p�i modlitb� ke cti sv�tce?", "display <i>description</i> for prayer for the saints?", ""};
const char *html_text_popis_svaty_explain[] = 
{"Modlitby zv��a obsahuj� pred n�zvom modlitby �ivotopis sv�t�ho, popis sviatku alebo podobn� stru�n� charakteristiku, ktor� pre jednoduchos� naz�vame <i>popis</i>.", 
 "Modlitby ke cti svat�ch obsahuj� stru�n� �ivotopis svat�ho, p�i sv�tku je to stru�n� popis sv�tku a podobn�. Tyto charakteristiky pro stru�nost naz�v�me <i>popis</i>.", 
 "xxx", 
 ""};

const char *html_text_zalmy_brat_zo[] = {"�almy bra� zo ", "�almy br�t ze ", "take psalmody from ", ""};
const char *html_text_zalmy_brat_zo_okrem_mcd[] = {" (okrem modlitby cez de�)\n", " (krom� modlitby p�es den)\n", " (excluding the prayers during the day)\n", ""};
const char *html_text_zalmy_brat_zo_explain[] = 
{"V z�vislosti od typu sv�tenia sa ber� alebo neber� na sviatok sv�tca/sv�tice �almy a chv�lospevy z vlastnej �asti (na rann� chv�ly z nedele 1. t��d�a �alt�ra); je mo�n� tieto �almy vy�iada�.", 
 "V z�vislosti na typu slaven� sv�tku sv�tce/sv�tice se berou nebo neberou �almy a kantika z vlastn� ��sti (na rann� chv�ly z ned�le 1. t�dne �alt��e); je mo�no tyto �almy vy��dat.", 
 "xxx", 
 ""};

const char *html_text_spol_casti_vziat_zo[] = {"�asti modlitby zo spolo�nej �asti ", "��sti modlitby ze spole�n� ��sti ", "parts of prayer from the common part ", ""};
const char *html_text_spol_casti_vziat_zo_explain[] = 
{"Na sviatok sv�tca/sv�tice sa pod�a liturgick�ch pravidiel ber� �asti, ktor� sa nenach�dzaj� vo vlastnej �asti �alt�ra, zo spolo�nej �asti sviatku, niekedy je mo�nos� vybra� si z viacer�ch spolo�n�ch �ast�; naviac je mo�nos� modli� sa tieto �asti zo v�edn�ho d�a.", 
 "Na sv�tek ke cti sv�tce/sv�tice se podle liturgick�ch pravidel berou ��sti, kter� se nenach�z� ve vlastn�ch textech, ze spole�n�ch text�, n�kdy je mo�n� vybrat si z v�ce spole�n�ch text�; nav�c je mo�nost modlit se tyto ��sti ze v�edn�ho dne.", 
 "xxx", 
 ""};

const char *html_text_zalmy_pre_mcd[] = {"�almy pre modlitbu cez de� bra� z ", "�almy pro modlitbu p�es den br�t ze ", "take psalmody for the prayer during the day from ", ""};
const char *html_text_zalmy_pre_mcd_explain[] = 
{"Doplnkov� psalm�dia zah��a 3 s�rie tzv. gradu�lnych �almov (� 120-129), ktor� mo�no bra� namiesto �almov zo �alt�ra.", 
 "Dopl�ovac� cyklus �alm� obsahuje 3 s�rie tzv. gradu�ln�ch �alm� (� 120-129), kter� je mo�no br�t m�sto �alm� ze �alt��e.", 
 "xxx", 
 ""};

const char *html_text_detaily_explain[] = 
{"Pokia� s� niektor� parametre pre vybran� modlitbu nepou�ite�n�, neber� sa do �vahy (m��u by� teda nastaven� �ubovo�ne).", 
 "Kdy� jsou n�kter� v��e uveden� volby nepou�iteln� pro n�jakou modlitbu, neberou se v �vahu (mohou b�t nastaveny dle libov�le).", 
 "If any of described options are not applicable for a chosen prayer, they can be set anyhow.", 
 ""};

const char *text_JAN_01[] =
{"Panny M�rie Bohorodi�ky",
 "Matky Bo��, Panny Marie",
 "", ""};
const char *text_JAN_02[] =
{"Sv. Bazila Ve�k�ho a Gregora Naziansk�ho, biskupov a u�ite�ov Cirkvi",
 "Sv. Basila Velik�ho a �eho�e Nazi�nsk�ho, biskup� a u�itel� c�rkve",
 "", ""};
const char *text_JAN_06[] =
{"Zjavenie P�na",
 "Zjeven� P�n�",
 "", ""};
const char *text_JAN_07[] =
{"Sv. Rajmunda z Pe�afortu, k�aza",
 "Sv. Rajmunda z Penafortu, kn�ze",
 "", ""};
const char *text_JAN_KRST[] =
{"Krst Krista P�na",
 "K�tu P�n�",
 "", ""};
const char *text_JAN_13[] =
{"Sv. Hil�ra, biskupa a u�ite�a Cirkvi",
 "Sv. Hilaria, biskupa a u�itele c�rkve",
 "", ""};
const char *text_JAN_17[] =
{"Sv. Antona, op�ta",
 "Sv. Anton�na, opata",
 "", ""};
const char *text_JAN_18[] =
{"(na Slovensku nie je)",
 "Panny Marie, Matky jednoty k�es�an�",
 "", ""};
const char *text_JAN_20_1[] =
{"Sv. Fabi�na, p�pe�a a mu�en�ka",
 "Sv. Fabi�na, pape�e a mu�edn�ka",
 "", ""};
const char *text_JAN_20_2[] =
{"Sv. �ebasti�na, mu�en�ka",
 "Sv. �ebesti�na, mu�edn�ka",
 "", ""};
const char *text_JAN_21[] =
{"Sv. Agnesy, panny a mu�enice",
 "Sv. Ane�ky, panny a mu�ednice",
 "", ""};
const char *text_JAN_22[] =
{"Sv. Vincenta, diakona a mu�en�ka",
 "Sv. Vincence, j�hna a mu�edn�ka",
 "", ""};
const char *text_JAN_23[] =
{"Sv. J�na Almu�n�ka, biskupa",
 "(v �ech�ch, na Morav� a ve Slezsku nen�)",
 "", ""};
const char *text_JAN_24[] =
{"Sv. Franti�ka Salesk�ho, biskupa a u�ite�a Cirkvi",
 "Sv. Franti�ka Salesk�ho, biskupa a u�itele c�rkve",
 "", ""};
const char *text_JAN_25[] =
{"Obr�tenie sv�t�ho Pavla, apo�tola",
 "Obr�cen� svat�ho Pavla, apo�tola",
 "", ""};
const char *text_JAN_26[] =
{"Sv. Timoteja a T�ta, biskupov",
 "Sv. Timoteje a Tita, biskup�",
 "", ""};
const char *text_JAN_27[] =
{"Sv. Angely Merici, panny",
 "Sv. And�ly Mericiov�, panny",
 "", ""};
const char *text_JAN_28[] =
{"Sv. Tom�ka Akvinsk�ho, k�aza a u�ite�a Cirkvi",
 "Sv. Tom�e Akvinsk�ho, kn�ze a u�itele c�rkve",
 "", ""};
const char *text_JAN_31[] =
{"Sv. J�na Boska, k�aza",
 "Sv. Jana Boska, kn�ze",
 "", ""};

const char *text_FEB_02[] =
{"Obetovanie P�na",
 "Uveden� P�n� do chr�mu",
 "", ""};
const char *text_FEB_03_1[] =
{"Sv. Bla�eja, biskupa a mu�en�ka",
 "Sv. Bla�eje, biskupa a mu�edn�ka",
 "", ""};
const char *text_FEB_03_2[] =
{"Sv. Osk�ra, biskupa",
 "Sv. Ansgara, biskupa",
 "", ""};
const char *text_FEB_05[] =
{"Sv. Agaty, panny a mu�enice",
 "Sv. Ag�ty, panny a mu�ednice",
 "", ""};
const char *text_FEB_06[] =
{"Sv. Pavla Mikiho a spolo�n�kov, mu�en�kov",
 "Sv. Pavla Mikiho a druh�, mu�edn�k�",
 "", ""};
const char *text_FEB_08[] =
{"Sv. Hieronyma Emilianiho",
 "Sv. Jeron�ma Emilianiho",
 "", ""};
const char *text_FEB_08_2[] =
{"Sv. Jozef�ny Bakhita, panny",
 "Sv. Josef�ny Bakhity, panny",
 "", ""};
const char *text_FEB_10[] =
{"Sv. �kolastiky, panny",
 "Sv. Scholastiky, panny",
 "", ""};
const char *text_FEB_11[] =
{"Prebl. Panny M�rie Lurdskej",
 "Panny Marie Lurdsk�",
 "", ""};
const char *text_FEB_17[] =
{"Siedmich sv�t�ch zakladate�ov rehole Slu�obn�kov Panny M�rie",
 "Sv. Alexia a druh�, �eholn�k�",
 "", ""};
const char *text_FEB_21[] =
{"Sv. Petra Damianiho, biskupa a u�ite�a Cirkvi",
 "Sv. Petra Damianiho, biskupa a u�itele c�rkve",
 "", ""};
const char *text_FEB_22[] =
{"Katedra sv. Petra, apo�tola",
 "Stolce svat�ho Petra, apo�tola",
 "", ""};
const char *text_FEB_23[] =
{"Sv. Polykarpa, biskupa a mu�en�ka",
 "Sv. Polykarpa, biskupa a mu�edn�ka",
 "", ""};

const char *text_POPOLCOVA_STREDA[] =
{"Popolcov� streda",
 "Popele�n� s�eda",
 "", ""};

const char *text_MAR_04[] =
{"Sv. Kazim�ra",
 "Sv. Kazim�ra",
 "", ""};
const char *text_MAR_07[] =
{"Sv. Perpetuy a Felicity, mu�en�c",
 "Sv. Perpetuy a Felicity, mu�ednic",
 "", ""};
const char *text_MAR_08[] =
{"Sv. J�na z Boha, reho�n�ka",
 "Sv. Jana z Boha, �eholn�ka",
 "", ""};
const char *text_MAR_09[] =
{"Sv. Franti�ky R�mskej, reho�n��ky",
 "Sv. Franti�ky ��msk�, �eholnice",
 "", ""};
const char *text_MAR_10[] =
{"(na Slovensku nie je)",
 "Sv. Jana Ogilvie, kn�ze a mu�edn�ka",
 "", ""};
const char *text_MAR_17[] =
{"Sv. Patrika, biskupa",
 "Sv. Patrika, biskupa",
 "", ""};
const char *text_MAR_18[] =
{"Sv. Cyrila Jeruzalemsk�ho, biskupa a u�ite�a Cirkvi",
 "Sv. Cyrila Jeruzal�msk�ho, biskupa a u�itele c�rkve",
 "", ""};
const char *text_MAR_19[] =
{"Sv. Jozefa, �en�cha Panny M�rie",
 "Sv. Josefa, Snoubence Panny Marie",
 "", ""};
const char *text_MAR_23[] =
{"Sv. Turibia de Mongrovejo, biskupa",
 "Sv. Turibia z Mongroveja, biskupa",
 "", ""};
const char *text_MAR_25[] =
{"Zvestovanie P�na",
 "Zv�stov�n� P�n�",
 "", ""};

const char *text_APR_02[] =
{"Sv. Franti�ka z Pauly, pustovn�ka",
 "Sv. Franti�ka z Pauly, poustevn�ka",
 "", ""};
const char *text_APR_04[] =
{"Sv. Izidora, biskupa a u�ite�a Cirkvi",
 "Sv. Izidora, biskupa a u�itele c�rkve",
 "", ""};
const char *text_APR_05[] =
{"Sv. Vincenta Ferrera, k�aza",
 "Sv. Vincence Ferrersk�ho, kn�ze",
 "", ""};
const char *text_APR_07[] =
{"Sv. J�na Krstite�a de la Salle, k�aza",
 "Sv. Jana K�titele de la Salle, kn�ze",
 "", ""};
const char *text_APR_11[] =
{"Sv. Stanislava, biskupa a mu�en�ka",
 "Sv. Stanislava, biskupa a mu�edn�ka",
 "", ""};
const char *text_APR_13[] =
{"Sv. Martina I., p�pe�a a mu�en�ka",
 "Sv. Martina I., pape�e a mu�edn�ka",
 "", ""};
const char *text_APR_21[] =
{"Sv. Anzelma, biskupa a u�ite�a Cirkvi",
 "Sv. Anselma, biskupa a u�itele c�rkve",
 "", ""};
const char *text_APR_23[] =
{"Sv. Vojtecha, biskupa a mu�en�ka",
 "Sv. Vojt�cha, biskupa a mu�edn�ka",
 "", ""};
const char *text_APR_24_1[] =
{"Sv. Juraja, mu�en�ka",
 "Sv. Ji��, mu�edn�ka",
 "", ""};
const char *text_APR_24_2[] =
{"Sv. Fid�la zo Sigmaringenu, k�aza a mu�en�ka",
 "Sv. Fidela ze Sigmaringy, kn�ze a mu�edn�ka",
 "", ""};
const char *text_APR_25[] =
{"Sv. Marka, evanjelistu",
 "Sv. Marka, evangelisty",
 "", ""};
const char *text_APR_28_1[] =
{"Sv. Petra Chanela, k�aza a mu�en�ka",
 "Sv. Petra Chanela, kn�ze a mu�edn�ka",
 "", ""};
const char *text_APR_28_2[] =
{"Sv. �udov�ta M�rie Grignion de Montfort, k�aza",
 "Sv. Ludv�ka Marie Grignona z Montfortu, kn�ze",
 "", ""};
const char *text_APR_29[] =
{"Sv. Katar�ny Sienskej, panny a u�ite�ky Cirkvi, spolupatr�nky Eur�py",
 "Sv. Kate�iny Siensk�, panny a u�itelky c�rkve, spolupatronky Evropy",
 "", ""};
const char *text_APR_30_1[] =
{"Sv. Pia V., p�pe�a",
 "Sv. Pia V., pape�e",
 "", ""};
const char *text_APR_30_2[] =
{"(na Slovensku nie je)",
 "Sv. Zikmunda, mu�edn�ka",
 "", ""};

const char *text_MAJ_01[] =
{"Sv. Jozefa, robotn�ka",
 "Sv. Josefa, D�ln�ka",
 "", ""};
const char *text_MAJ_02[] =
{"Sv. Atan�za, biskupa a u�ite�a Cirkvi",
 "Sv. Atan�e, biskupa a u�itele c�rkve",
 "", ""};
const char *text_MAJ_03[] =
{"Sv. Filipa a Jakuba, apo�tolov",
 "Sv. Filipa a Jakuba, apo�tol�",
 "", ""};
const char *text_MAJ_06[] =
{"(na Slovensku nie je)",
 "Sv. Jana Sarkandra, kn�ze a mu�edn�ka",
 "", ""};
const char *text_MAJ_08[] =
{"(na Slovensku nie je)",
 "Panny Marie, Prost�ednice v�ech milost�",
 "", ""};
const char *text_MAJ_12_1[] =
{"Sv. Nerea a Achila, mu�en�kov",
 "Sv. Nerea a Achillea, mu�edn�k�",
 "", ""};
const char *text_MAJ_12_2[] =
{"Sv. Pankr�ca, mu�en�ka",
 "Sv. Pankr�ce, mu�edn�ka",
 "", ""};
const char *text_MAJ_12_3[] =
{"(na Slovensku nie je)",
 "V�ro�� posv�cen� katedr�ly sv. V�ta",
 "", ""};
const char *text_MAJ_14[] =
{"Sv. Mateja, apo�tola",
 "Sv. Mat�je, apo�tola",
 "", ""};
const char *text_MAJ_16[] =
{"Sv. J�na Nepomuck�ho, k�aza a mu�en�ka",
 "Sv. Jana Nepomuck�ho, kn�ze a mu�edn�ka, hlavn�ho patrona �ech",
 "", ""};
const char *text_MAJ_18[] =
{"Sv. J�na I., p�pe�a a mu�en�ka",
 "Sv. Jana I., pape�e a mu�edn�ka",
 "", ""};
const char *text_MAJ_20_1[] =
{"(na Slovensku nie je)",
 "Sv. Klementa Marie Hofbauera, kn�ze",
 "", ""};
const char *text_MAJ_20_2[] =
{"Sv. Bernard�na Siensk�ho, k�aza",
 "Sv. Bernardina Siensk�ho, kn�ze",
 "", ""};
const char *text_MAJ_21[] =
{"(na Slovensku nie je)",
 "V�ro�� posv�cen� katedr�ly sv. Petra a Pavla",
 "", ""};
const char *text_MAJ_25_1[] =
{"Sv. B�du Ctihodn�ho, k�aza a u�ite�a Cirkvi",
 "Sv. Bedy Ctihodn�ho, kn�ze a u�itele c�rkve",
 "", ""};
const char *text_MAJ_25_2[] =
{"Sv. Gregora VII., p�pe�a",
 "Sv. �eho�e VII., pape�e",
 "", ""};
const char *text_MAJ_25_3[] =
{"Sv. M�rie Magdal�ny de� Pazzi, panny",
 "Sv. Marie Magdal�ny de� Pazzi, panny",
 "", ""};
const char *text_MAJ_26[] =
{"Sv. Filipa Neriho, k�aza",
 "Sv. Filipa Neriho, kn�ze",
 "", ""};
const char *text_MAJ_27[] =
{"Sv. August�na z Canterbury, biskupa",
 "Sv. Augustina z Canterbury, biskupa",
 "", ""};
const char *text_MAJ_30[] =
{"(na Slovensku nie je)",
 "Sv. Zdislavy",
 "", ""};
const char *text_MAJ_31[] =
{"Nav�t�venie prebl. Panny M�rie", /* na Slovensku sa sl�vi 2. j�la */
 "Nav�t�ven� Panny Marie",
 "", ""};

const char *text_NANEBOVSTUPENIE_PANA[] =
{"Nanebovst�penie P�na",
 "Nanebevstoupen� P�n�",
 "", ""};
const char *text_VELKONOCNA_NEDELA[] =
{"Ve�kono�n� nede�a",
 "Ned�le Zmrtv�chvst�n� P�n�",
 "", ""};
const char *text_NEDELA_PANOVHO_ZMRTVYCHVSTANIA[] =
{" - Nede�a P�novho zm�tvychvstania",
 "", /* "Ned�le velikono�n�" */
 "", ""};
const char *text_NEDELA_VO_VELKONOCNEJ_OKTAVE[] =
{"Nede�a vo Ve�kono�nej okt�ve",
 "Ned�le v okt�vu velikono�n�m",
 "", ""};
const char *text_DEN_VO_VELKONOCNEJ_OKTAVE[] =
{"Ve�kono�n%c %s",
 "%s velikono�n�",
 "", ""};

const char *text_NAJSVATEJSEJ_TROJICE[] =
{"Najsv�tej�ej Trojice",
 "Nejsv�t�j�� Trojice",
 "", ""};
const char *text_KRISTA_KRALA[] =
{"Krista Kr�a",
 "Je��e Krista Kr�le",
 "", ""};
const char *text_NAJSV_KRISTOVHO_TELA_A_KRVI[] =
{"Najsv�tej�ieho Kristovho tela a krvi",
 "T�la a krve P�n�",
 "", ""};
const char *text_NAJSV_SRDCA_JEZISOVHO[] =
{"Najsv�tej�ieho Srdca Je�i�ovho",
 "Nejsv�t�j��ho Srdce Je��ova",
 "", ""};
const char *text_NEPOSKVRNENEHO_SRDCA_PM[] =
{"Nepo�kvrnen�ho Srdca prebl. Panny M�rie",
 "Neposkvrn�n�ho Srdce Panny Marie",
 "", ""};
const char *text_NARODENIE_PANA[] =
{"Narodenie P�na",
 "Narozen� P�n�",
 "", ""};

const char *text_ZOSLANIE_DUCHA_SVATEHO[] =
{"Zoslanie Ducha Sv�t�ho",
 "Sesl�n� Ducha svat�ho",
 "", ""};

const char *text_PRVA_ADVENTNA_NEDELA[] =
{"Prv� adventn� nede�a",
 "Prvn� ned�le adventn�",
 "", ""};
const char *text_NEDELA_SV_RODINY[] =
{"Sv�tej rodiny Je�i�a, M�rie a Jozefa",
 "Sv. Rodiny Je��e, Marie a Josefa",
 "", ""};
const char *text_SPOMIENKA_PM_V_SOBOTU[] =
{"Spomienka Panny M�rie v sobotu",
 "Sobotn� pam�tka Panny Marie",
 "", ""};

const char *text_JUN_01[] =
{"Sv. Just�na, mu�en�ka",
 "Sv. Justina, mu�edn�ka",
 "", ""};
const char *text_JUN_02[] =
{"Sv. Marcel�na a Petra, mu�en�kov",
 "Sv. Marcelina a Petra, mu�edn�k�",
 "", ""};
const char *text_JUN_03[] =
{"Sv. Karola Lwangu a spolo�n�kov, mu�en�kov",
 "Sv. Karla Lwangy a druh�, mu�edn�k�",
 "", ""};
const char *text_JUN_05[] =
{"Sv. Bonif�ca, biskupa a mu�en�ka",
 "Sv. Bonif�ce, biskupa a mu�edn�ka",
 "", ""};
const char *text_JUN_06[] =
{"Sv. Norberta, biskupa",
 "Sv. Norberta, biskupa",
 "", ""};
const char *text_JUN_09[] =
{"Sv. Efr�ma, diakona a u�ite�a Cirkvi",
 "Sv. Efr�ma Syrsk�ho, j�hna a u�itele c�rkve",
 "", ""};
const char *text_JUN_11[] =
{"Sv. Barnab�a, apo�tola",
 "Sv. Barnab�e, apo�tola",
 "", ""};
const char *text_JUN_13[] =
{"Sv. Antona Padu�nskeho, k�aza a u�ite�a Cirkvi",
 "Sv. Anton�na z Padovy, kn�ze a u�itele c�rkve",
 "", ""};
const char *text_JUN_15[] =
{"(na Slovensku nie je)",
 "Sv. V�ta, mu�edn�ka",
 "", ""};
const char *text_JUN_16[] =
{"Sv. Neita, mu�en�ka",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "", ""};
const char *text_JUN_19[] =
{"Sv. Romualda, op�ta",
 "Sv. Romualda, opata",
 "", ""};
const char *text_JUN_19_1[] =
{"(na Slovensku nie je)",
 "Sv. Jana Nepomuck�ho Neumanna, biskupa",
 "", ""};
const char *text_JUN_21[] =
{"Sv. Alojza Gonz�gu, reho�n�ka",
 "Sv. Aloise Gonzagy, �eholn�ka",
 "", ""};
const char *text_JUN_22_2[] =
{"Sv. Pavl�na z Noly, biskupa",
 "Sv. Paulina Nol�nsk�ho, biskupa",
 "", ""};
const char *text_JUN_22_1[] =
{"Sv. J�na Fishera, biskupa, a sv. Tom�a M�rusa, mu�en�kov",
 "Sv. Jana Fishera, biskupa, a Tom�e Mora, mu�edn�k�",
 "", ""};
const char *text_JUN_24[] =
{"Narodenie sv. J�na Krstite�a",
 "Narozen� svat�ho Jana K�titele",
 "", ""};
const char *text_JUN_27[] =
{"Sv. Cyrila Alexandrijsk�ho, biskupa a u�ite�a Cirkvi",
 "Sv. Cyrila Alexandrijsk�ho, biskupa a u�itele c�rkve",
 "", ""};
const char *text_JUN_27_1[] =
{"Sv. Ladislava",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "", ""};
const char *text_JUN_28[] =
{"Sv. Ireneja, biskupa a mu�en�ka",
 "Sv. Ireneje, biskupa a mu�edn�ka",
 "", ""};
const char *text_JUN_29[] =
{"Sv. Petra a Pavla, apo�tolov",
 "Sv. Petra a Pavla, apo�tol�",
 "", ""};
const char *text_JUN_30[] =
{"Prv�ch sv�t�ch mu�en�kov Cirkvi v R�me",
 "Svat�ch prvomu�edn�k� ��msk�ch",
 "", ""};
const char *text_JUN_30_1[] =
{"(na Slovensku nie je)",
 "V�ro�� posv�cen� katedr�ly sv. V�clava",
 "", ""};

const char *text_JUL_03[] =
{"Sv. Tom�a, apo�tola",
 "Sv. Tom�e, apo�tola",
 "", ""};
const char *text_JUL_04[] =
{"Sv. Al�bety Portugalskej",
 "Sv. Al�b�ty Portugalsk�",
 "", ""};
const char *text_JUL_04_1[] =
{"(na Slovensku nie je)",
 "Sv. Prokopa, opata",
 "", ""};
const char *text_JUL_05[] =
{"Sv. Cyrila a Metoda, slovansk�ch vierozvestov, apo�tolov",
 "Sv. Cyrila, mnicha, a Metod�je, biskupa, patron� Evropy, hlavn�ch patron� Moravy",
 "", ""};
const char *text_JUL_06[] =
{"Sv. M�rie Goretti, panny a mu�enice",
 "Sv. Marie Gorettiov�, panny a mu�ednice",
 "", ""};
const char *text_JUL_07[] =
{"Sv. Antona M�rie Zaccariu, k�aza",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "", ""};
const char *text_JUL_11[] =
{"Sv. Benedikta, op�ta, patr�na Eur�py",
 "Sv. Benedikta, opata, patrona Evropy",
 "", ""};
const char *text_JUL_13[] =
{"Sv. Henricha",
 "Sv. Jind�icha",
 "", ""};
const char *text_JUL_14[] =
{"Sv. Kamila de Lellis, k�aza",
 "Sv. Kamila de Lellis, kn�ze",
 "", ""};
const char *text_JUL_14_1[] =
{"(na Slovensku nie je)",
 "Bl. Hroznaty, mu�edn�ka",
 "", ""};
const char *text_JUL_15[] =
{"Sv. Bonavent�ru, biskupa a u�ite�a Cirkvi",
 "Sv. Bonaventury, biskupa a u�itele c�rkve",
 "", ""};
const char *text_JUL_16[] =
{"Prebl. Panny M�rie Karmelskej",
 "Panny Marie Karmelsk�",
 "", ""};
const char *text_JUL_16_1[] =
{"(na Slovensku nie je)",
 "V�ro�� posv�cen� katedr�ly Bo�sk�ho Spasitele",
 "", ""};
const char *text_JUL_17_1[] =
{"Sv. Andreja-Svorada a Benedikta, pustovn�kov",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "", ""};
const char *text_JUL_17_2[] =
{"(na Slovensku nie je)",
 "Bl. �eslava a sv. Hyacinta, kn��",
 "", ""};
const char *text_JUL_21[] =
{"Sv. Vavrinca z Brindisi, k�aza a u�ite�a Cirkvi",
 "Sv. Vav�ince z Brindisi, kn�ze a u�itele c�rkve",
 "", ""};
const char *text_JUL_22[] =
{"Sv. M�rie Magdal�ny",
 "Sv. Marie Magdal�ny",
 "", ""};
const char *text_JUL_23[] =
{"Sv. Brigity, reho�n��ky, spolupatr�nky Eur�py",
 "Sv. Brigity, �eholnice patronky Evropy",
 "", ""};
const char *text_JUL_25[] =
{"Sv. Jakuba, apo�tola",
 "Sv. Jakuba, apo�tola",
 "", ""};
const char *text_JUL_26[] =
{"Sv. Joachima a Anny, rodi�ov Panny M�rie",
 "Sv. J�chyma a Anny, rodi�� Panny Marie",
 "", ""};
const char *text_JUL_27[] =
{"Sv. Gorazda a spolo�n�kov",
 "Sv. Gorazda a druh�",
 "", ""};
const char *text_JUL_29[] =
{"Sv. Marty",
 "Sv. Marty",
 "", ""};
const char *text_JUL_30[] =
{"Sv. Petra Chryzol�ga, biskupa a u�ite�a Cirkvi",
 "Sv. Petra Chryzologa, biskupa a u�itele c�rkve",
 "", ""};
const char *text_JUL_30_1[] =
{"Bl. Zdenky Schelingovej, panny a mu�enice",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "", ""};
const char *text_JUL_31[] =
{"Sv. Ign�ca z Loyoly, k�aza",
 "Sv. Ign�ce z Loyoly, kn�ze",
 "", ""};

const char *text_AUG_01[] =
{"Sv. Alfonza M�rie de� Ligouri, biskupa a u�ite�a Cirkvi",
 "Sv. Alfonsa z Liguori, biskupa a u�itele c�rkve",
 "", ""};
const char *text_AUG_02_1[] =
{"Sv. Euz�bia Vercellsk�ho, biskupa",
 "Sv. Eusebia z Vercelli, biskupa",
 "", ""};
const char *text_AUG_02_2[] =
{"Sv. Petra Juli�na Eymard, k�aza",
 "Sv. Petra Juli�na Eymarda, kn�ze",
 "", ""};
const char *text_AUG_04[] =
{"Sv. J�na M�rie Vianneya, k�aza",
 "Sv. Jana Marie Vianneye, kn�ze",
 "", ""};
const char *text_AUG_05[] =
{"V�ro�ie posviacky hlavnej mari�nskej baziliky v R�me",
 "Posv�cen� ��msk� baziliky Panny Marie",
 "", ""};
const char *text_AUG_06[] =
{"Premenenie P�na",
 "Prom�n�n� P�n�",
 "", ""};
const char *text_AUG_07_1[] =
{"Sv. Sixta II., p�pe�a, a jeho spolo�n�kov, mu�en�kov",
 "Sv. Sixta II., pape�e, a druh�, mu�edn�k�",
 "", ""};
const char *text_AUG_07_2[] =
{"Sv. Kajet�na, k�aza",
 "Sv. Kajet�na, kn�ze",
 "", ""};
const char *text_AUG_08[] =
{"Sv. Dominika, k�aza",
 "Sv. Dominika, kn�ze",
 "", ""};
const char *text_AUG_09[] =
{"Sv. Ter�zie Benedikty, reho�n��ky a mu�enice, spolupatr�nky Eur�py",
 "Sv. Terezie Benedikty, panny a mu�ednice, patronky Evropy",
 "", ""};
const char *text_AUG_10[] =
{"Sv. Vavrinca, diakona a mu�en�ka",
 "Sv. Vav�ince, mu�edn�ka",
 "", ""};
const char *text_AUG_11[] =
{"Sv. Kl�ry, panny",
 "Sv. Kl�ry, panny",
 "", ""};
const char *text_AUG_12[] =
{"Sv. Jany Franti�ky de Chantal, reho�n��ky",
 "Sv. Jany Franti�ky de Chantal, �eholnice",
 "", ""};
const char *text_AUG_13[] =
{"Sv. Ponci�na, p�pe�a, a sv. Hypolita, k�aza, mu�en�kov",
 "Sv. Ponci�na, pape�e, a Hippolyta, kn�ze, mu�edn�k�",
 "", ""};
const char *text_AUG_14[] =
{"Sv. Maximili�na Kolbeho, k�aza a mu�en�ka",
 "Sv. Maxmili�na Marie Kolbeho, kn�ze a mu�edn�ka",
 "", ""};
const char *text_AUG_15[] =
{"Nanebovzatie prebl. Panny M�rie",
 "Nanebevzet� Panny Marie",
 "", ""};
const char *text_AUG_16[] =
{"Sv. �tefana Uhorsk�ho",
 "Sv. �t�p�na Uhersk�ho",
 "", ""};
const char *text_AUG_19[] =
{"Sv. J�na Eudes, k�aza",
 "Sv. Jana Eudese, kn�ze",
 "", ""};
const char *text_AUG_20[] =
{"Sv. Bernarda, op�ta a u�ite�a Cirkvi",
 "Sv. Bernarda, opata a u�itele c�rkve",
 "", ""};
const char *text_AUG_21[] =
{"Sv. Pia X., p�pe�a",
 "Sv. Pia X., pape�e",
 "", ""};
const char *text_AUG_22[] =
{"Prebl. Panny M�rie Kr�ovnej",
 "Panny Marie Kr�lovny",
 "", ""};
const char *text_AUG_23[] =
{"Sv. Ru�eny Limskej, panny",
 "Sv. R��eny z Limy, panny",
 "", ""};
const char *text_AUG_24[] =
{"Sv. Bartolomeja, apo�tola",
 "Sv. Bartolom�je, apo�tola",
 "", ""};
const char *text_AUG_25_1[] =
{"Sv. Jozefa de Calasanz, k�aza",
 "Sv. Josefa Kalasansk�ho, kn�ze",
 "", ""};
const char *text_AUG_25_2[] =
{"Sv. �udov�ta",
 "Sv. Ludv�ka",
 "", ""};
const char *text_AUG_25_3[] =
{"(na Slovensku nie je)",
 "Sv. Benedikta, Jana, Matou�e, Iz�ka a Kristina, mu�edn�k�",
 "", ""};
const char *text_AUG_27[] =
{"Sv. Moniky",
 "Sv. Moniky",
 "", ""};
const char *text_AUG_28[] =
{"Sv. August�na, biskupa a u�ite�a Cirkvi",
 "Sv. Augustina, biskupa a u�itele c�rkve",
 "", ""};
const char *text_AUG_29[] =
{"Mu�en�cka smr� sv. J�na Krstite�a",
 "Umu�en� svat�ho Jana K�titele",
 "", ""};
const char *text_AUG_30[] =
{"V�ro�ie posviacky katedr�lneho chr�mu v Trnave",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "", ""};

const char *text_SEP_03[] =
{"Sv. Gregora Ve�k�ho, p�pe�a a u�ite�a Cirkvi",
 "Sv. �eho�e Velik�ho, pape�e a u�itele c�rkve",
 "", ""};
const char *text_SEP_06[] =
{"V�ro�ie posviacky katedr�lneho chr�mu v Ko�iciach",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "", ""};
const char *text_SEP_07[] =
{"Sv. Marka Kri�ina, Melichara Grodzieck�ho a �tefana Pongr�cza, k�azov a mu�en�kov",
 "Sv. Melichara Grodeck�ho, kn�ze a mu�edn�ka",
 "", ""};
const char *text_SEP_08[] =
{"Narodenie prebl. Panny M�rie",
 "Narozen� Panny Marie",
 "", ""};
const char *text_SEP_09[] =
{"Sv. Petra Clavera, k�aza",
 "Sv. Petra Klavera, kn�ze",
 "", ""};
const char *text_SEP_10[] =
{"(na Slovensku nie je)",
 "Bl. Karla Spinoly, kn�ze a mu�edn�ka",
 "", ""};
const char *text_SEP_12[] =
{"Mena prebl. Panny M�rie",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "", ""};
const char *text_SEP_13[] =
{"Sv. J�na Zlato�steho, biskupa a u�ite�a Cirkvi",
 "Sv. Jana Zlato�st�ho, biskupa a u�itele c�rkve",
 "", ""};
const char *text_SEP_14[] =
{"Pov��enie sv�t�ho kr�a",
 "Pov��en� svat�ho k��e",
 "", ""};
const char *text_SEP_15[] =
{"Sedembolestnej Panny M�rie, patr�nky Slovenska",
 "Panny Marie Bolestn�",
 "", ""};
const char *text_SEP_16_CZ[] =
{"(na Slovensku nie je)",
 "Sv. Ludmily, mu�ednice",
 "", ""};
const char *text_SEP_16[] =
{"Sv. Korn�lia, p�pe�a, a sv. Cypri�na, biskupa, mu�en�kov",
 "Sv. Korn�lia, pape�e, a Cypri�na, biskupa, mu�edn�k�",
 "", ""};
const char *text_SEP_17[] =
{"Sv. R�berta Bellarm�na, biskupa a u�ite�a Cirkvi",
 "Sv. Roberta Bellarmina, biskupa a u�itele c�rkve",
 "", ""};
const char *text_SEP_19[] =
{"Sv. Janu�ra, biskupa a mu�en�ka",
 "Sv. Janu�ria, biskupa a mu�edn�ka",
 "", ""};
const char *text_SEP_20[] =
{"Sv. Andreja Kim Taegona, k�aza, a sv. Pavla Chong Hasanga a spolo�n�kov, mu�en�kov",
 "Sv. Ond�eje Kim Taegona, kn�ze, Pavla Chong Hasanga a druh�, mu�edn�k�",
 "", ""};
const char *text_SEP_20_2[] =
{"(na Slovensku nie je)",
 "V�ro�� posv�cen� katedr�ly sv. �t�p�na",
 "", ""};
const char *text_SEP_21[] =
{"Sv. Mat��a, apo�tola a evanjelistu",
 "Sv. Matou�e, apo�tola a evangelisty",
 "", ""};
const char *text_SEP_22[] =
{"Sv. Emer�ma, biskupa a mu�en�ka",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "", ""};
const char *text_SEP_23[] =
{"Sv. Pia z Pietrel�iny, k�aza",
 "Sv. Pia z Pietrelciny, kn�ze",
 "", ""};
const char *text_SEP_24[] =
{"V�ro�ie posviacky katedr�lneho chr�mu v Banskej Bystrici",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "", ""};
const char *text_SEP_26[] =
{"Sv. Kozmu a Dami�na, mu�en�kov",
 "Sv. Kosmy a Dami�na, mu�edn�k�",
 "", ""};
const char *text_SEP_27[] =
{"Sv. Vincenta de Paul, k�aza",
 "Sv. Vincence z Paula, kn�ze",
 "", ""};
const char *text_SEP_28[] =
{"Sv. V�clava, mu�en�ka",
 "Sv. V�clava, mu�edn�ka, hlavn�ho patrona �esk�ho n�roda",
 "", ""};
const char *text_SEP_28_2[] =
{"Sv. Vavrinca Ruiza a spolo�n�kov, mu�en�kov",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "", ""};
const char *text_SEP_29[] =
{"Sv. Michala, Gabriela a Rafaela, archanjelov",
 "Sv. Michaela, Gabriela a Rafaela, archand�l�",
 "", ""};
const char *text_SEP_30[] =
{"Sv. Hieronyma, k�aza a u�ite�a Cirkvi",
 "Sv. Jeron�ma, kn�ze a u�itele c�rkve",
 "", ""};

const char *text_OKT_01[] =
{"Sv. Ter�zie z Lisieux, panny a u�ite�ky Cirkvi",
 "Sv. Terezie od D�t�te Je��e, panny",
 "", ""};
const char *text_OKT_02[] =
{"Sv�t�ch anjelov str�cov",
 "Svat�ch and�l� str�n�ch",
 "", ""};
const char *text_OKT_04[] =
{"Sv. Franti�ka Assisk�ho",
 "Sv. Franti�ka z Assisi",
 "", ""};
const char *text_OKT_06[] =
{"Sv. Bruna, k�aza",
 "Sv. Bruna, kn�ze",
 "", ""};
const char *text_OKT_07[] =
{"Ru�encovej prebl. Panny M�rie",
 "Panny Marie R��encov�",
 "", ""};
const char *text_OKT_09_1[] =
{"Sv. Dion�zia, biskupa, a spolo�n�kov, mu�en�ka",
 "Sv. Dion�sia, biskupa, a druh�, mu�edn�k�",
 "", ""};
const char *text_OKT_09_2[] =
{"Sv. J�na Leonardiho, k�aza",
 "Sv. Jana Leonardiho, kn�ze",
 "", ""};
const char *text_OKT_12[] =
{"(na Slovensku nie je)",
 "Sv. Radima, biskupa",
 "", ""};
const char *text_OKT_14[] =
{"Sv. Kalixta I., p�pe�a a mu�en�ka",
 "Sv. Kalista I., pape�e a mu�edn�ka",
 "", ""};
const char *text_OKT_15[] =
{"Sv. Ter�zie z Avily, panny a u�ite�ky Cirkvi",
 "Sv. Terezie od Je��e, panny a u�itelky c�rkve",
 "", ""};
const char *text_OKT_16_2[] =
{"Sv. Hedvigy, reho�n��ky",
 "Sv. Hedviky, �eholnice, hlavn� patronky Slezska",
 "", ""};
const char *text_OKT_16_1[] =
{"Sv. Margity M�rie Alacoque, panny",
 "Sv. Mark�ty Marie Alacoque, panny",
 "", ""};
const char *text_OKT_17[] =
{"Sv. Ign�ca Antiochijsk�ho, biskupa a mu�en�ka",
 "Sv. Ign�ce Antiochijsk�ho, biskupa a mu�edn�ka",
 "", ""};
const char *text_OKT_18[] =
{"Sv. Luk�a, evanjelistu",
 "Sv. Luk�e, evangelisty",
 "", ""};
const char *text_OKT_19_1[] =
{"Sv. J�na de Br�beuf a sv. Iz�ka Jogues, k�azov, a ich spolo�n�kov, mu�en�kov",
 "Sv. Jana de Br�beuf a Iz�ka Joguese, kn��, a druh�, mu�edn�k�",
 "", ""};
const char *text_OKT_19_2[] =
{"Sv. Pavla z Kr�a, k�aza",
 "Sv. Pavla od K��e, kn�ze",
 "", ""};
const char *text_OKT_23[] =
{"Sv. J�na Kapistr�nskeho, k�aza",
 "Sv. Jana Kapistr�nsk�ho, kn�ze",
 "", ""};
const char *text_OKT_24[] =
{"Sv. Antona M�rie Clareta, biskupa",
 "Sv. Anton�na Marie Klareta, biskupa",
 "", ""};
const char *text_OKT_25[] =
{"V�ro�ie posviacky katedr�lneho chr�mu v Spi�skom Podhrad�",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "", ""};
const char *text_OKT_26[] =
{"V�ro�ie posviacky chr�mov, ktor�ch de� posviacky je nezn�my",
 "V�ro�� posv�cen� chr�mu, jejich� den dedikace nen� zn�m�",
 "", ""};
const char *text_OKT_27[] =
{"V�ro�ie posviacky katedr�lneho chr�mu v Ro��ave",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "", ""};
const char *text_OKT_28[] =
{"Sv. �imona a J�du, apo�tolov",
 "Sv. �imona a Judy, apo�tol�",
 "", ""};
const char *text_OKT_30[] =
{"(na Slovensku nie je)",
 "V�ro�� posv�cen� katedr�ly Svat�ho Ducha",
 "", ""};
const char *text_OKT_31[] =
{"(na Slovensku nie je)",
 "Sv. Wolfganga, biskupa",
 "", ""};

const char *text_NOV_01[] =
{"V�etk�ch sv�t�ch",
 "V�ech svat�ch",
 "", ""};
const char *text_NOV_02[] =
{"V�etk�ch vern�ch zosnul�ch",
 "Vzpom�nka na v�echny v�rn� zem�el�",
 "", ""};
const char *text_NOV_03[] =
{"Sv. Martina de Porres, reho�n�ka",
 "Sv. Martina de Porres, �eholn�ka",
 "", ""};
const char *text_NOV_04[] =
{"Sv. Karola Borromea, biskupa",
 "Sv. Karla Boromejsk�ho, biskupa",
 "", ""};
const char *text_NOV_05[] =
{"Sv. Imricha",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "", ""};
const char *text_NOV_09[] =
{"V�ro�ie posviacky Later�nskej baziliky",
 "Posv�cen� later�nsk� baziliky",
 "", ""};
const char *text_NOV_10[] =
{"Sv. Leva Ve�k�ho, p�pe�a a u�ite�a Cirkvi",
 "Sv. Lva Velik�ho, pape�e a u�itele c�rkve",
 "", ""};
const char *text_NOV_11[] =
{"Sv. Martina z Tours, biskupa",
 "Sv. Martina, biskupa",
 "", ""};
const char *text_NOV_12[] =
{"Sv. Jozaf�ta, biskupa a mu�en�ka",
 "Sv. Josafata, biskupa a mu�edn�ka",
 "", ""};
const char *text_NOV_13[] =
{"(na Slovensku nie je)",
 "Sv. Ane�ky �esk�, panny",
 "", ""};
const char *text_NOV_15[] =
{"Sv. Alberta Ve�k�ho, biskupa a u�ite�a Cirkvi",
 "Sv. Alberta Velik�ho, biskupa a u�itele c�rkve",
 "", ""};
const char *text_NOV_16_1[] =
{"Sv. Margity �k�tskej",
 "Sv. Mark�ty Skotsk�",
 "", ""};
const char *text_NOV_16_2[] =
{"Sv. Gertr�dy, panny",
 "Sv. Gertrudy, panny",
 "", ""};
const char *text_NOV_17[] =
{"Sv. Al�bety Uhorskej, reho�n��ky",
 "Sv. Al�b�ty Uhersk�, �eholnice",
 "", ""};
const char *text_NOV_18[] =
{"V�ro�ie posviacky bazil�k sv. Petra a sv. Pavla, apo�tolov",
 "Posv�cen� ��msk�ch bazilik svat�ch apo�tol� Petra a Pavla",
 "", ""};
const char *text_NOV_20[] =
{"V�ro�ie posviacky katedr�lneho chr�mu v Nitre",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "", ""};
const char *text_NOV_21[] =
{"Obetovanie prebl. Panny M�rie",
 "Zasv�cen� Panny Marie v Jeruzal�m�",
 "", ""};
const char *text_NOV_22[] =
{"Sv. Cec�lie, panny a mu�enice",
 "Sv. Cecilie, panny a mu�ednice",
 "", ""};
const char *text_NOV_23_1[] =
{"Sv. Klementa I. p�pe�a a mu�en�ka",
 "Sv. Klementa I., pape�e a mu�edn�ka",
 "", ""};
const char *text_NOV_23_2[] =
{"Sv. Kolumb�na, op�ta",
 "Sv. Kolumb�na, opata",
 "", ""};
const char *text_NOV_24[] =
{"Sv. Ondreja Dung-Laca a spolo�n�kov, mu�en�kov",
 "Sv. Ond�eje Dung-Laca, kn�ze, a druh�, mu�edn�k�",
 "", ""};
const char *text_NOV_25[] =
{"Sv. Katar�ny Alexandrijskej, panny a mu�enice",
 "(v �ech�ch, na Morav� a na Slezsku nen�)",
 "", ""};
const char *text_NOV_30[] =
{"Sv. Ondreja, apo�tola",
 "Sv. Ond�eje, apo�tola",
 "", ""};

const char *text_DEC_01[] =
{"(na Slovensku nie je)",
 "Sv. Edmunda Kampi�na, kn�ze a mu�edn�ka",
 "", ""};
const char *text_DEC_02[] =
{"(na Slovensku nie je)",
 "V�ro�� posv�cen� katedr�ly sv. Bartolom�je",
 "", ""};
const char *text_DEC_03[] =
{"Sv. Franti�ka Xaversk�ho, k�aza",
 "Sv. Franti�ka Xaversk�ho, kn�ze",
 "", ""};
const char *text_DEC_04[] =
{"Sv. J�na Damasc�nskeho, k�aza a u�ite�a Cirkvi",
 "Sv. Jana Dama�sk�ho, kn�ze a u�itele c�rkve",
 "", ""};
const char *text_DEC_06[] =
{"Sv. Mikul�a, biskupa",
 "Sv. Mikul�e, biskupa",
 "", ""};
const char *text_DEC_07[] =
{"Sv. Ambr�za, biskupa a u�ite�a Cirkvi",
 "Sv. Ambro�e, biskupa a u�itele c�rkve",
 "", ""};
const char *text_DEC_08[] =
{"Nepo�kvrnen� po�atie Panny M�rie",
 "Panny Marie, po�at� bez poskvrny prvotn�ho h��chu",
 "", ""};
const char *text_DEC_11[] =
{"Sv. Damaza I., p�pe�a",
 "Sv. Damasa I., pape�e",
 "", ""};
const char *text_DEC_13[] =
{"Sv. Lucie, panny a mu�enice",
 "Sv. Lucie, panny a mu�ednice",
 "", ""};
const char *text_DEC_14[] =
{"Sv. J�na z Kr�a, k�aza a u�ite�a Cirkvi",
 "Sv. Jana od K��e, kn�ze a u�itele c�rkve",
 "", ""};
const char *text_DEC_21[] =
{"Sv. Petra Kan�zia, k�aza a u�ite�a Cirkvi",
 "Sv. Petra Kanisia, kn�ze a u�itele c�rkve",
 "", ""};
const char *text_DEC_22[] =
{"(na Slovensku nie je)",
 "V�ro�� posv�cen� katedr�ly Sv. Mikul�e",
 "", ""};
const char *text_DEC_23[] =
{"Sv. J�na Kentsk�ho, k�aza",
 "Sv. Jana Kentsk�ho, kn�ze",
 "", ""};
const char *text_DEC_26[] =
{"Sv. �tefana, prv�ho mu�en�ka",
 "Sv. �t�p�na, prvomu�edn�ka",
 "", ""};
const char *text_DEC_27[] =
{"Sv. J�na, apo�tola a evanjelistu",
 "Sv. Jana, apo�tola a evangelisty",
 "", ""};
const char *text_DEC_28[] =
{"Sv�t�ch Neviniatok, mu�en�kov",
 "Svat�ch Ml���tek, mu�edn�k�",
 "", ""};
const char *text_DEC_29[] =
{"Sv. Tom�a Becketa, biskupa a mu�en�ka",
 "Sv. Tom�e Becketa, biskupa a mu�edn�ka",
 "", ""};
const char *text_DEC_31[] =
{"Sv. Silvestra I., p�pe�a",
 "Sv. Silvestra I., pape�e",
 "", ""};

const char *text_ZELENY_STVRTOK[] =
{"Zelen� (ve�k�) �tvrtok - Pamiatka P�novej ve�ere",
 "Zelen� �tvrtek - Pam�tka Ve�e�e P�n�",
 "", ""};
const char *text_VELKY_PIATOK[] =
{"Ve�k� piatok",
 "Velk� p�tek",
 "", ""};
const char *text_BIELA_SOBOTA[] =
{"Biela (ve�k�) sobota",
 "B�l� sobota",
 "", ""};
const char *text_KVETNA_NEDELA[] =
{"Kvetn� nede�a",
 "Kv�tn� ned�le",
 "", ""};

#endif /* __HODIN_H */
