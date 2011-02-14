/***************************************************************/
/*                                                             */
/* mydefs.h                                                    */
/* (c)1999-2009 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | obsahuje zakladne define'y                    */
/* document history                                            */
/*   12/11/1999A.D. | created                                  */
/*   01/02/2000A.D. | modifikovane                             */
/*   09/02/2000A.D. | pridane PRM_DETAILY                      */
/*   06/09/2001A.D. | zmenene SCRIPT_PATH(a) UNCGI_PATH(a),    */
/*                    tento popis                              */
/*   2003-07-02a.D. | pridane HTML konstanty (casti stringov)  */
/*   2003-07-04a.D. | pridane konstanty pre batch mode         */
/*   2003-07-08a.D. | pridana konstanta MODL_OPT_APPEND        */
/*   2003-07-09a.D. | pridane #define HTML_AMPERSAND "&amp;"   */
/*   2003-07-15a.D. | zluceny s mybase.h, vycistene komentare  */
/*                  - pridane HTML_BUTTON_                     */
/*   2003-07-16a.D. | zmena WWW_ na ADD_WWW_PREFIX_            */
/*   2004-03-17a.D. | FILE_PATH sa nepouziva                   */
/*   2004-08-14a.D. | zmena definicie ADD_WWW_PREFIX_          */
/*   2005-03-28a.D. | zmena definicie UNCGI_PATH               */
/*   2005-07-27a.D. | pridane HTML_SPAN_RED_SMALL              */
/*   2006-07-11a.D. | prvé kroky k jazykovým mutáciám          */
/*   2006-08-18a.D. | zmena int na short int (staèí 32tis.)    */
/*   2008-11-29a.D. | pridané rôzne možnosti batch exportu     */
/*                                                             */
/*                                                             */
/***************************************************************/

#include "vstudio.h"

#ifndef __MYDEFS_H_
#define __MYDEFS_H_

#include "mysystem.h" /* tam pozri exportovanie, logovanie, system */
#include "myconf.h" /* kvoli cfg_MAIL_ADDRESS_default, cfg_HTTP_ADDRESS_default; pridane 30/03/2000A.D. */

#if defined(OS_linux)
#elif defined(OS_Windows)
#elif defined(OS_Windows_Ruby)
#else
	#error Unsupported operating system (not defined in mysystem.h)
#endif

/***************************************************************/
/*                                                             */
/* mybase.h                                                    */
/* (c)1999-2009 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | obsahuje zakladne vecicky                     */
/* document history                                            */
/*   29/10/1999A.D. | created                                  */
/*   06/09/2001A.D. | tento popis                              */
/*   2003-06-30a.D. | build (priliepa sa do hlavicky)          */
/*   2003-07-15a.D. | RUN_MODLITBA_CEZ_DEN definovane          */
/*   2003-07-15a.D. | vlozeny do mydefs.h                      */
/*   2003-08-13a.D. | odstranenie RUN_MODLITBA_CEZ_DEN         */
/*                                                             */
/***************************************************************/
#include <stdio.h>

#define BUILD_DATE "2009-01-05"

#define BYTES 250
#define SMALL 80

/* neurèená hodnota pre global option */
#define GLOBAL_OPTION_NULL -1

/* navratova hodnota funkcii */
#define NO_RESULT 2
#define FAILURE 1
#define SUCCESS 0

/* true -- false */
#define TRUE  1
#define FALSE 0
#define ANO   1
#define NIE   0

#define MAX_STR				300 /* maximalna dlzka retazca */
#define MAX_GLOBAL_STR		300 /* _global_string */ /* 31/03/2000A.D. */
#define MAX_GLOBAL_STR2		20 /* _global_string2, pridané 2006-08-19 */
#define MAX_GLOBAL_STR_FARBA 150 /* _global_string_farba, pridané 2006-08-19 */
#define MAX_QUERY_STR		300 /* query_string */
#define MAX_POM_QUERY_TYPE	300 /* pom_QUERY_TYPE */
#define MAX_GLOBAL_LINK		300 /* maximalna dlzka retazca _global_link */
//#define MAX_ENV	100 /* maximalna dlzka environmentalnej premennej */ /* 2006-08-01: nepoužíva sa */
#define MAX_VARIABLES		20 /* maximalny pocet syst. premennych WWW_..., zvyseny 2003-08-07 a opätovne 2006-08-01 */
#define MAX_GLOBAL_BUFFER	500 /* _global_buf, pridané 2005-08-01 */
/***************************************************************/
/* EOF of former file mybase.h                                 */
/***************************************************************/

