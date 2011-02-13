/***************************************************************/
/*                                                             */
/* liturgia.cpp                                                */
/* (c)1999-2005 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | obsahuje zakladne vecicky pre liturgiu hodin  */
/* document history                                            */
/*   18/10/1999A.D. | created                                  */
/*   06/09/2001A.D. | tento popis                              */
/*   2003-08-07a.D. | pridana void _init_dm co nastavi dummy   */
/*                  - pouzite v _allocate_global_var           */
/*   2003-08-11a.D. | void _init_dm zapoznamkovana             */
/*                  - inicializovane stringy;zmena na mystrcpy */
/*                  - (char) konverzie z int explicitne        */
/*   2003-08-13a.D. | pridane logy pre modlitbu cez den        */
/*                  - pridana inicializacia do _allocate_      */
/*                  - zmena "" na STR_EMPTY (mystring.h)       */
/*                  - odstranenie RUN_MODLITBA_CEZ_DEN         */
/*   2004-08-14a.D. | char zmeneny na unsigned (_nedelne_p...) */
/*   2005-03-21a.D. | pridany typ vypisu linky LINK_ISO_8601   */
/*   2005-07-27a.D. | nov� premenn� v �trukt.dm: typslav_lokal */
/*                                                             */
/*                                                             */
/***************************************************************/

#ifndef __LITURGIA_C_
#define __LITURGIA_C_

#include "liturgia.h"

#include "mylog.h" /* bolo tu .c */
#include "myexpt.h"
#include "mydefs.h"
#include "mysystem.h"
#include "mystring.h"
#include <ctype.h>


/* globalne premenne prehodene do liturgia.h, 17/02/2000A.D. */
/* ------------------------------------------------------------------- */
int _allocate_global_var(void){
	int ret = SUCCESS;
	Log("Allocating memory...\n");
/* _global_den_ptr */
	if((_global_den_ptr = (_struct_dm*) malloc(sizeof(_struct_dm))) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_den_ptr'\n");
		ret = FAILURE;
	}
	else{
		Log("  %d bytes for `_global_den_ptr'\n", sizeof(_struct_dm));
		_INIT_DM(_global_den); /* 2003-08-07 pridana, 2003-08-11 nahradena #definom */
	}

/* _global_result_ptr */
	if((_global_result_ptr = (_struct_dm*) malloc(sizeof(_struct_dm))) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_result_ptr'\n");
		ret = FAILURE;
	}
	else{
		Log("  %d bytes for `_global_result_ptr'\n", sizeof(_struct_dm));
		_INIT_DM(_global_result); /* 2003-08-07 pridana, 2003-08-11 nahradena #definom */
	}

/* _global_pm_sobota_ptr */
	if((_global_pm_sobota_ptr = (_struct_dm*) malloc(sizeof(_struct_dm))) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_pm_sobota_ptr'\n");
		ret = FAILURE;
	}
	else{
		Log("  %d bytes for `_global_pm_sobota_ptr'\n", sizeof(_struct_dm));
		_INIT_DM(_global_pm_sobota); /* 2003-08-07 pridana, 2003-08-11 nahradena #definom */
	}

/* _global_svaty1_ptr */
	if((_global_svaty1_ptr = (_struct_dm*) malloc(sizeof(_struct_dm))) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_svaty1_ptr'\n");
		ret = FAILURE;
	}
	else{
		Log("  %d bytes for `_global_svaty1_ptr'\n", sizeof(_struct_dm));
		_INIT_DM(_global_svaty1); /* 2003-08-07 pridana, 2003-08-11 nahradena #definom */
	}

/* _global_svaty2_ptr */
	if((_global_svaty2_ptr = (_struct_dm*) malloc(sizeof(_struct_dm))) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_svaty2_ptr'\n");
		ret = FAILURE;
	}
	else{
		Log("  %d bytes for `_global_svaty2_ptr'\n", sizeof(_struct_dm));
		_INIT_DM(_global_svaty2); /* 2003-08-07 pridana, 2003-08-11 nahradena #definom */
	}

/* _global_svaty3_ptr */
	if((_global_svaty3_ptr = (_struct_dm*) malloc(sizeof(_struct_dm))) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_svaty3_ptr'\n");
		ret = FAILURE;
	}
	else{
		Log("  %d bytes for `_global_svaty3_ptr'\n", sizeof(_struct_dm));
		_INIT_DM(_global_svaty3); /* 2003-08-07 pridana, 2003-08-11 nahradena #definom */
	}

/* _global_modl_prve_vespery_ptr */
	if((_global_modl_prve_vespery_ptr = (_type_1vespery*) malloc(sizeof(_type_1vespery))) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_modl_prve_vespery_ptr'\n");
		ret = FAILURE;
	}
	else{
		Log("  %d bytes for `_global_modl_prve_vespery_ptr'\n", sizeof(_type_1vespery));
		_INIT_TMODLITBA1(_global_modl_prve_vespery); /* pridana 2003-08-13 */
	}

/* _global_modl_1kompletorium_ptr */
	if((_global_modl_1kompletorium_ptr = (_type_1kompletorium*) malloc(sizeof(_type_1kompletorium))) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_modl_1kompletorium_ptr'\n");
		ret = FAILURE;
	}
	else{
		Log("  %d bytes for `_global_modl_1kompletorium_ptr'\n", sizeof(_type_1kompletorium));
	}

/* _global_modl_invitatorium_ptr */
	if((_global_modl_invitatorium_ptr = (_type_invitatorium*) malloc(sizeof(_type_invitatorium))) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_modl_invitatorium_ptr'\n");
		ret = FAILURE;
	}
	else{
		Log("  %d bytes for `_global_modl_invitatorium_ptr'\n", sizeof(_type_invitatorium));
	}

/* _global_modl_ranne_chvaly_ptr */
	if((_global_modl_ranne_chvaly_ptr = (_type_ranne_chvaly*) malloc(sizeof(_type_ranne_chvaly))) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_modl_ranne_chvaly_ptr'\n");
		ret = FAILURE;
	}
	else{
		Log("  %d bytes for `_global_modl_ranne_chvaly_ptr'\n", sizeof(_type_ranne_chvaly));
		_INIT_TMODLITBA1(_global_modl_ranne_chvaly); /* pridana 2003-08-13 */
	}
/* pridane 2003-08-13 */
/* _global_modl_posv_citanie_ptr */
	if((_global_modl_posv_citanie_ptr = (_type_posv_citanie*) malloc(sizeof(_type_posv_citanie))) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_modl_posv_citanie_ptr'\n");
		ret = FAILURE;
	}
	else{
		Log("  %d bytes for `_global_modl_posv_citanie_ptr'\n", sizeof(_type_posv_citanie));
		_INIT_TMODLITBA1(_global_modl_posv_citanie); /* pridana 2003-08-13 */
	}

/* _global_modl_cez_den_9_ptr */
	if((_global_modl_cez_den_9_ptr = (_type_cez_den_9*) malloc(sizeof(_type_cez_den_9))) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_modl_cez_den_9_ptr'\n");
		ret = FAILURE;
	}
	else{
		Log("  %d bytes for `_global_modl_cez_den_9_ptr'\n", sizeof(_type_cez_den_9));
		_INIT_TMODLITBA2(_global_modl_cez_den_9); /* pridana 2003-08-13 */
	}

/* _global_modl_cez_den_12_ptr */
	if((_global_modl_cez_den_12_ptr = (_type_cez_den_12*) malloc(sizeof(_type_cez_den_12))) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_modl_cez_den_12_ptr'\n");
		ret = FAILURE;
	}
	else{
		Log("  %d bytes for `_global_modl_cez_den_12_ptr'\n", sizeof(_type_cez_den_12));
		_INIT_TMODLITBA2(_global_modl_cez_den_12); /* pridana 2003-08-13 */
	}

/* _global_modl_cez_den_3_ptr */
	if((_global_modl_cez_den_3_ptr = (_type_cez_den_3*) malloc(sizeof(_type_cez_den_3))) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_modl_cez_den_3_ptr'\n");
		ret = FAILURE;
	}
	else{
		Log("  %d bytes for `_global_modl_cez_den_3_ptr'\n", sizeof(_type_cez_den_3));
		_INIT_TMODLITBA2(_global_modl_cez_den_3); /* pridana 2003-08-13 */
	}

/* _global_modl_vespery_ptr */
	if((_global_modl_vespery_ptr = (_type_vespery*) malloc(sizeof(_type_vespery))) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_modl_vespery_ptr'\n");
		ret = FAILURE;
	}
	else{
		Log("  %d bytes for `_global_modl_vespery_ptr'\n", sizeof(_type_vespery));
		_INIT_TMODLITBA1(_global_modl_vespery); /* pridana 2003-08-13 */
	}

/* _global_modl_kompletorium_ptr */
	if((_global_modl_kompletorium_ptr = (_type_kompletorium*) malloc(sizeof(_type_kompletorium))) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_modl_kompletorium_ptr'\n");
		ret = FAILURE;
	}
	else{
		Log("  %d bytes for `_global_modl_kompletorium_ptr'\n", sizeof(_type_kompletorium));
	}

/* _global_r_ptr */
	if((_global_r_ptr = (_struct_lrok*) malloc(sizeof(_struct_lrok))) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_r_ptr'\n");
		ret = FAILURE;
	}
	else{
		Log("  %d bytes for `_global_r_ptr'\n", sizeof(_struct_lrok));
	}

/* _global_link_ptr */
	if((_global_link_ptr = (char*) malloc(MAX_GLOBAL_LINK)) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_link_ptr'\n");
		ret = FAILURE;
	}
	else{
		Log("  %d bytes for `_global_link_ptr'\n", MAX_GLOBAL_LINK);
		mystrcpy(_global_link_ptr, STR_UNDEF, MAX_GLOBAL_LINK); /* pridane 2003-08-11, zmenene 2003-08-13 */
	}

/* _global_pom_str */
	if((_global_pom_str = (char*) malloc(MAX_STR)) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_pom_str'\n");
		ret = FAILURE;
	}
	else{
		Log("  %d bytes for `_global_pom_str'\n", MAX_STR);
		mystrcpy(_global_pom_str, STR_UNDEF, MAX_STR); /* pridane 2003-08-11, zmenene 2003-08-13 */
	}

/* _global_string */
	if((_global_string = (char*) malloc(MAX_GLOBAL_STR)) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_string'\n");
		ret = FAILURE;
	}
	else{
		Log("  %d bytes for `_global_string'\n", MAX_GLOBAL_STR);
		mystrcpy(_global_string, STR_UNDEF, MAX_GLOBAL_STR); /* pridane 2003-08-11, zmenene 2003-08-13 */
	}

/* _global_string2 */
	if((_global_string2 = (char*) malloc(MAX_GLOBAL_STR)) == NULL){
		Log("  Not enough memory to allocate buffer for `_global_string2'\n");
		ret = FAILURE;
	}
	else{
		Log("  %d bytes for `_global_string2'\n", MAX_GLOBAL_STR);
		mystrcpy(_global_string2, STR_EMPTY, MAX_GLOBAL_STR); /* pridane 2003-08-11 */
	}

	Log("...done.\n");
	return ret;
}

