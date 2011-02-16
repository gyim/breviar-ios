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

#define CONFIG_FILE "breviar.cfg"

extern char cfg_HTTP_ADDRESS_default[MAX_HTTP_STR];
extern char cfg_HTTP_DISPLAY_ADDRESS_default[MAX_HTTP_STR];
extern char cfg_MAIL_ADDRESS_default[MAX_MAIL_STR];
extern char cfg_INCLUDE_DIR_default [MAX_INCD_STR];
/* hodnoty options pre default jazyk, teda pre JAZYK_SK */
extern short int cfg_option1_default;
extern short int cfg_option2_default;
extern short int cfg_option4_default;
extern short int cfg_option5_default;
extern short int cfg_option6_default;
extern short int cfg_option7_default;
/* hodnoty options pre JAZYK_CZ */
extern short int cfg_option1_cz;
extern short int cfg_option2_cz;
extern short int cfg_option4_cz;
extern short int cfg_option5_cz;
extern short int cfg_option6_cz;
extern short int cfg_option7_cz;

#define CFG_OPTION1_DEFAULT (((_global_jazyk == JAZYK_SK) || (_global_jazyk == JAZYK_HU))? cfg_option1_default: ((_global_jazyk == JAZYK_CZ) || (_global_jazyk == JAZYK_CZ_OP))? cfg_option1_cz: cfg_option1_default)
#define CFG_OPTION2_DEFAULT (((_global_jazyk == JAZYK_SK) || (_global_jazyk == JAZYK_HU))? cfg_option2_default: ((_global_jazyk == JAZYK_CZ) || (_global_jazyk == JAZYK_CZ_OP))? cfg_option2_cz: cfg_option2_default)
#define CFG_OPTION4_DEFAULT (((_global_jazyk == JAZYK_SK) || (_global_jazyk == JAZYK_HU))? cfg_option4_default: ((_global_jazyk == JAZYK_CZ) || (_global_jazyk == JAZYK_CZ_OP))? cfg_option4_cz: cfg_option4_default)
#define CFG_OPTION5_DEFAULT (((_global_jazyk == JAZYK_SK) || (_global_jazyk == JAZYK_HU))? cfg_option5_default: ((_global_jazyk == JAZYK_CZ) || (_global_jazyk == JAZYK_CZ_OP))? cfg_option5_cz: cfg_option5_default)
#define CFG_OPTION6_DEFAULT (((_global_jazyk == JAZYK_SK) || (_global_jazyk == JAZYK_HU))? cfg_option6_default: ((_global_jazyk == JAZYK_CZ) || (_global_jazyk == JAZYK_CZ_OP))? cfg_option6_cz: cfg_option6_default)
#define CFG_OPTION7_DEFAULT (((_global_jazyk == JAZYK_SK) || (_global_jazyk == JAZYK_HU))? cfg_option7_default: ((_global_jazyk == JAZYK_CZ) || (_global_jazyk == JAZYK_CZ_OP))? cfg_option7_cz: cfg_option7_default)

void readConfig(void);
void printConfig(void);

#endif /* __MYCONFIG_H */

