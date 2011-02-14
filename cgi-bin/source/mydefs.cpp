/***************************************************************/
/*                                                             */
/* mydefs.cpp                                                  */
/* (c)1999-2007 | Juraj Videky | videky@breviar.sk             */
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

char script_name[MAX_STR] = STR_EMPTY; // = HTTP_ADDRESS + SCRIPT_PATH(SCRIPT_NAME)
char uncgi_name[MAX_STR] = STR_EMPTY;  // = HTTP_ADDRESS + UNCGI_SCRIPT_NAME

void updateScriptName(void){
	strcpy(script_name, HTTP_ADDRESS);
	strcat(script_name, SCRIPT_PATH(SCRIPT_NAME));
}

void updateUnCGIName(void){
	strcpy(uncgi_name, HTTP_ADDRESS);
	strcat(uncgi_name, UNCGI_SCRIPT_NAME);
}

