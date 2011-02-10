/***************************************************************/
/*                                                             */
/* mystring.h                                                  */
/* (c)1999-2001 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description |                                               */
/* document history                                            */
/*   31/03/2000A.D. | created                                  */
/*   06/09/2001A.D. | tento popis                              */
/*                                                             */
/***************************************************************/

#include <string.h>

#ifndef __MYSTRING_H
#define __MYSTRING_H

/* funkcia mystrcpy()
 * 1. zisti velkost dest -- sizeof(dest)
 * 2. kopiruje nanajvys count - 1 znakov z src do dest (pomocou strncpy)
 * 3. v kazdom pripade prida na koniec v dest '\0' (terminating null)
 */
char *mystrcpy(char *dest, char *src, int count);
char *mystrcpy(char *dest, const char *src, int count);

#endif /* __MYSTRING_H */