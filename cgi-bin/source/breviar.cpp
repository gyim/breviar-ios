/***************************************************************************/
/*                                                                         */
/* breviar.cpp                                                             */
/* (c)1998-2006 | Juraj Videky | videky@breviar.sk                         */
/*                                                                         */
/*                http://www.breviar.sk                                    */
/*                                                                         */
/* description | program tvoriaci stranky pre liturgiu hodin               */
/* document history                                                        */
/*   30/01/2000A.D. | trencin, modified                                    */
/*   01/02/2000A.D. | bratislava, modified                                 */
/*   18/02/2000A.D. | bratislava, modified                                 */
/*   25/02/2000A.D. | bratislava, modified                                 */
/*   30/03/2000A.D. | premenoval som dnes.cpp na breviar.cpp               */
/*   06/09/2001A.D. | tento popis                                          */
/*   2003-06-27a.D. | zacinam znova :))                                    */
/*                  - nefunguju detaily pre spomienku pm v sob.            */
/*                  - 2003-06-28: sv.Irenej; ma byt aj srdce pm            */
/*   2003-06-30a.D. | Peto Santavy napisal mail o chybach                  */
/*                  - prve vespery petra-pavla su zle v r.2003             */
/*                    (2003-06-28): zmena v liturgicke_obdobie             */
/*   2003-06-30a.D. | build (priliepa sa do hlavicky)                      */
/*                    (vypisovanie BUILD_DATE, mybase.h)                   */
/*   2003-07-01a.D. | opravene Detaily... pre Spom.PM v sobotu             */
/*   2003-07-02a.D. | pridana LINK_DEN_MESIAC_ROK_PRESTUP                  */
/*                    kvoli prestupnym rokom (_main_tabulka)               */
/*                  - pridane HTML_ elementy (mydefs.h)                    */
/*   2003-07-07a.D. | pridany batch mode (davkove spracovanie)             */
/*   2003-07-08a.D. | pridany parameter (option) `a' (append)              */
/*   2003-07-09a.D. | drobne zmeny kvoli HTML 4.01 Valid                   */
/*                  - zmena & v linkach na HTML_AMPERSAND                  */
/*   2003-07-14a.D. | zmena void main -> int main (gcc v3.2.2 )            */
/*                  - <font size=-1></font> zmeneny na                     */
/*                    <span class="small"></span>                          */
/*   2003-07-15a.D. | rozne pokusy s modlitbou cez den                     */
/*                  - pridane HTML_BUTTON_                                 */
/*   2003-07-15a.D. | odstraneny #include "mybase.h"                       */
/*   2003-07-16a.D. | este jedna zmena & na HTML_AMPERSAND                 */
/*                  - zmena WWW_ na ADD_WWW_PREFIX_                        */
/*                  - zmena exportovania uvodnej stranky                   */
/*   2003-07-17a.D. | zmena helpu (vypis pri commandd-line                 */
/*   2003-08-06a.D. | dalsie pokusy s modlitbou cez den                    */
/*   2003-08-11a.D. | -Wall upozornila na vselico                          */
/*   2003-08-11a.D. | Segmentation fault odhaleny-vid POUCENIE             */
/*   2003-08-12a.D. | opt5 pridana (modlitba cez den)                      */
/*   2003-08-13a.D. | zmena "" na STR_EMPTY (mystring.h)                   */
/*                  - odstranenie RUN_MODLITBA_CEZ_DEN                     */
/*                  - odstranenie POKUS_24_02_2000                         */
/*                  - male zmeny v includeFile()                           */
/*                  - option5 dorobena aj do getForm()                     */
/*   2003-08-21a.D. | interpretParameter() pre posv. citania               */
/*   2003-10-07a.D. | chybali prosby pre 1. vespery nediel OCR             */
/*                    dbzaltar.cpp::_SET_SPOLOCNE_VECI_NEDELA              */
/*   2003-11-20a.D. | interpretParameter(): pre posv. citania              */
/*                    pridane citanie1 a citanie2                          */
/*   2004-03-11a.D. | pre batch mod export parametrov                      */
/*   2004-03-16a.D. | pre batch mod export zoznamu ako HTML                */
/*   2004-03-17a.D. | cesty sa citaju z konfigu (INCLUDE_DIR)              */
/*   2005-03-21a.D. | novy typ exportu (1 den-1 riadok) pre LK             */
/*   2005-03-22a.D. | uprava funkcie parseQueryString()                    */
/*   2005-03-28a.D. | nova funkcia setForm(), uprava pre uncgi             */
/*   2005-03-30a.D. | upravene getForm()                                   */
/*   2005-05-24a.D. | opravena copy-paste chyba pre pom_ROK_TO             */
/*   2005-07-22a.D. | pridan˝ popis aj pre posv.ËÌtanie a mcd              */
/*   2005-07-27a.D. | rozöÌren· ötrukt˙ra dm (lokaliz·cia sl·venÌ)         */
/*   2005-08-15a.D. | upraven· _main_zaltar(): STR_MODL_                   */
/*                  - doroben˝ ûalt·r aj pre posv‰tnÈ ËÌtania              */
/*                  - interpretParameter: novÈ PARAM_HYMNUS_34_OCR_INY_... */
/*   2005-08-22a.D. | upraven· _export_rozbor_dna() - vöednÈ dni aj pre 11 */
/*   2005-11-11a.D. | DoplnenÈ: Te Deum posv‰tn˝m ËÌtaniam                 */
/*   2006-01-20a.D. | Oprava: Uû sa zobrazuj˙ aj spomienky v pÙste (æ.s.)  */
/*   2006-01-25a.D. | zmena default pre _global_opt2 => LINK_ISO_8601      */
/*   2006-01-28a.D. | upraven˝ spÙsob v˝pisu v includeFile()               */
/*   2006-01-31a.D. | batch mÛd exportuje aj mcd (mna) a posv. ËÌtanie     */
/*   2006-02-02a.D. | vytvoren· fcia _main_formular(),zobraz.pre kaûd˝ deÚ */
/*   2006-02-06a.D. | ˙prava v _rozbor_dna() kvÙli nastaveniu _global_opt3 */
/*   2006-07-11a.D. | prvÈ kroky k jazykov˝m mut·ci·m                      */
/*   2006-08-18a.D. | pokus: zmena mnoh˝ch int na short int (staËÌ 32tis.) */
/*   2006-08-19a.D. | zaveden˝ nedefinovan˝ define ZOBRAZ_JULIANSKY_DATUM  */
/*   2006-08-19a.D. | doplnenÈ liturgickÈ farby                            */
/*   2006-08-22a.D. | doplnen· ruûov· liturgick· farba                     */
/*   2006-09-06a.D. | upratanie vo funkcii init_global_string (t˝û.û.preNE)*/
/*                                                                         */
/*                                                                         */
/* pozn·mky |                                                              */
/*   * ako kompilovat a linkovat?                                          */
/*     najdi zarazku KOMPILACIA -- niekde ku koncu                         */
/*     pozri tiez POUCENIE                                                 */
/*   * unfinished parts: oznaËenÈ !!! alebo xxx                            */
/*   * debug in VC++: alt+f7, zalozka Debug, Program arguments             */
/*     napr. -qpbm -d1 -m1 -r2000 -f2 -g2 -p2001 -ba.txt                   */
/*     -i..\..\..\web\include\ -qpsqs -s"qt=pcr&dvt=pondelok&t=2&p=mpc"    */
/*     lh -qpdt -d30 -m4 -r2002 -pmrch -ic:\temp\breviar\ -emoja.htm       */
/*                                                                         */
/***************************************************************************/

#ifndef __BREVIAR_C_
#define __BREVIAR_C_

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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

/* 2005-03-28: Pridane, pokusy nahradit uncgi */
char *_global_buf; /* 2006-08-01: t˙to premenn˙ tieû alokujeme */
char *_global_buf2; /* 2006-08-01: vytvorenÈ; t˙to premenn˙ tieû alokujeme */

#define ishex(x) (((x) >= '0' && (x) <= '9') || ((x) >= 'a' && (x) <= 'f') || \
		  ((x) >= 'A' && (x) <= 'F'))

#define MAX_BUFFER 30

#define ANCHOR_VYSVETLIVKY "VYSVETLIVKY"
#define FILE_VYSVETLIVKY "vysvetl.htm"

#define ANCHOR_VYSVETLIVKY_TABULKA "VYSVETL_TABULKA"
#define FILE_VYSVETLIVKY_TABULKA "vysvetlt.htm"

#define UNKNOWN_PORADIE_SVATEHO -1 
/* 28/03/2000A.D.: naschval < 0, aby nebol problem s porovnanim s _global_pocet_svatych v _rozbor_dna() */

#define LOG_ciara Log("---------------------\n");

#define FILE_LOG "dnes.log"

#define _main_LOG_to_Export Log
#define _main_LOG Log

#ifndef OS_linux
	#include "breviar.h" /* su tam deklarovane nasledovne globalne premenne a main() */
#endif
/* ------------------------------------------------------------------- */
/* globalne premenne -- deklarovane v liturgia.h, definovane tu */
/* 18/02/2000A.D. */

short int query_type; /* premenna obsahujuca PRM_..., deklarovana v mydefs.h */

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

/* 2003-08-13 pridane posvatne citanie */
_type_posv_citanie *_global_modl_posv_citanie_ptr;
#define _global_modl_posv_citanie (*_global_modl_posv_citanie_ptr)

_type_ranne_chvaly *_global_modl_ranne_chvaly_ptr;
/*_type_ranne_chvaly  _global_modl_ranne_chvaly;*/
#define _global_modl_ranne_chvaly (*_global_modl_ranne_chvaly_ptr)

_type_cez_den_9     *_global_modl_cez_den_9_ptr;
/*_type_cez_den_9     _global_modl_cez_den_9;*/
#define _global_modl_cez_den_9 (*_global_modl_cez_den_9_ptr)
_type_cez_den_12     *_global_modl_cez_den_12_ptr;
/*_type_cez_den_12     _global_modl_cez_den_12;*/
#define _global_modl_cez_den_12 (*_global_modl_cez_den_12_ptr)
_type_cez_den_3     *_global_modl_cez_den_3_ptr;
/*_type_cez_den_3     _global_modl_cez_den_3;*/
#define _global_modl_cez_den_3 (*_global_modl_cez_den_3_ptr)

_type_vespery      *_global_modl_vespery_ptr;
/*_type_vespery       _global_modl_vespery;*/
#define _global_modl_vespery (*_global_modl_vespery_ptr)

_type_kompletorium *_global_modl_kompletorium_ptr;
/*_type_kompletorium _global_modl_kompletorium;*/
#define _global_modl_kompletorium (*_global_modl_kompletorium_ptr)

/* globalna premenna, ktora obsahuje MODL_... */
short int _global_modlitba;

/* globalna premenna, do ktorej ukladaju funkcie vytvor_query_string_...
 * linku tvaru PATH_CGI(script_name) ++ "?param1=val&param2=val&..." 
 * 2003-07-09 prerobeny & v linkach na HTML_AMPERSAND
 */
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
short int _global_pocet_svatych;

/* globalne premenne, obsahujuce pom_MODL_OPT... */
short int _global_opt1 = NIE;
short int _global_opt2 = MODL_ZALMY_ZO_DNA; /* 2006-01-25: upravenÈ, bolo tu MODL_ZALMY_ZO_SV */
short int _global_opt3 = MODL_SPOL_CAST_NEURCENA;
short int _global_opt4 = ANO; /* pridana 05/04/2000A.D. */
short int _global_opt5 = MODL_CEZ_DEN_ZALMY_ZO_DNA; /* pridana 2003-08-07 */
/* pokial ide o _global_opt5, kontroluje sa v zaltar(); poznamka pridana 2003-08-13 */
/* pridane 2003-07-08, append parameter */
short int _global_opt_append = NIE;

/* globalna premenna, co obsahuje string vypisany na obrazovku */
char *_global_string;
/*char _global_string[MAX_STR];*/
char *_global_string2;
/*char _global_string2[MAX_STR];*/ /* obsahuje I, II, III, IV, V alebo pismeno roka */
char *_global_string_farba; /* 2006-08-19: doplnenÈ */

/* pridane 13/04/2000A.D.; deklarovane v liturgia.h */
short int _global_linky;

/* 2006-07-11: PridanÈ kvÙli jazykov˝m mut·ci·m */
short int _global_language;
#ifndef _global_jazyk
#define	_global_jazyk	_global_language
#endif

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
short int _global_skip_in_prayer;

/* globalna premenna, ktora hovori, ci generujeme modlitbu */
//int _global_gen_modlitba; == (_global_modlitba == MODL_NEURCENA)

short int params; /* odkial su brane parametre; hodnoty
 * SCRIPT_PARAM_FROM_FORM
 * SCRIPT_PARAM_FROM_ARGV
 * SCRIPT_PARAM_FROM_QS
 */
char *query_string; /* QUERY_STRING environment variable */

char pom_QUERY_TYPE [MAX_POM_QUERY_TYPE] = STR_EMPTY; /* typ dotazu, retazec */
char pom_DEN        [SMALL] = STR_EMPTY; /* sluzi aj ako pom_DEN_V_TYZDNI a pom_SVIATOK */
#define pom_DEN_V_TYZDNI	pom_DEN
#define pom_SVIATOK			pom_DEN
char pom_MESIAC     [SMALL] = STR_EMPTY; /* sluzi aj ako pom_TYZDEN aj ako mesiac roka */
#define pom_TYZDEN		pom_MESIAC
char pom_ROK        [SMALL] = STR_EMPTY; /* sluzi aj ako pom_ANALYZA_ROKU */
#define pom_ANALYZA_ROKU	pom_ROK
char pom_MODLITBA   [SMALL] = STR_EMPTY;
char pom_MODL_OPT1  [SMALL] = STR_EMPTY;
char pom_MODL_OPT2  [SMALL] = STR_EMPTY;
char pom_MODL_OPT3  [SMALL] = STR_EMPTY;
char pom_MODL_OPT4  [SMALL] = STR_EMPTY;
/* pom_MODL_OPT5 pridana 2003-08-07 */
char pom_MODL_OPT5  [SMALL] = STR_EMPTY;
/* append pridany 2003-07-08, bude v _global_opt_append */
char pom_MODL_OPT_APPEND  [SMALL] = STR_EMPTY;
char pom_DALSI_SVATY[SMALL] = STR_EMPTY;
/* tieto dalsie 3 pridane kvoli PRM_TABULKA, 15/03/2000A.D. */
char pom_ROK_FROM   [SMALL] = STR_EMPTY;
char pom_ROK_TO     [SMALL] = STR_EMPTY;
/* pom_LINKY sa povodne volala pom_TABULKA_LINKY, avsak 
 * pouzivame ju vo win32-release ako indikator, ci zobrazovat linky vseobecne,
 * alebo iba "akoze"-odkazy, ako mi poradil Miro M. a aj Matko Bk
 * 13/04/2000A.D. 
 */
char pom_LINKY		[SMALL] = STR_EMPTY;

/* 2006-07-11: PridanÈ kvÙli jazykov˝m mut·ci·m */
char pom_JAZYK		[SMALL] = STR_EMPTY;

char bad_param_str[MAX_STR] = STR_EMPTY; /* inicializacia pridana 2003-08-13 */

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

char file_export[SMALL] = STR_EMPTY; 
/* nazov suboru, do ktoreho sa mozno exportuje
 * v pripade pouzitia switchu `e' pri getArgv();
 * pridane 13/03/2000A.D.
 *
 * ak je na jeho konci '+', tak sa appenduje;
 * vyuzite pre switch -a (append), pozri dolu
 * pre case SCRIPT_PARAM_FROM_ARGV, pridane 2003-07-08
 */

/* nasledovna pasaz pridana 05/06/2000A.D., a to pre 
 * pridany parameter `i' (include directory) */
/* deklarovane pre OS_Windows v mydefs.h */
/* 2004-03-17 vyhodene #ifdef pre windows; pouziva sa to jednotne */
//char FILE_PATH[MAX_STR] = "include\\";

char include_dir[MAX_STR] = STR_EMPTY;

/* nasledovna pasaz pridana 2003-07-04, a to pre batch mode;
 * pridany parameter `n' (name of binary executable),
 * pridany parameter `b' (name of batch mode file) */
char name_binary_executable[MAX_STR] = STR_EMPTY;
char name_batch_file[MAX_STR] = STR_EMPTY;
FILE *batch_file = NULL;
/* 2004-03-16 pridane pre batch mode, parameter `k', aby exportoval aj zoznam modlitieb do HTML */
char name_batch_html_file[MAX_STR] = STR_EMPTY;
FILE *batch_html_file = NULL;

/*---------------------------------------------------------------------*/
/* popis: odstrani backslashe zo stringu (argv[1]) a vrati novy string
 * ale NEVRATI novy string
 * 2006-08-18: hm, zaujÌmav˝ popis; naviac, funkcia sa nepouûÌva... preto zapozn·mkovanÈ.
 *
short int odstran_backslashe(char *input){
	short int i, j = 0;
	short int ilen;
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
*/

/*---------------------------------------------------------------------*/
/*
 * Read a POST query from standard input into a dynamic buffer.  Terminate
 * it with a null character.
 *
 * Vzate 2005-03-28 z uncgi.c.
 * Navratova hodnota SUCCESS/FAILURE,
 * vysledok je v globalnej premennej _global_buf.
 *
 */
short int postread(void){
	char *buf = NULL;
	short int	size = 0, sofar = 0, got;

	Log("uncgi::postread() -- zaciatok\n");
	buf = getenv("CONTENT_TYPE");
	if (buf == NULL || strcmp(buf, "application/x-www-form-urlencoded")){
		Log("uncgi::No content type was passed.\n");
		return FAILURE;
	}

	buf = getenv("CONTENT_LENGTH");
	if (buf == NULL){
		Log("uncgi::The server did not tell uncgi how long the request was.\n");
		return FAILURE;
	}
	
	size = atoi(buf);
	buf = (char *)malloc(size + 1);
	if (buf == NULL){
		Log("uncgi::Error: postread\n");
		return FAILURE;
	}
	do
	{
		got = fread(buf + sofar, 1, size - sofar, stdin);
		sofar += got;
	} while (got && sofar < size);

	buf[sofar] = '\0';

	_global_buf = buf;
	Log("uncgi::postread() -- koniec; v˝stupn˝ buffer == %s\n", _global_buf);
	return SUCCESS;
}

/*---------------------------------------------------------------------*/
/*
 * Convert two hex digits to a value.
 */
static short int htoi(/* unsigned */ char *s){
	short int	value;
	char	c;

	c = s[0];
	if (isupper(c))
		c = tolower(c);
	value = (c >= '0' && c <= '9' ? c - '0' : c - 'a' + 10) * 16;

	c = s[1];
	if (isupper(c))
		c = tolower(c);
	value += c >= '0' && c <= '9' ? c - '0' : c - 'a' + 10;

	return (value);
}

/*---------------------------------------------------------------------*/
/*
 * Get rid of all the URL escaping in a string.  Modify it in place, since
 * the result will always be equal in length or smaller.
 */
static void url_unescape(/* unsigned */ char *str){
	/* unsigned */ char *dest = str;

	while (str[0])
	{
		if (str[0] == '+')
			dest[0] = ' ';
		else if (str[0] == '%' && ishex(str[1]) && ishex(str[2]))
		{
			dest[0] = (/* unsigned */ char) htoi(str + 1);
			str += 2;
		}
		else
			dest[0] = str[0];

		str++;
		dest++;
	}

	dest[0] = '\0';
}

/*---------------------------------------------------------------------*/
/*
 * Stuff a URL-unescaped variable, with the prefix on its name, into the
 * environment.  Uses the "=" from the CGI arguments.  Putting an "=" in
 * a field name is probably a bad idea.
 *
 * If the variable is already defined, append a '#' to it along with the
 * new value.
 *
 * If the variable name begins with an underline, strip whitespace from the
 * start and end and normalize end-of-line characters.
 */
static void stuffenv(char *var){
	char *buf, *c, *s, *t, *oldval, *newval;
	short int	despace = 0, got_cr = 0;

#ifdef DEBUG
	Log("Before unescape: %s\n", var);
#endif

	url_unescape(var);

#ifdef DEBUG
	Log("After unescape: %s\n", var);
#endif

	/* 2006-08-01: pridanÈ */
	if(strlen(_global_buf2) > 0)
		strcat(_global_buf2, "&");
	strcat(_global_buf2, var);
#ifdef DEBUG
	Log("Nabaæujem _global_buf2 == %s\n", _global_buf2);
#endif

	/*
	 * Allocate enough memory for the variable name and its value.
	 */
	buf = (char *)malloc(strlen(var) + sizeof(WWW_PREFIX) + 2);
	if (buf == NULL){
		Log("  Not enough memory to allocate buffer for `buf'\n");
		return;
	}
	strcpy(buf, WWW_PREFIX);
	if (var[0] == '_')
	{
		strcpy(buf + sizeof(WWW_PREFIX) - 1, var + 1);
		despace = 1;
	}
	else
		strcpy(buf + sizeof(WWW_PREFIX) - 1, var);

	/*
	 * If, for some reason, there wasn't an = in the query string,
	 * add one so the environment will be valid.
	 *
	 * Also, change periods to underscores so folks can get at "image"
	 * input fields from the shell, which has trouble with periods
	 * in variable names.
	 */
	for (c = buf; *c != '\0'; c++)
	{
		if (*c == '.')
			*c = '_';
		if (*c == '=')
			break;
	}
	if (*c == '\0')
		c[1] = '\0';
	*c = '\0';

	/*
	 * Do whitespace stripping, if applicable.  Since this can only ever
	 * shorten the value, it's safe to do in place.
	 */
	if (despace && c[1])
	{
#ifdef DEBUG
		Log("  Stripping whitespace.\n");
#endif
		for (s = c + 1; *s && isspace(*s); s++)
			;
		t = c + 1;
		while (*s)
		{
			if (*s == '\r')
			{
				got_cr = 1;
				s++;
				continue;
			}
			if (got_cr)
			{
				if (*s != '\n')
					*t++ = '\n';
				got_cr = 0;
			}
			*t++ = *s++;
		}

		/* Strip trailing whitespace if we copied anything. */
		while (t > c && isspace(*--t))
			;
		t[1] = '\0';
	}

	/*
	 * Check for the presence of the variable.
	 */
	if ((oldval = getenv(buf)))
	{
#ifdef DEBUG
		Log("  Variable %s exists with value %s\n", buf, oldval);
#endif
		newval = (char *)malloc(strlen(oldval) + strlen(buf) + strlen(c+1) + 3);
		if (newval == NULL){
			Log("  Not enough memory to allocate buffer for `buf'\n");
			return;
		}
		*c = '=';
		sprintf(newval, "%s#%s", buf, oldval);
		*c = '\0';

		/*
		 * Set up to free the entire old environment variable -- there
		 * really ought to be a library function for this.  It's safe
		 * to free it since the only place these variables come from
		 * is a previous call to this function; we can never be
		 * freeing a system-supplied environment variable.
		 */
		oldval -= strlen(buf) + 1; /* skip past VAR= */
	}
	else
	{
#ifdef DEBUG
		Log("  Variable %s doesn't exist yet.\n", buf);
#endif
		*c = '=';
		newval = buf;
	}

#ifdef DEBUG
	Log("  putenv %s\n", newval);
#endif
	putenv(newval);
	
	if (oldval)
	{
		/*
		 * Do the actual freeing of the old value after it's not
		 * being referred to any more.
		 */
		free(oldval);
		free(buf);
	}
}

/*---------------------------------------------------------------------*/
/*
 * Scan a query string, stuffing variables into the environment.  This
 * should ideally just use strtok(), but that's not available everywhere.
 */
static void scanquery(char *q){
	char	*next = q;

	Log("uncgi::scanquery() -- zaËiatok\n");
	do {
		next = strchr(next, '&');
		if (next)
			*next = '\0';

		stuffenv(q);
		if (next)
			*next++ = '&';
		q = next;
		Log("uncgi::scanquery(): \n\tq == %s\n\t_global_buf == %s\n", q, _global_buf);
	} while (q != NULL);
	Log("uncgi::scanquery() -- koniec\n");
}

/*---------------------------------------------------------------------*/
/* popis: naplni premenne WWW_... hodnotami z QS, t.j. akoby to vratilo uncgi.c
 * vracia: on success, returns SUCCESS
 *         on error,   returns FAILURE
 */
short int setForm(void){
	char local_str[MAX_STR] = STR_EMPTY;
	short int ret;

	Log("setForm() -- begin\n");

	/* 2005-03-29 (Bratislava): Pokus (pada tabulka) - vlozime aj */
	/* 2005-08-15: S hrÙzou som zistil, ûe pri simul·cii z qs je pom_QUERY_TYPE = psqs 
	 *             preto upravujem, aby bola hodnota parametra param[x].name == qt
	 *             resp. berieme z query_type
	 */
	mystrcpy(local_str, STR_EMPTY, MAX_STR);
	if(!equals(pom_QUERY_TYPE, STR_EMPTY)){
		mystrcpy(local_str, ADD_WWW_PREFIX_(STR_QUERY_TYPE), MAX_STR);
		strcat(local_str, "=");
		if(equals(pom_QUERY_TYPE, STR_PRM_SIMULACIA_QS)){
			Log("\tpre simul·ciu priraÔujem hodnotu z query_type (%s)...\n", param[0].val);
			/* 2005-08-15: Ak je simul·cia, nastav hodnotu podæa query_type */
			strcat(local_str, param[0].val);
		}
		else
			strcat(local_str, pom_QUERY_TYPE);
		Log("--- setForm: putenv(%s); ... ", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret); /* 2005-03-30: Pridany vypis */
	}

	/* den */
	mystrcpy(local_str, STR_EMPTY, MAX_STR);
	if(!equals(pom_DEN, STR_EMPTY)){
		mystrcpy(local_str, ADD_WWW_PREFIX_(STR_DEN), MAX_STR);
		strcat(local_str, "=");
		strcat(local_str, pom_DEN);
		Log("--- setForm: putenv(%s); ...\n", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret); /* 2005-03-30: Pridany vypis */
	}
	/* mesiac */
	mystrcpy(local_str, STR_EMPTY, MAX_STR);
	if(!equals(pom_MESIAC, STR_EMPTY)){
		mystrcpy(local_str, ADD_WWW_PREFIX_(STR_MESIAC), MAX_STR);
		strcat(local_str, "=");
		strcat(local_str, pom_MESIAC);
		Log("--- setForm: putenv(%s); ...\n", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret); /* 2005-03-30: Pridany vypis */
	}
	/* rok */
	mystrcpy(local_str, STR_EMPTY, MAX_STR);
	if(!equals(pom_ROK, STR_EMPTY)){
		/* 2005-03-29: Doplnene, lebo pri analyze roka pouzivame parameter "ar" namiesto "r" */
		if(query_type == PRM_ANALYZA_ROKU)
			mystrcpy(local_str, ADD_WWW_PREFIX_(STR_ANALYZA_ROKU), MAX_STR);
		else
			mystrcpy(local_str, ADD_WWW_PREFIX_(STR_ROK), MAX_STR);
		strcat(local_str, "=");
		strcat(local_str, pom_ROK);
		Log("--- setForm: putenv(%s); ...\n", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret); /* 2005-03-30: Pridany vypis */
	}
	/* modlitba */
	mystrcpy(local_str, STR_EMPTY, MAX_STR);
	if(!equals(pom_MODLITBA, STR_EMPTY)){
		mystrcpy(local_str, ADD_WWW_PREFIX_(STR_MODLITBA), MAX_STR);
		strcat(local_str, "=");
		strcat(local_str, pom_MODLITBA);
		Log("--- setForm: putenv(%s); ...\n", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret); /* 2005-03-30: Pridany vypis */
	}
	/* pom_DALSI_SVATY */
	mystrcpy(local_str, STR_EMPTY, MAX_STR);
	if(!equals(pom_DALSI_SVATY, STR_EMPTY)){
		mystrcpy(local_str, ADD_WWW_PREFIX_(STR_DALSI_SVATY), MAX_STR);
		strcat(local_str, "=");
		strcat(local_str, pom_DALSI_SVATY);
		Log("--- setForm: putenv(%s); ...\n", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret); /* 2005-03-30: Pridany vypis */
	}
	/* pom_MODL_OPT1..pom_MODL_OPT5 */
	mystrcpy(local_str, STR_EMPTY, MAX_STR);
	if(!equals(pom_MODL_OPT1, STR_EMPTY)){
		mystrcpy(local_str, ADD_WWW_PREFIX_(STR_MODL_OPT1), MAX_STR);
		strcat(local_str, "=");
		strcat(local_str, pom_MODL_OPT1);
		Log("--- setForm: putenv(%s); ...\n", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret); /* 2005-03-30: Pridany vypis */
	}
	mystrcpy(local_str, STR_EMPTY, MAX_STR);
	if(!equals(pom_MODL_OPT2, STR_EMPTY)){
		mystrcpy(local_str, ADD_WWW_PREFIX_(STR_MODL_OPT2), MAX_STR);
		strcat(local_str, "=");
		strcat(local_str, pom_MODL_OPT2);
		Log("--- setForm: putenv(%s); ...\n", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret); /* 2005-03-30: Pridany vypis */
	}
	mystrcpy(local_str, STR_EMPTY, MAX_STR);
	if(!equals(pom_MODL_OPT3, STR_EMPTY)){
		mystrcpy(local_str, ADD_WWW_PREFIX_(STR_MODL_OPT3), MAX_STR);
		strcat(local_str, "=");
		strcat(local_str, pom_MODL_OPT3);
		Log("--- setForm: putenv(%s); ...\n", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret); /* 2005-03-30: Pridany vypis */
	}
	mystrcpy(local_str, STR_EMPTY, MAX_STR);
	if(!equals(pom_MODL_OPT4, STR_EMPTY)){
		mystrcpy(local_str, ADD_WWW_PREFIX_(STR_MODL_OPT4), MAX_STR);
		strcat(local_str, "=");
		strcat(local_str, pom_MODL_OPT4);
		Log("--- setForm: putenv(%s); ...\n", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret); /* 2005-03-30: Pridany vypis */
	}
	mystrcpy(local_str, STR_EMPTY, MAX_STR);
	if(!equals(pom_MODL_OPT5, STR_EMPTY)){
		mystrcpy(local_str, ADD_WWW_PREFIX_(STR_MODL_OPT5), MAX_STR);
		strcat(local_str, "=");
		strcat(local_str, pom_MODL_OPT5);
		Log("--- setForm: putenv(%s); ...\n", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret); /* 2005-03-30: Pridany vypis */
	}

	/* 2006-07-11: PridanÈ kvÙli jazykov˝m mut·ci·m */
	mystrcpy(local_str, STR_EMPTY, MAX_STR);
	if(!equals(pom_JAZYK, STR_EMPTY)){
		mystrcpy(local_str, ADD_WWW_PREFIX_(STR_JAZYK), MAX_STR);
		strcat(local_str, "=");
		strcat(local_str, pom_JAZYK);
		Log("--- setForm: putenv(%s); ...\n", local_str);
		ret = putenv(local_str);
		Log("--- setForm: putenv returned %d.\n", ret);
	}

	Log("setForm() -- end, returning SUCCESS\n");
	return SUCCESS;
}/* setForm(); */

/*---------------------------------------------------------------------*/
/* popis: zisti, odkial sa citaju argumenty (vstupy);
 * vracia:
 *
 * 	SCRIPT_PARAM_FROM_FORM (z formulara, t.j. syst. premennych WWW_...)
 * 	SCRIPT_PARAM_FROM_ARGV (z argumentov dialogoveho riadka)
 * 	SCRIPT_PARAM_FROM_QS   (zo systemovej premennej QUERY_STRING)
 */
short int getSrciptParamFrom(int argc){

	/* najprv zistime, ci existuje systemova premenna QUERY_STRING */
	char *qs;
	char *method;
	short int ret;
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
	Log("--- getSrciptParamFrom(): begin\n");
	qs = getenv("QUERY_STRING");
	if(qs != NULL) /* znamen· to, ûe existuje query string - Ëi uû klasick˝ GET, alebo Ëasù poslan· POST linkou; 2006-08-01 */
		mystrcpy(query_string, qs, MAX_QUERY_STR);
	else
		mystrcpy(query_string, STR_EMPTY, MAX_QUERY_STR);

	if(query_string != NULL)
		Log("query_string == %s\n", query_string);
	else
		Log("query_string is NULL\n");
	
	/* 2005-03-28: Pridane zistenie, odkial sa cita */
	method = getenv("REQUEST_METHOD");
	if(method != NULL)
		Log("method == %s\n", method);
	else
		Log("method is NULL\n");
	if (method != NULL && ! strcmp(method, "POST")){
		ret = postread();
		if(ret == SUCCESS){
			Log("OK. Pokracujem skenovanim query...\n");
			if ((_global_buf != NULL) && (_global_buf[0] != '\0')){
				scanquery(_global_buf);
				/* 2006-08-01: _global_buf sa menÌ, my si budujeme kÛpiu v _global_buf2 */
				Log("POST::Vysledok == %s\n", _global_buf2);
				// _main_LOG_to_Export("spustam setForm(); hodnota pom_QUERY_TYPE == %s\n", pom_QUERY_TYPE);
				// ret = setForm(); /* 2005-03-29: Pokus */
				// _main_LOG_to_Export("spat po skonceni setForm()\n");
				/* 2006-08-01: Neviem, Ëi vyööie uveden˝ pokus tak celkom vyöiel;
				 * v prÌpade, ak je query string nepr·zdny (napr. obsahuje öpecifik·ciu jazyka),
				 * ale ostatnÈ premennÈ sa ËÌtaj˙ z formul·ra (vr·tane query type),
				 * tak to nefunguje, preto op‰ù in˝ pokus: prilepÌme ku query stringu aj cel˝ global buffer */
				if(query_string != NULL && !equals(query_string, STR_EMPTY)){
					Log("2006-08-01: Experiment - prilepujem _global_buf2 na koniec query_stringu...\n");
					strcat(query_string, "&");
					strcat(query_string, _global_buf2);
				}
			}
		}
		else
			Log("Chyba.\n");
	}

	Log("--- getSrciptParamFrom(): end...\n");
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

/* 2003-07-16; zrusene nasledovne definy:
#define _export_heading1(a)	_export_heading(1, a)
#define _export_heading2(a)	_export_heading(2, a)
#define _export_heading3(a)	_export_heading(3, a)
*/

/*---------------------------------------------------------------------*/
/*
 * _export_heading();
 *
 * exportuje heading velkosti size;
 * 2003-06-17; jednotne exportovanie. <h2> pre Liturgiu hodin, <h3> pre detailnejsi vypis
 */
void _export_heading(/* int size, */const char *string){
	short int size = 2;
	/* 2003-07-16; pridany default vypis */
	Export("\n<center><h%d>Kontrola ˙dajov</h%d></center>\n\n", size, size);
	/* 2003-07-16; pre prehladnost pridany este jeden \n */
	size = 4;
	Export("\n<h%d class=\"blue\">%s</h%d>\n\n", size, string, size);
}
/* 2003-07-16; podobna funkcnost ako puovodne _export_heading */
void _export_heading_center(const char *string){
	short int size = 2;
	/* 2003-07-16; pridany default vypis */
	Export("\n<center><h%d>%s</h%d></center>\n\n", size, string, size);
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
/* nasleduje pasaz, ktora bola povodne v lithod.[h|cpp]                */

/*---------------------------------------------------------------------*/
/* includeFile():
 *
 * podla parametra paramname (PARAM_...)
 * 
 * 2006-01-28: upraven˝ spÙsob v˝pisu kvÙli zjednoduöenej diagnostike
 * 
 */
#define DetailLog emptyLog
void includeFile(short int type, char *paramname, char *fname, char *modlparam){
	short int c, buff_index = 0; /* 01/03/2000A.D. - inicializacia buff_index */
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
#if defined(EXPORT_HTML_FILENAME_ANCHOR)
		Export("file `%s' not found (anchor `%s')", fname, modlparam);
#elif defined(EXPORT_HTML_FILENAME)
		Export("file `%s' not found", fname);
#else
		Export("file not found");
#endif
		Log("--includeFile(): end (because of no body)\n");
		return;
	}
	/* 2006-01-28: pridanÈ kvÙli æahöej diagnostike */
#if defined(EXPORT_HTML_FILENAME_ANCHOR)
	Export("(file `%s', anchor `%s')", fname, modlparam);
#elif defined(EXPORT_HTML_FILENAME)
	Export("(file `%s')", fname);
#elif defined(EXPORT_HTML_ANCHOR)
	Export("(anchor `%s')", modlparam);
#endif
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
#if defined(EXPORT_HTML_FILENAME_ANCHOR)
						Export("begin of `%s', anchor `%s'", fname, modlparam);
#elif defined(EXPORT_HTML_ANCHOR)
						Export("BEGIN:%s", modlparam);
#endif
						Log("  begin of `%s' in `%s'\n", modlparam, fname);
					}
					else if(equals(strbuff, INCLUDE_END)){
						write = 0;
						vnutri_inkludovaneho = 0;
#if defined(EXPORT_HTML_FILENAME_ANCHOR)
						Export("end of `%s', anchor `%s'", fname, modlparam);
#elif defined(EXPORT_HTML_ANCHOR)
						Export("END:%s", modlparam);
#endif
						/* pridane 2003-08-13 kvoli viacnasobnym inkludom */
						Export("--><!--");
						/* ak to aj je posledny inklude, potom v nadradenom subore,
						 * do ktoreho "inkludujeme", sa vypise "-->"
						 */
						Log("  end of `%s' in `%s'\n", modlparam, fname);
					}
				}/* equalsi(rest, modlparam) */
				else{
					/* !equalsi(rest, modlparam) */
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
				}/* !equalsi(rest, modlparam) */
				continue;
		}
		if(!isbuff){
			if(write){
				Export("%c", c); /* fputc(c, exportfile); */
				DetailLog("%c", c);
			}
			else ; //skip
		}
		else strbuff[buff_index++] = (char)c;
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
 * 2003-08-21a.D.: postupne pridavam case aj pre posvatne citania
 * 2003-11-20a.D.: pridane citanie1 a citanie2 pre posvatne citania
 * 2005-08-15a.D.: Pridan˝ ÔalöÌ #define: Ëi je 34. t˝ûdeÚ obdobia cez rok
 */
