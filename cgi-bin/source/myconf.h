/* 30/03/2000A.D. Juraj Videky */

/* poskytuje rozhranie na konfiguraciu, subor CONFIG_FILE */
#ifndef __MYCONFIG_H
#define __MYCONFIG_H

#include "mybase.h"

#define MAX_HTTP_STR 80
#define MAX_MAIL_STR 80

#define CONFIG_FILE "breviar.cfg"
#define STOPPING_CHAR '|'

extern char MAIL_ADDRESS[MAX_HTTP_STR];
extern char HTTP_ADDRESS[MAX_MAIL_STR];

void readConfig(void);

#endif /* __MYCONFIG_H */