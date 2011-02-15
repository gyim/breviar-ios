/***************************************************************/
/*                                                             */
/* mysystem.h                                                  */
/* (c)1999-2009 | Juraj Videky | videky@breviar.sk             */
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
/*   2006-01-28a.D. | pridanÈ define pre spÙsob exportu        */
/*   2006-07-11a.D. | prvÈ kroky k jazykov˝m mut·ci·m          */
/*   2007-05-25a.D. | pridanÈ MODEL_Windows_RUBY               */
/*   2007-06-01a.D. | vËlenen˝ "config.h" pre confuse          */
/*   2007-06-19a.D. | odstr·nen˝ "config.h" pre confuse        */
/*   2007-06-28a.D. | oprava jednotliv˝ch modelov, popisy      */
/*   2007-11-20a.D. | doplnenÈ EXPORT_HTML_SPECIALS            */
/*   2008-05-19a.D. | EXPORT_HTML_FILENAME_ANCHOR aj pre linux */
/*   2008-08-08a.D. | doplnenÈ EXPORT_CMDLINE_CSS              */
/*                                                             */
/***************************************************************/

#include "vstudio.h"

#ifndef __MYSYSTEM_H_
#define __MYSYSTEM_H_

/* OS_...    - uz ani nie su potrebne (kedysi pre cesty) */
/* MODEL_... - model kompilacie */

#undef USE_UNCGI

#undef MODEL_linux
#undef MODEL_linux_commandline
#undef MODEL_Windows_RUBY
#undef MODEL_Windows_commandline

#undef MODEL_DEBUG_linux
#undef MODEL_DEBUG_linux_commandline
#undef MODEL_DEBUG_Windows_RUBY
#undef MODEL_DEBUG_Windows_commandline

/*
 * Pozn·mka: Pri buildovanÌ nezabudni zmeniù datum v mydefs.h (BUILD_DATE).
 *
 * Popis jednotliv˝ch modelov (JUV, 2007-06-28):
 *
 * MODEL_linux - takto to vyzer· na internete (www.breviar.sk): 
 *		- ûiadne logovanie, export do stdout, systÈm linux
 *		- debug verzia (s v˝pismi na stdout do HTML s˙boru ako pozn·mky): MODEL_DEBUG_linux
 *
 * MODEL_linux_commandline - off-line command-line verzia pre linux: 
 *		- ûiadne logovanie, export do s˙boru, systÈm linux 
 *		  (pouûitie pre off-line ruËnÈ generovanie HTML str·nok, 
 *		  napr. aj pre batch mÛd - d·vkovÈ generovanie veæa str·nok na s˙vislÈ obdobie)
 *		- debug verzia (s v˝pismi do samostatnÈho s˙boru): MODEL_DEBUG_linux_commandline
 *
 * MODEL_Windows_RUBY - off-line verzia pre Windows s pouûitÌm Ruby webservera: 
 *		- ûiadne logovanie, export do stdout, systÈm Windows
 *		// 2007-05-24: pridanÈ; pouûÌvame pre Windows/ruby
 *		- debug verzia (s v˝pismi na stdout do HTML s˙boru ako pozn·mky): MODEL_DEBUG_Windows_RUBY
 *
 * MODEL_Windows_commandline - off-line command-line verzia pre Windows: 
 *		- ûiadne logovanie, export do s˙boru, systÈm Windows 
 *		  (pouûitie pre off-line ruËnÈ generovanie HTML str·nok, 
 *		  napr. aj pre batch mÛd - d·vkovÈ generovanie veæa str·nok na s˙vislÈ obdobie)
 *		- debug verzia (s v˝pismi do samostatnÈho s˙boru): MODEL_DEBUG_Windows_commandline
 *
 */

/* Modely pre ostrÈ pouûitie */
//#define MODEL_linux
//#define MODEL_linux_commandline
//#define MODEL_Windows_RUBY
#define MODEL_Windows_commandline

/* Modely pre debugovanie */
//#define MODEL_DEBUG_linux
//#define MODEL_DEBUG_linux_commandline
//#define MODEL_DEBUG_Windows_RUBY
//#define MODEL_DEBUG_Windows_commandline

/* --------------------------------------------------------------------- */
/* prerobene 23/02/2000A.D. -- 24/02/2000A.D. */
/* 2006-01-28: pridanÈ define pre spÙsob v˝pisu kotiev a n·zvov s˙borov do HTML v˝sledku */
#undef EXPORT_HTML_FILENAME_ANCHOR
#undef EXPORT_HTML_FILENAME
#undef EXPORT_HTML_ANCHOR
#undef EXPORT_HTML_SPECIALS /* 2007-11-20: vytvorenÈ, kvÙli v˝pisom do v˝slednÈho HTML vo funkcii interpretParameter(), napr. "nie je velkonocne obdobie" */
#undef EXPORT_CMDLINE_CSS /* 2008-08-08: doplnenÈ kvÙli tomu, Ëi exportovaù v hlaviËke /breviar.css alebo ./breviar.css */

