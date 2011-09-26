/***************************************************************/
/*                                                             */
/* dbzaltar.h                                                  */
/* (c)1999-2011 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description |                                               */
/* document history                                            */
/*   22/02/2000A.D. | created                                  */
/*   06/09/2001A.D. | tento popis                              */
/*   2003-08-13a.D. | #define presunute sem z dbzaltar.cpp     */
/*   2003-11-20a.D. | pridane ANCHOR_CITANIE 1 a 2             */
/*   2006-01-24a.D. | pridane zaltar_zvazok()                  */
/*   2006-08-18a.D. | zmena int na short int (sta�� 32tis.)    */
/*   2007-10-02a.D. | doplnen� anchor ANCHOR_ANTIFONY          */
/*   2007-11-14a.D. | doplnen� anchor ANCHOR_NANEBOVSTUPENIE   */
/*   2009-03-24a.D. | �pravy liturgick�ho kalend�ra pre czop   */
/*                                                             */
/***************************************************************/

#include "vstudio.h"

#ifndef __DBZALTAR_H_
#define __DBZALTAR_H_

#include "liturgia.h"

#include "myexpt.h" /* export do suboru alebo na konzolu printf */
#include "mylog.h"
#include <string.h>
#include "myhpage.h" /* kv�li hlavicka() �*/

/* aby sa dala pouzivat v zaltar(); */
short int sviatky_svatych(short int, short int);
short int sviatky_svatych(short int, short int, short int);
short int sviatky_svatych(short int, short int, short int, short int); /* spustam druhykrat */

extern const char *html_title[POCET_JAZYKOV + 1];

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
#define ANCHOR_ANTIFONY     "ANTx" /* pridan� 2007-10-02 pre rovnak� antif�ny 1., 2. a 3. - modlitba cez de� */
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

#define ANCHOR_NANEBOVSTUPENIE "NAN" /* 2007-11-14: doplenn� kv�li invitat�riu */
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

#define ANCHOR_DOPLNKOVA_PSALMODIA "PSCOM"
#define FILE_DOPLNKOVA_PSALMODIA "pscom.htm"

#define ANCHOR_CSSR_TITUL "TITUL"

extern const char *text_JAN_01[POCET_JAZYKOV + 1];
extern const char *text_JAN_02[POCET_JAZYKOV + 1];
extern const char *text_JAN_03[POCET_JAZYKOV + 1];
extern const char *text_JAN_06[POCET_JAZYKOV + 1];
extern const char *text_JAN_07[POCET_JAZYKOV + 1];
extern const char *text_JAN_KRST[POCET_JAZYKOV + 1];
extern const char *text_JAN_13[POCET_JAZYKOV + 1];
extern const char *text_JAN_15[POCET_JAZYKOV + 1];
extern const char *text_JAN_17[POCET_JAZYKOV + 1];
extern const char *text_JAN_18_CZ[POCET_JAZYKOV + 1];
extern const char *text_JAN_19[POCET_JAZYKOV + 1];
extern const char *text_JAN_20_1[POCET_JAZYKOV + 1];
extern const char *text_JAN_20_2[POCET_JAZYKOV + 1];
extern const char *text_JAN_21[POCET_JAZYKOV + 1];
extern const char *text_JAN_22[POCET_JAZYKOV + 1];
extern const char *text_JAN_23_SK[POCET_JAZYKOV + 1];
extern const char *text_JAN_24[POCET_JAZYKOV + 1];
extern const char *text_JAN_25[POCET_JAZYKOV + 1];
extern const char *text_JAN_26[POCET_JAZYKOV + 1];
extern const char *text_JAN_27[POCET_JAZYKOV + 1];
extern const char *text_JAN_28[POCET_JAZYKOV + 1];
extern const char *text_JAN_31[POCET_JAZYKOV + 1];

extern const char *text_FEB_02[POCET_JAZYKOV + 1];
extern const char *text_FEB_03_1[POCET_JAZYKOV + 1];
extern const char *text_FEB_03_2[POCET_JAZYKOV + 1];
extern const char *text_FEB_04_CZOP[POCET_JAZYKOV + 1];
extern const char *text_FEB_05[POCET_JAZYKOV + 1];
extern const char *text_FEB_06[POCET_JAZYKOV + 1];
extern const char *text_FEB_07_CZOP[POCET_JAZYKOV + 1];
extern const char *text_FEB_08_1[POCET_JAZYKOV + 1];
extern const char *text_FEB_08_2[POCET_JAZYKOV + 1];
extern const char *text_FEB_10[POCET_JAZYKOV + 1];
extern const char *text_FEB_11[POCET_JAZYKOV + 1];
extern const char *text_FEB_12_CZOP[POCET_JAZYKOV + 1];
extern const char *text_FEB_13_CZOP[POCET_JAZYKOV + 1];
extern const char *text_FEB_14[POCET_JAZYKOV + 1];
extern const char *text_FEB_17[POCET_JAZYKOV + 1];
extern const char *text_FEB_18_CZOP[POCET_JAZYKOV + 1];
extern const char *text_FEB_21[POCET_JAZYKOV + 1];
extern const char *text_FEB_22[POCET_JAZYKOV + 1];
extern const char *text_FEB_23[POCET_JAZYKOV + 1];

