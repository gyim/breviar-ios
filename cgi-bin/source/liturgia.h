/***************************************************************/
/*                                                             */
/* liturgia.h                                                  */
/* (c)1999-2010 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | obsahuje zakladne vecicky pre liturgiu hodin  */
/* document history                                            */
/*   01/11/1999A.D. | created                                  */
/*   01/02/2000A.D. | modified                                 */
/*   18/02/2000A.D. | trosku prekopane | stringove kontanty su */
/*                    tu iba deklarovane; definovane v hodin.h */
/*   06/09/2001A.D. | tento popis                              */
/*   2003-07-02a.D. | pridana LINK_DEN_MESIAC_ROK_PRESTUP      */
/*                    kvoli prestupnym rokom (iny _global_link)*/
/*   2003-07-15a.D. | rozne definicie pre modlitbu cez den     */
/*   2003-07-15a.D. | odstraneny #include "mybase.h"           */
/*   2003-08-06a.D. | rozne definicie pre posvatne citanie     */
/*   2003-08-07a.D. | pridana void _init_dm co nastavi dummy   */
/*   2003-08-11a.D. | -Wall upozornila na / * within comments  */
/*   2003-08-11a.D. | void _init_dm zapoznamkovana             */
/*   2003-08-13a.D. | pridane logy pre modlitbu cez den        */
/*                  - pridane MODL_CEZ_DEN_VSETKY              */
/*   2003-08-21a.D. | definicie pre posvatne citania           */
/*   2003-11-20a.D. | definicie pre posvatne citania zmenene   */
/*   2004-04-28a.D. | MAX_STR_AF_FILE zmenene na 16            */
/*   2004-08-14a.D. | char zmeneny na unsigned (_nedelne_p...) */
/*   2005-03-27a.D. | CHAR_MODL_* z funkcie pismenko_modlitby  */
/*   2005-07-27a.D. | pridan� nazov_slavenia_lokal[]           */
/*   2005-08-05a.D. | pridan� zvazok_OBD[]                     */
/*   2005-11-11a.D. | Doplnen� parametre pre Te Deum           */
/*   2006-02-07a.D. | ZALTAR_... pre funkciu zaltar_zvazok();  */
/*   2006-07-11a.D. | prv� kroky k jazykov�m mut�ci�m          */
/*   2006-08-01a.D. | zmenen� defin�cie kon�t�nt (jaz.mut�cie) */
/*   2006-08-07a.D. | pridan� sv. mu�ov/�ien, �o �ili v man�.  */
/*   2006-08-18a.D. | zmena int na short int (sta�� 32tis.)    */
/*   2006-08-19a.D. | pridanie liturgickej farby               */
/*   2006-10-11a.D. | pre invitat�rium a komplet�rium          */
/*   2006-10-13a.D. | jazykovo z�visl� je aj nazov_Modlitby    */
/*   2006-12-12a.D. | doplnenie latin�iny (la)                 */
/*   2007-06-01a.D. | niektor� definy presunut� do mydefs.h    */
/*   2007-06-28a.D. | doplnen�: PARAM_TEDEUM_BEGIN aj _END     */
/*   2007-10-02a.D. | doplnen�: PARAM_SKRY_ANTIFONU_BEGIN/END  */
/*                  - tie� PARAM_ANTIFONA1x a PARAM_ANTIFONA3x */
/*   2008-01-03a.D. | doplnen� text_DRUHA_NEDELA_PO_NAR_PANA[] */
/*   2008-01-05a.D. | doplnen� text_PO_POPOLCOVEJ_STREDE[]     */
/*                  - a tie� text_V_OKTAVE_NARODENIA[]         */
/*   2008-01-23a.D. | opraven� pole kon�t�nt zvazok_breviara[] */
/*   2008-06-24a.D. | doplnen� LOKAL_SLAV_SPIS_BA_PATRON       */
/*   2008-08-15a.D. | pridan� �al�� "jazyk" (cz-op)            */
/*   2009-01-29a.D. | pridan� �al�� jazyk - ma�ar�ina (hu)     */
/*   2009-04-08a.D. | zakon�enie modlitby trojak� (kr�tke/dlh�)*/
/*   2009-05-15a.D. | pridan� text_PRO_OP[]                    */
/*   2009-12-14a.D. | zakon�enie modlitby s mal�m p�smenkom na za�iatku */
/*   2010-03-16a.D. | doplnen� LOKAL_SLAV_BRATISLAVA           */
/*   2010-05-17a.D. | pridan� niektor� ma�arsk� sl�venia       */
/*                                                             */
/*                                                             */
/***************************************************************/

#include "vstudio.h"
#ifndef __LITURGIA_H_
#define __LITURGIA_H_

#include "mysystem.h"
#include "mydefs.h"
#include "mylog.h"
#include <time.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#define MENO_SVIATKU 156 /* 2009-03-24: roz��ren� kv�li text_SEP_26_2[]; 2009-03-24: roz��ren� kv�li text_PRO_OP[] */

/* 2006-07-31: kv�li jazykov�m mut�ci�m; zmenen� 2008-08-15 na 5 
 * 2009-01-29: zmenen� na 6 (ma�ar�ina)
 */
#define	POCET_JAZYKOV	6

/* 2006-07-11: Pridan� kv�li jazykov�m mut�ci�m 
 * 2006-12-12: Pridan� latin�ina, k�dy s� pod�a ISO 639-1 (a� na �e�tinu)
 * 2008-08-15: Pridan� "dominik�nska �e�tina"; presunut� sem bezprostredne za defin�ciu POCET_JAZYKOV
 * 2009-01-29: pridan� ma�ar�ina
 */
#define JAZYK_SK	0
#define JAZYK_CZ	1
#define JAZYK_EN	2
#define JAZYK_LA    3
#define JAZYK_UNDEF 4
#define JAZYK_CZ_OP 5
#define JAZYK_HU    6

/* 2008-08-15: Pridan� POCET_CSS, aby mohol by� "doln�k" (CSS_UNDEF) hodnota 0 */
#define POCET_CSS	9
/* 2006-08-08: Pridan� kv�li r�znym css-k�m 
 * 2009-04-02: pridan� historick� css-k�
 * 2010-02-25: pridan� css pre webstr�nky http://www.jm-krize.cz/
 */
#define CSS_UNDEF				0
#define CSS_breviar_sk			1
#define CSS_kbd_sk				2
#define CSS_ebreviar_cz			3
#define CSS_breviar_cz_op		4
#define CSS_breviar_hist_2003	5
#define CSS_breviar_hist_2005	6
#define CSS_breviar_hist_2007	7
#define CSS_breviar_hist_2008	8
#define CSS_jm_krize_cz			9

/* nasledovne 2 definovane 2003-08-13; zmenene 2004-04-28 (12->16) */
#define MAX_STR_AF_FILE   16
#define MAX_STR_AF_ANCHOR 23
struct _anchor_and_file{
	char file[MAX_STR_AF_FILE];
	char anchor[MAX_STR_AF_ANCHOR];
};
typedef struct _anchor_and_file _struct_anchor_and_file;

/* definicie pre ranne chvaly a vespery */
#define rchvalospev  zalm2
#define vchvalospev  zalm3
#define magnifikat   benediktus

/* definicie pre posvatne citania upravene 2003-08-21 a opatovne 2003-11-20 */

/* vers po psalmodii pred citaniami - je kresponz */

/* prve  citanie aj s responzoriom za nim */
#define	citanie1	kcitanie

/* druhe citanie aj s responzoriom za nim */
#define	citanie2	benediktus

/* prosby ostavaju pre posvatne citania nedefinovane */

struct tmodlitba1{
	_struct_anchor_and_file popis     ; /* pridane 05/04/2000A.D. */
	_struct_anchor_and_file hymnus    ;
	_struct_anchor_and_file antifona1 ;
	_struct_anchor_and_file zalm1     ;
	_struct_anchor_and_file antifona2 ;
	_struct_anchor_and_file zalm2     ;
	_struct_anchor_and_file antifona3 ;
	_struct_anchor_and_file zalm3     ;
	_struct_anchor_and_file kcitanie  ; /* 1. citanie pre posvatne citanie */
	_struct_anchor_and_file kresponz  ; 
	_struct_anchor_and_file benediktus; /* antifona na benediktus/magnifikat/nunc dimittis; 2. citanie pre posvatne citanie */
	_struct_anchor_and_file prosby    ; /* pre posvatne citanie nedefinovane */
	_struct_anchor_and_file modlitba  ;
};
typedef struct tmodlitba1 _type_ranne_chvaly;
typedef struct tmodlitba1 _type_vespery;
typedef struct tmodlitba1 _type_1vespery;
typedef struct tmodlitba1 _type_posv_citanie;