#define je_post ((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN) || ((_global_den.litobd == OBD_VELKONOCNE_TROJDNIE) && ((_global_den.denvt == DEN_PIATOK) || (_global_den.denvt == DEN_SOBOTA))))
#define je_velka_noc ((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II) || ((_global_den.litobd == OBD_VELKONOCNE_TROJDNIE) && (_global_den.denvt == DEN_NEDELA)))
#define je_aleluja_aleluja ((_global_den.litobd == OBD_VELKONOCNA_OKTAVA) || ((_global_den.litobd == OBD_VELKONOCNE_TROJDNIE) && (_global_den.denvt == DEN_NEDELA)) || (equals(_global_den.meno, _global_r._ZOSLANIE_DUCHA_SV.meno) && (_global_modlitba == MODL_VESPERY)))
/* 2005-08-15: Pridan˝ ÔalöÌ #define: Ëi je 34. t˝ûdeÚ obdobia cez rok */
#define je_34_ocr ((_global_den.litobd == OBD_CEZ_ROK) && (_global_den.tyzden == 34) && (_global_den.denvt != DEN_NEDELA))
/* 2005-11-11: "V nedeæu a na sl·vnosti a sviatky po druhom ËÌtanÌ 
 *	a responzÛriu nasleduje hymnus Te Deum" 
 *	2005-11-20: OpravenÈ, lebo sme kontrolovali den, a nie denvt :)
 */
#define je_tedeum (type == MODL_POSV_CITANIE) && ((_global_den.denvt == DEN_NEDELA) || (_global_den.typslav == SLAV_SLAVNOST) || (_global_den.typslav == SLAV_SVIATOK))
void interpretParameter(short int type, char *paramname){
	char path[MAX_STR] = STR_EMPTY;
	mystrcpy(path, include_dir, MAX_STR);
	/* 2004-03-17 // strcat(path, FILE_PATH); // prerobene 05/06/2000A.D. */

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
	/* 2005-08-15: PridanÈ parsovanie PARAM_HYMNUS_34_OCR_INY_BEGIN/END */
	else if(equals(paramname, PARAM_HYMNUS_34_OCR_INY_BEGIN)){
		if(je_34_ocr){
			Log("JE 34.t˝ûdeÚ OCR... BEGIN\n");
			Export("je 34. tyzden OCR-->");
		}
		else
			Log("NIE JE 34.t˝ûdeÚ OCR... BEGIN\n");
	}
	else if(equals(paramname, PARAM_HYMNUS_34_OCR_INY_END)){
		if(je_34_ocr){
			Log("JE 34.t˝ûdeÚ OCR... END\n");
			Export("<!--je 34. tyzden OCR");
		}
		else
			Log("NIE JE 34.t˝ûdeÚ OCR... END\n");
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
			/* nezobrazovat Benediktus/Magnifikat/Te Deum */
			_global_skip_in_prayer = ANO;
			Export("nezobrazit Benediktus/Magnifikat/Te Deum");
			Log("  `Benediktus/Magnifikat/Te Deum' skipping...\n");
		}
		else{
			Export("zobrazit Benediktus/Magnifikat/Te Deum");
			Log("  `Benediktus/Magnifikat/Te Deum': begin...\n");
		}
	}
	else if(equals(paramname, PARAM_CHVALOSPEV_END)){
		if(_global_opt1 == NIE){
			/* nezobrazovat Benediktus/Magnifikat/Te Deum */
			_global_skip_in_prayer = NIE;
			Log("  `Benediktus/Magnifikat/Te Deum' skipped.\n");
		}
		else{
			Export("zobrazit Benediktus/Magnifikat/Te Deum");
			Log("  `Benediktus/Magnifikat/Te Deum' copied.\n");
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
				/* 2005-07-22: Pridan˝ popis aj pre posv‰tnÈ ËÌtanie a modlitbu cez deÚ */
				case MODL_POSV_CITANIE:
					strcat(path, _global_modl_posv_citanie.popis.file);
					includeFile(type, paramname, path, _global_modl_posv_citanie.popis.anchor);
					break;
				case MODL_CEZ_DEN_9:
					strcat(path, _global_modl_cez_den_9.popis.file);
					includeFile(type, paramname, path, _global_modl_cez_den_9.popis.anchor);
					break;
				case MODL_CEZ_DEN_12:
					strcat(path, _global_modl_cez_den_12.popis.file);
					includeFile(type, paramname, path, _global_modl_cez_den_12.popis.anchor);
					break;
				case MODL_CEZ_DEN_3:
					strcat(path, _global_modl_cez_den_3.popis.file);
					includeFile(type, paramname, path, _global_modl_cez_den_3.popis.anchor);
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
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.hymnus.file);
				includeFile(type, paramname, path, _global_modl_vespery.hymnus.anchor);
				break;
			case MODL_POSV_CITANIE:
				strcat(path, _global_modl_posv_citanie.hymnus.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.hymnus.anchor);
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
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.antifona1.file);
				includeFile(type, paramname, path, _global_modl_vespery.antifona1.anchor);
				break;
			case MODL_KOMPLETORIUM:
				strcat(path, _global_modl_kompletorium.antifona1.file);
				includeFile(type, paramname, path, _global_modl_kompletorium.antifona1.anchor);
				break;
			case MODL_POSV_CITANIE:
				strcat(path, _global_modl_posv_citanie.antifona1.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.antifona1.anchor);
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
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.antifona2.file);
				includeFile(type, paramname, path, _global_modl_vespery.antifona2.anchor);
				break;
			case MODL_POSV_CITANIE:
				strcat(path, _global_modl_posv_citanie.antifona2.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.antifona2.anchor);
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
/*			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.antifona3.file);
				includeFile(type, paramname, path, _global_modl_vespery.antifona3.anchor);
				break;
*/
			case MODL_POSV_CITANIE:
				strcat(path, _global_modl_posv_citanie.antifona3.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.antifona3.anchor);
				break;
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
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.zalm1.file);
				includeFile(type, paramname, path, _global_modl_vespery.zalm1.anchor);
				break;
			case MODL_KOMPLETORIUM:
				strcat(path, _global_modl_kompletorium.zalm1.file);
				includeFile(type, paramname, path, _global_modl_kompletorium.zalm1.anchor);
				break;
			case MODL_POSV_CITANIE:
				strcat(path, _global_modl_posv_citanie.zalm1.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.zalm1.anchor);
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
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.zalm2.file);
				includeFile(type, paramname, path, _global_modl_vespery.zalm2.anchor);
				break;
			case MODL_POSV_CITANIE:
				strcat(path, _global_modl_posv_citanie.zalm2.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.zalm2.anchor);
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
/*			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.zalm3.file);
				includeFile(type, paramname, path, _global_modl_vespery.zalm3.anchor);
				break;
*/
			case MODL_POSV_CITANIE:
				strcat(path, _global_modl_posv_citanie.zalm3.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.zalm3.anchor);
				break;
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
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.kresponz.file);
				includeFile(type, paramname, path, _global_modl_vespery.kresponz.anchor);
				break;
			case MODL_KOMPLETORIUM:
				strcat(path, _global_modl_kompletorium.kresponz.file);
				includeFile(type, paramname, path, _global_modl_kompletorium.kresponz.anchor);
				break;
			case MODL_POSV_CITANIE:
				/* pridane 2003-11-21 */
				strcat(path, _global_modl_posv_citanie.kresponz.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.kresponz.anchor);
				break;
			default:
				/* tieto modlitby nemaju kresponz */
				break;
		}/* switch */
	}/* PARAM_KRESPONZ */
	else if(equals(paramname, PARAM_CITANIE1)){
		/* pridane 2003-11-20 */
		if(type == MODL_POSV_CITANIE){
			strcat(path, _global_modl_posv_citanie.citanie1.file);
			includeFile(type, paramname, path, _global_modl_posv_citanie.citanie1.anchor);
		}
		else /* ostatne modlitby 1. citanie nemaju */
		;
	}/* PARAM_CITANIE1 */
	else if(equals(paramname, PARAM_CITANIE2)){
		/* pridane 2003-11-20 */
		if(type == MODL_POSV_CITANIE){
			strcat(path, _global_modl_posv_citanie.citanie2.file);
			includeFile(type, paramname, path, _global_modl_posv_citanie.citanie2.anchor);
		}
		else /* ostatne modlitby 2. citanie nemaju */
		;
	}/* PARAM_CITANIE2 */
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
			case MODL_VESPERY:
				strcat(path, _global_modl_vespery.modlitba.file);
				includeFile(type, paramname, path, _global_modl_vespery.modlitba.anchor);
				break;
			case MODL_KOMPLETORIUM:
				strcat(path, _global_modl_kompletorium.modlitba.file);
				includeFile(type, paramname, path, _global_modl_kompletorium.modlitba.anchor);
				break;
			/* pridane 2003-11-20 */
			case MODL_POSV_CITANIE:
				strcat(path, _global_modl_posv_citanie.modlitba.file);
				includeFile(type, paramname, path, _global_modl_posv_citanie.modlitba.anchor);
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
void interpretTemplate(short int type, char *tempfile){
	short int c, buff_index = 0; /* 01/03/2000A.D. - inicializacia */
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
		else strbuff[buff_index++] = (char)c;
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
void showPrayer(short int type){
	char templat[SMALL];
	char path[MAX_STR] = STR_EMPTY;
	mystrcpy(path, include_dir, MAX_STR);
	/* 2004-03-17 // strcat(path, FILE_PATH); // prerobene 05/06/2000A.D. */

	LOG_ciara;
	Log("/* teraz nasleduje zobrazenie modlitby */\n");
	Log("showPrayer(): begin\n");

	/* rozparsovanie parametrov opt1...opt5 -- takmer kompletne
	 * v _main_rozbor_dna, avsak chyba este nastavenie tretieho parametra
	 * (opt3), ak je neurceny -- aby sa tam dal z _global_den.spolcast
	 * (prvy komponent)
	 * 2005-03-22: Uz su premenne az po opt5...
	 */

	/* 2005-11-11: PridanÈ: ak je potrebnÈ vytlaËiù Te Deum, tak zmenÌme atrib˙t */
	if(je_tedeum){
		Log("JE tedeum...\n");
		_global_opt1 = 1;
	}
	else
		Log("NIE JE tedeum...\n");

	Log("showPrayer: jazyk == `%s' (%d)\n", pom_JAZYK, _global_jazyk); /* 2006-07-11: PridanÈ kvÙli jazykov˝m mut·ci·m */
	Log("showPrayer: opt1 == `%s' (%d)\n", pom_MODL_OPT1, _global_opt1);
	Log("showPrayer: opt2 == `%s' (%d)\n", pom_MODL_OPT2, _global_opt2);
	/* toto uz by tu bolo dost neskoro; je to v dbsvaty.cpp::set_spolocna_cast()
	if(_global_opt3 == MODL_SPOL_CAST_NEURCENA){
		_global_opt3 = (_decode_spol_cast(_global_den.spolcast)).a1;
	}
	// 17/02/2000A.D.
	*/
	/* 2006-02-06: upraven˝ v˝pis: ak je mimo rozsah, reùazcov· konötanta  */
	Log("showPrayer: opt3 == `%s' (%d -- %s)\n", 
		pom_MODL_OPT3, _global_opt3, _global_opt3 <= MODL_SPOL_CAST_NEBRAT ? nazov_spolc(_global_opt3) : EMPTY_STR);
	/* vypisanie dalsich options, 2003-08-13 */
	Log("showPrayer: opt4 == `%s' (%d)\n", pom_MODL_OPT4, _global_opt4);
	Log("showPrayer: opt5 == `%s' (%d -- %s)\n", pom_MODL_OPT5, _global_opt5, 
		(_global_opt5 == MODL_CEZ_DEN_ZALMY_ZO_DNA)? STR_MODL_CEZ_DEN_ZALMY_ZO_DNA: STR_MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA);

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
/* koniec pasaze, ktora bola povodne v lithod.[h|cpp]                  */

/*---------------------------------------------------------------------*/
void VYSVETLIVKY(void){ /* 13/03/2000A.D. */
	char fname[MAX_STR] = STR_EMPTY;
	mystrcpy(fname, include_dir, MAX_STR);
	/* 2004-03-17 // strcat(fname, FILE_PATH); // prerobene 05/06/2000A.D. */

	strcat(fname, FILE_VYSVETLIVKY);
	Export("<!--"); /* simulacia toho, ze replacujeme nejaky anchor */
	includeFile(0, ANCHOR_VYSVETLIVKY, fname, ANCHOR_VYSVETLIVKY);
	/* bolo tu Export("--!>"); zmenene 2003-07-08 */
	Export("-->"); /* simulacia toho, ze replacujeme nejaky anchor */
}
void VYSVETLIVKY_TABULKA(void){ /* 15/03/2000A.D. */
	char fname[MAX_STR] = STR_EMPTY;
	mystrcpy(fname, include_dir, MAX_STR);
	/* 2004-03-17 // strcat(fname, FILE_PATH); // prerobene 05/06/2000A.D. */

	strcat(fname, FILE_VYSVETLIVKY_TABULKA);
	Export("<!--"); /* simulacia toho, ze replacujeme nejaky anchor */
	includeFile(0, ANCHOR_VYSVETLIVKY_TABULKA, fname, ANCHOR_VYSVETLIVKY_TABULKA);
	/* bolo tu Export("--!>"); zmenene 2003-07-08 */
	Export("-->"); /* simulacia toho, ze replacujeme nejaky anchor */
}

/*---------------------------------------------------------------------*/
/*
 * kontrola();
 *
 * skontroluje datum, ci je ok zadany,
 * vracia: on success, returns SUCCESS
 *         on error,   returns FAILURE
 */
#define ExportKONTROLA _export_heading("Kontrola dÚa"); Export
short int kontrola(short int den, short int mesiac, short int rok){
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
				rok, nazov_mesiaca(MES_FEB));
		}
		else if(mesiac == 2){
			ExportKONTROLA("Rok %d nie je prestupn˝, takûe %s m· len 28 dnÌ.\n",
				rok, nazov_mesiaca(MES_FEB));
		}
		else{
			ExportKONTROLA("Mesiac %s m· %d dnÌ.\n",
				nazov_mesiaca(mesiac - 1), pocet_dni[mesiac - 1]);
		}
		//ALERT;
		return FAILURE;
	}
	return SUCCESS;
}/* kontrola() */

/* popis: vrati cislo dna (0--6), ak sa den == pondelok...
 *			 inak vrati UNKNOWN_DEN
 */
