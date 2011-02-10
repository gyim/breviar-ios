/* 31/03/2000 A.D. Juraj Videky */
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