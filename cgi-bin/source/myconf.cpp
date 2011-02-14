/******************************************************************/
/*                                                                */
/* myconf.cpp                                                     */
/* (c)1999-2007 | Juraj Videky | videky@breviar.sk                */
/*                                                                */
/* libconfuse (vid nizsie)                                        */
/* (c) 2002-2003 | Martin Hedenfalk | mhe@home.se                 */
/*                                                                */
/* description | poskytuje rozhranie na konfiguraciu,             */
/*               subor CONFIG_FILE                                */
/* document history                                               */
/*   30/03/2000A.D. | created                                     */
/*   06/09/2001A.D. | tento popis                                 */
/*   2003-07-08a.D. | MAIL_ADDRESS zmenena na videky@breviar.sk   */
/*   2003-08-13a.D. | pridany #include "mystring.h"               */
/*   2004-03-17a.D. | pridany INCLUDE_DIR                         */
/*   2006-07-13a.D. | prvÈ kroky k jazykov˝m mut·ci·m             */
/*   2007-05-24a.D. | Marek Eli·ö (MEL): pouûitie libconfuse      */
/*   2007-06-01a.D. | prepracovanie konfigurovateæn˝ch premenn˝ch */
/*                                                                */
/*                                                                */
/******************************************************************/

#undef SKIP_READING_CONFIG_20070601

#include "vstudio.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "myconf.h"
#include "mystring.h"
#include "confuse.h"
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

void readConfig(void){
	Log("readConfig(): begin\n");
	/* MEL: Toto som zmenil z pola na pointre, lebo libconfuse priraduje do pointrov */
	char *cfg_http_address_def = strdup(cfg_HTTP_ADDRESS_default); 
	char *cfg_http_display_address_def = strdup(cfg_HTTP_DISPLAY_ADDRESS_default);
	char *cfg_mail_address_def = strdup(cfg_MAIL_ADDRESS_default);
	char *cfg_incl_dir_def = strdup(cfg_INCLUDE_DIR_default);

	/* hodnoty pre default jazyk, teda pre JAZYK_SK */
	short int cfg_opt1_def = GLOBAL_OPTION_NULL;
	short int cfg_opt2_def = GLOBAL_OPTION_NULL;
	short int cfg_opt4_def = GLOBAL_OPTION_NULL;
	short int cfg_opt5_def = GLOBAL_OPTION_NULL;
	short int cfg_opt6_def = GLOBAL_OPTION_NULL;
	short int cfg_opt7_def = GLOBAL_OPTION_NULL;
	/* hodnoty pre JAZYK_CZ */
	short int cfg_opt1_cz = GLOBAL_OPTION_NULL;
	short int cfg_opt2_cz = GLOBAL_OPTION_NULL;
	short int cfg_opt4_cz = GLOBAL_OPTION_NULL;
	short int cfg_opt5_cz = GLOBAL_OPTION_NULL;
	short int cfg_opt6_cz = GLOBAL_OPTION_NULL;
	short int cfg_opt7_cz = GLOBAL_OPTION_NULL;

#ifndef SKIP_READING_CONFIG_20070601
	cfg_opt_t opts[] = {
		CFG_SIMPLE_STR("http_adresa_def", &cfg_http_address_def),
		CFG_SIMPLE_STR("http_zobraz_adr_def", &cfg_http_display_address_def),
		CFG_SIMPLE_STR("mail_adresa_def", &cfg_mail_address_def),
		CFG_SIMPLE_STR("incldir_def", &cfg_incl_dir_def),
		/* hodnoty pre default jazyk, teda pre JAZYK_SK */
		CFG_SIMPLE_INT("pevne_casti_modl_def", &cfg_opt1_def),
		CFG_SIMPLE_INT("zalmy_zo_dna_def", &cfg_opt2_def),
		CFG_SIMPLE_INT("popis_pri_modlitbe_def", &cfg_opt4_def),
		CFG_SIMPLE_INT("mcd_zalmy_doplnkpsalm_def", &cfg_opt5_def),
		CFG_SIMPLE_INT("expt_viac_dni_simple_def", &cfg_opt6_def),
		CFG_SIMPLE_INT("datum_iso_8601_def", &cfg_opt7_def),
		/* hodnoty pre JAZYK_CZ */
		CFG_SIMPLE_INT("pevne_sucasti_modl_cz", &cfg_opt1_cz),
		CFG_SIMPLE_INT("zalmy_zo_dna_cz", &cfg_opt2_cz),
		CFG_SIMPLE_INT("popis_pri_modlitbe_cz", &cfg_opt4_cz),
		CFG_SIMPLE_INT("mcd_zalmy_doplnkpsalm_cz", &cfg_opt5_cz),
		CFG_SIMPLE_INT("expt_viac_dni_simple_cz", &cfg_opt6_cz),
		CFG_SIMPLE_INT("datum_iso_8601_cz", &cfg_opt7_cz),
		CFG_END()
	};

	Log("readConfig(): declaration finished, calling cfg_init()...\n");

	cfg_t *cfg;

	cfg = cfg_init(opts, 0);
	/* MEL: Tu by mozno bolo dobre dotat, ze ked to najde chybu v parsovanom subore
	 * napr. neznamu volbu, tak to VYPISE EROR na STDOUT a skonci, teda ostatne
	 * premenne necha prazdne.
	 */

	Log("readConfig(): cfg_init() finished, calling cfg_parse(`%s')...\n", CONFIG_FILE);

	cfg_parse(cfg, CONFIG_FILE);
#endif

/*
	if (cfg_http_address_def)
		Log("cfg_http_address_def == `%s'\n", cfg_http_address_def);
	if (cfg_http_address_def)
		Log("cfg_http_display_address_def == `%s'\n", cfg_http_display_address_def);
	if (cfg_mail_address_def)
		Log("cfg_mail_address_def == `%s'\n", cfg_mail_address_def);
	if (cfg_incl_dir_def)
		Log("cfg_incl_dir_def == `%s'\n", cfg_incl_dir_def);
*/
	Log("readConfig(): cfg_parse(`%s') finished, checking parameters ...\n", CONFIG_FILE);

	if (cfg_http_address_def){
		mystrcpy(cfg_HTTP_ADDRESS_default, cfg_http_address_def, MAX_HTTP_STR);
	}
	if (cfg_http_display_address_def){
		mystrcpy(cfg_HTTP_DISPLAY_ADDRESS_default, cfg_http_display_address_def, MAX_HTTP_STR);
	}
	if (cfg_mail_address_def){
		mystrcpy(cfg_MAIL_ADDRESS_default, cfg_mail_address_def, MAX_MAIL_STR);
	}
	if (cfg_incl_dir_def){
		mystrcpy(cfg_INCLUDE_DIR_default, cfg_incl_dir_def, MAX_INCD_STR);
	}

	/* hodnoty pre default jazyk, teda pre JAZYK_SK */
	if(cfg_opt1_def != GLOBAL_OPTION_NULL)
		cfg_option1_default = cfg_opt1_def;
	else
		cfg_option1_default = NIE;

	if(cfg_opt2_def != GLOBAL_OPTION_NULL)
		cfg_option2_default = cfg_opt2_def;
	else
		cfg_option2_default = MODL_ZALMY_ZO_DNA;

	if(cfg_opt4_def != GLOBAL_OPTION_NULL)
		cfg_option4_default = cfg_opt4_def;
	else
		cfg_option4_default = ANO;

	if(cfg_opt5_def != GLOBAL_OPTION_NULL)
		cfg_option5_default = cfg_opt5_def;
	else
		cfg_option5_default = MODL_CEZ_DEN_ZALMY_ZO_DNA;

	if(cfg_opt6_def != GLOBAL_OPTION_NULL)
		cfg_option6_default = cfg_opt6_def;
	else
		cfg_option6_default = NIE;

	if(cfg_opt7_def != GLOBAL_OPTION_NULL)
		cfg_option7_default = cfg_opt7_def;
	else
		cfg_option7_default = NIE;

	/* hodnoty pre JAZYK_CZ */
	if(cfg_opt1_cz != GLOBAL_OPTION_NULL)
		cfg_option1_cz = cfg_opt1_cz;
	else
		cfg_option1_cz = ANO;

	if(cfg_opt2_cz != GLOBAL_OPTION_NULL)
		cfg_option2_cz = cfg_opt2_cz;
	else
		cfg_option2_cz = MODL_ZALMY_ZO_DNA;

	if(cfg_opt4_cz != GLOBAL_OPTION_NULL)
		cfg_option4_cz = cfg_opt4_cz;
	else
		cfg_option4_cz = ANO;

	if(cfg_opt5_cz != GLOBAL_OPTION_NULL)
		cfg_option5_cz = cfg_opt5_cz;
	else
		cfg_option5_cz = MODL_CEZ_DEN_ZALMY_ZO_DNA;

	if(cfg_opt6_cz != GLOBAL_OPTION_NULL)
		cfg_option6_cz = cfg_opt6_cz;
	else
		cfg_option6_cz = NIE;

	if(cfg_opt7_cz != GLOBAL_OPTION_NULL)
		cfg_option7_cz = cfg_opt7_cz;
	else
		cfg_option7_cz = NIE;

	printConfigOptions();

#ifndef SKIP_READING_CONFIG_20070601
	Log("readConfig(): cfg_free()...\n");
	cfg_free(cfg);
#endif

	if(cfg_http_address_def != NULL)
		free(cfg_http_address_def);
	if(cfg_http_display_address_def != NULL)
		free(cfg_http_display_address_def);
	if(cfg_mail_address_def != NULL)
		free(cfg_mail_address_def);
	if(cfg_incl_dir_def != NULL)
		free(cfg_incl_dir_def);

	Log("readConfig(): end\n");
	return;
}

