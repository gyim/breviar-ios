/***************************************************************/
/*                                                             */
/* breviar.cpp                                                 */
/* (c)1998-2001 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | program tvoriaci stranky pre liturgiu hodin   */
/* document history                                            */
/*   30/01/2000A.D. | trencin, modified                        */
/*   01/02/2000A.D. | bratislava, modified                     */
/*   18/02/2000A.D. | bratislava, modified                     */
/*   25/02/2000A.D. | bratislava, modified                     */
/*   30/03/2000A.D. | premenoval som dnes.cpp na breviar.cpp   */
/*   06/09/2001A.D. | tento popis                              */
/* notes |                                                     */
/*   * ako kompilovat a linkovat?                              */
/*     najdi zarazku KOMPILACIA -- niekde ku koncu             */
/*   * unfinished parts: signed by !!!                         */
/*                                                             */
/***************************************************************/

/* RUN_MODLITBA_CEZ_DEN je definovana v mybase.h */

#include <stdlib.h>
#include <stdio.h>

#include "mybase.h" /* zakladne vecicky */
#include "mystring.h" /* 31/03/2000A.D. */
#include "myconf.h" /* 30/03/2000A.D. */
#include "mysystem.h" /* hovori, ci som v systeme linux/DOS */
#include "liturgia.h"
#include "hodin.h"
#include "cgiutils.h" /* parsovanie query stringu */
#include "mygetopt.h" /* parsovanie argv[], t.j. options z command line */

/* dbzaltar:: zaltar(); liturgicke_obdobie(); sviatky_svatych(); */
#include "dbzaltar.h"
/* povodne tu bolo aj 'dbsvaty.cpp', obsahujuce sviatky_svatych();
 * potom tu bolo "dbzaltar.cpp" a este aj include "sets.c"
 * 22/02/2000A.D.: dal som tam dbzaltar.h a sets.c priamo do dbzaltar.cpp
 */
#include "mydefs.h" /* zakladne #define'y */
#include "mylog.h" /* logovanie udalosti do suboru */
#include "myexpt.h" /* export do suboru alebo na konzolu printf */
#include "myhpage.h" /* hlavicka(); patka(); */

#define MAX_BUFFER 30

#define ANCHOR_VYSVETLIVKY "VYSVETLIVKY"
#define FILE_VYSVETLIVKY "vysvetl.htm"

#define ANCHOR_VYSVETLIVKY_TABULKA "VYSVETL_TABULKA"
#define FILE_VYSVETLIVKY_TABULKA "vysvetlt.htm"

#define UNKNOWN_PORADIE_SVATEHO -1 
/* 28/03/2000A.D.: naschval < 0, aby nebol problem s porovnanim s _global_pocet_svatych v _rozbor_dna() */

#define LOG_ciara Log("---------------------\n");

#ifndef OS_linux
	#include "breviar.h" /* su tam deklarovane nasledovne globalne premenne a main() */
#endif
/* ------------------------------------------------------------------- */
/* globalne premenne -- deklarovane v liturgia.h, definovane tu */
/* 18/02/2000A.D. */

int query_type; /* premenna obsahujuca PRM_..., deklarovana v mydefs.h */

/* globalna premenna, do ktorej sa ukladaju info o analyzovanom dni
 * pouziva ju void nove_rozbor_dna() funkcia */

_struct_dm *_global_den_ptr;
/*_struct_dm _global_den;*/
#define _global_den (*_global_den_ptr)

/* globalne premenne, do ktorych sa ukladaju info o analyzovanom dni
 * o sviatkoch svatych */

_struct_dm *_global_svaty1_ptr;
/*_struct_dm _global_svaty1;*/
#define _global_svaty1 (*_global_svaty1_ptr)

_struct_dm *_global_svaty2_ptr;
/*_struct_dm _global_svaty2;*/ /* v pripade, ze je viac lubovolnych spomienok */
#define _global_svaty2 (*_global_svaty2_ptr)

_struct_dm *_global_svaty3_ptr;
/*_struct_dm _global_svaty3;*/ /* v pripade, ze je viac lubovolnych spomienok */
#define _global_svaty3 (*_global_svaty3_ptr)

/* globalna premenna, ktora obsahuje data o spomienke panny marie v sobotu */

_struct_dm *_global_pm_sobota_ptr;
/*_struct_dm _global_pm_sobota;*/
#define _global_pm_sobota (*_global_pm_sobota_ptr)

/* globalne premenne obsahujuce data modlitbach */

_type_1vespery     *_global_modl_prve_vespery_ptr;
/*_type_1vespery      _global_modl_prve_vespery;*/
#define _global_modl_prve_vespery (*_global_modl_prve_vespery_ptr)

_type_1kompletorium *_global_modl_1kompletorium_ptr;
/*_type_1kompletorium _global_modl_prve_kompletorium;*/
#define _global_modl_prve_kompletorium (*_global_modl_1kompletorium_ptr)

_type_invitatorium *_global_modl_invitatorium_ptr;
/*_type_invitatorium  _global_modl_invitatorium;*/
#define _global_modl_invitatorium (*_global_modl_invitatorium_ptr)

/* _type_posv_citanie  _global_modl_posv_citanie; */

_type_ranne_chvaly *_global_modl_ranne_chvaly_ptr;
/*_type_ranne_chvaly  _global_modl_ranne_chvaly;*/
#define _global_modl_ranne_chvaly (*_global_modl_ranne_chvaly_ptr)

#ifdef RUN_MODLITBA_CEZ_DEN
_type_cez_den_9     *_global_modl_cez_den_9_ptr;
/*_type_cez_den_9     _global_modl_cez_den_9;*/
#define _global_modl_cez_den_9 (*_global_modl_cez_den_9_ptr)
_type_cez_den_12     *_global_modl_cez_den_12_ptr;
/*_type_cez_den_12     _global_modl_cez_den_12;*/
#define _global_modl_cez_den_12 (*_global_modl_cez_den_12_ptr)
_type_cez_den_3     *_global_modl_cez_den_3_ptr;
/*_type_cez_den_3     _global_modl_cez_den_3;*/
#define _global_modl_cez_den_3 (*_global_modl_cez_den_3_ptr)
#endif

_type_vespery      *_global_modl_vespery_ptr;
/*_type_vespery       _global_modl_vespery;*/
#define _global_modl_vespery (*_global_modl_vespery_ptr)

_type_kompletorium *_global_modl_kompletorium_ptr;
/*_type_kompletorium _global_modl_kompletorium;*/
#define _global_modl_kompletorium (*_global_modl_kompletorium_ptr)

/* globalna premenna, ktora obsahuje MODL_... */
int _global_modlitba;

/* globalna premenna, do ktorej ukladaju funkcie vytvor_query_string_...
 * linku tvaru PATH_CGI(script_name) ++ "?param1=val&param2=val&..." */
char *_global_link_ptr;
/*char _global_link[MAX_STR];*/
#define _global_link _global_link_ptr

char *_global_pom_str; /* pomocny string pre velke pismena */
/*char _global_pom_str[MAX_STR];*/

/* globalna premenna, do ktorej sa ukladaju info o jednotlivych
 * vyznacnych liturgickych dni, pouzivaju void _dm_...() funkcie
 * a void analyzuj_rok() funkcia */
_struct_dm *_global_result_ptr;
/*_struct_dm _global_result;*/
#define _global_result (*_global_result_ptr)

/* globalna premenna, do ktorej sa uklada info o liturgickom roku
 * pouziva void analyzuj_rok() funkcia */
_struct_lrok *_global_r_ptr;
/*_struct_lrok _global_r;*/
#define _global_r (*_global_r_ptr)

/* globalna premenna, do ktorej sviatky_svatych() uklada
 * pocet sviatkov (de facto lubovolnych spomienok), ktore
 * pripadaju na dany den
 * -- v podstate neuklada do nej, ale v _rozbor_dna() sa do nej priradi
 * vysledok (navratova hodnota) z sviatky_svatych()
 */
int _global_pocet_svatych;

/* globalne premenne, obsahujuce pom_MODL_OPT... */
int _global_opt1 = NIE;
int _global_opt2 = MODL_ZALMY_ZO_SV;
int _global_opt3;
int _global_opt4 = ANO; /* pridana 05/04/2000A.D. */

/* globalna premenna, co obsahuje string vypisany na obsazovku */
char *_global_string;
/*char _global_string[MAX_STR];*/
char *_global_string2;
/*char _global_string2[MAX_STR];*/ /* obsahuje I, II, III, IV, V alebo pismeno roka */

/* pridane 13/04/2000A.D.; deklarovane v liturgia.h */
int _global_linky;
/* ------------------------------------------------------------------- */


/* ------------------------------------------------------------------- */
/* debuggovacie define'y */

#define DEBUG_GET_FORM 	Log("getForm(): ");Log
#define DEBUG_GET_ARGV	Log("getArgv(): ");Log

/*---------------------------------------------------------------------*/
/* globalne premenne -- pouzite iba tu, v dnes.cpp */

/* globalna premenna, ktora hovori, ci preskakovat <!--{ ... }--> tagy
 * pri preskakovani Magnifikat / Benediktus
 * (ak je _global_opt1 == ANO)
 */
int _global_skip_in_prayer;

/* globalna premenna, ktora hovori, ci generujeme modlitbu */
//int _global_gen_modlitba; == (_global_modlitba == MODL_NEURCENA)

int params; /* odkial su brane parametre; hodnoty
 * SCRIPT_PARAM_FROM_FORM
 * SCRIPT_PARAM_FROM_ARGV
 * SCRIPT_PARAM_FROM_QS
 */
char *query_string; /* QUERY_STRING environment variable */

char pom_QUERY_TYPE [MAX_POM_QUERY_TYPE] = ""; /* typ dotazu, retazec */
char pom_DEN        [SMALL] = ""; /* sluzi aj ako pom_DEN_V_TYZDNI a pom_SVIATOK */
#define pom_DEN_V_TYZDNI	pom_DEN
#define pom_SVIATOK			pom_DEN
char pom_MESIAC     [SMALL] = ""; /* sluzi aj ako pom_TYZDEN */
#define pom_TYZDEN		pom_MESIAC
char pom_ROK        [SMALL] = ""; /* sluzi aj ako pom_ANALYZA_ROKU */
#define pom_ANALYZA_ROKU	pom_ROK
char pom_MODLITBA   [SMALL] = "";
char pom_MODL_OPT1  [SMALL] = "";
char pom_MODL_OPT2  [SMALL] = "";
char pom_MODL_OPT3  [SMALL] = "";
char pom_MODL_OPT4  [SMALL] = "";
char pom_DALSI_SVATY[SMALL] = "";
/* tieto dalsie 3 pridane kvoli PRM_TABULKA, 15/03/2000A.D. */
char pom_ROK_FROM   [SMALL] = "";
char pom_ROK_TO     [SMALL] = "";
/* pom_LINKY sa povodne volala pom_TABULKA_LINKY, avsak 
 * pouzivame ju vo win32-release ako indikator, ci zobrazovat linky vseobecne,
 * alebo iba "akoze"-odkazy, ako mi poradil Miro M. a aj Matko Bk
 * 13/04/2000A.D. 
 */
char pom_LINKY[SMALL] = "";

char bad_param_str[MAX_STR];

urlvariable param[MAX_VARIABLES];
/* struktura oznacujuca dvojice <meno, hodnota> z query stringu,
 * napr. QUERY_STRING=QUERY_TYPE=PRM_DATUM&DEN=7&MESIAC=5&ROK=1976...
 * je to i-tica (tuple)
 *
 * <WWW_QUERY_TYPE, PRM_DATUM>,
 * <WWW_DEN, 7>,
 * <WWW_MESIAC, 5>,
 * <WWW_ROK, 1976>,
 * <WWW_MODLITBA, ...>
 *
 */

#define EMPTY_STR empty_str
char empty_str[6] = "ˇNULL";

char file_export[SMALL] = ""; /* nazov suboru, do ktoreho sa mozno exportuje
										 * v pripade pouzitia switchu `e' pri getArgv();
										 * pridane 13/03/2000A.D. */

/* nasledovna pasaz pridana 05/06/2000A.D., a to pre 
 * pridany parameter `i' (include directory) */
/* deklarovane pre OS_Windows v mydefs.h */
#ifdef OS_Windows
	char FILE_PATH[MAX_STR] = "include\\";
#endif
char include_dir[MAX_STR] = "";

/*---------------------------------------------------------------------*/
/* popis: odstrani backslashe zo stringu (argv[1]) a vrati novy string
 * ale NEVRATI novy string
 *
 */
int odstran_backslashe(char *input){
	int i, j = 0;
	int ilen;
	ilen = strlen(input);
	for(i = 0; i < ilen; i++){
		if(input[i] != '\\'){
			input[j] = input[i];
			j++;
		}
	}
	input[j] = '\0';
	return 0;
}

/*---------------------------------------------------------------------*/
/* popis: zisti, odkial sa citaju argumenty (vstupy);
 * vracia:
 *
 * 	SCRIPT_PARAM_FROM_FORM (z formulara, t.j. syst. premennych WWW_...)
 * 	SCRIPT_PARAM_FROM_ARGV (z argumentov dialogoveho riadka)
 * 	SCRIPT_PARAM_FROM_QS   (zo systemovej premennej QUERY_STRING)
 */
int getSrciptParamFrom(int argc){

	/* najprv zistime, ci existuje systemova premenna QUERY_STRING */
	char *qs;
	/* kedze na zaciatku main() alokujeme pre `query_string' miesto,
	 * musime tu spravit nie
	 *   query_string = getenv("QUERY_STRING");
	 * (vtedy by na konci free(query_string) urobil blbost zrejme, lebo
	 *  query_string uz neukazuje na alokovane miesto, ale na nieco, kde
	 *  vratila funkcia getenv() hodnotu -- a mozno to ani neexistuje...)
	 * ale
	 *   mystrcpy(query_string, getenv("QUERY_STRING"));
	 * 25/02/2000A.D.
	 */
	qs = getenv("QUERY_STRING");
	if(qs != NULL)
		mystrcpy(query_string, qs, MAX_QUERY_STR);
	else
		mystrcpy(query_string, "", MAX_QUERY_STR);

	if(query_string != NULL)
		Log("query_string == %s\n", query_string);
	else
		Log("query_string is NULL\n");
	/* systemova premenna QUERY_STRING existuje prave vtedy,
	 * ked query_string nie je prazdny retazec */
	if((query_string != NULL) && (strlen(query_string) > 0)){
		/* existuje, teda budeme pekne parsovat */
		Log("returning SCRIPT_PARAM_FROM_QS.\n");
		return SCRIPT_PARAM_FROM_QS;
	}
	else if(argc == 1){
		/* query_string bud neexistuje alebo je "",
		 * pritom program nema vstupne argumenty (z dial. riadka) */
		Log("returning SCRIPT_PARAM_FROM_FORM (argc == %d).\n", argc);
		return SCRIPT_PARAM_FROM_FORM;
	}
	else{/* program ma vstupne argumenty, argc > 1 */
		Log("returning SCRIPT_PARAM_FROM_ARGV -- nothing else matched.\n");
		return SCRIPT_PARAM_FROM_ARGV;
	}
}/* getSrciptParamFrom(); */

#define _export_heading1(a)	_export_heading(1, a)
#define _export_heading2(a)	_export_heading(2, a)
#define _export_heading3(a)	_export_heading(3, a)
/*---------------------------------------------------------------------*/
/*
 * _export_heading();
 *
 * exportuje heading velkosti size;
 *
 */
void _export_heading(int size, const char *string){
	Export("\n<center><h%d>%s</h%d></center>\n", size, string, size);
}


/*---------------------------------------------------------------------*/
/*
 * _main_prazdny_formular();
 *
 * vypise hlasky o tom, ze je prazdny formular resp. skript bol spusteny
 * bez vstupnych hodnot
 *
 * historicka poznamka: kedysi sa vtedy volala procedura dnes();
 * potom prazdny_formular(); a napokon sa _main_dnes(); vola az pri PRM_DNES
 *
 */
void _main_prazdny_formular(void){
	Export("Programu neboli zadanÈ argumenty.\n");
	ALERT;
}

/*---------------------------------------------------------------------*/
/* nasleduje pasaz, ktora bola povodne v lithod.[h|cpp]

/*---------------------------------------------------------------------*/
/* includeFile():
 *
 * podla parametra paramname (PARAM_...)
 * 
 */
#define DetailLog emptyLog
void includeFile(int type, char *paramname, char *fname, char *modlparam){
	int c, buff_index = 0; /* 01/03/2000A.D. - inicializacia buff_index */
	char strbuff[MAX_BUFFER];
	char rest[MAX_BUFFER];
	char isbuff = 0;
	char write = 0;
	char vnutri_inkludovaneho = 0;
	/* 17/02/2000A.D., kvoli "V.O. Aleluja" v inkludovanych napr. antifonach */

	Log("--includeFile(%d, %s, %s, %s): begin,\n",
		type, paramname, fname, modlparam);

	FILE *body = fopen(fname, "r");

	Log("  replacing {%s} with %s from file `%s':\n",
		paramname, modlparam, fname);
	if(body == NULL){
		/*printf("error `%s'\n", sys_errlist[errno]);*/
		Log("  file `%s' not found\n", fname);
#if defined(OS_DOS)
		Export("file %s not found", fname);
#elif defined(OS_Windows)
		Export("file %s not found", fname);
#elif defined(OS_linux)
		Export("file not found");
#endif
		Log("--includeFile(): end (because of no body)\n");
		return;
	}
	while((c = fgetc(body)) != EOF){
		switch (c){
			case CHAR_KEYWORD_BEGIN:
				isbuff= 1;
				buff_index = 0;
				continue;
			case CHAR_KEYWORD_END:
				isbuff = 0;
				strbuff[buff_index] = '\0';
				DetailLog("\nFile %s, \n\tparam {%s} found\n", fname, strbuff);
				mystrcpy(rest, strbuff, MAX_BUFFER);
				splitword(strbuff, rest, CHAR_KEYWORD_DIVIDER);
				DetailLog("\tstrbuff  == %s\n", strbuff);
				DetailLog("\trest     == %s\n", rest);
				DetailLog("\tmodlparam== %s\n", modlparam);
				if(equalsi(rest, modlparam)){
					if(equals(strbuff, INCLUDE_BEGIN)){
						write = 1;
						vnutri_inkludovaneho = 1;
#if defined(OS_DOS)
						Export("begin of %s, anchor %s", fname, modlparam);
#elif defined(OS_Windows)
						Export("BEGIN:%s", modlparam);
#elif defined(OS_linux)
						Export("BEGIN:%s", modlparam);
#endif
						Log("  begin of %s in `%s'\n", modlparam, fname);
					}
					else if(equals(strbuff, INCLUDE_END)){
						write = 0;
						vnutri_inkludovaneho = 0;
#if defined(OS_DOS)
						Export("end of %s, anchor %s", fname, modlparam);
#elif defined(OS_Windows)
						Export("END:%s", modlparam);
#elif defined(OS_linux)
						Export("END:%s", modlparam);
#endif
						Log("  end of %s in `%s'\n", modlparam, fname);
					}
				}
				else{
					/* write = 0; -- aby mohli byt nestovane viacere :-) */
					DetailLog("paramenter not matches: %s != %s\n", rest, modlparam);
					if(((_global_den.litobd != OBD_VELKONOCNE_I) && (_global_den.litobd != OBD_VELKONOCNE_II)) &&
						(equals(rest, PARAM_ALELUJA_VO_VELKONOCNOM))){
						if(equals(strbuff, INCLUDE_BEGIN) && (vnutri_inkludovaneho == 1)){
							write = 0;
							Log("  rusim writing to export file, kvoli V.O. Aleluja...\n");
						}
						else if(equals(strbuff, INCLUDE_END) && (vnutri_inkludovaneho == 1)){
							Export("nie je velkonocne obdobie");
							write = 1;
							Log("  opat writing to export file, end of V.O. Aleluja.\n");
						}
					}/* aleluja vo velkonocnom obdobi */
				}
				continue;
		}
		if(!isbuff){
			if(write){
				Export("%c", c); /* fputc(c, exportfile); */
				DetailLog("%c", c);
			}
			else ; //skip
		}
		else strbuff[buff_index++] = c;
	}
	fclose(body);
	Log("--includeFile(): end\n");
}

/*---------------------------------------------------------------------*/
/* interpretParameter():
 *
 * dostane vstup to, co sa pri parsovani templatu nachadza medzi znakmi
 * CHAR_KEYWORD_BEGIN a CHAR_KEYWORD_END;
 * zrejme ide o parameter;
 * podla neho inkluduje subor (alebo cast suboru)
 *
 * 27/04/2000A.D.: pozmenene (pridane #definy):
 *    - je_post(): odpoved je kladna, ak je niektore z nasledujucich
 *                 * OBD_POSTNE_I
 *                 * OBD_POSTNE_II_VELKY_TYZDEN
 *                 * OBD_VELKONOCNE_TROJDNIE && (den == piatok || sobota)
 *    - je_velka_noc(): odpoved je kladna, ak je niektore z nasledujucich
 *                 * OBD_VELKONOCNE_I
 *                 * OBD_VELKONOCNE_II
 *                 * OBD_VELKONOCNE_TROJDNIE && (den == nedela)
 *    - je_aleluja_aleluja(): odpoved je kladna, ak je splnene niektore z nasledovnych
 *                 * OBD_VELKONOCNA_OKTAVA
 *                 * OBD_VELKONOCNE_TROJDNIE && (den == nedela)
 *                 * _ZOSLANIE_DUCHA_SV && MODL_VESPERY
 */
