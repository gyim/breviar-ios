/***************************************************************/
/*                                                             */
/* breviar.h                                                   */
/* (c)1999-2011 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | obsahuje deklaracie globalnych premennych     */
/*               a funkciu main() z dnes.cpp kde su definovane */
/* document history                                            */
/*   30/03/2000A.D. | premenovane dnes --> breviar             */
/*   06/09/2001A.D. | tento popis                              */
/*   2003-07-01a.D. | void main je zakomentovane ak linux      */
/*   2003-07-14a.D. | zmena void main -> int main (gcc v3.2.2 )*/
/*   2003-08-07a.D. | pridane _global_opt[5]                   */
/*   2003-08-13a.D. | pridane _type a _global_modl pre posv.cit*/
/*   2006-07-11a.D. | prvÈ kroky k jazykov˝m mut·ci·m          */
/*   2006-08-18a.D. | zmena int na short int (staËÌ 32tis.)    */
/*   2010-05-14a.D. | presunutÈ niektorÈ definy z breviar.cpp  */
/*   2011-02-02a.D. | zadef. MIESTNE_SLAVENIE_CZOP_SVATY1 aû 3 */
/*   2011-03-07a.D. | zadef. MIESTNE_SLAVENIE_LOKAL_SVATY1..3  */
/*   2011-03-18a.D. | zadef. PODMIENKA_EXPORTOVAT_KALENDAR     */
/*   2011-03-30a.D. | zadef. PRILEP_REQUEST_OPTIONS            */
/*                                                             */
/*                                                             */
/***************************************************************/

#include "vstudio.h"

#ifndef __BREVIAR_H
#define __BREVIAR_H

#include "liturgia.h"
#include "mysystem.h" /* kvuoli OS_linux/OS_Windows_Ruby, zapozn·mkovanie void main, 2003-07-01; upravenÈ 2007-05-29 */

/* ------------------------------------------------------------------- */
/* globalne premenne -- deklarovane v liturgia.h, definovane tu */
/* 18/02/2000A.D. */

extern short int query_type; /* premenna obsahujuca PRM_..., deklarovana v mydefs.h */

/* globalna premenna, do ktorej sa ukladaju info o analyzovanom dni
 * pouziva ju void nove_rozbor_dna() funkcia */

extern _struct_dm *_global_den_ptr;
/*_struct_dm _global_den;*/
#define _global_den (*_global_den_ptr)

/* globalne premenne, do ktorych sa ukladaju info o analyzovanom dni
 * o sviatkoch svatych */

extern _struct_dm *_global_svaty1_ptr;
/*_struct_dm _global_svaty1;*/
#define _global_svaty1 (*_global_svaty1_ptr)

extern _struct_dm *_global_svaty2_ptr;
/*_struct_dm _global_svaty2;*/ /* v pripade, ze je viac lubovolnych spomienok */
#define _global_svaty2 (*_global_svaty2_ptr)

extern _struct_dm *_global_svaty3_ptr;
/*_struct_dm _global_svaty3;*/ /* v pripade, ze je viac lubovolnych spomienok */
#define _global_svaty3 (*_global_svaty3_ptr)

/* globalna premenna, ktora obsahuje data o spomienke panny marie v sobotu */

extern _struct_dm *_global_pm_sobota_ptr;
/*_struct_dm _global_pm_sobota;*/
#define _global_pm_sobota (*_global_pm_sobota_ptr)

/* globalne premenne obsahujuce data modlitbach */

extern _type_1vespery     *_global_modl_prve_vespery_ptr;
/*_type_1vespery      _global_modl_prve_vespery;*/
#define _global_modl_prve_vespery (*_global_modl_prve_vespery_ptr)

extern _type_1kompletorium *_global_modl_1kompletorium_ptr;
/*_type_1kompletorium _global_modl_prve_kompletorium;*/
#define _global_modl_prve_kompletorium (*_global_modl_1kompletorium_ptr)

extern _type_invitatorium *_global_modl_invitatorium_ptr;
/*_type_invitatorium  _global_modl_invitatorium;*/
#define _global_modl_invitatorium (*_global_modl_invitatorium_ptr)

/* 2003-08-13 pridane posvatne citanie */
extern _type_posv_citanie *_global_modl_posv_citanie_ptr;
#define _global_modl_posv_citanie (*_global_modl_posv_citanie_ptr)

extern _type_ranne_chvaly *_global_modl_ranne_chvaly_ptr;
/*_type_ranne_chvaly  _global_modl_ranne_chvaly;*/
#define _global_modl_ranne_chvaly (*_global_modl_ranne_chvaly_ptr)

