/***************************************************************/
/*                                                             */
/* mydefs.h                                                    */
/* (c)1999-2003 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | obsahuje zakladne define'y                    */
/* document history                                            */
/*   12/11/1999A.D. | created                                  */
/*   01/02/2000A.D. | modifikovane                             */
/*   09/02/2000A.D. | pridane PRM_DETAILY                      */
/*   06/09/2001A.D. | zmenene SCRIPT_PATH(a) UNCGI_PATH(a),    */
/*                    tento popis                              */
/*   2003-07-02a.D. | pridane HTML konstanty (casti stringov) */
/*                                                             */
/*                                                             */
/***************************************************************/

#ifndef __MYDEFS_H_
#define __MYDEFS_H_

/* ------------------------------------------------------------ */
/* --- pracovna verzia (v DOSe),  normalny beh (v linuxe)   --- */
/* ---                                                      --- */

#include "mysystem.h"
#include "myconf.h" /* kvoli MAIL_ADDRESS, HTTP_ADDRESS; pridane 30/03/2000A.D. */

#if defined(OS_DOS)
#elif defined(OS_linux)
#elif defined(OS_Windows)
#else
	#error Unsupported operating system (not defined in mysystem.h)
#endif

/* 24/02/2000A.D. */
/* exportovanie do suboru: EXPORT_TO_FILE */
/* logovanie do suboru: LOG_TO_FILE */
/* logovanie do exportu: LOG_TO_EXPORT */

/* tieto vecicky su v mysystem.h */

/* ---                                                      --- */
/* --- koniec veci pre pracovnu verziu (pre DOS)            --- */
/* ------------------------------------------------------------ */

/* Nahradzanie specialnych znakov v cmd-line pre skripty */
#define CGI_SPACE_CHAR '_' /* kvoli medzeram v menach autorov */
#define CGI_SEMICOLON '/' /* kvoli bodkociarkam v menach autorov */

/* Nazvy programov, suborov, skriptov... */
#define SCRIPT_NAME          "l.cgi" /* kedysi tu bolo dnes.cgi */
#define SCRIPT_PATH(a)       "cgi-bin/"a
	/* zmenene 06/09/2001A.D.; povodne tu bolo "cgi-bin/"##a */
#define UNCGI_PATH(a)        SCRIPT_PATH("uncgi.cgi/")a
	/* zmenene 06/09/2001A.D.; povodne tu bolo SCRIPT_PATH("uncgi.cgi/")##a */
#define UNCGI_SCRIPT_NAME    UNCGI_PATH(SCRIPT_NAME)
#define PATH_CGI(a) "cgi-bin/"a
	/* zmenene 06/09/2001A.D.; povodne tu bolo "cgi-bin/"##a */

/* pridane 30/03/2000A.D. */
extern char script_name[MAX_STR]; // = HTTP_ADDRESS + SCRIPT_PATH(SCRIPT_NAME)
extern char uncgi_name[MAX_STR];  // = HTTP_ADDRESS + UNCGI_SCRIPT_NAME
void updateScriptName(void);
void updateUnCGIName(void);

/*   v dalsom 'a' je string s nazvom .htm suboru
 * PATH(a): pre linky, teda cesta k fajlu pre browser
 * FILE_PATH(a): pre vnutorny proscessing, teda cesta k fajlu pre program;
 * 05/06/2000A.D.: FILE_PATH(a) prerobene (len pre Windows-mod sa nieco zmeni);
 *                 povodne bolo FILE_PATH(a) "include\\"##a,
 *                 ibaze vsade (jedine breviar.cpp) sa pouzivalo
 *                 FILE_PATH("");
 * nove FILE_PATH(a): 
 *         pre ostatne mody:
 *                 #define FILE_PATH "../include/" (linux)
 *                 #define FILE_PATH "c:\\breviar\\include\\" (DOS)
 *         zmena pre OS_Windows:
 *                 char FILE_PATH[MAX_STR] = "\\include";
 *                 tuto premennu treba strcat-ovat spolu s include_dir
 *                 (nova premenna pre debug mod, switch `-i')
 *                 
 */
/* tu kedysi bolo aj #define PATH(a) zvacsa a, ale nebolo to treba; vyhodene 2003-07-02 */
#if defined(OS_linux)
	#define FILE_PATH            "../include/"
#elif defined(OS_DOS)
	#define FILE_PATH            "c:\\breviar\\include\\"
//	#define FILE_PATH(a)         "c:\\breviar\\"##a /* 01/03/2000A.D. */
#elif defined(OS_Windows)
	extern char FILE_PATH[MAX_STR]; /* inicializovane v breviar.cpp */
	/* FILE_PATH zmenene 05/06/2000A.D. */
#else
	#error Unsupported operating system (not defined in mysystem.h)
#endif

#define MESSAGE_FOLDER "msg/"
#define FILE_PRESTUPNY_ROK		MESSAGE_FOLDER"prestupn.htm"
#define FILE_JULIANSKY_DATUM	MESSAGE_FOLDER"juldat.htm"
#define FILE_NEDELNE_PISMENO	MESSAGE_FOLDER"nedpism.htm"
#define FILE_LITURGICKY_ROK	    MESSAGE_FOLDER"lr_pism.htm"
#define FILE_NAME_POKEC         MESSAGE_FOLDER"xxx"
#define FILE_NAME_CHYBA         MESSAGE_FOLDER"chyba.htm"

extern int query_type; /* premenna obsahujuca PRM_... */
/* deklarovana tu; definovana v dnes.cpp (18/02/2000A.D.) */

/* meno skriptu nasleduje zoznam parametrov, alebo sa precitaju z form */
#define 	SCRIPT_PARAM_FROM_FORM     200 /* z formulara */
#define 	SCRIPT_PARAM_FROM_QS		   201 /* z query string (sys variable) */
#define 	SCRIPT_PARAM_FROM_ARGV		202 /* z argumentov */

/* nasleduju typy dotazov */
#define PRM_UNKNOWN		 10
#define PRM_NONE		    11

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

/* nasleduju parametre z formularov pre vsetky typy dotazov,
 * kedysi bolo pre kazdy STR_... definovane WWW_STR_...,
 * teraz WWW_(STR_...) */
#define WWW_(a) ("WWW_"##a)

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

/* global */
#define QUERY_TYPE	20
#ifdef LONG_PARAM_NAMES
	#define STR_QUERY_TYPE	"QUERY_TYPE"
#else
	#define STR_QUERY_TYPE	"qt"
#endif

#define ALERT	Export("<p>Ak probl&eacute;my pretrv&aacute;vaj&uacute;, kontaktujte pros&iacute;m <a href=\"mailto:%s\">autora str&aacute;nky</a>.</p>\n", MAIL_ADDRESS)

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

#define HTML_P_PATKA "p class=\"patka\""

#endif /*__MYDEFS_H_*/