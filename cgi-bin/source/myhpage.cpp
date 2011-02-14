/***************************************************************/
/*                                                             */
/* myhpage.cpp                                                 */
/* (c)1999-2006 | Juraj Videky | videky@breviar.sk             */
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
/*   2003-07-15a.D. | trosku zmenena hlavicka (ako _header.htm)*/
/*   2004-03-16a.D. | funkcie hlavicka a patka aj do suboru    */
/*   2006-07-31a.D. | prv� kroky k jazykov�m mut�ci�m          */
/*                                                             */
/*                                                             */
/***************************************************************/

#include "vstudio.h"

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
#include "breviar.h" /* 2006-07-31 kv�li jazyku */
#include "liturgia.h" /* 2006-07-31 kv�li jazyku */

/* exportuje hlavicku HTML dokumentu, kam pojde vysledok query */
void hlavicka(char *title){
/* ak nedebugujem (do suboru), potom treba pre prehliadace exportovat
 * nasledujuci riadok nasledovany prazdnym riadkom
 */
	/* 2003-07-01, pridane pripadne citanie zo suboru */
	char fname[MAX_STR] = STR_EMPTY;
	int c = 0;
	mystrcpy(fname, FILE_HEADER, MAX_STR);

#if defined(OS_linux)
	Export("Content-type: text/html\n");
	Export("\n");
#elif defined(OS_Windows_Ruby)
	Export("Content-type: text/html\n");
	Export("\n");
#endif

	FILE *body = fopen(fname, "r");

	Log("exporting %s:\n", fname);
	if(body == NULL){
		/*printf("error `%s'\n", sys_errlist[errno]);*/
		Log("  file `%s' not found\n", fname);
		Log("so, another attempt: exporting hard coded header...\n");

		/* 2003-07-15, zmenene na hlavicku pre css-ko; zrusene <style> */
		Export("<html>\n<head>\n");
		Export("   <meta http-equiv=\"Content-Type\" content=\"text/html; charset=windows-1250\">\n");
		Export("   <meta name=\"Author\" content=\"Juraj Vid�ky\">\n");
		Export("   <link rel=\"stylesheet\" type=\"text/css\" href=\"/breviar.css\">\n");
		Export("<title>%s</title>\n", title);
		Export("</head>\n\n");
		Export("<body>\n");
		return;
	}
	while((c = fgetc(body)) != EOF){
		Export("%c", c); /* fputc(c, exportfile); */
	}
	fclose(body);
}

void hlavicka(char *title, FILE * expt){
/* ak nedebugujem (do suboru), potom treba pre prehliadace exportovat
 * nasledujuci riadok nasledovany prazdnym riadkom
 */
	/* 2003-07-01, pridane pripadne citanie zo suboru */
	char fname[MAX_STR] = STR_EMPTY;
	int c = 0;
	mystrcpy(fname, FILE_HEADER, MAX_STR);

#if defined(OS_linux)
	fprintf(expt, "Content-type: text/html\n");
	fprintf(expt, "\n");
#elif defined(OS_Windows_Ruby)
	fprintf(expt, "Content-type: text/html\n");
	fprintf(expt, "\n");
#endif

	FILE *body = fopen(fname, "r");

	Log("exporting %s:\n", fname);
	if(body == NULL){
		/*printf("error `%s'\n", sys_errlist[errno]);*/
		Log("  file `%s' not found\n", fname);
		Log("so, another attempt: exporting hard coded header...\n");

		/* 2003-07-15, zmenene na hlavicku pre css-ko; zrusene <style> */
		fprintf(expt, "<html>\n<head>\n");
		fprintf(expt, "   <meta http-equiv=\"Content-Type\" content=\"text/html; charset=windows-1250\">\n");
		fprintf(expt, "   <meta name=\"Author\" content=\"Juraj Vid�ky\">\n");
		fprintf(expt, "   <link rel=\"stylesheet\" type=\"text/css\" href=\"/breviar.css\">\n");
		fprintf(expt, "<title>%s</title>\n", title);
		fprintf(expt, "</head>\n\n");
		fprintf(expt, "<body>\n");
		return;
	}
	while((c = fgetc(body)) != EOF){
		fprintf(expt, "%c", c); /* fputc(c, exportfile); */
	}
	fclose(body);
}

/* nazov_mesiaca: string pre nazov dna; suhlasi s struct tm.tm_mon;
 * Month (0--11) */
const char *nm[] =
{"janu�r", "febru�r", "marec", "apr�l", "m�j", "j�n", "j�l",
 "august", "september", "okt�ber", "november", "december", "nezn�my"};

const char *nm_cz[] =
{"leden", "�nor", "b�ezen", "duben", "kv�ten", "�erven", "�ervenec",
 "srpen", "z���", "��jen", "listopad", "prosinec", "nezn�m�"};