extern _type_cez_den_9     *_global_modl_cez_den_9_ptr;
/*_type_cez_den_9     _global_modl_cez_den_9;*/
#define _global_modl_cez_den_9 (*_global_modl_cez_den_9_ptr)
extern _type_cez_den_12     *_global_modl_cez_den_12_ptr;
/*_type_cez_den_12     _global_modl_cez_den_12;*/
#define _global_modl_cez_den_12 (*_global_modl_cez_den_12_ptr)
extern _type_cez_den_3     *_global_modl_cez_den_3_ptr;
/*_type_cez_den_3     _global_modl_cez_den_3;*/
#define _global_modl_cez_den_3 (*_global_modl_cez_den_3_ptr)

extern _type_vespery      *_global_modl_vespery_ptr;
/*_type_vespery       _global_modl_vespery;*/
#define _global_modl_vespery (*_global_modl_vespery_ptr)

extern _type_kompletorium *_global_modl_kompletorium_ptr;
/*_type_kompletorium _global_modl_kompletorium;*/
#define _global_modl_kompletorium (*_global_modl_kompletorium_ptr)

/* globalna premenna, ktora obsahuje MODL_... */
extern short int _global_modlitba;

/* globalna premenna, do ktorej ukladaju funkcie vytvor_query_string_...
 * linku tvaru PATH_CGI(SCRIPT_NAME) ++ "?param1=val&param2=val&..." */
extern char *_global_link_ptr;
/*char _global_link[MAX_STR];*/
#define _global_link _global_link_ptr

extern char *_global_pom_str; /* pomocny string pre velke pismena */
/*char _global_pom_str[MAX_STR];*/

/* globalna premenna, do ktorej sa ukladaju info o jednotlivych
 * vyznacnych liturgickych dni, pouzivaju void _dm_...() funkcie
 * a void analyzuj_rok() funkcia */
extern _struct_dm *_global_result_ptr;
/*_struct_dm _global_result;*/
#define _global_result (*_global_result_ptr)

/* globalna premenna, do ktorej sa uklada info o liturgickom roku
 * pouziva void analyzuj_rok() funkcia */
extern _struct_lrok *_global_r_ptr;
/*_struct_lrok _global_r;*/
#define _global_r (*_global_r_ptr)

/* globalna premenna, do ktorej sviatky_svatych() uklada
 * pocet sviatkov (de facto lubovolnych spomienok), ktore
 * pripadaju na dany den
 * -- v podstate neuklada do nej, ale v _rozbor_dna() sa do nej priradi
 * vysledok (navratova hodnota) z sviatky_svatych()
 */
extern short int _global_pocet_svatych;

/* glob·lna premenn· -- pole -- obsahuj˙ca options; pÙvodne to boli glob·lne premennÈ _global_opt[1].._global_opt[9] atÔ., obsahuj˙ pom_MODL_OPT... */
extern short int _global_opt[POCET_GLOBAL_OPT];

/* globalna premenna, co obsahuje string vypisany na obsazovku */
extern char *_global_string;
extern char *_global_string2; /* obsahuje I, II, III, IV, V alebo pismeno roka */
extern char *_global_string_farba; /* 2006-08-19: doplnenÈ */

extern char *_global_buf; /* 2006-08-01: t˙to premenn˙ tieû alokujeme */
extern char *_global_buf2; /* 2006-08-01: t˙to premenn˙ tieû alokujeme */
/* ------------------------------------------------------------------- */

/* 2006-07-11: PridanÈ kvÙli jazykov˝m mut·ci·m (breviar.cpp)
 * 2010-08-04: zmenenÈ _global_language na _global_jazyk (doteraz bolo len pomocou #define)
 */
extern short int _global_jazyk;
/* 2010-08-04: pridanÈ kvÙli kalend·rom (napr. rehoæn˝), s˙visÌ s jazykov˝mi mut·ciami */
extern short int _global_kalendar;

extern short int _global_css; /* 2008-08-08: PridanÈ kvÙli rÙznym css */

/* 2006-10-17: PridanÈ kvÙli kompletÛriu: niekedy obsahuje aû dva ûalmy */
extern short int _global_pocet_zalmov_kompletorium;

/* 2009-08-03, pridanÈ */
extern short int _global_opt_batch_monthly;

/* 2009-08-05, pridanÈ */
extern short int _global_hlavicka_Export;
// extern char name_batch_html_file[MAX_STR];

/* 2009-08-12, pridanÈ */
extern char _global_export_navig_hore[SMALL];
extern short int _global_opt_export_date_format;

