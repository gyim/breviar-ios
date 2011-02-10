/* obsahuje exportne rutinky na export do suboru FILE_EXPORT alebo printf */
/* Juraj Vid‚ky, 14/11/99a.D. */
/* zmenena definicia FILE_EXPORT, 10/02/2000A.D. */
/* zmenil som if defined -- 24/02/2000A.D.
 * povodne tam bolo DEBUG, teraz EXPORT_TO_FILE, pridal som EXPORT_TO_STDOUT
 */
#ifndef __MYEXPT_C_
#define __MYEXPT_C_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "mydefs.h"
#include "myexpt.h"
#include "mybase.h"

/* #define FILE_EXPORT -- v myexpt.h */
/* povodne to bolo #define, avsak kvoli tomu, aby sa to dalo menit,
 * v myexpt.h je deklarovane
 *
 * extern char FILE_EXPORT[MAX_STR];
 *
 * a to je definovane nasledovne:
 *
 */
char FILE_EXPORT[50] = DEFAULT_FILE_EXPORT;

/* navratove hodnoty su prerobene na int-y; vysledok SUCCESS resp. FAILURE */

int isbothExports = NIE;
/* inicialna hodnota true;
 * ci pri debuggovacom zapisovani do fajlu pisat aj na obrazovku */

void bothExports(void){
	isbothExports = ANO;
}

int exptused;
FILE *exportfile;

int initExport(void){
#if defined(EXPORT_TO_FILE)
	/* zapisovanie vyslednej stranky do suboru; pozor na nazvy suborov "" a "+" */
	if(FILE_EXPORT[strlen(FILE_EXPORT) - 1] == '+'){
		/* append, nie novy fajl; 13/03/2000A.D. */
		FILE_EXPORT[strlen(FILE_EXPORT) - 1] = '\0'; /* zrusime '+' na konci */
		exportfile = fopen(FILE_EXPORT, "a+t");
	}
	else{
		/* novy fajl */
		exportfile = fopen(FILE_EXPORT, "wt");
	}
	exptused = (exportfile == NULL)? FAILURE: SUCCESS;
	if(exportfile == NULL)
		exportfile = stdout;
#elif defined(EXPORT_TO_STDOUT)
	exportfile = stdout;
	exptused = SUCCESS;
#else
	#error Unsupported export model (use _EXPORT_TO_STDOUT or _EXPORT_TO_FILE)
#endif
	return exptused;
}

int initExport(char *expt_filename){ /* pridane, 13/03/2000A.D. */
	if(exptused == SUCCESS){
		closeExport();
	}
	strcpy(FILE_EXPORT, expt_filename);
	return initExport();
}

int closeExport(void){ /* pridane, urobi fclose(); 13/03/2000A.D. */
	int ret = EOF; /* error closing file */
	if(exptused == SUCCESS){
		ret = fclose(exportfile);
	}
	return ret;
}

void dumpFile(char *fname){
	int c;
	FILE *input_file = fopen(fname, "rb");
	if(input_file != NULL){
		while((c = fgetc(input_file)) != EOF)
			fputc(c, exportfile);
	}
}

/* kedysi tu bolo nasledovne:
 *
 * pouziva sa pri normalnom fungovani, vsetko sa posiela na konzolu
 *
 * nasledujuca definicia nahradza kratku:
 * #define Export	printf
int Export(char *fmt, ...){
	va_list argptr;
	int cnt;

	va_start(argptr, fmt);
	cnt = vprintf(fmt, argptr); // obycajne poslanie na konzolu
	va_end(argptr);
	return(cnt);
}
 *
 * avsak ked priradime do exportfile = stdout, tak potom staci
 * nasledovna definicia:
 */

/* vsetko sa posiela do suboru (handle == exportfile),
 * ak premenna exptused je 0,
 *    naviac ak isbothExports, tak sa posiela vystup aj na konzolu (stdout),
 * ak premenna exptused je 1,  tak sa posiela vystup iba na konzolu (stdout)
 */

int Export(char *fmt, ...){
	va_list argptr;
	int cnt;

	va_start(argptr, fmt);
	if(exptused == SUCCESS){
		cnt = vfprintf(exportfile, fmt, argptr);
		if(isbothExports)
			cnt = vprintf(fmt, argptr);
	}
	else{
		cnt = vprintf(fmt, argptr);
	}
	va_end(argptr);

	return(cnt);
}

#define YYdefault() { { \
	fprintf(exportfile, "%c", c); \
	if(isbothExports) \
		printf("%c", c); \
	} }
#define YYcharHTML(Kam, Lat2, ASCII, HTML, TeX, IBM)	{ { \
	fprintf(exportfile, "%s", HTML); \
	if(isbothExports) \
		printf("%s", HTML); \
	} }
#define YYcharASCII(Kam, Lat2, ASCII, HTML, TeX, IBM)	{ { \
	fprintf(exportfile, "%c", ASCII); \
	if(isbothExports) \
		printf("%c", ASCII); \
	} }