#define je_post ((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN) || ((_global_den.litobd == OBD_VELKONOCNE_TROJDNIE) && ((_global_den.denvt == DEN_PIATOK) || (_global_den.denvt == DEN_SOBOTA))))
#define je_velka_noc ((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II) || ((_global_den.litobd == OBD_VELKONOCNE_TROJDNIE) && (_global_den.denvt == DEN_NEDELA)))
#define je_aleluja_aleluja ((_global_den.litobd == OBD_VELKONOCNA_OKTAVA) || ((_global_den.litobd == OBD_VELKONOCNE_TROJDNIE) && (_global_den.denvt == DEN_NEDELA)) || (equals(_global_den.meno, _global_r._ZOSLANIE_DUCHA_SV.meno) && (_global_modlitba == MODL_VESPERY)))
void interpretParameter(int type, char *paramname){
	char path[MAX_STR] = "";
	mystrcpy(path, include_dir, MAX_STR);
	strcat(path, FILE_PATH); /* prerobene 05/06/2000A.D. */

	Log("interpretParameter(%s): Dumping by %s\n",
		paramname, paramname);
	if(equals(paramname, PARAM_ALELUJA_NIE_V_POSTE_BEGIN)){
		if(!je_post){
			Export("nie je postne obdobie-->");
		}
	}
	else if(equals(paramname, PARAM_ALELUJA_NIE_V_POSTE_END)){
		if(!je_post){
			Export("<!--nie je postne obdobie");
		}
	}
	else if(equals(paramname, PARAM_ALELUJA_VO_VELKONOCNOM_BEGIN)){
		if(!je_velka_noc){
			Export("nie je velkonocne obdobie-->");
		}
	}
	else if(equals(paramname, PARAM_ALELUJA_VO_VELKONOCNOM_END)){
		if(!je_velka_noc){
			Export("<!--nie je velkonocne obdobie");
		}
	}
	else if(equals(paramname, PARAM_ALELUJA_ALELUJA_BEGIN)){
		if(_global_skip_in_prayer == ANO){
			/* ak zakoncenie preskakujem, tak musim sa tvarit, ze nic */
			Export("{AAB:skip}");
			Log("  ALELUJA_ALELUJA_BEGIN: skipping -- because skipping ZAKONCENIE\n");
		}
		else{
			/* Od nedele P†novho zmrtvychvstania aß do Druhej velkonocnej nedele
			 * vr†tane, ako aj na druhÇ veÁpery sl†vnosti Zoslania Ducha SvÑtÇho */
			if(je_aleluja_aleluja){
				Export("velkonocna oktava-->");
				Log("  ALELUJA_ALELUJA_BEGIN: copying\n");
			}
			else{
				Log("  ALELUJA_ALELUJA_BEGIN: skipping -- because not velkonocna oktava\n");
			}
		}
	}
	else if(equals(paramname, PARAM_ALELUJA_ALELUJA_END)){
		if(_global_skip_in_prayer == ANO){
			/* ak zakoncenie preskakujem, tak musim sa tvarit, ze nic */
			/* preto otvorim poznamku, ktora sa zacala */
			Export("{AAE:skip}");
			Log("  ALELUJA_ALELUJA_END: skipping -- because skipping ZAKONCENIE\n");
		}
		else{
			/* Od nedele Panovho zmrtvychvstania az do Druhej velkonocnej nedele
			 * vratane, ako aj na druhe vespery slavnosti Zoslania Ducha Svateho */
			if(je_aleluja_aleluja){
				Export("<!--velkonocna oktava");
				Log("  ALELUJA_ALELUJA_END: copying\n");
			}
			else{
				Log("  ALELUJA_ALELUJA_END: skipping -- because not velkonocna oktava\n");
			}
		}
	}
	/* teraz nasleduje kontrola opt1...opt3 (options pre modlitbu) */
	/* najprv co sa tyka option1:
	 * ide o vynechanie Magnifikat/Benediktus, pozehnania, Otcenasa */
	else if(equals(paramname, PARAM_OTCENAS_BEGIN)){
		if(_global_opt1 == ANO){
			/* zobrazit Otcenas */
			Export("zobrazit Otcenas-->");
			Log("  `Otcenas': begin...\n");
		}
		else{
			/* nezobrazovat Otcenas */
			_global_skip_in_prayer = ANO;
			Export("nezobrazit Otcenas");
			Log("  `Otcenas' skipping...\n");
		}
	}
	else if(equals(paramname, PARAM_OTCENAS_END)){
		if(_global_opt1 == ANO){
			/* zobrazit Otcenas */
			Export("<!--zobrazit Otcenas");
			Log("  `Otcenas': copied.\n");
		}
		else{
			/* nezobrazovat Otcenas */
			_global_skip_in_prayer = NIE;
			Log("  `Otcenas' skipped.\n");
		}
	}
	else if(equals(paramname, PARAM_CHVALOSPEV_BEGIN)){
		if(_global_opt1 == NIE){
			/* nezobrazovat Benediktus/Magnifikat */
			_global_skip_in_prayer = ANO;
			Export("nezobrazit Benediktus/Magnifikat");
			Log("  `Benediktus/Magnifikat' skipping...\n");
		}
		else{
			Export("zobrazit Benediktus/Magnifikat");
			Log("  `Benediktus/Magnifikat': begin...\n");
		}
	}
	else if(equals(paramname, PARAM_CHVALOSPEV_END)){
		if(_global_opt1 == NIE){
			/* nezobrazovat Benediktus/Magnifikat */
			_global_skip_in_prayer = NIE;
			Log("  `Benediktus/Magnifikat' skipped.\n");
		}
		else{
			Export("zobrazit Benediktus/Magnifikat");
			Log("  `Benediktus/Magnifikat' copied.\n");
		}
	}
	else if(equals(paramname, PARAM_ZAKONCENIE_BEGIN)){
		if(_global_opt1 == NIE){
			/* nezobrazit zakoncenie */
			_global_skip_in_prayer = ANO;
			Export("nezobrazit zakoncenie");
			Log("  `zakoncenie' skipping...\n");
		}
		else{
			Export("zobrazit zakoncenie-->");
			Log("  `zakoncenie': begin...\n");
		}
	}
	else if(equals(paramname, PARAM_ZAKONCENIE_END)){
		if(_global_opt1 == NIE){
			/* nezobrazit zakoncenie */
			_global_skip_in_prayer = NIE;
			Log("  `zakoncenie' skipped.\n");
		}
		else{
			Export("<!--zobrazit zakoncenie");
			Log("  `zakoncenie' copied.\n");
		}
	}
	/* pokracuju dalsie klasicke `tagy' v modlitbach (teda templatoch) */
	else if(equals(paramname, PARAM_POPIS)){
		/* pridane 05/04/2000A.D. */
		Log("  _global_opt4 == %d: ", _global_opt4);
		if(_global_opt4 == ANO){
			Log("including POPIS\n");
			switch(type){
				case MODL_RANNE_CHVALY:
					strcat(path, _global_modl_ranne_chvaly.popis.file);
					includeFile(type, paramname, path, _global_modl_ranne_chvaly.popis.anchor);
					break;
				case MODL_VESPERY:
					strcat(path, _global_modl_vespery.popis.file);
					includeFile(type, paramname, path, _global_modl_vespery.popis.anchor);
					break;
				default:
					/* tieto modlitby nemaju popis */
					break;
			}/* switch */
		}
		else{
			Export("skipping POPIS");
			Log("skipping POPIS\n");
		}
	}/* PARAM_POPIS */
	else if(equals(paramname, PARAM_HYMNUS)){
		switch(type){
			case MODL_RANNE_CHVALY:
				strcat(path, _global_modl_ranne_chvaly.hymnus.file);
				includeFile(type, paramname, path, _global_modl_ranne_chvaly.hymnus.anchor);
				break;
#ifdef RUN_MODLITBA_CEZ_DEN
			case MODL_CEZ_DEN_9:
				strcat(path, _global_modl_cez_den_9.hymnus.file);
				includeFile(type, paramname, path, _global_modl_cez_den_9.hymnus.anchor);
				break;
			case MODL_CEZ_DEN_12:
				strcat(path, _global_modl_cez_den_12.hymnus.file);
				includeFile(type, paramname, path, _global_modl_cez_den_12.hymnus.anchor);
				break;
			case MODL_CEZ_DEN_3:
				strcat(path, _global_modl_cez_den_3.hymnus.file);
				includeFile(type, paramname, path, _global_modl_cez_den_3.hymnus.anchor);
				break;
#endif
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.hymnus.file);
				includeFile(type, paramname, path, _global_modl_vespery.hymnus.anchor);
				break;
			default:
				/* tieto modlitby nemaju hymnus */
				break;
		}/* switch */
	}/* PARAM_HYMNUS */
	else if(equals(paramname, PARAM_ANTIFONA1)){
		switch(type){
			case MODL_INVITATORIUM:
				strcat(path, _global_modl_invitatorium.antifona.file);
				includeFile(type, paramname, path, _global_modl_invitatorium.antifona.anchor);
				break;
			case MODL_RANNE_CHVALY:
				strcat(path, _global_modl_ranne_chvaly.antifona1.file);
				includeFile(type, paramname, path, _global_modl_ranne_chvaly.antifona1.anchor);
				break;
#ifdef RUN_MODLITBA_CEZ_DEN
			case MODL_CEZ_DEN_9:
				strcat(path, _global_modl_cez_den_9.antifona1.file);
				includeFile(type, paramname, path, _global_modl_cez_den_9.antifona1.anchor);
				break;
			case MODL_CEZ_DEN_12:
				strcat(path, _global_modl_cez_den_12.antifona1.file);
				includeFile(type, paramname, path, _global_modl_cez_den_12.antifona1.anchor);
				break;
			case MODL_CEZ_DEN_3:
				strcat(path, _global_modl_cez_den_3.antifona1.file);
				includeFile(type, paramname, path, _global_modl_cez_den_3.antifona1.anchor);
				break;
#endif
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.antifona1.file);
				includeFile(type, paramname, path, _global_modl_vespery.antifona1.anchor);
				break;
			case MODL_KOMPLETORIUM:
				strcat(path, _global_modl_kompletorium.antifona1.file);
				includeFile(type, paramname, path, _global_modl_kompletorium.antifona1.anchor);
				break;
			default:
				/* tieto modlitby nemaju antifonu1 */
				break;
		}/* switch */
	}/* PARAM_ANTIFONA1 */
	else if(equals(paramname, PARAM_ANTIFONA2)){
		switch(type){
/*			case MODL_RANNE_CHVALY:
				strcat(path, _global_modl_ranne_chvaly.antifona2.file);
				includeFile(type, paramname, path, _global_modl_ranne_chvaly.antifona2.anchor);
				break;
*/
#ifdef RUN_MODLITBA_CEZ_DEN
			case MODL_CEZ_DEN_9:
				strcat(path, _global_modl_cez_den_9.antifona2.file);
				includeFile(type, paramname, path, _global_modl_cez_den_9.antifona2.anchor);
				break;
			case MODL_CEZ_DEN_12:
				strcat(path, _global_modl_cez_den_12.antifona2.file);
				includeFile(type, paramname, path, _global_modl_cez_den_12.antifona2.anchor);
				break;
			case MODL_CEZ_DEN_3:
				strcat(path, _global_modl_cez_den_3.antifona2.file);
				includeFile(type, paramname, path, _global_modl_cez_den_3.antifona2.anchor);
				break;
#endif
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.antifona2.file);
				includeFile(type, paramname, path, _global_modl_vespery.antifona2.anchor);
				break;
			default:
				/* tieto modlitby nemaju antifonu2 */
				break;
		}/* switch */
	}/* PARAM_ANTIFONA2 */
	else if(equals(paramname, PARAM_ANTIFONA3)){
		switch(type){
			case MODL_RANNE_CHVALY:
				strcat(path, _global_modl_ranne_chvaly.antifona3.file);
				includeFile(type, paramname, path, _global_modl_ranne_chvaly.antifona3.anchor);
				break;
#ifdef RUN_MODLITBA_CEZ_DEN
			case MODL_CEZ_DEN_9:
				strcat(path, _global_modl_cez_den_9.antifona3.file);
				includeFile(type, paramname, path, _global_modl_cez_den_9.antifona3.anchor);
				break;
			case MODL_CEZ_DEN_12:
				strcat(path, _global_modl_cez_den_12.antifona3.file);
				includeFile(type, paramname, path, _global_modl_cez_den_12.antifona3.anchor);
				break;
			case MODL_CEZ_DEN_3:
				strcat(path, _global_modl_cez_den_3.antifona3.file);
				includeFile(type, paramname, path, _global_modl_cez_den_3.antifona3.anchor);
				break;
#endif
/*			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.antifona3.file);
				includeFile(type, paramname, path, _global_modl_vespery.antifona3.anchor);
				break;
*/
			default:
				/* tieto modlitby nemaju antifonu3 */
				break;
		}/* switch */
	}/* PARAM_ANTIFONA3 */
	else if(equals(paramname, PARAM_ZALM1)){
		switch(type){
			case MODL_INVITATORIUM:
				strcat(path, _global_modl_invitatorium.zalm.file);
				includeFile(type, paramname, path, _global_modl_invitatorium.zalm.anchor);
				break;
			case MODL_RANNE_CHVALY:
				strcat(path, _global_modl_ranne_chvaly.zalm1.file);
				includeFile(type, paramname, path, _global_modl_ranne_chvaly.zalm1.anchor);
				break;
#ifdef RUN_MODLITBA_CEZ_DEN
			case MODL_CEZ_DEN_9:
				strcat(path, _global_modl_cez_den_9.zalm1.file);
				includeFile(type, paramname, path, _global_modl_cez_den_9.zalm1.anchor);
				break;
			case MODL_CEZ_DEN_12:
				strcat(path, _global_modl_cez_den_12.zalm1.file);
				includeFile(type, paramname, path, _global_modl_cez_den_12.zalm1.anchor);
				break;
			case MODL_CEZ_DEN_3:
				strcat(path, _global_modl_cez_den_3.zalm1.file);
				includeFile(type, paramname, path, _global_modl_cez_den_3.zalm1.anchor);
				break;
#endif
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.zalm1.file);
				includeFile(type, paramname, path, _global_modl_vespery.zalm1.anchor);
				break;
			case MODL_KOMPLETORIUM:
				strcat(path, _global_modl_kompletorium.zalm1.file);
				includeFile(type, paramname, path, _global_modl_kompletorium.zalm1.anchor);
				break;
			default:
				/* tieto modlitby nemaju zalm1 */
				break;
		}/* switch */
	}/* PARAM_ZALM1 */
	else if(equals(paramname, PARAM_ZALM2)){
		switch(type){
/*			case MODL_RANNE_CHVALY:
				strcat(path, _global_modl_ranne_chvaly.zalm2.file);
				includeFile(type, paramname, path, _global_modl_ranne_chvaly.zalm2.anchor);
				break;
*/
#ifdef RUN_MODLITBA_CEZ_DEN
			case MODL_CEZ_DEN_9:
				strcat(path, _global_modl_cez_den_9.zalm2.file);
				includeFile(type, paramname, path, _global_modl_cez_den_9.zalm2.anchor);
				break;
			case MODL_CEZ_DEN_12:
				strcat(path, _global_modl_cez_den_12.zalm2.file);
				includeFile(type, paramname, path, _global_modl_cez_den_12.zalm2.anchor);
				break;
			case MODL_CEZ_DEN_3:
				strcat(path, _global_modl_cez_den_3.zalm2.file);
				includeFile(type, paramname, path, _global_modl_cez_den_3.zalm2.anchor);
				break;
#endif
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.zalm2.file);
				includeFile(type, paramname, path, _global_modl_vespery.zalm2.anchor);
				break;
			default:
				/* tieto modlitby nemaju zalm2 */
				break;
		}/* switch */
	}/* PARAM_ZALM2 */
	else if(equals(paramname, PARAM_ZALM3)){
		switch(type){
			case MODL_RANNE_CHVALY:
				strcat(path, _global_modl_ranne_chvaly.zalm3.file);
				includeFile(type, paramname, path, _global_modl_ranne_chvaly.zalm3.anchor);
				break;
#ifdef RUN_MODLITBA_CEZ_DEN
			case MODL_CEZ_DEN_9:
				strcat(path, _global_modl_cez_den_9.zalm3.file);
				includeFile(type, paramname, path, _global_modl_cez_den_9.zalm3.anchor);
				break;
			case MODL_CEZ_DEN_12:
				strcat(path, _global_modl_cez_den_12.zalm3.file);
				includeFile(type, paramname, path, _global_modl_cez_den_12.zalm3.anchor);
				break;
			case MODL_CEZ_DEN_3:
				strcat(path, _global_modl_cez_den_3.zalm3.file);
				includeFile(type, paramname, path, _global_modl_cez_den_3.zalm3.anchor);
				break;
#endif
/*			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.zalm3.file);
				includeFile(type, paramname, path, _global_modl_vespery.zalm3.anchor);
				break;
*/
			default:
				/* tieto modlitby nemaju zalm3 */
				break;
		}/* switch */
	}/* PARAM_ZALM3 */
	else if(equals(paramname, PARAM_KCITANIE)){
		switch(type){
			case MODL_RANNE_CHVALY:
				strcat(path, _global_modl_ranne_chvaly.kcitanie.file);
				includeFile(type, paramname, path, _global_modl_ranne_chvaly.kcitanie.anchor);
				break;
#ifdef RUN_MODLITBA_CEZ_DEN
			case MODL_CEZ_DEN_9:
				strcat(path, _global_modl_cez_den_9.kcitanie.file);
				includeFile(type, paramname, path, _global_modl_cez_den_9.kcitanie.anchor);
				break;
			case MODL_CEZ_DEN_12:
				strcat(path, _global_modl_cez_den_12.kcitanie.file);
				includeFile(type, paramname, path, _global_modl_cez_den_12.kcitanie.anchor);
				break;
			case MODL_CEZ_DEN_3:
				strcat(path, _global_modl_cez_den_3.kcitanie.file);
				includeFile(type, paramname, path, _global_modl_cez_den_3.kcitanie.anchor);
				break;
#endif
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.kcitanie.file);
				includeFile(type, paramname, path, _global_modl_vespery.kcitanie.anchor);
				break;
			case MODL_KOMPLETORIUM:
				strcat(path, _global_modl_kompletorium.kcitanie.file);
				includeFile(type, paramname, path, _global_modl_kompletorium.kcitanie.anchor);
				break;
			default:
				/* tieto modlitby nemaju kcitanie */
				break;
		}/* switch */
	}/* PARAM_KCITANIE */
	else if(equals(paramname, PARAM_KRESPONZ)){
		switch(type){
			case MODL_RANNE_CHVALY:
				strcat(path, _global_modl_ranne_chvaly.kresponz.file);
				includeFile(type, paramname, path, _global_modl_ranne_chvaly.kresponz.anchor);
				break;
#ifdef RUN_MODLITBA_CEZ_DEN
			case MODL_CEZ_DEN_9:
				strcat(path, _global_modl_cez_den_9.kresponz.file);
				includeFile(type, paramname, path, _global_modl_cez_den_9.kresponz.anchor);
				break;
			case MODL_CEZ_DEN_12:
				strcat(path, _global_modl_cez_den_12.kresponz.file);
				includeFile(type, paramname, path, _global_modl_cez_den_12.kresponz.anchor);
				break;
			case MODL_CEZ_DEN_3:
				strcat(path, _global_modl_cez_den_3.kresponz.file);
				includeFile(type, paramname, path, _global_modl_cez_den_3.kresponz.anchor);
				break;
#endif
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.kresponz.file);
				includeFile(type, paramname, path, _global_modl_vespery.kresponz.anchor);
				break;
			case MODL_KOMPLETORIUM:
				strcat(path, _global_modl_kompletorium.kresponz.file);
				includeFile(type, paramname, path, _global_modl_kompletorium.kresponz.anchor);
				break;
			default:
				/* tieto modlitby nemaju kresponz */
				break;
		}/* switch */
	}/* PARAM_KRESPONZ */
	else if(equals(paramname, PARAM_MAGNIFIKAT)){
		/* ak _global_skip_in_prayer je ANO, tak preskoc Magnifikat */
		if((type == MODL_VESPERY) && (_global_skip_in_prayer != ANO)){
			strcat(path, _global_modl_vespery.magnifikat.file);
			includeFile(type, paramname, path, _global_modl_vespery.magnifikat.anchor);
		}
		else /* ostatne modlitby magnifikat nemaju */
		;
	}/* PARAM_MAGNIFIKAT */
	else if(equals(paramname, PARAM_ANTVCHVAL)){
		if(type == MODL_VESPERY){
			strcat(path, _global_modl_vespery.antifona3.file);
			includeFile(type, paramname, path, _global_modl_vespery.antifona3.anchor);
		}
		else /* ostatne modlitby nemaju vecerny chvalospev */
		;
	}/* PARAM_ANTVCHVAL */
	else if(equals(paramname, PARAM_VCHVALOSPEV)){
		if(type == MODL_VESPERY){
			strcat(path, _global_modl_vespery.zalm3.file);
			includeFile(type, paramname, path, _global_modl_vespery.zalm3.anchor);
		}
		else /* ostatne modlitby nemaju vecerny chvalospev */
		;
	}/* PARAM_VCHVALOSPEV */
	else if(equals(paramname, PARAM_BENEDIKTUS)){
		/* ak _global_skip_in_prayer je ANO, tak preskoc Benediktus */
		if((type == MODL_RANNE_CHVALY) && (_global_skip_in_prayer != ANO)){
			strcat(path, _global_modl_ranne_chvaly.benediktus.file);
			includeFile(type, paramname, path, _global_modl_ranne_chvaly.benediktus.anchor);
		}
		else /* ostatne modlitby benediktus nemaju */
		;
	}/* PARAM_BENEDIKTUS */
	else if(equals(paramname, PARAM_ANTRCHVAL)){
		if(type == MODL_RANNE_CHVALY){
			strcat(path, _global_modl_ranne_chvaly.antifona2.file);
			includeFile(type, paramname, path, _global_modl_ranne_chvaly.antifona2.anchor);
		}
		else /* ostatne modlitby nemaju ranny chvalospev */
		;
	}/* PARAM_ANTRCHVAL */
	else if(equals(paramname, PARAM_RCHVALOSPEV)){
		if(type == MODL_RANNE_CHVALY){
			strcat(path, _global_modl_ranne_chvaly.zalm2.file);
			includeFile(type, paramname, path, _global_modl_ranne_chvaly.zalm2.anchor);
		}
		else /* ostatne modlitby nemaju ranny chvalospev */
		;
	}/* PARAM_RCHVALOSPEV */
	else if(equals(paramname, PARAM_PROSBY)){
		switch(type){
			case MODL_RANNE_CHVALY:
				strcat(path, _global_modl_ranne_chvaly.prosby.file);
				includeFile(type, paramname, path, _global_modl_ranne_chvaly.prosby.anchor);
				break;
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.prosby.file);
				includeFile(type, paramname, path, _global_modl_vespery.prosby.anchor);
				break;
			default:
				/* tieto modlitby nemaju prosby */
				break;
		}/* switch */
	}/* PARAM_PROSBY */
	else if(equals(paramname, PARAM_MODLITBA)){
		switch(type){
			case MODL_RANNE_CHVALY:
				strcat(path, _global_modl_ranne_chvaly.modlitba.file);
				includeFile(type, paramname, path, _global_modl_ranne_chvaly.modlitba.anchor);
				break;
#ifdef RUN_MODLITBA_CEZ_DEN
			case MODL_CEZ_DEN_9:
				strcat(path, _global_modl_cez_den_9.modlitba.file);
				includeFile(type, paramname, path, _global_modl_cez_den_9.modlitba.anchor);
				break;
			case MODL_CEZ_DEN_12:
				strcat(path, _global_modl_cez_den_12.modlitba.file);
				includeFile(type, paramname, path, _global_modl_cez_den_12.modlitba.anchor);
				break;
			case MODL_CEZ_DEN_3:
				strcat(path, _global_modl_cez_den_3.modlitba.file);
				includeFile(type, paramname, path, _global_modl_cez_den_3.modlitba.anchor);
				break;
#endif
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.modlitba.file);
				includeFile(type, paramname, path, _global_modl_vespery.modlitba.anchor);
				break;
			case MODL_KOMPLETORIUM:
				strcat(path, _global_modl_kompletorium.modlitba.file);
				includeFile(type, paramname, path, _global_modl_kompletorium.modlitba.anchor);
				break;
			default:
				/* tieto modlitby nemaju antifonu1 */
				break;
		}/* switch */
	}/* PARAM_MODLITBA */

}/* interpretParameter() */

/*---------------------------------------------------------------------*/
/* interpretTemplate():
 *
 * uz ma presnu cestu k suboru s templatom (vzorom) pre danu modlitbu,
 * potom tento templat interpretuje citajuc znak po znaku nasledovne:
 * - normalne kopiruje a exportuje,
 * - ak narazi na znak CHAR_KEYWORD_BEGIN, do buffra uklada vsetko az po
 *   znak CHAR_KEYWORD_END, pototm zavola interpretParameter(strbuff)
 *   a po skonceni pokracuje dalej az do EOF.
 *
 * CHAR_KEYWORD_BEGIN a CHAR_KEYWORD_END su #define'ovane v liturgia.h
 * exportfile je definovane v myexpt.[h|c]
 *
 */
void interpretTemplate(int type, char *tempfile){
	int c, buff_index = 0; /* 01/03/2000A.D. - inicializacia */
	char strbuff[MAX_BUFFER];
	char isbuff = 0;

	FILE *ftemplate = fopen(tempfile,"rb");

	Log("interpretTemplate(%s): Interpreting template %s\n",
		tempfile, tempfile);

	if(ftemplate == NULL){
		Export("Templ·t pre modlitbu sa nenaöiel. Zrejme neexistuje s˙bor `%s'.\n",
			tempfile);
		ALERT;
		return;
	}

	while((c = fgetc(ftemplate)) != EOF){
		switch (c){
			case CHAR_KEYWORD_BEGIN:
				isbuff= 1;
				buff_index = 0;
				continue;
			case CHAR_KEYWORD_END:
				isbuff = 0;
				strbuff[buff_index] = '\0';
				interpretParameter(type, strbuff);
				continue;
		}/* switch(c) */
		if(!isbuff){
			if(_global_skip_in_prayer != ANO){
				Export("%c", c); /* fputc(c, exportfile); */
			}
		}
		else strbuff[buff_index++] = c;
	}
	fclose(ftemplate);
	Log("interpretTemplate(): end.\n");
}

/*---------------------------------------------------------------------*/
/* showPrayer():
 * podla typu modlitby pripravi templat a spusti interpretTemplate()
 *
 * ak je vstupom typ vespery resp. kompletorium,
 * a v _global_modlitba je nieco ine (t.j. prve/druhe),
 * vtedy predpokladam, ze v premennych _global_[prve_]kompletorium/vespery
 * su spravne data
 *
 */
void showPrayer(int type){
	char templat[SMALL];
	char path[MAX_STR] = "";
	mystrcpy(path, include_dir, MAX_STR);
	strcat(path, FILE_PATH); /* prerobene 05/06/2000A.D. */

	LOG_ciara;
	Log("/* teraz nasleduje zobrazenie modlitby */\n");
	Log("showPrayer(): begin\n");

	/* rozparsovanie parametrov opt1...opt3 -- takmer kompletne
	 * v _main_rozbor_dna, avsak chyba este nastavenie tretieho parametra
	 * (opt3), ak je neurceny -- aby sa tam dal z _global_den.spolcast
	 * (prvy komponent)
	 */

	Log("showPrayer: opt1 == `%s' (%d)\n", pom_MODL_OPT1, _global_opt1);
	Log("showPrayer: opt2 == `%s' (%d)\n", pom_MODL_OPT2, _global_opt2);
	/* toto uz by tu bolo dost neskoro; je to v dbsvaty.cpp::set_spolocna_cast()
	if(_global_opt3 == MODL_SPOL_CAST_NEURCENA){
		_global_opt3 = (_decode_spol_cast(_global_den.spolcast)).a1;
	}
	// 17/02/2000A.D.
	*/
	Log("showPrayer: opt3 == `%s' (%d -- %s)\n",
		pom_MODL_OPT3, _global_opt3, nazov_spolc[_global_opt3]);

	/* samotne vypisanie, o aku modlitbu ide */
	Log("showPrayer(type %i, %s), _global_modlitba == %s\n",
		type, nazov_Modlitby[type], nazov_Modlitby[_global_modlitba]);

	if((type > MODL_KOMPLETORIUM) || (type < MODL_INVITATORIUM)){
		Export("Nezn·my typ modlitby.\n");
		ALERT;
		return;
	}
	if(_global_modlitba != type){
		/* zrejme ide o prve/druhe vespery ci kompletorium */
		if((_global_modlitba == MODL_PRVE_VESPERY) &&
			(type == MODL_VESPERY)){
			_global_modl_vespery = _global_modl_prve_vespery;
		}
		else if((_global_modlitba == MODL_PRVE_KOMPLETORIUM) &&
				  (type == MODL_KOMPLETORIUM)){
			_global_modl_kompletorium = _global_modl_prve_kompletorium;
		}
		else if((_global_modlitba == MODL_DRUHE_VESPERY) &&
			(type == MODL_VESPERY)){
			/* pohoda... vsetko je v _global_modl_vespery */
		}
		else if((_global_modlitba == MODL_DRUHE_KOMPLETORIUM) &&
				  (type == MODL_KOMPLETORIUM)){
			/* pohoda... vsetko je v _global_modl_kompletorium */
		}
		else{
			Log("_global_modlitba (%s) != type (%s), showPrayer()\n",
				_global_modlitba, type);
			Export("Nastala chyba programu (type != _global_modlitba).\n");
			ALERT;
			return;
		}
	}/* _global_modlitba != type */
	mystrcpy(templat, TEMPLAT[type], SMALL);
	strcat(path, templat);
	interpretTemplate(type, path);
	Log("showPrayer(): end\n");
}/* showPrayer(); */
/*---------------------------------------------------------------------*/
/* koniec pasaze, ktora bola povodne v lithod.[h|cpp]

/*---------------------------------------------------------------------*/
void VYSVETLIVKY(void){ /* 13/03/2000A.D. */
	char fname[MAX_STR] = "";
	mystrcpy(fname, include_dir, MAX_STR);
	strcat(fname, FILE_PATH); /* prerobene 05/06/2000A.D. */

	strcat(fname, FILE_VYSVETLIVKY);
	Export("<!--"); /* simulacia toho, ze replacujeme nejaky anchor */
	includeFile(0, ANCHOR_VYSVETLIVKY, fname, ANCHOR_VYSVETLIVKY);
	Export("--!>"); /* simulacia toho, ze replacujeme nejaky anchor */
}
void VYSVETLIVKY_TABULKA(void){ /* 15/03/2000A.D. */
	char fname[MAX_STR] = "";
	mystrcpy(fname, include_dir, MAX_STR);
	strcat(fname, FILE_PATH); /* prerobene 05/06/2000A.D. */

	strcat(fname, FILE_VYSVETLIVKY_TABULKA);
	Export("<!--"); /* simulacia toho, ze replacujeme nejaky anchor */
	includeFile(0, ANCHOR_VYSVETLIVKY_TABULKA, fname, ANCHOR_VYSVETLIVKY_TABULKA);
	Export("--!>"); /* simulacia toho, ze replacujeme nejaky anchor */
}

/*---------------------------------------------------------------------*/
/*
 * kontrola();
 *
 * skontroluje datum, ci je ok zadany,
 * vracia: on success, returns SUCCESS
 *         on error,   returns FAILURE
 */
#define ExportKONTROLA _export_heading1("Kontrola dna"); Export
int kontrola(int den, int mesiac, int rok){
	if((mesiac < 1) || (mesiac > 12)){
		ExportKONTROLA("Tak˝to mesiac nepozn·m (%d).\n", mesiac);
		//ALERT;
		return FAILURE;
	}
	if(prestupny(rok))
		pocet_dni[MES_FEB] = 29;
	else
		pocet_dni[MES_FEB] = 28;
	if((den < 1) || (den > pocet_dni[mesiac - 1])){
		if((mesiac == 2) && (pocet_dni[MES_FEB] == 29)){
			ExportKONTROLA("Rok %d je sÌce prestupn˝, ale aj tak m· %s len 29 dnÌ.\n",
				rok, nazov_mesiaca[MES_FEB]);
		}
		else if(mesiac == 2){
			ExportKONTROLA("Rok %d nie je prestupn˝, takûe %s m· len 28 dnÌ.\n",
				rok, nazov_mesiaca[MES_FEB]);
		}
		else{
			ExportKONTROLA("Mesiac %s m· %d dnÌ.\n",
				nazov_mesiaca[mesiac - 1], pocet_dni[mesiac - 1]);
		}
		//ALERT;
		return FAILURE;
	}
	return SUCCESS;
}/* kontrola() */

/* popis: vrati cislo dna (0--6), ak sa den == pondelok...
 *			 inak vrati UNKNOWN_DEN
 */
int atodenvt(char *den){
	int i = 0;
	do{
		if(equals(den, nazov_dna[i]) || equals(den, nazov_dna_asci[i])){
			return i;
		}
		i++;
	}while(i < DEN_UNKNOWN);
	return DEN_UNKNOWN;
}

/* popis: vrati int (cislo dna 1--31), ak sa den == 1,2...
 *        alebo (ako den == STR_VSETKY_DNI) vrati VSETKY_DNI;
 *        v pripade inych udajov vrati 0
 */
int atoden(char *den){
	int d;
	if(equals(den, STR_VSETKY_DNI))
		return VSETKY_DNI;
	else{
		d = atoi(den);
		return ((d < 0) || (d > 31)) ? 0 : d;
	}
}

/* popis: vrati cislo mesiaca (0--11), ak sa den == januar...
 *        alebo vrati VSETKY_MESIACE,  ak den == STR_VSETKY_MESIACE;
 *			 inak vrati UNKNOWN_MESIAC
 */
int atomes(char *mesiac){
	/* sprintf(pom_MESIAC, "%d", cislo_mesiaca(pom_MESIAC)); */
	if(equals(mesiac, STR_VSETKY_MESIACE))
		return VSETKY_MESIACE;
	/* mesiac moze byt string "1" -- "12" alebo nazov_mesiaca[0 -- 11] */
	int i = atoi(mesiac) - 1;
	if((i >= MES_JAN) && (i <= MES_DEC))
		return i;
	i = 0;
	do{
		if(equals(mesiac, nazov_mesiaca[i]) ||
			equals(mesiac, nazov_mesiaca_asci[i])){
			return i;
		}
		i++;
	}while(i < UNKNOWN_MESIAC);
	return UNKNOWN_MESIAC;
}

/*---------------------------------------------------------------------*/
/* definicie pre _rozbor_dna():
 *
 * obsahuju sviatky, ktore su bud pevne alebo pohyblive,
 * v kazdom pripade su to dolezite "hranicne" dni medzi obdobiami
 *
 */
#define koncovka_dna_asci(denvt) ((nazov_dna[(denvt)][strlen(nazov_dna[(denvt)]) - 1] == 'a')? 'a': 'y')
#define koncovka_dna(denvt) ((nazov_dna[(denvt)][strlen(nazov_dna[(denvt)]) - 1] == 'a')? '·': '˝')
#define KRST _global_r._KRST_KRISTA_PANA.denvr    /* nedela po 6. januari */
#define POS  _global_r._POPOLCOVA_STREDA.denvr
#define VN   _global_r._VELKONOCNA_NEDELA.denvr   /* velkonocna nedela */
#define KVET (VN - 7)                     /* kvetna nedela */
#define ZS   (VN - 3) 						   /* zeleny stvrtok */
#define VP   (VN - 2) 						   /* velky piatok */
#define BS   (VN - 1) 						   /* biela sobota */
#define VPON (VN + 1) 						   /* velkonocny pondelok */
#define VN2  (VN + 7) 						   /* nedela vo velkonocnej oktave */
#define NAN  _global_r._NANEBOVSTUPENIE_PANA.denvr
#define PAN  _global_r._PRVA_ADVENTNA_NEDELA.denvr
#define ZDS  _global_r._ZOSLANIE_DUCHA_SV.denvr
#define NAR2 (NAR + 1)						   /* druhy sviatok vianocny */
#define ROD  _global_r._SVATEJ_RODINY.denvr
#define TROJICA (ZDS + 7)             /* prva nedela po ZDS: sv. trojice */
#define TELAKRVI (ZDS + 11) /* stvrtok po trojici: kristovho tela a krvi */
#define SRDCA (ZDS + 19) /* piatok po druhej nedeli po ZDS: najsv. srdca jezisovho */
#define SRDPM (ZDS + 20) /* sobota po druhej nedeli po ZDS: neposkvrneneho srdca prebl. p. marie */

/*---------------------------------------------------------------------*/
/* _rozbor_dna()
 *
 * predpokoladam, ze pred jeho volanim bolo pouzite
 * 	analyzuj_rok(rok);
 * ktore da vysledok do _global_r
 *
 * dostane {den, mesiac} a rok
 * 01/03/2000A.D.: pridal som detailny vypis (_rozbor_dna_LOG)
 * 08/03/2000A.D.: pridal som parameter poradie_svaty, ktory je potrebny, aby som zbytocne nepriradoval
 *                 do _global_den veci z _global_svaty1
 * 28/03/2000A.D.: navratova hodnota je SUCCESS alebo FAILURE
 */