/*
 * 2009-01-28: jednotlivÈ define t˝kaj˙ce sa riadenia modlitby presunutÈ sem na zaËiatok s˙boru, 
 *             nakoæko ich pouûÌva nielen interpretParameter() alebo showPrayer(), ale aj includeFile()
 * 2009-08-11: opraven· podmienka pre je_tedeum (odstr·nenÈ nepotrebnÈ 9.11.)
 * 2010-05-14: definy presunutÈ z breviar.cpp
 */
#define je_post ((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN) || ((_global_den.litobd == OBD_VELKONOCNE_TROJDNIE) && ((_global_den.denvt == DEN_PIATOK) || (_global_den.denvt == DEN_SOBOTA))))
#define je_velka_noc ((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II) || ((_global_den.litobd == OBD_VELKONOCNE_TROJDNIE) && (_global_den.denvt == DEN_NEDELA)) || (_global_den.litobd == OBD_VELKONOCNA_OKTAVA))
#define je_aleluja_aleluja ((_global_den.litobd == OBD_VELKONOCNA_OKTAVA) || ((_global_den.litobd == OBD_VELKONOCNE_TROJDNIE) && (_global_den.denvt == DEN_NEDELA)) || (equals(_global_den.meno, _global_r._ZOSLANIE_DUCHA_SV.meno) && (_global_modlitba == MODL_VESPERY)))
#define je_34_ocr ((_global_den.litobd == OBD_CEZ_ROK) && (_global_den.tyzden == 34) && (_global_den.denvt != DEN_NEDELA))
#define je_tedeum (type == MODL_POSV_CITANIE) && (((_global_den.denvt == DEN_NEDELA) && (_global_den.litobd != OBD_POSTNE_I) && (_global_den.litobd != OBD_POSTNE_II_VELKY_TYZDEN)) || (_global_den.typslav == SLAV_SLAVNOST) || (_global_den.typslav == SLAV_SVIATOK) || (_global_den.litobd == OBD_VELKONOCNA_OKTAVA) || (_global_den.litobd == OBD_OKTAVA_NARODENIA))
/* 2010-05-24: doplnenÈ; 2011-03-16: rozöÌrenÈ o posv‰tnÈ ËÌtanie */
#define je_ant_modl_spom_post (( \
(_global_modlitba == MODL_RANNE_CHVALY &&  \
	(_global_modl_ranne_chvaly.ant_spompost.anchor != NULL) && (_global_modl_ranne_chvaly.ant_spompost.file != NULL) && \
	(_global_modl_ranne_chvaly.modlitba_spompost.anchor != NULL) && (_global_modl_ranne_chvaly.modlitba_spompost.file != NULL) && \
	(!equals(_global_modl_ranne_chvaly.ant_spompost.anchor, EMPTY_STR)) && (!equals(_global_modl_ranne_chvaly.ant_spompost.anchor, STR_UNDEF)) &&  \
	(!equals(_global_modl_ranne_chvaly.modlitba_spompost.anchor, EMPTY_STR)) && (!equals(_global_modl_ranne_chvaly.modlitba_spompost.anchor, STR_UNDEF)) && \
	(!equals(_global_modl_ranne_chvaly.ant_spompost.file, EMPTY_STR)) && (!equals(_global_modl_ranne_chvaly.ant_spompost.file, STR_UNDEF)) &&  \
	(!equals(_global_modl_ranne_chvaly.modlitba_spompost.file, EMPTY_STR)) && (!equals(_global_modl_ranne_chvaly.modlitba_spompost.file, STR_UNDEF)) \
) \
||  \
(_global_modlitba == MODL_VESPERY &&  \
	(_global_modl_vespery.ant_spompost.anchor != NULL) && (_global_modl_vespery.ant_spompost.file != NULL) && \
	(_global_modl_vespery.modlitba_spompost.anchor != NULL) && (_global_modl_vespery.modlitba_spompost.file != NULL) && \
	(strcmp(_global_modl_vespery.ant_spompost.anchor, EMPTY_STR) != 0) && (strcmp(_global_modl_vespery.ant_spompost.anchor, STR_UNDEF) != 0) &&  \
	(strcmp(_global_modl_vespery.modlitba_spompost.anchor, EMPTY_STR) != 0) && (strcmp(_global_modl_vespery.modlitba_spompost.anchor, STR_UNDEF) != 0) && \
	(strcmp(_global_modl_vespery.ant_spompost.file, EMPTY_STR) != 0) && (strcmp(_global_modl_vespery.ant_spompost.file, STR_UNDEF) != 0) &&  \
	(strcmp(_global_modl_vespery.modlitba_spompost.file, EMPTY_STR) != 0) && (strcmp(_global_modl_vespery.modlitba_spompost.file, STR_UNDEF) != 0) \
) \
||  \
(_global_modlitba == MODL_POSV_CITANIE &&  \
	(_global_modl_posv_citanie.citanie_spompost.anchor != NULL) && (_global_modl_posv_citanie.citanie_spompost.file != NULL) && \
	(strcmp(_global_modl_posv_citanie.citanie_spompost.anchor, EMPTY_STR) != 0) && (strcmp(_global_modl_posv_citanie.citanie_spompost.anchor, STR_UNDEF) != 0) &&  \
	(strcmp(_global_modl_posv_citanie.citanie_spompost.file, EMPTY_STR) != 0) && (strcmp(_global_modl_posv_citanie.citanie_spompost.file, STR_UNDEF) != 0) \
) \
))

