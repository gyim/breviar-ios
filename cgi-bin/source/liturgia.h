/***************************************************************/
/*                                                             */
/* liturgia.h                                                  */
/* (c)1999-2005 | Juraj Videky | videky@breviar.sk             */
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
/*   2005-07-27a.D. | pridanÈ nazov_slavenia_lokal[]           */
/*   2005-08-05a.D. | pridanÈ zvazok_OBD[]                     */
/*                                                             */
/*                                                             */
/***************************************************************/

#ifndef __LITURGIA_H_
#define __LITURGIA_H_

#include "mysystem.h"
#include "mydefs.h"
#include "mylog.h"
#include <time.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#define MENO_SVIATKU 100

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
	_struct_anchor_and_file benediktus; /* antifona na benediktus/magnifikat; 2. citanie pre posvatne citanie */
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
	_struct_anchor_and_file hymnus    ;
	_struct_anchor_and_file antifona1 ;
	_struct_anchor_and_file zalm1     ;
	_struct_anchor_and_file antifona2 ;
	_struct_anchor_and_file zalm2     ;
	_struct_anchor_and_file kcitanie  ;
	_struct_anchor_and_file kresponz  ;
	_struct_anchor_and_file nunkdim   ; /* antifona na nunk dimittus */
	_struct_anchor_and_file modlitba  ;
};
typedef struct tmodlitba3 _type_kompletorium;
typedef struct tmodlitba3 _type_1kompletorium;

struct tmodlitba4{
	_struct_anchor_and_file antifona ;
	_struct_anchor_and_file zalm     ;
};
typedef struct tmodlitba4 _type_invitatorium;


struct den_mesiac{ /* takto povodne vyzerala struct dm */
	int den;        /* cislo dna mesiaca (1--31) */
	int mesiac;     /* cislo mesiaca (1--12) */
};
typedef struct den_mesiac _struct_den_mesiac;

#define POCET_MODLITIEB         8
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


/* ... a stringy pre ne */
/* pre modlitbu cez den pridane 2003-07-15 */
/* pre posvatne citanie pridane 2003-08-06 */
#ifdef LONG_PARAM_NAMES
	#define STR_MODL_RANNE_CHVALY "MODL_RANNE_CHVALY"
	#define STR_MODL_POSV_CITANIE "MODL_POSV_CITANIE"
	#define STR_MODL_VESPERY "MODL_VESPERY"
	#define STR_MODL_PREDPOLUDNIM "MODL_PREDPOLUDNIM"
	#define STR_MODL_NAPOLUDNIE "MODL_NAPOLUDNIE"
	#define STR_MODL_POPOLUDNI "MODL_POPOLUDNI"
	#define STR_MODL_DETAILY "MODL_DETAILY"
#else
	#define STR_MODL_RANNE_CHVALY "mrch"
	#define STR_MODL_POSV_CITANIE "mpc"
	#define STR_MODL_VESPERY "mv"
	#define STR_MODL_PREDPOLUDNIM "mpred"
	#define STR_MODL_NAPOLUDNIE "mna"
	#define STR_MODL_POPOLUDNI "mpo"
	#define STR_MODL_DETAILY "*"
#endif

/* 2005-03-27: Vlozene do definicnej casti z funkcie dbzaltar.cpp::pismenko_modlitby() */
#define CHAR_MODL_INVITATORIUM       'i'
#define CHAR_MODL_RANNE_CHVALY       'r'
#define CHAR_MODL_POSV_CITANIE       'c'
#define CHAR_MODL_CEZ_DEN_9          '9'
#define CHAR_MODL_CEZ_DEN_12         '2'
#define CHAR_MODL_CEZ_DEN_3          '3'
#define CHAR_MODL_CEZ_DEN_VSETKY     'd' /* 2005-03-27: Pridane */
#define CHAR_MODL_VESPERY            'v'
#define CHAR_MODL_KOMPLETORIUM       'k'
#define CHAR_MODL_NEURCENA           '_' /* toto by sa nemalo */
#define CHAR_MODL_PRVE_VESPERY       '1'
#define CHAR_MODL_PRVE_KOMPLETORIUM  'p'
#define CHAR_MODL_DRUHE_VESPERY      'w' /* toto by sa nemalo */
#define CHAR_MODL_DRUHE_KOMPLETORIUM 'm' /* toto by sa nemalo */