#define _rozbor_dna_LOG Log("_rozbor_dna(): "); Log
int _rozbor_dna(_struct_den_mesiac datum, int rok, int poradie_svaty){
	Log("_rozbor_dna(): 3 parametre -- begin\n");
	Log("-- _rozbor_dna(_struct_den_mesiac, int, int): begin ({%d, %d} %d %d)\n",
		datum.den, datum.mesiac, rok, poradie_svaty);

	if(poradie_svaty == UNKNOWN_PORADIE_SVATEHO){
		Log("spustam pre poradie_svaty == UNKNOWN_PORADIE_SVATEHO\n");
	}
	_rozbor_dna_LOG("vypisem, co je v analyze roku...\n");
	/* Log(_global_r); //01/03/2000A.D. */

	int NAR = poradie(25, 12, rok);       /* narodenie pana */
/* slavnosti */
	int PMB = poradie(1, 1, rok); /* panny marie bohorodicky */
	int ZJV = poradie(6, 1, rok); /* zjavenie pana */
	int DEC16 = poradie(16, 12, rok); /* 16. december, prelom v adventnom obdobi */

	/* urcenie "obcianskych" zalezitosti dna:
	 *
	 * den, mesiac, rok, denvr, denvt
	 */
	_global_den.den = datum.den;
	_global_den.mesiac = datum.mesiac;
	_global_den.rok = rok;
	_global_den.denvr = poradie(datum.den, datum.mesiac, rok);
	_global_den.denvt = den_v_tyzdni(datum.den, datum.mesiac, rok);

	/* urcenie vseobecnych "liturgickych" zalezitosti dna:
	 *
	 * litrok,
	 * tyzzal  = 0;
	 * tyzden  = 0; // neurceny; 01/03/2000A.D.
	 * smer    = 14;
	 * meno    = "";
	 * prik    = NEPRIKAZANY_SVIATOK;
	 * typslav = SLAV_NEURCENE;
	 */
	if(_global_den.denvr < PAN){
		_global_den.litrok = _global_r._POPOLCOVA_STREDA.litrok;
		_rozbor_dna_LOG("pred prvou adventnou nedelou v roku\n");
	}
	else{
		_global_den.litrok = _global_r._SVATEJ_RODINY.litrok;
		_rozbor_dna_LOG("po prvej adventnej nedeli v roku (vratane)\n");
	}
	_global_den.tyzzal = 0; /* neurceny */
	_global_den.tyzden = 0; /* neurceny; 01/03/2000A.D. */
	_global_den.smer = 14; /* neurceny */
	_global_den.typslav = SLAV_NEURCENE; /* neurcene */
	_global_den.prik = NEPRIKAZANY_SVIATOK; /* nie je prikazany sviatok */
	mystrcpy(_global_den.meno, "", MENO_SVIATKU); /* neurcene */
	_global_den.spolcast = /* pridane 01/03/2000A.D. */
		_encode_spol_cast(MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA);

	/* urcenie ostatnych specifickych "liturgickych" zalezitosti:
	 *
	 * tyzzal, litobd, tyzden, smer, typslav, prip. meno
	 */
	if(_global_den.denvr < VN){
		/* pred velkou nocou */
		_rozbor_dna_LOG("/* pred velkou nocou */\n");
		if(_global_den.denvr >= POS){
			/* postne obdobie */
			_rozbor_dna_LOG("/* postne obdobie */\n");
			_global_den.litobd = OBD_POSTNE_I; /* do soboty v 5. post.tyzdni */
			_global_den.smer = 9; /* vsedne dni v poste */

			if(_global_den.denvr == POS){
				/* _global_den.denvr == POS */
				_rozbor_dna_LOG("/* _global_den.denvr == POS */\n");
				_global_den = _global_r._POPOLCOVA_STREDA;
			}
			else if(_global_den.denvr <= POS + 3){
				/* stvrtok, piatok, sobota po popolcovej strede */
				_rozbor_dna_LOG("/* stvrtok, piatok, sobota po popolcovej strede */\n");
				/* mystrcpy(_global_den.meno, nazov_dna[_global_den.denvt]);
				strcat(_global_den.meno, " po popolcovej strede"); */
				_global_den.tyzden = 0; /* pridane 06/03/2000A.D. namiesto nasledovneho */
				/* _global_den.tyzzal = 4; */
			}
			else if(_global_den.denvr <= BS){
				/* pred a vratane bielej soboty */
				_rozbor_dna_LOG("/* pred a vratane bielej soboty */\n");

				/* urcuje postny tyzden */
				_rozbor_dna_LOG("/* urcuje postny tyzden */\n");
				_global_den.tyzden = ((_global_den.denvr - POS - 4) DIV 7) + 1;

				if(_global_den.denvr < KVET){
					/* pred kvetnou nedelou */
					_rozbor_dna_LOG("/* pred kvetnou nedelou */\n");
					if(_global_den.denvt == DEN_NEDELA){
						/* nedela v postnom obdobi */
						_rozbor_dna_LOG("/* nedela v postnom obdobi */\n");
						_global_den.smer = 2; /* nedele adventne, postne a velkonocne */
					}
					else{
						/* vsedny den v poste */
						_rozbor_dna_LOG("/* vsedny den v poste */\n");
						_global_den.smer = 9;
					}
				}
				else if(_global_den.denvr == KVET){
					/* kvetna nedela */
					_rozbor_dna_LOG("/* kvetna nedela */\n");
					_global_den.litobd = OBD_POSTNE_II_VELKY_TYZDEN;
					_global_den.smer = 2; /* nedele adventne, postne a velkonocne */
					mystrcpy(_global_den.meno, "Kvetn· nedeæa", MENO_SVIATKU);
				}
				else if(_global_den.denvr <= ZS){
					/* po kvetnej nedeli, vo velkom tyzdni */
					_rozbor_dna_LOG("/* po kvetnej nedeli, vo velkom tyzdni */\n");
					_global_den.litobd = OBD_POSTNE_II_VELKY_TYZDEN;
					_global_den.smer = 2; /* nedele adventne, postne a velkonocne */
					/* vsedne dni velkeho tyzdna od pondelka do stvrtka vratane */
					if(_global_den.denvr == ZS)
						mystrcpy(_global_den.meno, "Zelen˝ (veæk˝) ötvrtok - Pamiatka P·novej veËere", MENO_SVIATKU);
				}
				else{
					_global_den.litobd = OBD_VELKONOCNE_TROJDNIE;
					_global_den.smer = 1;
					/* velkonocne trojdnie umucenia a zmrtvychvstania */
					_rozbor_dna_LOG("/* velkonocne trojdnie umucenia a zmrtvychvstania */\n");
					if(_global_den.denvr == VP)
						mystrcpy(_global_den.meno, "Veæk˝ piatok", MENO_SVIATKU);
					else if(_global_den.denvr == BS)
						mystrcpy(_global_den.meno, "Biela (veæk·) sobota", MENO_SVIATKU);
				}
			}/* if(_global_den.denvr <= BS) */
		}/* if(_global_den.denvr >= POS) */
		else if(_global_den.denvr < POS){
			/* od 1.1. po post, teda bud vianocne obdobie alebo obdobie cez rok */
			_rozbor_dna_LOG("/* od 1.1. po post, teda bud vianocne obdobie alebo obdobie cez rok */\n");
			if(_global_den.denvr == PMB){
				/* slavnost panny marie bohorodicky */
				_rozbor_dna_LOG("/* slavnost panny marie bohorodicky */\n");
				_global_den.smer = 3;
				_global_den.typslav = SLAV_SLAVNOST;
				_global_den.litobd = OBD_OKTAVA_NARODENIA;
				_global_den.prik = PRIKAZANY_SVIATOK;
				mystrcpy(_global_den.meno, "Panny M·rie BohorodiËky (koniec Okt·vy narodenia P·na)", MENO_SVIATKU);
			}
			else if(_global_den.denvr == ZJV){
				/* slavnost zjavenia pana */
				_rozbor_dna_LOG("/* slavnost zjavenia pana */\n");
				_global_den.smer = 2; /* zjavenie pana */
				_global_den.typslav = SLAV_SLAVNOST;
				_global_den.litobd = OBD_VIANOCNE_II; /* ma vlastne slavenie; zmenil som na vianocne obd. II 14/03/2000A.D. */
				_global_den.prik = PRIKAZANY_SVIATOK;
				mystrcpy(_global_den.meno, "Zjavenie P·na", MENO_SVIATKU);
			}
			else if((_global_den.denvt == DEN_NEDELA) &&
					  (_global_den.denvr >= 2) && (_global_den.denvr <= 5)){
				/* druha nedela po narodeni pana medzi 2. a 5. januarom;
				 * v krajinach, kde sa slavnost zjavenia pana slavi 6. januara
				 */
				_rozbor_dna_LOG("/* druha nedela po narodeni pana medzi 2. a 5. januarom; v krajinach, kde sa slavnost zjavenia pana slavi 6. januara */\n");
				_global_den.smer = 6; /* nedele vianocneho obdobia a obdobia "cez rok" */
				_global_den.litobd = OBD_VIANOCNE_I;
				mystrcpy(_global_den.meno, "2. nedeæa po NarodenÌ P·na", MENO_SVIATKU);
			}
			else if(_global_den.denvr < KRST){
				/* vianocne obdobie */
				_rozbor_dna_LOG("/* vianocne obdobie */\n");
				_global_den.tyzden = 2;
				/* vsedne dni vianocneho obdobia od 2. januara
				 * do soboty po zjaveni pana */
				_global_den.smer = 13;
				/* zistime, ci je pred alebo po zjaveni pana */
				if(_global_den.denvr < ZJV){
					_global_den.litobd = OBD_VIANOCNE_I;
					_rozbor_dna_LOG("/* pred zjavenim Pana */\n");
				}
				else{
					_global_den.litobd = OBD_VIANOCNE_II;
					_rozbor_dna_LOG("/* po zjaveni Pana (vratane) */\n");
				}
			}
			else if(_global_den.denvr > KRST){
				/* obdobie cez rok po vianociach do popolcovej stredy */
				_rozbor_dna_LOG("/* obdobie cez rok po vianociach do popolcovej stredy */\n");
				_global_den.litobd = OBD_CEZ_ROK;
				/* urcenie tyzdna v obdobi "cez rok" */
				_global_den.tyzden = ((_global_den.denvr - KRST) DIV 7) + 1;
				if(_global_den.denvt == DEN_NEDELA){
					/* nedela v obdobi cez rok */
					_rozbor_dna_LOG("/* nedela v obdobi cez rok */\n");
					_global_den.smer = 6; /* nedele vianocneho obdobia a obdobia "cez rok" */
				}
				else{
					/* vsedny den v obdobi cez rok */
					_rozbor_dna_LOG("/* vsedny den v obdobi cez rok */\n");
					_global_den.smer = 13; /* vsedne dni "cez rok" */
				}
			}/* if(_global_den.denvr > KRST) */
			else if(_global_den.denvr == KRST){
				/* sviatok krstu krista pana, nedela po 6. januari */
				_rozbor_dna_LOG("/* sviatok krstu krista pana, nedela po 6. januari */\n");
				_global_den = _global_r._KRST_KRISTA_PANA;
			}/* if(_global_den.denvr == KRST) */
		}/* if(_global_den.denvr < POS) */
	}/* if(_global_den.denvr < VN) */
	else if(_global_den.denvr >= VN){
		/* po velkej noci */
		_rozbor_dna_LOG("/* po velkej noci */\n");
		if(_global_den.denvr <= ZDS){
			/* velkonocne obdobie (po zoslanie d.s.) */
			_rozbor_dna_LOG("/* velkonocne obdobie (po zoslanie d.s.) */\n");
			_global_den.tyzden = ((_global_den.denvr - VN) DIV 7) + 1;

			if(_global_den.denvr == ZDS){
				/* zoslanie ducha svateho */
				_rozbor_dna_LOG("/* zoslanie ducha svateho */\n");
				_global_den = _global_r._ZOSLANIE_DUCHA_SV;
			}
			else if(_global_den.denvr <= VN2){
				/* velkonocna oktava */
				_rozbor_dna_LOG("/* velkonocna oktava */\n");
				_global_den.litobd = OBD_VELKONOCNA_OKTAVA;
				_global_den.smer = 2; /* dni velkonocnej oktavy */
				if(_global_den.denvr == VN){
					/* velkonocna nedela */
					_rozbor_dna_LOG("/* velkonocna nedela */\n");
					_global_den = _global_r._VELKONOCNA_NEDELA;
				}
				else{
					/* velkonocna oktava */
					_rozbor_dna_LOG("/* velkonocna oktava */\n");
					_global_den.litobd = OBD_VELKONOCNA_OKTAVA;
					if(_global_den.denvr == VN2){
						/* 2. velkonocna nedela */
						_rozbor_dna_LOG("/* 2. velkonocna nedela */\n");
						mystrcpy(_global_den.meno, "Nedeæa vo VeækonoËnej okt·ve (2. veækonoËn· nedeæa)", MENO_SVIATKU);
					}
					else{
						/* velkonocna oktava - vsedny den */
						_rozbor_dna_LOG("/* velkonocna oktava - vsedny den */\n");
						sprintf(_global_den.meno, "VeækonoËn%c %s",
							koncovka_dna(_global_den.denvt),
							nazov_dna[_global_den.denvt]);
					}
				}
			}/* if(_global_den.denvr <= VN2) */
			else if(_global_den.denvr == NAN){
				/* _global_den.denvr == NAN, nanebovstupenie Pana */
				_rozbor_dna_LOG("/* nanebovstupenie Pana */\n");
				_global_den = _global_r._NANEBOVSTUPENIE_PANA;
			}/* if(_global_den.denvr == NAN) */
			else{
				if(_global_den.denvr < NAN){
					/* velkonocne obdobie do nanebovstupenia */
					_rozbor_dna_LOG("/* velkonocne obdobie do nanebovstupenia */\n");
					_global_den.litobd = OBD_VELKONOCNE_I;
				}
				else{
					/* velkonocne obdobie po nanebovstupeni do zoslania ducha */
					_rozbor_dna_LOG("/* velkonocne obdobie po nanebovstupeni do zoslania ducha */\n");
					_global_den.litobd = OBD_VELKONOCNE_II;
				}
				if(_global_den.denvt == DEN_NEDELA){
					_rozbor_dna_LOG("/* nedela */\n");
					_global_den.smer = 2; /* nedele adventne, postne a velkonocne */
				}/* nedela */
				else{
					_rozbor_dna_LOG("/* vsedne dni velkonocneho obdobia od pondelka po velkonocnej oktave az do soboty pred zoslanim ducha svateho vcitane */\n");
					_global_den.smer = 13; /* vsedne dni velkonocneho obdobia od pondelka po velkonocnej oktave az do soboty pred zoslanim ducha svateho vcitane */
				}/* nie nedela */
			}/* if(_global_den.denvr != NAN) */
		}/* if(_global_den.denvr >= VN) */
		else if(_global_den.denvr > ZDS){
			/* obdobie cez rok po velkej noci a dalej
			 * (advent, vianocne obdobie do 31.12.) */
			_rozbor_dna_LOG("/* obdobie cez rok po velkej noci a dalej (advent, vianocne obdobie do 31.12.) */\n");
			if(_global_den.denvr < PAN){
				/* obdobie cez rok po velkej noci do prvej adventnej nedele */
				_rozbor_dna_LOG("/* obdobie cez rok po velkej noci do prvej adventnej nedele */\n");
				_global_den.litobd = OBD_CEZ_ROK;
				/* urcim tyzden v obdobi "cez rok" */
				_global_den.tyzden = POCET_NEDIEL_CEZ_ROK -
					((PAN - _global_den.denvr - 1) DIV 7);
				_rozbor_dna_LOG("/* %d. tyzden v obdobi cez rok */\n", _global_den.tyzden);
				if(_global_den.denvt == DEN_NEDELA){
					/* i.-ta nedela v obdobi cez rok */
					_rozbor_dna_LOG("/* nedela v ocr */\n");
					if(_global_den.denvr == TROJICA){
						/* najsv. trojice == ZDS + 7 */
						_rozbor_dna_LOG("/* najsv. trojice */\n");
						_global_den.smer = 3; /* slavnosti pana */
						_global_den.typslav = SLAV_SLAVNOST;
						mystrcpy(_global_den.meno, "Najsv‰tejöej Trojice", MENO_SVIATKU);
					}
					else if(_global_den.tyzden == KRISTA_KRALA){
						/* krista krala */
						_rozbor_dna_LOG("/* krista krala */\n");
						_global_den.smer = 3; /* slavnosti pana */
						_global_den.typslav = SLAV_SLAVNOST;
						mystrcpy(_global_den.meno, "Krista Kr·æa", MENO_SVIATKU);
					}
					else{
						_global_den.smer = 6; /* nedele vianocneho obdobia a obdobia "cez rok" */
					}
				}
				else{
					/* den v i.-tom tyzdni obdobia cez rok */
					_rozbor_dna_LOG("/* den v i.-tom tyzdni obdobia cez rok */\n");
					if(_global_den.denvr == TELAKRVI){
						/* najsv. krist. tela a krvi == ZDS + 11 */
						_rozbor_dna_LOG("/* najsv. krist. tela a krvi */\n");
						_global_den.smer = 3; /* slavnosti pana */
						_global_den.typslav = SLAV_SLAVNOST;
						_global_den.prik = PRIKAZANY_SVIATOK;
						mystrcpy(_global_den.meno, "Najsv‰tejöieho Kristovho tela a krvi", MENO_SVIATKU);
					}
					else if(_global_den.denvr == SRDCA){
						/* srdca jezisovho == ZDS + 19 */
						_rozbor_dna_LOG("/* srdca jezisovho */\n");
						_global_den.smer = 3; /* slavnosti pana */
						_global_den.typslav = SLAV_SLAVNOST;
						mystrcpy(_global_den.meno, "Najsv‰tejöieho Srdca Jeûiöovho", MENO_SVIATKU);
					}
					else if(_global_den.denvr == SRDPM){
						/* srdca prebl. panny marie == ZDS + 20 */
						_rozbor_dna_LOG("/* srdca prebl. panny marie */\n");
						_global_den.smer = 11; /* miestne povinne spomienky podla vseobecneho kalendara */
						/* zrejme pre Slovensko je tato lubovolna spomienka povinna; 
						 * aby sa nebila s inou spomienkou, dal som tam smer == 11; 10/03/2000A.D. */
						_global_den.typslav = SLAV_SPOMIENKA;
						mystrcpy(_global_den.meno, "NepoökvrnenÈho Srdca prebl. Panny M·rie", MENO_SVIATKU);
						_global_den.spolcast = /* pridane 04/07/2000A.D. */
							_encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
						_global_opt3 = MODL_SPOL_CAST_PANNA_MARIA;
					}
					else{
						_global_den.smer = 13; /* vsedne dni `cez rok' */
						_rozbor_dna_LOG("/* vsedne dni `cez rok' */\n");
					}
				}
			}/* if(_global_den.denvr < PAN) */
			else if(_global_den.denvr >= PAN){
				/* adventne obdobie resp. vianocne */
				_rozbor_dna_LOG("/* adventne obdobie resp. vianocne */\n");
				if(_global_den.denvr < NAR){
					/* adventne obdobie */
					_rozbor_dna_LOG("/* adventne obdobie */\n");
					_global_den.tyzden = ((_global_den.denvr - PAN) DIV 7) + 1;
					if(_global_den.denvr <= DEC16){
						/* do 16. decembra */
						_rozbor_dna_LOG("/* do 16. decembra */\n");
						_global_den.litobd = OBD_ADVENTNE_I;
						if(_global_den.denvt == DEN_NEDELA){
							_global_den.smer = 2; /* nedele adventne, postne a velkonocne */
							_rozbor_dna_LOG("/* nedela */\n");
						}
						else{
							_global_den.smer = 13; /* vsedne dni adventne az do 16. decembra */
							_rozbor_dna_LOG("/* vsedny den */\n");
						}
					}
					else{
						/* po 16. decembri */
						_rozbor_dna_LOG("/* po 16. decembri */\n");
						_global_den.litobd = OBD_ADVENTNE_II;
						if(_global_den.denvt == DEN_NEDELA){
							_global_den.smer = 2; /* nedele adventne, postne a velkonocne */
							_rozbor_dna_LOG("/* nedela */\n");
						}
						else{
							_global_den.smer = 9; /* adventne dni od 17. do 24. decembra vratane */
							_rozbor_dna_LOG("/* vsedny den od 17. do 24. decembra vratane */\n");
						}
					}
				}/* if(_global_den.denvr < NAR) */
				else if(_global_den.denvr >= NAR){
					/* vianocne obdobie */
					_rozbor_dna_LOG("/* vianocne obdobie */\n");
					_global_den.litobd = OBD_OKTAVA_NARODENIA; /* pretoze do 31.12. */
					_global_den.tyzden = 1;
					if(_global_den.denvr == NAR){
						/* narodenie pana */
						_rozbor_dna_LOG("/* narodenie pana */\n");
						_global_den.typslav = SLAV_SLAVNOST;
						_global_den.smer = 2; /* narodenie pana */
						_global_den.prik = PRIKAZANY_SVIATOK;
						mystrcpy(_global_den.meno, "Narodenie P·na", MENO_SVIATKU);
					}
					else if(_global_den.denvr == ROD){
						/* nedela sv. rodiny */
						_rozbor_dna_LOG("/* nedela sv. rodiny */\n");
						/* ked padne NAR na nedelu, sviatok sv. rodiny */
						/* sa slavi 30. dec a nema prve vespery */
						_global_den = _global_r._SVATEJ_RODINY;
					}
					else{
						_global_den.smer = 9; /* dni v oktave narodenia pana */
						_rozbor_dna_LOG("/* dni v oktave narodenia pana */\n");
					}
				}/* if(_global_den.denvr >= NAR) */
			}/* if(_global_den.denvr >= PAN) */
		}/* if(_global_den.denvr > ZDS) */
	}/* if(_global_den.denvr >= VN) */

	if(_global_den.tyzzal == 0){
		/* neurcili sme tyzden v zaltari, urobime tak teraz */
		_rozbor_dna_LOG("/* neurcili sme tyzden v zaltari, urobime tak teraz */\n");
		_global_den.tyzzal = ((_global_den.tyzden + 3) MOD 4) + 1;
			/* povodne tu bolo: (_global_den.tyzden - 1) MOD 4; 06/03/2000A.D. */
		_rozbor_dna_LOG("tyzzal == %d\n", _global_den.tyzzal);
	}
	else{
		_rozbor_dna_LOG("/* tyzden zaltara uz bol urceny, tyzzal == %d */\n", 
			_global_den.tyzzal);
		/* 27/04/2000A.D. */
	}

	Log("_rozbor_dna(): _global_den:\n");
	Log(_global_den); /* pridane 01/03/2000A.D. */

	/* nasleduje porovnanie so sviatkami svatych;
	 * berieme do uvahy, ze moze byt viac lubovolnych spomienok
	 */
	Log("_global_den.smer == %d\n", _global_den.smer);
	Log("_global_den.spolcast == %d\n", _global_den.spolcast);
	//Log("spustam sviatky_svatych(%d, %d);...\n", _global_den.den, _global_den.mesiac);

	_global_pocet_svatych = sviatky_svatych(_global_den.den, _global_den.mesiac);
	_rozbor_dna_LOG("_global_pocet_svatych = %d\n", _global_pocet_svatych);

	/* pridane 28/03/2000A.D.: ak chce vacsie cislo (poradie svateho) ako je v _global_pocet_svatych
	 * resp. ked nie je sobota a chce poradie svateho 4 (spomienka p. marie v sobotu)
	 */

	if((_global_pocet_svatych == 0) && (_global_pocet_svatych < poradie_svaty) && (poradie_svaty != 4)){
		Export("V tento deÚ nie je sviatok ûiadneho sv‰tÈho, preto nemÙûete poûadovaù sv‰tÈho Ë. %d.",
			poradie_svaty);
		ALERT;
		Log("returning from _rozbor_dna(), because: (_global_pocet_svatych == 0) && (_global_pocet_svatych < poradie_svaty) && (poradie_svaty != 4)\n");
		return FAILURE;
	}
	else if((_global_pocet_svatych < poradie_svaty) && (poradie_svaty != 4)){
		Export("Nie je viac ako %d sviatkov sv‰t˝ch v tento deÚ, preto nemÙûete poûadovaù sv‰tÈho Ë. %d.",
			_global_pocet_svatych, poradie_svaty);
		ALERT;
		Log("returning from _rozbor_dna(), because: (_global_pocet_svatych < poradie_svaty) && (poradie_svaty != 4)\n");
		return FAILURE;
	}
	else if((_global_den.denvt != DEN_SOBOTA) && (poradie_svaty == 4)){
		Export("Tento deÚ je %s, a nie je sobota, takûe nemÙûete poûadovaù modlitbu `Spomienka Panny M·rie v sobotu'.\n",
			nazov_dna[_global_den.denvt]);
		ALERT;
		Log("returning from _rozbor_dna(), because: (_global_den.denvt != DEN_SOBOTA) && (poradie_svaty == 4)\n");
		return FAILURE;
	}

	if(_global_pocet_svatych > 0){
		Log("sviatky_svatych() == %d\n", _global_pocet_svatych);

		/* treba pamatat na to, ze v poste sa vsetky spomienky
		 * stavaju lubovolnymi (c. 14 vseob. smernic) */
		if((_global_den.litobd == OBD_POSTNE_I) &&
			(_global_svaty1.typslav == SLAV_SPOMIENKA)){
			 Log("je postne obdobie, tak menim `spomienku' na `lubovolnu spomienku'\n");
			 _global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
		}

		/* c. 12 v c. 59 vseob. smernic: "lubovolne spomienky, ktore sa mozu
		 * slavit aj v dnoch uvedenych pod c. 9 [...] tak ist v omsi a oficiu
		 * na sposob lubovolnych spomienok mozno slavit tie povinne spomienky,
		 * ktore obcas pripadnu na vsedne dni v poste." ... */
		if(((_global_den.smer == 9) &&
			 (_global_svaty1.typslav == SLAV_LUB_SPOMIENKA)) ||

			 /* ... alebo c. 60: "ak na jeden den pripadnu viacere slavenia,
		 * uprednostni sa to, ktore ma v tabulke liturgickych dni vyssi stupen
		 * [t.j. .smer]. */
			(_global_den.smer > _global_svaty1.smer)){

			/* ked bola nasledovna pasaz zapoznamkovana,
			 * tak vsetko (bez modlitby) slo v poriadku; neslo generovanie
			 * modlitby ok;
			 * naopak, ked som ju odpoznamkoval 16/02/2000A.D.,
			 * prestalo to ist bez modlitby (iba generovalo ok)
			 * preto som to dal podla toho, ci _global_modlitba != MODL_NEURCENA
			 * (18/02/2000A.D.)
			 */
			/* 23/02/2000A.D. -- SVATY_VEDIE */
			Log("svaty ma prednost pred dnom (SVATY_VEDIE)\n");
			Log("_global_den.smer == %d, _global_svaty1.smer == %d, _global_svaty1.prik == %d\n",
				_global_den.smer, _global_svaty1.smer, _global_svaty1.prik);

			/* cele to tu bolo asi kvoli tomu, ze niektore veci sa pri generovani modlitby
			 * citali z _global_den explicitne;
			 * zda sa, ze to ide aj bez toho;
			 * napr. v BUTTONS (teda v tom export...) sa cita z _global_svaty...
			 * 08/03/2000A.D.
			 * akvsak ked som to cele zrusil, tak prestali fungovat prve vespery slavnosti, ktore
			 * mali definovane vecicky v _global_svaty1, pretoze sa nikde nepriradili do _global_den;
			 * takze som to napokon dal sem a pridal podmienku "iba ak ide o slavnost"
			 * 15/03/2000A.D.
			 */
			if((_global_modlitba != MODL_NEURCENA) && 
				(
					(poradie_svaty != 0) || /* 08/03/2000A.D. -- pridane */
					((poradie_svaty == 0) &&(_global_svaty1.smer < 5)) /* slavnosti */
				)
				){ /* 15/03/2000A.D. -- modifikovane */
				/* tato pasaz je cela divna... */
				/* menim, lebo svaty ma prednost */
				Log("menim, lebo `%s' ma prednost...\n", _global_svaty1.meno);

				mystrcpy(_global_den.meno, _global_svaty1.meno, MENO_SVIATKU);
				_global_den.smer = _global_svaty1.smer;
				_global_den.typslav = _global_svaty1.typslav;
				_global_den.spolcast = _global_svaty1.spolcast; /* pridane 22/02/2000A.D. */
				_global_den.prik = _global_svaty1.prik; /* pridane 23/02/2000A.D. */
			}/* koniec menenia pre _global_modlitba != MODL_NEURCENA a svaty > 0 resp. slavnost */
		}
		else{
			/* neuprednostnujeme svatych pred dnom */
			_global_pocet_svatych = 0;
		}
	}
	Log("sviatky_svatych(%d, %d) skoncila a ukoncilo sa aj rozhodovanie\n",
		_global_den.den, _global_den.mesiac);

	/* prikazane sviatky - boli oznacene na prislusnych miestach */

	/* inicializujem spomienku panny marie v sobotu */
	init_global_pm_sobota(); /* v liturgia.cpp */
	Log("init_global_pm_sobota(): _global_pm_sobota:\n");
	Log(_global_pm_sobota); /* pridane 27/04/2000A.D. */

	Log("-- _rozbor_dna(_struct_den_mesiac, int, int): end ({%d, %d}, %d %d)\n",
		datum.den, datum.mesiac, rok, poradie_svaty);
	/* export -- je inde
	 * _export_rozbor_dna() a v _rozbor_dna_s_modlitbou();
	 */
	Log("_rozbor_dna(): 3 parametre -- returning SUCCESS...\n");
	return SUCCESS;
}/* _rozbor_dna() */

int _rozbor_dna(_struct_den_mesiac datum, int rok){
	int ret;
	Log("_rozbor_dna(): 2 parametre -- begin\n");
	ret = _rozbor_dna(datum, rok, 0);
	Log("_rozbor_dna(): 2 parametre -- returning %d\n", ret);
	return ret;
}

#define EXPORT_DNA_JEDEN_DEN 1
#define EXPORT_DNA_VIAC_DNI 2
#define EXPORT_DNA_DNES 0
/* 08/03/2000A.D. -- pridane init_global_string(int, int, int) s troma
 * parametrami, lebo sa vyskytla potreba (zeleny stvrtok), ze meno sviatku
 * zavisi od modlitby
 */
/* -------------------------------------------------------------------- */
/* init_global_string(int, int)
 * vstup: typ (o aky sposob vypisu ide)
 *        poradie_svateho
 * vystup: do _global_string da string (spolu s HTML tagmi)
 *         s nazvom slavenia;
 * 28/03/2000A.D.: navratova hodnota SUCCESS/FAILURE;
 */
#define CASE_VELKE  5
#define CASE_MALE   4
#define COLOR_RED   3
#define COLOR_BLACK 2
int init_global_string(int typ, int poradie_svateho, int modlitba){
	/* lokalna premenna, do ktorej sa ukladaju info o analyzovanom dni
	 * pouziva ju void nove_rozbor_dna() funkcia */
	_struct_dm _local_den;

	char pom[MAX_STR];
	mystrcpy(_global_string, "", MAX_GLOBAL_STR); /* inicializacia */
	mystrcpy(_global_string2, "", MAX_GLOBAL_STR); /* inicializacia */

	int farba = COLOR_BLACK;
	int velkost = CASE_MALE;
	int obyc = NIE;

	Log("-- init_global_string(EXPORT_DNA_%d, %d, %s) -- zaciatok\n",
		typ, poradie_svateho, nazov_modlitby[modlitba]);
	/* -------------------------------------------------------------------- */
	/* najprv priradime do _local_den to, co tam ma byt */

		Log("poradie_svateho == %d\n", poradie_svateho);
		/* sviatky (spomienky, ls) svatych */
		switch(poradie_svateho){
			case 4:
				/* do _local_den priradim slavenie pm v sobotu v dalsom */
				if(_global_den.denvt != DEN_SOBOTA){
            	Export("Tento deÚ nie je sobota, preto nemÙûe maù `spomienku Panny M·rie v sobotu'!\n");
					Log("Tento den nie je sobota, preto nemoze mat spomienku P. Marie v sobotu!\n");
					ALERT;
					return FAILURE;
				}
				else{/* pridane 27/04/2000A.D. */
					/* do _local_den priradim dane slavenie */
					_local_den = _global_pm_sobota;
					Log("priradujem _local_den = _global_pm_sobota;\n");
				}
				break; /* case 4: */
			case 1:
				/* do _local_den priradim dane slavenie */
				_local_den = _global_svaty1;
				Log("priradujem _local_den = _global_svaty1;\n");
				break; /* case 1: */
			case 2:
				if(_global_pocet_svatych > 1){
					/* do _local_den priradim dane slavenie */
					_local_den = _global_svaty2;
					Log("priradujem _local_den = _global_svaty2;\n");
				}
				else{
					/* sice chce svateho c. 2, ale mam len jedneho */
					Log("-- Error: _global_svaty2 not assigned\n");
					sprintf(pom, "Error: _global_svaty2 not assigned");
					strcat(_global_string, pom);
					Export("%s\n", _global_string);
					ALERT;
					return FAILURE;
				}
				break; /* case 2: */
			case 3:
				if(_global_pocet_svatych > 2){
					/* teraz do _local_den priradim dane slavenie */
					_local_den = _global_svaty3;
					Log("priradujem _local_den = _global_svaty3;\n");
				}
				else{
					/* sice chce svateho c. 3, ale nemam troch */
					Log("-- Error: _global_svaty3 not assigned\n");
					sprintf(pom, "Error: _global_svaty3 not assigned");
					strcat(_global_string, pom);
					Export("%s\n", _global_string);
					ALERT;
					return FAILURE;
				}
				break; /* case 3: */
			case 5:
				Log("-- Error: poradie_svateho == 5\n");
				Export("Error: poradie_svateho == 5\n");
				ALERT;
				return FAILURE;
				break;
			case 0:
				/* bezny den */
				Log("/* bezny den */\n");
				obyc = ANO;
				_local_den = _global_den;
				break; /* case 0: */
		}/* switch(poradie_svateho) */

	Log("1:_local_den.meno == %s\n", _local_den.meno); /* 08/03/2000A.D. */

	/* 21/03/2000A.D.
	 * celu tuto pasaz som zapoznamkoval, lebo to nema vyznam 
	 * v pripade, ze su korektne nastavene veci do _global_den :-)
	 * sami si prioritu .smer ocekuju.
	 * naopak, tato pasaz skodila: pre 29. jun 2008, 24. jun 2001, 5. jul 1998 apod.
	if((_global_den.denvt == DEN_NEDELA) ||
		(_global_den.prik == PRIKAZANY_SVIATOK)){
		Log("// _local_den ostava _global_den, lebo nedela || prikazany sviatok \n");
		_local_den = _global_den;
	}
	 * 23/03/2000A.D.
	 * mohli by tu pre istotu byt nasledujuce riadky (v pripade, ze nieco zlyha v _rozbor_dna()):
	if(_global_den.smer < 5){
		Log("// _local_den ostava _global_den, lebo slavnost (smer == %d) \n", _global_den.smer);
		_local_den = _global_den;
	}
	 */

	Log("2:_local_den.meno == %s\n", _local_den.meno); /* 08/03/2000A.D. */

	/* este spomienka panny marie v sobotu, cl. 15 */
	if((_global_den.litobd == OBD_CEZ_ROK) &&
		(_global_den.denvt == DEN_SOBOTA) &&
		(
			((_global_den.smer >= 12) && (_global_pocet_svatych == 0)) ||
			((_global_svaty1.smer >= 12) && (_global_pocet_svatych > 0))) &&
		(poradie_svateho == 4)){
		/* teraz do _global_den priradim dane slavenie */
		_local_den = _global_pm_sobota;
	}

	Log("3:_local_den.meno == %s\n", _local_den.meno); /* 08/03/2000A.D. */
	
	/* skontrolujeme este pondelok -- stvrtok velkeho tyzdna */
	if((_local_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN) && (typ != EXPORT_DNA_VIAC_DNI)){
		if(!((_local_den.denvt == DEN_NEDELA) || ((_local_den.denvt == DEN_STVRTOK)) && (modlitba == MODL_VESPERY))){ /* 08/03/2000A.D. */
			mystrcpy(_local_den.meno, nazov_dna[_local_den.denvt], MENO_SVIATKU);
			strcat(_local_den.meno, " vo Veækom t˝ûdni");
		}
	}

	Log("4:_local_den.meno == %s\n", _local_den.meno); /* 08/03/2000A.D. */
	/* -------------------------------------------------------------------- */
	/* teraz podla toho, co je v _local_den, vytvorime _global_string */
	Log("_local_den.smer < 5 -- ");
	if(_local_den.smer < 5){
		/* slavnosti */
		velkost = CASE_VELKE;
		Log("ano\n");
	}
	else
		Log("nie\n");
	Log("_local_den.denvt == DEN_NEDELA || _local_den.prik == PRIKAZANY_SVIATOK -- ");
	if((_local_den.denvt == DEN_NEDELA) ||
		(_local_den.prik == PRIKAZANY_SVIATOK)){
		/* prikazane sviatky a nedele */
		farba = COLOR_RED;
		Log("ano\n");
	}
	else
		Log("nie\n");

	/* najprv nazov */
	mystrcpy(_global_string, "<b>", MAX_GLOBAL_STR);
	if(farba == COLOR_RED){
		strcat(_global_string, "<font color=\"#FF0000\">");
	}
	Log("5:_local_den.meno == %s\n", _local_den.meno); /* 08/03/2000A.D. */
	if(equals(_local_den.meno, "")){
		if(_local_den.denvt == DEN_NEDELA){
			/* nedela bez vlastneho nazvu */
			sprintf(pom, "%d. %s %s",
					_local_den.tyzden,
					nazov_DNA[_local_den.denvt],
					nazov_OBDOBIA_V[_local_den.litobd]);
			strcat(_global_string, pom);
		}
		else if(obyc == ANO){
			if(typ != EXPORT_DNA_VIAC_DNI){
#ifdef OLD_STYLE_obycajny_den /* 08/03/2000A.D. */
				sprintf(pom, "%s, %s</b>, %d. t˝ûdeÚ ûalt·ra",
					nazov_Dna[_local_den.denvt],
					nazov_obdobia[_local_den.litobd],
					tyzden_zaltara(_local_den.tyzden));
#else
				if((_local_den.tyzden == 0) && (_local_den.litobd == OBD_POSTNE_I)){
					sprintf(pom, "%s po Popolcovej strede, %s</b><br><font size=-1> %d. t˝ûdeÚ ûalt·ra</font>",
						nazov_Dna[_local_den.denvt],
						nazov_obdobia[_local_den.litobd],
						tyzden_zaltara(_local_den.tyzden));
				}
				else{
					sprintf(pom, "%s, %s</b>, %d. t˝ûdeÚ<br><font size=-1> %d. t˝ûdeÚ ûalt·ra</font>",
						nazov_Dna[_local_den.denvt],
						nazov_obdobia[_local_den.litobd],
						_local_den.tyzden,
						tyzden_zaltara(_local_den.tyzden));
				}
#endif
				strcat(_global_string, pom);
			}
			/* inak ostane string prazdny */
		}
		else{
			Log("-- Error: _local_den.meno == "", avsak obyc != ANO\n");
		}
	}
	else{
		/* vlastny nazov */
		if(_local_den.denvt == DEN_NEDELA){
			/* nedela co ma vlastny nazov */
			strcat(_global_string, caps_BIG(_local_den.meno));
		}
		else if(velkost == CASE_VELKE)
			strcat(_global_string, caps_BIG(_local_den.meno));
		else
			strcat(_global_string, _local_den.meno);
	}/* _local_den.meno != "" */

	if(farba == COLOR_RED){
		strcat(_global_string, "</font>");
	}
	strcat(_global_string, "</b>");

	/* teraz typ slavenia */
	if(_local_den.typslav != SLAV_NEURCENE){
		sprintf(pom, ", <font color=\"#FF0000\">%s</font>",
			nazov_slavenia[_local_den.typslav]);
		strcat(_global_string, pom);
	}

	Log("  -- _global_string == %s\n", _global_string);

	/* napokon inicializujem _global_string2 */
	if(((_global_r._POPOLCOVA_STREDA.den == _local_den.den) &&
		 (_global_r._POPOLCOVA_STREDA.mesiac == _local_den.mesiac)) ||
		/* popolcova streda */
		((_local_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN) &&
		 (typ == EXPORT_DNA_VIAC_DNI)) ||
		/* pondelok -- streda velkeho tyzdna */
		(_local_den.smer > 8)){
		/* nie slavnosti ani sviatky ani nedele */
		mystrcpy(_global_string2,
			rimskymi_tyzden_zaltara[tyzden_zaltara(_global_den.tyzden)], MAX_GLOBAL_STR);
	}
	else if(_local_den.denvt == DEN_NEDELA){
		/* 13/03/2000A.D. -- pridane, aby aj nedele mali tyzden zaltara */
		sprintf(_global_string2, "%c, %s", 
			_local_den.litrok, 
			rimskymi_tyzden_zaltara[tyzden_zaltara(_global_den.tyzden)]);
	}
	else{
		mystrcpy(_global_string2, "V", MAX_GLOBAL_STR);
	}

	Log("-- init_global_string(EXPORT_DNA_%d, %d, %s) -- returning SUCCESS\n",
		typ, poradie_svateho, nazov_modlitby[modlitba]);
	return SUCCESS;
}/* init_global_string(); -- 3 vstupy  */