struct tmodlitba2{
	/* 2003-07-15, pridane _struct_anchor_and_file popis */
	_struct_anchor_and_file popis     ; /* pridane 05/04/2000A.D. */
	_struct_anchor_and_file hymnus    ;
	_struct_anchor_and_file antifona1 ;
	_struct_anchor_and_file zalm1     ;
	_struct_anchor_and_file antifona2 ;
	_struct_anchor_and_file zalm2     ;
	_struct_anchor_and_file antifona3 ;
	_struct_anchor_and_file zalm3     ;
	_struct_anchor_and_file kcitanie  ;
	_struct_anchor_and_file kresponz  ;
	_struct_anchor_and_file modlitba  ;
};
typedef struct tmodlitba2 _type_cez_den_9;
typedef struct tmodlitba2 _type_cez_den_12;
typedef struct tmodlitba2 _type_cez_den_3;
/* pre jednoduchsiu orientaciu pridane 2003-07-15 */
typedef struct tmodlitba2 _type_cez_den_pred;
typedef struct tmodlitba2 _type_cez_den_na;
typedef struct tmodlitba2 _type_cez_den_po;

struct tmodlitba3{
	short int pocet_zalmov            ; /* pridan� 2006-10-18; niekedy s� a� 2 �almy */
	_struct_anchor_and_file popis     ; /* pridan� 2006-10-11; zru�en� antifona2, zalm2 a modlitba */
	_struct_anchor_and_file hymnus    ;
	_struct_anchor_and_file antifona1 ;
	_struct_anchor_and_file zalm1     ;
	_struct_anchor_and_file antifona2 ; /* pridan� 2006-10-17; niekedy s� a� 2 �almy */
	_struct_anchor_and_file zalm2     ;
	_struct_anchor_and_file kcitanie  ;
	_struct_anchor_and_file kresponz  ;
	_struct_anchor_and_file modlitba  ; /* pridan� 2006-10-24 */
};
typedef struct tmodlitba3 _type_kompletorium;
typedef struct tmodlitba3 _type_1kompletorium;

struct tmodlitba4{
	_struct_anchor_and_file popis     ; /* pridan� 2006-10-11 */
	_struct_anchor_and_file antifona1;
	_struct_anchor_and_file zalm1    ;
};
typedef struct tmodlitba4 _type_invitatorium;


struct den_mesiac{ /* takto povodne vyzerala struct dm */
	short int den;        /* cislo dna mesiaca (1--31) */
	short int mesiac;     /* cislo mesiaca (1--12) - in�� ako je potrebn� pre v��inu pol�, kde je mesiac 0--11 */
};
typedef struct den_mesiac _struct_den_mesiac;

#define POCET_MODLITIEB         13 /* 2006-08-02: nepou��valo sa; upraven� na 13 (z p�vodn�ch 8) */
/* modlitby */
#define MODL_INVITATORIUM       0
#define MODL_RANNE_CHVALY       1
#define MODL_POSV_CITANIE       2
#define MODL_CEZ_DEN_9          3
#define MODL_CEZ_DEN_12         4
#define MODL_CEZ_DEN_3          5
#define MODL_VESPERY            6
#define MODL_KOMPLETORIUM       7
#define MODL_NEURCENA           8
/* dalsie, iba docasne modlitby */
#define MODL_PRVE_VESPERY       9
#define MODL_PRVE_KOMPLETORIUM  10
#define MODL_DRUHE_VESPERY      11
#define MODL_DRUHE_KOMPLETORIUM 12
/* formular s detailami ohladom generovania modlitby */
#define MODL_DETAILY            13
/* pre jednoduchsiu orientaciu pridane 2003-07-15 */
#define MODL_PREDPOLUDNIM       3
#define MODL_NAPOLUDNIE         4
#define MODL_POPOLUDNI          5
/* pre modlitbu cez den kvoli zaltaru (psalmodii) rovnake, pridane 2003-08-13 */
#define MODL_CEZ_DEN_VSETKY     20

/* 2007-12-05: doplnen� kv�li modlitbe komplet�ria, funkcia _set_kompletorium_nedela() */
#define MODL_KOMPLETORIUM_NEDELNA	0
#define MODL_KOMPLETORIUM_SLAVNOSTI	1
#define MODL_KOMPLETORIUM_TROJDNIE	2

/* ... a stringy pre ne */
/* pre modlitbu cez den pridane 2003-07-15 */
/* pre posvatne citanie pridane 2003-08-06 */
/* pre invitat�rium a komplet�rium pridan� 2006-10-11 */
#ifdef LONG_PARAM_NAMES
	#define		STR_MODL_INVITATORIUM	"MODL_INVITATORIUM"
	#define		STR_MODL_RANNE_CHVALY	"MODL_RANNE_CHVALY"
	#define		STR_MODL_POSV_CITANIE	"MODL_POSV_CITANIE"
	#define		STR_MODL_VESPERY		"MODL_VESPERY"
	#define		STR_MODL_PREDPOLUDNIM	"MODL_PREDPOLUDNIM"
	#define		STR_MODL_NAPOLUDNIE		"MODL_NAPOLUDNIE"
	#define		STR_MODL_POPOLUDNI		"MODL_POPOLUDNI"
	#define		STR_MODL_DETAILY		"MODL_DETAILY"
	#define		STR_MODL_KOMPLETORIUM	"MODL_KOMPLETORIUM"
#else
	#define		STR_MODL_INVITATORIUM	"mi"
	#define		STR_MODL_RANNE_CHVALY	"mrch"
	#define		STR_MODL_POSV_CITANIE	"mpc"
	#define		STR_MODL_VESPERY		"mv"
	#define		STR_MODL_PREDPOLUDNIM	"mpred"
	#define		STR_MODL_NAPOLUDNIE		"mna"
	#define		STR_MODL_POPOLUDNI		"mpo"
	#define		STR_MODL_DETAILY		"*"
	#define		STR_MODL_KOMPLETORIUM	"mk"
#endif

/* 2005-03-27: Vlozene do definicnej casti z funkcie dbzaltar.cpp::pismenko_modlitby() */
#define CHAR_MODL_INVITATORIUM       'i'
#define CHAR_MODL_RANNE_CHVALY       'r'
#define CHAR_MODL_POSV_CITANIE       'c'
#define CHAR_MODL_CEZ_DEN_9          '9'
#define CHAR_MODL_CEZ_DEN_12         '2'
#define CHAR_MODL_CEZ_DEN_3          '3'
#define CHAR_MODL_VESPERY            'v'
#define CHAR_MODL_KOMPLETORIUM       'k'
#define CHAR_MODL_NEURCENA           '_' /* toto by sa nemalo */
#define CHAR_MODL_PRVE_VESPERY       '1'
#define CHAR_MODL_PRVE_KOMPLETORIUM  'p'
#define CHAR_MODL_DRUHE_VESPERY      'w' /* toto by sa nemalo */
#define CHAR_MODL_DRUHE_KOMPLETORIUM 'm' /* toto by sa nemalo */
// #define CHAR_MODL_CEZ_DEN_VSETKY     'd' /* 2005-03-27: Pridane */

/* 2008-04-09: doplnen� pre batch generovanie modlitieb */
extern const char char_modlitby[];
extern const char *str_modlitby[];

//extern const char *nazov_modlitby[];
extern const char *nazov_modlitby_jazyk[POCET_MODLITIEB + 1][POCET_JAZYKOV + 1];
#define		nazov_modlitby(a)	nazov_modlitby_jazyk[a][_global_jazyk]

//extern const char *nazov_Modlitby[];
extern const char *nazov_Modlitby_jazyk[POCET_MODLITIEB + 1][POCET_JAZYKOV + 1];
#define		nazov_Modlitby(a)	nazov_Modlitby_jazyk[a][_global_jazyk]

/* extern const char *nazov_MODLITBY[]; */

/* ... a file templates (suborove vzory) pre modlitby */
#define TEMPLAT_INVITATORIUM     "invitat.htm"
#define TEMPLAT_RANNE_CHVALY     "rchvaly.htm"
#define TEMPLAT_POSV_CITANIE     "posvcit.htm"
#define TEMPLAT_CEZ_DEN_9        "predpol.htm"
#define TEMPLAT_CEZ_DEN_12       "napol.htm"
#define TEMPLAT_CEZ_DEN_3        "popol.htm"
#define TEMPLAT_VESPERY          "vespery.htm"
#define TEMPLAT_KOMPLETORIUM     "komplet.htm"

/* pridan� 2006-10-24 pre komplet�rium */
#define nazov_obd_KOMPLETORIUM   "cezrok_k.htm"

extern const char *TEMPLAT[];

/* znaky, ktore znacia (pre interpretovanie templatu) zaciatok a koniec
 * klucoveho slova */
#define CHAR_KEYWORD_BEGIN   '{'
#define CHAR_KEYWORD_END     '}'
#define CHAR_KEYWORD_DIVIDER ':'

/* include parameters (parametre v inkludovanych suboroch) */
#define INCLUDE_BEGIN   "BEGIN" /* zaciatok */
#define INCLUDE_END     "END"   /* koniec */