extern const char *text_MAR_04[POCET_JAZYKOV + 1];
extern const char *text_MAR_07[POCET_JAZYKOV + 1];
extern const char *text_MAR_08[POCET_JAZYKOV + 1];
extern const char *text_MAR_09[POCET_JAZYKOV + 1];
extern const char *text_MAR_10_CZ[POCET_JAZYKOV + 1];
extern const char *text_MAR_10_SK[POCET_JAZYKOV + 1];
extern const char *text_MAR_17[POCET_JAZYKOV + 1];
extern const char *text_MAR_18[POCET_JAZYKOV + 1];
extern const char *text_MAR_19[POCET_JAZYKOV + 1];
extern const char *text_MAR_23[POCET_JAZYKOV + 1];
extern const char *text_MAR_25[POCET_JAZYKOV + 1];

extern const char *text_POPOLCOVA_STREDA[POCET_JAZYKOV + 1];

extern const char *text_APR_02[POCET_JAZYKOV + 1];
extern const char *text_APR_04[POCET_JAZYKOV + 1];
extern const char *text_APR_05[POCET_JAZYKOV + 1];
extern const char *text_APR_07[POCET_JAZYKOV + 1];
extern const char *text_APR_11[POCET_JAZYKOV + 1];
extern const char *text_APR_13[POCET_JAZYKOV + 1];
extern const char *text_APR_20[POCET_JAZYKOV + 1];
extern const char *text_APR_21[POCET_JAZYKOV + 1];
extern const char *text_APR_23[POCET_JAZYKOV + 1];
extern const char *text_APR_24_1[POCET_JAZYKOV + 1];
extern const char *text_APR_24_2[POCET_JAZYKOV + 1];
extern const char *text_APR_25[POCET_JAZYKOV + 1];
extern const char *text_APR_28_1[POCET_JAZYKOV + 1];
extern const char *text_APR_28_2[POCET_JAZYKOV + 1];
extern const char *text_APR_29[POCET_JAZYKOV + 1];
extern const char *text_APR_30_1[POCET_JAZYKOV + 1];
extern const char *text_APR_30_2[POCET_JAZYKOV + 1];

extern const char *text_MAJ_01[POCET_JAZYKOV + 1];
extern const char *text_MAJ_02[POCET_JAZYKOV + 1];
extern const char *text_MAJ_03[POCET_JAZYKOV + 1];
extern const char *text_MAJ_06[POCET_JAZYKOV + 1];
extern const char *text_MAJ_08_CZ[POCET_JAZYKOV + 1];
extern const char *text_MAJ_10_CZOP[POCET_JAZYKOV + 1];
extern const char *text_MAJ_11_SK[POCET_JAZYKOV + 1];
extern const char *text_MAJ_12_1[POCET_JAZYKOV + 1];
extern const char *text_MAJ_12_2[POCET_JAZYKOV + 1];
extern const char *text_MAJ_12_CZ[POCET_JAZYKOV + 1];
extern const char *text_MAJ_13[POCET_JAZYKOV + 1];
extern const char *text_MAJ_14[POCET_JAZYKOV + 1];
extern const char *text_MAJ_15_CZOP[POCET_JAZYKOV + 1];
extern const char *text_MAJ_16[POCET_JAZYKOV + 1];
extern const char *text_MAJ_18[POCET_JAZYKOV + 1];
extern const char *text_MAJ_20_CZ[POCET_JAZYKOV + 1];
extern const char *text_MAJ_20[POCET_JAZYKOV + 1];
extern const char *text_MAJ_21_CZ[POCET_JAZYKOV + 1];
extern const char *text_MAJ_21[POCET_JAZYKOV + 1];
extern const char *text_MAJ_21_CZOP[POCET_JAZYKOV + 1];
extern const char *text_MAJ_22[POCET_JAZYKOV + 1];
extern const char *text_MAJ_24_CZOP[POCET_JAZYKOV + 1];
extern const char *text_MAJ_25_1[POCET_JAZYKOV + 1];
extern const char *text_MAJ_25_2[POCET_JAZYKOV + 1];
extern const char *text_MAJ_25_3[POCET_JAZYKOV + 1];
extern const char *text_MAJ_26[POCET_JAZYKOV + 1];
extern const char *text_MAJ_27[POCET_JAZYKOV + 1];
extern const char *text_MAJ_30_CZ[POCET_JAZYKOV + 1];
extern const char *text_MAJ_31[POCET_JAZYKOV + 1];

