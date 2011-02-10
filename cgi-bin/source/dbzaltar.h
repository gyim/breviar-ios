/***************************************************************/
/*                                                             */
/* dbzaltar.h                                                  */
/* (c)1999-2001 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description |                                               */
/* document history                                            */
/*   22/02/2000A.D. | created                                  */
/*   06/09/2001A.D. | tento popis                              */
/*                                                             */
/***************************************************************/

#ifndef __DBZALTAR_H_
#define __DBZALTAR_H_

#include "liturgia.h"

#include "myexpt.h" /* export do suboru alebo na konzolu printf */
#include "mylog.h"
#include <string.h>

/* aby sa dala pouzivat v zaltar(); */
int sviatky_svatych(int, int);
int sviatky_svatych(int, int, int);
int sviatky_svatych(int, int, int, int); /* spustam druhykrat */

void set_popis_dummy(void); /* pridane 05/04/2000A.D. */

/* zaltar();
 *
 * vstup: den == 0 (DEN_NEDELA) .. 6 (DEN_SOBOTA)
 *        tyzzal == 1 .. 4 (prvy az stvrty tyzzal zaltar
 *
 * nastavi do _global_modl_... (podla _global_modlitba) udaje potrebne
 * k modlitbe
 *
 */
void zaltar(int den, int tyzzal);

void liturgicke_obdobie(int litobd, int tyzden, int den, int tyzzal, int poradie_svateho);

#endif /* __DBZALTAR_H_ */