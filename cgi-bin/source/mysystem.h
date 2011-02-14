/***************************************************************/
/*                                                             */
/* mysystem.h                                                  */
/* (c)1999-2006 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | obsahuje jediny #define, urcujuci, v akom     */
/*               systeme program pracuje; ovplyvnuje tvorbu    */
/*               linkov, DEBUG #define, veci pre loggovanie a  */
/*               export                                        */
/* document history                                            */
/*   02/11/1999A.D. | created                                  */
/*   24/02/2000A.D. | prekopane                                */
/*   30/03/2000A.D. | pridane OS_Windows, MODEL_DEBUG_Windows, */
/*                    MODEL_ostry_Windows                      */
/*   06/09/2001A.D. | tento popis                              */
/*   2004-03-17a.D. | poznamka k OS_...                        */
/*   2005-03-22a.D. | zrusene DOS, vytvoreny novy model        */
/*   2005-03-28a.D. | pridane na zaciatok #undef pre vsetky    */
/*   2006-01-28a.D. | pridané define pre spôsob exportu        */
/*   2006-07-11a.D. | prvé kroky k jazykovým mutáciám          */
/*   2007-05-25a.D. | pridané MODEL_ostry_Windows_RUBY         */
/*                                                             */
/***************************************************************/

#include "vstudio.h"

#ifndef __MYSYSTEM_H_
#define __MYSYSTEM_H_

/* OS_...    - uz ani nie su potrebne (kedysi pre cesty) */
/* MODEL_... - model kompilacie */

#undef USE_UNCGI

#undef MODEL_ostry_linux
#undef MODEL_ostry_Windows_RUBY
#undef MODEL_DEBUG_linux
#undef MODEL_ostry_SIMUL_linux_UNDER_Windows
#undef MODEL_DEBUG_SIMUL_linux_UNDER_Windows
#undef MODEL_ostry_Windows
#undef MODEL_DEBUG_Windows

//#define MODEL_ostry_linux
#define MODEL_ostry_Windows_RUBY // 2007-05-24: pridané; používame pre Windows/ruby
//#define MODEL_DEBUG_Windows
//#define MODEL_DEBUG_linux
//#define MODEL_ostry_SIMUL_linux_UNDER_Windows		// 2005-03-28 Vytvorene (simulacia ostreho linuxu)
//#define MODEL_DEBUG_SIMUL_linux_UNDER_Windows		// 2005-03-22 Vytvorene (simulacia DEBUG linuxu)
//#define MODEL_ostry_Windows // nezabudni zmenit datum v mybuild.h !!!

/* --------------------------------------------------------------------- */
/* prerobene 23/02/2000A.D. -- 24/02/2000A.D. */
/* 2006-01-28: pridané define pre spôsob výpisu kotiev a názvov súborov do HTML výsledku */
#undef EXPORT_HTML_FILENAME_ANCHOR
#undef EXPORT_HTML_FILENAME
#undef EXPORT_HTML_ANCHOR

/* ostry linux: */
#if defined(MODEL_ostry_linux)
	#define OS_linux
	#undef LOGGING
	#define EXPORT_HTML_FILENAME_ANCHOR
	#define EXPORT_TO_STDOUT
/* ostré Windows/RUBY: */
#elif defined(MODEL_ostry_Windows_RUBY)
	#define OS_Windows_Ruby
	#undef LOGGING
	#define EXPORT_HTML_FILENAME_ANCHOR
	#define EXPORT_TO_STDOUT
/* debugovanie linux -- vsetko sa vypisuje na stdout */
#elif defined(MODEL_DEBUG_linux)
	#define OS_linux
	#define LOGGING
	#define LOG_TO_STDOUT
	#define EXPORT_TO_STDOUT
	#define DEBUG
/* ostry Windows: */
#elif defined(MODEL_ostry_Windows)
	#define OS_Windows
	#undef LOGGING
	#define EXPORT_TO_FILE
/* debugovanie Windows -- vsetko sa loguje do suboru */
#elif defined(MODEL_DEBUG_Windows)
	#define OS_Windows
	#define LOGGING
	#define LOG_TO_FILE
	#define EXPORT_HTML_FILENAME_ANCHOR
	#define EXPORT_TO_FILE
/* simulacia ostreho linuxu pod Windows */
#elif defined(MODEL_ostry_SIMUL_linux_UNDER_Windows)
	#define OS_linux
	#undef LOGGING
	#define EXPORT_TO_STDOUT
/* debugovanie linuxu vo Windows -- vsetko sa loguje do suboru */
#elif defined(MODEL_DEBUG_SIMUL_linux_UNDER_Windows)
	#define OS_linux
	#define LOGGING
	#define LOG_TO_FILE
	#define EXPORT_TO_FILE
/*
// klasicky DOS
#elif defined(MODEL_klasicky_DOS)
	#define OS_DOS
	#define LOGGING
	#define LOG_TO_FILE
	#define EXPORT_TO_FILE
// debugovanie DOS -- vsetko sa vypisuje na stdout
#elif defined(MODEL_DEBUG_DOS)
	#define OS_DOS
	#define LOGGING
	#define LOG_TO_STDOUT
	#define EXPORT_TO_STDOUT
*/
#else
	#error Unsupported system model (try MODEL_ostry_linux, MODEL_ostry_Windows, MODEL_DEBUG_linux, MODEL_DEBUG_Windows, MODEL_DEBUG_SIMUL_linux_UNDER_Windows)
#endif

#ifdef LOG_TO_EXPORT
	#define Log Export
#else
	#define Log __Log
#endif

#ifdef OS_DOS
	#define DEFINED_strcmpi /* v DOSe */
#endif

/* 2006-07-17: Pridané */
#define		PATH_SEPARATOR_linux	'/'
#define		PATH_SEPARATOR_Windows	'\\'

/* 2007-05-29: upravené; pre Ruby on Windows tiež separátor ako pod linuxom */
#if defined(OS_linux)
	#define		PATH_SEPARATOR	PATH_SEPARATOR_linux
#elif defined(OS_Windows_Ruby)
	#define		PATH_SEPARATOR	PATH_SEPARATOR_linux
#else
	#define		PATH_SEPARATOR	PATH_SEPARATOR_Windows
#endif

/* 2006-07-31: Pridané */
#define		UNDERSCORE	'_'

#endif /* __MYSYSTEM_H_ */