extern const char *text_NANEBOVSTUPENIE_PANA[POCET_JAZYKOV + 1];
extern const char *text_VELKONOCNA_NEDELA[POCET_JAZYKOV + 1];
extern const char *text_NEDELA_PANOVHO_ZMRTVYCHVSTANIA[POCET_JAZYKOV + 1];
extern const char *text_NEDELA_VO_VELKONOCNEJ_OKTAVE[POCET_JAZYKOV + 1];
extern const char *text_DEN_VO_VELKONOCNEJ_OKTAVE[POCET_JAZYKOV + 1];
extern const char *text_NAJSVATEJSEJ_TROJICE[POCET_JAZYKOV + 1];
extern const char *text_KRISTA_KRALA[POCET_JAZYKOV + 1];
extern const char *text_NAJSV_KRISTOVHO_TELA_A_KRVI[POCET_JAZYKOV + 1];
extern const char *text_NAJSV_SRDCA_JEZISOVHO[POCET_JAZYKOV + 1];
extern const char *text_NEPOSKVRNENEHO_SRDCA_PM[POCET_JAZYKOV + 1];
extern const char *text_NARODENIE_PANA[POCET_JAZYKOV + 1];
extern const char *text_ZOSLANIE_DUCHA_SVATEHO[POCET_JAZYKOV + 1];
extern const char *text_PRVA_ADVENTNA_NEDELA[POCET_JAZYKOV + 1];
extern const char *text_NEDELA_SV_RODINY[POCET_JAZYKOV + 1];
extern const char *text_SPOMIENKA_PM_V_SOBOTU[POCET_JAZYKOV + 1];
extern const char *text_ZELENY_STVRTOK[POCET_JAZYKOV + 1];
extern const char *text_VELKY_PIATOK[POCET_JAZYKOV + 1];
extern const char *text_BIELA_SOBOTA[POCET_JAZYKOV + 1];
extern const char *text_KVETNA_NEDELA[POCET_JAZYKOV + 1];

extern const char *text_JUN_01[POCET_JAZYKOV + 1];
extern const char *text_JUN_02[POCET_JAZYKOV + 1];
extern const char *text_JUN_03[POCET_JAZYKOV + 1];
extern const char *text_JUN_04_CZOP[POCET_JAZYKOV + 1];
extern const char *text_JUN_04_HU[POCET_JAZYKOV + 1];
extern const char *text_JUN_05[POCET_JAZYKOV + 1];
extern const char *text_JUN_06[POCET_JAZYKOV + 1];
extern const char *text_JUN_08_HU[POCET_JAZYKOV + 1];
extern const char *text_JUN_08_CZOP[POCET_JAZYKOV + 1];
extern const char *text_JUN_09[POCET_JAZYKOV + 1];
extern const char *text_JUN_10_CZOP[POCET_JAZYKOV + 1];
extern const char *text_JUN_11[POCET_JAZYKOV + 1];
extern const char *text_JUN_13[POCET_JAZYKOV + 1];
extern const char *text_JUN_14_HU[POCET_JAZYKOV + 1];
extern const char *text_JUN_15_CZ[POCET_JAZYKOV + 1];
extern const char *text_JUN_15_HU[POCET_JAZYKOV + 1];
extern const char *text_JUN_16_SK[POCET_JAZYKOV + 1];
extern const char *text_JUN_16_HU[POCET_JAZYKOV + 1];
extern const char *text_JUN_19[POCET_JAZYKOV + 1];
extern const char *text_JUN_19_CZ[POCET_JAZYKOV + 1];
extern const char *text_JUN_21[POCET_JAZYKOV + 1];
extern const char *text_JUN_22_1[POCET_JAZYKOV + 1];
extern const char *text_JUN_22_2[POCET_JAZYKOV + 1];
extern const char *text_JUN_22_HU[POCET_JAZYKOV + 1];
extern const char *text_JUN_24[POCET_JAZYKOV + 1];
extern const char *text_JUN_27[POCET_JAZYKOV + 1];
extern const char *text_JUN_27_SK_HU[POCET_JAZYKOV + 1];
extern const char *text_JUN_28[POCET_JAZYKOV + 1];
extern const char *text_JUN_29[POCET_JAZYKOV + 1];
extern const char *text_JUN_30[POCET_JAZYKOV + 1];
extern const char *text_JUN_30_CZ[POCET_JAZYKOV + 1];

