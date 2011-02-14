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
/*                                                             */
/*                                                             */
/***************************************************************/

#include "liturgia.h"

const char *TEMPLAT[] =
{TEMPLAT_INVITATORIUM, TEMPLAT_RANNE_CHVALY, TEMPLAT_POSV_CITANIE,
 TEMPLAT_CEZ_DEN_9, TEMPLAT_CEZ_DEN_12, TEMPLAT_CEZ_DEN_3,
 TEMPLAT_VESPERY, TEMPLAT_KOMPLETORIUM};

const char *nazov_modlitby[] =
{"invitat�rium", "rann� chv�ly", "posv�tn� ��tanie",
 "modlitba predpoludn�m", "modlitba napoludnie", "modlitba popoludn�",
 "ve�pery", "komplet�rium", "neur�en�",
 "prv� ve�pery", "prv� komplet�rium",
 "druh� ve�pery", "druh� komplet�rium",
 "detaily"};

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
{"ve�kono�n� okt�va", "adventn� obdobie", "adventn� obdobie",
 "viano�n� obdobie", "viano�n� obdobie", "obdobie �cez rok�",
 "p�stne obdobie", "Ve�k� t��de�",
 "ve�kono�n� trojdnie", "ve�kono�n� obdobie", "ve�kono�n� obdobie",
 "okt�va Narodenia P�na"};
const char *nazov_obdobia_[] = // debuggovacie
{"ve�kono�n� okt�va", "adventn� obdobie I", "adventn� obdobie II",
 "viano�n� obdobie I", "viano�n� obdobie II", "obdobie �cez rok�",
 "p�stne obdobie I", "Ve�k� t��de�",
 "ve�kono�n� trojdnie", "ve�kono�n� obdobie I", "ve�kono�n� obdobie II",
 "okt�va Narodenia P�na"};
/* lokal == 6. pad, v kom/com */
const char *nazov_obdobia_v[] =
{"vo ve�kono�nej okt�ve", "v adventnom obdob�", "v adventnom obdob�",
 "vo viano�nom obdob�", "vo viano�nom obdob�", "v obdob� �cez rok�",
 "v p�stnom obdob�", "vo Ve�kom t��dni",
 "vo ve�kono�nom trojdn�", "vo ve�kono�nom obdob�", "vo ve�kono�nom obdob�",
 "v okt�ve Narodenia P�na"};
const char *nazov_OBDOBIA_V[] =
{"VO VE�KONO�NEJ OKT�VE", "V ADVENTNOM OBDOB�", "V ADVENTNOM OBDOB�",
 "VO VIANO�NOM OBDOB�", "VO VIANO�NOM OBDOB�", "V OBDOB� �CEZ ROK�",
 "V P�STNOM OBDOB�", "VO VE�KOM TݎDNI",
 "VO VE�KONO�NOM TROJDN�", "VO VE�KONO�NOM OBDOB�", "VO VE�KONO�NOM OBDOB�",
 "V OKT�VE NARODENIA P�NA"};
/* gen[itiv] == 2. pad, koho/coho */
const char *nazov_obdobia_gen[] =
{"ve�kono�nej okt�vy", "adventn�ho obdobia", "adventn�ho obdobia",
 "viano�n�ho obdobia", "viano�n�ho obdobia", "obdobia �cez rok�",
 "p�stneho obdobia", "Ve�k�ho t��d�a",
 "ve�kono�n�ho trojdnia", "ve�kono�n�ho obdobia", "ve�kono�n�ho obdobia",
 "okt�vy Narodenia P�na"};
/*
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

const char *nazov_slavenia[] =
{"___",
 "sl�vnos�", "sviatok", "spomienka", "�ubovo�n� spomienka",
 "vlastn� sl�venie"};
const char *nazov_Slavenia[] =
{"___",
 "Sl�vnos�", "Sviatok", "Spomienka", "�ubovo�n� spomienka",
 "Vlastn� sl�venie"};

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
,"Druh� ve�kono�n� nede�a"
,"koniec Okt�vy narodenia P�na"
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
{"nede�a", "pondelok", "utorok", "streda",
 "�tvrtok", "piatok", "sobota", "nezn�my"};
const char *nazov_dna_asci[] =
{"nedela", "pondelok", "utorok", "streda",
 "stvrtok", "piatok", "sobota", "neznamy"};
const char *nazov_Dna[] =
{"Nede�a", "Pondelok", "Utorok", "Streda",
 "�tvrtok", "Piatok", "Sobota", "Nezn�my"};
const char *nazov_DNA[] =
{"NEDE�A", "PONDELOK", "UTOROK", "STREDA",
 "�TVRTOK", "PIATOK", "SOBOTA", "NEZN�MY"};
const char *nazov_Dn[] =
{"Ne", "Po", "Ut", "St", "�t", "Pi", "So", "??"};
const char *nazov_DN_asci[] =
{"NE", "PO", "UT", "STR", "STV", "PI", "SO", "??"};
const char *nazov_dn_asci[] =
{"ne", "po", "ut", "str", "stv", "pi", "so", "??"};

/* nazov_mesiaca: string pre nazov dna; suhlasi s struct tm.tm_mon;
 * Month (0--11) */
const char *nazov_mesiaca[] =
{"janu�r", "febru�r", "marec", "apr�l", "m�j", "j�n", "j�l",
 "august", "september", "okt�ber", "november", "december", "nezn�my"};
const char *nazov_mesiaca_asci[] =
{"januar", "februar", "marec", "april", "maj", "jun", "jul",
 "august", "september", "oktober", "november", "december", "neznamy"};
const char *nazov_Mesiaca[] =
{"Janu�r", "Febru�r", "Marec", "Apr�l", "M�j", "J�n", "J�l",
 "August", "September", "Okt�ber", "November", "December", "Nezn�my"};
const char *nazov_MESIACA[] =
{"JANU�R", "FEBRU�R", "MAREC", "APR�L", "M�J", "J�N", "J�L",
 "AUGUST", "SEPTEMBER", "OKT�BER", "NOVEMBER", "DECEMBER", "NEZN�MY"};
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