/* 2011-02-02: presunutÈ do #define -- kontrola, ktor· zabezpeËuje, ûe norm·lne spr·vanie sa sl·venÌ nie je prebitÈ pre "CZOP miestne sl·venia" */
#define MIESTNE_SLAVENIE_CZOP_SVATY1 ((_global_svaty1.kalendar == KALENDAR_CZ_OP) && ((_global_svaty1.smer == 4) || (_global_svaty1.smer == 8) || (_global_svaty1.smer == 11)))
#define MIESTNE_SLAVENIE_CZOP_SVATY2 ((_global_svaty2.kalendar == KALENDAR_CZ_OP) && ((_global_svaty2.smer == 4) || (_global_svaty2.smer == 8) || (_global_svaty2.smer == 11)))
#define MIESTNE_SLAVENIE_CZOP_SVATY3 ((_global_svaty3.kalendar == KALENDAR_CZ_OP) && ((_global_svaty3.smer == 4) || (_global_svaty3.smer == 8) || (_global_svaty3.smer == 11)))

/* 2011-03-07: MIESTNE_SLAVENIE_CZOP_SVATY1 aû 3 aj pre slovenskÈ, ktorÈ maj˙ nastavenÈ "lok·lne" verzie */
#define MIESTNE_SLAVENIE_LOKAL_SVATY1 (((_global_svaty1.kalendar == KALENDAR_CZ_OP) || (_global_svaty1.typslav_lokal != LOKAL_SLAV_NEURCENE)) && ((_global_svaty1.smer == 4) || (_global_svaty1.smer == 8) || (_global_svaty1.smer == 11)))
#define MIESTNE_SLAVENIE_LOKAL_SVATY2 (((_global_svaty2.kalendar == KALENDAR_CZ_OP) || (_global_svaty2.typslav_lokal != LOKAL_SLAV_NEURCENE)) && ((_global_svaty2.smer == 4) || (_global_svaty2.smer == 8) || (_global_svaty2.smer == 11)))
#define MIESTNE_SLAVENIE_LOKAL_SVATY3 (((_global_svaty3.kalendar == KALENDAR_CZ_OP) || (_global_svaty3.typslav_lokal != LOKAL_SLAV_NEURCENE)) && ((_global_svaty3.smer == 4) || (_global_svaty3.smer == 8) || (_global_svaty3.smer == 11)))

/* 2011-03-18: presunutÈ samostatne na jedno jedinÈ miesto */
#define PODMIENKA_EXPORTOVAT_KALENDAR ( \
((_global_jazyk == JAZYK_SK) && !((_global_kalendar == KALENDAR_NEURCENY) || (_global_kalendar == KALENDAR_VSEOBECNY) || (_global_kalendar == KALENDAR_VSEOBECNY_SK) )) \
|| ((_global_jazyk == JAZYK_CZ) && !((_global_kalendar == KALENDAR_NEURCENY) || (_global_kalendar == KALENDAR_VSEOBECNY) || (_global_kalendar == KALENDAR_VSEOBECNY_CZ) )) \
|| ((_global_jazyk == JAZYK_CZ_OP) && !((_global_kalendar == KALENDAR_NEURCENY) || (_global_kalendar == KALENDAR_VSEOBECNY) || (_global_kalendar == KALENDAR_VSEOBECNY_CZ) || (_global_kalendar == KALENDAR_CZ_OP) )) \
)

#define PRILEP_REQUEST_OPTIONS(pom2, pom3, prvy_ampersand) {\
	/* 2006-07-31: pridanÈ odovzdanie parametra pre jazyk */\
	if(_global_jazyk != JAZYK_SK){\
		if(prvy_ampersand == ANO){\
			sprintf(pom3, HTML_AMPERSAND"%s=%s", STR_JAZYK, skratka_jazyka[_global_jazyk]);\
		} \
		else{ \
			sprintf(pom3, "%s=%s", STR_JAZYK, skratka_jazyka[_global_jazyk]);\
		} \
		strcat(pom2, pom3);\
		Log("\tPrilepil som aj jazyk: `%s' (2006-07-31)\n", pom3);\
	}\