extern const char *nazov_modlitby[];
extern const char *nazov_Modlitby[];
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

/* dalsie parametre: specificke pre obdobie */
/* Od nedele P·novho zm‡tvychvstania aû do Druhej veækonoËnej nedele vr·tane,
 * ako aj na druhÈ veöpery sl·vnosti Zoslania Ducha Sv‰tÈho */
#define PARAM_ALELUJA_ALELUJA_BEGIN         "ALELUJA_ALELUJA_BEGIN"
#define PARAM_ALELUJA_ALELUJA_END           "ALELUJA_ALELUJA_END"
#define PARAM_ALELUJA_NIE_V_POSTE           "ALELUJA_NIE_V_POSTE"
#define PARAM_ALELUJA_NIE_V_POSTE_BEGIN     "ALELUJA_NIE_V_POSTE_BEGIN"
#define PARAM_ALELUJA_NIE_V_POSTE_END       "ALELUJA_NIE_V_POSTE_END"
#define PARAM_ALELUJA_VO_VELKONOCNOM        "V_O_ALELUJA"
#define PARAM_ALELUJA_VO_VELKONOCNOM_BEGIN  "V_O_ALELUJA_BEGIN"
#define PARAM_ALELUJA_VO_VELKONOCNOM_END    "V_O_ALELUJA_END"
/* 2005-08-15: DoplnenÈ parametre pre voænÈ, inÈ hymny v 34. t˝ûdni OCR */
#define PARAM_HYMNUS_34_OCR_INY_BEGIN       "HYMNUS_34_OCR_INY_BEGIN"
#define PARAM_HYMNUS_34_OCR_INY_END         "HYMNUS_34_OCR_INY_END"
/* nasleduju casti, ktore sa mozu pri generovani modlitby vynechat
 * alebo doplnit podla lubovole */
#define PARAM_OTCENAS_BEGIN                 "OTCENAS_BEGIN"
#define PARAM_OTCENAS_END                   "OTCENAS_END"
#define PARAM_CHVALOSPEV_BEGIN              "CHVALOSPEV_BEGIN"
#define PARAM_CHVALOSPEV_END                "CHVALOSPEV_END"
#define PARAM_ZAKONCENIE_BEGIN              "ZAKONCENIE_BEGIN"
#define PARAM_ZAKONCENIE_END                "ZAKONCENIE_END"

/* stringy parametrov vstupu pre MODL_OPT..., ktore generovanie modlitby
 * ovplyvnuju */
/* option 1 */
#define STR_ANO "·no"
#define STR_NIE "nie"

/* option 2 */
#define MODL_ZALMY_ZO_DNA 0
#define MODL_ZALMY_ZO_SV  1
#define STR_MODL_ZALMY_ZO_DNA "dÚa"
#define STR_MODL_ZALMY_ZO_SV  "sviatku"

/* option 3 -- tieto nasledujuce definicie definuju to, co je sucastou
 * _struct_dm::spolcast */
#define MAX_MODL_SPOL_CAST  26
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
#define MODL_SPOL_CAST_NEBRAT            25 /* nechce zo spol. casti */

/* option 5, 2003-08-06, upravena 2003-08-13 */
#define MODL_CEZ_DEN_ZALMY_ZO_DNA         0
#define MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA  1
#define STR_MODL_CEZ_DEN_ZALMY_ZO_DNA        "beûnej"
#define STR_MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA "doplnkovej"

/* a pre tieto - vyssie uvedene - konstanty aj retazce...
 * -- malo by ich byt do MAX_MODL_SPOL_CAST */
extern const char *nazov_spolc[MODL_SPOL_CAST_NEBRAT + 1];
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
	int a1;
	int a2;
	int a3;
};
typedef struct sc _struct_sc;

/* 2005-07-27: zaveden· nov· premenn· v ötrukt˙re: typslav_lokal
 * urËen· niesù öpeci·lnu inform·ciu o tom, Ëi danÈ sl·venie je lok·lne.
 * ötandardne 0 = bez öpeci·lnej lokaliz·cie.
 */
