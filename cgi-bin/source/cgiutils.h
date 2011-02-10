/* cgiutils.c
 *
 * (c) 1995-1996 William E. Weinman
 *
 */
#define MAX_NAME_CGI_UTILS 128
#define MAX_VAL_CGI_UTILS 128
struct urlvariable_struct {
   char name[MAX_NAME_CGI_UTILS];
   char val[MAX_VAL_CGI_UTILS];
};
typedef struct urlvariable_struct urlvariable;

#ifndef __CGIUTILS_H
#define __CGIUTILS_H

void splitword(char *out, char *in, char stop);
char x2c(char *x);
void unescape_url(char *url);

#endif /* cgiutils.h */

