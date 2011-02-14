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
/*   2006-08-18a.D. | zmena int na short int (sta�� 32tis.)    */
/*                                                             */
/***************************************************************/

#ifndef __DBZALTAR_H_
#define __DBZALTAR_H_

#include "liturgia.h"

#include "myexpt.h" /* export do suboru alebo na konzolu printf */
#include "mylog.h"
#include <string.h>

/* aby sa dala pouzivat v zaltar(); */
short int sviatky_svatych(short int, short int);
short int sviatky_svatych(short int, short int, short int);
short int sviatky_svatych(short int, short int, short int, short int); /* spustam druhykrat */

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
 * 2006-01-24: �almy pre posv�tn� ��tanie s� v II. zv�zku �alt�ra (p�st, ve�k� noc)
 *             pre niektor� dni odli�n�, preto sme vytvorili aj �al�� parameter,
 *             ktor� sa pou��va len pri volan� za ��elom konkr�tnej modlitby
 *             (pre vo�bu posv. ��tania len pre de� a t��de� �alt�ra sa pou�ije default)
 *
 */
void zaltar(short int den, short int tyzzal);
void zaltar_zvazok(short int den, short int tyzzal, short int obdobie);

void liturgicke_obdobie(short int litobd, short int tyzden, short int den, short int tyzzal, short int poradie_svateho);

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
#define FILE_SPOM_PM_SOBOTA "spmvs.htm" /* 2006-02-02: nach�dzaj� sa tam aj posv. ��tania */

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
extern const char *text_FEB_08_2[];
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

extern const char *text_POPOLCOVA_STREDA[];

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

extern const char *text_MAJ_01[];
extern const char *text_MAJ_02[];
extern const char *text_MAJ_03[];
extern const char *text_MAJ_06[];
extern const char *text_MAJ_08[];
extern const char *text_MAJ_12_1[];
extern const char *text_MAJ_12_2[];
extern const char *text_MAJ_12_3[];
extern const char *text_MAJ_14[];
extern const char *text_MAJ_16[];
extern const char *text_MAJ_18[];
extern const char *text_MAJ_20_1[];
extern const char *text_MAJ_20_2[];
extern const char *text_MAJ_21[];
extern const char *text_MAJ_25_1[];
extern const char *text_MAJ_25_2[];
extern const char *text_MAJ_25_3[];
extern const char *text_MAJ_26[];
extern const char *text_MAJ_27[];
extern const char *text_MAJ_30[];
extern const char *text_MAJ_31[];

extern const char *text_NANEBOVSTUPENIE_PANA[];
extern const char *text_VELKONOCNA_NEDELA[];
extern const char *text_NEDELA_PANOVHO_ZMRTVYCHVSTANIA[];
extern const char *text_NEDELA_VO_VELKONOCNEJ_OKTAVE[];
extern const char *text_DEN_VO_VELKONOCNEJ_OKTAVE[];
extern const char *text_NAJSVATEJSEJ_TROJICE[];
extern const char *text_KRISTA_KRALA[];
extern const char *text_NAJSV_KRISTOVHO_TELA_A_KRVI[];
extern const char *text_NAJSV_SRDCA_JEZISOVHO[];
extern const char *text_NEPOSKVRNENEHO_SRDCA_PM[];
extern const char *text_NARODENIE_PANA[];
extern const char *text_ZOSLANIE_DUCHA_SVATEHO[];
extern const char *text_PRVA_ADVENTNA_NEDELA[];
extern const char *text_NEDELA_SV_RODINY[];
extern const char *text_SPOMIENKA_PM_V_SOBOTU[];

extern const char *text_DEC_08[];

#endif /* __DBZALTAR_H_ */

