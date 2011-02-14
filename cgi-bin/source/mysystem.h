/***************************************************************/
/*                                                             */
/* mysystem.h                                                  */
/* (c)1999-2007 | Juraj Videky | videky@breviar.sk             */
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
/*   2007-06-01a.D. | vèlenený "config.h" pre confuse          */
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
#undef MODEL_DEBUG_Windows_RUBY
#undef MODEL_DEBUG_linux
#undef MODEL_ostry_SIMUL_linux_UNDER_Windows
#undef MODEL_DEBUG_SIMUL_linux_UNDER_Windows
#undef MODEL_ostry_Windows
#undef MODEL_DEBUG_Windows

//#define MODEL_ostry_linux
#define MODEL_ostry_Windows_RUBY // 2007-05-24: pridané; používame pre Windows/ruby
//#define MODEL_DEBUG_Windows_RUBY // 2007-06-01: pridané; používame pre Windows/ruby a vypisovanie všetko na stdout
//#define MODEL_DEBUG_Windows
//#define MODEL_ostry_Windows // nezabudni zmenit datum v mybuild.h !!!
//#define MODEL_DEBUG_linux
//#define MODEL_ostry_SIMUL_linux_UNDER_Windows		// 2005-03-28 Vytvorene (simulacia ostreho linuxu)
//#define MODEL_DEBUG_SIMUL_linux_UNDER_Windows		// 2005-03-22 Vytvorene (simulacia DEBUG linuxu)

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
/* debugovanie Windows/RUBY -- vsetko sa vypisuje na stdout */
#elif defined(MODEL_DEBUG_Windows_RUBY)
	#define OS_Windows_Ruby
	#define LOGGING
	#define LOG_TO_STDOUT
	#define EXPORT_TO_STDOUT
	#define DEBUG
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

/* 2007-06-01: vèlenil som sem "config.h" pre confuse */
#if defined(OS_linux)
	/* Define to 1 if translation of program messages to the user's native
	   language is requested. */
	/*#undef ENABLE_NLS*/

	/* Define if the GNU dcgettext() function is already present or preinstalled.
	   */
	/*#undef HAVE_DCGETTEXT*/

	/* Define to 1 if you have the <dlfcn.h> header file. */
	/*#undef HAVE_DLFCN_H*/

	/* Define if the GNU gettext() function is already present or preinstalled. */
	/*#undef HAVE_GETTEXT*/

	/* Define if you have the iconv() function. */
	/*#undef HAVE_ICONV*/

	/* Define to 1 if you have the <inttypes.h> header file. */
	/*#undef HAVE_INTTYPES_H*/

	/* Define to 1 if you have the <memory.h> header file. */
	#define HAVE_MEMORY_H 1

	/* Define to 1 if you have the <stdint.h> header file. */
	#define HAVE_STDINT_H 1

	/* Define to 1 if you have the <stdlib.h> header file. */
	#define HAVE_STDLIB_H 1

	/* Define to 1 if you have the `strcasecmp' function. */
	#define HAVE_STRCASECMP 1

	/* Define to 1 if you have the `strdup' function. */
	#define HAVE_STRDUP 1

	/* Define to 1 if you have the `_strdup' function. */
	#define HAVE__STRDUP 1

	/* Define to 1 if you have the <strings.h> header file. */
	/*#undef HAVE_STRINGS_H*/

	/* Define to 1 if you have the <string.h> header file. */
	#define HAVE_STRING_H 1

	/* Define to 1 if you have the <sys/stat.h> header file. */
	#undef HAVE_SYS_STAT_H

	/* Define to 1 if you have the <sys/types.h> header file. */
	#define HAVE_SYS_TYPES_H 1

	/* Define to 1 if you have the <unistd.h> header file. */
	/*#undef HAVE_UNISTD_H*/

	/* Name of package */
	#define PACKAGE "confuse"

	/* Define to the address where bug reports for this package should be sent. */
	#define PACKAGE_BUGREPORT "confuse-devel@nongnu.org"

	/* Define to the full name of this package. */
	#define PACKAGE_NAME "libConfuse"

	/* Define to the full name and version of this package. */
	#define PACKAGE_STRING "libConfuse 2.5"

	/* Define to the one symbol short name of this package. */
	#define PACKAGE_TARNAME "confuse"

	/* Define to the version of this package. */
	#define PACKAGE_VERSION "2.5"

	/* Define to 1 if you have the ANSI C header files. */
	/* #define STDC_HEADERS 1 */

	/* Version number of package */
	#define VERSION "2.5"

	/* Define to 1 if `lex' declares `yytext' as a `char *' by default, not a
	   `char[]'. */
	#define YYTEXT_POINTER 1

	/* Define to empty if `const' does not conform to ANSI C. */
	/*#undef const*/

	/* Define to 1 if you have the strndup function */
	#define HAVE_STRNDUP 1

	/* Define if you have _fileno instead of fileno */
	#define HAVE__FILENO 1

	/* Define if you have _isatty but not isatty */
	#define HAVE__ISATTY 1