int init_global_string(int typ, int poradie_svateho){
	return init_global_string(typ, poradie_svateho, MODL_NEURCENA);
}/* init_global_string(); -- 2 vstupy  */

/*---------------------------------------------------------------------*/
/* _rozbor_dna_s_modlitbou()
 *
 * predpokoladam, ze pred jeho volanim bolo pouzite
 * 	analyzuj_rok(rok);
 * ak poradie_svateho == 5, znamena to, ze analyzujem nasledujuci den.
 * ktore da vysledok do _global_r
 *
 * dostane {den, mesiac} a rok
 *
 * 28/03/2000A.D.: prirobena navratova hodnota SUCCESS/FAILURE
 */
int _rozbor_dna_s_modlitbou(_struct_den_mesiac datum, int rok, int modlitba, int poradie_svateho){
	int ret;
	Log("-- _rozbor_dna_s_modlitbou(_struct_den_mesiac, int, int, int): begin ({%d, %d}, %d, %s, %d)\n",
		datum.den, datum.mesiac, rok, nazov_Modlitby[modlitba], poradie_svateho);

	Log("vo funkcii _rozbor_dna_s_modlitbou() spustam set_popis_dummy();\n");
	set_popis_dummy();
	Log("set_popis_dummy() skoncila.\n");

	ret = _rozbor_dna(datum, rok, poradie_svateho);
	if(ret == FAILURE){
		Log("_rozbor_dna() returned FAILURE, so returning FAILURE...\n");
		return FAILURE;
	}

	if(poradie_svateho == UNKNOWN_PORADIE_SVATEHO){
		/* kedze neviem poradie svateho, lebo robim nasledujuci den, priradim 0 */
		Log("/* kedze neviem poradie svateho, lebo robim nasledujuci den, priradim 0 */\n");
		poradie_svateho = 0;
	}

	/* nasledovna pasaz pridana 28/03/2000A.D. -- aby sme dobre kontrolovali, ci vobec mozeme
	 * spustit generovanie modlitby
	 */
	if((poradie_svateho == 4) && (_global_den.denvt != DEN_SOBOTA)){
		Export("NemÙûete poûadovaù t˙to modlitbu, pretoûe nie je sobota.\n");
		ALERT;
		Log("(poradie_svateho == 4) && (_global_den.denvt != DEN_SOBOTA), so returning FAILURE...\n");
		return FAILURE;
	}
	else if((poradie_svateho == 4) && (_global_den.denvt == DEN_SOBOTA) && (modlitba >= MODL_VESPERY)){
		Export("NemÙûete poûadovaù t˙to modlitbu, pretoûe `Spomienka Panny M·rie v sobotu' nem· veöpery ani kompletÛrium.\n");
		ALERT;
		Log("(poradie_svateho == 4) && (_global_den.denvt != DEN_SOBOTA), so returning FAILURE...\n");
		return FAILURE;
	}
	else if((poradie_svateho != 4) && (_global_pocet_svatych < poradie_svateho)){
		Export("NemÙûete poûadovaù t˙to modlitbu, pretoûe na dan˝ deÚ je menej sv‰t˝ch.\n");
		ALERT;
		Log("(poradie_svateho != 4) && (_global_pocet_svatych < poradie_svateho), so returning FAILURE...\n");
		return FAILURE;
	}


	/* teraz nasleduje nieco, co nahradza export
	 * -- avsak data uklada do stringu _global_string */
	Log("spustam init_global_string(EXPORT_DNA_JEDEN_DEN, svaty == %d, modlitba == %s)...\n",
		poradie_svateho, nazov_modlitby[modlitba]);
	ret = init_global_string(EXPORT_DNA_JEDEN_DEN, poradie_svateho, modlitba);

	if(ret == FAILURE){
		Log("init_global_string() returned FAILURE, so returning FAILURE...\n");
		return FAILURE;
	}

	/* urcenie dat k modlitbe */
	Log("spustam liturgicke_obdobie(%s, %d. tyzden, %s, %d. tyzden zaltara; svaty: %d)...\n",
		nazov_obdobia[_global_den.litobd],// nazov_obdobia_
		_global_den.tyzden,
		nazov_dna[_global_den.denvt],
		_global_den.tyzzal,
		poradie_svateho);
	
	Log("PRED:\t%d. %s %d\n",
		_global_den.den,
		nazov_mesiaca[_global_den.mesiac - 1],
		_global_den.rok);

	liturgicke_obdobie(_global_den.litobd, _global_den.tyzden, _global_den.denvt, _global_den.tyzzal, poradie_svateho);

	Log("-- _rozbor_dna_s_modlitbou:\n");
	Log("\t%d. %s %d, %s\n",
		_global_den.den,
		nazov_mesiaca[_global_den.mesiac - 1],
		_global_den.rok,
		_global_string);

	Log("-- _rozbor_dna_s_modlitbou(_struct_den_mesiac, int, int, int): returning SUCCESS\n");
	return SUCCESS;
}/* _rozbor_dna_s_modlitbou() */

/*---------------------------------------------------------------------*/
/* _export_rozbor_dna_buttons(int, int)
 *
 * typ - ako v _export_rozbor_dna()
 *
 * exportuje buttony pre _export_rozbor_dna()
 * int poradie_svateho: ak je 2 alebo 3, znamena to, ze ide o druheho
 * resp. tretieho svateho (ked je viac ako 1 lubovolna spomienka)
 * -- v takom pripade este pridavame premennu STR_DALSI_SVATY
 * s hodnotou 2 resp. 3
 *
 */
void _export_rozbor_dna_buttons(int typ, int poradie_svateho){
	if(typ != EXPORT_DNA_VIAC_DNI){
		char pom[MAX_STR];
		/* prerobene 13/04/2000A.D.: tlacitka niekedy linkuju iba subor, nie linku: podla _global_linky */
		if(_global_linky == ANO){
			if(poradie_svateho > 0)
				sprintf(pom, "&%s=%d", STR_DALSI_SVATY, poradie_svateho);
			else
				mystrcpy(pom, "", MAX_STR);
		}
		else{/* nezobrazovat linky */
			if((poradie_svateho >= 0) && (poradie_svateho < 5))
				sprintf(pom, "%s%d.htm", FILE_NAME_POKEC, poradie_svateho);
			else
				mystrcpy(pom, FILE_NAME_CHYBA, MAX_STR);
		}
		//Export("<center>\n");
		Export("</td>\n<td>");
		if(_global_linky == ANO){
			/* ranne chvaly -- button */
			Export("<form action=\"%s?%s=%s&%s=%d&%s=%d&%s=%d&%s=%s%s\" method=\"post\">\n",
				script_name,
				STR_QUERY_TYPE, STR_PRM_DATUM,
				STR_DEN, _global_den.den,
				STR_MESIAC, _global_den.mesiac,
				STR_ROK, _global_den.rok,
				STR_MODLITBA, STR_MODL_RANNE_CHVALY,
				pom);
		}
		else{
			Export("<form action=\"%s\">\n", pom);
		}
		Export("<input type=submit value=\"RannÈ chv·ly\">\n");
		Export("</form>\n");
		/* oddelenie */
		Export("</td>\n<td>");
		//Export("&nbsp;\n");
		/* vespery -- button */
		if(poradie_svateho != 4){
			/* spomienka panny marie v sobotu nema vespery */
		if(_global_linky == ANO){
			Export("<form action=\"%s?%s=%s&%s=%d&%s=%d&%s=%d&%s=%s%s\" method=\"post\">\n",
				script_name,
				STR_QUERY_TYPE, STR_PRM_DATUM,
				STR_DEN, _global_den.den,
				STR_MESIAC, _global_den.mesiac,
				STR_ROK, _global_den.rok,
				STR_MODLITBA, STR_MODL_VESPERY,
				pom);
		}
		else{
			Export("<form action=\"%s\">\n", pom);
		}
		Export("<input type=submit value=\"Veöpery\">\n");
		Export("</form>\n");
		}/* if(poradie_svateho != 4) */
		/* toto sa tyka buttonu 'Detaily...' */
		Export("</td>\n<td>");
		if(_global_linky == ANO){
			Export("<form action=\"%s?%s=%s&%s=%d&%s=%d&%s=%d&%s=%s%s\" method=\"post\">\n",
				script_name,
				STR_QUERY_TYPE, STR_PRM_DETAILY, /* povodne tu bolo PRM_DATUM */
				STR_DEN, _global_den.den,
				STR_MESIAC, _global_den.mesiac,
				STR_ROK, _global_den.rok,
				STR_MODLITBA, STR_MODL_DETAILY,
				pom);
			Export("<input type=submit value=\"Detaily...\">\n");
			Export("</form>\n");
		}/* ak nie zobrazovat linky na internet, tlacidlo `Detaily...' je zbytocne */
		//Export("</center>\n<p>\n");
	}/* if(typ) */
	/* inak buttony nedavam */
}/* _export_rozbor_dna_buttons */

/*---------------------------------------------------------------------*/
/* _export_rozbor_dna_buttons_dni(int, int)
 *
 * typ - ako v _export_rozbor_dna()
 *
 * exportuje buttony pre _export_rozbor_dna()
 * a to button predosleho a nasledujuceho dna
 *
 */
void _export_rozbor_dna_buttons_dni(int typ){
	if(typ != EXPORT_DNA_VIAC_DNI){
		_struct_den_mesiac datum;
		int _local_rok, i;

		Export("<center>\n");
		Export("<table>\n<tr>\n");

		/* predchadzajuci / nasledujuci den */

		/* vypocitanie predosleho dna */
		_local_rok = _global_den.rok;
		if(_global_den.den == 1){
			if(_global_den.mesiac == 1){ /* prveho januara */
				datum.mesiac = 12;
				_local_rok = _global_den.rok - 1;
			}
			else{
				datum.mesiac = _global_den.mesiac - 1;
			}
			datum.den = pocet_dni[datum.mesiac - 1];
		}
		else{
			datum.den = _global_den.den - 1;
			datum.mesiac = _global_den.mesiac;
		}
		/* predosly den -- button */
		Export("<td align=right><form action=\"%s?%s=%s&%s=%d&%s=%d&%s=%d\" method=\"post\">\n",
			script_name,
			STR_QUERY_TYPE, STR_PRM_DATUM,
			STR_DEN, datum.den,
			STR_MESIAC, datum.mesiac,
			STR_ROK, _local_rok);
		Export("<input type=submit value=\"< Predch·dzajuci deÚ\">\n");
		Export("</form></td>\n");

		/* oddelenie */
		//Export("&nbsp;");

		/* vypocitanie nasledujuceho dna */
		_local_rok = _global_den.rok;
		if(_global_den.den == pocet_dni[_global_den.mesiac - 1]){
			datum.den = 1;
			if(_global_den.mesiac == 12){
				datum.mesiac = 1;
				_local_rok = _global_den.rok + 1;
			}
			else{
				datum.mesiac = _global_den.mesiac + 1;
			}
		}
		else{
			datum.den = _global_den.den + 1;
			datum.mesiac = _global_den.mesiac;
		}

		/* nasledujuci den -- button */
		Export("<td><form action=\"%s?%s=%s&%s=%d&%s=%d&%s=%d\" method=\"post\">\n",
			script_name,
			STR_QUERY_TYPE, STR_PRM_DATUM,
			STR_DEN, datum.den,
			STR_MESIAC, datum.mesiac,
			STR_ROK, _local_rok);
		Export("<input type=submit value=\"Nasleduj˙ci deÚ >\">\n");
		Export("</form></td>\n");

		Export("</tr>\n<tr>\n");
		/* ten isty den pred rokom / o rok */

		/* vypocitanie toho isteho dna v predoslom roku */
		datum.den = _global_den.den;
		datum.mesiac = _global_den.mesiac;
		_local_rok = _global_den.rok - 1;
		if((_global_den.den == 29) && (_global_den.mesiac == 2)){
			if(!prestupny(_local_rok))
				datum.den = 28;
		}
		/* predosly rok -- button */
		Export("<td align=right><form action=\"%s?%s=%s&%s=%d&%s=%d&%s=%d\" method=\"post\">\n",
			script_name,
			STR_QUERY_TYPE, STR_PRM_DATUM,
			STR_DEN, datum.den,
			STR_MESIAC, datum.mesiac,
			STR_ROK, _local_rok);
		Export("<input type=submit value=\"<< Predch·dzaj˙ci rok\">\n");
		Export("</form></td>\n");

		/* oddelenie */
		//Export("&nbsp;");

		/* vypocitanie toho isteho dna v nasledujucom roku */
		datum.den = _global_den.den;
		datum.mesiac = _global_den.mesiac;
		_local_rok = _global_den.rok + 1;
		if((_global_den.den == 29) && (_global_den.mesiac == 2)){
			if(!prestupny(_local_rok))
				datum.den = 28;
		}
		/* nasledujuci rok -- button */
		Export("<td><form action=\"%s?%s=%s&%s=%d&%s=%d&%s=%d\" method=\"post\">\n",
			script_name,
			STR_QUERY_TYPE, STR_PRM_DATUM,
			STR_DEN, datum.den,
			STR_MESIAC, datum.mesiac,
			STR_ROK, _local_rok);
		Export("<input type=submit value=\"Nasleduj˙ci rok >>\">\n");
		Export("</form></td>\n");

		Export("</tr>\n");

		Export("</table>\n");
		Export("</center>\n");

		/* zoznam cisel dni */
		Export("<font size=-1>\n");

		Vytvor_global_link(VSETKY_DNI, _global_den.mesiac, _global_den.rok, LINK_DEN_MESIAC);
		Export("<b>%s:</b> ", _global_link);
		for(i = 1; i <= pocet_dni[_global_den.mesiac - 1]; i++){
			if(i == _global_den.den){
				if(((i + _global_den.denvt - _global_den.den) MOD 7) == 0)
					/* nedela */
					Export("<b><font color=\"#0000FF\">%d</font></b> ", i);
				else
					Export("<font color=\"#0000FF\">%d</font> ", i);
			}
			else{
				vytvor_global_link(i, _global_den.mesiac, _global_den.rok, LINK_DEN);
				if(((i + _global_den.denvt - _global_den.den) MOD 7) == 0)
					/* nedela */
					Export("<b>%s</b> ", _global_link);
				else
					Export("%s ", _global_link);
			}
		}
		Export("<br>\n");

		/* teraz zoznam mesiacov */
		Vytvor_global_link(VSETKY_DNI, VSETKY_MESIACE, _global_den.rok, LINK_DEN_MESIAC);
		Export("<b>%s:</b> ", _global_link);
		for(i = 1; i <= 12; i++){
			if(i == _global_den.mesiac){
				Export("<font color=\"#0000FF\">%s</font> ", nazov_Mesiaca[i - 1]);
			}
			else{
				Vytvor_global_link(VSETKY_DNI, i, _global_den.rok, LINK_DEN_MESIAC);
				Export("%s ", _global_link);
			}
		}

		Export("</font>\n");
	}/* if(typ) */
	/* inak buttony nedavam */
}/* _export_rozbor_dna_buttons_dni */

/*---------------------------------------------------------------------*/
/* _export_rozbor_dna()
 *
 * exportuje udaje, ktore nacitala _rozbor_dna()
 *
 */
#define NEWLINE Export("</td>\n</tr>\n\n<tr valign=baseline>\n<td></td>\n<td></td>\n<td>")
#define BUTTONS(a);	{init_global_string(typ, a);\
	Export("%s", _global_string);\
	_export_rozbor_dna_buttons(typ, a);}
void _export_rozbor_dna(int typ){
/* treba brat do uvahy:
 * 1. ked ma sviatok prioritu, tak ide on
 *    (ulozeny v _global_den, ak pocet_svatych == 0;
 *       resp. v _global_svaty1, ak pocet_svatych > 0;)
 * 2. ked su lubovolne spomienky, su ulozene v premennych
 *    _global_svaty1 (_global_pocet_svatych == 1),
 *    _global_svaty2 (_global_pocet_svatych == 2),
 *    _global_svaty3 (_global_pocet_svatych == 3),
 *    naviac treba napisat _global_den (ako vsedny den)
 * 3. ak ide o sobotu v OBD_CEZ_ROK, treba ponuknut moznost _global_pm_sobota
 *    (spomienka panny marie v sobotu)
 */
	int i;
#define MAX_PAT 5
#define MAX_DESAT 10
	char pom1[MAX_PAT] = "";
	char ciarka = 0;
	char dvojbodka = 0;
	char pom2[MAX_PAT] = "";
	char pom3[MAX_DESAT] = "";

	/* EXPORT_DNA_VIAC_DNI: predpoklada, ze sme v tabulke, <table> */
	if(typ != EXPORT_DNA_VIAC_DNI){
		Export("<table>\n");
	}
	/* vytvorenie linku */
	if(typ == EXPORT_DNA_VIAC_DNI){
		i = LINK_DEN;
		mystrcpy(pom1, "<b>", MAX_PAT);
		mystrcpy(pom2, "</b>", MAX_PAT);
		mystrcpy(pom3, nazov_Dn[_global_den.denvt], MAX_DESAT);
	}
	else{
		i = LINK_DEN_MESIAC_ROK;
/*		if(_global_den.denvt != DEN_NEDELA){
			mystrcpy(pom3, nazov_dna[_global_den.denvt], MAX_DESAT);
		}*/
		if((_global_den.denvt != DEN_NEDELA)/* &&
			(!equals(_global_den.meno, ""))*/){
			//ciarka = ',';
		}
		dvojbodka = ':';
	}
	vytvor_global_link(_global_den.den, _global_den.mesiac, _global_den.rok, i);
	/* export */
	Export("\n<tr valign=baseline>\n");

	/* prvy stlpec: cislo dna */
	Export("<td><div align=right>%s%s%s%c</div></td>\n",
		pom1, _global_link, pom2, dvojbodka);

	/* druhy stlpec: nazov dna */
	Export("<td><div align=left>%s%s%s%c</div></td>\n",
		pom1, pom3, pom2, ciarka);
	Export("<td>");

	/* pozor, hoci je nedela, predsa na nu mohlo pripadnut slavenie s vyssou
	 * prioritou */
	if((_global_den.denvt == DEN_NEDELA) ||
		(_global_den.prik == PRIKAZANY_SVIATOK) ||
		(_global_den.smer < 5)){
		/* nedele a prikazane sviatky - cervenou, velkymi pismenami */
		/* slavnosti - velkymi pismenami */

		/* 23/02/2000A.D. -- teraz este testujeme, ci nema nahodou pred nedelou
		 * (trebars v obdobi cez rok, smer == 6)
		 * prednost napr. sviatok Pana (smer == 5); dalsia cast je skopirovana
		 * podla casti v _rozbor_dna, v poznamke SVATY_VEDIE
		 */
		/* ... alebo c. 60: "ak na jeden den pripadnu viacere slavenia,
		 * uprednostni sa to, ktore ma v tabulke liturgickych dni vyssi stupen
		 * [t.j. .smer]. */
		if(_global_den.smer > _global_svaty1.smer){
			BUTTONS(1);
		}
		else{
			BUTTONS(0);
		}
	}/* if((_global_den.denvt == DEN_NEDELA) || (_global_den.prik == PRIKAZANY_SVIATOK) || (_global_den.smer < 5)) */
	else if(_global_pocet_svatych > 0){
		/* sviatky (spomienky, ls) svatych */
		if((_global_den.smer > _global_svaty1.smer) ||
			(_global_den.smer == 9) && (_global_svaty1.smer == 12)){
		/* svaty */
			BUTTONS(1);
			if(_global_pocet_svatych > 1){
				NEWLINE;
				BUTTONS(2);
				if(_global_pocet_svatych > 2){
					NEWLINE;
					BUTTONS(3);
				}
			}
			if((_global_svaty1.smer >= 12) &&
				(typ != EXPORT_DNA_VIAC_DNI)){
				/* ak je to iba lubovolna spomienka, tak vsedny den */
				NEWLINE;
				BUTTONS(0);
			}
		}/* svaty ma prednost */
		else{
		/* prednost ma den */
			BUTTONS(0);
		}
	}/* if(_global_pocet_svatych > 0) */
	else{
		/* obycajne dni, nie sviatok */
		BUTTONS(0);
	}/* if(equals(_global_den.meno, "")) */

	/* este spomienka panny marie v sobotu, cl. 15 */
	if((_global_den.litobd == OBD_CEZ_ROK) &&
		(_global_den.denvt == DEN_SOBOTA) &&
		(
			((_global_den.smer >= 12) && (_global_pocet_svatych == 0)) ||
			((_global_svaty1.smer >= 12) && (_global_pocet_svatych > 0))) &&
		(typ != EXPORT_DNA_VIAC_DNI)){
		NEWLINE;
		BUTTONS(4);
	}

	Export("</td>\n<td><div align=right>");
	/* vypisanie rimskeho cisla (citanie) */
	if(typ == EXPORT_DNA_VIAC_DNI)
		Export("%s", _global_string2);
	Export("</div>");


	Export("</td>\n</tr>\n");
	/* EXPORT_DNA_VIAC_DNI: predpoklada, ze sme v tabulke, <table> */
	if(typ != EXPORT_DNA_VIAC_DNI){
		Export("</table>\n");
	}

	/* vypisanie buttonov predchadzajuceho a nasledujuceho dna */
	if(typ !=  EXPORT_DNA_VIAC_DNI){
		if(_global_linky == ANO){ /* pridane 13/04/2000A.D. */
			_export_rozbor_dna_buttons_dni(typ);
		}
	}
}/* _export_rozbor_dna() */

/* showDetails():
 * vytvorena v Trencine, 29/01/2000A.D. */
/* vyskusat Run -> Arguments...:
 * `-qpdt -r2000 -m1 -d20 -x1 -p* -1nie -2sviatku' */
/*---------------------------------------------------------------------*/
/*
 * ked stlaci button 'Detaily...' pri konretnej modlitbe,
 * zavola sa z funkcie rozbor_dna_s_modlitbou() toto vypisanie
 * detailov (options) pre konretnu modlitbu
 *
 * vela z jadra je prevzateho z funkcie _main_dnes()
 *
 */
void showDetails(int den, int mesiac, int rok, int poradie_svaty){

	Log("spustam showDetails(%d, %s, %d, %d)...\n", den,
		nazov_mesiaca[mesiac - 1], rok, poradie_svaty);
	Log("_global_den: \n");
	Log(_global_den);

	Export("<hr size=1>\n");
	Export("NasledovnÈ moûnosti ovplyvnia vzhæad i obsah vygenerovanej modlitby.\n");
	Export("Vyberte tie, podæa ktor˝ch sa m· modlitba vygenerovaù.\n");
	Export("<br>\n");
	Export("<form action=\"%s?%s=%s&%s=%d&%s=%d&%s=%d&%s=%d\" method=\"post\">\n",
		uncgi_name,
		STR_QUERY_TYPE, STR_PRM_DATUM, /* chvilu tu bolo PRM_DETAILY */
		STR_DEN, den,
		STR_MESIAC, mesiac,
		STR_ROK, rok,
		STR_DALSI_SVATY, poradie_svaty);
	/* historicka poznamka: kym nebol program (funkcia main()) upraveny tak,
	 * zeby umoznoval aj `mixovane dotazy' (nieco je v query stringu, nieco
	 * je z formulara -- ako je to vyssie a nizsie teraz --, tak bolo treba
	 * nepopularne trapne vytlacit na obrazovku prenasane udaje, ako svedci
	 * tento -- uz nepouzivany -- kus kodu:
	 *
	Export("<input type=radio name=\"%s\" value=\"%s\" checked>",
		STR_QUERY_TYPE, STR_PRM_DATUM);
	Export("%s\n", _global_string);
	Export("<br>\n");
	// pole WWW_DEN
	Export("(<select name=\"%s\">\n", STR_DEN);
	Export("<option selected>%d", den);
	Export("\n</select>.\n");
	// pole WWW_MESIAC
	Export("<select name=\"%s\">\n", STR_MESIAC);
	Export("<option selected>%s", nazov_mesiaca[mesiac - 1]);
	Export("\n</select>&nbsp;\n");

	// pole WWW_ROK
	Export("<select name=\"%s\">\n", STR_ROK);
	Export("<option selected>%d", rok);
	Export("\n</select>)\n");

	// pole WWW_DALSI_SVATY
	Export("(<select name=\"%s\">\n", STR_DALSI_SVATY);
	Export("<option selected>%d", poradie_svaty);
	Export("\n</select>)\n");
	 *
	 * -- koniec historickej poznamky :-)
	 */
	Export("<ul>\n");

	Export("<li>modlitba \n");
	/* pole WWW_MODLITBA */
	Export("<select name=\"%s\">\n", STR_MODLITBA);
	Export("<option selected>%s\n", nazov_modlitby[MODL_RANNE_CHVALY]);
	/* spomienka P. Marie v sobotu nema vespery */
	if(poradie_svaty != 4)
		Export("<option>%s\n", nazov_modlitby[MODL_VESPERY]);
	Export("</select>\n");
	Export("</li>\n");

	Export("<li>zobraziù <i>nemennÈ s˙Ëasti</i> modlitby?\n");
	/* pole WWW_MODL_OPT1 */
	Export("<select name=\"%s\">\n", STR_MODL_OPT1);
	Export("<option>%s\n", STR_ANO);
	Export("<option selected>%s\n", STR_NIE);
	Export("</select>\n");
	Export("<br>(kaûdÈ rannÈ chv·ly obsahuj˙ Benediktus, veöpery Magnifikat, ");
	Export("obe modlitby OtËen·ö a zakonËenie modlitby; tieto ");
	Export("Ëasti modlitby naz˝vame <i>nemennÈ s˙Ëasti</i>)");
	Export("</li>\n");

	if((poradie_svaty > 0) && (poradie_svaty < 4)){

		Export("<li>zobraziù <i>popis</i> k modlitbe sv‰tÈho?\n");
		/* pole WWW_MODL_OPT4 */
		Export("<select name=\"%s\">\n", STR_MODL_OPT4);
		Export("<option>%s\n", STR_ANO);
		Export("<option selected>%s\n", STR_NIE);
		Export("</select>\n");
		Export("<br>(rannÈ chv·ly a veöpery zv‰Ëöa obsahuj˙ pred n·zvom modlitby ");
		Export("ûivotopis sv‰tÈho, popis sviatku alebo podobn˙ struËn˙ charakteristiku, ");
		Export("ktor˙ naz˝vame <i>popis</i>)");
		Export("</li>\n");

	/* pole WWW_MODL_OPT2 */
		Export("<li>braù ûalmy zo \n");
		Export("<select name=\"%s\">\n", STR_MODL_OPT2);
		Export("<option selected>%s\n", STR_MODL_ZALMY_ZO_DNA);
		Export("<option>%s\n", STR_MODL_ZALMY_ZO_SV);
		Export("</select>\n");
		Export("<br>(na sviatok sv‰tÈho sa podæa liturgick˝ch pravidiel ber˙ ûalmy ");
		Export("zo sviatku, öpeci·lne na rannÈ chv·ly öpeci·lne z nedele 1. t˝ûdÚa ûalt·ra; ");
		Export("avöak niekto sa radöej modlÌ ûalmy zo vöednÈho dÚa)");
		Export("</li>\n");

		/* najprv si rozkodujeme, co je v _global_den.spolcast */
		_struct_sc sc = _decode_spol_cast(_global_den.spolcast);
		/* pole WWW_MODL_OPT3 */
		Export("<li>Ëasti modlitby zo spoloËnej Ëasti \n");
		Export("<select name=\"%s\">\n", STR_MODL_OPT3);
		if((sc.a1 != MODL_SPOL_CAST_NEURCENA) && (sc.a1 != MODL_SPOL_CAST_NEBRAT)){
			Export("<option selected>%s\n", nazov_spolc[sc.a1]);
			if(sc.a2 != MODL_SPOL_CAST_NEURCENA){
				Export("<option>%s\n", nazov_spolc[sc.a2]);
				if(sc.a3 != MODL_SPOL_CAST_NEURCENA){
					Export("<option>%s\n", nazov_spolc[sc.a3]);
				}
			}
			Export("<option>%s\n", nazov_spolc[MODL_SPOL_CAST_NEBRAT]);
		}
		else{
			Export("<option selected>%s\n", nazov_spolc[MODL_SPOL_CAST_NEBRAT]);
		}
		Export("</select>\n");
		Export("<br>(na sviatok sv‰tÈho sa podæa liturgick˝ch pravidiel ber˙ Ëasti, ");
		Export("ktorÈ sa nenach·dzaj˙ vo vlastnej Ëasti ûalt·ra, zo spoloËnej Ëasti sviatku, ");
		Export("niekedy je moûnosù vybraù si z viacer˝ch spoloËn˝ch ËastÌ; naviac je moûnosù niekto sa modliù sa tieto Ëasti zo vöednÈho dÚa)");
		Export("</li>\n");
	}

	/* tu bude treba urobit porovnanie s nejakou premennou, ktora obsahuje
	 * to, ze pre sviatok svateho je viac moznosti, odkial brat veci zo
	 * `spolocnej casti na sviatky svatych'
	 */

	Export("</ul>\n");

	Export("<br>\n");
	Export("<center>\n");
	/* button Vyhladaj (GO!) */
	Export("<input type=submit value=\"Zobraz modlitbu\">");

	/* button Vycisti (CLEAR!) */
	Export("&nbsp;&nbsp;&nbsp;\n");
	Export("<input type=reset value=\"PÙvodnÈ hodnoty\">");

	Export("</center>\n</form>\n");

	Log("showDetails(%d, %s, %d, %d) -- end\n", den,
		nazov_mesiaca[mesiac - 1], rok, poradie_svaty);

}/* showDetails(); */

