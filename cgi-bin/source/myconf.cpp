/******************************************************************/
/*                                                                */
/* myconf.cpp                                                     */
/* (c)1999-2010 | Juraj Videky | videky@breviar.sk                */
/*                                                                */
/*                                                                */
/* description | poskytuje rozhranie na konfiguraciu,             */
/*               subor CONFIG_FILE                                */
/* document history                                               */
/*   30/03/2000A.D. | created                                     */
/*   06/09/2001A.D. | tento popis                                 */
/*   2003-07-08a.D. | MAIL_ADDRESS zmenena na videky@breviar.sk   */
/*   2003-08-13a.D. | pridany #include "mystring.h"               */
/*   2004-03-17a.D. | pridany INCLUDE_DIR                         */
/*   2006-07-13a.D. | prve kroky k jazykovym mutaciam             */
/*   2007-05-24a.D. | Marek Elias (MEL): pouzitie libconfuse      */
/*   2007-06-01a.D. | prepracovanie konfigurovatelnych premennych */
/*   2007-06-19a.D. | odstr·nenÈ pouûitie libconfuse (MEL, JUV)   */
/*                                                                */
/*                                                                */
/******************************************************************/

#undef LOG_READCONFIG

#include "vstudio.h"

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "myconf.h"
#include "mystring.h"
#include "mysystem.h"
#include "mylog.h"
#include "mydefs.h"

char cfg_HTTP_ADDRESS_default[MAX_HTTP_STR] = "http://www.breviar.sk/";
char cfg_HTTP_DISPLAY_ADDRESS_default[MAX_HTTP_STR] = "http://www.breviar.sk/";
char cfg_MAIL_ADDRESS_default[MAX_MAIL_STR] = "videky@breviar.sk";
char cfg_INCLUDE_DIR_default[MAX_INCD_STR] = "../include/";

/* hodnoty options pre default jazyk, teda pre JAZYK_SK */
short int cfg_option1_default;
short int cfg_option2_default;
short int cfg_option4_default;
short int cfg_option5_default;
short int cfg_option6_default;
short int cfg_option7_default;
/* hodnoty options pre JAZYK_CZ */
short int cfg_option1_cz;
short int cfg_option2_cz;
short int cfg_option4_cz;
short int cfg_option5_cz;
short int cfg_option6_cz;
short int cfg_option7_cz;

void printConfigOptions(void){
	/* hodnoty options pre default jazyk, teda pre JAZYK_SK */
	Log("=== SK: Hodnoty option parametrov pre JAZYK_SK ===\n");
	Log("cfg_option1_default == `%d'\n", cfg_option1_default);
	Log("cfg_option2_default == `%d'\n", cfg_option2_default);
	Log("cfg_option4_default == `%d'\n", cfg_option4_default);
	Log("cfg_option5_default == `%d'\n", cfg_option5_default);
	Log("cfg_option6_default == `%d'\n", cfg_option6_default);
	Log("cfg_option7_default == `%d'\n", cfg_option7_default);
	/* hodnoty options pre JAZYK_CZ */
	Log("=== CZ: Hodnoty option parametrov pre JAZYK_CZ ===\n");
	Log("cfg_option1_cz == `%d'\n", cfg_option1_cz);
	Log("cfg_option2_cz == `%d'\n", cfg_option2_cz);
	Log("cfg_option4_cz == `%d'\n", cfg_option4_cz);
	Log("cfg_option5_cz == `%d'\n", cfg_option5_cz);
	Log("cfg_option6_cz == `%d'\n", cfg_option6_cz);
	Log("cfg_option7_cz == `%d'\n", cfg_option7_cz);
}