/* parameter identifiers */
#define PARAM_POPIS        "POPIS" /* pridane 05/04/2000A.D. */
#define PARAM_HYMNUS       "HYMNUS"
#define PARAM_ANTIFONA1    "ANTIFONA1"
#define PARAM_ANTIFONA2    "ANTIFONA2"
#define PARAM_ANTIFONA3    "ANTIFONA3"
#define PARAM_ZALM1        "ZALM1"
#define PARAM_ZALM2        "ZALM2"
#define PARAM_ZALM3        "ZALM3"
#define PARAM_ANTRCHVAL    "ANTRCHVAL" /* vlastne ANTIFONA2 */
#define PARAM_ANTVCHVAL    "ANTVCHVAL" /* vlastne ANTIFONA3 */
#define PARAM_RCHVALOSPEV  "RCHVALOSPEV" /* vlastne ZALM2 */
#define PARAM_VCHVALOSPEV  "VCHVALOSPEV" /* vlastne ZALM3 */
#define PARAM_KCITANIE     "KCITANIE"
#define PARAM_KRESPONZ     "KRESPONZ"
#define PARAM_MAGNIFIKAT   "MAGNIFIKAT" /* antifona na magnifikat */
#define PARAM_BENEDIKTUS   "BENEDIKTUS" /* antifona na benediktus */
#define PARAM_PROSBY       "PROSBY"
#define PARAM_MODLITBA     "MODLITBA"
/* pridane 2003-08-06, upravene 2003-08-21 */                                        
#define PARAM_CITANIE1     "CITANIE1" /* vlastne KCITANIE */
#define PARAM_CITANIE2     "CITANIE2" /* vlastne BENEDIKTUS */
/* 2007-10-02: pridan� kv�li rovnak�m antif�nam pre modlitbu cez de� */
#define PARAM_ANTIFONA1x   "ANTIFONA1_DRUHA"
#define PARAM_ANTIFONA3x   "ANTIFONA3_PRVA"
/* 2008-04-03: pridan� kv�li komplet�riu vo ve�kono�nom obdob�, �i pri druhej antif�ne zobrazi� dvojku alebo nie */
#define PARAM_ANTIFONA1k   "ANTIFONA1_KOMPLET"
#define PARAM_ANTIFONA2k   "ANTIFONA2_KOMPLET"

/* dalsie parametre: specificke pre obdobie */
/* Od nedele P�novho zm�tvychvstania a� do Druhej ve�kono�nej nedele vr�tane,
 * ako aj na druh� ve�pery sl�vnosti Zoslania Ducha Sv�t�ho */
#define PARAM_ALELUJA_ALELUJA_BEGIN         "ALELUJA_ALELUJA_BEGIN"
#define PARAM_ALELUJA_ALELUJA_END           "ALELUJA_ALELUJA_END"
#define PARAM_ALELUJA_NIE_V_POSTE           "ALELUJA_NIE_V_POSTE" /* pou��va sa v inkludovan�ch s�boroch, napr. v r�mci antif�n */
#define PARAM_ALELUJA_NIE_V_POSTE_BEGIN     "ALELUJA_NIE_V_POSTE_BEGIN"
#define PARAM_ALELUJA_NIE_V_POSTE_END       "ALELUJA_NIE_V_POSTE_END"
#define PARAM_ALELUJA_VO_VELKONOCNOM        "V_O_ALELUJA" /* pou��va sa v inkludovan�ch s�boroch, napr. v r�mci antif�n */
#define PARAM_ALELUJA_VO_VELKONOCNOM_BEGIN  "V_O_ALELUJA_BEGIN" /* pou��vaj� sa v templ�tach */
#define PARAM_ALELUJA_VO_VELKONOCNOM_END    "V_O_ALELUJA_END"
/* 2005-08-15: Doplnen� parametre pre vo�n�, in� hymny v 34. t��dni OCR */
#define PARAM_HYMNUS_34_OCR_INY_BEGIN       "HYMNUS_34_OCR_INY_BEGIN"
#define PARAM_HYMNUS_34_OCR_INY_END         "HYMNUS_34_OCR_INY_END"
/* 2005-11-11: Doplnen� parametre pre Te Deum 
#define PARAM_HYMNUS_TEDEUM_BEGIN           "HYMNUS_TEDEUM_BEGIN"
#define PARAM_HYMNUS_TEDEUM_END             "HYMNUS_TEDEUM_END"
	- napokon sa nepou��va zatia�
*/
/* nasleduju casti, ktore sa mozu pri generovani modlitby vynechat
 * alebo doplnit podla lubovole */
#define PARAM_OTCENAS_BEGIN                 "OTCENAS_BEGIN"
#define PARAM_OTCENAS_END                   "OTCENAS_END"
#define PARAM_CHVALOSPEV_BEGIN              "CHVALOSPEV_BEGIN"
#define PARAM_CHVALOSPEV_END                "CHVALOSPEV_END"
#define PARAM_ZAKONCENIE_BEGIN              "ZAKONCENIE_BEGIN"
#define PARAM_ZAKONCENIE_END                "ZAKONCENIE_END"
#define PARAM_KOMPLETORIUM_DVA_ZALMY_BEGIN	"KOMPLETORIUM_DVA_ZALMY_BEGIN"
#define PARAM_KOMPLETORIUM_DVA_ZALMY_END	"KOMPLETORIUM_DVA_ZALMY_END"
/* 2007-03-23: doplnen� Sl�va Otcu */
#define PARAM_SLAVAOTCU_BEGIN               "SLAVAOTCU_BEGIN"
#define PARAM_SLAVAOTCU_END                 "SLAVAOTCU_END"
/* 2007-06-28: doplnen� Te Deum; nem��e sa riadi� rovnak�mi pravidlami ako chv�lospevy */
#define PARAM_TEDEUM_BEGIN                  "TEDEUM_BEGIN"
#define PARAM_TEDEUM_END                    "TEDEUM_END"
/* 2007-10-02: doplnen� skrytie rovnak�ch antif�n pre mcd */
#define PARAM_SKRY_ANTIFONU_BEGIN           "SKRY_ANTIFONU_BEGIN"
#define PARAM_SKRY_ANTIFONU_END             "SKRY_ANTIFONU_END"
/* 2009-04-08, doplnen�: zakon�enie modlitby trojak�, kr�tke resp. dlh� */
#define PARAM_ZAKONCENIE_SKRZE              "ZAKONCENIE_SKRZE"
#define PARAM_ZAKONCENIE_LEBO_TY            "ZAKONCENIE_LEBO_TY"
#define PARAM_ZAKONCENIE_LEBO_ON            "ZAKONCENIE_LEBO_ON"
/* 2009-12-14, doplnen�: zakon�enie modlitby trojak�, kr�tke resp. dlh� s mal�m p�smenkom na za�iatku */
#define PARAM_ZAKONCENIE_SKRZE_MALE         "ZAKONCENIE_SKRZE_MALE"
#define PARAM_ZAKONCENIE_LEBO_TY_MALE       "ZAKONCENIE_LEBO_TY_MALE"
#define PARAM_ZAKONCENIE_LEBO_ON_MALE       "ZAKONCENIE_LEBO_ON_MALE"

/* stringy parametrov vstupu pre MODL_OPT..., ktore generovanie modlitby
 * ovplyvnuju */
/* option 1 */
//#define STR_ANO "�no"
extern const char *str_ano[POCET_JAZYKOV + 1];
#ifndef		STR_ANO
#define		STR_ANO		str_ano[_global_jazyk]
#endif
//#define STR_NIE "nie"
extern const char *str_nie[POCET_JAZYKOV + 1];
#ifndef		STR_NIE
#define		STR_NIE		str_nie[_global_jazyk]
#endif

/* option 2 - presunut� do mydefs.h 
#define MODL_ZALMY_ZO_DNA 0
#define MODL_ZALMY_ZO_SV  1
*/

//#define STR_MODL_ZALMY_ZO_DNA "d�a"
extern const char *str_modl_zalmy_zo_dna[POCET_JAZYKOV + 1];
#ifndef		STR_MODL_ZALMY_ZO_DNA
#define		STR_MODL_ZALMY_ZO_DNA 	str_modl_zalmy_zo_dna[_global_jazyk]
#endif
//#define STR_MODL_ZALMY_ZO_SV  "sviatku"
extern const char *str_modl_zalmy_zo_sv[POCET_JAZYKOV + 1];
#ifndef		STR_MODL_ZALMY_ZO_SV
#define		STR_MODL_ZALMY_ZO_SV 	str_modl_zalmy_zo_sv[_global_jazyk]
#endif

/* option 3 -- tieto nasledujuce definicie definuju to, co je sucastou
 * _struct_dm::spolcast */
#define MAX_MODL_SPOL_CAST  28
/* najviac MAX_MODL_SPOL_CAST "spolocnych casti", t.j. identifikatorov MODL_SPOL_CAST_...;
 * musi byt o jedno vacsia ako poslena, t.j. MODL_SPOL_CAST_NEBRAT */

