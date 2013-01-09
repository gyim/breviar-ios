/************************************************************************/
/*                                                                      */
/* myhpage.h                                                            */
/* (c)1999-2013 | Juraj Vid�ky | videky@breviar.sk                      */
/*                                                                      */
/* description | obsahuje vypis hlavicky a patky HTML dokumentu         */
/* document history                                                     */
/*   19/11/1998A.D. | created                                           */
/*   06/09/2001A.D. | tento popis                                       */
/*   2003-07-01a.D. | pridany subor pre hlavicku aj patku               */
/*   2004-03-16a.D. | funkcie hlavicka a patka aj do suboru             */
/*   2008-08-08a.D. | hlavi�ka sa ne��ta z FILE_HEADER (kv�li css)      */
/*   2011-05-18a.D. | upraven� a zjednoten� hlavi�ka a p�tka,           */
/*                    _hlavicka() a _patka() pou��vaj� Export_to_file() */
/*                                                                      */
/************************************************************************/

#include "vstudio.h"
#include "myexpt.h"

#ifndef __MYHPAGE_H_
#define __MYHPAGE_H_

// #define FILE_HEADER "_header.htm"
// #define FILE_FOOTER "_footer.htm"

// exportuje hlavicku HTML dokumentu, kam pojde vysledok query
void hlavicka(char *title, short int level = 0, short int spec = 0);
void hlavicka(char *title, FILE * expt, short int level = 0, short int spec = 0);
// exportuje hlavicku XML dokumentu
void xml_hlavicka(void);
void xml_hlavicka(FILE * expt);

// exportuje patku HTML dokumentu (vysledok query)
void patka(void);
void patka(FILE * expt);
// exportuje patku XML dokumentu
void xml_patka(void);
void xml_patka(FILE * expt);

void myhpage_init_globals();

#endif // __MYHPAGE_H_