struct dm{
	int den;        /* cislo dna mesiaca (1--31) */
	int mesiac;     /* cislo mesiaca (1--12) */
	int rok;        /* rok */
	int denvt;      /* cislo dna v tyzdni (0--6) DEN_... */ /* deÚ v roku */
	int denvr;      /* cislo dna v roku (1--365/366) */
	/* toto boli "obcianske" zalezitosti */
	char litrok;    /* liturgicky rok ('A'--'C') */
	int tyzden;     /* tyzden v danom liturgickom obdobi */
	int tyzzal;     /* tyzden v zaltari (vacsinou ((tyzden - 1) % 4) + 1) */
	int litobd;     /* liturgicke obdobie, OBD_... */
	int typslav;    /* typ slavenia (1--5): SLAV_... */
	int typslav_lokal;    /* lok·lny typ slavenia : LOKAL_SLAV_... */
	int smer;       /* poradove cislo z c.59 Vseobecnych smernic
						  * o liturgii hodin a kalendari */
	int prik;       /* ci je to prikazany sviatok alebo nie:
						  * PRIKAZANY_SVIATOK resp. NEPRIKAZANY_SVIATOK */
	int spolcast;   /* spolocna cast -- pridane 09/02/2000A.D.,
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

/* mesiace */
#define MES_JAN 0
#define MES_FEB 1
#define MES_MAR 2
#define MES_APR 3
#define MES_MAY 4
#define MES_JUN 5
#define MES_JUL 6
#define MES_AUG 7
#define MES_SEP 8
#define MES_OCT 9
#define MES_NOV 10
#define MES_DEC 11
/* neznamy mesiac */
#define UNKNOWN_MESIAC 12
/* vsetky mesiace */
#define VSETKY_MESIACE 13
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

/* nazov_obdobia: string pre nazov liturgickeho obdobia */
extern const char *nazov_obdobia[];
extern const char *nazov_obdobia_[];
/* lokal == 6. pad, v kom/com */
extern const char *nazov_obdobia_v[];
extern const char *nazov_OBDOBIA_V[];
/* gen[itiv] == 2. pad, koho/coho */
extern const char *nazov_obdobia_gen[];
/* extern const char *nazov_Obdobia[]; */

/* nazov_obdobia: string pre nazov suboru .htm liturgickeho obdobia */
extern const char *nazov_obd_htm[];
/* nazov_obdobia: string pre nazov kotvy v .htm liturgickeho obdobia */
extern const char *nazov_OBD[];
/* nazov_obdobia pc: string pre nazov suboru .htm liturgickeho obdobia pre posvatne citania */
extern const char *nazov_obd_htm_pc[];
/* 2005-08-05: PridanÈ. zv‰zok brevi·ra (LH) pre spoloËnÈ Ëasti sv‰t˝ch v kotv·ch */
extern const char *zvazok_OBD[];

/* typy slavenia */
#define SLAV_NEURCENE            0
#define SLAV_SLAVNOST            1
#define SLAV_SVIATOK             2
#define SLAV_SPOMIENKA           3
#define SLAV_LUB_SPOMIENKA       4
#define SLAV_VLASTNE             5

/* nazov_slavenia: string pre nazov typu slavenia */
extern const char *nazov_slavenia[];
extern const char *nazov_Slavenia[];
/* 2005-07-27: doplnenÈ */
extern const char *nazov_slavenia_lokal[];

/* 2005-07-27: doplnenÈ lok·lne typy sl·venia */
#define LOKAL_SLAV_NEURCENE            0
#define LOKAL_SLAV_ROZNAVA_KATEDRALA   1
#define LOKAL_SLAV_TRNAVA_PATRON       2
#define LOKAL_SLAV_TT_BB_KE_NR_RO      3
#define LOKAL_SLAV_NITRA_PATRON        4
#define LOKAL_SLAV_KOSICE_POSVIACKA    5

/* prikazany / neprikazany sviatok */
#define PRIKAZANY_SVIATOK 1
#define NEPRIKAZANY_SVIATOK 0

/* div, mod: delenie pre int */
#define DIV	/
#define MOD	%

/* juliansky datum, funkcia juliansky_datum, dane synonymum JD */
#define	JD	juliansky_datum

/* tyzden zaltara (1, 2, 3, 4) podla tyzdna t; 06/03/2000A.D.: namiesto "-1" prerobene na "+3" */
#define  tyzden_zaltara(t)  ((((t) + 3) % 4) + 1)
extern const char *rimskymi_tyzden_zaltara[];

extern const int prvy_den[12];

extern int pocet_dni[12];

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
extern const char *nazov_dna[];
extern const char *nazov_dna_asci[];
extern const char *nazov_Dna[];
extern const char *nazov_DNA[];
extern const char *nazov_Dn[];
extern const char *nazov_DN_asci[];
extern const char *nazov_dn_asci[];

/* nazov_mesiaca: string pre nazov dna; suhlasi s struct tm.tm_mon;
 * Month (0--11) */
extern const char *nazov_mesiaca[];
extern const char *nazov_mesiaca_asci[];
extern const char *nazov_Mesiaca[];
extern const char *nazov_MESIACA[];
extern const char *nazov_MES[];
extern const char *nazov_mes[];

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
	int prestupny;     /* ci je rok prestupny (YES, NO) */
	char p1, p2;       /* nedelne pismeno/pismena;
							  * ak ma rok iba jedno,
							  * druhe p2 == NIJAKE_NEDELNE_PISMENO */
	char litrok;       /* pismeno liturgickeho roka,
							  * ktory zacina prvou adventnou nedelou v roku */
	int tyzden_ocr_po_vn; /* cislo tyzdna obdobia "cez rok", ktory nasleduje po nedeli zoslania
							  * ducha svateho, teda po velkonocnom obdobi */
	int tyzden_ocr_pred_po; /* cislo tyzdna obdobia cez rok, v ktorom zacina post; 15/03/2000A.D. */
	struct dm _den[POCET_ALIASOV];
};
typedef struct lrok _struct_lrok;