/* Nazvy programov, suborov, skriptov... */
#define SCRIPT_NAME          "l.cgi" /* kedysi tu bolo dnes.cgi */
#define SCRIPT_PATH(a)       "cgi-bin/"a
	/* zmenene 06/09/2001A.D.; povodne tu bolo "cgi-bin/"##a */

#if defined(USE_UNCGI)
#define UNCGI_PATH(a)        SCRIPT_PATH("uncgi.cgi/")a
#else
#define UNCGI_PATH(a)        SCRIPT_PATH(a)
#endif
	/* zmenene 06/09/2001A.D.; povodne tu bolo SCRIPT_PATH("uncgi.cgi/")##a */
	/* 2005-03-28: Zapoznamkovane (pokus) */

#define UNCGI_SCRIPT_NAME    UNCGI_PATH(SCRIPT_NAME)
#define PATH_CGI(a) "cgi-bin/"a
	/* zmenene 06/09/2001A.D.; povodne tu bolo "cgi-bin/"##a */

/* pridane 30/03/2000A.D. */
extern char script_name[MAX_STR]; // = cfg_HTTP_ADDRESS_default + SCRIPT_PATH(SCRIPT_NAME)
extern char uncgi_name[MAX_STR];  // = cfg_HTTP_ADDRESS_default + UNCGI_SCRIPT_NAME
void updateScriptName(void);
void updateUnCGIName(void);

/* tu kedysi bolo aj #define PATH(a) zvacsa a, ale nebolo to treba; vyhodene 2003-07-02 */

/* 2004-03-17
 * FILE_PATH nie je potrebne; citame to z myconf.cpp::readConfig() (config file)
extern char FILE_PATH[MAX_STR]; // inicializovane v breviar.cpp
 */

#define MESSAGE_FOLDER "msg/"
#define FILE_PRESTUPNY_ROK		MESSAGE_FOLDER"prestupn.htm"
#define FILE_JULIANSKY_DATUM	MESSAGE_FOLDER"juldat.htm"
#define FILE_NEDELNE_PISMENO	MESSAGE_FOLDER"nedpism.htm"
#define FILE_LITURGICKY_ROK	    MESSAGE_FOLDER"lr_pism.htm"
#define FILE_NAME_POKEC         MESSAGE_FOLDER"xxx"
#define FILE_NAME_CHYBA         MESSAGE_FOLDER"chyba.htm"

extern short int query_type; /* premenna obsahujuca PRM_... */
/* deklarovana tu; definovana v dnes.cpp (18/02/2000A.D.) */

/* meno skriptu nasleduje zoznam parametrov, alebo sa precitaju z form */
#define 	SCRIPT_PARAM_FROM_FORM     200 /* z formulara */
#define 	SCRIPT_PARAM_FROM_QS	   201 /* z query string (sys variable) */
#define 	SCRIPT_PARAM_FROM_ARGV	   202 /* z argumentov */

/* nasleduju typy dotazov */
#define PRM_UNKNOWN		 100
#define PRM_NONE		 110

#define PRM_SIMULACIA_QS 12 /* 24/02/2000A.D. */
#ifdef LONG_PARAM_NAMES
	#define STR_PRM_SIMULACIA_QS "PRM_SIMULACIA_QS"
#else
	#define STR_PRM_SIMULACIA_QS "psqs"
#endif

#define PRM_TABULKA 13 /* 15/03/2000A.D. */
#ifdef LONG_PARAM_NAMES
	#define STR_PRM_TABULKA "PRM_TABULKA"
#else
	#define STR_PRM_TABULKA "ptab"
#endif

#define PRM_DATUM   	0 /* dotaz na konkretny datum */
#ifdef LONG_PARAM_NAMES
	#define STR_PRM_DATUM "PRM_DATUM"
#else
	#define STR_PRM_DATUM "pdt"
#endif

#define PRM_CEZ_ROK 	1    /* dotaz na napr. piatok v tretom tyzdni */
#ifdef LONG_PARAM_NAMES
	#define STR_PRM_CEZ_ROK "PRM_CEZ_ROK"
#else
	#define STR_PRM_CEZ_ROK "pcr"
#endif

#define PRM_SVIATOK 	2    /* dotaz na konkretny sviatok */
#ifdef LONG_PARAM_NAMES
	#define STR_PRM_SVIATOK "PRM_SVIATOK"
#else
	#define STR_PRM_SVIATOK "psv"
#endif