short int atodenvt(char *den){
	short int i = 0;
	do{
		if(equals(den, nazov_dna(i)) || equals(den, nazov_dna_asci(i))){
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
short int atoden(char *den){
	short int d;
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
short int atomes(char *mesiac){
	/* sprintf(pom_MESIAC, "%d", cislo_mesiaca(pom_MESIAC)); */
	if(equals(mesiac, STR_VSETKY_MESIACE))
		return VSETKY_MESIACE;
	/* mesiac moze byt string "1" -- "12" alebo nazov_mesiaca(0 -- 11) */
	short int i = atoi(mesiac) - 1;
	if((i >= MES_JAN) && (i <= MES_DEC))
		return i;
	i = 0;
	do{
		if(equals(mesiac, nazov_mesiaca(i)) ||
//		if(equals(mesiac, nazov_mesiaca_jazyk[i][_global_jazyk]) ||
			equals(mesiac, nazov_mesiaca_asci(i))){
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

/* 2006-08-01: pozor, koncovky s˙ pre kaûd˝ jazyk odliönÈ */
#define koncovka_dna_asci(denvt) ((nazov_dna((denvt))[strlen(nazov_dna((denvt))) - 1] == 'a')? 'a': 'y')
#define koncovka_dna(denvt) ((nazov_dna((denvt))[strlen(nazov_dna((denvt))) - 1] == 'a')? '·': '˝')
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
/* 2006-08-22: kvÙli ruûovej farbe r˙cha potrebujeme define aj pre 
 * 3. adventn˙ nedeæu a 4. pÙstnu nedeæu */
#define AN3		(PAN + 14) /* tretia adventn· nedeæa - dva t˝ûdne po prvej AN */
#define PN4		(VN - 21)  /* ötvrt· pÙstna nedeæa - tri t˝ûdne pred VN */

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
short int _rozbor_dna(_struct_den_mesiac datum, short int rok, short int poradie_svaty){
	Log("_rozbor_dna(): 3 parametre -- begin\n");
	Log("-- _rozbor_dna(_struct_den_mesiac, int, int): begin ({%d, %d} %d, %d)\n",
		datum.den, datum.mesiac, rok, poradie_svaty);

	if(poradie_svaty == UNKNOWN_PORADIE_SVATEHO){
		Log("spustam pre poradie_svaty == UNKNOWN_PORADIE_SVATEHO\n");
	}
	/* zapoznamkovane 2003-08-13
		_rozbor_dna_LOG("vypisem, co je v analyze roku...\n");
		Log(_global_r); // 01/03/2000A.D. 
	 */

	short int NAR = poradie(25, 12, rok);       /* narodenie pana */
/* slavnosti */
	short int PMB = poradie(1, 1, rok); /* panny marie bohorodicky */
	short int ZJV = poradie(6, 1, rok); /* zjavenie pana */
	short int DEC16 = poradie(16, 12, rok); /* 16. december, prelom v adventnom obdobi */

	/* 2006-02-06: pomocn· premenn· kvÙli eventu·lnemu prednastaveniu _global_opt3 */
	_struct_sc sc;
	sc.a1 = MODL_SPOL_CAST_NEURCENA;
	sc.a2 = MODL_SPOL_CAST_NEURCENA;
	sc.a3 = MODL_SPOL_CAST_NEURCENA;

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
	 * meno    = STR_EMPTY;
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
	_global_den.typslav_lokal = LOKAL_SLAV_NEURCENE; /* pridanÈ 2005-07-27 */
	mystrcpy(_global_den.meno, STR_EMPTY, MENO_SVIATKU); /* neurcene */
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
			_global_den.farba = LIT_FARBA_FIALOVA; /* 2006-08-19: pridanÈ */
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
				/* mystrcpy(_global_den.meno, nazov_dna(_global_den.denvt));
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
						/* 2006-08-22: pre 4. pÙstnu nedeæu je ruûov· farbe r˙cha */
						if(_global_den.denvr == PN4)
							_global_den.farba = LIT_FARBA_RUZOVA; /* 2006-08-22: pridanÈ */
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
					_global_den.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					_global_den.litobd = OBD_POSTNE_II_VELKY_TYZDEN;
					_global_den.smer = 2; /* nedele adventne, postne a velkonocne */
					mystrcpy(_global_den.meno, text_KVETNA_NEDELA[_global_jazyk], MENO_SVIATKU);
				}
				else if(_global_den.denvr <= ZS){
					/* po kvetnej nedeli, vo velkom tyzdni */
					_rozbor_dna_LOG("/* po kvetnej nedeli, vo velkom tyzdni */\n");
					_global_den.litobd = OBD_POSTNE_II_VELKY_TYZDEN;
					_global_den.smer = 2; /* nedele adventne, postne a velkonocne */
					/* vsedne dni velkeho tyzdna od pondelka do stvrtka vratane */
					if(_global_den.denvr == ZS){
						mystrcpy(_global_den.meno, text_ZELENY_STVRTOK[_global_jazyk], MENO_SVIATKU);
					}
				}
				else{
					_global_den.litobd = OBD_VELKONOCNE_TROJDNIE;
					_global_den.smer = 1;
					/* velkonocne trojdnie umucenia a zmrtvychvstania */
					_rozbor_dna_LOG("/* velkonocne trojdnie umucenia a zmrtvychvstania */\n");
					if(_global_den.denvr == VP){
						mystrcpy(_global_den.meno, text_VELKY_PIATOK[_global_jazyk], MENO_SVIATKU);
						_global_den.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					}
					else if(_global_den.denvr == BS){
						mystrcpy(_global_den.meno, text_BIELA_SOBOTA[_global_jazyk], MENO_SVIATKU);
						/* 2006-08-19: farba ost·va nastaven· ako pre cel˝ pÙst - fialov· */
					}
				}
			}/* if(_global_den.denvr <= BS) */
		}/* if(_global_den.denvr >= POS) */
		else if(_global_den.denvr < POS){
			/* od 1.1. po post, teda bud vianocne obdobie alebo obdobie cez rok */
			_rozbor_dna_LOG("/* od 1.1. po post, teda bud vianocne obdobie alebo obdobie cez rok */\n");
			if(_global_den.denvr == PMB){
				/* slavnost panny marie bohorodicky */
				_rozbor_dna_LOG("/* slavnost panny marie bohorodicky */\n");
				_global_den.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
				_global_den.smer = 3;
				_global_den.typslav = SLAV_SLAVNOST;
				_global_den.litobd = OBD_OKTAVA_NARODENIA;
				_global_den.prik = PRIKAZANY_SVIATOK;
				mystrcpy(_global_den.meno, text_JAN_01[_global_jazyk], MENO_SVIATKU);
				/* 2006-02-16: podreùazec (koniec Okt·vy narodenia P·na) podobne ako (2. veækonoËn· nedeæa) rieöen˝ pomocou "typslav_lokal" */
				if(_global_jazyk == JAZYK_CZ){
					_global_den.typslav_lokal = LOKAL_SLAV_KONIEC_OKTAVY_NAR_CZ;
				}
				else {
					_global_den.typslav_lokal = LOKAL_SLAV_KONIEC_OKTAVY_NAR;
				}
				/* 2006-08-14: upravenÈ; bude potrebnÈ pre inÈ jazyky dorobiù konötanty */
			}
			else if(_global_den.denvr == ZJV){
				/* slavnost zjavenia pana */
				_rozbor_dna_LOG("/* slavnost zjavenia pana */\n");
				_global_den.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
				_global_den.smer = 2; /* zjavenie pana */
				_global_den.typslav = SLAV_SLAVNOST;
				_global_den.litobd = OBD_VIANOCNE_II; /* ma vlastne slavenie; zmenil som na vianocne obd. II 14/03/2000A.D. */
				_global_den.prik = PRIKAZANY_SVIATOK;
				mystrcpy(_global_den.meno, text_JAN_06[_global_jazyk], MENO_SVIATKU);
			}
			else if((_global_den.denvt == DEN_NEDELA) &&
					  (_global_den.denvr >= 2) && (_global_den.denvr <= 5)){
				/* druha nedela po narodeni pana medzi 2. a 5. januarom;
				 * v krajinach, kde sa slavnost zjavenia pana slavi 6. januara
				 */
				_rozbor_dna_LOG("/* druha nedela po narodeni pana medzi 2. a 5. januarom; v krajinach, kde sa slavnost zjavenia pana slavi 6. januara */\n");
				_global_den.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
				_global_den.smer = 6; /* nedele vianocneho obdobia a obdobia "cez rok" */
				_global_den.litobd = OBD_VIANOCNE_I;
				mystrcpy(_global_den.meno, "2. nedeæa po NarodenÌ P·na", MENO_SVIATKU);
			}
			else if(_global_den.denvr < KRST){
				/* vianocne obdobie */
				_rozbor_dna_LOG("/* vianocne obdobie */\n");
				_global_den.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
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
				_global_den.farba = LIT_FARBA_ZELENA; /* 2006-08-19: pridanÈ */
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
			_global_den.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
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
						mystrcpy(_global_den.meno, text_NEDELA_VO_VELKONOCNEJ_OKTAVE[_global_jazyk], MENO_SVIATKU);
						/* 2006-02-08: podreùazec (2. veækonoËn· nedeæa) rieöen˝ pomocou "typslav_lokal" */
						if(_global_jazyk == JAZYK_SK)
							_global_den.typslav_lokal = LOKAL_SLAV_DRUHA_VELK_NEDELA;
						else if(_global_jazyk == JAZYK_CZ)
							_global_den.typslav_lokal = LOKAL_SLAV_DRUHA_VELK_NEDELA_CZ;
					}
					else{
						/* veækonoËn· okt·va - 'vöedn˝ deÚ' vo veækonoËnej okt·ve */
						_rozbor_dna_LOG("/* veækonoËn· okt·va - 'vöedn˝ deÚ' vo veækonoËnej okt·ve */\n");
						if(_global_jazyk == JAZYK_SK){
							sprintf(_global_den.meno, text_DEN_VO_VELKONOCNEJ_OKTAVE[_global_jazyk],
								koncovka_dna(_global_den.denvt),
								nazov_dna(_global_den.denvt));
						}
						else if(_global_jazyk == JAZYK_CZ){
							sprintf(_global_den.meno, text_DEN_VO_VELKONOCNEJ_OKTAVE[_global_jazyk],
								nazov_Dna(_global_den.denvt));
						}
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
				_global_den.farba = LIT_FARBA_ZELENA; /* 2006-08-19: pridanÈ */
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
						_global_den.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
						_rozbor_dna_LOG("/* najsv. trojice */\n");
						_global_den.smer = 3; /* slavnosti pana */
						_global_den.typslav = SLAV_SLAVNOST;
						mystrcpy(_global_den.meno, text_NAJSVATEJSEJ_TROJICE[_global_jazyk], MENO_SVIATKU);
					}
					else if(_global_den.tyzden == KRISTA_KRALA){
						/* krista krala */
						_global_den.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
						_rozbor_dna_LOG("/* krista krala */\n");
						_global_den.smer = 3; /* slavnosti pana */
						_global_den.typslav = SLAV_SLAVNOST;
						mystrcpy(_global_den.meno, text_KRISTA_KRALA[_global_jazyk], MENO_SVIATKU);
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
						_global_den.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
						_rozbor_dna_LOG("/* najsv. krist. tela a krvi */\n");
						_global_den.smer = 3; /* slavnosti pana */
						_global_den.typslav = SLAV_SLAVNOST;
						_global_den.prik = PRIKAZANY_SVIATOK;
						mystrcpy(_global_den.meno, text_NAJSV_KRISTOVHO_TELA_A_KRVI[_global_jazyk], MENO_SVIATKU);
					}
					else if(_global_den.denvr == SRDCA){
						/* srdca jezisovho == ZDS + 19 */
						_global_den.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
						_rozbor_dna_LOG("/* srdca jezisovho */\n");
						_global_den.smer = 3; /* slavnosti pana */
						_global_den.typslav = SLAV_SLAVNOST;
						mystrcpy(_global_den.meno, text_NAJSV_SRDCA_JEZISOVHO[_global_jazyk], MENO_SVIATKU);
					}
					else if(_global_den.denvr == SRDPM){
						/* srdca prebl. panny marie == ZDS + 20 */
						_global_den.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
						_rozbor_dna_LOG("/* srdca prebl. panny marie */\n");

						/* 2003-06-30: povodne tu bolo 11: "miestne povinne spomienky podla vseobecneho kalendara",
						 * zmenil som to na 10.
						 * nasleduje nejaka starsia vysvetlujuca poznamka; 
						 * "zrejme pre Slovensko je tato lubovolna spomienka povinna; 
						 *  aby sa nebila s inou spomienkou, dal som tam smer == 11; 10/03/2000A.D." 
						 */
						_global_den.smer = 10;
						_global_den.typslav = SLAV_SPOMIENKA;
						mystrcpy(_global_den.meno, text_NEPOSKVRNENEHO_SRDCA_PM[_global_jazyk], MENO_SVIATKU);
							/* pridane 04/07/2000A.D. */
						_global_den.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
						_global_opt3 = MODL_SPOL_CAST_PANNA_MARIA;
						/* 2003-06-30: porov. pasaz venovanu srdcu pm vo funkcii dbzaltar.cpp::sviatky_svatych(); -- 2 vstupy */
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
					_global_den.farba = LIT_FARBA_FIALOVA; /* 2006-08-19: pridanÈ */
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
					/* 2006-08-22: pre 3. adventn˙ nedeæu je ruûov· farbe r˙cha */
					if(_global_den.denvr == AN3)
						_global_den.farba = LIT_FARBA_RUZOVA; /* 2006-08-22: pridanÈ */
				}/* if(_global_den.denvr < NAR) */
				else if(_global_den.denvr >= NAR){
					/* vianocne obdobie */
					_rozbor_dna_LOG("/* vianocne obdobie */\n");
					_global_den.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					_global_den.litobd = OBD_OKTAVA_NARODENIA; /* pretoze do 31.12. */
					_global_den.tyzden = 1;
					if(_global_den.denvr == NAR){
						/* narodenie pana */
						_rozbor_dna_LOG("/* narodenie pana */\n");
						_global_den.typslav = SLAV_SLAVNOST;
						_global_den.smer = 2; /* narodenie pana */
						_global_den.prik = PRIKAZANY_SVIATOK;
						mystrcpy(_global_den.meno, text_NARODENIE_PANA[_global_jazyk], MENO_SVIATKU);
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

	/* 2003-06-30, odkomentovane kvoli lepsiemu debugovaniu */
	Log("spustam sviatky_svatych(%d, %d);...\n", _global_den.den, _global_den.mesiac);

	_global_pocet_svatych = sviatky_svatych(_global_den.den, _global_den.mesiac);
	_rozbor_dna_LOG("_global_pocet_svatych = %d\n", _global_pocet_svatych);

	/* 2003-06-30 */
	/* 2003-10-07; prve nedelne vespery nemali prosby, chyba bola v dbzaltar.cpp::_SET_SPOLOCNE_VECI_NEDELA */
	Log("(1) _global_modl_prve_vespery:\n"); Log(_global_modl_prve_vespery);

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
			nazov_dna(_global_den.denvt));
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
			 /* 2006-01-20: doplnenÈ, lebo nezobrazovalo tieto æubovoænÈ spomienky */
			 if(_global_svaty1.smer < 12)
				 _global_svaty1.smer = 12;
		}

		/* c. 12 v c. 59 vseob. smernic: "lubovolne spomienky, ktore sa mozu
		 * slavit aj v dnoch uvedenych pod c. 9 [...] tak isto v omsi a oficiu
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
				/* 2006-02-06: pre viacero æubovoæn˝ch spomienok treba byù obozretnejöÌ */
				Log("\tporadie_svaty == %d\n", poradie_svaty);
				Log("menim, lebo `%s' ma prednost...\n", 
					poradie_svaty == 1 ? _global_svaty1.meno :
					(poradie_svaty == 2 ? _global_svaty2.meno : 
					(poradie_svaty == 3 ? _global_svaty3.meno : "spomienka PM v sobotu")));

				mystrcpy(_global_den.meno, _global_svaty1.meno, MENO_SVIATKU);
				_global_den.smer = _global_svaty1.smer;
				_global_den.typslav = _global_svaty1.typslav;
				_global_den.spolcast = _global_svaty1.spolcast; /* pridane 22/02/2000A.D. */
				_global_den.typslav_lokal = _global_svaty1.typslav_lokal; /* pridanÈ 2005-07-27 */
				_global_den.prik = _global_svaty1.prik; /* pridane 23/02/2000A.D. */
				// Log(_global_den); /* kvÙli p·traniu pridanÈ 2006-02-06 */
				/* pridanÈ 2006-02-06; upravujeme premenn˙ _global_opt3 ak nebola nastaven· MODL_SPOL_CAST_NEBRAT
				 * treba nastaviù podæa toho, ktor˝ sv‰t˝ je (mÙûe byù 1--3) 
				 * a z·roveÚ braù do ˙vahy eventu·lne prednastavenie od pouûÌvateæa
				 */
				Log("\tPremenn· _global_opt3 pred ˙pravou == %d (%s)...\n", 
					_global_opt3, 
					_global_opt3 <= MODL_SPOL_CAST_NEBRAT ? nazov_spolc(_global_opt3) : EMPTY_STR);
				if(_global_opt3 != MODL_SPOL_CAST_NEBRAT){
					switch(poradie_svaty){
						case 1:
							sc = _decode_spol_cast(_global_svaty1.spolcast);
							break;
						case 2:
							sc = _decode_spol_cast(_global_svaty2.spolcast);
							break;
						case 3:
							sc = _decode_spol_cast(_global_svaty3.spolcast);
							break;
						case 4:
							sc.a1 = MODL_SPOL_CAST_PANNA_MARIA; /* 2006-02-06: spomienka PM v sobotu */
							break;
					}/* switch */
					Log("\tNastavil som do premennej sc == (%d) %s, (%d) %s, (%d) %s\n",
						sc.a1, nazov_spolc(sc.a1), sc.a2, nazov_spolc(sc.a2), sc.a3, nazov_spolc(sc.a3));
					if(sc.a1 != MODL_SPOL_CAST_NEURCENA){
						if(sc.a2 != MODL_SPOL_CAST_NEURCENA){
							if(sc.a3 != MODL_SPOL_CAST_NEURCENA){
								if((_global_opt3 != sc.a1)
								&& (_global_opt3 != sc.a2)
								&& (_global_opt3 != sc.a3)){
									_global_opt3 = sc.a1; /* iba ak nie je ani podæa jednej z nenullov˝vh, zmenÌm */
								}
							}
							else{
								if((_global_opt3 != sc.a1)
								&& (_global_opt3 != sc.a2)){
									_global_opt3 = sc.a1; /* iba ak nie je ani podæa jednej z nenullov˝vh, zmenÌm */
								}
							}
						}
						else{
							if(_global_opt3 != sc.a1){
								_global_opt3 = sc.a1; /* iba ak nie je ani podæa jednej z nenullov˝vh, zmenÌm */
							}
						}
					}
					else{
						Log("\tHmmm, pre sv‰tca nie je nastaven· spoloËn· Ëasù, nech·vam _global_opt3 tak ako je...\n");
					}
					/* pÙvodne - nespr·vne - som sem dnes, 2006-02-06, dal:
					 * _global_opt3 = 
					 *	poradie_svaty == 1 ? (_decode_spol_cast(_global_svaty1.spolcast)).a1 :
					 *	(poradie_svaty == 2 ? (_decode_spol_cast(_global_svaty2.spolcast)).a1 : 
					 *	(poradie_svaty == 3 ? (_decode_spol_cast(_global_svaty3.spolcast)).a1 : MODL_SPOL_CAST_PANNA_MARIA));
					 */
					Log("\tNastavil som _global_opt3 == %d (%s)...\n", 
						_global_opt3, 
						_global_opt3 <= MODL_SPOL_CAST_NEBRAT ? nazov_spolc(_global_opt3) : EMPTY_STR);
				} /* if(_global_opt3 != MODL_SPOL_CAST_NEBRAT) */
				else{
					Log("\tKeÔûe pouûÌvateæ nechcel braù spoloËn˙ Ëasù, neupravujem.\n");
				}
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

	Log("-- _rozbor_dna(_struct_den_mesiac, int, int): end ({%d, %d}, %d, %d)\n",
		datum.den, datum.mesiac, rok, poradie_svaty);
	/* export -- je inde
	 * _export_rozbor_dna() a v _rozbor_dna_s_modlitbou();
	 */
	Log("_rozbor_dna(): 3 parametre -- returning SUCCESS...\n");
	return SUCCESS;
}/* _rozbor_dna() */

short int _rozbor_dna(_struct_den_mesiac datum, short int rok){
	short int ret;
	Log("_rozbor_dna(): 2 parametre -- begin\n");
	ret = _rozbor_dna(datum, rok, 0);
	Log("_rozbor_dna(): 2 parametre -- returning %d\n", ret);
	return ret;
}
/* 2005-03-21: Pridany dalsi typ exportu */
#define EXPORT_DNA_VIAC_DNI_SIMPLE 3
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
short int init_global_string(short int typ, short int poradie_svateho, short int modlitba){
	/* lokalna premenna, do ktorej sa ukladaju info o analyzovanom dni
	 * pouziva ju void nove_rozbor_dna() funkcia */
	/* 2003-07-07: obavam sa, ze nove_rozbor_dna() je alebo
	 * _rozbor_dna alebo _rozbor_dna_s_modlitbou...
	 * lebo nic take neexistuje 
	 * skoda, ze som neaktualizoval aj komentare. teraz je ten odkaz nezrozumitelny.
	 */

	_struct_dm _local_den;
	_INIT_DM(_local_den); /* 2003-08-07 pridana */

	char pom[MAX_STR];
	mystrcpy(pom, STR_EMPTY, MAX_STR); /* 2003-08-11 pridana inicializacia */
	mystrcpy(_global_string, STR_EMPTY, MAX_GLOBAL_STR); /* inicializacia */
	mystrcpy(_global_string2, STR_EMPTY, MAX_GLOBAL_STR2); /* inicializ·cia, upraven· dÂûka */
	mystrcpy(_global_string_farba, STR_EMPTY, MAX_GLOBAL_STR_FARBA); /* 2006-08-19: pridanÈ - inicializ·cia */

	short int farba = COLOR_BLACK;
	short int velkost = CASE_MALE;
	short int obyc = NIE;
	short int liturgicka_farba = LIT_FARBA_NEURCENA; /* 2006-08-19: pridanÈ */

	Log("-- init_global_string(EXPORT_DNA_%d, %d, %s) -- zaËiatok (inicializuje tri _global_string* premennÈ)\n",
		typ, poradie_svateho, nazov_modlitby(modlitba));
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
	/* 2006-02-02: pridanÈ posv. ËÌtania a upravenÈ; 
	 * keÔûe smer == 11 pouûÌvame pre lok·lne povinnÈ spomienky, 
	 * upravili sme kontrolu z 12 na 11
	 */
	if((_global_den.litobd == OBD_CEZ_ROK) &&
		(_global_den.denvt == DEN_SOBOTA) &&
		(
			((_global_den.smer >= 11) && (_global_pocet_svatych == 0)) ||
			((_global_svaty1.smer >= 11) && (_global_pocet_svatych > 0))) &&
		(poradie_svateho == 4)){
		/* teraz do _global_den priradim dane slavenie */
		_local_den = _global_pm_sobota;
	}

	Log("3:_local_den.meno == %s\n", _local_den.meno); /* 08/03/2000A.D. */
	
	/* skontrolujeme este pondelok -- stvrtok velkeho tyzdna */
	if((_local_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN) && (typ != EXPORT_DNA_VIAC_DNI)){
		if(!((_local_den.denvt == DEN_NEDELA) || ((_local_den.denvt == DEN_STVRTOK)) && (modlitba == MODL_VESPERY))){ /* 08/03/2000A.D. */
			mystrcpy(_local_den.meno, nazov_dna(_local_den.denvt), MENO_SVIATKU);
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
	/* zmenene <b> na <span class="bold">, 2003-07-02 */
	mystrcpy(_global_string, "<"HTML_SPAN_BOLD">", MAX_GLOBAL_STR);

	if(farba == COLOR_RED){
		/* zmenene <font color> na <span>, 2003-07-02 */
		strcat(_global_string, "<"HTML_SPAN_RED">");
	}
	Log("5:_local_den.meno == %s\n", _local_den.meno); /* 08/03/2000A.D. */

	if(equals(_local_den.meno, STR_EMPTY)){
		if(_local_den.denvt == DEN_NEDELA){
			/* nedela bez vlastneho nazvu */
			sprintf(pom, "%d. %s %s",
					_local_den.tyzden,
					nazov_DNA(_local_den.denvt),
					nazov_OBDOBIA_V(_local_den.litobd));

			if(farba == COLOR_RED){
				/* zmenene <font color> na <span>, 2003-07-02 */
				strcat(pom, "</span>");
			}
			
			strcat(pom, "</span>"); /* kvÙli HTML_SPAN_BOLD, 2003-09-06 */

			/* 2006-09-06: pridanÈ prilepenie "t˝ûdÚa ûalt·ra" aj pre nedele */
			if((typ != EXPORT_DNA_VIAC_DNI) && (typ != EXPORT_DNA_VIAC_DNI_SIMPLE)){
					strcat(_global_string, pom); /* 2006-08-03: prilepujeme nadvakr·t */
					sprintf(pom, "<br><"HTML_SPAN_SMALL"> %d", tyzden_zaltara(_local_den.tyzden));
					strcat(pom, html_text_tyzden_zaltara[_global_jazyk]);
					strcat(pom, "</span>");
			}
			strcat(_global_string, pom);
		}
		else{
			/* doplnenÈ z·tvorky, kvÙli span-ovaËk·m na konci */
			if(obyc == ANO){
			/* 2005-03-21: Pridany dalsi typ exportu */
				if((typ != EXPORT_DNA_VIAC_DNI) && (typ != EXPORT_DNA_VIAC_DNI_SIMPLE)){
#ifdef OLD_STYLE_obycajny_den /* 08/03/2000A.D. */
					sprintf(pom, "%s, %s</span>, %d",
						nazov_Dna(_local_den.denvt),
						nazov_obdobia(_local_den.litobd),
						tyzden_zaltara(_local_den.tyzden));
					strcat(pom, html_text_tyzden_zaltara[_global_jazyk]);
#else
					if((_local_den.tyzden == 0) && (_local_den.litobd == OBD_POSTNE_I)){
						/* <font size=-1></font> zmeneny na <span class="small"></span>, 2003-07-14 */
						sprintf(pom, "%s po Popolcovej strede, %s</span><br><span class=\"small\"> %d",
							nazov_Dna(_local_den.denvt),
							nazov_obdobia(_local_den.litobd),
							tyzden_zaltara(_local_den.tyzden));
						strcat(pom, html_text_tyzden_zaltara[_global_jazyk]);
						strcat(pom, "</span>");
					}
					else{
						/* <font size=-1></font> zmeneny na <span class="small"></span>, 2003-07-14 */
						sprintf(pom, "%s, %s</span>, %d",
							nazov_Dna(_local_den.denvt),
							nazov_obdobia(_local_den.litobd),
							_local_den.tyzden);
						strcat(pom, html_text_tyzden[_global_jazyk]);
						strcat(_global_string, pom); /* 2006-08-03: prilepujeme nadvakr·t */
						sprintf(pom, "<br><"HTML_SPAN_SMALL"> %d", tyzden_zaltara(_local_den.tyzden));
						strcat(pom, html_text_tyzden_zaltara[_global_jazyk]);
						strcat(pom, "</span>");
					}
#endif
					strcat(_global_string, pom);
				}
				else 
					if (typ == EXPORT_DNA_VIAC_DNI_SIMPLE){
						/* 2005-03-21: Pridane */
						sprintf(pom, "%s, %s</span>, %d%s",
							nazov_Dna(_local_den.denvt),
							nazov_obdobia(_local_den.litobd),
							_local_den.tyzden,
							html_text_tyzden[_global_jazyk]);
						strcat(_global_string, pom);
					}
				/* inak ostane string prazdny */

				if(farba == COLOR_RED){
					/* zmenene <font color> na <span>, 2003-07-02 */
					strcat(_global_string, "</span>");
				}
				strcat(_global_string, "</span>"); /* zmenene <b> na <span class="bold">, 2003-07-02 */
			}
			else{
				Log("-- Error: _local_den.meno == \"\", avsak obyc != ANO\n");
			}
		}
	}/* if(equals(_local_den.meno, STR_EMPTY)) */
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

		if(farba == COLOR_RED){
			/* zmenene <font color> na <span>, 2003-07-02 */
			strcat(_global_string, "</span>");
		}
		strcat(_global_string, "</span>"); /* zmenene <b> na <span class="bold">, 2003-07-02 */
	}/* _local_den.meno != STR_EMPTY */

	/* 2006-09-06: z tohto miesta presunut· kontrola na Ëerven˙ farbu vyööie - if(farba == COLOR_RED) */

	/* teraz typ slavenia */
	if(_local_den.typslav != SLAV_NEURCENE){
		/* zmenene <font color> na <span>, 2003-07-02 */
		sprintf(pom, ", <"HTML_SPAN_RED">%s</span>",
			nazov_slavenia(_local_den.typslav));
		strcat(_global_string, pom);
	}

	/* teraz lokaliz·cia slavenia, 2005-07-27: pridanÈ */
	if(_local_den.typslav_lokal != LOKAL_SLAV_NEURCENE){
		sprintf(pom, "\n<br> <"HTML_SPAN_RED_SMALL">(%s)</span>\n",
			nazov_slavenia_lokal[_local_den.typslav_lokal]);
		strcat(_global_string, pom);
	}

	Log("  -- _global_string == %s\n", _global_string);

	/* inicializujem _global_string2 */
	if(((_global_r._POPOLCOVA_STREDA.den == _local_den.den) &&
		 (_global_r._POPOLCOVA_STREDA.mesiac == _local_den.mesiac)) ||
		/* popolcova streda */
		((_local_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN) &&
		 (typ == EXPORT_DNA_VIAC_DNI)) ||
		/* pondelok -- streda velkeho tyzdna */
		(_local_den.smer > 8)){
		/* nie slavnosti ani sviatky ani nedele */
		mystrcpy(_global_string2,
			rimskymi_tyzden_zaltara[tyzden_zaltara(_global_den.tyzden)], MAX_GLOBAL_STR2);
	}
	else if(_local_den.denvt == DEN_NEDELA){
		/* 13/03/2000A.D. -- pridane, aby aj nedele mali tyzden zaltara */
		sprintf(_global_string2, "%c, %s", 
			_local_den.litrok, 
			rimskymi_tyzden_zaltara[tyzden_zaltara(_global_den.tyzden)]);
	}
	else{
		mystrcpy(_global_string2, "V", MAX_GLOBAL_STR2);
	}

	Log("  -- _global_string2 == %s\n", _global_string2);

	/* napokon inicializujem _global_string_farba */

	/* 2006-08-19: pridan· liturgick· farba */
	liturgicka_farba = _local_den.farba;

#undef LIT_FARBA_TEXT
#ifdef LIT_FARBA_TEXT
	sprintf(_global_string_farba, 
		"\n<"HTML_SPAN_SMALL">(%s)</span>\n", 
		(char *)nazov_farby(liturgicka_farba));
#else
	sprintf(_global_string_farba,
		"\n<table bgcolor=\"%s\"><tr><td><font color=\"%s\" size=\""HTML_FONT_SIZE_FARBA"\">%s</font></td></tr></table>\n", 
		(char *)html_farba_pozadie[liturgicka_farba], 
		(char *)html_farba_popredie[liturgicka_farba], 
		(char *)nazov_farby(liturgicka_farba));
#endif

	Log("  -- _global_string_farba == %s\n", _global_string_farba);

	Log("-- init_global_string(EXPORT_DNA_%d, %d, %s) -- returning SUCCESS\n",
		typ, poradie_svateho, nazov_modlitby(modlitba));
	return SUCCESS;
}/* init_global_string(); -- 3 vstupy  */

short int init_global_string(short int typ, short int poradie_svateho){
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
short int _rozbor_dna_s_modlitbou(_struct_den_mesiac datum, short int rok, short int modlitba, short int poradie_svateho){
	short int ret;
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
	/* toto sa vypisovalo aj pre "detaily" (tlacidlo na webe), ked je MODL_NEURCENA,
	 * preto som `modlitba >= MODL_VESPERY' upravil na `(modlitba == MODL_VESPERY) || (modlitba == MODL_KOMPLETORIUM)'
	 * aby kontroloval len vespery a kompletorium.
	 * 2003-07-01 */
	else if((poradie_svateho == 4) && (_global_den.denvt == DEN_SOBOTA) && ((modlitba == MODL_VESPERY) || (modlitba == MODL_KOMPLETORIUM))){
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
		poradie_svateho, nazov_modlitby(modlitba));
	ret = init_global_string(EXPORT_DNA_JEDEN_DEN, poradie_svateho, modlitba);

	if(ret == FAILURE){
		Log("init_global_string() returned FAILURE, so returning FAILURE...\n");
		return FAILURE;
	}

	/* urcenie dat k modlitbe */
	Log("spustam liturgicke_obdobie(%s, %d. tyzden, %s, %d. tyzden zaltara; svaty: %d)...\n",
		nazov_obdobia(_global_den.litobd),// nazov_obdobia_
		_global_den.tyzden,
		nazov_dna(_global_den.denvt),
		_global_den.tyzzal,
		poradie_svateho);
	
	Log("PRED:\t%d. %s %d\n",
		_global_den.den,
		nazov_mesiaca(_global_den.mesiac - 1),
		_global_den.rok);

	liturgicke_obdobie(_global_den.litobd, _global_den.tyzden, _global_den.denvt, _global_den.tyzzal, poradie_svateho);

	Log("-- _rozbor_dna_s_modlitbou:\n");
	Log("\t%d. %s %d, %s\n",
		_global_den.den,
		nazov_mesiaca(_global_den.mesiac - 1),
		_global_den.rok,
		_global_string);

	Log("-- _rozbor_dna_s_modlitbou(_struct_den_mesiac, int, int, int): returning SUCCESS\n");
	return SUCCESS;
}/* _rozbor_dna_s_modlitbou() */

/*---------------------------------------------------------------------*/
/* _export_rozbor_dna_buttons(typ, int, int)
 *
 * typ - ako v _export_rozbor_dna()
 *
 * exportuje buttony pre _export_rozbor_dna()
 * int poradie_svateho: ak je 2 alebo 3, znamena to, ze ide o druheho
 * resp. tretieho svateho (ked je viac ako 1 lubovolna spomienka)
 * -- v takom pripade este pridavame premennu STR_DALSI_SVATY
 * s hodnotou 2 resp. 3
 *
 * premenovana na lowercase, 2003-08-13
 */
void _export_rozbor_dna_buttons(short int typ, short int poradie_svateho){
/* 2005-03-21: Pridany dalsi typ exportu */
	Log("--- _export_rozbor_dna_buttons(typ == %d) -- begin\n", typ); /* 2005-03-22: Pridane */
	if((typ != EXPORT_DNA_VIAC_DNI) && (typ != EXPORT_DNA_VIAC_DNI_SIMPLE)){
		Log("--- _export_rozbor_dna_buttons(): idem tlacit buttony...\n");
		char pom[MAX_STR];
		char pom2[MAX_STR]; /* 2006-07-31: pridanÈ */

		mystrcpy(pom, STR_EMPTY, MAX_STR); /* 2003-08-11 pridana inicializacia */
		mystrcpy(pom2, STR_EMPTY, MAX_STR); /* 2006-07-31: pridanÈ */

		/* prerobene 13/04/2000A.D.: tlacitka niekedy linkuju iba subor, 
		 * nie linku: podla _global_linky */
		if(_global_linky == ANO){
			if(poradie_svateho > 0)
				/* 2003-07-16 zmeneny & na HTML_AMPERSAND */
				sprintf(pom, HTML_AMPERSAND"%s=%d", STR_DALSI_SVATY, poradie_svateho);
			else
				mystrcpy(pom, STR_EMPTY, MAX_STR);
		}
		else{/* nezobrazovat linky */
			if((poradie_svateho >= 0) && (poradie_svateho < 5))
				sprintf(pom, "%s%d.htm", FILE_NAME_POKEC, poradie_svateho);
			else
				mystrcpy(pom, FILE_NAME_CHYBA, MAX_STR);
		}

		/* 2006-07-31: pridanÈ odovzdanie parametra pre jazyk */
		if(_global_jazyk != JAZYK_SK){
			sprintf(pom2, HTML_AMPERSAND"%s=%s", STR_JAZYK, skratka_jazyka[_global_jazyk]);
			strcat(pom, pom2);
			Log("\tPrilepil som aj jazyk: `%s' (2006-07-31)\n", pom2);
		}

		/* 2006-08-19: pridan· liturgick· farba - pre buttons je treba v kaûdom riadku */
		Export("</td>\n<td>&nbsp;");
		Export("</td>\n<td>");
		Export("%s", _global_string_farba);
		Export("</td>\n<td>&nbsp;");

		/* 2003-07-15 vycistene poznamky, dorobene modlitby cez den */

		/* oddelenie */
		Export("</td>\n<td>");
		if(_global_linky == ANO){
			/* ranne chvaly -- button */
			Export("<form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%s%s\" method=\"post\">\n",
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
		Export("<"HTML_FORM_INPUT_SUBMIT" value=\"");
		Export((char *)HTML_BUTTON_RANNE_CHVALY);
		Export("\">\n");
		Export("</form>\n");

/* 2003-08-06 dorobene posvatne citanie */

		/* oddelenie */
		Export("</td>\n<td>");
		if(_global_linky == ANO){
			/* modlitba posvatneho citania -- button */
			Export("<form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%s%s\" method=\"post\">\n",
				script_name,
				STR_QUERY_TYPE, STR_PRM_DATUM,
				STR_DEN, _global_den.den,
				STR_MESIAC, _global_den.mesiac,
				STR_ROK, _global_den.rok,
				STR_MODLITBA, STR_MODL_POSV_CITANIE,
				pom);
				/* 2003-08-11 pozor, segfault bol spuosobeny tym, ze
				 * ako %s sa vypisoval int! (chybal prefix STR_...)
				 */
		}
		else{
			Export("<form action=\"%s\">\n", pom);
		}
		Export("<"HTML_FORM_INPUT_SUBMIT" value=\"");
		Export((char *)HTML_BUTTON_POSV_CITANIE);
		Export("\">\n");
		Export("</form>\n");

/* 2003-07-15 dorobene modlitby cez den */

		/* oddelenie */
		Export("</td>\n<td>");
		if(_global_linky == ANO){
			/* modlitba cez den (predpoludnim) -- button */
			Export("<form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%s%s\" method=\"post\">\n",
				script_name,
				STR_QUERY_TYPE, STR_PRM_DATUM,
				STR_DEN, _global_den.den,
				STR_MESIAC, _global_den.mesiac,
				STR_ROK, _global_den.rok,
				STR_MODLITBA, STR_MODL_PREDPOLUDNIM,
				pom);
		}
		else{
			Export("<form action=\"%s\">\n", pom);
		}
		Export("<"HTML_FORM_INPUT_SUBMIT" value=\"");
		Export((char *)HTML_BUTTON_PREDPOLUDNIM);
		Export("\">\n");
		Export("</form>\n");

		/* oddelenie */
		Export("</td>\n<td>");
		if(_global_linky == ANO){
			/* modlitba cez den (napoludnie) -- button */
			Export("<form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%s%s\" method=\"post\">\n",
				script_name,
				STR_QUERY_TYPE, STR_PRM_DATUM,
				STR_DEN, _global_den.den,
				STR_MESIAC, _global_den.mesiac,
				STR_ROK, _global_den.rok,
				STR_MODLITBA, STR_MODL_NAPOLUDNIE,
				pom);
		}
		else{
			Export("<form action=\"%s\">\n", pom);
		}
		Export("<"HTML_FORM_INPUT_SUBMIT" value=\"");
		Export((char *)HTML_BUTTON_NAPOLUDNIE);
		Export("\">\n");
		Export("</form>\n");

		/* oddelenie */
		Export("</td>\n<td>");
		if(_global_linky == ANO){
			/* modlitba cez den (popoludni) -- button */
			Export("<form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%s%s\" method=\"post\">\n",
				script_name,
				STR_QUERY_TYPE, STR_PRM_DATUM,
				STR_DEN, _global_den.den,
				STR_MESIAC, _global_den.mesiac,
				STR_ROK, _global_den.rok,
				STR_MODLITBA, STR_MODL_POPOLUDNI,
				pom);
		}
		else{
			Export("<form action=\"%s\">\n", pom);
		}
		Export("<"HTML_FORM_INPUT_SUBMIT" value=\"");
		Export((char *)HTML_BUTTON_POPOLUDNI);
		Export("\">\n");
		Export("</form>\n");

/* 2003-07-15 pokracuje sa buttonom `Vespery' */

		/* oddelenie */
		Export("</td>\n<td>");

		if(poradie_svateho != 4){
			/* spomienka panny marie v sobotu nema vespery,
			 * spravne odsadene az 2003-07-15
			 */
			if(_global_linky == ANO){
				/* vespery -- button */
				Export("<form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%s%s\" method=\"post\">\n",
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
			Export("<"HTML_FORM_INPUT_SUBMIT" value=\"");
			Export((char *)HTML_BUTTON_VESPERY);
			Export("\">\n");
			Export("</form>\n");
		}/* if(poradie_svateho != 4) */

		/* toto sa tyka buttonu 'Detaily...' */
		Export("</td>\n<td>");
		if(_global_linky == ANO){
			Export("<form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%s%s\" method=\"post\">\n",
				script_name,
				STR_QUERY_TYPE, STR_PRM_DETAILY, /* povodne tu bolo PRM_DATUM */
				STR_DEN, _global_den.den,
				STR_MESIAC, _global_den.mesiac,
				STR_ROK, _global_den.rok,
				STR_MODLITBA, STR_MODL_DETAILY,
				pom);
			Export("<"HTML_FORM_INPUT_SUBMIT" value=\"");
			Export((char *)HTML_BUTTON_DETAILY);
			Export("\">\n"); /* zmenene 2003-08-06 */
			Export("</form>\n");
		}/* ak nie zobrazovat linky na internet, tlacidlo `Detaily...' je zbytocne */

	}/* if(typ) */
	/* inak buttony nedavam */
	else if(typ == EXPORT_DNA_VIAC_DNI){
		/* 2006-08-19: pridan· liturgick· farba - pre buttons je treba v kaûdom riadku */
		Export("<td>&nbsp;</td>\n<td>%s</td>\n", _global_string_farba);
	}
	Log("--- _export_rozbor_dna_buttons(typ == %d) -- end\n", typ); /* 2005-03-22: Pridane */
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
void _export_rozbor_dna_buttons_dni(short int typ){
	Log("--- _export_rozbor_dna_buttons_dni(typ == %d) -- begin\n", typ); /* 2005-03-22: Pridane */
	if((typ != EXPORT_DNA_VIAC_DNI) && (typ != EXPORT_DNA_VIAC_DNI_SIMPLE)){
		Log("--- _export_rozbor_dna_buttons_dni(): idem tlacit buttony...\n");
		_struct_den_mesiac datum;
		short int _local_rok, i;

		char pom2[MAX_STR]; /* 2006-07-31: pridanÈ */
		mystrcpy(pom2, STR_EMPTY, MAX_STR); /* 2006-07-31: pridanÈ */

		/* 2006-07-31: pridanÈ odovzdanie parametra pre jazyk */
		if(_global_jazyk != JAZYK_SK){
			sprintf(pom2, HTML_AMPERSAND"%s=%s", STR_JAZYK, skratka_jazyka[_global_jazyk]);
			Log("\tPrilepil som aj jazyk: `%s' (2006-07-31)\n", pom2);
		}

		Export("\n<table align=\"center\">\n<tr>\n");

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
		Export("<td align=\"right\"><form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d%s\" method=\"post\">\n",
			script_name,
			STR_QUERY_TYPE, STR_PRM_DATUM,
			STR_DEN, datum.den,
			STR_MESIAC, datum.mesiac,
			STR_ROK, _local_rok, 
			pom2);
		/* 2003-07-16; < zmenene na &lt; */
		Export("<"HTML_FORM_INPUT_SUBMIT" value=\"&lt; ");
		Export((char *)html_button_predchadzajuci_[_global_jazyk]);
		Export(" ");
		Export((char *)html_text_den[_global_jazyk]);
		Export(" \">\n");
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
		Export("<td><form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d%s\" method=\"post\">\n",
			script_name,
			STR_QUERY_TYPE, STR_PRM_DATUM,
			STR_DEN, datum.den,
			STR_MESIAC, datum.mesiac,
			STR_ROK, _local_rok,
			pom2);
		/* 2003-07-16; > zmenene na &gt; */
		Export("<"HTML_FORM_INPUT_SUBMIT" value=\"");
		Export((char *)html_button_nasledujuci_[_global_jazyk]);
		Export(" ");
		Export((char *)html_text_den[_global_jazyk]);
		Export(" &gt;\">\n");
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
		Export("<td align=\"right\"><form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d%s\" method=\"post\">\n",
			script_name,
			STR_QUERY_TYPE, STR_PRM_DATUM,
			STR_DEN, datum.den,
			STR_MESIAC, datum.mesiac,
			STR_ROK, _local_rok,
			pom2);
		/* 2003-07-16; << zmenene na &lt;&lt; */
		Export("<"HTML_FORM_INPUT_SUBMIT" value=\"&lt;&lt; ");
		Export((char *)html_button_predchadzajuci_[_global_jazyk]);
		Export(" ");
		Export((char *)html_text_rok[_global_jazyk]);
		Export(" \">\n");
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
		Export("<td align=\"right\"><form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d%s\" method=\"post\">\n",
			script_name,
			STR_QUERY_TYPE, STR_PRM_DATUM,
			STR_DEN, datum.den,
			STR_MESIAC, datum.mesiac,
			STR_ROK, _local_rok,
			pom2);
		/* 2003-07-16; >> zmenene na &gt;&gt; */
		Export("<"HTML_FORM_INPUT_SUBMIT" value=\"");
		Export((char *)html_button_nasledujuci_[_global_jazyk]);
		Export(" ");
		Export((char *)html_text_rok[_global_jazyk]);
		Export("  &gt;&gt;\">\n");
		Export("</form></td>\n");

		Export("</tr>\n");

		Export("</table>\n");

		/* zoznam cisel dni */
		/* <font size=-1></font> zmeneny na <span class="small"></span>, 2003-07-14 */
		Export("<span class=\"small\">\n");

		Vytvor_global_link(VSETKY_DNI, _global_den.mesiac, _global_den.rok, LINK_DEN_MESIAC);
		/* zmenene <b> na <span class="bold">, 2003-07-02 */
		Export("<"HTML_SPAN_BOLD">%s:</span> ", _global_link);
		for(i = 1; i <= pocet_dni[_global_den.mesiac - 1]; i++){
			if(i == _global_den.den){
				/* zmenene farby: <font color> na <span class="blue">; 2003-07-02 */
				if(((i + _global_den.denvt - _global_den.den) MOD 7) == 0)
					/* nedela */
					Export("<"HTML_SPAN_BLUE_BOLD">%d</span> ", i);
				else
					Export("<"HTML_SPAN_BLUE">%d</span> ", i);
			}
			else{
				vytvor_global_link(i, _global_den.mesiac, _global_den.rok, LINK_DEN);
				if(((i + _global_den.denvt - _global_den.den) MOD 7) == 0)
					/* nedela */
					/* zmeneny bold: <b> na <span class="bold">; 2003-07-02 */
					Export("<"HTML_SPAN_BOLD">%s</span> ", _global_link);
				else
					Export("%s ", _global_link);
			}
		}
		Export("<br>\n");

		/* teraz zoznam mesiacov */
		Vytvor_global_link(VSETKY_DNI, VSETKY_MESIACE, _global_den.rok, LINK_DEN_MESIAC);
		/* zmenene <b> na <span class="bold">, 2003-07-02 */
		Export("<"HTML_SPAN_BOLD">%s:</span> ", _global_link);
		for(i = 1; i <= 12; i++){
			if(i == _global_den.mesiac){
				/* zmenene farby: <font color> na <span class="blue">; 2003-07-02 */
				Export("<"HTML_SPAN_BLUE">%s</span> ", nazov_Mesiaca(i - 1));
			}
			else{
				Vytvor_global_link(VSETKY_DNI, i, _global_den.rok, LINK_DEN_MESIAC);
				Export("%s ", _global_link);
			}
		}
		
		/* <font size=-1></font> zmeneny na <span class="small"></span>, 2003-07-14 */
		Export("</span>\n");

	}/* if(typ) */
	/* inak buttony nedavam */
	Log("--- _export_rozbor_dna_buttons_dni(typ == %d) -- end\n", typ); /* 2005-03-22: Pridane */
}/* _export_rozbor_dna_buttons_dni */

/*---------------------------------------------------------------------*/
/* _export_rozbor_dna()
 *
 * exportuje udaje, ktore nacitala _rozbor_dna()
 *
 */
/* 2005-03-21: Pridany dalsi typ exportu - EXPORT_DNA_VIAC_DNI_SIMPLE */
#define NEWLINE if(typ != EXPORT_DNA_VIAC_DNI_SIMPLE) Export("</td>\n</tr>\n\n<tr valign=baseline>\n<td></td>\n<td></td>\n<td>"); else Export("; ")

#define BUTTONS(typ, a);     {init_global_string(typ, a); \
        Export("%s", _global_string); \
        _export_rozbor_dna_buttons(typ, a); }
/* 
 * 2003-08-13 ked som sa snazil zistit priciny segfaultu, 
 * nachvilku som #define nahradil procedurou:
void BUTTONS(short int typ, short int a){
	init_global_string(typ, a);
	Export("%s", _global_string);
	_export_rozbor_dna_buttons(typ, a);
}
*/
void _export_rozbor_dna(short int typ){
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
	short int i;
#define MAX_SMALL 30 
	/* bolo tu MAX_PAT a MAX_DESAT, ale kopiroval som tam HTML_SPAN_, 
	 * ktore su dlhsie, 2003-07-02;
	 * unifikovane na MAX_SMALL, 2003-08-11 */
	char pom1[MAX_SMALL] = STR_EMPTY;
	char ciarka = ' ';     /* 2003-08-11 bolo tu 0 */
	char dvojbodka = ' ';  /* 2003-08-11 bolo tu 0 */
	char pom2[MAX_SMALL] = STR_EMPTY;
	char pom3[MAX_SMALL] = STR_EMPTY;

	/* EXPORT_DNA_VIAC_DNI: predpoklada, ze sme v tabulke, <table> */
	if(typ != EXPORT_DNA_VIAC_DNI){
		Export("<table>\n");
	}
	/* vytvorenie linku */
	if(typ == EXPORT_DNA_VIAC_DNI){
		/* 2005-03-22: Upravene. Da sa dat aj ISO-8601 datum. 
		 * 2006-01-15: Vzhæadom k zmene default hodnoty zmenen· podmienka (pÙvodne: NIE).
		 */
		if(_global_opt2 == ANO)
			i = LINK_ISO_8601;
		else
			i = LINK_DEN;
		/* zmenene <b> na <span class="bold">, 2003-07-02 */
		mystrcpy(pom1, "<"HTML_SPAN_BOLD">", MAX_SMALL);
		mystrcpy(pom2, "</span>", MAX_SMALL);
		mystrcpy(pom3, nazov_Dn(_global_den.denvt), MAX_SMALL);
	}/* typ == EXPORT_DNA_VIAC_DNI */
	else if(typ == EXPORT_DNA_VIAC_DNI_SIMPLE){
		/* 2005-03-22: Upravene. Da sa dat aj ISO-8601 datum. 
		 * 2006-01-15: Vzhæadom k zmene default hodnoty zmenen· podmienka (pÙvodne: NIE).
		 */
		if(_global_opt2 == ANO)
			i = LINK_ISO_8601;
		else
			i = LINK_DEN;
		mystrcpy(pom3, nazov_Dn(_global_den.denvt), MAX_SMALL);
	}/* typ == EXPORT_DNA_VIAC_DNI_SIMPLE */
	else{
		i = LINK_DEN_MESIAC_ROK;
/*		if(_global_den.denvt != DEN_NEDELA){
			mystrcpy(pom3, nazov_dna(_global_den.denvt), MAX_SMALL);
		}*/
		if((_global_den.denvt != DEN_NEDELA)/* &&
			(!equals(_global_den.meno, STR_EMPTY))*/){
			//ciarka = ',';
		}
		dvojbodka = ':';
	}/* typ != EXPORT_DNA_VIAC_DNI */

	vytvor_global_link(_global_den.den, _global_den.mesiac, _global_den.rok, i);
		/* 2006-08-19: okrem premennej _global_string t·to funkcia eöte naplnÌ aj _global_string2 a _global_string_farba */

	/* export vytvorenÈho linku */
	Export("\n<tr valign=baseline>\n");

	/* zmenene <div align> na priamo do <td>, 2003-07-09 kvoli HTML 4.01 */

	/* 2005-03-21: Pridane */
	Log("\n===\npom1 == %s", pom1);
	Log("\n_global_link == %s", _global_link);
	Log("\npom2 == %s\n", pom2);

	/* prvy stlpec: cislo dna */
	Export("<td align=right>%s%s%s%c</td>\n",
		pom1, _global_link, pom2, dvojbodka);

	/* druhy stlpec: nazov dna 
	 * 2005-03-21: Vypisujeme, iba ak typ != EXPORT_DNA_VIAC_DNI_SIMPLE
	 */
	if(typ != EXPORT_DNA_VIAC_DNI_SIMPLE)
		Export("<td align=left>%s%s%s%c</td>\n",
			pom1, pom3, pom2, ciarka);

	/* ÔalöÌ stÂpec: buttons (tlaËidl·), podæa typu v˝pisu */
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
			BUTTONS(typ, 1);
		}
		else{
			BUTTONS(typ, 0);
		}
	}/* if((_global_den.denvt == DEN_NEDELA) || (_global_den.prik == PRIKAZANY_SVIATOK) || (_global_den.smer < 5)) */
	else if(_global_pocet_svatych > 0){
		/* sviatky (spomienky, ls) svatych */
		if((_global_den.smer > _global_svaty1.smer) ||
			(_global_den.smer == 9) && (_global_svaty1.smer == 12)){
		/* svaty */
			BUTTONS(typ, 1);
			if(_global_pocet_svatych > 1){
				NEWLINE;
				BUTTONS(typ, 2);
				if(_global_pocet_svatych > 2){
					NEWLINE;
					BUTTONS(typ, 3);
				}
			}
			/* 2005-08-22: pÙvodne sa tu porovn·valo s 12, ale aj pre 11 (lok·lne sl·venia) 
			 * by mal systÈm pon˙knuù vöedn˝ deÚ - keÔ je to napr. v inej diecÈze */
			if((_global_svaty1.smer >= 11) &&
				(typ != EXPORT_DNA_VIAC_DNI)){
				/* ak je to iba lubovolna spomienka, tak vsedny den */
				NEWLINE;
				BUTTONS(typ, 0);
			}
		}/* svaty ma prednost */
		else{
		/* prednost ma den */
			BUTTONS(typ, 0);
		}
	}/* if(_global_pocet_svatych > 0) */
	else{
		/* obycajne dni, nie sviatok */
		BUTTONS(typ, 0);
	}/* if(equals(_global_den.meno, STR_EMPTY)) */

	/* este spomienka panny marie v sobotu, cl. 15 */
	if((_global_den.litobd == OBD_CEZ_ROK) &&
		(_global_den.denvt == DEN_SOBOTA) &&
		(
			/* 2005-08-22: pÙvodne sa tu porovn·valo s 12, ale aj pre 11 (lok·lne sl·venia) 
			 * by mal systÈm pon˙knuù (v sobotu) spomienku p. m·rie - keÔ je to napr. v inej diecÈze */
			((_global_den.smer >= 11) && (_global_pocet_svatych == 0)) ||
			((_global_svaty1.smer >= 11) && (_global_pocet_svatych > 0))) &&
		(typ != EXPORT_DNA_VIAC_DNI)){
		NEWLINE;
		BUTTONS(typ, 4);
	}

	if(typ == EXPORT_DNA_VIAC_DNI){

		/* ÔalöÌ stÂpec: liturgick· farba, pridanÈ 2006-08-19 -- presunutÈ do buttons, pretoûe treba pre kaûdÈ sl·venie samostatne */
		// Export("<td>&nbsp;</td>\n<td>%s</td>\n", _global_string_farba);

		/* ÔalöÌ stÂpec: rÌmske ËÌslo podæa t˝ûdÚa ûalt·ra, pre nedele aj liturgick˝ rok A, B resp. C */
		Export("</td>\n<td><div align=right>"); /* 2006-08-19: podæa mÚa zbytoËne sa to vypisovalo aj pri obyËajnom exporte 1 dÚa */
		/* vypisanie rimskeho cisla (citanie) */
		Export("%s", _global_string2);
		Export("</div>");
	}

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

/*---------------------------------------------------------------------*/
/* _export_rozbor_dna_batch()
 *
 * exportuje udaje, ktore nacitala _rozbor_dna()
 * zalozene na _export_rozbor_dna(); 2003-07-07
 * ale tento ich exportuje do batch suboru (pre dalsie davkove spracovanie)
 *
 */
/* BATCH_COMMAND vygeneruje do batch suboru prikazy, ktore sa pri dalsom
 * behu spustia;
 * 2003-08-13 pre batch bude treba na miesto TUTOLA dodat modlitby cez den,
 * asi cez nejaku option (ci ranne chvaly a vespery, alebo vsetky modlitby 
 *
 * 2004-03-11 pre batch mod sa nevyexportovali niektore parametre,
 * mailom upozornil Stanislav »˙zy <trobon@inMail.sk> 2004-03-06. Vdaka.
 * pridane do BATCH_COMMAND
 *
 * 2006-01-31: zmenenÈ TUTOLA na 2006-01-31-TUTOLA, pridali sme modlitbu cez deÚ
 * (len napoludnie) a posv‰tnÈ ËÌtanie
 * 
 * 2006-02-06: upravenÈ: negenerovaù veöpery pre æubovoæn˙ spomienku PM (a != 4)
 *
 *
 */
#define BATCH_COMMAND(a)	{ \
	/* napokon to vyprintujeme do batch suboru, 2003-07-07 */\
	/* ak je nastaveny _global_opt_append, tak vsetko do 1 suboru, 2003-07-08 */\
	/* 2003-08-11 -Wall upozornila na too many arguments for format */\
	/* 2004-03-11 pridane niektore dalsie parametre */\
	/* 2004-03-16 pridany vypis do batch_html_file */\
	/* 2006-01-31 pridan˝ z·pis modlitby cez deÚ a posv. ËÌtania */\
	fprintf(batch_html_file, "<li>%d. %s %d: \n", _global_den.den, nazov_mesiaca(_global_den.mesiac - 1), _global_den.rok);\
	if(_global_opt_append == YES){\
		fprintf(batch_file, "%s -1%d -2%d -3%d -4%d -x%d -pmrch\n", batch_command, _global_opt1, _global_opt2, _global_opt3, _global_opt4, a); /* ranne chvaly */\
		fprintf(batch_file, "%s -1%d -2%d -3%d -4%d -x%d -pmna\n", batch_command, _global_opt1, _global_opt2, _global_opt3, _global_opt4, a); /* napoludnie */\
		fprintf(batch_file, "%s -1%d -2%d -3%d -4%d -x%d -pmpc\n", batch_command, _global_opt1, _global_opt2, _global_opt3, _global_opt4, a); /* posv‰tnÈ ËÌtanie */\
		/* 2006-01-31-TUTOLA */\
		if(a != 4){\
			fprintf(batch_file, "%s -1%d -2%d -3%d -4%d -x%d -pmv\n", batch_command, _global_opt1, _global_opt2, _global_opt3, _global_opt4, a); /* vespery */\
		}\
	}else{\
		fprintf(batch_file, "%s%dr.htm -1%d -2%d -3%d -4%d -x%d -pmrch\n", batch_command, a, _global_opt1, _global_opt2, _global_opt3, _global_opt4, a); /* ranne chvaly */\
		fprintf(batch_html_file, "\t<a href=\"%.4d-%.2d-%.2d_%dr.htm\">rannÈ chv·ly</a>, \n", _global_den.rok, _global_den.mesiac, _global_den.den, a);\
		fprintf(batch_file, "%s%dn.htm -1%d -2%d -3%d -4%d -x%d -pmna\n", batch_command, a, _global_opt1, _global_opt2, _global_opt3, _global_opt4, a); /* napoludnie */\
		fprintf(batch_html_file, "\t<a href=\"%.4d-%.2d-%.2d_%dn.htm\">modlitba napoludnie</a>, \n", _global_den.rok, _global_den.mesiac, _global_den.den, a);\
		fprintf(batch_file, "%s%dc.htm -1%d -2%d -3%d -4%d -x%d -pmpc\n", batch_command, a, _global_opt1, _global_opt2, _global_opt3, _global_opt4, a); /* posv‰tnÈ ËÌtanie */\
		fprintf(batch_html_file, "\t<a href=\"%.4d-%.2d-%.2d_%dc.htm\">posv‰tnÈ ËÌtanie</a>, \n", _global_den.rok, _global_den.mesiac, _global_den.den, a);\
		/* 2006-01-31-TUTOLA */\
		if(a != 4){\
			fprintf(batch_file, "%s%dv.htm -1%d -2%d -3%d -4%d -x%d -pmv\n", batch_command, a, _global_opt1, _global_opt2, _global_opt3, _global_opt4, a); /* vespery */\
			fprintf(batch_html_file, "\t<a href=\"%.4d-%.2d-%.2d_%dv.htm\">veöpery</a> \n", _global_den.rok, _global_den.mesiac, _global_den.den, a);\
		}\
	}\
	fprintf(batch_html_file, "</li>\n");\
}
void _export_rozbor_dna_batch(short int typ){
/* poznamky bez uvedenia datumu su prevzate z _export_rozbor_dna; 2003-07-07 */

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
	char batch_command[MAX_STR] = STR_EMPTY;
	/* ak vypisovat do jednotlivych suborov, 2003-07-08 */
	if(_global_opt_append != YES){
		/* pripravime si command line string pre dany datum */
		sprintf(batch_command, "%s -i%s -qpdt -d%d -m%d -r%d -e%.4d-%.2d-%.2d_", 
			name_binary_executable, include_dir, 
			_global_den.den, _global_den.mesiac, _global_den.rok,
			_global_den.rok, _global_den.mesiac, _global_den.den);
	}
	/* v opacnom pripade je furt ten isty fajl, 2003-07-08,
	 * pridame tam aj "-a1" = append */
	else{
		sprintf(batch_command, "%s -i%s -qpdt -d%d -m%d -r%d -a1 -e%s.htm", 
			name_binary_executable, include_dir, 
			_global_den.den, _global_den.mesiac, _global_den.rok,
			_global_string); /* _global_string sa nastavi v _main_batch_mode(); */
	}
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
			BATCH_COMMAND(1);
		}
		else{
			BATCH_COMMAND(0);
		}
	}/* if((_global_den.denvt == DEN_NEDELA) || (_global_den.prik == PRIKAZANY_SVIATOK) || (_global_den.smer < 5)) */
	else if(_global_pocet_svatych > 0){
		/* sviatky (spomienky, ls) svatych */
		if((_global_den.smer > _global_svaty1.smer) ||
			(_global_den.smer == 9) && (_global_svaty1.smer == 12)){
		/* svaty */
			BATCH_COMMAND(1);
			if(_global_pocet_svatych > 1){
				BATCH_COMMAND(2);
				if(_global_pocet_svatych > 2){
					BATCH_COMMAND(3);
				}
			}
			if((_global_svaty1.smer >= 12) &&
				(typ != EXPORT_DNA_VIAC_DNI)){
				/* ak je to iba lubovolna spomienka, tak vsedny den */
				BATCH_COMMAND(0);
			}
		}/* svaty ma prednost */
		else{
		/* prednost ma den */
			BATCH_COMMAND(0);
		}
	}/* if(_global_pocet_svatych > 0) */
	else{
		/* obycajne dni, nie sviatok */
		BATCH_COMMAND(0);
	}/* if(equals(_global_den.meno, STR_EMPTY)) */

	/* este spomienka panny marie v sobotu, cl. 15 */
	/* 2006-02-02: pridanÈ posv. ËÌtania a upravenÈ; 
	 * keÔûe smer == 11 pouûÌvame pre lok·lne povinnÈ spomienky, 
	 * upravili sme kontrolu z 12 na 11
	 */
	if((_global_den.litobd == OBD_CEZ_ROK) &&
		(_global_den.denvt == DEN_SOBOTA) &&
		(
			((_global_den.smer >= 11) && (_global_pocet_svatych == 0)) ||
			((_global_svaty1.smer >= 11) && (_global_pocet_svatych > 0))) &&
		(typ != EXPORT_DNA_VIAC_DNI)){
		BATCH_COMMAND(4);
	}

}/* _export_rozbor_dna_batch() */

/*---------------------------------------------------------------------*/

/* showDetails():
 * vytvorena v Trencine, 29/01/2000A.D. */
/* vyskusat Run -> Arguments...:
 * `-qpdt -r2000 -m1 -d20 -x1 -p* -1nie -2sviatku'
 * 2003-08-13: vo VC++ je to Project->Settings zalozka Debug, Program arguments
 */
/*---------------------------------------------------------------------*/
/*
 * ked stlaci button 'Detaily...' pri konretnej modlitbe,
 * zavola sa z funkcie rozbor_dna_s_modlitbou() toto vypisanie
 * detailov (options) pre konretnu modlitbu
 *
 * vela z jadra je prevzateho z funkcie _main_dnes()
 *
 */
void showDetails(short int den, short int mesiac, short int rok, short int poradie_svaty){

	Log("spustam showDetails(%d, %s, %d, %d)...\n", den,
		nazov_mesiaca(mesiac - 1), rok, poradie_svaty);
	Log("_global_den: \n");
	Log(_global_den);

	char pom2[MAX_STR]; /* 2006-08-01: pridanÈ */
	mystrcpy(pom2, STR_EMPTY, MAX_STR); /* 2006-07-31: pridanÈ */

	/* 2006-08-01: pridanÈ odovzdanie parametra pre jazyk */
	if(_global_jazyk != JAZYK_SK){
		sprintf(pom2, HTML_AMPERSAND"%s=%s", STR_JAZYK, skratka_jazyka[_global_jazyk]);
		Log("\tPrilepil som aj jazyk: `%s' (2006-07-31)\n", pom2);
	}

	Export("<hr>\n");
	Export("<p>");
	Export((char *)html_text_detaily_uvod[_global_jazyk]);
	Export("</p>\n");
	Export("<form action=\"%s?%s=%s&%s=%d&%s=%d&%s=%d&%s=%d%s\" method=\"post\">\n",
		uncgi_name,
		STR_QUERY_TYPE, STR_PRM_DATUM, /* chvilu tu bolo PRM_DETAILY */
		STR_DEN, den,
		STR_MESIAC, mesiac,
		STR_ROK, rok,
		STR_DALSI_SVATY, poradie_svaty,
		pom2);
	/* historicka poznamka: kym nebol program (funkcia main()) upraveny tak,
	 * zeby umoznoval aj `mixovane dotazy' (nieco je v query stringu, nieco
	 * je z formulara -- ako je to vyssie a nizsie teraz --, tak bolo treba
	 * nepopularne trapne vytlacit na obrazovku prenasane udaje, ako svedci
	 * tento -- uz nepouzivany -- kus kodu:
	 *
	Export("<"HTML_FORM_INPUT_RADIO" name=\"%s\" value=\"%s\" checked>",
		STR_QUERY_TYPE, STR_PRM_DATUM);
	Export("%s\n", _global_string);
	Export("<br>\n");
	// pole WWW_DEN
	Export("(<select name=\"%s\">\n", STR_DEN);
	Export("<option selected>%d", den);
	Export("\n</select>.\n");
	// pole WWW_MESIAC
	Export("<select name=\"%s\">\n", STR_MESIAC);
	Export("<option selected>%s", nazov_mesiaca(mesiac - 1));
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

	Export("<li>");
	Export((char *)html_text_modlitba[_global_jazyk]);
	Export(" \n");
	/* pole WWW_MODLITBA */
	Export("<select name=\"%s\">\n", STR_MODLITBA);
	Export("<option selected>%s\n", nazov_modlitby(MODL_RANNE_CHVALY));
	Export("<option>%s\n", nazov_modlitby(MODL_POSV_CITANIE)); /* posv.citanie pridane 2003-08-13 */
	Export("<option>%s\n", nazov_modlitby(MODL_PREDPOLUDNIM));
	Export("<option>%s\n", nazov_modlitby(MODL_NAPOLUDNIE));
	Export("<option>%s\n", nazov_modlitby(MODL_POPOLUDNI)); /* cez den: pridane 2003-08-13 */
	/* spomienka P. Marie v sobotu nema vespery */
	if(poradie_svaty != 4)
		Export("<option>%s\n", nazov_modlitby(MODL_VESPERY));
	Export("</select>\n");
	Export("</li>\n");

	Export("<li>");
	Export((char *)html_text_nemenne_sucasti[_global_jazyk]);
	Export(" \n");
	/* pole WWW_MODL_OPT1 */
	Export("<select name=\"%s\">\n", STR_MODL_OPT1);
	Export("<option>%s\n", STR_ANO);
	Export("<option selected>%s\n", STR_NIE);
	Export("</select>\n");
	Export("<br><span class=\"explain\">");
	Export((char *)html_text_nemenne_sucasti_explain[_global_jazyk]);
	Export("</span>");
	Export("</li>\n");

	if((poradie_svaty > 0) && (poradie_svaty < 4)){

		Export("<li>");
		Export((char *)html_text_popis_svaty[_global_jazyk]);
		Export(" \n");
		/* pole WWW_MODL_OPT4 */
		Export("<select name=\"%s\">\n", STR_MODL_OPT4);
		Export("<option>%s\n", STR_ANO);
		Export("<option selected>%s\n", STR_NIE);
		Export("</select>\n");
		Export("<br><span class=\"explain\">");
		Export((char *)html_text_popis_svaty_explain[_global_jazyk]);
		Export("</span>");
		Export("</li>\n");

		/* tu je treba urobit porovnanie s nejakou premennou, ktora obsahuje
		 * to, ze pre sviatok svateho je viac moznosti, odkial brat veci zo
		 * `spolocnej casti na sviatky svatych'
		 */

		Export("<li>");
		Export((char *)html_text_zalmy_brat_zo[_global_jazyk]);
		Export(" \n");
		/* pole WWW_MODL_OPT2 */
		Export("<select name=\"%s\">\n", STR_MODL_OPT2);
		Export("<option selected>%s\n", STR_MODL_ZALMY_ZO_DNA);
		Export("<option>%s\n", STR_MODL_ZALMY_ZO_SV);
		Export("</select>\n");
		Export((char *)html_text_zalmy_brat_zo_okrem_mcd[_global_jazyk]); /* pridane 2003-08-13; upraven˝ popis 2006-01-25 */
		Export("<br><span class=\"explain\">");
		Export((char *)html_text_zalmy_brat_zo_explain[_global_jazyk]);
		Export("</span>");
		Export("</li>\n");

		/* najprv si rozkodujeme, co je v _global_den.spolcast */
		_struct_sc sc = _decode_spol_cast(_global_den.spolcast);
		/* pole WWW_MODL_OPT3 */
		Export("<li>");
		Export((char *)html_text_spol_casti_vziat_zo[_global_jazyk]);
		Export(" \n");
		Export("<select name=\"%s\">\n", STR_MODL_OPT3);
		if((sc.a1 != MODL_SPOL_CAST_NEURCENA) && (sc.a1 != MODL_SPOL_CAST_NEBRAT)){
			Export("<option selected>%s\n", nazov_spolc(sc.a1));
			if(sc.a2 != MODL_SPOL_CAST_NEURCENA){
				Export("<option>%s\n", nazov_spolc(sc.a2));
				if(sc.a3 != MODL_SPOL_CAST_NEURCENA){
					Export("<option>%s\n", nazov_spolc(sc.a3));
				}
			}
			Export("<option>%s\n", nazov_spolc(MODL_SPOL_CAST_NEBRAT));
		}
		else{
			Export("<option selected>%s\n", nazov_spolc(MODL_SPOL_CAST_NEBRAT));
		}
		Export("</select>\n");
		Export("<br><span class=\"explain\">");
		Export((char *)html_text_spol_casti_vziat_zo_explain[_global_jazyk]);
		Export("</span>");
		Export("</li>\n");
	}/* if(poradie svateho in 1, 2, 3) */

	/* pridane 2003-08-06 */
	Export("<li>");
	Export((char *)html_text_zalmy_pre_mcd[_global_jazyk]);
	Export(" \n");
	/* pole WWW_MODL_OPT5 */
	Export("<select name=\"%s\">\n", STR_MODL_OPT5);
	Export("<option selected>%s\n", STR_MODL_CEZ_DEN_ZALMY_ZO_DNA);
	Export("<option>%s\n", STR_MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA);
	Export("</select>\n");
	Export("<br><span class=\"explain\">");
	Export((char *)html_text_zalmy_pre_mcd_explain[_global_jazyk]);
	Export("</span>");
	Export("</li>\n");

	Export("</ul>\n");

	/* 2003-08-13 pridane vysvetlenie */
	Export("<p>\n");
	Export((char *)html_text_detaily_explain[_global_jazyk]);
	Export("</p>\n");

	Export("<center>\n");
	/* button Vyhladaj (GO!) */
	Export("<"HTML_FORM_INPUT_SUBMIT" value=\"");
	Export((char *)HTML_BUTTON_DET_SHOW);
	Export("\">");

	/* button Vycisti (CLEAR!) */
	Export("&nbsp;&nbsp;&nbsp;\n");
	Export("<"HTML_FORM_INPUT_RESET" value=\"");
	Export((char *)HTML_BUTTON_DET_DEFAULTS);
	Export("\">");

	Export("</center>\n</form>\n");

	Log("showDetails(%d, %s, %d, %d) -- end\n", den,
		nazov_mesiaca(mesiac - 1), rok, poradie_svaty);

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
 * - napokon spusti vytvorenie modlitby
 *
 * POZOR! Narozdiel od rozbor dna, pred samotnym spustenim generovania
 * modlitby je vysledok (co sa presne bude modlit) v premennej _global_den;
 *
 * 2003-06-30: chyba toho, ze pre 2003-06-28, vespery, neboli 1. vespery zo
 * sviatku (slavnosti) sv. Petra a sv. Pavla, bude asi v porovnani
 *
 * 2003-08-13: neviem preco boli hore tri vykricniky ("napokon spusti vytvorenie modlitby")
 */
void rozbor_dna_s_modlitbou(short int den, short int mesiac, short int rok, short int modlitba, short int poradie_svaty){
	short int ret = SUCCESS;

	/* lokalne premenne, v ktorych sa pamata to, co vrati _rozbor_dna() */
	/* lokalna premenna, do ktorej sa ukladaju info o analyzovanom dni
	 * pouziva ju void nove_rozbor_dna() funkcia */
	_struct_dm _local_den;
	_INIT_DM(_local_den); /* 2003-08-07 pridana */

	/* lokalne premenne obsahujuce data modlitbach -- 23/02/2000A.D.
	 * prerobene, aby sa alokovali dynamicky */

/*
 * 2003-08-13: tu bolo kedysi toto (pre #ifdef POKUS_24_02_2000):
	_type_1vespery      _local_modl_prve_vespery;
	_type_1kompletorium _local_modl_prve_kompletorium;
 */
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
		_INIT_TMODLITBA1(_local_modl_prve_vespery); /* pridana 2003-08-13 */
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
		_INIT_TMODLITBA1(_local_modl_vespery); /* pridana 2003-08-13 */
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

	/* lokalna kopia roka; ak treba analyzovat dalsi rok */
	short int _local_rok = -1; /* inicializacia dorobena 01/03/2000A.D. */

	/* lokalna premenna, co obsahuje string vypisany na obsazovku */
	char _local_string[MAX_STR];

	char pom[MAX_STR];

	_global_modlitba = modlitba;

	Log("-- rozbor_dna_s_modlitbou(int, int, int, int, int): begin (%d.%d %d, %d; %d)\n",
		den, mesiac, rok, modlitba, poradie_svaty);
	_struct_den_mesiac datum;

	if((modlitba == MODL_VESPERY) || (modlitba == MODL_KOMPLETORIUM)){
		/* najprv analyzujem nasledujuci den - kvoli prvym vesperam resp. kompletoriu */
		Log("kedze modlitba je vespery alebo kompletorium, robim tuto cast...\n"); /* 2003-08-13 pridane */
		_local_rok = rok;
		/* do premennej datum dame datum nasledujuceho dna, poznamka pridana 2003-08-13 */
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
			datum.den, nazov_mesiaca(datum.mesiac - 1), _local_rok);
		ret = _rozbor_dna_s_modlitbou(datum, _local_rok, modlitba, UNKNOWN_PORADIE_SVATEHO);
		if(ret == FAILURE){
			Log("_rozbor_dna_s_modlitbou() pre nasledujuci den returned FAILURE, so...\n");
			Log("-- rozbor_dna_s_modlitbou(int, int, int, int): uncomplete end\n");
			goto LABEL_s_modlitbou_DEALLOCATE;
		}/* ret == FAILURE */
		Log("analyza nasledujuceho dna (%d. %s %d) skoncila.\n",
			datum.den, nazov_mesiaca(datum.mesiac - 1), rok);
		LOG_ciara;
		/* teraz mam vsetky data v _global_den, _global_modl_... */

		_local_den = _global_den;
		/* neviem, ci tam ma byt _global_modl_[prve_]vespery ... */
		/* 23/02/2000A.D. -- prirobil som aj bez _prve_ */
		_local_modl_prve_vespery = _global_modl_prve_vespery;
		_local_modl_prve_kompletorium = _global_modl_prve_kompletorium;
		_local_modl_vespery = _global_modl_vespery;
		_local_modl_kompletorium = _global_modl_kompletorium;
		/* logy pridane 2003-06-30 */
		Log("_local_modl_vespery obsahuje:\n"); Log(_local_modl_vespery);
		/* pridane 2003-10-07 kvoli debugovaniu, co prve vespery nediel ocr nemali prosby
			Log("_local_modl_prve_vespery obsahuje:\n"); Log(_local_modl_prve_vespery);
		*/
		// Log("_local_modl_prve_kompletorium obsahuje:\n"); Log(_local_modl_prve_kompletorium);
		mystrcpy(_local_string, _global_string, MAX_STR);
	}/* kompletorium alebo vespery */

	/* teraz analyzujem dnesny den */
	Log("teraz analyzujem dnesny (ten vyziadany) den...\n"); /* pridane 2003-08-13 */
	datum.den = den;
	datum.mesiac = mesiac;
	if(_local_rok != rok){
		Log("spustam analyzu roka (rok %d)...\n", rok);
		analyzuj_rok(rok); /* vysledok da do _global_r */
	}
	Log("spustam analyzu tohto dna (%d. %s %d)...\n",
		datum.den, nazov_mesiaca(datum.mesiac - 1), rok);
	ret = _rozbor_dna_s_modlitbou(datum, rok, modlitba, poradie_svaty);
	if(ret == FAILURE){
		Log("_rozbor_dna_s_modlitbou() returned FAILURE, so...\n");
		Log("-- rozbor_dna_s_modlitbou(int, int, int, int): uncomplete end\n");
		goto LABEL_s_modlitbou_DEALLOCATE;
	}/* ret == FAILURE */
	Log("analyza tohto dna (%d. %s %d) skoncila.\n",
		datum.den, nazov_mesiaca(datum.mesiac - 1), rok);
	LOG_ciara;
	/* teraz mam vsetky data v _global_den, _global_modl_... */
	Log("teraz mam vsetky data v _global_den, _global_modl_...\n"); /* pridane 2003-08-13 */
/*
 * 2003-08-13: tu bolo kedysi toto:
 * kontrola 2003-10-07; uz na tomto mieste chybali prosby pre 1. vespery;
   chyba bola v dbzaltar.cpp::_SET_SPOLOCNE_VECI_NEDELA - opravene.
	Log("_local_modl_prve_vespery:\n"); Log(_local_modl_prve_vespery);
	Log("_local_modl_vespery:\n"); Log(_local_modl_vespery);
	Log("(2) _global_modl_prve_vespery:\n"); Log(_global_modl_prve_vespery);
	Log("_global_modl_vespery:\n"); Log(_global_modl_vespery);
 */
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
			_local_den.smer, nazov_dna(_local_den.denvt), nazov_obdobia(_local_den.litobd), _local_den.smer);
		// 2003-06-30
		Log(_local_den);
		Log("_local_modl_prve_vespery obsahuje:\n"); Log(_local_modl_prve_vespery);
		
		Log("tento den (%d.%d): _global_den.smer == %d, _global_den.denvt == %s, _global_den.litobd == %s (%d)\n",
			_global_den.den, _global_den.mesiac,
			_global_den.smer, nazov_dna(_global_den.denvt), nazov_obdobia(_global_den.litobd), _global_den.smer);
		// 2003-06-30
		Log(_global_den);
		Log("(3) _global_modl_prve_vespery obsahuje:\n"); Log(_global_modl_prve_vespery);

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
				/* begin: docasny vypis - 16/02/2000A.D. */
				Log("prve vespery:\n");
				Log(_global_modl_prve_vespery);
				Log("vespery:\n");
				Log(_global_modl_vespery);
				/* end: docasny vypis - 16/02/2000A.D. */

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
	}/* vespery alebo kompletorium, zistovanie priority */

	 /* predosla pasaz, kedy sa kontroluje priorita nasledujuceho dna, preskakujeme
	 * pre ostatne modlitby okrem vespier a kompletoria; poznamka pridana 2003-08-13 
	 */

LABEL_NIE_INE_VESPERY: /* 08/03/2000A.D. */

	LOG_ciara;
	Log("/* vypisanie udajov, podla ktorych vlastne budem generovat modlitbu */\n");
	Log("/* datum bol vypisany uz predtym, preto teraz (pri prvych vesperach) \n");
	Log(" * moze byt iny - o jeden den vacsi */\n");
	Log("_global_string: %s\n", _global_string);
	Log("%s\n", nazov_modlitby(modlitba));
	switch(modlitba){
		/* dalsie case pridane 2003-08-13 */
		case MODL_RANNE_CHVALY:
			Log(_global_modl_ranne_chvaly);
			break;
		case MODL_POSV_CITANIE:
			Log(_global_modl_posv_citanie);
			break;
		case MODL_PREDPOLUDNIM:
			Log(_global_modl_predpol);
			break;
		case MODL_NAPOLUDNIE:
			Log(_global_modl_napol);
			break;
		case MODL_POPOLUDNI:
			Log(_global_modl_popol);
			break;
		case MODL_VESPERY:
			Log(_global_modl_vespery);
			break;
	}
/*	Log("_global_den:\n");	Log(_global_den); */

	_export_heading_center(_global_string);

	if(_global_modlitba == MODL_DETAILY){
		Log("spustam showDetails(%d, %s, %d, %d) z funkcie rozbor_dna_s_modlitbou():\n",
			den, nazov_mesiaca(mesiac - 1), rok, poradie_svaty);
		showDetails(den, mesiac, rok, poradie_svaty);
	}/* _global_modlitba == MODL_DETAILY */
	else{/* _global_modlitba != MODL_DETAILY */
		Log("spustam showPrayer(%s)...\n",
			nazov_Modlitby[_global_modlitba]);
		/* predpokladam, ze aj _global_modlitba je prve/druhe vespery,
		 * v _global_prve_vespery su spravne udaje (podobne kompletorium) */
		showPrayer(modlitba);
	}/* _global_modlitba != MODL_DETAILY, teda pre konkretnu modlitbu */

LABEL_s_modlitbou_DEALLOCATE:
	Log("Deallocating memory...\n");
	Log("_local_modl_prve_vespery_ptr\n"); free(_local_modl_prve_vespery_ptr);
	Log("_local_modl_1kompletorium_ptr\n"); free(_local_modl_1kompletorium_ptr);
	Log("_local_modl_vespery_ptr\n"); free(_local_modl_vespery_ptr);
	Log("_local_modl_kompletorium_ptr\n"); free(_local_modl_kompletorium_ptr);
	Log("...done.\n");
	Log("-- rozbor_dna_s_modlitbou(int, int, int, int): ret == %d\n", ret);
}/* rozbor_dna_s_modlitbou() */

/*---------------------------------------------------------------------*/
/* rozbor_dna(int, int, int)
 *
 * dostane 3 inty,
 * spusti analyzuj_rok();
 * potom spusti _export_rozbor_dna();
 *
 */
void rozbor_dna(short int den, short int mesiac, short int rok){
	short int ret;
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
void rozbor_mesiaca(short int mesiac, short int rok){
	Log("-- _main_rozbor_mesiaca(int, int): begin (%d %d)\n", mesiac, rok);
	_struct_den_mesiac datum;
	datum.mesiac = mesiac;
	analyzuj_rok(rok); /* vysledok da do _global_r */
	Export("\n<br>\n<table>\n");
	for(datum.den = 1; datum.den <= pocet_dni[mesiac - 1]; datum.den++){
		_rozbor_dna(datum, rok);
		/* 2005-03-21: Pridany dalsi typ exportu */
		if(_global_opt1 == NIE){
			Log("-- EXPORT_DNA_VIAC_DNI --");
			_export_rozbor_dna(EXPORT_DNA_VIAC_DNI);
		}
		else{ /* (_global_opt1 == ANO) */
			Log("-- EXPORT_DNA_VIAC_DNI_SIMPLE --");
			_export_rozbor_dna(EXPORT_DNA_VIAC_DNI_SIMPLE);
		}
	}
	Export("\n</table>\n\n");
	Log("-- rozbor_mesiaca(int, int): end\n");
}

/*---------------------------------------------------------------------*/
/*
 * _main_formular();
 *
 * 2006-02-02 (doma pri chrÌpke)
 *
 * vypluje cel˝ formul·r, doln˙ Ëasù, ktor· pÙvodne bola v _main_dnes(),
 * ktor˝ obsahuje:
 * - okienka pre deÚ, mesiac, rok; 
 * - okienko pre (anal˝zu) rok;
 * - okienko pre sviatok,
 * - okienko pre liturgick˝ kalend·r,
 * atÔ. a to kvÙli tomu, aby sa to eventu·lne dalo pouûiù aj pre in˝ deÚ ako "dnes".
 *
 */
void _main_formular(short int den, short int mesiac, short int rok, short int denvt){

	/* 2006-02-02: premennÈ z _main_dnes musÌme naplniù podæa vstupn˝ch hodnÙt */

	struct tm dnes;
	short int month, day;

	dnes.tm_mday = den;
	dnes.tm_mon  = mesiac;
	dnes.tm_year = rok;
	dnes.tm_wday = denvt;

	char pom2[MAX_STR]; /* 2006-08-01: pridanÈ */
	mystrcpy(pom2, STR_EMPTY, MAX_STR); /* 2006-07-31: pridanÈ */

	/* 2006-08-01: pridanÈ odovzdanie parametra pre jazyk */
	if(_global_jazyk != JAZYK_SK){
		sprintf(pom2, "%s=%s", STR_JAZYK, skratka_jazyka[_global_jazyk]);
		Log("\tPrilepil som aj jazyk: `%s' (2006-07-31)\n", pom2);
	}

	/* 2006-02-02: prevzat· Ëasù z _main_dnes */

	/* pokracujem vypisanim formulara */
	/* 2003-07-16; zrusene: Export("<hr>\n"); */
	Export("\n<form action=\"%s?%s\" method=\"post\">\n", uncgi_name, pom2); /* 2006-08-01: pridan˝ jazyk */

	Export((char *)html_text_dalsie_moznosti[_global_jazyk]); /* 2006-08-02: jazykovÈ mut·cie; \n presunut˝ pred <table>; staröia pozn·mka: 2003-07-16; kedysi tu bolo "Chcem zobraziù" */

	/* 2003-07-09, zmenene <center><table> na <table align="center"> */
	Export("\n<table align=\"center\">\n");

/* ------------------------------------------- */
	Export("<tr>\n<td>\n");
	Export("<table>\n<tr><td>\n");
	/* formular pre PRM_DATUM */
	Export("<"HTML_FORM_INPUT_RADIO" name=\"%s\" value=\"%s\" checked>",
		STR_QUERY_TYPE, STR_PRM_DATUM);
	Export("</td><td>\n");

	Export("&nbsp;");
	Export((char *)html_text_modlitby_pre_den[_global_jazyk]); /* 2006-08-02 */
	Export(" &nbsp;\n"); /* 2006-02-02: upravenÈ, pridan˝ "dnes" */
	/* pÙvodne tu bolo: Export("&nbsp;vyööie uveden˝ rozbor dÚa pre &nbsp;&nbsp;\n"); pÙvodn˝ koment·r: 2003-07-16; kedysi tu bolo "d·tum" */

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
			Export("<option selected>%s", nazov_mesiaca(month - 1));
		else
			Export("<option>%s", nazov_mesiaca(month - 1));
	Export("\n</select>&nbsp;\n");

	/* pole WWW_ROK */
	Export("<"HTML_FORM_INPUT_TEXT" name=\"%s\" size=5 value=\"%d\">\n",
		STR_ROK, dnes.tm_year);
	
	/* 2006-02-02: upravenÈ, pridan˝ "dnes" */
	Export("&nbsp; ");
	Export((char *)html_text_alebo_pre[_global_jazyk]); /* 2006-08-02 */
	Export(" ");
	Export("<a href=\"%s?%s=%s"HTML_AMPERSAND"%s\">\n",
		script_name,
		STR_QUERY_TYPE, STR_PRM_DNES, pom2); /* 2006-08-01: pridan˝ jazyk */
	Export((char *)html_text_dnesok[_global_jazyk]); /* 2006-08-02 */
	Export("</a></td>\n");

	Export("</td></tr></table>\n");
	Export("</tr>\n\n"); /* 2003-07-09, podozrivo tam bolo aj </td> */

#ifdef FORMULAR_PRE_PRM_SVIATOK
/* ------------------------------------------- */
	Export("<tr>\n<td>\n");
	Export("<table>\n<tr><td>\n");
	/* formular pre PRM_SVIATOK */
	Export("<"HTML_FORM_INPUT_RADIO" name=\"%s\" value=\"%s\">\n",
		STR_QUERY_TYPE, STR_PRM_SVIATOK);
	Export("</td><td>\n");
	/* !!! sviatky --- */
	Export("</td></tr></table>\n");
	Export("</tr>\n\n"); /* 2003-07-09, podozrivo tam bolo aj </td> */
#endif

/* ------------------------------------------- */
	Export("<tr>\n<td>\n");
	Export("<table>\n<tr><td>\n");
	/* formular pre PRM_ANALYZA_ROKU */
	Export("<"HTML_FORM_INPUT_RADIO" name=\"%s\" value=\"%s\">",
		STR_QUERY_TYPE, STR_PRM_ANALYZA_ROKU);
	Export("</td><td>\n");
	Export("&nbsp;");
	Export((char *)html_text_prik_sviatky_atd[_global_jazyk]); /* 2006-08-02 */
	Export("\n");
	/* pole WWW_ANALYZA_ROKU */
	Export("<"HTML_FORM_INPUT_TEXT" name=\"%s\" size=5 value=\"%d\">\n",
		STR_ANALYZA_ROKU, dnes.tm_year);
	Export("</td></tr></table>\n");
	Export("</tr>\n\n"); /* 2003-07-09, podozrivo tam bolo aj </td> */

/* ------------------------------------------- */
	Export("<tr>\n<td>\n");
	Export("<table>\n<tr><td>\n");
	/* formular pre PRM_MESIAC_ROKA */
	Export("<"HTML_FORM_INPUT_RADIO" name=\"%s\" value=\"%s\">",
		STR_QUERY_TYPE, STR_PRM_MESIAC_ROKA);
	Export("</td><td>\n");
	Export("&nbsp;");
	Export((char *)html_text_lit_kalendar[_global_jazyk]); /* 2006-08-02 */
	Export(" &nbsp;"); /* 2003-07-16; povodne tu bolo "mesiac" */
	/* pole WWW_MESIAC_ROKA */
	Export("<select name=\"%s\">\n", STR_MESIAC_ROKA);
	for(month = 1; month < 13; month++)
		if(month == dnes.tm_mon)
			Export("<option selected>%s", nazov_mesiaca(month - 1));
		else
			Export("<option>%s", nazov_mesiaca(month - 1));
	Export("\n</select>&nbsp;\n");

	Export("");
	Export((char *)html_text_roku[_global_jazyk]); /* 2006-08-02 */
	Export(" \n"); /* 2003-07-16; povodne tu bolo "v roku" */
	/* pole WWW_ROK_ROKA */
	Export("<"HTML_FORM_INPUT_TEXT" name=\"%s\" size=5 value=\"%d\">\n",
		STR_ROK_ROKA, dnes.tm_year);
	Export("</td></tr></table>\n");
	Export("</tr>\n\n"); /* 2003-07-09, podozrivo tam bolo aj </td> */

/* ------------------------------------------- */
	Export("<tr>\n<td>\n");
	Export("<table>\n<tr><td>\n");
	/* formular pre PRM_TABULKA, 15/03/2000A.D. */
	Export("<"HTML_FORM_INPUT_RADIO" name=\"%s\" value=\"%s\">",
		STR_QUERY_TYPE, STR_PRM_TABULKA);
	Export("</td><td>\n");
	Export("&nbsp;");
	Export((char *)html_text_tabulka_pohyblive_od[_global_jazyk]); /* 2006-08-02 */
	Export("&nbsp;");
	/* pole WWW_ROK_FROM */
	Export("<"HTML_FORM_INPUT_TEXT" name=\"%s\" size=5 value=\"%d\">\n",
		STR_ROK_FROM, dnes.tm_year - 12);
	Export("&nbsp;");
	Export((char *)html_text_do_roku[_global_jazyk]); /* 2006-08-02 */
	Export("&nbsp;\n");
	/* pole WWW_ROK_TO */
	Export("<"HTML_FORM_INPUT_TEXT" name=\"%s\" size=5 value=\"%d\">\n",
		STR_ROK_TO, dnes.tm_year + 12);
	Export("</td></tr>\n<tr><td></td><td>");
	/* pole WWW_TABULKA_LINKY */
	Export("<"HTML_FORM_INPUT_CHECKBOX" name=\"%s\" value=\"%d\">\n",
		STR_TABULKA_LINKY, 1); /* ked bude zaskrtnuty, tak vrati hodnotu 1; 15/03/2000A.D. */
	Export("&nbsp;");
	Export((char *)html_text_zobrazit_linky[_global_jazyk]); /* 2006-08-02 */
	Export("\n");
	Export("</td></tr></table>\n");
	Export("</tr>\n\n"); /* 2003-07-09, podozrivo tam bolo aj </td> */

/* ------------------------------------------- */
	Export("<tr>\n<td>\n");
	Export("<table>\n<tr><td>\n");
	/* 2003-07-16; tento formular bol povodne na 2. mieste */
	/* formular pre PRM_CEZ_ROK */
	Export("<"HTML_FORM_INPUT_RADIO" name=\"%s\" value=\"%s\">",
		STR_QUERY_TYPE, STR_PRM_CEZ_ROK);
	Export("</td><td>\n");

	/* 2003-07-16; povodne toto pole bolo na konci */
	/* pole WWW_MODLITBA */
	Export("<select name=\"%s\">\n", STR_MODLITBA);
	Export("<option>%s\n", nazov_modlitby(MODL_PRVE_VESPERY));
	Export("<option selected>%s\n", nazov_modlitby(MODL_RANNE_CHVALY));
	Export("<option>%s\n", nazov_modlitby(MODL_POSV_CITANIE)); /* posv‰tnÈ ËÌtanie: pridanÈ 2005-08-15 */
	Export("<option>%s\n", nazov_modlitby(MODL_PREDPOLUDNIM));
	Export("<option>%s\n", nazov_modlitby(MODL_NAPOLUDNIE));
	Export("<option>%s\n", nazov_modlitby(MODL_POPOLUDNI)); /* cez den: pridane 2003-08-06 */
	Export("<option>%s\n", nazov_modlitby(MODL_DRUHE_VESPERY));
	Export("</select>\n");

	Export("&nbsp;");
	Export((char *)html_text_pre_cezrocne_obd[_global_jazyk]); /* 2006-08-02 */
	Export(",&nbsp;&nbsp;\n");

	/* pole WWW_DEN_V_TYZDNI */
	Export("<select name=\"%s\">\n", STR_DEN_V_TYZDNI);
	for(day = 0; day < 7; day++)
		if(day == dnes.tm_wday)
			Export("<option selected>%s", nazov_dna(day));
		else
			Export("<option>%s", nazov_dna(day));
	Export("\n</select>&nbsp;v\n");

	/* pole WWW_TYZDEN */
	Export("<select name=\"%s\">\n", STR_TYZDEN);
	for(day = 1; day < 5; day++)
		if(day == _global_den.tyzzal)
			Export("<option selected>%d", day);
		else
			Export("<option>%d", day);
	Export("\n</select>&nbsp;");
	Export((char *)html_text_v_tyzdni_zaltara[_global_jazyk]); /* 2006-08-02 */

	Export("</td></tr></table>\n");
	Export("</tr>\n\n"); /* 2003-07-09, podozrivo tam bolo aj </td> */

/* ------------------------------------------- */
	Export("</table>\n");

	/* predtym tu bolo <br>, ale kedze hore som dal <table align="center">, 
	 * tak tu musi byt <center> kvoli buttonom; 2003-07-09
	 */
	Export("\n<center>\n");
	/* button Vyhladaj (GO!) */
	Export("<"HTML_FORM_INPUT_SUBMIT" value=\"");
	Export((char *)HTML_BUTTON_DNES_SHOW);
	Export("\">");

	/* button Vycisti (CLEAR!) */
	Export("&nbsp;&nbsp;&nbsp;\n");
	Export("<"HTML_FORM_INPUT_RESET" value=\"");
	Export((char *)HTML_BUTTON_DNES_DEFAULTS);
	Export("\">");

	Export("</center>\n</form>\n\n");

}

/* 2006-07-12: vytvorenÈ kvÙli jazykov˝m mut·ci·m
 * popis: vr·ti ËÌslo jazyka 
 *			 inak vrati UNKNOWN_DEN
 */
short int atojazyk(char *jazyk){
	short int i = 0;
	do{
		if(equalsi(jazyk, skratka_jazyka[i]) || equalsi(jazyk, nazov_jazyka[i])){
			return i;
		}
		i++;
	}while(i < JAZYK_UNDEF);
	return JAZYK_UNDEF;
}

/* 2006-02-10: nov˝ define; pouûÌva premennÈ int i, p */
#define _parsuj_parameter_MODLITBA {\
	/* rozparsovanie parametra modlitba */\
	Log("/* rozparsovanie parametra modlitba */\n");\
	if(equals(modlitba, STR_EMPTY))\
		p = MODL_NEURCENA;\
	else if(equals(modlitba, STR_MODL_DETAILY))\
		p = MODL_DETAILY;\
/*	else if(equals(modlitba, STR_MODL_INVITATORIUM))\
		p = MODL_INVITATORIUM;*/\
	else if(equals(modlitba, STR_MODL_RANNE_CHVALY))\
		p = MODL_RANNE_CHVALY;\
	/* 2003-08-11 pridana modlitba posvatneho citania */\
	else if(equals(modlitba, STR_MODL_POSV_CITANIE))\
		p = MODL_POSV_CITANIE;\
	/* 2003-07-15 pridane modlitby cez den */\
	else if(equals(modlitba, STR_MODL_PREDPOLUDNIM))\
		p = MODL_PREDPOLUDNIM;\
	else if(equals(modlitba, STR_MODL_NAPOLUDNIE))\
		p = MODL_NAPOLUDNIE;\
	else if(equals(modlitba, STR_MODL_POPOLUDNI))\
		p = MODL_POPOLUDNI;\
	else if(equals(modlitba, STR_MODL_VESPERY))\
		p = MODL_VESPERY;\
/*	else if(equals(modlitba, STR_MODL_KOMPLETORIUM))\
		p = MODL_KOMPLETORIUM; */\
	else\
		p = MODL_NEURCENA;\
	/* este treba skontrolovat, ci nazov modlitby nie je\
	 * string ...azov_modlitby[...] */\
	if(p == MODL_NEURCENA){\
		/* postupne porovnavame s troma konstantami,\
		 * nazov_[modlitby|Modlitby|MODLITBY],\
		 * a to pre konstanty MODL_INVITATORIUM -- MODL_DETAILY (vratane)\
		 */\
		for(i = MODL_INVITATORIUM; i <= MODL_DETAILY; i++){\
			if(equals(modlitba, nazov_modlitby(i)) || \
				equals(modlitba, nazov_Modlitby[i]) /*|| \
				equals(modlitba, nazov_MODLITBY[i])*/){\
				/* ak je zhoda, potom prirad do p a ukonci `for' */\
				p = i;\
				break;\
			}\
		}\
	}\
}

/* 2006-02-10: nov˝ define; pouûÌva premenn˙ int i */
#define _rozparsuj_parametre_OPT {\
	Log("/* rozparsovanie parametrov opt1...opt5 */\n"); \
 \
	/* option 1 */ \
	if(equals(pom_MODL_OPT1, STR_ANO) || equals(pom_MODL_OPT1, "1")){ \
		_global_opt1 = ANO; \
	} \
	else if(equals(pom_MODL_OPT1, STR_NIE) || equals(pom_MODL_OPT1, "0")){ \
		_global_opt1 = NIE; \
	}/* inak ostane _global_opt1 default */ \
	Log("opt1 == `%s' (%d)\n", pom_MODL_OPT1, _global_opt1); \
 \
	/* option 2 */ \
	if(equals(pom_MODL_OPT2, STR_MODL_ZALMY_ZO_DNA) || equals(pom_MODL_OPT2, "0")){ \
		_global_opt2 = MODL_ZALMY_ZO_DNA; \
	} \
	else if(equals(pom_MODL_OPT2, STR_MODL_ZALMY_ZO_SV) || equals(pom_MODL_OPT2, "1")){ \
		_global_opt2 = MODL_ZALMY_ZO_SV; \
	}/* inak ostane _global_opt2 default - upravena copy-paste chyba; 2005-03-22 */ \
	Log("opt2 == `%s' (%d)\n", pom_MODL_OPT2, _global_opt2); \
 \
	/* option 3 */ \
	i = atoi(pom_MODL_OPT3); \
	/* povodne pre debuggovanie v DOSe, potom sa ukazalo, ze je to uzitocne \
	 * aj pod linuxom (v ostrej prevadzke); 18/02/2000A.D. \
	 * predpokladam, ze tento parameter moze byt \
	 * zadany eventualne cislom (teda retazcom, kt. hodnota pri konverzii \
	 * na int je int, urcujuci opt3 \
	 */ \
	if((i > MODL_SPOL_CAST_NEBRAT) || (i <= 0)){ \
		i = 0; \
		/* ide o znakovy retazec nekonvertovatelny na cislo */ \
	} \
	else{ \
		mystrcpy(pom_MODL_OPT3, nazov_spolc(i), SMALL); \
		/* ak je zadane cislo spravne, tak i bude spravny int \
		 * a pom_MODL_OPT3 bude spravny char* */ \
	} \
	Log("opt3: i == %d\n", i); \
	while(i <= MODL_SPOL_CAST_NEBRAT){ \
		if(equals(pom_MODL_OPT3, nazov_spolc(i))){ \
			_global_opt3 = i; \
			break; \
		} \
		i++; \
	} \
	if(i > MODL_SPOL_CAST_NEBRAT){ \
		_global_opt3 = MODL_SPOL_CAST_NEURCENA; \
	} \
	Log("opt3 == `%s' (%d)\n", pom_MODL_OPT3, _global_opt3); \
 \
	/* option 4 */ \
	if(equals(pom_MODL_OPT4, STR_ANO) || equals(pom_MODL_OPT4, "1")){ /* 2003-07-08 opravene z "4" na "1" */ \
		_global_opt4 = ANO; \
	} \
	else if(equals(pom_MODL_OPT4, STR_NIE) || equals(pom_MODL_OPT4, "0")){ \
		_global_opt4 = NIE; \
	}/* inak ostane _global_opt4 default */ \
	Log("opt4 == `%s' (%d)\n", pom_MODL_OPT4, _global_opt4); \
 \
	/* option 5, pridana 2003-08-12, upravena 2003-08-13 */ \
	if(equals(pom_MODL_OPT5, STR_MODL_CEZ_DEN_ZALMY_ZO_DNA) || equals(pom_MODL_OPT5, "0")){ \
		_global_opt5 = MODL_CEZ_DEN_ZALMY_ZO_DNA; \
	} \
	else if(equals(pom_MODL_OPT5, STR_MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA) || equals(pom_MODL_OPT5, "1")){ \
		_global_opt5 = MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA; \
	}/* inak ostane _global_opt5 default */ \
	Log("opt5 == `%s' (%d)\n", pom_MODL_OPT5, _global_opt5); \
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
#define ExportUDAJE	result = FAILURE; if(!heading_written){_export_heading("Rozbor dÚa"); heading_written = 1;} Log("error: Nevhodne udaje\n"); Export("NevhodnÈ ˙daje: "); Export
void _main_rozbor_dna(char *den, char *mesiac, char *rok, char *modlitba, char *poradie_svaty){
	short int heading_written = 0;
	char pom[MAX_STR];
	Log("-- _main_rozbor_dna(char *, char *, char *, char *, char *): begin (%s, %s, %s, %s, %s)\n",
		den, mesiac, rok, modlitba, poradie_svaty);
	short int d, m, r, p, s, i;
	short int pm, pr; /* pomocny mesiac, pomocny rok */

	char pom2[MAX_STR]; /* 2006-08-01: pridanÈ kvÙli transferu ˙dajov o jazyku */
	mystrcpy(pom, STR_EMPTY, MAX_STR); /* 2006-08-01: pridan· inicializ·cia */
	mystrcpy(pom2, STR_EMPTY, MAX_STR); /* 2006-08-01: pridanÈ */

	/* 2006-08-01: pridanÈ odovzdanie parametra pre jazyk */
	if(_global_jazyk != JAZYK_SK){
		sprintf(pom2, HTML_AMPERSAND"%s=%s", STR_JAZYK, skratka_jazyka[_global_jazyk]);
		Log("\tBudem prilepovaù aj jazyk: `%s' (2006-07-31)\n", pom2);
	}

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
	_parsuj_parameter_MODLITBA;

	_global_modlitba = p;
	Log("modl == %s (%d, %s) -- priradene do _global_modlitba\n", modlitba, p, nazov_modlitby(p));

	/* rozparsovanie parametrov opt1...opt5, 2005-03-22; presunutÈ do define 2006-02-10 */
	_rozparsuj_parametre_OPT;

	/* option a (append), pridana 2003-07-08 - nastavi sa v getArgv(); */

	/* kontrola udajov */
	short int result = SUCCESS;
	/* den */
	if(equals(den, STR_EMPTY)){
		ExportUDAJE("ch˝ba ˙daj o dni.<br>\n");
	}
	else if(d == 0){
		/* zmenene <b> na <span class="bold">, 2003-07-02 */
		ExportUDAJE("deÚ = <"HTML_SPAN_BOLD">%s</span>.<br>\n", den);
	}
	/* mesiac */
	if(equals(mesiac, STR_EMPTY)){
		ExportUDAJE("ch˝ba ˙daj o mesiaci.<br>\n");
	}
	else if(m == UNKNOWN_MESIAC){
		ExportUDAJE("tak˝ mesiac nepozn·m (%s).<br>\n", mesiac);
	}
	/* rok */
	if(equals(rok, STR_EMPTY)){
		ExportUDAJE("ch˝ba ˙daj o roku.<br>\n");
	}
	else if(r == 0){
		/* zmenene <b> na <span class="bold">, 2003-07-02 */
		ExportUDAJE("rok = <"HTML_SPAN_BOLD">%s</span>.<br>\n", rok);
	}

	/* kontrola udajov ukoncena, podla nej pokracujeme dalej */
	if(result == FAILURE){
		Log("/* teraz result == FAILURE */\n");
		ALERT;
		return;
	}

	Log("/* teraz result == SUCCESS */\n");
	if(m == VSETKY_MESIACE){
		if(p != MODL_NEURCENA){
			ExportUDAJE("pre viacej mesiacov zobrazenie modlitby nie je podporovanÈ\n");
			return;
		}/* p != MODL_NEURCENA */
		if(_global_opt1 == NIE){
			/* 2005-03-22: Toto zobrazujeme len pre isty typ exportu */
			Log("/* teraz vypisujem heading, rok %d */\n", r);
			sprintf(pom, (char *)html_text_Rok_x[_global_jazyk], r);
			_export_heading_center(pom);
			/* nezobrazovalo sa korektne; pridane </a>, 2003-07-02 */
			Export("<a name=\"rok\"></a>\n");
			Export("<center>\n");
			/* najprv vygenerujem zoznam liniek (mesiace) */
			for(m = MES_JAN; m <= MES_DEC; m++){
				Export("<a href=\"#mesiac%d\">%s</a>&nbsp;\n",
					m, nazov_MESIACA(m));
			}
			/* teraz linku na #explain -- vysvetlivky */

			/* <font size=-1></font> zmeneny na <span class="small"></span>, 2003-07-14 
			 * a napokon uplne odstraneny...
			 */
			Export("<br><span class=\"small\"><a href=\"#explain\">Vysvetlivky</a></span>\n");
			/* napokon ciaru */
			Export("</center>\n<hr>\n");
		}

		/* teraz generujem jednotlive mesiace so vsetkymi dnami */
		for(m = MES_JAN; m <= MES_DEC; m++){
			/*
				Vytvor_global_link(VSETKY_DNI, m + 1, r);
				// nezobrazovalo sa korektne; pridane </a>, 2003-07-02
				Export("\n\n<a name=\"mesiac%d\"></a>", m);
				// zmenene <b> na <span class="bold">, 2003-07-02
				Export("\n<p><center><"HTML_SPAN_BOLD">%s</span> (<a href=\"#rok\">zoznam mesiacov</a>)</center>\n",
					_global_link);
				rozbor_mesiaca(m + 1, r);
			*/
			if(_global_opt1 == NIE){
				/* 2005-03-22: Toto zobrazujeme len pre isty typ exportu */
				/* nezobrazovalo sa korektne; pridane </a>, 2003-07-02 */
				Export("\n\n<a name=\"mesiac%d\"></a>", m);
				/* zmenene <b><font color> na <span class="redbold">, 2003-07-02 */
				Export("\n<p><center><"HTML_SPAN_RED_BOLD">%s</span>",
					nazov_MESIACA(m));
				Export(" (<a href=\"#rok\">zoznam mesiacov</a>)</center>\n");
			}
			rozbor_mesiaca(m + 1, r);
		}/* for */

		VYSVETLIVKY();

		if((_global_linky == ANO) && (_global_opt1 == NIE)){
		/* 2005-03-22: Upravene; podmienka zosilnena (and _global_opt1 == NIE) */
		/* pridane 13/04/2000A.D. */
		/* pridane 25/02/2000A.D. -- buttony Predchadzajuci, Nasledujuci rok */
		/* 2003-07-16; zrusene <hr> */
		Export("\n<br>\n<center><table>\n");
		/* predosly rok -- button */
		Export("<td align=\"right\"><form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%s"HTML_AMPERSAND"%s=%s"HTML_AMPERSAND"%s=%d%s\" method=\"post\">\n",
			script_name,
			STR_QUERY_TYPE, STR_PRM_DATUM,
			STR_DEN, STR_VSETKY_DNI,
			STR_MESIAC, STR_VSETKY_MESIACE,
			STR_ROK, r - 1,
			pom2);
		/* 2003-07-16; << zmenene na &lt;&lt; */
		Export("<"HTML_FORM_INPUT_SUBMIT" value=\"&lt;&lt;%d (", r - 1);
		Export((char *)html_button_predchadzajuci_[_global_jazyk]);
		Export(" ");
		Export((char *)html_text_rok[_global_jazyk]);
		Export(" )\">\n");
		Export("</form></td>\n");

		/* nasledujuci rok -- button */
		Export("<td align=\"right\"><form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%s"HTML_AMPERSAND"%s=%s"HTML_AMPERSAND"%s=%d%s\" method=\"post\">\n",
			script_name,
			STR_QUERY_TYPE, STR_PRM_DATUM,
			STR_DEN, STR_VSETKY_DNI,
			STR_MESIAC, STR_VSETKY_MESIACE,
			STR_ROK, r + 1,
			pom2);
		/* 2003-07-16; >> zmenene na &gt;&gt; */
		Export("<"HTML_FORM_INPUT_SUBMIT" value=\"(");
		Export((char *)html_button_nasledujuci_[_global_jazyk]);
		Export(" ");
		Export((char *)html_text_rok[_global_jazyk]);
		Export(" ) %d&gt;&gt;\">\n", r + 1);
		Export("</form></td>\n");
		/* koniec buttonov */
		Export("</table></center>\n");
		}/* if(_global_linky == ANO) */
	}/* m == VSETKY_MESIACE */
	else{/* m != VSETKY_MESIACE */
		/* nesmiem zabudnut, ze m je 0--11 */
		m++;
		if(d == VSETKY_DNI){
			if(p != MODL_NEURCENA){
				ExportUDAJE("pre viacej dnÌ zobrazenie modlitby nie je podporovanÈ\n");
				return;
			}
			Log("/* teraz vypisujem heading 1, mesiac %s, rok %d */\n",
				nazov_mesiaca(m - 1), r);
			/* 2003-07-16; presunute sem vyssie */
			if(prestupny(r))
				pocet_dni[MES_FEB] = 29;
			else
				pocet_dni[MES_FEB] = 28;
			vytvor_global_link(VSETKY_DNI, VSETKY_MESIACE, r, LINK_DEN_MESIAC_ROK);

			sprintf(pom, "%s %s", nazov_Mesiaca(m - 1), _global_link); /* 2003-07-16; bolo tu %d - r */
			_export_heading_center(pom);
			/* 2003-07-16 zapoznamkovane - je to redundantne
			 * Export("\n<center><h2>Rok %s</h2></center>\n", _global_link);
			 */

			/* zmenene <b><font color> na <span class="redbold">, 2003-07-02 */
			Export("<center><"HTML_SPAN_RED_BOLD">%s</span></center>\n",
				nazov_MESIACA(m - 1));

			rozbor_mesiaca(m, r);

			VYSVETLIVKY();

			if((_global_linky == ANO) && (_global_opt1 == NIE)){
			/* 2005-03-22: Upravene; podmienka zosilnena (and _global_opt1 == NIE) */
				/* pridane 13/04/2000A.D. */
				/* pridane 25/02/2000A.D. -- buttony Predchadzajuci, Nasledujuci mesiac */
				Export("\n<table align=\"center\">\n"); /* 2003-07-16 zrusena <hr> */
				/* predosly mesiac -- button */
				pm = m; pr = r;
				if(m == 1){
					pm = 12;
					pr = r - 1;
				}
				else{
					pm = m - 1;
				}
				Export("<td align=right><form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d%s\" method=\"post\">\n",
					script_name,
					STR_QUERY_TYPE, STR_PRM_DATUM,
					STR_DEN, STR_VSETKY_DNI,
					STR_MESIAC, pm,
					STR_ROK, pr,
					pom2);
				Export("<"HTML_FORM_INPUT_SUBMIT" value=\"<<%s %d\">\n", nazov_Mesiaca(pm - 1), pr);
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
				Export("<td align=right><form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%s"HTML_AMPERSAND"%s=%d"HTML_AMPERSAND"%s=%d%s\" method=\"post\">\n",
					script_name,
					STR_QUERY_TYPE, STR_PRM_DATUM,
					STR_DEN, STR_VSETKY_DNI,
					STR_MESIAC, pm,
					STR_ROK, pr,
					pom2);
				Export("<"HTML_FORM_INPUT_SUBMIT" value=\"%s %d>>\">\n", nazov_Mesiaca(pm - 1), pr);
				Export("</form></td>\n");
				/* koniec buttonov */
				Export("</table>\n");
			}/* _global_linky == ANO */
		}/* d == VSETKY_DNI */
		else{/* d != VSETKY_DNI */
			if(!kontrola(d, m, r)){
				Log("/* teraz vypisujem heading 1, datum %d. %s %d */\n",
					d, nazov_mesiaca(m - 1), r);
				sprintf(pom, "%d. %s %d", d, nazov_mesiaca(m - 1), r);
				_export_heading_center(pom);
				/* 2003-06-30: podla toho, ci je alebo nie je urcena modlitba */
				if(p == MODL_NEURCENA){
					rozbor_dna(d, m, r);
					_main_formular(d, m, r, den_v_tyzdni(d, m, r));
				}
				else{
					rozbor_dna_s_modlitbou(d, m, r, p, s);
				}
			}
		}/* d != VSETKY_DNI */
	}/* m != VSETKY_MESIACE */

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
 * 2006-02-10: pridan· moûnosù priamo generovaù modlitbu,
 *             preto s˙ vstupom aj dve premennÈ podobne ako je to v _main_rozbor_dna
 *
 */
void _main_dnes(char *modlitba, char *poradie_svaty){
	time_t timer;
	struct tm dnes;
	long jd_dnes;
	char pom[MAX_STR];

	Log("-- _main_dnes(char *, char *): begin (%s, %s)\n", modlitba, poradie_svaty);

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

	/* dnes.tm_wday == 0--6 (0==sunday, nedela) */

	/* dalej rozoberiem den a vypisem vysledok */
	_struct_den_mesiac datum;
	datum.den = dnes.tm_mday;
	datum.mesiac = dnes.tm_mon;
	analyzuj_rok(dnes.tm_year); /* vysledok da do _global_r */

	short int s, p, i;

	s = atoi(poradie_svaty); /* ak je viac svatych, ktory z nich (1--3) */
	Log("sv == `%s' (%d)\n", poradie_svaty, s);

	/* rozparsovanie parametra modlitba */
	_parsuj_parameter_MODLITBA;

	_global_modlitba = p;
	Log("modl == %s (%d, %s) -- priradene do _global_modlitba\n", modlitba, p, nazov_modlitby(p));

	/* rozparsovanie parametrov opt1...opt5; v define 2006-02-10 podæa _main_rozbor_dna */
	_rozparsuj_parametre_OPT;

	/* vypis */
	Log("/* teraz vypisujem heading 1, datum %d. %s %d */\n",
		dnes.tm_mday, nazov_mesiaca(dnes.tm_mon - 1), dnes.tm_year);
	sprintf(pom, "%d. %s %d",
		dnes.tm_mday, nazov_mesiaca(dnes.tm_mon - 1), dnes.tm_year);
	_export_heading_center(pom);

	/* 2006-02-10: v˝pis juli·nskeho d·tumu, len ak nie je urËen· modlitba */
	if(_global_modlitba == MODL_NEURCENA){
		Export((char *)html_text_dnes_je_atd[_global_jazyk],
			dnes.tm_yday,
#undef ZOBRAZ_JULIANSKY_DATUM
#ifdef ZOBRAZ_JULIANSKY_DATUM
			(char *)STR_EMPTY,
#else
			(char *)HTML_COMMENT_BEGIN,
#endif
			(_global_linky == ANO)? HTTP_ADDRESS: MESSAGE_FOLDER,
			FILE_JULIANSKY_DATUM,
			jd_dnes,
#ifdef ZOBRAZ_JULIANSKY_DATUM
			(char *)STR_EMPTY
#else
			(char *)HTML_COMMENT_END
#endif
			);
		_rozbor_dna(datum, dnes.tm_year);
		_export_rozbor_dna(EXPORT_DNA_DNES);
		/* 2006-02-02: cel˝ zvyön˝ formul·r presunut˝ do samostatnej funkcie */
		_main_formular(datum.den, datum.mesiac, dnes.tm_year, dnes.tm_wday);
	}
	else{
		/* ak je urËen· modlitba, postupujeme rovnako ako v _main_rozbor_dna */
		rozbor_dna_s_modlitbou(datum.den, datum.mesiac, dnes.tm_year, p, s);
	}

	Log("-- _main_dnes(char *, char *): end\n");

}/* _main_dnes(); */

/*---------------------------------------------------------------------*/
/* _main_zaltar() */
void _main_zaltar(char *den, char *tyzden, char *modlitba){
	short int d, t, p, i;
	d = atodenvt(den);
	t = atoi(tyzden);
	if((d < 0) || (d > 6) || (t < 1) || (t > 4)){
		Export("NevhodnÈ ˙daje:<br>\n<ul>");
		/* den */
		if(equals(den, STR_EMPTY))
			Export("<li>ch˝ba ˙daj o dni</li>\n");
		else if(d == DEN_UNKNOWN)
			Export("<li>deÚ = <"HTML_SPAN_BOLD">%s</span></li>\n", den); /* zmenene <b> na <span class="bold">, 2003-07-02 */
		/* tyzden */
		if(equals(tyzden, STR_EMPTY))
			Export("<li>ch˝ba ˙daj o t˝ûdni</li>\n");
		else if((t < 1) || (t > 4))
			Export("<li>t˝ûdeÚ = <"HTML_SPAN_BOLD">%s</span></li>\n", tyzden); /* zmenene <b> na <span class="bold">, 2003-07-02 */
		Export("</ul>\n");
		ALERT;
		return;
	}
	p = MODL_NEURCENA;
	for(i = MODL_INVITATORIUM; i <= MODL_DRUHE_KOMPLETORIUM; i++){
		if(equals(modlitba, nazov_modlitby(i))){
			p = i;
			continue; /* exit from loop */
		}
	}
	if(p == MODL_NEURCENA){
		/* 2005-08-15: KvÙli simul·cii porovn·vame aj s konötantami STR_MODL_... */
		if(equals(modlitba, STR_MODL_RANNE_CHVALY))
			p = MODL_RANNE_CHVALY;
		else if(equals(modlitba, STR_MODL_POSV_CITANIE))
			p = MODL_POSV_CITANIE;
		else if(equals(modlitba, STR_MODL_VESPERY))
			p = MODL_VESPERY;
		else if(equals(modlitba, STR_MODL_PREDPOLUDNIM))
			p = MODL_PREDPOLUDNIM;
		else if(equals(modlitba, STR_MODL_NAPOLUDNIE))
			p = MODL_NAPOLUDNIE;
		else if(equals(modlitba, STR_MODL_POPOLUDNI))
			p = MODL_POPOLUDNI;
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
	/* 2003-08-13: neviem preco tu bola poznamka "unfinished - este nejde uplne spravne" */

	Log("spustam showPrayer(%s)...\n",
		nazov_Modlitby[_global_modlitba]);

	/* predpokladam, ze aj _global_modlitba je prve/druhe vespery,
	 * v _global_prve_vespery su spravne udaje (podobne kompletorium) */
	showPrayer(p);
}/* _main_zaltar() */

/*---------------------------------------------------------------------*/
/* _main_sviatok() */
void _main_sviatok(char *sviatok){
	if(equals(sviatok, STR_EMPTY)){
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
	short int i;
	short int year;
	char pom[MAX_STR];

	char pom2[MAX_STR]; /* 2006-08-01: pridanÈ kvÙli transferu ˙dajov o jazyku */
	mystrcpy(pom, STR_EMPTY, MAX_STR); /* 2006-08-01: pridan· inicializ·cia */
	mystrcpy(pom2, STR_EMPTY, MAX_STR); /* 2006-08-01: pridanÈ */

	/* 2006-08-01: pridanÈ odovzdanie parametra pre jazyk */
	if(_global_jazyk != JAZYK_SK){
		sprintf(pom2, HTML_AMPERSAND"%s=%s", STR_JAZYK, skratka_jazyka[_global_jazyk]);
		Log("\tBudem prilepovaù aj jazyk: `%s' (2006-07-31)\n", pom2);
	}

#define LOG  Log("analyza_roku(): "); Log
	Log("-- _main_analyza_roku(): zaciatok\n");

#define ExportROK	Export("<br>"); Export
	year = atoi(rok);
	if(year <= 0){
		_export_heading("Anal˝za roku");
		Export("Nevhodn˝ ˙daj: ");
		if(equals(rok, STR_EMPTY))
			Export("nezadan˝ rok.\n");
		else if(equals(rok, "0"))
			Export("nepozn·m rok <"HTML_SPAN_BOLD">0</span>.\n"); /* zmenene <b> na <span class="bold">, 2003-07-02 */
		else
			Export("chybnÈ ËÌslo (%s).\n", rok);
		ALERT;
		return;
	}

	sprintf(pom, (char *)html_text_Rok_x[_global_jazyk], year);
	_export_heading_center(pom);

	LOG("vchadzam do analyzuj_rok()...\n");
	analyzuj_rok(year); /* vysledok da do _global_r */
	LOG("analyzuj_rok() ukoncena.\n");

	/* zmenene <font color> na <span>, 2003-07-02 */
	Export("<"HTML_SPAN_RED">");
	Export((char *)html_text_zakladne_info[_global_jazyk]); /* 2006-08-02 */
	Export(":</span>\n");
	Export("<br>\n");
	vytvor_global_link(VSETKY_DNI, VSETKY_MESIACE, year, LINK_DEN_MESIAC_ROK);

	/* 13/04/2000A.D.: pridane rozhodovanie podla _global_linky */
	if(_global_linky == ANO)
		mystrcpy(pom, HTTP_ADDRESS, MAX_STR);
	else /* _global_linky == NIE */
		mystrcpy(pom, MESSAGE_FOLDER, MAX_STR);

	/* zmenene <b> na <span class="bold">, 2003-07-02 */
	ExportROK((char *)html_text_Rok[_global_jazyk]);
	Export(" %s <"HTML_SPAN_BOLD">", _global_link);
	if(_global_r.prestupny == YES){
		Export((char *)html_text_je[_global_jazyk]); /* 2006-08-02 */
	}
	else{
		Export((char *)html_text_nie_je[_global_jazyk]); /* 2006-08-02 */
	}
	Export("</span> <a href=\"%s%s\">", pom, FILE_PRESTUPNY_ROK);
	Export((char *)html_text_prestupny[_global_jazyk]); /* 2006-08-02 */
	Export("</a>.\n");

	ExportROK("<a href=\"%s%s\">", pom, FILE_NEDELNE_PISMENO);
	if(_global_r.prestupny == YES){
		/* zmenene <b> na <span class="bold">, 2003-07-02 */
		Export((char *)html_text_Nedelne_pismena[_global_jazyk]); /* 2006-08-07 */
		Export("</a>: <"HTML_SPAN_BOLD">%c %c</span>\n", _global_r.p1, _global_r.p2);
	}
	else{
		/* zmenene <b> na <span class="bold">, 2003-07-02 */
		Export((char *)html_text_Nedelne_pismeno[_global_jazyk]); /* 2006-08-07 */
		Export("</a>: <"HTML_SPAN_BOLD">%c</span>\n", _global_r.p1);
	}

	datum = prva_adventna_nedela(year - 1);
	vytvor_global_link(datum.den, datum.mesiac, year - 1, LINK_DEN_MESIAC);
	/* vytvor_global_link nastavi _global_link */
		/* zmenene <b> na <span class="bold">, 2003-07-02 */
	ExportROK((char *)html_text_Od_prvej_adv_atd[_global_jazyk], /* 2006-08-07 */
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
			/* zmenene <b> na <span class="bold">, 2003-07-02 */
			Export("<tr valign=baseline><td>%s</td><td>%s</td><td>(%s, %d. deÚ v roku), zaËÌna <a href=\"%s%s\">liturgick˝ rok</a> <"HTML_SPAN_BOLD">%c</span>.</td></tr>\n",
				_global_r._den[i].meno,
				_global_link,
				nazov_dna(_global_r._den[i].denvt),
				_global_r._den[i].denvr,
				pom,
				FILE_LITURGICKY_ROK,
				_global_r._den[i].litrok);
		}
		else{
			if(i == VELKONOCNA_NEDELA)
				mystrcpy(_global_r._den[i].meno, text_VELKONOCNA_NEDELA[_global_jazyk], MENO_SVIATKU);
			Export("<tr valign=baseline><td>%s</td><td>%s</td><td>(%s, %d. deÚ v roku)</td></tr>\n",
				_global_r._den[i].meno,
				_global_link,
				nazov_dna(_global_r._den[i].denvt),
				_global_r._den[i].denvr);
		}
	}
	Export("</table>\n");

	ExportROK("Po Veækej noci nasleduje %d. %s v obdobÌ Ñcez rokì.\n",
		_global_r.tyzden_ocr_po_vn + 1,
		nazov_dna(DEN_NEDELA));

	vytvor_global_link(VSETKY_DNI, VSETKY_MESIACE, year, LINK_DEN_MESIAC_ROK);
	/* zmenene <font color> na <span>, 2003-07-02 */
	ExportROK("<p><"HTML_SPAN_RED">Prik·zanÈ sviatky v roku %s:</span>\n",
		_global_link);
	Export("<br>\n");
	Export("\n<table>\n");

	/* 1. januara */
	vytvor_global_link(1, 1, year, LINK_DEN_MESIAC);
	Export("<tr valign=baseline>\n<td>%s</td><td>%s</td></tr>\n", _global_link, text_JAN_01[_global_jazyk]);

	/* 6. januara */
	vytvor_global_link(6, 1, year, LINK_DEN_MESIAC);
	Export("<tr valign=baseline>\n<td>%s</td><td>%s</td></tr>\n", _global_link, text_JAN_06[_global_jazyk]);

	/* nanebovstupenie pana, pridane 2003-07-01 */
	vytvor_global_link(_global_r._NANEBOVSTUPENIE_PANA.den, _global_r._NANEBOVSTUPENIE_PANA.mesiac, year, LINK_DEN_MESIAC);
	Export("<tr valign=baseline>\n<td>%s</td><td>%s</td></tr>\n", _global_link, text_NANEBOVSTUPENIE_PANA[_global_jazyk]);

	/* najsv. kristovho tela a krvi, pridane 2003-07-01 */
	/* kedze nie je v strukture _global_r, treba ho spocitat podla zoslania ducha sv.
	 * ide vlastne o datum (cislo v roku) pre ZDS + 11, ako je definovany TELAKRVI,
	 * vyuzijeme parameter datum na zistenie dna a mesiaca */
	datum = por_den_mesiac(TELAKRVI, year);
	vytvor_global_link(datum.den, datum.mesiac, year, LINK_DEN_MESIAC);
	Export("<tr valign=baseline>\n<td>%s</td><td>%s</td></tr>\n", _global_link, text_NAJSV_KRISTOVHO_TELA_A_KRVI[_global_jazyk]);

	/* 29. juna */
	vytvor_global_link(29, 6, year, LINK_DEN_MESIAC);
	Export("<tr valign=baseline>\n<td>%s</td><td>%s</td></tr>\n", _global_link, text_JUN_29[_global_jazyk]);

	/* 15. augusta */
	vytvor_global_link(15, 8, year, LINK_DEN_MESIAC);
	Export("<tr valign=baseline>\n<td>%s</td><td>%s</td></tr>\n", _global_link, text_AUG_15[_global_jazyk]);

	/* 1. novembra */
	vytvor_global_link(1, 11, year, LINK_DEN_MESIAC);
	Export("<tr valign=baseline>\n<td>%s</td><td>%s</td></tr>\n", _global_link, text_NOV_01[_global_jazyk]);

	/* 8. decembra */
	vytvor_global_link(8, 12, year, LINK_DEN_MESIAC);
	Export("<tr valign=baseline>\n<td>%s</td><td>%s</td></tr>\n", _global_link, text_DEC_08[_global_jazyk]);

	/* 25. decembra */
	vytvor_global_link(25, 12, year, LINK_DEN_MESIAC);
	Export("<tr valign=baseline>\n<td>%s</td><td>%s</td></tr>\n", _global_link, text_NARODENIE_PANA[_global_jazyk]);

	Export("</table>\n");

	/* teraz nasleduju jednotlive mesiace roku s linkami na ne */
	vytvor_global_link(VSETKY_DNI, VSETKY_MESIACE, year, LINK_DEN_MESIAC_ROK);
	/* zmenene <font color> na <span>, 2003-07-02 */
	ExportROK("<"HTML_SPAN_RED">JednotlivÈ mesiace roku %s:</span>\n",
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
	if((_global_linky == ANO) && (_global_opt1 == NIE)){
	/* 2005-03-22: Upravene; podmienka zosilnena (and _global_opt1 == NIE) */
	/* pridane 13/04/2000A.D. */
	/* pridane 21/02/2000A.D. -- buttony Predchadzajuci, Nasledujuci rok */
		ExportROK("<table align=\"center\">\n");
		/* predosly rok -- button */
		Export("<td align=\"right\"><form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%d%s\" method=\"post\">\n",
			script_name,
			STR_QUERY_TYPE, STR_PRM_ANALYZA_ROKU,
			STR_ANALYZA_ROKU, year - 1,
			pom2);
		/* 2003-07-16; << zmenene na &lt;&lt; */
		Export("<"HTML_FORM_INPUT_SUBMIT" value=\"&lt;&lt;%d (Predch·dzaj˙ci rok)\">\n", year - 1);
		Export("</form></td>\n");

		/* nasledujuci rok -- button */
		Export("<td align=\"right\"><form action=\"%s?%s=%s"HTML_AMPERSAND"%s=%d%s\" method=\"post\">\n",
			script_name,
			STR_QUERY_TYPE, STR_PRM_ANALYZA_ROKU,
			STR_ANALYZA_ROKU, year + 1,
			pom2);
		/* 2003-07-16; >> zmenene na &gt;&gt; */
		Export("<"HTML_FORM_INPUT_SUBMIT" value=\"(Nasleduj˙ci rok) %d&gt;&gt;\">\n", year + 1);
		Export("</form></td>\n");
		Export("</form></td>\n");
		/* koniec buttonov */
		Export("</table>\n");
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
	short int i;
	short int rfrom, rto, year, linky;

	Log("-- _main_tabulka(): zaciatok\n");

	rfrom = atoi(rok_from);
	rto = atoi(rok_to);
	linky = atoi(tab_linky);
	if((rfrom <= 0) || (rto <= 0) || (rfrom > rto)){
		_export_heading("Anal˝za rokov");
		Export("Nevhodn˝ ˙daj: ");
		if(equals(rok_from, STR_EMPTY))
			Export("nezadan˝ v˝chodzÌ rok.\n");
		if(equals(rok_to, STR_EMPTY))
			Export("nezadan˝ koncov˝ rok.\n");
		else if((equals(rok_from, "0")) || (equals(rok_to, "0")))
			Export("nepozn·m rok <"HTML_SPAN_BOLD">0</span>.\n"); /* zmenene <b> na <span class="bold">, 2003-07-02 */
		else
			Export("chybnÈ ËÌslo (%s, %s).\n", rok_from, rok_to);
		ALERT;
		return;
	}

	_export_heading_center((char *)html_text_datumy_pohyblivych_slaveni[_global_jazyk]);

	Export("<center><table border CELLSPACING=1>\n");
	Export("<tr>\n");
	switch(_global_jazyk){
		case JAZYK_CZ:
			Export("<td align=center>LÈto<br>P·nÏ</td>\n");
			Export("<td align=center>NedÏlnÌ<br>pÌsmeno</td>\n");
			Export("<td align=center>NedÏlnÌ<br>cyklus</td>\n");
			Export("<td align=center>K¯est Krista<br>P·nÏ</td>\n");
			Export("<td align=center><a href=\"#explain\">OCR<br>p¯ed<br>postem</a></td>\n"); /* fajl VYSVETLIVKY_TABULKA(); */
			Export("<td align=center>PopeleËnÌ<br>st¯eda</td>\n");
			Export("<td align=center>Veliko-<br>noce</td>\n");
			Export("<td align=center>Nanebe-<br>vstoupenÌ<br>P·nÏ</td>\n");
			Export("<td align=center>Sesl·nÌ<br>Ducha<br>SvatÈho</td>\n");
			Export("<td align=center><a href=\"#explain\">OCR<br>po<br>VN</a></td>\n"); /* fajl VYSVETLIVKY_TABULKA(); */
			Export("<td align=center>PrvnÌ<br>adventnÌ<br>nedÏle</td>\n");
			Export("<td align=center>NedÏle SvatÈ<br>rodiny</td></tr>\n");
			break;
		case JAZYK_EN:
			/* todo - xxx */
		default:
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
			break;
	} /* switch(_global_jazyk) */
	for(year = rfrom; year <= rto; year++){
		LOG("vchadzam do analyzuj_rok()...\n");
		analyzuj_rok(year); /* vysledok da do _global_r */
		LOG("analyzuj_rok() ukoncena.\n");

		Export("<tr>\n");

		/* rok */
		Export("<td>\n");
		if(linky == ANO){
			/* aj linka musi obsahovat 'prestupnost', podla toho ma farbu */
			if(_global_r.prestupny == YES)
				vytvor_global_link(VSETKY_DNI, VSETKY_MESIACE, year, LINK_DEN_MESIAC_ROK_PRESTUP);
			else
				vytvor_global_link(VSETKY_DNI, VSETKY_MESIACE, year, LINK_DEN_MESIAC_ROK);
		}
		else
			sprintf(_global_link, "%d", year);
		/* kedze <font color=#ff0000> neprebil nastavenia css-ka, 
		 * 1. pridal som globalnu definiciu .red { color: #ff0000; } kt. sa da menit;
		 * 2. pri prestupnom roku sa voli iny parameter ().
		 * 2003-07-02
		 */
		if(_global_r.prestupny == YES)
			Export("<"HTML_SPAN_RED">%s</span>", _global_link);
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
				sprintf(_global_link, "%d. %s", _global_r._den[i].den, nazov_mesiaca(_global_r._den[i].mesiac - 1));
			Export("%s</td>\n", _global_link);
		}/* for -- pre aliasy */

		Export("</tr>\n");
	}/* for */
	Export("</table></center>\n");

	VYSVETLIVKY_TABULKA();
	Log("-- _main_tabulka(): koniec\n");
}/* _main_tabulka() */

void dumpFile(char *fname, FILE *expt){
	short int c;
	FILE *input_file = fopen(fname, "rb");
	if(input_file != NULL){
		while((c = fgetc(input_file)) != EOF)
			fputc(c, expt);
	}
}

/*---------------------------------------------------------------------*/
/* _main_batch_mode(); 2003-07-04
 *
 * dostane vela char *; najprv ich skontroluje a potom
 * ak je vsetko v poriadku, 
 * do export fajlu generuje command-line prikazy pre
 * vytvorenie modlitby na jednotlive dni dane obdobim
 *
 */
void _main_batch_mode(
	char *den_from, char *mesiac_from, char *rok_from, 
	char *den_to, char *mesiac_to, char *rok_to, 
	char *nieco, char *tab_linky){

	short int heading_written = 0; /* je tu kvoli ExportUDAJE definovane pred _main_rozbor_dna */
	Log("-- _main_batch_mode(char * -- 7x): begin (%s, %s, %s, %s, %s, %s, %s, %s)\n",
		den_from, mesiac_from, rok_from, den_to, mesiac_to, rok_to, nieco, tab_linky);
	short int d_from, m_from, r_from, d_to, m_to, r_to;
	long jd_from, jd_to;

	/* rozparsovanie parametrov den, mesiac, rok */
	Log("--start(from)--\n");
	/* from */
	Log("/* rozparsovanie parametrov den, mesiac, rok */\n");
	d_from = atoden(den_from); /* vrati VSETKY_DNI, resp. atoi(den_from) */
	Log("den_from == `%s' (%d)\n", den_from, d_from);
	m_from = atomes(mesiac_from); /* bude to 0--11, resp. VSETKY_MESIACE resp. UNKNOWN_MESIAC */
	Log("mes == `%s' (%d)\n", mesiac_from, m_from);
	r_from = atoi(rok_from); /* vrati 0 v pripade chyby; alebo int */
	Log("rok == `%s' (%d)\n", rok_from, r_from);

	Log("--end(to)--\n");
	/* to */
	Log("/* rozparsovanie parametrov den, mesiac, rok */\n");
	d_to = atoden(den_to); /* vrati VSETKY_DNI, resp. atoi(den_to) */
	Log("den_to == `%s' (%d)\n", den_to, d_to);
	m_to = atomes(mesiac_to); /* bude to 0--11, resp. VSETKY_MESIACE resp. UNKNOWN_MESIAC */
	Log("mes == `%s' (%d)\n", mesiac_to, m_to);
	r_to = atoi(rok_to); /* vrati 0 v pripade chyby; alebo int */
	Log("rok == `%s' (%d)\n", rok_to, r_to);

	/* rozparsovanie parametrov opt1...opt5 - uz ich je viac; 2005-03-22
	 * nebolo by to mozno ani treba, 2003-07-04, prevzate z _main_rozbor_dna();
	 */
	Log("/* rozparsovanie parametrov opt1...opt5 */\n");

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
	short int i = atoi(pom_MODL_OPT3);
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
		mystrcpy(pom_MODL_OPT3, nazov_spolc(i), SMALL);
		/* ak je zadane cislo spravne, tak i bude spravny int
		 * a pom_MODL_OPT3 bude spravny char* */
	}
	Log("opt3: i == %d\n", i);
	while(i <= MODL_SPOL_CAST_NEBRAT){
		if(equals(pom_MODL_OPT3, nazov_spolc(i))){
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
	if(equals(pom_MODL_OPT4, STR_ANO) || equals(pom_MODL_OPT4, "1")){ /* 2003-07-08 opravene z "4" na "1" */
		_global_opt4 = ANO;
	}
	else if(equals(pom_MODL_OPT4, STR_NIE) || equals(pom_MODL_OPT4, "0")){
		_global_opt4 = NIE;
	}/* inak ostane _global_opt4 default */
	Log("opt4 == `%s' (%d)\n", pom_MODL_OPT4, _global_opt4);

	/* option a (append), pridana 2003-07-08 - nastavi sa v getArgv(); */

	/* kontrola udajov */
	short int result = SUCCESS;

	/* ExportUDAJE definovane pred _main_rozbor_dna */

	/* from */

	/* den */
	if(equals(den_from, STR_EMPTY)){
		ExportUDAJE("ch˝ba ˙daj o poËiatoËnom dni.<br>\n");
	}
	else if(d_from == 0){
		ExportUDAJE("deÚ = <"HTML_SPAN_BOLD">%s</span>.<br>\n", den_from);
	}
	/* mesiac */
	if(equals(mesiac_from, STR_EMPTY)){
		ExportUDAJE("ch˝ba ˙daj o poËiatoËnom mesiaci.<br>\n");
	}
	else if(m_from == UNKNOWN_MESIAC){
		ExportUDAJE("tak˝ mesiac nepozn·m (%s).<br>\n", mesiac_from);
	}
	/* rok */
	if(equals(rok_from, STR_EMPTY)){
		ExportUDAJE("ch˝ba ˙daj o poËiatoËnom roku.<br>\n");
	}
	else if(r_from == 0){
		ExportUDAJE("rok = <"HTML_SPAN_BOLD">%s</span>.<br>\n", rok_from);
	}

	/* to */

	/* den */
	if(equals(den_to, STR_EMPTY)){
		ExportUDAJE("ch˝ba ˙daj o koncovom dni.<br>\n");
	}
	else if(d_to == 0){
		ExportUDAJE("deÚ = <"HTML_SPAN_BOLD">%s</span>.<br>\n", den_to);
	}
	/* mesiac */
	if(equals(mesiac_to, STR_EMPTY)){
		ExportUDAJE("ch˝ba ˙daj o koncovom mesiaci.<br>\n");
	}
	else if(m_to == UNKNOWN_MESIAC){
		ExportUDAJE("tak˝ mesiac nepozn·m (%s).<br>\n", mesiac_to);
	}
	/* rok */
	if(equals(rok_to, STR_EMPTY)){
		ExportUDAJE("ch˝ba ˙daj o koncovom roku.<br>\n");
	}
	else if(r_to == 0){
		ExportUDAJE("rok = <"HTML_SPAN_BOLD">%s</span>.<br>\n", rok_to);
	}

	/* juliansky datum dna _from musi byt <= ako dna _to */
		/* mesiac (int) je 0-11! juliansky_datum() ocakava 1-12 */
	jd_from = JD(d_from, m_from + 1, r_from);
	jd_to = JD(d_to, m_to + 1, r_to);
	if(jd_from > jd_to){
		Log("JD_from = %ld > JD_to = %ld\n", jd_from, jd_to);
		ExportUDAJE("ZlÈ ËasovÈ obdobie (d·tum `od' (%s.%s.%s) nasleduje po d·tume `do' (%s.%s.%s)).<br>\n",
			den_from, mesiac_from, rok_from, den_to, mesiac_to, rok_to);
	}/* datum _to je casovo _pred_ datumom _from! */
	else{
		Log("julianske datumy: v poriadku\n");
	}/* datumy su v spravnom vztahu */

	/* skontrolovat `name_binary_executable',
	 * ktore mame v globalnej premennej,
	 * nie je potrebne (jednoducho to napastujeme do exportu),
	 * name_batch_mode skontrolujeme v dalsom
	 */

	/* udaje su skontrolovane */
	if(result == FAILURE){
		Log("/* teraz result == FAILURE */\n");
		ALERT;
		return;
	}
	else{
		Log("/* teraz result == SUCCESS */\n");
		/* kontrola name_batch_file - ci sa do suboru da zapisovat */
		/* na zapisovanie do batch_file nevyuzivame Export() */
		if(strcmp(name_batch_file, STR_EMPTY) != 0){
			batch_file = fopen(name_batch_file, "wt");
			if(batch_file != NULL){
				Log("File `%s' opened for writing...\n", name_batch_file);
				/* teraz zacina cela sranda :)) ... */

				/* 2004-03-16: vystupny zoznam sa pripadne zapisuje aj ako HTML do suboru 
				 * na zapisovanie do batch_html_file nevyuzivame Export() */
				if(strcmp(name_batch_html_file, STR_EMPTY) == 0)
					mystrcpy(name_batch_html_file, DEFAULT_HTML_EXPORT, MAX_STR);
				batch_html_file = fopen(name_batch_html_file, "wt");
				if(batch_html_file != NULL){
					Log("File `%s' opened for writing...\n", name_batch_html_file);
					hlavicka("Batch mÛd", batch_html_file);
					fprintf(batch_html_file, "\n");
					fprintf(batch_html_file, "<center><h2>Zoznam modlitieb</h2></center>\n");
					fprintf(batch_html_file, "<ul>\n");
	
					LOG_ciara;
					Log("batch mode: teraz zacinam po jednom dni prechadzat cele zadane obdobie...\n");

					/* 2004-03-16: toto su uz minule poznamky o tom, ako to bude (teda je) spravene (2003-07-04)
					 * 1. ak r_from < r_to:
					 *    (i)   od poradie(d_from, m_from, r_from) do poradie(31, MES_DEC, r_from);
					 *    (ii)  pre roky i = (r_from + 1) do (r_to - 1):
					 *          od poradie(1, MES_JAN, i) do poradie(31, MES_DEC, i);
					 *    (iii) pre posledny rok: od poradie(1, MES_JAN, r_to) do poradie(d_to, m_to, r_to);
					 * 2. ak je to r_from == r_to, tak len
					 *    pre poradie(d_from, m_from, r_from) do poradie(d_to, m_to, r_from==r_to)
					 *
					 * co sa tam vlastne bude robit?
					 * 1. analyzuj_rok() daneho roku (r_from, i, r_to) -- ale len 1x!
					 * 2. pre vsetky potrebne dni: rozbor_dna() -- ale printovat to 
					 *    nie Exportom do `export.htm', ale printf(name_batch_file)!
					 * 3. that's all
					 */

					/* 2003-07-08
					 * _global_string vyuzijeme na to, aby sme si medzi jednotlivymi dnami
					 * posielali nazov suboru v pripade, ze chce vsetky modlitby
					 * do 1 suboru (pouzil "-a1" = append)
					 */
					if(_global_opt_append == YES){
						mystrcpy(_global_string, STR_EMPTY, MAX_GLOBAL_STR); /* inicializacia */
						sprintf(_global_string, "%.4d-%.2d-%.2d_%.4d-%.2d-%.2d", 
								r_from, m_from, d_from, r_to, m_to, d_to);
					}

					/* 2003-07-07 
					 * _struct_den_mesiac je typ, ktory vrati _rozbor_dna();
					 * 
					 */
					if(r_from < r_to){
						Log("batch mode: viacero rokov (%d-%d)...\n", r_from, r_to);
						/* analyzujem prvy rok (r_from). potom pre jednotlive dni az do konca roka
						 * robim: _rozbor_dna a _export_rozbor_dna_batch
						 */
						Log("rok %d...\n", r_from);
						analyzuj_rok(r_from);
						for(i = poradie(d_from, m_from + 1, r_from); i <= poradie(31, MES_DEC + 1, r_from); i++){
							Log("%d. den v roku %d...\n", i, r_from);
							/* 2006-02-06: doplnenie nastavenia premenn˝ch kvÙli tomu, ûe v batch mÛde pouûÌvame viackr·t */
							_global_opt3 = MODL_SPOL_CAST_NEURCENA;
							_rozbor_dna(por_den_mesiac(i, r_from), r_from);
							_export_rozbor_dna_batch(EXPORT_DNA_JEDEN_DEN);
						}
						
						/* teraz pre roky (r_from + 1) az (r_to - 1) robim to, co predtym,
						 * cize analyzujem rok a pre vsetky dni - tentokrat pre cele roky, 
						 * od 1.1. do 31.12. - robim _rozbor_dna a _export_rozbor_dna_batch
						 */
						for(short int y = (r_from + 1); y < r_to; y++){
							Log("rok %d...\n", y);
							analyzuj_rok(y);
							for(i = poradie(1, MES_JAN + 1, y); i <= poradie(31, MES_DEC + 1, y); i++){
								Log("%d. den v roku %d...\n", i, y);
								/* 2006-02-06: doplnenie nastavenia premenn˝ch kvÙli tomu, ûe v batch mÛde pouûÌvame viackr·t */
								_global_opt3 = MODL_SPOL_CAST_NEURCENA;
								_rozbor_dna(por_den_mesiac(i, y), y);
								_export_rozbor_dna_batch(EXPORT_DNA_JEDEN_DEN);
							}
							Log("...(rok %d) skoncil.\n", y);
						}

						/* napokon analyzujem posledny rok (r_to). pre jednotlive dni az do 
						 * dna (d_to, m_to) robim: _rozbor_dna a _export_rozbor_dna_batch
						 */
						Log("rok %d...\n", r_to);
						analyzuj_rok(r_to);
						for(i = poradie(1, MES_JAN + 1, r_to); i <= poradie(d_to, m_to + 1, r_to); i++){
							Log("%d. den v roku %d...\n", i, r_to);
							/* 2006-02-06: doplnenie nastavenia premenn˝ch kvÙli tomu, ûe v batch mÛde pouûÌvame viackr·t */
							_global_opt3 = MODL_SPOL_CAST_NEURCENA;
							_rozbor_dna(por_den_mesiac(i, r_to), r_to);
							_export_rozbor_dna_batch(EXPORT_DNA_JEDEN_DEN);
						}
					}/* r_from < r_to */
					else{
						Log("batch mode: vramci jedneho roka (%d)...\n", r_from);
						/* analyzujem ten jeden rok. potom pre jednotlive dni robim:
						 * _rozbor_dna a _export_rozbor_dna_batch
						 */
						analyzuj_rok(r_from);
						for(i = poradie(d_from, m_from + 1, r_from); i <= poradie(d_to, m_to + 1, r_to); i++){
							Log("%d. den v roku %d...\n", i, r_from);
							/* 2006-02-06: doplnenie nastavenia premenn˝ch kvÙli tomu, ûe v batch mÛde pouûÌvame viackr·t */
							_global_opt3 = MODL_SPOL_CAST_NEURCENA;
							_rozbor_dna(por_den_mesiac(i, r_from), r_from);
							_export_rozbor_dna_batch(EXPORT_DNA_JEDEN_DEN);
						}
					}/* r_from == r_to */

					fprintf(batch_html_file, "</ul>\n");
					patka(batch_html_file);
					fclose(batch_html_file);
					Log("batch mode: ...cele zadane obdobie je prejdene.\n");
					LOG_ciara;

				}/* batch_html_file != NULL */
				else{
					Export("NemÙûem pÌsaù do s˙boru `%s'.\n", name_batch_html_file);
					Log("Cannot open file `%s' for writing.\n", name_batch_html_file);
				}/* batch_html_file == NULL) */

				/* ...a sranda skoncila */
				fclose(batch_file);
			}/* ok, batch_file != NULL */
			else{
				Export("NemÙûem pÌsaù do s˙boru `%s'.\n", name_batch_file);
				Log("Cannot open file `%s' for writing.\n", name_batch_file);
			}/* batch_file == NULL */
		}/* name_batch_file != EMPTY_STR */
		else{
			Export("NezadanÈ meno batch s˙boru (pouûite parameter `%s').\n", STR_PRM_BATCH_MODE);
			Log("Batch filename empty (use `%s' parameter).\n", STR_PRM_BATCH_MODE);
		}
	}/* result == SUCCESS */
}/* _main_batch_mode() */

/*---------------------------------------------------------------------*/
/* debugovacia funkcia vypisujuca systemove premenne WWW_ a query
 * v linuxe treba definovat extern char **environ;
 */

extern char **environ;
void write(void){
	short int i = 0;
	while (environ[i]){
//		if(strstr(environ[i], "WWW_") != NULL)
			Log("<p>%d: %s<br><hr>\n", i, environ[i]);
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
short int getQueryTypeFrom_QS(char *qs){
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
	else if(strstr(qs, STR_PRM_BATCH_MODE) != NULL){ /* pridane 2003-07-04, batch mode */
		/* parameter STR_PRM_BATCH_MODE */
		Log("getQueryTypeFrom_QS() -- end, returning PRM_BATCH_MODE\n");
		return PRM_BATCH_MODE;
	}
	else{
		Log("getQueryTypeFrom_QS() -- end, returning PRM_UNKNOWN\n");
		return PRM_UNKNOWN; /* argumenty neobsahuju STR_PRM_... */
	}
}

/*---------------------------------------------------------------------*/
short int getQueryTypeFrom_WWW(void){
	char *ptr;
	short int ret;

	Log("getQueryTypeFrom_WWW() -- begin\n");
	ptr = getenv(ADD_WWW_PREFIX_(STR_QUERY_TYPE)); /* zistim, ci je to z formulara */

	if(ptr == NULL){
		/* nie, dotaz nie je spusteny z formulara */
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_NONE\n");
		ret = PRM_NONE; /* aj bez parametrov WWW_... */
	}
	/* v tomto pripade existuje premenna WWW_QUERY_TYPE */
	else if(equals(ptr, STR_PRM_DATUM)){
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_DATUM\n");
		ret = PRM_DATUM;
	}
	/* toto tu nemusi byt, lebo PRM_DETAILY sa pouziva len pre tlacidlo
	 * 'Detaily...', aby sa dalo odlisit od uvodneho formulara -- kedysi sa
	 * tam miesala modlitba (pole WWW_MODLITBA) z option 'PRM_CEZ_ROK',
	 * ktora sa aplikovala aj na option 'PRM_DATUM'
	 */
	else if(equals(ptr, STR_PRM_DETAILY)){
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_DETAILY\n");
		ret = PRM_DETAILY;
	}
	else if(equals(ptr, STR_PRM_CEZ_ROK)){
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_CEZ_ROK\n");
		ret = PRM_CEZ_ROK;
	}
	else if(equals(ptr, STR_PRM_SVIATOK)){
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_SVIATOK\n");
		ret = PRM_SVIATOK;
	}
	else if(equals(ptr, STR_PRM_ANALYZA_ROKU)){
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_ANALYZA_ROKU\n");
		ret = PRM_ANALYZA_ROKU;
	}
	else if(equals(ptr, STR_PRM_DNES)){
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_DNES\n");
		ret = PRM_DNES;
	}
	else if(equals(ptr, STR_PRM_MESIAC_ROKA)){
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_MESIAC_ROKA\n");
		ret = PRM_MESIAC_ROKA;
	}
	else if(equals(ptr, STR_PRM_TABULKA)){ /* pridane 15/03/2000A.D. */
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_TABULKA\n");
		ret = PRM_TABULKA;
	}
	/* nie je tu PRM_BATCH_MODE, 
	 * pretoze batch mode nie je urceny pre web,
	 * 2003-07-04
	 */
	else{
		Log("getQueryTypeFrom_WWW() -- end, returning PRM_UNKNOWN\n");
		ret = PRM_UNKNOWN; /* failure */
	}
	return ret;
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
short int getArgv(int argc, char **argv){
	short int c;
	
	optind = 0; /* pokial tu toto nebolo, 
				 * tak getopt sa neinicializovala pri dalsich volaniach
				 * 10/04/2000A.D.
				 */

	/* short int digit_optind = 0; */
	char *option_string;
	/* short int this_option_optind; */

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
	 * 2003-07-04: pridane nasledovne parametre:
	 *            `n' (name of binary executable) -> name_binary_executable
	 *            `b' (name of generated batch file, analogia exportu, `e') -> name_batch_file
	 * 2003-07-08: pridany nasledovny parameter:
	 *            `a' (append) aby pri exportovani do suboru (-e) appendoval, nie prepisal subor
	 * 2004-03-16: pridany nasledovny parameter:
	 *            `k' (hyperteKst) aby pri exportovani v batch mode pisal do HTML suboru zoznam modlitieb
	 * 2006-07-12: pridan˝ nasledovn˝ parameter:
	 *            `j' (Jazyk) jazykov· mut·cia, zatiaæ sk, cz
	 *            
	 */
	mystrcpy(option_string, "?q::d::m::r::p::x::s::t::1::2::3::4::5::a::h::e::f::g::l::i::\?::b::n::k::j::", MAX_STR);
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
				case 'j': /* 2006-07-11: PridanÈ kvÙli jazykov˝m mut·ci·m */
					if(optarg != NULL){
						mystrcpy(pom_JAZYK, optarg, SMALL);
					}
					Log("option %c with value `%s' -- `%s' used for language mutation\n", c, optarg, optarg); break;
				case 'k': /* pridane 2004-03-16, name_batch_html_file */
					if(optarg != NULL){
						mystrcpy(name_batch_html_file, optarg, SMALL);
					}
					Log("option %c with value `%s' -- batch file HTML name `%s' used for batch mode\n", c, optarg, optarg); break;
				case 'b': /* pridane 2003-07-04, name_batch_file */
					if(optarg != NULL){
						mystrcpy(name_batch_file, optarg, SMALL);
					}
					Log("option %c with value `%s' -- batch file name `%s' used for batch mode\n", c, optarg, optarg); break;
				case 'n': /* pridane 2003-07-04, name_binary_executable */
					if(optarg != NULL){
						mystrcpy(name_binary_executable, optarg, SMALL);
					}
					Log("option %c with value `%s' -- binary executable name `%s' used for batch mode\n", c, optarg, optarg); break;
				case 'i': /* pridane 05/06/2000A.D., include_dir */
					if(optarg != NULL){
						mystrcpy(include_dir, optarg, SMALL);
					}
					Log("option %c with value `%s' -- including files from `%s'\n", c, optarg, optarg /* 2004-03-17 zapoznamkovane FILE_PATH */); break;
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
			 * ktorezto '1' -- '4' su pre options, vid dalej */
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

				/* nasledovne case'y sa tykaju MODL_OPT... */
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
					/* znamena deviaty parameter */
					if(optarg != NULL){
						mystrcpy(pom_MODL_OPT4, optarg, SMALL);
					}
					Log("option %c with value `%s'\n", c, optarg); break;
				case '5': /* MODL_OPT5 */
					/* znamena desiaty parameter, pridane 2003-08-12 */
					if(optarg != NULL){
						mystrcpy(pom_MODL_OPT5, optarg, SMALL);
					}
					Log("option %c with value `%s'\n", c, optarg); break;

				/* append pridany 2003-07-08, bude v _global_opt_append */
				case 'a': /* MODL_OPT_APPEND */
					/* znamena ? parameter */
					if(optarg != NULL){
						mystrcpy(pom_MODL_OPT_APPEND, optarg, SMALL);
					}
					/* option a (append), pridana 2003-07-08 */
					if(equals(pom_MODL_OPT_APPEND, STR_ANO) || equals(pom_MODL_OPT_APPEND, "1")){
						_global_opt_append = ANO;
					}
					else if(equals(pom_MODL_OPT_APPEND, STR_NIE) || equals(pom_MODL_OPT4, "0")){
						_global_opt_append = NIE;
					}/* inak ostane _global_opt_APPEND default */
					Log("opt_append == `%s' (%d)\n", pom_MODL_OPT_APPEND, _global_opt_append);
					Log("option %c with value `%s'\n", c, optarg); break;

				case 'q': /* QUERY_TYPE */
					if(optarg != NULL){
						mystrcpy(pom_QUERY_TYPE, optarg, MAX_POM_QUERY_TYPE);
					}
					Log("option %c with value `%s'\n", c, optarg); break;

				case '?': /* pridany 05/06/2000A.D., oprava 07/09/2001A.D. */
				case 'h':

					/* opravene 07/09/2001A.D. - pridane niektore switche */
					/* 2003-06-26 -- pridane -s (query string), -q psqs */
					printf("\n");
					printf("lh - command-line verzia on-line breviara (http://www.breviar.sk)\n");
					/* pridane 2003-07-17 */
					printf("\tProgram vytvara stranky (HTML vystup) pre Liturgiu hodin.\n");
					/* build pridany 2003-07-04 */
					printf("\tBuild: %s\n", BUILD_DATE);
					printf("\t(c) 1999-2006 Juraj VidÈky <videky@breviar.sk>\n");
					printf("\n");
					printf("\npouzitie:\n");
					printf("\tlh [prepinac [hodnota]...]\n");
					printf("\nprepinace:\n");
					printf("\tq  query type (napr. %s, %s, %s, %s, %s, %s...)\n",
						STR_PRM_DNES, STR_PRM_DATUM, STR_PRM_DETAILY, STR_PRM_TABULKA, STR_PRM_SIMULACIA_QS, STR_PRM_BATCH_MODE);
					printf("\ts  query string (tak ako je na webe)\n");
					printf("\td  den  %s, %s (1--31, po--ne)\n", STR_DEN, STR_DEN_V_TYZDNI);
					/* printf("\ts  SVIATOK \n"); */
					printf("\tm  mesiac  %s (1--12, jan--dec)\n", STR_MESIAC);
					printf("\tt  tyzden zaltara (1--4) \n");
					printf("\tr  rok (napr. 2000)\n");
					printf("\tp  %s (modlitba: %s, %s, %s, %s, %s, %s, %s...) \n", 
						STR_MODLITBA, STR_MODL_RANNE_CHVALY, STR_MODL_VESPERY, STR_MODL_POSV_CITANIE, STR_MODL_PREDPOLUDNIM, STR_MODL_NAPOLUDNIE, STR_MODL_POPOLUDNI, STR_MODL_DETAILY);
					printf("\t\t (resp. rok do pre davkove spracovanie)\n"); /* pridane 2003-07-07 */
					printf("\tx  %s (dalsi svaty, 1--3 resp. 4) \n", STR_DALSI_SVATY);
					/* 2004-03-11, zlepseny popis */
					printf("\t1  ci zobrazit nemenne casti modlitby (default 0) \n");
					printf("\t   pri rozbore mesiaca: ci vypisovat vsetko do 1 riadka (default 0)\n"); /* upravene 2005-03-22 */
					printf("\t2  ci brat zalmy zo dna (0) alebo z vlastnej casti (1) \n");
					printf("\t   pri rozbore mesiaca: ci datum zobrazit v ISO-8601 standarde \n");
					printf("\t   (napr. 2005-03-22) (1) alebo jednoducho ako cislo (0, default) \n"); /* upravene 2005-03-22 a zasa 2006-01-25 */
					printf("\t3  ktoru spolocnu cast brat, ak je ich viac (0, 1, 2, 3) \n");
					printf("\t4  ci zobrazit popis k modlitbe (strucny zivotopis, default 1) \n");
					printf("\tf  rok from (resp. den do pre davkove spracovanie)\n");
					printf("\tg  rok to (resp. mesiac do pre davkove spracovanie)\n");
					printf("\tl  ci zobrazovat linky \n");
					printf("\te  export filename (default: export.htm)\n");
					printf("\ti  include folder\n");
					/* pridane 2003-07-07 */
					printf("\tb  batch mode (davkove spracovanie), nazov vystupneho davkoveho suboru\n");
					printf("\tn  nazov binarky (tohto suboru, napr. lh.exe) pre batch mode\n");
					printf("\tk  nazov (HTML) suboru pre vysledny zoznam modlitieb, batch mode\n");
					printf("\th, ?  tento help \n");
					/* pridane 2003-07-08 */
					printf("\ta  (append) pri exportovani do suboru (-e) neprepisuje subor\n");
					/* pridanÈ 2006-07-12 */
					printf("\tj  jazyk (jazykova mutacia), zatial: sk, cz\n");

					/* pridane 2003-06-27; prave prva uvedena linka sposobuje problem (nefunguju detaily pre spomienku pm v sobotu) */
					printf("\n\t   pri prepinacoch ano = 1, nie = 0\n");
					printf("\npriklady pouzitia:\n");
					printf("\tlh.exe -i..\\..\\..\\ -qpsqs -s\"qt=pdt&d=12&m=7&r=2003\"\n");
					printf("\tlh -qpdt -d30 -m4 -r2002 -pmrch -ic:\\temp\\breviar\\ -emoja.htm\n");
					printf("\tlh.exe -i..\\..\\..\\ -d28 -m6 -r2003 -qpdt -pmrch -x1\n");
					/* pridane 2003-07-07 */
					printf("\tlh -qpbm -d1 -m1 -r2000 -f2 -g2 -p2000 -ba.bat -nlh.exe -ic:\\breviar\\\n");
					/* pridane 2003-07-17 */
					printf("\nviac informacii:\n");
					printf("\thttp://www.breviar.sk - hlavna stranka\n");
					printf("\thttp://breviar.christ-net.sk - alternativna lokacia stranok (mirror)\n");
					printf("\thttp://www.breviar.sk/info/parametre.htm - o parametroch\n");
					printf("\thttp://www.breviar.sk/info/batchmode.htm - o davkovom mode (batch mode)\n");

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
		if(equals(pom_QUERY_TYPE, STR_EMPTY)){
			/* zmenene <b> na <span class="bold">, 2003-07-02 */
			mystrcpy(bad_param_str, "<"HTML_SPAN_BOLD">nijak˝ parameter PRM_...</span>", MAX_STR);
		}
		else{
			/* zmenene <b> na <span class="bold">, 2003-07-02 */
			mystrcpy(bad_param_str, pom_QUERY_TYPE, MAX_STR);
			strcat(bad_param_str, " (switch <"HTML_SPAN_BOLD">-q</span>)");
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
 *
 * 2005-03-30: Upravene. 
 * Ak hodnoty su v pom_ premennych, nepotrebujem citat z WWW_ premennych.
 * V opacnom pripade to na linux::apache vypisovalo pre tlacidla (Dalsi den >>)
 * ze nie su vytvorene premenne WWW_d a podobne, hoci boli v query stringu.
 * Mozno je to cele nejak dosachovane tym, ze som preniesol uncgi sem do kodu.
 * Ale hlavne ze to chodi :))
 *
 */
short int getForm(void){
	char *ptr;

	Log("getForm() -- begin\n");
	//DEBUG_GET_FORM("argc == %d\n", argc);

	/* malo by byt argc == 1 */

	/* premenn· WWW_JAZYK pridan· 2006-07-11 kvÙli jazykov˝m mut·ci·m */
	ptr = getenv(ADD_WWW_PREFIX_(STR_JAZYK));
	/* ak nie je vytvorena, ak t.j. ptr == NULL, tak nas to netrapi,
	 * lebo pom_... su inicializovane na STR_EMPTY */
	if(ptr != NULL){
		if(strcmp(ptr, EMPTY_STR) != 0)
			mystrcpy(pom_JAZYK, ptr, SMALL);
	}

	if((query_type == PRM_DATUM) || (query_type == PRM_DETAILY)){
		/* datum: treba nacitat den, mesiac a rok */

		/* premenna WWW_DEN */
		/* ak je naplnena pom_DEN, znamena to, ze uz bola naplnena, preto nemusi existovat */
		if(equals(pom_DEN, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_DEN));
			if(ptr == NULL){
				Export("Nebola vytvoren· systÈmov· premenn· %s.\n", ADD_WWW_PREFIX_(STR_DEN));
				ALERT;
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_DEN));
				return FAILURE; /* failure */
			}
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_DEN, ptr, SMALL);
		}
		else{
			Log("Premenn· pom_DEN je uû naplnen· (%s). NeËÌtam z %s...\n", pom_DEN, ADD_WWW_PREFIX_(STR_DEN));
		}

		/* premenna WWW_MESIAC */
		/* ak je naplnena pom_MESIAC, znamena to, ze uz bola naplnena, preto nemusi existovat */
		if(equals(pom_MESIAC, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_MESIAC));
			if(ptr == NULL){
				Export("Nebola vytvoren· systÈmov· premenn· %s.\n", ADD_WWW_PREFIX_(STR_MESIAC));
				ALERT;
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_MESIAC));
				return FAILURE; /* failure */
			}
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_MESIAC, ptr, SMALL);
		}
		else{
			Log("Premenn· pom_MESIAC je uû naplnen· (%s). NeËÌtam z %s...\n", pom_MESIAC, ADD_WWW_PREFIX_(STR_MESIAC));
		}

		/* premenna WWW_ROK */
		/* ak je naplnena pom_ROK, znamena to, ze uz bola naplnena, preto nemusi existovat */
		if(equals(pom_ROK, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_ROK));
			if(ptr == NULL){
				Export("Nebola vytvoren· systÈmov· premenn· %s.\n", ADD_WWW_PREFIX_(STR_ROK));
				ALERT;
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_ROK));
				return FAILURE; /* failure */
			}
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_ROK, ptr, SMALL);
		}
		else{
			Log("Premenn· pom_ROK je uû naplnen· (%s). NeËÌtam z %s...\n", pom_ROK, ADD_WWW_PREFIX_(STR_ROK));
		}

		/* nasledujuce sa zistuju kvoli 'Detaily...', formular vytvorila
		 * funckia showDetails();
		 * v normalnom formulari (vytvori ho _main_dnes();) nie su */

		/* premenna WWW_MODLITBA */
		ptr = getenv(ADD_WWW_PREFIX_(STR_MODLITBA));
		/* ak nie je vytvorena, ak t.j. ptr == NULL, tak nas to netrapi,
		 * lebo pom_... su inicializovane na STR_EMPTY */
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
		ptr = getenv(ADD_WWW_PREFIX_(STR_MESIAC_ROKA));
		if(ptr != NULL){ /* povodne if(query_type == PRM_DATUM) */
			/* nie je NULL, ide teda o prvy vstupny formular */
			mystrcpy(pom_MODLITBA, STR_EMPTY, SMALL);
		}

		/* premenna WWW_DALSI_SVATY */
		ptr = getenv(ADD_WWW_PREFIX_(STR_DALSI_SVATY));
		/* ak nie je vytvorena, ak t.j. ptr == NULL, tak nas to netrapi,
		 * lebo pom_... su inicializovane na STR_EMPTY */
		if(ptr != NULL){
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_DALSI_SVATY, ptr, SMALL);
		}

		/* premenna WWW_MODL_OPT1 */
		ptr = getenv(ADD_WWW_PREFIX_(STR_MODL_OPT1));
		/* ak nie je vytvorena, ak t.j. ptr == NULL, tak nas to netrapi,
		 * lebo pom_... su inicializovane na STR_EMPTY */
		if(ptr != NULL){
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_MODL_OPT1, ptr, SMALL);
		}

		/* premenna WWW_MODL_OPT2 */
		ptr = getenv(ADD_WWW_PREFIX_(STR_MODL_OPT2));
		/* ak nie je vytvorena, ak t.j. ptr == NULL, tak nas to netrapi,
		 * lebo pom_... su inicializovane na STR_EMPTY */
		if(ptr != NULL){
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_MODL_OPT2, ptr, SMALL);
		}

		/* premenna WWW_MODL_OPT3 */
		ptr = getenv(ADD_WWW_PREFIX_(STR_MODL_OPT3));
		/* ak nie je vytvorena, ak t.j. ptr == NULL, tak nas to netrapi,
		 * lebo pom_... su inicializovane na STR_EMPTY */
		if(ptr != NULL){
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_MODL_OPT3, ptr, SMALL);
		}

		/* premenna WWW_MODL_OPT4 */
		ptr = getenv(ADD_WWW_PREFIX_(STR_MODL_OPT4));
		/* ak nie je vytvorena, ak t.j. ptr == NULL, tak nas to netrapi,
		 * lebo pom_... su inicializovane na STR_EMPTY */
		if(ptr != NULL){
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_MODL_OPT4, ptr, SMALL);
		}

		/* premenna WWW_MODL_OPT5, pridana 2003-08-13 */
		ptr = getenv(ADD_WWW_PREFIX_(STR_MODL_OPT5));
		/* ak nie je vytvorena, ak t.j. ptr == NULL, tak nas to netrapi,
		 * lebo pom_... su inicializovane na STR_EMPTY */
		if(ptr != NULL){
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_MODL_OPT5, ptr, SMALL);
		}
	}/* (query_type == PRM_DATUM) || (query_type == PRM_DETAILY) */

	else if(query_type == PRM_CEZ_ROK){
		/* cez rok: treba nacitat den v tyzdni a cislo tyzdna */

		/* premenna WWW_DEN_V_TYZDNI */
		/* ak je naplnena pom_DEN_V_TYZDNI, znamena to, ze uz bola naplnena, preto nemusi existovat */
		if(equals(pom_DEN_V_TYZDNI, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_DEN_V_TYZDNI));
			if(ptr == NULL){
				Export("Nebola vytvoren· systÈmov· premenn· %s.\n", ADD_WWW_PREFIX_(STR_DEN_V_TYZDNI));
				ALERT;
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_DEN_V_TYZDNI));
				return FAILURE; /* failure */
			}
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_DEN_V_TYZDNI, ptr, SMALL);
		}
		else{
			Log("Premenn· pom_DEN_V_TYZDNI je uû naplnen· (%s). NeËÌtam z %s...\n", pom_DEN_V_TYZDNI, ADD_WWW_PREFIX_(STR_DEN_V_TYZDNI));
		}

		/* premenna WWW_TYZDEN */
		/* ak je naplnena pom_TYZDEN, znamena to, ze uz bola naplnena, preto nemusi existovat */
		if(equals(pom_TYZDEN, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_TYZDEN));
			if(ptr == NULL){
				Export("Nebola vytvoren· systÈmov· premenn· %s.\n", ADD_WWW_PREFIX_(STR_TYZDEN));
				ALERT;
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_TYZDEN));
				return FAILURE; /* failure */
			}
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_TYZDEN, ptr, SMALL);
		}
		else{
			Log("Premenn· pom_TYZDEN je uû naplnen· (%s). NeËÌtam z %s...\n", pom_TYZDEN, ADD_WWW_PREFIX_(STR_TYZDEN));
		}

		/* premenna WWW_MODLITBA */
		/* ak je naplnena pom_MODLITBA, znamena to, ze uz bola naplnena, preto nemusi existovat */
		if(equals(pom_MODLITBA, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_MODLITBA));
			if(ptr == NULL){
				Export("Nebola vytvoren· systÈmov· premenn· %s.\n", ADD_WWW_PREFIX_(STR_MODLITBA));
				ALERT;
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_MODLITBA));
				return FAILURE; /* failure */
			}
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_MODLITBA, ptr, SMALL);
		}
		else{
			Log("Premenn· pom_MODLITBA je uû naplnen· (%s). NeËÌtam z %s...\n", pom_MODLITBA, ADD_WWW_PREFIX_(STR_MODLITBA));
		}

	}/* query_type == PRM_CEZ_ROK */

	else if(query_type == PRM_SVIATOK){
		/* cez rok: treba nacitat nazov sviatku */

		/* premenna WWW_NAZOV_SVIATOK */
		/* ak je naplnena pom_SVIATOK, znamena to, ze uz bola naplnena, preto nemusi existovat */
		if(equals(pom_SVIATOK, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_NAZOV_SVIATOK));
			if(ptr == NULL){
				Export("Nebola vytvoren· systÈmov· premenn· %s.\n", ADD_WWW_PREFIX_(STR_NAZOV_SVIATOK));
				ALERT;
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_NAZOV_SVIATOK));
				return FAILURE; /* failure */
			}
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_SVIATOK, ptr, SMALL);
		}
		else{
			Log("Premenn· pom_SVIATOK je uû naplnen· (%s). NeËÌtam z %s...\n", pom_SVIATOK, ADD_WWW_PREFIX_(STR_NAZOV_SVIATOK));
		}

	}/* query_type == PRM_SVIATOK */

	else if(query_type == PRM_ANALYZA_ROKU){
		/* cez rok: treba nacitat nazov sviatku */

		/* premenna WWW_ANALYZA_ROKU */
		/* ak je naplnena pom_ANALYZA_ROKU, znamena to, ze uz bola naplnena, preto nemusi existovat */
		if(equals(pom_ANALYZA_ROKU, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_ANALYZA_ROKU));
			if(ptr == NULL){
				Export("Nebola vytvoren· systÈmov· premenn· %s.\n",
					ADD_WWW_PREFIX_(STR_ANALYZA_ROKU));
				ALERT;
				DEBUG_GET_FORM("%s neexistuje.\n",
					ADD_WWW_PREFIX_(STR_ANALYZA_ROKU));
				return FAILURE; /* failure */
			}
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_ANALYZA_ROKU, ptr, SMALL);
		}
		else{
			Log("Premenn· pom_ANALYZA_ROKU je uû naplnen· (%s). NeËÌtam z %s...\n", pom_ANALYZA_ROKU, ADD_WWW_PREFIX_(STR_ANALYZA_ROKU));
		}

	}/* query_type == PRM_ANALYZA_ROKU */

	else if(query_type == PRM_MESIAC_ROKA){
		/* 2005-03-21: novy typ exportu liturgickeho kalendara: 
		 * ak je hodnota premennej option "1" = 0 (default), tak klasicky pre web,
		 * inak rozlicny sposob vystupu ("1" = 1 pre www.kbs.sk liturgicky kalendar)
		 * 2005-03-22: novy typ exportu liturgickeho kalendara: 
		 * ak je hodnota premennej option "2" = 1 (default), tak datum ako ISO-8601,
		 * inak len datum */

		/* premenna WWW_MODL_OPT1 */
		ptr = getenv(ADD_WWW_PREFIX_(STR_MODL_OPT1));
		/* ak nie je vytvorena, ak t.j. ptr == NULL, tak nas to netrapi,
		 * lebo pom_... su inicializovane na STR_EMPTY */
		if(ptr != NULL){
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_MODL_OPT1, ptr, SMALL);
		}

		/* premenna WWW_MODL_OPT2 */
		ptr = getenv(ADD_WWW_PREFIX_(STR_MODL_OPT2));
		/* ak nie je vytvorena, ak t.j. ptr == NULL, tak nas to netrapi,
		 * lebo pom_... su inicializovane na STR_EMPTY */
		if(ptr != NULL){
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_MODL_OPT2, ptr, SMALL);
		}

		/* treba nacitat mesiac a rok */
		/* premenna WWW_MESIAC_ROKA */
		/* ak je naplnena pom_MESIAC (vynimocne nie pom_MESIAC_ROKA), znamena to, ze uz bola naplnena, preto nemusi existovat */
		if(equals(pom_MESIAC, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_MESIAC_ROKA));
			if(ptr == NULL){
				Export("Nebola vytvoren· systÈmov· premenn· %s.\n", ADD_WWW_PREFIX_(STR_MESIAC_ROKA));
				ALERT;
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_MESIAC_ROKA));
				return FAILURE; /* failure */
			}
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_MESIAC, ptr, SMALL);
		}
		else{
			Log("Premenn· pom_MESIAC je uû naplnen· (%s). NeËÌtam z %s...\n", pom_MESIAC, ADD_WWW_PREFIX_(STR_MESIAC_ROKA));
		}

		/* premenna WWW_ROK */
		/* ak je naplnena pom_ROK (vynimocne nie pom_ROK_ROKA), znamena to, ze uz bola naplnena, preto nemusi existovat */
		if(equals(pom_ROK, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_ROK_ROKA));
			if(ptr == NULL){
				Export("Nebola vytvoren· systÈmov· premenn· %s.\n", ADD_WWW_PREFIX_(STR_ROK_ROKA));
				ALERT;
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_ROK_ROKA));
				return FAILURE; /* failure */
			}
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_ROK, ptr, SMALL);
		}
		else{
			Log("Premenn· pom_ROK je uû naplnen· (%s). NeËÌtam z %s...\n", pom_ROK, ADD_WWW_PREFIX_(STR_ROK_ROKA));
		}

	}/* query_type == PRM_MESIAC_ROKA */

	else if(query_type == PRM_TABULKA){
		/* PRM_TABULKA: treba nacitat from a to; ak chyba linka, tak automaticky == NIE */

		/* premenna WWW_ROK_FROM */
		/* ak je naplnena pom_ROK_FROM, znamena to, ze uz bola naplnena, preto nemusi existovat */
		if(equals(pom_ROK_FROM, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_ROK_FROM));
			if(ptr == NULL){
				Export("Nebola vytvoren· systÈmov· premenn· %s.\n", ADD_WWW_PREFIX_(STR_ROK_FROM));
				ALERT;
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_ROK_FROM));
				return FAILURE; /* failure */
			}
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_ROK_FROM, ptr, SMALL);
		}
		else{
			Log("Premenn· pom_ROK_FROM je uû naplnen· (%s). NeËÌtam z %s...\n", pom_ROK_FROM, ADD_WWW_PREFIX_(STR_ROK_FROM));
		}

		/* premenna WWW_ROK_TO */
		/* ak je naplnena pom_ROK_TO, znamena to, ze uz bola naplnena, preto nemusi existovat */
		/* 2005-05-24 Opravena copy-paste chyba: bolo mylne if(equals(pom_ROK_FROM, STR_EMPTY)) */
		if(equals(pom_ROK_TO, STR_EMPTY)){
			ptr = getenv(ADD_WWW_PREFIX_(STR_ROK_TO));
			if(ptr == NULL){
				Export("Nebola vytvoren· systÈmov· premenn· %s.\n", ADD_WWW_PREFIX_(STR_ROK_TO));
				ALERT;
				DEBUG_GET_FORM("%s neexistuje.\n", ADD_WWW_PREFIX_(STR_ROK_TO));
				return FAILURE; /* failure */
			}
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_ROK_TO, ptr, SMALL);
		}
		else{
			Log("Premenn· pom_ROK_TO je uû naplnen· (%s). NeËÌtam z %s...\n", pom_ROK_TO, ADD_WWW_PREFIX_(STR_ROK_TO));
		}

		/* premenna WWW_TABULKA_LINKY */
		ptr = getenv(ADD_WWW_PREFIX_(STR_TABULKA_LINKY));
		/* ak nie je vytvorena, ak t.j. ptr == NULL, tak nas to netrapi,
		 * lebo pom_... su inicializovane na STR_EMPTY */
		if(ptr != NULL){
			if(strcmp(ptr, EMPTY_STR) != 0)
				mystrcpy(pom_LINKY, ptr, SMALL);
		}
	}/* query_type == PRM_TABULKA */

	else if(query_type == PRM_DNES){
		/* 2005-03-28: Pridane, aby nevracalo FAILURE. */
		Log("getForm() -- nie je potrebne nic nacitavat :)) \n");
	}

	else{
		Log("getForm() -- end, returning FAILURE\n");
		/* neznamy typ dotazu */
		return FAILURE;
	}
	Log("getForm() -- end, returning SUCCESS\n");
	return SUCCESS;
}/* getForm(); */

