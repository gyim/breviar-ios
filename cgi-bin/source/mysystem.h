/***************************************************************/
/*                                                             */
/* mysystem.h                                                  */
/* (c)1999-2011 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* NOTE: popis ni��ie -- for description see below             */
/*                                                             */
/***************************************************************/
#include "vstudio.h"

#ifndef __MYSYSTEM_H_
#define __MYSYSTEM_H_

#undef USE_UNCGI

#undef MODEL_linux
#undef MODEL_linux_commandline
#undef MODEL_Windows_RUBY
#undef MODEL_Windows_commandline

#undef MODEL_DEBUG_linux
#undef MODEL_DEBUG_linux_commandline
#undef MODEL_DEBUG_Windows_RUBY
#undef MODEL_DEBUG_Windows_commandline

/* Modely pre Windows */

/* Modely pre ostr� pou�itie -- for release */
#define MODEL_Windows_RUBY
//#define MODEL_Windows_commandline

/* Modely pre debugovanie -- for debug */
//#define MODEL_DEBUG_Windows_RUBY
//#define MODEL_DEBUG_Windows_commandline

/* Modely pre linux */

/* Modely pre ostr� pou�itie -- for release */
//#define MODEL_linux
//#define MODEL_linux_commandline

/* Modely pre debugovanie -- for debug */
//#define MODEL_DEBUG_linux
//#define MODEL_DEBUG_linux_commandline

/***************************************************************/
/*                                                             */
/* mysystem.h                                                  */
/* (c)1999-2011 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | obsahuje jediny #define, urcujuci, v akom     */
/*               systeme program pracuje; ovplyvnuje tvorbu    */
/*               linkov, DEBUG #define, veci pre loggovanie a  */
/*               export                                        */
/* document history                                            */
/*   02/11/1999A.D. | created                                  */
/*   24/02/2000A.D. | prekopane                                */
/*   30/03/2000A.D. | pridane OS_Windows, MODEL_DEBUG_Windows, */
/*                    MODEL_Windows                            */
/*   06/09/2001A.D. | tento popis                              */
/*   2004-03-17a.D. | poznamka k OS_...                        */
/*   2005-03-22a.D. | zrusene DOS, vytvoreny novy model        */
/*   2005-03-28a.D. | pridane na zaciatok #undef pre vsetky    */
/*   2006-01-28a.D. | pridan� define pre sp�sob exportu        */
/*   2006-07-11a.D. | prv� kroky k jazykov�m mut�ci�m          */
/*   2007-05-25a.D. | pridan� MODEL_Windows_RUBY               */
/*   2007-06-01a.D. | v�lenen� "config.h" pre confuse          */
/*   2007-06-19a.D. | odstr�nen� "config.h" pre confuse        */
/*   2007-06-28a.D. | oprava jednotliv�ch modelov, popisy      */
/*   2007-11-20a.D. | doplnen� EXPORT_HTML_SPECIALS            */
/*   2008-05-19a.D. | EXPORT_HTML_FILENAME_ANCHOR aj pre linux */
/*   2008-08-08a.D. | doplnen� EXPORT_CMDLINE_CSS              */
/*   2009-08-26a.D. | pred popis predsunut� samotn� nastavenie */
/*                                                             */
/***************************************************************/

/*
 * Pozn�mka: Pri buildovan� nezabudni zmeni� datum v mydefs.h (BUILD_DATE).
 *
 * Popis jednotliv�ch modelov (JUV, 2007-06-28):
 *
 * MODEL_linux - takto to vyzer� na internete (www.breviar.sk): 
 *		- �iadne logovanie, export do stdout, syst�m linux
 *		- debug verzia (s v�pismi na stdout do HTML s�boru ako pozn�mky): MODEL_DEBUG_linux
 *
 * MODEL_linux_commandline - off-line command-line verzia pre linux: 
 *		- �iadne logovanie, export do s�boru, syst�m linux 
 *		  (pou�itie pre off-line ru�n� generovanie HTML str�nok, 
 *		  napr. aj pre batch m�d - d�vkov� generovanie ve�a str�nok na s�visl� obdobie)
 *		- debug verzia (s v�pismi do samostatn�ho s�boru): MODEL_DEBUG_linux_commandline
 *
 * MODEL_Windows_RUBY - off-line verzia pre Windows s pou�it�m Ruby webservera: 
 *		- �iadne logovanie, export do stdout, syst�m Windows
 *		// 2007-05-24: pridan�; pou��vame pre Windows/ruby
 *		- debug verzia (s v�pismi na stdout do HTML s�boru ako pozn�mky): MODEL_DEBUG_Windows_RUBY
 *
 * MODEL_Windows_commandline - off-line command-line verzia pre Windows: 
 *		- �iadne logovanie, export do s�boru, syst�m Windows 
 *		  (pou�itie pre off-line ru�n� generovanie HTML str�nok, 
 *		  napr. aj pre batch m�d - d�vkov� generovanie ve�a str�nok na s�visl� obdobie)
 *		- debug verzia (s v�pismi do samostatn�ho s�boru): MODEL_DEBUG_Windows_commandline
 *
 * 2 z�kladn� druhy spr�vania aplik�cie (JUV, 2010-06-07):
 *
 * BEHAVIOUR_WEB -- spr�vanie ako na webe: export pr�p. logovanie ide na STDOUT (t. j. ako output pre web browser)
 * BEHAVIOUR_CMDLINE -- spr�vanie pre command-line verziu: export pr�p. logovanie ide do s�boru/s�borov (t. j. ako output pre batch m�d)
 *
 */