int _deallocate_global_var(void){
	Log("Deallocating memory...\n");
	Log("_global_den_ptr\n"); free(_global_den_ptr);
	Log("_global_result_ptr\n"); free(_global_result_ptr);
	Log("_global_pm_sobota_ptr\n"); free(_global_pm_sobota_ptr);
	Log("_global_svaty1_ptr\n"); free(_global_svaty1_ptr);
	Log("_global_svaty2_ptr\n"); free(_global_svaty2_ptr);
	Log("_global_svaty3_ptr\n"); free(_global_svaty3_ptr);
	Log("_global_modl_prve_vespery_ptr\n"); free(_global_modl_prve_vespery_ptr);
	Log("_global_modl_1kompletorium_ptr\n"); free(_global_modl_1kompletorium_ptr);
	Log("_global_modl_invitatorium_ptr\n"); free(_global_modl_invitatorium_ptr);
	Log("_global_modl_ranne_chvaly_ptr\n"); free(_global_modl_ranne_chvaly_ptr);
	Log("_global_modl_cez_den_9_ptr\n"); free(_global_modl_cez_den_9_ptr);
	Log("_global_modl_cez_den_12_ptr\n"); free(_global_modl_cez_den_12_ptr);
	Log("_global_modl_cez_den_3_ptr\n"); free(_global_modl_cez_den_3_ptr);
	Log("_global_modl_vespery_ptr\n"); free(_global_modl_vespery_ptr);
	Log("_global_modl_kompletorium_ptr\n"); free(_global_modl_kompletorium_ptr);
	Log("_global_r_ptr\n"); free(_global_r_ptr);

	Log("_global_link_ptr\n"); free(_global_link_ptr);
	Log("_global_pom_str\n"); free(_global_pom_str);
	Log("_global_string\n"); free(_global_string);
	Log("_global_string2\n"); free(_global_string2);

	Log("...done.\n");
	return SUCCESS;
}

/* ------------------------------------------------------------------- */
/* string comparator -- pre vsetky kombinacie dvojic
 * [const] char, [const] char
 */
int equals(char *s1, char *s2){
	if(strcmp(s1, s2) == 0)
		return 1;
	else
		return 0;
}

int equals(const char *s1, char *s2){
	if(strcmp(s1, s2) == 0)
		return 1;
	else
		return 0;
}

int equals(const char *s1, const char *s2){
	if(strcmp(s1, s2) == 0)
		return 1;
	else
		return 0;
}

int equals(char *s1, const char *s2){
	if(strcmp(s1, s2) == 0)
		return 1;
	else
		return 0;
}

/* string comparator without case sensitivity  -- pre vsetky kombinacie
 * dvojic [const] char, [const] char
 */

int equalsi(char *is1, char *is2){
#if defined(DEFINED_strcmpi)
	if(strcmpi(is1, is2) == 0)
		return 1;
	else
		return 0;
#else
	int i, length;
	char s1[MAX_STR], s2[MAX_STR];
	mystrcpy(s1, is1, MAX_STR);
	mystrcpy(s2, is2, MAX_STR);
	length = strlen(s1);
	for(i = 0; i < length; i++){
		s1[i] = (char)tolower(s1[i]);
	}
	length = strlen(s2);
	for(i = 0; i < length; i++){
		s2[i] = (char)tolower(s2[i]);
	}
	return equals(s1, s2);
#endif
}

int equalsi(const char *is1, char *is2){
#if defined(DEFINED_strcmpi)
	if(strcmpi(is1, is2) == 0)
		return 1;
	else
		return 0;
#else
	int i, length;
	char s1[MAX_STR], s2[MAX_STR];
	mystrcpy(s1, is1, MAX_STR);
	mystrcpy(s2, is2, MAX_STR);
	length = strlen(s1);
	for(i = 0; i < length; i++){
		s1[i] = (char)tolower(s1[i]);
	}
	length = strlen(s2);
	for(i = 0; i < length; i++){
		s2[i] = (char)tolower(s2[i]);
	}
	return equals(s1, s2);
#endif
}

int equalsi(const char *is1, const char *is2){
#if defined(DEFINED_strcmpi)
	if(strcmpi(is1, is2) == 0)
		return 1;
	else
		return 0;
#else
	int i, length;
	char s1[MAX_STR], s2[MAX_STR];
	mystrcpy(s1, is1, MAX_STR);
	mystrcpy(s2, is2, MAX_STR);
	length = strlen(s1);
	for(i = 0; i < length; i++){
		s1[i] = (char)tolower(s1[i]);
	}
	length = strlen(s2);
	for(i = 0; i < length; i++){
		s2[i] = (char)tolower(s2[i]);
	}
	return equals(s1, s2);
#endif
}

