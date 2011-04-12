/***************************************************************/
/*                                                             */
/* myconf.h                                                    */
/* (c)1999-2011 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | poskytuje rozhranie na konfiguraciu,          */
/*               subor CONFIG_FILE                             */
/* document history                                            */
/*   30/03/2000A.D. | created                                  */
/*   06/09/2001A.D. | tento popis                              */
/*   2003-07-15a.D. | #include "mybase.h" nahradeny "mydefs.h" */
/*   2004-03-17a.D. | pridany INCLUDE_DIR                      */
/*   2011-01-31a.D. | pridané CFG_OPTION1_DEFAULT (1 až 5)     */
/*   2011-04-11a.D. | CONFIG_FILE sa nastavuje pod¾a "OS"      */
/*                                                             */
/***************************************************************/

#include "vstudio.h"

#ifndef __MYCONFIG_H
#define __MYCONFIG_H

#include "mydefs.h"

#define MAX_HTTP_STR	80
#define MAX_MAIL_STR	50
#define MAX_INCD_STR	50
#define MAX_OPTION_LENGTH	40
#define MAX_VALUE_LENGTH	80

#ifdef OS_Windows_Ruby
#define CONFIG_FILE "breviar-local.cfg"
#else
#define CONFIG_FILE "breviar-web.cfg"
#endif

extern char cfg_HTTP_ADDRESS_default[MAX_HTTP_STR];
extern char cfg_HTTP_DISPLAY_ADDRESS_default[MAX_HTTP_STR];
extern char cfg_MAIL_ADDRESS_default[MAX_MAIL_STR];
extern char cfg_INCLUDE_DIR_default [MAX_INCD_STR];

/* hodnoty options pre default jazyk, teda pre JAZYK_SK */
extern short int cfg_option0_default;
extern short int cfg_option1_default;
extern short int cfg_option2_default;
extern short int cfg_option4_default;
/* hodnoty options pre JAZYK_CZ */
extern short int cfg_option0_cz;
extern short int cfg_option1_cz;
extern short int cfg_option2_cz;
extern short int cfg_option4_cz;
/* hodnoty options pre JAZYK_CZ_OP */
extern short int cfg_option0_czop;
extern short int cfg_option1_czop;
extern short int cfg_option2_czop;
extern short int cfg_option4_czop;

#define CFG_OPTION0_DEFAULT (((_global_jazyk == JAZYK_SK) || (_global_jazyk == JAZYK_HU))? cfg_option0_default: ((_global_jazyk == JAZYK_CZ) || (_global_jazyk == JAZYK_CZ_OP))? cfg_option0_cz: cfg_option0_default)
#define CFG_OPTION1_DEFAULT (((_global_jazyk == JAZYK_SK) || (_global_jazyk == JAZYK_HU))? cfg_option1_default: ((_global_jazyk == JAZYK_CZ) || (_global_jazyk == JAZYK_CZ_OP))? cfg_option1_cz: cfg_option1_default)
#define CFG_OPTION2_DEFAULT (((_global_jazyk == JAZYK_SK) || (_global_jazyk == JAZYK_HU) || (_global_jazyk == JAZYK_CZ))? cfg_option2_default: ((_global_jazyk == JAZYK_CZ_OP))? cfg_option2_czop: cfg_option2_default)
// option 3 nemá default
#define CFG_OPTION4_DEFAULT (((_global_jazyk == JAZYK_SK) || (_global_jazyk == JAZYK_HU))? cfg_option4_default: ((_global_jazyk == JAZYK_CZ) || (_global_jazyk == JAZYK_CZ_OP))? cfg_option4_cz: cfg_option4_default)

void readConfig(void);
void printConfig(void);

#endif /* __MYCONFIG_H */

