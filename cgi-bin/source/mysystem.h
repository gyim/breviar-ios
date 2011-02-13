/***************************************************************/
/*                                                             */
/* mysystem.h                                                  */
/* (c)1999-2005 | Juraj Videky | videky@breviar.sk             */
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
/*                                                             */
/***************************************************************/

#ifndef __MYSYSTEM_H_
#define __MYSYSTEM_H_

/* OS_...    - uz ani nie su potrebne (kedysi pre cesty) */
/* MODEL_... - model kompilacie */

#undef USE_UNCGI

#undef MODEL_ostry_linux
#undef MODEL_DEBUG_linux
#undef MODEL_ostry_SIMUL_linux_UNDER_Windows
#undef MODEL_DEBUG_SIMUL_linux_UNDER_Windows
#undef MODEL_ostry_Windows
#undef MODEL_DEBUG_Windows

#define MODEL_ostry_linux
//#define MODEL_DEBUG_linux
//#define MODEL_ostry_SIMUL_linux_UNDER_Windows		// 2005-03-28 Vytvorene (simulacia ostreho linuxu)
//#define MODEL_DEBUG_SIMUL_linux_UNDER_Windows		// 2005-03-22 Vytvorene (simulacia DEBUG linuxu)
//#define MODEL_ostry_Windows // nezabudni zmenit datum v mybuild.h !!!
//#define MODEL_DEBUG_Windows

/* --------------------------------------------------------------------- */
/* prerobene 23/02/2000A.D. -- 24/02/2000A.D. */

/* ostry linux: */
#if defined(MODEL_ostry_linux)
	#define OS_linux
	#undef LOGGING
	#define EXPORT_TO_STDOUT
/* debugovanie linux -- vsetko sa vypisuje na stdout */
#elif defined(MODEL_DEBUG_linux)
	#define OS_linux
	#define LOGGING
	#define LOG_TO_STDOUT
	#define EXPORT_TO_STDOUT
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

#endif /* __MYSYSTEM_H_ */