/*---------------------------------------------------------------------*/
/* rozbor_dna_s_modlitbou(int, int, int, int)
 *
 * skoro ako rozbor_dna(), avsak dostane este int, ktory oznacuje
 * modlitbu; a int, ktory oznacuje poradie svateho, ak je ich viac (2,3).
 * pracuje nasledovne:
 *
 * - kvoli prvym vesperam nasledujuceho dna spusti analyzuj_rok(rok + 1);
 * - spusti _rozbor_dna(datum + 1, ???) (rok alebo rok + 1, podla dna)
 * - ulozi vysledok do lokalnej premennej _local_den, _local_svaty...
 * - spusti analyzuj_rok(rok);
 * - spusti _rozbor_dna(datum, rok);
 * - porovna, ci (ked su modlitbou vespery) budu prve vespery z dalsieho dna
 *   alebo nie,
 * - napokon !!! spusti vytvorenie modlitby
 *
 *
 * POZOR! Narozdiel od rozbor dna, pred samotnym spustenim generovania
 * modlitby je vysledok (co sa presne bude modlit) v premennej _global_den;
 *
 */
void rozbor_dna_s_modlitbou(int den, int mesiac, int rok, int modlitba, int poradie_svaty){
	int ret = SUCCESS;

	/* lokalne premenne, v ktorych sa pamata to, co vrati _rozbor_dna() */
	/* lokalna premenna, do ktorej sa ukladaju info o analyzovanom dni
	 * pouziva ju void nove_rozbor_dna() funkcia */
	_struct_dm _local_den;

	/* lokalne premenne obsahujuce data modlitbach -- 23/02/2000A.D.
	 * prerobene, aby sa alokovali dynamicky */
#define POKUS_24_02_2000
#ifdef POKUS_24_02_2000
	_type_1vespery      _local_modl_prve_vespery;
	_type_1kompletorium _local_modl_prve_kompletorium;
#else
	_type_1vespery      *_local_modl_prve_vespery_ptr;
#define _local_modl_prve_vespery (*_local_modl_prve_vespery_ptr)
	_type_1kompletorium *_local_modl_1kompletorium_ptr;
#define _local_modl_prve_kompletorium (*_local_modl_1kompletorium_ptr)
	_type_vespery       *_local_modl_vespery_ptr;
#define _local_modl_vespery (*_local_modl_vespery_ptr)
	_type_kompletorium *_local_modl_kompletorium_ptr;
#define _local_modl_kompletorium (*_local_modl_kompletorium_ptr)

	Log("Allocating memory...\n");
/* _local_modl_prve_vespery_ptr */
	if((_local_modl_prve_vespery_ptr = (_type_1vespery*) malloc(sizeof(_type_1vespery))) == NULL){
		Log("  Not enough memory to allocate buffer for `_local_modl_prve_vespery_ptr'\n");
		return;
	}
	else{
		Log("  %d bytes for `_local_modl_prve_vespery_ptr'\n", sizeof(_type_1vespery));
	}

/* _local_modl_1kompletorium_ptr */
	if((_local_modl_1kompletorium_ptr = (_type_1kompletorium*) malloc(sizeof(_type_1kompletorium))) == NULL){
		Log("  Not enough memory to allocate buffer for `_local_modl_1kompletorium_ptr'\n");
		return;
	}
	else{
		Log("  %d bytes for `_local_modl_1kompletorium_ptr'\n", sizeof(_type_1kompletorium));
	}
/* _local_modl_vespery_ptr */
	if((_local_modl_vespery_ptr = (_type_vespery*) malloc(sizeof(_type_vespery))) == NULL){
		Log("  Not enough memory to allocate buffer for `_local_modl_vespery_ptr'\n");
		return;
	}
	else{
		Log("  %d bytes for `_local_modl_vespery_ptr'\n", sizeof(_type_vespery));
	}

/* _local_modl_kompletorium_ptr */
	if((_local_modl_kompletorium_ptr = (_type_kompletorium*) malloc(sizeof(_type_kompletorium))) == NULL){
		Log("  Not enough memory to allocate buffer for `_local_modl_kompletorium_ptr'\n");
		return;
	}
	else{
		Log("  %d bytes for `_local_modl_kompletorium_ptr'\n", sizeof(_type_kompletorium));
	}

	Log("...done.\n");
#endif /* pokus 24/02/2000A.D., mozno to nebude padat */

	/* lokalna kopia roka; ak treba analyzovat dalsi rok */
	int _local_rok = -1; /* inicializacia dorobena 01/03/2000A.D. */

	/* lokalna premenna, co obsahuje string vypisany na obsazovku */
	char _local_string[MAX_STR];

	char pom[MAX_STR];

	_global_modlitba = modlitba;

	Log("-- rozbor_dna_s_modlitbou(int, int, int, int, int): begin (%d.%d %d, %d; %d)\n",
		den, mesiac, rok, modlitba, poradie_svaty);
	_struct_den_mesiac datum;

	if((modlitba == MODL_VESPERY) || (modlitba == MODL_KOMPLETORIUM)){
		/* najprv analyzujem nasledujuci den - kvoli prvym vesperam resp. kompletoriu */
		_local_rok = rok;
		if(den == pocet_dni[mesiac - 1]){
			datum.den = 1;
			if(mesiac == 12){
				datum.mesiac = 1;
				_local_rok = rok + 1;
			}
			else{
				datum.mesiac = mesiac + 1;
			}
		}
		else{
			datum.den = den + 1;
			datum.mesiac = mesiac;
		}
		Log("spustam analyzu roka (rok %d)...\n", _local_rok);
		analyzuj_rok(_local_rok); /* vysledok da do _global_r */
		LOG_ciara;
		Log("spustam analyzu nasledujuceho dna (%d. %s %d)...\n",
			datum.den, nazov_mesiaca[datum.mesiac - 1], _local_rok);
		ret = _rozbor_dna_s_modlitbou(datum, _local_rok, modlitba, UNKNOWN_PORADIE_SVATEHO);
		if(ret == FAILURE){
			Log("_rozbor_dna_s_modlitbou() returned FAILURE, so...\n");
			Log("-- rozbor_dna_s_modlitbou(int, int, int, int): uncomplete end\n");
			goto LABEL_s_modlitbou_DEALLOCATE;
		}
		Log("analyza nasledujuceho dna (%d. %s %d) skoncila.\n",
			datum.den, nazov_mesiaca[datum.mesiac - 1], rok);
		LOG_ciara;
		/* teraz mam vsetky data v _global_den, _global_modl_... */

		_local_den = _global_den;
		/* neviem, ci tam ma byt _global_modl_[prve_]vespery ... */
		/* 23/02/2000A.D. -- prirobil som aj bez _prve_ */
		_local_modl_prve_vespery = _global_modl_prve_vespery;
		_local_modl_prve_kompletorium = _global_modl_prve_kompletorium;
#ifndef POKUS_24_02_2000
		_local_modl_vespery = _global_modl_vespery;
		_local_modl_kompletorium = _global_modl_kompletorium;
#endif
		mystrcpy(_local_string, _global_string, MAX_STR);
	}/* kompletorium alebo vespery */

	/* teraz analyzujem dnesny den */
	datum.den = den;
	datum.mesiac = mesiac;
	if(_local_rok != rok){
		Log("spustam analyzu roka (rok %d)...\n", rok);
		analyzuj_rok(rok); /* vysledok da do _global_r */
	}
	Log("spustam analyzu tohto dna (%d. %s %d)...\n",
		datum.den, nazov_mesiaca[datum.mesiac - 1], rok);
	ret = _rozbor_dna_s_modlitbou(datum, rok, modlitba, poradie_svaty);
	if(ret == FAILURE){
		Log("_rozbor_dna_s_modlitbou() returned FAILURE, so...\n");
		Log("-- rozbor_dna_s_modlitbou(int, int, int, int): uncomplete end\n");
		goto LABEL_s_modlitbou_DEALLOCATE;
	}
	Log("analyza tohto dna (%d. %s %d) skoncila.\n",
		datum.den, nazov_mesiaca[datum.mesiac - 1], rok);
	LOG_ciara;
	/* teraz mam vsetky data v _global_den, _global_modl_... */
#ifndef POKUS_24_02_2000
//#define DEBUG_23_02_2000
#ifdef DEBUG_23_02_2000
	Log("_local_modl_prve_vespery:\n"); Log(_local_modl_prve_vespery);
	Log("_local_modl_vespery:\n"); Log(_local_modl_vespery);
	Log("_global_modl_prve_vespery:\n"); Log(_global_modl_prve_vespery);
	Log("_global_modl_vespery:\n"); Log(_global_modl_vespery);
#endif
#endif
	/* ak ma nasledujuci den prioritu pred dnesnym dnom */
	if((modlitba == MODL_VESPERY) || (modlitba == MODL_KOMPLETORIUM)){
		Log("teraz uvidime, ci vespery/kompletorium nasledovneho dna nemaju nahodou prioritu...\n");

		/* netyka sa to zeleneho stvrtka, velkeho tyzdna, velkonocneho trojdnia, ... 08/03/2000A.D. */
		if(_global_den.denvr == (_global_r._VELKONOCNA_NEDELA.denvr - 3)){
			Log("netyka sa to zeleneho stvrtka\n");
			goto LABEL_NIE_INE_VESPERY;
		}
		else if((_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN) && (_global_den.denvt != DEN_NEDELA)){
			Log("netyka sa to velkeho tyzdna (okrem druhych vespier kvetnej nedele)\n");
			goto LABEL_NIE_INE_VESPERY;
		}
		else if(_global_den.litobd == OBD_VELKONOCNE_TROJDNIE){
			Log("netyka sa to velkonocneho trojdnia\n");
			goto LABEL_NIE_INE_VESPERY;
		}
		/* ...a tiez sa to netyka popolcovej stredy, 09/03/2000A.D. */
		if((_global_den.denvr == _global_r._POPOLCOVA_STREDA.denvr) || ((_global_den.denvr == (_global_r._POPOLCOVA_STREDA.denvr - 1)))){
			/* preto aj POS aj POS - 1, lebo prve aj druhe vespery */
			Log("netyka sa to popolcovej stredy\n");
			goto LABEL_NIE_INE_VESPERY;
		}
		/* ...a tiez sa to netyka dni velkonocnej oktavy okrem nedele, 09/03/2000A.D. */
		if((_global_den.litobd == OBD_VELKONOCNA_OKTAVA) && (_global_den.denvt != DEN_SOBOTA) && (_global_den.denvt != DEN_NEDELA)){
			/* sobota kvoli prvym vesperam */
			Log("netyka sa to vsednych dni velkonocnej oktavy\n");
			goto LABEL_NIE_INE_VESPERY;
		}

		/* 23/02/2000A.D.: kedze nefungovali prave sviatky Pana a slavnosti,
		 * co pripadli na nedelu, tak to bolo treba preskumat */
		Log("dalsi den (%d.%d): _local_den.smer == %d, _local_den.denvt == %s, _local_den.litobd == %s (%d)\n",
			_local_den.den, _local_den.mesiac,
			_local_den.smer, nazov_dna[_local_den.denvt], nazov_obdobia[_local_den.litobd], _local_den.smer);
		//Log(_local_den);
		Log("tento den (%d.%d): _global_den.smer == %d, _global_den.denvt == %s, _global_den.litobd == %s (%d)\n",
			_global_den.den, _global_den.mesiac,
			_global_den.smer, nazov_dna[_global_den.denvt], nazov_obdobia[_global_den.litobd], _global_den.smer);
		//Log(_global_den);

		/* if VYNIMKY: porov. nizsie. 14/03/2000A.D. */
		if((_global_den.smer > _local_den.smer) ||
			((_global_den.smer == _local_den.smer) && 
				(
					((_global_den.litobd == OBD_VELKONOCNA_OKTAVA) && (_global_den.denvt == DEN_SOBOTA)) ||/* 2. velkonocna nedela, pridane 09/03/2000A.D. */
					((_local_den.mesiac - 1 == MES_DEC) && (_local_den.den == 25)) /* ked narodenie pana pripadne na pondelok, tak prve vespery maju prednost pred 4. adventnou nedelou; napr. rok 2000, pridane 14/03/2000A.D. */
				)
			)
		){
			Log("jumping to LABEL_ZMENA...\n");
			goto LABEL_ZMENA;
		}

		if((_global_den.smer < 5) ||
			/* cl. 11: slavnosti su zvlast vyznacnymi dnami. ich slavenie
			 * sa zacina prvymi vesperami v predchadzajuci den. */
			((_global_den.smer == 5) && (_global_den.denvt == DEN_NEDELA) &&
					((_global_den.litobd == OBD_CEZ_ROK) ||
					 (_global_den.litobd == OBD_VIANOCNE_I) ||
					 (_global_den.litobd == OBD_VIANOCNE_II))) ||
			/* cl. 13: sviatky sa slavia v rozsahu jedneho dna, a preto nemaju
			 * prve vespery, ak len nejde o sviatky pana, ktore pripadaju na
			 * nedelu v obdobi ,,cez rok" a na nedelu vo vianocnom obdobi
			 * a nahradzuju nedelnajsiu liturgiu hodin. */
			(_global_den.denvt == DEN_NEDELA)
			/* nedela */
		){
			/* cl. 61: ak na ten isty den pripadnu vespery bezneho dna
			 * a prve vespery nasledujuceho dna, maju prednost vespery slavenia,
			 * ktore ma v tabulke liturgickych dni vyssi stupen. v pripade
			 * rovnosti sa beru vespery bezneho dna. */

			if(modlitba == MODL_VESPERY){
				_global_modlitba = MODL_DRUHE_VESPERY;
				Log("-- MODL_DRUHE_VESPERY\n");
			}
			else if(modlitba == MODL_KOMPLETORIUM){
				_global_modlitba = MODL_DRUHE_KOMPLETORIUM;
				Log("-- MODL_DRUHE_KOMPLETORIUM\n");
			}
			if((_global_den.den == 2) && (_global_den.mesiac - 1 == MES_NOV) && (_global_modlitba == MODL_DRUHE_VESPERY))
				Log("Spomienka vsetkych vernych zosnulych -- nevypisem, ze su druhe vespery...\n");
			else{
				sprintf(pom, " (%s)", nazov_Modlitby[_global_modlitba]);
				strcat(_global_string, pom);
			}
		}/* _global_den ma dvoje vespery/kompletorium, teda musime brat DRUHE */

		else
LABEL_ZMENA:
			if((_local_den.smer < 5) ||
			/* cl. 11: slavnosti su zvlast vyznacnymi dnami. ich slavenie
			 * sa zacina prvymi vesperami v predchadzajuci den. */
			((_local_den.smer == 5) && (_local_den.denvt == DEN_NEDELA) &&
					((_local_den.litobd == OBD_CEZ_ROK) ||
					 (_local_den.litobd == OBD_VIANOCNE_I) ||
					 (_local_den.litobd == OBD_VIANOCNE_II))) ||
			/* cl. 13: sviatky sa slavia v rozsahu jedneho dna, a preto nemaju
			 * prve vespery, ak len nejde o sviatky Pana, ktore pripadaju na
			 * nedelu v obdobi ,,cez rok" a na nedelu vo vianocnom obdobi
			 * a nahradzuju nedelnajsiu liturgiu hodin. */
			(_local_den.denvt == DEN_NEDELA)
			/* nedela */
		){
			/* cl. 61: ak na ten isty den pripadnu vespery bezneho dna
			 * a prve vespery nasledujuceho dna, maju prednost vespery slavenia,
			 * ktore ma v tabulke liturgickych dni vyssi stupen. v pripade
			 * rovnosti sa beru vespery bezneho dna. */
			/* tento if je kopirovany z vyssieho, VYNIMKY */
			if((_global_den.smer > _local_den.smer) ||
				((_global_den.smer == _local_den.smer) && 
					(
						((_global_den.litobd == OBD_VELKONOCNA_OKTAVA) && (_global_den.denvt == DEN_SOBOTA)) ||/* 2. velkonocna nedela, pridane 09/03/2000A.D. */
						((_local_den.mesiac - 1 == MES_DEC) && (_local_den.den == 25)) /* ked narodenie pana pripadne na pondelok, tak prve vespery maju prednost pred 4. adventnou nedelou; napr. rok 2000, pridane 14/03/2000A.D. */
					)
				)
			){
				Log("priradujem %s z dalsieho dna\n",
					nazov_Modlitby[modlitba]);
				_global_den = _local_den;
				_global_modl_vespery = _local_modl_prve_vespery;
				_global_modl_kompletorium = _local_modl_prve_kompletorium;
				//???
				_global_modl_prve_vespery = _local_modl_prve_vespery;
				_global_modl_prve_kompletorium = _local_modl_prve_kompletorium;
				//??? -- divna pasaz!!!
				/* !!! begin: docasny vypis - 16/02/2000A.D. */
				Log("prve vespery:\n");
				Log(_global_modl_prve_vespery);
				Log("vespery:\n");
				Log(_global_modl_vespery);
				/* !!! end: docasny vypis - 16/02/2000A.D. */

				if(modlitba == MODL_VESPERY){
					_global_modlitba = MODL_PRVE_VESPERY;
					Log("-- MODL_PRVE_VESPERY\n");
					/* pridane 16/02/2000A.D. */
					_global_modl_vespery = _global_modl_prve_vespery;
					_global_modl_kompletorium = _global_modl_prve_kompletorium;
				}
				else if(modlitba == MODL_KOMPLETORIUM){
					_global_modlitba = MODL_PRVE_KOMPLETORIUM;
					Log("-- MODL_PRVE_KOMPLETORIUM\n");
					/* pridane 16/02/2000A.D. */
					_global_modl_vespery = _global_modl_prve_vespery;
					_global_modl_kompletorium = _global_modl_prve_kompletorium;
				}
				mystrcpy(_global_string, _local_string, MAX_STR);
				sprintf(pom, " (%s)", nazov_Modlitby[_global_modlitba]);
				strcat(_global_string, pom);
			}
		}/* _local_den ma dvoje vespery/kompletorium, teda musime brat PRVE */
	}/* vespery alebo kompletorium */

LABEL_NIE_INE_VESPERY: /* 08/03/2000A.D. */

	LOG_ciara;
	Log("/* vypisanie udajov, podla ktorych vlastne budem generovat modlitbu */\n");
	Log("/* datum bol vypisany uz predtym, preto teraz (pri prvych vesperach) \n");
	Log(" * moze byt iny - o jeden den vacsi */\n");
	Log("_global_string: %s\n", _global_string);
	Log("%s\n", nazov_modlitby[modlitba]);
	switch(modlitba){
		case MODL_RANNE_CHVALY:
			Log(_global_modl_ranne_chvaly);
			break;
		case MODL_VESPERY:
			Log(_global_modl_vespery);
			break;
	}
/*	Log("_global_den:\n");	Log(_global_den); */

	_export_heading3(_global_string);

	if(_global_modlitba == MODL_DETAILY){
		Log("spustam showDetails(%d, %s, %d, %d) z funkcie rozbor_dna_s_modlitbou():\n",
			den, nazov_mesiaca[mesiac - 1], rok, poradie_svaty);
		showDetails(den, mesiac, rok, poradie_svaty);
	}
	else{
		Log("spustam showPrayer(%s)...\n",
			nazov_Modlitby[_global_modlitba]);
		/* predpokladam, ze aj _global_modlitba je prve/druhe vespery,
		 * v _global_prve_vespery su spravne udaje (podobne kompletorium) */
		showPrayer(modlitba);
	}

LABEL_s_modlitbou_DEALLOCATE:
#ifndef POKUS_24_02_2000
	Log("Deallocating memory...\n");
	Log("_local_modl_prve_vespery_ptr\n"); free(_local_modl_prve_vespery_ptr);
	Log("_local_modl_1kompletorium_ptr\n"); free(_local_modl_1kompletorium_ptr);
	Log("_local_modl_vespery_ptr\n"); free(_local_modl_vespery_ptr);
	Log("_local_modl_kompletorium_ptr\n"); free(_local_modl_kompletorium_ptr);
	Log("...done.\n");
#endif
	Log("-- rozbor_dna_s_modlitbou(int, int, int, int): ret == %d\n", ret);
}/* rozbor_dna_s_modlitbou() */

/*---------------------------------------------------------------------*/
/* rozbor_dna(int, int, int)
 *
 * dostane 3 inty,
 * spusti analyzuj_rok();
 * potom spusti _/rozbor_dna();
 *
 */
void rozbor_dna(int den, int mesiac, int rok){
	int ret;
	Log("-- rozbor_dna(int, int, int): begin (%d.%d %d)\n", den, mesiac, rok);
	_struct_den_mesiac datum;
	datum.den = den;
	datum.mesiac = mesiac;
	analyzuj_rok(rok); /* vysledok da do _global_r */

	ret = _rozbor_dna(datum, rok);
	if(ret == FAILURE){
		Log("_rozbor_dna() returned FAILURE, so...\n");
		Log("-- rozbor_dna(int, int, int): uncomplete end\n");
		return;
	}
	_export_rozbor_dna(EXPORT_DNA_JEDEN_DEN);

	Log("-- rozbor_dna(int, int, int): end\n");
}

/*---------------------------------------------------------------------*/
/* rozbor_mesiaca(int, int)
 *
 * dostane cislo mesiaca (1--12) a rok,
 * spusti analyzuj_rok();
 * potom pre vsetky dni spusti _rozbor_dna();
 *
 */
void rozbor_mesiaca(int mesiac, int rok){
	Log("-- _main_rozbor_mesiaca(int, int): begin (%d %d)\n", mesiac, rok);
	_struct_den_mesiac datum;
	datum.mesiac = mesiac;
	analyzuj_rok(rok); /* vysledok da do _global_r */
	Export("\n<br>\n<table>\n");
	for(datum.den = 1; datum.den <= pocet_dni[mesiac - 1]; datum.den++){
		_rozbor_dna(datum, rok);
		_export_rozbor_dna(EXPORT_DNA_VIAC_DNI);
	}
	Export("\n</table>\n\n");
	Log("-- rozbor_mesiaca(int, int): end\n");
}

/*---------------------------------------------------------------------*/
/* _main_rozbor_dna(char *, char *, char *, char *, char *)
 *
 * dostane 3 stringy (datum) + mozno 2 striny (modlitba, dalsi_svaty),
 * prekonvertuje ich a skontroluje
 * ak je vsetko ok,
 * vykona _main_rozbor_dna(int, int, int) resp. _main_rozbor_mesiaca(int)
 * resp. cely rok, 12krat rozbor_mesiaca(int)
 */
#define ExportUDAJE	result = FAILURE; if(!heading_written){_export_heading(1, "Rozbor dÚa"); heading_written = 1;} Log("error: Nevhodne udaje\n"); Export("NevhodnÈ ˙daje: "); Export
void _main_rozbor_dna(char *den, char *mesiac, char *rok, char *modlitba, char *poradie_svaty){
	int heading_written = 0;
	char pom[MAX_STR];
	Log("-- rozbor_dna(char *, char *, char *, char *, char *): begin (%s, %s, %s, %s, %s)\n",
		den, mesiac, rok, modlitba, poradie_svaty);
	int d, m, r, p, s;
	int pm, pr; /* pomocny mesiac, pomocny rok */

	/* rozparsovanie parametrov den, mesiac, rok, svaty */
	Log("/* rozparsovanie parametrov den, mesiac, rok, svaty */\n");
	d = atoden(den); /* vrati VSETKY_DNI, resp. atoi(den) */
   Log("den == `%s' (%d)\n", den, d);
	m = atomes(mesiac); /* bude to 0--11, resp. VSETKY_MESIACE resp. UNKNOWN_MESIAC */
	Log("mes == `%s' (%d)\n", mesiac, m);
	r = atoi(rok); /* vrati 0 v pripade chyby; alebo int */
	Log("rok == `%s' (%d)\n", rok, r);
	s = atoi(poradie_svaty); /* ak je viac svatych, ktory z nich (1--3) */
	Log("sv == `%s' (%d)\n", poradie_svaty, s);

	/* rozparsovanie parametra modlitba */
	Log("/* rozparsovanie parametra modlitba */\n");
	if(equals(modlitba, ""))
		p = MODL_NEURCENA;
	else if(equals(modlitba, STR_MODL_DETAILY))
		p = MODL_DETAILY;
/*	else if(equals(modlitba, STR_MODL_INVITATORIUM))
		p = MODL_INVITATORIUM;*/
	else if(equals(modlitba, STR_MODL_RANNE_CHVALY))
		p = MODL_RANNE_CHVALY;
	else if(equals(modlitba, STR_MODL_VESPERY))
		p = MODL_VESPERY;
/*	else if(equals(modlitba, STR_MODL_KOMPLETORIUM))
		p = MODL_KOMPLETORIUM; */
	else /* !!! zatial len predosle */
		p = MODL_NEURCENA;
	/* este treba skontrolovat, ci nazov modlitby nie je
	 * string ...azov_modlitby[...] */
	if(p == MODL_NEURCENA){
		/* postupne porovnavame s troma konstantami,
		 * nazov_[modlitby|Modlitby|MODLITBY],
		 * a to pre konstanty MODL_INVITATORIUM -- MODL_DETAILY (vratane)
		 */
		for(int i = MODL_INVITATORIUM; i <= MODL_DETAILY; i++){
			if(equals(modlitba, nazov_modlitby[i]) ||
				equals(modlitba, nazov_Modlitby[i]) /*||
				equals(modlitba, nazov_MODLITBY[i])*/){
				/* ak je zhoda, potom prirad do p a ukonci `for' */
				p = i;
				break;
			}
		}
	}
	_global_modlitba = p;
	Log("modl == %s (%d, %s) -- priradene do _global_modlitba\n", modlitba, p, nazov_modlitby[p]);

	/* rozparsovanie parametrov opt1...opt3 */
	Log("/* rozparsovanie parametrov opt1...opt3 */\n");

	/* option 1 */
	if(equals(pom_MODL_OPT1, STR_ANO) || equals(pom_MODL_OPT1, "1")){
		_global_opt1 = ANO;
	}
	else if(equals(pom_MODL_OPT1, STR_NIE) || equals(pom_MODL_OPT1, "0")){
		_global_opt1 = NIE;
	}/* inak ostane _global_opt1 default */
	Log("opt1 == `%s' (%d)\n", pom_MODL_OPT1, _global_opt1);

	/* option 2 */
	if(equals(pom_MODL_OPT2, STR_MODL_ZALMY_ZO_DNA) || equals(pom_MODL_OPT1, "0")){
		_global_opt2 = MODL_ZALMY_ZO_DNA;
	}
	else if(equals(pom_MODL_OPT2, STR_MODL_ZALMY_ZO_SV) || equals(pom_MODL_OPT1, "1")){
		_global_opt2 = MODL_ZALMY_ZO_SV;
	}/* inak ostane _global_opt2 default */
	Log("opt2 == `%s' (%d)\n", pom_MODL_OPT2, _global_opt2);

	/* option 3 */
	int i = atoi(pom_MODL_OPT3);
	/* povodne pre debuggovanie v DOSe, potom sa ukazalo, ze je to uzitocne
	 * aj pod linuxom (v ostrej prevadzke); 18/02/2000A.D.
	 * predpokladam, ze tento parameter moze byt
	 * zadany eventualne cislom (teda retazcom, kt. hodnota pri konverzii
	 * na int je int, urcujuci opt3
	 */
	if((i > MODL_SPOL_CAST_NEBRAT) || (i <= 0)){
		i = 0;
		/* ide o znakovy retazec nekonvertovatelny na cislo */
	}
	else{
		mystrcpy(pom_MODL_OPT3, nazov_spolc[i], SMALL);
		/* ak je zadane cislo spravne, tak i bude spravny int
		 * a pom_MODL_OPT3 bude spravny char* */
	}
	Log("opt3: i == %d\n", i);
	while(i <= MODL_SPOL_CAST_NEBRAT){
		if(equals(pom_MODL_OPT3, nazov_spolc[i])){
			_global_opt3 = i;
			break;
		}
		i++;
	}
	if(i > MODL_SPOL_CAST_NEBRAT){
		_global_opt3 = MODL_SPOL_CAST_NEURCENA;
	}
	Log("opt3 == `%s' (%d)\n", pom_MODL_OPT3, _global_opt3);

	/* option 4 */
	if(equals(pom_MODL_OPT4, STR_ANO) || equals(pom_MODL_OPT4, "4")){
		_global_opt4 = ANO;
	}
	else if(equals(pom_MODL_OPT4, STR_NIE) || equals(pom_MODL_OPT4, "0")){
		_global_opt4 = NIE;
	}/* inak ostane _global_opt4 default */
	Log("opt4 == `%s' (%d)\n", pom_MODL_OPT4, _global_opt4);

	/* kontrola udajov */
	int result = SUCCESS;
	/* den */
	if(equals(den, "")){
		ExportUDAJE("ch˝ba ˙daj o dni.<br>\n");
	}
	else if(d == 0){
		ExportUDAJE("deÚ = <b>%s</b>.<br>\n", den);
	}
	/* mesiac */
	if(equals(mesiac, "")){
		ExportUDAJE("ch˝ba ˙daj o mesiaci.<br>\n");
	}
	else if(m == UNKNOWN_MESIAC){
		ExportUDAJE("tak˝ mesiac nepozn·m (%s).<br>\n", mesiac);
	}
	/* rok */
	if(equals(rok, "")){
		ExportUDAJE("ch˝ba ˙daj o roku.<br>\n");
	}
	else if(r == 0){
		ExportUDAJE("rok = <b>%s</b>.<br>\n", rok);
	}

	if(result == FAILURE){
		Log("/* teraz result == FAILURE */\n");
		ALERT;
		return;
	}
	else{
		Log("/* teraz result == SUCCESS */\n");
		if(m == VSETKY_MESIACE){
			if(p != MODL_NEURCENA){
				ExportUDAJE("pre viacej mesiacov zobrazenie modlitby nie je podporovanÈ\n");
				return;
			}
			Log("/* teraz vypisujem heading 1, rok %d */\n", r);
			sprintf(pom, "Rok %d", r);
			_export_heading1(pom);
			Export("<a name=\"rok\">\n");
			Export("<center>\n");
			/* najprv vygenerujem zoznam liniek (mesiace) */
			for(m = MES_JAN; m <= MES_DEC; m++){
				Export("<a href=\"#mesiac%d\">%s</a>&nbsp;\n",
					m, nazov_MESIACA[m]);
			}
			/* teraz linku na #explain -- vysvetlivky */
			Export("<br><font size=-1><a href=\"#explain\">Vysvetlivky</a></font>\n");
			/* napokon ciaru */
			Export("</center>\n<hr size=1>\n");

			/* teraz generujem jednotlive mesiace so vsetkymi dnami */
			for(m = MES_JAN; m <= MES_DEC; m++){
			/*
				Vytvor_global_link(VSETKY_DNI, m + 1, r);
				Export("\n\n<a name=\"mesiac%d\">", m);
				Export("\n<p><center><b>%s</b> (<a href=\"#rok\">zoznam mesiacov</a>)</center>\n",
					_global_link);
				rozbor_mesiaca(m + 1, r);
			*/
				Export("\n\n<a name=\"mesiac%d\">", m);
				Export("\n<p><center><b><font color=\"#FF0000\">%s</font></b>",
					nazov_MESIACA[m]);
				Export(" (<a href=\"#rok\">zoznam mesiacov</a>)</center>\n");
				rozbor_mesiaca(m + 1, r);
			}

			VYSVETLIVKY();

			if(_global_linky == ANO){/* pridane 13/04/2000A.D. */
			/* pridane 25/02/2000A.D. -- buttony Predchadzajuci, Nasledujuci rok */
			Export("<hr size=1>\n<br>\n<center><table>\n");
			/* predosly rok -- button */
			Export("<td align=right><form action=\"%s?%s=%s&%s=%s&%s=%s&%s=%d\" method=\"post\">\n",
				script_name,
				STR_QUERY_TYPE, STR_PRM_DATUM,
				STR_DEN, STR_VSETKY_DNI,
				STR_MESIAC, STR_VSETKY_MESIACE,
				STR_ROK, r - 1);
			Export("<input type=submit value=\"<<%d (Predch·dzaj˙ci rok)\">\n", r - 1);
			Export("</form></td>\n");

			/* nasledujuci rok -- button */
			Export("<td align=right><form action=\"%s?%s=%s&%s=%s&%s=%s&%s=%d\" method=\"post\">\n",
				script_name,
				STR_QUERY_TYPE, STR_PRM_DATUM,
				STR_DEN, STR_VSETKY_DNI,
				STR_MESIAC, STR_VSETKY_MESIACE,
				STR_ROK, r + 1);
			Export("<input type=submit value=\"(Nasleduj˙ci rok) %d>>\">\n", r + 1);
			Export("</form></td>\n");
			/* koniec buttonov */
			Export("</table></center>\n");
			}/* if(_global_linky == ANO) */
		}
		else{
			/* nesmiem zabudnut, ze m je 0--11 */
			m++;
			if(d == VSETKY_DNI){
				if(p != MODL_NEURCENA){
					ExportUDAJE("pre viacej dnÌ zobrazenie modlitby nie je podporovanÈ\n");
					return;
				}
				Log("/* teraz vypisujem heading 1, mesiac %s, rok %d */\n",
					nazov_mesiaca[m - 1], r);
				sprintf(pom, "%s %d", nazov_Mesiaca[m - 1], r);
				_export_heading1(pom);
				if(prestupny(r))
					pocet_dni[MES_FEB] = 29;
				else
					pocet_dni[MES_FEB] = 28;
				vytvor_global_link(VSETKY_DNI, VSETKY_MESIACE, r, LINK_DEN_MESIAC_ROK);
				Export("\n<center><h2>Rok %s</h2></center>\n", _global_link);
				Export("<center><b><font color=\"#FF0000\">%s</font></b></center>\n",
					nazov_MESIACA[m - 1]);
				rozbor_mesiaca(m, r);

				VYSVETLIVKY();

				if(_global_linky == ANO){/* pridane 13/04/2000A.D. */
				/* pridane 25/02/2000A.D. -- buttony Predchadzajuci, Nasledujuci mesiac */
				Export("<hr size=1>\n<br>\n<center><table>\n");
				/* predosly mesiac -- button */
				pm = m; pr = r;
				if(m == 1){
					pm = 12;
					pr = r - 1;
				}
				else{
					pm = m - 1;
				}
				Export("<td align=right><form action=\"%s?%s=%s&%s=%s&%s=%d&%s=%d\" method=\"post\">\n",
					script_name,
					STR_QUERY_TYPE, STR_PRM_DATUM,
					STR_DEN, STR_VSETKY_DNI,
					STR_MESIAC, pm,
					STR_ROK, pr);
				Export("<input type=submit value=\"<<%s %d\">\n", nazov_Mesiaca[pm - 1], pr);
				Export("</form></td>\n");

				/* nasledujuci mesiac -- button */
				pm = m; pr = r;
				if(m == 12){
					pm = 1;
					pr = r + 1;
				}
				else{
					pm = m + 1;
				}
				Export("<td align=right><form action=\"%s?%s=%s&%s=%s&%s=%d&%s=%d\" method=\"post\">\n",
					script_name,
					STR_QUERY_TYPE, STR_PRM_DATUM,
					STR_DEN, STR_VSETKY_DNI,
					STR_MESIAC, pm,
					STR_ROK, pr);
				Export("<input type=submit value=\"%s %d>>\">\n", nazov_Mesiaca[pm - 1], pr);
				Export("</form></td>\n");
				/* koniec buttonov */
				Export("</table></center>\n");
				}
			}
			else{
				if(!kontrola(d, m, r)){
					Log("/* teraz vypisujem heading 1, datum %d. %s %d */\n",
						d, nazov_mesiaca[m - 1], r);
					sprintf(pom, "%d. %s %d", d, nazov_mesiaca[m - 1], r);
					_export_heading1(pom);
					if(p == MODL_NEURCENA)
						rozbor_dna(d, m, r);
					else
						rozbor_dna_s_modlitbou(d, m, r, p, s);
				}
			}
		}
	}

	Log("-- _main_rozbor_dna(char *, char *, char *, char *, char *): end\n");
}/* _main_rozbor_dna() */