/* ostry linux: */
#if defined(MODEL_linux)
	#define OS_linux
	#undef LOGGING
	#define EXPORT_HTML_FILENAME_ANCHOR
	#define EXPORT_TO_STDOUT
/* ostrÈ Windows/RUBY: */
#elif defined(MODEL_Windows_RUBY)
	#define OS_Windows_Ruby
	#undef LOGGING
	#define EXPORT_HTML_FILENAME_ANCHOR
	#define EXPORT_HTML_SPECIALS
	#define EXPORT_TO_STDOUT
/* debugovanie Windows/RUBY -- vsetko sa vypisuje na stdout */
#elif defined(MODEL_DEBUG_Windows_RUBY)
	#define OS_Windows_Ruby
	#define LOGGING
	#define LOG_TO_STDOUT
	#define EXPORT_HTML_FILENAME_ANCHOR
	#define EXPORT_HTML_SPECIALS
	#define EXPORT_TO_STDOUT
	#define DEBUG
/* debugovanie linux -- vsetko sa vypisuje na stdout */
#elif defined(MODEL_DEBUG_linux)
	#define OS_linux
	#define LOGGING
	#define LOG_TO_STDOUT
	#define EXPORT_HTML_FILENAME_ANCHOR
	#define EXPORT_HTML_SPECIALS
	#define EXPORT_TO_STDOUT
	#define DEBUG
/* ostry Windows (command-line verzia): */
#elif defined(MODEL_Windows_commandline)
	#define OS_Windows
	#undef LOGGING
	#define EXPORT_TO_FILE
	#define EXPORT_CMDLINE_CSS
/* debugovanie Windows/command-line -- vsetko sa loguje do suboru */
#elif defined(MODEL_DEBUG_Windows_commandline)
	#define OS_Windows
	#define LOGGING
	#define LOG_TO_FILE
	#define EXPORT_HTML_FILENAME_ANCHOR
	#define EXPORT_HTML_SPECIALS
	#define EXPORT_TO_FILE
	#define EXPORT_CMDLINE_CSS
/* ostry linux (command-line verzia): */
#elif defined(MODEL_linux_commandline)
	#define OS_linux
	#undef LOGGING
	#define EXPORT_TO_FILE
	#define EXPORT_CMDLINE_CSS
/* debugovanie linux/command-line -- vsetko sa loguje do suboru */
#elif defined(MODEL_DEBUG_Windows_commandline)
	#define OS_linux
	#define LOGGING
	#define LOG_TO_FILE
	#define EXPORT_HTML_FILENAME_ANCHOR
	#define EXPORT_HTML_SPECIALS
	#define EXPORT_TO_FILE
	#define EXPORT_CMDLINE_CSS

#else
	#error Unsupported system model (see mysystem.h) - Nepodporovan˝ systÈmov˝ model (pozri s˙bor mysystem.h)
#endif

#ifdef LOG_TO_EXPORT
	#define Log Export
#else
	#define Log __Log
#endif

#ifdef OS_DOS
	#define DEFINED_strcmpi /* v DOSe */
#endif

/* 2006-07-17: PridanÈ */
#define		PATH_SEPARATOR_linux	'/'
#define		PATH_SEPARATOR_Windows	'\\'
/* 2008-08-08: PridanÈ */
#define		STR_PATH_SEPARATOR_linux	"/"
#define		STR_PATH_SEPARATOR_Windows	"\\"

/* 2007-05-29: upravenÈ; pre Ruby on Windows tieû separ·tor ako pod linuxom */
#if defined(OS_linux)
	#define		PATH_SEPARATOR	PATH_SEPARATOR_linux
	#define		STR_PATH_SEPARATOR	STR_PATH_SEPARATOR_linux
#elif defined(OS_Windows_Ruby)
	#define		PATH_SEPARATOR	PATH_SEPARATOR_linux
	#define		STR_PATH_SEPARATOR	STR_PATH_SEPARATOR_linux
#else
	#define		PATH_SEPARATOR	PATH_SEPARATOR_Windows
	#define		STR_PATH_SEPARATOR	STR_PATH_SEPARATOR_Windows
#endif

/* 2006-07-31: PridanÈ */
#define		UNDERSCORE	'_'

#endif /* __MYSYSTEM_H_ */