/* OS_...    - uz ani nie su potrebne (kedysi pre cesty) */
/* MODEL_... - model kompilacie */

/* --------------------------------------------------------------------- */
/* prerobene 23/02/2000A.D. -- 24/02/2000A.D. */
/* 2006-01-28: pridan� define pre sp�sob v�pisu kotiev a n�zvov s�borov do HTML v�sledku */
#undef EXPORT_HTML_FILENAME_ANCHOR
#undef EXPORT_HTML_FILENAME
#undef EXPORT_HTML_ANCHOR
#undef EXPORT_HTML_SPECIALS /* 2007-11-20: vytvoren�, kv�li v�pisom do v�sledn�ho HTML vo funkcii interpretParameter(), napr. "nie je velkonocne obdobie" */
#undef EXPORT_CMDLINE_CSS /* 2008-08-08: doplnen� kv�li tomu, �i exportova� v hlavi�ke /breviar.css alebo ./breviar.css */

#undef BEHAVIOUR_WEB /* 2010-06-07: spr�vanie ako na webe: export pr�p. logovanie ide na STDOUT (t. j. ako output pre web browser) */
#undef BEHAVIOUR_CMDLINE /* 2010-06-07: spr�vanie pre command-line verziu: export pr�p. logovanie ide do s�boru/s�borov (t. j. ako output pre batch m�d) */

/* ostry linux: */
#if defined(MODEL_linux)
	#define BEHAVIOUR_WEB
	#define OS_linux
	#undef LOGGING
	#define EXPORT_HTML_FILENAME_ANCHOR
	#define EXPORT_TO_STDOUT
/* ostr� Windows/RUBY: */
#elif defined(MODEL_Windows_RUBY)
	#define BEHAVIOUR_WEB
	#define OS_Windows_Ruby
	#undef LOGGING
	#define EXPORT_HTML_FILENAME_ANCHOR
	#define EXPORT_HTML_SPECIALS
	#define EXPORT_TO_STDOUT
/* debugovanie Windows/RUBY -- vsetko sa vypisuje na stdout */
#elif defined(MODEL_DEBUG_Windows_RUBY)
	#define BEHAVIOUR_WEB
	#define OS_Windows_Ruby
	#define LOGGING
	#define LOG_TO_STDOUT
	#define EXPORT_HTML_FILENAME_ANCHOR
	#define EXPORT_HTML_SPECIALS
	#define EXPORT_TO_STDOUT
	#define DEBUG
/* debugovanie linux -- vsetko sa vypisuje na stdout */
#elif defined(MODEL_DEBUG_linux)
	#define BEHAVIOUR_WEB
	#define OS_linux
	#define LOGGING
	#define LOG_TO_STDOUT
	#define EXPORT_HTML_FILENAME_ANCHOR
	#define EXPORT_HTML_SPECIALS
	#define EXPORT_TO_STDOUT
	#define DEBUG
/* ostry Windows (command-line verzia): */
#elif defined(MODEL_Windows_commandline)
	#define BEHAVIOUR_CMDLINE
	#define OS_Windows
	#undef LOGGING
	#define EXPORT_TO_FILE
	#define EXPORT_CMDLINE_CSS
/* debugovanie Windows/command-line -- vsetko sa loguje do suboru */
#elif defined(MODEL_DEBUG_Windows_commandline)
	#define BEHAVIOUR_CMDLINE
	#define OS_Windows
	#define LOGGING
	#define LOG_TO_FILE
	#define EXPORT_HTML_FILENAME_ANCHOR
	#define EXPORT_HTML_SPECIALS
	#define EXPORT_TO_FILE
	#define EXPORT_CMDLINE_CSS
