/***************************************************************/
/*                                                             */
/* mybase.cpp                                                  */
/* (c)1999-2001 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | obsahuje zakladne vecicky                     */
/* document history                                            */
/*   19/11/1998A.D. | created                                  */
/*   30/03/2000A.D. | prerobene na cpp                         */
/*   06/09/2001A.D. | tento popis                              */
/*                                                             */
/***************************************************************/

#ifndef __MYBASE_CPP_
#define __MYBASE_CPP_

#include <stdio.h>
#include <string.h>
#include "mybase.h"

/* popis: zapise do suboru ciferne int c, nakoniec zariadkuje
 * priklad: pre c==234 napise znaky '2', '3', '4', '\n'
 * pouzitie: while(!feof(in)) fputint(fgetc(in), out);*/
void fputint(int c, FILE *stream){
	int d = 10000;
	if(c < 0){
		fputc('-', stream);
		c = -c;
	}
	while(d > 1){
		if(c >= d){
			fputc(48 + (c/d), stream);
			c = c - d * (c/d);
		}
		d = d/10;
	}
	fputc(48 + c, stream);
	fprintf(stream, "\n");
}

/* popis: nasledujuce 2 makra (vyuzivajuce funkciu __code_char)
 *        kvoli CGI-skriptom konvertuju
 *        medzery na znak CGI_SPACE_CHAR a opacne
 *
 * encode_space(): 32 --> CGI_SPACE_CHAR
 * decode_space(): CGI_SPACE_CHAR --> 32
 * encode_semicolon(): 59 --> CGI_SEMICOLON
 * decode_semicolon(): CGI_SEMICOLON --> 59
 */
char* __code_char(char char_from, char char_to, char* str){
	int len = strlen(str);
	int i = len - 1;
	while(str[i] == 32){i--;} /* spapanie medzier na konci rekordu */
	str[i + 1] = '\0';
	len = strlen(str);
	for(i = len; i >= 0; i--)
		if(str[i] == char_from)
			str[i] = char_to;
	return str;
}

#define encode_space(str)	__code_char(32, CGI_SPACE_CHAR, str)
#define decode_space(str)	__code_char(CGI_SPACE_CHAR, 32, str)
#define encode_semicolon(str)	__code_char(59, CGI_SEMICOLON, str)
#define decode_semicolon(str)	__code_char(CGI_SEMICOLON, 59, str)

#endif /*__MYBASE_CPP_*/