const char *gpage[] = {"Generovan� str�nka", "Str�nky jsou generov�ny", "Generated page", "Generated"};

/* exportuje patku HTML dokumentu (vysledok query) */
void patka(void){
	time_t t;
	struct tm dnes;
	int baserok = 1999;
#define ROK 5
	char rok[ROK];

	time(&t);

	/* konvertuje date/time na strukturu */
	dnes = *localtime(&t);
	/* upravenie time_check structure with the data */
	dnes.tm_year = dnes.tm_year + 1900;
	dnes.tm_yday = dnes.tm_yday + 1;
	mystrcpy(rok, STR_EMPTY, ROK);
	if(dnes.tm_year > baserok){
		sprintf(rok, "-%d", dnes.tm_year);
	}

	Export("<hr>\n"); /* bolo tu <hr size=1>, ale to je v css-ku; 2003-07-02 */
	Export("<center>");
	Export("<"HTML_P_PATKA">%s\n", gpage[_global_jazyk]);
	/* Export("(%s). ", ctime(&t) + 4); */
	Export("(%d. %s %d, %02d:%02d:%02d). ",
		dnes.tm_mday,
		(_global_jazyk == JAZYK_CZ) ? nm_cz[dnes.tm_mon] : nm[dnes.tm_mon],
		dnes.tm_year,
		dnes.tm_hour,
		dnes.tm_min,
		dnes.tm_sec);

	/* nezabudni zmenit #define BUILD_DATE v mydefs.h!!! (2003-07-15) */
	Export("Build: %s. ", BUILD_DATE);

	/* zapoznamkovane, 2003-06-30 */
	/* Export("K�dovanie Windows-1250 (Central European).\n"); */
	Export("<br>\n");

	/* pridana stranka HTTP_ADDRESS, 12/04/2000A.D. */
	Export("<"HTML_LINK_NORMAL" href=\"%s\" target=\"_top\">%s</a>\n", HTTP_ADDRESS, HTTP_DISPLAY_ADDRESS);
	Export("&#169; %d%s <"HTML_LINK_NORMAL" href=\"mailto:%s\">Juraj Vid�ky</a>\n", baserok, rok, MAIL_ADDRESS);

	Export("</p>\n"); /* pridane kvoli tomu, ze cele to bude <p class="patka">, 2003-07-02 */
	Export("</center>");

	Export("</body>\n</html>\n");
}

/* exportuje patku HTML dokumentu (vysledok query) */
void patka(FILE * expt){
	time_t t;
	struct tm dnes;
	int baserok = 1999;
#define ROK 5
	char rok[ROK];

	time(&t);

	/* konvertuje date/time na strukturu */
	dnes = *localtime(&t);
	/* upravenie time_check structure with the data */
	dnes.tm_year = dnes.tm_year + 1900;
	dnes.tm_yday = dnes.tm_yday + 1;
	mystrcpy(rok, STR_EMPTY, ROK);
	if(dnes.tm_year > baserok){
		sprintf(rok, "-%d", dnes.tm_year);
	}

	fprintf(expt, "<hr>\n"); /* bolo tu <hr size=1>, ale to je v css-ku; 2003-07-02 */
	fprintf(expt, "<center>");
	fprintf(expt, "<"HTML_P_PATKA">Generovan� str�nka\n");
	/* fprintf(expt, "(%s). ", ctime(&t) + 4); */
	fprintf(expt, "(%d. %s %d, %02d:%02d:%02d). ",
		dnes.tm_mday,
		nm[dnes.tm_mon],
		dnes.tm_year,
		dnes.tm_hour,
		dnes.tm_min,
		dnes.tm_sec);

	/* nezabudni zmenit #define BUILD_DATE v mydefs.h!!! (2003-07-15) */
	fprintf(expt, "Build: %s. ", BUILD_DATE);

	/* zapoznamkovane, 2003-06-30 */
	/* fprintf(expt, "K�dovanie Windows-1250 (Central European).\n"); */
	fprintf(expt, "<br>\n");

	/* pridana stranka HTTP_ADDRESS, 12/04/2000A.D. */
	fprintf(expt, "<"HTML_LINK_NORMAL" href=\"%s\" target=\"_top\">%s</a>\n", HTTP_ADDRESS, HTTP_DISPLAY_ADDRESS);
	fprintf(expt, "&#169; %d%s <"HTML_LINK_NORMAL" href=\"mailto:%s\">Juraj Vid�ky</a>\n", baserok, rok, MAIL_ADDRESS);

	fprintf(expt, "</p>\n"); /* pridane kvoli tomu, ze cele to bude <p class="patka">, 2003-07-02 */
	fprintf(expt, "</center>");

	fprintf(expt, "</body>\n</html>\n");
}

#endif /*__MYHPAGE_C_*/