#define PRM_ANALYZA_ROKU 	3   /* dotaz na sviatky v roku */
#ifdef LONG_PARAM_NAMES
	#define STR_PRM_ANALYZA_ROKU  "PRM_ANALYZA_ROKU"
#else
	#define STR_PRM_ANALYZA_ROKU  "par"
#endif

#define PRM_DNES 4 /* to, co bolo kedysi bez parametra - info o dnesnom dni */
#ifdef LONG_PARAM_NAMES
	#define STR_PRM_DNES "PRM_DNES"
#else
	#define STR_PRM_DNES "pdnes"
#endif

#define PRM_MESIAC_ROKA 17
#ifdef LONG_PARAM_NAMES
	#define STR_PRM_MESIAC_ROKA "PRM_MESIAC_ROKA"
#else
	#define STR_PRM_MESIAC_ROKA "pmr"
#endif

/* pridana konstanta pre batch mode; 2003-07-04 */
#define PRM_BATCH_MODE 21
#ifdef LONG_PARAM_NAMES
	#define STR_PRM_BATCH_MODE "PRM_BATCH_MODE"
#else
	#define STR_PRM_BATCH_MODE "pbm"
#endif

/* nasleduju parametre z formularov pre vsetky typy dotazov,
 * kedysi bolo pre kazdy STR_... definovane WWW_STR_...,
 * teraz ADD_WWW_PREFIX_(STR_...) 
 * 
 * 2004-08-14, duurko
 * definicia ADD_WWW_PREFIX_(a) ("WWW_"##a) 
 * ktora bola OK na g++ (gcc version 2.95.4 20011002)
 * sposobovala problemy 
 * na g++ (gcc version 3.3.3 20040412)
 * preto zmenene na ADD_WWW_PREFIX_(a) ("WWW_"a)
 */
#define WWW_PREFIX "WWW_"
#define ADD_WWW_PREFIX_(a) ("WWW_"a)

/* nasleduju parametre z formularov pre dotaz PRM_DATUM */
#define DEN 3 /* dotaz na konkretny datum */
#ifdef LONG_PARAM_NAMES
	#define STR_DEN "DEN"
#else
	#define STR_DEN "d"
#endif

#define MESIAC 4 /* dotaz na konkretny datum */
#ifdef LONG_PARAM_NAMES
	#define STR_MESIAC "MESIAC"
#else
	#define STR_MESIAC "m"
#endif

#define ROK 5 /* dotaz na konkretny datum */
#ifdef LONG_PARAM_NAMES
	#define STR_ROK "ROK"
#else
	#define STR_ROK "r"
#endif

#define MODLITBA 15
#ifdef LONG_PARAM_NAMES
	#define STR_MODLITBA "MODLITBA"
#else
	#define STR_MODLITBA "p"
#endif

#define DALSI_SVATY 16
#ifdef LONG_PARAM_NAMES
	#define STR_DALSI_SVATY  "DALSI_SVATY"
#else
	#define STR_DALSI_SVATY  "ds"
#endif

/* nasleduju parametre z formularov pre dotaz PRM_CEZ_ROK */
#define DEN_V_TYZDNI 6         /* dotaz na konkretny den */
#ifdef LONG_PARAM_NAMES
	#define STR_DEN_V_TYZDNI "DEN_V_TYZDNI"
#else
	#define STR_DEN_V_TYZDNI "dvt"
#endif

#define TYZDEN	7               /* dotaz na konkretny tyzden */
#ifdef LONG_PARAM_NAMES
	#define STR_TYZDEN "TYZDEN"
#else
	#define STR_TYZDEN "t"
#endif

/* nasleduju parametre z formularov pre dotaz PRM_SVIATOK */
#define NAZOV_SVIATOK 8
#ifdef LONG_PARAM_NAMES
	#define STR_NAZOV_SVIATOK "SVIATOK"
#else
	#define STR_NAZOV_SVIATOK "s"
#endif

/* nasleduju parametre z formularov pre dotaz PRM_ANALYZA_ROKU */
#define ANALYZA_ROKU 9
#ifdef LONG_PARAM_NAMES
	#define STR_ANALYZA_ROKU "ANALYZA_ROKU"
#else
	#define STR_ANALYZA_ROKU "ar"
#endif

/* nasleduju parametre z formularov pre dotaz PRM_MESIAC_ROKA */
#define MESIAC_ROKA 17
#ifdef LONG_PARAM_NAMES
	#define STR_MESIAC_ROKA "MESIAC_ROKA"
#else
	#define STR_MESIAC_ROKA "mr"
#endif

