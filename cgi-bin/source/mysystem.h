/***************************************************************/
/*                                                             */
/* mysystem.h                                                  */
/* (c)1999-2013 | Juraj Vid�ky | videky@breviar.sk             */
/*                                                             */
/* NOTE: popis ni��ie -- for description see below             */
/* http://sourceforge.net/p/predef/wiki/OperatingSystems/      */
/*                                                             */
/***************************************************************/
#include "vstudio.h"

#ifndef __MYSYSTEM_H_
#define __MYSYSTEM_H_

#undef USE_UNCGI

#ifndef MODEL_SELECTED_IN_MAKEFILE

#undef MODEL_linux
#undef MODEL_linux_commandline
#undef MODEL_android // __ANDROID__
#undef MODEL_Windows_RUBY
#undef MODEL_Windows_commandline

#undef MODEL_DEBUG_linux
#undef MODEL_DEBUG_linux_commandline
#undef MODEL_DEBUG_Windows_RUBY
#undef MODEL_DEBUG_Windows_commandline

// --------------------------------------------------
// pou�itie ako CGI skript (Windows/RUBY, linux)

// Modely pre Windows/RUBY
#ifdef _WIN32
// Defined for both 32-bit and 64-bit environments | http://msdn.microsoft.com/en-us/library/ff540443.aspx | A 32-bit platform. This value is also defined by the 64-bit compiler for backward compatibility.

#ifdef _DEBUG
// Modely pre debugovanie -- for debug (direkt�va VStudia)
#define MODEL_DEBUG_Windows_RUBY
#else
// Modely pre ostr� pou�itie -- for release
#define MODEL_Windows_RUBY
#endif // _DEBUG

// Modely pre linux
#elif __linux__
// http://www.faqs.org/docs/Linux-HOWTO/GCC-HOWTO.html#INDEX.25 | Use __linux__ for this purpose, not linux. Although the latter is defined, it is not POSIX compliant.

#ifdef _DEBUG
// Modely pre debugovanie -- for debug
#define MODEL_DEBUG_linux
#else
// Modely pre ostr� pou�itie -- for release
#define MODEL_linux
#endif // _DEBUG

#endif // linux

/*
// --------------------------------------------------
// pou�itie ako command-line (Windows/RUBY, linux)
// Modely pre Windows
#ifdef _WIN32
// Defined for both 32-bit and 64-bit environments | http://msdn.microsoft.com/en-us/library/ff540443.aspx | A 32-bit platform. This value is also defined by the 64-bit compiler for backward compatibility.

#ifdef _DEBUG
// Modely pre debugovanie -- for debug (direkt�va VStudia)
#define MODEL_DEBUG_Windows_commandline
#else
// Modely pre ostr� pou�itie -- for release
#define MODEL_Windows_commandline
#endif // _DEBUG

// Modely pre linux
#elif __linux__
// http://www.faqs.org/docs/Linux-HOWTO/GCC-HOWTO.html#INDEX.25 | Use __linux__ for this purpose, not linux. Although the latter is defined, it is not POSIX compliant.

#ifdef _DEBUG
// Modely pre debugovanie -- for debug
#define MODEL_DEBUG_linux_commandline
#else
// Modely pre ostr� pou�itie -- for release
#define MODEL_linux_commandline
#endif // _DEBUG

#endif // linux
*/

#endif // MODEL_SELECTED_IN_MAKEFILE

#endif // __MYSYSTEM_H_
