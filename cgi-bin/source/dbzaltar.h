/***************************************************************/
/*                                                             */
/* dbzaltar.h                                                  */
/* (c)1999-2006 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description |                                               */
/* document history                                            */
/*   22/02/2000A.D. | created                                  */
/*   06/09/2001A.D. | tento popis                              */
/*   2003-08-13a.D. | #define presunute sem z dbzaltar.cpp     */
/*   2003-11-20a.D. | pridane ANCHOR_CITANIE 1 a 2             */
/*   2006-01-24a.D. | pridane zaltar_zvazok()                  */
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
 *
 * 2006-01-24: žalmy pre posvätné èítanie sú v II. zväzku žaltára (pôst, ve¾ká noc)
 *             pre niektoré dni odlišné, preto sme vytvorili aj ïalší parameter,
 *             ktorý sa používa len pri volaní za úèelom konkrétnej modlitby
 *             (pre vo¾bu posv. èítania len pre deò a týždeò žaltára sa použije default)
 *
 */
void zaltar(int den, int tyzzal);
void zaltar_zvazok(int den, int tyzzal, int obdobie);

void liturgicke_obdobie(int litobd, int tyzden, int den, int tyzzal, int poradie_svateho);

/* nasledujuce boli v dbzaltar.cpp, presunute 2003-08-13 */

#define VELKONOCNA_PRIPONA  "VE"
#define POSTNA_PRIPONA      "PO"
#define CEZROCNA_PRIPONA    "CR"

/* anchor identifiers */
#define ANCHOR_POPIS        "POPIS" /* pridane 05/04/2000A.D. */
#define ANCHOR_HYMNUS       "HYMNUS"
#define ANCHOR_ANTIFONA1    "ANT1"
#define ANCHOR_ANTIFONA2    "ANT2"
#define ANCHOR_ANTIFONA3    "ANT3"
#define ANCHOR_ANTIFONA1V   "ANT1V"
#define ANCHOR_ANTIFONA2V   "ANT2V"
#define ANCHOR_ANTIFONA3V   "ANT3V"
#define ANCHOR_KCITANIE     "CIT"
#define ANCHOR_KRESPONZ     "RESP"
#define ANCHOR_MAGNIFIKAT   "MAGNIFIKAT" /* antifona na magnifikat */
#define ANCHOR_BENEDIKTUS   "BENEDIKTUS" /* antifona na benediktus */
#define ANCHOR_PROSBY       "PROSBY"
#define ANCHOR_MODLITBA     "MODLITBA"
/* pridane 2003-11-20 */
#define ANCHOR_CITANIE1     "CIT1"
#define ANCHOR_CITANIE2     "CIT2"

/* special identifiers */
#define SPOM_PM_SOBOTA "SPMVS"
/* special filename indentifiers */
/* podobne ako v liturgia.h::char *nazov_obd_htm[] */
#define FILE_SPOM_PM_SOBOTA "spmvs.htm" /* 2006-02-02: nachádzajú sa tam aj posv. èítania */

#define FILE_NANEBOVSTUPENIE "nan.htm" /* 10/03/2000A.D. -- kotvy v nom su podla OBD_VELKONOCNE_I */

#define ANCHOR_ZOSLANIE_DUCHA_SV "ZDS"
#define FILE_ZOSLANIE_DUCHA_SV "zds.htm" /* 10/03/2000A.D. -- kotvy v nom su podla OBD_VELKONOCNE_II, ANCHOR_ZOSLANIE_DUCHA_SV */

#define ANCHOR_NAJSV_TROJICE "TROJ"
#define FILE_NAJSV_TROJICE "troj.htm" /* 10/03/2000A.D. -- kotvy v nom su podla ANCHOR_NAJSV_TROJICE */

#define ANCHOR_KRISTA_KRALA "KRKRALA"
#define FILE_KRISTA_KRALA "krkrala.htm" /* 10/03/2000A.D. -- kotvy v nom su podla ANCHOR_KRISTA_KRALA */

#define ANCHOR_TELA_A_KRVI "TK"
#define FILE_TELA_A_KRVI "tk.htm" /* 10/03/2000A.D. -- kotvy v nom su podla ANCHOR_TELA_A_KRVI */

#define ANCHOR_SRDCA "SRDCA"
#define FILE_SRDCA "srdca.htm" /* 10/03/2000A.D. -- kotvy v nom su podla ANCHOR_SRDCA */

#define ANCHOR_SRDCA_PM "SRDCAPM"
#define FILE_SRDCA_PM "nspm.htm" /* 10/03/2000A.D. -- kotvy v nom su podla ANCHOR_SRDCA_PM */

#define ANCHOR_PM_BOHOROD "PMB"
#define FILE_PM_BOHOROD "pmb.htm" /* 14/03/2000A.D. -- kotvy v nom su podla ANCHOR_PM_BOHOROD */

#define ANCHOR_2NE_PO_NAR "2NE" /* 14/03/2000A.D. */
#define ANCHOR_ZJAVENIE_PANA "ZJV" /* 14/03/2000A.D. */

#define ANCHOR_SV_RODINY "SVROD"
#define FILE_SV_RODINY "svrod.htm" /* 14/03/2000A.D. -- kotvy v nom su podla ANCHOR_SV_RODINY */

#define ANCHOR_KRST_PANA "KRST"
#define FILE_KRST_PANA "krst.htm" /* 14/03/2000A.D. -- kotvy v nom su podla ANCHOR_KRST_PANA */

extern const char *text_JAN_01[];
extern const char *text_JAN_02[];
extern const char *text_JAN_06[];
extern const char *text_JAN_07[];
extern const char *text_JAN_KRST[];
extern const char *text_JAN_13[];
extern const char *text_JAN_17[];
extern const char *text_JAN_18[];
extern const char *text_JAN_20_1[];
extern const char *text_JAN_20_2[];
extern const char *text_JAN_21[];
extern const char *text_JAN_22[];
extern const char *text_JAN_23[];
extern const char *text_JAN_24[];
extern const char *text_JAN_25[];
extern const char *text_JAN_26[];
extern const char *text_JAN_27[];
extern const char *text_JAN_28[];
extern const char *text_JAN_31[];

extern const char *text_FEB_02[];
extern const char *text_FEB_03_1[];
extern const char *text_FEB_03_2[];
extern const char *text_FEB_05[];
extern const char *text_FEB_06[];
extern const char *text_FEB_08[];
extern const char *text_FEB_10[];
extern const char *text_FEB_11[];
extern const char *text_FEB_17[];
extern const char *text_FEB_21[];
extern const char *text_FEB_22[];
extern const char *text_FEB_23[];

extern const char *text_MAR_04[];
extern const char *text_MAR_07[];
extern const char *text_MAR_08[];
extern const char *text_MAR_09[];
extern const char *text_MAR_10[];
extern const char *text_MAR_17[];
extern const char *text_MAR_18[];
extern const char *text_MAR_19[];
extern const char *text_MAR_23[];
extern const char *text_MAR_25[];

extern const char *text_APR_02[];
extern const char *text_APR_04[];
extern const char *text_APR_05[];
extern const char *text_APR_07[];
extern const char *text_APR_11[];
extern const char *text_APR_13[];
extern const char *text_APR_21[];
extern const char *text_APR_23[];
extern const char *text_APR_24_1[];
extern const char *text_APR_24_2[];
extern const char *text_APR_25[];
extern const char *text_APR_28_1[];
extern const char *text_APR_28_2[];
extern const char *text_APR_29[];
extern const char *text_APR_30_1[];
extern const char *text_APR_30_2[];

#endif /* __DBZALTAR_H_ */

