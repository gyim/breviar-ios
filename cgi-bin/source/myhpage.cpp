/************************************************************************/
/*                                                                      */
/* myhpage.cpp                                                          */
/* (c)1999-2011 | Juraj Videky | videky@breviar.sk                      */
/*                                                                      */
/* description | obsahuje vypis hlavicky a patky HTML dokumentu         */
/* document history                                                     */
/*   28/10/1999A.D. | created                                           */
/*   25/02/2000A.D. | zrusena funkcia linky()                           */
/*   12/04/2000A.D. | pridana stranka cfg_HTTP_ADDRESS_default          */
/*   06/09/2001A.D. | tento popis                                       */
/*   2003-06-30a.D. | pridane vypisovanie BUILD_DATE (mybase.h)         */
/*                  - tiez zapoznamkovane Kodovanie w-1250.             */
/*   2003-07-01a.D. | citanie hlavicky zo suboru                        */
/*   2003-07-02a.D. | trosku zmenena patka                              */
/*   2003-07-15a.D. | trosku zmenena hlavicka (ako _header.htm)         */
/*   2004-03-16a.D. | funkcie hlavicka a patka aj do suboru             */
/*   2006-07-31a.D. | prv� kroky k jazykov�m mut�ci�m                   */
/*   2008-01-23a.D. | upraven� funkcie patka()                          */
/*   2008-08-08a.D. | upraven� funkcie hlavicka() kv�li css             */
/*   2008-09-26a.D. | pridan� pou�itie nazov_mesiaca()                  */
/*   2008-12-22a.D. | upraven� exportovanie p�tky (�as)                 */
/*   2009-08-05a.D. | upraven� exportovanie hlavi�ky                    */
/*   2010-02-15a.D. | upraven� hlavi�ky aj p�tky (navig�cia)            */
/*   2011-05-13a.D. | doplnen� aj ve�kos� fontu                         */
/*   2011-05-18a.D. | doplnen� pou�itie charset_jazyka[]                */
/*   2011-05-18a.D. | upraven� a zjednoten� hlavi�ka a p�tka,           */
/*                    _hlavicka() a _patka() pou��vaj� Export_to_file() */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#include "vstudio.h"

#ifndef __MYHPAGE_CPP_
#define __MYHPAGE_CPP_

#include <stdio.h>
#include <string.h>
#include <time.h> /* kvoli time_t a time(); */
#include "myconf.h" /* kvoli cfg_MAIL_ADDRESS_default a cfg_HTTP_ADDRESS_default; pridane 30/03/2000A.D. */
#include "myhpage.h"
#include "mydefs.h" /* kvoli #ifdef DEBUG; a tiez HTML_ - pridane 2003-07-02 */
#include "myexpt.h"
#include "mystring.h" /* kvoli mystrcpy, 2003-07-01 */
#include "mylog.h"
#include "breviar.h" /* 2006-07-31 kv�li jazyku a css (2008-08-08) */
#include "liturgia.h" /* 2006-07-31 kv�li jazyku */

short int bol_content_type_text_html = NIE;

#ifndef __MYHPAGE_CPP_HTML_CONST
#define __MYHPAGE_CPP_HTML_CONST

// obsahuje %s
const char *html_header_1 = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"\n\t\"http://www.w3.org/TR/html4/loose.dtd\">\n<html>\n<head>\n\t<meta http-equiv=\"Content-Type\" content=\"text/html; charset=%s\">\n\t<meta name=\"Author\" content=\"Juraj Vid�ky\">\n\t<link rel=\"stylesheet\" type=\"text/css\" href=\"";
const char *html_footer_1 = STR_EMPTY; // "<p><center>______</center>"; // "<hr>";

#endif /* __MYHPAGE_CPP_HTML_CONST */

#define MAX_MAIL_LABEL 20
#define MAX_EXT 5
char html_mail_label[MAX_MAIL_LABEL];
char pismeno_modlitby;
char pismeno_prev[1];
char pismeno_next[1];
char ext[MAX_EXT];
char file_name_pom[MAX_STR];
char *ptr;
short int _local_modlitba;