/* ostry linux (command-line verzia): */
#elif defined(MODEL_linux_commandline)
	#define BEHAVIOUR_CMDLINE
	#define OS_linux
	#undef LOGGING
	#define EXPORT_TO_FILE
	#define EXPORT_CMDLINE_CSS
/* debugovanie linux/command-line -- vsetko sa loguje do suboru */
#elif defined(MODEL_DEBUG_Windows_commandline)
	#define BEHAVIOUR_CMDLINE
	#define OS_linux
	#define LOGGING
	#define LOG_TO_FILE
	#define EXPORT_HTML_FILENAME_ANCHOR
	#define EXPORT_HTML_SPECIALS
	#define EXPORT_TO_FILE
	#define EXPORT_CMDLINE_CSS

#else
	#error Unsupported system model (see mysystem.h) - Nepodporovan� syst�mov� model (pozri s�bor mysystem.h)
#endif

// 2010-06-07: doplnen� pod�a direkt�vy Visual Studia (vlastne tak trocha prepisuje vy��ie uveden�)
#ifdef _DEBUG
	#define DEBUG
	#define LOGGING
	#ifdef BEHAVIOUR_WEB
		#define LOG_TO_STDOUT
		#define EXPORT_TO_STDOUT
	#elif defined (BEHAVIOUR_CMDLINE)
		#define LOG_TO_FILE
		#define EXPORT_TO_FILE
	#endif
	#define EXPORT_HTML_FILENAME_ANCHOR
	#define EXPORT_HTML_SPECIALS
/*
#else
	#undef DEBUG
	#undef LOGGING
	#undef LOG_TO_STDOUT
	#undef LOG_TO_FILE
*/
#endif

#ifdef LOG_TO_EXPORT
	#define Log Export
#else
	#define Log __Log
#endif

#ifdef OS_DOS
	#define DEFINED_strcmpi /* v DOSe */
#endif

/* 2006-07-17: Pridan� */
#define		PATH_SEPARATOR_linux	'/'
#define		PATH_SEPARATOR_Windows	'\\'
/* 2008-08-08: Pridan� */
#define		STR_PATH_SEPARATOR_linux	"/"
#define		STR_PATH_SEPARATOR_Windows	"\\"
/* 2009-08-03: pridan� pre HTML s�bory */
#define		STR_PATH_SEPARATOR_HTML	STR_PATH_SEPARATOR_linux

#define		SYSTEM_RUBY    0
#define		SYSTEM_LINUX   1
#define		SYSTEM_WINDOWS 2

/* 2007-05-29: upraven�; pre Ruby on Windows tie� separ�tor ako pod linuxom
 * 2011-05-16: pri debugovan� Ruby on Windows treba backslashe
 */
#if defined(OS_linux)
	#define		PATH_SEPARATOR	PATH_SEPARATOR_linux
	#define		STR_PATH_SEPARATOR	STR_PATH_SEPARATOR_linux
#elif defined(OS_Windows_Ruby) && defined(DEBUG)
	#define		PATH_SEPARATOR	PATH_SEPARATOR_Windows
	#define		STR_PATH_SEPARATOR	STR_PATH_SEPARATOR_Windows
#elif defined(OS_Windows_Ruby)
	#define		PATH_SEPARATOR	PATH_SEPARATOR_linux
	#define		STR_PATH_SEPARATOR	STR_PATH_SEPARATOR_linux
#else
	#define		PATH_SEPARATOR	PATH_SEPARATOR_Windows
	#define		STR_PATH_SEPARATOR	STR_PATH_SEPARATOR_Windows
#endif

/* 2006-07-31: Pridan� */
#define		UNDERSCORE	'_'

/* 2006-07-31: kv�li jazykov�m mut�ci�m; zmenen� 2008-08-15 na 5 
 * 2009-01-29: zmenen� na 6 (ma�ar�ina)
 * 2011-04-13: presunut� sem spolu s POCET_GLOBAL_OPT aj MAX_STR, GLOBAL_OPTION_NULL
 */
#define	POCET_JAZYKOV	     6
#define POCET_GLOBAL_OPT     5
#define MAX_STR            300 /* maximalna dlzka retazca */
#define GLOBAL_OPTION_NULL  -1 /* neur�en� hodnota pre global option */


#endif /* __MYSYSTEM_H_ */
