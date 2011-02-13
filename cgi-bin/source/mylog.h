/***************************************************************/
/*                                                             */
/* mylog.h                                                     */
/* (c)1999-2005 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | logovanie                                     */
/* document history                                            */
/*   24/02/2000A.D. | created                                  */
/*   06/09/2001A.D. | tento popis                              */
/* notes |                                                     */
/*   * ked je v materskom programe definovane LOG_TO_FILE, bude*/
/*     sa logovat do suboru, ktory treba dat ako vstup fname   */
/*     v initLog                                               */
/*   * v opacnom pripade sa nebude logovat do suboru           */
/*                                                             */
/***************************************************************/

#ifndef __MYLOG_H_
#define __MYLOG_H_

#define EmptyLog NoLog
#define emptyLog NoLog
int NoLog(char *fmt, ...); /* empty log - nerobi nic, ale ma vstup (...) */

int initLog(char *fname);
void bothLogs(void); /* prepne na oboje logovanie */
void fileLog(void); /* prepne na logovanie do fajlu */
int isbothLogs(void); /* vrati 1, ak su oba logy, inak vrati 0 */
int closeLog(void);
/* Log() premenovana na __Log() -- 24/02/2000A.D. */
int __Log(char *fmt, ...);
void Logint(int c);

#endif /*__MYLOG_H_*/