/* exportuje hlavicku HTML dokumentu, kam pojde vysledok query */
void _hlavicka(char *title, FILE * expt, short int level, short int spec){
	Log("_hlavicka() -- za�iatok...\n");
	_local_modlitba = _global_modlitba;
	if((_local_modlitba == MODL_PRVE_VESPERY) || (_local_modlitba == MODL_DRUHE_VESPERY))
		_local_modlitba = MODL_VESPERY;
	if((_local_modlitba == MODL_PRVE_KOMPLETORIUM) || (_local_modlitba == MODL_DRUHE_KOMPLETORIUM))
		_local_modlitba = MODL_KOMPLETORIUM;

	/* 2009-08-04: viackr�t sa pri exporte modlitby do HTML exportovala hlavi�ka; pridan� kontrola */
	if(_global_hlavicka_Export > 0)
		return;
	_global_hlavicka_Export++;
	/* 
	 * 2003-07-01, pridane pripadne citanie zo suboru
	 * 2008-08-08: ��tanie zo s�boru odstr�nen�
	 */
	const char *nazov_css_suboru;
	if(_global_css == CSS_UNDEF)
		nazov_css_suboru = nazov_css[CSS_breviar_sk];
	else
		nazov_css_suboru = nazov_css[_global_css];

	/*
	 * 2011-05-05: nastavenie font-family
	 *             zatia� len pevn� re�azce; �asom mo�no bude premenn� pre n�zov fontu
	 * 2011-05-06: doplnen�: najprv sa testuje nastavenie _global_font; n�sledne sa pr�padne nastavia defaulty
	 */
	if((_global_font == FONT_UNDEF) || (_global_font == FONT_CHECKBOX)){
		if((_global_opt[OPT_2_HTML_EXPORT] & BIT_OPT_2_FONT_FAMILY) == BIT_OPT_2_FONT_FAMILY){
			mystrcpy(_global_css_font_family, DEFAULT_FONT_FAMILY_SANS_SERIF, MAX_STR);
		}
		else{
			mystrcpy(_global_css_font_family, DEFAULT_FONT_FAMILY_SERIF, MAX_STR);
		}
	}/* (_global_font == FONT_UNDEF)  || (_global_font == FONT_CHECKBOX) */
	else if(_global_font == FONT_CSS){
		mystrcpy(_global_css_font_family, DEFAULT_FONT_FAMILY_INHERIT, MAX_STR);
	}/* (_global_font == FONT_CSS) */
	else{
		mystrcpy(_global_css_font_family, nazov_fontu[_global_font], MAX_STR);
	}/* else */
	/*
	 * 2011-05-13: doplnen�: nastavenie font-size
	 */
	if(_global_font_size == FONT_SIZE_UNDEF){
		mystrcpy(_global_css_font_size, STR_EMPTY, MAX_STR);
	}/* (_global_font_size == FONT_SIZE_UNDEF) */
	else if(_global_font_size == FONT_SIZE_CSS){
		mystrcpy(_global_css_font_size, DEFAULT_FONT_SIZE_INHERIT, MAX_STR);
	}/* (_global_font_size == FONT_SIZE_CSS) */
	else{
		mystrcpy(_global_css_font_size, nazov_font_size_css[_global_font_size], MAX_STR);
	}/* else */

	if(bol_content_type_text_html == NIE){
#if defined(OS_linux)
		Export_to_file(expt, "Content-type: text/html\n");
		Export_to_file(expt, "\n");
#elif defined(OS_Windows_Ruby)
		Export_to_file(expt, "Content-type: text/html\n");
		Export_to_file(expt, "\n");
#endif
		bol_content_type_text_html = ANO;
	}
	Log("creating header...\n");
	/* 2003-07-15, zmenene na hlavicku pre css-ko; zrusene <style>
	 * 2008-08-08: pridan� dynamicky css-ko
	 * 2010-02-15: statick� texty do kon�t�nt
	 * 2011-05-18: charset sa nastav� pod�a jazyka
	 */
	Export_to_file(expt, (char *)html_header_1, charset_jazyka[_global_jazyk]);
#ifdef	EXPORT_CMDLINE_CSS
	// pre command-line pou�itie (aj pre batch m�d): "./breviar.css" resp. ".\breviar.css"
	/* 2009-08-03: level ozna�uje po�et adres�rov, o ktor� je treba �s� "hore" (pre mesa�n� export) */
	if(level == 0 && _global_opt_batch_monthly == ANO)
		level = 1;
	if(level < 0 || level > 5)
		level = 0;
	if(level == 0)
		Export_to_file(expt, ".");
	else{
		while(level > 1){
			Export_to_file(expt, "..");
			Export_to_file(expt, STR_PATH_SEPARATOR_HTML);
			level--;
		}
		Export_to_file(expt, "..");
	}
	Export_to_file(expt, STR_PATH_SEPARATOR_HTML);
#else
	// pre web-pou�itie (aj pre ruby): "/breviar.css"
	Export_to_file(expt, "/");
#endif
	Export_to_file(expt, "%s\">\n", nazov_css_suboru); // n�zov css s�boru
	Export_to_file(expt, "<title>%s</title>\n", title);
	Export_to_file(expt, "</head>\n\n");

	/* 2011-05-05: pridanie font-family 
	 * 2011-05-06: font sa neprid�va v�dy
	 */
	Export_to_file(expt, "<body");
	if((_global_font != FONT_CSS) || (_global_font_size != FONT_SIZE_CSS)){
		Export_to_file(expt, " style=\"");
		if(_global_font != FONT_CSS){
			Export_to_file(expt, "font-family: %s", _global_css_font_family);
		}
		if(_global_font_size != FONT_SIZE_CSS){
			if(_global_font != FONT_CSS){
				Export_to_file(expt, "; ");
			}
			Export_to_file(expt, "font-size: %s", _global_css_font_size);
		}
		Export_to_file(expt, "\"");
	}
	/* 2010-02-15: kv�li �peci�lnemu "zoznam.htm" */
	if(spec == 1){
		Export_to_file(expt, " onLoad=\"fn_aktualne(0,0,0)\"");
	}
	Export_to_file(expt, ">\n");

	/* 2010-02-15: doplnen� predo�l� a nasledovn� modlitba */
	if(_global_opt_batch_monthly == ANO && query_type != PRM_BATCH_MODE){
		Export_to_file(expt, "<center>\n");
		pismeno_modlitby = CHAR_MODL_NEURCENA;
		if((_local_modlitba < MODL_NEURCENA) && (_local_modlitba >= MODL_INVITATORIUM))
			pismeno_modlitby = char_modlitby[_local_modlitba];
		sprintf(ext, "%c", pismeno_modlitby);
		strcat(ext, ".htm");
		Export_to_file(expt, "<p>");
		// << prev
		mystrcpy(file_name_pom, FILE_EXPORT, MAX_STR);
		ptr = strstr(file_name_pom, ext);
		if((_local_modlitba < MODL_NEURCENA) && (_local_modlitba > MODL_INVITATORIUM)){
			if(ptr != NULL){
				sprintf(pismeno_prev, "%c", char_modlitby[_local_modlitba - 1]);
				strncpy(ptr, pismeno_prev, 1);
			}
			Export_to_file(expt, "<a href=\"%s\">", file_name_pom);
			Export_to_file(expt, (char *)html_text_batch_Prev[_global_jazyk]);
			Export_to_file(expt, " ");
			Export_to_file(expt, (char *)nazov_modlitby(_local_modlitba - 1));
			Export_to_file(expt, "</a>");
		}
		// |
		Export_to_file(expt, " | ");
		// ^ hore
		Export_to_file(expt, "<a href=\".%s%s\">", STR_PATH_SEPARATOR_HTML, _global_export_navig_hore); // v tom istom adres�ri
		Export_to_file(expt, (char *)html_text_batch_Back[_global_jazyk]);
		Export_to_file(expt, "</a>");
		// |
		Export_to_file(expt, " | ");
		// >> next
		mystrcpy(file_name_pom, FILE_EXPORT, MAX_STR);
		ptr = strstr(file_name_pom, ext);
		if((_local_modlitba != MODL_NEURCENA) && (_local_modlitba < MODL_KOMPLETORIUM)){
			if(ptr != NULL){
				sprintf(pismeno_next, "%c", char_modlitby[_local_modlitba + 1]);
				strncpy(ptr, pismeno_next, 1);
			}
			Export_to_file(expt, "<a href=\"%s\">", file_name_pom);
			Export_to_file(expt, (char *)nazov_modlitby(_local_modlitba + 1));
			Export_to_file(expt, " ");
			Export_to_file(expt, (char *)html_text_batch_Next[_global_jazyk]);
			Export_to_file(expt, "</a>");
		}
		Export_to_file(expt, "</p>");
		Export_to_file(expt, "</center>\n");
	}/* << predo�l� | ^ hore | nasledovn� >> */
	Log("_hlavicka() -- koniec.\n");
	return;
}/* _hlavicka() */