int ExpL2HTML(char *fmt)
{
	int i;
	int ilen;
	char c;
	ilen = strlen(fmt);
	for(i = 0; i < ilen; i++){
		c = fmt[i];
		switch(c){
			case '¬': YYcharHTML(128, 172, 67, "È", "\\vC ", 67); /*C makcen*/ break;
			case '': YYcharHTML(129, 129, 117, "&uuml;", "\\\"u", 117); /*u bodky*/ break;
			case '‚': YYcharHTML(130, 130, 101, "é", "\\\'e", 130); /*e dlzen*/ break;
			case 'Ô': YYcharHTML(131, 212, 100, "ï", "\\vd ", 100); /*d makcen*/ break;
			case '„': YYcharHTML(132, 132, 97, "&auml;", "\\\"a", 132); /*a bodky*/ break;
			case 'Ò': YYcharHTML(133, 210, 68, "Ï", "\\vD ", 68); /*D makcen*/ break;
			case '›': YYcharHTML(134, 155, 84, "", "\\vT ", 84); /*T makcen*/ break;
			case 'Ÿ': YYcharHTML(135, 159, 99, "è", "\\vc ", 99); /*c makcen*/ break;
			case 'Ø': YYcharHTML(136, 216, 101, "ì", "\\ve ", 101); /*e makcen*/ break;
			case '·': YYcharHTML(137, 183, 69, "Ì", "\\vE ", 69); /*E makcen*/ break;
			case '‘': YYcharHTML(138, 145, 76, "Å", "\\\'L ", 76); /*L dlzen*/ break;
			case 'Ö': YYcharHTML(139, 214, 73, "&Iacute;", "\\\'I ", 73); /*I dlzen*/ break;
			case '–': YYcharHTML(140, 150, 108, "¾", "\\vl ", 108); /*l makcen*/ break;
			case '’': YYcharHTML(141, 146, 108, "å", "\\\'l ", 108); /*l dlzen*/ break;
			case 'Ž': YYcharHTML(142, 142, 65, "&Auml;", "\\\"A ", 142); /*A bodky*/ break;
			case 'µ': YYcharHTML(143, 181, 65, "&Aacute;", "\\\'A ", 65); /*A dlzen*/ break;
			case '': YYcharHTML(144, 144, 69, "&Eacute;", "\\\'E ", 144); /*E dlzen*/ break;
			case '§': YYcharHTML(145, 167, 122, "ž", "\\vz ", 122); /*z makcen*/ break;
			case '¦': YYcharHTML(146, 166, 90, "Ž", "\\vZ ", 90); /*Z makcen*/ break;
			case '“': YYcharHTML(147, 147, 111, "&ocirc;", "\\^o ", 147); /*o vokan !!!*/ break;
			case '”': YYcharHTML(148, 148, 111, "&ouml;", "\\\"o", 148); /*o bodky*/ break;
			case 'à': YYcharHTML(149, 224, 79, "&Oacute;", "\\\'O", 79); /*O dlzen*/ break;
			case '…': YYcharHTML(150, 133, 117, "ù", "\\ou ", 117); /*u kruzok !!!*/ break;
			case 'é': YYcharHTML(151, 233, 85, "&Uacute;", "\\\'U ", 85); /*U dlzen*/ break;
			case 'ì': YYcharHTML(152, 236, 121, "&yacute;", "\\\'y", 121); /*y dlzen*/ break;
			case '™': YYcharHTML(153, 153, 79, "&Ouml;", "\\\"O", 153); /*O bodky*/ break;
			case 'š': YYcharHTML(154, 154, 85, "&Uuml;", "\\\"U", 154); /*U bodky*/ break;
			case 'æ': YYcharHTML(155, 230, 83, "Š", "\\vS ", 83); /*S makcen*/ break;
			case '•': YYcharHTML(156, 149, 76, "¼", "\\vL ", 76); /*L makcen*/ break;
			case 'í': YYcharHTML(157, 237, 89, "&Yacute;", "\\\'Y ", 89); /*Y dlzen*/ break;
			case 'ü': YYcharHTML(158, 252, 82, "Ø", "\\vR ", 82); /*R makcen*/ break;
			case 'œ': YYcharHTML(159, 156, 116, "", "\\vt ", 116); /*t makcen*/ break;
			case ' ': YYcharHTML(160, 160, 97, "&aacute;", "\\\'a ", 160); /*a dlzen*/ break;
			case '¡': YYcharHTML(161, 161, 105, "&iacute;", "\\\'i ", 161); /*i dlzen*/ break;
			case '¢': YYcharHTML(162, 162, 111, "&oacute;", "\\\'o ", 162); /*o dlzen*/ break;
			case '£': YYcharHTML(163, 163, 117, "&uacute;", "\\\'u ", 163); /*u dlzen*/ break;
			case 'å': YYcharHTML(164, 229, 110, "ò", "\\vn ", 110); /*n makcen*/ break;
			case 'Õ': YYcharHTML(165, 213, 78, "Ò", "\\vN ", 78); /*N makcen*/ break;
			case 'Þ': YYcharHTML(166, 222, 85, "Ù", "\\oU ", 85); /*U kruzok !!!*/ break;
			case 'â': YYcharHTML(167, 226, 79, "&Ocirc;", "", 79); /*O vokan !!!*/ break;
			case 'ç': YYcharHTML(168, 231, 115, "š", "\\vs ", 115); /*s makcen*/ break;
			case 'ý': YYcharHTML(169, 253, 114, "ø", "\\vr ", 114); /*r makcen*/ break;
			case 'ê': YYcharHTML(170, 234, 114, "à", "\\\'r ", 114); /*r dlzen*/ break;
			case 'è': YYcharHTML(171, 232, 82, "À", "\\\'R ", 82); /*R dlzen*/ break;
			case 'õ': YYcharHTML(173, 245, 0, "§", "", 0); /*paragraf !!!*/ break;
			default: YYdefault();
		}
	}
	return 0;
}

#endif /*__MYEXPT_C_*/