/*---------------------------------------------------------------------*/
/*
 * _main_dnes();
 *
 * vypluje cely objednavaci formular,
 * ktory obsahuje dnesny den, udaje o nom, linku nan,
 * okienka pre den, mesiac, rok; okienko pre (analyzu) rok;
 * okienko pre sviatok, ... a tak.
 *
 * historicka poznamka: kedysi sa volala dnes(); potom prazdny_formular();
 *
 */
void _main_dnes(void){
	time_t timer;
	struct tm dnes;
	int month, day;
	long jd_dnes;
	char pom[MAX_STR];

	/* zisti denny cas */
	timer = time(NULL);

	/* konvertuje date/time na strukturu */
	dnes = *localtime(&timer);

	/* upravenie time_check structure with the data */
	dnes.tm_mon  = dnes.tm_mon + 1;
	dnes.tm_year = dnes.tm_year + 1900;
	dnes.tm_yday = dnes.tm_yday + 1;
	/* juliansky datum */
	jd_dnes = JD(dnes.tm_mday, dnes.tm_mon, dnes.tm_year);

	/* vypis */
	Log("/* teraz vypisujem heading 1, datum %d. %s %d */\n",
		dnes.tm_mday, nazov_mesiaca[dnes.tm_mon - 1], dnes.tm_year);
	sprintf(pom, "%d. %s %d",
		dnes.tm_mday, nazov_mesiaca[dnes.tm_mon - 1], dnes.tm_year);
	_export_heading1(pom);
	Export("Dnes je %d. deÚ v roku, <a href=\"%s%s\">juli·nsky d·tum</a> JD = %ld.\n<br>\n",
		dnes.tm_yday,
		(_global_linky == ANO)? HTTP_ADDRESS: MESSAGE_FOLDER,
		FILE_JULIANSKY_DATUM,
		jd_dnes);
	/* dnes.tm_wday == 0--6 (0==sunday, nedela) */

	/* dalej rozoberiem den a vypisem vysledok */
	_struct_den_mesiac datum;
	datum.den = dnes.tm_mday;
	datum.mesiac = dnes.tm_mon;
	analyzuj_rok(dnes.tm_year); /* vysledok da do _global_r */

	_global_modlitba = MODL_NEURCENA;
	/* pridane 21/02/2000A.D. -- totiz, ked to tu nebolo, tak priradil
	 * niekde neskor do `_global_den' premennu `_global_svaty1' atd.
	 * (jednoducho 'menim, lebo [...] ma prednost' sa urobi jedine v pripade
	 *  generovania modlitby; v opacnom pripade nie)
	 */
	_rozbor_dna(datum, dnes.tm_year);
	_export_rozbor_dna(EXPORT_DNA_DNES);

	/* pokracujem vypisanim formulara */
	Export("<hr size=1>\n");
	Export("<form action=\"%s\" method=\"post\">\n",
		uncgi_name);

	Export("Chcem zobraziù\n");

	Export("<center><table>\n");

/* ------------------------------------------- */
	Export("<tr>\n<td>\n");
	Export("<table>\n<tr><td>\n");
	/* formular pre PRM_DATUM */
	Export("<input type=radio name=\"%s\" value=\"%s\" checked>",
		STR_QUERY_TYPE, STR_PRM_DATUM);
	Export("</td><td>\n");
	Export("&nbsp;d·tum&nbsp;&nbsp;\n");

	/* pole WWW_DEN */
	Export("<select name=\"%s\">\n", STR_DEN);
	for(day = 1; day < 32; day++)
		if(day == dnes.tm_mday)
			Export("<option selected>%d", day);
		else
			Export("<option>%d", day);
	Export("\n</select>&nbsp;.\n");

	/* pole WWW_MESIAC */
	Export("<select name=\"%s\">\n", STR_MESIAC);
	for(month = 1; month < 13; month++)
		if(month == dnes.tm_mon)
			Export("<option selected>%s", nazov_mesiaca[month - 1]);
		else
			Export("<option>%s", nazov_mesiaca[month - 1]);
	Export("\n</select>&nbsp;\n");
/* -- cisla
	for(month = 1; month < 13; month++)
		if(month == dnes.tm_mon)
			Export("<option selected>%d", month);
		else
			Export("<option>%d", month);
	Export("\n</select>&nbsp;.\n");
*/
	/* pole WWW_ROK */
	Export("<INPUT TYPE=TEXT name=\"%s\" size=5 value=\"%d\">\n",
		STR_ROK, dnes.tm_year);

	Export("</td></tr></table>\n");
	Export("</tr>\n</td>\n");

/* ------------------------------------------- */
	Export("<tr>\n<td>\n");
	Export("<table>\n<tr><td>\n");
	/* formular pre PRM_CEZ_ROK */
	Export("<input type=radio name=\"%s\" value=\"%s\">",
		STR_QUERY_TYPE, STR_PRM_CEZ_ROK);
	Export("</td><td>\n");
	Export("&nbsp;cezroËnÈ obdobie,&nbsp;&nbsp;\n");

	/* pole WWW_DEN_V_TYZDNI */
	Export("<select name=\"%s\">\n", STR_DEN_V_TYZDNI);
	for(day = 0; day < 7; day++)
		if(day == dnes.tm_wday)
			Export("<option selected>%s", nazov_dna[day]);
		else
			Export("<option>%s", nazov_dna[day]);
	Export("\n</select>&nbsp;v\n");

	/* pole WWW_TYZDEN */
	Export("<select name=\"%s\">\n", STR_TYZDEN);
	for(day = 1; day < 5; day++)
		if(day == _global_den.tyzzal)
			Export("<option selected>%d", day);
		else
			Export("<option>%d", day);
	Export("\n</select>&nbsp;. t˝ûdni ûalt·ra,&nbsp;");

	/* pole WWW_MODLITBA */
	Export("<select name=\"%s\">\n", STR_MODLITBA);
	Export("<option>%s\n", nazov_modlitby[MODL_PRVE_VESPERY]);
	Export("<option selected>%s\n", nazov_modlitby[MODL_RANNE_CHVALY]);
	Export("<option>%s\n", nazov_modlitby[MODL_DRUHE_VESPERY]);
	Export("</select>\n");

	Export("</td></tr></table>\n");
	Export("</tr>\n</td>\n");

#ifdef FORMULAR_PRE_PRM_SVIATOK
/* ------------------------------------------- */
	Export("<tr>\n<td>\n");
	Export("<table>\n<tr><td>\n");
	/* formular pre PRM_SVIATOK */
	Export("<input type=radio name=\"%s\" value=\"%s\">\n",
		STR_QUERY_TYPE, STR_PRM_SVIATOK);
	Export("</td><td>\n");
	/* !!! sviatky --- */
	Export("</td></tr></table>\n");
	Export("</tr>\n</td>\n");
#endif

/* ------------------------------------------- */
	Export("<tr>\n<td>\n");
	Export("<table>\n<tr><td>\n");
	/* formular pre PRM_ANALYZA_ROKU */
	Export("<input type=radio name=\"%s\" value=\"%s\">",
		STR_QUERY_TYPE, STR_PRM_ANALYZA_ROKU);
	Export("</td><td>\n");
	Export("&nbsp;prik·zanÈ sviatky a sl·vnosti P·na v roku \n");
	/* pole WWW_ANALYZA_ROKU */
	Export("<INPUT TYPE=TEXT name=\"%s\" size=5 value=\"%d\">\n",
		STR_ANALYZA_ROKU, dnes.tm_year);
	Export("</td></tr></table>\n");
	Export("</tr>\n</td>\n");

/* ------------------------------------------- */
	Export("<tr>\n<td>\n");
	Export("<table>\n<tr><td>\n");
	/* formular pre PRM_MESIAC_ROKA */
	Export("<input type=radio name=\"%s\" value=\"%s\">",
		STR_QUERY_TYPE, STR_PRM_MESIAC_ROKA);
	Export("</td><td>\n");
	Export("&nbsp;mesiac &nbsp;");
	/* pole WWW_MESIAC_ROKA */
	Export("<select name=\"%s\">\n", STR_MESIAC_ROKA);
	for(month = 1; month < 13; month++)
		if(month == dnes.tm_mon)
			Export("<option selected>%s", nazov_mesiaca[month - 1]);
		else
			Export("<option>%s", nazov_mesiaca[month - 1]);
	Export("\n</select>&nbsp;\n");

	Export("v roku \n");
	/* pole WWW_ROK_ROKA */
	Export("<INPUT TYPE=TEXT name=\"%s\" size=5 value=\"%d\">\n",
		STR_ROK_ROKA, dnes.tm_year);
	Export("</td></tr></table>\n");
	Export("</tr>\n</td>\n");
/* ------------------------------------------- */
	Export("<tr>\n<td>\n");
	Export("<table>\n<tr><td>\n");
	/* formular pre PRM_TABULKA, 15/03/2000A.D. */
	Export("<input type=radio name=\"%s\" value=\"%s\">",
		STR_QUERY_TYPE, STR_PRM_TABULKA);
	Export("</td><td>\n");
	Export("&nbsp;tabuæka d·tumov pohybliv˝ch sl·venÌ od roku&nbsp;");
	/* pole WWW_ROK_FROM */
	Export("<INPUT TYPE=TEXT name=\"%s\" size=5 value=\"%d\">\n",
		STR_ROK_FROM, dnes.tm_year - 12);
	Export("&nbsp;do roku&nbsp;\n");
	/* pole WWW_ROK_TO */
	Export("<INPUT TYPE=TEXT name=\"%s\" size=5 value=\"%d\">\n",
		STR_ROK_TO, dnes.tm_year + 12);
	Export("</td></tr>\n<tr><td></td><td>");
	/* pole WWW_TABULKA_LINKY */
	Export("<INPUT TYPE=checkbox name=\"%s\" value=\"%d\">\n",
		STR_TABULKA_LINKY, 1); /* ked bude zaskrtnuty, tak vrati hodnotu 1; 15/03/2000A.D. */
	Export("&nbsp;zobraziù tabuæku vr·tane hypertextov˝ch odkazov na jednotlivÈ dni\n");
	Export("</td></tr></table>\n");
	Export("</tr>\n</td>\n");
/* ------------------------------------------- */
	Export("</table>\n");

	Export("<br>\n");
	/* button Vyhladaj (GO!) */
	Export("<input type=submit value=\"Zobraz\">");

	/* button Vycisti (CLEAR!) */
	Export("&nbsp;&nbsp;&nbsp;\n");
	Export("<input type=reset value=\"VyËisti\">");

	Export("</center>\n</form>\n");

}/* _main_dnes(); */

/*---------------------------------------------------------------------*/
/* _main_zaltar() */
void _main_zaltar(char *den, char *tyzden, char *modlitba){
	int d, t, p, i;
	d = atodenvt(den);
	t = atoi(tyzden);
	if((d < 0) || (d > 6) || (t < 1) || (t > 4)){
		Export("NevhodnÈ ˙daje:<br>\n<ul>");
		/* den */
		if(equals(den, ""))
			Export("<li>ch˝ba ˙daj o dni</li>\n");
		else if(d == DEN_UNKNOWN)
			Export("<li>deÚ = <b>%s</b></li>\n", den);
		/* tyzden */
		if(equals(tyzden, ""))
			Export("<li>ch˝ba ˙daj o t˝ûdni</li>\n");
		else if((t < 1) || (t > 4))
			Export("<li>t˝ûdeÚ = <b>%s</b></li>\n", tyzden);
		Export("</ul>\n");
		ALERT;
		return;
	}
	p = MODL_NEURCENA;
	for(i = MODL_INVITATORIUM; i <= MODL_DRUHE_KOMPLETORIUM; i++){
		if(equals(modlitba, nazov_modlitby[i])){
			p = i;
			continue; /* exit from loop */
		}
	}
	if(p == MODL_NEURCENA){
		Export("NevhodnÈ ˙daje: nie je urËen· modlitba.\n");
		return;
	}
	_global_modlitba = p;
	/* vstupom pre showPrayer() je iba zakladny typ modlitby;
	 * zvysna informacia (ci ide o prve/druhe vespery/kompl.) sa uchova
	 * v premennej _global_modlitba */
	if((p == MODL_PRVE_VESPERY) || (p == MODL_DRUHE_VESPERY))
		p = MODL_VESPERY;
	if((p == MODL_PRVE_KOMPLETORIUM) || (p == MODL_DRUHE_KOMPLETORIUM))
		p = MODL_KOMPLETORIUM;
	/* ked nejde o nedelu, nema zmysel rozlisovat prve/druhe vespery/kompl. */
	if(d != DEN_NEDELA){
		if(p == MODL_VESPERY)
			_global_modlitba = MODL_VESPERY;
		if(p == MODL_KOMPLETORIUM)
			_global_modlitba = MODL_KOMPLETORIUM;
	}/* nie je to nedela */

	zaltar(d, t);
	// unfinished !!! - este nejde uplne spravne

	Log("spustam showPrayer(%s)...\n",
		nazov_Modlitby[_global_modlitba]);

	/* predpokladam, ze aj _global_modlitba je prve/druhe vespery,
	 * v _global_prve_vespery su spravne udaje (podobne kompletorium) */
	showPrayer(p);
}/* _main_zaltar() */

/*---------------------------------------------------------------------*/
/* _main_sviatok() */
void _main_sviatok(char *sviatok){
	if(equals(sviatok, "")){
		Export("NevhodnÈ ˙daje: ch˝ba ˙daj o sviatku");
		ALERT;
		return;
	}
	// unfinished !!!
	Export("Chces %s? Este nejde...\n", sviatok);
}/* _main_sviatok() */

/*---------------------------------------------------------------------*/
/* _main_analyza_roku()
 *
 * dostane char *, najprv ho skontroluje a potom
 * ak je vsetko v poriadku, exportuje stranku s jednotlivymi
 * vyznacnymi dnami roka a linkami na vsetky mesiace
 *
 */
void _main_analyza_roku(char *rok){
	_struct_den_mesiac datum;
	int i;
	int year;
	char pom[MAX_STR];

#define LOG  Log("analyza_roku(): "); Log
	Log("-- _main_analyza_roku(): zaciatok\n");

#define ExportROK	Export("<br>"); Export
	year = atoi(rok);
	if(year <= 0){
		_export_heading1("Anal˝za roku");
		Export("Nevhodn˝ ˙daj: ");
		if(equals(rok, ""))
			Export("nezadan˝ rok.\n");
		else if(equals(rok, "0"))
			Export("nepozn·m rok <b>0</b>.\n");
		else
			Export("chybnÈ ËÌslo (%s).\n", rok);
		ALERT;
		return;
	}

	sprintf(pom, "Rok %d", year);
	_export_heading1(pom);

	LOG("vchadzam do analyzuj_rok()...\n");
	analyzuj_rok(year); /* vysledok da do _global_r */
	LOG("analyzuj_rok() ukoncena.\n");

	Export("<font color=\"#FF0000\">Z·kladnÈ inform·cie:</font>\n");
	Export("<br>\n");
	vytvor_global_link(VSETKY_DNI, VSETKY_MESIACE, year, LINK_DEN_MESIAC_ROK);

	/* 13/04/2000A.D.: pridane rozhodovanie podla _global_linky */
	if(_global_linky == ANO)
		mystrcpy(pom, HTTP_ADDRESS, MAX_STR);
	else /* _global_linky == NIE */
		mystrcpy(pom, MESSAGE_FOLDER, MAX_STR);

	if(_global_r.prestupny == YES){
		ExportROK("Rok %s <b>je</b> <a href=\"%s%s\">prestupn˝</a>.\n",
			_global_link, pom, FILE_PRESTUPNY_ROK);
	}
	else{
		ExportROK("Rok %s <b>nie je</b> <a href=\"%s%s\">priestupn˝</a>.\n",
			_global_link, pom, FILE_PRESTUPNY_ROK);
	}

	if(_global_r.prestupny == YES){
		ExportROK("<a href=\"%s%s\">NedeænÈ pÌsmen·</a>: <b>%c %c</b>\n",
			pom, FILE_NEDELNE_PISMENO, _global_r.p1, _global_r.p2);
	}
	else{
		ExportROK("<a href=\"%s%s\">NedeænÈ pÌsmeno</a>: <b>%c</b>\n",
			pom, FILE_NEDELNE_PISMENO, _global_r.p1);
	}

	datum = prva_adventna_nedela(year - 1);
	vytvor_global_link(datum.den, datum.mesiac, year - 1, LINK_DEN_MESIAC);
	/* vytvor_global_link nastavi _global_link */
	ExportROK("Od prvej adventnej nedele v roku %d (%s) pokraËuje <a href=\"%s%s\">liturgick˝ rok</a> <b>%c</b>.\n",
		year - 1,
		_global_link,
		pom,
		FILE_LITURGICKY_ROK,
		'A' + nedelny_cyklus(datum.den, datum.mesiac, year - 1));

	Export("<table>\n");
	for(i = 0; i < POCET_ALIASOV; i++){
		vytvor_global_link(_global_r._den[i].den, _global_r._den[i].mesiac, _global_r._den[i].rok,
			LINK_DEN_MESIAC);
		if(i == PRVA_ADVENTNA_NEDELA){
			Export("<tr valign=baseline><td>%s</td><td>%s</td><td>(%s, %d. deÚ v roku), zaËÌna <a href=\"%s%s\">liturgick˝ rok</a> <b>%c</b>.</td></tr>\n",
				_global_r._den[i].meno,
				_global_link,
				nazov_dna[_global_r._den[i].denvt],
				_global_r._den[i].denvr,
				pom,
				FILE_LITURGICKY_ROK,
				_global_r._den[i].litrok);
		}
		else{
			if(i == VELKONOCNA_NEDELA)
				mystrcpy(_global_r._den[i].meno, "VeækonoËn· nedeæa", MENO_SVIATKU);
			Export("<tr valign=baseline><td>%s</td><td>%s</td><td>(%s, %d. deÚ v roku)</td></tr>\n",
				_global_r._den[i].meno,
				_global_link,
				nazov_dna[_global_r._den[i].denvt],
				_global_r._den[i].denvr);
		}
	}
	Export("</table>\n");

	ExportROK("Po Veækej noci nasleduje %d. %s v obdobÌ Ñcez rokì.\n",
		_global_r.tyzden_ocr_po_vn + 1,
		nazov_dna[DEN_NEDELA]);

	vytvor_global_link(VSETKY_DNI, VSETKY_MESIACE, year, LINK_DEN_MESIAC_ROK);
	ExportROK("<p><font color=\"#FF0000\">Prik·zanÈ sviatky v roku %s:</font>\n",
		_global_link);
	Export("<br>\n");
	Export("\n<table>\n");

	/* 1. januara */
	vytvor_global_link(1, 1, year, LINK_DEN_MESIAC);
	Export("<tr valign=baseline>\n<td>%s</td><td>Panny M·rie BohorodiËky</td></tr>\n",
		_global_link);
	/* 6. januara */
	vytvor_global_link(6, 1, year, LINK_DEN_MESIAC);
	Export("<tr valign=baseline>\n<td>%s</td><td>Zjavenie P·na</td></tr>\n",
		_global_link);
	/* 29. juna */
	vytvor_global_link(29, 6, year, LINK_DEN_MESIAC);
	Export("<tr valign=baseline>\n<td>%s</td><td>Sv. Petra a Pavla, apoötolov</td></tr>\n",
		_global_link);
	/* 15. augusta */
	vytvor_global_link(15, 8, year, LINK_DEN_MESIAC);
	Export("<tr valign=baseline>\n<td>%s</td><td>Nanebovzatie Panny M·rie</td></tr>\n",
		_global_link);
	/* 1. novembra */
	vytvor_global_link(1, 11, year, LINK_DEN_MESIAC);
	Export("<tr valign=baseline>\n<td>%s</td><td>Vöetk˝ch sv‰t˝ch</td></tr>\n",
		_global_link);
	/* 8. decembra */
	vytvor_global_link(8, 12, year, LINK_DEN_MESIAC);
	Export("<tr valign=baseline>\n<td>%s</td><td>NepoökvrnenÈ poËatie Panny M·rie</td></tr>\n",
		_global_link);
	/* 25. decembra */
	vytvor_global_link(25, 12, year, LINK_DEN_MESIAC);
	Export("<tr valign=baseline>\n<td>%s</td><td>Narodenie P·na</td></tr>\n",
		_global_link);

	Export("</table>\n");

	/* teraz nasleduju jednotlive mesiace roku s linkami na ne */
	vytvor_global_link(VSETKY_DNI, VSETKY_MESIACE, year, LINK_DEN_MESIAC_ROK);
	ExportROK("<font color=\"#FF0000\">JednotlivÈ mesiace roku %s:</font>\n",
		_global_link);
#ifdef RICH_JEDNOTLIVE_MESIACE
	Export("<ul>\n");
	for(i = MES_JAN; i <= MES_DEC; i++){
		Vytvor_global_link(VSETKY_DNI, i + 1, year, LINK_DEN_MESIAC_ROK);
		Export("\n<li>%s</li>", _global_link);
	}
	Export("</ul>\n");
#else
	Export("<br>\n<p><center>\n");
	/* teraz zoznam mesiacov -- podla casti pre analyzu dna */
	for(i = 1; i <= 12; i++){
		Vytvor_global_link(VSETKY_DNI, i, year, LINK_DEN_MESIAC);
		Export("%s ", _global_link);
	}
	Export("\n</center>\n");
#endif
	if(_global_linky == ANO){/* pridane 13/04/2000A.D. */
	/* pridane 21/02/2000A.D. -- buttony Predchadzajuci, Nasledujuci rok */
	ExportROK("<center><table>\n");
	/* predosly rok -- button */
	Export("<td align=right><form action=\"%s?%s=%s&%s=%d\" method=\"post\">\n",
		script_name,
		STR_QUERY_TYPE, STR_PRM_ANALYZA_ROKU,
		STR_ANALYZA_ROKU, year - 1);
	Export("<input type=submit value=\"<<%d (Predch·dzaj˙ci rok)\">\n", year - 1);
	Export("</form></td>\n");

	/* nasledujuci rok -- button */
	Export("<td align=right><form action=\"%s?%s=%s&%s=%d\" method=\"post\">\n",
		script_name,
		STR_QUERY_TYPE, STR_PRM_ANALYZA_ROKU,
		STR_ANALYZA_ROKU, year + 1);
	Export("<input type=submit value=\"(Nasleduj˙ci rok) %d>>\">\n", year + 1);
	Export("</form></td>\n");
	Export("</form></td>\n");
	/* koniec buttonov */
	Export("</table></center>\n");
	}

	Log("-- _main_analyza_roku(): koniec\n");
}/* _main_analyza_roku() */

/*---------------------------------------------------------------------*/
/* _main_tabulka(); 15/03/2000A.D.
 *
 * dostane char *, char * (a pripadne char *); najprv ich skontroluje a potom
 * ak je vsetko v poriadku, exportuje stranku s tabulkou datumov pohyblivych slaveni
 * rokov FROM -- TO a pripadne linkami na vsetky slavenia (podla TABULKA_LINKY)
 *
 */
void _main_tabulka(char *rok_from, char *rok_to, char *tab_linky){
	_struct_den_mesiac datum;
	int i;
	int rfrom, rto, year, linky;

	Log("-- _main_tabulka(): zaciatok\n");

	rfrom = atoi(rok_from);
	rto = atoi(rok_to);
	linky = atoi(tab_linky);
	if((rfrom <= 0) || (rto <= 0) || (rfrom > rto)){
		_export_heading1("Anal˝za rokov");
		Export("Nevhodn˝ ˙daj: ");
		if(equals(rok_from, ""))
			Export("nezadan˝ v˝chodzÌ rok.\n");
		if(equals(rok_to, ""))
			Export("nezadan˝ koncov˝ rok.\n");
		else if((equals(rok_from, "0")) || (equals(rok_to, "0")))
			Export("nepozn·m rok <b>0</b>.\n");
		else
			Export("chybnÈ ËÌslo (%s, %s).\n", rok_from, rok_to);
		ALERT;
		return;
	}

	_export_heading1("D·tumy pohybliv˝ch sl·venÌ");

	Export("<center><table border CELLSPACING=1>\n");
	Export("<tr>\n");
	Export("<td align=center>Rok<br>P·na</td>\n");
	Export("<td align=center>Nedeæn·<br>litera</td>\n");
	Export("<td align=center>Nedeæn˝<br>cyklus</td>\n");
	Export("<td align=center>Krst Krista<br>P·na</td>\n");
	Export("<td align=center><a href=\"#explain\">OCR<br>pred<br>PO</a></td>\n"); /* fajl VYSVETLIVKY_TABULKA(); */
	Export("<td align=center>Popolcov·<br>streda</td>\n");
	Export("<td align=center>Veæk·<br>noc</td>\n");
	Export("<td align=center>Nanebo-<br>vst˙penie<br>P·na</td>\n");
	Export("<td align=center>Zoslanie<br>Ducha<br>Sv‰tÈho</td>\n");
	Export("<td align=center><a href=\"#explain\">OCR<br>po<br>VN</a></td>\n"); /* fajl VYSVETLIVKY_TABULKA(); */
	Export("<td align=center>Prv·<br>adventn·<br>nedeæa</td>\n");
	Export("<td align=center>Nedeæa Sv‰tej<br>rodiny</td></tr>\n");
	for(year = rfrom; year <= rto; year++){
		LOG("vchadzam do analyzuj_rok()...\n");
		analyzuj_rok(year); /* vysledok da do _global_r */
		LOG("analyzuj_rok() ukoncena.\n");

		Export("<tr>\n");

		/* rok */
		Export("<td>\n");
		if(linky == ANO)
			vytvor_global_link(VSETKY_DNI, VSETKY_MESIACE, year, LINK_DEN_MESIAC_ROK);
		else
			sprintf(_global_link, "%d", year);
		if(_global_r.prestupny == YES)
			Export("<font color=\"#ff0000\">%s</font>", _global_link);
		else
			Export("%s", _global_link);
		Export("</td>\n");

		/* nedelne litery */
		Export("<td align=center>\n");
		if(_global_r.prestupny == YES)
			Export("%c %c", _global_r.p1, _global_r.p2);
		else
			Export("%c", _global_r.p1);
		Export("</td>\n");
	
		/* nedelne litery */
		Export("<td>\n");
		datum = prva_adventna_nedela(year - 1);
		i = nedelny_cyklus(datum.den, datum.mesiac, year - 1);
		Export("%c-%c", 'A' + i, 'A' + ((i + 1) MOD 3));
		Export("</td>\n");
	
		/* aliasy -- vyznacne dni */
		for(i = 0; i < POCET_ALIASOV; i++){
			if(i == PRVA_ADVENTNA_NEDELA){
				/* pred prvou adv. nedelou, po zoslani ducha sv. ide vypis, aky tyzden obdobia cez rok ide po velkej noci */
				Export("<td align=right>%d.</td>", _global_r.tyzden_ocr_po_vn);
			}
			else if(i == POPOLCOVA_STREDA){
				/* pred popolcovou stredou, aky tyzden obdobia cez rok ide pred postom */
				Export("<td align=center>%d</td>", _global_r.tyzden_ocr_pred_po);
			}
			Export("<td>");
			if(_global_r._den[i].den < 10)
				Export("&nbsp;");
			if(linky == ANO)
				vytvor_global_link(_global_r._den[i].den, _global_r._den[i].mesiac, _global_r._den[i].rok, LINK_DEN_MESIAC);
			else
				sprintf(_global_link, "%d. %s", _global_r._den[i].den, nazov_mesiaca[_global_r._den[i].mesiac - 1]);
			Export("%s</td>\n", _global_link);
		}/* for -- pre aliasy */

		Export("</tr>\n");
	}/* for */
	Export("</table></center>\n");

	VYSVETLIVKY_TABULKA();
	Log("-- _main_tabulka(): koniec\n");
}/* _main_tabulka() */