void hlavicka(char *title, short int level, short int spec){
	_hlavicka(title, NULL, level, spec);
}
void hlavicka(char *title, FILE * expt, short int level, short int spec){
	_hlavicka(title, expt, level, spec);
}

/* 2008-01-23: upraven� */
//const char *gpage[] = {"Generovan� str�nka", "Str�nky jsou generov�ny", "Generated page", "Generated"};
const char *gpage[POCET_JAZYKOV + 1] = {"Generovan�: ", "Generov�no: ", "Generated: ", "Generated: ", "Generated: ", "Generov�no: ", "Gener�lva: "};
// Generovan� + d�tum: "%d. %s %d, %02d:%02d:%02d" -- p�vodne to bolo v z�tvork�ch
const char *datum_cas_template[POCET_JAZYKOV + 1] = {"%d. %s %d, %02d:%02d", "%d. %s %d, %02d:%02d", "%d. %s %d, %02d:%02d", "%d. %s %d, %02d:%02d", "%d. %s %d, %02d:%02d", "%d. %s %d, %02d:%02d", "%d. %s %d, %02d:%02d"};
// Build: "Build: %s. "
const char *build_template[POCET_JAZYKOV + 1] = {"<!--Verzia: %s.-->", "<!--Verze: %s.-->", "<!--Build: %s.-->", "<!--Build: %s.-->", "<!--Build: %s.-->", "<!--Verze: %s.-->", "<!--Build: %s.-->"};
// Generovan� + d�tum (bez �asu - pre batch m�d, aby sa �ahko porovn�vali vygenerovan� modlitby): "%d. %s %d"
const char *datum_template[POCET_JAZYKOV + 1] = {"%d. %s %d", "%d. %s %d", "%d. %s %d", "%d. %s %d", "%d. %s %d", "%d. %s %d", "%d. %s %d"};

