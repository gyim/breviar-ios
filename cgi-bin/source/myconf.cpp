/***************************************************************/
/*                                                             */
/* myconf.cpp                                                  */
/* (c)1999-2006 | Juraj Videky | videky@breviar.sk             */
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
/*   2007-05-24a.D. | Marek Eliáš: použitie libconfuse         */
/*                                                             */
/*                                                             */
/***************************************************************/

#include "vstudio.h"

#include "myconf.h"
#include "mystring.h"
#include "confuse.h"

char HTTP_ADDRESS[MAX_HTTP_STR] = "http://www.breviar.sk/";
char MAIL_ADDRESS[MAX_MAIL_STR] = "videky@breviar.sk";
char INCLUDE_DIR [MAX_INCD_STR] = "../web/include/";

void readConfig(void){
	/* Toto som zmenil z pola na pointre, lebo libconfuse priradzuje do
	 * pointrov
	 */
	char *http_address = NULL; 
	char *mail_address = NULL;
	char *include_dir = NULL;

	cfg_opt_t opts[] = {
		CFG_SIMPLE_STR("http_adresa", &http_address),
		CFG_SIMPLE_STR("mail_adresa", &mail_address),
		CFG_SIMPLE_STR("include", &include_dir),
		CFG_END()
	};

	cfg_t *cfg;

	cfg = cfg_init(opts, 0);
	/* Tu by mozno bolo dobre dotat, ze ked to najde chybu v parsovanom subore
	 * napr. neznamu volbu, tak to VYPISE EROR na STDOUT a skonci, teda ostatne
	 * premenne necha prazdne.
	 */
	cfg_parse(cfg, CONFIG_FILE);
	
	// No a teraz sa tie stringy napchaju do globalnych poli
	if (http_address){
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