/*---------------------------------------------------------------------*/
/* debugovacia funkcia vypisujuca systemove premenne WWW_ a query
 * v linuxe treba definovat extern char **environ;
 */

extern char **environ;
void write(void){
	int i = 0;
	while (environ[i]){
//		if(strstr(environ[i], "WWW_") != NULL)
			printf("<p>%d: %s<br><hr size=1>\n", i, environ[i]);
		i++;
	}
}

/*---------------------------------------------------------------------*/
/* popis: zisti, ktory z parametrov je pouzity; ostatne sa zisti z WWW_...
 * vracia: on error, returns PRM_NONE or PRM_UNKNOWN
 *         on success, returns PRM_DATUM, PRM_SVIATOK or PRM_CEZ_ROK
 *                     (09/02/2000A.D.: pridane PRM_DETAILY)
 *
 *         return values #define'd in mydefs.h
 */
int getQueryTypeFrom_QS(char *qs){
	Log("getQueryTypeFrom_QS() -- begin\n");
	Log("  qs == %s\n", qs);
	if(strstr(qs, STR_PRM_DATUM) != NULL){
		/* parameter STR_PRM_DATUM */
		Log("getQueryTypeFrom_QS() -- end, returning PRM_DATUM\n");
		return PRM_DATUM;
	}
	else if(strstr(qs, STR_PRM_DETAILY) != NULL){
		/* parameter STR_PRM_DETAILY*/
		Log("getQueryTypeFrom_QS() -- end, returning PRM_DETAILY\n");
		return PRM_DETAILY; /* pridane kvoli formularu 'Detaily...' */
	}
	else if(strstr(qs, STR_PRM_CEZ_ROK) != NULL){
		/* parameter STR_PRM_CEZ_ROK */
		Log("getQueryTypeFrom_QS() -- end, returning PRM_CEZ_ROK\n");
		return PRM_CEZ_ROK;
	}
	else if(strstr(qs, STR_PRM_SVIATOK) != NULL){
		/* parameter STR_PRM_SVIATOK*/
		Log("getQueryTypeFrom_QS() -- end, returning PRM_SVIATOK\n");
		return PRM_SVIATOK;
	}
	else if(strstr(qs, STR_PRM_ANALYZA_ROKU) != NULL){
		/* parameter STR_PRM_ANALYZA_ROKU */
		Log("getQueryTypeFrom_QS() -- end, returning PRM_ANALYZA_ROKU\n");
		return PRM_ANALYZA_ROKU;
	}
	else if(strstr(qs, STR_PRM_DNES) != NULL){
		/* parameter STR_PRM_DNES */
		Log("getQueryTypeFrom_QS() -- end, returning PRM_DNES\n");
		return PRM_DNES;
	}
	else if(strstr(qs, STR_PRM_MESIAC_ROKA) != NULL){
		/* parameter STR_PRM_MESIAC_ROKA */
		Log("getQueryTypeFrom_QS() -- end, returning PRM_MESIAC_ROKA\n");
		return PRM_MESIAC_ROKA;
	}
	else if(strstr(qs, STR_PRM_TABULKA) != NULL){ /* pridane 15/03/2000A.D. */
		/* parameter STR_PRM_TABULKA */
		Log("getQueryTypeFrom_QS() -- end, returning PRM_TABULKA\n");
		return PRM_TABULKA;
	}
	else{
		Log("getQueryTypeFrom_QS() -- end, returning PRM_UNKNOWN\n");
		return PRM_UNKNOWN; /* argumenty neobsahuju STR_PRM_... */
	}
}

/*---------------------------------------------------------------------*/
#define deallocate_ptr {Log("now deallocating memory for local variable ptr...\n"); free(ptr); Log("...done.\n");}
int getQueryTypeFrom_WWW(void){
	char *ptr;

	Log("getQueryTypeFrom_WWW() -- begin\n");
	Log("first of all, allocate memory for local variables...\n");
	/* ptr */
	if((ptr = (char*) malloc(MAX_STR)) == NULL){
		Log("  Not enough memory to allocate buffer for `ptr'\n");
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_UNKNOWN because of memory insufficience\n");
	}
	else{
		Log("  %d bytes for `ptr'\n", MAX_STR);
	}
	Log("...done.\n");

	ptr = getenv(WWW_(STR_QUERY_TYPE)); /* zistim, ci je to z formulara */

	if(ptr == NULL){
		/* nie, dotaz nie je spusteny z formulara */
		deallocate_ptr;
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_NONE\n");
		return PRM_NONE; /* aj bez parametrov WWW_... */
	}
	/* v tomto pripade existuje premenna WWW_QUERY_TYPE */
	if(equals(ptr, STR_PRM_DATUM)){
		deallocate_ptr;
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_DATUM\n");
		return PRM_DATUM;
	}
	/* toto tu nemusi byt, lebo PRM_DETAILY sa pouziva len pre tlacidlo
	 * 'Detaily...', aby sa dalo odlisit od uvodneho formulara -- kedysi sa
	 * tam miesala modlitba (pole WWW_MODLITBA) z option 'PRM_CEZ_ROK',
	 * ktora sa aplikovala aj na option 'PRM_DATUM'
	 */
	else if(equals(ptr, STR_PRM_DETAILY)){
		deallocate_ptr;
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_DETAILY\n");
		return PRM_DETAILY;
	}
	else if(equals(ptr, STR_PRM_CEZ_ROK)){
		deallocate_ptr;
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_CEZ_ROK\n");
		return PRM_CEZ_ROK;
	}
	else if(equals(ptr, STR_PRM_SVIATOK)){
		deallocate_ptr;
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_SVIATOK\n");
		return PRM_SVIATOK;
	}
	else if(equals(ptr, STR_PRM_ANALYZA_ROKU)){
		deallocate_ptr;
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_ANALYZA_ROKU\n");
		return PRM_ANALYZA_ROKU;
	}
	else if(equals(ptr, STR_PRM_DNES)){
		deallocate_ptr;
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_DNES\n");
		return PRM_DNES;
	}
	else if(equals(ptr, STR_PRM_MESIAC_ROKA)){
		deallocate_ptr;
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_MESIAC_ROKA\n");
		return PRM_MESIAC_ROKA;
	}
	else if(equals(ptr, STR_PRM_TABULKA)){ /* pridane 15/03/2000A.D. */
		deallocate_ptr;
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_TABULKA\n");
		return PRM_TABULKA;
	}
	else{
		deallocate_ptr;
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_UNKNOWN\n");
		return PRM_UNKNOWN; /* failure */
	}
}/* getQueryTypeFrom_WWW(); */

/*---------------------------------------------------------------------*/
/* popis: naplni premenne pom_... hodnotami,
 *        ktore boli dodane ako sucast argumentu
 *        napriklad "-q PRM_DATUM -1 7 -2 5 -3 1976"
 *        vrati query_type == PRM_DATUM;
 *              pom_DEN == 7; pom_MESIAC == 5; pom_ROK == 1976
 * vracia: on success, returns SUCCESS
 *         on error,   returns FAILURE
 * popritom: nastavi do query_type to, co by malo byt po switchi -q
 */
int getArgv(int argc, char **argv){
	int c;
	
	optind = 0; /* pokial tu toto nebolo, 
				 * tak getopt sa neinicializovala pri dalsich volaniach
				 * 10/04/2000A.D.
				 */

	/* int digit_optind = 0; */
	char *option_string;
	/* int this_option_optind; */

	Log("allocating memory for option_string...\n");
	/* allocate memory for string */
	if((option_string = (char *) malloc(MAX_STR)) == NULL){
		Log("Not enough memory to allocate buffer, so returning FAILURE\n");
		//printf("Not enough memory to allocate buffer (getArgv(), char *option_string)\n");
		/* exit(1); -- terminate program if out of memory */
		return FAILURE; /* 13/03/2000A.D. */
	}
	/* 07/04/2000A.D. -- chybala dealokacia! */

	/* option_string obsahuje options (case sensitive) */
	/* 24/02/2000A.D.: odstranil som `e' switch -- sposoboval problemy;
	 * pismeno `s' je pouzite na debuggovacie ucely pre zadanie uplneho query
	 * stringu;
	 * 13/03/2000A.D.: znova som pridal `e' switch; 
	 * tentokrat uz prirobene closeExport() a initExport(char*) v myexpt.[h|cpp]
	 * 15/03/2000A.D.: pridal som parametre
	 *  `f' (rok from), `g' (rok to), `l' (hyperlinky) pre -qptab
	 * 05/06/2000A.D.: pridany parameter `i' (include directory)
	 */
	mystrcpy(option_string, "?q::d::m::r::p::x::s::t::1::2::3::4::5::h::e::f::g::l::i::\?::", MAX_STR);
	/* tie options, ktore maju za sebou : maju povinny argument;
	 *	ak maju :: tak maju volitelny */

	Log("-- getArgv(): begin\n");
	DEBUG_GET_ARGV("argc == %d\n", argc);

	if(argc == 1){
		/* bud nie su zadane ziadne hodnoty alebo cerpam z premennych WWW_ */
		/* sem sa to nemalo dostat, pretoze
		 * najprv sme pouzili get_query_type() */

		/* keby sa to sem vsak predsalen dostalo, dame sem nasledujucu pasaz,
		 * aby sme mohli exportovat, pretoze pred pouzitim getArgv nie je
		 * otvoreny fajl FILE_EXPORT
		 */

		/* initExport(); bola kedysi na zaciatku, avsak kvoli tomu, aby
		 * bolo mozne menit (switch -e) nazov suboru, dalo sa to sem
		 * 24/02/2000A.D. -- urobil som to presne tak, ako bolo kedysi
		 */
/* begin -- 24/02/2000A.D. -- zapoznamkovane */
/*		initExport();
		hlavicka("Liturgia hodÌn");
 */
/* end -- 24/02/2000A.D. -- zapoznamkovane */

		Export("ObsluûnÈmu programu neboli zadanÈ ûiadne argumenty.\n");
		Export("<p>getArgv();\n");
		ALERT;
		DEBUG_GET_ARGV("Nezadane ziadne argumenty (argc == 1).\n");
		return FAILURE; /* nie su argumenty */
	}
	else{
		Log("option_string == %s\n", option_string);
		for(c = 0; c < argc; c++)
			Log("argv[%d] == %s\n", c, argv[c]);
		/* hodnoty su v dialogovom riadku */
		/* zistujeme ich cez standardne mygetopt.c */
		while(1){
			/* this_option_optind = optind ? optind : 1; */
			c = getopt(argc, argv, option_string);
			if (c == -1) /* uz nie je option, vyskoc z while(1) */
				break;
			switch (c){ /* podla option urob nieco */
				case 'i': /* pridane 05/06/2000A.D., include_dir */
					if(optarg != NULL){
						mystrcpy(include_dir, optarg, SMALL);
					}
					Log("option %c with value `%s' -- including files from `%s%s'\n", c, optarg, optarg, FILE_PATH); break;
				case 'f': /* tabulka - rok from */
					if(optarg != NULL){
						mystrcpy(pom_ROK_FROM, optarg, SMALL);
					}
					Log("option %c with value `%s'\n", c, optarg); break;
				case 'g': /* tabulka - rok to */
					if(optarg != NULL){
						mystrcpy(pom_ROK_TO, optarg, SMALL);
					}
					Log("option %c with value `%s'\n", c, optarg); break;
				case 'l': /* tabulka - [hyper]linky */
					if(optarg != NULL){
						mystrcpy(pom_LINKY, optarg, SMALL);
					}
					Log("option %c with value `%s'\n", c, optarg); break;
				case 'e': /* export filename */
					if(optarg != NULL){
						mystrcpy(file_export, optarg, SMALL);
					}
					Log("option %c with value `%s'\n", c, optarg); break;
			/* zmenene: *
			 * povodne tu boli pri kazdom parametri aj '1' -- '5';
			 * teraz: vyhodene case '1' -- '5',
			 * ktorezto '1' -- '3' su pre options, vid dalej */
				case 's': /* debuggovanie, query string */
					if(optarg != NULL){
						Log("--copying `%s' to query_string...", optarg);
						mystrcpy(query_string, optarg, MAX_QUERY_STR);
						/* to mozeme urobit;
						 * predtym, ked sme este nealokovali pre query_string
						 * miesto, bolo by lepsie urobit nejaku lokalnu premennu,
						 * na ktoru by potom query_string ukazoval
						 * 25/02/2000A.D.
						 */
						mystrcpy(pom_QUERY_TYPE, STR_PRM_SIMULACIA_QS, MAX_POM_QUERY_TYPE);
						query_type = PRM_SIMULACIA_QS;
					}
					Log("option %c with value `%s'\n", c, optarg); break;
				case 'd': /* DEN */
					/* znamena prvy parameter */
					if(optarg != NULL){
						mystrcpy(pom_DEN, optarg, SMALL);
					}
					Log("option %c with value `%s' -- den\n", c, optarg); break;
				case 'm': /* MESIAC */
				case 't': /* TYZDEN */
					/* znamena druhy parameter */
					if(optarg != NULL){
						mystrcpy(pom_MESIAC, optarg, SMALL);
					}
					Log("option %c with value `%s' -- mesiac/tyzden\n", c, optarg); break;
				case 'r': /* ROK, ANALYZA_ROKU */
					/* znamena treti parameter */
					if(optarg != NULL){
						mystrcpy(pom_ROK, optarg, SMALL);
					}
					Log("option %c with value `%s' -- rok\n", c, optarg); break;
				case 'p': /* MODLITBA */
					/* znamena stvrty parameter */
					if(optarg != NULL){
						mystrcpy(pom_MODLITBA, optarg, SMALL);
					}
					Log("option %c with value `%s' -- modlitba\n", c, optarg); break;
				case 'x': /* DALSI_SVATY */
					/* znamena piaty parameter */
					if(optarg != NULL){
						mystrcpy(pom_DALSI_SVATY, optarg, SMALL);
					}
					Log("option %c with value `%s' -- poradie svateho\n", c, optarg); break;

				/* nasledovne 3 case'y sa tykaju MODL_OPT... */
				case '1': /* MODL_OPT1 */
					/* znamena siesty parameter */
					if(optarg != NULL){
						mystrcpy(pom_MODL_OPT1, optarg, SMALL);
					}
					Log("option %c with value `%s'\n", c, optarg); break;
				case '2': /* MODL_OPT2 */
					/* znamena siedmy parameter */
					if(optarg != NULL){
						mystrcpy(pom_MODL_OPT2, optarg, SMALL);
					}
					Log("option %c with value `%s'\n", c, optarg); break;
				case '3': /* MODL_OPT3 */
					/* znamena osmy parameter */
					if(optarg != NULL){
						mystrcpy(pom_MODL_OPT3, optarg, SMALL);
					}
					Log("option %c with value `%s'\n", c, optarg); break;
				case '4': /* MODL_OPT4 */
					/* znamena osmy parameter */
					if(optarg != NULL){
						mystrcpy(pom_MODL_OPT4, optarg, SMALL);
					}
					Log("option %c with value `%s'\n", c, optarg); break;

				case 'q': /* QUERY_TYPE */
					if(optarg != NULL){
						mystrcpy(pom_QUERY_TYPE, optarg, MAX_POM_QUERY_TYPE);
					}
					Log("option %c with value `%s'\n", c, optarg); break;

				case '?': /* pridany 05/06/2000A.D., oprava 07/09/2001A.D. */
				case 'h':

					/* opravene 07/09/2001A.D. - pridane niektore switche */
					printf("lh | liturgia hodin | on-line breviar | http://www.breviar.sk \n");
					printf("\t(c) juraj videky | videky@breviar.sk\n");
					printf("usage | lh [switch [value]...]\n");
					printf("switches |\n");
					printf("\tq  query type (napr. %s, %s, %s, %s, ...)\n",
						STR_PRM_DNES, STR_PRM_DATUM, STR_PRM_DETAILY, STR_PRM_TABULKA);
					printf("\td  den  %s, %s (1--31, po--ne)\n", STR_DEN, STR_DEN_V_TYZDNI);
					/* printf("\ts  SVIATOK \n"); */
					printf("\tm  mesiac  %s (1--12, jan--dec)\n", STR_MESIAC);
					printf("\tt  tyzden zaltara (1--4) \n");
					printf("\tr  rok (napr. 2000)\n");
					printf("\tp  %s (modlitba  napr. %s, %s, ...) \n", STR_MODLITBA, STR_MODL_RANNE_CHVALY, STR_MODL_VESPERY);
					printf("\tx  %s (dalsi svaty, 1--3 resp. 4) \n", STR_DALSI_SVATY);
					printf("\t1, 2, 3, 4  option 1, option 2, option 3, option 4 \n");
					printf("\tf  rok from \n");
					printf("\tg  rok to \n");
					printf("\tl  ci zobrazovat linky \n");
					printf("\te  export filename (default: export.htm)\n");
					printf("\ti  include folder\n");
					printf("\th, ?  this help \n");

					Log("option %c (without value)\n", c, optarg); break;

				default:
				/* znamena option uvedenu v optionstringu, pre ktoru
				 * nebolo definovane case vyssie
				 */
					Log("?? getopt returned character `%c' ??\n", c);
			}/*switch*/
		}/*while*/
		if(optind < argc){
			Log("non-option ARGV-elements: ");
			while(optind < argc)
			Log("%s ", argv[optind++]);
			Log("\n");
		}

		/* dokoncili sme parsovanie options (switchov apod),
		 * a teraz rozoberieme, co sme zistili */

		/* najprv nakopirujeme chybovu hlasku do bad_param_str */
		if(equals(pom_QUERY_TYPE, "")){
			mystrcpy(bad_param_str, "<b>nijak˝ parameter PRM_...</b>", MAX_STR);
		}
		else{
			mystrcpy(bad_param_str, pom_QUERY_TYPE, MAX_STR);
			strcat(bad_param_str, " (switch <b>-q</b>)");
		}
		/* a teraz vydolujeme typ dotazu */
		/* vynecham to v pripade, ze pom_QUERY_TYPE == STR_PRM_SIMULACIA_QS,
		 * t.j. query_type == PRM_SIMULACIA_QS
		 */
		/* 24/02/2000A.D. */
		if(query_type != PRM_SIMULACIA_QS){
			Log("query_type != PRM_SIMULACIA_QS, so running getQueryTypeFrom_QS(%s)...\n", pom_QUERY_TYPE);
			query_type = getQueryTypeFrom_QS(pom_QUERY_TYPE);
		}
	}

	Log("deallocating memory for option_string...\n");
	free(option_string);

	Log("-- getArgv(): end, query_type == %d, query_string == %s\n",
		query_type, query_string);

	return SUCCESS;
}/* getArgv(); */

/*---------------------------------------------------------------------*/
/* popis: naplni premenne pom_... hodnotami z environmentu, t.j.
 *        premennymi WWW_ ktore vrati uncgi.c
 * vracia: on success, returns SUCCESS
 *         on error,   returns FAILURE
 */
int getForm(void){
	char *ptr;

	//DEBUG_GET_FORM("argc == %d\n", argc);

	/* malo by byt argc == 1 */

	if((query_type == PRM_DATUM) || (query_type == PRM_DETAILY)){
		/* datum: treba nacitat den, mesiac a rok */

		/* premenna WWW_DEN */
		ptr = getenv(WWW_(STR_DEN));
		if(ptr == NULL){
			Export("Nebola vytvoren·; systÈmov· premenn· %s.\n",
				WWW_(STR_DEN));
			ALERT;
			DEBUG_GET_FORM("%s neexistuje.\n",
				WWW_(STR_DEN));
			return FAILURE; /* failure */
		}
		if(strcmp(ptr, EMPTY_STR) != 0)
			mystrcpy(pom_DEN, ptr, SMALL);

		/* premenna WWW_MESIAC */
		ptr = getenv(WWW_(STR_MESIAC));
		if(ptr == NULL){
			Export("Nebola vytvoren· systÈmov· premenn· %s.\n",
				WWW_(STR_MESIAC));
			ALERT;
			DEBUG_GET_FORM("%s neexistuje.\n",
				WWW_(STR_MESIAC));
			return FAILURE; /* failure */
		}
		if(strcmp(ptr, EMPTY_STR) != 0)
			mystrcpy(pom_MESIAC, ptr, SMALL);

		/* premenna WWW_ROK */
		ptr = getenv(WWW_(STR_ROK));
		if(ptr == NULL){
			Export("Nebola vytvoren· systÈmov· premenn· %s.\n",
				WWW_(STR_ROK));
			ALERT;
			DEBUG_GET_FORM("%s neexistuje.\n",
				WWW_(STR_ROK));
			return FAILURE; /* failure */
		}
		if(strcmp(ptr, EMPTY_STR) != 0)
			mystrcpy(pom_ROK, ptr, SMALL);

		/* nasledujuce sa zistuju kvoli 'Detaily...', formular vytvorila
		 * funckia showDetails();
		 * v normalnom formulari (vytvori ho _main_dnes();) nie su */

		/* premenna WWW_MODLITBA */
		ptr = getenv(WWW_(STR_MODLITBA));
		/* ak nie je vytvorena, ak t.j. ptr == NULL, tak nas to netrapi,
		 * lebo pom_... su inicializovane na "" */
		if(ptr != NULL){
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_MODLITBA, ptr, SMALL);
		}
		/* treba otestovat, ci (v pripade, ze sa jedna o prvy vstupny
		 * formular, t.j. PRM_DATUM) je modlitba nastavena -- v takom
		 * pripade treba nastavit modlitbu na MODL_NEURCENA;
		 *
		 * ak je druhy formular -- Detaily (t.j. PRM_DETAILY),
		 * tak modlitba ostane ponechana
		 *
		 * je to tu kvoli tomu, ze v prvom formulari sa da napr. oznacit
		 *
		 * (o) datum 22. februar 2000
		 * ( ) cezrocne obdobie, utorok v 3. tyzdni zaltara, ranne chvaly
		 * ( ) ... atd,
		 *
		 * a po odoslani sa _vytvori_ premenna WWW_... (modlitba) s hodnotou
		 * 'ranne chvaly' -- takze ju treba znicit
		 *
		 * zistime to tak, ze ci je nastavena napr. premenna WWW_MESIAC_ROKA
		 *                            22/02/2000A.D.
		 */
		/* premenna WWW_MESIAC_ROKA -- len testovo, aby sme odlisili prvy od
		 * druheho formulara
		 */
		ptr = getenv(WWW_(STR_MESIAC_ROKA));
		if(ptr != NULL){ /* povodne if(query_type == PRM_DATUM) */
			/* nie je NULL, ide teda o prvy vstupny formular */
			mystrcpy(pom_MODLITBA, "", SMALL);
		}

		/* premenna WWW_DALSI_SVATY */
		ptr = getenv(WWW_(STR_DALSI_SVATY));
		/* ak nie je vytvorena, ak t.j. ptr == NULL, tak nas to netrapi,
		 * lebo pom_... su inicializovane na "" */
		if(ptr != NULL){
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_DALSI_SVATY, ptr, SMALL);
		}

		/* premenna WWW_MODL_OPT1 */
		ptr = getenv(WWW_(STR_MODL_OPT1));
		/* ak nie je vytvorena, ak t.j. ptr == NULL, tak nas to netrapi,
		 * lebo pom_... su inicializovane na "" */
		if(ptr != NULL){
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_MODL_OPT1, ptr, SMALL);
		}

		/* premenna WWW_MODL_OPT2 */
		ptr = getenv(WWW_(STR_MODL_OPT2));
		/* ak nie je vytvorena, ak t.j. ptr == NULL, tak nas to netrapi,
		 * lebo pom_... su inicializovane na "" */
		if(ptr != NULL){
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_MODL_OPT2, ptr, SMALL);
		}

		/* premenna WWW_MODL_OPT3 */
		ptr = getenv(WWW_(STR_MODL_OPT3));
		/* ak nie je vytvorena, ak t.j. ptr == NULL, tak nas to netrapi,
		 * lebo pom_... su inicializovane na "" */
		if(ptr != NULL){
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_MODL_OPT3, ptr, SMALL);
		}

		/* premenna WWW_MODL_OPT4 */
		ptr = getenv(WWW_(STR_MODL_OPT4));
		/* ak nie je vytvorena, ak t.j. ptr == NULL, tak nas to netrapi,
		 * lebo pom_... su inicializovane na "" */
		if(ptr != NULL){
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_MODL_OPT4, ptr, SMALL);
		}

	}
	else if(query_type == PRM_CEZ_ROK){
		/* cez rok: treba nacitat den v tyzdni a cislo tyzdna */

		/* premenna WWW_DEN_V_TYZDNI */
		ptr = getenv(WWW_(STR_DEN_V_TYZDNI));
		if(ptr == NULL){
			Export("Nebola vytvoren· systÈmov· premenn· %s.\n",
				WWW_(STR_DEN_V_TYZDNI));
			ALERT;
			DEBUG_GET_FORM("%s neexistuje.\n",
				WWW_(STR_DEN_V_TYZDNI));
			return FAILURE; /* failure */
		}
		if(strcmp(ptr, EMPTY_STR) != 0)
			mystrcpy(pom_DEN_V_TYZDNI, ptr, SMALL);

		/* premenna WWW_TYZDEN */
		ptr = getenv(WWW_(STR_TYZDEN));
		if(ptr == NULL){
			Export("Nebola vytvoren· systÈmov· premenn· %s.\n",
				WWW_(STR_TYZDEN));
			ALERT;
			DEBUG_GET_FORM("%s neexistuje.\n",
				WWW_(STR_TYZDEN));
			return FAILURE; /* failure */
		}
		if(strcmp(ptr, EMPTY_STR) != 0)
			mystrcpy(pom_TYZDEN, ptr, SMALL);

		/* premenna WWW_MODLITBA */
		ptr = getenv(WWW_(STR_MODLITBA));
		if(ptr == NULL){
			Export("Nebola vytvoren· systÈmov· premenn· %s.\n",
				WWW_(STR_MODLITBA));
			ALERT;
			DEBUG_GET_FORM("%s neexistuje.\n",
				WWW_(STR_MODLITBA));
			return FAILURE; /* failure */
		}
		if(strcmp(ptr, EMPTY_STR) != 0)
			mystrcpy(pom_MODLITBA, ptr, SMALL);

	}
	else if(query_type == PRM_SVIATOK){
		/* cez rok: treba nacitat nazov sviatku */

		/* premenna WWW_NAZOV_SVIATOK */
		ptr = getenv(WWW_(STR_NAZOV_SVIATOK));
		if(ptr == NULL){
			Export("Nebola vytvoren· systÈmov· premenn· %s.\n",
				WWW_(STR_NAZOV_SVIATOK));
			ALERT;
			DEBUG_GET_FORM("%s neexistuje.\n",
				WWW_(STR_NAZOV_SVIATOK));
			return FAILURE; /* failure */
		}
		if(strcmp(ptr, EMPTY_STR) != 0)
			mystrcpy(pom_SVIATOK, ptr, SMALL);

	}
	else if(query_type == PRM_ANALYZA_ROKU){
		/* cez rok: treba nacitat nazov sviatku */

		/* premenna WWW_ANALYZA_ROKU */
		ptr = getenv(WWW_(STR_ANALYZA_ROKU));
		if(ptr == NULL){
			Export("Nebola vytvoren· systÈmov· premenn· %s.\n",
				WWW_(STR_ANALYZA_ROKU));
			ALERT;
			DEBUG_GET_FORM("%s neexistuje.\n",
				WWW_(STR_ANALYZA_ROKU));
			return FAILURE; /* failure */
		}
		if(strcmp(ptr, EMPTY_STR) != 0)
			mystrcpy(pom_ANALYZA_ROKU, ptr, SMALL);

	}
	else if(query_type == PRM_MESIAC_ROKA){
		/* treba nacitat mesiac a rok */
		/* premenna WWW_MESIAC_ROKA */
		ptr = getenv(WWW_(STR_MESIAC_ROKA));
		if(ptr == NULL){
			Export("Nebola vytvoren· systÈmov· premenn· %s.\n",
				WWW_(STR_MESIAC_ROKA));
			ALERT;
			DEBUG_GET_FORM("%s neexistuje.\n",
				WWW_(STR_MESIAC_ROKA));
			return FAILURE; /* failure */
		}
		if(strcmp(ptr, EMPTY_STR) != 0)
			mystrcpy(pom_MESIAC, ptr, SMALL);

		/* premenna WWW_ROK */
		ptr = getenv(WWW_(STR_ROK_ROKA));
		if(ptr == NULL){
			Export("Nebola vytvoren· systÈmov· premenn· %s.\n",
				WWW_(STR_ROK_ROKA));
			ALERT;
			DEBUG_GET_FORM("%s neexistuje.\n",
				WWW_(STR_ROK_ROKA));
			return FAILURE; /* failure */
		}
		if(strcmp(ptr, EMPTY_STR) != 0)
			mystrcpy(pom_ROK, ptr, SMALL);

	}
	else if(query_type == PRM_TABULKA){
		/* PRM_TABULKA: treba nacitat from a to; ak chyba linka, tak automaticky == NIE */

		/* premenna WWW_ROK_FROM */
		ptr = getenv(WWW_(STR_ROK_FROM));
		if(ptr == NULL){
			Export("Nebola vytvoren· systÈmov· premenn· %s.\n",
				WWW_(STR_ROK_FROM));
			ALERT;
			DEBUG_GET_FORM("%s neexistuje.\n",
				WWW_(STR_ROK_FROM));
			return FAILURE; /* failure */
		}
		if(strcmp(ptr, EMPTY_STR) != 0)
			mystrcpy(pom_ROK_FROM, ptr, SMALL);

		/* premenna WWW_ROK_TO */
		ptr = getenv(WWW_(STR_ROK_TO));
		if(ptr == NULL){
			Export("Nebola vytvoren· systÈmov· premenn· %s.\n",
				WWW_(STR_ROK_TO));
			ALERT;
			DEBUG_GET_FORM("%s neexistuje.\n",
				WWW_(STR_ROK_TO));
			return FAILURE; /* failure */
		}
		if(strcmp(ptr, EMPTY_STR) != 0)
			mystrcpy(pom_ROK_TO, ptr, SMALL);

		/* premenna WWW_TABULKA_LINKY */
		ptr = getenv(WWW_(STR_TABULKA_LINKY));
		/* ak nie je vytvorena, ak t.j. ptr == NULL, tak nas to netrapi,
		 * lebo pom_... su inicializovane na "" */
		if(ptr != NULL){
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_LINKY, ptr, SMALL);
		}
	}
	else{
		/* neznamy typ dotazu */
		return FAILURE;
	}
	return SUCCESS;
}/* getForm(); */

/*---------------------------------------------------------------------*/
/* popis: naplni premenne pom_... hodnotami z environmentu, t.j.
 *        premennymi zo stringu QUERY_STRING (systemova premenna)
 *        napriklad retazec "QUERY_TYPE=PRM_DATUM&DEN=7&MESIAC=5&ROK=1976"
 * vracia: on success, returns SUCCESS
 *         on error,   returns FAILURE
 */