int equalsi(char *is1, const char *is2){
#if defined(DEFINED_strcmpi)
	if(strcmpi(is1, is2) == 0)
		return 1;
	else
		return 0;
#else
	int i, length;
	char s1[MAX_STR], s2[MAX_STR];
	mystrcpy(s1, is1, MAX_STR);
	mystrcpy(s2, is2, MAX_STR);
	length = strlen(s1);
	for(i = 0; i < length; i++){
		s1[i] = (char)tolower(s1[i]);
	}
	length = strlen(s2);
	for(i = 0; i < length; i++){
		s2[i] = (char)tolower(s2[i]);
	}
	return equals(s1, s2);
#endif
}

/* ------------------------------------------------------------------- */
/* vezme retazec a porovna s nazvami mesiaca; ak najde, vrati, inak 0 */
int cislo_mesiaca(char *mesiac){
	int ret = 0;
	int i;
	for(i = 0; i < 12; i++){
		if(equals(nazov_mesiaca[i], mesiac))
			ret = i + 1;
	}
	return ret;
}

/* ------------------------------------------------------------------- */
/* urobi velke pismena */
char *caps_BIG(const char *input){
	int i = 0;
	char c;
	mystrcpy(_global_pom_str, input, MAX_STR);
	while(( c = _global_pom_str[i]) != '\0'){
		if((c >= 'a') && (c <= 'z')){
			c = (char)(c - 32);
		}
		else{
			switch(c){
				/* samohlasky -- dlhe */
				case '�': c = '�'; break;
				case '�': c = '�'; break;
				case '�': c = '�'; break;
				case '�': c = '�'; break;
				case '�': c = '�'; break;
				case '�': c = '�'; break;
				/* samohlasky -- specialne */
				case '�': c = '�'; break;
				case '�': c = '�'; break;
				case '�': c = '�'; break;
				case '�': c = '�'; break;
				/* spoluhlasky -- makke */
				case '�': c = '�'; break;
				case '�': c = '�'; break;
				case '�': c = '�'; break;
				case '�': c = '�'; break;
				case '�': c = '�'; break;
				case '�': c = '�'; break;
				case '�': c = '�'; break;
				case '�': c = '�'; break;
				/* spoluhlasky -- dlhe */
				case '�': c = '�'; break;
				case '�': c = '�'; break;
			}
		}
		if(_global_pom_str[i] != c)
			_global_pom_str[i] = c;
		i++;
	}
	return (_global_pom_str);
}

/* do globalneho stringu _global_link vrati retazec, ktory je linkou
 * na SCRIPT_NAME ++ ? zoznam param(i) = value(i)
 *
 * premenna typ oznacuje, ci ide o vypisanie tvaru (napr.)
 *         11. december 1999 (LINK_DEN_MESIAC_ROK)
 * alebo   11                (LINK_DEN)
 * alebo   'meno sviatku'    (default)
 * alebo   1999-12-11        (LINK_ISO_8601) - pridane 2005-03-21
 *
 */
void _vytvor_global_link(int den, int mesiac, int rok, int _case, int typ){
	/* 2003-07-09 zmeneny & na HTML_AMPERSAND kvoli HTML 4.01 */
	char pom[MAX_STR];

	mystrcpy(pom, STR_EMPTY, MAX_STR); /* 2003-08-11 pridana inicializacia */

	/* ak pozadujeme vytvorenie linku s inou farbou pre prestupny rok, 2003-07-02 */
	if(typ == LINK_DEN_MESIAC_ROK_PRESTUP)
		mystrcpy(_global_link, "<"HTML_LINK_RED" href=\"", MAX_GLOBAL_LINK); /* 2003-08-11 zmenene na mystrcpy(...,MAX_GLOBAL_LINK) */
	else /* inak normalny a href, toto tu bolo predtym; 2003-07-02 */
		mystrcpy(_global_link, "<"HTML_LINK_NORMAL" href=\"", MAX_GLOBAL_LINK); /* 2003-08-11 zmenene na mystrcpy(...,MAX_GLOBAL_LINK) */

	/* 13/04/2000A.D.: podla toho, co je v _global_linky, sa bud zobrazi
	 * to co klasicky (linka), alebo
	 * linka na subor FILE_NAME_POKEC + "d"/"m"/"r" + ".htm"
	 */
	if(_global_linky == ANO){
		/* linka ano */

		strcat(_global_link, script_name);

		/* query_type */
		sprintf(pom, "?%s=%s"HTML_AMPERSAND, STR_QUERY_TYPE, STR_PRM_DATUM);
		strcat(_global_link, pom);

		/* den */
		if(den == VSETKY_DNI)
			sprintf(pom, "%s=%s"HTML_AMPERSAND, STR_DEN, STR_VSETKY_DNI);
		else
			sprintf(pom, "%s=%d"HTML_AMPERSAND, STR_DEN, den);
		strcat(_global_link, pom);

		/* mesiac */
		if(mesiac == VSETKY_MESIACE)
			sprintf(pom, "%s=%s"HTML_AMPERSAND, STR_MESIAC, STR_VSETKY_MESIACE);
		else
			sprintf(pom, "%s=%d"HTML_AMPERSAND, STR_MESIAC, mesiac);
		strcat(_global_link, pom);

		/* rok */
		sprintf(pom, "%s=%d", STR_ROK, rok);
		strcat(_global_link, pom);

	}/* linka ano */
	else{ /* linka nie */
		strcat(_global_link, FILE_NAME_POKEC);
		if(mesiac == VSETKY_MESIACE){
			strcat(_global_link, "r");
		}
		else if(den == VSETKY_DNI){
			strcat(_global_link, "m");
		}
		else{
			strcat(_global_link, "d");
		}
		strcat(_global_link, ".htm");
	}/* linka nie */

	strcat(_global_link, "\">");

	/* napisanie textu linky */
	switch(typ){
		case LINK_DEN_MESIAC_ROK_PRESTUP: /* pridane 2003-07-02 */
		case LINK_DEN_MESIAC_ROK:
		case LINK_DEN_MESIAC:
			if(den == VSETKY_DNI){
				if(mesiac == VSETKY_MESIACE)
					sprintf(pom, "%d</a>", rok);
				else{
					switch(_case){
						case CASE_case:
							sprintf(pom, "%s", nazov_mesiaca[mesiac - 1]);
							break;
						case CASE_Case:
							sprintf(pom, "%s", nazov_Mesiaca[mesiac - 1]);
							break;
						case CASE_CASE:
							sprintf(pom, "%s", nazov_MESIACA[mesiac - 1]);
							break;
					}/* switch(_case) */
					if(typ == LINK_DEN_MESIAC_ROK){
						/* pridame aj rok */
						strcat(_global_link, pom);
						sprintf(pom, " %d", rok);
					}
					strcat(pom, "</a>");
				}/* mesiac != VSETKY_MESIACE */
			}/* if(den == VSETKY_DNI) */
			else{
				switch(_case){
					case CASE_case:
						sprintf(pom, "%d. %s", den, nazov_mesiaca[mesiac - 1]);
						break;
					case CASE_Case:
						sprintf(pom, "%d. %s", den, nazov_Mesiaca[mesiac - 1]);
						break;
					case CASE_CASE:
						sprintf(pom, "%d. %s", den, nazov_MESIACA[mesiac - 1]);
						break;
				}/* switch(_case) */
				if(typ == LINK_DEN_MESIAC_ROK){
					/* pridame aj rok */
					strcat(_global_link, pom);
					sprintf(pom, " %d", rok);
				}
				strcat(pom, "</a>");
			}/* den != VSETKY_DNI */
			break;
		case LINK_DEN:
				sprintf(pom, "%d</a>", den);
			break;
		case LINK_ISO_8601: /* 2005-31-21: Pridane */
				sprintf(pom, "%04d-%02d-%02d</a>", rok, mesiac, den);
			break;
		default:
				switch(_case){
					case CASE_case:
						sprintf(pom, "%s</a>", _global_den.meno);
						break;
					case CASE_Case:
						sprintf(pom, "%s</a>", _global_den.meno);
						break;
					case CASE_CASE:
						sprintf(pom, "%s</a>", caps_BIG(_global_den.meno));
						break;
				}/* switch(_case) */
			break;
	}/* switch(typ) */

	strcat(_global_link, pom);

}/* _vytvor_global_link(); */