\
	/* 2010-08-04: pridanÈ odovzdanie parametra pre kalend·r \
	 * 2010-09-14: podmienka opraven·; ak nie je kalend·r urËen˝ resp. je vöeobecn˝ pre dan˝ jazyk, nie je potrebnÈ ho exportovaù\
	 */\
	if(PODMIENKA_EXPORTOVAT_KALENDAR){\
		sprintf(pom3, HTML_AMPERSAND"%s=%s", STR_KALENDAR, skratka_kalendara[_global_kalendar]);\
		strcat(pom2, pom3);\
		Log("\tPrilepil som aj kalend·r: `%s' (2010-08-04)\n", pom3);\
	}\
	else{\
		Log("\tNetreba prilepiù kalend·r (jazyk == %s, kalend·r == %s)\n", skratka_jazyka[_global_jazyk], skratka_kalendara[_global_kalendar]);\
	}\
\
	/* 2008-08-08: pridanÈ odovzdanie parametra pre css */\
	if(_global_css != CSS_breviar_sk){\
		sprintf(pom3, HTML_AMPERSAND"%s=%s", STR_CSS, skratka_css[_global_css]);\
		strcat(pom2, pom3);\
		Log("\tPrilepil som aj css: `%s' (2008-08-08)\n", pom3);\
	}\
\
	/* 2011-01-26: pridanÈ odovzdanie parametrov pre options1 atÔ. */\
    /* 2011-04-07: upravenÈ -- pouûitie polÌ */\
	char local_str[SMALL];\
	short int local_opt_default;\
	for(i = 0; i < POCET_GLOBAL_OPT; i++){\
		Log("i == %d...\n", i);\
		if(i == 3)\
			continue;\
		if((i == 6) || (i == 7))\
			continue;\
		switch(i){\
			case 0: local_opt_default = CFG_OPTION0_DEFAULT; break;\
			case 1: local_opt_default = CFG_OPTION1_DEFAULT; break;\
			case 2: local_opt_default = CFG_OPTION2_DEFAULT; break;\
			/* case 3: vynechan˝; nem· default */ \
			case 4: local_opt_default = CFG_OPTION4_DEFAULT; break;\
			case 5: local_opt_default = CFG_OPTION5_DEFAULT; break;\
			case 6: local_opt_default = CFG_OPTION6_DEFAULT; break;\
			case 7: local_opt_default = CFG_OPTION7_DEFAULT; break;\
			case 8: local_opt_default = CFG_OPTION8_DEFAULT; break;\
			case 9: local_opt_default = CFG_OPTION9_DEFAULT; break;\
		}/* switch(i) */\
		if(_global_opt[i] != local_opt_default){\
			strcpy(local_str, STR_EMPTY);\
			switch(i){\
				case 0: strcat(local_str, STR_MODL_OPT0); break;\
				case 1: strcat(local_str, STR_MODL_OPT1); break;\
				case 2: strcat(local_str, STR_MODL_OPT2); break;\
				case 3: strcat(local_str, STR_MODL_OPT3); break;\
				case 4: strcat(local_str, STR_MODL_OPT4); break;\
				case 5: strcat(local_str, STR_MODL_OPT5); break;\
				case 6: strcat(local_str, STR_MODL_OPT6); break;\
				case 7: strcat(local_str, STR_MODL_OPT7); break;\
				case 8: strcat(local_str, STR_MODL_OPT8); break;\
				case 9: strcat(local_str, STR_MODL_OPT9); break;\
			}/* switch(i) */\
			sprintf(pom3, HTML_AMPERSAND"%s=%d", local_str, _global_opt[i]);\
			strcat(pom2, pom3);\
			Log("\tPrilepil som aj opt%d: `%s'\n", i, pom3);\
		}\
	}\
}

#ifndef OS_linux
/* kedysi bolo void main;
 * 2003-07-14, kvoli gcc version 3.2.2 20030222 (Red Hat Linux 3.2.2-5) christ-net.sk 
 */
int main(int argc, char **argv);
#endif /* OS_linux */

#if (_MSC_VER >= 1400)       // VC8+ 2007-02-12 kvÙli vc++ 2005 express edition
	#pragma warning(disable : 4996)    // disable all deprecation warnings
	#define putenv _putenv
#endif   // VC8+

#endif /* __BREVIAR_H */

