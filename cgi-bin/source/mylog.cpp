/***************************************************************/
/*                                                             */
/* mylog.cpp                                                   */
/* (c)1997-2001 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | pomocne vypisovanie (logovanie) na obrazovku  */
/*               a/alebo do suboru                             */
/* document history                                            */
/*   07/12/1997A.D. | created                                  */
/*   13/10/1998A.D. | prerobeny                                */
/*   27/10/1998A.D. | male zmeny                               */
/*   01/12/1999A.D. | pridany NoLog (emptyLog)                 */
/*                    LOGGING ponechane (v takom pripade sa    */
/*                    loguje)                                  */
/*   24/02/2000A.D. |  pridane LOG_TO_FILE / LOG_TO_STDOUT     */
/*   06/09/2001A.D. | tento popis                              */
/* notes |                                                     */
/*   * ked je v materskom programe definovane LOG_TO_FILE, bude*/
/*     sa logovat do suboru, ktory treba dat ako vstup fname   */
/*     v initLog                                               */
/*   * v opacnom pripade sa nebude logovat do suboru           */
/*                                                             */
/***************************************************************/

#ifndef __MYLOG_C_
#define __MYLOG_C_

#include <stdio.h>
#include <stdarg.h>
#include "mydefs.h" /* tu su deklarovane vecicky ako sa ma __Log-ovat */
#include "mylog.h"

int both;

void bothLogs(void){ both = (0 == 0); }
void fileLog(void){ both = (0 != 0); }
int isbothLogs(void){ return both; }

#ifdef LOGGING

FILE *logfile;
int used;

/* popis: otvori logovaci subor; globalna premenna logfile obsahuje handle
 * vracia: on success, returns 0
 *         on error, returns 1
 */
int initLog(char *fname){
	fileLog();
#if defined(LOG_TO_FILE)
	logfile = fopen(fname, "wt");
	used = (logfile == NULL)? 1: 0;
#elif defined(LOG_TO_STDOUT)
	logfile = stdout;
	used = 0;
#else
	#error Unsupported logging model (use _LOG_TO_STDOUT or _LOG_TO_FILE)
#endif
	return used; // 1: failure, 0: success
}

/* popis: zatvori logovaci subor
 * vracia: on success, returns 0
 *         on error, returns EOF; presne ako fclose()
 */
int closeLog(void){
	int ret;
	if(used == 0){
		if((ret = fclose(logfile)) == EOF)
			fprintf(stderr, "Cannot close log file\n");
	}
	else{
		fprintf(stderr, "Log file not opened\n");
		ret = EOF;
	}
	return ret;
}

int __Log(char *fmt, ...)
{
	va_list argptr;
	int cnt;

	va_start(argptr, fmt);
	if(used == 0){
		cnt = vfprintf(logfile, fmt, argptr);
		if(both)
			cnt = vprintf(fmt, argptr);
	}
	else
		cnt = vprintf(fmt, argptr);
	va_end(argptr);

	return(cnt);
}

/* popis: zapise do logfile ciferne (po cifrach) int c
 * priklad: pre c==234 napise znaky '2', '3', '4'
 */
void Logint(int c){
	int d = 10000;
	if(used == 0){ // iba ak je pouzivany logfile
		if(c < 0){
			fputc('-', logfile);
			if(both)
				fputc('-', stdout);
			c = -c;
		}
		while(d > 1){
			if(c >= d){
				fputc(48 + (c/d), logfile);
				if(both)
					fputc(48 + (c/d), stdout);
				c = c - d * (c/d);
			}
			d = d/10;
		}
		fputc(48 + c, logfile);
		if(both)
			fputc(48 + c, stdout);
	}
}

/*
 * Nasleduje len atrapa modulu mylog.cpp
 * pouzije sa vtedy, ak sa nedebuguje
 *
 * staci v materskom programe nedefinovat #define LOGGING
 */

#else /* nie LOGGING */

int initLog(char *fname){return 0;}
/* void bothLogs(void){} */
/* void fileLog(void){} */
int closeLog(void){return 0;}
int __Log(char *fmt, ...){return 0;}
void Logint(int c){};

#endif /* LOGGING */

/* ------------------------------------------------------------------- */
/* empty log - nerobi nic, ale ma vstup (...) */
int NoLog(char *fmt, ...){
	return(fmt == 0); /* aby nehlasilo param `fmt' not used */
}


#endif /*__MYLOG_C_*/