/* vrati 1, ak je rok priestupny, inak vrati 0 */
int prestupny(int rok){
	if((rok MOD 4) == 0){
		if((rok MOD 100) == 0){
			return ((rok MOD 400) == 0);
		}
		else
			return 1;
	}
	else
		return 0;
}

int pocet_dni_v_roku(int rok){
	if(prestupny(rok))
		return POCET_DNI_V_ROKU + 1;
	else
		return POCET_DNI_V_ROKU;
}

/* vrati poradove cislo dna v roku,
 * 1.1. == 1, 2.1. == 2, ..., 31.12. == 365/366
 * ocakava cislo mesiaca 1-12 (pozn. 2003-07-04)
 */
int poradie(int den, int mesiac, int rok){
	if(mesiac > 2)
		return prvy_den[mesiac - 1] + den - 1 + prestupny(rok);
	else
		return prvy_den[mesiac - 1] + den - 1;
}

int poradie(_struct_den_mesiac den_a_mesiac, int rok){
	return poradie(den_a_mesiac.den, den_a_mesiac.mesiac, rok);
}

/* ------------------------------------------------------------------- */

/* Francuzsky vedec Joseph Scaliger vydal v roku 1583 traktat
 * "Nova praca o zdokonaleni letopoctu". Zaviedol juliansky datum
 * (podla svojho otca Juliusa), pricom zaciatok julianskej periody vzal
 * 1. januar roku 4713 pred Kr.
 *
 * 1. januar 1 po Kr. == 1721058 JD (podla julianskeho kalendara)
 * 1. januar 1920     == 2422325 JD
 * 1. januar 1968     == 2439857 JD
 */
long juliansky_datum(int por, int rok){
	int r;
	long jd = 0;
	if(rok >= ROK_1968){
		for(r = ROK_1968; r < rok; r++)
			jd = jd + pocet_dni_v_roku(r);
		return (jd + por + JUL_DATE_0_JAN_1968);
	}
	else{
		for(r = rok; r < ROK_1968; r++)
			jd = jd + pocet_dni_v_roku(r);
		return (por + JUL_DATE_0_JAN_1968 - jd);
	}
}

/* ocakava cislo mesiaca 1-12 (pozn. 2003-07-04) */
long juliansky_datum(int den, int mesiac, int rok){
	int por;
	por = poradie(den, mesiac, rok);
	return juliansky_datum(por, rok);
}

/* ------------------------------------------------------------------- */
/* nasledujuce funkcie zistuju datum velkonocnej nedele */

/* urcenie datumu VN podla Gaussovho pravidla */
_struct_den_mesiac velkonocna_nedela(int R){
	int x, y, k, q, p, a, b, c, d, e;
	_struct_den_mesiac result;

/* 1. urcenie konstant */
	/* juliansky kalendar: x = 15, y = 6 */
	/* gregoriansky kalendar: */
	k = R DIV 100;				/* DEBUG("k==%d", k); */
	q = k DIV 4;    			/* DEBUG("q==%d", q); */
	p = ((8 * k) + 13) DIV 25;  /* DEBUG("p==%d", p); */
	x = (15 - p + k - q) MOD 30;/* DEBUG("x==%d", x); */
	y = (4 + k - q) MOD 7;      /* DEBUG("y==%d", y); */
/* 2. samotny vypocet */
	a = R MOD 19;				/* DEBUG("a==%d", a); */
	b = R MOD 4;                /* DEBUG("b==%d", b); */
	c = R MOD 7;                /* DEBUG("c==%d", c); */
	d = (x + (19 * a)) MOD 30;  /* DEBUG("d==%d", d); */
	e = (y + (2 * b) + (4 * c) + (6 * d)) MOD 7;  /* DEBUG("e==%d", e); */
/* velkonocna nedela je (22 + d + e). marca == (d + e - 9). aprila */
	if((22 + d + e) > 31){
		result.den = d + e - 9;
		result.mesiac = 4; /* april */
	}
	else{
		result.den = 22 + d + e;
		result.mesiac = 3; /* marec */
	}
	return result;
}

/* vrati poradie velkonocnej nedele; 1.1. == 1, 31.12. == 365/366 */
int _velkonocna_nedela(int rok){
//	int vnd, vnm;
	_struct_den_mesiac result;

	result = velkonocna_nedela(rok);
	return poradie(result, rok);
}

/* ------------------------------------------------------------------- */
/* nasledujuce funkcie podla velkonocnej nedele urcia den v tyzdni */

/* vrati cislo dna v tyzdni zodpovedajuce datumu,
 * 0 == DEN_NEDELA, 1 == DEN_PONDELOK atd.
 */
int den_v_tyzdni(int por, int rok){
	int vn;
	vn  = _velkonocna_nedela(rok);
	return ((por MOD 7) + 7 - (vn MOD 7)) MOD 7;
}

int den_v_tyzdni(int den, int mesiac, int rok){
	int por;
	por = poradie(den, mesiac, rok);
	return den_v_tyzdni(por, rok);
}

int den_v_tyzdni(_struct_den_mesiac den_a_mesiac, int rok){
	return den_v_tyzdni(den_a_mesiac.den, den_a_mesiac.mesiac, rok);
}

/* ------------------------------------------------------------------- */
/* nasledujuce funkcie urcia nedelne pismeno/pismena roka resp. dna v roku */

/* vrati nedelne pismeno pre dany rok;
 * ak je rok prestupny, vracia PRVE nedelne pismeno,
 * DRUHE sa dostane tak, ze char_nedelne_pismeno[(PRVE + 6) MOD 7];
 * _nedelne_pismeno vrati ciselny udaj (0 -- 6), ktory je vstupom pre
 * konstantne pole char_nedelne_pismeno[]
 */
unsigned char _nedelne_pismeno(int rok){
	int vn;
	vn = _velkonocna_nedela(rok);
	return (char)((vn + 5) MOD 7); /* (char) pridane 01/03/2000A.D. */
}

char nedelne_pismeno(int rok){
	return char_nedelne_pismeno[_nedelne_pismeno(rok)];
}

/* vrati nedelne pismeno v tej casti roka, kde je den.mesiac.
 * to pre prestupny rok znamena, ze pocnuc 1. marcom je druhe nedelne pismeno
 */
unsigned char _nedelne_pismeno(int por, int rok){
 /* (char) pridane 01/03/2000A.D. */
	if((prestupny(rok)) && (por > poradie(29, MES_FEB + 1, rok)))
		return (char)((_nedelne_pismeno(rok) + 6) MOD 7);
	else
		return _nedelne_pismeno(rok);
}

char nedelne_pismeno(int por, int rok){
	return char_nedelne_pismeno[_nedelne_pismeno(por, rok)];
}

char nedelne_pismeno(int den, int mesiac, int rok){
	int por;
	por = poradie(den, mesiac, rok);
	return nedelne_pismeno(por, rok);
}

unsigned char _nedelne_pismeno(int den, int mesiac, int rok){
	int por;
	por = poradie(den, mesiac, rok);
	return _nedelne_pismeno(por, rok);
}

