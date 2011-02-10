/***************************************************************/
/*                                                             */
/* myhpage.cpp                                                 */
/* (c)1999-2001 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | obsahuje vypis hlavicky a patky HTML dokumentu*/
/* document history                                            */
/*   28/10/1999A.D. | created                                  */
/*   25/02/2000A.D. | zrusena funkcia linky()                  */
/*   12/04/2000A.D. | pridana stranka HTTP_ADDRESS             */
/*   06/09/2001A.D. | tento popis                              */
/*                                                             */
/***************************************************************/

#ifndef __MYHPAGE_C_
#define __MYHPAGE_C_

#include <stdio.h>
#include <string.h>
#include <time.h> /* kvoli time_t a time(); */
#include "myconf.h" /* kvoli MAIL_ADDRESS a HTTP_ADDRESS; pridane 30/03/2000A.D. */
#include "myhpage.h"
#include "mydefs.h" /* kvoli #ifdef DEBUG */
#include "myexpt.h"

/* exportuje hlavicku HTML dokumentu, kam pojde vysledok query */
void hlavicka(char *title){
/* ak nedebugujem (do suboru), potom treba pre prehliadace exportovat
 * nasledujuci riadok nasledovany prazdnym riadkom
 */
#ifdef OS_linux
	Export("Content-type: text/html\n");
	Export("\n");
#endif
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

	Export("<hr size=1>\n");
	Export("<center>");
	Export("<font size=-1>Generovaná stránka\n");
	/* Export("(%s). ", ctime(&t) + 4); */
	Export("(%d. %s %d, %02d:%02d:%02d). ",
		dnes.tm_mday,
		nm[dnes.tm_mon],
		dnes.tm_year,
		dnes.tm_hour,
		dnes.tm_min,
		dnes.tm_sec);
	Export("Kódovanie Windows-1250 (Central European).\n");
	Export("</FONT>\n<br>\n");

	/* pridana stranka HTTP_ADDRESS, 12/04/2000A.D. */
	Export("<a href=\"%s\" target=\"_top\">%s</a> &#169; %d%s <A HREF=\"mailto:%s\">Juraj Vidéky</A>", HTTP_ADDRESS, HTTP_ADDRESS, baserok, rok, MAIL_ADDRESS);
	Export("</CENTER>");

	Export("</BODY>\n</HTML>\n");
}

#endif /*__MYHPAGE_C_*/