#define MODL_SPOL_CAST_NEURCENA           0
#define MODL_SPOL_CAST_DUCH_PAST_KNAZ     1
#define MODL_SPOL_CAST_DUCH_PAST_BISKUP   2
#define MODL_SPOL_CAST_DUCH_PAST_PAPEZ    3
#define MODL_SPOL_CAST_UCITEL_CIRKVI      4
#define MODL_SPOL_CAST_APOSTOL            5
#define MODL_SPOL_CAST_MUCENIK            6 /* muz */
#define MODL_SPOL_CAST_VIAC_MUCENIKOV     7
#define MODL_SPOL_CAST_PANNA_MARIA        8
#define MODL_SPOL_CAST_SV_MUZ_REHOLNIK    9
#define MODL_SPOL_CAST_SV_MUZ            10 /* jeden */
#define MODL_SPOL_CAST_PANNA             11 /* jedna */
#define MODL_SPOL_CAST_SV_ZENA_REHOLNIK  12
#define MODL_SPOL_CAST_SV_ZENA           13 /* jedna */
#define MODL_SPOL_CAST_DUCH_PAST_VIACERI 14
#define MODL_SPOL_CAST_MUCENICA          15 /* zena */
#define MODL_SPOL_CAST_SV_ZENA_VYCH      16
#define MODL_SPOL_CAST_SV_MUZ_VYCH       17
#define MODL_SPOL_CAST_SV_ZENA_SKUTKYMIL 18
#define MODL_SPOL_CAST_SV_MUZ_SKUTKYMIL  19
#define MODL_SPOL_CAST_SV_ZENA_VIACERE   20
#define MODL_SPOL_CAST_SV_MUZ_VIACERI    21 /* viaceri */
#define MODL_SPOL_CAST_PANNY_VIACERE     22 /* viacere */
/* nasledovne dve pridane 29/03/2000A.D. */
#define MODL_SPOL_CAST_POSVIACKA_CHRAMU  23
#define MODL_SPOL_CAST_ZA_ZOSNULYCH      24
/* MODL_SPOL_CAST_NEBRAT musi byt posledna, napr. kvoli "while"
 * v dnes.cpp::showPrayer();
 * ale predsa mensia ako MAX_MODL_SPOL_CAST */
#define MODL_SPOL_CAST_SV_ZENA_MANZ      25 /* pridan� 2006-08-07 pre t�ch, �o �ili v man�elstve */
#define MODL_SPOL_CAST_SV_MUZ_MANZ       26 /* pridan� 2006-08-07 pre t�ch, �o �ili v man�elstve */
#define MODL_SPOL_CAST_NEBRAT            27 /* nechce zo spol. casti */
#define POCET_SPOL_CASTI	MAX_MODL_SPOL_CAST - 1

/* option 5, 2003-08-06, upravena 2003-08-13; 2007-06-01: presunut� do mydefs.h
#define MODL_CEZ_DEN_ZALMY_ZO_DNA         0
#define MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA  1
*/

//#define STR_MODL_CEZ_DEN_ZALMY_ZO_DNA        "be�nej"
extern const char *str_modl_cez_den_zalmy_zo_dna[POCET_JAZYKOV + 1];
#ifndef		STR_MODL_CEZ_DEN_ZALMY_ZO_DNA
#define		STR_MODL_CEZ_DEN_ZALMY_ZO_DNA	str_modl_cez_den_zalmy_zo_dna[_global_jazyk]
#endif
//#define STR_MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA "doplnkovej"
extern const char *str_modl_cez_den_doplnkova_psalmodia[POCET_JAZYKOV + 1];
#ifndef		STR_MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA
#define		STR_MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA	str_modl_cez_den_doplnkova_psalmodia[_global_jazyk]
#endif

/* a pre tieto - vyssie uvedene - konstanty aj retazce...
 * -- malo by ich byt do MAX_MODL_SPOL_CAST */
//extern const char *nazov_spolc[MODL_SPOL_CAST_NEBRAT + 1];
extern const char *nazov_spolc_jazyk[POCET_SPOL_CASTI + 1][POCET_JAZYKOV + 1];
#ifndef		nazov_spolc
#define		nazov_spolc(a)	nazov_spolc_jazyk[a][_global_jazyk]
#endif

/* a pre tieto konstanty aj retazce -- nazvy suborov
 * -- malo by ich byt do MAX_MODL_SPOL_CAST */
/* sc_rh == spolocna cast pre reholnikov / reholnice;
 * sc_skm == spolocna cast pre tych, co konali skutky milosrdenstva ;
 * sc_vv == spolocna cast pre vychovavatelov;
 * zosnuli == oficium za zosnulych;
 */
extern const char *nazov_spolc_htm[MODL_SPOL_CAST_NEBRAT + 1];
/* a pre tieto konstanty aj retazce -- nazvy kotiev
 * -- malo by ich byt do MAX_MODL_SPOL_CAST */
extern const char *nazov_spolc_ANCHOR[MODL_SPOL_CAST_NEBRAT + 1];

#define ANCHOR_SPOL_CAST_DUCH_PAST "SCDP" /* 23/02/2000A.D. */
/* vacsinu veci maju duchovni pastieri spolocnych;
 * odlisnosti: su v nazov_spolc_ANCHOR[] */
#define ANCHOR_SPOL_CAST_JEDEN_MUCENIK "SCJM" /* 23/02/2000A.D. */
/* na sviatok jedneho mucenika sa rozhoduje, ci ide o muza alebo zenu
 * v niektorych pripadoch; odlisnosti: su v nazov_spolc_ANCHOR[] */
#define ANCHOR_SPOL_CAST_PANNA_MUCENICA "SCAM" /* 23/02/2000A.D. */
/* na sviatok vychovavatelov: nevieme (a je jedno), ci ide o muza alebo
 * zenu -- ked berieme z fajlu sc_vv.htm; 29/02/2000A.D.
#define ANCHOR_SPOL_CAST_VYCHOVAVATEL "SCVV"
#define FILE_SPOL_CAST_VYCHOVAVATEL "sc_vv.htm" */
/* na sviatok tych, co konali skutky milosrdenstva: nevieme (a je jedno),
 * ci ide o muza alebo zenu -- ked berieme z fajlu sc_skm.htm; 29/02/2000A.D.
#define ANCHOR_SPOL_CAST_SKUTKYMIL "SCSKM"
#define FILE_SPOL_CAST_SKUTKYMIL "sc_skm.htm"
*/ // je to v poli... v hodin.h

struct sc{
	short int a1;
	short int a2;
	short int a3;
};
typedef struct sc _struct_sc;

/* 2005-07-27: zaveden� nov� premenn� v �trukt�re: typslav_lokal
 * ur�en� nies� �peci�lnu inform�ciu o tom, �i dan� sl�venie je lok�lne.
 * �tandardne 0 = bez �peci�lnej lokaliz�cie.
 *
 * 2006-08-19: pridan� premenn� pre liturgick� farbu
 *
 *
 */
struct dm{
	short int den;        /* cislo dna mesiaca (1--31) */
	short int mesiac;     /* cislo mesiaca (1--12) */
	short int rok;        /* rok */
	short int denvt;      /* cislo dna v tyzdni (0--6) DEN_... */
	short int denvr;      /* cislo dna v roku (1--365/366) */ /* de� v roku */
	/* toto boli "obcianske" zalezitosti */
	char litrok;    /* liturgicky rok ('A'--'C') */
	short int tyzden;     /* tyzden v danom liturgickom obdobi */
	short int tyzzal;     /* tyzden v zaltari (vacsinou ((tyzden - 1) % 4) + 1) */
	short int litobd;     /* liturgicke obdobie, OBD_... */
	short int typslav;    /* typ slavenia (1--5): SLAV_... */
	short int typslav_lokal;    /* lok�lny typ slavenia : LOKAL_SLAV_... */
	short int smer;       /* poradove cislo z c.59 Vseobecnych smernic
						  * o liturgii hodin a kalendari */
	short int prik;		 /* ci je to prikazany sviatok alebo nie:
						  * PRIKAZANY_SVIATOK resp. NEPRIKAZANY_SVIATOK */
	int spolcast;		 /* spolocna cast -- pridane 09/02/2000A.D.,
						  * zakodovane data pre svatych o tom, z akej spolocnej
						  * casti sa ma modlit;
						  * obsahuje max. 3 spolocne casti vo formate
						  *
						  * spolcast == a1 + a2 * MAX + a3 * MAX * MAX,
						  *
						  * kde
						  * - MAX je MAX_MODL_SPOL_CAST,
						  * - a1, a2, a3 su konstanty MODL_SPOL_CAST_...
						  *   (v poradi a1, ak druhe tak a2, ak tretie tak aj a3)
						  *
						  * _encode_..., _decode_spol_cast();
						  */
	char meno[MENO_SVIATKU]; /* nazov prip. sviatku */
	short int farba;     /* liturgick� farba pre sl�venie */
};
typedef struct dm _struct_dm;

/* dni */
#define DEN_NEDELA      0
#define DEN_PONDELOK    1
#define DEN_UTOROK      2
#define DEN_STREDA      3
#define DEN_STVRTOK     4
#define DEN_PIATOK      5
#define DEN_SOBOTA      6
/* neznamy den */
#define DEN_UNKNOWN     7
#define POCET_DNI		7

