/***************************************************************/
/*                                                             */
/* myhpage.cpp                                                 */
/* (c)1999-2008 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | obsahuje vypis hlavicky a patky HTML dokumentu*/
/* document history                                            */
/*   28/10/1999A.D. | created                                  */
/*   25/02/2000A.D. | zrusena funkcia linky()                  */
/*   12/04/2000A.D. | pridana stranka cfg_HTTP_ADDRESS_default */
/*   06/09/2001A.D. | tento popis                              */
/*   2003-06-30a.D. | pridane vypisovanie BUILD_DATE (mybase.h)*/
/*                  - tiez zapoznamkovane Kodovanie w-1250.    */
/*   2003-07-01a.D. | citanie hlavicky zo suboru               */
/*   2003-07-02a.D. | trosku zmenena patka                     */
/*   2003-07-15a.D. | trosku zmenena hlavicka (ako _header.htm)*/
/*   2004-03-16a.D. | funkcie hlavicka a patka aj do suboru    */
/*   2006-07-31a.D. | prvé kroky k jazykovým mutáciám          */
/*   2008-01-23a.D. | upravené funkcie patka()                 */
/*   2008-08-08a.D. | upravené funkcie hlavicka() kvôli css    */
/*   2008-09-26a.D. | pridané použitie nazov_mesiaca()         */
/*   2008-12-22a.D. | upravené exportovanie pätky (èas)        */
/*                                                             */
/*                                                             */
/***************************************************************/

#include "vstudio.h"

#ifndef __MYHPAGE_C_
#define __MYHPAGE_C_

#include <stdio.h>
#include <string.h>
#include <time.h> /* kvoli time_t a time(); */
#include "myconf.h" /* kvoli cfg_MAIL_ADDRESS_default a cfg_HTTP_ADDRESS_default; pridane 30/03/2000A.D. */
#include "myhpage.h"
#include "mydefs.h" /* kvoli #ifdef DEBUG; a tiez HTML_ - pridane 2003-07-02 */
#include "myexpt.h"
#include "mystring.h" /* kvoli mystrcpy, 2003-07-01 */
#include "mylog.h"
#include "breviar.h" /* 2006-07-31 kvôli jazyku a css (2008-08-08) */
#include "liturgia.h" /* 2006-07-31 kvôli jazyku */

