/***************************************************************/
/*                                                             */
/* breviar.h                                                   */
/* (c)1999-2007 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | obsahuje deklaracie globalnych premennych     */
/*               a funkciu main() z dnes.cpp kde su definovane */
/* document history                                            */
/*   30/03/2000A.D. | premenovane dnes --> breviar             */
/*   06/09/2001A.D. | tento popis                              */
/*   2003-07-01a.D. | void main je zakomentovane ak linux      */
/*   2003-07-14a.D. | zmena void main -> int main (gcc v3.2.2 )*/
/*   2003-08-07a.D. | pridane _global_opt5                     */
/*   2003-08-13a.D. | pridane _type a _global_modl pre posv.cit*/
/*   2006-07-11a.D. | prv� kroky k jazykov�m mut�ci�m          */
/*   2006-08-18a.D. | zmena int na short int (sta�� 32tis.)    */
/*                                                             */
/*                                                             */
/***************************************************************/

#include "vstudio.h"

#ifndef __BREVIAR_H
#define __BREVIAR_H

#include "liturgia.h"
#include "mysystem.h" /* kvuoli OS_linux/OS_Windows_Ruby, zapozn�mkovanie void main, 2003-07-01; upraven� 2007-05-29 */

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

/* globalne premenne, obsahujuce pom_MODL_OPT... */
extern short int _global_opt1/* = NIE */;
extern short int _global_opt2/* = MODL_ZALMY_ZO_DNA; 2006-01-25: upraven�, bolo tu MODL_ZALMY_ZO_SV */;
extern short int _global_opt3;
extern short int _global_opt4;
extern short int _global_opt5; /* pridane 2003-08-07 */

/* globalna premenna, co obsahuje string vypisany na obsazovku */
extern char *_global_string;
extern char *_global_string2; /* obsahuje I, II, III, IV, V alebo pismeno roka */
extern char *_global_string_farba; /* 2006-08-19: doplnen� */

extern char *_global_buf; /* 2006-08-01: t�to premenn� tie� alokujeme */
extern char *_global_buf2; /* 2006-08-01: t�to premenn� tie� alokujeme */
/* ------------------------------------------------------------------- */

/* 2006-07-11: Pridan� kv�li jazykov�m mut�ci�m (breviar.cpp) */
extern short int _global_language;
#ifndef _global_jazyk
#define	_global_jazyk	_global_language
#endif

/* 2006-10-17: Pridan� kv�li komplet�riu: niekedy obsahuje a� dva �almy */
extern short int _global_pocet_zalmov_kompletorium;

#ifndef OS_linux
/* kedysi bolo void main;
 * 2003-07-14, kvoli gcc version 3.2.2 20030222 (Red Hat Linux 3.2.2-5) christ-net.sk 
 */
int main(int argc, char **argv);
#endif /* OS_linux */

#if (_MSC_VER >= 1400)       // VC8+ 2007-02-12 kv�li vc++ 2005 express edition
	#pragma warning(disable : 4996)    // disable all deprecation warnings
	#define putenv _putenv
#endif   // VC8+

#endif /* __BREVIAR_H */