/* vrati nedelne pismeno v spravnej casti roka, ale neberie do uvahy
 * typ modlitby, t.j. ked su (prve) vespery, vrati zly den!!! pozor!!!
 */
unsigned char _nedelne_pismeno(_struct_den_mesiac den_a_mesiac, int rok){
	return
	_nedelne_pismeno(poradie(den_a_mesiac.den, den_a_mesiac.mesiac, rok), rok);
}

char nedelne_pismeno(_struct_den_mesiac den_a_mesiac, int rok){
	return char_nedelne_pismeno[_nedelne_pismeno(den_a_mesiac, rok)];
}

/* ------------------------------------------------------------------- */

/* z poradoveho cisla dna v roku urobi datum,
 * 1 == 1.1., 2 == 2.1., 32 == 1.2., ... 365 == 31.12./30.12.
 */
_struct_den_mesiac por_den_mesiac(int poradie, int rok){
	int d, m;
	_struct_den_mesiac result;

	if(prestupny(rok))
		pocet_dni[MES_FEB] = 29;
	else
		pocet_dni[MES_FEB] = 28;
	d = poradie;
	m = MES_JAN; /* januar */
	while(d > pocet_dni[m]){
		d = d - pocet_dni[m];
		m++;
	}
	result.den = d;
	result.mesiac = m + 1; /* vysledok: 1--12 */
	return result;
}

/* ------------------------------------------------------------------- */
/* nasledujuce int _...() funkcie vracaju poradove cislo dna v roku */

/* vrati poradove cislo dna, kt. zodpoveda sviatku sv. rodiny */
/* je to nedela v oktave pana alebo (ak padne narodenie pana na nedelu)
 * 30. decembra bez prvych vespier
 */
int _svatej_rodiny(int rok){
	int i;
	if(den_v_tyzdni(25, 12, rok) == DEN_NEDELA)
		return(poradie(30, 12, rok));
	else{
		i = poradie(25, 12, rok);
		while(den_v_tyzdni(i, rok) != DEN_NEDELA)
			i++;
		return i;
	}
}

/* vrati poradove cislo dna, kt. zodpoveda sviatku krstu krista pana */
/* je to nedela po zjaveni pana */
int _krst_krista_pana(int rok){
	int i = poradie(6, 1, rok) + 1;
	while(den_v_tyzdni(i, rok) != DEN_NEDELA)
		i++;
	return i;
}

/* popolcova streda je 46.-ty den pred velkou nocou, treba VN - 46 */
int _popolcova_streda(int rok){
	return (_velkonocna_nedela(rok) + OD_VELKEJ_NOCI_PO_POPOLCOVU_STR);
}

/* nanebovstupenie pana je 40.-ty den po velkej noci, treba VN + 39 */
int _nanebovstupenie(int rok){
	return (_velkonocna_nedela(rok) + OD_VELKEJ_NOCI_PO_NANEBOSTUPENIE);
}

/* zoslanie ducha sv. je 50.-ty den po velkej noci, treba VN + 49 */
int _zoslanie_ducha(int rok){
	return (_velkonocna_nedela(rok) + OD_VELKEJ_NOCI_PO_ZOSLANIE_DUCHA);
}

/* _prva_adventna_nedela() vrati poradove cislo dna, kt. zodpoveda
 * 		prvej adventnej nedeli;
 * prva_adventna_nedela() vracia strukturu (datum) prvej adv. nedele
 */
int _prva_adventna_nedela(int rok){
	char p;
	_struct_den_mesiac datum;

	/* volime 1.3.rok */
	datum.den = 1;
	datum.mesiac = 3;
	/* po februari, pretoze potrebujeme DRUHE nedelne pismeno */
	p = _nedelne_pismeno(datum, rok);
	return (PRVA_ADVENTNA_NEDELA_b + p + prestupny(rok));
}

/* ------------------------------------------------------------------- */
/* nasledujuce _struct_den_mesiac ...() funkcie vracaju <den, mesiac> */

_struct_den_mesiac prva_adventna_nedela(int rok){
	return (por_den_mesiac(_prva_adventna_nedela(rok), rok));
}

/* ------------------------------------------------------------------- */

/* vrati 0 == rok A, 1 == rok B, 2 == rok C */
/* pozor!
 * neuvazujeme o tom, ze vecer toho dna su prve vespery z dalsieho dna,
 * ktory uz moze byt inym liturgickym rokom. to nie je osetrene ani
 * vo funkcii nedelny_cyklus(_struct_den_mesiac, int);
 */
int nedelny_cyklus(int por, int rok){
	_struct_den_mesiac pan;
	int porpan;
	pan = prva_adventna_nedela(rok);
	porpan = poradie(pan.den, pan.mesiac, rok);
	if(por < porpan)
		return ((rok - 1) MOD 3);
	else
		return (rok MOD 3);
}

int nedelny_cyklus(int den, int mesiac, int rok){
	int por;
	por = poradie(den, mesiac, rok);
	return nedelny_cyklus(por, rok);
}

int nedelny_cyklus(_struct_den_mesiac den_a_mesiac, int rok){
	return
	nedelny_cyklus(poradie(den_a_mesiac.den, den_a_mesiac.mesiac, rok), rok);
}

/* z poradoveho cisla dna v roku urobi datum,
 * 1 == 1.1., 2 == 2.1., 32 == 1.2., ... 365 == 31.12./30.12.
 * zapise tiez do _struct_dm tieto polozky:
 *    .den, .mesiac, .rok, .denvr, .denvt, .link, .litrok
 */
_struct_dm por_den_mesiac_dm(int poradie, int rok){
	_struct_den_mesiac pom;
	_struct_dm result;

	pom = por_den_mesiac(poradie, rok);
	result.den = pom.den;
	result.mesiac = pom.mesiac;
	result.rok = rok;
	result.denvr = poradie;
	result.denvt = den_v_tyzdni(poradie, rok);
	result.litrok  = (char)('A' + nedelny_cyklus(pom.den, pom.mesiac, rok));
		/* (char) pridane 01/03/2000A.D. */
	/* dalsia cast pridana kvoli tomu, aby nic nebolo nedefinovane :-) 
	 * 27/04/2000A.D.
	 */
	result.tyzden = 0;
	result.tyzzal = 0;    
	result.litobd = OBD_CEZ_ROK; /* nemam neurcene... */
	result.typslav = SLAV_NEURCENE;
	result.smer = 14; /* neurcene */
	result.prik = NEPRIKAZANY_SVIATOK;
	result.spolcast =
		_encode_spol_cast(MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA);
	mystrcpy(result.meno, STR_EMPTY, MENO_SVIATKU); /* 2003-08-11 zmenena na mystrcpy */
	return result;
}

/* ------------------------------------------------------------------- */

/* vrati cislo tyzdna v obdobi cez rok, ktory nasleduje po nedeli zoslania
 * ducha sv. - teda po konci velkonocneho obdobia
 */
int tyzden_cez_rok_po_vn(int rok){
	int zds, pan;

	pan = _prva_adventna_nedela(rok);
	zds = _zoslanie_ducha(rok);
	return (POCET_NEDIEL_CEZ_ROK - ((pan - zds) DIV 7));
}

int cislo_nedele_cez_rok_po_vn(int rok){
	return (tyzden_cez_rok_po_vn(rok) + 1);
}

/* naplni strukturu _global_pm_sobota, ale az vtedy, ked v _global_den su
 * spravne udaje
 */