extern const char *text_JUL_03[POCET_JAZYKOV + 1];
extern const char *text_JUL_04[POCET_JAZYKOV + 1];
extern const char *text_JUL_04_CZ[POCET_JAZYKOV + 1];
extern const char *text_JUL_05[POCET_JAZYKOV + 1];
extern const char *text_JUL_06[POCET_JAZYKOV + 1];
extern const char *text_JUL_06_CZOP[POCET_JAZYKOV + 1];
extern const char *text_JUL_07_SK[POCET_JAZYKOV + 1];
extern const char *text_JUL_08_HU[POCET_JAZYKOV + 1];
extern const char *text_JUL_09[POCET_JAZYKOV + 1];
extern const char *text_JUL_09_CZOP[POCET_JAZYKOV + 1];
extern const char *text_JUL_11[POCET_JAZYKOV + 1];
extern const char *text_JUL_13[POCET_JAZYKOV + 1];
extern const char *text_JUL_14[POCET_JAZYKOV + 1];
extern const char *text_JUL_14_CZ[POCET_JAZYKOV + 1];
extern const char *text_JUL_15[POCET_JAZYKOV + 1];
extern const char *text_JUL_16[POCET_JAZYKOV + 1];
extern const char *text_JUL_16_CZ[POCET_JAZYKOV + 1];
extern const char *text_JUL_17_SK[POCET_JAZYKOV + 1];
extern const char *text_JUL_17_CZ[POCET_JAZYKOV + 1];
extern const char *text_JUL_17_CZOP[POCET_JAZYKOV + 1];
extern const char *text_JUL_18_HU[POCET_JAZYKOV + 1];
extern const char *text_JUL_20[POCET_JAZYKOV + 1];
extern const char *text_JUL_21[POCET_JAZYKOV + 1];
extern const char *text_JUL_22[POCET_JAZYKOV + 1];
extern const char *text_JUL_23[POCET_JAZYKOV + 1];
extern const char *text_JUL_24[POCET_JAZYKOV + 1];
extern const char *text_JUL_24_HU[POCET_JAZYKOV + 1];
extern const char *text_JUL_25[POCET_JAZYKOV + 1];
extern const char *text_JUL_26[POCET_JAZYKOV + 1];
extern const char *text_JUL_27[POCET_JAZYKOV + 1];
extern const char *text_JUL_29[POCET_JAZYKOV + 1];
extern const char *text_JUL_30[POCET_JAZYKOV + 1];
extern const char *text_JUL_30_SK[POCET_JAZYKOV + 1];
extern const char *text_JUL_31[POCET_JAZYKOV + 1];

extern const char *text_AUG_01[POCET_JAZYKOV + 1];
extern const char *text_AUG_02_1[POCET_JAZYKOV + 1];
extern const char *text_AUG_02_2[POCET_JAZYKOV + 1];
extern const char *text_AUG_02_CZOP[POCET_JAZYKOV + 1];
extern const char *text_AUG_04[POCET_JAZYKOV + 1];
extern const char *text_AUG_05[POCET_JAZYKOV + 1];
extern const char *text_AUG_06[POCET_JAZYKOV + 1];
extern const char *text_AUG_07_1[POCET_JAZYKOV + 1];
extern const char *text_AUG_07_2[POCET_JAZYKOV + 1];
extern const char *text_AUG_08[POCET_JAZYKOV + 1];
extern const char *text_AUG_09[POCET_JAZYKOV + 1];
extern const char *text_AUG_10[POCET_JAZYKOV + 1];
extern const char *text_AUG_11[POCET_JAZYKOV + 1];
extern const char *text_AUG_12[POCET_JAZYKOV + 1];
extern const char *text_AUG_13[POCET_JAZYKOV + 1];
extern const char *text_AUG_13_HU[POCET_JAZYKOV + 1];
extern const char *text_AUG_14[POCET_JAZYKOV + 1];
extern const char *text_AUG_15[POCET_JAZYKOV + 1];
extern const char *text_AUG_16[POCET_JAZYKOV + 1];
extern const char *text_AUG_17_CZOP[POCET_JAZYKOV + 1];
extern const char *text_AUG_17_HU[POCET_JAZYKOV + 1];
extern const char *text_AUG_18_HU[POCET_JAZYKOV + 1];
extern const char *text_AUG_18_CZOP[POCET_JAZYKOV + 1];
extern const char *text_AUG_19[POCET_JAZYKOV + 1];
extern const char *text_AUG_20[POCET_JAZYKOV + 1];
extern const char *text_AUG_21[POCET_JAZYKOV + 1];
extern const char *text_AUG_22[POCET_JAZYKOV + 1];
extern const char *text_AUG_23[POCET_JAZYKOV + 1];
extern const char *text_AUG_24[POCET_JAZYKOV + 1];
extern const char *text_AUG_25_1[POCET_JAZYKOV + 1];
extern const char *text_AUG_25_2[POCET_JAZYKOV + 1];
extern const char *text_AUG_25_CZ[POCET_JAZYKOV + 1];
extern const char *text_AUG_25_HU[POCET_JAZYKOV + 1];
extern const char *text_AUG_27[POCET_JAZYKOV + 1];
extern const char *text_AUG_28[POCET_JAZYKOV + 1];
extern const char *text_AUG_29[POCET_JAZYKOV + 1];
extern const char *text_AUG_30_SK[POCET_JAZYKOV + 1];
extern const char *text_AUG_31_HU[POCET_JAZYKOV + 1];

