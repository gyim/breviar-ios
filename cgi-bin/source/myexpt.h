/***************************************************************/
/*                                                             */
/* myexpt.h                                                    */
/* (c)1999-2006 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | obsahuje exportne rutinky na export           */
/*               do suboru FILE_EXPORT alebo stdout            */
/* document history                                            */
/*   14/11/1999A.D. | created                                  */
/*   10/02/2000A.D. | zmenena definicia FILE_EXPORT            */
/*   06/09/2001A.D. | tento popis                              */
/*   2003-07-15a.D. | odstraneny #include "mybase.h"           */
/*   2004-03-15a.D. | pridany DEFAULT_HTML_EXPORT (batch mode) */
/*                                                             */
/***************************************************************/

#include "vstudio.h"

#ifndef __MYEXPT_H_
#define __MYEXPT_H_

#include <stdio.h>
#include "mydefs.h"

#define DEFAULT_FILE_EXPORT "export.htm"
#define DEFAULT_HTML_EXPORT "export2.htm"

short int Export(char *fmt, ...);
short int ExpL2HTML(char *fmt);
void bothExports(void);
void dumpFile(char *fname);

/* povodne tu bolo #define FILE_EXPORT "export.htm" */
/* deklarovane tu; definovane v myexpt.c -- 21/02/2000A.D. */
extern char FILE_EXPORT[];

extern short int exptused;
extern FILE *exportfile;

short int initExport(void); /* nechapem, preco to tu chybalo; 22/02/2000A.D. */
short int initExport(char *expt_filename); /* pridane, 13/03/2000A.D.; pozor na nazvy suborov "" (STR_EMPTY) a "+" */
short int closeExport(void); /* pridane, urobi fclose(); 13/03/2000A.D. */
/* navratove hodnoty su prerobene na int-y; vysledok SUCCESS resp. FAILURE */

#endif /*__MYEXPT_H_*/