/* 2007-06-01: keÔûe prib˙da mnoho konfiguraËn˝ch parametrov, je uûitoËnÈ spraviù funkciu na ich v˝pis */
void printConfig(void){
	Log("\n");
	Log("=== BEGIN:configuration ===\n");

	/* 2007-06-01: niekoæko prv˝ch parametrov: prevzatÈ z breviar.cpp::main() */
	Log("cfg_HTTP_ADDRESS_default == `%s'\n", cfg_HTTP_ADDRESS_default);
	Log("cfg_HTTP_DISPLAY_ADDRESS_default == `%s'\n", cfg_HTTP_DISPLAY_ADDRESS_default); /* 2007-05-24, JUV: pridanÈ */
	Log("cfg_MAIL_ADDRESS_default == `%s'\n", cfg_MAIL_ADDRESS_default);
	/* 2004-03-17 pridane cfg_INCLUDE_DIR_default */
	Log("cfg_INCLUDE_DIR_default == `%s'\n", cfg_INCLUDE_DIR_default);
	/* 2007-06-01: nasleduj˙ novÈ parametre */
	printConfigOptions();
	Log("=== END:configuration ===\n");
	Log("\n");
}

/* Configuration file parser -*- tab-width: 4; -*-
 *
 * $Id: confuse.h,v 1.19 2004/10/17 16:57:00 mhe Exp $
 *
 * Copyright (c) 2002-2003, Martin Hedenfalk <mhe@home.se>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
 */