/*---------------------------------------------------------------------*/
/* popis: naplni premenne pom_... hodnotami z environmentu, t.j.
 *        premennymi zo stringu QUERY_STRING (systemova premenna)
 *        napriklad retazec "QUERY_TYPE=PRM_DATUM&DEN=7&MESIAC=5&ROK=1976"
 * vracia: on success, returns SUCCESS
 *         on error,   returns FAILURE
 * historia: 
 *        2005-03-22 Upravene, 
 *        natvrdo sa predpokladalo urcite poradie parametrov.
 *        Umoznujeme aj odlisne poradie (prip. vynechanie niektorych parametrov) 
 *        v query stringu.
 *
 */
short int parseQueryString(void){
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

	short int i, pocet, ok;

	Log("parseQueryString() -- begin\n");
	if(query_string != NULL)
		Log("query_string == %s, lenght == %d\n", query_string, strlen(query_string));
	else
		Log("query_string is NULL, something is wrong...\n");

	/* get parameters */
	i = 0;
	while((strlen(query_string) > 0) && (i < MAX_VARIABLES)){ /* 2006-08-01: doplnen· podmienka, aby nepretieklo napÂÚanie premenn˝ch, ak je ich viac */
		mystrcpy(param[i].name, STR_EMPTY, MAX_NAME_CGI_UTILS);
		mystrcpy(param[i].val, STR_EMPTY, MAX_VAL_CGI_UTILS);
		splitword(param[i].val, query_string, '&');
		unescape_url(param[i].val);
		splitword(param[i].name, param[i].val, '=');
		Log("--- param[%d].name == %s, .val == %s\n", i, param[i].name, param[i].val);
		i++;
	}
	pocet = i; /* od 0 po i - 1 */

	/* 2006-08-01: doplnen· podmienka, aby nepretieklo napÂÚanie premenn˝ch, ak je ich viac */
	if((strlen(query_string) > 0) && (pocet >= MAX_VARIABLES)){
		Export("Program nedok·ûe obsl˙ûiù viac parametrov (maximum: %d). OstatnÈ bud˙ ignorovanÈ.\n", MAX_VARIABLES);
		ALERT;
	}

	/* 2006-07-12: pridanÈ kvÙli jazykov˝m mut·ci·m */
	i = 0; /* param[0] by mal sÌce obsahovaù typ akcie, ale radöej kontrolujeme od 0 */
	Log("pok˙öam sa zistiù jazyk...\n");
	while((equalsi(pom_JAZYK, STR_EMPTY)) && (i < pocet)){
		Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
		if(equals(param[i].name, STR_JAZYK)){
			/* ide o parameter STR_JAZYK */
			mystrcpy(pom_JAZYK, param[i].val, SMALL);
			Log("jazyk zisten˝.\n");
		}
		i++;
	}

	/* 2006-08-01: pÙvodne sme predpokladali, ûe param[0] by mal obsahovaù typ akcie; 
	 * odteraz ho hæad·me v celom zozname parametrov */
	ok = NIE;
	query_type = PRM_UNKNOWN;
	i = 0; /* od param[0] */
	Log("pok˙öam sa zistiù query type...\n");
	while((ok != ANO) && (i < pocet)){
		Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
		if(equals(param[i].name, STR_QUERY_TYPE)){ /* zistÌme typ akcie, lebo sa jedn· o dobr˝ parameter */
			if(equals(param[i].val, STR_PRM_DATUM)){
				/* ide o parameter STR_PRM_DATUM */
				query_type = PRM_DATUM;
			}
			else if(equals(param[i].val, STR_PRM_DETAILY)){
				/* ide o parameter STR_PRM_DETAILY*/
				/* pridany 09/02/2000A.D. ako alternativa k PRM_DATUM */
				query_type = PRM_DETAILY;
			}
			else if(equals(param[i].val, STR_PRM_CEZ_ROK)){
				/* ide o parameter STR_PRM_CEZ_ROK */
				query_type = PRM_CEZ_ROK;
			}
			else if(equals(param[i].val, STR_PRM_SVIATOK)){
				/* ide o parameter STR_PRM_SVIATOK */
				query_type = PRM_SVIATOK;
			}
			else if(equals(param[i].val, STR_PRM_DNES)){
				/* ide o parameter STR_PRM_DNES */
				query_type = PRM_DNES;
			}
			else if(equals(param[i].val, STR_PRM_ANALYZA_ROKU)){
				/* ide o parameter STR_PRM_ANALYZA_ROKU */
				query_type = PRM_ANALYZA_ROKU;
			}
			else if(equals(param[i].val, STR_PRM_MESIAC_ROKA)){
				/* ide o parameter STR_PRM_MESIAC_ROKA */
				query_type = PRM_MESIAC_ROKA;
			}
			else if(equals(param[i].val, STR_PRM_TABULKA)){
				/* ide o parameter STR_PRM_TABULKA */
				query_type = PRM_TABULKA;
			}
			else{
				/* n·zov parametra je OK, ale neurËuje ûiadnu spr·vnu akciu */
				Export("Chybn· hodnota parametra %s: %s\n",
					param[i].name, param[i].val);
				query_type = PRM_UNKNOWN; /* pridane 24/02/2000A.D. */
			}
			Log("query type parameter prÌtomn˝ (%s), hodnota zisten· (%s).\n", param[i].name, param[i].val);
		}/* if(equals(param[i].name, STR_QUERY_TYPE)) */
		if(query_type != PRM_UNKNOWN)
			ok = ANO;
		i++;
	}

	if(ok != ANO){
		/* ani jeden z parametrov neobsahuje query type alebo obsahuje nezn·my qt */
		if(i >= pocet)
			Export("Ch˝baj˙ci parameter pre query type.\n");
		else /* sÌce bol query type parameter, ale hodnota je chybn· */
			Export("Chybn˝ parameter: %s\n", param[i - 1].name);
		ALERT;
		return FAILURE;
	}

	Log("\tswitch(query_type)...\n");
	switch(query_type){
		case PRM_DNES:{
			/* 2006-02-10: doplnenÈ kvÙli tomu, aby aj pre PRM_DNES mohla byù modlitba resp. sv‰tec */
			Log("\tcase PRM_DNES...\n");
			/* nasleduj˙ca pas·û prevzat· a upraven· podæa PRM_DATUM; op‰tovne 2006-08-01 */

			/* premenn· MODLITBA (nepovinn·)
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_MODLITBA);
			while((equalsi(pom_MODLITBA, STR_EMPTY)) && (i < pocet)){
				// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_MODLITBA)){
					/* ide o parameter STR_MODLITBA */
					mystrcpy(pom_MODLITBA, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_MODLITBA, pom_MODLITBA);
				}
				i++;
			}
			if(equalsi(pom_MODLITBA, STR_EMPTY)){
				Log("Nebola zadan· premenn· %s (nevadÌ).\n", STR_MODLITBA);
			}

			/* premenn· DALSI_SVATY (nepovinn·)
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_DALSI_SVATY);
			while((equalsi(pom_DALSI_SVATY, STR_EMPTY)) && (i < pocet)){
				// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_DALSI_SVATY)){
					/* ide o parameter STR_DALSI_SVATY */
					mystrcpy(pom_DALSI_SVATY, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_DALSI_SVATY, pom_DALSI_SVATY);
				}
				i++;
			}
			if(equalsi(pom_DALSI_SVATY, STR_EMPTY)){
				Log("Nebola zadan· premenn· %s (nevadÌ).\n", STR_DALSI_SVATY);
			}
			
			/* premenn· MODL_OPT1 (nepovinn·)
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_MODL_OPT1);
			while((equalsi(pom_MODL_OPT1, STR_EMPTY)) && (i < pocet)){
				// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_MODL_OPT1)){
					/* ide o parameter STR_MODL_OPT1 */
					mystrcpy(pom_MODL_OPT1, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_MODL_OPT1, pom_MODL_OPT1);
				}
				i++;
			}
			if(equalsi(pom_MODL_OPT1, STR_EMPTY)){
				Log("Nebola zadan· premenn· %s (nevadÌ).\n", STR_MODL_OPT1);
			}
			
			/* premenn· MODL_OPT2 (nepovinn·)
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_MODL_OPT2);
			while((equalsi(pom_MODL_OPT2, STR_EMPTY)) && (i < pocet)){
				// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_MODL_OPT2)){
					/* ide o parameter STR_MODL_OPT2 */
					mystrcpy(pom_MODL_OPT2, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_MODL_OPT2, pom_MODL_OPT2);
				}
				i++;
			}
			if(equalsi(pom_MODL_OPT2, STR_EMPTY)){
				Log("Nebola zadan· premenn· %s (nevadÌ).\n", STR_MODL_OPT2);
			}
			
			/* premenn· MODL_OPT3 (nepovinn·)
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_MODL_OPT3);
			while((equalsi(pom_MODL_OPT3, STR_EMPTY)) && (i < pocet)){
				// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_MODL_OPT3)){
					/* ide o parameter STR_MODL_OPT3 */
					mystrcpy(pom_MODL_OPT3, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_MODL_OPT3, pom_MODL_OPT3);
				}
				i++;
			}
			if(equalsi(pom_MODL_OPT3, STR_EMPTY)){
				Log("Nebola zadan· premenn· %s (nevadÌ).\n", STR_MODL_OPT3);
			}
			
			/* premenn· MODL_OPT4 (nepovinn·)
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_MODL_OPT4);
			while((equalsi(pom_MODL_OPT4, STR_EMPTY)) && (i < pocet)){
				// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_MODL_OPT4)){
					/* ide o parameter STR_MODL_OPT4 */
					mystrcpy(pom_MODL_OPT4, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_MODL_OPT4, pom_MODL_OPT4);
				}
				i++;
			}
			if(equalsi(pom_MODL_OPT4, STR_EMPTY)){
				Log("Nebola zadan· premenn· %s (nevadÌ).\n", STR_MODL_OPT4);
			}

			break; /* case */
		}
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
		 * ----------------------------------------------
		 * 2005-03-22: pridane dalsie vyznamy opt1 a opt2
		 * ----------------------------------------------
		 * 0: [query type]
		 * 1: den          / rok from
		 * 2: mesiac       / rok to
		 * 3: rok          / (linky) -- tieto tri `alternativne' parametre pre typ dotazu case PRM_TABULKA:, vid nizsie
		 * 4: (modlitba)
		 * 5: (dalsi svaty) - poradie svateho
		 * 6: (opt1) - pri modlitbe: ci zobrazit Benediktus/Magnifikat, Otcenas, zakoncenie
		 *             pri liturgickom kalendari: ci generovat standardny alebo skrateny tvar
		 * 7: (opt2) - pri modlitbe: ci brat (pri sviatkoch svatych) zalmy zo dna / zo sviatku
		 *             pri liturgickom kalendari: ci datum zobrazit len ako cislo (default) alebo ISO-8601 (napr. 2005-03-22)
		 * 8: (opt3) - ktoru `spolocnu cast' (pri sviatkoch svatych) brat
		 * 9: (opt4) - for future use
		 * ---------------------------------------------
		 * 2006-02-10: pridanÈ moûnosti vymenenÈho poradia a nezadania niektor˝ch options
		 * ----------------------------------------------
		 * na z·klade dodania case-u pre PRM_DNES
		 * 
		 * ---------------------------------------------
		 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov
		 * ----------------------------------------------
		 * 
		 */

			/* premenn· DEN 
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_DEN);
			while((equalsi(pom_DEN, STR_EMPTY)) && (i < pocet)){
				// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_DEN)){
					/* ide o parameter STR_DEN */
					mystrcpy(pom_DEN, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_DEN, pom_DEN);
				}
				i++;
			}
			if(equalsi(pom_DEN, STR_EMPTY)){
				Export("Nebola zadan· premenn· %s.\n", STR_DEN);
				ALERT;
				return FAILURE; /* failure */
			}

			/* premenn· MESIAC 
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_MESIAC);
			while((equalsi(pom_MESIAC, STR_EMPTY)) && (i < pocet)){
				// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_MESIAC)){
					/* ide o parameter STR_MESIAC */
					mystrcpy(pom_MESIAC, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_MESIAC, pom_MESIAC);
				}
				i++;
			}
			if(equalsi(pom_MESIAC, STR_EMPTY)){
				Export("Nebola zadan· premenn· %s.\n", STR_MESIAC);
				ALERT;
				return FAILURE; /* failure */
			}

			/* premenn· ROK 
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_ROK);
			while((equalsi(pom_ROK, STR_EMPTY)) && (i < pocet)){
				// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_ROK)){
					/* ide o parameter STR_ROK */
					mystrcpy(pom_ROK, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_ROK, pom_ROK);
				}
				i++;
			}
			if(equalsi(pom_ROK, STR_EMPTY)){
				Export("Nebola zadan· premenn· %s.\n", STR_ROK);
				ALERT;
				return FAILURE; /* failure */
			}

			/* premenn· MODLITBA (nepovinn·)
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_MODLITBA);
			while((equalsi(pom_MODLITBA, STR_EMPTY)) && (i < pocet)){
				// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_MODLITBA)){
					/* ide o parameter STR_MODLITBA */
					mystrcpy(pom_MODLITBA, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_MODLITBA, pom_MODLITBA);
				}
				i++;
			}
			if(equalsi(pom_MODLITBA, STR_EMPTY)){
				Log("Nebola zadan· premenn· %s (nevadÌ).\n", STR_MODLITBA);
			}

			/* premenn· DALSI_SVATY (nepovinn·)
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_DALSI_SVATY);
			while((equalsi(pom_DALSI_SVATY, STR_EMPTY)) && (i < pocet)){
				// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_DALSI_SVATY)){
					/* ide o parameter STR_DALSI_SVATY */
					mystrcpy(pom_DALSI_SVATY, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_DALSI_SVATY, pom_DALSI_SVATY);
				}
				i++;
			}
			if(equalsi(pom_DALSI_SVATY, STR_EMPTY)){
				Log("Nebola zadan· premenn· %s (nevadÌ).\n", STR_DALSI_SVATY);
			}
			
			/* premenn· MODL_OPT1 (nepovinn·)
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_MODL_OPT1);
			while((equalsi(pom_MODL_OPT1, STR_EMPTY)) && (i < pocet)){
				// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_MODL_OPT1)){
					/* ide o parameter STR_MODL_OPT1 */
					mystrcpy(pom_MODL_OPT1, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_MODL_OPT1, pom_MODL_OPT1);
				}
				i++;
			}
			if(equalsi(pom_MODL_OPT1, STR_EMPTY)){
				Log("Nebola zadan· premenn· %s (nevadÌ).\n", STR_MODL_OPT1);
			}
			
			/* premenn· MODL_OPT2 (nepovinn·)
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_MODL_OPT2);
			while((equalsi(pom_MODL_OPT2, STR_EMPTY)) && (i < pocet)){
				// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_MODL_OPT2)){
					/* ide o parameter STR_MODL_OPT2 */
					mystrcpy(pom_MODL_OPT2, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_MODL_OPT2, pom_MODL_OPT2);
				}
				i++;
			}
			if(equalsi(pom_MODL_OPT2, STR_EMPTY)){
				Log("Nebola zadan· premenn· %s (nevadÌ).\n", STR_MODL_OPT2);
			}
			
			/* premenn· MODL_OPT3 (nepovinn·)
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_MODL_OPT3);
			while((equalsi(pom_MODL_OPT3, STR_EMPTY)) && (i < pocet)){
				// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_MODL_OPT3)){
					/* ide o parameter STR_MODL_OPT3 */
					mystrcpy(pom_MODL_OPT3, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_MODL_OPT3, pom_MODL_OPT3);
				}
				i++;
			}
			if(equalsi(pom_MODL_OPT3, STR_EMPTY)){
				Log("Nebola zadan· premenn· %s (nevadÌ).\n", STR_MODL_OPT3);
			}
			
			/* premenn· MODL_OPT4 (nepovinn·)
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_MODL_OPT4);
			while((equalsi(pom_MODL_OPT4, STR_EMPTY)) && (i < pocet)){
				// Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_MODL_OPT4)){
					/* ide o parameter STR_MODL_OPT4 */
					mystrcpy(pom_MODL_OPT4, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_MODL_OPT4, pom_MODL_OPT4);
				}
				i++;
			}
			if(equalsi(pom_MODL_OPT4, STR_EMPTY)){
				Log("Nebola zadan· premenn· %s (nevadÌ).\n", STR_MODL_OPT4);
			}

			break; /* case */
		}

		case PRM_CEZ_ROK:{
		/* pripad, ze ide o tyzden cez rok */

			/* premenn· DEN_V_TYZDNI 
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_DEN_V_TYZDNI);
			while((equalsi(pom_DEN_V_TYZDNI, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_DEN_V_TYZDNI)){
					/* ide o parameter STR_DEN_V_TYZDNI */
					mystrcpy(pom_DEN_V_TYZDNI, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_DEN_V_TYZDNI, pom_DEN_V_TYZDNI);
				}
				i++;
			}
			if(equalsi(pom_DEN_V_TYZDNI, STR_EMPTY)){
				Export("Nebola zadan· premenn· %s.\n", STR_DEN_V_TYZDNI);
				ALERT;
				return FAILURE; /* failure */
			}

			/* premenn· TYZDEN 
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_TYZDEN);
			while((equalsi(pom_TYZDEN, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_TYZDEN)){
					/* ide o parameter STR_TYZDEN */
					mystrcpy(pom_TYZDEN, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_TYZDEN, pom_TYZDEN);
				}
				i++;
			}
			if(equalsi(pom_TYZDEN, STR_EMPTY)){
				Export("Nebola zadan· premenn· %s.\n", STR_TYZDEN);
				ALERT;
				return FAILURE; /* failure */
			}

			/* premenn· MODLITBA 
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_MODLITBA);
			while((equalsi(pom_MODLITBA, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_MODLITBA)){
					/* ide o parameter STR_MODLITBA */
					mystrcpy(pom_MODLITBA, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_MODLITBA, pom_MODLITBA);
				}
				i++;
			}
			if(equalsi(pom_MODLITBA, STR_EMPTY)){
				Export("Nebola zadan· premenn· %s.\n", STR_MODLITBA);
				ALERT;
				return FAILURE; /* failure */
			}

			break; /* case */
		}

		case PRM_SVIATOK:{
		/* pripad, ze ide o sviatok */

			/* premenn· NAZOV_SVIATOK 
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_NAZOV_SVIATOK);
			while((equalsi(pom_SVIATOK, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_NAZOV_SVIATOK)){
					/* ide o parameter STR_NAZOV_SVIATOK */
					mystrcpy(pom_SVIATOK, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_NAZOV_SVIATOK, pom_SVIATOK);
				}
				i++;
			}
			if(equalsi(pom_SVIATOK, STR_EMPTY)){
				Export("Nebola zadan· premenn· %s.\n", STR_NAZOV_SVIATOK);
				ALERT;
				return FAILURE; /* failure */
			}

			break; /* case */
		}

		case PRM_ANALYZA_ROKU:{
		/* pripad, ze ide o sviatok */

			/* premenn· ANALYZA_ROKU 
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_ANALYZA_ROKU);
			while((equalsi(pom_ANALYZA_ROKU, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_ANALYZA_ROKU)){
					/* ide o parameter STR_ANALYZA_ROKU */
					mystrcpy(pom_ANALYZA_ROKU, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_ANALYZA_ROKU, pom_ANALYZA_ROKU);
				}
				i++;
			}
			if(equalsi(pom_ANALYZA_ROKU, STR_EMPTY)){
				Export("Nebola zadan· premenn· %s.\n", STR_ANALYZA_ROKU);
				ALERT;
				return FAILURE; /* failure */
			}

			break; /* case */
		}

		case PRM_MESIAC_ROKA:{
		/* pripad, ze ide o mesiac roka */

			/* premenn· MESIAC
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_MESIAC_ROKA);
			while((equalsi(pom_MESIAC, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_MESIAC_ROKA)){
					/* ide o parameter STR_MESIAC_ROKA */
					mystrcpy(pom_MESIAC, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_MESIAC_ROKA, pom_MESIAC);
				}
				i++;
			}
			if(equalsi(pom_MESIAC, STR_EMPTY)){
				Export("Nebola zadan· premenn· %s.\n", STR_MESIAC_ROKA);
				ALERT;
				return FAILURE; /* failure */
			}

			/* premenn· ROK
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_ROK_ROKA);
			while((equalsi(pom_ROK, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_ROK_ROKA)){
					/* ide o parameter STR_ROK_ROKA */
					mystrcpy(pom_ROK, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_ROK_ROKA, pom_ROK);
				}
				i++;
			}
			if(equalsi(pom_ROK, STR_EMPTY)){
				Export("Nebola zadan· premenn· %s.\n", STR_ROK_ROKA);
				ALERT;
				return FAILURE; /* failure */
			}

			break; /* case */
		}

		case PRM_TABULKA:{
		/* pripad, ze ide o tabulku pohyblivych slaveni */

			/* premenn· ROK_FROM 
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_ROK_FROM);
			while((equalsi(pom_ROK_FROM, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_ROK_FROM)){
					/* ide o parameter STR_ROK_FROM */
					mystrcpy(pom_ROK_FROM, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_ROK_FROM, pom_ROK_FROM);
				}
				i++;
			}
			if(equalsi(pom_ROK_FROM, STR_EMPTY)){
				Export("Nebola zadan· premenn· %s.\n", STR_ROK_FROM);
				ALERT;
				return FAILURE; /* failure */
			}

			/* premenn· ROK_TO 
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_ROK_TO);
			while((equalsi(pom_ROK_TO, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_ROK_TO)){
					/* ide o parameter STR_ROK_TO */
					mystrcpy(pom_ROK_TO, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_ROK_TO, pom_ROK_TO);
				}
				i++;
			}
			if(equalsi(pom_ROK_TO, STR_EMPTY)){
				Export("Nebola zadan· premenn· %s.\n", STR_ROK_TO);
				ALERT;
				return FAILURE; /* failure */
			}

			/* premenn· TABULKA_LINKY (nepovinn·)
			 * 
			 * 2006-08-01: dynamickÈ zisùovanie hodnÙt parametrov */
			i = 0; /* param[0] by mal sÌce obsahovaù query type, ale radöej kontrolujeme od 0 */
			Log("pok˙öam sa zistiù hodnotu parametra %s...\n", STR_TABULKA_LINKY);
			while((equalsi(pom_LINKY, STR_EMPTY)) && (i < pocet)){
				Log("...parameter %i (meno: %s, hodnota: %s)\n", i, param[i].name, param[i].val);
				if(equals(param[i].name, STR_TABULKA_LINKY)){
					/* ide o parameter STR_TABULKA_LINKY */
					mystrcpy(pom_LINKY, param[i].val, SMALL);
					Log("hodnota parametra %s je %s.\n", STR_TABULKA_LINKY, pom_LINKY);
				}
				i++;
			}
			if(equalsi(pom_LINKY, STR_EMPTY)){
				Log("Nebola zadan· premenn· %s (nevadÌ).\n", STR_TABULKA_LINKY);
			}

			break; /* case */
		}

	}
	Log("parseQueryString() -- end, returning SUCCESS\n");
	return SUCCESS;
}/* parseQueryString(); */