void init_global_pm_sobota(void){
	_global_pm_sobota.den = _global_den.den;
	_global_pm_sobota.mesiac = _global_den.mesiac;
	_global_pm_sobota.rok = _global_den.rok;
	_global_pm_sobota.denvt = _global_den.denvt;
	_global_pm_sobota.denvr = _global_den.denvr;
	_global_pm_sobota.litobd = _global_den.litobd;
	_global_pm_sobota.litrok = _global_den.litrok;
	_global_pm_sobota.tyzden = _global_den.tyzden;
	_global_pm_sobota.tyzzal = _global_den.tyzzal;
	/* a teraz vlastne udaje */
	_global_pm_sobota.smer = 12; /* lubovolna spomienka */
	_global_pm_sobota.typslav = SLAV_LUB_SPOMIENKA; /* lubovolna spomienka */
	_global_pm_sobota.typslav_lokal = LOKAL_SLAV_NEURCENE; /* nie je obmedzenie na lokalitu, pridan� 2005-07-27 */
	mystrcpy(_global_pm_sobota.meno, "Spomienka Panny M�rie v sobotu", MENO_SVIATKU); /* 2003-08-11 zmenena na mystrcpy */
	_global_pm_sobota.prik    = NEPRIKAZANY_SVIATOK; /* pridane 27/04/2000A.D. */
	_global_pm_sobota.spolcast = /* pridane 27/04/2000A.D. */
		_encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA, MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA);
}

/* ------------------------------------------------------------------- */
/* nasledujuce void _dm_...() funkcie strukturu dm zapisu do _global_result */
void _dm_popolcova_streda(int rok, int _vn){

	/* v tomto kroku sa zapisu:
	 * .den, .mesiac, .rok, .link, .denvt, .denvr, .litrok */
	_global_result = por_den_mesiac_dm(_vn + OD_VELKEJ_NOCI_PO_POPOLCOVU_STR, rok);
	_global_result.typslav = SLAV_NEURCENE;
	_global_result.typslav_lokal = LOKAL_SLAV_NEURCENE; /* nie je obmedzenie na lokalitu, pridan� 2005-07-27 */
	_global_result.litobd  = OBD_POSTNE_I;
	_global_result.tyzden  = 0; /* 4. tyzden zaltara */
	_global_result.smer    = 2;
	_global_result.prik    = NEPRIKAZANY_SVIATOK; /* pridane 06/03/2000A.D. */
	mystrcpy(_global_result.meno, "Popolcov� streda", MENO_SVIATKU); /* 2003-08-11 zmenena na mystrcpy */
	_global_result.tyzzal  = 4; /* pridane 06/03/2000A.D. */
	_global_result.spolcast= /* pridane 06/03/2000A.D. */
		_encode_spol_cast(MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA);
}

void _dm_nanebovstupenie(int rok, int _vn){
	/* v tomto kroku sa zapisu:
	 * .den, .mesiac, .rok, .link, .denvt, .denvr, .litrok */
	_global_result = por_den_mesiac_dm(_vn + OD_VELKEJ_NOCI_PO_NANEBOSTUPENIE, rok);
	_global_result.typslav = SLAV_SLAVNOST;
	_global_result.typslav_lokal = LOKAL_SLAV_NEURCENE; /* nie je obmedzenie na lokalitu, pridan� 2005-07-27 */
	_global_result.litobd  = OBD_VELKONOCNE_I; /* ma vlastne slavenie */
	_global_result.tyzden  = 0; /* pridane kvoli kotvam vo fajli FILE_NANEBOVSTUPENIE, 10/03/2000A.D. */
	_global_result.tyzzal  = 1; /* pridane 27/04/2000A.D., aby tam nebolo 'hausnumero' */
	_global_result.smer    = 2;
	_global_result.prik    = PRIKAZANY_SVIATOK;
	mystrcpy(_global_result.meno, "Nanebovst�penie P�na", MENO_SVIATKU); /* 2003-08-11 zmenena na mystrcpy */
	_global_result.spolcast= /* pridane 06/03/2000A.D. */
		_encode_spol_cast(MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA);
}

void _dm_zoslanie_ducha(int rok, int _vn){
	/* v tomto kroku sa zapisu:
	 * .den, .mesiac, .rok, .link, .denvt, .denvr, .litrok */
	_global_result = por_den_mesiac_dm(_vn + OD_VELKEJ_NOCI_PO_ZOSLANIE_DUCHA, rok);
	_global_result.typslav = SLAV_SLAVNOST;
	_global_result.typslav_lokal = LOKAL_SLAV_NEURCENE; /* nie je obmedzenie na lokalitu, pridan� 2005-07-27 */
	_global_result.litobd  = OBD_VELKONOCNE_II; /* ma vlastne slavenie */
	_global_result.tyzden  = 0; /* pridane kvoli kotvam vo fajli FILE_ZOSLANIE_DUCHA_SV, 10/03/2000A.D. */
	_global_result.tyzzal  = 1; /* pridane 27/04/2000A.D., aby tam nebolo 'hausnumero' */
	_global_result.smer    = 2;
	_global_result.prik    = PRIKAZANY_SVIATOK;
	mystrcpy(_global_result.meno, "Zoslanie Ducha Sv�t�ho", MENO_SVIATKU); /* 2003-08-11 zmenena na mystrcpy */
	_global_result.spolcast= /* pridane 06/03/2000A.D. */
		_encode_spol_cast(MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA);
}

void _dm_prva_adventna_nedela(int rok, int p2){
	/* v tomto kroku sa zapisu:
	 * .den, .mesiac, .rok, .link, .denvt, .denvr, .litrok */
	_global_result = por_den_mesiac_dm(PRVA_ADVENTNA_NEDELA_b + p2 + prestupny(rok), rok);
	_global_result.typslav = SLAV_VLASTNE;
	_global_result.typslav_lokal = LOKAL_SLAV_NEURCENE; /* nie je obmedzenie na lokalitu, pridan� 2005-07-27 */
	_global_result.litobd  = OBD_ADVENTNE_I;
	_global_result.tyzden  = 1; /* 1. adventna nedela */
	_global_result.smer    = 2;
	_global_result.prik    = NEPRIKAZANY_SVIATOK; /* pridane 06/03/2000A.D. */
	mystrcpy(_global_result.meno, "Prv� adventn� nede�a", MENO_SVIATKU); /* 2003-08-11 zmenena na mystrcpy */
	_global_result.spolcast= /* pridane 06/03/2000A.D. */
		_encode_spol_cast(MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA);
	_global_result.tyzzal  = 1; /* pridane 27/04/2000A.D. */
}

void _dm_svatej_rodiny(int rok){
	/* v tomto kroku sa zapisu:
	 * .den, .mesiac, .rok, .link, .denvt, .denvr, .litrok */
	int _svrod;
	if(den_v_tyzdni(25, 12, rok) == DEN_NEDELA)
		_svrod = poradie(30, 12, rok);
	else{
		_svrod = poradie(25, 12, rok);
		while(den_v_tyzdni(_svrod, rok) != DEN_NEDELA)
			_svrod++;
	}
	_global_result = por_den_mesiac_dm(_svrod, rok);
	_global_result.typslav = SLAV_SVIATOK;
	_global_result.typslav_lokal = LOKAL_SLAV_NEURCENE; /* nie je obmedzenie na lokalitu, pridan� 2005-07-27 */
	_global_result.litobd  = OBD_OKTAVA_NARODENIA;
	_global_result.smer    = 5;
	_global_result.tyzden  = 1; /* 1. tyzden vianocneho obdobia, oktava */
	_global_result.prik    = NEPRIKAZANY_SVIATOK; /* pridane 06/03/2000A.D. */
	mystrcpy(_global_result.meno, "Sv�tej rodiny Je�i�a, M�rie a Jozefa", MENO_SVIATKU); /* 2003-08-11 zmenena na mystrcpy */
	_global_result.spolcast= /* pridane 06/03/2000A.D. */
		_encode_spol_cast(MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA);
	_global_result.tyzzal  = 1; /* pridane 27/04/2000A.D. */
}

