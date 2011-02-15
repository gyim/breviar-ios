/***************************************************************/
/*                                                             */
/* mydefs.cpp                                                  */
/* (c)1999-2010 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | obsahuje zakladne define'y                    */
/* document history                                            */
/*   30/03/2000A.D. | created                                  */
/*   06/09/2001A.D. | tento popis                              */
/*   2003-08-13a.D. | pridany #include "mystring.h"            */
/*                                                             */
/***************************************************************/

#include "vstudio.h"

#include "mydefs.h"
#include <string.h>
#include "mystring.h" /* pridane 2003-08-13 */

char script_name[MAX_STR] = STR_EMPTY; // = cfg_HTTP_ADDRESS_default + SCRIPT_PATH(SCRIPT_NAME)
char uncgi_name[MAX_STR] = STR_EMPTY;  // = cfg_HTTP_ADDRESS_default + UNCGI_SCRIPT_NAME

void updateScriptName(void){
	strcpy(script_name, cfg_HTTP_ADDRESS_default);
	strcat(script_name, SCRIPT_PATH(SCRIPT_NAME));
}

void updateUnCGIName(void){
	strcpy(uncgi_name, cfg_HTTP_ADDRESS_default);
	strcat(uncgi_name, UNCGI_SCRIPT_NAME);
}