/* KOMPILACIA -- idiotuv pruvodce kompilovanim tohoto gigantu */

/* nezabudni zmenit #define BUILD_DATE v mydefs.h! (2003-07-15) */

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
 * 
 * 2003-08-11: pouzil som pre g++ option -Wall, ktora pomohla odhalit niektore warningy
 */

/* POUCENIE
 * z hladania Segmentation fault (segfault), 2003-08-11
 *
 * Dovod segfaultu
 * - bol ako obycajne v blbosti: int sa vypisovalo pomocou Export("...%s...");
 *
 * Priciny neodhalenia
 * - nespustal som linux-verziu pre Windows (parameter "-l1", ci vytvarat linky)
 *
 * Poucenie
 * - aj pod Windows kompilovat/spustat s option presne ako bezi na linuxe
 * - pozor na preklepy
 *
 * Zaver
 * - hlavne, ze uz je to za nami :)) duurko, 2003-08-11
 * - O.A.M.D.G.
 */

/*---------------------------------------------------------------------*/
/* main();
 *    hlavny program
 */
#define _main_LOG_to_Export_PARAMS {\
	_main_LOG_to_Export("\tparam1 == %s (pom_DEN/pom_SVIATOK/pom_DEN_V_TYZDNI), param1 == %s (pom_ROK_FROM)\n", pom_DEN, pom_ROK_FROM);\
	_main_LOG_to_Export("\tparam2 == %s (pom_MESIAC/pom_TYZDEN), param2 == %s (pom_ROK_TO)\n", pom_MESIAC, pom_ROK_TO);\
	_main_LOG_to_Export("\tparam3 == %s (pom_ROK/pom_ANALYZA_ROKU), param3 == %s (pom_LINKY)\n", pom_ROK, pom_LINKY);\
	_main_LOG_to_Export("\tparam4 == %s (pom_MODLITBA)\n", pom_MODLITBA);\
	_main_LOG_to_Export("\tparam5 == %s (pom_DALSI_SVATY)\n", pom_DALSI_SVATY);\
	_main_LOG_to_Export("\tparam6 == %s (pom_MODL_OPT1)\n", pom_MODL_OPT1);\
	_main_LOG_to_Export("\tparam7 == %s (pom_MODL_OPT2)\n", pom_MODL_OPT2);\
	_main_LOG_to_Export("\tparam8 == %s (pom_MODL_OPT3)\n", pom_MODL_OPT3);\
	_main_LOG_to_Export("\tparam9 == %s (pom_MODL_OPT4)\n", pom_MODL_OPT4);\
	_main_LOG_to_Export("\tparam10== %s (pom_MODL_OPT5)\n", pom_MODL_OPT5);\
	_main_LOG_to_Export("\tparam11== %s (pom_MODL_OPT_APPEND)\n", pom_MODL_OPT_APPEND);\
	_main_LOG_to_Export("\tparam12== %s (pom_JAZYK)\n", pom_JAZYK);\
}