extern const char *text_SEP_03[POCET_JAZYKOV + 1];
extern const char *text_SEP_05[POCET_JAZYKOV + 1];
extern const char *text_SEP_06_SK[POCET_JAZYKOV + 1];
extern const char *text_SEP_07[POCET_JAZYKOV + 1];
extern const char *text_SEP_08[POCET_JAZYKOV + 1];
extern const char *text_SEP_09[POCET_JAZYKOV + 1];
extern const char *text_SEP_10_CZ[POCET_JAZYKOV + 1];
extern const char *text_SEP_12[POCET_JAZYKOV + 1];
extern const char *text_SEP_13[POCET_JAZYKOV + 1];
extern const char *text_SEP_13_HU[POCET_JAZYKOV + 1];
extern const char *text_SEP_14[POCET_JAZYKOV + 1];
extern const char *text_SEP_15[POCET_JAZYKOV + 1];
extern const char *text_SEP_16_CZ[POCET_JAZYKOV + 1];
extern const char *text_SEP_16[POCET_JAZYKOV + 1];
extern const char *text_SEP_17[POCET_JAZYKOV + 1];
extern const char *text_SEP_18_CZOP[POCET_JAZYKOV + 1];
extern const char *text_SEP_19[POCET_JAZYKOV + 1];
extern const char *text_SEP_20[POCET_JAZYKOV + 1];
extern const char *text_SEP_20_CZ[POCET_JAZYKOV + 1];
extern const char *text_SEP_21[POCET_JAZYKOV + 1];
extern const char *text_SEP_22[POCET_JAZYKOV + 1];
extern const char *text_SEP_23[POCET_JAZYKOV + 1];
extern const char *text_SEP_24_SK[POCET_JAZYKOV + 1];
extern const char *text_SEP_24_HU[POCET_JAZYKOV + 1];
extern const char *text_SEP_26[POCET_JAZYKOV + 1];
extern const char *text_SEP_26_CZOP[POCET_JAZYKOV + 1];
extern const char *text_SEP_27[POCET_JAZYKOV + 1];
extern const char *text_SEP_28[POCET_JAZYKOV + 1];
extern const char *text_SEP_28_2[POCET_JAZYKOV + 1];
extern const char *text_SEP_29[POCET_JAZYKOV + 1];
extern const char *text_SEP_30[POCET_JAZYKOV + 1];

extern const char *text_OKT_01[POCET_JAZYKOV + 1];
extern const char *text_OKT_02[POCET_JAZYKOV + 1];
extern const char *text_OKT_04[POCET_JAZYKOV + 1];
extern const char *text_OKT_05_CZOP[POCET_JAZYKOV + 1];
extern const char *text_OKT_05_HU[POCET_JAZYKOV + 1];
extern const char *text_OKT_06[POCET_JAZYKOV + 1];
extern const char *text_OKT_07[POCET_JAZYKOV + 1];
extern const char *text_OKT_08_HU[POCET_JAZYKOV + 1];
extern const char *text_OKT_09_1[POCET_JAZYKOV + 1];
extern const char *text_OKT_09_2[POCET_JAZYKOV + 1];
extern const char *text_OKT_09_CZOP[POCET_JAZYKOV + 1];
extern const char *text_OKT_11[POCET_JAZYKOV + 1];
extern const char *text_OKT_12_CZ[POCET_JAZYKOV + 1];
extern const char *text_OKT_14[POCET_JAZYKOV + 1];
extern const char *text_OKT_15[POCET_JAZYKOV + 1];
extern const char *text_OKT_16_1[POCET_JAZYKOV + 1];
extern const char *text_OKT_16_2[POCET_JAZYKOV + 1];
extern const char *text_OKT_17[POCET_JAZYKOV + 1];
extern const char *text_OKT_18[POCET_JAZYKOV + 1];
extern const char *text_OKT_19_1[POCET_JAZYKOV + 1];
extern const char *text_OKT_19_2[POCET_JAZYKOV + 1];
extern const char *text_OKT_22_CZOP[POCET_JAZYKOV + 1];
extern const char *text_OKT_23[POCET_JAZYKOV + 1];
extern const char *text_OKT_24[POCET_JAZYKOV + 1];
extern const char *text_OKT_25_SK[POCET_JAZYKOV + 1];
extern const char *text_OKT_26[POCET_JAZYKOV + 1];
extern const char *text_OKT_27_SK[POCET_JAZYKOV + 1];
extern const char *text_OKT_28[POCET_JAZYKOV + 1];
extern const char *text_OKT_29_CZ[POCET_JAZYKOV + 1];
extern const char *text_OKT_30_CZ[POCET_JAZYKOV + 1];
extern const char *text_OKT_31_CZ[POCET_JAZYKOV + 1];

