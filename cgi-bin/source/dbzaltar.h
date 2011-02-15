/***************************************************************/
/*                                                             */
/* dbzaltar.h                                                  */
/* (c)1999-2009 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description |                                               */
/* document history                                            */
/*   22/02/2000A.D. | created                                  */
/*   06/09/2001A.D. | tento popis                              */
/*   2003-08-13a.D. | #define presunute sem z dbzaltar.cpp     */
/*   2003-11-20a.D. | pridane ANCHOR_CITANIE 1 a 2             */
/*   2006-01-24a.D. | pridane zaltar_zvazok()                  */
/*   2006-08-18a.D. | zmena int na short int (staèí 32tis.)    */
/*   2007-10-02a.D. | doplnený anchor ANCHOR_ANTIFONY          */
/*   2007-11-14a.D. | doplnený anchor ANCHOR_NANEBOVSTUPENIE   */
/*   2009-03-24a.D. | úpravy liturgického kalendára pre czop   */
/*                                                             */
/***************************************************************/

#include "vstudio.h"

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
 * 2006-01-24: žalmy pre posvätné èítanie sú v II. zväzku žaltára (pôst, ve¾ká noc)
 *             pre niektoré dni odlišné, preto sme vytvorili aj ïalší parameter,
 *             ktorý sa používa len pri volaní za úèelom konkrétnej modlitby
 *             (pre vo¾bu posv. èítania len pre deò a týždeò žaltára sa použije default)
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
#define ANCHOR_ANTIFONY     "ANTx" /* pridané 2007-10-02 pre rovnaké antifóny 1., 2. a 3. - modlitba cez deò */
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

#define ANCHOR_NANEBOVSTUPENIE "NAN" /* 2007-11-14: doplenné kvôli invitatóriu */
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
extern const char *text_JAN_03[];
extern const char *text_JAN_06[];
extern const char *text_JAN_07[];
extern const char *text_JAN_KRST[];
extern const char *text_JAN_13[];
extern const char *text_JAN_15[];
extern const char *text_JAN_17[];
extern const char *text_JAN_18[];
extern const char *text_JAN_19[];
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
extern const char *text_FEB_04[];
extern const char *text_FEB_05[];
extern const char *text_FEB_06[];
extern const char *text_FEB_08[];
extern const char *text_FEB_08_2[];
extern const char *text_FEB_10[];
extern const char *text_FEB_11[];
extern const char *text_FEB_12[];
extern const char *text_FEB_13[];
extern const char *text_FEB_14[];
extern const char *text_FEB_17[];
extern const char *text_FEB_18[];
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
extern const char *text_APR_20[];
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
extern const char *text_MAJ_10[];
extern const char *text_MAJ_12_1[];
extern const char *text_MAJ_12_2[];
extern const char *text_MAJ_12_3[];
extern const char *text_MAJ_13[];
extern const char *text_MAJ_14[];
extern const char *text_MAJ_15[];
extern const char *text_MAJ_16[];
extern const char *text_MAJ_18[];
extern const char *text_MAJ_20_1[];
extern const char *text_MAJ_20_2[];
extern const char *text_MAJ_21[];
extern const char *text_MAJ_21_1[];
extern const char *text_MAJ_21_2[];
extern const char *text_MAJ_22[];
extern const char *text_MAJ_24[];
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
extern const char *text_ZELENY_STVRTOK[];
extern const char *text_VELKY_PIATOK[];
extern const char *text_BIELA_SOBOTA[];
extern const char *text_KVETNA_NEDELA[];

extern const char *text_JUN_01[];
extern const char *text_JUN_02[];
extern const char *text_JUN_03[];
extern const char *text_JUN_04[];
extern const char *text_JUN_05[];
extern const char *text_JUN_06[];
extern const char *text_JUN_08[];
extern const char *text_JUN_09[];
extern const char *text_JUN_10[];
extern const char *text_JUN_11[];
extern const char *text_JUN_13[];
extern const char *text_JUN_15[];
extern const char *text_JUN_16[];
extern const char *text_JUN_19[];
extern const char *text_JUN_19_1[];
extern const char *text_JUN_21[];
extern const char *text_JUN_22_1[];
extern const char *text_JUN_22_2[];
extern const char *text_JUN_24[];
extern const char *text_JUN_27[];
extern const char *text_JUN_27_1[];
extern const char *text_JUN_28[];
extern const char *text_JUN_29[];
extern const char *text_JUN_30[];
extern const char *text_JUN_30_1[];

extern const char *text_JUL_03[];
extern const char *text_JUL_04[];
extern const char *text_JUL_04_1[];
extern const char *text_JUL_05[];
extern const char *text_JUL_06[];
extern const char *text_JUL_07[];
extern const char *text_JUL_09[];
extern const char *text_JUL_09_2[];
extern const char *text_JUL_11[];
extern const char *text_JUL_13[];
extern const char *text_JUL_14[];
extern const char *text_JUL_14_1[];
extern const char *text_JUL_15[];
extern const char *text_JUL_16[];
extern const char *text_JUL_16_1[];
extern const char *text_JUL_17_1[];
extern const char *text_JUL_17_2[];
extern const char *text_JUL_17_3[];
extern const char *text_JUL_20[];
extern const char *text_JUL_21[];
extern const char *text_JUL_22[];
extern const char *text_JUL_23[];
extern const char *text_JUL_24[];
extern const char *text_JUL_25[];
extern const char *text_JUL_26[];
extern const char *text_JUL_27[];
extern const char *text_JUL_29[];
extern const char *text_JUL_30[];
extern const char *text_JUL_30_1[];
extern const char *text_JUL_31[];