/* exportuje hlavicku HTML dokumentu, kam pojde vysledok query */
void hlavicka(char *title){
	/* 
	 * 2003-07-01, pridane pripadne citanie zo suboru
	 * 2008-08-08: èítanie zo súboru odstránené
	 */
	const char *nazov_css_suboru;
	if(_global_css == CSS_UNDEF)
		nazov_css_suboru = nazov_css[CSS_breviar_sk];
	else
		nazov_css_suboru = nazov_css[_global_css];
#if defined(OS_linux)
	Export("Content-type: text/html\n");
	Export("\n");
#elif defined(OS_Windows_Ruby)
	Export("Content-type: text/html\n");
	Export("\n");
#endif
	Log("creating header...\n");
	/* 2003-07-15, zmenene na hlavicku pre css-ko; zrusene <style> */
	/* 2008-08-08: pridané dynamicky css-ko */
	Export("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"\n");
	Export("\t\"http://www.w3.org/TR/html4/loose.dtd\">\n");
	Export("<html>\n<head>\n");
	Export("\t<meta http-equiv=\"Content-Type\" content=\"text/html; charset=windows-1250\">\n");
	Export("\t<meta name=\"Author\" content=\"Juraj Vidéky\">\n");
	Export("\t<link rel=\"stylesheet\" type=\"text/css\" href=\"");
#ifdef	EXPORT_CMDLINE_CSS
	// pre command-line použitie (aj pre batch mód): "./breviar.css" resp. ".\breviar.css"
	Export(".");
	Export(STR_PATH_SEPARATOR);
#else
	// pre web-použitie (aj pre ruby): "/breviar.css"
	Export("/");
#endif
	Export("%s\">\n", nazov_css_suboru); // názov css súboru
	Export("<title>%s</title>\n", title);
	Export("</head>\n\n");
	Export("<body>\n");
	return;
}/* hlavicka() */

void hlavicka(char *title, FILE * expt){
	/* 
	 * 2003-07-01, pridane pripadne citanie zo suboru
	 * 2008-08-08: èítanie zo súboru odstránené
	 */
	const char *nazov_css_suboru;
	if(_global_css == CSS_UNDEF)
		nazov_css_suboru = nazov_css[CSS_breviar_sk];
	else
		nazov_css_suboru = nazov_css[_global_css];
#if defined(OS_linux)
	fprintf(expt, "Content-type: text/html\n");
	fprintf(expt, "\n");
#elif defined(OS_Windows_Ruby)
	fprintf(expt, "Content-type: text/html\n");
	fprintf(expt, "\n");
#endif
	Log("creating header...\n");
	/* 2003-07-15, zmenene na hlavicku pre css-ko; zrusene <style> */
	/* 2008-08-08: pridané dynamicky css-ko */
	fprintf(expt, "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"");
	fprintf(expt, "\t\"http://www.w3.org/TR/html4/loose.dtd\">");
	fprintf(expt, "<html>\n<head>\n");
	fprintf(expt, "\t<meta http-equiv=\"Content-Type\" content=\"text/html; charset=windows-1250\">\n");
	fprintf(expt, "\t<meta name=\"Author\" content=\"Juraj Vidéky\">\n");
	fprintf(expt, "\t<link rel=\"stylesheet\" type=\"text/css\" href=\"");
#ifdef	EXPORT_CMDLINE_CSS
	// pre command-line použitie (aj pre batch mód): "./breviar.css" resp. ".\breviar.css"
	fprintf(expt, ".");
	fprintf(expt, STR_PATH_SEPARATOR);
#else
	// pre web-použitie (aj pre ruby): "/breviar.css"
	fprintf(expt, "/");
#endif
	fprintf(expt, "%s\">\n", nazov_css_suboru); // názov css súboru
	fprintf(expt, "<title>%s</title>\n", title);
	fprintf(expt, "</head>\n\n");
	fprintf(expt, "<body>\n");
	return;
}/* hlavicka() */

/* 2008-01-23: upravené */
//const char *gpage[] = {"Generovaná stránka", "Stránky jsou generovány", "Generated page", "Generated"};
const char *gpage[POCET_JAZYKOV + 1] = {"Generované: ", "Generováno: ", "Generated: ", "Generated: ", "Generated: ", "Generováno: "};
// Generované + dátum: "%d. %s %d, %02d:%02d:%02d" -- pôvodne to bolo v zátvorkách
const char *datum_cas_template[POCET_JAZYKOV + 1] = {"%d. %s %d, %02d:%02d", "%d. %s %d, %02d:%02d", "%d. %s %d, %02d:%02d", "%d. %s %d, %02d:%02d", "%d. %s %d, %02d:%02d", "%d. %s %d, %02d:%02d"};
// Build: "Build: %s. "
const char *build_template[POCET_JAZYKOV + 1] = {"<!--Verzia: %s.-->", "<!--Verze: %s.-->", "<!--Build: %s.-->", "<!--Build: %s.-->", "<!--Build: %s.-->", "<!--Verze: %s.-->"};
// Generované + dátum (bez èasu - pre batch mód, aby sa ¾ahko porovnávali vygenerované modlitby): "%d. %s %d"
const char *datum_template[POCET_JAZYKOV + 1] = {"%d. %s %d", "%d. %s %d", "%d. %s %d", "%d. %s %d", "%d. %s %d", "%d. %s %d"};

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
	/* 2008-12-22: odvetvené - pre commandline export (do súboru) sa netlaèí èasová zložka, kedy bolo HTML generované */
#if defined(EXPORT_TO_FILE)
	Export((char *)datum_template[_global_jazyk],
		dnes.tm_mday,
		nazov_mesiaca(dnes.tm_mon)/* (_global_jazyk == JAZYK_CZ) ? nm_cz[dnes.tm_mon] : nm[dnes.tm_mon] */,
		dnes.tm_year
		);
#else
	Export((char *)datum_cas_template[_global_jazyk],
		dnes.tm_mday,
		nazov_mesiaca(dnes.tm_mon)/* (_global_jazyk == JAZYK_CZ) ? nm_cz[dnes.tm_mon] : nm[dnes.tm_mon] */,
		dnes.tm_year,
		dnes.tm_hour,
		dnes.tm_min
		// , dnes.tm_sec
		);
#endif
	Export(". ");

	/* nezabudni zmenit #define BUILD_DATE v mydefs.h!!! (2003-07-15) */
	Export((char *)build_template[_global_jazyk], BUILD_DATE);

	/* zapoznamkovane, 2003-06-30 */
	/* Export("Kódovanie Windows-1250 (Central European).\n"); */
	Export("<br>\n");

	/* pridana stranka cfg_HTTP_ADDRESS_default, 12/04/2000A.D. */
	Export("<"HTML_LINK_NORMAL" href=\"%s\" target=\"_top\">%s</a>\n", cfg_HTTP_ADDRESS_default, cfg_HTTP_DISPLAY_ADDRESS_default);
	Export("&#169; %d%s <"HTML_LINK_NORMAL" href=\"mailto:%s\">Juraj Vidéky</a>\n", baserok, rok, cfg_MAIL_ADDRESS_default);

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
	fprintf(expt, "<"HTML_P_PATKA">%s\n", gpage[_global_jazyk]);
	/* fprintf(expt, "(%s). ", ctime(&t) + 4); */
	/* 2008-12-22: odvetvené - pre commandline export (do súboru) sa netlaèí èasová zložka, kedy bolo HTML generované */
#if defined(EXPORT_TO_FILE)
	fprintf(expt, (char *)datum_template[_global_jazyk],
		dnes.tm_mday,
		nazov_mesiaca(dnes.tm_mon) /* nm[dnes.tm_mon] */,
		dnes.tm_year
		);
#else
	fprintf(expt, (char *)datum_cas_template[_global_jazyk],
		dnes.tm_mday,
		nazov_mesiaca(dnes.tm_mon) /* nm[dnes.tm_mon] */,
		dnes.tm_year,
		dnes.tm_hour,
		dnes.tm_min
		// , dnes.tm_sec
		);
#endif
	fprintf(expt, ". ");

	/* nezabudni zmenit #define BUILD_DATE v mydefs.h!!! (2003-07-15) */
	fprintf(expt, (char *)build_template[_global_jazyk], BUILD_DATE);

	/* zapoznamkovane, 2003-06-30 */
	/* fprintf(expt, "Kódovanie Windows-1250 (Central European).\n"); */
	fprintf(expt, "<br>\n");

	/* pridana stranka cfg_HTTP_ADDRESS_default, 12/04/2000A.D. */
	fprintf(expt, "<"HTML_LINK_NORMAL" href=\"%s\" target=\"_top\">%s</a>\n", cfg_HTTP_ADDRESS_default, cfg_HTTP_DISPLAY_ADDRESS_default);
	fprintf(expt, "&#169; %d%s <"HTML_LINK_NORMAL" href=\"mailto:%s\">Juraj Vidéky</a>\n", baserok, rok, cfg_MAIL_ADDRESS_default);

	fprintf(expt, "</p>\n"); /* pridane kvoli tomu, ze cele to bude <p class="patka">, 2003-07-02 */
	fprintf(expt, "</center>");

	fprintf(expt, "</body>\n</html>\n");
}

#endif /*__MYHPAGE_C_*/
