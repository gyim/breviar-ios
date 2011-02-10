/* 30/03/2000A.D. Juraj Videky */

/* poskytuje rozhranie na konfiguraciu, subor CONFIG_FILE */
#include "myconf.h"
#include "mystring.h"

char HTTP_ADDRESS[MAX_HTTP_STR] = "http://www.breviar.sk/";
char MAIL_ADDRESS[MAX_MAIL_STR] = "videky@pobox.sk";

void readConfig(void){
	FILE *cfg_file;
	char *ptr;
	char http_address[MAX_STR] = "";
	char mail_address[MAX_STR] = "";

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
		fclose(cfg_file); /* pridane 11/04/2000A.D. */
	}
	return;
}