extern const char *text_NOV_01[POCET_JAZYKOV + 1];
extern const char *text_NOV_02[POCET_JAZYKOV + 1];
extern const char *text_NOV_03[POCET_JAZYKOV + 1];
extern const char *text_NOV_04[POCET_JAZYKOV + 1];
extern const char *text_NOV_05_SK[POCET_JAZYKOV + 1];
extern const char *text_NOV_06_CZOP[POCET_JAZYKOV + 1];
extern const char *text_NOV_07_CZOP[POCET_JAZYKOV + 1];
extern const char *text_NOV_08_CZOP[POCET_JAZYKOV + 1];
extern const char *text_NOV_09[POCET_JAZYKOV + 1];
extern const char *text_NOV_10[POCET_JAZYKOV + 1];
extern const char *text_NOV_11[POCET_JAZYKOV + 1];
extern const char *text_NOV_12[POCET_JAZYKOV + 1];
extern const char *text_NOV_13_CZ[POCET_JAZYKOV + 1];
extern const char *text_NOV_15[POCET_JAZYKOV + 1];
extern const char *text_NOV_16_1[POCET_JAZYKOV + 1];
extern const char *text_NOV_16_2[POCET_JAZYKOV + 1];
extern const char *text_NOV_17[POCET_JAZYKOV + 1];
extern const char *text_NOV_18[POCET_JAZYKOV + 1];
extern const char *text_NOV_20_SK[POCET_JAZYKOV + 1];
extern const char *text_NOV_21[POCET_JAZYKOV + 1];
extern const char *text_NOV_22[POCET_JAZYKOV + 1];
extern const char *text_NOV_23_1[POCET_JAZYKOV + 1];
extern const char *text_NOV_23_2[POCET_JAZYKOV + 1];
extern const char *text_NOV_24[POCET_JAZYKOV + 1];
extern const char *text_NOV_25[POCET_JAZYKOV + 1];
extern const char *text_NOV_30[POCET_JAZYKOV + 1];

extern const char *text_DEC_01_CZ[POCET_JAZYKOV + 1];
extern const char *text_DEC_02_CZ[POCET_JAZYKOV + 1];
extern const char *text_DEC_03[POCET_JAZYKOV + 1];
extern const char *text_DEC_04[POCET_JAZYKOV + 1];
extern const char *text_DEC_06[POCET_JAZYKOV + 1];
extern const char *text_DEC_07[POCET_JAZYKOV + 1];
extern const char *text_DEC_08[POCET_JAZYKOV + 1];
extern const char *text_DEC_09[POCET_JAZYKOV + 1];
extern const char *text_DEC_11[POCET_JAZYKOV + 1];
extern const char *text_DEC_12[POCET_JAZYKOV + 1];
extern const char *text_DEC_13[POCET_JAZYKOV + 1];
extern const char *text_DEC_14[POCET_JAZYKOV + 1];
extern const char *text_DEC_21[POCET_JAZYKOV + 1];
extern const char *text_DEC_22_CZ[POCET_JAZYKOV + 1];
extern const char *text_DEC_23[POCET_JAZYKOV + 1];
extern const char *text_DEC_26[POCET_JAZYKOV + 1];
extern const char *text_DEC_27[POCET_JAZYKOV + 1];
extern const char *text_DEC_28[POCET_JAZYKOV + 1];
extern const char *text_DEC_29[POCET_JAZYKOV + 1];
extern const char *text_DEC_31[POCET_JAZYKOV + 1];

/* --------------- CSSR propri� --------------- */
extern const char *text_JAN_05_CSSR[POCET_JAZYKOV + 1];
extern const char *text_JAN_14_CSSR[POCET_JAZYKOV + 1];
extern const char *text_MAR_15_CSSR[POCET_JAZYKOV + 1];
extern const char *text_JUN_27_CSSR[POCET_JAZYKOV + 1];
extern const char *text_JUN_30_CSSR[POCET_JAZYKOV + 1];
extern const char *text_CSSR_TITUL_KONGREGACIE[POCET_JAZYKOV + 1]; // JUL
extern const char *text_AUG_01_CSSR[POCET_JAZYKOV + 1];
extern const char *text_SEP_26_CSSR[POCET_JAZYKOV + 1];
extern const char *text_OKT_16_CSSR[POCET_JAZYKOV + 1];