/* mesiace */
#define MES_JAN 0
#define MES_FEB 1
#define MES_MAR 2
#define MES_APR 3
#define MES_MAY 4
#define MES_MAJ 4
#define MES_JUN 5
#define MES_JUL 6
#define MES_AUG 7
#define MES_SEP 8
#define MES_OCT 9
#define MES_OKT 9
#define MES_NOV 10
#define MES_DEC 11
/* neznamy mesiac */
#define UNKNOWN_MESIAC	12
#define POCET_MESIACOV	12
/* vsetky mesiace */
#define VSETKY_MESIACE	13
#define STR_VSETKY_MESIACE  "*"
/* vsetky dni */
#define VSETKY_DNI   32
#define STR_VSETKY_DNI  "*"

/* liturgicke obdobia */
//OBD_ADVENTNE
#define OBD_ADVENTNE_I             1 /* do 16. decembra */
#define OBD_ADVENTNE_II            2 /* po 16. decembri */
//OBD_VIANOCNE
#define OBD_VIANOCNE_I             3 /* do slavnosti zjavenia pana */
#define OBD_VIANOCNE_II            4 /* po slavnosti zjavenia pana */
//OBD_CEZ_ROK
#define OBD_CEZ_ROK                5
//OBD_POSTNE
#define OBD_POSTNE_I               6 /* do soboty v piatom tyzdni */
#define OBD_POSTNE_II_VELKY_TYZDEN 7 /* velky tyzden */
//OBD_VELKONOCNE
#define OBD_VELKONOCNE_TROJDNIE    8 /* umucenia a zmrtvychvstania Pana */
#define OBD_VELKONOCNE_I           9 /* do nanebovstupenia pana */
#define OBD_VELKONOCNE_II         10 /* po nanebovstupeni pana */
/* nasleduju specialne pod-obdobia */
#define OBD_VELKONOCNA_OKTAVA      0 /* velkonocna nedela -- 2. velk. ne */
#define OBD_OKTAVA_NARODENIA      11 /* narodenie Pana -- 1. jan. */

#define	POCET_OBDOBI	11

/* zv�zok brevi�ra - zv�zok, v ktorom sa nach�dza dan� liturgick� obdobie; doplnen� 2007-12-20; opraven� 2008-01-23 */
const short int zvazok_breviara[POCET_OBDOBI + 1] = 
{2, 1, 1, 1, 1, 3, 2, 2, 2, 2, 2, 1}; // nepotrebujeme rozl�i� 3. a 4. zv�zok, ktor� obidva obsahuj� OBD_CEZ_ROK

/* nazov_obdobia: string pre nazov liturgickeho obdobia */
//extern const char *nazov_obdobia[];
extern const char *nazov_obdobia_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1];
#define		nazov_obdobia(a)	nazov_obdobia_jazyk[a][_global_jazyk]

extern const char *nazov_obdobia_[];

/* lokal == 6. pad, v kom/com */
//extern const char *nazov_obdobia_v[];
extern const char *nazov_obdobia_v_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1];
#define		nazov_obdobia_v(a)	nazov_obdobia_v_jazyk[a][_global_jazyk]

//extern const char *nazov_OBDOBIA_V[];
extern const char *nazov_OBDOBIA_V_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1];
#define		nazov_OBDOBIA_V(a)	nazov_OBDOBIA_V_jazyk[a][_global_jazyk]

/* 2008-12-20: doplnen� */
extern const char *nazov_OBDOBIA_AKA_jazyk[POCET_OBDOBI + 1][POCET_JAZYKOV + 1];
#define		nazov_OBDOBIA_AKA(a)	nazov_OBDOBIA_AKA_jazyk[a][_global_jazyk]

/* gen[itiv] == 2. pad, koho/coho */
/* extern const char *nazov_obdobia_gen[]; */
/* extern const char *nazov_Obdobia[]; */

/* nazov_obdobia: string pre nazov suboru .htm liturgickeho obdobia */
extern const char *nazov_obd_htm[];
/* nazov_obdobia: string pre nazov kotvy v .htm liturgickeho obdobia */
extern const char *nazov_OBD[];
/* nazov_obdobia pc: string pre nazov suboru .htm liturgickeho obdobia pre posvatne citania */
extern const char *nazov_obd_htm_pc[];
/* 2005-08-05: Pridan�. zv�zok brevi�ra (LH) pre spolo�n� �asti sv�t�ch v kotv�ch */
extern const char *zvazok_OBD[];

/* typy slavenia */
#define SLAV_NEURCENE            0
#define SLAV_SLAVNOST            1
#define SLAV_SVIATOK             2
#define SLAV_SPOMIENKA           3
#define SLAV_LUB_SPOMIENKA       4
#define SLAV_VLASTNE             5

#define	POCET_SLAVENI		5

/* nazov_slavenia: string pre nazov typu slavenia */
//extern const char *nazov_slavenia[];
extern const char *nazov_slavenia_jazyk[POCET_SLAVENI + 1][POCET_JAZYKOV + 1];
#define		nazov_slavenia(a)	nazov_slavenia_jazyk[a][_global_jazyk]

/* extern const char *nazov_Slavenia[]; */

/* 2005-07-27: doplnen� */
extern const char *nazov_slavenia_lokal[];

/* 2005-07-27: doplnen� lok�lne typy sl�venia */
#define LOKAL_SLAV_NEURCENE					0
#define LOKAL_SLAV_ROZNAVA_KATEDRALA		1
#define LOKAL_SLAV_TRNAVA_PATRON			2
#define LOKAL_SLAV_TT_BB_KE_NR_RO			3
#define LOKAL_SLAV_NITRA_PATRON				4
#define LOKAL_SLAV_KOSICE					5
#define LOKAL_SLAV_NITRA					6
#define LOKAL_SLAV_BYSTRICA					7
#define LOKAL_SLAV_SPIS						8
#define LOKAL_SLAV_ROZNAVA					9
#define LOKAL_SLAV_TRNAVA					10 /* p�vodne bolo LOKAL_SLAV_TRNAVA, upraven� 2007-08-31 na LOKAL_SLAV_BA_TT; nasp� na LOKAL_SLAV_TRNAVA 2008-06-23 */
#define LOKAL_SLAV_DOM_SV_MARTINA			11
#define LOKAL_SLAV_SPIS_PATRON				12
#define LOKAL_SLAV_BYSTRICA_PATRON			13
#define LOKAL_SLAV_TT_BB_NR_RO				14
#define LOKAL_SLAV_KOSICE_PATRON			15
#define LOKAL_SLAV_14_FEB_CYRIL_METOD		16
#define LOKAL_SLAV_ROZNAVA_PATRON			17
#define LOKAL_SLAV_KONSEKR_KOSTOLY			18
#define LOKAL_SLAV_DRUHA_VELK_NEDELA		19
#define LOKAL_SLAV_KONIEC_OKTAVY_NAR		20
#define LOKAL_SLAV_KONIEC_OKTAVY_NAR_CZ		21
#define LOKAL_SLAV_PRAHA_PATRON				22
#define LOKAL_SLAV_PRAHA					23
#define LOKAL_SLAV_BRNO						24
#define LOKAL_SLAV_MORAVA_SPOMIENKA			25
#define LOKAL_SLAV_DRUHA_VELK_NEDELA_CZ		26
#define LOKAL_SLAV_PRAHA_KATEDRALA			27
#define LOKAL_SLAV_CESKE_BUDEJOVICE			28
#define LOKAL_SLAV_OLOMOUC					29
#define LOKAL_SLAV_CECHY_SPOMIENKA			30
#define LOKAL_SLAV_PLZEN_PATRON				31
#define LOKAL_SLAV_OSTRAVA_OPAVA			32
#define LOKAL_SLAV_LITOMERICE				33
#define LOKAL_SLAV_HRADEC_KRALOVE			34
#define LOKAL_SLAV_KONSEKR_KOSTOLY_CZ 		35
#define LOKAL_SLAV_PLZEN 					36
#define LOKAL_SLAV_SLEZSKO_SVATEK			37
#define LOKAL_SLAV_CESKE_BUDEJOVICE_PAMATKA	38
#define LOKAL_SLAV_SPIS_BA_PATRON			39 /* pre 11. novembra, patr�na BA-arcidiec�zy; 2008-06-24; nahr�dza LOKAL_SLAV_SPIS_PATRON */
#define LOKAL_SLAV_BRATISLAVA				40 /* doplnen� 2010-03-16 */
#define LOKAL_SLAV_KONIEC_OKTAVY_NAR_HU		41 /* doplnen� 2010-05-17 */

/* prikazany / neprikazany sviatok */
#define PRIKAZANY_SVIATOK 1
#define NEPRIKAZANY_SVIATOK 0

/* div, mod: delenie pre short int */
#define DIV	/
#define MOD	%

/* 2006-02-07: dodefinovan� r�zne spr�vanie funkcie zaltar_zvazok(); */
#define	ZALTAR_VSETKO                0
#define ZALTAR_IBA_ZALMY             1
#define ZALTAR_IBA_ZALMY_HYMNUS_MCD  2

