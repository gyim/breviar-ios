/***************************************************************/
/*                                                             */
/* myhpage.h                                                   */
/* (c)1999-2001 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | obsahuje vypis hlavicky a patky HTML dokumentu*/
/* document history                                            */
/*   19/11/1998A.D. | created                                  */
/*   06/09/2001A.D. | tento popis                              */
/*   2003-07-01a.D. | pridany subor pre hlavicku aj patku      */
/*                                                             */
/***************************************************************/

#ifndef __MYHPAGE_H_
#define __MYHPAGE_H_

#define FILE_HEADER "_header.htm"
#define FILE_FOOTER "_footer.htm"

/* exportuje hlavicku HTML dokumentu, kam pojde vysledok query */
void hlavicka(char *);
/* exportuje patku HTML dokumentu (vysledok query) */
void patka(void);

#endif /*__MYHPAGE_H_*/

