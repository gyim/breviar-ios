/***************************************************************/
/*                                                             */
/* dbzaltar.cpp                                                */
/* (c)1999-2006 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | program tvoriaci stranky pre liturgiu hodin   */
/* document history                                            */
/*   09/02/2000A.D. | urobene .cpp kvoli dvojakosti funkcie    */
/*                    sviatky_svatych(); a inym veciam         */
/*   23/02/2000A.D. | ponechal som tu "stare", zle pokusy,     */
/*                    oznacene WRONG_23_02_2000                */
/*   05/04/2000A.D. | uz su dokoncene vsetky sviatky svatych.  */
/*                    odstranil som label_... pre slavnosti    */
/*                    obdobia cez rok, lebo tam nevadi, ze     */
/*                    slavnost padne na nedelu, lebo ma vyssiu */
/*                    prioritu                                 */
/*   29/03/2000A.D. | ukoncene vsetky mesiace MES_JAN - MES_DEC*/
/*   06/09/2001A.D. | tento popis                              */
/*   07/09/2001A.D. | opravene: sv. Brigity (sviatok)          */
/*   26/09/2001A.D. | opravene: sv. Terezie Benedikty (sviatok)*/
/*   2003-06-30a.D. | zmeny pre spomienku neposkvrn.srdca PM   */
/*   2003-08-11a.D. | -Wall upozornila na / * within comments  */
/*   2003-08-13a.D. | odstranene DEBUG_MODLITBA_CEZ_DEN        */
/*                  - zaltar() doplnena o modlitbu cez den     */
/*                  - nastavovanie doplnkovej psalmodie        */
/*                  - #define presunute do header-u dbzaltar.h */
/*   2003-08-21a.D. | pokusy s posvatnymi citaniami (zalmy)    */
/*   2003-10-07a.D. | zmena v _SET_SPOLOCNE_VECI_NEDELA        */
/*   2003-11-20a.D. | zmeny pre posvatne citanie (adv1)        */
/*   2003-12-07a.D. | posvatne citanie (adv2)                  */
/*   2004-04-28a.D. | posvatne citanie (cez rok)               */
/*                  - rozsafne strcpy zmenene na mystrcpy      */
/*   2004-08-14a.D. | Sviatok Sv. Jany Frantiöky de Chantal    */
/*                    presunuty z 12. decembra na 12. augusta  */
/*                  - Sviatok Bl. Zdenky Schelingovej,         */
/*                    panny a muËenice, ako 2. moznost 30.jula */
/*   2004-08-31a.D. | nastavenie modlitby pre posv.cit.o.c.r.  */
/*   2004-09-03a.D. | zmena v modlitbe (na nedelnu kolektu)    */
/*   2004-09-23a.D. | pridany sv. pater Pio                    */
/*   2005-03-26a.D. | pridane posvatne citania (Trencin)       */
/*   2005-03-27a.D. | CHAR_MODL_* z funkcie pismenko_modlitby  */
/*                    do liturgia.h                            */
/*                  - upravy v psalmodii pre posvatne citanie  */
/*   2005-07-22a.D. | pokus o doplnenie udajov k posv.cit.svsv */
/*   2005-07-27a.D. | posv. ËÌtania pre vlastnÈ Ëasti sv‰t˝ch  */
/*   2005-08-05a.D. | 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloË. */
/*                    Ëasti sviatkov sv‰t˝ch nasledovne:       */
/*                    - I. zv.(advent, vianoce) a II. zv.(pÙst)*/
/*                    - II. zv‰zok (veæk· noc)                 */
/*                    - III. a IV. zv‰zok (obdobie cez rok)    */
/*   2005-08-08a.D. | dokonËenÈ vlastnÈ Ëasti augusta          */
/*   2005-10-13a.D. | dokonË. vlastnÈ Ëasti sept-okt (len kÛd) */
/*   2005-11-20a.D. | zaË. modlitba cez deÚ, adv1              */
/*   2005-11-24a.D. | skorektnenÈ: su_zalmy_nedela1tyzden      */
/*   2006-01-19a.D. | dokonËen˝ janu·r a febru·r, sv.muûov     */
/*   2006-01-19a.D. | nedokonËenÈ: "2006-01-19_LABEL"          */
/*   2006-01-24a.D. | pridanÈ zaltar_zvazok()                  */
/*   2006-01-25a.D. | dokonËenÈ pÙstne obdobie (mcd+posv.ËÌt.) */
/*   2006-01-25a.D. | su_zalmy_nedela1tyzden > ZALMY1NE_FIX    */
/*   2006-02-02a.D. | pridanÈ posv. ËÌtania pre æs PM v sobotu */
/*   2006-02-04a.D. | su_zalmy_zo_sviatku > ZALMY_ZO_SVIATKU   */
/*   2006-02-05a.D. | dokonËenÈ vianoËnÈ obdobie I (ËÌt.+mcd)  */
/*   2006-02-07a.D. | ZALTAR_... pre funkciu zaltar_zvazok();  */
/*                  - doplnenÈ modl.cez deÚ - sviatky sv‰t˝ch  */
/*   2006-08-07a.D. | pridanÈ sv. muûov/ûien, Ëo ûili v manû.  */
/*   2006-08-08a.D. | skutky mil., rehoænÌkov, vychov·vateæov  */
/*   2006-08-18a.D. | zmena int na short int (staËÌ 32tis.)    */
/*                                                             */
/* notes |                                                     */
/*   * povodne islo o dva fajly, dbzaltar.c a dbsvaty.c        */
/*                                                             */
/***************************************************************/

//#define DETAIL_LOG_SVATY /* 22/02/2000A.D. */
//#define DETAIL_LOG_GLOBAL_DEN /* 22/02/2000A.D. */

#include "dbzaltar.h" /* 22/02/2000A.D. -- rozdelene na .h a .cpp subor */

char _anchor_head[SMALL];

#include "liturgia.h"

#include "myexpt.h" /* export do suboru alebo na konzolu printf */
/* povodne tu bolo aj include "sets.c", ale to je nizsie */
#include "mylog.h"
#include <string.h>
#include "mystring.h" /* pridane 2003-08-11 kvoli _INIT_DM */
#include "breviar.h"  /* pridane 2003-08-13 kvoli _global_opt5 */

/* 2005-03-26: Presunute na zaciatok */
/* 2003-06-30 pre lahsie debugovanie obohateny vypis */
#define set_LOG_litobd Log("   set(litobd): %s: `%s', <!--{BEGIN:%s}-->\n", nazov_modlitby(modlitba), _file, _anchor)
/* 2004-04-28 pre lahsie debugovanie obohateny vypis pre pc */
#define set_LOG_litobd_pc Log("   set(litobd): %s: `%s', <!--{BEGIN:%s}-->\n", nazov_modlitby(modlitba), _file_pc, _anchor)
/* 2004-04-28 pre lahsie debugovanie obohateny vypis pre pc-tyzden */
#define set_LOG_litobd_pc_tyzden Log("   set(litobd): %s: `%s', <!--{BEGIN:%s}-->\n", nazov_modlitby(modlitba), _file_pc_tyzden, _anchor)

/* #define (stringove konstanty) presunute do header-u dbzaltar.h, 2003-08-15 */
/* globalne premenne prehodene do liturgia.h, 17/02/2000A.D. */
/* ------------------------------------------------------------------- */

/* ------------------------------------------------------------------- */
/* nasledujuca pasaz bola kedysi fajl sets.c */

void _set_popis(short int modlitba, const char *file, const char *anchor){ /* pridana 05/04/2000A.D. */
	switch(modlitba){
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.popis.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.popis.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		/* 2005-07-22: Pridan˝ popis aj pre posv‰tnÈ ËÌtanie a modlitbu cez deÚ */
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.popis.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.popis.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_9:
			mystrcpy(_global_modl_cez_den_9.popis.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_9.popis.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_12:
			mystrcpy(_global_modl_cez_den_12.popis.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_12.popis.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_3:
			mystrcpy(_global_modl_cez_den_3.popis.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_3.popis.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.popis.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.popis.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.popis.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.popis.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

void _set_hymnus(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.hymnus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.hymnus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.hymnus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.hymnus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_9:
			mystrcpy(_global_modl_cez_den_9.hymnus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_9.hymnus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_12:
			mystrcpy(_global_modl_cez_den_12.hymnus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_12.hymnus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_3:
			mystrcpy(_global_modl_cez_den_3.hymnus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_3.hymnus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.hymnus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.hymnus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.hymnus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.hymnus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

void _set_antifona1(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.antifona1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.antifona1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_9:
			mystrcpy(_global_modl_cez_den_9.antifona1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_9.antifona1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_12:
			mystrcpy(_global_modl_cez_den_12.antifona1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_12.antifona1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_3:
			mystrcpy(_global_modl_cez_den_3.antifona1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_3.antifona1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.antifona1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.antifona1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.antifona1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.antifona1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		/* pridane 2003-11-20 */
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.antifona1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.antifona1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

void _set_antifona2(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.antifona2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.antifona2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_9:
			mystrcpy(_global_modl_cez_den_9.antifona2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_9.antifona2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_12:
			mystrcpy(_global_modl_cez_den_12.antifona2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_12.antifona2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_3:
			mystrcpy(_global_modl_cez_den_3.antifona2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_3.antifona2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.antifona2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.antifona2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.antifona2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.antifona2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		/* pridane 2003-11-20 */
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.antifona2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.antifona2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

void _set_antifona3(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.antifona3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.antifona3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_9:
			mystrcpy(_global_modl_cez_den_9.antifona3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_9.antifona3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_12:
			mystrcpy(_global_modl_cez_den_12.antifona3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_12.antifona3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_3:
			mystrcpy(_global_modl_cez_den_3.antifona3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_3.antifona3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.antifona3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.antifona3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.antifona3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.antifona3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		/* pridane 2003-11-20 */
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.antifona3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.antifona3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

void _set_zalm1(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.zalm1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.zalm1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		/* modlitby cez den maju spolocnu psalmodiu, 
		 * pokial si pouzivatel nevyziada doplnkovu psalmodiu (seria 1-3),
		 * preto nastavujem aj spolocne pre vsetky modlitby
		 * 2003-08-13
		 */
		case MODL_CEZ_DEN_VSETKY:
		case MODL_PREDPOLUDNIM:
			/* predpoludnim */
			mystrcpy(_global_modl_cez_den_9.zalm1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_9.zalm1.anchor, anchor, MAX_STR_AF_ANCHOR);
			if(modlitba == MODL_PREDPOLUDNIM) break;
		case MODL_NAPOLUDNIE:
			/* napoludnie */
			mystrcpy(_global_modl_cez_den_12.zalm1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_12.zalm1.anchor, anchor, MAX_STR_AF_ANCHOR);
			if(modlitba == MODL_NAPOLUDNIE) break;
		case MODL_POPOLUDNI:
			/* popoludni */
			mystrcpy(_global_modl_cez_den_3.zalm1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_3.zalm1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.zalm1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.zalm1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.zalm1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.zalm1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.zalm1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.zalm1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

#define _set_rchvalospev _set_zalm2
void _set_zalm2(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.zalm2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.zalm2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		/* modlitby cez den maju spolocnu psalmodiu, 
		 * pokial si pouzivatel nevyziada doplnkovu psalmodiu (seria 1-3),
		 * preto nastavujem aj spolocne pre vsetky modlitby
		 * 2003-08-13
		 */
		case MODL_CEZ_DEN_VSETKY:
		case MODL_PREDPOLUDNIM:
			/* predpoludnim */
			mystrcpy(_global_modl_cez_den_9.zalm2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_9.zalm2.anchor, anchor, MAX_STR_AF_ANCHOR);
			if(modlitba == MODL_PREDPOLUDNIM) break;
		case MODL_NAPOLUDNIE:
			/* napoludnie */
			mystrcpy(_global_modl_cez_den_12.zalm2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_12.zalm2.anchor, anchor, MAX_STR_AF_ANCHOR);
			if(modlitba == MODL_NAPOLUDNIE) break;
		case MODL_POPOLUDNI:
			/* popoludni */
			mystrcpy(_global_modl_cez_den_3.zalm2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_3.zalm2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.zalm2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.zalm2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.zalm2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.zalm2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.zalm2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.zalm2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

#define _set_vchvalospev _set_zalm3
void _set_zalm3(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.zalm3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.zalm3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		/* modlitby cez den maju spolocnu psalmodiu, 
		 * pokial si pouzivatel nevyziada doplnkovu psalmodiu (seria 1-3),
		 * preto nastavujem aj spolocne pre vsetky modlitby
		 * 2003-08-13
		 */
		case MODL_CEZ_DEN_VSETKY:
		case MODL_PREDPOLUDNIM:
			/* predpoludnim */
			mystrcpy(_global_modl_cez_den_9.zalm3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_9.zalm3.anchor, anchor, MAX_STR_AF_ANCHOR);
			if(modlitba == MODL_PREDPOLUDNIM) break;
		case MODL_NAPOLUDNIE:
			/* napoludnie */
			mystrcpy(_global_modl_cez_den_12.zalm3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_12.zalm3.anchor, anchor, MAX_STR_AF_ANCHOR);
			if(modlitba == MODL_NAPOLUDNIE) break;
		case MODL_POPOLUDNI:
			/* popoludni */
			mystrcpy(_global_modl_cez_den_3.zalm3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_3.zalm3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.zalm3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.zalm3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.zalm3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.zalm3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.zalm3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.zalm3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

/* pri posvatnom citani plati pre 1. citanie */
#define _set_citanie1 _set_kcitanie
/* pridane 2003-11-20 */

void _set_kcitanie(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.kcitanie.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.kcitanie.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_9:
			mystrcpy(_global_modl_cez_den_9.kcitanie.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_9.kcitanie.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_12:
			mystrcpy(_global_modl_cez_den_12.kcitanie.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_12.kcitanie.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_3:
			mystrcpy(_global_modl_cez_den_3.kcitanie.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_3.kcitanie.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.kcitanie.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.kcitanie.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.kcitanie.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.kcitanie.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		/* pridane 2003-11-20 */
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.kcitanie.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.kcitanie.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

/* pri posvatnom citani plati pre responz _pred_ citaniami */
void _set_kresponz(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.kresponz.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.kresponz.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_9:
			mystrcpy(_global_modl_cez_den_9.kresponz.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_9.kresponz.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_12:
			mystrcpy(_global_modl_cez_den_12.kresponz.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_12.kresponz.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_3:
			mystrcpy(_global_modl_cez_den_3.kresponz.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_3.kresponz.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.kresponz.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.kresponz.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.kresponz.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.kresponz.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		/* pridane 2003-11-20 */
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.kresponz.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.kresponz.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

/* pri posvatnom citani plati magn/ben pre 2. citanie */
#define _set_citanie2 _set_benediktus
/* pridane 2003-11-20 */

#define _set_magnifikat _set_benediktus
void _set_benediktus(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.benediktus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.benediktus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.benediktus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.benediktus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.benediktus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.benediktus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		/* pridane 2003-11-20 */
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.benediktus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.benediktus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

void _set_prosby(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.prosby.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.prosby.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.prosby.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.prosby.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.prosby.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.prosby.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

void _set_modlitba(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.modlitba.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.modlitba.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.modlitba.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.modlitba.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_9:
			mystrcpy(_global_modl_cez_den_9.modlitba.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_9.modlitba.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_12:
			mystrcpy(_global_modl_cez_den_12.modlitba.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_12.modlitba.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_3:
			mystrcpy(_global_modl_cez_den_3.modlitba.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_3.modlitba.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.modlitba.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.modlitba.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.modlitba.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.modlitba.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}
/* koniec pasaze, co bola kedysi sets.c -- 22/02/2000A.D. */
/* ------------------------------------------------------------------- */

/* files - nazvy suborov pre zaltar styroch tyzdnov */
char _file[SMALL]; /* nazov fajlu, napr. _1ne.htm */
char _file_pc[SMALL]; /* nazov fajlu pre posvatne citania; pridane 2003-11-20 */
char _file_pc_tyzden[SMALL]; /* nazov fajlu pre posvatne citania v zavislosti od tyzdna (obdobie cez rok); pridane 2004-04-28 */

/* tyzzal == 1 .. 4,
 * den == 0 (DEN_NEDELA) .. 6 (DEN_SOBOTA) */
void file_name_zaltar(short int den, short int tyzzal){
	sprintf(_file, "_%d%s.htm", tyzzal, nazov_dn_asci[den]);
}
void file_name_litobd(short int litobd){
	sprintf(_file, "%s", nazov_obd_htm[litobd]);
}
/* pridane 2003-11-20 - iny subor pre posvatne citania */
void file_name_litobd_pc(short int litobd){
	sprintf(_file_pc, "%s", nazov_obd_htm_pc[litobd]);
}
/* pridane 2004-04-28 - iny subor pre posvatne citania v obdobi cez rok (pre kazdy tyzden iny) */
void file_name_litobd_pc_tyzden(short int litobd, short int tyzden){
	sprintf(_file_pc_tyzden, "%02d%s", tyzden, nazov_obd_htm_pc[litobd]);
}

/* anchors - nazvy kotiev pre zaltar styroch tyzdnov */
char _anchor[SMALL];
/* tyzzal == 1 .. 4,
 * den == 0 (DEN_NEDELA) .. 6 (DEN_SOBOTA),
 * modlitba == MODL_...,
 * anchor == ANCHOR_... */
char pismenko_modlitby(short int modlitba){
	/* 2005-03-27: Upravene na konstanty, presunute do liturgia.h */
	switch(modlitba){
		case MODL_INVITATORIUM       : return CHAR_MODL_INVITATORIUM;
		case MODL_RANNE_CHVALY       : return CHAR_MODL_RANNE_CHVALY;
		case MODL_POSV_CITANIE       : return CHAR_MODL_POSV_CITANIE;
		case MODL_CEZ_DEN_9          : return CHAR_MODL_CEZ_DEN_9;
		case MODL_CEZ_DEN_12         : return CHAR_MODL_CEZ_DEN_12;
		case MODL_CEZ_DEN_3          : return CHAR_MODL_CEZ_DEN_3;
		case MODL_VESPERY            : return CHAR_MODL_VESPERY;
		case MODL_KOMPLETORIUM       : return CHAR_MODL_KOMPLETORIUM;
		case MODL_NEURCENA           : return CHAR_MODL_NEURCENA; /* toto by sa nemalo */
		case MODL_PRVE_VESPERY       : return CHAR_MODL_PRVE_VESPERY;
		case MODL_PRVE_KOMPLETORIUM  : return CHAR_MODL_PRVE_KOMPLETORIUM;
		case MODL_DRUHE_VESPERY      : return CHAR_MODL_DRUHE_VESPERY; /* toto by sa nemalo */
		case MODL_DRUHE_KOMPLETORIUM : return CHAR_MODL_DRUHE_KOMPLETORIUM; /* toto by sa nemalo */
	}/* switch(modlitba) */
	return 0;
}/* pismenko_modlitby(); */

void anchor_name_zaltar(short int den, short int tyzzal, short int modlitba, char *anchor){
	sprintf(_anchor, "_%d%s%c_%s",
		tyzzal, nazov_DN_asci[den], pismenko_modlitby(modlitba), anchor);
}

#define set_LOG_zaltar
//Log("   set(zaltar): %s: `%s', <!--{...:%s}-->\n", nazov_modlitby(modlitba), _file, _anchor)

void set_hymnus(short int den, short int tyzzal, short int modlitba){
	/* pridana modlitba cez den, ma hymny rovnake pre cele obdobie cez rok, 2003-08-15 */
	if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		file_name_litobd(OBD_CEZ_ROK);
		sprintf(_anchor, "%c_%s_%d", 
			pismenko_modlitby(modlitba), ANCHOR_HYMNUS, (den + tyzzal) % 2);
		_set_hymnus(modlitba, _file, _anchor);
		set_LOG_zaltar;
	}
	else{ /* nie modlitba cez den */
		/* prvy a treti, resp. druhy a stvrty tyzden maju rovnake */
		if(tyzzal == 3)
			tyzzal = 1;
		else if(tyzzal == 4)
			tyzzal = 2;
		/* 2005-03-26: Pridane odvetvenie pre posvatne citania */
		if(modlitba == MODL_POSV_CITANIE){
			file_name_litobd_pc(OBD_CEZ_ROK);
			anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_HYMNUS);
			_set_hymnus(modlitba, _file_pc, _anchor);
			set_LOG_litobd_pc;
		}
		else{
			file_name_zaltar(den, tyzzal);
			anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_HYMNUS);
			_set_hymnus(modlitba, _file, _anchor);
			set_LOG_zaltar;
		}
	}

}

#define _set_antifony_velk_pc(den, tyzzal, modlitba) {\
		/* 1. antifona */\
		file_name_litobd_pc(OBD_CEZ_ROK);\
		anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA1V);\
		_set_antifona1(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
		/* 2. antifona */\
		file_name_litobd_pc(OBD_CEZ_ROK);\
		anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA2V);\
		_set_antifona2(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
		/* 3. antifona */\
		file_name_litobd_pc(OBD_CEZ_ROK);\
		anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA3V);\
		_set_antifona3(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
}

void set_antifony(short int den, short int tyzzal, short int zvazok, short int modlitba){
	/* 2006-01-24: pÙvodn· podmienka zosilnen·, keÔûe pre obyËajnÈ dni veækonoËnÈho 
	 * obdobia (2.-7. t˝ûdeÚ) moûno braù antifÛny pre posv‰tnÈ ËÌtania z cezroËnÈho obdobia
	 * 
	 * 2006-01-24: taktieû pridan˝ ÔalöÌ parameter; pre niektorÈ dni v II. zv‰zku s˙ 
	 * inÈ ûalmy aj antifÛny
	 * 
	 * 2006-02-09: podmienka zmenen·: 
	 * aj pre nedeænÈ posv. ËÌtanie s˙ antifÛny v file_name_litobd_pc(OBD_CEZ_ROK);
	 * 
	 */
	short int povodny_tyzzal;
	povodny_tyzzal = tyzzal; /* 2006-01-24: uloûÌme pÙvodn˙ hodnotu */
	if(
			((_global_den.litobd == OBD_VELKONOCNE_I) ||
			(_global_den.litobd == OBD_VELKONOCNE_II))
		&& 
			(modlitba != MODL_POSV_CITANIE)
	){
		/* velkonocne obdobie */
		file_name_zaltar(den, tyzzal);
		anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA1V);
		_set_antifona1(modlitba, _file, _anchor);
		set_LOG_zaltar;
		anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA2V);
		_set_antifona2(modlitba, _file, _anchor);
		set_LOG_zaltar;
		/* antifona na vecerny hymnus je rovnaka pre prvy a treti,
		 * resp. druhy a stvrty tyzden zaltara */
		if((modlitba == MODL_VESPERY) || (modlitba == MODL_PRVE_VESPERY)){
			if(tyzzal == 3)
				tyzzal = 1;
			else if(tyzzal == 4)
				tyzzal = 2;
		}
		file_name_zaltar(den, tyzzal);
		anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA3V);
		_set_antifona3(modlitba, _file, _anchor);
		set_LOG_zaltar;
	}
	/* 2006-02-09: Pre posv. ËÌtania nedieæ veækonoËnÈho obdobia samostatne nastavÌme,
	 *             hoci sme si vedomÌ, ûe pre 5., 6. a 7. veækonoËn˙ nedeæu to bude potrebnÈ zmeniù
	 */
	else if(
			((_global_den.litobd == OBD_VELKONOCNE_I) ||
			(_global_den.litobd == OBD_VELKONOCNE_II))
		&& 
			(modlitba = MODL_POSV_CITANIE)
		&& 
			(_global_den.den = DEN_NEDELA)
	){
		_set_antifony_velk_pc(den, tyzzal, modlitba);
	}
	else{
		/* 2005-03-26: Pridane odvetvenie pre posvatne citania */

		/* 1. antifona */
		if(modlitba == MODL_POSV_CITANIE){
			file_name_litobd_pc(OBD_CEZ_ROK);
			anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA1);
			_set_antifona1(modlitba, _file_pc, _anchor);
			set_LOG_litobd_pc;
		}
		else{
			file_name_zaltar(den, tyzzal);
			anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA1);
			_set_antifona1(modlitba, _file, _anchor);
			set_LOG_zaltar;
		}

		/* 2. antifona */
		if(modlitba == MODL_POSV_CITANIE){
			file_name_litobd_pc(OBD_CEZ_ROK);
			anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA2);
			_set_antifona2(modlitba, _file_pc, _anchor);
			set_LOG_litobd_pc;
		}
		else{
			file_name_zaltar(den, tyzzal);
			anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA2);
			_set_antifona2(modlitba, _file, _anchor);
			set_LOG_zaltar;
		}

	/* 3. antifona */
		/* antifona na vecerny hymnus je rovnaka pre prvy a treti,
		 * resp. druhy a stvrty tyzden zaltara */
		if((modlitba == MODL_VESPERY) || (modlitba == MODL_PRVE_VESPERY)){
			if(tyzzal == 3)
				tyzzal = 1;
			else if(tyzzal == 4)
				tyzzal = 2;
		}
		if(modlitba == MODL_POSV_CITANIE){
			file_name_litobd_pc(OBD_CEZ_ROK);
			anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA3);
			_set_antifona3(modlitba, _file_pc, _anchor);
			set_LOG_litobd_pc;
		}
		else{
			file_name_zaltar(den, tyzzal);
			anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA3);
			_set_antifona3(modlitba, _file, _anchor);
			set_LOG_zaltar;
		}
	}
	/* 2006-01-24: napokon upravÌme niektorÈ antifÛny pre II. zv‰zok, posv‰tnÈ ËÌtanie */
	if((zvazok == 2) && (modlitba == MODL_POSV_CITANIE)){
		/* jedn· sa o nasledovnÈ:
		 * 1. t˝ûdeÚ: sobota
		 * 2. t˝ûdeÚ: sobota
		 * 4. t˝ûdeÚ: piatok (asi chceli, aby to bola vûdy sobota, ale tento ûalm nadv‰zuje)
		 * 4. t˝ûdeÚ: sobota
		 */
		if(
			((den == DEN_SOBOTA) && ((povodny_tyzzal == 1) || (povodny_tyzzal == 2) || (povodny_tyzzal == 4)))
		||
			((den == DEN_PIATOK) && (povodny_tyzzal == 4))
		){
			Log("-- upravujeme antifÛny (t˝ûdeÚ + 4), lebo v II. zv‰zku brevi·ra s˙ pre tento deÚ inÈ...\n");
			file_name_litobd_pc(OBD_CEZ_ROK);
			anchor_name_zaltar(den, 4 + tyzzal, modlitba, ANCHOR_ANTIFONA1);
			_set_antifona1(modlitba, _file_pc, _anchor);
			set_LOG_litobd_pc;
			anchor_name_zaltar(den, 4 + tyzzal, modlitba, ANCHOR_ANTIFONA2);
			_set_antifona2(modlitba, _file_pc, _anchor);
			set_LOG_litobd_pc;
			anchor_name_zaltar(den, 4 + tyzzal, modlitba, ANCHOR_ANTIFONA3);
			_set_antifona3(modlitba, _file_pc, _anchor);
			set_LOG_litobd_pc;
		}
	}
}

void set_kcitanie(short int den, short int tyzzal, short int modlitba){
	file_name_zaltar(den, tyzzal);
	anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_KCITANIE);
	_set_kcitanie(modlitba, _file, _anchor);
	set_LOG_zaltar;
}

void set_kresponz(short int den, short int tyzzal, short int modlitba){
	/* 2005-03-26: Pridane odvetvenie pre posvatne citania */
	if(modlitba == MODL_POSV_CITANIE){
		file_name_litobd_pc(OBD_CEZ_ROK);
		anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_KRESPONZ);
		_set_kresponz(modlitba, _file_pc, _anchor);
		set_LOG_litobd_pc;
	}
	else{
		if((modlitba != MODL_PREDPOLUDNIM) && (modlitba != MODL_NAPOLUDNIE) && (modlitba != MODL_POPOLUDNI)){
			/* 2005-03-27: pre modlitbu cez den to neplati:
			 * prvy a treti, resp. druhy a stvrty tyzden maju rovnake */
			if(tyzzal == 3)
				tyzzal = 1;
			else if(tyzzal == 4)
				tyzzal = 2;
		}
		file_name_zaltar(den, tyzzal);
		anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_KRESPONZ);
		_set_kresponz(modlitba, _file, _anchor);
		set_LOG_zaltar;
	}
}

void set_prosby(short int den, short int tyzzal, short int modlitba){
	file_name_zaltar(den, tyzzal);
	anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_PROSBY);
	_set_prosby(modlitba, _file, _anchor);
	set_LOG_zaltar;
}

void set_modlitba(short int den, short int tyzzal, short int modlitba){
	if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		/* 2005-03-27: pre modlitbu cez den:
		 * prvy a treti, resp. druhy a stvrty tyzden maju rovnake */
		if(tyzzal == 3)
			tyzzal = 1;
		else if(tyzzal == 4)
			tyzzal = 2;
	}
	file_name_zaltar(den, tyzzal);
	anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_MODLITBA);
	_set_modlitba(modlitba, _file, _anchor);
	set_LOG_zaltar;
}

void set_benediktus(short int den, short int tyzzal, short int modlitba){
	/* prvy a treti, resp. druhy a stvrty tyzden maju rovnake */
	if(tyzzal == 3)
		tyzzal = 1;
	else if(tyzzal == 4)
		tyzzal = 2;
	file_name_zaltar(den, tyzzal);
	anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_BENEDIKTUS);
	_set_benediktus(modlitba, _file, _anchor);
	set_LOG_zaltar;
}

void set_magnifikat(short int den, short int tyzzal, short int modlitba){
	/* prvy a treti, resp. druhy a stvrty tyzden maju rovnake */
	if(tyzzal == 3)
		tyzzal = 1;
	else if(tyzzal == 4)
		tyzzal = 2;
	file_name_zaltar(den, tyzzal);
	anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_MAGNIFIKAT);
	_set_magnifikat(modlitba, _file, _anchor);
	set_LOG_zaltar;
}

void set_popis(short int modlitba, char *file, char *anchor){
	_set_popis(modlitba, file, anchor);
	Log("   set(popis): %s: `%s', <!--{BEGIN:%s}-->\n", nazov_modlitby(modlitba), _file, _anchor);
}

void set_popis_dummy(void){
/* pridane 05/04/2000A.D. */
	Log("  teraz nastavujem POPIS (dummy)...\n");
	mystrcpy(_file, "dummy", MAX_STR_AF_FILE);
	mystrcpy(_anchor, "dummy", MAX_STR_AF_ANCHOR);
	set_popis(MODL_RANNE_CHVALY, _file, _anchor); 
	/* 2005-07-22: PridanÈ popisy pre posv‰tnÈ ËÌtania */
	set_popis(MODL_POSV_CITANIE, _file, _anchor);
	set_popis(MODL_VESPERY, _file, _anchor);
	set_popis(MODL_PRVE_VESPERY, _file, _anchor);
	/* 2006-01-27: PridanÈ popisy pre modlitby cez deÚ */
	set_popis(MODL_PREDPOLUDNIM, _file, _anchor);
	set_popis(MODL_NAPOLUDNIE, _file, _anchor);
	set_popis(MODL_POPOLUDNI, _file, _anchor);
}

void _set_zalm_cez_den_doplnkova_psalmodia(void){
	/* modlitba predpoludnim, 1. seria doplnkovej psalmodie */
		_set_zalm1(MODL_PREDPOLUDNIM, "z120.htm", "ZALM120");
		_set_zalm2(MODL_PREDPOLUDNIM, "z121.htm", "ZALM121");
		_set_zalm3(MODL_PREDPOLUDNIM, "z122.htm", "ZALM122");
	/* modlitba napoludnie, 2. seria doplnkovej psalmodie */
		_set_zalm1(MODL_NAPOLUDNIE, "z123.htm", "ZALM123");
		_set_zalm2(MODL_NAPOLUDNIE, "z124.htm", "ZALM124");
		_set_zalm3(MODL_NAPOLUDNIE, "z125.htm", "ZALM125");
	/* modlitba popoludni, 3. seria doplnkovej psalmodie */
		_set_zalm1(MODL_POPOLUDNI, "z126.htm", "ZALM126");
		_set_zalm2(MODL_POPOLUDNI, "z127.htm", "ZALM127");
		_set_zalm3(MODL_POPOLUDNI, "z128.htm", "ZALM128");
}

/* zaltar();
 *
 * vstup: den == 0 (DEN_NEDELA) .. 6 (DEN_SOBOTA)
 *        tyzzal == 1 .. 4 (prvy az stvrty tyzzal zaltar
 *
 * nastavi do _global_modl_... (podla _global_modlitba) udaje potrebne
 * k modlitbe
 * 2003-08-13: nakoniec pridane porovnanie s _global_opt5 
 *             (ci brat zalmy z doplnkovej psalmodie pre modlitbu cez den)
 *
 * 2006-01-24: ûalmy pre posv‰tnÈ ËÌtanie s˙ v II. zv‰zku ûalt·ra (pÙst, veæk· noc)
 *             pre niektorÈ dni odliönÈ, preto sme vytvorili aj ÔalöÌ parameter,
 *             ktor˝ sa pouûÌva len pri volanÌ za ˙Ëelom konkrÈtnej modlitby
 *             (pre voæbu posv. ËÌtania len pre deÚ a t˝ûdeÚ ûalt·ra sa pouûije default)
 *
 */
#define _SET_SPOLOCNE_VECI_NEDELA(m) {\
	if((m == MODL_RANNE_CHVALY) || (m == MODL_VESPERY)){ \
		set_hymnus  (den, tyzzal, m); \
		set_antifony(den, tyzzal, zvazok, m); \
		set_kcitanie(den, tyzzal, m); \
		set_kresponz(den, tyzzal, m); \
		set_prosby  (den, tyzzal, m); \
		/* set_magnifikat(den, tyzzal, m); -- vlastna (pre vespery a 1. vespery) */ \
		/* set_benediktus(den, tyzzal, m); -- vlastna (pre ranne chvaly) */ \
		/* set_modlitba(den, tyzzal, m); -- vlastna */ \
	} \
	else{ \
		set_hymnus  (den, tyzzal, m); \
		set_antifony(den, tyzzal, zvazok, m); \
		set_kcitanie(den, tyzzal, m); \
		set_kresponz(den, tyzzal, m); \
		set_prosby  (den, tyzzal, m); /* 2003-10-07: pridane */\
		/* set_modlitba(den, tyzzal, m); -- vlastna */ \
	} \
}
#define _SET_SPOLOCNE_VECI_NIE_NEDELA(m) {\
	if((m == MODL_RANNE_CHVALY) || (m == MODL_VESPERY)){ \
		set_hymnus  (den, tyzzal, m); \
		set_antifony(den, tyzzal, zvazok, m); \
		set_kcitanie(den, tyzzal, m); \
		set_kresponz(den, tyzzal, m); \
		set_prosby  (den, tyzzal, m); \
		/* set_magnifikat(den, tyzzal, m); -- nastavene samostatne */ \
		/* set_benediktus(den, tyzzal, m); -- nastavene samostatne */ \
		set_modlitba(den, tyzzal, m); \
	} \
	else{ \
		set_hymnus  (den, tyzzal, m); \
		set_antifony(den, tyzzal, zvazok, m); \
		set_kcitanie(den, tyzzal, m); \
		set_kresponz(den, tyzzal, m); \
		set_modlitba(den, tyzzal, m); \
	} \
}
void zaltar_zvazok(short int den, short int tyzzal, short int obdobie, short int specialne){
	/* 2006-01-24: pÙvodn· funkcia mala 2 parametre 
	 *             pridan˝ parameter obdobie
	 * 2006-02-07: dodefinovanÈ rÙzne spr·vanie funkcie zaltar_zvazok();
	 *             podæa pridanÈho parametra ZALTAR_VSETKO alebo ZALTAR_IBA_ZALMY
	 */
	Log("-- zaltar_zvazok(%d, %d, %d, %d) -- zaciatok\n", den, tyzzal, obdobie, specialne);
	short int zvazok;
	if((obdobie == OBD_VELKONOCNA_OKTAVA) 
	|| (obdobie == OBD_VELKONOCNE_TROJDNIE) 
	|| (obdobie == OBD_VELKONOCNE_I) 
	|| (obdobie == OBD_VELKONOCNE_II) 
	|| (obdobie == OBD_POSTNE_I) 
	|| (obdobie == OBD_POSTNE_II_VELKY_TYZDEN) 
	){
		zvazok = 2;
	}
	else{
		zvazok = 0;
	}

	if(specialne == ZALTAR_VSETKO){
		Log("ZALTAR_VSETKO -- takûe nastavujem vöetko zo ûalt·ra...\n");
		/* cast vseobecna pre vsetky 4 tyzdne zaltara
		 * upravena 2003-08-13. veci dane do dvoch makier
		 */
		if(den == DEN_NEDELA){
			/* pridane casti pre modlitbu cez den a posvatne citanie, 2003-08-13 */
			_SET_SPOLOCNE_VECI_NEDELA(MODL_PRVE_VESPERY);
			_SET_SPOLOCNE_VECI_NEDELA(MODL_RANNE_CHVALY);
			_SET_SPOLOCNE_VECI_NEDELA(MODL_POSV_CITANIE);
			_SET_SPOLOCNE_VECI_NEDELA(MODL_PREDPOLUDNIM);
			_SET_SPOLOCNE_VECI_NEDELA(MODL_NAPOLUDNIE);
			_SET_SPOLOCNE_VECI_NEDELA(MODL_POPOLUDNI);
			_SET_SPOLOCNE_VECI_NEDELA(MODL_VESPERY);
		}/* den == DEN_NEDELA */
		else{/* nie nedela */
			_SET_SPOLOCNE_VECI_NIE_NEDELA(MODL_RANNE_CHVALY);
			_SET_SPOLOCNE_VECI_NIE_NEDELA(MODL_VESPERY);
			_SET_SPOLOCNE_VECI_NIE_NEDELA(MODL_POSV_CITANIE);
			_SET_SPOLOCNE_VECI_NIE_NEDELA(MODL_PREDPOLUDNIM);
			_SET_SPOLOCNE_VECI_NIE_NEDELA(MODL_NAPOLUDNIE);
			_SET_SPOLOCNE_VECI_NIE_NEDELA(MODL_POPOLUDNI);
			set_benediktus(den, tyzzal, MODL_RANNE_CHVALY);
			set_magnifikat(den, tyzzal, MODL_VESPERY);
		}/* den != DEN_NEDELA */
	}/* len ak if(specialne == ZALTAR_VSETKO) */
	else if(specialne == ZALTAR_IBA_ZALMY_HYMNUS_MCD){
		Log("ZALTAR_IBA_ZALMY_HYMNUS_MCD -- takûe nastavujem len hymny pre mcd...\n");
		set_hymnus(den, tyzzal, MODL_PREDPOLUDNIM);
		set_hymnus(den, tyzzal, MODL_NAPOLUDNIE);
		set_hymnus(den, tyzzal, MODL_POPOLUDNI);
	}/* len ak if(specialne == ZALTAR_IBA_ZALMY_HYMNUS_MCD) */
	else{
		Log("nebolo ZALTAR_VSETKO ani ZALTAR_IBA_ZALMY_HYMNUS_MCD -- takûe nastavujem len ûalmy...\n");
	}

	Log("Ôalej nastavujem ûalmy (öpecialitky spoloËnÈ pre niektorÈ t˝ûdne ûalt·ra)...\n");
	/* cast rovnaka pre kazdy tyzden zaltara */
	switch(den){
		case DEN_NEDELA:
			/* druhe vespery maju vzdy prvy zalm 110, 1-5.7 */
			_set_zalm1(MODL_VESPERY, "z110.htm", "ZALM110");
			/* nedelny ranny hymnus je rovnaky v prvom a tretom,
			 * resp. druhom a stvrtom tyzdni */
			if((tyzzal == 1) || (tyzzal == 3)){
				_set_zalm2(MODL_RANNE_CHVALY, "dan3_57.htm", "DAN3,57-88.56");
				/* modlitba cez den */
				_set_zalm1(MODL_CEZ_DEN_VSETKY, "z118.htm", "ZALM118_I");
				_set_zalm2(MODL_CEZ_DEN_VSETKY, "z118.htm", "ZALM118_II");
				_set_zalm3(MODL_CEZ_DEN_VSETKY, "z118.htm", "ZALM118_III");
			}
			else{ /* if((tyzzal == 2) || (tyzzal == 4)) */
				_set_zalm1(MODL_RANNE_CHVALY, "z118.htm", "ZALM118");
				_set_zalm2(MODL_RANNE_CHVALY, "dan3_52.htm", "DAN3,52-57");
				_set_zalm3(MODL_RANNE_CHVALY, "z150.htm", "ZALM150");
				/* modlitba cez den */
				_set_zalm1(MODL_CEZ_DEN_VSETKY, "z23.htm", "ZALM23");
				_set_zalm2(MODL_CEZ_DEN_VSETKY, "z76.htm", "ZALM76_I");
				_set_zalm3(MODL_CEZ_DEN_VSETKY, "z76.htm", "ZALM76_II");
			}
			/* vecerne nedelne hymny su rovnake v kazdom tyzdni */
			_set_zalm3(MODL_PRVE_VESPERY, "flp2.htm", "CHVAL_FLP2");
			if((_global_den.litobd != OBD_POSTNE_I) &&
				(_global_den.litobd != OBD_POSTNE_II_VELKY_TYZDEN)){				_set_zalm3(MODL_VESPERY, "zjv19.htm", "CHVAL_ZJV19");
			}
			else{
				_set_zalm3(MODL_VESPERY, "1pt2.htm", "CHVAL_1PT2");
			}
			break;
		/* vecerny hymnus vsedneho dna je rovnaky v kazdom tyzdni */
		case DEN_PONDELOK:
			_set_zalm3(MODL_VESPERY, "ef1.htm", "CHVAL_EF1");
			break;
		case DEN_UTOROK:
			_set_zalm3(MODL_VESPERY, "zjv4_5.htm", "CHVAL_ZJV45");
			break;
		case DEN_STREDA:
			_set_zalm3(MODL_VESPERY, "kol1.htm", "CHVAL_KOL1");
			break;
		case DEN_STVRTOK:
			_set_zalm3(MODL_VESPERY, "zjv11.htm", "CHVAL_ZJV11");
			break;
		case DEN_PIATOK:
			/* kazdy piatok, ranne chvaly je zalm 51 */
			_set_zalm1(MODL_RANNE_CHVALY, "z51.htm", "ZALM51");
			_set_zalm3(MODL_VESPERY, "zjv15.htm", "CHVAL_ZJV15");
			break;
		case DEN_SOBOTA:
			/* sobota v 1. a 3. tyzdni je zalm 34 */
			if((tyzzal == 1) || (tyzzal == 3)){
				_set_zalm2(MODL_CEZ_DEN_VSETKY, "z34.htm", "ZALM34_I");
				_set_zalm3(MODL_CEZ_DEN_VSETKY, "z34.htm", "ZALM34_II");
			}
			break;
	}/* switch(den) */

	Log("Ôalej nastavujem ûalmy (pre jednotliv˝ t˝ûdeÚ ûalt·ra)...\n");
	/* cast specificka pre kazdy tyzden zaltara */
	switch(tyzzal){
		case 1: /* prvy tyzden zaltara */
			switch(den){
				case DEN_NEDELA:
				/* prve vespery */
					_set_zalm1(MODL_PRVE_VESPERY, "z141.htm", "ZALM141");
					_set_zalm2(MODL_PRVE_VESPERY, "z142.htm", "ZALM142");
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z63.htm", "ZALM63");
					_set_zalm3(MODL_RANNE_CHVALY, "z149.htm", "ZALM149");
				/* modlitba cez den */
				/* druhe vespery */
					_set_zalm2(MODL_VESPERY, "z114.htm", "ZALM114");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z1.htm", "ZALM1");
					_set_zalm2(MODL_POSV_CITANIE, "z2.htm", "ZALM2");
					_set_zalm3(MODL_POSV_CITANIE, "z3.htm", "ZALM3");
					break;

				case DEN_PONDELOK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z5.htm", "ZALM5");
					_set_zalm2(MODL_RANNE_CHVALY, "1krn29.htm", "CHVAL_1KRN29");
					_set_zalm3(MODL_RANNE_CHVALY, "z29.htm", "ZALM29");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z19.htm", "ZALM19,8-15");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z7.htm", "ZALM7_I");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z7.htm", "ZALM7_II");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z11.htm", "ZALM11");
					_set_zalm2(MODL_VESPERY, "z15.htm", "ZALM15");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z6.htm", "ZALM6");
					_set_zalm2(MODL_POSV_CITANIE, "z9.htm", "ZALM9_I");
					_set_zalm3(MODL_POSV_CITANIE, "z9.htm", "ZALM9_II");
					break;

				case DEN_UTOROK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z24.htm", "ZALM24");
					_set_zalm2(MODL_RANNE_CHVALY, "tob13.htm", "CHVAL_TOB13,2-8");
					_set_zalm3(MODL_RANNE_CHVALY, "z33.htm", "ZALM33");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_ALEF");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z13.htm", "ZALM13");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z14.htm", "ZALM14");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z20.htm", "ZALM20");
					_set_zalm2(MODL_VESPERY, "z21.htm", "ZALM21");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z10.htm", "ZALM10_I");
					_set_zalm2(MODL_POSV_CITANIE, "z10.htm", "ZALM10_II");
					_set_zalm3(MODL_POSV_CITANIE, "z12.htm", "ZALM12");
					break;

				case DEN_STREDA:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z36.htm", "ZALM36");
					_set_zalm2(MODL_RANNE_CHVALY, "jdt16.htm", "CHVAL_JDT16");
					_set_zalm3(MODL_RANNE_CHVALY, "z47.htm", "ZALM47");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_BET");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z17.htm", "ZALM17_I");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z17.htm", "ZALM17_II");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z27.htm", "ZALM27_I");
					_set_zalm2(MODL_VESPERY, "z27.htm", "ZALM27_II");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z18.htm", "ZALM18_I");
					_set_zalm2(MODL_POSV_CITANIE, "z18.htm", "ZALM18_II");
					_set_zalm3(MODL_POSV_CITANIE, "z18.htm", "ZALM18_III");
					break;

				case DEN_STVRTOK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z57.htm", "ZALM57");
					_set_zalm2(MODL_RANNE_CHVALY, "jer31.htm", "CHVAL_JER31");
					_set_zalm3(MODL_RANNE_CHVALY, "z48.htm", "ZALM48");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_GIMEL");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z25.htm", "ZALM25_I");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z25.htm", "ZALM25_II");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z30.htm", "ZALM30");
					_set_zalm2(MODL_VESPERY, "z32.htm", "ZALM32");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z18.htm", "ZALM18_IV");
					_set_zalm2(MODL_POSV_CITANIE, "z18.htm", "ZALM18_V");
					_set_zalm3(MODL_POSV_CITANIE, "z18.htm", "ZALM18_VI");
					break;

				case DEN_PIATOK:
				/* ranne chvaly */
					_set_zalm2(MODL_RANNE_CHVALY, "iz45.htm", "CHVAL_IZ45");
					_set_zalm3(MODL_RANNE_CHVALY, "z100.htm", "ZALM100");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_DALET");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z26.htm", "ZALM26");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z28.htm", "ZALM28,1-3.6-9");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z41.htm", "ZALM41");
					_set_zalm2(MODL_VESPERY, "z46.htm", "ZALM46");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z35.htm", "ZALM35_I");
					_set_zalm2(MODL_POSV_CITANIE, "z35.htm", "ZALM35_II");
					_set_zalm3(MODL_POSV_CITANIE, "z35.htm", "ZALM35_III");
					break;

				case DEN_SOBOTA:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z119.htm", "ZALM119_KOF");
					_set_zalm2(MODL_RANNE_CHVALY, "ex15.htm", "CHVAL_EX15");
					_set_zalm3(MODL_RANNE_CHVALY, "z117.htm", "ZALM117");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_HE");
				/* posvatne citanie */
					if(zvazok != 2){
						_set_zalm1(MODL_POSV_CITANIE, "z131.htm", "ZALM131");
						_set_zalm2(MODL_POSV_CITANIE, "z132.htm", "ZALM132_I");
						_set_zalm3(MODL_POSV_CITANIE, "z132.htm", "ZALM132_II");
					}
					else {
						_set_zalm1(MODL_POSV_CITANIE, "z105.htm", "ZALM105_I");
						_set_zalm2(MODL_POSV_CITANIE, "z105.htm", "ZALM105_II");
						_set_zalm3(MODL_POSV_CITANIE, "z105.htm", "ZALM105_III");
					}
					/* 2005-03-27:
					 * Neviem preco tu bolo "z105.htm", "ZALM105_I" az "ZALM105_III"
					 * Mozno z nejakeho ineho obdobia zaltara.
					 * Opravene pre OCR na Z131 a Z132 I-II.
					 *
					 * 2006-01-24:
					 * OdpoveÔ je jednoduch·: II. zv‰zok brevi·ra m· odliönÈ ûalmy.
					 *
					 */
					break;

				default: break;
			}; break; /* case 1 */

		case 2: /* druhy tyzden zaltara */
			switch(den){
				case DEN_NEDELA:
				/* prve vespery */
					_set_zalm1(MODL_PRVE_VESPERY, "z119.htm", "ZALM119_NUN");
					_set_zalm2(MODL_PRVE_VESPERY, "z16.htm", "ZALM16");
				/* ranne chvaly */
				/* modlitba cez den */
				/* druhe vespery */
					_set_zalm2(MODL_VESPERY, "z115.htm", "ZALM115");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z104.htm", "ZALM104_I");
					_set_zalm2(MODL_POSV_CITANIE, "z104.htm", "ZALM104_II");
					_set_zalm3(MODL_POSV_CITANIE, "z104.htm", "ZALM104_III");
					break;

				case DEN_PONDELOK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z42.htm", "ZALM42");
					_set_zalm2(MODL_RANNE_CHVALY, "sir36.htm", "CHVAL_SIR36");
					_set_zalm3(MODL_RANNE_CHVALY, "z19.htm", "ZALM19,2-7");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_VAU");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z40.htm", "ZALM40_I");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z40.htm", "ZALM40_II");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z45.htm", "ZALM45_I");
					_set_zalm2(MODL_VESPERY, "z45.htm", "ZALM45_II");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z31.htm", "ZALM31_I");
					_set_zalm2(MODL_POSV_CITANIE, "z31.htm", "ZALM31_II");
					_set_zalm3(MODL_POSV_CITANIE, "z31.htm", "ZALM31_III");
					break;

				case DEN_UTOROK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z43.htm", "ZALM43");
					_set_zalm2(MODL_RANNE_CHVALY, "iz38.htm", "CHVAL_IZ38");
					_set_zalm3(MODL_RANNE_CHVALY, "z65.htm", "ZALM65");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_ZAJIN");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z53.htm", "ZALM53");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z54.htm", "ZALM54");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z49.htm", "ZALM49_I");
					_set_zalm2(MODL_VESPERY, "z49.htm", "ZALM49_II");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z37.htm", "ZALM37_I");
					_set_zalm2(MODL_POSV_CITANIE, "z37.htm", "ZALM37_II");
					_set_zalm3(MODL_POSV_CITANIE, "z37.htm", "ZALM37_III");
					break;

				case DEN_STREDA:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z77.htm", "ZALM77");
					_set_zalm2(MODL_RANNE_CHVALY, "1sam2.htm", "CHVAL_1SAM2");
					_set_zalm3(MODL_RANNE_CHVALY, "z97.htm", "ZALM97");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_CHET");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z55.htm", "ZALM55_I");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z55.htm", "ZALM55_II");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z62.htm", "ZALM62");
					_set_zalm2(MODL_VESPERY, "z67.htm", "ZALM67");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z39.htm", "ZALM39_I");
					_set_zalm2(MODL_POSV_CITANIE, "z39.htm", "ZALM39_II");
					_set_zalm3(MODL_POSV_CITANIE, "z52.htm", "ZALM52");
					break;

				case DEN_STVRTOK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z80.htm", "ZALM80");
					_set_zalm2(MODL_RANNE_CHVALY, "iz12.htm", "CHVAL_IZ12");
					_set_zalm3(MODL_RANNE_CHVALY, "z81.htm", "ZALM81");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_TET");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z56.htm", "ZALM56");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z57.htm", "ZALM57");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z72.htm", "ZALM72_I");
					_set_zalm2(MODL_VESPERY, "z72.htm", "ZALM72_II");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z44.htm", "ZALM44_I");
					_set_zalm2(MODL_POSV_CITANIE, "z44.htm", "ZALM44_II");
					_set_zalm3(MODL_POSV_CITANIE, "z44.htm", "ZALM44_III");
					break;

				case DEN_PIATOK:
				/* ranne chvaly */
					_set_zalm2(MODL_RANNE_CHVALY, "hab3.htm", "CHVAL_HAB3");
					_set_zalm3(MODL_RANNE_CHVALY, "z147.htm", "ZALM147,12-20");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_JOD");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z59.htm", "ZALM59");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z60.htm", "ZALM60");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z116.htm", "ZALM116,1-9");
					_set_zalm2(MODL_VESPERY, "z121.htm", "ZALM121");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z38.htm", "ZALM38_I");
					_set_zalm2(MODL_POSV_CITANIE, "z38.htm", "ZALM38_II");
					_set_zalm3(MODL_POSV_CITANIE, "z38.htm", "ZALM38_III");
					break;

				case DEN_SOBOTA:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z92.htm", "ZALM92");
					_set_zalm2(MODL_RANNE_CHVALY, "dt32.htm", "CHVAL_DT32");
					_set_zalm3(MODL_RANNE_CHVALY, "z8.htm", "ZALM8");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_KAF");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z61.htm", "ZALM61");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z64.htm", "ZALM64");
				/* posvatne citanie */
					if(zvazok != 2){
						_set_zalm1(MODL_POSV_CITANIE, "z136.htm", "ZALM136_I");
						_set_zalm2(MODL_POSV_CITANIE, "z136.htm", "ZALM136_II_PC");
						_set_zalm3(MODL_POSV_CITANIE, "z136.htm", "ZALM136_III_PC"); /* inak je 136 cleneny pre pondelok 4. tyzdna, vespery */
					}
					else {
						_set_zalm1(MODL_POSV_CITANIE, "z106.htm", "ZALM106_I");
						_set_zalm2(MODL_POSV_CITANIE, "z106.htm", "ZALM106_II");
						_set_zalm3(MODL_POSV_CITANIE, "z106.htm", "ZALM106_III");
					}
					/* 2005-03-27:
					 * Neviem preco tu bolo "z106.htm", "ZALM106_I" az "ZALM106_III"
					 * Mozno z nejakeho ineho obdobia zaltara (podobne sobota v 1. tyzdni).
					 * Opravene pre OCR na Z136 I-III.
					 *
					 * 2006-01-24:
					 * OdpoveÔ je jednoduch·: II. zv‰zok brevi·ra m· odliönÈ ûalmy.
					 *
					 */
					break;

				default: break;
			}; break; /* case 2 */

		case 3: /* treti tyzden zaltara */
			switch(den){
				case DEN_NEDELA:
				/* prve vespery */
					_set_zalm1(MODL_PRVE_VESPERY, "z113.htm", "ZALM113");
					_set_zalm2(MODL_PRVE_VESPERY, "z116.htm", "ZALM116,10-19");
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z93.htm", "ZALM93");
					_set_zalm3(MODL_RANNE_CHVALY, "z148.htm", "ZALM148");
				/* modlitba cez den */
				/* druhe vespery */
					_set_zalm2(MODL_VESPERY, "z111.htm", "ZALM111");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z145.htm", "ZALM145pc_I");
					_set_zalm2(MODL_POSV_CITANIE, "z145.htm", "ZALM145pc_II");
					_set_zalm3(MODL_POSV_CITANIE, "z145.htm", "ZALM145pc_III");
					break;

				case DEN_PONDELOK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z84.htm", "ZALM84");
					_set_zalm2(MODL_RANNE_CHVALY, "iz2.htm", "CHVAL_IZ2");
					_set_zalm3(MODL_RANNE_CHVALY, "z96.htm", "ZALM96");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_LAMED");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z71.htm", "ZALM71_I");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z71.htm", "ZALM71_II");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z123.htm", "ZALM123");
					_set_zalm2(MODL_VESPERY, "z124.htm", "ZALM124");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z50.htm", "ZALM50_I");
					_set_zalm2(MODL_POSV_CITANIE, "z50.htm", "ZALM50_II");
					_set_zalm3(MODL_POSV_CITANIE, "z50.htm", "ZALM50_III");
					break;

				case DEN_UTOROK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z85.htm", "ZALM85");
					_set_zalm2(MODL_RANNE_CHVALY, "iz26.htm", "CHVAL_IZ26");
					_set_zalm3(MODL_RANNE_CHVALY, "z67.htm", "ZALM67");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_MEM");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z74.htm", "ZALM74_I");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z74.htm", "ZALM74_II");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z125.htm", "ZALM125");
					_set_zalm2(MODL_VESPERY, "z131.htm", "ZALM131");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z68.htm", "ZALM68_I");
					_set_zalm2(MODL_POSV_CITANIE, "z68.htm", "ZALM68_II");
					_set_zalm3(MODL_POSV_CITANIE, "z68.htm", "ZALM68_III");
					break;

				case DEN_STREDA:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z86.htm", "ZALM86");
					_set_zalm2(MODL_RANNE_CHVALY, "iz33.htm", "CHVAL_IZ33");
					_set_zalm3(MODL_RANNE_CHVALY, "z98.htm", "ZALM98");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_NUN");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z70.htm", "ZALM70");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z75.htm", "ZALM75");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z126.htm", "ZALM126");
					_set_zalm2(MODL_VESPERY, "z127.htm", "ZALM127");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z89.htm", "ZALM89_I");
					_set_zalm2(MODL_POSV_CITANIE, "z89.htm", "ZALM89_II");
					_set_zalm3(MODL_POSV_CITANIE, "z89.htm", "ZALM89_III");
					break;

				case DEN_STVRTOK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z87.htm", "ZALM87");
					_set_zalm2(MODL_RANNE_CHVALY, "iz40.htm", "CHVAL_IZ40");
					_set_zalm3(MODL_RANNE_CHVALY, "z99.htm", "ZALM99");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_SAMECH");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z79.htm", "ZALM79");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z80.htm", "ZALM80");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z132.htm", "ZALM132_I");
					_set_zalm2(MODL_VESPERY, "z132.htm", "ZALM132_II");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z89.htm", "ZALM89_IV");
					_set_zalm2(MODL_POSV_CITANIE, "z89.htm", "ZALM89_V");
					_set_zalm3(MODL_POSV_CITANIE, "z90.htm", "ZALM90");
					break;

				case DEN_PIATOK:
				/* ranne chvaly */
					_set_zalm2(MODL_RANNE_CHVALY, "jer14.htm", "CHVAL_JER14");
					_set_zalm3(MODL_RANNE_CHVALY, "z100.htm", "ZALM100");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z22.htm", "ZALM22_I");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z22.htm", "ZALM22_II");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z22.htm", "ZALM22_III");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z135.htm", "ZALM135_I");
					_set_zalm2(MODL_VESPERY, "z135.htm", "ZALM135_II");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z69.htm", "ZALM69_I");
					_set_zalm2(MODL_POSV_CITANIE, "z69.htm", "ZALM69_II");
					_set_zalm3(MODL_POSV_CITANIE, "z69.htm", "ZALM69_III");
					break;

				case DEN_SOBOTA:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z119.htm", "ZALM119_KOF");
					_set_zalm2(MODL_RANNE_CHVALY, "mud9.htm", "CHVAL_MUD9");
					_set_zalm3(MODL_RANNE_CHVALY, "z117.htm", "ZALM117");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_AIN");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z107.htm", "ZALM107_I");
					_set_zalm2(MODL_POSV_CITANIE, "z107.htm", "ZALM107_II");
					_set_zalm3(MODL_POSV_CITANIE, "z107.htm", "ZALM107_III");
					break;

				default: break;
			}; break; /* case 3 */

		case 4: /* stvrty tyzden zaltara */
			switch(den){
				case DEN_NEDELA:
				/* prve vespery */
					_set_zalm1(MODL_PRVE_VESPERY, "z122.htm", "ZALM122");
					_set_zalm2(MODL_PRVE_VESPERY, "z130.htm", "ZALM130");
				/* ranne chvaly */
				/* modlitba cez den */
				/* druhe vespery */
					_set_zalm2(MODL_VESPERY, "z112.htm", "ZALM112");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z24.htm", "ZALM24");
					_set_zalm2(MODL_POSV_CITANIE, "z66.htm", "ZALM66_I");
					_set_zalm3(MODL_POSV_CITANIE, "z66.htm", "ZALM66_II");
					break;

				case DEN_PONDELOK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z90.htm", "ZALM90");
					_set_zalm2(MODL_RANNE_CHVALY, "iz42.htm", "CHVAL_IZ42");
					_set_zalm3(MODL_RANNE_CHVALY, "z135.htm", "ZALM135,1-12");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_PE");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z82.htm", "ZALM82");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z120.htm", "ZALM120");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z136.htm", "ZALM136_I");
					_set_zalm2(MODL_VESPERY, "z136.htm", "ZALM136_II"); /* inak je 136 cleneny pre sobotu 2. tyzdna, posvatne citanie */
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z73.htm", "ZALM73_I");
					_set_zalm2(MODL_POSV_CITANIE, "z73.htm", "ZALM73_II");
					_set_zalm3(MODL_POSV_CITANIE, "z73.htm", "ZALM73_III");
					break;

				case DEN_UTOROK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z101.htm", "ZALM101");
					_set_zalm2(MODL_RANNE_CHVALY, "dan3_26.htm", "CHVAL_DAN3,26");
					_set_zalm3(MODL_RANNE_CHVALY, "z144.htm", "ZALM144,1-10");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_SADE");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z88.htm", "ZALM88_I");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z88.htm", "ZALM88_II");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z137.htm", "ZALM137");
					_set_zalm2(MODL_VESPERY, "z138.htm", "ZALM138");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z102.htm", "ZALM102_I");
					_set_zalm2(MODL_POSV_CITANIE, "z102.htm", "ZALM102_II");
					_set_zalm3(MODL_POSV_CITANIE, "z102.htm", "ZALM102_III");
					break;

				case DEN_STREDA:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z108.htm", "ZALM108");
					_set_zalm2(MODL_RANNE_CHVALY, "iz61.htm", "CHVAL_IZ61");
					_set_zalm3(MODL_RANNE_CHVALY, "z146.htm", "ZALM146");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_KOF");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z94.htm", "ZALM94_I");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z94.htm", "ZALM94_II");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z139.htm", "ZALM139_I");
					_set_zalm2(MODL_VESPERY, "z139.htm", "ZALM139_II");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z103.htm", "ZALM103_I");
					_set_zalm2(MODL_POSV_CITANIE, "z103.htm", "ZALM103_II");
					_set_zalm3(MODL_POSV_CITANIE, "z103.htm", "ZALM103_III");
					break;

				case DEN_STVRTOK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z143.htm", "ZALM143");
					_set_zalm2(MODL_RANNE_CHVALY, "iz66.htm", "CHVAL_IZ66");
					_set_zalm3(MODL_RANNE_CHVALY, "z147.htm", "ZALM147,1-11");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_RES");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z128.htm", "ZALM128");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z129.htm", "ZALM129");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z144.htm", "ZALM144_I");
					_set_zalm2(MODL_VESPERY, "z144.htm", "ZALM144_II");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z44.htm", "ZALM44_I");
					_set_zalm2(MODL_POSV_CITANIE, "z44.htm", "ZALM44_II");
					_set_zalm3(MODL_POSV_CITANIE, "z44.htm", "ZALM44_III");
					break;

				case DEN_PIATOK:
				/* ranne chvaly */
					_set_zalm2(MODL_RANNE_CHVALY, "tob13.htm", "CHVAL_TOB13,8-11");
					_set_zalm3(MODL_RANNE_CHVALY, "z147.htm", "ZALM147,12-20");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_SIN");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z133.htm", "ZALM133");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z140.htm", "ZALM140");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z145.htm", "ZALM145_I");
					_set_zalm2(MODL_VESPERY, "z145.htm", "ZALM145_II");
				/* posvatne citanie */
					if(zvazok != 2){
						_set_zalm1(MODL_POSV_CITANIE, "z55.htm", "ZALM55_I_PC");
						_set_zalm2(MODL_POSV_CITANIE, "z55.htm", "ZALM55_II_PC");
						_set_zalm3(MODL_POSV_CITANIE, "z55.htm", "ZALM55_III_PC"); /* inak clenene pre modlitbu cez den, streda v 2. tyzdni */ 
					}
					else {
						_set_zalm1(MODL_POSV_CITANIE, "z78.htm", "ZALM78_I");
						_set_zalm2(MODL_POSV_CITANIE, "z78.htm", "ZALM78_II");
						_set_zalm3(MODL_POSV_CITANIE, "z78.htm", "ZALM78_III");
					}
					/* 2005-03-27:
					 * Neviem preco tu bolo "z78.htm", "ZALM78_I" az "ZALM78_III"
					 * Mozno z nejakeho ineho obdobia zaltara (podobne sobota v 1. a 2. tyzdni).
					 * Opravene pre OCR na Z55 I-III.
					 *
					 * 2006-01-24:
					 * OdpoveÔ je jednoduch·: II. zv‰zok brevi·ra m· odliönÈ ûalmy.
					 *
					 */
					break;

				case DEN_SOBOTA:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z92.htm", "ZALM92");
					_set_zalm2(MODL_RANNE_CHVALY, "ez36.htm", "CHVAL_EZ36");
					_set_zalm3(MODL_RANNE_CHVALY, "z8.htm", "ZALM8");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_TAU");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z45.htm", "ZALM45_I");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z45.htm", "ZALM45_II");
				/* posvatne citanie */
					if(zvazok != 2){
						_set_zalm1(MODL_POSV_CITANIE, "z50.htm", "ZALM50_I");
						_set_zalm2(MODL_POSV_CITANIE, "z50.htm", "ZALM50_II");
						_set_zalm3(MODL_POSV_CITANIE, "z50.htm", "ZALM50_III");
					}
					else {
						_set_zalm1(MODL_POSV_CITANIE, "z78.htm", "ZALM78_IV");
						_set_zalm2(MODL_POSV_CITANIE, "z78.htm", "ZALM78_V");
						_set_zalm3(MODL_POSV_CITANIE, "z78.htm", "ZALM78_VI");
					}
					/* 2005-03-27:
					 * Neviem preco tu bolo "z78.htm", "ZALM78_IV" az "ZALM78_VI"
					 * Mozno z nejakeho ineho obdobia zaltara (podobne sobota v 1. a 2. tyzdni a piatok vo 4. tyzdni, posv. citanie).
					 * Opravene pre OCR na Z55 I-III.
					 *
					 * 2006-01-24:
					 * OdpoveÔ je jednoduch·: II. zv‰zok brevi·ra m· odliönÈ ûalmy.
					 *
					 */
					break;

				default: break;
			}; break; /* case 4 */

	}/* switch(tyzzal) */

	/* nasledujuca pasaz pridana 2003-08-13 */
	Log("napokon idem pre modlitbu cez deÚ skontrolovaù, Ëi netreba braù doplnkov˙ psalmÛdiu...\n");
	if(_global_opt5 == MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA){
		Log("\t·no, beriem doplnkov˙ psalmÛdiu.\n");
		_set_zalm_cez_den_doplnkova_psalmodia();
		/* 2006-01-24: vyÚatÈ do samostatnej funkcie */
	}/* _global_opt5 == MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA */
	else{
		/* 2006-02-07: doplnenÈ */
		Log("\tnie, doplnkov˙ psalmÛdiu neberiem.\n");
	}
	Log("-- zaltar_zvazok(%d, %d, %d, %d) -- koniec\n", den, tyzzal, obdobie, specialne);
}/* zaltar_zvazok(); */

void zaltar(short int den, short int tyzzal){
	/* 2006-01-24: kvÙli sp‰tnej kompatibilite ponechan· aj funkcia s 2 parametrami */
	Log("-- zaltar(%d, %d) -- zaciatok\n", den, tyzzal);
	zaltar_zvazok(den, tyzzal, OBD_CEZ_ROK, ZALTAR_VSETKO);
	Log("-- zaltar(%d, %d) -- koniec\n", den, tyzzal);
}/* zaltar(); */

/* 2006-01-26: pridanÈ posv. ËÌtanie a modlitba cez deÚ */
void _set_zalmy_velky_piatok(short int modlitba){
	Log("_set_zalmy_velky_piatok(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z116.htm", "ZALM116,10-19");
		_set_zalm2(modlitba, "z143.htm", "ZALM143");
		_set_zalm3(modlitba, "flp2.htm", "CHVAL_FLP2");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		/* zalmy z piatka 2. tyzdna zaltara */
		Log("zalmy su z piatka 2. tyzdna zaltara...\n");
	}
	/* 2006-01-26: doplnenÈ ûalmy pre posv. ËÌtanie */
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z2.htm", "ZALM2");
		_set_zalm2(modlitba, "z22.htm", "ZALM22_CELY");
		_set_zalm3(modlitba, "z38.htm", "ZALM38_CELY");
	}
	/* 2006-01-26: doplnenÈ ûalmy pre modlitbu cez deÚ */
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalm1(modlitba, "z40.htm", "ZALM40");
		_set_zalm2(modlitba, "z54.htm", "ZALM54");
		_set_zalm3(modlitba, "z88.htm", "ZALM88");
	}
	Log("_set_zalmy_velky_piatok(%s) -- end\n", nazov_modlitby(modlitba));
}
/* 2006-01-26: pridanÈ posv. ËÌtanie a modlitba cez deÚ */
void _set_zalmy_biela_sobota(short int modlitba){
	Log("_set_zalmy_biela_sobota(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z116.htm", "ZALM116,10-19");
		_set_zalm2(modlitba, "z143.htm", "ZALM143");
		_set_zalm3(modlitba, "flp2.htm", "CHVAL_FLP2");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalm1(modlitba, "z64.htm", "ZALM64");
		_set_zalm2(modlitba, "iz38.htm", "CHVAL_IZ38");
		_set_zalm3(modlitba, "z150.htm", "ZALM150");
	}
	/* 2006-01-26: doplnenÈ ûalmy pre posv. ËÌtanie */
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z4.htm", "ZALM4");
		_set_zalm2(modlitba, "z16.htm", "ZALM16");
		_set_zalm3(modlitba, "z24.htm", "ZALM24");
	}
	/* 2006-01-26: doplnenÈ ûalmy pre modlitbu cez deÚ */
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalm1(modlitba, "z27.htm", "ZALM27");
		_set_zalm2(modlitba, "z30.htm", "ZALM30");
		_set_zalm3(modlitba, "z76.htm", "ZALM76");
	}
	Log("_set_zalmy_biela_sobota(%s) -- end\n", nazov_modlitby(modlitba));
}

void _set_zalmy_za_zosnulych(short int modlitba){
	Log("_set_zalmy_za_zosnulych(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z121.htm", "ZALM121");
		_set_zalm2(modlitba, "z130.htm", "ZALM130");
		_set_zalm3(modlitba, "flp2.htm", "CHVAL_FLP2");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalm1(modlitba, "z51.htm", "ZALM51");
		_set_zalm2(modlitba, "iz38.htm", "CHVAL_IZ38");
		if(_global_den.tyzden MOD 2 == 0)
			_set_zalm3(modlitba, "z146.htm", "ZALM146");
		else
			_set_zalm3(modlitba, "z150.htm", "ZALM150");
	}
	/* 2006-02-04: doplnenÈ ûalmy pre posv. ËÌtanie a pre modlitbu cez deÚ */
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z40.htm", "ZALM40_I");
		_set_zalm2(modlitba, "z40.htm", "ZALM40_II");
		_set_zalm3(modlitba, "z42.htm", "ZALM42");
	}
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalm1(modlitba, "z70.htm", "ZALM70");
		_set_zalm2(modlitba, "z85.htm", "ZALM85");
		_set_zalm3(modlitba, "z86.htm", "ZALM86");
	}
	Log("_set_zalmy_za_zosnulych(%s) -- end\n", nazov_modlitby(modlitba));
}

void _set_zalmy_1nedele_rch(void){/* ranne chvaly */
	Log("_set_zalmy_1nedele_rch() -- begin\n");
	_set_zalm1(MODL_RANNE_CHVALY, "z63.htm", "ZALM63");
	_set_zalm2(MODL_RANNE_CHVALY, "dan3_57.htm", "DAN3,57-88.56");
	_set_zalm3(MODL_RANNE_CHVALY, "z149.htm", "ZALM149");
	Log("_set_zalmy_1nedele_rch() -- end\n");
}

void _set_zalmy_1nedele_v(void){/* vespery */
	Log("_set_zalmy_1nedele_v() -- begin\n");
	_set_zalm1(MODL_VESPERY, "z110.htm", "ZALM110");
	_set_zalm2(MODL_VESPERY, "z114.htm", "ZALM114");
	_set_zalm3(MODL_VESPERY, "zjv19.htm", "CHVAL_ZJV19");
	Log("_set_zalmy_1nedele_v() -- end\n");
}

void _set_zalmy_1nedele_1v(void){/* prve vespery */
	Log("_set_zalmy_1nedele_v() -- begin\n");
	_set_zalm1(MODL_PRVE_VESPERY, "z141.htm", "ZALM141");
	_set_zalm2(MODL_PRVE_VESPERY, "z142.htm", "ZALM142");
	_set_zalm3(MODL_PRVE_VESPERY, "flp2.htm", "CHVAL_FLP2");
	Log("_set_zalmy_1nedele_v() -- end\n");
}

/* 2006-01-24: pridanÈ ûalmy nedele 1. t˝ûdÚa kvÙli modlitbe cez deÚ */
void _set_zalmy_1nedele_mcd(void){/* prve vespery */
	Log("_set_zalmy_1nedele_mcd() -- begin\n");
	/* modlitba cez den */
	_set_zalm1(MODL_CEZ_DEN_VSETKY, "z118.htm", "ZALM118_I");
	_set_zalm2(MODL_CEZ_DEN_VSETKY, "z118.htm", "ZALM118_II");
	_set_zalm3(MODL_CEZ_DEN_VSETKY, "z118.htm", "ZALM118_III");
	Log("_set_zalmy_1nedele_mcd() -- end\n");
}

/* 2006-01-26: pridanÈ ûalmy nedele 1. t˝ûdÚa kvÙli posv. ËÌtaniam (napr. druh· nedeæa vo veæk. okt·ve) */
void _set_zalmy_1nedele_pc(void){/* prve vespery */
	Log("_set_zalmy_1nedele_pc() -- begin\n");
	/* modlitba cez den */
	_set_zalm1(MODL_POSV_CITANIE, "z1.htm", "ZALM1");
	_set_zalm2(MODL_POSV_CITANIE, "z2.htm", "ZALM2");
	_set_zalm3(MODL_POSV_CITANIE, "z3.htm", "ZALM3");
	Log("_set_zalmy_1nedele_pc() -- end\n");
}

/* 2006-01-26: pridanÈ ûalmy pre posv‰tnÈ ËÌtania veækonoËnÈho t˝ûdÚa */
void _set_zalmy_velk_oktava(short int den, short int modlitba){
	Log("_set_zalmy_velk_oktava(%d, %s) -- begin\n", den, nazov_modlitby(modlitba));
	if(modlitba == MODL_POSV_CITANIE){
		/* posv‰tnÈ ËÌtanie */
		switch(den){
			case DEN_NEDELA: /* 2006-01-26: v podstate len pre druh˙ nedeæu vo veækonoËnej okt·ve */
			case DEN_PONDELOK:
				_set_zalm1(modlitba, "z1.htm", "ZALM1");
				_set_zalm2(modlitba, "z2.htm", "ZALM2");
				_set_zalm3(modlitba, "z3.htm", "ZALM3");
				break;
			case DEN_UTOROK:
				_set_zalm1(modlitba, "z24.htm", "ZALM24");
				_set_zalm2(modlitba, "z66.htm", "ZALM66_I");
				_set_zalm3(modlitba, "z66.htm", "ZALM66_II");
				break;
			case DEN_STREDA:
				_set_zalm1(modlitba, "z104.htm", "ZALM104_I");
				_set_zalm2(modlitba, "z104.htm", "ZALM104_II");
				_set_zalm3(modlitba, "z104.htm", "ZALM104_III");
				break;
			case DEN_STVRTOK:
				_set_zalm1(modlitba, "z118.htm", "ZALM118_I");
				_set_zalm2(modlitba, "z118.htm", "ZALM118_II");
				_set_zalm3(modlitba, "z118.htm", "ZALM118_III");
				break;
			case DEN_PIATOK:
				_set_zalm1(modlitba, "z136.htm", "ZALM136_I");
				_set_zalm2(modlitba, "z136.htm", "ZALM136_II_PC");
				_set_zalm3(modlitba, "z136.htm", "ZALM136_III_PC");
				break;
			case DEN_SOBOTA:
				_set_zalm1(modlitba, "z145.htm", "ZALM145pc_I");
				_set_zalm2(modlitba, "z145.htm", "ZALM145pc_II");
				_set_zalm3(modlitba, "z145.htm", "ZALM145pc_III");
				break;
		}/* switch(den) */
	}
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		/* modlitba cez deÚ */
		switch(den){
			case DEN_NEDELA:
				_set_zalm1(MODL_CEZ_DEN_VSETKY, "z118.htm", "ZALM118_I");
				_set_zalm2(MODL_CEZ_DEN_VSETKY, "z118.htm", "ZALM118_II");
				_set_zalm3(MODL_CEZ_DEN_VSETKY, "z118.htm", "ZALM118_III");
				break;
			case DEN_PONDELOK:
				_set_zalm1(MODL_CEZ_DEN_VSETKY, "z8.htm", "ZALM8");
				_set_zalm2(MODL_CEZ_DEN_VSETKY, "z19.htm", "ZALM19_I");
				_set_zalm3(MODL_CEZ_DEN_VSETKY, "z19.htm", "ZALM19_II");
				break;
			case DEN_UTOROK:
				_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_ALEF");
				_set_zalm2(MODL_CEZ_DEN_VSETKY, "z16.htm", "ZALM16");
				_set_zalm3(MODL_CEZ_DEN_VSETKY, "z23.htm", "ZALM23");
				break;
			case DEN_STREDA:
				_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_BET");
				_set_zalm2(MODL_CEZ_DEN_VSETKY, "z28.htm", "ZALM28,1-3.6-9");
				_set_zalm3(MODL_CEZ_DEN_VSETKY, "z116.htm", "ZALM116,10-19");
				break;
			case DEN_STVRTOK:
				_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_GIMEL");
				_set_zalm2(MODL_CEZ_DEN_VSETKY, "z30.htm", "ZALM30_I");
				_set_zalm3(MODL_CEZ_DEN_VSETKY, "z30.htm", "ZALM30_II");
				break;
			case DEN_PIATOK:
				_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_DALET");
				_set_zalm2(MODL_CEZ_DEN_VSETKY, "z76.htm", "ZALM76_I");
				_set_zalm3(MODL_CEZ_DEN_VSETKY, "z76.htm", "ZALM76_II");
				break;
			case DEN_SOBOTA:
				_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_HE");
				_set_zalm2(MODL_CEZ_DEN_VSETKY, "z96.htm", "ZALM96_I");
				_set_zalm3(MODL_CEZ_DEN_VSETKY, "z96.htm", "ZALM96_II");
				break;
		}/* switch(den) */
	}
	Log("_set_zalmy_velk_oktava(%d, %s) -- end\n", den, nazov_modlitby(modlitba));
}/* _set_zalmy_velk_oktava */

/* 2006-02-04: pridanÈ ûalmy pre posv‰tnÈ ËÌtania vianoËnej okt·vy okrem narodenia P·na */
void _set_zalmy_vian_oktava(short int den, short int modlitba){
	Log("_set_zalmy_vian_oktava(%d, %s) -- begin\n", den, nazov_modlitby(modlitba));
	if(modlitba == MODL_POSV_CITANIE){
		/* posv‰tnÈ ËÌtanie */
		switch(den){
			case 25:
				_set_zalm1(modlitba, "z2.htm", "ZALM2");
				_set_zalm2(modlitba, "z19.htm", "ZALM19,2-7");
				_set_zalm3(modlitba, "z45.htm", "ZALM45");
				break;
			case 29:
				_set_zalm1(modlitba, "z46.htm", "ZALM46");
				_set_zalm2(modlitba, "z72.htm", "ZALM72_I");
				_set_zalm3(modlitba, "z72.htm", "ZALM72_II");
				break;
			case 30:
				_set_zalm1(modlitba, "z85.htm", "ZALM85");
				_set_zalm2(modlitba, "z89.htm", "ZALM89_I_30DEC");
				_set_zalm3(modlitba, "z89.htm", "ZALM89_II_30DEC");
				break;
			case 31:
				_set_zalm1(modlitba, "z96.htm", "ZALM96");
				_set_zalm2(modlitba, "z97.htm", "ZALM97");
				_set_zalm3(modlitba, "z98.htm", "ZALM98");
				break;
			case 1:
				_set_zalm1(modlitba, "z24.htm", "ZALM24");
				_set_zalm2(modlitba, "z87.htm", "ZALM87");
				_set_zalm3(modlitba, "z99.htm", "ZALM99");
				break;
		}/* switch(den) */
	}
	Log("_set_zalmy_vian_oktava(%d, %s) -- end\n", den, nazov_modlitby(modlitba));
}/* _set_zalmy_vian_oktava */

void _set_zalmy_posviacka_chramu(short int modlitba){
	Log("_set_zalmy_posviacka_chramu(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z46.htm", "ZALM46");
		_set_zalm2(modlitba, "z122.htm", "ZALM122");
		if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN))
			_set_zalm3(modlitba, "zjv15.htm", "CHVAL_ZJV15");
		else
			_set_zalm3(modlitba, "zjv19.htm", "CHVAL_ZJV19");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z147.htm", "ZALM147,1-11");
		_set_zalm2(modlitba, "z147.htm", "ZALM147,12-20");
		if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN))
			_set_zalm3(modlitba, "kol1.htm", "CHVAL_KOL1");
		else
			_set_zalm3(modlitba, "zjv19.htm", "CHVAL_ZJV19");
	}
	/* 2006-02-04: doplnenÈ ûalmy pre posv. ËÌtanie a pre modlitbu cez deÚ */
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z24.htm", "ZALM24");
		_set_zalm2(modlitba, "z84.htm", "ZALM84");
		_set_zalm3(modlitba, "z87.htm", "ZALM87");
	}
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalm_cez_den_doplnkova_psalmodia();
	}
	Log("_set_zalmy_posviacka_chramu(%s) -- end\n", nazov_modlitby(modlitba));
}

void _set_zalmy_velkonocna_nedela(short int modlitba){
	Log("_set_zalmy_velkonocna_nedela(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalmy_1nedele_v();
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalmy_1nedele_1v();
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	/* 2006-01-26: pridanÈ posv‰tnÈ ËÌtanie a modlitba cez deÚ */
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalmy_1nedele_pc();
	}
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalmy_1nedele_mcd();
	}
	Log("_set_zalmy_velkonocna_nedela(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2006-01-27: doplnenÈ posv. ËÌtanie a modlitba cez deÚ */
void _set_zalmy_nanebovstupenie(short int modlitba){
	Log("_set_zalmy_nanebovstupenie(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z47.htm", "ZALM47");
		_set_zalm3(modlitba, "zjv11.htm", "CHVAL_ZJV11");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z117.htm", "ZALM117");
		_set_zalm3(modlitba, "zjv11.htm", "CHVAL_ZJV11");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	/* 2006-01-27: pridanÈ posv‰tnÈ ËÌtanie a modlitba cez deÚ */
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z68.htm", "ZALM68_I");
		_set_zalm2(modlitba, "z68.htm", "ZALM68_II");
		_set_zalm3(modlitba, "z68.htm", "ZALM68_III");
	}
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalm1(modlitba, "z8.htm", "ZALM8");
		_set_zalm2(modlitba, "z19.htm", "ZALM19_I");
		_set_zalm3(modlitba, "z19.htm", "ZALM19_II");
	}
	Log("_set_zalmy_nanebovstupenie(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2006-01-27: doplnenÈ posv. ËÌtanie a modlitba cez deÚ */
void _set_zalmy_zoslanie_ducha_sv(short int modlitba){
	Log("_set_zalmy_zoslanie_ducha_sv(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z114.htm", "ZALM114");
		_set_zalm3(modlitba, "zjv19.htm", "CHVAL_ZJV19");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z147.htm", "ZALM147,1-11");
		_set_zalm3(modlitba, "zjv15.htm", "CHVAL_ZJV15");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	/* 2006-01-27: pridanÈ posv‰tnÈ ËÌtanie a modlitba cez deÚ */
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z104.htm", "ZALM104_I");
		_set_zalm2(modlitba, "z104.htm", "ZALM104_II");
		_set_zalm3(modlitba, "z104.htm", "ZALM104_III");
	}
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalmy_1nedele_mcd();
	}
	Log("_set_zalmy_zoslanie_ducha_sv(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2006-01-24: pridanÈ posv. ËÌtanie a modlitba cez deÚ */
void _set_zalmy_najsv_trojice(short int modlitba){
	Log("_set_zalmy_najsv_trojice(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z114.htm", "ZALM114");
		_set_zalm3(modlitba, "zjv19.htm", "CHVAL_ZJV19");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z147.htm", "ZALM147,12-20");
		_set_zalm3(modlitba, "ef1.htm", "CHVAL_EF1");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z8.htm", "ZALM8");
		_set_zalm2(modlitba, "z33.htm", "ZALM33_I");
		_set_zalm3(modlitba, "z33.htm", "ZALM33_II");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	/* 2006-01-24: doplnenÈ ûalmy pre modlitbu cez deÚ */
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalmy_1nedele_mcd();
	}
	Log("_set_zalmy_najsv_trojice(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2006-01-24: pridan· modlitba cez deÚ */
void _set_zalmy_krista_krala(short int modlitba){
	Log("_set_zalmy_krista_krala(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z145.htm", "ZALM145,1-13");
		_set_zalm3(modlitba, "zjv19.htm", "CHVAL_ZJV19");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z117.htm", "ZALM117");
		_set_zalm3(modlitba, "zjv4_5.htm", "CHVAL_ZJV45");
	}
	/* 2005-08-12: doplnenÈ ûalmy na posv‰tnÈ ËÌtanie */
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z2.htm", "ZALM2");
		_set_zalm2(modlitba, "z72.htm", "ZALM72_I");
		_set_zalm3(modlitba, "z72.htm", "ZALM72_II");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	/* 2006-01-24: doplnenÈ ûalmy pre modlitbu cez deÚ */
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalmy_1nedele_mcd();
	}
	Log("_set_zalmy_krista_krala(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2006-01-24: pridanÈ posv. ËÌtanie a modlitba cez deÚ */
void _set_zalmy_telakrvi(short int modlitba){
	Log("_set_zalmy_telakrvi(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z116.htm", "ZALM116,10-19");
		_set_zalm3(modlitba, "zjv19.htm", "CHVAL_ZJV19");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z111.htm", "ZALM111");
		_set_zalm2(modlitba, "z147.htm", "ZALM147,12-20");
		_set_zalm3(modlitba, "zjv11.htm", "CHVAL_ZJV11");
	}
	/* 2006-01-24: doplnenÈ ûalmy na posv‰tnÈ ËÌtanie */
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z23.htm", "ZALM23");
		_set_zalm2(modlitba, "z42.htm", "ZALM42");
		_set_zalm3(modlitba, "z81.htm", "ZALM81");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	/* 2006-01-24: doplnenÈ ûalmy pre modlitbu cez deÚ */
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalm_cez_den_doplnkova_psalmodia();
	}
	Log("_set_zalmy_telakrvi(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2006-01-24: pridanÈ posv. ËÌtanie a modlitba cez deÚ */
void _set_zalmy_srdca(short int modlitba){
	Log("_set_zalmy_srdca(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z111.htm", "ZALM111");
		_set_zalm3(modlitba, "flp2.htm", "CHVAL_FLP2");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z146.htm", "ZALM146");
		_set_zalm3(modlitba, "zjv4_5.htm", "CHVAL_ZJV45");
	}
	/* 2006-01-24: doplnenÈ ûalmy na posv‰tnÈ ËÌtanie */
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z36.htm", "ZALM36");
		_set_zalm2(modlitba, "z61.htm", "ZALM61");
		_set_zalm3(modlitba, "z98.htm", "ZALM98");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	/* 2006-01-24: doplnenÈ ûalmy pre modlitbu cez deÚ */
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalm_cez_den_doplnkova_psalmodia();
	}
	Log("_set_zalmy_srdca(%s) -- end\n", nazov_modlitby(modlitba));
}
/* 2006-02-04: pridanÈ posv‰tnÈ ËÌtanie a mcd */
void _set_zalmy_narodenie(short int modlitba){
	Log("_set_zalmy_narodenie(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z130.htm", "ZALM130");
		_set_zalm3(modlitba, "kol1.htm", "CHVAL_KOL1");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z147.htm", "ZALM147,12-20");
		_set_zalm3(modlitba, "flp2.htm", "CHVAL_FLP2");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z2.htm", "ZALM2");
		_set_zalm2(modlitba, "z19.htm", "ZALM19,2-7");
		_set_zalm3(modlitba, "z45.htm", "ZALM45");
	}
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalm1(modlitba, "z19.htm", "ZALM19,8-15");
		_set_zalm2(modlitba, "z47.htm", "ZALM47");
		_set_zalm3(modlitba, "z48.htm", "ZALM48");
	}
	Log("_set_zalmy_narodenie(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2006-01-24: pridanÈ posv. ËÌtania (2006-02-04 doplnenÈ naozajstnÈ ˙daje) */
void _set_zalmy_zjv(short int modlitba){
	Log("_set_zalmy_zjv(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z112.htm", "ZALM112");
		_set_zalm3(modlitba, "zjv15.htm", "CHVAL_ZJV15");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z135.htm", "ZALM135_I");
		_set_zalm2(modlitba, "z135.htm", "ZALM135_II");
		_set_zalm3(modlitba, "1tim3.htm", "CHVAL_1TIM3");
	}
/* 2006-02-04: pridanÈ ûalmy na posv‰tnÈ ËÌtania a modlitbu cez deÚ */
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z72.htm", "ZALM72");
		_set_zalm2(modlitba, "z96.htm", "ZALM96");
		_set_zalm3(modlitba, "z97.htm", "ZALM97");
	}
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalm1(modlitba, "z47.htm", "ZALM47");
		_set_zalm2(modlitba, "z86.htm", "ZALM86,1-10");
		_set_zalm3(modlitba, "z98.htm", "ZALM98");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	Log("_set_zalmy_zjv(%s) -- end\n", nazov_modlitby(modlitba));
}

void _set_zalmy_premenenie(short int modlitba){
	Log("_set_zalmy_premenenie(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z121.htm", "ZALM121");
		_set_zalm3(modlitba, "1tim3.htm", "CHVAL_1TIM3");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z117.htm", "ZALM117");
		_set_zalm3(modlitba, "zjv19.htm", "CHVAL_ZJV19");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		/* 2005-08-02: pridanÈ posv‰tnÈ ËÌtanie */
		_set_zalm1(modlitba, "z84.htm", "ZALM84");
		_set_zalm2(modlitba, "z97.htm", "ZALM97");
		_set_zalm3(modlitba, "z99.htm", "ZALM99");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	/* 2006-01-24: modlitba cez deÚ: ûalmy s˙ z beûnÈho dÚa */
	Log("_set_zalmy_premenenie(%s) -- end\n", nazov_modlitby(modlitba));
}

/* vespery a posv. citanie */
void _set_zalmy_sviatok_apostolov(short int modlitba){
	Log("_set_zalmy_sviatok_apostolov(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z116.htm", "ZALM116,10-19");
		_set_zalm2(modlitba, "z126.htm", "ZALM126");
		_set_zalm3(modlitba, "ef1.htm", "CHVAL_EF1");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z117.htm", "ZALM117");
		_set_zalm2(modlitba, "z147.htm", "ZALM147,12-20");
		_set_zalm3(modlitba, "ef1.htm", "CHVAL_EF1");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z19.htm", "ZALM19,2-7");
		_set_zalm2(modlitba, "z64.htm", "ZALM64");
		_set_zalm3(modlitba, "z97.htm", "ZALM97");
	}
	Log("_set_zalmy_sviatok_apostolov(%s) -- end\n", nazov_modlitby(modlitba));
}

void _set_zalmy_sviatok_duch_past(short int modlitba){
	Log("_set_zalmy_sviatok_duch_past(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z15.htm", "ZALM15");
		_set_zalm2(modlitba, "z112.htm", "ZALM112");
		_set_zalm3(modlitba, "zjv15.htm", "CHVAL_ZJV15");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z146.htm", "ZALM146");
		_set_zalm3(modlitba, "ef1.htm", "CHVAL_EF1");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z21.htm", "ZALM21");
		_set_zalm2(modlitba, "z92.htm", "ZALM92_I");
		_set_zalm3(modlitba, "z92.htm", "ZALM92_II");
	}
	Log("_set_zalmy_sviatok_duch_past(%s) -- end\n", nazov_modlitby(modlitba));
}

void _set_zalmy_sviatok_panien(short int modlitba){
	Log("_set_zalmy_sviatok_panien(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z122.htm", "ZALM122");
		_set_zalm2(modlitba, "z127.htm", "ZALM127");
		_set_zalm3(modlitba, "ef1.htm", "CHVAL_EF1");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z147.htm", "ZALM147,12-20");
		_set_zalm3(modlitba, "ef1.htm", "CHVAL_EF1");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z19.htm", "ZALM19,2-7");
		_set_zalm2(modlitba, "z45.htm", "ZALM45_I");
		_set_zalm3(modlitba, "z45.htm", "ZALM45_II");
	}
	Log("_set_zalmy_sviatok_panien(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2005-07-22: Sviatky Panny M·rie maj˙ pre rannÈ chv·ly a veöpery rovnakÈ ûalmy ako 
 * sviatky panien, ale pre posv‰tnÈ ËÌtania s˙ inÈ ûalmy.
 */
void _set_zalmy_sviatok_marie(short int modlitba){
	Log("_set_zalmy_sviatok_marie(%s) -- begin\n", nazov_modlitby(modlitba));
	if((modlitba == MODL_VESPERY) || (modlitba == MODL_PRVE_VESPERY)){
		_set_zalmy_sviatok_panien(modlitba);
	}
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z24.htm", "ZALM24");
		_set_zalm2(modlitba, "z46.htm", "ZALM46");
		_set_zalm3(modlitba, "z87.htm", "ZALM87");
	}
	Log("_set_zalmy_sviatok_marie(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2006-02-04: Sviatok sv. J·na apoötola-evanjelistu m· pre posv‰tnÈ ËÌtania s˙ inÈ ûalmy
 *             (namiesto 3. ûalmu 97 m· é 99)
 */
void _set_zalmy_sviatok_jana_ap(short int modlitba){
	Log("_set_zalmy_sviatok_jana_ap(%s) -- begin\n", nazov_modlitby(modlitba));
	/* 2006-02-04: nem· ani prvÈ veöpery ani "norm·lne" veöpery */
	if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z19.htm", "ZALM19,2-7");
		_set_zalm2(modlitba, "z64.htm", "ZALM64");
		_set_zalm3(modlitba, "z99.htm", "ZALM99");
	}
	Log("_set_zalmy_sviatok_jana_ap(%s) -- end\n", nazov_modlitby(modlitba));
}

void _set_zalmy_sviatok_muc(short int modlitba){
	Log("_set_zalmy_sviatok_muc(%s) (pre jednÈho muËenÌka resp. spoloËnÈ) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z116.htm", "ZALM116,1-9");
		_set_zalm2(modlitba, "z116.htm", "ZALM116,10-19");
		_set_zalm3(modlitba, "zjv4_5.htm", "CHVAL_ZJV45");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		/* 2003-08-13, nebolo v z118.htm anchor ZALM118_I resp. II;
		 * je tam ine rozdelenie ako pre ucely modlitby cez den
		 * (napr. nedela 1. tyzdna zaltara), preto som to prerobil
		 */
		_set_zalm1(modlitba, "z118.htm", "ZALM118_muc_I");
		_set_zalm2(modlitba, "z118.htm", "ZALM118_muc_II");
		_set_zalm3(modlitba, "1pt2.htm", "CHVAL_1PT2");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z2.htm", "ZALM2");
		/* viacero muË.:  ZALM33_I, ZALM33_2 - rieöenÌ osobitne
		 * jeden muËenÌk: ZALM11, ZALM17
		 */
		_set_zalm2(modlitba, "z11.htm", "ZALM11");
		_set_zalm3(modlitba, "z17.htm", "ZALM17");
	}
	Log("_set_zalmy_sviatok_muc(%s) (pre jednÈho muËenÌka resp. spoloËnÈ) -- end\n", nazov_modlitby(modlitba));
}

/* 2005-07-22: Doroben· funkËnosù pre odliönÈ ûalmy pre jednÈho resp. viacer˝ch muËenÌkov */
void _set_zalmy_sviatok_muc(short int modlitba, short int su_viaceri){
	Log("_set_zalmy_sviatok_muc(%s) (pre viacer˝ch muËenÌkov) -- begin\n", nazov_modlitby(modlitba));
	_set_zalmy_sviatok_muc(modlitba);
	if((su_viaceri > 0) && (modlitba == MODL_POSV_CITANIE)){
		/* viacero muË.:  ZALM33_I, ZALM33_2
		 * jeden muËenÌk: ZALM11, ZALM17 - rieöen˝ vyööie
		 */
		_set_zalm2(modlitba, "z33.htm", "ZALM33_I");
		_set_zalm3(modlitba, "z33.htm", "ZALM33_II");
	}
	Log("_set_zalmy_sviatok_muc(%s) (pre viacer˝ch muËenÌkov) -- end\n", nazov_modlitby(modlitba));
}

void _set_zalmy_sviatok_krstu(short int modlitba){
	Log("_set_zalmy_sviatok_krstu(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z130.htm", "ZALM130");
		_set_zalm3(modlitba, "kol1.htm", "CHVAL_KOL1");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		/* 2006-01-20: pridanÈ */
		_set_zalm1(modlitba, "z29.htm", "ZALM29");
		_set_zalm2(modlitba, "z66.htm", "ZALM66_I");
		_set_zalm3(modlitba, "z66.htm", "ZALM66_II");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z147.htm", "ZALM147,12-20");
		_set_zalm3(modlitba, "flp2.htm", "CHVAL_FLP2");
	}
	/* 2006-01-24: doplnenÈ ûalmy pre modlitbu cez deÚ - overiù, Ëi s˙ naozaj z nedele 1. t˝ûdÚa */
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalmy_1nedele_mcd();
	}
	Log("_set_zalmy_sviatok_krstu(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2006-01-19: pridanÈ, vytvorenÈ pre Obetovanie P·na */
void _set_zalmy_sviatok_obetovania(short int modlitba){
	Log("_set_zalmy_sviatok_obetovania(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z130.htm", "ZALM130");
		_set_zalm3(modlitba, "kol1.htm", "CHVAL_KOL1");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z2.htm", "ZALM2");
		_set_zalm2(modlitba, "z19.htm", "ZALM19,2-7");
		_set_zalm3(modlitba, "z45.htm", "ZALM45");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z147.htm", "ZALM147,12-20");
		_set_zalm3(modlitba, "flp2.htm", "CHVAL_FLP2");
	}
	Log("_set_zalmy_sviatok_obetovania(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2005-08-04: PridanÈ posv‰tnÈ ËÌtania */
void _set_zalmy_slavnost_Cyrila_a_Metoda(short int modlitba){
	Log("_set_zalmy_slavnost_Cyrila_a_Metoda(%s) -- begin\n", nazov_modlitby(modlitba));
	if((modlitba == MODL_VESPERY) || (modlitba == MODL_PRVE_VESPERY)){
		_set_zalm1(modlitba, "z117.htm", "ZALM117");
		_set_zalm2(modlitba, "z146.htm", "ZALM146");
		_set_zalm3(modlitba, "ef1.htm", "CHVAL_EF1");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z19.htm", "ZALM19,2-7");
		_set_zalm2(modlitba, "z33.htm", "ZALM33_I");
		_set_zalm3(modlitba, "z33.htm", "ZALM33_II");
	}
	Log("_set_zalmy_slavnost_Cyrila_a_Metoda(%s) -- end\n", nazov_modlitby(modlitba));
}
void _set_zalmy_sv_kriz(short int modlitba){
	Log("_set_zalmy_sv_kriz(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z116.htm", "ZALM116,10-19");
		_set_zalm3(modlitba, "zjv4_5.htm", "CHVAL_ZJV45");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z147.htm", "ZALM147_I");
		_set_zalm2(modlitba, "z147.htm", "ZALM147_II");
		_set_zalm3(modlitba, "flp2.htm", "CHVAL_FLP2");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		/* 2005-08-24: PridanÈ */
		_set_zalm1(modlitba, "z2.htm", "ZALM2");
		_set_zalm2(modlitba, "z8.htm", "ZALM8");
		_set_zalm3(modlitba, "z96.htm", "ZALM96");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	Log("_set_zalmy_sv_kriz(%s) -- end\n", nazov_modlitby(modlitba));
}

void _set_zalmy_archanjelov(short int modlitba){
	Log("_set_zalmy_archanjelov(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z8.htm", "ZALM8");
		_set_zalm2(modlitba, "z138.htm", "ZALM138");
		_set_zalm3(modlitba, "kol1.htm", "CHVAL_KOL1");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		/* 2005-10-13: PridanÈ */
		_set_zalm1(modlitba, "z97.htm", "ZALM97");
		_set_zalm2(modlitba, "z103.htm", "ZALM103_I_ANJ");
		_set_zalm3(modlitba, "z103.htm", "ZALM103_II_ANJ");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	Log("_set_zalmy_archanjelov(%s) -- end\n", nazov_modlitby(modlitba));
}

void _set_zalmy_anjelov_strazcov(short int modlitba){
	Log("_set_zalmy_anjelov_strazcov(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z34.htm", "ZALM34_I");
		_set_zalm2(modlitba, "z34.htm", "ZALM34_II");
		_set_zalm3(modlitba, "zjv11.htm", "CHVAL_ZJV11");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	Log("_set_zalmy_anjelov_strazcov(%s) -- end\n", nazov_modlitby(modlitba));
}
void _set_zalmy_vsetkych_svatych(short int modlitba){
	Log("_set_zalmy_vsetkych_svatych(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z116.htm", "ZALM116,10-19");
		_set_zalm3(modlitba, "zjv4_5.htm", "CHVAL_ZJV45");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z147.htm", "ZALM147,12-20");
		_set_zalm3(modlitba, "zjv19.htm", "CHVAL_ZJV19");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		/* 2005-10-24: PridanÈ */
		_set_zalm1(modlitba, "z8.htm", "ZALM8");
		_set_zalm2(modlitba, "z15.htm", "ZALM15");
		_set_zalm3(modlitba, "z16.htm", "ZALM16");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	Log("_set_zalmy_vsetkych_svatych(%s) -- end\n", nazov_modlitby(modlitba));
}

void liturgicke_obdobie(short int litobd, short int tyzden, short int den, short int tyzzal, short int poradie_svateho){
	short int modlitba, t;

	Log("-- liturgicke_obdobie(%d, %d, %d, %d: svaty: %d) -- zaciatok\n",
		litobd, tyzden, den, tyzzal, poradie_svateho);


	/* 02/03/2000A.D. -- kedysi tu bolo niekedy nespustenie zaltara, ale to mozeme */
	/* if((_global_den.smer > 5) || (_global_den.smer == 2)) */
		/* najprv spustime zaltar(); */
		/* >5 -- to su [6] nedele vianocneho obdobia a nedele cez rok,
		 *             [7] sviatky panny marie a svatych,
		 *             [8] miestne sviatky,
		 *             [9] adventne vsedne dni od 17. do 24. dec. vratane, 
		 *                 dni v oktave narodenia pana, 
		 *                 vsedne dni v poste,
		 *             [10] povinne spomienky,
		 *             [11] miestne povinne spomienky,
		 *             [12] lubovolne spomienky,
		 *             [13] vsedne dni adventne do 16. decembra vratane,
		 *                  vsedne dni vianocneho obdobia 2. januarom pocnuc a sobotou po zjaveni pana konciac,
		 *                  vsedne dni cez rok.
		 */
		/* == 2:       [2] nedele adventne, postne a velkonocne,
		 *                 vsedne dni velkeho tyzdna od pondelka do stvrtka vcitane
		 */

	 /* najprv treba skontrolovat, ci nejde o nedelu, na ktoru pripadol 
	  * sviatok Premenenia Pana (6. augusta)
	  * resp. sviatok Povysenia sv. Kriza (14. septembra);
	  * ak ano, tak nenastavuj nic, lebo
	  * vsetko sa nastavilo vo funkcii sviatky_svatych()
	  * 28/03/2000A.D.
	  * rovnako tak slavnost vsetkych svatych (1. novembra) - bez ohladu na to, ci ide o nedelu,
	  * 29/03/2000A.D.
	  *
	  * 2003-06-30a.D.: rovnako tak pre slavnost sv. Petra a sv. Pavla (29. juna)
	  *
	  * 2006-02-07: pravdupovediac, vöetko sa nenastavilo (modlitba cez deÚ, ûalmy) - musÌm to fixn˙ù
	  */
	if(
		((_global_den.denvt == DEN_NEDELA) && (_global_den.den == 6) && (_global_den.mesiac - 1 == MES_AUG)) ||
		((_global_den.denvt == DEN_NEDELA) && (_global_den.den == 29) && (_global_den.mesiac - 1 == MES_JUN)) ||
		((_global_den.denvt == DEN_NEDELA) && (_global_den.den == 14) && (_global_den.mesiac - 1 == MES_SEP) && (_global_modlitba != MODL_PREDPOLUDNIM) && (_global_modlitba != MODL_NAPOLUDNIE) && (_global_modlitba != MODL_POPOLUDNI)) ||
		((_global_den.den == 1) && (_global_den.mesiac - 1 == MES_NOV))
		){
		Log("premenenie p·na || pov˝öenie sv. krÌûa || vöetk˝ch sv‰t˝ch, so return...\n");
		return;
	}
	if((_global_den.denvt == DEN_NEDELA) && (_global_den.den == 14) && (_global_den.mesiac - 1 == MES_SEP)){
		Log("pov˝öenie sv. krÌûa, modlitba cez deÚ...\n");
		zaltar_zvazok(den, tyzzal, _global_den.litobd, ZALTAR_IBA_ZALMY_HYMNUS_MCD);
		return;
	}

	Log("/* najprv spustime zaltar_zvazok(); */\n");
	/* 2006-01-24: pÙvodne sa p˙öùala fnkcia s 2 parametrami; 
		pridan˝ ÔalöÌ parameter pre zv‰zok brevi·ra */
	zaltar_zvazok(den, tyzzal, _global_den.litobd, ZALTAR_VSETKO);

	file_name_litobd(litobd);
	Log("  _file == %s\n", _file);

Log(_global_modl_posv_citanie); /* 2005-03-26: Pridany vypis */

	/* file pre posvatne citania; pridane 2003-11-20 */
	file_name_litobd_pc(litobd);
	Log("  _file_pc == %s\n", _file_pc);

	/* 2004-04-28, pridane _file_pc_tyzden */
	mystrcpy(_file_pc_tyzden, STR_EMPTY, SMALL);
	Log("  _file_pc_tyzden bude nastavene na prislusnom mieste (teraz == %s).\n", _file_pc_tyzden);

	char c;
	/* char c sa pouziva vo vynimocnych pripadoch: napr. druha velkonocna nedela; 09/03/2000A.D. */

/* 2006-01-27: preklopenÈ spoloËnÈ kusy kÛdu pre adventnÈ obdobia do define-ov */
#define _adv_hymnus {\
	sprintf(_anchor, "%s%c_%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_hymnus(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_hymnus(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _adv1_kresponz {\
	sprintf(_anchor, "%s%s%c_%s", nazov_OBD[litobd], nazov_DN_asci[DEN_UNKNOWN], /* '??' */ 	pismenko_modlitby(modlitba), /* 'v' */ ANCHOR_KRESPONZ);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv_antifony_mcd {\
	/* 1. antifÛna */\
	sprintf(_anchor, "%s%c_%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	/* 2. antifÛna */\
	sprintf(_anchor, "%s%c_%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	/* 3. antifÛna */\
	sprintf(_anchor, "%s%c_%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv1_kcitanie {\
	sprintf(_anchor, "%s%s%c_%s", nazov_OBD[litobd], nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv1_kresp_mcd {\
	sprintf(_anchor, "%s%s%c_%s", nazov_OBD[litobd], nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv1_modlitba {\
	sprintf(_anchor, "%s%d%s_%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv1_prosby {\
	sprintf(_anchor, "%s%d%s%c_%s", nazov_OBD[litobd], t, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_PROSBY);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv1_antifony {\
	sprintf(_anchor, "%s%d%s%c_%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona1(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona1(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s%d%s%c_%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona2(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona2(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s%d%s%c_%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona3(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona3(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}

		/* velky switch(litobd), podla ktoreho sa priradia zakladne udaje */
	switch(litobd){
/* switch(litobd), case OBD_ADVENTNE_I -- begin ----------------------------------------------- */
		case OBD_ADVENTNE_I :/* do 16. decembra */

		/* ranne chvaly */
			/* hymnus */
			modlitba = MODL_RANNE_CHVALY;
			_adv_hymnus;
			_adv1_kresponz; /* kratke responzorium - rovnake pre vsetky dni okrem nedele */
		/* vespery */
			/* hymnus - rovnaky pre vsetky dni */
			modlitba = MODL_VESPERY;
			_adv_hymnus;
			_adv1_kresponz; /* kratke responzorium - rovnake pre vsetky dni okrem nedele */
		/* modlitba cez deÚ, pridanÈ 2005-11-20 */
			modlitba = MODL_PREDPOLUDNIM;
			_adv_hymnus; /* hymnus */
			_adv_antifony_mcd; /* antifÛny */
			_adv1_kcitanie; /* kr·tke ËÌtanie - rovnakÈ pre vöetky adventnÈ t˝ûdne */
			_adv1_kresp_mcd; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */
			_adv1_modlitba; /* modlitba ako na rannÈ chv·ly */

			modlitba = MODL_NAPOLUDNIE;
			_adv_hymnus; /* hymnus */
			_adv_antifony_mcd; /* antifÛny */
			_adv1_kcitanie; /* kr·tke ËÌtanie - rovnakÈ pre vöetky adventnÈ t˝ûdne */
			_adv1_kresp_mcd; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */
			_adv1_modlitba; /* modlitba ako na rannÈ chv·ly */

			modlitba = MODL_POPOLUDNI;
			_adv_hymnus; /* hymnus */
			_adv_antifony_mcd; /* antifÛny */
			_adv1_kcitanie; /* kr·tke ËÌtanie - rovnakÈ pre vöetky adventnÈ t˝ûdne */
			_adv1_kresp_mcd; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */
			_adv1_modlitba; /* modlitba ako na rannÈ chv·ly */

		/* posvatne citanie, pridane 2003-11-19 */
			modlitba = MODL_POSV_CITANIE;
			_adv_hymnus; /* hymnus */
			_adv1_modlitba;  /* modlitba - rovnaka ako cez den */

			/* 1. citanie */
			sprintf(_anchor, "%s%d%s%c_%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_CITANIE1);
			_set_citanie1(modlitba, _file_pc, _anchor);
			set_LOG_litobd_pc;

			/* 2. citanie */
			sprintf(_anchor, "%s%d%s%c_%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_CITANIE2);
			_set_citanie2(modlitba, _file_pc, _anchor);
			set_LOG_litobd_pc;

			if(tyzden == 3)
				t = 1;
			else if(tyzden == 4) /* nema efekt, lebo to uz je OBD_ADVENTNE_II */
				t = 2;
			else
				t = tyzden;

			if(den == DEN_NEDELA){

			/* prve vespery */
				/* !!! sem treba zadratovat, ze 16. decembra, 1. vespery,
				 * uz maju mnohe veci z OBD_ADVENTNE_II */
				/* hymnus - rovnaky pre prve a druhe vespery */
				modlitba = MODL_PRVE_VESPERY;
				sprintf(_anchor, "%s%c_%s",
					nazov_OBD[litobd],
					pismenko_modlitby(MODL_VESPERY),
					ANCHOR_HYMNUS);
				_set_hymnus(MODL_PRVE_VESPERY, _file, _anchor);
				set_LOG_litobd;
				/* kratke responzorium - rovnaka pre prve a druhe vespery a pre vsetky nedele */
				sprintf(_anchor, "%s%s%c_%s",
					nazov_OBD[litobd],
					nazov_DN_asci[den], /* 'NE' */
					pismenko_modlitby(MODL_VESPERY), /* 'v' */
					ANCHOR_KRESPONZ);
				_set_kresponz(modlitba, _file, _anchor);
				_set_kresponz(MODL_VESPERY, _file, _anchor);
				set_LOG_litobd;
				/* antifony */
				modlitba = MODL_PRVE_VESPERY;
				_adv1_antifony;
				_adv1_kcitanie; /* kratke citanie - rovnake pre vsetky tyzdne */
				/* magnifikat */
				sprintf(_anchor, "%s%d%s%c_%s%c",
					nazov_OBD[litobd],
					tyzden,
					nazov_DN_asci[den],
					pismenko_modlitby(modlitba),
					ANCHOR_MAGNIFIKAT,
					_global_den.litrok);
				_set_magnifikat(modlitba, _file, _anchor);
				set_LOG_litobd;
				_adv1_prosby; /* prosby - rovnake pre prvu a tretiu, resp. druhu a stvrtu adventnu nedelu */
				_adv1_modlitba; /* modlitba */

			/* posvatne citanie */
			/* pridane 2003-11-20 */

				modlitba = MODL_POSV_CITANIE;
				/* hymnus - rovnaky pre vsetky nedele */
				/* kratke responzorium  */
				sprintf(_anchor, "%s%s%c_%s",
					nazov_OBD[litobd],
					nazov_DN_asci[den],
					pismenko_modlitby(modlitba),
					ANCHOR_KRESPONZ);
				_set_kresponz(modlitba, _file_pc, _anchor);
				set_LOG_litobd;
				_adv1_antifony; /* antifony */

			/* ranne chvaly */
				/* hymnus - rovnaky pre vsetky dni */
				/* kratke responzorium - rovnake pre vsetky nedele */
				modlitba = MODL_RANNE_CHVALY;
				sprintf(_anchor, "%s%s%c_%s",
					nazov_OBD[litobd],
					nazov_DN_asci[den], /* 'NE' */
					pismenko_modlitby(modlitba), /* 'r' */
					ANCHOR_KRESPONZ);
				_set_kresponz(modlitba, _file, _anchor);
				set_LOG_litobd;
				_adv1_antifony; /* antifony */
				_adv1_kcitanie; /* kratke citanie - rovnake pre vsetky tyzdne */
				/* benediktus */
				sprintf(_anchor, "%s%d%s%c_%s%c",
					nazov_OBD[litobd],
					tyzden,
					nazov_DN_asci[den],
					pismenko_modlitby(modlitba),
					ANCHOR_BENEDIKTUS,
					_global_den.litrok);
				_set_benediktus(modlitba, _file, _anchor);
				set_LOG_litobd;
				_adv1_prosby; /* prosby - rovnake pre prvu a tretiu, resp. druhu a stvrtu adventnu nedelu */
				_adv1_modlitba; /* modlitba */

			/* druhe vespery */
				/* antifony */
				modlitba = MODL_VESPERY;
				_adv1_antifony; /* antifony */
				_adv1_kcitanie; /* kratke citanie - rovnake pre vsetky tyzdne */
				/* magnifikat */
				sprintf(_anchor, "%s%d%s%c_%s%c",
					nazov_OBD[litobd],
					tyzden,
					nazov_DN_asci[den],
					pismenko_modlitby(modlitba),
					ANCHOR_MAGNIFIKAT,
					_global_den.litrok);
				_set_magnifikat(modlitba, _file, _anchor);
				set_LOG_litobd;
				_adv1_prosby; /* prosby - rovnake pre prvu a tretiu, resp. druhu a stvrtu adventnu nedelu */
				_adv1_modlitba; /* modlitba */

			/* modlitbu cez deÚ nie je potrebnÈ öpeci·lne rieöiù, pozn·mka 2005-12-17 */
			}/* nedela */
			else{

			/* posvatne citanie */
			/* pridane 2003-11-20 */

				modlitba = MODL_POSV_CITANIE;
				/* hymnus - rovnaky pre vsetky dni */
				/* kratke responzorium  */
				sprintf(_anchor, "%s%s%c_%s",
					nazov_OBD[litobd],
					nazov_DN_asci[den],
					pismenko_modlitby(modlitba),
					ANCHOR_KRESPONZ);
				_set_kresponz(modlitba, _file_pc, _anchor);
				set_LOG_litobd;
				/* antifony - s˙ ako pre obdobie cez rok, z beûnÈho ûalt·ra; 2005-12-17 */

			/* ranne chvaly */
				/* hymnus - rovnaky pre vsetky dni */
				/* kratke responzorium - rovnake pre vsetky vsedne dni */
				modlitba = MODL_RANNE_CHVALY;
				sprintf(_anchor, "%s%s%c_%s",
					nazov_OBD[litobd],
					nazov_DN_asci[DEN_UNKNOWN], /* '??' */
					pismenko_modlitby(modlitba), /* 'r' */
					ANCHOR_KRESPONZ);
				_set_kresponz(modlitba, _file, _anchor);
				set_LOG_litobd;
				/* antifony - su zo vsedneho dna */
				_adv1_kcitanie; /* kratke citanie - rovnake pre vsetky tyzdne */
				/* benediktus */
				sprintf(_anchor, "%s%d%s%c_%s",
					nazov_OBD[litobd],
					tyzden,
					nazov_DN_asci[den],
					pismenko_modlitby(modlitba),
					ANCHOR_BENEDIKTUS);
				_set_benediktus(modlitba, _file, _anchor);
				set_LOG_litobd;
				_adv1_prosby; /* prosby - rovnake pre prvu a tretiu, resp. druhu a stvrtu adventnu nedelu */
				_adv1_modlitba; /* modlitba - rovnaka pre ranne chvaly aj vespery */

			/* vespery */
				/* hymnus - rovnaky pre vsetky dni */
				/* kratke responzorium - rovnake pre vsetky vsedne dni */
				modlitba = MODL_VESPERY;
				sprintf(_anchor, "%s%s%c_%s",
					nazov_OBD[litobd],
					nazov_DN_asci[DEN_UNKNOWN], /* '??' */
					pismenko_modlitby(modlitba), /* 'r' */
					ANCHOR_KRESPONZ);
				_set_kresponz(modlitba, _file, _anchor);
				set_LOG_litobd;
				/* antifony - su zo vsedneho dna */
				_adv1_kcitanie; /* kratke citanie - rovnake pre vsetky tyzdne */
				/* magnifikat */
				sprintf(_anchor, "%s%d%s%c_%s",
					nazov_OBD[litobd],
					tyzden,
					nazov_DN_asci[den],
					pismenko_modlitby(modlitba),
					ANCHOR_MAGNIFIKAT);
				_set_magnifikat(modlitba, _file, _anchor);
				set_LOG_litobd;
				_adv1_prosby; /* prosby - rovnake pre prvu a tretiu, resp. druhu a stvrtu adventnu nedelu */
				_adv1_modlitba; /* modlitba - rovnaka pre ranne chvaly aj vespery */

			}/* nie nedela */
			break;
/* switch(litobd), case OBD_ADVENTNE_I -- end ------------------------------------------------- */

#define _adv2_kcitanie {\
	sprintf(_anchor, "%s%d%c_%s", nazov_OBD[litobd], _global_den.den, pismenko_modlitby(modlitba), ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv2_kcitanie_ne {\
	sprintf(_anchor, "%s%d%c_%s", nazov_OBD[litobd], (_global_den.den == 24) ? 24 : 18, /* len pre nedeæu 24. dec. berie sa 24. dec, inak (pre ostatnÈ nedele) ako keby bolo 18. dec. */ pismenko_modlitby(modlitba), ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv2_kcitanie_adv1 {\
	sprintf(_anchor, "%s%s%c_%s", nazov_OBD[OBD_ADVENTNE_I], nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, nazov_obd_htm[OBD_ADVENTNE_I], _anchor);\
	set_LOG_litobd;\
}
#define _adv2_kresponz {\
	sprintf(_anchor, "%s%d%c_%s", nazov_OBD[litobd], (_global_den.den == 24) ? 24 : 18, /* len pre nedeæu 24. dec. berie sa 24. dec, inak (pre ostatnÈ nedele) ako keby bolo 18. dec. */ pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv2_kresponz_mcd {\
	sprintf(_anchor, "%s%d%c_%s", nazov_OBD[litobd], _global_den.den, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv2_modlitba {\
	sprintf(_anchor, "%s%d_%s", nazov_OBD[litobd], _global_den.den, ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv2_modlitba_ne {\
	sprintf(_anchor, "%s%d%s_%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv2_prosby {\
	sprintf(_anchor, "%s%d%c_%s", nazov_OBD[litobd], _global_den.den, pismenko_modlitby(modlitba), ANCHOR_PROSBY);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv2_prosby_4advne {\
	sprintf(_anchor, "%s%d%s%c_%s", nazov_OBD[litobd], 4, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_PROSBY);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv2_antifony_vesp {\
	sprintf(_anchor, "%s%s%c_%s", nazov_OBD[litobd], nazov_DN_asci[den], pismenko_modlitby(MODL_VESPERY), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s%s%c_%s", nazov_OBD[litobd], nazov_DN_asci[den], pismenko_modlitby(MODL_VESPERY), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s%s%c_%s", nazov_OBD[litobd], nazov_DN_asci[den], pismenko_modlitby(MODL_VESPERY), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv2_antifony {\
	sprintf(_anchor, "%s%d%c_%s", nazov_OBD[litobd], _global_den.den, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona1(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona1(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s%d%c_%s", nazov_OBD[litobd], _global_den.den, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona2(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona2(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s%d%c_%s", nazov_OBD[litobd], _global_den.den, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona3(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona3(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}

/* switch(litobd), case OBD_ADVENTNE_II -- begin ---------------------------------------------- */
		case OBD_ADVENTNE_II:/* po 16. decembri */

			file_name_litobd(OBD_ADVENTNE_II);

		/* ranne chvaly */
			modlitba = MODL_RANNE_CHVALY;
			/* hymnus - rovnaky pre kazdy den */
			_adv_hymnus;
			/* antifony - zavisia od dna v tyzdni (PONDELOK -- SOBOTA) */
			/* kedze su rovnake na ranne chvaly aj na vespery, rozhodli sme sa
			 * dat tam 'v' */
			_adv2_antifony_vesp;
			/* kratke responzorium - rovnake pre vsetky dni */
			sprintf(_anchor, "%s%s%c_%s",
				nazov_OBD[litobd],
				nazov_DN_asci[DEN_UNKNOWN],
				pismenko_modlitby(modlitba),
				ANCHOR_KRESPONZ);
			_set_kresponz(modlitba, _file, _anchor);
			set_LOG_litobd;
			/* dalsie zavisia od datumu (17. -- 24. december) */
			_adv2_kcitanie; /* kratke citanie */
			/* benediktus */
			sprintf(_anchor, "%s%d%c_%s",
				nazov_OBD[litobd],
				_global_den.den,
				pismenko_modlitby(modlitba),
				ANCHOR_BENEDIKTUS);
			_set_benediktus(modlitba, _file, _anchor);
			set_LOG_litobd;
			_adv2_prosby; /* prosby */
			_adv2_modlitba; /* modlitba - rovnaka pre rano i vecer */

		/* vespery */
			/* antifony */
			modlitba = MODL_VESPERY;
			/* hymnus - rovnaky pre kazdy den */
			_adv_hymnus;
			/* antifony - zavisia od dna v tyzdni (PONDELOK -- SOBOTA) */
			_adv2_antifony_vesp;
			/* dalsie zavisia od datumu (17. -- 24. december) */
			/* kratke responzorium - rovnake pre 17. a 18., resp.
			 * pre vsetky ostatne dni (19.-23.) */
			sprintf(_anchor, "%s%d%c_%s",
				nazov_OBD[litobd],
				(_global_den.den > 18? 19: 17),
				pismenko_modlitby(modlitba),
				ANCHOR_KRESPONZ);
			_set_kresponz(modlitba, _file, _anchor);
			set_LOG_litobd;
			_adv2_kcitanie; /* kratke citanie */
			/* magnifikat */
			sprintf(_anchor, "%s%d%c_%s",
				nazov_OBD[litobd],
				_global_den.den,
				pismenko_modlitby(modlitba),
				ANCHOR_MAGNIFIKAT);
			_set_benediktus(modlitba, _file, _anchor);
			set_LOG_litobd;
			_adv2_prosby; /* prosby */
			_adv2_modlitba; /* modlitba - rovnaka pre rano i vecer */

		/* prve vespery */
			/* antifony */
			modlitba = MODL_PRVE_VESPERY;
			/* hymnus - rovnaky ako vespery pre kazdy den */
			sprintf(_anchor, "%s%c_%s",
				nazov_OBD[litobd],
				pismenko_modlitby(MODL_VESPERY),
				ANCHOR_HYMNUS);
			_set_hymnus(modlitba, _file, _anchor);
			set_LOG_litobd;
			/* dalsie zavisia od datumu (17. -- 24. december) */
			/* magnifikat */
			sprintf(_anchor, "%s%d%c_%s",
				nazov_OBD[litobd],
				_global_den.den,
				pismenko_modlitby(MODL_VESPERY),
				ANCHOR_MAGNIFIKAT);
			_set_benediktus(modlitba, _file, _anchor);
			set_LOG_litobd;
			/* prosby */
			sprintf(_anchor, "%s%d%c_%s",
				nazov_OBD[litobd],
				_global_den.den,
				pismenko_modlitby(MODL_VESPERY),
				ANCHOR_PROSBY);
			_set_prosby(modlitba, _file, _anchor);
			set_LOG_litobd;

		/* modlitba cez deÚ, pridanÈ 2005-12-17 trochu podæa ADV.I. */
			/* hymnus */
			modlitba = MODL_PREDPOLUDNIM;
			_adv_hymnus;
			/* antifÛny */
			_adv_antifony_mcd;
			/* Ôalöie z·visia od d·tumu (17. -- 24. december) */
			_adv2_kcitanie; /* kratke citanie */
			_adv2_kresponz_mcd; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */
			_adv2_modlitba; /* modlitba ako na rannÈ chv·ly aj veöpery */

			/* hymnus */
			modlitba = MODL_NAPOLUDNIE;
			_adv_hymnus;
			/* antifÛny */
			_adv_antifony_mcd;
			/* Ôalöie z·visia od d·tumu (17. -- 24. december) */
			_adv2_kcitanie; /* kratke citanie */
			_adv2_kresponz_mcd; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */
			_adv2_modlitba; /* modlitba ako na rannÈ chv·ly aj veöpery */

			/* hymnus */
			modlitba = MODL_POPOLUDNI;
			_adv_hymnus;
			/* antifÛny */
			_adv_antifony_mcd;
			/* Ôalöie z·visia od d·tumu (17. -- 24. december) */
			_adv2_kcitanie; /* kratke citanie */
			_adv2_kresponz_mcd; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */
			_adv2_modlitba; /* modlitba ako na rannÈ chv·ly aj veöpery */

			/* posvatne citanie, pridane 2003-11-19, modifikovane 2003-12-07 */
			/* hymnus */
			modlitba = MODL_POSV_CITANIE;
			_adv_hymnus;
			_adv2_antifony; /* antifony */

			/* dalsie zavisia od datumu (17. -- 24. december) */
			/* 1. citanie */
			sprintf(_anchor, "%s%d%c_%s",
				nazov_OBD[litobd],
				_global_den.den,
				pismenko_modlitby(modlitba),
				ANCHOR_CITANIE1);
			_set_citanie1(modlitba, _file_pc, _anchor);
			set_LOG_litobd;

			/* 2. citanie */
			sprintf(_anchor, "%s%d%c_%s",
				nazov_OBD[litobd],
				_global_den.den,
				pismenko_modlitby(modlitba),
				ANCHOR_CITANIE2);
			_set_citanie2(modlitba, _file_pc, _anchor);
			set_LOG_litobd;

			/* kratke responzorium  */
			sprintf(_anchor, "%s%d%c_%s",
				nazov_OBD[litobd],
				_global_den.den,
				pismenko_modlitby(modlitba),
				ANCHOR_KRESPONZ);
			_set_kresponz(modlitba, _file_pc, _anchor);
			set_LOG_litobd;

			_adv2_modlitba; /* modlitba - rovnaka pre rano i vecer */

			/* nedela */
			/* pozor! ak tretia adventna nedela padne na 17. decembra, beru sa
			 * antifony na magnifikat, benediktus, prosby a hymny z tejto casti,
			 * avsak ostatne sa berie akoby z OBD_ADVENTNE_I, teda
			 * _file == nazov_obd_htm[OBD_ADVENTNE_I]
			 * _anchor == napr. ADV13NEr_ANT1 */
			if(den == DEN_NEDELA){
				if(tyzden == 3){/* jedine 17. decembra */

					litobd = OBD_ADVENTNE_I;
					file_name_litobd(litobd);
				/* prve vespery */
					modlitba = MODL_PRVE_VESPERY;
					/* kratke responzorium - rovnaka pre prve a druhe vespery a pre vsetky nedele */
					sprintf(_anchor, "%s%s%c_%s",
						nazov_OBD[litobd],
						nazov_DN_asci[den], /* 'NE' */
						pismenko_modlitby(MODL_VESPERY), /* 'v' */
						ANCHOR_KRESPONZ);
					_set_kresponz(modlitba, _file, _anchor);
					_set_kresponz(MODL_VESPERY, _file, _anchor);
					set_LOG_litobd;
					modlitba = MODL_PRVE_VESPERY;
					_adv1_antifony; /* antifony */
					/* kratke citanie - rovnake pre vsetky adventne nedele */
					_adv1_kcitanie; /* pozor, pouûÌvame z adv. obdobia I. - 2006-01-27 */
					/* modlitba */
					_adv1_modlitba;
				/* ranne chvaly */
					/* kratke responzorium - rovnake pre vsetky nedele */
					modlitba = MODL_RANNE_CHVALY;
					sprintf(_anchor, "%s%s%c_%s", nazov_OBD[litobd], nazov_DN_asci[den], /* 'NE' */ pismenko_modlitby(modlitba), /* 'r' */ ANCHOR_KRESPONZ);
					_set_kresponz(modlitba, _file, _anchor);
					set_LOG_litobd;
					_adv1_antifony; /* antifony */
					/* kratke citanie - rovnake pre vsetky adventne nedele */
					_adv1_kcitanie; /* pozor, pouûÌvame z adv. obdobia I. - 2006-01-27 */
					/* modlitba */
					_adv1_modlitba;
				/* druhe vespery */
					/* antifony */
					modlitba = MODL_VESPERY;
					_adv1_antifony;
					/* kratke citanie - rovnake pre vsetky adventne nedele */
					_adv1_kcitanie; /* pozor, pouûÌvame z adv. obdobia I. - 2006-01-27 */
					/* modlitba */
					_adv1_modlitba;

				/* modlitba cez deÚ, pridanÈ 2005-12-17 podæa 2005-11-20 (ADV.I.) okrem hymnov */
					modlitba = MODL_PREDPOLUDNIM;
					_adv_antifony_mcd; /* antifÛny */
					_adv1_kcitanie; /* kr·tke ËÌtanie - rovnakÈ pre vöetky adventnÈ t˝ûdne */
					_adv1_kresp_mcd; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */
					_adv1_modlitba; /* modlitba ako na rannÈ chv·ly */

					modlitba = MODL_NAPOLUDNIE;
					_adv_antifony_mcd; /* antifÛny */
					_adv1_kcitanie; /* kr·tke ËÌtanie - rovnakÈ pre vöetky adventnÈ t˝ûdne */
					_adv1_kresp_mcd; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */
					_adv1_modlitba; /* modlitba ako na rannÈ chv·ly */

					modlitba = MODL_POPOLUDNI;
					_adv_antifony_mcd; /* antifÛny */
					_adv1_kcitanie; /* kr·tke ËÌtanie - rovnakÈ pre vöetky adventnÈ t˝ûdne */
					_adv1_kresp_mcd; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */
					_adv1_modlitba; /* modlitba ako na rannÈ chv·ly */

				}/* tretia adventna nedela */
				else{/* tyzden == 4, stvrta adventna nedela */

					file_name_litobd(OBD_ADVENTNE_I);

					/* prve vespery */
					/* kratke responzorium - rovnaka pre prve a druhe vespery a pre vsetky nedele */
					sprintf(_anchor, "%s%s%c_%s",
						nazov_OBD[OBD_ADVENTNE_I],
						nazov_DN_asci[den], /* 'NE' */
						pismenko_modlitby(MODL_VESPERY), /* 'v' */
						ANCHOR_KRESPONZ);
					_set_kresponz(modlitba, nazov_obd_htm[OBD_ADVENTNE_I], _anchor);
					_set_kresponz(MODL_VESPERY, _file, _anchor);
					set_LOG_litobd;
					modlitba = MODL_PRVE_VESPERY;
					_adv1_antifony; /* antifony */
					_adv2_kcitanie_adv1; /* kratke citanie - rovnake pre vsetky adventne nedele */
					_adv2_prosby_4advne; /* prosby */
					_adv2_modlitba_ne; /* modlitba */

				/* ak je 24. dec., vsetko pre ranne chvaly sa berie zo dna 24. */
					if(_global_den.den == 24){
						mystrcpy(_file, nazov_obd_htm[OBD_ADVENTNE_II], MAX_STR_AF_FILE);
						/* benediktus */
						sprintf(_anchor, "%s%d%c_%s",
							nazov_OBD[litobd],
							_global_den.den,
							pismenko_modlitby(MODL_RANNE_CHVALY),
							ANCHOR_BENEDIKTUS);
						_set_benediktus(MODL_RANNE_CHVALY, _file, _anchor);
						set_LOG_litobd;
						goto label_24_DEC;
					}

				/* ranne chvaly */
					/* kratke responzorium - rovnake pre vsetky nedele */
					modlitba = MODL_RANNE_CHVALY;
					sprintf(_anchor, "%s%s%c_%s",
						nazov_OBD[OBD_ADVENTNE_I],
						nazov_DN_asci[den], /* 'NE' */
						pismenko_modlitby(modlitba), /* 'r' */
						ANCHOR_KRESPONZ);
					_set_kresponz(modlitba, nazov_obd_htm[OBD_ADVENTNE_I], _anchor);
					set_LOG_litobd;
					_adv1_antifony; /* antifony */
					_adv2_kcitanie_adv1; /* kratke citanie - rovnake pre vsetky adventne nedele */
					/* benediktus */
					if((_global_den.den == 21) || (_global_den.den == 23)){
						/* treba brat Nebojte sa resp. Hla, splnilo sa */
					}
					else{
					  sprintf(_anchor, "%s%d%s%c_%s%c",
						  nazov_OBD[litobd],
						  tyzden,
						  nazov_DN_asci[den],
						  pismenko_modlitby(modlitba),
						  ANCHOR_BENEDIKTUS,
						  _global_den.litrok);
					  _set_benediktus(modlitba, _file, _anchor);
					}
					set_LOG_litobd;
					_adv2_prosby_4advne; /* prosby */
					_adv2_modlitba_ne; /* modlitba */

				/* druhe vespery */
					modlitba = MODL_VESPERY;
					_adv1_antifony; /* antifony */
					_adv2_kcitanie_adv1; /* kratke citanie - rovnake pre vsetky adventne nedele */
					_adv2_prosby_4advne; /* prosby */
					_adv2_modlitba_ne; /* modlitba */

				/* modlitba cez deÚ, pridanÈ 2005-12-17 trochu podæa 2005-11-20 (ADV.I.) okrem hymnov a antifÛn */

					modlitba = MODL_PREDPOLUDNIM;
					_adv2_modlitba_ne; /* modlitba */

					modlitba = MODL_NAPOLUDNIE;
					_adv2_modlitba_ne; /* modlitba */

					modlitba = MODL_POPOLUDNI;
					_adv2_modlitba_ne; /* modlitba */

					file_name_litobd(OBD_ADVENTNE_II);

					modlitba = MODL_PREDPOLUDNIM;
					/* Ôalöie z·visia od d·tumu (18. dec. pre nedele okrem 24. decembra) */
					_adv2_kcitanie_ne; /* kr·tke ËÌtanie */
					_adv2_kresponz; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */
					modlitba = MODL_NAPOLUDNIE;
					/* Ôalöie z·visia od d·tumu (18. dec. pre nedele okrem 24. decembra) */
					_adv2_kcitanie_ne; /* kr·tke ËÌtanie */
					_adv2_kresponz; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */

					modlitba = MODL_POPOLUDNI;
					/* Ôalöie z·visia od d·tumu (18. dec. pre nedele okrem 24. decembra) */
					_adv2_kcitanie_ne; /* kr·tke ËÌtanie */
					_adv2_kresponz; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */

				}/* stvrta adventna nedela */
			}/* nedela */
			else{
				/* upravime veci pre 24. dec. */
				if(_global_den.den == 24){
label_24_DEC:
				/* iba ranne chvaly */
					modlitba = MODL_RANNE_CHVALY;
					/* hymnus - rovnaky pre kazdy den */
					_adv2_antifony; /* antifony - vlastne */
					/* kratke responzorium - vlastne */
					sprintf(_anchor, "%s%d%c_%s",
						nazov_OBD[litobd],
						_global_den.den,
						pismenko_modlitby(modlitba),
						ANCHOR_KRESPONZ);
					_set_kresponz(modlitba, _file, _anchor);
					set_LOG_litobd;

				}
			}/* nie nedela -- upravenie pre 24. dec. */

			/* Vo vöednÈ dni od 17. do 23. decembra sa ber˙:
			 * invitatÛrium, hymny, ËÌtania a responzÛri·, veröe, modlitba,
			 * antifÛny a prosby na rannÈ chv·ly a veöpery, ako s˙ na
			 * strane 71n. Tieto Ëasti sa potom z tretieho t˝ûdÚa vynech·vaj˙.
			 * ostatne veci sa beru z predosleho */

			break;
/* switch(litobd), case OBD_ADVENTNE_II -- end ------------------------------------------------ */

/* panny marie bohorodicky */
#define _bohorod_hymnus {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	sprintf(_anchor, "%s_%c%s", ANCHOR_PM_BOHOROD, c, ANCHOR_HYMNUS);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_hymnus(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_hymnus(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _bohorod_kcitanie {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	sprintf(_anchor, "%s_%c%s", ANCHOR_PM_BOHOROD, c, ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-02-05: doplnenÈ posv‰tnÈ ËÌtanie */
#define _bohorod_citanie1 {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_PM_BOHOROD, pismenko_modlitby(modlitba), ANCHOR_CITANIE1);\
	_set_citanie1(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _bohorod_citanie2 {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_PM_BOHOROD, pismenko_modlitby(modlitba), ANCHOR_CITANIE2);\
	_set_citanie2(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _bohorod_kresponz {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	sprintf(_anchor, "%s_%c%s", ANCHOR_PM_BOHOROD, c, ANCHOR_KRESPONZ);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_kresponz(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_kresponz(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _bohorod_prosby {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_PM_BOHOROD, pismenko_modlitby(modlitba), ANCHOR_PROSBY);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _bohorod_benediktus {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_PM_BOHOROD, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _bohorod_magnifikat {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_PM_BOHOROD, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-02-05: doplnenÈ posv‰tnÈ ËÌtanie - modlitba ako na rannÈ chv·ly 
 * 2006-02-16: doplnen· modlitba cez deÚ - modlitba ako na rannÈ chv·ly 
 */
#define _bohorod_modlitba {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI) || (modlitba == MODL_POSV_CITANIE))\
		c = pismenko_modlitby(MODL_RANNE_CHVALY);\
	sprintf(_anchor, "%s_%c%s", ANCHOR_PM_BOHOROD, c, ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _bohorod_antifony {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	sprintf(_anchor, "%s_%c%s", ANCHOR_PM_BOHOROD, c, ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", ANCHOR_PM_BOHOROD, c, ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", ANCHOR_PM_BOHOROD, c, ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

/* sviatok svatej rodiny; 2006-02-05: doplnenÈ posv. ËÌtania a modlitba cez deÚ */
#define _sv_rodiny_hymnus {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SV_RODINY, pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_hymnus(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_hymnus(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _sv_rodiny_kcitanie {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SV_RODINY, pismenko_modlitby(modlitba), ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-02-05: doplnenÈ posv‰tnÈ ËÌtanie */
#define _sv_rodiny_citanie1 {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SV_RODINY, pismenko_modlitby(modlitba), ANCHOR_CITANIE1);\
	_set_citanie1(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _sv_rodiny_citanie2 {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SV_RODINY, pismenko_modlitby(modlitba), ANCHOR_CITANIE2);\
	_set_citanie2(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _sv_rodiny_kresponz {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SV_RODINY, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_kresponz(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_kresponz(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _sv_rodiny_prosby {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SV_RODINY, c, ANCHOR_PROSBY);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _sv_rodiny_benediktus {\
	sprintf(_anchor, "%s_%c%s%c", ANCHOR_SV_RODINY, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, _global_den.litrok);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _sv_rodiny_magnifikat {\
	sprintf(_anchor, "%s_%c%s%c", ANCHOR_SV_RODINY, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, _global_den.litrok);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _sv_rodiny_modlitba {\
	sprintf(_anchor, "%s_%s", ANCHOR_SV_RODINY, ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _sv_rodiny_antifony {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SV_RODINY, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SV_RODINY, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SV_RODINY, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

/* vianocne obdobie I */

/* 2006-02-04: doplnenÈ posv‰tnÈ ËÌtania a mcd */
#define _vian1_hymnus {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_VIANOCNE_I], c, ANCHOR_HYMNUS);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_hymnus(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_hymnus(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _vian1_kcitanie {\
	sprintf(_anchor, "%s_%c%s%d", nazov_OBD[OBD_VIANOCNE_I], pismenko_modlitby(modlitba), ANCHOR_KCITANIE, _global_den.den);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian1_2ne_kcitanie {\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VIANOCNE_I], ANCHOR_2NE_PO_NAR, pismenko_modlitby(modlitba), ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

/* 2006-02-04: doplnenÈ posv‰tnÈ ËÌtania a mcd */
#define _vian1_kresponz {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	if((den == DEN_NEDELA) && (_global_den.den != 25 /* narodenie Pana */)\
		&& (modlitba != MODL_POSV_CITANIE)){\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[OBD_VIANOCNE_I], c, ANCHOR_KRESPONZ, nazov_DN_asci[den]);\
	}\
	else if(modlitba != MODL_POSV_CITANIE){\
		sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_VIANOCNE_I], c, ANCHOR_KRESPONZ);\
	}\
	else {\
		sprintf(_anchor, "%s_%c%s_%d", nazov_OBD[OBD_VIANOCNE_I], c, ANCHOR_KRESPONZ, _global_den.den);\
	}\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_kresponz(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_kresponz(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _vian1_prosby {\
	sprintf(_anchor, "%s_%c%s%d", nazov_OBD[OBD_VIANOCNE_I], pismenko_modlitby(modlitba), ANCHOR_PROSBY, _global_den.den);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian1_2ne_prosby {\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VIANOCNE_I], ANCHOR_2NE_PO_NAR, pismenko_modlitby(modlitba), ANCHOR_PROSBY);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian1_2ne_benediktus {\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VIANOCNE_I], ANCHOR_2NE_PO_NAR, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian1_2ne_magnifikat {\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VIANOCNE_I], ANCHOR_2NE_PO_NAR, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian1_benediktus {\
	sprintf(_anchor, "%s_%c%s%d", nazov_OBD[OBD_VIANOCNE_I], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, _global_den.den);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian1_magnifikat {\
	sprintf(_anchor, "%s_%c%s%d", nazov_OBD[OBD_VIANOCNE_I], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, _global_den.den);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian1_2ne_modlitba {\
	sprintf(_anchor, "%s_%s%s", nazov_OBD[OBD_VIANOCNE_I], ANCHOR_2NE_PO_NAR, ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian1_2ne_antifony {\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VIANOCNE_I], ANCHOR_2NE_PO_NAR, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VIANOCNE_I], ANCHOR_2NE_PO_NAR, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VIANOCNE_I], ANCHOR_2NE_PO_NAR, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian1_modlitba {\
	if(_global_den.den == 25/* narodenie Pana */){\
		sprintf(_anchor, "%s_%c%s%d", nazov_OBD[OBD_VIANOCNE_I], pismenko_modlitby(modlitba), ANCHOR_MODLITBA, _global_den.den);\
	}\
	else{\
		sprintf(_anchor, "%s_%s%d", nazov_OBD[OBD_VIANOCNE_I], ANCHOR_MODLITBA, _global_den.den);\
	}\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _narodenie_antifony {\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_OKTAVA_NARODENIA], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_OKTAVA_NARODENIA], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_OKTAVA_NARODENIA], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-02-04: doplnenÈ posv‰tnÈ ËÌtanie */
#define _vian1_citanie1 {\
	sprintf(_anchor, "%s_%c%s_%d", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE1, _global_den.den);\
	_set_citanie1(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _vian1_citanie2 {\
	sprintf(_anchor, "%s_%c%s_%d", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE2, _global_den.den);\
	_set_citanie2(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _vian_okt_antifony_pc {\
	sprintf(_anchor, "%s_%c%s_%d", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1, _global_den.den);\
	_set_antifona1(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
	sprintf(_anchor, "%s_%c%s_%d", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2, _global_den.den);\
	_set_antifona2(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
	sprintf(_anchor, "%s_%c%s_%d", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3, _global_den.den);\
	_set_antifona3(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
/* 2006-02-05: vytvorenÈ pre modlitbu cez deÚ podæa _post1_mcd_antifony; porov. _adv_antifony_mcd */
#define _vian1_mcd_antifony {\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_VIANOCNE_I], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_VIANOCNE_I], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_VIANOCNE_I], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

/* switch(litobd), case OBD_OKTAVA_NARODENIA -- begin ----------------------------------------- */
		case OBD_OKTAVA_NARODENIA :/* narodenie Pana -- 1. jan. */
			/* a pokracujeme ako vianocne obdobie I; 14/03/2000A.D. */
/* switch(litobd), case OBD_VIANOCNE_I -- begin ----------------------------------------------- */
		case OBD_VIANOCNE_I :/* do slavnosti zjavenia pana */

		/* 2006-01-24: tu zaËÌna VIANO»N… OBDOBIE I. */

			if((_global_den.den == 26) || (_global_den.den == 27) || (_global_den.den == 28)){
				/* maju vlastnu cast zo sv. jana apostola, sv. stefana a sv. neviniatok */
			}
			else{
				/* ranne chvaly */
				modlitba = MODL_RANNE_CHVALY;
				_vian1_hymnus;
				_vian1_kcitanie;
				_vian1_kresponz;
				_vian1_benediktus;
				_vian1_prosby;
				_vian1_modlitba;

				/* posv‰tnÈ ËÌtanie; 2006-02-04 */
				modlitba = MODL_POSV_CITANIE;
				_vian1_hymnus;
				_set_zalmy_vian_oktava(_global_den.den, modlitba);
				if(_global_den.den >= 25){
					/* 2006-02-05: antifÛny s˙ samostatnÈ len pre vianoËn˙ okt·vu; inak zo ûalt·ra */
					_vian_okt_antifony_pc;
				}
				_vian1_kresponz;
				_vian1_citanie1;
				_vian1_citanie2;
				_vian1_modlitba;

				/* modlitba cez deÚ, pridanÈ 2006-02-05 */
				modlitba = MODL_PREDPOLUDNIM;
				_vian1_hymnus; /* hymnus */
				_vian1_mcd_antifony; /* antifÛny */
				_vian1_kcitanie; /* kr·tke ËÌtanie */
				_vian1_kresponz; /* kr·tke responzÛrium */
				_vian1_modlitba; /* modlitba ako na rannÈ chv·ly */

				modlitba = MODL_NAPOLUDNIE;
				_vian1_hymnus; /* hymnus */
				_vian1_mcd_antifony; /* antifÛny */
				_vian1_kcitanie; /* kr·tke ËÌtanie */
				_vian1_kresponz; /* kr·tke responzÛrium */
				_vian1_modlitba; /* modlitba ako na rannÈ chv·ly */

				modlitba = MODL_POPOLUDNI;
				_vian1_hymnus; /* hymnus */
				_vian1_mcd_antifony; /* antifÛny */
				_vian1_kcitanie; /* kr·tke ËÌtanie */
				_vian1_kresponz; /* kr·tke responzÛrium */
				_vian1_modlitba; /* modlitba ako na rannÈ chv·ly */

			}

			/* vespery */
			modlitba = MODL_VESPERY;
			_vian1_hymnus;
			_vian1_kcitanie;
			_vian1_kresponz;
			_vian1_magnifikat;
			_vian1_prosby;
			_vian1_modlitba;

			if(litobd == OBD_OKTAVA_NARODENIA){
				if(_global_den.den == 25){  /* narodenie Pana */
					/* prve vespery */
					modlitba = MODL_PRVE_VESPERY;
					_vian1_hymnus;
					_narodenie_antifony;
					_vian1_kcitanie;
					_vian1_kresponz;
					_vian1_magnifikat;
					_vian1_prosby;
					_vian1_modlitba;
					_set_zalmy_narodenie(modlitba);
					/* modlitba cez deÚ, pridanÈ 2006-02-05 */
					modlitba = MODL_PREDPOLUDNIM;
					_set_zalmy_narodenie(modlitba);
					modlitba = MODL_NAPOLUDNIE;
					_set_zalmy_narodenie(modlitba);
					modlitba = MODL_POPOLUDNI;
					_set_zalmy_narodenie(modlitba);
				}

				/* ranne chvaly */
				modlitba = MODL_RANNE_CHVALY;
				_set_zalmy_narodenie(modlitba);
				_narodenie_antifony;
	
				/* druhe vespery */
				modlitba = MODL_VESPERY;
				_set_zalmy_narodenie(modlitba);
				_narodenie_antifony;
			}

			if((_global_den.den == 1) && (_global_den.mesiac == 1)){ /* Panny Marie Bohorodicky */
				/* panny marie bohorodicky; 14/03/2000A.D. */
				mystrcpy(_file, FILE_PM_BOHOROD, MAX_STR_AF_FILE);
				mystrcpy(_file_pc, FILE_PM_BOHOROD, MAX_STR_AF_FILE); /* 2006-02-05: doplnenÈ */
				mystrcpy(_anchor, ANCHOR_PM_BOHOROD, MAX_STR_AF_ANCHOR);
				Log("  ide o slavnost panny marie bohorodicky: _file = `%s', _anchor = %s...\n", _file, _anchor);
				modlitba = MODL_PRVE_VESPERY;
				_set_zalmy_sviatok_panien(modlitba);
				_bohorod_hymnus;
				_bohorod_kcitanie;
				_bohorod_kresponz;
				_bohorod_magnifikat;
				_bohorod_prosby;
				_bohorod_modlitba;
				_bohorod_antifony;
				modlitba = MODL_RANNE_CHVALY;
				_set_zalmy_1nedele_rch();
				_bohorod_hymnus;
				_bohorod_kcitanie;
				_bohorod_kresponz;
				_bohorod_benediktus;
				_bohorod_prosby;
				_bohorod_modlitba;
				_bohorod_antifony;
				modlitba = MODL_VESPERY;
				_set_zalmy_sviatok_panien(modlitba);
				_bohorod_hymnus;
				_bohorod_kcitanie;
				_bohorod_kresponz;
				_bohorod_magnifikat;
				_bohorod_prosby;
				_bohorod_modlitba;
				_bohorod_antifony;
				/* posv‰tnÈ ËÌtanie; 2006-02-05 */
				modlitba = MODL_POSV_CITANIE;
				_bohorod_hymnus;
				_set_zalmy_sviatok_marie(modlitba);
				_bohorod_antifony;
				_bohorod_kresponz;
				_bohorod_citanie1;
				_bohorod_citanie2;
				_bohorod_modlitba;

				/* 2006-02-16: doplnenÈ modlitby cez deÚ */
				modlitba = MODL_PREDPOLUDNIM;
				_bohorod_kcitanie;
				_bohorod_modlitba;
				modlitba = MODL_NAPOLUDNIE;
				_bohorod_kcitanie;
				_bohorod_modlitba;
				modlitba = MODL_POPOLUDNI;
				_bohorod_kcitanie;
				_bohorod_modlitba;
			}
			else if((_global_den.denvt == DEN_NEDELA) && (_global_den.mesiac - 1 == MES_JAN)){ /* druha nedela po narodeni pana */
				/* prve vespery */
				modlitba = MODL_PRVE_VESPERY;
				_vian1_hymnus;
				_vian1_2ne_kcitanie;
				_vian1_kresponz;
				_vian1_2ne_magnifikat;
				_vian1_2ne_prosby;
				_vian1_2ne_modlitba;
				_vian1_2ne_antifony;
				/* ranne chvaly */
				modlitba = MODL_RANNE_CHVALY;
				_vian1_2ne_kcitanie;
				_vian1_2ne_benediktus;
				_vian1_2ne_prosby;
				_vian1_2ne_antifony;
				_vian1_2ne_modlitba;
				/* druhe vespery */
				modlitba = MODL_VESPERY;
				_vian1_2ne_kcitanie;
				_vian1_2ne_magnifikat;
				_vian1_2ne_prosby;
				_vian1_2ne_antifony;
				_vian1_2ne_modlitba;
			
				/* modlitba cez deÚ, pridanÈ 2006-02-05 (posv‰tnÈ ËÌtanie je zo dÚa podæa d·tumu ) */
				modlitba = MODL_PREDPOLUDNIM;
				_vian1_2ne_kcitanie;
				_vian1_kresponz;
				_vian1_2ne_modlitba;
				modlitba = MODL_NAPOLUDNIE;
				_vian1_2ne_kcitanie;
				_vian1_kresponz;
				_vian1_2ne_modlitba;
				modlitba = MODL_POPOLUDNI;
				_vian1_2ne_kcitanie;
				_vian1_kresponz;
				_vian1_2ne_modlitba;
			}
			else if(_global_den.denvr == _global_r._SVATEJ_RODINY.denvr){
				/* sviatok svatej rodiny; 14/03/2000A.D. */
				mystrcpy(_file, FILE_SV_RODINY, MAX_STR_AF_FILE);
				mystrcpy(_file_pc, FILE_SV_RODINY, MAX_STR_AF_FILE); /* 2006-02-05: doplnenÈ */
				mystrcpy(_anchor, ANCHOR_SV_RODINY, MAX_STR_AF_ANCHOR);
				Log("  ide o sviatok svatej rodiny: _file = `%s', _anchor = %s...\n", _file, _anchor);
				modlitba = MODL_PRVE_VESPERY;
				_set_zalmy_sviatok_panien(modlitba);
				_sv_rodiny_hymnus;
				_sv_rodiny_kcitanie;
				_sv_rodiny_kresponz;
				_sv_rodiny_magnifikat;
				_sv_rodiny_prosby;
				_sv_rodiny_modlitba;
				_sv_rodiny_antifony;
				modlitba = MODL_RANNE_CHVALY;
				_set_zalmy_1nedele_rch();
				_sv_rodiny_hymnus;
				_sv_rodiny_kcitanie;
				_sv_rodiny_kresponz;
				_sv_rodiny_benediktus;
				_sv_rodiny_prosby;
				_sv_rodiny_modlitba;
				_sv_rodiny_antifony;
				modlitba = MODL_VESPERY;
				_set_zalmy_sviatok_panien(modlitba);
				_sv_rodiny_hymnus;
				_sv_rodiny_kcitanie;
				_sv_rodiny_kresponz;
				_sv_rodiny_magnifikat;
				_sv_rodiny_prosby;
				_sv_rodiny_modlitba;
				_sv_rodiny_antifony;

				/* posv‰tnÈ ËÌtanie; 2006-02-05 */
				modlitba = MODL_POSV_CITANIE;
				_sv_rodiny_hymnus;
				_set_zalmy_sviatok_marie(modlitba);
				_sv_rodiny_antifony;
				_sv_rodiny_kresponz;
				_sv_rodiny_citanie1;
				_sv_rodiny_citanie2;
				_sv_rodiny_modlitba;

				/* modlitba cez deÚ, pridanÈ 2006-02-05 */
				modlitba = MODL_PREDPOLUDNIM;
				_sv_rodiny_kcitanie;
				_sv_rodiny_kresponz;
				_sv_rodiny_modlitba;
				/* ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
				if(_global_den.denvt != DEN_NEDELA) {
					_set_zalm_cez_den_doplnkova_psalmodia();
				}
				else {
					_set_zalmy_1nedele_mcd();
				}

				modlitba = MODL_NAPOLUDNIE;
				_sv_rodiny_kcitanie;
				_sv_rodiny_kresponz;
				_sv_rodiny_modlitba;
				/* ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
				if(_global_den.denvt != DEN_NEDELA) {
					_set_zalm_cez_den_doplnkova_psalmodia();
				}
				else {
					_set_zalmy_1nedele_mcd();
				}

				modlitba = MODL_POPOLUDNI;
				_sv_rodiny_kcitanie;
				_sv_rodiny_kresponz;
				_sv_rodiny_modlitba;
				/* ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
				if(_global_den.denvt != DEN_NEDELA) {
					_set_zalm_cez_den_doplnkova_psalmodia();
				}
				else {
					_set_zalmy_1nedele_mcd();
				}

			}
			break;
/* switch(litobd), case OBD_OKTAVA_NARODENIA -- end ------------------------------------------- */
/* switch(litobd), case OBD_VIANOCNE_I -- end ------------------------------------------------- */

/* switch(litobd), case OBD_VIANOCNE_II -- begin ---------------------------------------------- */
		case OBD_VIANOCNE_II: {/* po slavnosti zjavenia pana */
/* vianocne obdobie II */
/* 2006-02-07: doplnenÈ posv‰tnÈ ËÌtania a mcd */
#define _vian2_hymnus {\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_VIANOCNE_II], pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_hymnus(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_hymnus(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _zjv_kcitanie {\
	sprintf(_anchor, "%s_%c%s%d", nazov_OBD[OBD_VIANOCNE_II], pismenko_modlitby(modlitba), ANCHOR_KCITANIE, _global_den.den);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-02-07: doplnenÈ posv‰tnÈ ËÌtania */
#define _vian2_kresponz {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	if(modlitba != MODL_POSV_CITANIE){\
		sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_VIANOCNE_II], c, ANCHOR_KRESPONZ);\
	}\
	else {\
		sprintf(_anchor, "%s_%c%s_%d", nazov_OBD[OBD_VIANOCNE_II], c, ANCHOR_KRESPONZ, _global_den.den);\
	}\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_kresponz(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_kresponz(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _vian2_prosby {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	sprintf(_anchor, "%s_%c%s%d", nazov_OBD[OBD_VIANOCNE_II], c, ANCHOR_PROSBY, _global_den.den);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian2_benediktus {\
	sprintf(_anchor, "%s_%c%s%d", nazov_OBD[OBD_VIANOCNE_II], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, _global_den.den);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian2_magnifikat {\
	sprintf(_anchor, "%s_%c%s%d", nazov_OBD[OBD_VIANOCNE_II], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, _global_den.den);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian2_modlitba {\
	sprintf(_anchor, "%s_%s%d", nazov_OBD[OBD_VIANOCNE_II], ANCHOR_MODLITBA, _global_den.den);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-02-07: pridanÈ posv‰tnÈ ËÌtanie */
#define _zjv_antifony {\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VIANOCNE_II], ANCHOR_ZJAVENIE_PANA, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona1(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona1(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VIANOCNE_II], ANCHOR_ZJAVENIE_PANA, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona2(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona2(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VIANOCNE_II], ANCHOR_ZJAVENIE_PANA, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona3(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona3(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
/* 2006-02-07: doplnenÈ posv‰tnÈ ËÌtanie */
#define _vian2_citanie1 {\
	sprintf(_anchor, "%s_%c%s_%d", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE1, _global_den.den);\
	_set_citanie1(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _vian2_citanie2 {\
	sprintf(_anchor, "%s_%c%s_%d", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE2, _global_den.den);\
	_set_citanie2(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
/* 2006-02-07: vytvorenÈ pre modlitbu cez deÚ podæa _vian1_mcd_antifony (to podæa _post1_mcd_antifony; porov. _adv_antifony_mcd) */
#define _vian2_mcd_antifony {\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_VIANOCNE_II], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_VIANOCNE_II], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_VIANOCNE_II], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
									 
		/* 2006-01-24: tu v skutoËnosti zaËÌna VIANO»N… OBDOBIE II. */

			/* ranne chvaly */
			modlitba = MODL_RANNE_CHVALY;
			_vian2_hymnus;
			_vian2_kresponz;
			_vian2_benediktus;
			_vian2_prosby;
			_vian2_modlitba;

			/* vespery */
			modlitba = MODL_VESPERY;
			_vian2_hymnus;
			_vian2_kresponz;
			_vian2_magnifikat;
			_vian2_prosby;
			_vian2_modlitba;

			/* posv‰tnÈ ËÌtanie; 2006-02-07 */
			modlitba = MODL_POSV_CITANIE;
			_vian2_hymnus;
			_vian2_kresponz;
			_vian2_citanie1;
			_vian2_citanie2;
			_vian2_modlitba;

			/* modlitba cez deÚ, pridanÈ 2006-02-05 */
			modlitba = MODL_PREDPOLUDNIM;
			_vian2_hymnus; /* hymnus */
			_vian2_mcd_antifony; /* antifÛny */
			/* kr·tke ËÌtanie nastavenÈ neskÙr podæa vian1 */
			_vian2_kresponz; /* kr·tke responzÛrium */
			_vian2_modlitba; /* modlitba ako na rannÈ chv·ly */

			modlitba = MODL_NAPOLUDNIE;
			_vian2_hymnus; /* hymnus */
			_vian2_mcd_antifony; /* antifÛny */
			/* kr·tke ËÌtanie nastavenÈ neskÙr podæa vian1 */
			_vian2_kresponz; /* kr·tke responzÛrium */
			_vian2_modlitba; /* modlitba ako na rannÈ chv·ly */

			modlitba = MODL_POPOLUDNI;
			_vian2_hymnus; /* hymnus */
			_vian2_mcd_antifony; /* antifÛny */
			/* kr·tke ËÌtanie nastavenÈ neskÙr podæa vian1 */
			_vian2_kresponz; /* kr·tke responzÛrium */
			_vian2_modlitba; /* modlitba ako na rannÈ chv·ly */

			if((_global_den.den == 6) && (_global_den.mesiac == 1)){ /* zjavenie pana */
			/* prve vespery */
				modlitba = MODL_PRVE_VESPERY;
				_vian2_hymnus;
				_zjv_antifony;
				_zjv_kcitanie;
				_vian2_kresponz;
				_vian2_magnifikat;
				_vian2_prosby;
				_vian2_modlitba;
				_set_zalmy_zjv(modlitba);
			/* ranne chvaly */
				modlitba = MODL_RANNE_CHVALY;
				_set_zalmy_zjv(modlitba);
				_zjv_kcitanie;
				_zjv_antifony;
			/* druhe vespery */
				modlitba = MODL_VESPERY;
				_set_zalmy_zjv(modlitba);
				_zjv_kcitanie;
				_zjv_antifony;
				/* posv‰tnÈ ËÌtanie; 2006-02-07 */
				modlitba = MODL_POSV_CITANIE;
				_set_zalmy_zjv(modlitba);
				_zjv_antifony;
				/* modlitby cez deÚ, pridanÈ 2006-02-05 */
				modlitba = MODL_PREDPOLUDNIM;
				_set_zalmy_zjv(modlitba);
				_zjv_kcitanie;
				modlitba = MODL_NAPOLUDNIE;
				_set_zalmy_zjv(modlitba);
				_zjv_kcitanie;
				modlitba = MODL_POPOLUDNI;
				_set_zalmy_zjv(modlitba);
				_zjv_kcitanie;

			}/* zjavenie pana */
			else{
				/* vsedny den vianocneho obdobia II -- citania podla vian.obd.I 
				 * 2006-02-07: presne takto isto sa spr·vaj˙ aj kr·tke ËÌtania pre modlitbu cez deÚ
				 *             (ako pre kr·tk ËÌtanie na rannÈ chv·ly)
				 */
				mystrcpy(_file, nazov_obd_htm[OBD_VIANOCNE_I], MAX_STR_AF_FILE);
				if(_global_den.den == 8){
					modlitba = MODL_RANNE_CHVALY;
					_global_den.den = 31;
					_vian1_kcitanie;
					modlitba = MODL_PREDPOLUDNIM;
					_vian1_kcitanie;
					modlitba = MODL_NAPOLUDNIE;
					_vian1_kcitanie;
					modlitba = MODL_POPOLUDNI;
					_vian1_kcitanie;
					modlitba = MODL_VESPERY;
					_global_den.den = 28;
					_vian1_kcitanie;
				}
				else{
					if(_global_den.den == 7){
						_global_den.den = 30;
						modlitba = MODL_RANNE_CHVALY;
						_vian1_kcitanie;
						modlitba = MODL_PREDPOLUDNIM;
						_vian1_kcitanie;
						modlitba = MODL_NAPOLUDNIE;
						_vian1_kcitanie;
						modlitba = MODL_POPOLUDNI;
						_vian1_kcitanie;
						modlitba = MODL_VESPERY;
						_vian1_kcitanie;
					}
					else{/* den == 9, 10, 11, 12 */
						_global_den.den = _global_den.den - 7; /* den == 2, 3, 4, 5 */
						modlitba = MODL_RANNE_CHVALY;
						_vian1_kcitanie;
						modlitba = MODL_PREDPOLUDNIM;
						_vian1_kcitanie;
						modlitba = MODL_NAPOLUDNIE;
						_vian1_kcitanie;
						modlitba = MODL_POPOLUDNI;
						_vian1_kcitanie;
						modlitba = MODL_VESPERY;
						_vian1_kcitanie;					
					}
				}
			}/* obycajny den vian.obd. II -- priradenie citania */

			}
			break;
/* switch(litobd), case OBD_VIANOCNE_II -- end ------------------------------------------------ */

/* switch(litobd), case OBD_CEZ_ROK -- begin -------------------------------------------------- */
		case OBD_CEZ_ROK:{

/* najsv. trojice */
#define _troj_hymnus {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_NAJSV_TROJICE, pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	_set_hymnus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _troj_kcitanie {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_NAJSV_TROJICE, pismenko_modlitby(modlitba), ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-24: _troj_citanie1 a _troj_citanie2 - doplnenÈ pre posv. ËÌtanie */
#define _troj_citanie1 {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_NAJSV_TROJICE, pismenko_modlitby(modlitba), ANCHOR_CITANIE1);\
	_set_citanie1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _troj_citanie2 {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_NAJSV_TROJICE, pismenko_modlitby(modlitba), ANCHOR_CITANIE2);\
	_set_citanie2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _troj_kresponz {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_NAJSV_TROJICE, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _troj_prosby {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_NAJSV_TROJICE, pismenko_modlitby(modlitba), ANCHOR_PROSBY);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _troj_benediktus {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_NAJSV_TROJICE, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _troj_magnifikat {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_NAJSV_TROJICE, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _troj_modlitba {\
	sprintf(_anchor, "%s_%s", ANCHOR_NAJSV_TROJICE, ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _troj_ne_antifony {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_NAJSV_TROJICE, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", ANCHOR_NAJSV_TROJICE, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", ANCHOR_NAJSV_TROJICE, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

/* krista krala */
#define _krkrala_hymnus {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_KRISTA_KRALA, pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	_set_hymnus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _krkrala_kcitanie {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_KRISTA_KRALA, pismenko_modlitby(modlitba), ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-24: pridanÈ */
#define _krkrala_citanie1 {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_KRISTA_KRALA, pismenko_modlitby(modlitba), ANCHOR_CITANIE1);\
	_set_citanie1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _krkrala_citanie2 {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_KRISTA_KRALA, pismenko_modlitby(modlitba), ANCHOR_CITANIE2);\
	_set_citanie2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _krkrala_kresponz {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_KRISTA_KRALA, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _krkrala_prosby {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_KRISTA_KRALA, pismenko_modlitby(modlitba), ANCHOR_PROSBY);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _krkrala_benediktus {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_KRISTA_KRALA, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _krkrala_magnifikat {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_KRISTA_KRALA, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _krkrala_modlitba {\
	sprintf(_anchor, "%s_%s", ANCHOR_KRISTA_KRALA, ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _krkrala_ne_antifony {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_KRISTA_KRALA, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", ANCHOR_KRISTA_KRALA, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", ANCHOR_KRISTA_KRALA, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

/* najsv. tela a krvi jezisovej */
#define _telakrvi_hymnus {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_TELA_A_KRVI, pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	_set_hymnus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-24: doplnenÈ posv. ËÌtania */
#define _telakrvi_citanie1 {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_TELA_A_KRVI, pismenko_modlitby(modlitba), ANCHOR_CITANIE1);\
	_set_citanie1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _telakrvi_citanie2 {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_TELA_A_KRVI, pismenko_modlitby(modlitba), ANCHOR_CITANIE2);\
	_set_citanie2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _telakrvi_kcitanie {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_TELA_A_KRVI, pismenko_modlitby(modlitba), ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _telakrvi_kresponz {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_TELA_A_KRVI, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _telakrvi_prosby {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_TELA_A_KRVI, pismenko_modlitby(modlitba), ANCHOR_PROSBY);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _telakrvi_benediktus {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_TELA_A_KRVI, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _telakrvi_magnifikat {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_TELA_A_KRVI, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _telakrvi_modlitba {\
	sprintf(_anchor, "%s_%s", ANCHOR_TELA_A_KRVI, ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _telakrvi_ne_antifony {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_TELA_A_KRVI, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", ANCHOR_TELA_A_KRVI, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", ANCHOR_TELA_A_KRVI, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

/* najsv. srdca jezisovho */
#define _srdca_hymnus {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SRDCA, pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	_set_hymnus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-24: doplnenÈ posv. ËÌtania */
#define _srdca_citanie1 {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SRDCA, pismenko_modlitby(modlitba), ANCHOR_CITANIE1);\
	_set_citanie1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _srdca_citanie2 {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SRDCA, pismenko_modlitby(modlitba), ANCHOR_CITANIE2);\
	_set_citanie2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _srdca_kcitanie {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SRDCA, pismenko_modlitby(modlitba), ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _srdca_kresponz {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SRDCA, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _srdca_prosby {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SRDCA, pismenko_modlitby(modlitba), ANCHOR_PROSBY);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _srdca_benediktus {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SRDCA, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _srdca_magnifikat {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SRDCA, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _srdca_modlitba {\
	sprintf(_anchor, "%s_%s", ANCHOR_SRDCA, ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _srdca_ne_antifony {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SRDCA, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SRDCA, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SRDCA, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

/* krist krista p·na */
#define _krst_hymnus {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_KRST_PANA, pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	_set_hymnus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _krst_kcitanie {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_KRST_PANA, pismenko_modlitby(modlitba), ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _krst_kresponz {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_KRST_PANA, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-24: doplnenÈ posv. ËÌtania */
#define _krst_citanie1 {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_KRST_PANA, pismenko_modlitby(modlitba), ANCHOR_CITANIE1);\
	_set_citanie1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _krst_citanie2 {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_KRST_PANA, pismenko_modlitby(modlitba), ANCHOR_CITANIE2);\
	_set_citanie2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _krst_prosby {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_KRST_PANA, pismenko_modlitby(modlitba), ANCHOR_PROSBY);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _krst_benediktus {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_KRST_PANA, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _krst_magnifikat {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_KRST_PANA, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _krst_modlitba {\
	sprintf(_anchor, "%s_%s", ANCHOR_KRST_PANA, ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _krst_ne_antifony {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_KRST_PANA, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", ANCHOR_KRST_PANA, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", ANCHOR_KRST_PANA, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

	/* 2006-01-24: tu v skutoËnosti zaËÌna CEZRO»N… OBDOBIE */

					/* najprv treba skontrolovat, ci nejde o nedelu, na ktoru pripadol 
					 * sviatok Premenenia Pana (6. augusta); ak ano, tak nenastavuj nic, lebo
					 * vsetko sa nastavilo vo funkcii sviatky_svatych()
					 * 28/03/2000A.D.
					 */
				if((_global_den.denvt == DEN_NEDELA) && (_global_den.den == 6) && (_global_den.mesiac - 1 == MES_AUG)){
					Log("premenenie pana, so break...\n");
					break;
				}
				if(_global_den.denvt == DEN_NEDELA){
					Log("--- nedela OCR, nastavujem modlitbu dna...\n");
					/* ak je specialna, tak _file sa nastavi v dalsom, 10/03/2000A.D. */
					file_name_litobd(OBD_CEZ_ROK);
					/* benediktus */
					modlitba = MODL_RANNE_CHVALY;
					sprintf(_anchor, "_%d%s%c_%s%c", tyzden, nazov_DN_asci[den], /* 'NE', nedela */ pismenko_modlitby(MODL_RANNE_CHVALY), ANCHOR_BENEDIKTUS, _global_den.litrok);
					_set_benediktus(MODL_RANNE_CHVALY, _file, _anchor);
					set_LOG_litobd;
					/* magnifikat 1 */
					modlitba = MODL_PRVE_VESPERY;
					sprintf(_anchor, "_%d%s%c_%s%c", tyzden, nazov_DN_asci[den], /* 'NE', nedela */ pismenko_modlitby(MODL_PRVE_VESPERY), ANCHOR_MAGNIFIKAT, _global_den.litrok);
					_set_magnifikat(MODL_PRVE_VESPERY, _file, _anchor);
					set_LOG_litobd;
					/* magnifikat v */
					modlitba = MODL_VESPERY;
					sprintf(_anchor, "_%d%s%c_%s%c", tyzden, nazov_DN_asci[den], /* 'NE', nedela */ pismenko_modlitby(MODL_VESPERY), ANCHOR_MAGNIFIKAT, _global_den.litrok);
					_set_magnifikat(MODL_VESPERY, _file, _anchor);
					set_LOG_litobd;
					/* modlitba */
					sprintf(_anchor, "_%d%s_%s", tyzden, nazov_DN_asci[den], /* 'NE', nedela */ ANCHOR_MODLITBA); 
					modlitba = MODL_RANNE_CHVALY;
					_set_modlitba(MODL_RANNE_CHVALY, _file, _anchor);
					set_LOG_litobd;
					modlitba = MODL_PRVE_VESPERY;
					_set_modlitba(MODL_PRVE_VESPERY, _file, _anchor);
					set_LOG_litobd;
					modlitba = MODL_VESPERY;
					_set_modlitba(MODL_VESPERY, _file, _anchor);
					set_LOG_litobd;
					/* modlitba pre posvatne citania a modlitbu cez den, 2005-03-27 */
					modlitba = MODL_PREDPOLUDNIM;
					_set_modlitba(MODL_PREDPOLUDNIM, _file, _anchor);
					set_LOG_litobd;
					modlitba = MODL_NAPOLUDNIE;
					_set_modlitba(MODL_NAPOLUDNIE, _file, _anchor);
					set_LOG_litobd;
					modlitba = MODL_POPOLUDNI;
					_set_modlitba(MODL_POPOLUDNI, _file, _anchor);
					set_LOG_litobd;
					modlitba = MODL_POSV_CITANIE;
					_set_modlitba(MODL_POSV_CITANIE, _file, _anchor);
					set_LOG_litobd;

				/* posvatne citanie, pridane 2004-04-28; presunutÈ 2006-01-24 sem a do Ëasti "nie nedeæa" kvÙli napr. Najsv. Trojici */
					Log("posvatne citanie, pridane 2004-04-28...\n");

					/* idem nastavit _file_pc_tyzden podla tyzdna */
					file_name_litobd_pc_tyzden(litobd, tyzden);
					Log("  _file_pc_tyzden == %s\n", _file_pc_tyzden);

					modlitba = MODL_POSV_CITANIE;

					/* 1. citanie */
					sprintf(_anchor, "%s%d%s%c_%s",
						nazov_OBD[litobd],
						tyzden,
						nazov_DN_asci[den],
						pismenko_modlitby(modlitba),
						ANCHOR_CITANIE1);
					_set_citanie1(modlitba, _file_pc_tyzden, _anchor);
					set_LOG_litobd_pc_tyzden;
					/* Log(_global_modl_posv_citanie); */

					/* 2. citanie */
					sprintf(_anchor, "%s%d%s%c_%s",
						nazov_OBD[litobd],
						tyzden,
						nazov_DN_asci[den],
						pismenko_modlitby(modlitba),
						ANCHOR_CITANIE2);
					/*
						Log("docasne - %s\n", _file_pc_tyzden);
						Log("docasne - %s\n", _anchor);
					*/
					_set_citanie2(modlitba, _file_pc_tyzden, _anchor);
					set_LOG_litobd_pc_tyzden;
					/* Log(_global_modl_posv_citanie); */


					/* 10/03/2000A.D. */
					if(_global_den.denvr == (_global_r._ZOSLANIE_DUCHA_SV.denvr + 7)){
						/* najsv. trojice; 10/03/2000A.D. */
						mystrcpy(_file, FILE_NAJSV_TROJICE, MAX_STR_AF_FILE);
						mystrcpy(_anchor, ANCHOR_NAJSV_TROJICE, MAX_STR_AF_ANCHOR);
						Log("  ide o slavnost najsv. trojice: _file = `%s', _anchor = %s...\n", _file, _anchor);
						modlitba = MODL_PRVE_VESPERY;
						_set_zalmy_najsv_trojice(modlitba);
						_troj_hymnus;
						_troj_kcitanie;
						_troj_kresponz;
						_troj_magnifikat;
						_troj_prosby;
						_troj_modlitba;
						_troj_ne_antifony;
						modlitba = MODL_RANNE_CHVALY;
						_set_zalmy_najsv_trojice(modlitba);
						_troj_hymnus;
						_troj_kcitanie;
						_troj_kresponz;
						_troj_benediktus;
						_troj_prosby;
						_troj_modlitba;
						_troj_ne_antifony;
						modlitba = MODL_VESPERY;
						_set_zalmy_najsv_trojice(modlitba);
						_troj_hymnus;
						_troj_kcitanie;
						_troj_kresponz;
						_troj_magnifikat;
						_troj_prosby;
						_troj_modlitba;
						_troj_ne_antifony;
						/* 2006-01-24: doplnenÈ posv‰tnÈ ËÌtania */
						modlitba = MODL_POSV_CITANIE;
						_set_zalmy_najsv_trojice(modlitba);
						_troj_hymnus;
						_troj_ne_antifony;
						_troj_citanie1;
						_troj_citanie2;
						_troj_kresponz;
						_troj_modlitba;
						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						modlitba = MODL_PREDPOLUDNIM;
						_set_zalmy_najsv_trojice(modlitba);
						_troj_ne_antifony;
						_troj_kcitanie;
						_troj_kresponz;
						_troj_modlitba;
						modlitba = MODL_NAPOLUDNIE;
						_set_zalmy_najsv_trojice(modlitba);
						_troj_ne_antifony;
						_troj_kcitanie;
						_troj_kresponz;
						_troj_modlitba;
						modlitba = MODL_POPOLUDNI;
						_set_zalmy_najsv_trojice(modlitba);
						_troj_ne_antifony;
						_troj_kcitanie;
						_troj_kresponz;
						_troj_modlitba;
					}/* najsv. trojice */
					else if(tyzden == 34){
						/* krista krala -- 34. nedela obdobia `cez rok'; 10/03/2000A.D. */
						mystrcpy(_file, FILE_KRISTA_KRALA, MAX_STR_AF_FILE);
						mystrcpy(_anchor, ANCHOR_KRISTA_KRALA, MAX_STR_AF_ANCHOR);
						Log("  ide o slavnost krista krala: _file = `%s', _anchor = %s...\n", _file, _anchor);
						modlitba = MODL_PRVE_VESPERY;
						_set_zalmy_krista_krala(modlitba);
						_krkrala_hymnus;
						_krkrala_kcitanie;
						_krkrala_kresponz;
						_krkrala_magnifikat;
						_krkrala_prosby;
						_krkrala_modlitba;
						_krkrala_ne_antifony;
						modlitba = MODL_RANNE_CHVALY;
						_set_zalmy_krista_krala(modlitba);
						_krkrala_hymnus;
						_krkrala_kcitanie;
						_krkrala_kresponz;
						_krkrala_benediktus;
						_krkrala_prosby;
						_krkrala_modlitba;
						_krkrala_ne_antifony;
						/* 2005-08-12: pridanÈ posv‰tnÈ ËÌtanie; opravenÈ 2006-01-24 */
						modlitba = MODL_POSV_CITANIE;
						_set_zalmy_krista_krala(modlitba);
						_krkrala_hymnus;
						/* s˙ nastavenÈ ako 34. nedeæa cezroËnÈho obdobia vyööie
						_krkrala_citanie1;
						_krkrala_citanie2;
						_krkrala_kresponz;
						*/
						_krkrala_modlitba;
						_krkrala_ne_antifony;
						modlitba = MODL_VESPERY;
						_set_zalmy_krista_krala(modlitba);
						_krkrala_hymnus;
						_krkrala_kcitanie;
						_krkrala_kresponz;
						_krkrala_magnifikat;
						_krkrala_prosby;
						_krkrala_modlitba;
						_krkrala_ne_antifony;
						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						modlitba = MODL_PREDPOLUDNIM;
						_set_zalmy_krista_krala(modlitba);
						_krkrala_ne_antifony;
						_krkrala_kcitanie;
						_krkrala_kresponz;
						_krkrala_modlitba;
						modlitba = MODL_NAPOLUDNIE;
						_set_zalmy_krista_krala(modlitba);
						_krkrala_ne_antifony;
						_krkrala_kcitanie;
						_krkrala_kresponz;
						_krkrala_modlitba;
						modlitba = MODL_POPOLUDNI;
						_set_zalmy_krista_krala(modlitba);
						_krkrala_ne_antifony;
						_krkrala_kcitanie;
						_krkrala_kresponz;
						_krkrala_modlitba;
					}/* krista krala */
					else if((tyzden == 1) && (_global_den.denvr == _global_r._KRST_KRISTA_PANA.denvr)){
						/* krst krista pana -- 1. nedela obdobia `cez rok'; 14/03/2000A.D. */
						mystrcpy(_file, FILE_KRST_PANA, MAX_STR_AF_FILE);
						mystrcpy(_anchor, ANCHOR_KRST_PANA, MAX_STR_AF_ANCHOR);
						Log("  ide o slavnost najsv. trojice.: _file = `%s', _anchor = %s...\n", _file, _anchor);
						modlitba = MODL_PRVE_VESPERY;
						_set_zalmy_sviatok_krstu(modlitba);
						_krst_hymnus;
						_krst_kcitanie;
						_krst_kresponz;
						_krst_magnifikat;
						_krst_prosby;
						_krst_modlitba;
						_krst_ne_antifony;
						modlitba = MODL_RANNE_CHVALY;
						_set_zalmy_sviatok_krstu(modlitba);
						_krst_hymnus;
						_krst_kcitanie;
						_krst_kresponz;
						_krst_benediktus;
						_krst_prosby;
						_krst_modlitba;
						_krst_ne_antifony;
						modlitba = MODL_VESPERY;
						_set_zalmy_sviatok_krstu(modlitba);
						_krst_hymnus;
						_krst_kcitanie;
						_krst_kresponz;
						_krst_magnifikat;
						_krst_prosby;
						_krst_modlitba;
						_krst_ne_antifony;
						/* 2006-01-24: doplnenÈ posv‰tnÈ ËÌtania */
						modlitba = MODL_POSV_CITANIE;
						_set_zalmy_sviatok_krstu(modlitba);
						_krst_hymnus;
						_krst_ne_antifony;
						/* hoci by mohli byù nastavenÈ ako 1. nedeæa cezroËnÈho obdobia vyööie,
						 * predsa pouûijeme samostatn˝ s˙bor a samostatne ich nastavÌme; 2006-02-07
						 */
						_krst_citanie1;
						_krst_citanie2;
						_krst_kresponz;
						_krst_modlitba;
						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						modlitba = MODL_PREDPOLUDNIM;
						_set_zalmy_sviatok_krstu(modlitba);
						_krst_ne_antifony;
						_krst_kcitanie;
						_krst_kresponz;
						_krst_modlitba;
						modlitba = MODL_NAPOLUDNIE;
						_set_zalmy_sviatok_krstu(modlitba);
						_krst_ne_antifony;
						_krst_kcitanie;
						_krst_kresponz;
						_krst_modlitba;
						modlitba = MODL_POPOLUDNI;
						_set_zalmy_sviatok_krstu(modlitba);
						_krst_ne_antifony;
						_krst_kcitanie;
						_krst_kresponz;
						_krst_modlitba;
					}/* krst krista pana */
				}/* nedela v obdobi cez rok */
				else{
					Log("--- obdobie cez rok, nie nedela...\n");
					/* nie je nedela, ale len bezny den - feria - v obdobi cez rok */

				/* posvatne citanie, pridane 2004-04-28; presunutÈ sem (aj do nedele) 2006-01-24 */
					Log("posvatne citanie, pridane 2004-04-28...\n");

					/* idem nastavit _file_pc_tyzden podla tyzdna */
					file_name_litobd_pc_tyzden(litobd, tyzden);
					Log("  _file_pc_tyzden == %s\n", _file_pc_tyzden);

					modlitba = MODL_POSV_CITANIE;

					/* 1. citanie */
					sprintf(_anchor, "%s%d%s%c_%s",
						nazov_OBD[litobd],
						tyzden,
						nazov_DN_asci[den],
						pismenko_modlitby(modlitba),
						ANCHOR_CITANIE1);
					_set_citanie1(modlitba, _file_pc_tyzden, _anchor);
					set_LOG_litobd_pc_tyzden;
					/* Log(_global_modl_posv_citanie); */

					/* 2. citanie */
					sprintf(_anchor, "%s%d%s%c_%s",
						nazov_OBD[litobd],
						tyzden,
						nazov_DN_asci[den],
						pismenko_modlitby(modlitba),
						ANCHOR_CITANIE2);
					/*
						Log("docasne - %s\n", _file_pc_tyzden);
						Log("docasne - %s\n", _anchor);
					*/
					_set_citanie2(modlitba, _file_pc_tyzden, _anchor);
					set_LOG_litobd_pc_tyzden;
					/* Log(_global_modl_posv_citanie); */

					if(_global_den.denvr == (_global_r._ZOSLANIE_DUCHA_SV.denvr + 11)){
						/* najsv. kristovho tela a krvi; 10/03/2000A.D. */
						mystrcpy(_file, FILE_TELA_A_KRVI, MAX_STR_AF_FILE);
						mystrcpy(_anchor, ANCHOR_TELA_A_KRVI, MAX_STR_AF_ANCHOR);
						Log("  ide o slavnost najsv. kristovho tela a krvi: _file = `%s', _anchor = %s...\n", _file, _anchor);
						modlitba = MODL_PRVE_VESPERY;
						_set_zalmy_telakrvi(modlitba);
						_telakrvi_hymnus;
						_telakrvi_kcitanie;
						_telakrvi_kresponz;
						_telakrvi_magnifikat;
						_telakrvi_prosby;
						_telakrvi_modlitba;
						_telakrvi_ne_antifony;
						modlitba = MODL_RANNE_CHVALY;
						_set_zalmy_telakrvi(modlitba);
						_telakrvi_hymnus;
						_telakrvi_kcitanie;
						_telakrvi_kresponz;
						_telakrvi_benediktus;
						_telakrvi_prosby;
						_telakrvi_modlitba;
						_telakrvi_ne_antifony;
						modlitba = MODL_VESPERY;
						_set_zalmy_telakrvi(modlitba);
						_telakrvi_hymnus;
						_telakrvi_kcitanie;
						_telakrvi_kresponz;
						_telakrvi_magnifikat;
						_telakrvi_prosby;
						_telakrvi_modlitba;
						_telakrvi_ne_antifony;
						/* 2006-01-24: doplnenÈ posv‰tnÈ ËÌtania */
						modlitba = MODL_POSV_CITANIE;
						_set_zalmy_telakrvi(modlitba);
						_telakrvi_hymnus;
						_telakrvi_modlitba;
						_telakrvi_ne_antifony;
						_telakrvi_citanie1;
						_telakrvi_citanie2;
						_telakrvi_kresponz;
						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						modlitba = MODL_PREDPOLUDNIM;
						_set_zalmy_telakrvi(modlitba);
						_telakrvi_ne_antifony;
						_telakrvi_kcitanie;
						_telakrvi_kresponz;
						_telakrvi_modlitba;
						modlitba = MODL_NAPOLUDNIE;
						_set_zalmy_telakrvi(modlitba);
						_telakrvi_ne_antifony;
						_telakrvi_kcitanie;
						_telakrvi_kresponz;
						_telakrvi_modlitba;
						modlitba = MODL_POPOLUDNI;
						_set_zalmy_telakrvi(modlitba);
						_telakrvi_ne_antifony;
						_telakrvi_kcitanie;
						_telakrvi_kresponz;
						_telakrvi_modlitba;
					}/* tela a krvi */
					else if(_global_den.denvr == (_global_r._ZOSLANIE_DUCHA_SV.denvr + 19)){
						/* najsv. srdca jezisovho; 10/03/2000A.D. */
						mystrcpy(_file, FILE_SRDCA, MAX_STR_AF_FILE);
						mystrcpy(_anchor, ANCHOR_SRDCA, MAX_STR_AF_ANCHOR);
						Log("  ide o slavnost najsv. srdca jezisovho: _file = `%s', _anchor = %s...\n", _file, _anchor);
						modlitba = MODL_PRVE_VESPERY;
						_set_zalmy_srdca(modlitba);
						_srdca_hymnus;
						_srdca_kcitanie;
						_srdca_kresponz;
						_srdca_magnifikat;
						_srdca_prosby;
						_srdca_modlitba;
						_srdca_ne_antifony;
						modlitba = MODL_RANNE_CHVALY;
						_set_zalmy_srdca(modlitba);
						_srdca_hymnus;
						_srdca_kcitanie;
						_srdca_kresponz;
						_srdca_benediktus;
						_srdca_prosby;
						_srdca_modlitba;
						_srdca_ne_antifony;
						modlitba = MODL_VESPERY;
						_set_zalmy_srdca(modlitba);
						_srdca_hymnus;
						_srdca_kcitanie;
						_srdca_kresponz;
						_srdca_magnifikat;
						_srdca_prosby;
						_srdca_modlitba;
						_srdca_ne_antifony;
						/* 2006-01-24: doplnenÈ posv‰tnÈ ËÌtania */
						modlitba = MODL_POSV_CITANIE;
						_set_zalmy_srdca(modlitba);
						_srdca_hymnus;
						_srdca_modlitba;
						_srdca_ne_antifony;
						_srdca_citanie1;
						_srdca_citanie2;
						_srdca_kresponz;
						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						modlitba = MODL_PREDPOLUDNIM;
						_set_zalmy_srdca(modlitba);
						_srdca_ne_antifony;
						_srdca_kcitanie;
						_srdca_kresponz;
						_srdca_modlitba;
						modlitba = MODL_NAPOLUDNIE;
						_set_zalmy_srdca(modlitba);
						_srdca_ne_antifony;
						_srdca_kcitanie;
						_srdca_kresponz;
						_srdca_modlitba;
						modlitba = MODL_POPOLUDNI;
						_set_zalmy_srdca(modlitba);
						_srdca_ne_antifony;
						_srdca_kcitanie;
						_srdca_kresponz;
						_srdca_modlitba;
					}/* srdca */
					else if(_global_den.denvr == (_global_r._ZOSLANIE_DUCHA_SV.denvr + 20)){
						/* neposkvrneneho srdca prebl. panny marie; 04/07/2000A.D. */
						Log("  (hoci tu nic nenastavujem) ide o spomienku neposkvrneneho srdca prebl. panny marie\n");
					}
					else {
						/* 2005-03-27: posvatne citania doplnena modlitba - je z prislusnej nedele OCR */
						Log("--- modlitba dna pre bezne dni OCR je z prislusnej nedele...\n");
						modlitba = MODL_POSV_CITANIE;
						/* modlitba */
						sprintf(_anchor, "_%d%s_%s", tyzden, nazov_DN_asci[DEN_NEDELA], ANCHOR_MODLITBA); 
						modlitba = MODL_POSV_CITANIE;
						_set_modlitba(MODL_POSV_CITANIE, _file, _anchor);
						set_LOG_litobd;
					}
				}/* nie nedela */
				/* 2006-01-24: chv·la Bohu, dokonËenÈ cezroËnÈ obdobie 
				 *             vr·tane posv. ËÌtania a modlity cez deÚ :) 
				 * 2006-02-02: dokonËenÈ pre cezroËnÈ obdobie aj æs PM v sobotu :)
				 */
			}

			break;
/* switch(litobd), case OBD_CEZ_ROK -- end ---------------------------------------------------- */

/* switch(litobd), case OBD_POSTNE_I -- begin ------------------------------------------------- */
		case OBD_POSTNE_I:/* do soboty v piatom tyzdni */
		/* 06/03/2000A.D. */
/* 2006-01-24: upravenÈ pre posv‰tnÈ ËÌtanie
 * 2006-01-25: pre modlitbu cez deÚ aj pre nedeæu hymnus ako pre vöedn˝ deÚ.
 */
#define _post1_hymnus {\
	if((den == DEN_NEDELA)\
		&& (modlitba != MODL_PREDPOLUDNIM) && (modlitba != MODL_NAPOLUDNIE) && (modlitba != MODL_POPOLUDNI)){\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), nazov_DN_asci[den], ANCHOR_HYMNUS);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	}\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_hymnus(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_hymnus(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
/* 2006-01-24: doplnenÈ posv‰tnÈ ËÌtanie */
#define _post1_citanie1 {\
	sprintf(_anchor, "%s_%c%s_%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE1, tyzden, nazov_DN_asci[den]);\
	_set_citanie1(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _post1_citanie2 {\
	sprintf(_anchor, "%s_%c%s_%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE2, tyzden, nazov_DN_asci[den]);\
	_set_citanie2(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _post1_kcitanie {\
	if(tyzden != 5){\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), nazov_DN_asci[den], ANCHOR_KCITANIE);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s%s%d", nazov_OBD[litobd], pismenko_modlitby(modlitba), nazov_DN_asci[den], ANCHOR_KCITANIE, tyzden);\
	}\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-24: upravenÈ pre posv‰tnÈ ËÌtanie
 * 2006-01-25: pre modlitbu cez deÚ platÌ to istÈ Ëo pre beûn˝ deÚ, t.j. responz· s˙ rovnakÈ.
 *             jedin· zmena: aj pre nedeæu pre mcd platÌ to, Ëo pre vöedn˝ deÚ.
 */
#define _post1_kresponz {\
	if((den == DEN_NEDELA) && (modlitba == MODL_POSV_CITANIE)){\
		sprintf(_anchor, "%s_%c%s%s%d", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_KRESPONZ, nazov_DN_asci[den], tyzden);\
	}\
	else if(((den == DEN_NEDELA) || (modlitba == MODL_POSV_CITANIE))\
		&& (modlitba != MODL_PREDPOLUDNIM) && (modlitba != MODL_NAPOLUDNIE) && (modlitba != MODL_POPOLUDNI)){\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_KRESPONZ, nazov_DN_asci[den]);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	}\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_kresponz(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_kresponz(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _post1_prosby {\
	if((den == DEN_STREDA) && (tyzden == 0) && (modlitba == MODL_RANNE_CHVALY)){\
		sprintf(_anchor, "%s_%c%s%sPOPOL", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_PROSBY, nazov_DN_asci[den]);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_PROSBY, t, nazov_DN_asci[den]);\
	}\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _post1_benediktus {\
	if(den == DEN_NEDELA){\
		sprintf(_anchor, "%s_%c%s%d%s%c", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, tyzden, nazov_DN_asci[den], _global_den.litrok);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, tyzden, nazov_DN_asci[den]);\
	}\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _post1_magnifikat {\
	if(den == DEN_NEDELA){\
		sprintf(_anchor, "%s_%c%s%d%s%c", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, tyzden, nazov_DN_asci[den], _global_den.litrok);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, tyzden, nazov_DN_asci[den]);\
	}\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _post1_modlitba {\
	sprintf(_anchor, "%s_%s%d%s", nazov_OBD[litobd], ANCHOR_MODLITBA, tyzden, nazov_DN_asci[den]);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _post1_ne_antifony {\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-25: vytvorenÈ pre modlitbu cez deÚ */
#define _post1_mcd_antifony {\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

		/* 2006-01-24: tu v skutoËnosti zaËÌna POSTNE OBDOBIE I. */

			t = tyzden MOD 2;

		/* ranne chvaly */
			modlitba = MODL_RANNE_CHVALY;
			_post1_hymnus;
			_post1_kcitanie;
			_post1_kresponz;
			_post1_benediktus;
			_post1_prosby;
			_post1_modlitba;
		/* vespery */
			modlitba = MODL_VESPERY;
			_post1_hymnus;
			_post1_kcitanie;
			_post1_kresponz;
			_post1_magnifikat;
			_post1_prosby;
			_post1_modlitba;
		/* 2006-01-24: posv‰tnÈ ËÌtanie */
			modlitba = MODL_POSV_CITANIE;
			_post1_hymnus;
			_post1_citanie1;
			_post1_citanie2;
			_post1_kresponz;
			_post1_modlitba;

		/* 2006-01-25: modlitba cez deÚ MODL_PREDPOLUDNIM + MODL_NAPOLUDNIE + MODL_POPOLUDNI */
			modlitba = MODL_PREDPOLUDNIM;
			_post1_hymnus;
			_post1_mcd_antifony;
			_post1_kcitanie;
			_post1_kresponz;
			_post1_modlitba;
			modlitba = MODL_NAPOLUDNIE;
			_post1_hymnus;
			_post1_mcd_antifony;
			_post1_kcitanie;
			_post1_kresponz;
			_post1_modlitba;
			modlitba = MODL_POPOLUDNI;
			_post1_hymnus;
			_post1_mcd_antifony;
			_post1_kcitanie;
			_post1_kresponz;
			_post1_modlitba;

			if(den == DEN_NEDELA){

			/* prve vespery */
				modlitba = MODL_PRVE_VESPERY;
				_post1_hymnus;
				_post1_ne_antifony;
				_post1_kcitanie;
				_post1_kresponz;
				_post1_magnifikat;
				_post1_prosby;
				_post1_modlitba;
			/* ranne chvaly */
				modlitba = MODL_RANNE_CHVALY;
				_post1_ne_antifony;
			/* druhe vespery */
				modlitba = MODL_VESPERY;
				_post1_ne_antifony;
			}/* nedela */
			else{
			}/* nie nedela */
			break;
/* switch(litobd), case OBD_POSTNE_I -- end --------------------------------------------------- */

/* switch(litobd), case OBD_POSTNE_II -- begin ------------------------------------------------ */
		case OBD_POSTNE_II_VELKY_TYZDEN:/* velky tyzden */
			/* 08/03/2000A.D. */
/* 2006-01-25: upravenÈ pre posv‰tnÈ ËÌtanie
 * 2006-01-25: pre modlitbu cez deÚ (okrem nedele) je hymnus ako pre pÙstne obdobie I.
 */
#define _post2_hymnus {\
	if(((den == DEN_STVRTOK) && (modlitba == MODL_VESPERY))\
	|| ((den == DEN_NEDELA) && ((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)))){\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), nazov_DN_asci[den], ANCHOR_HYMNUS);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	}\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_hymnus(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_hymnus(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _post2_kcitanie {\
	if((den == DEN_NEDELA) && (modlitba == MODL_RANNE_CHVALY)){\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), nazov_DN_asci[den], ANCHOR_KCITANIE);\
		_set_kcitanie(modlitba, _file, _anchor);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s%s%d", nazov_OBD[OBD_POSTNE_I], pismenko_modlitby(modlitba), nazov_DN_asci[den], ANCHOR_KCITANIE, 5);\
		_set_kcitanie(modlitba, nazov_obd_htm[OBD_POSTNE_I], _anchor);\
	}\
	set_LOG_litobd;\
}
/* 2006-01-25: doplnenÈ posv‰tnÈ ËÌtanie 
 * 2006-02-08: modlitba cez deÚ aj posv. ËÌtanie maj˙ responzÛrium rovnakÈ, Ëi je alebo nie je nedeæa
 */
#define _post2_kresponz {\
	if(((den == DEN_STVRTOK) && (modlitba == MODL_VESPERY)) || ((den == DEN_NEDELA) && (modlitba != MODL_PREDPOLUDNIM) && (modlitba != MODL_NAPOLUDNIE) && (modlitba != MODL_POPOLUDNI) && (modlitba != MODL_POSV_CITANIE))){\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_KRESPONZ, nazov_DN_asci[den]);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	}\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_kresponz(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_kresponz(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _post2_prosby {\
	if(((den == DEN_STVRTOK) && (modlitba == MODL_VESPERY)) || (den == DEN_NEDELA)){\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_PROSBY, nazov_DN_asci[den]);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_PROSBY);\
	}\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _post2_benediktus {\
	if(den == DEN_NEDELA){\
		sprintf(_anchor, "%s_%c%s%d%s%c", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, tyzden, nazov_DN_asci[den], _global_den.litrok);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, tyzden, nazov_DN_asci[den]);\
	}\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _post2_magnifikat {\
	if(den == DEN_NEDELA){\
		sprintf(_anchor, "%s_%c%s%d%s%c", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, tyzden, nazov_DN_asci[den], _global_den.litrok);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, tyzden, nazov_DN_asci[den]);\
	}\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-25: upravenÈ: odliön· modlitba je len pre veöpery na Zelen˝ ötvrtok */
#define _post2_modlitba {\
	if((den == DEN_STVRTOK) && (modlitba == MODL_VESPERY)){\
		sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_MODLITBA, tyzden, nazov_DN_asci[den]);\
	}\
	else{\
		sprintf(_anchor, "%s_%s%d%s", nazov_OBD[litobd], ANCHOR_MODLITBA, tyzden, nazov_DN_asci[den]);\
	}\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-25: doplnenÈ posv‰tnÈ ËÌtanie */
#define _post2_antifony {\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona1(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona1(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona2(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona2(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona3(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona3(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
/* 2006-01-25: doplnenÈ posv‰tnÈ ËÌtanie */
#define _post2_citanie1 {\
	sprintf(_anchor, "%s_%c%s_%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE1, tyzden, nazov_DN_asci[den]);\
	_set_citanie1(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _post2_citanie2 {\
	sprintf(_anchor, "%s_%c%s_%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE2, tyzden, nazov_DN_asci[den]);\
	_set_citanie2(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
/* 2006-01-25: vytvorenÈ pre modlitbu cez deÚ */
#define _post2_mcd_antifony {\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-27: pridanÈ pre popis veöpier veækonoËnÈho trojdnia (vr·tane zelenÈho ötvrtka */
#define _vtroj_popis {\
	sprintf(_anchor, "%s_%c%s_%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_POPIS, nazov_DN_asci[den]);\
	if(modlitba == MODL_POSV_CITANIE){\
		set_popis(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		set_popis(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}

		/* 2006-01-24: tu v skutoËnosti zaËÌna POSTNE OBDOBIE II. */

		/* ranne chvaly */
			modlitba = MODL_RANNE_CHVALY;
			_post2_hymnus;
			_post2_antifony;
			_post2_kcitanie;
			_post2_kresponz;
			_post2_benediktus;
			_post2_prosby;
			_post2_modlitba;
		/* vespery */
			modlitba = MODL_VESPERY;
			_post2_hymnus;
			_post2_antifony;
			_post2_kcitanie;
			_post2_kresponz;
			_post2_magnifikat;
			_post2_prosby;
			_post2_modlitba;

		/* 2006-01-25: posv‰tnÈ ËÌtanie */
			modlitba = MODL_POSV_CITANIE;
			_post2_hymnus;
			_post2_citanie1;
			_post2_citanie2;
			_post2_kresponz;
			_post2_modlitba;

		/* 2006-01-25: modlitba cez deÚ MODL_PREDPOLUDNIM + MODL_NAPOLUDNIE + MODL_POPOLUDNI */
			modlitba = MODL_PREDPOLUDNIM;
			_post2_hymnus;
			_post2_mcd_antifony;
			_post2_kcitanie;
			_post2_kresponz;
			_post2_modlitba;
			modlitba = MODL_NAPOLUDNIE;
			_post2_hymnus;
			_post2_mcd_antifony;
			_post2_kcitanie;
			_post2_kresponz;
			_post2_modlitba;
			modlitba = MODL_POPOLUDNI;
			_post2_hymnus;
			_post2_mcd_antifony;
			_post2_kcitanie;
			_post2_kresponz;
			_post2_modlitba;

			if(den == DEN_NEDELA){
				/* Kvetn· nedeæa */

			/* prve vespery */
				modlitba = MODL_PRVE_VESPERY;
				_post2_hymnus;
				_post2_antifony;
				_post2_kcitanie;
				_post2_kresponz;
				_post2_magnifikat;
				_post2_prosby;
				_post2_modlitba;

			/* 2006-01-25: posv‰tnÈ ËÌtanie */
				modlitba = MODL_POSV_CITANIE;
				_post2_antifony;
			}/* nedela */
			else if(den == DEN_STVRTOK){
				/* 2006-01-27: pridan˝ popis k veöper·m zelenÈho ötvrtka */
				modlitba = MODL_VESPERY;
				_vtroj_popis;
			}/* nie nedela ale zelen˝ ötvrtok */
			break;
/* switch(litobd), case OBD_POSTNE_II -- end -------------------------------------------------- */

/* switch(litobd), case OBD_VELKONOCNE_TROJDNIE -- begin -------------------------------------- */
		case OBD_VELKONOCNE_TROJDNIE:/* umucenia a zmrtvychvstania Pana */
			/* 08/03/2000A.D. */
/* 2006-01-26: doplnenÈ posv‰tnÈ ËÌtanie */
#define _vtroj_hymnus {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	sprintf(_anchor, "%s_%c%s%s", nazov_OBD[OBD_VELKONOCNE_TROJDNIE], c, nazov_DN_asci[den], ANCHOR_HYMNUS);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_hymnus(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_hymnus(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _vtroj_kcitanie {\
	sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), nazov_DN_asci[den], ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-26: doplnenÈ posv‰tnÈ ËÌtanie */
#define _vtroj_kresponz {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	sprintf(_anchor, "%s_%c%s%s", nazov_OBD[OBD_VELKONOCNE_TROJDNIE], c, ANCHOR_KRESPONZ, nazov_DN_asci[den]);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_kresponz(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_kresponz(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _vtroj_prosby {\
	sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_PROSBY, nazov_DN_asci[den]);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vtroj_benediktus {\
	sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, tyzden, nazov_DN_asci[den]);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vtroj_magnifikat {\
	sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, tyzden, nazov_DN_asci[den]);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vtroj_modlitba {\
	sprintf(_anchor, "%s_%s%d%s", nazov_OBD[litobd], ANCHOR_MODLITBA, tyzden, nazov_DN_asci[den]);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-26: doplnenÈ posv‰tnÈ ËÌtanie */
#define _vtroj_antifony {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VELKONOCNE_TROJDNIE], nazov_DN_asci[den], c, ANCHOR_ANTIFONA1);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona1(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona1(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VELKONOCNE_TROJDNIE], nazov_DN_asci[den], c, ANCHOR_ANTIFONA2);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona2(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona2(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VELKONOCNE_TROJDNIE], nazov_DN_asci[den], c, ANCHOR_ANTIFONA3);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona3(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona3(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
/* 2006-01-26: doplnenÈ posv‰tnÈ ËÌtanie */
#define _vtroj_citanie1 {\
	sprintf(_anchor, "%s_%c%s_%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE1, nazov_DN_asci[den]);\
	_set_citanie1(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _vtroj_citanie2 {\
	sprintf(_anchor, "%s_%c%s_%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE2, nazov_DN_asci[den]);\
	_set_citanie2(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}

		/* ranne chvaly */
			modlitba = MODL_RANNE_CHVALY;
			_vtroj_hymnus;
			_vtroj_antifony;
			_vtroj_kcitanie;
			_vtroj_kresponz;
			_vtroj_benediktus;
			_vtroj_prosby;
			_vtroj_modlitba;
		/* vespery */
			modlitba = MODL_VESPERY;
			_vtroj_hymnus;
			_vtroj_antifony;
			_vtroj_kcitanie;
			_vtroj_kresponz;
			_vtroj_magnifikat;
			_vtroj_prosby;
			_vtroj_modlitba;

		/* 2006-01-26: posv‰tnÈ ËÌtanie */
			modlitba = MODL_POSV_CITANIE;
			_vtroj_hymnus;
			_vtroj_antifony;
			_vtroj_citanie1;
			_vtroj_citanie2;
			_vtroj_kresponz;
			_vtroj_modlitba;

		/* 2006-01-26: modlitba cez deÚ MODL_PREDPOLUDNIM + MODL_NAPOLUDNIE + MODL_POPOLUDNI */
			modlitba = MODL_PREDPOLUDNIM;
			_vtroj_hymnus;
			_vtroj_antifony;
			_vtroj_kcitanie;
			_vtroj_kresponz;
			_vtroj_modlitba;
			modlitba = MODL_NAPOLUDNIE;
			_vtroj_hymnus;
			_vtroj_antifony;
			_vtroj_kcitanie;
			_vtroj_kresponz;
			_vtroj_modlitba;
			modlitba = MODL_POPOLUDNI;
			_vtroj_hymnus;
			_vtroj_antifony;
			_vtroj_kcitanie;
			_vtroj_kresponz;
			_vtroj_modlitba;

			if(den == DEN_NEDELA){
				modlitba = MODL_RANNE_CHVALY;
				_set_zalmy_velkonocna_nedela(modlitba);
				modlitba = MODL_VESPERY;
				_set_zalmy_velkonocna_nedela(modlitba);
				modlitba = MODL_POSV_CITANIE;
				_set_zalmy_velkonocna_nedela(modlitba);
				/* 2006-01-27: pridan˝ popis k posv. ËÌtaniu veækonoËnej nedele */
				_vtroj_popis;
				modlitba = MODL_PREDPOLUDNIM;
				_set_zalmy_velkonocna_nedela(modlitba);
				modlitba = MODL_NAPOLUDNIE;
				_set_zalmy_velkonocna_nedela(modlitba);
				modlitba = MODL_POPOLUDNI;
				_set_zalmy_velkonocna_nedela(modlitba);
			}/* nedela */
			else if(den == DEN_SOBOTA){
				modlitba = MODL_RANNE_CHVALY;
				_set_zalmy_biela_sobota(modlitba);
				modlitba = MODL_VESPERY;
				_set_zalmy_biela_sobota(modlitba);
				modlitba = MODL_POSV_CITANIE;
				_set_zalmy_biela_sobota(modlitba);
				modlitba = MODL_PREDPOLUDNIM;
				_set_zalmy_biela_sobota(modlitba);
				modlitba = MODL_NAPOLUDNIE;
				_set_zalmy_biela_sobota(modlitba);
				modlitba = MODL_POPOLUDNI;
				_set_zalmy_biela_sobota(modlitba);
			}/* nie nedela, ale biela sobota */
			else if(den == DEN_PIATOK){
				modlitba = MODL_VESPERY;
				_set_zalmy_velky_piatok(modlitba);
				/* 2006-01-27: pridan˝ popis k veöper·m veækÈho piatka */
				_vtroj_popis;
				modlitba = MODL_POSV_CITANIE;
				_set_zalmy_velky_piatok(modlitba);
				modlitba = MODL_PREDPOLUDNIM;
				_set_zalmy_velky_piatok(modlitba);
				modlitba = MODL_NAPOLUDNIE;
				_set_zalmy_velky_piatok(modlitba);
				modlitba = MODL_POPOLUDNI;
				_set_zalmy_velky_piatok(modlitba);
			}/* nie nedela, ani sobota, ale veæk˝ piatok */
			break;
/* switch(litobd), case OBD_VELKONOCNE_TROJDNIE -- end ---------------------------------------- */

/* switch(litobd), case OBD_VELKONOCNE_I -- begin --------------------------------------------- */
		case OBD_VELKONOCNE_I:/* do nanebovstupenia pana */
			/* 09/03/2000A.D. */
/* zabezpecime nahodnost pri hymne vo feriu, kedy sa "podla lubovole" mozre brat nie nedelny hymnus */
/* ((_global_den.den MOD 3) == 0) */
/* 2006-01-27: pridan· modlitba posv‰tnÈ ËÌtanie 
 * 2006-02-08: pre modlitbu cez deÚ nem· nedeæa odliön˝ hymnus, preto "podæa æubovÙle" nie pre modlitbu cez deÚ
 * 2006-02-09: skorektnenÈ: rovnocenn˝ test: nie je MCD a (nedeæa alebo MOD 3); MOD aj vzhæadom k modlitbe
 */
#define _velk1_hymnus {\
	if(((den == DEN_NEDELA) || (((_global_den.den + modlitba) MOD 3) == 0))\
		&& ((modlitba != MODL_PREDPOLUDNIM) && (modlitba != MODL_NAPOLUDNIE) && (modlitba != MODL_POPOLUDNI))\
	){\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_HYMNUS, nazov_DN_asci[DEN_NEDELA]);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	}\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_hymnus(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_hymnus(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}

#define _velk1_kcitanie {\
	sprintf(_anchor, "%s_%c%s%s", nazov_OBD[OBD_VELKONOCNE_I], pismenko_modlitby(modlitba), nazov_DN_asci[den], ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-27: pridan· modlitba posv‰tnÈ ËÌtanie */
#define _velk1_kresponz {\
	if(((den == DEN_NEDELA) || (modlitba == MODL_POSV_CITANIE))\
		&& (modlitba != MODL_PREDPOLUDNIM) && (modlitba != MODL_NAPOLUDNIE) && (modlitba != MODL_POPOLUDNI)){\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_KRESPONZ, nazov_DN_asci[den]);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	}\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_kresponz(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_kresponz(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
/* 2006-01-27: doplnenÈ posv‰tnÈ ËÌtanie */
#define _velk1_citanie1 {\
	sprintf(_anchor, "%s_%c%s_%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE1, tyzden, nazov_DN_asci[den]);\
	_set_citanie1(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _velk1_citanie2 {\
	sprintf(_anchor, "%s_%c%s_%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE2, tyzden, nazov_DN_asci[den]);\
	_set_citanie2(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _velk1_prosby {\
	sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[OBD_VELKONOCNE_I], pismenko_modlitby(modlitba), ANCHOR_PROSBY, t, nazov_DN_asci[den]);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _velk1_benediktus {\
	if(den == DEN_NEDELA){\
		sprintf(_anchor, "%s_%c%s%d%s%c", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, tyzden, nazov_DN_asci[den], _global_den.litrok);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, tyzden, nazov_DN_asci[den]);\
	}\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _velk1_magnifikat {\
	if(den == DEN_NEDELA){\
		sprintf(_anchor, "%s_%c%s%d%s%c", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, tyzden, nazov_DN_asci[den], _global_den.litrok);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, tyzden, nazov_DN_asci[den]);\
	}\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _velk1_modlitba {\
	sprintf(_anchor, "%s_%s%d%s", nazov_OBD[litobd], ANCHOR_MODLITBA, tyzden, nazov_DN_asci[den]);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-28: doplnenÈ antifÛny pre posv‰tnÈ ËÌtania */
#define _velk1_ne_antifony {\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona1(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona1(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona2(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona2(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona3(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona3(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
/* 2006-01-28: doplnenÈ antifÛny pre modlitbu cez deÚ */
#define _velk1_mcd_antifony {\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

		/* 2006-01-24: tu v skutoËnosti zaËÌna VEºKONO»N… OBDOBIE I. */

			t = tyzden MOD 2;

			if(_global_den.denvr == _global_r._NANEBOVSTUPENIE_PANA.denvr){
				/* nanebovstupenie sice ma rovnake kotvy, ale v inom fajli; 10/03/2000A.D. */
				/* 2006-02-09: odËlenenÈ samostatne, lebo sa tu ökaredo natvrdo pre rannÈ chv·ly 
				 *             a veöpety nastavuje den = DEN_NEDELA 
				 */
				mystrcpy(_file, FILE_NANEBOVSTUPENIE, MAX_STR_AF_FILE);
				mystrcpy(_file_pc, FILE_NANEBOVSTUPENIE, MAX_STR_AF_FILE); /* 2006-02-09: doplnenÈ */
				den = DEN_NEDELA;
				Log("  ide o nanebovstupenie Pana: _file = `%s', den = %s...\n", _file, nazov_dna(den));
				modlitba = MODL_PRVE_VESPERY;
				_set_zalmy_nanebovstupenie(modlitba);
				modlitba = MODL_RANNE_CHVALY;
				_set_zalmy_nanebovstupenie(modlitba);
				modlitba = MODL_VESPERY;
				_set_zalmy_nanebovstupenie(modlitba);

				/* ranne chvaly */
				modlitba = MODL_RANNE_CHVALY;
				_velk1_hymnus;
				_velk1_kcitanie;
				_velk1_kresponz;
				_velk1_benediktus;
				_velk1_prosby;
				_velk1_modlitba;

				/* vespery */
				modlitba = MODL_VESPERY;
				_velk1_hymnus;
				_velk1_kcitanie;
				_velk1_kresponz;
				_velk1_magnifikat;
				_velk1_prosby;
				_velk1_modlitba;

				/* 2006-01-27: pridanÈ posv. ËÌtania a modlitba cez deÚ */
				modlitba = MODL_POSV_CITANIE;
				_set_zalmy_nanebovstupenie(modlitba);
				modlitba = MODL_PREDPOLUDNIM;
				_set_zalmy_nanebovstupenie(modlitba);
				modlitba = MODL_NAPOLUDNIE;
				_set_zalmy_nanebovstupenie(modlitba);
				modlitba = MODL_POPOLUDNI;
				_set_zalmy_nanebovstupenie(modlitba);

				modlitba = MODL_PRVE_VESPERY;
				_velk1_hymnus;
				_velk1_kcitanie;
				_velk1_kresponz;
				_velk1_magnifikat;
				_velk1_prosby;
				_velk1_modlitba;
				_velk1_ne_antifony;
				modlitba = MODL_RANNE_CHVALY;
				_velk1_ne_antifony;
				modlitba = MODL_VESPERY;
				_velk1_ne_antifony;

				/* 2006-02-09: nasp‰ù pre posv. ËÌtanie a modlitbu cez deÚ */
				den = DEN_STVRTOK;
				modlitba = MODL_POSV_CITANIE;
				_velk1_hymnus;
				_velk1_ne_antifony;
				_velk1_citanie1;
				_velk1_citanie2;
				_velk1_kresponz;
				_velk1_modlitba;

				modlitba = MODL_PREDPOLUDNIM;
				_velk1_hymnus;
				_velk1_mcd_antifony;
				_velk1_kresponz;
				_velk1_kcitanie;
				_velk1_modlitba;
				modlitba = MODL_NAPOLUDNIE;
				_velk1_hymnus;
				_velk1_mcd_antifony;
				_velk1_kresponz;
				_velk1_kcitanie;
				_velk1_modlitba;
				modlitba = MODL_POPOLUDNI;
				_velk1_hymnus;
				_velk1_mcd_antifony;
				_velk1_kresponz;
				_velk1_kcitanie;
				_velk1_modlitba;

			}/* je nanebovst˙penie */
			else{
				
				/* ranne chvaly */
				modlitba = MODL_RANNE_CHVALY;
				_velk1_hymnus;
				_velk1_kcitanie;
				_velk1_kresponz;
				_velk1_benediktus;
				_velk1_prosby;
				_velk1_modlitba;

				/* vespery */
				modlitba = MODL_VESPERY;
				_velk1_hymnus;
				_velk1_kcitanie;
				_velk1_kresponz;
				_velk1_magnifikat;
				_velk1_prosby;
				_velk1_modlitba;

				/* 2006-01-27: modlitba cez deÚ a posv‰tnÈ ËÌtania */
				modlitba = MODL_POSV_CITANIE;
				_velk1_hymnus;
				_velk1_citanie1;
				_velk1_citanie2;
				_velk1_kresponz;
				_velk1_modlitba;

				modlitba = MODL_PREDPOLUDNIM;
				_velk1_hymnus;
				_velk1_mcd_antifony;
				_velk1_kresponz;
				_velk1_kcitanie;
				_velk1_modlitba;
				modlitba = MODL_NAPOLUDNIE;
				_velk1_hymnus;
				_velk1_mcd_antifony;
				_velk1_kresponz;
				_velk1_kcitanie;
				_velk1_modlitba;
				modlitba = MODL_POPOLUDNI;
				_velk1_hymnus;
				_velk1_mcd_antifony;
				_velk1_kresponz;
				_velk1_kcitanie;
				_velk1_modlitba;

				if(den == DEN_NEDELA){
					modlitba = MODL_PRVE_VESPERY;
					_velk1_hymnus;
					_velk1_kcitanie;
					_velk1_kresponz;
					_velk1_magnifikat;
					_velk1_prosby;
					_velk1_modlitba;
					_velk1_ne_antifony;
					modlitba = MODL_RANNE_CHVALY;
					_velk1_ne_antifony;
					modlitba = MODL_VESPERY;
					_velk1_ne_antifony;
					/* 2006-02-09: doplnenÈ */
					modlitba = MODL_POSV_CITANIE;
					_set_antifony_velk_pc(den, tyzden, modlitba);
					/* toto sa musÌ urobiù nakoniec, lebo sa tam menÌ s˙bor _file_pc */

				}/* nedela */
			}/* nie je nanebovst˙penie */
			break;
/* switch(litobd), case OBD_VELKONOCNE_I -- end ----------------------------------------------- */

/* switch(litobd), case OBD_VELKONOCNE_II -- begin -------------------------------------------- */
		case OBD_VELKONOCNE_II:/* po nanebovstupeni pana */
			/* 10/03/2000A.D. */
/* 2006-02-11: doplnenÈ posv‰tnÈ ËÌtanie */
#define _velk2_hymnus {\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_hymnus(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_hymnus(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}

/* citania ako v OBD_VELKONOCNE_I; 7. tyzden ma na vespery vlastne citanie 
 * 2006-02-11: oprava
 */
#define _velk2_kcitanie {\
	Log("\n\n _velk2_kcitanie \n\n");\
	if(((den == DEN_NEDELA) || (modlitba == MODL_RANNE_CHVALY) || (tyzden == 6))\
		/* 2006-02-11: modlitba cez deÚ */\
		|| (modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[OBD_VELKONOCNE_I], pismenko_modlitby(modlitba), nazov_DN_asci[den], ANCHOR_KCITANIE);\
		_set_kcitanie(modlitba, nazov_obd_htm[OBD_VELKONOCNE_I], _anchor);\
	}\
	else /* if((modlitba == MODL_VESPERY) && (tyzden == 7)) alebo posv. ËÌtanie mimo nedele */{\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), nazov_DN_asci[den], ANCHOR_KCITANIE);\
		_set_kcitanie(modlitba, _file, _anchor);\
	}\
	set_LOG_litobd;\
}

#define _velk2_prosby {\
	sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[OBD_VELKONOCNE_I], pismenko_modlitby(modlitba), ANCHOR_PROSBY, t, nazov_DN_asci[den]);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _velk2_benediktus {\
	if(den == DEN_NEDELA){\
		sprintf(_anchor, "%s_%c%s%d%s%c", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, tyzden, nazov_DN_asci[den], _global_den.litrok);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, tyzden, nazov_DN_asci[den]);\
	}\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _velk2_magnifikat {\
	if(den == DEN_NEDELA){\
		sprintf(_anchor, "%s_%c%s%d%s%c", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, tyzden, nazov_DN_asci[den], _global_den.litrok);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, tyzden, nazov_DN_asci[den]);\
	}\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _velk2_modlitba {\
	sprintf(_anchor, "%s_%s%d%s", nazov_OBD[litobd], ANCHOR_MODLITBA, tyzden, nazov_DN_asci[den]);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _velk2_ne_antifony {\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* zoslanie ducha sv. */
#define _zds_hymnus {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_ZOSLANIE_DUCHA_SV, pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	_set_hymnus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _zds_kcitanie {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_ZOSLANIE_DUCHA_SV, pismenko_modlitby(modlitba), ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _zds_kresponz {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_ZOSLANIE_DUCHA_SV, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _zds_prosby {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_ZOSLANIE_DUCHA_SV, pismenko_modlitby(modlitba), ANCHOR_PROSBY);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _zds_benediktus {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_ZOSLANIE_DUCHA_SV, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _zds_magnifikat {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_ZOSLANIE_DUCHA_SV, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-02-11: opravenÈ: prvÈ veöpery maj˙ in˙ modlitbu ako ostatnÈ hodinky;
 * in˙ modlitbu m· aj modlitba cez deÚ */
#define _zds_modlitba {\
	c = pismenko_modlitby(modlitba);\
	if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){\
		c = pismenko_modlitby(MODL_NAPOLUDNIE);\
	}\
	if((modlitba == MODL_PRVE_VESPERY) || (modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI))\
		sprintf(_anchor, "%s_%c%s", ANCHOR_ZOSLANIE_DUCHA_SV, c, ANCHOR_MODLITBA);\
	else\
		sprintf(_anchor, "%s_%s", ANCHOR_ZOSLANIE_DUCHA_SV, ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

#define _zds_antifony {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_ZOSLANIE_DUCHA_SV, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", ANCHOR_ZOSLANIE_DUCHA_SV, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", ANCHOR_ZOSLANIE_DUCHA_SV, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

/* 2006-02-11: doplnenÈ posv‰tnÈ ËÌtanie */
#define _zds_citanie1 {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_ZOSLANIE_DUCHA_SV, pismenko_modlitby(modlitba), ANCHOR_CITANIE1);\
	_set_citanie1(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _zds_citanie2 {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_ZOSLANIE_DUCHA_SV, pismenko_modlitby(modlitba), ANCHOR_CITANIE2);\
	_set_citanie2(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}

		/* 2006-01-24: tu v skutoËnosti zaËÌna VEºKONO»N… OBDOBIE II. */

			t = tyzden MOD 2;

			/* ranne chvaly */
			modlitba = MODL_RANNE_CHVALY;
			_velk2_hymnus;
			_velk2_kcitanie;
			_velk1_kresponz;
			_velk2_benediktus;
			_velk2_prosby;
			_velk2_modlitba;

			/* vespery */
			modlitba = MODL_VESPERY;
			_velk2_hymnus;
			_velk2_kcitanie;
			_velk1_kresponz;
			_velk2_magnifikat;
			_velk2_prosby;
			_velk2_modlitba;

			/* 2006-02-09: modlitba cez deÚ a posv‰tnÈ ËÌtania */
			modlitba = MODL_POSV_CITANIE;
			_velk2_hymnus;
			_velk1_citanie1;
			_velk1_citanie2;
			_velk1_kresponz;
			_velk2_modlitba;

			modlitba = MODL_PREDPOLUDNIM;
			_velk1_hymnus;
			_velk1_mcd_antifony;
			_velk1_kresponz;
			_velk2_kcitanie;
			_velk2_modlitba;
			modlitba = MODL_NAPOLUDNIE;
			_velk1_hymnus;
			_velk1_mcd_antifony;
			_velk1_kresponz;
			_velk2_kcitanie;
			_velk2_modlitba;
			modlitba = MODL_POPOLUDNI;
			_velk1_hymnus;
			_velk1_mcd_antifony;
			_velk1_kresponz;
			_velk2_kcitanie;
			_velk2_modlitba;

			if(den == DEN_NEDELA){
				if(_global_den.denvr == _global_r._ZOSLANIE_DUCHA_SV.denvr){
					/* zoslanie ducha sv.; 10/03/2000A.D. */
					mystrcpy(_file, FILE_ZOSLANIE_DUCHA_SV, MAX_STR_AF_FILE);
					mystrcpy(_file_pc, FILE_ZOSLANIE_DUCHA_SV, MAX_STR_AF_FILE);
					mystrcpy(_anchor, ANCHOR_ZOSLANIE_DUCHA_SV, MAX_STR_AF_ANCHOR);
					Log("  ide o zoslanie Ducha Sv.: _file = `%s', _anchor = %s...\n", _file, _anchor);
					modlitba = MODL_PRVE_VESPERY;
					_set_zalmy_zoslanie_ducha_sv(modlitba);
					_zds_hymnus;
					_zds_kcitanie;
					_zds_kresponz;
					_zds_magnifikat;
					_zds_prosby;
					_zds_modlitba;
					_zds_antifony;
					modlitba = MODL_RANNE_CHVALY;
					_set_zalmy_zoslanie_ducha_sv(modlitba);
					_zds_hymnus;
					_zds_kcitanie;
					_zds_kresponz;
					_zds_benediktus;
					_zds_prosby;
					_zds_modlitba;
					_zds_antifony;
					modlitba = MODL_VESPERY;
					_set_zalmy_zoslanie_ducha_sv(modlitba);
					_zds_hymnus;
					_zds_kcitanie;
					_zds_kresponz;
					_zds_magnifikat;
					_zds_prosby;
					_zds_modlitba;
					_zds_antifony;

					/* 2006-01-27: pridanÈ posv. ËÌtania a modlitba cez deÚ, len ûalmy
					 * 2006-02-11: dokonËenÈ posv‰tnÈ ËÌtania a modlitba cez deÚ
					 */
					modlitba = MODL_POSV_CITANIE;
					_set_zalmy_zoslanie_ducha_sv(modlitba);
					_zds_antifony;
					_zds_hymnus;
					_zds_citanie1;
					_zds_citanie2;
					_zds_kresponz;
					_zds_modlitba;

					modlitba = MODL_PREDPOLUDNIM;
					_set_zalmy_zoslanie_ducha_sv(modlitba);
					_zds_antifony;
					_zds_hymnus;
					_zds_kresponz;
					_zds_kcitanie;
					_zds_modlitba;
					modlitba = MODL_NAPOLUDNIE;
					_set_zalmy_zoslanie_ducha_sv(modlitba);
					_zds_antifony;
					_zds_hymnus;
					_zds_kresponz;
					_zds_kcitanie;
					_zds_modlitba;
					modlitba = MODL_POPOLUDNI;
					_set_zalmy_zoslanie_ducha_sv(modlitba);
					_zds_antifony;
					_zds_hymnus;
					_zds_kresponz;
					_zds_kcitanie;
					_zds_modlitba;

				}
				else{
					modlitba = MODL_PRVE_VESPERY;
					_velk2_hymnus;
					_velk2_kcitanie;
					_velk1_kresponz;
					_velk2_magnifikat;
					_velk2_prosby;
					_velk2_modlitba;
					_velk2_ne_antifony;
					modlitba = MODL_RANNE_CHVALY;
					_velk2_ne_antifony;
					modlitba = MODL_VESPERY;
					_velk2_ne_antifony;
					/* 2006-02-09: doplnenÈ */
					modlitba = MODL_POSV_CITANIE;
					_set_antifony_velk_pc(den, tyzden, modlitba);
					/* toto sa musÌ urobiù nakoniec, lebo sa tam menÌ s˙bor _file_pc */

				}/* nie je zoslanie ds */
			}/* nedela */
			break;
/* switch(litobd), case OBD_VELKONOCNE_II -- end ---------------------------------------------- */

/* switch(litobd), case OBD_VELKONOCNA_OKTAVA -- begin ---------------------------------------- */
		case OBD_VELKONOCNA_OKTAVA:/* velkonocna nedela -- 2. velk. ne */
			/* velkonocna oktava: 09/03/2000A.D.
			 *    - hymnus, antifony 1 -- 3, zalmy a chvalospev su z velkonocnej nedele;
			 *    - responzorium, 'Toto je den...' ako na velkonocnu nedelu;
			 *    - citanie,  prosby: z velkonocneho obdobia I,
			 *    - ant. na benediktus/magnifikat a modlitba: vlastne;
			 */
#define _vnokt_benediktus {\
	sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, nazov_DN_asci[den]);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vnokt_magnifikat {\
	sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, nazov_DN_asci[den]);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vnokt_modlitba {\
	sprintf(_anchor, "%s_%s%s", nazov_OBD[litobd], ANCHOR_MODLITBA, nazov_DN_asci[den]);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

		/* 2006-01-24: tu v skutoËnosti zaËÌna VEºKONO»N¡ OKT¡VA */

			t = tyzden MOD 2;

		/* teda najprv nastavime vlastne ant. na benediktus/magnifikat a modlitbu */
		/* ranne chvaly */
			modlitba = MODL_RANNE_CHVALY;
			_vnokt_benediktus;
			_vnokt_modlitba;
		/* vespery */
			modlitba = MODL_VESPERY;
			_vnokt_magnifikat;
			_vnokt_modlitba;
		/* teraz nastavime zalmy z velkonocnej nedele */
			modlitba = MODL_RANNE_CHVALY;
			_set_zalmy_velkonocna_nedela(modlitba);
			modlitba = MODL_VESPERY;
			_set_zalmy_velkonocna_nedela(modlitba);
		/* a veci pre prve vespery */
			if(den == DEN_NEDELA){
				modlitba = MODL_PRVE_VESPERY;
				_vnokt_magnifikat;
				_vnokt_modlitba;
				_set_zalmy_velkonocna_nedela(modlitba);
			}/* nedela */

		/* 2006-01-27: ûalmy pre modlitbu cez deÚ a posv‰tnÈ ËÌtania (pË-antifÛny) */
			modlitba = MODL_POSV_CITANIE;
			_set_zalmy_velk_oktava(den, modlitba);
			_vnokt_modlitba;
			_velk1_ne_antifony;
			_velk1_kresponz;
			_velk1_citanie1;
			_velk1_citanie2;

			modlitba = MODL_PREDPOLUDNIM;
			_set_zalmy_velk_oktava(den, modlitba);
			_vnokt_modlitba;
			modlitba = MODL_NAPOLUDNIE;
			_set_zalmy_velk_oktava(den, modlitba);
			_vnokt_modlitba;
			modlitba = MODL_POPOLUDNI;
			_set_zalmy_velk_oktava(den, modlitba);
			_vnokt_modlitba;

		/* dalej nastavime citanie a prosby z velkonocneho obd. I */
			mystrcpy(_file, nazov_obd_htm[OBD_VELKONOCNE_I], MAX_STR_AF_FILE); /* aby bolo z velkonocneho obd. I */
		/* ranne chvaly */
			modlitba = MODL_RANNE_CHVALY;
			_velk1_kcitanie;
			_velk1_prosby;
		/* vespery */
			modlitba = MODL_VESPERY;
			_velk1_kcitanie;
			_velk1_prosby;
		/* a veci pre prve vespery */
			if(den == DEN_NEDELA){
				modlitba = MODL_PRVE_VESPERY;
				_velk1_kcitanie;
				_velk1_prosby;
			}/* nedela */

		/* 2006-01-27: kr·tke ËÌtanie pre modlitbu cez deÚ */
			modlitba = MODL_PREDPOLUDNIM;
			_velk1_kcitanie;
			modlitba = MODL_NAPOLUDNIE;
			_velk1_kcitanie;
			modlitba = MODL_POPOLUDNI;
			_velk1_kcitanie;

		/* napokon nastavime hymnus, antifony a kratke resp. z velkonocnej nedele */
			mystrcpy(_file, nazov_obd_htm[OBD_VELKONOCNE_TROJDNIE], MAX_STR_AF_FILE); /* aby bolo z velkonocnej nedele */
			mystrcpy(_file_pc, nazov_obd_htm_pc[OBD_VELKONOCNE_TROJDNIE], MAX_STR_AF_FILE); /* aby bolo z velkonocnej nedele */
			den = DEN_NEDELA;
		/* ranne chvaly */
			modlitba = MODL_RANNE_CHVALY;
			_vtroj_hymnus;
			_vtroj_antifony;
			_vtroj_kresponz;
		/* vespery */
			modlitba = MODL_VESPERY;
			_vtroj_hymnus;
			_vtroj_antifony;
			_vtroj_kresponz;
		/* 2006-01-27: modlitba cez deÚ a posv‰tnÈ ËÌtania */
			modlitba = MODL_POSV_CITANIE;
			_vtroj_hymnus;
			modlitba = MODL_PREDPOLUDNIM;
			_vtroj_hymnus;
			_vtroj_antifony;
			_vtroj_kresponz;
			modlitba = MODL_NAPOLUDNIE;
			_vtroj_hymnus;
			_vtroj_antifony;
			_vtroj_kresponz;
			modlitba = MODL_POPOLUDNI;
			_vtroj_hymnus;
			_vtroj_antifony;
			_vtroj_kresponz;
		/* a veci pre prve vespery */
			if(den == DEN_NEDELA){
				modlitba = MODL_PRVE_VESPERY;
				_vtroj_hymnus;
				_vtroj_antifony;
				_vtroj_kresponz;
			}/* nedela */

			break;
/* switch(litobd), case OBD_VELKONOCNA_OKTAVA -- end ------------------------------------------ */

	}/* switch(litobd) */
	/* koniec velkeho switchu, podla ktoreho sa priradia zakladne udaje */

#ifdef DETAIL_LOG_GLOBAL_DEN
	Log("_global_den (nastavene v dbzaltar.cpp::liturgicke_obdobie() po velkom switchi, pred druhym spustanim sviatky_svatych()):\n");
	Log(_global_den);
#endif
	/* -------------------------------------------------------------------- */
	/* nasledujuca cast berie do uvahy, kedy sa ma `robit' svaty */
	/* je to cast prevzata z dnes.cpp::init_global_string(); */
	_struct_dm _local_den;
	_INIT_DM(_local_den); /* 2003-08-11 pridane */

	short int obyc = NIE;
	/* najprv priradime do _local_den to, co tam ma byt */
	if(poradie_svateho > 0){
		/* sviatky (spomienky, ls) svatych */
		switch(poradie_svateho){
			case 4:
				/* do _local_den priradim slavenie pm v sobotu v dalsom */
				_local_den = _global_pm_sobota;
				/* ale predsalen aspon _local_den = _global_pm_sobota; urobim tu; 04/07/2000A.D. */
				break; /* case 4: */
			case 1:
				/* do _local_den priradim dane slavenie */
				_local_den = _global_svaty1;
				Log("spustam druhykrat sviatky_svatych(), tentokrat pre %d. svateho\n", poradie_svateho);
				sviatky_svatych(_local_den.den, _local_den.mesiac, poradie_svateho, 2);
				break; /* case 1: */
			case 2:
				if(_global_pocet_svatych > 1){
					/* do _local_den priradim dane slavenie */
					_local_den = _global_svaty2;
					Log("spustam druhykrat sviatky_svatych(), tentokrat pre %d. svateho\n", poradie_svateho);
					sviatky_svatych(_local_den.den, _local_den.mesiac, poradie_svateho, 2);
				}
				else{
					/* sice chce svateho c. 2, ale mam len jedneho */
					Log("-- Error: _global_svaty2 not assigned\n");
					Export("%s\n", "Error: _global_svaty2 not assigned");
					ALERT;
				}
				break; /* case 2: */
			case 3:
				if(_global_pocet_svatych > 2){
					/* teraz do _local_den priradim dane slavenie */
					_local_den = _global_svaty3;
					Log("spustam druhykrat sviatky_svatych(), tentokrat pre %d. svateho\n", poradie_svateho);
					sviatky_svatych(_local_den.den, _local_den.mesiac, poradie_svateho, 2);
				}
				else{
					/* sice chce svateho c. 3, ale nemam troch */
					Log("-- Error: _global_svaty3 not assigned\n");
					Export("%s\n", "Error: _global_svaty3 not assigned");
					ALERT;
				}
				break; /* case 3: */
			case 5:
				Log("-- Error: poradie_svateho == 5\n");
				Export("Error: poradie_svateho == 5\n");
				ALERT;
				break;
			case 0:
				/* je smiesne, ze case 0 tu vobec je: ved toto je mrtvy kus kodu! 04/07/2000A.D. */
				/* bezny den */
				if(_global_svaty1.smer >= 12){
					/* ak je to iba lubovolna spomienka, tak vsedny den */
					obyc = ANO;
					_local_den = _global_den;
				}
				else{
					/* sice chce obycajny den, ale nemoze byt */
					Log("-- Error: _global_den not assigned\n");
					Export("%s\n", "Error: _global_den not assigned");
					ALERT;
				}
				break; /* case 0: */
		}/* switch(poradie_svateho) */
	}
	else if((_global_den.denvt == DEN_NEDELA) ||
		(_global_den.prik == PRIKAZANY_SVIATOK)){
		/* _local_den ostava _global_den */
		_local_den = _global_den;
	}
	else if((poradie_svateho > 0) && (_global_pocet_svatych > 0)){
	}/* if(_global_pocet_svatych > 0) */
	else{
		/* obycajny den */
		obyc = ANO;
		_local_den = _global_den;
	}
	/* este spomienka panny marie v sobotu, cl. 15 */
	/* najprv sa spytame tej soboty, ci nahodou nie je 
	   spomienka neposkvrneneho srdca panny marie;
	   ak je, tak uprednostnime tuto.
	   pridane 04/07/2000A.D. */
	/* 2006-02-02: pridanÈ posv. ËÌtania a upravenÈ; 
	 * keÔûe smer == 11 pouûÌvame pre lok·lne povinnÈ spomienky, 
	 * upravili sme kontrolu z 12 na 11
	 */
	if(_global_den.denvr == (_global_r._ZOSLANIE_DUCHA_SV.denvr + 20)){
		/* pri spusteni liturgicke_obdobie(); spomienka neposkvrneneho srdca panny marie */
		Log("/* pri spusteni liturgicke_obdobie(); spomienka neposkvrneneho srdca panny marie */\n");
		Log("spustam druhykrat sviatky_svatych(), tentokrat pre %d. svateho\n", poradie_svateho);
		_local_den = _global_den;
		sviatky_svatych(_local_den.den, _local_den.mesiac, poradie_svateho, 2);
	}
	if((_global_den.litobd == OBD_CEZ_ROK) &&
		(_global_den.denvt == DEN_SOBOTA) &&
		((_global_den.denvr != (_global_r._ZOSLANIE_DUCHA_SV.denvr + 20))) && /* pridane 04/07/2000A.D. */
		(
			((_global_den.smer >= 11) && (_global_pocet_svatych == 0)) ||
			((_global_svaty1.smer >= 11) && (_global_pocet_svatych > 0))) &&
		(poradie_svateho == 4)){
		/* teraz do _global_den priradim dane slavenie */
		_local_den = _global_pm_sobota;
		mystrcpy(_file, FILE_SPOM_PM_SOBOTA, MAX_STR_AF_FILE);

		/* rannÈ chv·ly */

		modlitba = MODL_RANNE_CHVALY;
		/* hymnus */
		/* su tri hymny, preto ich dame podla tyzzal MOD 3 (0, 1, 2) */
		sprintf(_anchor, "%s%c_%s%d", SPOM_PM_SOBOTA, pismenko_modlitby(modlitba), ANCHOR_HYMNUS, tyzzal MOD 3);
		_set_hymnus(modlitba, _file, _anchor);
		set_LOG_litobd;
		/* kratke citanie */
		/* su tri, preto ich dame podla tyzzal MOD 3 (0, 1, 2) */
		sprintf(_anchor, "%s%c_%s%d", SPOM_PM_SOBOTA, pismenko_modlitby(modlitba), ANCHOR_KCITANIE, tyzzal MOD 3);
		_set_kcitanie(modlitba, _file, _anchor);
		set_LOG_litobd;
		/* kratke responzorium  */
		/* su tri, preto ich dame podla tyzzal MOD 3 (0, 1, 2) */
		sprintf(_anchor, "%s%c_%s%d", SPOM_PM_SOBOTA, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ, tyzzal MOD 3);
		_set_kresponz(modlitba, _file, _anchor);
		set_LOG_litobd;
		/* benediktus */
		/* je ich 6, takze tyzzal MOD 6 + 1 (1 -- 6) */
		/* preto "+ 1", aby sme dodrzali povodne cislovanie */
		sprintf(_anchor, "%s%c_%s%d", SPOM_PM_SOBOTA, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, tyzzal MOD 6);
		_set_benediktus(modlitba, _file, _anchor);
		set_LOG_litobd;
		/* prosby */
		/* su 2, takze tyzzal MOD 2 (0, 1) */
		sprintf(_anchor, "%s%c_%s%d", SPOM_PM_SOBOTA, pismenko_modlitby(modlitba), ANCHOR_PROSBY, tyzzal MOD 2);
		_set_prosby(modlitba, _file, _anchor);
		set_LOG_litobd;
		/* modlitba */
		/* je ich 6, takze tyzzal MOD 6 + 1 (1 -- 6) */
		/* preto "+ 1", aby sme dodrzali povodne cislovanie */
		sprintf(_anchor, "%s%c_%s%d", SPOM_PM_SOBOTA, pismenko_modlitby(modlitba), ANCHOR_MODLITBA, tyzzal MOD 6);
		_set_modlitba(modlitba, _file, _anchor);
		set_LOG_litobd;

		/* 2006-02-02: pridanÈ posv‰tnÈ ËÌtanie */

		modlitba = MODL_POSV_CITANIE;
		/* hymnus */
		/* su tri hymny, preto ich dame podla tyzzal MOD 3 (0, 1, 2) */
		sprintf(_anchor, "%s%c_%s%d", SPOM_PM_SOBOTA, pismenko_modlitby(modlitba), ANCHOR_HYMNUS, tyzzal MOD 3);
		_set_hymnus(modlitba, _file, _anchor);
		set_LOG_litobd;

		/* antifÛny, ûalmy, verö a prvÈ ËÌtanie s responzÛriom sa berie z prÌsluönej soboty */

		/* druhÈ ËÌtanie */
		/* s˙ ötyri hymny, preto ich d·me podæa tyzzal MOD 4 (0, 1, 2, 3) */
		sprintf(_anchor, "%s%c_%s%d", SPOM_PM_SOBOTA, pismenko_modlitby(modlitba), ANCHOR_CITANIE2, tyzzal MOD 4);
		_set_citanie2(modlitba, _file, _anchor);
		set_LOG_litobd;

	}

	_global_den = _local_den;
#ifdef DETAIL_LOG_GLOBAL_DEN
	Log("_global_den (nastavene v dbzaltar.cpp::liturgicke_obdobie() na konci):\n");
	Log(_global_den);
#endif
	/* koniec casti podla dnes.cpp::init_global_string(); */
	Log("-- liturgicke_obdobie(%d, %d, %d, %d) -- koniec\n",
		litobd, tyzden, den, tyzzal);
}/* liturgicke_obdobie(); */

/* --------------------------------------------------------------------- */

/* obsahuje udaje o spolocnej casti, MODL_SPOL_CAST...
 * kedze ju pouzivame len pri druhom volani sviatky_svatych(),
 * mame zarucene, ze _global_den obsahuje dobre udaje -- toho spravneho
 * svateho :-)
 */
short int modlitba;

/* nasleduje funkcia sviatky_svatych(); ktora bola povodne sama vo fajli
 * dbsvaty.c */

/* sviatky_svatych();
 *
 * nastavi do _global_svaty1 nasledovne udaje:
 *
 *	    typslav;    // typ slavenia (1--5): SLAV_...
 *     smer;       // poradove cislo z c.59 Vseobecnych smernic
 *                 // o liturgii hodin a kalendari
 *	    meno[MAX_MENO]; // nazov prip. sviatku
 *
 * az na konci nastavi .den a .mesiac, ostatne sa nastavia inde !!!
 *
 * 09/02/2000A.D.: tato funkcia default dostava vstup poradie_svaty == 0;
 * to sa rovna 'staremu pouzitiu'; v pripade, ze poradie_svaty != 0,
 * znamena to, ze chceme uz pri generovani modlitby nastavit konkretne
 * pre danu modlitbu (svateho) atributy.
 *
 */

/* najprv nejake define'y... */
#define LOG_ciara_sv Log("  -------------------------\n");
/* 2003-06-30 pre lahsie debugovanie obohateny vypis */
#define set_LOG_svsv Log("   set(svsv): %s: `%s', <!--{BEGIN:%s}-->\n", nazov_modlitby(modlitba), _file, _anchor)

/* ked dostane strukturu sc, vrati
 * MODL_SPOL_CAST_DUCH_PAST_... resp.
 * MODL_SPOL_CAST_PANNA
 * alebo MODL_SPOL_CAST_REHOLNIK -- vtedy priradim MODL_SPOL_CAST_SV_MUZ; 03/03/2000A.D.
 * mozno je to diskriminujuce, ale napr. kvoli sv. Efremovi (9. juna), 
 * ak nematchuje, vrati MODL_SPOL_CAST_SV_MUZ; 03/03/2000A.D.
 * (predtym som vracal MODL_SPOL_CAST_NEURCENA)
 */
#define otazka_sedi_to {\
	if((a == MODL_SPOL_CAST_DUCH_PAST_KNAZ) || (a == MODL_SPOL_CAST_DUCH_PAST_BISKUP) || (a == MODL_SPOL_CAST_DUCH_PAST_PAPEZ) || (a == MODL_SPOL_CAST_PANNA)){\
		Log("matches (duchovny pastier || panna). returning %s (%d)\n", nazov_spolc(a), a);\
		return a;\
	}\
	else if((a == MODL_SPOL_CAST_SV_MUZ_REHOLNIK) || (a == MODL_SPOL_CAST_SV_MUZ)){\
		Log("matches (reholnik || muz). returning %s (%d)\n", nazov_spolc(MODL_SPOL_CAST_SV_MUZ), MODL_SPOL_CAST_SV_MUZ);\
		return MODL_SPOL_CAST_SV_MUZ;\
	}\
}	
short int _spol_cast_vyber_dp_pn(_struct_sc sc){
	Log("_spol_cast_vyber_dp_pn() -- skusam, co sedi...\n");
	short int a;
	a = sc.a1;
	Log("  sc.a1 == %s (%d)\n", nazov_spolc(a), a);
	otazka_sedi_to;
	a = sc.a2;
	Log("  sc.a2 == %s (%d)\n", nazov_spolc(sc.a2), sc.a2);
	otazka_sedi_to;
	a = sc.a3;
	Log("  sc.a3 == %s (%d)\n", nazov_spolc(sc.a3), sc.a3);
	otazka_sedi_to;
	Log("not matches. returning %s (%d)\n", nazov_spolc(MODL_SPOL_CAST_SV_MUZ), MODL_SPOL_CAST_SV_MUZ);
	return MODL_SPOL_CAST_SV_MUZ;
}/* _spol_cast_vyber_dp_pn(); */

#define otazka_sedi_to2 if(a == MODL_SPOL_CAST_PANNA){Log("matches. returning ANO\n");return ANO;}
short int _spol_cast_je_panna(_struct_sc sc){
	Log("_spol_cast_je_panna() -- skusam, ci v sc je panna...\n");
	short int a;
	a = sc.a1;
	Log("  sc.a1 == %s (%d)\n", nazov_spolc(sc.a1), sc.a1);
	otazka_sedi_to2;
	a = sc.a2;
	Log("  sc.a2 == %s (%d)\n", nazov_spolc(sc.a2), sc.a2);
	otazka_sedi_to2;
	a = sc.a3;
	Log("  sc.a3 == %s (%d)\n", nazov_spolc(sc.a3), sc.a3);
	otazka_sedi_to2;
	Log("  returning NIE\n");
	return NIE;
}/* _spol_cast_je_panna(); */

/* tu boli _set_zalmy_..., ale su inde; 14/03/2000A.D. */

/* nastavenie jednotlivych parametrov modlitby -- predpoklad je, ze premenna
 * modlitba ma spravne nastavenu konstantu MODL_... */

/* hymnus */
#define _vlastna_cast_hymnus {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	if(modlitba == MODL_POSV_CITANIE){_set_hymnus(modlitba, _file_pc, _anchor);}\
	else{_set_hymnus(modlitba, _file, _anchor);}\
	set_LOG_svsv;}
/* antifony */
/* kedysi tam pred celym blokom bolo if(_global_opt2 == MODL_ZALMY_ZO_SV) 
 * 2005-07-27: pre sviatky sv‰t˝ch posv‰tnÈ ËÌtania maj˙ antifÛny tam, kde ËÌtania
 */
#define _vlastna_cast_antifony {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	if(modlitba == MODL_POSV_CITANIE){_set_antifona1(modlitba, _file_pc, _anchor);}\
	else{_set_antifona1(modlitba, _file, _anchor);}\
	set_LOG_svsv;\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	if(modlitba == MODL_POSV_CITANIE){_set_antifona2(modlitba, _file_pc, _anchor);}\
	else{_set_antifona2(modlitba, _file, _anchor);}\
	set_LOG_svsv;\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	if(modlitba == MODL_POSV_CITANIE){_set_antifona3(modlitba, _file_pc, _anchor);}\
	else{_set_antifona3(modlitba, _file, _anchor);}\
	set_LOG_svsv;}
/* kratke citanie */
#define _vlastna_cast_kcitanie {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_svsv;}
/* kratke responzorium */
#define _vlastna_cast_kresponz {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	if(modlitba == MODL_POSV_CITANIE){_set_kresponz(modlitba, _file_pc, _anchor);}\
	else{_set_kresponz(modlitba, _file, _anchor);}\
	set_LOG_svsv;}
/* bedediktus */
#define _vlastna_cast_benediktus {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_svsv;}
/* magnifikat */
#define _vlastna_cast_magnifikat {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_svsv;}
/* prosby */
#define _vlastna_cast_prosby {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_PROSBY);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_svsv;}
/* modlitba -- rovnaka rano i vecer */
#define _vlastna_cast_modlitba {\
	sprintf(_anchor, "%s%s", _anchor_head, ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_svsv;}
/* modlitba -- ina pre prve vespery ako rano i vecer dna */
#define _vlastna_cast_modlitba_prve_vesp {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_svsv;}

/* 2005-07-26: posv‰tnÈ ËÌtanie potrebuje 1. a 2. ËÌtanie */

/* 1. ËÌtanie */
#define _vlastna_cast_1citanie {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_CITANIE1);\
	_set_citanie1(modlitba, _file_pc, _anchor);\
	set_LOG_svsv;\
}

/* 2. ËÌtanie */
#define _vlastna_cast_2citanie {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_CITANIE2);\
	_set_citanie2(modlitba, _file_pc, _anchor);\
	set_LOG_svsv;\
}

/* full -- vsetko (hymnus, antifony, kcitanie, kresponz,
 * benediktus/magnifikat, prosby, modlitba */
#define _vlastna_cast_full(modl) {\
	_vlastna_cast_hymnus;\
	_vlastna_cast_antifony;\
	if(modl == MODL_POSV_CITANIE){_vlastna_cast_1citanie;}\
	else {_vlastna_cast_kcitanie;}\
	_vlastna_cast_kresponz;\
	if(modl == MODL_RANNE_CHVALY){_vlastna_cast_benediktus;}\
	else if((modl == MODL_VESPERY) || (modl == MODL_PRVE_VESPERY)){_vlastna_cast_magnifikat;}\
	else if(modl == MODL_POSV_CITANIE){_vlastna_cast_2citanie;}\
	_vlastna_cast_prosby;\
	_vlastna_cast_modlitba;\
}

#define _vlastna_cast_full_okrem_prosieb(modl) {\
	_vlastna_cast_hymnus;\
	_vlastna_cast_antifony;\
	if(modl == MODL_POSV_CITANIE){_vlastna_cast_1citanie;}\
	else {_vlastna_cast_kcitanie;}\
	_vlastna_cast_kresponz;\
	if(modl == MODL_RANNE_CHVALY){_vlastna_cast_benediktus;}\
	else if((modl == MODL_VESPERY) || (modl == MODL_PRVE_VESPERY)){_vlastna_cast_magnifikat;}\
	else if(modl == MODL_POSV_CITANIE){_vlastna_cast_2citanie;}\
	_vlastna_cast_modlitba;\
}
/* full -- vsetko (hymnus, antifony, kcitanie, kresponz,
 * benediktus/magnifikat, prosby, modlitba -- ina ako na rchv a vesp */
#define _vlastna_cast_antifony_ako_na_ranne_chvaly {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(MODL_RANNE_CHVALY), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_svsv;\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(MODL_RANNE_CHVALY), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_svsv;\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(MODL_RANNE_CHVALY), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}

/* rovnako tak pre spolocnu cast... */
/* #define _spolocna_cast_hymnus             _vlastna_cast_hymnus */
#define _spolocna_cast_kcitanie           _vlastna_cast_kcitanie
#define _spolocna_cast_benediktus         _vlastna_cast_benediktus
#define _spolocna_cast_magnifikat         _vlastna_cast_magnifikat
#define _spolocna_cast_prosby             _vlastna_cast_prosby
#define _spolocna_cast_modlitba           _vlastna_cast_modlitba
#define _spolocna_cast_modlitba_prve_vesp _vlastna_cast_modlitba_prve_vesp
/* #define _spolocna_cast_antifony           _vlastna_cast_antifony*/
/* ... az na antifony... */
#define _spolocna_cast_antifony {\
	if(_global_opt3 != MODL_SPOL_CAST_NEBRAT){\
		Log("  antifony vlastnej casti zo sviatku...\n");\
		sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
		_set_antifona1(modlitba, _file, _anchor);\
		set_LOG_svsv;\
		sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
		_set_antifona2(modlitba, _file, _anchor);\
		set_LOG_svsv;\
		sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
		_set_antifona3(modlitba, _file, _anchor);\
		set_LOG_svsv;\
	}\
}

/* ... 2005-07-26: in· je tieû spoloËn· Ëasù pre 1. resp. 2. ËÌtanie ... */

/* 1. ËÌtanie */
#define _spolocna_cast_1citanie {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_CITANIE1);\
	_set_citanie1(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}

/* 2. ËÌtanie */
#define _spolocna_cast_2citanie {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_CITANIE2);\
	_set_citanie2(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}

/* ... a spolocnu cast full 
 * 2005-07-27: upravenÈ / nahradenÈ _vlastna_cast_kresponz reùazcom _spolocna_cast_kresponz
 * kvÙli posv‰tn˝m ËÌtaniam, viÔ niûöie 
 * 2005-08-16: nahraden· "_vlastna_cast_hymnus" novou funkciou "_spolocna_cast_hymnus"
 */
#define _spolocna_cast_full(modl) {\
	_spolocna_cast_hymnus;\
	_spolocna_cast_antifony;\
	if(modl == MODL_POSV_CITANIE){\
		_spolocna_cast_1citanie;\
	}\
	else {\
		_vlastna_cast_kcitanie;\
	}\
	_spolocna_cast_kresponz;\
	if(modl == MODL_RANNE_CHVALY){\
		_vlastna_cast_benediktus;\
	}\
	else if((modl == MODL_VESPERY) || (modl == MODL_PRVE_VESPERY)){\
		_vlastna_cast_magnifikat;\
	}\
	else if(modl == MODL_POSV_CITANIE){\
		_spolocna_cast_2citanie;\
	}\
	_vlastna_cast_prosby;\
	_vlastna_cast_modlitba;\
}

/* 2005-07-27: kedysi bolo nasledovnÈ: #define _spolocna_cast_kresponz           _vlastna_cast_kresponz
 * ale potrebujeme, aby spoloËn· Ëasù mala zo spoloËnej Ëasti. preto nasledovn· definÌcia:
 * kratke responzorium */
#define _spolocna_cast_kresponz {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}

/* 2005-08-08: potrebujeme individualny hymnus pre spolocnu cast - berie sa z ineho 
 * suboru ako vlastna cast
 */
#define _spolocna_cast_hymnus {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	_set_hymnus(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}

#define _vlastna_cast_hymnus_po {\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_HYMNUS, POSTNA_PRIPONA);\
	_set_hymnus(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}
#define _vlastna_cast_hymnus_ve {\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_HYMNUS, VELKONOCNA_PRIPONA);\
	_set_hymnus(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}
#define _spolocna_cast_benediktus_ve _vlastna_cast_benediktus_ve
#define _vlastna_cast_benediktus_ve {\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, VELKONOCNA_PRIPONA);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}
#define _spolocna_cast_magnifikat_ve _vlastna_cast_magnifikat_ve
#define _vlastna_cast_magnifikat_ve {\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, VELKONOCNA_PRIPONA);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}
#define _spolocna_cast_kresponz_ve _vlastna_cast_kresponz_ve
#define _vlastna_cast_kresponz_ve {\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ, VELKONOCNA_PRIPONA);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}
#define _vlastna_cast_kresponz_po {\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ, POSTNA_PRIPONA);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}
#define _vlastna_cast_kresponz_cr {\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ, CEZROCNA_PRIPONA);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}

/* specialne veci pre sviatky duchovnych pastierov, jedneho mucenika... */
/* funguje to aj pre svatych muzov (jeden resp. viaceri -- podla toho, co je
 * v _anchor_pom); 29/02/2000A.D. */
void _spolocna_cast_hymnus_rozne(short int modlitba, char *_anchor_pom, char *_anchor, char *_file){
	sprintf(_anchor, "%s%c%s", _anchor_pom, pismenko_modlitby(modlitba), ANCHOR_HYMNUS);
	_set_hymnus(modlitba, _file, _anchor);
	set_LOG_svsv;
}

void _spolocna_cast_benediktus_rozne(short int modlitba, char *_anchor_pom, char *_anchor, char *_file){
	sprintf(_anchor, "%s%c%s", _anchor_pom, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS);
	_set_benediktus(modlitba, _file, _anchor);
	set_LOG_svsv;
}

void _spolocna_cast_magnifikat_rozne(short int modlitba, char *_anchor_pom, char *_anchor, char *_file){
	sprintf(_anchor, "%s%c%s", _anchor_pom, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT);
	_set_magnifikat(modlitba, _file, _anchor);
	set_LOG_svsv;
}

void _spolocna_cast_kresponz_rozne(short int modlitba, char *_anchor_pom, char *_anchor, char *_file){
	sprintf(_anchor, "%s%c%s", _anchor_pom, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);
	_set_kresponz(modlitba, _file, _anchor);
	set_LOG_svsv;
}
/* 2005-08-27: kvÙli 2. ËÌtaniu pre duchovn˝ch pastierov; pouûÌvame aj pre odliönÈ ËÌtanie pre sv‰tÈ ûeny - Ëo ûili v manûelstve; 2006-08-08 */
void _spolocna_cast_2cit_rozne(short int modlitba, char *_anchor_pom, char *_anchor, char *_file){
	sprintf(_anchor, "%s%c%s", _anchor_pom, pismenko_modlitby(modlitba), ANCHOR_CITANIE2);
	_set_citanie2(modlitba, _file, _anchor);
	set_LOG_svsv;
}

/* specialne veci pre sviatky jedneho mucenika */
#define _spolocna_cast_kcit_kresp_chval_ve {\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_KCITANIE, VELKONOCNA_PRIPONA);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_svsv;\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ, VELKONOCNA_PRIPONA);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_svsv;\
	if(modlitba == MODL_RANNE_CHVALY){\
		sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, VELKONOCNA_PRIPONA);\
		_set_benediktus(modlitba, _file, _anchor);\
		set_LOG_svsv;\
	}\
	else if((modlitba == MODL_VESPERY) || (modlitba == MODL_PRVE_VESPERY)){\
		sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, VELKONOCNA_PRIPONA);\
		_set_magnifikat(modlitba, _file, _anchor);\
		set_LOG_svsv;\
	}\
}

#define _spolocna_cast_ant1_3_po {\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1, POSTNA_PRIPONA);\
	_set_antifona1(modlitba, _file, _anchor);\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3, POSTNA_PRIPONA);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}
/* specialne veci pre sviatky viacerych mucenikov */
#define _spolocna_cast_ant2_po {\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2, POSTNA_PRIPONA);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}

/* specialne veci pre sviatky panien */
#define _spolocna_cast_kresp_ve {\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ, VELKONOCNA_PRIPONA);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}

/* ked je viac napevov, `kolko' uvadza, z kolkych je na vyber;
 * zvacsa sa vyberie napr. podla (_global_den.den MOD kolko) + 1
 * (aby bol z intervalu 1..kolko)
 * 23/02/2000A.D.
 */
void _spolocna_cast_magnifikat_viac(short int kolko, char *_anchor_head, char *_anchor, char *_file){
	sprintf(_anchor, "%s%c%s%d",
		_anchor_head, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT,
		(_global_den.den MOD kolko) + 1);
	_set_magnifikat(modlitba, _file, _anchor);
	set_LOG_svsv;
}
/* viac benediktus-ov - dorobene 01/03/2000A.D. */
void _spolocna_cast_benediktus_viac(short int kolko, char *_anchor_head, char *_anchor, char *_file){
	sprintf(_anchor, "%s%c%s%d",
		_anchor_head, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS,
		(_global_den.den MOD kolko) + 1);
	_set_benediktus(modlitba, _file, _anchor);
	set_LOG_svsv;
}
/* viac prosieb -- dorobene 01/03/2000A.D., spol.casti panny marie */
void _spolocna_cast_prosby_viac(short int kolko, char *_anchor_head, char *_anchor, char *_file){
	sprintf(_anchor, "%s%c%s%d",
		_anchor_head, pismenko_modlitby(modlitba), ANCHOR_PROSBY,
		(_global_den.den MOD kolko) + 1);
	_set_prosby(modlitba, _file, _anchor);
	set_LOG_svsv;
}
/* viac responzÛriÌ -- dorobene 29/03/2000A.D., oficium za zosnulych */
void _spolocna_cast_kresponz_viac(short int kolko, char *_anchor_head, char *_anchor, char *_file){
	sprintf(_anchor, "%s%c%s%d",
		_anchor_head, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ,
		(_global_den.den MOD kolko) + 1);
	_set_kresponz(modlitba, _file, _anchor);
	set_LOG_svsv;
}
void _spolocna_cast_ant3_viac(short int kolko, char *_anchor_head, char *_anchor, char *_file){
	sprintf(_anchor, "%s%c%s%d",
		_anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3,
		(_global_den.den MOD kolko) + 1);
	_set_antifona3(modlitba, _file, _anchor);
	set_LOG_svsv;
}
/* 2005-08-05: posv‰tnÈ ËÌtania, 1. ËÌtanie */
void _spolocna_cast_1cit_viac(short int kolko, char *_anchor_head, char *_anchor, char *_file){
	sprintf(_anchor, "%s%c%s%d",
		_anchor_head, pismenko_modlitby(modlitba), ANCHOR_CITANIE1,
		(_global_den.den MOD kolko) + 1);
	_set_citanie1(modlitba, _file, _anchor);
	set_LOG_svsv;
}
/* 2005-08-05: posv‰tnÈ ËÌtania, 2. ËÌtanie */
void _spolocna_cast_2cit_viac(short int kolko, char *_anchor_head, char *_anchor, char *_file){
	sprintf(_anchor, "%s%c%s%d",
		_anchor_head, pismenko_modlitby(modlitba), ANCHOR_CITANIE2,
		(_global_den.den MOD kolko) + 1);
	_set_citanie2(modlitba, _file, _anchor);
	set_LOG_svsv;
}
/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
 * - II. zv‰zok (veæk· noc),
 * - III. a IV. zv‰zok (obdobie cez rok).
 */
void _spolocna_cast_1cit_zvazok(short int modlitba, char *_anchor_pom, char *_anchor_zvazok, char *_anchor, char *_file){
	char _anchor_lokal[SMALL]; /* 2005-08-08: lok·lna premenn· */
	Log("_spolocna_cast_1cit_zvazok: \n");
	Log("\tmodlitba == %s\n", nazov_modlitby(modlitba));
	Log("\tanchor_pom == %s\n", _anchor_pom);
	Log("\tanchor_zvazok == %s\n", _anchor_zvazok);
	Log("\tanchor == %s\n", _anchor);
	Log("\tfile == %s\n", _file);
	if(!equals(_anchor_pom, STR_EMPTY)){
		sprintf(_anchor_lokal, "%s%s%s%c%s", _anchor, _anchor_pom, _anchor_zvazok, pismenko_modlitby(modlitba), ANCHOR_CITANIE1);
	}
	else {
		sprintf(_anchor_lokal, "%s%s%c%s", _anchor, _anchor_zvazok, pismenko_modlitby(modlitba), ANCHOR_CITANIE1);
	}
	_set_citanie1(modlitba, _file, _anchor_lokal);
	/* set_LOG_svsv; */
	Log("   set(svsv): %s: `%s', <!--{BEGIN:%s}-->\n", nazov_modlitby(modlitba), _file, _anchor_lokal);
}

/* 2005-08-27: kr·tke responzÛrium na posv‰tnÈ ËÌtanie pre vlastnÈ Ëasti je 
 * zv‰Ëöa rovnakÈ, ale pre sviatky prebl. panny m·rie je odliönÈ (porov. 1. ËÌtanie vyööie):
 * - I. zv‰zok (advent, vianoce),
 * - II. zv‰zok (pÙst), II. zv‰zok (veæk· noc), III. a IV. zv‰zok (obdobie cez rok).
 */
void _spolocna_cast_kresponz_zvazok(short int modlitba, char *_anchor_pom, char *_anchor_zvazok, char *_anchor, char *_file){
	char _anchor_lokal[SMALL]; /* 2005-08-08: lok·lna premenn· */
	Log("_spolocna_cast_kresp_zvazok: \n");
	Log("\tmodlitba == %s\n", nazov_modlitby(modlitba));
	Log("\tanchor_pom == %s\n", _anchor_pom);
	Log("\tanchor_zvazok == %s\n", _anchor_zvazok);
	Log("\tanchor == %s\n", _anchor);
	Log("\tfile == %s\n", _file);
	if(!equals(_anchor_pom, STR_EMPTY)){
		sprintf(_anchor_lokal, "%s%s%s%c%s", _anchor, _anchor_pom, _anchor_zvazok, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);
	}
	else {
		sprintf(_anchor_lokal, "%s%s%c%s", _anchor, _anchor_zvazok, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);
	}
	_set_kresponz(modlitba, _file, _anchor_lokal);
	/* set_LOG_svsv; */
	Log("   set(svsv): %s: `%s', <!--{BEGIN:%s}-->\n", nazov_modlitby(modlitba), _file, _anchor_lokal);
}

/* 2005-11-24: pridanÈ; podæa vöeobecn˝ch smernÌc, Ë. 134:

"Na sl·vnosti a sviatky, vo VeækonoËnom trojdnÌ a v dÚoch VeækonoËnej a VianoËnej okt·vy 
s˙ pre posv‰tnÈ ËÌtanie urËenÈ vlastnÈ ûalmy v s˙lade s tradÌciou; ich vhodnosù osvetæuje 
zvyËajne antifÛna. Tak je to aj pri modlitbe cez deÚ na niektorÈ sl·vnosti P·na 
a vo VeækonoËnej okt·ve. Na rannÈ chv·ly sa ber˙ ûalmy a chv·lospev z nedele prvÈho t˝ûdÚa 
v ûalt·ri. 

Na prvÈ veöpery sl·vnostÌ sa ber˙ ûalmy podæa starod·vneho zvyku zo sÈrie Laud·te. 

DruhÈ veöpery sl·vnostÌ a veöpery sviatkov maj˙ ûalmy i chv·lospev vlastnÈ. 

Na modlitbu cez deÚ sl·vnostÌ, okrem t˝ch, o ktor˝ch sa uû hovorilo, a ak nepripadn˙ na nedeæu, 
ber˙ sa ûalmy z doplnkovÈho cyklu (gradu·lne).

Na sviatky sa na modlitbu cez deÚ ber˙ ûalmy z prÌsluönÈho dÚa v t˝ûdni."
 * 2006-02-04: premenovanÈ z "su_zalmy_nedela1tyzden" na "su_zalmy_zo_sviatku" 
 *             a pouûitÈ aj pre inÈ modlitby ako pre rannÈ chv·ly
 *             miesta v kÛde oznaËenÈ 2006-02-04_ZALMY_ZO_SVIATKU_FIX
 */
#define su_zalmy_zo_sviatku ((_global_den.denvt == DEN_NEDELA) || (_global_den.typslav == SLAV_SLAVNOST) || (_global_den.typslav == SLAV_SVIATOK))
void _set_spolocna_cast(short int a, _struct_sc sc){
	/* 2005-07-22: pokus o doplnenie udajov k posvatnym citaniam */

	/* anchors - nazvy kotiev pre zaltar styroch tyzdnov */
	char _anchor[SMALL];
	char _anchor_head[SMALL];
	char _anchor_pom[SMALL];
	/* 2005-08-05: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
	char _anchor_zvazok[SMALL];
	/* files - nazvy suborov pre zaltar styroch tyzdnov */
	char _file[SMALL]; /* nazov fajlu, napr. _1ne.htm */
	short int b; /* pre ucitelov cirkvi, odkial sa maju brat ine casti */

	Log("_set_spolocna_cast(%s) -- begin\n", nazov_spolc(a));

	if(a != MODL_SPOL_CAST_NEBRAT){
		Log("/* nastavenie nazvu suboru, kotvy apod. (_set_spolocna_cast) */\n");
		/* nastavenie nazvu suboru, kotvy apod. */
		sprintf(_anchor_head, "%s_", nazov_spolc_ANCHOR[a]);
		Log("  _anchor_head == %s\n", _anchor_head);
		sprintf(_file, "%s", nazov_spolc_htm[a]);
		Log("  _file == %s\n", _file);
	}
	else{
		Log("   nebrat... takze nenastavujem kotvy ani nic\n");
	}

	/* spolocna cast na sviatky apostolov */
	if(a == MODL_SPOL_CAST_APOSTOL){

		Log("/* spolocna cast na sviatky apostolov */\n");

		/* prvÈ veöpery */
		modlitba = MODL_PRVE_VESPERY;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_apostolov(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_apostolov(modlitba);
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_modlitba_prve_vesp;

		/* 2005-08-05: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_pom, "%s", STR_EMPTY);
		Log("  _anchor_pom == %s\n", _anchor_pom);
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		/* posvatne citanie */
		modlitba = MODL_POSV_CITANIE;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_apostolov(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_apostolov(modlitba);
		}
		_spolocna_cast_full(modlitba);
		/* 2005-07-22: ToDo: skontrolovaù, Ëi pre öpeci·lne obdobia nie s˙ öpeci·lne Ëasti z obdobia */

		/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, _anchor_pom, _anchor_zvazok, _anchor_head, _file);

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		/* 2006-01-25: PÙvodne tu bolo AND; upravenÈ kvÙli tomu, aby sa ûalmy z nedele 1. t˝ûdÚa
		 *             zobrazili aj v prÌpade, ak by podæa smernÌc nemali (nemuseli) byù,
		 *             ale pouûÌvateæ si to v detailoch vyberie.
		 *             Pritom default pre _global_opt2 sme zmenili na MODL_ZALMY_ZO_DNA.
		 *             Takto isto zmenenÈ na vöetk˝ch ostatn˝ch miestach - bez pozn·mky.
		 *             2006-01-25_ZALMY1NE_FIX
		 */
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-01-25_ZALMY1NE_FIX */
			_set_zalmy_1nedele_rch();
		}
		_spolocna_cast_full(modlitba);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_vlastna_cast_kresponz_ve;
		/* ranne chvaly na sviatky apostolov maju specialne hymny pre postne a velkonocne obdobie */
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			_vlastna_cast_hymnus_ve;
		}
		else if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN)){
			_vlastna_cast_hymnus_po;
		}

		/* vespery */
		if(_global_den.litobd != OBD_OKTAVA_NARODENIA){
			modlitba = MODL_VESPERY;
			if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
				Log("  _set_zalmy_sviatok_apostolov(%s)...\n", nazov_modlitby(modlitba));
				_set_zalmy_sviatok_apostolov(modlitba);
			}
			_spolocna_cast_full(modlitba);
			if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
				_vlastna_cast_kresponz_ve;
			if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
				_vlastna_cast_hymnus_ve;
		}/* v OBD_OKTAVA_NARODENIA (sv. Jana, 27. dec) vespery su zo dna */

	}/* MODL_SPOL_CAST_APOSTOL */

	/* spolocna cast na sviatky duchovnych pastierov */
	else if((a == MODL_SPOL_CAST_DUCH_PAST_KNAZ) ||
		(a == MODL_SPOL_CAST_DUCH_PAST_BISKUP) ||
		(a == MODL_SPOL_CAST_DUCH_PAST_PAPEZ) ||
		(a == MODL_SPOL_CAST_DUCH_PAST_VIACERI)){

		Log("/* spolocna cast na sviatky duchovnych pastierov */\n");

		sprintf(_anchor_head, "%s_", ANCHOR_SPOL_CAST_DUCH_PAST);
		Log("  _anchor_head == %s\n", _anchor_head);
		sprintf(_anchor_pom, "%s_", nazov_spolc_ANCHOR[a]);
		Log("  _anchor_pom == %s\n", _anchor_pom);
		/* 2005-08-05: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if(
			((a == MODL_SPOL_CAST_DUCH_PAST_BISKUP) || (a == MODL_SPOL_CAST_DUCH_PAST_PAPEZ))
			&& ((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
		){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		/* prvÈ veöpery */
		modlitba = MODL_PRVE_VESPERY;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_duch_past(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_duch_past(modlitba);
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
		_spolocna_cast_modlitba_prve_vesp;

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-01-25_ZALMY1NE_FIX */
			_set_zalmy_1nedele_rch();
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_vlastna_cast_kresponz_ve;

		/* posvatne citanie */
		modlitba = MODL_POSV_CITANIE;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_duch_past(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_duch_past(modlitba);
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
		/* 2005-07-22: ToDo: skontrolovaù, Ëi pre öpeci·lne obdobia nie s˙ öpeci·lne Ëasti z obdobia */

		/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, _anchor_pom, _anchor_zvazok, STR_EMPTY /* 2005-08-08: _anchor netreba*/, _file);
		/* 2005-08-27: doplnenÈ druhÈ ËÌtanie */
		_spolocna_cast_2cit_rozne(modlitba, _anchor_pom, _anchor, _file);

		/* vespery */
		if(_global_den.litobd != OBD_OKTAVA_NARODENIA){
			modlitba = MODL_VESPERY;
			if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
				Log("  _set_zalmy_sviatok_duch_past(%s)...\n", nazov_modlitby(modlitba));
				_set_zalmy_sviatok_duch_past(modlitba);
			}
			_spolocna_cast_full(modlitba);
			_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
			_spolocna_cast_magnifikat_viac(2, _anchor_head, _anchor, _file);
			if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
				_vlastna_cast_kresponz_ve;
		}/* v OBD_OKTAVA_NARODENIA -- vespery su zo dna */

	}/* MODL_SPOL_CAST_DUCH_PAST_... */

	/* spolocna cast na sviatky ucitelov cirkvi */
	else if(a == MODL_SPOL_CAST_UCITEL_CIRKVI){
		/* najprv nastavime podla spol. casti duchovnych pastierov resp.
		 * panien... */

		Log("/* spolocna cast na sviatky ucitelov cirkvi */\n");

		b = _spol_cast_vyber_dp_pn(sc);
		if(b != MODL_SPOL_CAST_NEURCENA){
			Log("spustam _set_spolocna_cast(%s) druhy raz (vnorene) -- \n  kvoli castiam, ktore pre ucitelov cirkvi nie su\n", nazov_spolc(b));
			_set_spolocna_cast(b, sc);
			Log("po vnorenom spusteni _set_spolocna_cast() -- navrat.\n");
			Log("pokracujem v nastaveni veci pre spol. cast MODL_SPOL_CAST_UCITEL_CIRKVI...\n");
		}
		/* ...a teraz vlastnu cast ucitelov cirkvi */

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		_spolocna_cast_hymnus;
		_spolocna_cast_kcitanie;
		_spolocna_cast_kresponz;
		_spolocna_cast_benediktus;
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_vlastna_cast_kresponz_ve; /* pridane 18/06/2000A.D. */

		/* vespery */
		modlitba = MODL_VESPERY;
		_spolocna_cast_hymnus;
		_spolocna_cast_kcitanie;
		_spolocna_cast_kresponz;
		_spolocna_cast_magnifikat;
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_vlastna_cast_kresponz_ve; /* pridane 18/06/2000A.D. */

		/* posv‰tnÈ ËÌtanie */
		modlitba = MODL_POSV_CITANIE;
		_spolocna_cast_hymnus;

		sprintf(_anchor_pom, "%s_", nazov_spolc_ANCHOR[a]);
		Log("  _anchor_pom == %s\n", _anchor_pom);
		/* 2005-08-05: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, _anchor_pom, _anchor_zvazok, STR_EMPTY /* 2005-08-08: _anchor netreba*/, _file);
		_spolocna_cast_2citanie;

	}/* MODL_SPOL_CAST_UCITEL_CIRKVI */

	/* spolocna cast na sviatky jedneho mucenika */
	else if((a == MODL_SPOL_CAST_MUCENIK) ||
		(a == MODL_SPOL_CAST_MUCENICA)){

		Log("/* spolocna cast na sviatky jedneho mucenika */\n");

		sprintf(_anchor_head, "%s_", ANCHOR_SPOL_CAST_JEDEN_MUCENIK);
		Log("  _anchor_head == %s\n", _anchor_head);
		sprintf(_anchor_pom, "%s_", nazov_spolc_ANCHOR[a]);
		if(_spol_cast_je_panna(sc) == ANO){
			sprintf(_anchor_pom, "%s_", ANCHOR_SPOL_CAST_PANNA_MUCENICA);
		}
		Log("  _anchor_pom == %s\n", _anchor_pom);
		/* 2005-08-09: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		/* prvÈ veöpery */
		modlitba = MODL_PRVE_VESPERY;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_muc(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_muc(modlitba);
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_spolocna_cast_kcit_kresp_chval_ve;
		_spolocna_cast_modlitba_prve_vesp;

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-01-25_ZALMY1NE_FIX */
			_set_zalmy_1nedele_rch();
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_spolocna_cast_kcit_kresp_chval_ve;

		/* posvatne citanie */
		modlitba = MODL_POSV_CITANIE;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_muc(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_muc(modlitba);
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
		/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 *
		 * 2005-08-16: Zmenen˝ _anchor_pom na _anchor_head.
		 */
		_spolocna_cast_1cit_zvazok(modlitba, _anchor_head, _anchor_zvazok, STR_EMPTY /* 2005-08-08: _anchor netreba*/, _file);

		/* vespery */
		if(_global_den.litobd != OBD_OKTAVA_NARODENIA){
			modlitba = MODL_VESPERY;
			if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
				Log("  _set_zalmy_sviatok_muc(%s)...\n", nazov_modlitby(modlitba));
				_set_zalmy_sviatok_muc(modlitba);
			}
			_spolocna_cast_full(modlitba);
			_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
			if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
				_spolocna_cast_kcit_kresp_chval_ve;
		}/* v OBD_OKTAVA_NARODENIA -- vespery su zo dna */

	}/* MODL_SPOL_CAST_MUCENIK/MUCENICA */

	/* spolocna cast na sviatky viacerych mucenikov */
	else if(a == MODL_SPOL_CAST_VIAC_MUCENIKOV){

		Log("/* spolocna cast na sviatky viacerych mucenikov */\n");

		sprintf(_anchor_pom, "%s_", nazov_spolc_ANCHOR[a]);
		Log("  _anchor_pom == %s\n", _anchor_pom);
		/* 2005-08-16: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		modlitba = MODL_PRVE_VESPERY;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_muc(%s, 2)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_muc(modlitba, 2);
		}
		_spolocna_cast_full(modlitba);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_spolocna_cast_kcit_kresp_chval_ve;
		_spolocna_cast_modlitba_prve_vesp;

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-01-25_ZALMY1NE_FIX */
			_set_zalmy_1nedele_rch();
		}
		_spolocna_cast_full(modlitba);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_spolocna_cast_kcit_kresp_chval_ve;
		if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN)){
			_spolocna_cast_ant2_po;
		}

		/* posvatne citanie */
		modlitba = MODL_POSV_CITANIE;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_muc(%s, 2)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_muc(modlitba, 2);
		}
		_spolocna_cast_full(modlitba);
		/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, STR_EMPTY /* 2005-08-16: _anchor_pom netreba */, _anchor_zvazok, _anchor_pom, _file);

		/* vespery */
		if(_global_den.litobd != OBD_OKTAVA_NARODENIA){
			modlitba = MODL_VESPERY;
			if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
				Log("  _set_zalmy_sviatok_muc(%s, 2)...\n", nazov_modlitby(modlitba));
				_set_zalmy_sviatok_muc(modlitba, 2);
			}
			_spolocna_cast_full(modlitba);
			if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
				_spolocna_cast_kcit_kresp_chval_ve;
		}/* v OBD_OKTAVA_NARODENIA -- vespery su zo dna */

	}/* MODL_SPOL_CAST_VIAC_MUCENIKOV */

	/* spoloËn· Ëasù na sviatky sv‰t˝ch muûov/ûien -- pre t˝ch, Ëo ûili v manûelstve */
	else if((a == MODL_SPOL_CAST_SV_MUZ_MANZ) || (a == MODL_SPOL_CAST_SV_ZENA_MANZ)){
		/* najprv nastavÌme podæa spol. Ëasti sv‰t˝ch muûov/ûien... */

		Log("/* spoloËn· Ëasù na sviatky sv‰t˝ch muûov/ûien -- pre t˝ch, Ëo ûili v manûelstve */\n");

		b = MODL_SPOL_CAST_NEURCENA;
		if(a == MODL_SPOL_CAST_SV_ZENA_MANZ)
			b = MODL_SPOL_CAST_SV_ZENA;
		else if(a == MODL_SPOL_CAST_SV_MUZ_MANZ)
			b = MODL_SPOL_CAST_SV_MUZ;

		if(b != MODL_SPOL_CAST_NEURCENA){
			Log("sp˙öùam _set_spolocna_cast(%s) druh˝ raz (vnorenÈ) -- \n   kvÙli Ëastiam, ktorÈ pre t˝ch, Ëo ûili v manûelstve nie s˙\n", nazov_spolc(b));
			_set_spolocna_cast(b, sc);
			Log("po vnorenom spustenÌ _set_spolocna_cast() -- navrat.\n");
			Log("pokraËujem v nastavenÌ vecÌ pre spol. Ëast MODL_SPOL_CAST_..._MANZ...\n");
		}
		/* ...a teraz vlastn· Ëasù pre t˝ch, Ëo ûili v manûelstve */

		/* posv‰tnÈ ËÌtanie */
		modlitba = MODL_POSV_CITANIE;

		sprintf(_anchor_pom, "%s_", nazov_spolc_ANCHOR[a]);
		Log("  _anchor_pom == %s\n", _anchor_pom);

		/* 2005-08-05: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, STR_EMPTY, _anchor_zvazok, _anchor_pom, _file);
		/* 2006-08-07: bude treba otestovaù, pretoûe zatiaæ to nem· asi ûiadny sv‰tec nastavenÈ */
		if(a == MODL_SPOL_CAST_SV_ZENA_MANZ){ /* 2006-08-08: odliönÈ druhÈ ËÌtanie */
			_spolocna_cast_2cit_rozne(modlitba, _anchor_pom, _anchor, _file);
		}

	}/* MODL_SPOL_CAST_SV_MUZ/ZENA_MANZ */

	/* spolocna cast na sviatky svatych muzov/zien -- pre vychovavatelov */
	else if((a == MODL_SPOL_CAST_SV_MUZ_VYCH) || (a == MODL_SPOL_CAST_SV_ZENA_VYCH)){
		/* najprv nastavime podla spol. casti svatych muzov/zien... */

		Log("/* spolocna cast na sviatky svatych muzov/zien -- pre vychovavatelov */\n");

		b = MODL_SPOL_CAST_NEURCENA;
		if(a == MODL_SPOL_CAST_SV_ZENA_VYCH)
			b = MODL_SPOL_CAST_SV_ZENA;
		else if(a == MODL_SPOL_CAST_SV_MUZ_VYCH)
			b = MODL_SPOL_CAST_SV_MUZ;

		if(b != MODL_SPOL_CAST_NEURCENA){
			Log("spustam _set_spolocna_cast(%s) druhy raz (vnorene) -- \n   kvoli castiam, ktore pre vychovavatelov nie su\n", nazov_spolc(b));
			_set_spolocna_cast(b, sc);
			Log("po vnorenom spusteni _set_spolocna_cast() -- navrat.\n");
			Log("pokracujem v nastaveni veci pre spol. cast MODL_SPOL_CAST_..._VYCH...\n");
		}
		/* ...a teraz vlastnu cast pre vychovavatelov */

		/* prve vespery */
		modlitba = MODL_PRVE_VESPERY;
		_spolocna_cast_magnifikat;
		_spolocna_cast_modlitba;

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		_spolocna_cast_benediktus;
		_spolocna_cast_modlitba;

		/* vespery */
		modlitba = MODL_VESPERY;
		_spolocna_cast_magnifikat;
		_spolocna_cast_modlitba;

		/* posv‰tnÈ ËÌtanie */
		modlitba = MODL_POSV_CITANIE;

		sprintf(_anchor_pom, "%s_", nazov_spolc_ANCHOR[a]);
		Log("  _anchor_pom == %s\n", _anchor_pom);

		/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		/* 2006-08-08: tÌ Ëo konali skutky milosrdenstva nemaj˙ samostatnÈ 1. ËÌtanie */
		_spolocna_cast_2cit_rozne(modlitba, _anchor_pom, _anchor, _file);
		/* 2006-08-08: tÌ Ëo konali skutky milosrdenstva maj˙ rovnakÈ 2. ËÌtanie */

	}/* MODL_SPOL_CAST_SV_MUZ/ZENA_VYCH */

	/* spolocna cast na sviatky svatych muzov/zien -- pre tych, ktori konali skutky milosrdenstva */
	else if((a == MODL_SPOL_CAST_SV_MUZ_SKUTKYMIL) || (a == MODL_SPOL_CAST_SV_ZENA_SKUTKYMIL)){
		/* najprv nastavime podla spol. casti svatych muzov/zien... */

		Log("/* spolocna cast na sviatky svatych muzov/zien -- pre tych, co konali skutky milosrdenstva */\n");

		b = MODL_SPOL_CAST_NEURCENA;
		if(a == MODL_SPOL_CAST_SV_ZENA_SKUTKYMIL)
			b = MODL_SPOL_CAST_SV_ZENA;
		else if(a == MODL_SPOL_CAST_SV_MUZ_SKUTKYMIL)
			b = MODL_SPOL_CAST_SV_MUZ;

		if(b != MODL_SPOL_CAST_NEURCENA){
			Log("spustam _set_spolocna_cast(%s) druhy raz (vnorene) -- \n   kvoli castiam, ktore pre tych, co konali skutky milosrdenstva nie su\n", nazov_spolc(b));
			_set_spolocna_cast(b, sc);
			Log("po vnorenom spusteni _set_spolocna_cast() -- navrat.\n");
			Log("pokracujem v nastaveni veci pre spol. cast MODL_SPOL_CAST_..._SKUTKYMIL...\n");
		}
		/* ...a teraz vlastnu cast pre tych, co konali skutky milosrdenstva */

		/* prve vespery */
		modlitba = MODL_PRVE_VESPERY;
		_spolocna_cast_magnifikat;
		_spolocna_cast_modlitba;

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		_spolocna_cast_benediktus;
		_spolocna_cast_modlitba;

		/* vespery */
		modlitba = MODL_VESPERY;
		_spolocna_cast_magnifikat;
		_spolocna_cast_modlitba;

		/* posv‰tnÈ ËÌtanie */
		modlitba = MODL_POSV_CITANIE;

		sprintf(_anchor_pom, "%s_", nazov_spolc_ANCHOR[a]);
		Log("  _anchor_pom == %s\n", _anchor_pom);
		/* 2005-08-08: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, STR_EMPTY, _anchor_zvazok, _anchor_pom, _file);
		/* 2006-08-08: tÌ Ëo konali skutky milosrdenstva maj˙ v I. a II. zv‰zku rovnakÈ 1. ËÌtanie; v III. a IV. inÈ rovnakÈ 1. ËÌtanie */
		_spolocna_cast_2cit_rozne(modlitba, _anchor_pom, _anchor, _file);
		/* 2006-08-08: tÌ Ëo konali skutky milosrdenstva maj˙ rovnakÈ 2. ËÌtanie */

	}/* MODL_SPOL_CAST_SV_MUZ/ZENA_SKUTKYMIL */

	/* spolocna cast na sviatky svatych muzov/zien -- pre reholnikov */
	else if((a == MODL_SPOL_CAST_SV_MUZ_REHOLNIK) || (a == MODL_SPOL_CAST_SV_ZENA_REHOLNIK)){
		/* najprv nastavime podla spol. casti svatych muzov/zien... */

		Log("/* spolocna cast na sviatky svatych muzov/zien -- pre reholnikov */\n");

		b = MODL_SPOL_CAST_NEURCENA;
		if(a == MODL_SPOL_CAST_SV_ZENA_REHOLNIK)
			b = MODL_SPOL_CAST_SV_ZENA;
		else if(a == MODL_SPOL_CAST_SV_MUZ_REHOLNIK)
			b = MODL_SPOL_CAST_SV_MUZ;

		if(b != MODL_SPOL_CAST_NEURCENA){
			Log("spustam _set_spolocna_cast(%s) druhy raz (vnorene) -- \n   kvoli castiam, ktore pre reholnikov nie su\n", nazov_spolc(b));
			_set_spolocna_cast(b, sc);
			Log("po vnorenom spusteni _set_spolocna_cast() -- navrat.\n");
			Log("pokracujem v nastaveni veci pre spol. cast MODL_SPOL_CAST_..._REHOLNIK...\n");
		}
		/* ...a teraz vlastnu cast reholnikov */

		/* prve vespery */
		modlitba = MODL_PRVE_VESPERY;
		_spolocna_cast_hymnus;
		_spolocna_cast_magnifikat_viac(2, _anchor_head, _anchor, _file);
		_spolocna_cast_modlitba;

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		_spolocna_cast_hymnus;
		_spolocna_cast_benediktus_viac(2, _anchor_head, _anchor, _file);
		_spolocna_cast_modlitba;

		/* vespery */
		modlitba = MODL_VESPERY;
		_spolocna_cast_hymnus;
		_spolocna_cast_magnifikat_viac(2, _anchor_head, _anchor, _file);
		_spolocna_cast_modlitba;

		/* posv‰tnÈ ËÌtanie */
		modlitba = MODL_POSV_CITANIE;

		sprintf(_anchor_pom, "%s_", nazov_spolc_ANCHOR[a]);
		Log("  _anchor_pom == %s\n", _anchor_pom);
		/* 2005-08-08: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, STR_EMPTY, _anchor_zvazok, _anchor_pom, _file);
		/* 2006-08-08: rehoænÌci maj˙ v I. a II. zv‰zku rovnakÈ 1. ËÌtanie; v III. a IV. inÈ rovnakÈ 1. ËÌtanie */
		_spolocna_cast_2cit_rozne(modlitba, _anchor_pom, _anchor, _file);
		/* 2006-08-08: rehoænÌci maj˙ rovnakÈ 2. ËÌtanie */

	}/* MODL_SPOL_CAST_SV_MUZ/ZENA_REHOLNIK */

	/* spolocna cast na sviatky svatych muzov */
	else if((a == MODL_SPOL_CAST_SV_MUZ) ||
		(a == MODL_SPOL_CAST_SV_MUZ_VIACERI)){

		Log("/* spolocna cast na sviatky svatych muzov */\n");

		sprintf(_anchor_head, "%s_", nazov_spolc_ANCHOR[MODL_SPOL_CAST_SV_MUZ]);
		Log("  _anchor_head == %s\n", _anchor_head);
		sprintf(_anchor_pom, "%s_", nazov_spolc_ANCHOR[a]);
		Log("  _anchor_pom == %s\n", _anchor_pom);

		/* prvÈ veöpery */
		modlitba = MODL_PRVE_VESPERY;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_duch_past(%s)... - pretoûe pre sv‰t˝ch muûov sa ber˙ tie istÈ ûalmy\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_duch_past(modlitba);
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-01-25_ZALMY1NE_FIX */
			_set_zalmy_1nedele_rch();
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
		_spolocna_cast_benediktus_rozne(modlitba, _anchor_pom, _anchor, _file);
		_spolocna_cast_kresponz_rozne(modlitba, _anchor_pom, _anchor, _file);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_vlastna_cast_kresponz_ve;

		/* posvatne citanie */
		modlitba = MODL_POSV_CITANIE;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_duch_past(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_duch_past(modlitba);
		}

		/* 2005-08-05: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		_spolocna_cast_full(modlitba);
		/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, STR_EMPTY /* 2005-08-16: _anchor_pom netreba */, _anchor_zvazok, _anchor_pom, _file);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file); /* 2006-08-07: doplnenÈ */

		/* vespery */
		if(_global_den.litobd != OBD_OKTAVA_NARODENIA){
			modlitba = MODL_VESPERY;
			if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
				Log("  _set_zalmy_sviatok_duch_past(%s)...\n", nazov_modlitby(modlitba));
				_set_zalmy_sviatok_duch_past(modlitba);
			}
			_spolocna_cast_full(modlitba);
			_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
			_spolocna_cast_magnifikat_rozne(modlitba, _anchor_pom, _anchor, _file);
			if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
				_vlastna_cast_kresponz_ve; /* pridane 18/06/2000A.D. */
		}/* v OBD_OKTAVA_NARODENIA -- vespery su zo dna */

	}/* MODL_SPOL_CAST_SV_MUZ_[VIACERI]... */

	/* spolocna cast na sviatky svatych zien */
	else if((a == MODL_SPOL_CAST_SV_ZENA) ||
		(a == MODL_SPOL_CAST_SV_ZENA_VIACERE)){

		Log("/* spolocna cast na sviatky svatych zien */\n");

		sprintf(_anchor_head, "%s_", nazov_spolc_ANCHOR[MODL_SPOL_CAST_SV_ZENA]);
		Log("  _anchor_head == %s\n", _anchor_head);
		sprintf(_anchor_pom, "%s_", nazov_spolc_ANCHOR[a]);
		Log("  _anchor_pom == %s\n", _anchor_pom);

		/* prvÈ veöpery */
		modlitba = MODL_PRVE_VESPERY;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_panien(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_panien(modlitba);
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-01-25_ZALMY1NE_FIX */
			_set_zalmy_1nedele_rch();
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_vlastna_cast_kresponz_ve;

		/* posvatne citanie */
		modlitba = MODL_POSV_CITANIE;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_panien(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_panien(modlitba);
		}

		/* 2005-08-05: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		_spolocna_cast_full(modlitba);
		/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, STR_EMPTY /* 2005-08-16: _anchor_pom netreba */, _anchor_zvazok, _anchor_pom, _file);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file); /* 2006-08-07: doplnenÈ */

		/* vespery */
		if(_global_den.litobd != OBD_OKTAVA_NARODENIA){
			modlitba = MODL_VESPERY;
			if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
				Log("  _set_zalmy_sviatok_panien(%s)...\n", nazov_modlitby(modlitba));
				_set_zalmy_sviatok_panien(modlitba);
			}
			_spolocna_cast_full(modlitba);
			_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
		}/* v OBD_OKTAVA_NARODENIA -- vespery su zo dna */

	}/* MODL_SPOL_CAST_SV_ZENA_[VIACERE]... */

	/* spolocna cast na sviatky panien */
	else if((a == MODL_SPOL_CAST_PANNA) ||
		(a == MODL_SPOL_CAST_PANNY_VIACERE)){

		Log("/* spolocna cast na sviatky panien */\n");

		/* prvÈ veöpery */
		modlitba = MODL_PRVE_VESPERY;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_panien(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_panien(modlitba);
		}
		_spolocna_cast_full(modlitba);
		//_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_spolocna_cast_kresp_ve;

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-01-25_ZALMY1NE_FIX */
			_set_zalmy_1nedele_rch();
		}
		_spolocna_cast_full(modlitba);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_spolocna_cast_kresp_ve;

		/* posvatne citanie */
		modlitba = MODL_POSV_CITANIE;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_panien(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_panien(modlitba);
		}
		_spolocna_cast_full(modlitba);
		/* 2005-07-22: ToDo: skontrolovaù, Ëi pre öpeci·lne obdobia nie s˙ öpeci·lne Ëasti z obdobia */
		/* _spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file); */
		/* 2005-08-27: 1. ËÌtanie je rovnakÈ pre vöetky obdobia a zv‰zky ûalt·ra :-) */

		/* vespery */
		if(_global_den.litobd != OBD_OKTAVA_NARODENIA){
			modlitba = MODL_VESPERY;
			if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
				Log("  _set_zalmy_sviatok_panien(%s)...\n", nazov_modlitby(modlitba));
				_set_zalmy_sviatok_panien(modlitba);
			}
			_spolocna_cast_full(modlitba);
			if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
				_spolocna_cast_kresp_ve;
		}/* v OBD_OKTAVA_NARODENIA -- vespery su zo dna */

	}/* MODL_SPOL_CAST_PANNA/viacere */

	/* spolocna cast na sviatky Panny Marie */
	else if(a == MODL_SPOL_CAST_PANNA_MARIA){ /* 2005-08-25: UpravenÈ */

		Log("/* spolocna cast na sviatky Panny Marie */\n");

		/* prvÈ veöpery */
		modlitba = MODL_PRVE_VESPERY;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_marie(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_marie(modlitba);
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_prosby_viac(2, _anchor_head, _anchor, _file);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_spolocna_cast_kresp_ve;

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-01-25_ZALMY1NE_FIX */
			_set_zalmy_1nedele_rch();
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_prosby_viac(2, _anchor_head, _anchor, _file);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_spolocna_cast_kresp_ve;

		/* 2005-08-25: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_pom, "%s", STR_EMPTY);
		Log("  _anchor_pom == %s\n", _anchor_pom);
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		/* posvatne citanie */
		modlitba = MODL_POSV_CITANIE;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_marie(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_marie(modlitba);
		}
		_spolocna_cast_full(modlitba);
		/* 2005-08-25: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, _anchor_pom, _anchor_zvazok, _anchor_head, _file);
		_spolocna_cast_kresponz_zvazok(modlitba, _anchor_pom, _anchor_zvazok, _anchor_head, _file);

		/* vespery */
		if(_global_den.litobd != OBD_OKTAVA_NARODENIA){
			modlitba = MODL_VESPERY;
			if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
				Log("  _set_zalmy_sviatok_marie(%s)...\n", nazov_modlitby(modlitba));
				_set_zalmy_sviatok_marie(modlitba);
			}
			_spolocna_cast_full(modlitba);
			_spolocna_cast_prosby_viac(2, _anchor_head, _anchor, _file);
			if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
				_spolocna_cast_kresp_ve;
		}/* v OBD_OKTAVA_NARODENIA -- vespery su zo dna */

	}/* MODL_SPOL_CAST_PANNA_MARIA */

// 2006-01-19_LABEL // 2005-08-16: tu treba pokraËovaù

	/* spolocna cast na oficium za zosnulych */
	else if(a == MODL_SPOL_CAST_ZA_ZOSNULYCH){

		Log("/* spolocna cast na oficium za zosnulych */\n");

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_za_zosnulych(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_za_zosnulych(modlitba);
		}
		_spolocna_cast_full(modlitba);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_spolocna_cast_benediktus_ve;
		_spolocna_cast_ant3_viac(2, _anchor_head, _anchor, _file);

		/* vespery */
		if(_global_den.litobd != OBD_OKTAVA_NARODENIA){
			modlitba = MODL_VESPERY;
			if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
				Log("  _set_zalmy_za_zosnulych(%s)...\n", nazov_modlitby(modlitba));
				_set_zalmy_za_zosnulych(modlitba);
			}
			_spolocna_cast_full(modlitba);
			_spolocna_cast_kresponz_viac(2, _anchor_head, _anchor, _file);
			if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
				_spolocna_cast_magnifikat_ve;
		}/* v OBD_OKTAVA_NARODENIA -- vespery su zo dna */

	}/* MODL_SPOL_CAST_ZA_ZOSNULYCH */

	/* spolocna cast na sviatky posviacky chramu */
	else if(a == MODL_SPOL_CAST_POSVIACKA_CHRAMU){

		Log("/* spolocna cast na sviatky posviacky chramu */\n");

		/* prvÈ veöpery */
		modlitba = MODL_PRVE_VESPERY;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_posviacka_chramu(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_posviacka_chramu(modlitba);
		}
		_spolocna_cast_full(modlitba);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_spolocna_cast_kresponz_ve;
		if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN))
			_spolocna_cast_ant1_3_po;

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_posviacka_chramu(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_posviacka_chramu(modlitba);
		}
		_spolocna_cast_full(modlitba);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_spolocna_cast_kresponz_ve;

		/* 2005-08-25: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_pom, "%s", STR_EMPTY);
		Log("  _anchor_pom == %s\n", _anchor_pom);
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		/* posv‰tnÈ ËÌtanie; 2006-02-11 */
		modlitba = MODL_POSV_CITANIE;
		if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_posviacka_chramu(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_posviacka_chramu(modlitba);
		}
		_spolocna_cast_full(modlitba);
		/* 2005-08-25: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, _anchor_pom, _anchor_zvazok, _anchor_head, _file);

		/* vespery */
		if(_global_den.litobd != OBD_OKTAVA_NARODENIA){
			modlitba = MODL_VESPERY;
			if(su_zalmy_zo_sviatku || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
				Log("  _set_zalmy_posviacka_chramu(%s)...\n", nazov_modlitby(modlitba));
				_set_zalmy_posviacka_chramu(modlitba);
			}
			_spolocna_cast_full(modlitba);
			if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN))
				_spolocna_cast_ant1_3_po;
			if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
				_spolocna_cast_kresponz_ve;
		}/* v OBD_OKTAVA_NARODENIA -- vespery su zo dna */

	}/* MODL_SPOL_CAST_POSVIACKA_CHRAMU */

	Log("_set_spolocna_cast(%s) -- end\n", nazov_spolc(a));
}/* _set_spolocna_cast(); -- dva argumenty */

#define _set_spolocna_cast(a) _set_spolocna_cast(a, sc)


#define set_LOG_sc Log("          sc == {%s (%d), %s (%d), %s (%d)}\n",	\
	nazov_spolc(sc.a1), sc.a1, \
	nazov_spolc(sc.a2), sc.a2, \
	nazov_spolc(sc.a3), sc.a3); Log

void set_spolocna_cast(_struct_sc sc, short int poradie_svaty){
	/* poradie_svaty je vstupom iba kvoli tomu, ze ak je 0,
	 * potom nas neznepokojuju vypisy typu Error: not assigned...
	 *
	 * 22/02/2000A.D.: ked nastavi vo formulari (detaily) zalmy zo `sviatku'
	 * a spolocnu cast `nebrat', predsa sa nevyvolaju zalmy zo sviatku,
	 * lebo sa nespusti _set_spolocna_cast(); !!! -- mozno by bolo dobre
	 * oddelit nastavenie pre spolocnu cast a potom inde dat samotne zalmy...
	 * !!!
	 */
	Log("set_spolocna_cast({%s, %s, %s}) -- begin\n",
		nazov_spolc(sc.a1), nazov_spolc(sc.a2), nazov_spolc(sc.a3));
	Log("          _global_opt3 == %s (%d)\n",
		nazov_spolc(_global_opt3), _global_opt3);

	Log("  teraz nastavujem POPIS (pre daneho svateho)...\n");
	mystrcpy(_anchor, _anchor_head, MAX_STR_AF_ANCHOR);
	strcat(_anchor, ANCHOR_POPIS);
	modlitba = MODL_RANNE_CHVALY;
	set_popis(modlitba, _file, _anchor); /* pridane 05/04/2000A.D. */
	modlitba = MODL_VESPERY;
	set_popis(modlitba, _file, _anchor); /* pridane 05/04/2000A.D. */
	modlitba = MODL_POSV_CITANIE;
	set_popis(modlitba, _file, _anchor); /* pridanÈ 2005-07-22 */
	modlitba = MODL_PRVE_VESPERY;
	set_popis(modlitba, _file, _anchor); /* pridane 05/04/2000A.D. */
	/* 2006-01-27: PridanÈ popisy pre modlitby cez deÚ */
	set_popis(MODL_PREDPOLUDNIM, _file, _anchor);
	set_popis(MODL_NAPOLUDNIE, _file, _anchor);
	set_popis(MODL_POPOLUDNI, _file, _anchor);
	/* 2003-06-30: tento POPIS nie je dobre nastaveny pre spomienku
	 * NepoökvrnenÈho Srdca prebl. Panny M·rie,
	 * preto je tam nastaveny este raz na dummy, vid ZNOVUNASTAVENIE_POPISU_NA_DUMMY */

	/* tu bola pasaz, nastavujuca _global_opt3 na sc.a1 v pripade,
	 * ze je neurcena;
	 * je teraz v sviatky_svatych() so styrmi vstupmi,
	 * pretoze sa musi vykonat iba pri druhom spusteni funkcie
	 * sviatky_svatych() -- 18/02/2000A.D.
	 */

	/* podla _global_opt3 urcime, ktoru spolocnu cast dat */
	if(sc.a1 != MODL_SPOL_CAST_NEURCENA){
		if(_global_opt3 == sc.a1){
			_set_spolocna_cast(_global_opt3);
		}
		else{
			if(sc.a2 != MODL_SPOL_CAST_NEURCENA){
				if(_global_opt3 == sc.a2){
					_set_spolocna_cast(_global_opt3);
				}
				else{
					if(sc.a3 != MODL_SPOL_CAST_NEURCENA){
						if(_global_opt3 == sc.a3){
							_set_spolocna_cast(_global_opt3);
						}
						else{
							if(_global_opt3 == MODL_SPOL_CAST_NEBRAT){
								set_LOG_sc("  neberiem spolocnu cast\n");
								Export("<!--neberiem spolocnu cast-->");
							}
							else
							/* sem by to nemalo prist */
							{
							set_LOG_sc("-- Error: sc (a1, a2, a3) su sice urcene, ale _global_opt3 sa nerovna ani jednej z nich!\n");
							Export("%s\n", "Error: _global_opt3 assigned incorectly (a1, a2, a3 -- ok)");
							ALERT;
							return;
							}
						}
					}/* sc.a3 je urcena */
					else{
						if(_global_opt3 == MODL_SPOL_CAST_NEBRAT){
							set_LOG_sc("  neberiem spolocnu cast\n");
							Export("<!--neberiem spolocnu cast-->");
						}
						else
						/* sem by to nemalo prist */
						if(poradie_svaty != 0){
							set_LOG_sc("-- Error: sc (a1, a2) su sice urcene, ale _global_opt3 sa nerovna ani jednej z nich!\n");
							Export("%s\n", "Error: _global_opt3 assigned incorectly (a1, a2 -- ok)");
							ALERT;
							return;
						}
					}
				}
			}/* sc.a2 je urcena */
			else{
				if(_global_opt3 == MODL_SPOL_CAST_NEBRAT){
					set_LOG_sc("  neberiem spolocnu cast\n");
					Export("<!--neberiem spolocnu cast-->");
				}
				else
				/* sem by to nemalo prist */
				if(poradie_svaty != 0){
					set_LOG_sc("-- Error: sc (a1) je sice urcena, ale _global_opt3 sa jej nerovna!\n");
					Export("%s\n", "Error: _global_opt3 assigned incorectly (a1 -- ok)");
					ALERT;
					return;
				}
			}
		}
	}/* sc.a1 je urcene */
	else{
		/* sem by to nemalo prist */
		if(poradie_svaty != 0){
			Log("-- Error: sc (a1) nie je urcene; _global_opt3 == %s\n", nazov_spolc(_global_opt3));
			Export("%s\n", "Error: a1 (member of sc) assigned incorectly");
			ALERT;
			return;
		}
	}
	Log("set_spolocna_cast(_global_opt3 == %s) -- end\n", nazov_spolc(_global_opt3));
}/* set_spolocna_cast(); */

/* ... a teraz samotna funkcia sviatky_svatych(): */
short int sviatky_svatych(short int den, short int mesiac, short int poradie_svaty){
	/* toto priradujeme preto, aby sme nemuseli pri kazdom svatom
	 * priradovat pocet = 1; */
	short int pocet = 1;
	
	Log("-- sviatky_svatych(%d, %d) -- zaciatok\n", den, mesiac);

	/* nasledujuca pasaz v pripade, ze poradie_svaty nie je dane (t.j. nie je
	 * 1, 2 alebo 3) vycisti udaje;
	 * to je vtedy, ked je tato funkcia volana poprvykrat
	 */

	if((poradie_svaty < 1) || (poradie_svaty > 3)){
		/* den */
		_global_svaty1.den = _global_svaty2.den = _global_svaty3.den = den;
		/* mesiac */
		_global_svaty1.mesiac = _global_svaty2.mesiac = _global_svaty3.mesiac = mesiac;
		/* rok */
		_global_svaty1.rok = _global_svaty2.rok = _global_svaty3.rok = _global_den.rok;
		/* denvt */
		_global_svaty1.denvt = _global_svaty2.denvt = _global_svaty3.denvt = _global_den.denvt;
		/* denvr */
		_global_svaty1.denvr = _global_svaty2.denvr = _global_svaty3.denvr = _global_den.denvr;
		/* smer */
		_global_svaty1.smer = _global_svaty2.smer = _global_svaty3.smer = _global_den.smer;
		/* litobd */
		_global_svaty1.litobd = _global_svaty2.litobd = _global_svaty3.litobd = _global_den.litobd;
		/* litrok */
		_global_svaty1.litrok = _global_svaty2.litrok = _global_svaty3.litrok = _global_den.litrok;
		/* tyzden */
		_global_svaty1.tyzden = _global_svaty2.tyzden = _global_svaty3.tyzden = _global_den.tyzden;
		/* tyzzal */
		_global_svaty1.tyzzal = _global_svaty2.tyzzal = _global_svaty3.tyzzal = _global_den.tyzzal;
		/* typslav - neurcena */
		_global_svaty1.typslav = _global_svaty2.typslav = _global_svaty3.typslav = SLAV_NEURCENE;
		/* typ lok·lneho sl·venia - neurËenÈ; pridanÈ 2005-07-27 */
		_global_svaty1.typslav_lokal = _global_svaty2.typslav_lokal = _global_svaty3.typslav_lokal = LOKAL_SLAV_NEURCENE;
		/* prik - nie je prikazany */
		_global_svaty1.prik = _global_svaty2.prik = _global_svaty3.prik = NEPRIKAZANY_SVIATOK;
		/* meno - neurcene */
		mystrcpy(_global_svaty1.meno, STR_EMPTY, MENO_SVIATKU); /* prerobene na mystrcpy, 2003-08-13 */
		mystrcpy(_global_svaty2.meno, STR_EMPTY, MENO_SVIATKU);
		mystrcpy(_global_svaty3.meno, STR_EMPTY, MENO_SVIATKU);
		/* spolcast - neurcena */
		_global_svaty1.spolcast = _global_svaty2.spolcast = _global_svaty3.spolcast = _encode_spol_cast(MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA);
		Log("nastavil som _global_svaty[1,2,3] na default (bud neurcene alebo z _global_den)\n");
		_global_svaty1.farba = _global_svaty2.farba = _global_svaty3.farba = LIT_FARBA_NEURCENA; /* 2006-08-19: pridanÈ */
	}
	else{
		/* povodne tu bola pasaz, ktora podla poradie_svaty nastavila
		 * do _global_den = _global_svaty[1,2,3],
		 * tato pasaz je teraz na zaciatku sviatky_svatych() so styrmi
		 * vstupmi/argumentami
		 */
		Log("   (tu bola pasaz, co je teraz v sviakty_svatych() so 4 vstupmi)\n");
	}
	/* dalsia cast v zatvorkach {, } je sice len pre pripad, ze
	 * poradie_svaty == 1, 2, 3; avsak aj pre 0 je to
	 * preto, ze aj ked nie je svaty urceny, moze ist o slavnost,
	 * ktora ma takmer najvacsiu prioritu, a preto ma aj prve
	 * vespery - a vtedy by to normalne nefungovalo
	 */
	{/* pasaz kt. ma zmysel len pre poradie_svaty == 1, 2, 3, ale
	  * v pripade slavnosti aj pre == 0 */
		Log("/* nastavenie nazvu suboru, kotvy apod. (sviatky_svatych) */\n");
		/* nastavenie nazvu suboru, kotvy apod. */
		if(poradie_svaty > 1) /* pridame cislo svateho */
			sprintf(_anchor_head, "%02d%s%d_", den, nazov_MES[mesiac - 1], poradie_svaty);
		else
			sprintf(_anchor_head, "%02d%s_", den, nazov_MES[mesiac - 1]);
		Log("  _anchor_head == %s\n", _anchor_head);

		sprintf(_file, "sv_%s.htm", nazov_mes[mesiac - 1]);
		Log("  _file == %s\n", _file);

		/* 2005-07-26: s˙bor pre posv‰tnÈ ËÌtania */
		sprintf(_file_pc, "pc_sv_%s.htm", nazov_mes[mesiac - 1]);
		Log("  _file_pc == %s\n", _file_pc);
	}

	/* LOG_ciara_sv; Log("_global_den: \n"); Log(_global_den); */

	/* az teraz, ked je v _global_den (pri druhom volani fcie)
	 * spravna hodnota z _global_svaty[1,2,3], mozem urobit toto
	 * priradenie do sc
	 */
	_struct_sc sc = _decode_spol_cast(_global_den.spolcast);

	/* 2006-02-06: pridan˝ debug v˝pis */
	Log("\tDeklarujem ötrukt˙ru sc == ({%s, %s, %s}) -- begin\n",
		nazov_spolc(sc.a1), nazov_spolc(sc.a2), nazov_spolc(sc.a3));

	Log("Teraz nasleduje veæk˝ switch() podæa mesiacov a dnÌ...\n");

	/* a teraz velky switch()... 'Velky inkvizitor'... ;-) */
	switch(mesiac - 1){
		case MES_JAN:
			switch(den){
				case 2:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_02[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_VIACERI, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 7:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_07[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 13:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_13[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 17:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_17[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 18:
					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						_global_svaty1.smer = 10; /* povinne spomienky podla (vseobecneho) kalendara */
							mystrcpy(_global_svaty1.meno, text_JAN_18[_global_jazyk], MENO_SVIATKU);
							_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 20:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_20_1[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_PAPEZ);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, text_JAN_20_2[_global_jazyk], MENO_SVIATKU);
					_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
					_global_svaty2.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 21:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_21[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENICA, MODL_SPOL_CAST_PANNA);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 22:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_22[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 23:
					if(_global_jazyk == JAZYK_SK){
						/* 2005-10-24: pridanÈ, je to spomienka len v DÛme sv. Martina, BA */
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_DOM_SV_MARTINA; /* 2005-07-27: pridanÈ */
						mystrcpy(_global_svaty1.meno, text_JAN_23[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 24:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_24[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 25:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_full(modlitba);

						modlitba = MODL_VESPERY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_JAN_25[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 26:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_26[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 27:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_27[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA, MODL_SPOL_CAST_SV_ZENA_VYCH);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 28:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_28[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_UCITEL_CIRKVI, MODL_SPOL_CAST_DUCH_PAST_KNAZ);
						/* ...KNAZ nie je vo vlastnej casti, avsak aby sme vedeli,
						 * co mame dat v tych castiach, ktore nie su v uciteloch
						 * cirkvi, kde sa odvolava na duchovnych pastierov; 23/02/2000A.D.
						 */
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 31:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_31[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_SV_MUZ_VYCH);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				default: break;
			}; break; /* case MES_JAN */
		case MES_FEB:
			switch(den){
				case 1:
					break;
#ifdef WRONG_23_02_2000
					if(!((_global_den.denvt == DEN_SOBOTA) && (_global_modlitba == MODL_VESPERY)))
						break;
					else{
						den++;
						sprintf(_anchor_head, "%02d%s_", den, nazov_MES[mesiac - 1]);
						Log("  _anchor_head == %s\n", _anchor_head);
					}
#endif
					/* v opacnom pripade sa ide na case 2:
					 * treba vsak upravit kotvu _anchor
					 */
				case 2:
					//if(poradie_svaty == 1){
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* definovanie parametrov pre modlitbu */

						if((poradie_svaty == 1) &&
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sviatok_krstu(modlitba);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_1nedele_rch();

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sviatok_obetovania(modlitba);

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sviatok_krstu(modlitba);

						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 5; /* sviatky Pana uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_FEB_02[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_NEBRAT);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 3:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_FEB_03_1[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, text_FEB_03_2[_global_jazyk], MENO_SVIATKU);
					_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty2.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 5:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}

					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_FEB_05[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENICA, MODL_SPOL_CAST_PANNA);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 6:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}

					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_FEB_06[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 8:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* 2006-08-19: pridanÈ */
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_FEB_08[_global_jazyk], MENO_SVIATKU);
					/* 2006-08-08: spoloËn· Ëasù pridan· podæa mailu don Val·bka z 19. augusta 2005 */
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_VYCH, MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_SV_MUZ_SKUTKYMIL);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, text_FEB_08_2[_global_jazyk], MENO_SVIATKU);
					_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA);
					_global_svaty2.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 10:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_FEB_10[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 11:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_FEB_11[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 14:
					if(_global_jazyk == JAZYK_SK){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_benediktus;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_magnifikat;
							_vlastna_cast_modlitba;

							break;
						}
						/* na Slovensku 5. jula, slavnost, v Europe sviatok */
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_14_FEB_CYRIL_METOD; /* 2006-02-03: pridanÈ */
						mystrcpy(_global_svaty1.meno, "Sv. Cyrila, mnÌcha, a sv. Metoda, biskupa", MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_VIACERI);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 17:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_FEB_17[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 21:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_FEB_21[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 22:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_modlitba;
						_vlastna_cast_kresponz;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;

						/* 2006-02-07: doplnenÈ mcd; */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_FEB_22[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 23:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_FEB_23[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				default:
					break;
			}; break; /* case MES_FEB */
		case MES_MAR:
			switch(den){
				case 4:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					if(_global_jazyk == JAZYK_SK){
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					}
					else {
						/* v Ëeskom liturgickom kalend·ri "Nez·vazn· pam·tka" */
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					}
					mystrcpy(_global_svaty1.meno, text_MAR_04[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 7:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAR_07[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 8:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAR_08[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_REHOLNIK, MODL_SPOL_CAST_SV_MUZ_SKUTKYMIL);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 9:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAR_09[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_ZENA_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 10:
					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky */
						mystrcpy(_global_svaty1.meno, text_MAR_10[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_KNAZ);
						_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 17:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAR_17[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 18:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						/* nema modlitba = MODL_VESPERY, lebo su prve vespery slavnosti sv. Jozefa */
						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAR_18[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 19:
label_19_MAR:
					//if(poradie_svaty == 1){
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* definovanie parametrov pre modlitbu */

						if((poradie_svaty == 1) &&
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
							_vlastna_cast_kresponz_ve;
						}
						else if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN)){
							_vlastna_cast_kresponz_po;
						}
						_set_zalmy_sviatok_duch_past(modlitba);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);
						if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
							_vlastna_cast_kresponz_ve;
						}
						else if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN)){
							_vlastna_cast_kresponz_po;
						}
						_set_zalmy_1nedele_rch();

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_modlitba;
						_vlastna_cast_kresponz;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;

						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						/* 2006-02-04: ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
						if(_global_den.denvt != DEN_NEDELA) {
							_set_zalm_cez_den_doplnkova_psalmodia();
						}
						else {
							_set_zalmy_1nedele_mcd();
						}

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
							_vlastna_cast_kresponz_ve;
						}
						else if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN)){
							_vlastna_cast_kresponz_po;
						}
						_set_zalmy_sviatok_duch_past(modlitba);

						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SLAVNOST;
					_global_svaty1.smer = 3; /* slavnosti Pana, preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_MAR_19[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_NEBRAT);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 20:
					if(_global_den.denvt == DEN_PONDELOK){
						/* t.j. slavnost sv. Jozefa padla na nedelu */
						sprintf(_anchor_head, "%02d%s_", den - 1, nazov_MES[mesiac - 1]);
						Log("  _anchor_head == %s\n", _anchor_head);
						Log("jumping to label_19_MAR...\n");
						goto label_19_MAR;
					}
					break;
				case 23:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAR_23[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 25:
label_25_MAR:
					//if(poradie_svaty == 1){
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* definovanie parametrov pre modlitbu */

						if((poradie_svaty == 1) &&
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
							_vlastna_cast_kresponz_ve;
						}
						else if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN)){
							_vlastna_cast_kresponz_po;
						}
						_set_zalmy_sviatok_krstu(modlitba);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);
						if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
							_vlastna_cast_kresponz_ve;
						}
						else if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN)){
							_vlastna_cast_kresponz_po;
						}
						_set_zalmy_1nedele_rch();

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_modlitba;
						_vlastna_cast_kresponz;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;
						_set_zalmy_sviatok_obetovania(modlitba);

						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						/* 2006-02-04: ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
						if(_global_den.denvt != DEN_NEDELA) {
							_set_zalm_cez_den_doplnkova_psalmodia();
						}
						else {
							_set_zalmy_1nedele_mcd();
						}

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
							_vlastna_cast_kresponz_ve;
						}
						else if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN)){
							_vlastna_cast_kresponz_po;
						}
						_set_zalmy_sviatok_krstu(modlitba);

						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SLAVNOST;
					_global_svaty1.smer = 3; /* slavnosti Pana, preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_MAR_25[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_NEBRAT);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 26:
					if(_global_den.denvt == DEN_PONDELOK){
						/* t.j. Zvestovanie Pana padlo na nedelu */
						sprintf(_anchor_head, "%02d%s_", den - 1, nazov_MES[mesiac - 1]);
						Log("  _anchor_head == %s\n", _anchor_head);
						Log("jumping to label_25_MAR...\n");
						goto label_25_MAR;
					}
					break;
			}; break; /* case MES_MAR */
		case MES_APR:
			switch(den){
				case 2:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_APR_02[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 4:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_APR_04[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 5:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_APR_05[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 7:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_APR_07[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_SV_MUZ_VYCH);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 11:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_APR_11[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 13:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_APR_13[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_PAPEZ);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 21:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_APR_21[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 23:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					if(_global_jazyk == JAZYK_CZ){
						_global_svaty1.typslav = SLAV_SVIATOK;
						_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_PRAHA_PATRON; /* 2006-08-15: pridanÈ */
					}
					else{
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					}
					mystrcpy(_global_svaty1.meno, text_APR_23[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 24:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_APR_24_1[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, text_APR_24_2[_global_jazyk], MENO_SVIATKU);
					_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_KNAZ);
					_global_svaty2.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 25:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;
						_vlastna_cast_kresponz;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;

						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_APR_25[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 28:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						// _vlastna_cast_2citanie; // 2006-08-08: nem· 2. ËÌtanie vlastnÈ

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_APR_28_1[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, text_APR_28_2[_global_jazyk], MENO_SVIATKU);
					_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ);
					_global_svaty2.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 29:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_hymnus;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					/* 2006-01-11: pÙvodne to bola spomienka, ale don Val·bek ma upozornil, ûe sa jedn· o sviatok; upraven˝ n·zov
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; - povinne spomienky podla vseobecneho kalendara 
					*/
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_APR_29[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 30:
					if(_global_jazyk == JAZYK_SK){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty1.meno, text_APR_30_1[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_PAPEZ);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					else if(_global_jazyk == JAZYK_CZ){
						/* okrem Pia V. maj˙ aj sv. éigmunda */
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						else if(poradie_svaty == 2){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty1.meno, text_APR_30_2[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
						_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
						pocet = 2;
						_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty2.meno, text_APR_30_1[_global_jazyk], MENO_SVIATKU);
						_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_PAPEZ);
						_global_svaty2.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
			}; break; /* case MES_APR */
		case MES_MAY:
			switch(den){
				case 1:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_benediktus;
						_vlastna_cast_prosby;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_hymnus;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_magnifikat;
						_vlastna_cast_prosby;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAJ_01[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 2:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAJ_02[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 3:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_antifony;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_hymnus;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_antifony;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_MAJ_03[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 6:
					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla (vseobecneho) kalendara */
						mystrcpy(_global_svaty1.meno, text_MAJ_06[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_KNAZ);
						_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 8:
					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						_global_svaty1.smer = 10; /* povinne spomienky podla (vseobecneho) kalendara */
						mystrcpy(_global_svaty1.meno, text_MAJ_08[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 12:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					/* 2006-08-16: pridanÈ */
					else if((_global_jazyk == JAZYK_CZ) && (poradie_svaty == 3)){
						/* definovanie parametrov pre modlitbu */
						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);
						/* 2005-08-22: Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAJ_12_1[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					if(_global_jazyk == JAZYK_CZ)
						pocet = 3;
					else
						pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, text_MAJ_12_2[_global_jazyk], MENO_SVIATKU);
					_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
					_global_svaty2.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					if(_global_jazyk == JAZYK_CZ){
						_global_svaty3.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
						_global_svaty3.typslav_lokal = LOKAL_SLAV_PRAHA;
						_global_svaty3.typslav = SLAV_SVIATOK;
						mystrcpy(_global_svaty3.meno, text_MAJ_12_3[_global_jazyk], MENO_SVIATKU);
						_global_svaty3.spolcast = _encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
						_global_svaty3.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 14:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;
						_vlastna_cast_benediktus;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_hymnus;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;
						_vlastna_cast_magnifikat;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_MAJ_14[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 16:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);
						if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
							_vlastna_cast_kresponz_ve;
						/* inak zostane cezrocne, ale bez pripony */

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_hymnus;
						_vlastna_cast_kresponz;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
							_vlastna_cast_kresponz_ve;
						/* inak zostane cezrocne, ale bez pripony */

						break;
					}
					if(_global_jazyk == JAZYK_CZ){
						_global_svaty1.typslav = SLAV_SVIATOK;
						_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					}
					else { /* na Slovensku */
						/* v roznavskej dieceze sviatok (hlavny patron) */
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_ROZNAVA_PATRON; /* 2006-02-03: pridanÈ */
					}
					mystrcpy(_global_svaty1.meno, text_MAJ_16[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_MUCENIK,
							MODL_SPOL_CAST_DUCH_PAST_KNAZ);
					break;
				case 18:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAJ_18[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_MUCENIK,
							MODL_SPOL_CAST_DUCH_PAST_PAPEZ);
					break;
				case 20:
					if(_global_jazyk == JAZYK_SK){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty1.meno, text_MAJ_20_2[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast =
							_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ,
								MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					}
					else if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						else if(poradie_svaty == 2){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.typslav_lokal = LOKAL_SLAV_MORAVA_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty1.meno, text_MAJ_20_1[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast =
							_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ);
						pocet = 2;
						_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty2.meno, text_MAJ_20_2[_global_jazyk], MENO_SVIATKU);
						_global_svaty2.spolcast =
							_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ,
								MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					}
					break;
				case 21: /* 2006-08-16: pridanÈ */
					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */
							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);
							break;
							/* 2005-08-22: Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
						}
						_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_BRNO;
						_global_svaty1.typslav = SLAV_SVIATOK;
						mystrcpy(_global_svaty1.meno, text_MAJ_21[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast =
							_encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
					}
					break;
				case 25:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 3){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAJ_25_1[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_UCITEL_CIRKVI,
							MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					pocet = 3;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, text_MAJ_25_2[_global_jazyk], MENO_SVIATKU);
					_global_svaty2.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_PAPEZ);
					_global_svaty3.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty3.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty3.meno, text_MAJ_25_3[_global_jazyk], MENO_SVIATKU);
					_global_svaty3.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_PANNA,
							MODL_SPOL_CAST_SV_ZENA_REHOLNIK);
					break;
				case 26:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAJ_26[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ,
							MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					break;
				case 27:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAJ_27[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					break;
				case 31:
					/* na Slovensku sa sl·vi 2. j˙la */
					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_full(modlitba);

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_hymnus;
							_vlastna_cast_1citanie;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_full(modlitba);

							break;
						}
						_global_svaty1.typslav = SLAV_SVIATOK;
						_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
						mystrcpy(_global_svaty1.meno, text_MAJ_31[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast =
							_encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					}
					break;
			}; break; /* case MES_MAY */
		case MES_JUN:
			switch(den){
				case 1:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. JustÌna, muËenÌka", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
					break;
				case 2:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. MarcelÌna a Petra, muËenÌkov", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					break;
				case 3:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Karola Lwangu a spoloËnÌkov, muËenÌkov", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					break;
				case 5:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Bonif·ca, biskupa a muËenÌka", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_MUCENIK,
							MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					break;
				case 6:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Norberta, biskupa", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					break;
				case 9:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. EfrÈma, diakona a uËiteæa Cirkvi", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_UCITEL_CIRKVI);
					break;
				case 11:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */
						/* 2005-08-27: sviatok apoötola Barnab·öa - ûalmy a antifÛny zo dÚa - ale 
						 * len pre rannÈ chv·ly; preto vlastne to ignorujeme, nech sa napr. posv‰tnÈ ËÌtanie 
						 * alebo veöpery ber˙ z apoötolov - preto sme zapozn·mkovali nasledovnÈ priradenie:
						 * _global_opt2 = MODL_ZALMY_ZO_DNA; - ûalmy a antifÛny zo dÚa - ale len pre rannÈ chv·ly */
						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_benediktus;
						_vlastna_cast_prosby;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_hymnus;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_magnifikat;
						_vlastna_cast_prosby;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Barnab·öa, apoötola", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					break;
				case 13:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Antona Padu·nskeho, kÚaza a uËiteæa Cirkvi", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ,
							MODL_SPOL_CAST_UCITEL_CIRKVI,
							MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					break;
				case 16:
					/* 2005-07-27: pridanÈ, je to spomienka len v roûÚavskej katedr·le */
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
					_global_svaty1.typslav_lokal = LOKAL_SLAV_ROZNAVA_KATEDRALA; /* 2005-07-27: pridanÈ */
					mystrcpy(_global_svaty1.meno, "Sv. Neita, muËenÌka", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
					break;
				case 19:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Romualda, op·ta", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					break;
				case 21:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Alojza Gonz·gu, rehoænÌka", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					break;
				case 22:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. J·na Fishera, biskupa, a sv. Tom·öa MÛrusa, muËenÌkov", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, "Sv. PavlÌna z Noly, biskupa", MENO_SVIATKU);
					_global_svaty2.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					break;
				case 24:
					//if(poradie_svaty == 1){
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* definovanie parametrov pre modlitbu */

						if((poradie_svaty == 1) &&
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						_vlastna_cast_modlitba_prve_vesp;
						_set_zalmy_sviatok_duch_past(modlitba);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_1nedele_rch();

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kresponz;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;

						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						/* 2006-02-04: ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
						if(_global_den.denvt != DEN_NEDELA) {
							_set_zalm_cez_den_doplnkova_psalmodia();
						}
						else {
							_set_zalmy_1nedele_mcd();
						}

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sviatok_duch_past(modlitba);

						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SLAVNOST;
					_global_svaty1.smer = 3; /* slavnosti Pana, preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					_global_svaty1.typslav_lokal = LOKAL_SLAV_TRNAVA_PATRON; /* 2005-07-27: pridanÈ */
					mystrcpy(_global_svaty1.meno, "Narodenie sv. J·na Krstiteæa", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_NEBRAT);
					break;
				case 25:
					/* hoci slavnost narodenia sv. Jana Krstitela padla na nedelu, 
					 * slavi sa v nedelu, lebo ide o nedelu v obdobi cez rok, 
					 * ktora ma nizsiu prioritu,
					 * preto to, co tu bolo 
						if(_global_den.denvt == DEN_PONDELOK){
							sprintf(_anchor_head, "%02d%s_", den - 1, nazov_MES[mesiac - 1]);
							Log("  _anchor_head == %s\n", _anchor_head);
							Log("jumping to label_24_JUN...\n");
							goto label_24_JUN;
						}
					 * nema opodstatnenie; 
					 * 21/03/2000A.D.
					 */
					break;
				case 27:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}

					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Cyrila AlexandrijskÈho, biskupa a uËiteæa Cirkvi", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP,
							MODL_SPOL_CAST_UCITEL_CIRKVI);
					pocet = 2;
					/* v trnavskej, banskobystrickej, roznavskej a nitrianskej dieceze */
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					_global_svaty2.typslav_lokal = LOKAL_SLAV_TT_BB_NR_RO; /* 2005-07-27: pridanÈ; 2006-02-03: opravenÈ, KE nie */
					mystrcpy(_global_svaty2.meno, "Sv. Ladislava", MENO_SVIATKU);
					_global_svaty2.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_MUZ);
					break;
				case 28:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;
						/* nema vespery, lebo su 1. vespery zo sv. petra a pavla */

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Ireneja, biskupa a muËenÌka", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_MUCENIK,
							MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					break;
				case 29:
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* preto 0, ze aj ked nie je svaty urceny, ide o slavnost,
						 * ktora ma takmer najvacsiu prioritu, a preto ma aj prve
						 * vespery - a vtedy by to normalne nefungovalo;
						 * nastavenie veci pre modlitbu by sa muselo diat
						 * v predoslom dni, co je neciste riesenie
						 */
						/* definovanie parametrov pre modlitbu */

						sc = _decode_spol_cast(_global_svaty1.spolcast);
						Log("Peter a Pavol: sc: {%s, %s, %s}, svaty == %d\n\n", nazov_spolc(sc.a1), nazov_spolc(sc.a2), nazov_spolc(sc.a3), poradie_svaty);

						if(/*(poradie_svaty == 1) && */ // 23/02/2000A.D.
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						_vlastna_cast_modlitba_prve_vesp;
						_set_zalmy_sviatok_apostolov(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kresponz;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);

						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						/* 2006-02-04: ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
						if(_global_den.denvt != DEN_NEDELA) {
							_set_zalm_cez_den_doplnkova_psalmodia();
						}
						else {
							_set_zalmy_1nedele_mcd();
						}

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sviatok_apostolov(modlitba);

						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SLAVNOST;
					_global_svaty1.smer = 3; /* slavnosti Pana, preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					_global_svaty1.prik = PRIKAZANY_SVIATOK;
					mystrcpy(_global_svaty1.meno, "Sv. Petra a Pavla, apoötolov", MENO_SVIATKU);
					break;
				case 30:
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Prv˝ch sv‰t˝ch muËenÌkov Cirkvi v RÌme", MENO_SVIATKU);
					/* hoci slavnost sv. Petra a Pavla padla na nedelu, 
					 * slavi sa v nedelu, lebo ide o nedelu v obdobi cez rok, 
					 * ktora ma nizsiu prioritu,
					 * preto to, co tu bolo 
					 * "if(_global_den.denvt == DEN_PONDELOK) goto label_29_JUN;"
					 * nema opodstatnenie; porov. r. 1997
					 * 21/03/2000A.D.
					 */
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;
						_vlastna_cast_benediktus;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;
						_vlastna_cast_magnifikat;

						break;
					}
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					break;
			}; break; /* case MES_JUN */
		case MES_JUL:
			switch(den){
				case 2:
					/* vo vöeobecnom kalend·ri sa sl·vi 31. m·ja */
					if(_global_jazyk == JAZYK_SK){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_full(modlitba);

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_hymnus;
							_vlastna_cast_1citanie;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_full(modlitba);

							break;
						}
						_global_svaty1.typslav = SLAV_SVIATOK;
						_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
						mystrcpy(_global_svaty1.meno, text_MAJ_31[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast =
							_encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					}
					break;
				case 3:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_antifony_ako_na_ranne_chvaly;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, "Sv. Tom·öa, apoötola", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					break;
				case 4:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						/* nema vespery, lebo su 1. vespery zo sv. cyrila a metoda */

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Alûbety Portugalskej", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_ZENA_SKUTKYMIL,
							MODL_SPOL_CAST_SV_ZENA_MANZ /* 2006-08-08: doplnenÈ */);
					break;
				case 5:
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* preto 0, ze aj ked nie je svaty urceny, ide o slavnost,
						 * ktora ma takmer najvacsiu prioritu, a preto ma aj prve
						 * vespery - a vtedy by to normalne nefungovalo;
						 * nastavenie veci pre modlitbu by sa muselo diat
						 * v predoslom dni, co je neciste riesenie
						 */
						/* definovanie parametrov pre modlitbu */

						sc = _decode_spol_cast(_global_svaty1.spolcast);
						Log("Cyril a Metod: sc: {%s, %s, %s}, svaty == %d\n\n", nazov_spolc(sc.a1), nazov_spolc(sc.a2), nazov_spolc(sc.a3), poradie_svaty);

						if(/*(poradie_svaty == 1) && */ // 23/02/2000A.D. -- prevzate z Petra a Pavla, 23/03/2000A.D.
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_slavnost_Cyrila_a_Metoda(modlitba);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_full(modlitba);
						_set_zalmy_slavnost_Cyrila_a_Metoda(modlitba);
						/* hymnus ako na veöpery */
						sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(MODL_VESPERY), ANCHOR_HYMNUS);
						_set_hymnus(modlitba, _file, _anchor);
						set_LOG_svsv;

						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						/* 2006-02-04: ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
						if(_global_den.denvt != DEN_NEDELA) {
							_set_zalm_cez_den_doplnkova_psalmodia();
						}
						else {
							_set_zalmy_1nedele_mcd();
						}

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_slavnost_Cyrila_a_Metoda(modlitba);

						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SLAVNOST;
					_global_svaty1.smer = 3; /* slavnosti Pana, preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, "Sv. Cyrila a Metoda, slovansk˝ch vierozvestov, apoötolov", MENO_SVIATKU);
					break;
				case 6:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. M·rie Goretti, panny a muËenice", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_MUCENICA,
							MODL_SPOL_CAST_PANNA);
					/* hoci slavnost sv. Cyrila a Metoda padla na nedelu, 
					 * slavi sa v nedelu, lebo ide o nedelu v obdobi cez rok, 
					 * ktora ma nizsiu prioritu,
					 * preto to, co tu bolo 
					 * "if(_global_den.denvt == DEN_PONDELOK) goto label_5_JUL;"
					 * nema opodstatnenie; porov. 1998
					 * 21/03/2000A.D.
					 */
					break;
				case 7:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Antona M·rie Zaccariu, kÚaza", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ,
							MODL_SPOL_CAST_SV_MUZ_VYCH,
							MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					break;
				case 11:
					/* spomienka, v Europe sviatok */
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus
						_vlastna_cast_prosby;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_hymnus; /* 2006-02-02: doplnenÈ; hymnus ako na veöpery */
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_kresponz;
						_vlastna_cast_magnifikat;
						_vlastna_cast_prosby;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, "Sv. Benedikta, op·ta, patrÛna EurÛpy", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					break;
				case 13:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Henricha", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_MUZ);
					break;
				case 14:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Kamila de Lellis, kÚaza", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_SKUTKYMIL,
							MODL_SPOL_CAST_DUCH_PAST_KNAZ /* 2006-08-08: doplnenÈ */);
					break;
				case 15:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Bonavent˙ru, biskupa a uËiteæa Cirkvi", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP,
							MODL_SPOL_CAST_UCITEL_CIRKVI);
					break;
				case 16:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Prebl. Panny M·rie Karmelskej", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					break;
				case 17:
					/* v Nitrianskej dieceze sviatok - hlavni patroni */
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kresponz;
						_vlastna_cast_benediktus;
						_vlastna_cast_prosby;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;
						_vlastna_cast_1citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					_global_svaty1.typslav_lokal = LOKAL_SLAV_NITRA_PATRON; /* 2005-08-04: pridanÈ */
					mystrcpy(_global_svaty1.meno, "Sv. Andreja-Svorada a Benedikta, pustovnÌkov", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_VIACERI);
					break;
				case 21:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Vavrinca z Brindisi, kÚaza a uËiteæa Cirkvi", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ,
							MODL_SPOL_CAST_UCITEL_CIRKVI);
					break;
				case 22:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kresponz;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;
						/* hymnus ako na veöpery */
						sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(MODL_VESPERY), ANCHOR_HYMNUS);
						_set_hymnus(modlitba, _file, _anchor);
						set_LOG_svsv;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kresponz;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. M·rie MagdalÈny", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_ZENA);
					break;
				case 23:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					/* _global_svaty1.smer = 12; */
					/* zmena, na ktoru ma mailom zo dna Monday, July 23, 2001 11:40 AM upozornil 
					 * Marian Val·bek,SDB <marian.valabek@donbosco.sk>:
					 * "ProsÌm opravte Sv. Brigita je spolu so sv. KatarÌnou Sienskou a 
					 *  sv. TerÈziou Benediktou z KrÌza spolupatrÛnkou EurÛpy a teda je 
					 *  to v EurÛpe sviatok od 1999."
					 * 07/09/2001A.D.
					 *
					 * 2006-01-11: opravenÈ: do n·zvu pridanÈ ", spolupatrÛnky EurÛpy"
					 */
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Brigity, rehoænÌËky, spolupatrÛnky EurÛpy", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_ZENA_REHOLNIK);
					break;
				case 25:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_antifony;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, "Sv. Jakuba, apoötola", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					break;
				case 26:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;
						/* hymnus ako na veöpery */
						sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(MODL_VESPERY), ANCHOR_HYMNUS);
						_set_hymnus(modlitba, _file, _anchor);
						set_LOG_svsv;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Joachima a Anny, rodiËov Panny M·rie", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_MANZ); /* 2006-08-07: upravenÈ lebo ûili v manûelstve :) */
					break;
				case 27:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Gorazda a spoloËnÌkov", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_VIACERI);
					break;
				case 29:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;
						/* hymnus ako na veöpery */
						sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(MODL_VESPERY), ANCHOR_HYMNUS);
						_set_hymnus(modlitba, _file, _anchor);
						set_LOG_svsv;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Marty", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_ZENA);
					break;
				case 30:
				/* 2004-08-14, duurko
				 * Sviatok Bl. Zdenky Schelingovej, panny a muËenice, ako 2. moznost.
				 * Upozornil Jan Kusenda <exonkuda@savba.sk>.
				 */
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						// _vlastna_cast_2citanie; // 2006-08-08: nem· 2. ËÌtanie vlastnÈ

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Petra ChryzolÛga, biskupa a uËiteæa Cirkvi", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP,
							MODL_SPOL_CAST_UCITEL_CIRKVI);
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara - Slovensko */
					mystrcpy(_global_svaty2.meno, "Bl. Zdenky Schelingovej, panny a muËenice", MENO_SVIATKU);
					_global_svaty2.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_MUCENICA,
							MODL_SPOL_CAST_PANNA);
					break;
				case 31:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Ign·ca z Loyoly, kÚaza", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ,
							MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					break;
			}; break; /* case MES_JUL */
		case MES_AUG:
			switch(den){
				case 1:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Alfonza M·rie deí Ligouri, biskupa a uËiteæa Cirkvi", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP,
							MODL_SPOL_CAST_UCITEL_CIRKVI);
					break;
				case 2:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						// _vlastna_cast_2citanie; // 2006-08-08: nem· 2. ËÌtanie vlastnÈ

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. EuzÈbia VercellskÈho, biskupa", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, "Sv. Petra Juli·na Eymard, kÚaza", MENO_SVIATKU);
					_global_svaty2.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ,
							MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					break;
				case 4:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. J·na M·rie Vianneya, kÚaza", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ);
					break;
				case 5:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "V˝roËie posviacky hlavnej mari·nskej baziliky v RÌme", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					break;
				case 6:
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_NEBRAT);
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* preto 0, ze aj ked nie je svaty urceny, ide o sviatok Pana,
						 * ktora ma velku prioritu, a preto ma aj - ak je nedela - prve
						 * vespery 
						 */
						/* definovanie parametrov pre modlitbu */

						sc = _decode_spol_cast(_global_svaty1.spolcast);
						Log("Premenenie Pana: sc: {%s, %s, %s}, svaty == %d\n\n", nazov_spolc(sc.a1), nazov_spolc(sc.a2), nazov_spolc(sc.a3), poradie_svaty);

						if(/*(poradie_svaty == 1) && */ // 23/02/2000A.D. -- prevzate z Petra a Pavla, 28/03/2000A.D.
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_premenenie(modlitba);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_premenenie(modlitba); /* preto, lebo nespustame zaltar(); 28/03/2000A.D. */

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_full(modlitba);
						_set_zalmy_premenenie(modlitba);

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_premenenie(modlitba);

						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 5; /* sviatky Pana uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, "Premenenie P·na", MENO_SVIATKU);
					break;
				case 7:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Sixta II., p·peûa, a jeho spoloËnÌkov, muËenÌkov", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, "Sv. Kajet·na, kÚaza", MENO_SVIATKU);
					_global_svaty2.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ,
							MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					break;
				case 8:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Dominika, kÚaza", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ,
							MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					break;
				case 9:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					/* _global_svaty1.smer = 12; */
					/* zmena, na ktoru ma mailom zo dna Monday, July 23, 2001 11:40 AM upozornil 
					 * Marian Val·bek,SDB <marian.valabek@donbosco.sk>:
					 * "ProsÌm opravte Sv. Brigita je spolu so sv. KatarÌnou Sienskou a 
					 *  sv. TerÈziou Benediktou z KrÌza spolupatrÛnkou EurÛpy a teda je 
					 *  to v EurÛpe sviatok od 1999."
					 * 26/09/2001A.D.
					 *
					 * 2006-01-11: opravenÈ, do n·zvu pridanÈ: ", spolupatrÛnky EurÛpy"
					 */
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. TerÈzie Benedikty, rehoænÌËky a muËenice, spolupatrÛnky EurÛpy", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_ZENA_REHOLNIK,
							MODL_SPOL_CAST_MUCENICA);
					break;
				case 10:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;
						/* hymnus ako na veöpery */
						sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(MODL_VESPERY), ANCHOR_HYMNUS);
						_set_hymnus(modlitba, _file, _anchor);
						set_LOG_svsv;

						modlitba = MODL_VESPERY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, "Sv. Vavrinca, diakona a muËenÌka", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
					break;
				case 11:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Kl·ry, panny", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_PANNA,
							MODL_SPOL_CAST_SV_ZENA_REHOLNIK);
					break;

				/* 2004-08-14, duurko
				 * Sviatok Sv. Jany Frantiöky de Chantal presunuty z 12. decembra na 12. augusta.
				 */
				case 12:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Jany Frantiöky de Chantal, rehoænÌËky", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_ZENA_REHOLNIK,
							MODL_SPOL_CAST_SV_ZENA_MANZ /* 2006-08-08: doplnenÈ */);
					break;
				case 13:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Ponci·na, p·peûa, a sv. Hypolita, kÚaza, muËenÌkov", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV,
							MODL_SPOL_CAST_DUCH_PAST_VIACERI);
					break;
				case 14:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						/* nema vespery, lebo su prve vespery nanebovzatia p. marie */
						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Maximili·na Kolbeho, kÚaza a muËenÌka", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ,
							MODL_SPOL_CAST_MUCENIK);
					break;
				case 15:
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* preto 0, ze aj ked nie je svaty urceny, ide o sviatok Pana,
						 * ktora ma velku prioritu, a preto ma aj - ak je nedela - prve
						 * vespery 
						 */
						/* definovanie parametrov pre modlitbu */

						sc = _decode_spol_cast(_global_svaty1.spolcast);
						Log("Premenenie Pana: sc: {%s, %s, %s}, svaty == %d\n\n", nazov_spolc(sc.a1), nazov_spolc(sc.a2), nazov_spolc(sc.a3), poradie_svaty);

						if(/*(poradie_svaty == 1) && */ // 23/02/2000A.D. -- prevzate z Petra a Pavla, 28/03/2000A.D.
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						_vlastna_cast_modlitba_prve_vesp;
						_set_zalmy_sviatok_panien(modlitba);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sviatok_panien(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kresponz;

						/* 2006-02-07: doplnenÈ mcd */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						/* 2006-02-04: ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
						if(_global_den.denvt != DEN_NEDELA) {
							_set_zalm_cez_den_doplnkova_psalmodia();
						}
						else {
							_set_zalmy_1nedele_mcd();
						}

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sviatok_panien(modlitba);

						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SLAVNOST;
					_global_svaty1.smer = 3; /* slavnosti Pana, preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					_global_svaty1.prik = PRIKAZANY_SVIATOK;
					mystrcpy(_global_svaty1.meno, "Nanebovzatie prebl. Panny M·rie", MENO_SVIATKU);
					break;
				case 16:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. ätefana UhorskÈho", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_MANZ); /* 2006-08-07: upravenÈ lebo ûil v manûelstve :) */
					break;
				case 19:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. J·na Eudes, kÚaza", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ,
							MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 20:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Bernarda, op·ta a uËiteæa Cirkvi", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_UCITEL_CIRKVI,
							MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 21:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Pia X., p·peûa", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_PAPEZ);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 22:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Prebl. Panny M·rie Kr·æovnej", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 23:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Ruûeny Limskej, panny", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_PANNA,
							MODL_SPOL_CAST_SV_ZENA_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 24:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, "Sv. Bartolomeja, apoötola", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 25:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Jozefa de Calasanz, kÚaza", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_VYCH,
							MODL_SPOL_CAST_DUCH_PAST_KNAZ);
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, "Sv. ºudovÌta", MENO_SVIATKU);
					_global_svaty2.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_MANZ); /* 2006-08-07: upravenÈ lebo ûil v manûelstve :) */
					break;
				case 27:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Moniky", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_ZENA);
					break;
				case 28:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. AugustÌna, biskupa a uËiteæa Cirkvi", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP,
							MODL_SPOL_CAST_UCITEL_CIRKVI);
					break;
				case 29:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;
						/* hymnus ako na veöpery */
						sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(MODL_VESPERY), ANCHOR_HYMNUS);
						_set_hymnus(modlitba, _file, _anchor);
						set_LOG_svsv;

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "MuËenÌcka smrù sv. J·na Krstiteæa", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
					break;
				case 30: /* 2005-10-17: pridanÈ */
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */
						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);
						break;
						/* 2005-08-22: Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
					}
					_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
					_global_svaty1.typslav_lokal = LOKAL_SLAV_TRNAVA;
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					mystrcpy(_global_svaty1.meno, "V˝roËie posviacky katedr·lneho chr·mu v Trnave", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
					break;
				default:
					break;
			}; break; /* case MES_AUG */
		case MES_SEP:
			switch(den){
				case 3:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Gregora VeækÈho, p·peûa a uËiteæa Cirkvi", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_PAPEZ,
							MODL_SPOL_CAST_UCITEL_CIRKVI);
					break;
				case 6:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */
						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);
						break;
						/* 2005-08-22: Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
					}
					_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
					_global_svaty1.typslav_lokal = LOKAL_SLAV_KOSICE; /* 2005-08-22: pridanÈ */
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					mystrcpy(_global_svaty1.meno, "V˝roËie posviacky katedr·lneho chr·mu v Koöiciach", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
					break;
				case 7:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Marka Kriûina, Melichara GrodzieckÈho a ätefana Pongr·cza, kÚazov a muËenÌkov", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					break;
				case 8:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;
						_vlastna_cast_1citanie;
						/* hymnus ako na veöpery */
						sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(MODL_VESPERY), ANCHOR_HYMNUS);
						_set_hymnus(modlitba, _file, _anchor);
						set_LOG_svsv;

						/* 2006-02-07: doplnenÈ mcd */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						modlitba = MODL_VESPERY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, "Narodenie prebl. Panny M·rie", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					break;
				case 9:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						// _vlastna_cast_2citanie; // 2006-08-08: nie je...

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Petra Clavera, kÚaza", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ,
							MODL_SPOL_CAST_SV_MUZ_SKUTKYMIL);
					break;
				case 12:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Mena prebl. Panny M·rie", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					break;
				case 13:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. J·na Zlato˙steho, biskupa a uËiteæa Cirkvi", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP,
							MODL_SPOL_CAST_UCITEL_CIRKVI);
					break;
				case 14:
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_NEBRAT);
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* preto 0, ze aj ked nie je svaty urceny, ide o sviatok Pana,
						 * ktora ma velku prioritu, a preto ma aj - ak je nedela - prve
						 * vespery 
						 */
						/* definovanie parametrov pre modlitbu */

						sc = _decode_spol_cast(_global_svaty1.spolcast);
						Log("Povysenie sv. Kriza: sc: {%s, %s, %s}, svaty == %d\n\n", nazov_spolc(sc.a1), nazov_spolc(sc.a2), nazov_spolc(sc.a3), poradie_svaty);

						if(/*(poradie_svaty == 1) && */ // 23/02/2000A.D. -- prevzate z Petra a Pavla, 28/03/2000A.D.
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sv_kriz(modlitba);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sv_kriz(modlitba); /* preto, lebo nespustame zaltar(); 28/03/2000A.D. */

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sv_kriz(modlitba);

						/* 2006-02-07: doplnenÈ mcd;
						 *             ûalmy pre mcd s˙ zo dÚa, vyrieöenÈ pomocou ZALTAR_IBA_ZALMY_HYMNUS_MCD
						 */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sv_kriz(modlitba);

						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 5; /* sviatky Pana uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, "Pov˝öenie sv‰tÈho krÌûa", MENO_SVIATKU);
					break;
				case 15:
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* preto 0, ze aj ked nie je svaty urceny, ide o slavnost,
						 * ktora ma takmer najvacsiu prioritu, a preto ma aj prve
						 * vespery - a vtedy by to normalne nefungovalo;
						 * nastavenie veci pre modlitbu by sa muselo diat
						 * v predoslom dni, co je neciste riesenie
						 */
						/* definovanie parametrov pre modlitbu */

						sc = _decode_spol_cast(_global_svaty1.spolcast);
						Log("Sedembolestnej Panny Marie, patronky Slovenska: sc: {%s, %s, %s}, svaty == %d\n\n", nazov_spolc(sc.a1), nazov_spolc(sc.a2), nazov_spolc(sc.a3), poradie_svaty);

						if(/*(poradie_svaty == 1) && */ // 23/02/2000A.D.; zobrate z 8.dec; 28/03/2000A.D.
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sviatok_panien(modlitba);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_full(modlitba);

						/* 2006-02-07: doplnenÈ mcd; */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						/* 2006-02-04: ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
						if(_global_den.denvt != DEN_NEDELA) {
							_set_zalm_cez_den_doplnkova_psalmodia();
						}
						else {
							_set_zalmy_1nedele_mcd();
						}

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sviatok_panien(modlitba);

						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SLAVNOST;
					_global_svaty1.smer = 3; /* slavnosti Pana, preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, "Sedembolestnej Panny M·rie, patrÛnky Slovenska", MENO_SVIATKU);
					break;
				case 16:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. KornÈlia, p·peûa, a sv. Cypri·na, biskupa, muËenÌkov", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV,
							MODL_SPOL_CAST_DUCH_PAST_VIACERI);
					break;
				case 17:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. RÛberta BellarmÌna, biskupa a uËiteæa Cirkvi", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP,
							MODL_SPOL_CAST_UCITEL_CIRKVI);
					break;
				case 19:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Janu·ra, biskupa a muËenÌka", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_MUCENIK,
							MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					break;
				case 20:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Andreja Kim Taegona, kÚaza, a sv. Pavla Chong Hasanga a spoloËnÌkov, muËenÌkov", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					break;
				case 21:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, "Sv. Mat˙öa, apoötola a evanjelistu", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					break;
				case 22: /* 2005-10-13: pridanÈ */
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
					_global_svaty1.typslav_lokal = LOKAL_SLAV_NITRA;
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					mystrcpy(_global_svaty1.meno, "Sv. Emer·ma, biskupa a muËenÌka", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_MUCENIK,
							MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					break;
				case 23: /* 2004-09-23, pridane - pater Pio */
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						// _vlastna_cast_2citanie; // 2006-08-09: nem· zatiaæ vlastnÈ druhÈ ËÌtanie

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Pia z PietrelËiny, kÚaza", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ);
					break;
				case 24: /* 2005-10-13: pridanÈ */
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */
						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);
						break;
						/* 2005-08-22: Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
					}
					_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
					_global_svaty1.typslav_lokal = LOKAL_SLAV_BYSTRICA;
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					mystrcpy(_global_svaty1.meno, "V˝roËie posviacky katedr·lneho chr·mu v Banskej Bystrici", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
					break;
				case 26:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Kozmu a Dami·na, muËenÌkov", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					break;
				case 27:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Vincenta de Paul, kÚaza", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ,
							MODL_SPOL_CAST_SV_MUZ_SKUTKYMIL);
					break;
				case 28:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. V·clava, muËenÌka", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, "Sv. Vavrinca Ruiza a spoloËnÌkov, muËenÌkov", MENO_SVIATKU);
					_global_svaty2.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					break;
				case 29:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_archanjelov(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_full(modlitba);
						_set_zalmy_archanjelov(modlitba);

						/* 2006-02-07: doplnenÈ mcd; */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_archanjelov(modlitba);

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, "Sv. Michala, Gabriela a Rafaela, archanjelov", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_NEBRAT);
					break;
				case 30:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Hieronyma, kÚaza a uËiteæa Cirkvi", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_UCITEL_CIRKVI);
					break;
			}; break; /* case MES_SEP */
		case MES_OCT:
			switch(den){
				case 1:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. TerÈzie z Lisieux, panny a uËiteæky Cirkvi", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_PANNA,
							MODL_SPOL_CAST_UCITEL_CIRKVI);
					break;
				case 2:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_anjelov_strazcov(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						/* 2006-02-07: doplnenÈ mcd; */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_anjelov_strazcov(modlitba);

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv‰t˝ch anjelov str·ûcov", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_NEBRAT);
					break;
				case 4:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Frantiöka AssiskÈho", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					break;
				case 6:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Bruna, kÚaza", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ,
							MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					break;
				case 7:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Ruûencovej prebl. Panny M·rie", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					break;
				case 9:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Dion˝zia, biskupa, a spoloËnÌkov, muËenÌka", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, "Sv. J·na Leonardiho, kÚaza", MENO_SVIATKU);
					_global_svaty2.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ,
							MODL_SPOL_CAST_SV_MUZ_SKUTKYMIL);
					break;
				case 14:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Kalixta I., p·peûa a muËenÌka", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_MUCENIK,
							MODL_SPOL_CAST_DUCH_PAST_PAPEZ);
					break;
				case 15:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. TerÈzie z Avily, panny a uËiteæky Cirkvi", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_PANNA,
							MODL_SPOL_CAST_UCITEL_CIRKVI);
					break;
				case 16:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Margity M·rie Alacoque, panny", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_PANNA,
							MODL_SPOL_CAST_SV_ZENA_REHOLNIK);
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, "Sv. Hedvigy, rehoænÌËky", MENO_SVIATKU);
					_global_svaty2.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_ZENA_SKUTKYMIL,
							MODL_SPOL_CAST_SV_ZENA_REHOLNIK,
							MODL_SPOL_CAST_SV_ZENA_MANZ /* 2006-08-07: doplnenÈ */);
					break;
				case 17:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Ign·ca AntiochijskÈho, biskupa a muËenÌka", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_MUCENIK,
							MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					break;
				case 18:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_hymnus;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;

						/* 2006-02-07: doplnenÈ mcd; */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, "Sv. Luk·öa, evanjelistu", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					break;
				case 19:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. J·na de BrÈbeuf a sv. Iz·ka Jogues, kÚazov, a ich spoloËnÌkov, muËenÌkov", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV,
							MODL_SPOL_CAST_DUCH_PAST_VIACERI);
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, "Sv. Pavla z KrÌûa, kÚaza", MENO_SVIATKU);
					_global_svaty2.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ,
							MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					break;
				case 23:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. J·na Kapistr·nskeho, kÚaza", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ);
					break;
				case 24:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Antona M·rie Clareta, biskupa", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					break;
				case 25: /* 2005-10-13: pridanÈ */
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */
						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);
						break;
						/* 2005-08-22: Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
					}
					_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
					_global_svaty1.typslav_lokal = LOKAL_SLAV_SPIS;
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					mystrcpy(_global_svaty1.meno, "V˝roËie posviacky katedr·lneho chr·mu v Spiöskom PodhradÌ", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
					break;
				case 26: /* 2006-02-03: pridanÈ */
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */
						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);
						break;
						/* Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
					}
					_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
					_global_svaty1.typslav_lokal = LOKAL_SLAV_KONSEKR_KOSTOLY;
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					mystrcpy(_global_svaty1.meno, "V˝roËie posviacky chr·mov, ktor˝ch deÚ posviacky je nezn·my", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
					break;
				case 27: /* 2005-10-13: pridanÈ */
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */
						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);
						break;
						/* 2005-08-22: Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
					}
					_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
					_global_svaty1.typslav_lokal = LOKAL_SLAV_ROZNAVA;
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					mystrcpy(_global_svaty1.meno, "V˝roËie posviacky katedr·lneho chr·mu v RoûÚave", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
					break;
				case 28:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, "Sv. äimona a J˙du, apoötolov", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					break;
			}; break; /* case MES_OCT */
		case MES_NOV:
			switch(den){
				case 1:
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_NEBRAT);
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* preto 0, ze aj ked nie je svaty urceny, ide o sviatok Pana,
						 * ktora ma velku prioritu, a preto ma aj - ak je nedela - prve
						 * vespery 
						 */
						/* definovanie parametrov pre modlitbu */

						sc = _decode_spol_cast(_global_svaty1.spolcast);
						Log("Premenenie Pana: sc: {%s, %s, %s}, svaty == %d\n\n", nazov_spolc(sc.a1), nazov_spolc(sc.a2), nazov_spolc(sc.a3), poradie_svaty);

						if(/*(poradie_svaty == 1) && */ // 23/02/2000A.D. -- prevzate z Petra a Pavla, 29/03/2000A.D.
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_vsetkych_svatych(modlitba);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_vsetkych_svatych(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_full(modlitba);
						_set_zalmy_vsetkych_svatych(modlitba);

						/* 2006-02-07: doplnenÈ mcd; */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						/* 2006-02-04: ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
						if(_global_den.denvt != DEN_NEDELA) {
							_set_zalm_cez_den_doplnkova_psalmodia();
						}
						else {
							_set_zalmy_1nedele_mcd();
						}

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_vsetkych_svatych(modlitba);

						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SLAVNOST;
					_global_svaty1.smer = 3; /* slavnosti Pana, preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					_global_svaty1.prik = PRIKAZANY_SVIATOK;
					mystrcpy(_global_svaty1.meno, "Vöetk˝ch sv‰t˝ch", MENO_SVIATKU);
					break;
				case 2:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 3; /* vsetkych vernych zosnulych */
					mystrcpy(_global_svaty1.meno, "Vöetk˝ch vern˝ch zosnul˝ch", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_ZA_ZOSNULYCH);
					break;
				case 3:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Martina de Porres, rehoænÌka", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					break;
				case 4:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Karola Borromea, biskupa", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					break;
				case 5:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					_global_svaty1.typslav_lokal = LOKAL_SLAV_TT_BB_KE_NR_RO; /* 2006-02-03: pridanÈ */
					mystrcpy(_global_svaty1.meno, "Sv. Imricha", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_MUZ);
					break;
				case 9:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */
						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer =  5; /* sviatky Pana uvedene vo vseobecnom kalendari */
						/* povodne: 7; sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
						/* lenze 9. NOV 1997 mal tento sviatok prednost pred 32. nedelou v ocr, takze smer == 5 */
					mystrcpy(_global_svaty1.meno, "V˝roËie posviacky Later·nskej baziliky", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
					break;
				case 10:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Leva VeækÈho, p·peûa a uËiteæa Cirkvi", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_PAPEZ,
							MODL_SPOL_CAST_UCITEL_CIRKVI);
					break;
				case 11:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;
						/* hymnus ako na veöpery */
						sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(MODL_VESPERY), ANCHOR_HYMNUS);
						_set_hymnus(modlitba, _file, _anchor);

						modlitba = MODL_VESPERY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Martina z Tours, biskupa", MENO_SVIATKU);
					_global_svaty1.typslav_lokal = LOKAL_SLAV_SPIS_PATRON; /* 2005-10-28: pridanÈ */
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					break;
				case 12:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Jozaf·ta, biskupa a muËenÌka", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_MUCENIK,
							MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					break;
				case 15:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Alberta VeækÈho, biskupa a uËiteæa Cirkvi", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP,
							MODL_SPOL_CAST_UCITEL_CIRKVI);
					break;
				case 16:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Margity äkÛtskej", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_ZENA_MANZ /* 2006-08-07: doplnenÈ */,
							MODL_SPOL_CAST_SV_ZENA_SKUTKYMIL);
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, "Sv. Gertr˙dy, panny", MENO_SVIATKU);
					_global_svaty2.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_PANNA,
							MODL_SPOL_CAST_SV_ZENA_REHOLNIK);
					break;
				case 17:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Alûbety Uhorskej, rehoænÌËky", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_SV_ZENA_REHOLNIK,
							MODL_SPOL_CAST_SV_ZENA_MANZ /* 2006-08-08: doplnenÈ */,
							MODL_SPOL_CAST_SV_ZENA_SKUTKYMIL);
					break;
				case 18:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "V˝roËie posviacky bazilÌk sv. Petra a sv. Pavla, apoötolov", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					break;
				case 21:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Obetovanie prebl. Panny M·rie", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					break;
				case 20: /* 2005-10-28: pridanÈ */
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */
						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);
						break;
						/* 2005-08-22: Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
					}
					_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
					_global_svaty1.typslav_lokal = LOKAL_SLAV_NITRA;
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					mystrcpy(_global_svaty1.meno, "V˝roËie posviacky katedr·lneho chr·mu v Nitre", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
					break;
				case 22:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. CecÌlie, panny a muËenice", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_MUCENICA,
							MODL_SPOL_CAST_PANNA);
					break;
				case 23:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Klementa I. p·peûa a muËenÌka", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_MUCENIK,
							MODL_SPOL_CAST_DUCH_PAST_PAPEZ);
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, "Sv. Kolumb·na, op·ta", MENO_SVIATKU);
					_global_svaty2.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ,
							MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					break;
				case 24:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Ondreja Dung-Laca a spoloËnÌkov, muËenÌkov", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					break;
				case 25:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. KatarÌny Alexandrijskej, panny", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_MUCENIK,
							MODL_SPOL_CAST_PANNA);
					break;
				case 30:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, "Sv. Ondreja, apoötola", MENO_SVIATKU);
					_global_svaty1.typslav_lokal = LOKAL_SLAV_KOSICE_PATRON; /* 2006-02-03: pridanÈ */
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					break;
			}; break; /* case MES_NOV */
		case MES_DEC:;
			switch(den){
				case 3:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Frantiöka XaverskÈho, kÚaza", MENO_SVIATKU);
					_global_svaty1.typslav_lokal = LOKAL_SLAV_BYSTRICA_PATRON; /* 2006-02-03: pridanÈ */
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ);
					break;
				case 4:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. J·na DamascÈnskeho, kÚaza a uËiteæa Cirkvi", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ,
							MODL_SPOL_CAST_UCITEL_CIRKVI);
					break;
				case 6:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Mikul·öa, biskupa", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					break;
				case 7:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. AmbrÛza, biskupa a uËiteæa Cirkvi", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP,
							MODL_SPOL_CAST_UCITEL_CIRKVI);
					break;
				case 8:
label_8_DEC:
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* preto 0, ze aj ked nie je svaty urceny, ide o slavnost,
						 * ktora ma takmer najvacsiu prioritu, a preto ma aj prve
						 * vespery - a vtedy by to normalne nefungovalo;
						 * nastavenie veci pre modlitbu by sa muselo diat
						 * v predoslom dni, co je neciste riesenie
						 */
						/* definovanie parametrov pre modlitbu */

						sc = _decode_spol_cast(_global_svaty1.spolcast);
						Log("Neposkvrnene pocatie Panny Marie: sc: {%s, %s, %s}, svaty == %d\n\n", nazov_spolc(sc.a1), nazov_spolc(sc.a2), nazov_spolc(sc.a3), poradie_svaty);

						if(/*(poradie_svaty == 1) && */ // 23/02/2000A.D.
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sviatok_panien(modlitba);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_full(modlitba);
						/* 2005-10-24: moûno bude potrebnÈ nastaviù ûalmy? */
						_set_zalmy_sviatok_marie(modlitba);
						/* 2006-02-03: celkom dobr· intuÌcia :) ûalmy nastavenÈ */

						/* 2006-02-07: doplnenÈ mcd; */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						/* 2006-02-04: ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
						if(_global_den.denvt != DEN_NEDELA) {
							_set_zalm_cez_den_doplnkova_psalmodia();
						}
						else {
							_set_zalmy_1nedele_mcd();
						}

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sviatok_panien(modlitba);

						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SLAVNOST;
					_global_svaty1.smer = 3; /* slavnosti Pana, preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					_global_svaty1.prik = PRIKAZANY_SVIATOK;
					mystrcpy(_global_svaty1.meno, text_DEC_08[_global_jazyk], MENO_SVIATKU);
					break;
				case 9:
					if(_global_den.denvt == DEN_PONDELOK){
						/* 05/04/2000A.D. -- bolo to tu zle */
						/* t.j. slavnost neposkvrneneho pocatia P. Marie padla na nedelu */
						sprintf(_anchor_head, "%02d%s_", den - 1, nazov_MES[mesiac - 1]);
						Log("  _anchor_head == %s\n", _anchor_head);
						Log("jumping to label_8_DEC...\n");
						goto label_8_DEC;
					}
					break;
				case 11:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Damaza I., p·peûa", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_PAPEZ);
					break;

				/* 2004-08-14, duurko
				 * Sviatok Sv. Jany Frantiöky de Chantal presunuty z 12. decembra na 12. augusta.
				 */

				case 13:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Lucie, panny a muËenice", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_MUCENICA,
							MODL_SPOL_CAST_PANNA);
					break;
				case 14:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. J·na z KrÌûa, kÚaza a uËiteæa Cirkvi", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ,
							MODL_SPOL_CAST_UCITEL_CIRKVI);
					break;
				case 21:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Petra KanÌzia, kÚaza a uËiteæa Cirkvi", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ,
							MODL_SPOL_CAST_UCITEL_CIRKVI);
					break;
				case 23:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. J·na KentskÈho, kÚaza", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ);
					break;
				case 26:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_benediktus;
						//_vlastna_cast_prosby;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE; /* 2006-02-04: doplnenÈ */
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kresponz;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;
						_vlastna_cast_modlitba;

						/* modlitba cez deÚ, pridanÈ 2006-02-05 */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						/* vespery -- vsetko je z oktavy narodenia Pana */
						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, "Sv. ätefana, prvÈho muËenÌka", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
					break;
				case 27:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_benediktus;
						_vlastna_cast_prosby;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE; /* 2006-02-04: doplnenÈ */
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						/* _vlastna_cast_kresponz; - zo sviatkov apoötolov */
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;
						_vlastna_cast_modlitba;
						_set_zalmy_sviatok_jana_ap(modlitba);

						/* modlitba cez deÚ, pridanÈ 2006-02-05 */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						/* vespery -- vsetko je z oktavy narodenia Pana */
						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, "Sv. J·na, apoötola a evanjelistu", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					break;
				case 28:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_benediktus;
						_vlastna_cast_prosby;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE; /* 2006-02-04: doplnenÈ */
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kresponz;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;
						_vlastna_cast_modlitba;

						/* modlitba cez deÚ, pridanÈ 2006-02-05 */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						/* vespery -- vsetko je z oktavy narodenia Pana */
						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, "Sv‰t˝ch Neviniatok, muËenÌkov", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					break;
				case 29:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Tom·öa Becketa, biskupa a muËenÌka", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP,
							MODL_SPOL_CAST_MUCENIK);
					break;
				case 31:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						/* nema vespery, lebo uz su prve vespery slavnosti bohorodicky panny marie */
						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, "Sv. Silvestra I., p·peûa", MENO_SVIATKU);
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_PAPEZ);
					break;
			}; break; /* case MES_DEC */
	}/* switch(mesiac - 1) */

	/* 10/03/2000A.D.: dorobena pasaz pre spomienku neposkvrneneho srdca panny marie */
#define _srdca_pm_benediktus {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SRDCA_PM, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _srdca_pm_modlitba {\
	sprintf(_anchor, "%s_%s", ANCHOR_SRDCA_PM, ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2005-08-25: PridanÈ vlastnÈ druhÈ ËÌtanie na posv‰tnÈ ËÌtanie */
#define _srdca_pm_2cit {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SRDCA_PM, pismenko_modlitby(modlitba), ANCHOR_CITANIE2);\
	_set_citanie2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
	if((_global_den.denvr == (_global_r._ZOSLANIE_DUCHA_SV.denvr + 20)) && 
		(_global_svaty1.smer >= 10)){
		/* neposkvrneneho srdca panny marie; 10/03/2000A.D.;
		 * vtedy som aj napisal tuto vysvetlujucu poznamku:
		       "berie sa len v takom pripade, ked to nekoliduje 
		        s inou povinnou spomienkou alebo slavenim,
		        co ma vyssiu prioritu (smer <= 10)"
		 * kedze vsak som si uvedomil, ze bolo treba nastavit smer=10,
		 * tu treba dat opravenu poznamku:
		       "berie sa v takom pripade, ked nie je slavenie s vyssou prioritou,
			    teda smer < 10"
		 * 2003-06-30a.D.
		 */
		Log(" neposkvrneneho srdca panny marie: \n");
		Log(" ...berie sa len v takom pripade, ked to nekoliduje\n");
		Log(" ...so slavenim, co ma vyssiu prioritu (smer < 10)\n");
		/* 04/07/2000A.D.: vypisanie logu, uprava */
		poradie_svaty = 1;
		if(poradie_svaty == 1){
			/* definovanie parametrov pre modlitbu */

			if(query_type != PRM_DETAILY)
			set_spolocna_cast(sc, poradie_svaty);
			/* ZNOVUNASTAVENIE_POPISU_NA_DUMMY, 2003-06-30 */
			Log("vo funkcii sviatky_svatych() spustam set_popis_dummy(); - kvoli spomienke neposkvrneneho srdca panny marie...\n");
			set_popis_dummy();
			Log("set_popis_dummy() skoncila.\n");

			mystrcpy(_file, FILE_SRDCA_PM, MAX_STR_AF_FILE);
			mystrcpy(_anchor, ANCHOR_SRDCA_PM, MAX_STR_AF_ANCHOR);
			Log("  ide o spomienku srdca panny marie...\n");
			modlitba = MODL_RANNE_CHVALY;
			_srdca_pm_benediktus;
			_srdca_pm_modlitba;
			/* 2005-08-25: PridanÈ */
			modlitba = MODL_POSV_CITANIE;
			_srdca_pm_2cit;
			_srdca_pm_modlitba;
		}
		_global_svaty1.typslav = SLAV_SPOMIENKA;
		/* 2003-06-30: kedysi tu bolo 11: "miestne povinne spomienky podla vseobecneho kalendara"
		 * zmenil som to na 10 */
		_global_svaty1.smer = 10; 
		/* vysvetlujuca poznamka z r. 2000: "zrejme pre Slovensko je tato lubovolna 
		 * spomienka povinna; aby sa nebila s inou spomienkou, dal som tam 
		 * smer == 11; 10/03/2000A.D.;" -- zmenene 2003-06-30
		 * porov. pasaz venovanu srdcu pm vo funkcii breviar.cpp::_rozbor_dna()
		 */
		mystrcpy(_global_svaty1.meno, "NepoökvrnenÈho Srdca prebl. Panny M·rie", MENO_SVIATKU);
		_global_svaty1.spolcast =
			_encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
	}/* srdca panny marie */

	if(_global_svaty1.typslav == SLAV_NEURCENE){
		Log("neurcene slavenie, t.j. pocet = 0\n");
		pocet = 0;
	}
	else{
		/* 2006-02-06: obohaten˝ debug v˝pis */
		Log("sl·venie je urËenÈ, poËet == %d\n", pocet);
		Log("\tötrukt˙ra sc == ({%s, %s, %s}) -- begin\n",
			nazov_spolc(sc.a1), nazov_spolc(sc.a2), nazov_spolc(sc.a3));

		_global_svaty1.den = den;
		_global_svaty1.mesiac = mesiac;
		Log("  %d. %d: %s (%d) [%d]\n", _global_svaty1.den,	_global_svaty1.mesiac, _global_svaty1.meno,	_global_svaty1.typslav, _global_svaty1.smer);
#ifdef DETAIL_LOG_SVATY
		Log(_global_svaty1);
#endif
		/* mozno je druha lubovolna spomienka */
		if(pocet > 1){
			_global_svaty2.den = den;
			_global_svaty2.mesiac = mesiac;
			Log("  %d. %d: %s (%d) [%d]\n", _global_svaty2.den,	_global_svaty2.mesiac, _global_svaty2.meno, _global_svaty2.typslav, _global_svaty2.smer);
#ifdef DETAIL_LOG_SVATY
			Log(_global_svaty2);
#endif
			/* este dalsi */
			if(pocet > 2){
				_global_svaty3.den = den;
				_global_svaty3.mesiac = mesiac;
				Log("  %d. %d: %s (%d) [%d]\n", _global_svaty3.den,	_global_svaty3.mesiac, _global_svaty3.meno,	_global_svaty3.typslav, _global_svaty3.smer);
#ifdef DETAIL_LOG_SVATY
				Log(_global_svaty3);
#endif
			}
		}
	}
	Log("-- sviatky_svatych(%d, %d) -- koniec (returning %d)\n",
		den, mesiac, pocet);
	return pocet;
}/* sviatky_svatych(); -- 3 vstupy */

short int sviatky_svatych(short int den, short int mesiac){
	short int ret;
	Log("-- sviatky_svatych(%d, %d) -- spustam bez tretieho parametra\n", den, mesiac);
	Log("   (poradie_svaty == 0)\n");
	ret = sviatky_svatych(den, mesiac, 0);
	Log("-- sviatky_svatych(%d, %d) -- spustene bez tretieho parametra, vysledok (pocet svatych) == %d\n", den, mesiac, ret);
	return ret;
}/* sviatky_svatych(); -- 2 vstupy */

short int sviatky_svatych(short int den, short int mesiac, short int poradie_svaty, short int druhykrat){
	short int ret;
	Log("-- sviatky_svatych(%d, %d, %d) -- spustam druhykrat\n", den, mesiac, poradie_svaty);
	if(druhykrat != 2){
		Log("   zle spustena, nie s 4. parametrom == 2\n");
		Log("-- sviatky_svatych(%d, %d) -- failure. Nespustila sa.\n");
		return 5;
	}

	Log("_global_svaty[1,2,3] som nemenil, lebo poradie_svaty == %d\n", poradie_svaty);
	Log("teraz priradim do _global_den vsetko z _global_svaty%d...\n", poradie_svaty);
	Log("    (tato cast bola povodne v sviatky_svatych s 3 vstupmi, ale teraz je tu)\n");
	switch(poradie_svaty){
		case 1: _global_den = _global_svaty1; break;
		case 2: _global_den = _global_svaty2; break;
		case 3: _global_den = _global_svaty3; break;
		default: /* sem by sa to nemalo dostat */
			Log("--Error: switch(poradie_svaty) nezabralo pre 1, 2, 3...\n"); break;
	}/* switch(); */
	Log("takze _global_den teraz:\n");
	Log(_global_den);
	/*
	LOG_ciara_sv; Log("_global_svaty1: \n"); Log(_global_svaty1);
	LOG_ciara_sv; Log("_global_svaty2: \n"); Log(_global_svaty2);
	LOG_ciara_sv; Log("_global_svaty3: \n"); Log(_global_svaty3);
	*/

	/* az teraz, ked je v _global_den (pri druhom volani fcie)
	 * spravna hodnota z _global_svaty[1,2,3], mozem urobit toto
	 * priradenie do sc
	 */
	_struct_sc sc = _decode_spol_cast(_global_den.spolcast);

	/* 2006-02-06: doplnen˝ debug v˝pis */
	Log("a hned nastavujem _global_opt3 (ak je neurËenÈ: je teraz %d) na sc.a1):\n", _global_opt3);
	/* ak opt3 je MODL_SPOL_CAST_NEURCENA, tak ju urcime podla
	 * 1. spolocnej casti */
	if(_global_opt3 == MODL_SPOL_CAST_NEURCENA){
		_global_opt3 = sc.a1;
		Log("\tsetting _global_opt3 to sc.a1 == %d\n", sc.a1);
	}
	else {
		Log("\tnie je potrebnÈ modifikovaù, lebo uû je nastaven· (hoci sc.a1 == %d)\n", sc.a1);
	}
	ret = sviatky_svatych(den, mesiac, poradie_svaty);
	Log("-- sviatky_svatych(%d, %d) -- spustene druhykrat, vysledok (pocet svatych) == %d\n", den, mesiac, ret);
	return ret;
}/* sviatky_svatych(); -- 4 vstupy; posledny == 2 */