/* --------------- SVD propri� --------------- */
extern const char *text_JAN_15_SVD[POCET_JAZYKOV + 1];
extern const char *text_JAN_29_SVD[POCET_JAZYKOV + 1];

/* --------------- SDB propri� --------------- */
extern const char *text_JAN_15_SDB[POCET_JAZYKOV + 1];
extern const char *text_JAN_22_SDB[POCET_JAZYKOV + 1];
extern const char *text_JAN_24_SDB[POCET_JAZYKOV + 1];
extern const char *text_JAN_30_SDB[POCET_JAZYKOV + 1];
extern const char *text_JAN_31_SDB[POCET_JAZYKOV + 1];
extern const char *text_FEB_01_SDB[POCET_JAZYKOV + 1];
extern const char *text_FEB_07_SDB[POCET_JAZYKOV + 1];
extern const char *text_FEB_09_SDB[POCET_JAZYKOV + 1];
extern const char *text_FEB_25_SDB[POCET_JAZYKOV + 1];
extern const char *text_MAJ_06_SDB[POCET_JAZYKOV + 1];
extern const char *text_MAJ_13_SDB[POCET_JAZYKOV + 1];
extern const char *text_MAJ_16_SDB[POCET_JAZYKOV + 1];
extern const char *text_MAJ_18_SDB[POCET_JAZYKOV + 1];
extern const char *text_MAJ_24_SDB[POCET_JAZYKOV + 1];
extern const char *text_MAJ_29_SDB[POCET_JAZYKOV + 1];
extern const char *text_JUN_12_SDB[POCET_JAZYKOV + 1];
extern const char *text_JUN_23_SDB[POCET_JAZYKOV + 1];
extern const char *text_JUL_07_SDB[POCET_JAZYKOV + 1];
extern const char *text_AUG_02_SDB[POCET_JAZYKOV + 1];
extern const char *text_AUG_26_SDB[POCET_JAZYKOV + 1];
extern const char *text_SEP_22_SDB[POCET_JAZYKOV + 1];
extern const char *text_OKT_05_SDB[POCET_JAZYKOV + 1];
extern const char *text_OKT_13_SDB[POCET_JAZYKOV + 1];
extern const char *text_OKT_24_SDB[POCET_JAZYKOV + 1];
extern const char *text_OKT_25_SDB[POCET_JAZYKOV + 1];
extern const char *text_OKT_29_SDB[POCET_JAZYKOV + 1];
extern const char *text_NOV_05_SDB[POCET_JAZYKOV + 1];
extern const char *text_NOV_13_SDB[POCET_JAZYKOV + 1];
extern const char *text_NOV_15_SDB[POCET_JAZYKOV + 1];
extern const char *text_NOV_25_SDB[POCET_JAZYKOV + 1];
extern const char *text_DEC_05_SDB[POCET_JAZYKOV + 1];

/* --------------- SJ propri� --------------- */
extern const char *text_JAN_01_SJ[POCET_JAZYKOV + 1];
extern const char *text_JAN_19_SJ[POCET_JAZYKOV + 1];
extern const char *text_FEB_04_SJ[POCET_JAZYKOV + 1];
extern const char *text_FEB_06_SJ[POCET_JAZYKOV + 1];
extern const char *text_FEB_15_SJ[POCET_JAZYKOV + 1];
extern const char *text_APR_22_SJ[POCET_JAZYKOV + 1];
extern const char *text_APR_27_SJ[POCET_JAZYKOV + 1];
extern const char *text_MAJ_04_SJ[POCET_JAZYKOV + 1];
extern const char *text_MAJ_16_SJ[POCET_JAZYKOV + 1];
extern const char *text_JUN_09_SJ[POCET_JAZYKOV + 1];
extern const char *text_JUN_21_SJ[POCET_JAZYKOV + 1];
extern const char *text_JUL_02_SJ[POCET_JAZYKOV + 1];
extern const char *text_JUL_31_SJ[POCET_JAZYKOV + 1];
extern const char *text_AUG_02_SJ[POCET_JAZYKOV + 1];
extern const char *text_AUG_18_SJ[POCET_JAZYKOV + 1];
extern const char *text_SEP_07_SJ[POCET_JAZYKOV + 1];
extern const char *text_SEP_09_SJ[POCET_JAZYKOV + 1];
extern const char *text_SEP_10_SJ[POCET_JAZYKOV + 1];
extern const char *text_SEP_17_SJ[POCET_JAZYKOV + 1];
extern const char *text_OKT_03_SJ[POCET_JAZYKOV + 1];
extern const char *text_OKT_06_SJ[POCET_JAZYKOV + 1];
extern const char *text_OKT_14_SJ[POCET_JAZYKOV + 1];
extern const char *text_OKT_19_SJ[POCET_JAZYKOV + 1];
extern const char *text_OKT_30_SJ[POCET_JAZYKOV + 1];
extern const char *text_OKT_31_SJ[POCET_JAZYKOV + 1];
extern const char *text_NOV_03_SJ[POCET_JAZYKOV + 1];
extern const char *text_NOV_05_SJ[POCET_JAZYKOV + 1];
extern const char *text_NOV_13_SJ[POCET_JAZYKOV + 1];
extern const char *text_NOV_14_SJ[POCET_JAZYKOV + 1];
extern const char *text_NOV_16_SJ[POCET_JAZYKOV + 1];
extern const char *text_NOV_23_SJ[POCET_JAZYKOV + 1];
extern const char *text_NOV_26_SJ[POCET_JAZYKOV + 1];
extern const char *text_DEC_01_SJ[POCET_JAZYKOV + 1];
extern const char *text_DEC_03_SJ[POCET_JAZYKOV + 1];