void readConfig(void)
{
	FILE* subor = NULL;
	char option[MAX_OPTION_LENGTH];
	char hodnota[MAX_VALUE_LENGTH];
	int znak = '\0';
	int i = 0;

	if(! (subor = fopen(CONFIG_FILE, "r")) ){
		Log("NemÙûem otvoriù s˙bor `%s'.\n", CONFIG_FILE);
		return;
	}
	else{
		Log("S˙bor `%s' otvoren˝.\n", CONFIG_FILE);
	}

	for (; (znak = fgetc(subor)) != EOF;)
	{
		if (znak == '#'){
#ifdef LOG_READCONFIG
			Log("Parsujem pozn·mku...\n");
#endif
			while((znak = fgetc(subor)) != EOF && (znak != '\n') ); // parsuj pozn·mku do konca riadka
			if(znak == EOF){ 
				Log("EOF... break.\n");
				break; 
			}
			continue;
		}

		if (isspace(znak)){
			continue;
		}

		mystrcpy(option, STR_EMPTY, MAX_OPTION_LENGTH);
		// naËÌta maxim·lne MAX_OPTION_LENGTH znakov (mÌnus medzery, ktorÈ ignoruje)
		for(i = 0; (znak != EOF) && (znak != '\n') && (znak != '=') && (i < (MAX_OPTION_LENGTH - 1)); znak = fgetc(subor), ++i)
		{
#ifdef LOG_READCONFIG
			Log("znak == `%c'\n", znak);
#endif
			if(znak == ' ') // v prÌpade medzery preskoË, ËÌtaj Ôalej
				// aby tu mohlo byù znak = fgetc(subor); je potrebnÈ, aby sme skontrolovali, Ëi nie sme na konci
				i--;
			else{
#ifdef LOG_READCONFIG
				Log("i == %d\n", i);
#endif
				option[i] = znak;
			}
		}
		option[i] = '\0';

		if (znak != '='){continue;}
		if (znak == EOF){
			Log("EOF... break.\n");
			break;
		}

		if ((znak = fgetc(subor)) == '"'){
			znak = fgetc(subor);
		}
		else if(znak == EOF){
			Log("EOF... break.\n");
			break;
		}

		mystrcpy(hodnota, STR_EMPTY, MAX_VALUE_LENGTH);
		// naËÌta maxim·lne MAX_OPTION_LENGTH znakov (mÌnus medzery, ktorÈ ignoruje)
		for(i = 0; (znak != EOF) && (znak != '\n') && (znak != '"') && (i < (MAX_HTTP_STR - 1)); znak = fgetc(subor), ++i)
		{
#ifdef LOG_READCONFIG
			Log("znak == `%c'\n", znak);
#endif
			if(znak == ' ') // v prÌpade medzery preskoË, ËÌtaj Ôalej
				// aby tu mohlo byù znak = fgetc(subor); je potrebnÈ, aby sme skontrolovali, Ëi nie sme na konci
				i--;
			else{
#ifdef LOG_READCONFIG
				Log("i == %d\n", i);
#endif
				hodnota[i] = znak;
			}
		}
		hodnota[i] = '\0';

		Log("Parsovan· option  == `%s'\n", option);
		Log("Parsovan· hodnota == `%s'\n", hodnota);
		if (!strcmp(option, "http_adresa_def")){
			strncpy(cfg_HTTP_ADDRESS_default, hodnota, MAX_HTTP_STR);
		} else if (!strcmp(option, "http_zobraz_adr_def")){
			strcpy(cfg_HTTP_DISPLAY_ADDRESS_default, hodnota);
		} else if (!strcmp(option, "mail_adresa_def")){
			strcpy(cfg_MAIL_ADDRESS_default, hodnota);
		} else if (!strcmp(option, "incldir_def")){
			strcpy(cfg_INCLUDE_DIR_default, hodnota);
		} else if (!strcmp(option, "pevne_casti_modl_def")){
			if(isdigit(hodnota[0])){
				cfg_option1_default = atoi(hodnota);
			}
		} else if (!strcmp(option, "zalmy_zo_dna_def")){
			if(isdigit(hodnota[0])){
				cfg_option2_default = atoi(hodnota);
			}
		} else if (!strcmp(option, "popis_pri_modlitbe_def")){
			if(isdigit(hodnota[0])){
				cfg_option4_default = atoi(hodnota);
			}
		} else if (!strcmp(option, "mcd_zalmy_doplnkpsalm_def")){
			if(isdigit(hodnota[0])){
				cfg_option5_default = atoi(hodnota);
			}
		} else if (!strcmp(option, "expt_viac_dni_simple_def")){
			if(isdigit(hodnota[0])){
				cfg_option6_default = atoi(hodnota);
			}
		} else if (!strcmp(option, "datum_iso_8601_def")){
			if(isdigit(hodnota[0])){
				cfg_option7_default = atoi(hodnota);
			}
		} else if (!strcmp(option, "pevne_casti_modl_cz")){
			if(isdigit(hodnota[0])){
				cfg_option1_cz = atoi(hodnota);
			}
		} else if (!strcmp(option, "zalmy_zo_dna_cz")){
			if(isdigit(hodnota[0])){
				cfg_option2_cz = atoi(hodnota);
			}
		} else if (!strcmp(option, "popis_pri_modlitbe_cz")){
			if(isdigit(hodnota[0])){
				cfg_option4_cz = atoi(hodnota);
			}
		} else if (!strcmp(option, "mcd_zalmy_doplnkpsalm_cz")){
			if(isdigit(hodnota[0])){
				cfg_option5_cz = atoi(hodnota);
			}
		} else if (!strcmp(option, "expt_viac_dni_simple_cz")){
			if(isdigit(hodnota[0])){
				cfg_option6_cz = atoi(hodnota);
			}
		} else if (!strcmp(option, "datum_iso_8601_cz")){
			if(isdigit(hodnota[0])){
				cfg_option7_cz = atoi(hodnota);
			}
		}

		for(; (znak != EOF) && (znak != '\n'); znak = fgetc(subor) );

		if(znak == EOF){
			Log("EOF... break.\n");
			break;
		}

	}
	fclose(subor);

	return;
}

/* 2007-06-01: kedze pribuda mnoho konfiguracnych parametrov, je uzitocne spravit funkciu na ich vypis */
void printConfig(void){
	Log("\n");
	Log("=== BEGIN:configuration ===\n");

	/* 2007-06-01: niekolko prvych parametrov: prevzate z breviar.cpp::main() */
	Log("cfg_HTTP_ADDRESS_default == `%s'\n", cfg_HTTP_ADDRESS_default);
	Log("cfg_HTTP_DISPLAY_ADDRESS_default == `%s'\n", cfg_HTTP_DISPLAY_ADDRESS_default); /* 2007-05-24, JUV: pridane */
	Log("cfg_MAIL_ADDRESS_default == `%s'\n", cfg_MAIL_ADDRESS_default);
	/* 2004-03-17 pridane cfg_INCLUDE_DIR_default */
	Log("cfg_INCLUDE_DIR_default == `%s'\n", cfg_INCLUDE_DIR_default);
	/* 2007-06-01: nasleduju novÈ parametre */
	printConfigOptions();
	Log("=== END:configuration ===\n");
	Log("\n");
}
