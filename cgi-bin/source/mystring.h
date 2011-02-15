/***************************************************************/
/*                                                             */
/* mystring.h                                                  */
/* (c)1999-2009 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description |                                               */
/* document history                                            */
/*   31/03/2000A.D. | created                                  */
/*   06/09/2001A.D. | tento popis                              */
/*   2003-08-13a.D. | pridane definicie STR_EMPTY a STR_UNDEF  */
/*   2009-08-05a.D. | pridaná funkcia substring()              */
/*                                                             */
/***************************************************************/

#include "vstudio.h"

#include <string.h>

#ifndef __MYSTRING_H
#define __MYSTRING_H

#define STR_EMPTY ""
#define STR_UNDEF "(undef)"

/* funkcia mystrcpy()
 * 1. zisti velkost dest -- sizeof(dest)
 * 2. kopiruje nanajvys count - 1 znakov z src do dest (pomocou strncpy)
 * 3. v kazdom pripade prida na koniec v dest '\0' (terminating null)
 */
char *mystrcpy(char *dest, char *src, short int count);
char *mystrcpy(char *dest, const char *src, short int count);
int substring(char *str1, char *str2);

#endif /* __MYSTRING_H */