extern const char *text_AUG_01[];
extern const char *text_AUG_02_1[];
extern const char *text_AUG_02_2[];
extern const char *text_AUG_02_3[];
extern const char *text_AUG_04[];
extern const char *text_AUG_05[];
extern const char *text_AUG_06[];
extern const char *text_AUG_07_1[];
extern const char *text_AUG_07_2[];
extern const char *text_AUG_08[];
extern const char *text_AUG_09[];
extern const char *text_AUG_10[];
extern const char *text_AUG_11[];
extern const char *text_AUG_12[];
extern const char *text_AUG_13[];
extern const char *text_AUG_14[];
extern const char *text_AUG_15[];
extern const char *text_AUG_16[];
extern const char *text_AUG_17[];
extern const char *text_AUG_18[];
extern const char *text_AUG_19[];
extern const char *text_AUG_20[];
extern const char *text_AUG_21[];
extern const char *text_AUG_22[];
extern const char *text_AUG_23[];
extern const char *text_AUG_24[];
extern const char *text_AUG_25_1[];
extern const char *text_AUG_25_2[];
extern const char *text_AUG_25_3[];
extern const char *text_AUG_27[];
extern const char *text_AUG_28[];
extern const char *text_AUG_29[];
extern const char *text_AUG_30[];

extern const char *text_SEP_03[];
extern const char *text_SEP_06[];
extern const char *text_SEP_07[];
extern const char *text_SEP_08[];
extern const char *text_SEP_09[];
extern const char *text_SEP_10[];
extern const char *text_SEP_12[];
extern const char *text_SEP_13[];
extern const char *text_SEP_14[];
extern const char *text_SEP_15[];
extern const char *text_SEP_16_CZ[];
extern const char *text_SEP_16[];
extern const char *text_SEP_17[];
extern const char *text_SEP_18[];
extern const char *text_SEP_19[];
extern const char *text_SEP_20[];
extern const char *text_SEP_20_2[];
extern const char *text_SEP_21[];
extern const char *text_SEP_22[];
extern const char *text_SEP_23[];
extern const char *text_SEP_24[];
extern const char *text_SEP_26[];
extern const char *text_SEP_26_2[];
extern const char *text_SEP_27[];
extern const char *text_SEP_28[];
extern const char *text_SEP_28_2[];
extern const char *text_SEP_29[];
extern const char *text_SEP_30[];

extern const char *text_OKT_01[];
extern const char *text_OKT_02[];
extern const char *text_OKT_04[];
extern const char *text_OKT_05[];
extern const char *text_OKT_06[];
extern const char *text_OKT_07[];
extern const char *text_OKT_09_1[];
extern const char *text_OKT_09_2[];
extern const char *text_OKT_09_3[];
extern const char *text_OKT_12[];
extern const char *text_OKT_14[];
extern const char *text_OKT_15[];
extern const char *text_OKT_16_1[];
extern const char *text_OKT_16_2[];
extern const char *text_OKT_17[];
extern const char *text_OKT_18[];
extern const char *text_OKT_19_1[];
extern const char *text_OKT_19_2[];
extern const char *text_OKT_22[];
extern const char *text_OKT_23[];
extern const char *text_OKT_24[];
extern const char *text_OKT_25[];
extern const char *text_OKT_26[];
extern const char *text_OKT_27[];
extern const char *text_OKT_28[];
extern const char *text_OKT_29[];
extern const char *text_OKT_30[];
extern const char *text_OKT_31[];

extern const char *text_NOV_01[];
extern const char *text_NOV_02[];
extern const char *text_NOV_03[];
extern const char *text_NOV_04[];
extern const char *text_NOV_05[];
extern const char *text_NOV_06[];
extern const char *text_NOV_07[];
extern const char *text_NOV_09[];
extern const char *text_NOV_10[];
extern const char *text_NOV_11[];
extern const char *text_NOV_12[];
extern const char *text_NOV_13[];
extern const char *text_NOV_15[];
extern const char *text_NOV_16_1[];
extern const char *text_NOV_16_2[];
extern const char *text_NOV_17[];
extern const char *text_NOV_18[];
extern const char *text_NOV_20[];
extern const char *text_NOV_21[];
extern const char *text_NOV_22[];
extern const char *text_NOV_23_1[];
extern const char *text_NOV_23_2[];
extern const char *text_NOV_24[];
extern const char *text_NOV_25[];
extern const char *text_NOV_30[];

extern const char *text_DEC_01[];
extern const char *text_DEC_02[];
extern const char *text_DEC_03[];
extern const char *text_DEC_04[];
extern const char *text_DEC_06[];
extern const char *text_DEC_07[];
extern const char *text_DEC_08[];
extern const char *text_DEC_09[];
extern const char *text_DEC_11[];
extern const char *text_DEC_12[];
extern const char *text_DEC_13[];
extern const char *text_DEC_14[];
extern const char *text_DEC_21[];
extern const char *text_DEC_22[];
extern const char *text_DEC_23[];
extern const char *text_DEC_26[];
extern const char *text_DEC_27[];
extern const char *text_DEC_28[];
extern const char *text_DEC_29[];
extern const char *text_DEC_31[];

#endif /* __DBZALTAR_H_ */