#define LINK_DEN_MESIAC_ROK 1
#define LINK_DEN_MESIAC 3
#define LINK_DEN 2
#define LINK_DEN_MESIAC_ROK_PRESTUP 4 /* pridana kvoli prestupnym rokom, 2003-07-02 */
#define LINK_ISO_8601 5 /* pridana kvoli SIMPLE exportu, 2005-03-21 */

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
extern int _global_modlitba;

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
extern int _global_pocet_svatych;

/* globalne premenne, obsahujuce pom_MODL_OPT... */
extern int _global_opt1/* = NIE*/;
extern int _global_opt2/* = MODL_ZALMY_ZO_DNA*/;
extern int _global_opt3;
extern int _global_opt4;

/* globalna premenna, co obsahuje string vypisany na obsazovku */
extern char *_global_string;
/*extern char _global_string[MAX_STR];*/
extern char *_global_string2;
/*extern char _global_string2[MAX_STR];*/ /* obsahuje I, II, III, IV, V alebo pismeno roka */

/* pridane 13/04/2000A.D.; definovane v breviar.cpp */
extern int _global_linky;
/* ------------------------------------------------------------------- */

/* ------------------------------------------------------------------- */
/* tu nasleduju funkcie(), ibaze by som inkludoval "liturgia.cpp" */

int _allocate_global_var(void);
int _deallocate_global_var(void);

int equals(char *, char *);
int equals(const char *, const char *);
int equals(const char *, char *);
int equals(char *, const char *);
int equalsi(char *, char *);
int equalsi(const char *, const char *);
int equalsi(const char *, char *);
int equalsi(char *, const char *);

int cislo_mesiaca(char *mesiac);
char *caps_BIG(const char *input);

/* podla toho, ako sa funkcia vola, urcim case */
#define vytvor_global_link(den, mesiac, rok, typ)	_vytvor_global_link(den, mesiac, rok, CASE_case, typ)
#define Vytvor_global_link(den, mesiac, rok, typ)	_vytvor_global_link(den, mesiac, rok, CASE_Case, typ)
#define VYTVOR_global_link(den, mesiac, rok, typ)	_vytvor_global_link(den, mesiac, rok, CASE_CASE, typ)
void _vytvor_global_link(int den, int mesiac, int rok, int _case, int typ);

