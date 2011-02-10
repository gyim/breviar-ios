/* obsahuje zakladne vecicky */
/* Juraj Videky, 29/10/99a.D. */

#ifndef __MYBASE_H_
#define __MYBASE_H_

#include <stdio.h>

//#define RUN_MODLITBA_CEZ_DEN
/* 18/02/2000A.D.-- ci alokovat miesto pre a pouzivat
 * premenne pre modl_cez_den */

#define BYTES 250
#define SMALL 80

/* navratova hodnota funkcii */
#define NO_RESULT 2
#define FAILURE 1
#define SUCCESS 0

/* true -- false */
#define TRUE  1
#define FALSE 0
#define ANO   1
#define NIE   0

#define MAX_STR	300 /* maximalna dlzka retazca */
#define MAX_GLOBAL_STR 300 /* _global_string */ /* 31/03/2000A.D. */
#define MAX_QUERY_STR 300 /* query_string */
#define MAX_POM_QUERY_TYPE 300 /* pom_QUERY_TYPE */
#define MAX_GLOBAL_LINK 300 /* maximalna dlzka retazca _global_link */
#define MAX_ENV	100 /* maximalna dlzka environmentalnej premennej */
#define MAX_VARIABLES 10 /* maximalny pocet syst. premennych WWW_... */

/* popis: zapise do suboru ciferne int c, nakoniec zariadkuje
 * priklad: pre c==234 napise znaky '2', '3', '4', '\n'
 * pouzitie: while(!feof(in)) fputint(fgetc(in), out);*/
void fputint(int c, FILE *stream);

/* popis: nasledujuce 2 makra (vyuzivajuce funkciu __code_char)
 *        kvoli CGI-skriptom konvertuju
 *        medzery na znak CGI_SPACE_CHAR a opacne
 *
 * encode_space(): 32 --> CGI_SPACE_CHAR
 * decode_space(): CGI_SPACE_CHAR --> 32
 * encode_semicolon(): 59 --> CGI_SEMICOLON
 * decode_semicolon(): CGI_SEMICOLON --> 59
 */
char* __code_char(char char_from, char char_to, char* str);
#define encode_space(str)	__code_char(32, CGI_SPACE_CHAR, str)
#define decode_space(str)	__code_char(CGI_SPACE_CHAR, 32, str)
#define encode_semicolon(str)	__code_char(59, CGI_SEMICOLON, str)
#define decode_semicolon(str)	__code_char(CGI_SEMICOLON, 59, str)

#endif /*__MYBASE_H_*/