#define HTML_P_PATKA "p class=\"patka\""

const char *html_mail_label_long = "Juraj Vid�ky";
const char *html_mail_label_short = "J. V.";

/* exportuje patku HTML dokumentu (vysledok query) */
void _patka(FILE * expt){
	Log("_patka() -- za�iatok...\n");
	_local_modlitba = _global_modlitba;
	if((_local_modlitba == MODL_PRVE_VESPERY) || (_local_modlitba == MODL_DRUHE_VESPERY))
		_local_modlitba = MODL_VESPERY;
	if((_local_modlitba == MODL_PRVE_KOMPLETORIUM) || (_local_modlitba == MODL_DRUHE_KOMPLETORIUM))
		_local_modlitba = MODL_KOMPLETORIUM;

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

	/* 2010-02-15: vlo�en� "^ hore" pod�a hlavicka(); doplnen� predo�l� a nasledovn� modlitba */
	if(_global_opt_batch_monthly == ANO && query_type != PRM_BATCH_MODE){
		Export_to_file(expt, "<center>\n");
		pismeno_modlitby = CHAR_MODL_NEURCENA;
		if((_local_modlitba < MODL_NEURCENA) && (_local_modlitba >= MODL_INVITATORIUM))
			pismeno_modlitby = char_modlitby[_local_modlitba];
		sprintf(ext, "%c", pismeno_modlitby);
		strcat(ext, ".htm");
		Export_to_file(expt, "<p>");
		// << prev
		mystrcpy(file_name_pom, FILE_EXPORT, MAX_STR);
		ptr = strstr(file_name_pom, ext);
		if((_local_modlitba < MODL_NEURCENA) && (_local_modlitba > MODL_INVITATORIUM)){
			if(ptr != NULL){
				sprintf(pismeno_prev, "%c", char_modlitby[_local_modlitba - 1]);
				strncpy(ptr, pismeno_prev, 1);
			}
			Export_to_file(expt, "<a href=\"%s\">", file_name_pom);
			Export_to_file(expt, (char *)html_text_batch_Prev[_global_jazyk]);
			Export_to_file(expt, " ");
			Export_to_file(expt, (char *)nazov_modlitby(_local_modlitba - 1));
			Export_to_file(expt, "</a>");
		}
		// |
		Export_to_file(expt, " | ");
		// ^ hore
		Export_to_file(expt, "<a href=\".%s%s\">", STR_PATH_SEPARATOR_HTML, _global_export_navig_hore); // v tom istom adres�ri
		Export_to_file(expt, (char *)html_text_batch_Back[_global_jazyk]);
		Export_to_file(expt, "</a>");
		// |
		Export_to_file(expt, " | ");
		// >> next
		mystrcpy(file_name_pom, FILE_EXPORT, MAX_STR);
		ptr = strstr(file_name_pom, ext);
		if((_local_modlitba != MODL_NEURCENA) && (_local_modlitba < MODL_KOMPLETORIUM)){
			if(ptr != NULL){
				sprintf(pismeno_next, "%c", char_modlitby[_local_modlitba + 1]);
				strncpy(ptr, pismeno_next, 1);
			}
			Export_to_file(expt, "<a href=\"%s\">", file_name_pom);
			Export_to_file(expt, (char *)nazov_modlitby(_local_modlitba + 1));
			Export_to_file(expt, " ");
			Export_to_file(expt, (char *)html_text_batch_Next[_global_jazyk]);
			Export_to_file(expt, "</a>");
		}
		Export_to_file(expt, "</p>");
		Export_to_file(expt, "</center>\n");
	}/* << predo�l� | ^ hore | nasledovn� >> */

	Export_to_file(expt, (char *)html_footer_1);

	if(_global_opt_batch_monthly == ANO && query_type != PRM_BATCH_MODE){
		mystrcpy(html_mail_label, html_mail_label_short, MAX_MAIL_LABEL);
	}
	else
	{
		mystrcpy(html_mail_label, html_mail_label_long, MAX_MAIL_LABEL);
	}

	Export("\n");
	/* 2010-02-15: cel� zapozn�mkovan� */
	if(1 == 1 || _global_opt_batch_monthly == ANO && query_type != PRM_BATCH_MODE){
		Export_to_file(expt, "<"HTML_P_PATKA">\n");
	}
	else{
		Export_to_file(expt, "<"HTML_P_PATKA">%s\n", gpage[_global_jazyk]);
		/* Export_to_file(expt, "(%s). ", ctime(&t) + 4); */
		/* 2008-12-22: odvetven� - pre commandline export (do s�boru) sa netla�� �asov� zlo�ka, kedy bolo HTML generovan� */
#if defined(EXPORT_TO_FILE)
		Export_to_file(expt, (char *)datum_template[_global_jazyk],
			dnes.tm_mday,
			nazov_mesiaca(dnes.tm_mon) /* nm[dnes.tm_mon] */,
			dnes.tm_year
			);
#else
		Export_to_file(expt, (char *)datum_cas_template[_global_jazyk],
			dnes.tm_mday,
			nazov_mesiaca(dnes.tm_mon) /* nm[dnes.tm_mon] */,
			dnes.tm_year,
			dnes.tm_hour,
			dnes.tm_min
			// , dnes.tm_sec
			);
#endif
		Export_to_file(expt, ". ");

		/* nezabudni zmenit #define BUILD_DATE v mydefs.h (2003-07-15) */
		Export_to_file(expt, (char *)build_template[_global_jazyk], BUILD_DATE);

		/* zapoznamkovane, 2003-06-30 */
		/* Export_to_file(expt, "K�dovanie Windows-1250 (Central European).\n"); */
		Export_to_file(expt, "<br>\n");
	}

	/* pridana stranka cfg_HTTP_ADDRESS_default, 12/04/2000A.D. */
	Export_to_file(expt, "<"HTML_LINK_NORMAL" href=\"%s\" target=\"_top\">%s</a>\n", cfg_HTTP_ADDRESS_default, cfg_HTTP_DISPLAY_ADDRESS_default);
	Export_to_file(expt, "&#169; %d%s <"HTML_LINK_NORMAL" href=\"mailto:%s\">%s</a>\n", baserok, rok, cfg_MAIL_ADDRESS_default, html_mail_label);

	Export_to_file(expt, "</p>\n"); /* pridane kvoli tomu, ze cele to bude <p class="patka">, 2003-07-02 */

	Export_to_file(expt, "</body>\n</html>\n");
	Log("_patka() -- koniec.\n");
	return;
}/* _patka() */

void patka(void){
	_patka(NULL);
}
void patka(FILE * expt){
	_patka(expt);
}

#endif /* __MYHPAGE_CPP_ */
