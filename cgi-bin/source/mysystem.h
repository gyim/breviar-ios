/***************************************************************/
/*                                                             */
/* mysystem.h                                                  */
/* (c)1999-2001 | Juraj Videky | videky@breviar.sk             */
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
/*                                                             */
/***************************************************************/

#ifndef __MYSYSTEM_H_
#define __MYSYSTEM_H_

/* OS_... - kvoli cestam (PATH...) */
/* MODEL_... -- model kompilacie */

//#define MODEL_ostry_linux
//#define MODEL_klasicky_DOS  // neodporucam pouzit
//#define MODEL_DEBUG_linux
//#define MODEL_DEBUG_DOS     // neodporucam pouzit
#define MODEL_ostry_Windows // nezabudni zmenit datum v mybuild.h !!!
//#define MODEL_DEBUG_Windows

/* --------------------------------------------------------------------- */
/* prerobene 23/02/2000A.D. -- 24/02/2000A.D. */

/* ostry linux: */
#if defined(MODEL_ostry_linux)
	#define OS_linux
	#undef LOGGING
	#define EXPORT_TO_STDOUT
/* debugovanie -- vsetko sa vypisuje na stdout */
#elif defined(MODEL_DEBUG_linux)
	#define OS_linux
	#define LOGGING
	#define LOG_TO_STDOUT
	#define EXPORT_TO_STDOUT
/* klasicky DOS: */
#elif defined(MODEL_klasicky_DOS)
	#define OS_DOS
	#define LOGGING
	#define LOG_TO_FILE
	#define EXPORT_TO_FILE
/* debugovanie -- vsetko sa vypisuje na stdout */
#elif defined(MODEL_DEBUG_DOS)
	#define OS_DOS
	#define LOGGING
	#define LOG_TO_STDOUT
	#define EXPORT_TO_STDOUT
/* ostry Windows: */
#elif defined(MODEL_ostry_Windows)
	#define OS_Windows
	#undef LOGGING
	#define EXPORT_TO_FILE
/* debugovanie -- vsetko sa vypisuje na stdout */
#elif defined(MODEL_DEBUG_Windows)
	#define OS_Windows
	#define LOGGING
	#define LOG_TO_FILE
	#define EXPORT_TO_FILE
#else
	#error Unsupported system model (try MODEL_ostry_linux, MODEL_klasicky_DOS, MODEL_ostry_Windows, MODEL_DEBUG_linux, MODEL_DEBUG_DOS, MODEL_DEBUG_Windows)
#endif

#ifdef LOG_TO_EXPORT
	#define Log Export
#else
	#define Log __Log
#endif


#ifdef OS_DOS
	#define DEFINED_strcmpi /* v DOSe */
#endif

#endif /* __MYSYSTEM_H_ */

