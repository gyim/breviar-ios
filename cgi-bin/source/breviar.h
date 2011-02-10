/* subor obsahujuci deklaracie globalnych premennych a funkciu main()
 * z dnes.cpp -- tam su definovane
 *
 * 30/03/2000A.D. -- premenovane dnes --> breviar
 */
#ifndef __BREVIAR_H
#define __BREVIAR_H
#include "liturgia.h"

/* ------------------------------------------------------------------- */
/* globalne premenne -- deklarovane v liturgia.h, definovane tu */
/* 18/02/2000A.D. */

extern int query_type; /* premenna obsahujuca PRM_..., deklarovana v mydefs.h */

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

/* extern _type_posv_citanie  _global_modl_posv_citanie; */

extern _type_ranne_chvaly *_global_modl_ranne_chvaly_ptr;
/*_type_ranne_chvaly  _global_modl_ranne_chvaly;*/
#define _global_modl_ranne_chvaly (*_global_modl_ranne_chvaly_ptr)

#ifdef RUN_MODLITBA_CEZ_DEN
extern _type_cez_den_9     *_global_modl_cez_den_9_ptr;
/*_type_cez_den_9     _global_modl_cez_den_9;*/
#define _global_modl_cez_den_9 (*_global_modl_cez_den_9_ptr)
extern _type_cez_den_12     *_global_modl_cez_den_12_ptr;
/*_type_cez_den_12     _global_modl_cez_den_12;*/
#define _global_modl_cez_den_12 (*_global_modl_cez_den_12_ptr)
extern _type_cez_den_3     *_global_modl_cez_den_3_ptr;
/*_type_cez_den_3     _global_modl_cez_den_3;*/
#define _global_modl_cez_den_3 (*_global_modl_cez_den_3_ptr)
#endif

extern _type_vespery      *_global_modl_vespery_ptr;
/*_type_vespery       _global_modl_vespery;*/
#define _global_modl_vespery (*_global_modl_vespery_ptr)

extern _type_kompletorium *_global_modl_kompletorium_ptr;
/*_type_kompletorium _global_modl_kompletorium;*/
#define _global_modl_kompletorium (*_global_modl_kompletorium_ptr)

/* globalna premenna, ktora obsahuje MODL_... */
extern int _global_modlitba;

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
extern int _global_pocet_svatych;

/* globalne premenne, obsahujuce pom_MODL_OPT... */
extern int _global_opt1/* = NIE */;
extern int _global_opt2/* = MODL_ZALMY_ZO_SV */;
extern int _global_opt3;
extern int _global_opt4;

/* globalna premenna, co obsahuje string vypisany na obsazovku */
extern char *_global_string;
/*char _global_string[MAX_STR];*/
extern char *_global_string2;
/*char _global_string2[MAX_STR];*/ /* obsahuje I, II, III, IV, V alebo pismeno roka */
/* ------------------------------------------------------------------- */

void main(int argc, char **argv);

#endif /* __BREVIAR_H */