/* kedysi bolo void main;
 * 2003-07-14, kvoli gcc version 3.2.2 20030222 (Red Hat Linux 3.2.2-5) christ-net.sk 
 */
int main(int argc, char **argv){
	/* pretoze pocas behu win32-release verzie on-line breviara sa spusta
	 * main() viackrat bez zrusenia programu,
	 * je potrebne inicializovat globalne premenne pri kazdom pusteni jej behu
	 * 11/04/2000A.D.
	 */
	_global_opt1 = NIE;
	_global_opt2 = MODL_ZALMY_ZO_DNA; /* 2006-01-25: upravenÈ, bolo tu MODL_ZALMY_ZO_SV */
	_global_opt3 = MODL_SPOL_CAST_NEURCENA; /* 2003-08-11 -Wall upozornila `statement with no effect' */
	_global_opt4 = ANO;
	_global_opt_append = NIE;
	strcpy(pom_QUERY_TYPE , STR_EMPTY);
	strcpy(pom_DEN        , STR_EMPTY);
	strcpy(pom_MESIAC     , STR_EMPTY); 
	strcpy(pom_ROK        , STR_EMPTY); 
	strcpy(pom_MODLITBA   , STR_EMPTY);
	strcpy(pom_MODL_OPT1  , STR_EMPTY);
	strcpy(pom_MODL_OPT2  , STR_EMPTY);
	strcpy(pom_MODL_OPT3  , STR_EMPTY);
	strcpy(pom_MODL_OPT4  , STR_EMPTY);
	strcpy(pom_DALSI_SVATY, STR_EMPTY);
	strcpy(pom_ROK_FROM   , STR_EMPTY);
	strcpy(pom_ROK_TO     , STR_EMPTY);
	strcpy(pom_LINKY      , STR_EMPTY);
	strcpy(pom_JAZYK      , STR_EMPTY); /* 2006-07-11: PridanÈ kvÙli jazykov˝m mut·ci·m */
	/* koniec inicializacie globalnych premennych; teraz samotna main()
	 * 11/04/2000A.D.
	 */
#if defined(OS_linux)
	_global_linky = 1; /* zobrazovat linky */
#elif defined(OS_Windows)
	_global_linky = 0; /* nezobrazovat linky */
#else
	#error Unsupported operating system (not defined in mysystem.h)
#endif

	short int ret; /* navratova hodnota */
	short int len; /* dÂûka; pridanÈ 2006-07-17 */

	initLog(FILE_LOG);

	/* 2005-03-29: Pridane kvoli debuggovaniu na obrazovku */
// #ifdef OS_linux
	_main_LOG("Content-type: text/html\n");
	_main_LOG("\n");
// #endif
	
	_main_LOG("-- log file programu pre Liturgiu hodin (c)1999-2006 Juraj Videky --\n");

	/* config: dorobene 30/03/2000A.D. */
	_main_LOG("first, reading configuration (file %s)...\n", CONFIG_FILE);
	readConfig();
	_main_LOG("HTTP_ADDRESS == `%s'\n", HTTP_ADDRESS);
	_main_LOG("MAIL_ADDRESS == `%s'\n", MAIL_ADDRESS);
	/* 2004-03-17 pridane INCLUDE_DIR */
	_main_LOG("INCLUDE_DIR == `%s'\n", INCLUDE_DIR);
	/* 2004-03-17 na inom mieste sa upravuje include_dir - je to 2004-03-17_TUTOLA */

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

	/* pridanÈ 2005-08-01 */

	/* _global_buf */
	if((_global_buf = (char*) malloc(MAX_GLOBAL_STR)) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_buf'\n");
		goto _main_end;
	}
	else{
		_main_LOG("  %d bytes for `_global_buf'\n", MAX_GLOBAL_STR);
		mystrcpy(_global_buf, STR_EMPTY, MAX_GLOBAL_STR);
	}

	/* _global_buf2 */
	if((_global_buf2 = (char*) malloc(MAX_GLOBAL_STR)) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_buf2'\n");
		goto _main_end;
	}
	else{
		_main_LOG("  %d bytes for `_global_buf2'\n", MAX_GLOBAL_STR);
		mystrcpy(_global_buf2, STR_EMPTY, MAX_GLOBAL_STR);
	}

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
				if(equals(file_export, STR_EMPTY) || equals(file_export, "+")){
					/* "+" -- error, chce pridavat do nicoho */
					Log("continuing to export in FILE_EXPORT (`%s')...\n", FILE_EXPORT);
				}
				else{
					/* pridane 2003-07-08 */
					if(_global_opt_append == YES){
						/* pridame na koniec nazvu suboru "+" aby to vedel initExport() */
						strcat(file_export, "+");
						Log("budem appendovat (_global_opt_append == YES)...\n");
					}
					/* a napokon puovodna pasaz pred 2003-07-08 */
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
			_main_LOG_to_Export("params == SCRIPT_PARAM_FROM_QS\n");
			/* nasledujuca pasaz je tu preto, ze mozno bolo pouzite kombinovane
			 * aj query string, aj formular (teda treba citat aj systemove
			 * premenne WWW_...
			 */

_main_SIMULACIA_QS:
			_main_LOG_to_Export("---getting query type from query string (query_string == %s):\n", query_string);
			query_type = getQueryTypeFrom_QS(query_string);
			_main_LOG_to_Export("---getting query type from query string: finished.\n");

			_main_LOG_to_Export("---parsing query string:\n");
			ret = parseQueryString();
			_main_LOG_to_Export("---parsing query string: finished.\n");

			Log("2005-08-15, pomocn˝ v˝pis: query_type == %d\n", query_type);

			_main_LOG_to_Export("---scanning for system variables WWW_...: started...\n");
			/* historicka poznamka:                          (01/02/2000A.D.)
			 * kedysi tu tato pasaz (podla casti `case SCRIPT_PARAM_FROM_FORM')
			 * nebola, avsak pretoze to neumoznovalo `mixovane' dotazy
			 * (ked je nieco v QS a navyse, uncgi.c vlozi (aj QS aj) ostatne veci
			 *  z formulara do systemovych premennych WWW_...),
			 * zmenili sme to tak, ze sa tu precitaju WWW_... a potom parsuje qs
			 */

			/* 2005-03-28: Zmenene poradie. POST dotazy handlovane vyssie sposobom uncgi. */
			_main_LOG_to_Export("spustam setForm();\n");
			ret = setForm();
			_main_LOG_to_Export("spat po skonceni setForm()\n");

			// query_type = getQueryTypeFrom_WWW();
			/* zistili sme, aky je typ dotazu podla formulara */
			if((ret == SUCCESS) && (query_type != PRM_NONE) && (query_type != PRM_UNKNOWN)){
				/* znamena to teda, ze existuje systemova premenna,
				 * oznacujuca typ dotazu ==> treba nacitat z formulara resp.
				 * systemovych premennych WWW_...
				 */
				_main_LOG_to_Export("spustam getForm();\n");
				ret = getForm();
				_main_LOG_to_Export("params from system variables WWW_...:\n");
				_main_LOG_to_Export_PARAMS; /* 2003-08-13, dane do #define */
				_main_LOG_to_Export("spat po skonceni getForm()\n");
			}
			_main_LOG_to_Export("---scanning for system variables WWW_...:finished.\n");

			break;
		}
	}

	_main_LOG_to_Export("query_type == ");
	switch(query_type){
		case PRM_UNKNOWN:		_main_LOG_to_Export("PRM_UNKNOWN\n"); break;
		case PRM_TABULKA:		_main_LOG_to_Export("PRM_TABULKA\n"); break;
		case PRM_NONE:			_main_LOG_to_Export("PRM_NONE\n"); break;
		case PRM_DATUM:			_main_LOG_to_Export("PRM_DATUM\n"); break;
		case PRM_DETAILY:		_main_LOG_to_Export("PRM_DETAILY\n"); break;
		case PRM_CEZ_ROK:		_main_LOG_to_Export("PRM_CEZ_ROK\n"); break;
		case PRM_ANALYZA_ROKU:	_main_LOG_to_Export("PRM_ANALYZA_ROKU\n"); break;
		case PRM_SVIATOK:		_main_LOG_to_Export("PRM_SVIATOK\n"); break;
		case PRM_MESIAC_ROKA:	_main_LOG_to_Export("PRM_MESIAC_ROKA\n"); break;
		case PRM_DNES:			_main_LOG_to_Export("PRM_DNES\n"); break;
		/* pridane 2003-07-04, batch mode */
		case PRM_BATCH_MODE:	_main_LOG_to_Export("PRM_BATCH_MODE\n"); break;
	}

	_main_LOG_to_Export_PARAMS; /* 2003-08-13, dane do #define */

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
			/* inicializacia pridana do _allocate_global_var 2003-08-13 */
