/* 31/03/2000 A.D. Juraj Videky */

#include "mystring.h"

/* funkcia mystrcpy()
 * 1. zisti velkost dest -- sizeof(dest)
 * 2. kopiruje nanajvys count - 1 znakov z src do dest (pomocou strncpy)
 * 3. v kazdom pripade prida na koniec v dest '\0' (terminating null)
 */
char *mystrcpy(char *dest, char *src, int count){
	char *ret;
	/* sizeof(dest) nefunguje pre char *dest */
	ret = strncpy(dest, src, count - 1);
	dest[count - 1] = '\0';
	return ret;
}
char *mystrcpy(char *dest, const char *src, int count){
	char *ret;
	/* sizeof(dest) nefunguje pre char *dest */
	ret = strncpy(dest, src, count - 1);
	dest[count - 1] = '\0';
	return ret;
}

/* The strncpy function copies the initial count characters of strSource to strDest 
 * and returns strDest. If count is less than or equal to the length of strSource, 
 * a null character is not appended automatically to the copied string. 
 * If count is greater than the length of strSource, the destination string is padded 
 * with null characters up to length count. 
 * The behavior of strncpy is undefined if the source and destination strings overlap.
 * This function returns strDest. No return value is reserved to indicate an error.
 */