#define ROK_ROKA 18
#ifdef LONG_PARAM_NAMES
	#define STR_ROK_ROKA "ROK_ROKA"
#else
	#define STR_ROK_ROKA "rr"
#endif

/* nasleduju parametre z formularov pre dotaz PRM_TABULKA, 15/03/2000A.D. */
#define ROK_FROM 40
#ifdef LONG_PARAM_NAMES
	#define STR_ROK_FROM "ROK_FROM"
#else
	#define STR_ROK_FROM "rfrom"
#endif

#define ROK_TO 41
#ifdef LONG_PARAM_NAMES
	#define STR_ROK_TO "ROK_TO"
#else
	#define STR_ROK_TO "rto"
#endif

#define TABULKA_LINKY 42
#ifdef LONG_PARAM_NAMES
	#define STR_TABULKA_LINKY "TABULKA_LINKY"
#else
	#define STR_TABULKA_LINKY "hl" /* od 'hyperlinks' */
#endif

#define PRM_DETAILY 30 /* dotaz na konkretny datum, to iste ako PRM_DATUM */
#ifdef LONG_PARAM_NAMES
	#define STR_PRM_DETAILY "PRM_DETAILY"
#else
	#define STR_PRM_DETAILY "pdet"
#endif

/* nasleduju parametre pre modlitbu (PRM_DATUM, PRM_DETAILY)
 * -- specialne options, ktore platia rovnako pre oboje, ale
 * de facto sa vyuzivaju len pre PRM_DETAILY */
#define MODL_OPT1 31
#ifdef LONG_PARAM_NAMES
	#define STR_MODL_OPT1 "MODL_OPT1"
#else
	#define STR_MODL_OPT1 "o1"
#endif

#define MODL_OPT2 32
#ifdef LONG_PARAM_NAMES
	#define STR_MODL_OPT2 "MODL_OPT2"
#else
	#define STR_MODL_OPT2 "o2"
#endif

#define MODL_OPT3 33
#ifdef LONG_PARAM_NAMES
	#define STR_MODL_OPT3 "MODL_OPT3"
#else
	#define STR_MODL_OPT3 "o3"
#endif

#define MODL_OPT4 34
#ifdef LONG_PARAM_NAMES
	#define STR_MODL_OPT4 "MODL_OPT4"
#else
	#define STR_MODL_OPT4 "o4"
#endif

/* append pridany 2003-07-08, bude v _global_opt_append; nemal by byt pouzity na webe */
#define MODL_OPT_APPEND 35
#ifdef LONG_PARAM_NAMES
	#define STR_MODL_OPT_APPEND "MODL_OPT_APPEND"
#else
	#define STR_MODL_OPT_APPEND "a"
#endif

/* option 5 pridana 2003-08-07,
 * urcuje, ci brat pre modlitbu cez den zalmy z doplnkovej psalmodie */
#define MODL_OPT5 36
#ifdef LONG_PARAM_NAMES
	#define STR_MODL_OPT5 "MODL_OPT5"
#else
	#define STR_MODL_OPT5 "o5"
#endif

/* 2006-07-11: Pridané kvôli jazykovým mutáciám */
#define JAZYK 37
#ifdef LONG_PARAM_NAMES
	#define STR_JAZYK "JAZYK"
#else
	#define STR_JAZYK "j"
#endif

/* MODL_OPT6 resp. MODL_OPT7 pridané 2007-06-01, pretože sa používali (pre rozbor mesiaca) opt1 resp. opt2; default sa "bil" */
#define MODL_OPT6 38
#ifdef LONG_PARAM_NAMES
	#define STR_MODL_OPT6 "MODL_OPT6"
#else
	#define STR_MODL_OPT6 "o6"
#endif

#define MODL_OPT7 39
#ifdef LONG_PARAM_NAMES
	#define STR_MODL_OPT7 "MODL_OPT7"
#else
	#define STR_MODL_OPT7 "o7"
#endif

/* 2008-08-08: Pridané kvôli rôznym css */
#define CSS 40
#ifdef LONG_PARAM_NAMES
	#define STR_CSS "CSS"
#else
	#define STR_CSS "c"
#endif

/* 2008-11-29: Pridané: spôsob zapisovania dátumu pre súbory v batch móde */
#define MODL_OPT_DATE_FORMAT 41
#ifdef LONG_PARAM_NAMES
	#define STR_MODL_OPT_DATE_FORMAT "MODL_OPT_DATE_FORMAT"
#else
	#define STR_MODL_OPT_DATE_FORMAT "u"
#endif