/* 2006-08-19: pridan� liturgick� farby */
#define LIT_FARBA_NEURCENA			0
#define LIT_FARBA_CERVENA			1
#define LIT_FARBA_BIELA				2
#define LIT_FARBA_ZELENA			3
#define LIT_FARBA_FIALOVA			4
#define LIT_FARBA_RUZOVA			5

#define POCET_FARIEB				5

/* nazov_farby: string pre n�zov liturgickej farby */
extern const char *nazov_farby_jazyk[POCET_FARIEB + 1][POCET_JAZYKOV + 1];
#define		nazov_farby(a)	nazov_farby_jazyk[a][_global_jazyk]

extern const char *html_farba_pozadie[];
extern const char *html_farba_popredie[];

/* juliansky datum, funkcia juliansky_datum, dane synonymum JD */
#define	JD	juliansky_datum

/* tyzden zaltara (1, 2, 3, 4) podla tyzdna t; 06/03/2000A.D.: namiesto "-1" prerobene na "+3" */
#define  tyzden_zaltara(t)  ((((t) + 3) % 4) + 1)
extern const char *rimskymi_tyzden_zaltara[];

extern const short int prvy_den[12];

extern short int pocet_dni[12];

extern const char char_nedelne_pismeno[7];

extern const char char_nedelny_cyklus[3];

#define	ROK_1968		1968
#define	JUL_DATE_0_JAN_1968	2439856L /* juliansky datum pre 0. januar 1968 */

#define	POCET_DNI_V_ROKU	365

#define	POCET_NEDIEL_CEZ_ROK	34
#define	KRISTA_KRALA	34 /* 34. nedela v obdobi cez rok je sviatok K.K. */

/* poradie prva adventna nedela, neprestupny rok! */
#define	PRVA_ADVENTNA_NEDELA_b	331

#define	OD_VELKEJ_NOCI_PO_POPOLCOVU_STR		-46
#define OD_VELKEJ_NOCI_PO_NANEBOSTUPENIE	39
#define	OD_VELKEJ_NOCI_PO_ZOSLANIE_DUCHA	49

/* sposob pisania slov */
#define CASE_case 0 /* vsetky male */
#define CASE_Case 1 /* Prve Pismeno Velke */
#define CASE_CASE 2 /* VSETKO VELKE */

/* nazov_dna: string pre nazov dna; suhlasi s struct tm.tm_wday;
 * Weekday (0--6; Sunday/nedela = 0) */

//extern const char *nazov_dna[];
extern const char *nazov_dna_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1];
#define		nazov_dna(a)	nazov_dna_jazyk[a][_global_jazyk]

//extern const char *nazov_dna_asci[];
extern const char *nazov_dna_asci_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1];
#define		nazov_dna_asci(a)	nazov_dna_asci_jazyk[a][_global_jazyk]

//extern const char *nazov_Dna[];
extern const char *nazov_Dna_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1];
#define		nazov_Dna(a)	nazov_Dna_jazyk[a][_global_jazyk]

//extern const char *nazov_DNA[];
extern const char *nazov_DNA_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1];
#define		nazov_DNA(a)	nazov_DNA_jazyk[a][_global_jazyk]

//extern const char *nazov_Dn[];
extern const char *nazov_Dn_jazyk[POCET_DNI + 1][POCET_JAZYKOV + 1];
#define		nazov_Dn(a)	nazov_Dn_jazyk[a][_global_jazyk]

extern const char *nazov_DN_asci[];
extern const char *nazov_dn_asci[];

/* nazov_mesiaca: string pre nazov dna; suhlasi s struct tm.tm_mon;
 * Month (0--11) */

//extern const char *nazov_mesiaca[];
extern const char *nazov_mesiaca_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1];
#define		nazov_mesiaca(a)	nazov_mesiaca_jazyk[a][_global_jazyk]

//extern const char *nazov_mesiaca_asci[];
extern const char *nazov_mesiaca_asci_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1];
#define		nazov_mesiaca_asci(a)	nazov_mesiaca_asci_jazyk[a][_global_jazyk]

//extern const char *nazov_Mesiaca[];
extern const char *nazov_Mesiaca_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1];
#define		nazov_Mesiaca(a)	nazov_Mesiaca_jazyk[a][_global_jazyk]

//extern const char *nazov_MESIACA[];
extern const char *nazov_MESIACA_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1];
#define		nazov_MESIACA(a)	nazov_MESIACA_jazyk[a][_global_jazyk]

/* 2007-03-20: pridan� genit�v n�zvu mesiaca kv�li latin�ine */
extern const char *nazov_mesiaca_gen_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1];
#define		nazov_mesiaca_gen(a)	nazov_mesiaca_gen_jazyk[a][_global_jazyk]

extern const char *nazov_Mesiaca_gen_jazyk[POCET_MESIACOV + 1][POCET_JAZYKOV + 1];
#define		nazov_Mesiaca_gen(a)	nazov_Mesiaca_gen_jazyk[a][_global_jazyk]

extern const char *nazov_MES[];
extern const char *nazov_mes[];

#define		POCET_TYZDNOV 34

/* 2008-12-20: pridan� re�azec pre poradov� ��slo */
extern const char *poradie_Slovom_jazyk[POCET_TYZDNOV + 1][POCET_JAZYKOV + 1];
#define		poradie_Slovom(a)	poradie_Slovom_jazyk[a][_global_jazyk]

extern const char *poradie_SLOVOM_jazyk[POCET_TYZDNOV + 1][POCET_JAZYKOV + 1];
#define		poradie_SLOVOM(a)	poradie_SLOVOM_jazyk[a][_global_jazyk]

#define POCET_ALIASOV          7
/* sucast struktury lrok, indexy */
#define KRST_KRISTA_PANA       0
#define POPOLCOVA_STREDA       1
#define VELKONOCNA_NEDELA      2
#define NANEBOVSTUPENIE_PANA   3
#define ZOSLANIE_DUCHA_SV      4
#define PRVA_ADVENTNA_NEDELA   5
#define SVATEJ_RODINY          6

/* sucast struktury lrok, aliasy */
#define _KRST_KRISTA_PANA         _den[KRST_KRISTA_PANA]
#define _POPOLCOVA_STREDA         _den[POPOLCOVA_STREDA]
#define _VELKONOCNA_NEDELA        _den[VELKONOCNA_NEDELA]
#define _NANEBOVSTUPENIE_PANA     _den[NANEBOVSTUPENIE_PANA]
#define _PRVA_ADVENTNA_NEDELA     _den[PRVA_ADVENTNA_NEDELA]
#define _ZOSLANIE_DUCHA_SV        _den[ZOSLANIE_DUCHA_SV]
#define _SVATEJ_RODINY            _den[SVATEJ_RODINY]

#define YES 1
#define NO  0

#define NIJAKE_NEDELNE_PISMENO 'x'
struct lrok{
	short int prestupny;     /* ci je rok prestupny (YES, NO) */
	char p1, p2;       /* nedelne pismeno/pismena;
							  * ak ma rok iba jedno,
							  * druhe p2 == NIJAKE_NEDELNE_PISMENO */
	char litrok;       /* pismeno liturgickeho roka,
							  * ktory zacina prvou adventnou nedelou v roku */
	short int tyzden_ocr_po_vn; /* cislo tyzdna obdobia "cez rok", ktory nasleduje po nedeli zoslania
							  * ducha svateho, teda po velkonocnom obdobi */
	short int tyzden_ocr_pred_po; /* cislo tyzdna obdobia cez rok, v ktorom zacina post; 15/03/2000A.D. */
	struct dm _den[POCET_ALIASOV];
};
typedef struct lrok _struct_lrok;

#define LINK_DEN_MESIAC_NIE 0 /* 2008-01-22: pridan�, Vlado Ki� upozornil, �e je to zbyto�n� */
#define LINK_DEN_MESIAC_ROK 1
#define LINK_DEN_MESIAC 3
#define LINK_DEN 2
#define LINK_DEN_MESIAC_ROK_PRESTUP 4 /* pridana kvoli prestupnym rokom, 2003-07-02 */
#define LINK_ISO_8601 5 /* pridana kvoli SIMPLE exportu, 2005-03-21 */
#define LINK_DEN_MESIAC_PREDOSLY 6 /* 2007-08-15 pridan� kv�li nov�mu kalend�ru */
#define LINK_DEN_MESIAC_NASLEDOVNY 7 /* 2007-08-15 pridan� kv�li nov�mu kalend�ru */

/* ------------------------------------------------------------------- */
/* globalne premenne -- su definovane v dnes.cpp (18/02/2000A.D.) */

/* globalna premenna, do ktorej sa ukladaju info o analyzovanom dni
 * pouziva ju void nove_rozbor_dna() funkcia */

extern _struct_dm *_global_den_ptr;
/*extern _struct_dm _global_den;*/
#define _global_den (*_global_den_ptr)

/* globalna premenna, ktora obsahuje data o spomienke panny marie v sobotu */

extern _struct_dm *_global_pm_sobota_ptr;
/*extern _struct_dm _global_pm_sobota;*/
#define _global_pm_sobota (*_global_pm_sobota_ptr)