/* --------------- OFM propri� --------------- */
extern const char *text_JAN_04_OFM[POCET_JAZYKOV + 1];
extern const char *text_JAN_05_OFM[POCET_JAZYKOV + 1];
extern const char *text_JAN_12_OFM[POCET_JAZYKOV + 1];
extern const char *text_JAN_14_OFM[POCET_JAZYKOV + 1];
extern const char *text_JAN_16_OFM[POCET_JAZYKOV + 1];
extern const char *text_JAN_20_OFM[POCET_JAZYKOV + 1];
extern const char *text_JAN_30_OFM[POCET_JAZYKOV + 1];
extern const char *text_FEB_04_OFM[POCET_JAZYKOV + 1];
extern const char *text_FEB_06_OFM[POCET_JAZYKOV + 1];
extern const char *text_FEB_07_OFM[POCET_JAZYKOV + 1];
extern const char *text_MAR_02_OFM[POCET_JAZYKOV + 1];
extern const char *text_MAR_12_OFM[POCET_JAZYKOV + 1];
extern const char *text_MAR_18_OFM[POCET_JAZYKOV + 1];
extern const char *text_APR_21_OFM[POCET_JAZYKOV + 1];
extern const char *text_APR_23_OFM[POCET_JAZYKOV + 1];
extern const char *text_APR_24_OFM[POCET_JAZYKOV + 1];
extern const char *text_APR_30_OFM[POCET_JAZYKOV + 1];
extern const char *text_MAJ_08_OFM[POCET_JAZYKOV + 1];
extern const char *text_MAJ_08_2_OFM[POCET_JAZYKOV + 1];
extern const char *text_MAJ_08_3_OFM[POCET_JAZYKOV + 1];
extern const char *text_MAJ_09_OFM[POCET_JAZYKOV + 1];
extern const char *text_MAJ_11_OFM[POCET_JAZYKOV + 1];
extern const char *text_MAJ_12_OFM[POCET_JAZYKOV + 1];
extern const char *text_MAJ_13_OFM[POCET_JAZYKOV + 1];
extern const char *text_MAJ_16_OFM[POCET_JAZYKOV + 1];
extern const char *text_MAJ_17_OFM[POCET_JAZYKOV + 1];
extern const char *text_MAJ_18_OFM[POCET_JAZYKOV + 1];
extern const char *text_MAJ_19_OFM[POCET_JAZYKOV + 1];
extern const char *text_MAJ_20_OFM[POCET_JAZYKOV + 1];
extern const char *text_MAJ_24_OFM[POCET_JAZYKOV + 1];
extern const char *text_JUN_02_OFM[POCET_JAZYKOV + 1];
extern const char *text_JUN_08_OFM[POCET_JAZYKOV + 1];
extern const char *text_JUN_12_OFM[POCET_JAZYKOV + 1];
extern const char *text_JUN_12_2_OFM[POCET_JAZYKOV + 1];
extern const char *text_JUN_12_3_OFM[POCET_JAZYKOV + 1];
extern const char *text_JUN_13_OFM[POCET_JAZYKOV + 1];
extern const char *text_JUN_16_OFM[POCET_JAZYKOV + 1];
extern const char *text_JUN_16_2_OFM[POCET_JAZYKOV + 1];
extern const char *text_JUN_17_OFM[POCET_JAZYKOV + 1];
extern const char *text_JUN_26_OFM[POCET_JAZYKOV + 1];
extern const char *text_NEPOSKVRNENEHO_SRDCA_PM_OFM[POCET_JAZYKOV + 1];
extern const char *text_JUL_09_OFM[POCET_JAZYKOV + 1];
extern const char *text_JUL_10_OFM[POCET_JAZYKOV + 1];
extern const char *text_JUL_14_OFM[POCET_JAZYKOV + 1];
extern const char *text_JUL_15_OFM[POCET_JAZYKOV + 1];

#endif /* __DBZALTAR_H_ */

