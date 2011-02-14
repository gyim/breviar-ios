/***************************************************************/
/*                                                             */
/* myconf.cpp                                                  */
/* (c)1999-2007 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* libconfuse (vid nizsie)                                     */
/* (c) 2002-2003 | Martin Hedenfalk | mhe@home.se              */
/*                                                             */
/* description | poskytuje rozhranie na konfiguraciu,          */
/*               subor CONFIG_FILE                             */
/* document history                                            */
/*   30/03/2000A.D. | created                                  */
/*   06/09/2001A.D. | tento popis                              */
/*   2003-07-08a.D. | MAIL_ADDRESS zmenena na videky@breviar.sk*/
/*   2003-08-13a.D. | pridany #include "mystring.h"            */
/*   2004-03-17a.D. | pridany INCLUDE_DIR                      */
/*   2006-07-13a.D. | prvé kroky k jazykovým mutáciám          */
/*   2007-05-24a.D. | Marek Eliáš (MEL): použitie libconfuse   */
/*                                                             */
/*                                                             */
/***************************************************************/

#include "vstudio.h"

#include "myconf.h"
#include "mystring.h"
#include "confuse.h"

char HTTP_ADDRESS[MAX_HTTP_STR] = "http://www.breviar.sk/";
char HTTP_DISPLAY_ADDRESS[MAX_HTTP_STR] = "http://www.breviar.sk/";
char MAIL_ADDRESS[MAX_MAIL_STR] = "videky@breviar.sk";
char INCLUDE_DIR [MAX_INCD_STR] = "../web/include/";

void readConfig(void){
	/* MEL: Toto som zmenil z pola na pointre, lebo libconfuse priradzuje do pointrov */
	char *http_address = NULL; 
	char *http_display_address = NULL; /* JUV: pridané */
	char *mail_address = NULL;
	char *include_dir = NULL;

/*    cfg_opt_t arg_opts[] = {
        CFG_SIMPLE_INT("pevne_sucasti_modl", &opt1),
        CFG_SIMPLE_INT("zalmy_zo_dna", &opt2),
        CFG_END()
    };
*/
	cfg_opt_t opts[] = {
		CFG_SIMPLE_STR("http_adresa", &http_address),
		CFG_SIMPLE_STR("http_zobraz_adresa", &http_display_address),
		CFG_SIMPLE_STR("mail_adresa", &mail_address),
		CFG_SIMPLE_STR("include", &include_dir),
		CFG_END()
	};

	cfg_t *cfg;

	cfg = cfg_init(opts, 0);
	/* MEL: Tu by mozno bolo dobre dotat, ze ked to najde chybu v parsovanom subore
	 * napr. neznamu volbu, tak to VYPISE EROR na STDOUT a skonci, teda ostatne
	 * premenne necha prazdne.
	 */
	cfg_parse(cfg, CONFIG_FILE);

	/* MEL: No a teraz sa tie stringy napchaju do globalnych poli */
	if (http_address){
		strncpy(HTTP_ADDRESS, http_address, MAX_HTTP_STR);
	}
	if (http_display_address){
		strncpy(HTTP_ADDRESS, http_address, MAX_HTTP_STR);
	}
	if (mail_address){
		strncpy(MAIL_ADDRESS, mail_address, MAX_MAIL_STR);
	}
	if (include_dir){
		strncpy(INCLUDE_DIR, include_dir, MAX_INCD_STR);
	}

	return;
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