void _dm_krst_krista_pana(int rok){
	/* v tomto kroku sa zapisu:
	 * .den, .mesiac, .rok, .link, .denvt, .denvr, .litrok */
	int _krst = poradie(6, 1, rok) + 1;
	while(den_v_tyzdni(_krst, rok) != DEN_NEDELA)
		_krst++;
	_global_result = por_den_mesiac_dm(_krst, rok);
	_global_result.typslav = SLAV_SVIATOK;
	_global_result.typslav_lokal = LOKAL_SLAV_NEURCENE; /* nie je obmedzenie na lokalitu, pridan� 2005-07-27 */
	_global_result.litobd  = OBD_CEZ_ROK;
	_global_result.tyzden  = 1; /* 1. nedela "cez rok" */
	_global_result.smer    = 5;
	mystrcpy(_global_result.meno, "Krst Krista P�na", MENO_SVIATKU); /* 2003-08-11 zmenena na mystrcpy */
	_global_result.spolcast= /* pridane 06/03/2000A.D. */
		_encode_spol_cast(MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA);
	_global_result.prik    = NEPRIKAZANY_SVIATOK; /* pridane 27/04/2000A.D. */
	_global_result.tyzzal  = 1; /* pridane 27/04/2000A.D. */
}

void _dm_velkonocna_nedela(int rok, int _vn){
	/* v tomto kroku sa zapisu:
	 * .den, .mesiac, .rok, .link, .denvt, .denvr, .litrok */
	_global_result = por_den_mesiac_dm(_vn, rok);
	_global_result.typslav = SLAV_SLAVNOST;
	_global_result.typslav_lokal = LOKAL_SLAV_NEURCENE; /* nie je obmedzenie na lokalitu, pridan� 2005-07-27 */
	_global_result.litobd  = OBD_VELKONOCNE_TROJDNIE;
	_global_result.tyzden  = 1; /* 1. velkonocna nedela */
	_global_result.smer    = 1;
	mystrcpy(_global_result.meno, "Ve�kono�n� nede�a - Nede�a P�novho zm�tvychvstania", MENO_SVIATKU); /* 2003-08-11 zmenena na mystrcpy */
	_global_result.spolcast= /* pridane 06/03/2000A.D. */
		_encode_spol_cast(MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA);
	_global_result.prik    = NEPRIKAZANY_SVIATOK; /* pridane 27/04/2000A.D. */
	_global_result.tyzzal  = 1; /* pridane 27/04/2000A.D. */
}

/* pridana 2003-08-07 */
/* zapoznamkovana 2003-08-11 */
#undef ZAPOZNAMKOVANE_2003_08_11
#ifdef ZAPOZNAMKOVANE_2003_08_11
void _init_dm(_struct_dm a){
	a.den = 0;        /* cislo dna mesiaca (1--31) */
	a.mesiac = 0;     /* cislo mesiaca (1--12) */
	a.rok = 0;        /* rok */
	a.denvt = -1;     /* cislo dna v tyzdni (0--6) DEN_... */ /* de� v roku */
	a.denvr = 0;      /* cislo dna v roku (1--365/366) */
	a.litrok = 0;     /* liturgicky rok ('A'--'C') */
	a.tyzden = 0;     /* tyzden v danom liturgickom obdobi */
	a.tyzzal = 0;     /* tyzden v zaltari (vacsinou ((tyzden - 1) % 4) + 1) */
	a.litobd = -1;    /* liturgicke obdobie, OBD_... */
	a.typslav = 0;    /* typ slavenia (1--5): SLAV_... */
	a.typslav_lokal = 0; /* LOKAL_SLAV_NEURCENE; nie je obmedzenie na lokalitu, pridan� 2005-07-27 */
	a.smer = 100;     /* poradove cislo z c.59 Vseobecnych smernic
	                   * o liturgii hodin a kalendari */
	a.prik = -1;      /* ci je to prikazany sviatok alebo nie:
				       * PRIKAZANY_SVIATOK resp. NEPRIKAZANY_SVIATOK */
	a.spolcast = -1;  /* spolocna cast -- pridane 09/02/2000A.D.,
					   * zakodovane data pre svatych o tom, z akej spolocnej
					   * casti sa ma modlit */
	mystrcpy(a.meno, STR_EMPTY, MENO_SVIATKU); /* nazov prip. sviatku */
}
#endif

/* ------------------------------------------------------------------- */
/* analyzuj_rok()
 *
 * vstup:  int year
 * vystup: do globalnej premennej struct lrok _global_r da jednotlive vyznacne dni
 *         a ostatne data (prestupny, p1, p2, litrok, tyzden_ocr_po_vn, _den[]
 */
/* logovanie: 01/03/2000A.D. */
void analyzuj_rok(int year){
	int _vn; /* poradie velkonocnej nedele */
	_struct_den_mesiac vn; /* datum velkonocnej nedele */
	int p1, p2; /* nedelne pismena */

	Log("analyzuj_rok(%d) -- begin\n", year);
	vn = velkonocna_nedela(year);
	_vn = poradie(vn, year);

	/* ci je rok prestupny */
	if(prestupny(year))
		_global_r.prestupny = YES;
	else
		_global_r.prestupny = NO;

	/* urcime nedele pismena */
	p1 = ((_vn + 5) MOD 7);
	p2 = (_global_r.prestupny == YES)?
			((p1 + 6) MOD 7): /* ak je rok prestupny, ma dve nedelne pismena */
			p1;               /* inak p1 == p2 */
	/* teraz znaky (char) */
	_global_r.p1 = char_nedelne_pismeno[p1];
	_global_r.p2 = (_global_r.prestupny == YES)?
		char_nedelne_pismeno[p2]:
		NIJAKE_NEDELNE_PISMENO;

	/* slavnosti a sviatky */
	_dm_krst_krista_pana    (year);      _global_r._KRST_KRISTA_PANA     = _global_result;
	_dm_popolcova_streda    (year, _vn); _global_r._POPOLCOVA_STREDA     = _global_result;
	_dm_velkonocna_nedela   (year, _vn); _global_r._VELKONOCNA_NEDELA    = _global_result;
	_dm_nanebovstupenie     (year, _vn); _global_r._NANEBOVSTUPENIE_PANA = _global_result;
	_dm_zoslanie_ducha      (year, _vn); _global_r._ZOSLANIE_DUCHA_SV    = _global_result;
	_dm_prva_adventna_nedela(year, p2);  _global_r._PRVA_ADVENTNA_NEDELA = _global_result;
	_dm_svatej_rodiny       (year);      _global_r._SVATEJ_RODINY        = _global_result;

	/* cislo nedele obdobia "cez rok" po velkej noci */
	_global_r.tyzden_ocr_po_vn = (POCET_NEDIEL_CEZ_ROK -
		( (_global_r._PRVA_ADVENTNA_NEDELA.denvr - _global_r._ZOSLANIE_DUCHA_SV.denvr)
		  DIV 7) ) + 1;

	/* cislo tyzdna obdobia "cez rok" pred postom, kedy zacina post; 15/03/2000A.D. */
	_global_r.tyzden_ocr_pred_po = 
		((_global_r._POPOLCOVA_STREDA.denvr - _global_r._KRST_KRISTA_PANA.denvr)
			DIV 7) + 1;

	Log("analyzuj_rok(%d) -- end\n", year);
}/* analyzuj_rok(); */

/* pridane Log-ovacie utilitky pre rozne datove struktury */

