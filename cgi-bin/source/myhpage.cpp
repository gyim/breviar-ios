/***************************************************************/
/*                                                             */
/* myhpage.cpp                                                 */
/* (c)1999-2003 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | obsahuje vypis hlavicky a patky HTML dokumentu*/
/* document history                                            */
/*   28/10/1999A.D. | created                                  */
/*   25/02/2000A.D. | zrusena funkcia linky()                  */
/*   12/04/2000A.D. | pridana stranka HTTP_ADDRESS             */
/*   06/09/2001A.D. | tento popis                              */
/*   2003-06-30a.D. | pridane vypisovanie BUILD_DATE (mybase.h)*/
/*                  - tiez zapoznamkovane Kodovanie w-1250.    */
/*   2003-07-01a.D. | citanie hlavicky zo suboru               */
/*   2003-07-02a.D. | trosku zmenena patka                     */
/*                                                             */
/*                                                             */
/***************************************************************/

#ifndef __MYHPAGE_C_
#define __MYHPAGE_C_

#include <stdio.h>
#include <string.h>
#include <time.h> /* kvoli time_t a time(); */
#include "myconf.h" /* kvoli MAIL_ADDRESS a HTTP_ADDRESS; pridane 30/03/2000A.D. */
#include "myhpage.h"
#include "mydefs.h" /* kvoli #ifdef DEBUG; a tiez HTML_ - pridane 2003-07-02 */
#include "myexpt.h"
#include "mystring.h" /* kvoli mystrcpy, 2003-07-01 */
#include "mylog.h"

/* exportuje hlavicku HTML dokumentu, kam pojde vysledok query */
void hlavicka(char *title){
/* ak nedebugujem (do suboru), potom treba pre prehliadace exportovat
 * nasledujuci riadok nasledovany prazdnym riadkom
 */
	/* 2003-07-01, pridane pripadne citanie zo suboru */
	char fname[MAX_STR] = "";
	int c = 0;
	mystrcpy(fname, FILE_HEADER, MAX_STR);

#ifdef OS_linux
	Export("Content-type: text/html\n");
	Export("\n");
#endif

	FILE *body = fopen(fname, "r");

	Log("exporting %s:\n", fname);
	if(body == NULL){
		/*printf("error `%s'\n", sys_errlist[errno]);*/
		Log("  file `%s' not found\n", fname);
		Log("so, another attempt: exporting hard coded header...\n");

		Export("<html>\n<head>\n");
		Export("<!-- Liturgia hodin, (c)1999, 2000 Juraj Videky -->\n");
		Export("   <meta http-equiv=\"Content-Type\" content=\"text/html; charset=windows-1250\">\n");
		Export("<title>%s</title>\n", title);
		Export("</head>\n");
		Export("<body text=\"#000000\" bgcolor=\"#FFFFF0\" link=\"#000000\" vlink=\"#000000\" alink=\"#000000\">\n");
		/* pridane 24/07/2000A.D. */
		Export("<style>\n");
		Export("<!--\n");
		Export("	A:link {color: Black;}\n");
		Export("	A:hover {color: fuchsia;}\n");
		Export("-->\n");
		Export("</style>\n");
		return;
	}
	while((c = fgetc(body)) != EOF){
		Export("%c", c); /* fputc(c, exportfile); */
	}
	fclose(body);
}

/* nazov_mesiaca: string pre nazov dna; suhlasi s struct tm.tm_mon;
 * Month (0--11) */
const char *nm[] =
{"január", "február", "marec", "apríl", "máj", "jún", "júl",
 "august", "september", "október", "november", "december", "neznámy"};

/* exportuje patku HTML dokumentu (vysledok query) */
void patka(void){
	time_t t;
	struct tm dnes;
	int baserok = 1999;
	char rok[5];

	time(&t);

	/* konvertuje date/time na strukturu */
	dnes = *localtime(&t);
	/* upravenie time_check structure with the data */
	dnes.tm_year = dnes.tm_year + 1900;
	dnes.tm_yday = dnes.tm_yday + 1;
	strcpy(rok, "");
	if(dnes.tm_year > baserok){
		sprintf(rok, "-%d", dnes.tm_year);
	}

	Export("<hr>\n"); /* bolo tu <hr size=1>, ale to je v css-ku; 2003-07-02 */
	Export("<center>");
	Export("<"HTML_P_PATKA">Generovaná stránka\n");
	/* Export("(%s). ", ctime(&t) + 4); */
	Export("(%d. %s %d, %02d:%02d:%02d). ",
		dnes.tm_mday,
		nm[dnes.tm_mon],
		dnes.tm_year,
		dnes.tm_hour,
		dnes.tm_min,
		dnes.tm_sec);

	/* nezabudni zmenit #define BUILD_DATE v mybase.h!!! (2003-06-30) */
	Export("Build: %s. ", BUILD_DATE);

	/* zapoznamkovane, 2003-06-30 */
	/* Export("Kódovanie Windows-1250 (Central European).\n"); */
	Export("<br>\n");

	/* pridana stranka HTTP_ADDRESS, 12/04/2000A.D. */
	Export("<"HTML_LINK_NORMAL" href=\"%s\" target=\"_top\">%s</a>\n", HTTP_ADDRESS, HTTP_ADDRESS);
	Export("&#169; %d%s <"HTML_LINK_NORMAL" href=\"mailto:%s\">Juraj Vidéky</a>\n", baserok, rok, MAIL_ADDRESS);

	Export("</p>\n"); /* pridane kvoli tomu, ze cele to bude <p class="patka">, 2003-07-02 */
	Export("</center>");

	Export("</body>\n</html>\n");
}

#endif /*__MYHPAGE_C_*/