/* globalne premenne, do ktorych sa ukladaju info o analyzovanom dni
 * o sviatkoch svatych */

extern _struct_dm *_global_svaty1_ptr;
/*extern _struct_dm _global_svaty1;*/
#define _global_svaty1 (*_global_svaty1_ptr)

extern _struct_dm *_global_svaty2_ptr;
/*extern _struct_dm _global_svaty2;*/ /* v pripade, ze je viac lubovolnych spomienok */
#define _global_svaty2 (*_global_svaty2_ptr)

extern _struct_dm *_global_svaty3_ptr;
/*extern _struct_dm _global_svaty3;*/ /* v pripade, ze je viac lubovolnych spomienok */
#define _global_svaty3 (*_global_svaty3_ptr)

/* globalne premenne obsahujuce data modlitbach */

extern _type_1vespery     *_global_modl_prve_vespery_ptr;
/*extern _type_1vespery      _global_modl_prve_vespery;*/
#define _global_modl_prve_vespery (*_global_modl_prve_vespery_ptr)

extern _type_1kompletorium *_global_modl_1kompletorium_ptr;
/*extern _type_1kompletorium _global_modl_prve_kompletorium;*/
#define _global_modl_prve_kompletorium (*_global_modl_1kompletorium_ptr)

extern _type_invitatorium *_global_modl_invitatorium_ptr;
/*extern _type_invitatorium  _global_modl_invitatorium;*/
#define _global_modl_invitatorium (*_global_modl_invitatorium_ptr)

/* 2003-08-13 pridane posvatne citanie */
extern _type_posv_citanie *_global_modl_posv_citanie_ptr;
#define _global_modl_posv_citanie (*_global_modl_posv_citanie_ptr)

extern _type_ranne_chvaly *_global_modl_ranne_chvaly_ptr;
/*extern _type_ranne_chvaly  _global_modl_ranne_chvaly;*/
#define _global_modl_ranne_chvaly (*_global_modl_ranne_chvaly_ptr)

extern _type_cez_den_9     *_global_modl_cez_den_9_ptr;
/*extern _type_cez_den_9     _global_modl_cez_den_9;*/
#define _global_modl_cez_den_9 (*_global_modl_cez_den_9_ptr)
extern _type_cez_den_12     *_global_modl_cez_den_12_ptr;
/*extern _type_cez_den_12     _global_modl_cez_den_12;*/
#define _global_modl_cez_den_12 (*_global_modl_cez_den_12_ptr)
extern _type_cez_den_3     *_global_modl_cez_den_3_ptr;
/*extern _type_cez_den_3     _global_modl_cez_den_3;*/
#define _global_modl_cez_den_3 (*_global_modl_cez_den_3_ptr)

/* pridane 2003-08-13 pre lahsie pouzitie */
#define _global_modl_predpol  _global_modl_cez_den_9
#define _global_modl_napol    _global_modl_cez_den_12
#define _global_modl_popol    _global_modl_cez_den_3

extern _type_vespery      *_global_modl_vespery_ptr;
/*extern _type_vespery       _global_modl_vespery;*/
#define _global_modl_vespery (*_global_modl_vespery_ptr)

extern _type_kompletorium *_global_modl_kompletorium_ptr;
/*extern _type_kompletorium _global_modl_kompletorium;*/
#define _global_modl_kompletorium (*_global_modl_kompletorium_ptr)

/* globalna premenna, ktora obsahuje MODL_... */
extern short int _global_modlitba;

/* globalna premenna, do ktorej ukladaju funkcie vytvor_query_string_...
 * linku tvaru PATH_CGI(SCRIPT_NAME) ++ "?param1=val&param2=val&..." */
extern char *_global_link_ptr;
/*extern char _global_link[MAX_STR];*/
#define _global_link _global_link_ptr

extern char *_global_pom_str; /* pomocny string pre velke pismena */
/*extern char _global_pom_str[MAX_STR];*/

/* globalna premenna, do ktorej sa ukladaju info o jednotlivych
 * vyznacnych liturgickych dni, pouzivaju void _dm_...() funkcie
 * a void analyzuj_rok() funkcia */
extern _struct_dm *_global_result_ptr;
/*extern _struct_dm _global_result;*/
#define _global_result (*_global_result_ptr)

/* globalna premenna, do ktorej sa uklada info o liturgickom roku
 * pouziva void analyzuj_rok() funkcia */
extern _struct_lrok *_global_r_ptr;
/*extern _struct_lrok _global_r;*/
#define _global_r (*_global_r_ptr)

/* globalna premenna, do ktorej sviatky_svatych() uklada
 * pocet sviatkov (de facto lubovolnych spomienok), ktore
 * pripadaju na dany den
 * -- v podstate neuklada do nej, ale v _rozbor_dna() sa do nej priradi
 * vysledok (navratova hodnota) z sviatky_svatych()
 */
extern short int _global_pocet_svatych;

/* globalne premenne, obsahujuce pom_MODL_OPT... */
extern short int _global_opt1/* = NIE*/;
extern short int _global_opt2/* = MODL_ZALMY_ZO_DNA*/;
extern short int _global_opt3;
extern short int _global_opt4;
extern short int _global_opt5; /* pridane 2003-08-07 */
extern short int _global_opt6; /* pridan� 2007-06-01 */
extern short int _global_opt7; /* pridan� 2007-06-01 */

/* globalna premenna, co obsahuje string vypisany na obsazovku */
extern char *_global_string;
extern char *_global_string2; /* obsahuje I, II, III, IV, V alebo pismeno roka */
extern char *_global_string_farba; /* 2006-08-19: doplnen� */

extern char *_global_buf; /* 2006-08-01: t�to premenn� tie� alokujeme */
extern char *_global_buf2; /* 2006-08-01: t�to premenn� tie� alokujeme */

/* pridane 13/04/2000A.D.; definovane v breviar.cpp */
extern short int _global_linky;

/* 2006-07-11: Pridan� kv�li jazykov�m mut�ci�m (breviar.cpp) */
extern short int _global_language;
#ifndef _global_jazyk
#define	_global_jazyk	_global_language
#endif

extern short int _global_css; /* 2008-08-08: Pridan� kv�li r�znym css */

/* 2006-10-17: Pridan� kv�li komplet�riu: niekedy obsahuje a� dva �almy */
extern short int _global_pocet_zalmov_kompletorium;

extern const char *nazov_jazyka[];
extern const char *skratka_jazyka[];
extern const char *postfix_jazyka[];

extern const char *skratka_css[];
extern const char *nazov_css[];

/* ------------------------------------------------------------------- */

/* ------------------------------------------------------------------- */
/* tu nasleduju funkcie(), ibaze by som inkludoval "liturgia.cpp" */

short int _allocate_global_var(void);
short int _deallocate_global_var(void);

short int equals(char *, char *);
short int equals(const char *, const char *);
short int equals(const char *, char *);
short int equals(char *, const char *);
short int equalsi(char *, char *);
short int equalsi(const char *, const char *);
short int equalsi(const char *, char *);
short int equalsi(char *, const char *);

short int cislo_mesiaca(char *mesiac);
char *caps_BIG(const char *input);

/* podla toho, ako sa funkcia vola, urcim case */
#define vytvor_global_link(den, mesiac, rok, typ)	_vytvor_global_link(den, mesiac, rok, CASE_case, typ)
#define Vytvor_global_link(den, mesiac, rok, typ)	_vytvor_global_link(den, mesiac, rok, CASE_Case, typ)
#define VYTVOR_global_link(den, mesiac, rok, typ)	_vytvor_global_link(den, mesiac, rok, CASE_CASE, typ)
void _vytvor_global_link(short int den, short int mesiac, short int rok, short int _case, short int typ);

short int prestupny(short int);
short int pocet_dni_v_roku(short int);
short int poradie(short int den, short int mesiac, short int rok);
short int poradie(_struct_den_mesiac den_a_mesiac, short int rok);
long juliansky_datum(short int por, short int rok);
long juliansky_datum(short int den, short int mesiac, short int rok);
_struct_den_mesiac velkonocna_nedela(short int R);
short int _velkonocna_nedela(short int rok);
short int den_v_tyzdni(short int por, short int rok);
short int den_v_tyzdni(short int den, short int mesiac, short int rok);
short int den_v_tyzdni(_struct_den_mesiac den_a_mesiac, short int rok);
unsigned char _nedelne_pismeno(short int rok);
char nedelne_pismeno(short int rok);
unsigned char _nedelne_pismeno(short int por, short int rok);
char nedelne_pismeno(short int por, short int rok);
char nedelne_pismeno(short int den, short int mesiac, short int rok);
unsigned char _nedelne_pismeno(short int den, short int mesiac, short int rok);
unsigned char _nedelne_pismeno(_struct_den_mesiac den_a_mesiac, short int rok);
char nedelne_pismeno(_struct_den_mesiac den_a_mesiac, short int rok);
_struct_den_mesiac por_den_mesiac(short int poradie, short int rok);
short int _svatej_rodiny(short int rok);
short int _krst_krista_pana(short int rok);
short int _popolcova_streda(short int rok);
short int _nanebovstupenie(short int rok);
short int _zoslanie_ducha(short int rok);
short int _prva_adventna_nedela(short int rok);
_struct_den_mesiac prva_adventna_nedela(short int rok);
short int nedelny_cyklus(short int por, short int rok);
short int nedelny_cyklus(short int den, short int mesiac, short int rok);
short int nedelny_cyklus(_struct_den_mesiac den_a_mesiac, short int rok);
_struct_dm por_den_mesiac_dm(short int poradie, short int rok);
short int tyzden_cez_rok_po_vn(short int rok);
short int cislo_nedele_cez_rok_po_vn(short int rok);
void init_global_pm_sobota(void);
void _dm_popolcova_streda(short int rok, short int _vn);
void _dm_nanebovstupenie(short int rok, short int _vn);
void _dm_zoslanie_ducha(short int rok, short int _vn);
void _dm_prva_adventna_nedela(short int rok, short int p2);
void _dm_svatej_rodiny(short int rok);
void _dm_krst_krista_pana(short int rok);
void _dm_velkonocna_nedela(short int rok, short int _vn);