/* ------------------------------------------------------------------------- */
			LOG_ciara;

			/* 2006-07-12: pridanÈ parsovanie jazyka kvÙli jazykov˝m mut·ci·m */
			_main_LOG_to_Export("zisùujem jazyk...\n");
			_global_jazyk = atojazyk(pom_JAZYK);
			if(_global_jazyk == JAZYK_UNDEF){
				_global_jazyk = JAZYK_SK;
				_main_LOG_to_Export("\t(vzhæadom k neurËenÈmu jazyku pouûÌvam default)\n");
			}
			_main_LOG_to_Export("...jazyk (%s) = %i, teda %s (%s)\n", pom_JAZYK, _global_jazyk, nazov_jazyka[_global_jazyk], skratka_jazyka[_global_jazyk]);
/* ------------------------------------------------------------------------- */
			LOG_ciara;

			/* pridane 27/04/2000A.D.
			 * 2005-03-22: Upraveny vystup aj pre OS_linux rovnako ako pre ostatne
			 */
			_main_LOG_to_Export("pom_LINKY == `%s'\n", pom_LINKY);
#if defined(OS_linux)
			_global_linky = 1; /* zobrazovat linky */
			_main_LOG_to_Export("/* linux: teraz som nastavil _global_linky == %d */\n", _global_linky);