void Log(_struct_lrok r){ /* 01/03/2000A.D. */
	Log_struktura_rok("struktura liturgicky rok:\n");
	Log_struktura_rok("   prestupny: %s\n", (r.prestupny == YES)? "ANO":"NIE");
	Log_struktura_rok("   p1, p2: %c, %c\n", r.p1, r.p2);
	Log_struktura_rok("   litrok: %c\n", r.litrok);
	Log_struktura_rok("   tyzden_ocr_po_vn: %d\n", r.tyzden_ocr_po_vn);
	Log_struktura_rok("   struct dm _den[POCET_ALIASOV]:\n");
	Log_struktura_rok("   _KRST_KRISTA_PANA         :\n"); Log(r._den[KRST_KRISTA_PANA]);
	Log_struktura_rok("   _POPOLCOVA_STREDA         :\n"); Log(r._den[POPOLCOVA_STREDA]);
	Log_struktura_rok("   _VELKONOCNA_NEDELA        :\n"); Log(r._den[VELKONOCNA_NEDELA]);
	Log_struktura_rok("   _NANEBOVSTUPENIE_PANA     :\n"); Log(r._den[NANEBOVSTUPENIE_PANA]);
	Log_struktura_rok("   _PRVA_ADVENTNA_NEDELA     :\n"); Log(r._den[PRVA_ADVENTNA_NEDELA]);
	Log_struktura_rok("   _ZOSLANIE_DUCHA_SV        :\n"); Log(r._den[ZOSLANIE_DUCHA_SV]);
	Log_struktura_rok("   _SVATEJ_RODINY            :\n"); Log(r._den[SVATEJ_RODINY]);
}

void Log(_struct_dm g){
	Log_struktura_dm("struktura dm:\n");
	Log_struktura_dm("   den:    %d\n", g.den);
	Log_struktura_dm("   mesiac: %s\n", nazov_mesiaca[g.mesiac - 1]);
	Log_struktura_dm("   rok:    %d\n", g.rok);
	Log_struktura_dm("   denvt:  %s\n", nazov_dna[g.denvt]);
	Log_struktura_dm("   denvr:  %d\n", g.denvr);
	/* toto boli "obcianske" zalezitosti */
	Log_struktura_dm("   litrok: %c\n", g.litrok);
	Log_struktura_dm("   tyzden: %d\n", g.tyzden);
	Log_struktura_dm("   tyzzal: %d\n", g.tyzzal);
	Log_struktura_dm("   litobd: %s\n", nazov_obdobia_[g.litobd]); // nazov_obdobia_
	Log_struktura_dm("   typslav:%s\n", nazov_slavenia[g.typslav]);
	/* 2005-07-27: doplnen� typslav_lokal */
	Log_struktura_dm("   typslav_lokal: %s\n", nazov_slavenia_lokal[g.typslav_lokal]);	
	Log_struktura_dm("   smer:   %d\n", g.smer);
	Log_struktura_dm("   prik:   %d\n", g.prik);
	Log_struktura_dm("   meno:   %s\n", g.meno);
	_struct_sc sc = _decode_spol_cast(g.spolcast);
	Log_struktura_dm("   spolcast: %s, %s, %s\n",
		nazov_spolc[sc.a1], nazov_spolc[sc.a2], nazov_spolc[sc.a3]);
}

void Log(struct tmodlitba1 t){
	Log_struktura_tm1("struktura tmodlitba1:\n");
	Log_struktura_tm1("   popis           file `%s', anchor `%s'\n", t.popis.file, t.popis.anchor);
	Log_struktura_tm1("   hymnus          file `%s', anchor `%s'\n", t.hymnus.file, t.hymnus.anchor);
	Log_struktura_tm1("   antifona1       file `%s', anchor `%s'\n", t.antifona1.file, t.antifona1.anchor);
	Log_struktura_tm1("   zalm1           file `%s', anchor `%s'\n", t.zalm1.file, t.zalm1.anchor);
	Log_struktura_tm1("   antifona2       file `%s', anchor `%s'\n", t.antifona2.file, t.antifona2.anchor);
	Log_struktura_tm1("   zalm2           file `%s', anchor `%s'\n", t.zalm2.file, t.zalm2.anchor);
	Log_struktura_tm1("   antifona3       file `%s', anchor `%s'\n", t.antifona3.file, t.antifona3.anchor);
	Log_struktura_tm1("   zalm3           file `%s', anchor `%s'\n", t.zalm3.file, t.zalm3.anchor);
	Log_struktura_tm1("   kcitanie (c1)   file `%s', anchor `%s'\n", t.kcitanie.file, t.kcitanie.anchor);
	Log_struktura_tm1("   kresponz        file `%s', anchor `%s'\n", t.kresponz.file, t.kresponz.anchor);
	Log_struktura_tm1("   bened/mag (c2)  file `%s', anchor `%s'\n", t.benediktus.file, t.benediktus.anchor); /* antifona na benediktus/magnifikat */
	Log_struktura_tm1("   prosby          file `%s', anchor `%s'\n", t.prosby.file, t.prosby.anchor);
	Log_struktura_tm1("   modlitba        file `%s', anchor `%s'\n", t.modlitba.file, t.modlitba.anchor);
}

void Log(struct tmodlitba2 t){
	Log_struktura_tm2("struktura tmodlitba2:\n");
	Log_struktura_tm2("   popis        file `%s', anchor `%s'\n", t.popis.file, t.popis.anchor);
	Log_struktura_tm2("   hymnus       file `%s', anchor `%s'\n", t.hymnus.file, t.hymnus.anchor);
	Log_struktura_tm2("   antifona1    file `%s', anchor `%s'\n", t.antifona1.file, t.antifona1.anchor);
	Log_struktura_tm2("   zalm1        file `%s', anchor `%s'\n", t.zalm1.file, t.zalm1.anchor);
	Log_struktura_tm2("   antifona2    file `%s', anchor `%s'\n", t.antifona2.file, t.antifona2.anchor);
	Log_struktura_tm2("   zalm2        file `%s', anchor `%s'\n", t.zalm2.file, t.zalm2.anchor);
	Log_struktura_tm2("   antifona3    file `%s', anchor `%s'\n", t.antifona3.file, t.antifona3.anchor);
	Log_struktura_tm2("   zalm3        file `%s', anchor `%s'\n", t.zalm3.file, t.zalm3.anchor);
	Log_struktura_tm2("   kcitanie     file `%s', anchor `%s'\n", t.kcitanie.file, t.kcitanie.anchor);
	Log_struktura_tm2("   kresponz     file `%s', anchor `%s'\n", t.kresponz.file, t.kresponz.anchor);
	Log_struktura_tm2("   modlitba     file `%s', anchor `%s'\n", t.modlitba.file, t.modlitba.anchor);
}

/*---------------------------------------------------------------------*/
/* popis:
 *
 * int _struct_dm::spolcast obsahuje zakodovane data pre svatych o tom,
 * z akej spolocnej casti sa ma modlit;
 * obsahuje max. 3 spolocne casti vo formate
 *
 * spolcast == a1 + a2 * MAX + a3 * MAX * MAX,
 *
 * kde
 * - MAX je MAX_MODL_SPOL_CAST,
 * - a1, a2, a3 su konstanty MODL_SPOL_CAST_...
 *   (v poradi a1, ak druhe tak a2, ak tretie tak aj a3)
 *
 * _encode_..., _decode_spol_cast(); robia tuto konverziu
 *
 */
int _encode_spol_cast(int a1, int a2, int a3){
	return(a1 + a2 * MAX_MODL_SPOL_CAST + a3 * MAX_MODL_SPOL_CAST * MAX_MODL_SPOL_CAST);
}
int _encode_spol_cast(int a1, int a2){
	return _encode_spol_cast(a1, a2, MODL_SPOL_CAST_NEURCENA);
}
int _encode_spol_cast(int a1){
	return _encode_spol_cast(a1, MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA);
}
_struct_sc _decode_spol_cast(int spolc){
	_struct_sc ret;
	ret.a3 = spolc DIV (MAX_MODL_SPOL_CAST * MAX_MODL_SPOL_CAST);
	ret.a2 = (spolc MOD (MAX_MODL_SPOL_CAST * MAX_MODL_SPOL_CAST)) DIV MAX_MODL_SPOL_CAST;
	ret.a1 = (spolc MOD (MAX_MODL_SPOL_CAST * MAX_MODL_SPOL_CAST)) MOD MAX_MODL_SPOL_CAST;
	return ret;
}



#endif /* __LITURGIA_C_ */