int parseQueryString(void){
/* totiz spustenie skriptu
 *
 * /cgi-bin/script_name?QUERY_TYPE=PRM_DATUM&DEN=7&MESIAC=5&ROK=1976
 * funguje tak, ze vytvori systemovu premennu QUERY_STRING
 * takze vlastne treba simulovat uncgi
 * (parsovanie QUERY_STRING systemovej premennej)
 *
 *    (keby sme to este prehnali cez uncgi, teda spustili
 *     /cgi-bin/uncgi.cgi/script_name?QUERY_TYPE=PRM_DATUM&DEN=7&MESIAC=5&ROK=1976
 *     tak to funguje ako POST hodnoty z formulara - urobi systemove premenne
 *     WWW_QUERY_TYPE=PRM_DATUM, WWW_DATUM, WWW_MESIAC, WWW_ROK)
 */

	int i;

	Log("parseQueryString() -- begin\n");
	if(query_string != NULL)
		Log("query_string == %s, lenght == %d\n", query_string, strlen(query_string));
	else
		Log("query_string is NULL, something is wrong...\n");

	/* get parameters */
	i = 0;
	while(strlen(query_string) > 0){
		mystrcpy(param[i].name, "", MAX_NAME_CGI_UTILS);
		mystrcpy(param[i].val, "", MAX_VAL_CGI_UTILS);
		splitword(param[i].val, query_string, '&');
		unescape_url(param[i].val);
		splitword(param[i].name, param[i].val, '=');
		i++;
	}

	if(equals(param[0].name, STR_QUERY_TYPE)){

		if(equals(param[0].val, STR_PRM_DATUM)){
			/* ide o parameter STR_PRM_DATUM */
			query_type = PRM_DATUM;
		}
		else if(equals(param[0].val, STR_PRM_DETAILY)){
			/* ide o parameter STR_PRM_DETAILY*/
			/* pridany 09/02/2000A.D. ako alternativa k PRM_DATUM */
			query_type = PRM_DETAILY;
		}
		else if(equals(param[0].val, STR_PRM_CEZ_ROK)){
			/* ide o parameter STR_PRM_CEZ_ROK */
			query_type = PRM_CEZ_ROK;
		}
		else if(equals(param[0].val, STR_PRM_SVIATOK)){
			/* ide o parameter STR_PRM_SVIATOK */
			query_type = PRM_SVIATOK;
		}
		else if(equals(param[0].val, STR_PRM_DNES)){
			/* ide o parameter STR_PRM_DNES */
			query_type = PRM_DNES;
		}
		else if(equals(param[0].val, STR_PRM_ANALYZA_ROKU)){
			/* ide o parameter STR_PRM_ANALYZA_ROKU */
			query_type = PRM_ANALYZA_ROKU;
		}
		else if(equals(param[0].val, STR_PRM_MESIAC_ROKA)){
			/* ide o parameter STR_PRM_MESIAC_ROKA */
			query_type = PRM_MESIAC_ROKA;
		}
		else if(equals(param[0].val, STR_PRM_TABULKA)){
			/* ide o parameter STR_PRM_TABULKA */
			query_type = PRM_TABULKA;
		}
		else{
			/* ani jeden z parametrov nie je uvedeny ako prvy */
			Export("Chybn· hodnota parametra %s: %s\n",
				param[0].name, param[0].val);
			query_type = PRM_UNKNOWN; /* pridane 24/02/2000A.D. */
			ALERT;
			return FAILURE;
		}
	}
	else{
		/* ani jeden z parametrov nie je uvedeny ako prvy */
		Export("Chybn˝ parameter: %s\n", param[0].name);
		ALERT;
		return FAILURE;
	}

	switch(query_type){
		case PRM_DETAILY:
			/* presne to iste co PRM_DATUM s jedinkym rozdielom: co sa tyka
			 * formularov, prvy (uvodny) formular pre PRM_DATUM vycisti
			 * modlitbu (premenna pom_MODLITBA, ktora sa nacita zo systemovej
			 * premennej WWW_MODLITBA) -- pretoze z inej casti fomrulara sa tam
			 * nieco dostane...
			 */
		case PRM_DATUM:{
		/* pripad, ze ide o datum */

		/* treba dodrzat presne poradie v query stringu;
		 *   '()' znaci optional,
		 *   '[]' znaci vyssie uvedeny typ dotazu.
		 * ---------------------------------------------
		 * 0: [query type]
		 * 1: den          / rok from
		 * 2: mesiac       / rok to
		 * 3: rok          / (linky) -- tieto tri `alternativne' parametre pre typ dotazu case PRM_TABULKA:, vid nizsie
		 * 4: (modlitba)
		 * 5: (dalsi svaty) - poradie svateho
		 * 6: (opt1) - ci zobrazit Benediktus/Magnifikat, Otcenas, zakoncenie
		 * 7: (opt2) - ci brat (pri sviatkoch svatych) zalmy zo dna / zo sviatku
		 * 8: (opt3) - ktoru `spolocnu cast' (pri sviatkoch svatych) brat
		 * 9: (opt4) - for future use
		 * ---------------------------------------------
		 */

			/* premenna DEN */
			if(equals(param[1].name, STR_DEN)){
				mystrcpy(pom_DEN, param[1].val, SMALL);
			}
			else{
				Export("Nebola zadan· premenn· %s.\n",
					STR_DEN);
				ALERT;
				return FAILURE; /* failure */
			}

			/* premenna MESIAC */
			if(equals(param[2].name, STR_MESIAC)){
				mystrcpy(pom_MESIAC, param[2].val, SMALL);
			}
			else{
				Export("Nebola zadan· premenn· %s.\n",
					STR_MESIAC);
				ALERT;
				return FAILURE; /* failure */
			}

			/* premenna ROK */
			if(equals(param[3].name, STR_ROK)){
				mystrcpy(pom_ROK, param[3].val, SMALL);
			}
			else{
				Export("Nebola zadan· premenn· %s.\n",
					STR_ROK);
				ALERT;
				return FAILURE; /* failure */
			}

			/* premenna MODLITBA resp. DALSI_SVATY */
			if(equals(param[4].name, STR_MODLITBA)){
				mystrcpy(pom_MODLITBA, param[4].val, SMALL);
			}
			else{
			/* nevadi, ze nebola zadana modlitba, skusime, ci param[4]
			 * nahodou nie je DALSI_SVATY
			 */
				if(equals(param[4].name, STR_DALSI_SVATY)){
					mystrcpy(pom_DALSI_SVATY, param[4].val, SMALL);
				}
			}

			/* premenna DALSI_SVATY (resp. MODLITBA) */
			if(equals(param[5].name, STR_DALSI_SVATY)){
				mystrcpy(pom_DALSI_SVATY, param[5].val, SMALL);
			}
			else{
			/* nevadi, ze nebol zadany dalsi svaty, skusime, ci param[5]
			 * nie je nahodou MODLITBA
			 */
				if(equals(param[5].name, STR_MODLITBA)){
					mystrcpy(pom_MODLITBA, param[5].val, SMALL);
				}
			}

			/* premenna MODL_OPT1 */
			if(equals(param[6].name, STR_MODL_OPT1)){
				mystrcpy(pom_MODL_OPT1, param[6].val, SMALL);
			}
			else{
				/* nevadi, ze nebola zadana option1 k modlitbe */
			}

			/* premenna MODL_OPT2 */
			if(equals(param[7].name, STR_MODL_OPT2)){
				mystrcpy(pom_MODL_OPT2, param[7].val, SMALL);
			}
			else{
				/* nevadi, ze nebola zadana option2 k modlitbe */
			}

			/* premenna MODL_OPT3 */
			if(equals(param[8].name, STR_MODL_OPT3)){
				mystrcpy(pom_MODL_OPT3, param[8].val, SMALL);
			}
			else{
				/* nevadi, ze nebola zadana option3 k modlitbe */
			}

			/* premenna MODL_OPT4 */
			if(equals(param[9].name, STR_MODL_OPT4)){
				mystrcpy(pom_MODL_OPT4, param[9].val, SMALL);
			}
			else{
				/* nevadi, ze nebola zadana option4 k modlitbe */
			}

			break; /* case */
		}

		case PRM_CEZ_ROK:{
		/* pripad, ze ide o tyzden cez rok */
			/* premenna DEN_V_TYZDNI */
			if(equals(param[1].name, STR_DEN_V_TYZDNI)){
				mystrcpy(pom_DEN_V_TYZDNI, param[1].val, SMALL);
			}
			else{
				Export("Nebola zadan· premenn· %s.\n",
					STR_DEN_V_TYZDNI);
				ALERT;
				return FAILURE; /* failure */
			}

			/* premenna TYZDEN */
			if(equals(param[2].name, STR_TYZDEN)){
				mystrcpy(pom_TYZDEN, param[2].val, SMALL);
			}
			else{
				Export("Nebola zadan· premenn· %s.\n",
					STR_TYZDEN);
				ALERT;
				return FAILURE; /* failure */
			}

			/* premenna MODLITBA */
			if(equals(param[3].name, STR_MODLITBA)){
				mystrcpy(pom_MODLITBA, param[3].val, SMALL);
			}
			else{
				Export("Nebola zadan· premenn· %s.\n",
					STR_MODLITBA);
				ALERT;
				return FAILURE; /* failure */
			}

			break; /* case */
		}

		case PRM_SVIATOK:{
		/* pripad, ze ide o sviatok */
			/* premenna NAZOV_SVIATOK */
			if(equals(param[1].name, STR_NAZOV_SVIATOK)){
				mystrcpy(pom_SVIATOK, param[1].val, SMALL);
			}
			else{
				Export("Nebola zadan· premenn· %s.\n",
					STR_NAZOV_SVIATOK);
				ALERT;
				return FAILURE; /* failure */
			}
			break; /* case */
		}

		case PRM_ANALYZA_ROKU:{
		/* pripad, ze ide o sviatok */
			/* premenna ANALYZA_ROKU */
			if(equals(param[1].name, STR_ANALYZA_ROKU)){
				mystrcpy(pom_ANALYZA_ROKU, param[1].val, SMALL);
			}
			else{
				Export("Nebola zadan· premenn· %s.\n",
					STR_ANALYZA_ROKU);
				ALERT;
				return FAILURE; /* failure */
			}
			break; /* case */
		}

		case PRM_MESIAC_ROKA:{
		/* pripad, ze ide o mesiac roka */

			/* premenna MESIAC */
			if(equals(param[1].name, STR_MESIAC_ROKA)){
				mystrcpy(pom_MESIAC, param[1].val, SMALL);
			}
			else{
				Export("Nebola zadan· premenn· %s.\n",
					STR_MESIAC_ROKA);
				ALERT;
				return FAILURE; /* failure */
			}

			/* premenna ROK */
			if(equals(param[2].name, STR_ROK_ROKA)){
				mystrcpy(pom_ROK, param[2].val, SMALL);
			}
			else{
				Export("Nebola zadan· premenn· %s.\n",
					STR_ROK_ROKA);
				ALERT;
				return FAILURE; /* failure */
			}

			break; /* case */
		}

		case PRM_TABULKA:{
		/* pripad, ze ide o tabulku pohyblivych slaveni */
			/* premenna ROK_FROM */
			if(equals(param[1].name, STR_ROK_FROM)){
				mystrcpy(pom_ROK_FROM, param[1].val, SMALL);
			}
			else{
				Export("Nebola zadan· premenn· %s.\n",
					STR_ROK_FROM);
				ALERT;
				return FAILURE; /* failure */
			}

			/* premenna ROK_TO */
			if(equals(param[2].name, STR_ROK_TO)){
				mystrcpy(pom_ROK_TO, param[2].val, SMALL);
			}
			else{
				Export("Nebola zadan· premenn· %s.\n",
					STR_ROK_TO);
				ALERT;
				return FAILURE; /* failure */
			}

			/* premenna TABULKA_LINKY */
			if(equals(param[3].name, STR_TABULKA_LINKY)){
				mystrcpy(pom_LINKY, param[3].val, SMALL);
			}
			else{
				/* nevadi, ze nebola zadana premenna ci zobrazovat linky k tabulke */
			}
			break; /* case */
		}

	}
	Log("parseQueryString() -- end, returning SUCCESS\n");
	return SUCCESS;
}/* parseQueryString(); */

/* KOMPILACIA -- idiotuv pruvodce kompilovanim tohoto gigantu */

/* 17/02/2000A.D.: Segmentation fault pod linuxom;
 * 18/02/2000A.D.:
 * preto som prerobil _global_... (typov _struct...) na ..._ptr,
 * ktore sa alokuju dynamicky
 * a povodne mena su urobene ako symbolicke mena
 * vsetko je to deklarovane v liturgia.h
 *            a definovane tu, v dnes.cpp
 * 30/03/2000A.D.: pridane myconf.cpp a mydefs.cpp, premenovane dnes.cpp --> breviar.cpp
 * 31/03/2000A.D.: pridane mystring.cpp (kvoli buffer overflow na webe)
 * 
 * teraz sa kompiluje a linkuje takto:
 *
 * DOS: Project --> obsahuje liturgia.cpp, dnes.cpp
 * linux: file `urob'
 * ------------------------(begin of file `urob')
	chmod u=rwx *.*
	make
	cp uncgi uncgi.cgi
	g++ breviar.cpp dbzaltar.cpp liturgia.cpp mygetopt.cpp mylog.cpp myhpage.cpp myexpt.cpp cgiutils.cpp myconf.cpp mydefs.cpp mystring.cpp
	mv a.out l.cgi
	chmod u=rw *.c
	chmod u=rw *.cpp
	chmod u=rw *.h
	chmod oa+x *.cgi
 * ------------------------(end of file `urob')
 * 21/02/2000A.D.: vsetky inkludy, ktore su .h a .c[pp], som prerobil
 * tak, aby sa inkludovali .h, kde su premenne iba (extern) deklarovane
 */

/*---------------------------------------------------------------------*/
/* main();
 *    hlavny program
 */
#define FILE_LOG "dnes.log"

#define _main_LOG_to_Export Log
#define _main_LOG Log

void main(int argc, char **argv){
	/* pretoze pocas behu win32-release verzie on-line breviara sa spusta
	 * main() viackrat bez zrusenia programu,
	 * je potrebne inicializovat globalne premenne pri kazdom pusteni jej behu
	 * 11/04/2000A.D.
	 */
	_global_opt1 = NIE;
	_global_opt2 = MODL_ZALMY_ZO_SV;
	_global_opt3;
	_global_opt4 = ANO;
	strcpy(pom_QUERY_TYPE , "");
	strcpy(pom_DEN        , "");
	strcpy(pom_MESIAC     , ""); 
	strcpy(pom_ROK        , ""); 
	strcpy(pom_MODLITBA   , "");
	strcpy(pom_MODL_OPT1  , "");
	strcpy(pom_MODL_OPT2  , "");
	strcpy(pom_MODL_OPT3  , "");
	strcpy(pom_MODL_OPT4  , "");
	strcpy(pom_DALSI_SVATY, "");
	strcpy(pom_ROK_FROM   , "");
	strcpy(pom_ROK_TO     , "");
	strcpy(pom_LINKY, "");
	/* koniec inicializacie globalnych premennych; teraz samotna main()
	 * 11/04/2000A.D.
	 */
#if defined(OS_linux)
	_global_linky = 1; /* zobrazovat linky */
#elif defined(OS_Windows)
	_global_linky = 0; /* nezobrazovat linky */
#elif defined(OS_DOS)
	_global_linky = 1; /* zobrazovat linky */
#else
	#error Unsupported operating system (not defined in mysystem.h)
#endif

	int ret; /* navratova hodnota */

	initLog(FILE_LOG);

	_main_LOG("-- log file programu pre Liturgiu hodin (c)1999-2000 Juraj Videky --\n");

	/* config: dorobene 30/03/2000A.D. */
	_main_LOG("first, reading configuration (file %s)...\n", CONFIG_FILE);
	readConfig();
	_main_LOG("HTTP_ADDRESS == `%s'\n", HTTP_ADDRESS);
	_main_LOG("MAIL_ADDRESS == `%s'\n", MAIL_ADDRESS);
	updateScriptName();
	_main_LOG("script_name == %s\n", script_name);
	updateUnCGIName();
	_main_LOG("uncgi_name == %s\n", uncgi_name);

	/* o initExport() pozri poznamky na prislusnych zapoznamkovanych miestach
	 * 24/02/2000A.D. */
	initExport();
	hlavicka("Liturgia hodÌn");

	/* nasledovalo tu vypisanie headingu 1,
	 * avsak to je teraz v kazdej funkcii _main_...
	 * zabezpecene funkciou _export_heading(int, const char *); */

	/* pre query_string musime alokovat pamat */
	_main_LOG("/* pre query_string musime alokovat pamat */\n");
	_main_LOG("now allocating memory...\n");

	/* query_string */
	if((query_string = (char*) malloc(MAX_QUERY_STR)) == NULL){
		_main_LOG("  Not enough memory to allocate buffer for `query_string'\n");
		goto _main_end;
	}
	else{
		_main_LOG("  %d bytes for `query_string'\n", MAX_QUERY_STR);
	}
	_main_LOG("...done.\n");

	_main_LOG("spustatm getSrciptParamFrom(argc == %d)...\n", argc);
	params = getSrciptParamFrom(argc);
	/* vysledok je, ze sa do params nacita bud
	 * SCRIPT_PARAM_FROM_FORM alebo
	 * SCRIPT_PARAM_FROM_QS alebo
	 * SCRIPT_PARAM_FROM_ARGV;
	 * ------------------------------ 01/02/2000A.D. ---
	 *
	 * ak vsak pouzivam aj query string, aj vysledky
	 * z formulara, vysledok bude predsa SCRIPT_PARAM_FROM_QS, lebo
	 * QS je neprazdny retazec; taku strategiu umoznuje uncgi.c:
	 * ---
	 * First, get the query string, wherever it is, and stick its
	 * component parts into the environment.  Allow combination
	 * GET and POST queries, even though that's a bit strange.
	 * ---
	 * takze v pripade, ze query string je neprazdny, treba
	 * 1. zistit systemove premenne WWW_...
	 * 2. zistit (a rozparsovat) QUERY_STRING
	 *
	 */

	ret = NO_RESULT;
	switch(params){
	/* v tomto switch() naplnime premennu query_type
	 * a naviac (ak su) premenne pom_... */
		case SCRIPT_PARAM_FROM_FORM:{
			/* initExport(); bola kedysi na zaciatku, avsak kvoli tomu, aby
			 * bolo mozne menit (switch -e) nazov suboru, dalo sa to sem
			 * 24/02/2000A.D. -- urobil som to presne tak, ako bolo kedysi
			 */
			/*
			initExport();
			hlavicka("Liturgia hodÌn");
			 */
			_main_LOG_to_Export("params == SCRIPT_PARAM_FROM_FORM\n");
			/* neboli zadane ziadne parametre, teda citam z formularu */
			query_type = getQueryTypeFrom_WWW();
			/* zistili sme, aky je typ dotazu */
			if(query_type == PRM_NONE){
				/* spusteny bez parametrov */
				_main_LOG_to_Export("query_type == PRM_NONE\n");
				_main_LOG_to_Export("spustam _main_prazdny_formular();\n");
				_main_prazdny_formular();
				_main_LOG_to_Export("spat po skonceni _main_prazdny_formular()\n");
				goto _main_end;
			}
			else{
				_main_LOG_to_Export("spustam getForm();\n");
				ret = getForm();
				_main_LOG_to_Export("spat po skonceni getForm()\n");
			}
			break;
		}
		case SCRIPT_PARAM_FROM_ARGV:{
			_main_LOG("params == SCRIPT_PARAM_FROM_ARGV\n");
			_main_LOG("spustam getArgv();\n");
			/* query_type sa nastavi priamo vovnutri */
			ret = getArgv(argc, argv);
			if(ret == SUCCESS){ /* 13/03/2000A.D. -- aby mohlo exportovat do file_export */
				Log("file_export == `%s'...\n", file_export);
				if(equals(file_export, "") || equals(file_export, "+")){
					/* "+" -- error, chce pridavat do nicoho */
					Log("continuing to export in FILE_EXPORT (`%s')...\n", FILE_EXPORT);
				}
				else{
					if(initExport(file_export) == SUCCESS){
						Log("initExport(`%s'): success\n", file_export);
						hlavicka("Liturgia hodÌn");
					}
					else{
						Log("initExport(`%s'): failure, \n", file_export);
						Log("continuing to export into DEFAULT_FILE_EXPORT (`%s')\n", DEFAULT_FILE_EXPORT);
						initExport(DEFAULT_FILE_EXPORT);
						hlavicka("Liturgia hodÌn");
					}
				}
			}
			_main_LOG("spat po skonceni getArgv(); exporting to file `%s'...\n",
				FILE_EXPORT);

			/* 24/02/2000A.D. pridana simulacia QS */
			if(query_type == PRM_SIMULACIA_QS){
				Log("jumping to _main_SIMULACIA_QS (query_string == %s)...\n", query_string);
				goto _main_SIMULACIA_QS;
			}

			/* initExport(); bola kedysi na zaciatku, avsak kvoli tomu, aby
			 * bolo mozne menit (switch -e) nazov suboru, dalo sa to sem
			 * 24/02/2000A.D. -- urobil som to presne tak, ako bolo kedysi
			 */
			/*
			initExport();
			hlavicka("Liturgia hodÌn");
			*/
			break;
		}
		case SCRIPT_PARAM_FROM_QS:{
			/* initExport(); bola kedysi na zaciatku, avsak kvoli tomu, aby
			 * bolo mozne menit (switch -e) nazov suboru, dalo sa to sem
			 * 24/02/2000A.D. -- urobil som to presne tak, ako bolo kedysi
			 */
			/*
			initExport();
			hlavicka("Liturgia hodÌn");
			*/

			_main_LOG_to_Export("params == SCRIPT_PARAM_FROM_QS\n");
			/* nasledujuca pasaz je tu preto, ze mozno bolo pouzite kombinovane
			 * aj query string, aj formular (teda treba citat aj systemove
			 * premenne WWW_...
			 */
			_main_LOG_to_Export("---scanning for system variables WWW_...: started...\n");
			/* historicka poznamka:                          (01/02/2000A.D.)
			 * kedysi tu tato pasaz (podla casti `case SCRIPT_PARAM_FROM_FORM')
			 * nebola, avsak pretoze to neumoznovalo `mixovane' dotazy
			 * (ked je nieco v QS a navyse, uncgi.c vlozi (aj QS aj) ostatne veci
			 *  z formulara do systemovych premennych WWW_...),
			 * zmenili sme to tak, ze sa tu precitaju WWW_... a potom parsuje qs
			 */
			query_type = getQueryTypeFrom_WWW();
			/* zistili sme, aky je typ dotazu podla formulara */
			if((query_type != PRM_NONE) && (query_type != PRM_UNKNOWN)){
				/* znamena to teda, ze existuje systemova premenna,
				 * oznacujuca typ dotazu ==> treba nacitat z formulara resp.
				 * systemovych premennych WWW_...
				 */
				_main_LOG_to_Export("spustam getForm();\n");
				ret = getForm();
				_main_LOG_to_Export("params from system variables WWW_...:\n");
				_main_LOG_to_Export("param1 == %s (pom_DEN/pom_SVIATOK/pom_DEN_V_TYZDNI), param1 == %s (pom_ROK_FROM)\n", pom_DEN, pom_ROK_FROM);
				_main_LOG_to_Export("param2 == %s (pom_MESIAC/pom_TYZDEN), param2 == %s (pom_ROK_TO)\n", pom_MESIAC, pom_ROK_TO);
				_main_LOG_to_Export("param3 == %s (pom_ROK/pom_ANALYZA_ROKU), param3 == %s (pom_LINKY)\n", pom_ROK, pom_LINKY);
				_main_LOG_to_Export("param4 == %s (pom_MODLITBA)\n", pom_MODLITBA);
				_main_LOG_to_Export("param5 == %s (pom_DALSI_SVATY)\n", pom_DALSI_SVATY);
				_main_LOG_to_Export("param6 == %s (pom_MODL_OPT1)\n", pom_MODL_OPT1);
				_main_LOG_to_Export("param7 == %s (pom_MODL_OPT2)\n", pom_MODL_OPT2);
				_main_LOG_to_Export("param8 == %s (pom_MODL_OPT3)\n", pom_MODL_OPT3);
				_main_LOG_to_Export("param9 == %s (pom_MODL_OPT4)\n", pom_MODL_OPT4);
				_main_LOG_to_Export("spat po skonceni getForm()\n");
			}
			_main_LOG_to_Export("---scanning for system variables WWW_...:finished.\n");
			/* a bez ohladu na to, ci sme nieco precitali z WWW_... pokracujeme
			 * parsovanim query stringu;
			 * pritom je mozne, ze niektore hodnoty nacitane z WWW_... (alebo
			 * aj vsetky) prepiseme prave tymito, z qs - ale nevadi-NEVADI |_
			 */
_main_SIMULACIA_QS:
			_main_LOG_to_Export("---getting query type from query string (query_string == %s):\n", query_string);
			query_type = getQueryTypeFrom_QS(query_string);
			_main_LOG_to_Export("---getting query type from query string: finished.\n");

			_main_LOG_to_Export("---parsing query string:\n");
			ret = parseQueryString();
			_main_LOG_to_Export("---parsing query string: finished.\n");
			break;
		}
	}

	_main_LOG_to_Export("query_type == ");
	switch(query_type){
		case PRM_UNKNOWN: _main_LOG_to_Export("PRM_UNKNOWN\n"); break;
		case PRM_TABULKA: _main_LOG_to_Export("PRM_TABULKA\n"); break;
		case PRM_NONE: _main_LOG_to_Export("PRM_NONE\n"); break;
		case PRM_DATUM: _main_LOG_to_Export("PRM_DATUM\n"); break;
		case PRM_DETAILY: _main_LOG_to_Export("PRM_DETAILY\n"); break;
		case PRM_CEZ_ROK: _main_LOG_to_Export("PRM_CEZ_ROK\n"); break;
		case PRM_ANALYZA_ROKU: _main_LOG_to_Export("PRM_ANALYZA_ROKU\n"); break;
		case PRM_SVIATOK: _main_LOG_to_Export("PRM_SVIATOK\n"); break;
		case PRM_MESIAC_ROKA: _main_LOG_to_Export("PRM_MESIAC_ROKA\n"); break;
		case PRM_DNES: _main_LOG_to_Export("PRM_DNES\n"); break;
	}

	_main_LOG_to_Export("param1 == %s (pom_DEN/pom_SVIATOK/pom_DEN_V_TYZDNI), param1 == %s (pom_ROK_FROM)\n", pom_DEN, pom_ROK_FROM);
	_main_LOG_to_Export("param2 == %s (pom_MESIAC/pom_TYZDEN), param1 == %s (pom_ROK_TO)\n", pom_MESIAC, pom_ROK_TO);
	_main_LOG_to_Export("param3 == %s (pom_ROK/pom_ANALYZA_ROKU), param1 == %s (pom_LINKY)\n", pom_ROK, pom_LINKY);
	_main_LOG_to_Export("param4 == %s (pom_MODLITBA)\n", pom_MODLITBA);
	_main_LOG_to_Export("param5 == %s (pom_DALSI_SVATY)\n", pom_DALSI_SVATY);
	_main_LOG_to_Export("param6 == %s (pom_MODL_OPT1)\n", pom_MODL_OPT1);
	_main_LOG_to_Export("param7 == %s (pom_MODL_OPT2)\n", pom_MODL_OPT2);
	_main_LOG_to_Export("param8 == %s (pom_MODL_OPT3)\n", pom_MODL_OPT3);
	_main_LOG_to_Export("param9 == %s (pom_MODL_OPT4)\n", pom_MODL_OPT4);

	if(query_type == PRM_MESIAC_ROKA){
		mystrcpy(pom_DEN, STR_VSETKY_DNI, SMALL);
		query_type = PRM_DATUM;
	}

	if(query_type != PRM_UNKNOWN){

		if(ret == SUCCESS){
			/* alokovanie pamate som sem premiestnil 24/02/2000A.D. */
			_main_LOG_to_Export("now allocating memory...\n");
			if(_allocate_global_var() == FAILURE)
				goto _main_end;

			LOG_ciara;
		
			/* pridane 27/04/2000A.D. */
			_main_LOG_to_Export("pom_LINKY == `%s'\n", pom_LINKY);
#if defined(OS_linux)
			_global_linky = 1; /* zobrazovat linky */
#elif defined(OS_Windows)
			if(pom_LINKY != NULL) /* pridane 13/04/2000A.D. */
				_global_linky = atoi(pom_LINKY);
			_main_LOG_to_Export("/* Windows: teraz som nastavil _global_linky == %d */\n", _global_linky);
#elif defined(OS_DOS)
			if((pom_LINKY != NULL) && (!equals(pom_LINKY, ""))){ /* pridane 27/04/2000A.D. */
				_global_linky = atoi(pom_LINKY);
				_main_LOG_to_Export("/* DOS: teraz som nastavil _global_linky == %d */\n", _global_linky);
			}
#else
	#error Unsupported operating system (not defined in mysystem.h)
#endif

			/* inak ostane defaul nastaveny na zaciatku pre kazdy operacny system zvlast */
			_main_LOG_to_Export("/* teraz nasleduje vykonanie jadra programu podla parametrov */\n");
			_main_LOG_to_Export("switch: podla query_type...\n");
			switch(query_type){
				case PRM_DETAILY:
				/* presne to iste co PRM_DATUM s jedinkym rozdielom: co sa tyka
				 * formularov, prvy (uvodny) formular pre PRM_DATUM vycisti
				 * modlitbu (premenna pom_MODLITBA, ktora sa nacita zo systemovej
				 * premennej WWW_MODLITBA) -- pretoze z inej casti fomrulara sa
				 * tam nieco dostane...
				 */
				case PRM_DATUM:
					_main_LOG_to_Export("spustam _main_rozbor_dna(%s, %s, %s, %s, %s);\n",
						pom_DEN, pom_MESIAC, pom_ROK, pom_MODLITBA, pom_DALSI_SVATY);
					_main_rozbor_dna(pom_DEN, pom_MESIAC, pom_ROK, pom_MODLITBA, pom_DALSI_SVATY);
					_main_LOG_to_Export("spat po skonceni _main_rozbor_dna(%s, %s, %s, %s, %s);\n",
						pom_DEN, pom_MESIAC, pom_ROK, pom_MODLITBA, pom_DALSI_SVATY);
					break;
				case PRM_CEZ_ROK:
					_main_LOG_to_Export("spustam _main_zaltar(%s, %s, %s);\n", pom_DEN_V_TYZDNI, pom_TYZDEN, pom_MODLITBA);
					_main_zaltar(pom_DEN_V_TYZDNI, pom_TYZDEN, pom_MODLITBA);
					_main_LOG_to_Export("spat po skonceni _main_zaltar(%s, %s, %s);\n", pom_DEN_V_TYZDNI, pom_TYZDEN, pom_MODLITBA);
					break;
				case PRM_SVIATOK:
					_main_LOG_to_Export("spustam sviatok(%s);\n", pom_SVIATOK);
					_main_sviatok(pom_SVIATOK);
					_main_LOG_to_Export("spat po skonceni sviatok(%s);\n", pom_SVIATOK);
					break;
				case PRM_ANALYZA_ROKU:
					_main_LOG_to_Export("spustam analyza_roku(%s);\n", pom_ANALYZA_ROKU);
					_main_analyza_roku(pom_ANALYZA_ROKU);
					_main_LOG_to_Export("spat po skonceni analyza_roku(%s);\n", pom_ANALYZA_ROKU);
					break;
				case PRM_DNES:
					_main_LOG_to_Export("spustam _main_dnes();\n");
					_main_dnes();
					_main_LOG_to_Export("spat po skonceni _main_dnes();\n");
					break;
				case PRM_TABULKA:					
					_main_LOG_to_Export("spustam _main_tabulka();\n");
					_main_tabulka(pom_ROK_FROM, pom_ROK_TO, pom_LINKY);
					_main_LOG_to_Export("spat po skonceni _main_tabulka();\n");
					break;
				default:
					Export("Intern· chyba programu.\n");
					Export("<br>(switch(query_type); case == default)\n");
					ALERT;
					break;
			}/* switch(query_type) */

			_deallocate_global_var();
			/* dealokovanie som sem presunul 24/02/2000A.D. */

		}/* if(ret == SUCCESS) */
		else if(ret == FAILURE){
			/* uz sa vyriesilo vyssie, dufam :-) */
			_main_LOG_to_Export("ret == FAILURE\n");
		}
		else if(ret == NO_RESULT){
			/* vtedy, ked
			 * - case SCRIPT_PARAM_FROM_FORM
			 * - query_type == PRM_NONE
			 * - historicka poznamka: povodne spustilo sa prazdny_formular();
			 * - v skutocnosti _main_prazdny_formular();
			 */
			_main_LOG_to_Export("ret == NO_RESULT\n");
		}
	}/* if(query_type != PRM_UNKNOWN) */
	else{
		Export("ObsluûnÈmu programu neboli zadanÈ vhodnÈ parametre.\n");
		Export("<p>Nezn·my parameter: %s.\n", bad_param_str);
		ALERT;
	}

	_main_LOG_to_Export("Deallocating memory...\n");
	_main_LOG_to_Export("query_string\n"); free(query_string);
	_main_LOG_to_Export("...done.\n");
_main_end:
	patka();
	if(closeExport() == EOF)
		Log("closeExport(): error closing file (return == EOF)\n");
	else
		Log("closeExport(): success.\n");
	closeLog();
}
