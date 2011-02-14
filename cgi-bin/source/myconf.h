/***************************************************************/
/*                                                             */
/* myconf.h                                                    */
/* (c)1999-2006 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | poskytuje rozhranie na konfiguraciu,          */
/*               subor CONFIG_FILE                             */
/* document history                                            */
/*   30/03/2000A.D. | created                                  */
/*   06/09/2001A.D. | tento popis                              */
/*   2003-07-15a.D. | #include "mybase.h" nahradeny "mydefs.h" */
/*   2004-03-17a.D. | pridany INCLUDE_DIR                      */
/*                                                             */
/***************************************************************/

#include "vstudio.h"

#ifndef __MYCONFIG_H
#define __MYCONFIG_H

#include "mydefs.h"

#include "confuse.h"

#define MAX_HTTP_STR 80
#define MAX_MAIL_STR 80
#define MAX_INCD_STR 80

#define CONFIG_FILE "breviar.cfg"
#define STOPPING_CHAR '|'

extern char MAIL_ADDRESS[MAX_HTTP_STR];
extern char HTTP_ADDRESS[MAX_MAIL_STR];
extern char INCLUDE_DIR [MAX_INCD_STR];

void readConfig(void);

#endif /* __MYCONFIG_H */