/* global */
#define QUERY_TYPE	20
#ifdef LONG_PARAM_NAMES
	#define STR_QUERY_TYPE	"QUERY_TYPE"
#else
	#define STR_QUERY_TYPE	"qt"
#endif

#define ALERT	Export("<p>Ak probl&eacute;my pretrv&aacute;vaj&uacute;, kontaktujte pros&iacute;m <a href=\"mailto:%s\">autora str&aacute;nky</a>.</p>\n", cfg_MAIL_ADDRESS_default)

/* HTML stringy - casti stringov sustredene na tomto mieste; pridane 2003-07-02 */
#define HTML_FORM_INPUT_SUBMIT   "input type=\"submit\" class=\"button\""
#define HTML_FORM_INPUT_RESET    "input type=\"reset\" class=\"reset\""
#define HTML_FORM_INPUT_RADIO    "input type=\"radio\" class=\"radio\""
#define HTML_FORM_INPUT_TEXT     "input type=\"text\" class=\"text\""
#define HTML_FORM_INPUT_CHECKBOX "input type=\"checkbox\" class=\"checkbox\""

#define HTML_LINK_RED    "a class=\"red\""
#define HTML_LINK_NORMAL "a"

#define HTML_SPAN_NORMAL    "span class=\"normal\""
#define HTML_SPAN_BOLD      "span class=\"bold\""
#define HTML_SPAN_RED       "span class=\"red\""
#define HTML_SPAN_RED_BOLD  "span class=\"redbold\""
#define HTML_SPAN_BLUE      "span class=\"blue\""
#define HTML_SPAN_BLUE_BOLD "span class=\"bluebold\""
#define HTML_SPAN_RED_SMALL "span class=\"redsmall\""
#define HTML_SPAN_SMALL     "span class=\"small\""

#define HTML_P_PATKA "p class=\"patka\""

/* pridane 2003-07-09, zmenene v cestach pre skript */
#define HTML_AMPERSAND "&amp;"
/* 2006-08-19: pridané */
#define HTML_COMMENT_BEGIN		"<!--"
#define HTML_COMMENT_END		"-->"
#define HTML_FONT_SIZE_FARBA	"2"
/* 2007-03-19: pridané namiesto gt a lt html znakov */
#define HTML_LEFT_ARROW			"&laquo;"
#define HTML_RIGHT_ARROW		"&raquo;"

/* definície HTML prvkov upravené a presunuté do hodin.h, 2006-08-01;
 * tu ponechané len z historických dôvodov zakomentované
 * -- pridane 2003-07-15 
 * #define HTML_BUTTON_RANNE_CHVALY "Ranné chvály"
 * #define HTML_BUTTON_PREDPOLUDNIM "9h"
 * #define HTML_BUTTON_NAPOLUDNIE   "12h"
 * #define HTML_BUTTON_POPOLUDNI    "15h"
 * #define HTML_BUTTON_VESPERY      "Vešpery"
 * -- dalsie pridane 2003-08-06 
 * #define HTML_BUTTON_POSV_CITANIE "Posv.èít."
 * #define HTML_BUTTON_DETAILY      "Detaily..."
 * #define HTML_BUTTON_DET_SHOW     "Zobraz modlitbu"
 * #define HTML_BUTTON_DET_DEFAULTS "Pôvodné hodnoty"
 * -- pridané 2003-08-07 
 * #define HTML_BUTTON_DNES_SHOW     "Zobraz"
 * #define HTML_BUTTON_DNES_DEFAULTS "Vyèisti"
 */

/* 2007-03-19: výpis "Dnes je..." sa zobrazí len pri tomto nastavení, ak je 1 */
#define HTML_ZOBRAZIT_DNES_JE	0

/* 2007-06-01: niektoré definy presunuté z liturgia.h */

/* option 2 */
#define MODL_ZALMY_ZO_DNA 0
#define MODL_ZALMY_ZO_SV  1

/* option 5, 2003-08-06, upravena 2003-08-13 */
#define MODL_CEZ_DEN_ZALMY_ZO_DNA         0
#define MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA  1

/* 2008-11-29: pridané rôzne možnosti batch exportu */
#define	EXPORT_DATE_SIMPLE 0
#define	EXPORT_DATE_FULL   1

#define STR_SIMPLE "simple"
#define STR_FULL   "full"

#define FILENAME_EXPORT_DATE_SIMPLE "%.2d%.2d%.2d"
#define FILENAME_EXPORT_DATE_FULL   "%.4d-%.2d-%.2d"

#endif /*__MYDEFS_H_*/