void analyzuj_rok(short int year);

/* pridana 2003-08-07 */
/* zapoznamkovana 2003-08-11 */
#undef ZAPOZNAMKOVANE_2003_08_11
#ifdef ZAPOZNAMKOVANE_2003_08_11
void _init_dm(_struct_dm a);
#endif

#define UNKNOWN_PORADIE_SVATEHO 0
/* 28/03/2000A.D.: naschval < 0, aby nebol problem s porovnanim s _global_pocet_svatych v _rozbor_dna() 
 * 2009-03-19: presunut� z breviar.cpp
 * 2009-03-27: po z�fal�ch pokusoch dnes - napokon som zistil, �e u� je �plne jedno, ak� hodnotu bude t�to kon�tanta ma�, preto som ju dal op� na 0
 */

/* definovany 2003-08-11 na zaklade funkcie _init_dm() 
 * upraven� 2007-08-16, preto�e sa pou��va aj v _main_dnes()
 */
#define _INIT_DM(a) {\
	a.den = 1;        /* cislo dna v mesiaci (1--31) */\
	a.mesiac = 1;     /* cislo mesiaca (1--12) */\
	a.rok = 1900;        /* rok */\
	a.denvt = 0;     /* cislo dna v tyzdni (0--6) DEN_... */ /* de� v roku */\
	a.denvr = 1;      /* cislo dna v roku (1--365/366) */\
	/* toto boli "obcianske" zalezitosti */\
	a.litrok = 'A';     /* liturgicky rok ('A'--'C') */\
	a.tyzden = 1;     /* tyzden v danom liturgickom obdobi */\
	a.tyzzal = 1;     /* tyzden v zaltari (vacsinou ((tyzden - 1) % 4) + 1) */\
	a.litobd = OBD_CEZ_ROK;    /* liturgicke obdobie, OBD_... */\
	a.typslav = SLAV_NEURCENE;    /* typ slavenia (1--5): SLAV_... */\
	a.typslav_lokal = LOKAL_SLAV_NEURCENE; /* LOKAL_SLAV_NEURCENE; nie je obmedzenie na lokalitu, pridan� 2005-07-27 */\
	a.smer = 99;     /* poradove cislo z c.59 Vseobecnych smernic o liturgii hodin a kalendari */\
	a.prik = NEPRIKAZANY_SVIATOK;      /* ci je to prikazany sviatok alebo nie: PRIKAZANY_SVIATOK resp. NEPRIKAZANY_SVIATOK */\
	a.spolcast = _encode_spol_cast(MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA); /* MODL_SPOL_CAST_NEURCENA; spolocna cast -- zakodovane data pre svatych o tom, z akej spolocnej casti sa ma modlit */\
	mystrcpy(a.meno, STR_UNDEF, MENO_SVIATKU); /* nazov prip. sviatku */\
	a.farba = LIT_FARBA_NEURCENA; /* 2006-08-19: pridan� */\
}

/* inicializacne definy pridane 2003-08-13 */
#define _INIT_ANCHOR_AND_FILE(a) {\
	mystrcpy(a.file, STR_UNDEF, MAX_STR_AF_FILE); \
	mystrcpy(a.anchor, STR_UNDEF, MAX_STR_AF_ANCHOR); \
}

#define _INIT_TMODLITBA1(a) {\
	_INIT_ANCHOR_AND_FILE(a.popis); \
	_INIT_ANCHOR_AND_FILE(a.hymnus); \
	_INIT_ANCHOR_AND_FILE(a.antifona1); \
	_INIT_ANCHOR_AND_FILE(a.zalm1); \
	_INIT_ANCHOR_AND_FILE(a.antifona2); \
	_INIT_ANCHOR_AND_FILE(a.zalm2); \
	_INIT_ANCHOR_AND_FILE(a.antifona3); \
	_INIT_ANCHOR_AND_FILE(a.zalm3); \
	_INIT_ANCHOR_AND_FILE(a.kcitanie); \
	_INIT_ANCHOR_AND_FILE(a.kresponz); \
	_INIT_ANCHOR_AND_FILE(a.benediktus); \
	_INIT_ANCHOR_AND_FILE(a.prosby); \
	_INIT_ANCHOR_AND_FILE(a.modlitba); \
};

#define _INIT_TMODLITBA2(a) {\
	_INIT_ANCHOR_AND_FILE(a.popis); \
	_INIT_ANCHOR_AND_FILE(a.hymnus); \
	_INIT_ANCHOR_AND_FILE(a.antifona1); \
	_INIT_ANCHOR_AND_FILE(a.zalm1); \
	_INIT_ANCHOR_AND_FILE(a.antifona2); \
	_INIT_ANCHOR_AND_FILE(a.zalm2); \
	_INIT_ANCHOR_AND_FILE(a.antifona3); \
	_INIT_ANCHOR_AND_FILE(a.zalm3); \
	_INIT_ANCHOR_AND_FILE(a.kcitanie); \
	_INIT_ANCHOR_AND_FILE(a.kresponz); \
	_INIT_ANCHOR_AND_FILE(a.modlitba); \
};

/* 2006-10-11 doplnen� */
#define _INIT_TMODLITBA3(a) {\
	a.pocet_zalmov = 1;\
	_INIT_ANCHOR_AND_FILE(a.popis); \
	_INIT_ANCHOR_AND_FILE(a.hymnus); \
	_INIT_ANCHOR_AND_FILE(a.antifona1); \
	_INIT_ANCHOR_AND_FILE(a.zalm1); \
	_INIT_ANCHOR_AND_FILE(a.antifona2); \
	_INIT_ANCHOR_AND_FILE(a.zalm2); \
	_INIT_ANCHOR_AND_FILE(a.kcitanie); \
	_INIT_ANCHOR_AND_FILE(a.kresponz); \
	_INIT_ANCHOR_AND_FILE(a.modlitba); \
};

/* 2006-10-11 doplnen� */
#define _INIT_TMODLITBA4(a) {\
	_INIT_ANCHOR_AND_FILE(a.popis); \
	_INIT_ANCHOR_AND_FILE(a.antifona1); \
	_INIT_ANCHOR_AND_FILE(a.zalm1); \
};

#define Log_struktura_dm Log("  <dm>"); Log
void Log(_struct_dm g);
#define Log_struktura_rok Log("  <rok>"); Log
void Log(_struct_lrok r);
#define Log_struktura_tm1 Log("  <tm1>"); Log
void Log(struct tmodlitba1);
#define Log_struktura_tm2 Log("  <tm2>"); Log
void Log(struct tmodlitba2);
#define Log_struktura_tm3 Log("  <tm3>"); Log
void Log(struct tmodlitba3);
#define Log_struktura_tm4 Log("  <tm4>"); Log
void Log(struct tmodlitba4);

int _encode_spol_cast(short int, short int, short int);
int _encode_spol_cast(short int, short int);
int _encode_spol_cast(short int);
_struct_sc _decode_spol_cast(int);

extern const char *text_JAN_KRST[];
extern const char *text_POPOLCOVA_STREDA[];
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
extern const char *text_DRUHA_NEDELA_PO_NAR_PANA[];
extern const char *text_PO_POPOLCOVEJ_STREDE[];
extern const char *text_V_OKTAVE_NARODENIA[];

extern const char *text_DEC_08[];
extern const char *text_AUG_15[];
extern const char *text_NOV_01[];

extern const char *text_ZAKONCENIE_SKRZE_dlhe[];
extern const char *text_ZAKONCENIE_SKRZE_kratke[];
extern const char *text_ZAKONCENIE_LEBO_ON_dlhe[];
extern const char *text_ZAKONCENIE_LEBO_ON_kratke[];
extern const char *text_ZAKONCENIE_LEBO_TY_dlhe[];
extern const char *text_ZAKONCENIE_LEBO_TY_kratke[];

extern const char *text_PRO_OP[];

extern const char *html_text_batch_Back[];
extern const char *html_text_batch_Prev[];
extern const char *html_text_batch_Next[];

#endif /* __LITURGIA_H_ */