#elif defined(OS_Windows)
			if(pom_LINKY != NULL) /* pridane 13/04/2000A.D. */
				_global_linky = atoi(pom_LINKY);
			_main_LOG_to_Export("/* Windows: teraz som nastavil _global_linky == %d */\n", _global_linky);
#elif defined(OS_DOS)
			if((pom_LINKY != NULL) && (!equals(pom_LINKY, STR_EMPTY))){ /* pridane 27/04/2000A.D. */
				_global_linky = atoi(pom_LINKY);
				_main_LOG_to_Export("/* DOS: teraz som nastavil _global_linky == %d */\n", _global_linky);
			}
#else
	#error Unsupported operating system (not defined in mysystem.h)
#endif
			/* inak ostane default hodnoty nastavene na zaciatku pre kazdy operacny system zvlast */

			_main_LOG_to_Export("˙prava include adres·ra...\n");
			/* 2006-07-17: dokonËenie ˙pravy include adres·ra podæa jazyka */

			/* 2004-03-17 uprava ciest: INCLUDE_DIR a include_dir
			 * tzv. miesto 2004-03-17_TUTOLA
			 */
			_main_LOG_to_Export("\tINCLUDE_DIR = `%s'\n\tinclude_dir = `%s'\n", INCLUDE_DIR, include_dir);
			if(strcmp(include_dir, STR_EMPTY) == 0){
				_main_LOG_to_Export("\tberiem INCLUDE_DIR...\n");
				mystrcpy(include_dir, INCLUDE_DIR, MAX_STR);
			}
			else
				_main_LOG_to_Export("\tberiem include_dir...\n");

			/* 2006-07-17: prv· kontrola, Ëi include_dir konËÌ na backslash resp. slash */
			len = strlen(include_dir) - 1;
			_main_LOG_to_Export("prv· kontrola include adres·ra (Ëi konËÌ oddeæovaËom `%c' [dÂûka %d])...\n", PATH_SEPARATOR, len);
			if(include_dir[len] != (short int)PATH_SEPARATOR){
				include_dir[len + 1] = PATH_SEPARATOR;
				_main_LOG_to_Export("\tupravenÈ (pridanÈ na koniec reùazca): %s\n", include_dir);
			}
			else{
				_main_LOG_to_Export("\tok.\n");
			}

			/* 2006-07-13: pridanÈ doplnenie jazyka kvÙli jazykov˝m mut·ci·m */
			_main_LOG_to_Export("upravujem include adres·r podæa jazyka (%d - %s)...\n", _global_jazyk, nazov_jazyka[_global_jazyk]);

			/* 2006-07-17: dokonËenie ˙pravy include adres·ra podæa jazyka */
			if(strlen(postfix_jazyka[_global_jazyk]) > 0){
				/* 2006-07-31: pÙvodne sme uvaûovali, ûe include_dir bude napr. include/cz, incluce/en; teraz bude radöej include_cz, include_en t.j. nahraÔ backslash resp. slash znakom underscore */
				include_dir[len] = UNDERSCORE;
				strcat(include_dir, postfix_jazyka[_global_jazyk]);
			}

			/* 2006-07-17: druh· kontrola, Ëi include_dir konËÌ na backslash resp. slash */
			len = strlen(include_dir) - 1;
			_main_LOG_to_Export("druh· kontrola include adres·ra (Ëi konËÌ oddeæovaËom `%c' [dÂûka %d])...\n", PATH_SEPARATOR, len);
			if(include_dir[len] != (short int)PATH_SEPARATOR){
				include_dir[len + 1] = PATH_SEPARATOR;
				_main_LOG_to_Export("\tupravenÈ (pridanÈ na koniec reùazca): %s\n", include_dir);
			}
			else{
				_main_LOG_to_Export("\tok.\n");
			}

			_main_LOG_to_Export("include s˙bory bud˙ z adres·ra `%s'\n", include_dir);
/* ------------------------------------------------------------------------- */
			LOG_ciara;

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
					_main_LOG_to_Export("spustam _main_dnes(%s, %s);\n", pom_MODLITBA, pom_DALSI_SVATY);
					_main_dnes(pom_MODLITBA, pom_DALSI_SVATY);
					_main_LOG_to_Export("spat po skonceni _main_dnes();\n");
					break;
				case PRM_TABULKA:
					_main_LOG_to_Export("spustam _main_tabulka();\n");
					_main_tabulka(pom_ROK_FROM, pom_ROK_TO, pom_LINKY);
					_main_LOG_to_Export("spat po skonceni _main_tabulka();\n");
					break;
				/* pridany batch mode; 2003-07-04 */
				case PRM_BATCH_MODE:
					_main_LOG_to_Export("spustam _main_batch_mode();\n");
					Export("<center><h2>Batch mode (d·vkovÈ pouûitie)</h2></center>\n");
					/* vyuzivam parametre, ktore boli nastavene */
					_main_batch_mode(
						/* vyuzite parametre sa sice volaju haluzne, ale sluzia pre
						 * den from (prve tri), den to (dalsie tri),
						 * este jedno mam reserved 
						 * 2003-07-04 */
						pom_DEN, pom_MESIAC, pom_ROK,
						pom_ROK_FROM, pom_ROK_TO, pom_MODLITBA, 
						pom_DALSI_SVATY, pom_LINKY);
						/* naimplementovana 2003-07-07 */
					_main_LOG_to_Export("spat po skonceni _main_batch_mode();\n");
					Export("<p>V˝sledn˝ batch skript (d·vkov˝ s˙bor) sa nach·dza v s˙bore <a href=\"%s\">%s</a>.<br>\n",
						name_batch_file, name_batch_file);
					Export("Po spustenÌ tento skript vygeneruje modlitby pre danÈ obdobie \n");
					Export("do s˙borov <span class=\"tt\">yyyy-mm-dd_xp.htm</span>, kde v˝znam \n");
					Export("jednotliv˝ch ËastÌ mena s˙boru je nasledovn˝:\n");
					Export("<ul class=\"level1\">\n");
					Export("<li><span class=\"parameter\">yyyy</span> | rok</li>\n");
					Export("<li><span class=\"parameter\">mm</span> | mesiac (napr. <span class=\"value\">05</span> pre m·j)</li>\n");
					Export("<li><span class=\"parameter\">dd</span> | deÚ (napr. <span class=\"value\">07</span>)</li>\n");
					Export("<li><span class=\"parameter\">x</span> | poradie sv‰tÈho (<span class=\"value\">0</span> aû <span class=\"value\">4</span>)</li>\n");
					Export("<li><span class=\"parameter\">p</span> | modlitba (<span class=\"value\">r</span> = rannÈ chv·ly, <span class=\"value\">v</span> = veöpery)</li>\n");
					Export("</ul>\n");
					/* pridane 2003-07-08 */
					Export("<p>V prÌpade, ûe je pouûit˝ parameter <span class=\"parameter\">a</span> (append), \n");
					Export("bude vytvoren˝ len jeden s˙bor s nasledovn˝m menom:\n");
					Export("<span class=\"tt\">yyyy-mm-dd_YYYY-MM-DD.htm</span>, kde v˝znam \n");
					Export("jednotliv˝ch ËastÌ mena s˙boru je nasledovn˝:\n");
					Export("<ul class=\"level1\">\n");
					Export("<li><span class=\"parameter\">yyyy</span> | rok poËiatoËnÈho d·tumu</li>\n");
					Export("<li><span class=\"parameter\">mm</span> | mesiac poËiatoËnÈho d·tumu</li>\n");
					Export("<li><span class=\"parameter\">dd</span> | deÚ poËiatoËnÈho d·tumu</li>\n");
					Export("<li><span class=\"parameter\">YYYY</span> | rok koncovÈho d·tumu</li>\n");
					Export("<li><span class=\"parameter\">MM</span> | mesiac koncovÈho d·tumu</li>\n");
					Export("<li><span class=\"parameter\">DD</span> | deÚ koncovÈho d·tumu</li>\n");
					Export("</ul>\n");
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
	_main_LOG_to_Export("_global_buf\n"); free(_global_buf);
	_main_LOG_to_Export("_global_buf2\n"); free(_global_buf2);
	_main_LOG_to_Export("...done.\n");
_main_end:
	patka();
	if(closeExport() == EOF)
		Log("closeExport(): error closing file (return == EOF)\n");
	else
		Log("closeExport(): success.\n");
	closeLog();
	return 0; /* 2003-07-14, kvoli gcc version 3.2.2 20030222 (Red Hat Linux 3.2.2-5) christ-net.sk */
}

#endif /* __BREVIAR_C_ */