int prestupny(int);
int pocet_dni_v_roku(int);
int poradie(int den, int mesiac, int rok);
int poradie(_struct_den_mesiac den_a_mesiac, int rok);
long juliansky_datum(int por, int rok);
long juliansky_datum(int den, int mesiac, int rok);
_struct_den_mesiac velkonocna_nedela(int R);
int _velkonocna_nedela(int rok);
int den_v_tyzdni(int por, int rok);
int den_v_tyzdni(int den, int mesiac, int rok);
int den_v_tyzdni(_struct_den_mesiac den_a_mesiac, int rok);
unsigned char _nedelne_pismeno(int rok);
char nedelne_pismeno(int rok);
unsigned char _nedelne_pismeno(int por, int rok);
char nedelne_pismeno(int por, int rok);
char nedelne_pismeno(int den, int mesiac, int rok);
unsigned char _nedelne_pismeno(int den, int mesiac, int rok);
unsigned char _nedelne_pismeno(_struct_den_mesiac den_a_mesiac, int rok);
char nedelne_pismeno(_struct_den_mesiac den_a_mesiac, int rok);
_struct_den_mesiac por_den_mesiac(int poradie, int rok);
int _svatej_rodiny(int rok);
int _krst_krista_pana(int rok);
int _popolcova_streda(int rok);
int _nanebovstupenie(int rok);
int _zoslanie_ducha(int rok);
int _prva_adventna_nedela(int rok);
_struct_den_mesiac prva_adventna_nedela(int rok);
int nedelny_cyklus(int por, int rok);
int nedelny_cyklus(int den, int mesiac, int rok);
int nedelny_cyklus(_struct_den_mesiac den_a_mesiac, int rok);
_struct_dm por_den_mesiac_dm(int poradie, int rok);
int tyzden_cez_rok_po_vn(int rok);
int cislo_nedele_cez_rok_po_vn(int rok);
void init_global_pm_sobota(void);
void _dm_popolcova_streda(int rok, int _vn);
void _dm_nanebovstupenie(int rok, int _vn);
void _dm_zoslanie_ducha(int rok, int _vn);
void _dm_prva_adventna_nedela(int rok, int p2);
void _dm_svatej_rodiny(int rok);
void _dm_krst_krista_pana(int rok);
void _dm_velkonocna_nedela(int rok, int _vn);

void analyzuj_rok(int year);

/* pridana 2003-08-07 */
/* zapoznamkovana 2003-08-11 */
#undef ZAPOZNAMKOVANE_2003_08_11
#ifdef ZAPOZNAMKOVANE_2003_08_11
void _init_dm(_struct_dm a);
#endif

/* definovany 2003-08-11 na zaklade funkcie _init_dm() */
#define _INIT_DM(a) {\
	a.den = 1;        /* cislo dna mesiaca (1--31) */\
	a.mesiac = 1;     /* cislo mesiaca (1--12) */\
	a.rok = 1900;        /* rok */\
	a.denvt = 0;     /* cislo dna v tyzdni (0--6) DEN_... */ /* deÚ v roku */\
	a.denvr = 1;      /* cislo dna v roku (1--365/366) */\
	a.litrok = 'A';     /* liturgicky rok ('A'--'C') */\
	a.tyzden = 1;     /* tyzden v danom liturgickom obdobi */\
	a.tyzzal = 1;     /* tyzden v zaltari (vacsinou ((tyzden - 1) % 4) + 1) */\
	a.litobd = OBD_VIANOCNE_I;    /* liturgicke obdobie, OBD_... */\
	a.typslav = 1;    /* typ slavenia (1--5): SLAV_... */\
	a.typslav_lokal = 0; /* LOKAL_SLAV_NEURCENE; nie je obmedzenie na lokalitu, pridanÈ 2005-07-27 */\
	a.smer = 100;     /* poradove cislo z c.59 Vseobecnych smernic o liturgii hodin a kalendari */\
	a.prik = PRIKAZANY_SVIATOK;      /* ci je to prikazany sviatok alebo nie: PRIKAZANY_SVIATOK resp. NEPRIKAZANY_SVIATOK */\
	a.spolcast = MODL_SPOL_CAST_NEURCENA;  /* spolocna cast -- zakodovane data pre svatych o tom, z akej spolocnej casti sa ma modlit */\
	mystrcpy(a.meno, STR_UNDEF, MENO_SVIATKU); /* nazov prip. sviatku */\
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

#define Log_struktura_dm Log("  <dm>"); Log
void Log(_struct_dm g);
#define Log_struktura_rok Log("  <rok>"); Log
void Log(_struct_lrok r);
#define Log_struktura_tm1 Log("  <tm1>"); Log
void Log(struct tmodlitba1);
#define Log_struktura_tm2 Log("  <tm2>"); Log
void Log(struct tmodlitba2);

int _encode_spol_cast(int, int, int);
int _encode_spol_cast(int, int);
int _encode_spol_cast(int);
_struct_sc _decode_spol_cast(int);

#endif /* __LITURGIA_H_ */

