/***************************************************************/
/*                                                             */
/* myconf.cpp                                                  */
/* (c)1999-2005 | Juraj Videky | videky@breviar.sk             */
/*                                                             */
/* description | poskytuje rozhranie na konfiguraciu,          */
/*               subor CONFIG_FILE                             */
/* document history                                            */
/*   30/03/2000A.D. | created                                  */
/*   06/09/2001A.D. | tento popis                              */
/*   2003-07-08a.D. | MAIL_ADDRESS zmenena na videky@breviar.sk*/
/*   2003-08-13a.D. | pridany #include "mystring.h"            */
/*   2004-03-17a.D. | pridany INCLUDE_DIR                      */
/*                                                             */
/*                                                             */
/***************************************************************/

#include "myconf.h"
#include "mystring.h"

char HTTP_ADDRESS[MAX_HTTP_STR] = "http://www.breviar.sk/";
char MAIL_ADDRESS[MAX_MAIL_STR] = "videky@breviar.sk";
char INCLUDE_DIR [MAX_INCD_STR] = "../web/include/";

void readConfig(void){
	FILE *cfg_file;
	char *ptr;
	char http_address[MAX_STR] = STR_EMPTY;
	char mail_address[MAX_STR] = STR_EMPTY;
	char include_dir [MAX_STR] = STR_EMPTY;

	cfg_file = fopen(CONFIG_FILE, "rt");

/* The fgets function reads a string from the input stream argument 
 * and stores it in string. fgets reads characters from the current 
 * stream position to and including the first newline character, to 
 * the end of the stream, or until the number of characters read is 
 * equal to n - 1, whichever comes first. The result stored in 
 * string is appended with a null character. 
 * The newline character, if read, is included in the string. 
 * -- avsak nam to nevadi. ze je tam aj <CR><LF>, lebo ho odfiltrujeme
 * 30/03/2000A.D.
 * 2004-03-17 pridane INCLUDE_DIR
 */
	if(cfg_file != NULL){
		fgets(http_address, MAX_STR, cfg_file);
		if((http_address != NULL) && (strlen(http_address) > 0)){
			mystrcpy(HTTP_ADDRESS, http_address, MAX_HTTP_STR);
			ptr = strchr(HTTP_ADDRESS, STOPPING_CHAR);
			if(ptr)/* The character %c is at position: %d\n", STOPPING_CHAR, ptr - HTTP_ADDRESS */
				HTTP_ADDRESS[ptr - HTTP_ADDRESS] = '\0';
			else/* The character was not found */
				;
		}
		fgets(mail_address, MAX_STR, cfg_file);
		if((mail_address != NULL) && (strlen(mail_address) > 0)){
			mystrcpy(MAIL_ADDRESS, mail_address, MAX_MAIL_STR);
			ptr = strchr(MAIL_ADDRESS, STOPPING_CHAR);
			if(ptr)/* The character %c is at position: %d\n", STOPPING_CHAR, ptr - MAIL_ADDRESS */
				MAIL_ADDRESS[ptr - MAIL_ADDRESS] = '\0';
			else/* The character was not found */
				;
		}
		/* 2004-03-17 pridane INCLUDE_DIR */
		fgets(include_dir, MAX_STR, cfg_file);
		if((include_dir != NULL) && (strlen(include_dir) > 0)){
			mystrcpy(INCLUDE_DIR, include_dir, MAX_INCD_STR);
			ptr = strchr(INCLUDE_DIR, STOPPING_CHAR);
			if(ptr)/* The character %c is at position: %d\n", STOPPING_CHAR, ptr - INCLUDE_DIR */
				INCLUDE_DIR[ptr - INCLUDE_DIR] = '\0';
			else/* The character was not found */
				;
		}
		fclose(cfg_file); /* pridane 11/04/2000A.D. */
	}
	return;
}

