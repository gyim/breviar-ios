/* obsahuje exportne rutinky na export do suboru FILE_EXPORT alebo stdout */
/* Juraj Videky, 14/11/99a.D. */
/* zmenena definicia FILE_EXPORT, 10/02/2000A.D. */

#ifndef __MYEXPT_H_
#define __MYEXPT_H_

#include <stdio.h>
#include "mydefs.h"
#include "mybase.h"

#define DEFAULT_FILE_EXPORT "export.htm"

int Export(char *fmt, ...);
int ExpL2HTML(char *fmt);
void bothExports(void);
void dumpFile(char *fname);

/* povodne tu bolo #define FILE_EXPORT "export.htm" */
/* deklarovane tu; definovane v myexpt.c -- 21/02/2000A.D. */
extern char FILE_EXPORT[];

extern int exptused;
extern FILE *exportfile;

int initExport(void); /* nechapem, preco to tu chybalo; 22/02/2000A.D. */
int initExport(char *expt_filename); /* pridane, 13/03/2000A.D.; pozor na nazvy suborov "" a "+" */
int closeExport(void); /* pridane, urobi fclose(); 13/03/2000A.D. */
/* navratove hodnoty su prerobene na int-y; vysledok SUCCESS resp. FAILURE */

#endif /*__MYEXPT_H_*/