#else
	/* config.h. Handcrafted for Microsoft Visual Studio.  */

	/* Define to 1 if translation of program messages to the user's native
	   language is requested. */
	/*#undef ENABLE_NLS*/

	/* Define if the GNU dcgettext() function is already present or preinstalled.
	   */
	/*#undef HAVE_DCGETTEXT*/

	/* Define to 1 if you have the <dlfcn.h> header file. */
	/*#undef HAVE_DLFCN_H*/

	/* Define if the GNU gettext() function is already present or preinstalled. */
	/*#undef HAVE_GETTEXT*/

	/* Define if you have the iconv() function. */
	/*#undef HAVE_ICONV*/

	/* Define to 1 if you have the <inttypes.h> header file. */
	/*#undef HAVE_INTTYPES_H*/

	/* Define to 1 if you have the <memory.h> header file. */
	#define HAVE_MEMORY_H 1

	/* Define to 1 if you have the <stdint.h> header file. */
	#define HAVE_STDINT_H 1

	/* Define to 1 if you have the <stdlib.h> header file. */
	#define HAVE_STDLIB_H 1

	/* Define to 1 if you have the `strcasecmp' function. */
	/* #define HAVE_STRCASECMP 1 */

	/* Define to 1 if you have the `strdup' function. */
	#define HAVE_STRDUP 1

	/* Define to 1 if you have the `_strdup' function. */
	#define HAVE__STRDUP 1

	/* Define to 1 if you have the <strings.h> header file. */
	/*#undef HAVE_STRINGS_H*/

	/* Define to 1 if you have the <string.h> header file. */
	#define HAVE_STRING_H 1

	/* Define to 1 if you have the <sys/stat.h> header file. */
	#undef HAVE_SYS_STAT_H

	/* Define to 1 if you have the <sys/types.h> header file. */
	#define HAVE_SYS_TYPES_H 1

	/* Define to 1 if you have the <unistd.h> header file. */
	/*#undef HAVE_UNISTD_H*/

	/* Name of package */
	#define PACKAGE "confuse"

	/* Define to the address where bug reports for this package should be sent. */
	#define PACKAGE_BUGREPORT "confuse-devel@nongnu.org"

	/* Define to the full name of this package. */
	#define PACKAGE_NAME "libConfuse"

	/* Define to the full name and version of this package. */
	#define PACKAGE_STRING "libConfuse 2.5"

	/* Define to the one symbol short name of this package. */
	#define PACKAGE_TARNAME "confuse"

	/* Define to the version of this package. */
	#define PACKAGE_VERSION "2.5"

	/* Define to 1 if you have the ANSI C header files. */
	/* #define STDC_HEADERS 1 */

	/* Version number of package */
	#define VERSION "2.5"

	/* Define to 1 if `lex' declares `yytext' as a `char *' by default, not a
	   `char[]'. */
	#define YYTEXT_POINTER 1

	/* Define to empty if `const' does not conform to ANSI C. */
	/*#undef const*/

	/* Define to 1 if you have the strndup function */
	/* #define HAVE_STRNDUP 1 */

	/* Define if you have _fileno instead of fileno */
	#define HAVE__FILENO 1

	/* Define if you have _isatty but not isatty */
	#define HAVE__ISATTY 1
#endif

#endif /* __MYSYSTEM_H_ */

