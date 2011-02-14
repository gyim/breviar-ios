#define yy_create_buffer cfg_yy_create_buffer
#define yy_delete_buffer cfg_yy_delete_buffer
#define yy_scan_buffer cfg_yy_scan_buffer
#define yy_scan_string cfg_yy_scan_string
#define yy_scan_bytes cfg_yy_scan_bytes
#define yy_flex_debug cfg_yy_flex_debug
#define yy_init_buffer cfg_yy_init_buffer
#define yy_flush_buffer cfg_yy_flush_buffer
#define yy_load_buffer_state cfg_yy_load_buffer_state
#define yy_switch_to_buffer cfg_yy_switch_to_buffer
#define yyin cfg_yyin
#define yyleng cfg_yyleng
#define yylex cfg_yylex
#define yyout cfg_yyout
#define yyrestart cfg_yyrestart
#define yytext cfg_yytext

#define FLEX_SCANNER
#define YY_FLEX_MAJOR_VERSION 2
#define YY_FLEX_MINOR_VERSION 5

#include "vstudio.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


/* cfront 1.2 defines "c_plusplus" instead of "__cplusplus" */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif


#ifdef __cplusplus

#include <stdlib.h>

// JUV
#include "unistd.h"
#include "vstudio.h"

/* Use prototypes in function declarations. */
#define YY_USE_PROTOS

/* The "const" storage-class-modifier is valid. */
#define YY_USE_CONST

#else	/* ! __cplusplus */

#if __STDC__

#define YY_USE_PROTOS
#define YY_USE_CONST

#endif	/* __STDC__ */
#endif	/* ! __cplusplus */

#ifdef __TURBOC__
 #pragma warn -rch
 #pragma warn -use
#include <io.h>
#include <stdlib.h>
#define YY_USE_CONST
#define YY_USE_PROTOS
#endif

#ifdef YY_USE_CONST
#define yyconst const
#else
#define yyconst
#endif


#ifdef YY_USE_PROTOS
#define YY_PROTO(proto) proto
#else
#define YY_PROTO(proto) ()
#endif

/* Returned upon end-of-file. */
#define YY_NULL 0

/* Promotes a possibly negative, possibly signed char to an unsigned
 * integer for use as an array index.  If the signed char is negative,
 * we want to instead treat it as an 8-bit unsigned char, hence the
 * double cast.
 */
#define YY_SC_TO_UI(c) ((unsigned int) (unsigned char) c)

/* Enter a start condition.  This macro really ought to take a parameter,
 * but we do it the disgusting crufty way forced on us by the ()-less
 * definition of BEGIN.
 */
#define BEGIN yy_start = 1 + 2 *

/* Translate the current start state into a value that can be later handed
 * to BEGIN to return to the state.  The YYSTATE alias is for lex
 * compatibility.
 */
#define YY_START ((yy_start - 1) / 2)
#define YYSTATE YY_START

/* Action number for EOF rule of a given start state. */
#define YY_STATE_EOF(state) (YY_END_OF_BUFFER + state + 1)

/* Special action meaning "start processing a new file". */
#define YY_NEW_FILE yyrestart( yyin )

#define YY_END_OF_BUFFER_CHAR 0

/* Size of default input buffer. */
#define YY_BUF_SIZE 16384

typedef struct yy_buffer_state *YY_BUFFER_STATE;

extern int yyleng;
extern FILE *yyin, *yyout;

#define EOB_ACT_CONTINUE_SCAN 0
#define EOB_ACT_END_OF_FILE 1
#define EOB_ACT_LAST_MATCH 2

/* The funky do-while in the following #define is used to turn the definition
 * int a single C statement (which needs a semi-colon terminator).  This
 * avoids problems with code like:
 *
 * 	if ( condition_holds )
 *		yyless( 5 );
 *	else
 *		do_something_else();
 *
 * Prior to using the do-while the compiler would get upset at the
 * "else" because it interpreted the "if" statement as being all
 * done when it reached the ';' after the yyless() call.
 */

/* Return all but the first 'n' matched characters back to the input stream. */

#define yyless(n) \
	do \
		{ \
		/* Undo effects of setting up yytext. */ \
		*yy_cp = yy_hold_char; \
		YY_RESTORE_YY_MORE_OFFSET \
		yy_c_buf_p = yy_cp = yy_bp + n - YY_MORE_ADJ; \
		YY_DO_BEFORE_ACTION; /* set up yytext again */ \
		} \
	while ( 0 )

#define unput(c) yyunput( c, yytext_ptr )

/* The following is because we cannot portably get our hands on size_t
 * (without autoconf's help, which isn't available because we want
 * flex-generated scanners to compile on their own).
 */
typedef unsigned int yy_size_t;


struct yy_buffer_state
	{
	FILE *yy_input_file;

	char *yy_ch_buf;		/* input buffer */
	char *yy_buf_pos;		/* current position in input buffer */

	/* Size of input buffer in bytes, not including room for EOB
	 * characters.
	 */
	yy_size_t yy_buf_size;

	/* Number of characters read into yy_ch_buf, not including EOB
	 * characters.
	 */
	int yy_n_chars;

	/* Whether we "own" the buffer - i.e., we know we created it,
	 * and can realloc() it to grow it, and should free() it to
	 * delete it.
	 */
	int yy_is_our_buffer;

	/* Whether this is an "interactive" input source; if so, and
	 * if we're using stdio for input, then we want to use getc()
	 * instead of fread(), to make sure we stop fetching input after
	 * each newline.
	 */
	int yy_is_interactive;

	/* Whether we're considered to be at the beginning of a line.
	 * If so, '^' rules will be active on the next match, otherwise
	 * not.
	 */
	int yy_at_bol;

	/* Whether to try to fill the input buffer when we reach the
	 * end of it.
	 */
	int yy_fill_buffer;

	int yy_buffer_status;
#define YY_BUFFER_NEW 0
#define YY_BUFFER_NORMAL 1
	/* When an EOF's been seen but there's still some text to process
	 * then we mark the buffer as YY_EOF_PENDING, to indicate that we
	 * shouldn't try reading from the input source any more.  We might
	 * still have a bunch of tokens to match, though, because of
	 * possible backing-up.
	 *
	 * When we actually see the EOF, we change the status to "new"
	 * (via yyrestart()), so that the user can continue scanning by
	 * just pointing yyin at a new input file.
	 */
#define YY_BUFFER_EOF_PENDING 2
	};

static YY_BUFFER_STATE yy_current_buffer = 0;

/* We provide macros for accessing buffer states in case in the
 * future we want to put the buffer states in a more general
 * "scanner state".
 */
#define YY_CURRENT_BUFFER yy_current_buffer


/* yy_hold_char holds the character lost when yytext is formed. */
static char yy_hold_char;

static int yy_n_chars;		/* number of characters read into yy_ch_buf */


int yyleng;

/* Points to current character in buffer. */
static char *yy_c_buf_p = (char *) 0;
static int yy_init = 1;		/* whether we need to initialize */
static int yy_start = 0;	/* start state number */

/* Flag which is used to allow yywrap()'s to do buffer switches
 * instead of setting up a fresh yyin.  A bit of a hack ...
 */
static int yy_did_buffer_switch_on_eof;

void yyrestart YY_PROTO(( FILE *input_file ));

void yy_switch_to_buffer YY_PROTO(( YY_BUFFER_STATE new_buffer ));
void yy_load_buffer_state YY_PROTO(( void ));
YY_BUFFER_STATE yy_create_buffer YY_PROTO(( FILE *file, int size ));
void yy_delete_buffer YY_PROTO(( YY_BUFFER_STATE b ));
void yy_init_buffer YY_PROTO(( YY_BUFFER_STATE b, FILE *file ));
void yy_flush_buffer YY_PROTO(( YY_BUFFER_STATE b ));
#define YY_FLUSH_BUFFER yy_flush_buffer( yy_current_buffer )

YY_BUFFER_STATE yy_scan_buffer YY_PROTO(( char *base, yy_size_t size ));
YY_BUFFER_STATE yy_scan_string YY_PROTO(( yyconst char *yy_str ));
YY_BUFFER_STATE yy_scan_bytes YY_PROTO(( yyconst char *bytes, int len ));

static void *yy_flex_alloc YY_PROTO(( yy_size_t ));
static void *yy_flex_realloc YY_PROTO(( void *, yy_size_t ));
static void yy_flex_free YY_PROTO(( void * ));

#define yy_new_buffer yy_create_buffer

#define yy_set_interactive(is_interactive) \
	{ \
	if ( ! yy_current_buffer ) \
		yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE ); \
	yy_current_buffer->yy_is_interactive = is_interactive; \
	}

#define yy_set_bol(at_bol) \
	{ \
	if ( ! yy_current_buffer ) \
		yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE ); \
	yy_current_buffer->yy_at_bol = at_bol; \
	}

#define YY_AT_BOL() (yy_current_buffer->yy_at_bol)


#define yywrap() 1
#define YY_SKIP_YYWRAP
typedef unsigned char YY_CHAR;
FILE *yyin = (FILE *) 0, *yyout = (FILE *) 0;
typedef int yy_state_type;
extern char *yytext;
#define yytext_ptr yytext

static yy_state_type yy_get_previous_state YY_PROTO(( void ));
static yy_state_type yy_try_NUL_trans YY_PROTO(( yy_state_type current_state ));
static int yy_get_next_buffer YY_PROTO(( void ));
static void yy_fatal_error YY_PROTO(( yyconst char msg[] ));

/* Done after the current pattern has been matched and before the
 * corresponding action - sets up yytext.
 */
#define YY_DO_BEFORE_ACTION \
	yytext_ptr = yy_bp; \
	yyleng = (int) (yy_cp - yy_bp); \
	yy_hold_char = *yy_cp; \
	*yy_cp = '\0'; \
	yy_c_buf_p = yy_cp;

#define YY_NUM_RULES 43
#define YY_END_OF_BUFFER 44
static yyconst short int yy_accept[81] =
    {   0,
        0,    0,   12,   12,    0,    0,    0,    0,   44,   42,
        1,    2,   43,   16,    3,   42,   34,    6,    7,   43,
       10,   43,    8,    4,    5,   12,   14,   13,   33,   19,
       17,   33,   43,   40,   36,   35,   43,   42,    0,    1,
        3,    0,    9,   11,    3,   12,   13,   13,   15,   33,
       33,   32,   20,   21,   22,   28,   26,   29,   27,   24,
       25,   30,   31,   32,   40,   39,   37,   38,    0,   41,
       33,    0,   18,   21,   22,   23,   18,   21,   23,    0
    } ;

static yyconst int yy_ec[256] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    2,    3,
        1,    1,    4,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    2,    1,    5,    6,    7,    1,    1,    8,    9,
       10,   11,   12,   13,    1,    1,   14,   15,   15,   15,
       15,   15,   15,   15,   15,   16,   16,    1,    1,    1,
       17,    1,    1,    1,   18,   18,   18,   18,   18,   18,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,   19,    1,    1,    1,    1,   20,   21,   18,   18,

       22,   23,    1,    1,    1,    1,    1,    1,    1,   24,
        1,    1,    1,   25,    1,   26,    1,   27,    1,   28,
        1,    1,   29,    1,   30,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,

        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1
    } ;

static yyconst int yy_meta[31] =
    {   0,
        1,    2,    3,    2,    4,    2,    1,    5,    2,    2,
        6,    2,    2,    1,    7,    7,    2,    7,    8,    7,
        7,    7,    7,    1,    1,    1,    1,    1,    2,    2
    } ;

static yyconst short int yy_base[97] =
    {   0,
        0,    0,   28,   29,   30,   31,   38,   39,  104,   88,
       98,  225,  225,  225,    0,   30,  225,  225,  225,   82,
      225,   34,  225,  225,  225,    0,  225,   40,    0,  225,
      225,   69,   57,    0,  225,  225,   67,   83,   41,   94,
        0,   65,  225,  225,    0,    0,   42,   50,  225,    0,
       71,  225,  225,   47,   50,  225,  225,  225,  225,  225,
      225,  225,  225,    0,    0,  225,  225,  225,   58,  225,
       84,   41,    0,   52,   76,    0,  225,   78,  225,  225,
      114,  122,  130,  138,  146,  154,  162,  170,  177,  185,
      192,  200,  208,   62,  216,   36

    } ;

static yyconst short int yy_def[97] =
    {   0,
       80,    1,   81,   81,   82,   82,   83,   83,   80,   84,
       80,   80,   80,   80,   85,   84,   80,   80,   80,   80,
       80,   84,   80,   80,   80,   86,   80,   87,   88,   80,
       80,   88,   89,   90,   80,   80,   91,   84,   84,   80,
       85,   92,   80,   80,   85,   86,   87,   87,   80,   88,
       93,   80,   80,   80,   80,   80,   80,   80,   80,   80,
       80,   80,   80,   94,   90,   80,   80,   80,   92,   80,
       93,   95,   88,   80,   80,   96,   80,   80,   80,    0,
       80,   80,   80,   80,   80,   80,   80,   80,   80,   80,
       80,   80,   80,   80,   80,   80

    } ;

static yyconst short int yy_nxt[256] =
    {   0,
       10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
       10,   20,   21,   22,   10,   10,   23,   10,   10,   10,
       10,   10,   10,   10,   10,   10,   10,   10,   24,   25,
       27,   27,   30,   30,   31,   31,   32,   32,   28,   28,
       35,   35,   79,   39,   44,   36,   36,   45,   33,   33,
       48,   80,   80,   49,   80,   80,   37,   37,   42,   53,
       48,   74,   75,   49,   75,   75,   78,   75,   76,   67,
       77,   54,   55,   72,   68,   72,   56,   57,   58,   59,
       60,   61,   62,   63,   64,   68,   72,   70,   72,   72,
       75,   75,   75,   75,   70,   40,   39,   51,   43,   40,

       73,   39,   72,   80,   80,   80,   80,   80,   80,   80,
       80,   80,   80,   73,   26,   26,   26,   26,   26,   26,
       26,   26,   29,   29,   29,   29,   29,   29,   29,   29,
       34,   34,   34,   34,   34,   34,   34,   34,   38,   80,
       80,   80,   80,   38,   38,   38,   41,   41,   80,   41,
       41,   41,   41,   41,   46,   46,   80,   46,   46,   80,
       46,   46,   47,   47,   80,   47,   47,   47,   47,   47,
       50,   50,   80,   80,   50,   50,   50,   52,   52,   52,
       52,   52,   52,   52,   52,   65,   65,   80,   65,   80,
       65,   65,   66,   66,   66,   66,   66,   66,   66,   66,

       69,   69,   69,   69,   69,   69,   69,   69,   71,   71,
       71,   71,   71,   71,   71,   71,   72,   72,   72,   72,
       72,   72,   72,   72,    9,   80,   80,   80,   80,   80,
       80,   80,   80,   80,   80,   80,   80,   80,   80,   80,
       80,   80,   80,   80,   80,   80,   80,   80,   80,   80,
       80,   80,   80,   80,   80
    } ;

static yyconst short int yy_chk[256] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        3,    4,    5,    6,    5,    6,    5,    6,    3,    4,
        7,    8,   96,   16,   22,    7,    8,   22,    5,    6,
       28,   39,   47,   28,   39,   47,    7,    8,   16,   33,
       48,   54,   54,   48,   55,   55,   74,   74,   94,   37,
       72,   33,   33,   51,   37,   51,   33,   33,   33,   33,
       33,   33,   33,   33,   33,   37,   71,   69,   71,   51,
       75,   75,   78,   78,   42,   40,   38,   32,   20,   11,

       51,   10,   71,    9,    0,    0,    0,    0,    0,    0,
        0,    0,    0,   71,   81,   81,   81,   81,   81,   81,
       81,   81,   82,   82,   82,   82,   82,   82,   82,   82,
       83,   83,   83,   83,   83,   83,   83,   83,   84,    0,
        0,    0,    0,   84,   84,   84,   85,   85,    0,   85,
       85,   85,   85,   85,   86,   86,    0,   86,   86,    0,
       86,   86,   87,   87,    0,   87,   87,   87,   87,   87,
       88,   88,    0,    0,   88,   88,   88,   89,   89,   89,
       89,   89,   89,   89,   89,   90,   90,    0,   90,    0,
       90,   90,   91,   91,   91,   91,   91,   91,   91,   91,

       92,   92,   92,   92,   92,   92,   92,   92,   93,   93,
       93,   93,   93,   93,   93,   93,   95,   95,   95,   95,
       95,   95,   95,   95,   80,   80,   80,   80,   80,   80,
       80,   80,   80,   80,   80,   80,   80,   80,   80,   80,
       80,   80,   80,   80,   80,   80,   80,   80,   80,   80,
       80,   80,   80,   80,   80
    } ;

static yy_state_type yy_last_accepting_state;
static char *yy_last_accepting_cpos;

/* The intent behind this definition is that it'll catch
 * any uses of REJECT which flex missed.
 */
#define REJECT reject_used_but_not_detected
#define yymore() yymore_used_but_not_detected
#define YY_MORE_ADJ 0
#define YY_RESTORE_YY_MORE_OFFSET
char *yytext;
#define INITIAL 0
/* Configuration file parser
 *
 * $Id: lexer.l,v 1.10 2004/10/02 17:19:36 mhe Exp $
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

/* JUV - upraven�, 2007-06-01
#ifdef HAVE_CONFIG_H
# include "config.h"
#endif
*/
#include "mysystem.h"

#include <assert.h>

#ifdef HAVE_STRING_H
# include <string.h>
#endif

#include "confuse.h"

#include <errno.h>

#if defined(ENABLE_NLS) && defined(HAVE_GETTEXT)
# include <libintl.h>
# define _(str) dgettext(PACKAGE, str)
#else
# define _(str) str
#endif
#define N_(str) str

typedef char * YYSTYPE;
extern YYSTYPE cfg_yylval;

// #define YY_DECL int cfg_yylex YY_PROTO(( cfg_t *cfg ))

/* temporary buffer for the quoted strings scanner
 */
char *cfg_qstring = NULL;
static unsigned int qstring_index = 0;
static unsigned int qstring_len = 0;
static void qputc(char ch);
#define CFG_QSTRING_BUFSIZ 32

#define MAX_INCLUDE_DEPTH 10
struct {
    YY_BUFFER_STATE state;
    char *filename;
    unsigned int line;
} cfg_include_stack[MAX_INCLUDE_DEPTH];
int cfg_include_stack_ptr = 0;

static YY_BUFFER_STATE pre_string_scan_state = 0;
static YY_BUFFER_STATE string_scan_state = 0;

/* start conditions
*/
#define comment 1

#define dq_str 2

#define sq_str 3


/* Macros after this point can all be overridden by user definitions in
 * section 1.
 */

#ifndef YY_SKIP_YYWRAP
#ifdef __cplusplus
extern "C" int yywrap YY_PROTO(( void ));
#else
extern int yywrap YY_PROTO(( void ));
#endif
#endif

#ifndef YY_NO_UNPUT
static void yyunput YY_PROTO(( int c, char *buf_ptr ));
#endif

#ifndef yytext_ptr
static void yy_flex_strncpy YY_PROTO(( char *, yyconst char *, int ));
#endif

#ifdef YY_NEED_STRLEN
static int yy_flex_strlen YY_PROTO(( yyconst char * ));
#endif

#ifndef YY_NO_INPUT
#ifdef __cplusplus
static int yyinput YY_PROTO(( void ));
#else
static int input YY_PROTO(( void ));
#endif
#endif

#if YY_STACK_USED
static int yy_start_stack_ptr = 0;
static int yy_start_stack_depth = 0;
static int *yy_start_stack = 0;
#ifndef YY_NO_PUSH_STATE
static void yy_push_state YY_PROTO(( int new_state ));
#endif
#ifndef YY_NO_POP_STATE
static void yy_pop_state YY_PROTO(( void ));
#endif
#ifndef YY_NO_TOP_STATE
static int yy_top_state YY_PROTO(( void ));
#endif

#else
#define YY_NO_PUSH_STATE 1
#define YY_NO_POP_STATE 1
#define YY_NO_TOP_STATE 1
#endif

#ifdef YY_MALLOC_DECL
YY_MALLOC_DECL
#else
#if __STDC__
#ifndef __cplusplus
#include <stdlib.h>
#endif
#else
/* Just try to get by without declaring the routines.  This will fail
 * miserably on non-ANSI systems for which sizeof(size_t) != sizeof(int)
 * or sizeof(void*) != sizeof(int).
 */
#endif
#endif

/* Amount of stuff to slurp up with each read. */
#ifndef YY_READ_BUF_SIZE
#define YY_READ_BUF_SIZE 8192
#endif

/* Copy whatever the last rule matched to the standard output. */

#ifndef ECHO
/* This used to be an fputs(), but since the string might contain NUL's,
 * we now use fwrite().
 */
#define ECHO (void) fwrite( yytext, yyleng, 1, yyout )
#endif

/* Gets input and stuffs it into "buf".  number of characters read, or YY_NULL,
 * is returned in "result".
 */
#ifndef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
	if ( yy_current_buffer->yy_is_interactive ) \
		{ \
		int c = '*', n; \
		for ( n = 0; n < max_size && \
			     (c = getc( yyin )) != EOF && c != '\n'; ++n ) \
			buf[n] = (char) c; \
		if ( c == '\n' ) \
			buf[n++] = (char) c; \
		if ( c == EOF && ferror( yyin ) ) \
			YY_FATAL_ERROR( "input in flex scanner failed" ); \
		result = n; \
		} \
	else if ( ((result = fread( buf, 1, max_size, yyin )) == 0) \
		  && ferror( yyin ) ) \
		YY_FATAL_ERROR( "input in flex scanner failed" );
#endif

/* No semi-colon after return; correct usage is to write "yyterminate();" -
 * we don't want an extra ';' after the "return" because that will cause
 * some compilers to complain about unreachable statements.
 */
#ifndef yyterminate
#define yyterminate() return YY_NULL
#endif

/* Number of entries by which start-condition stack grows. */
#ifndef YY_START_STACK_INCR
#define YY_START_STACK_INCR 25
#endif

/* Report a fatal error. */
#ifndef YY_FATAL_ERROR
#define YY_FATAL_ERROR(msg) yy_fatal_error( msg )
#endif

/* Default declaration of generated scanner - a define so the user can
 * easily add parameters.
#ifndef YY_DECL
// #define YY_DECL int yylex YY_PROTO(( void ))
#define YY_DECL int cfg_yylex YY_PROTO(( cfg_t *cfg ))
#endif
*/

/* Code executed at the beginning of each rule, after yytext and yyleng
 * have been set up.
 */
#ifndef YY_USER_ACTION
#define YY_USER_ACTION
#endif

/* Code executed at the end of each rule. */
#ifndef YY_BREAK
#define YY_BREAK break;
#endif

#define YY_RULE_SETUP \
	YY_USER_ACTION

int cfg_yylex /* YY_PROTO( */( cfg_t *cfg ) /*)*/
	{
	register yy_state_type yy_current_state;
	register char *yy_cp, *yy_bp;
	register int yy_act;

	if ( yy_init )
		{
		yy_init = 0;

#ifdef YY_USER_INIT
		YY_USER_INIT;
#endif

		if ( ! yy_start )
			yy_start = 1;	/* first start state */

		if ( ! yyin )
			yyin = stdin;

		if ( ! yyout )
			yyout = stdout;

		if ( ! yy_current_buffer )
			yy_current_buffer =
				yy_create_buffer( yyin, YY_BUF_SIZE );

		yy_load_buffer_state();
		}

	while ( 1 )		/* loops until end-of-file is reached */
		{
		yy_cp = yy_c_buf_p;

		/* Support of yytext. */
		*yy_cp = yy_hold_char;

		/* yy_bp points to the position in yy_ch_buf of the start of
		 * the current run.
		 */
		yy_bp = yy_cp;

		yy_current_state = yy_start;
yy_match:
		do
			{
			register YY_CHAR yy_c = yy_ec[YY_SC_TO_UI(*yy_cp)];
			if ( yy_accept[yy_current_state] )
				{
				yy_last_accepting_state = yy_current_state;
				yy_last_accepting_cpos = yy_cp;
				}
			while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
				{
				yy_current_state = (int) yy_def[yy_current_state];
				if ( yy_current_state >= 81 )
					yy_c = yy_meta[(unsigned int) yy_c];
				}
			yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
			++yy_cp;
			}
		while ( yy_base[yy_current_state] != 225 );

yy_find_action:
		yy_act = yy_accept[yy_current_state];
		if ( yy_act == 0 )
			{ /* have to back up */
			yy_cp = yy_last_accepting_cpos;
			yy_current_state = yy_last_accepting_state;
			yy_act = yy_accept[yy_current_state];
			}

		YY_DO_BEFORE_ACTION;


do_action:	/* This label is used only to access EOF actions. */


		switch ( yy_act )
	{ /* beginning of action switch */
			case 0: /* must back up */
			/* undo the effects of YY_DO_BEFORE_ACTION */
			*yy_cp = yy_hold_char;
			yy_cp = yy_last_accepting_cpos;
			yy_current_state = yy_last_accepting_state;
			goto yy_find_action;

	case 1:
	YY_RULE_SETUP
	/* eat up whitespace */
		YY_BREAK
	case 2:
	YY_RULE_SETUP
	cfg->line++; /* keep track of line number */
		YY_BREAK
	case 3:
	YY_RULE_SETUP
	/* eat up one-line comments */
		YY_BREAK
	/* special keywords/symbols
	  */
	case 4:
	YY_RULE_SETUP
	{ cfg_yylval = yytext; return '{'; }
		YY_BREAK
	case 5:
	YY_RULE_SETUP
	{ cfg_yylval = yytext; return '}'; }
		YY_BREAK
	case 6:
	YY_RULE_SETUP
	{ cfg_yylval = yytext; return '('; }
		YY_BREAK
	case 7:
	YY_RULE_SETUP
	{ cfg_yylval = yytext; return ')'; }
		YY_BREAK
	case 8:
	YY_RULE_SETUP
	{ cfg_yylval = yytext; return '='; }
		YY_BREAK
	case 9:
	YY_RULE_SETUP
	{ cfg_yylval = yytext; return '+'; }
		YY_BREAK
	case 10:
	YY_RULE_SETUP
	{ cfg_yylval = yytext; return ','; }
		YY_BREAK
	/* handle multi-line C-style comments
	  */
	case 11:
	YY_RULE_SETUP
	BEGIN(comment);
		YY_BREAK
	case 12:
	YY_RULE_SETUP
	/* eat anything that's not a '*' */
		YY_BREAK
	case 13:
	YY_RULE_SETUP
	/* eat up '*'s not followed by '/'s */
		YY_BREAK
	case 14:
	YY_RULE_SETUP
	cfg->line++;
		YY_BREAK
	case 15:
	YY_RULE_SETUP
	BEGIN(INITIAL);
		YY_BREAK
	/* handle C-style strings
	  */
	case 16:
	YY_RULE_SETUP
	{
	    qstring_index = 0;
	    BEGIN(dq_str);
	}
		YY_BREAK
	case 17:
	YY_RULE_SETUP
	{ /* saw closing quote - all done */
	    BEGIN(INITIAL);
	    qputc('\0');
	    cfg_yylval = cfg_qstring;
	    return CFGT_STR;
	 }
		YY_BREAK
	case 18:
	YY_RULE_SETUP
	{ /* environment variable substitution */
	    char *var;
	    char *e;
	    yytext[strlen(yytext) - 1] = 0;
	    e = strchr(yytext+2, ':');
	    if(e && e[1] == '-')
	        *e = 0;
	    else
	        e = 0;
	    var = getenv(yytext+2);
	    if(!var && e)
	        var = e+2;
	    while(var && *var)
	        qputc(*var++);
	}
		YY_BREAK
	case 19:
	YY_RULE_SETUP
	{
	    qputc('\n');
	    cfg->line++;
	}
		YY_BREAK
	case 20:
	YY_RULE_SETUP
	{ /* allow continuing on next line */
	    /* no-op */
	    cfg->line++;
	}
		YY_BREAK
	case 21:
	YY_RULE_SETUP
	{  /* octal escape sequence */
	    int result;
	    sscanf(yytext + 1, "%o", &result);
	    if(result > 0xFF) {
	        cfg_error(cfg, _("invalid octal number '%s'"), yytext);
	        return 0;
	    }
	    qputc(result);
	 }
		YY_BREAK
	case 22:
	YY_RULE_SETUP
	{
	    cfg_error(cfg, _("bad escape sequence '%s'"), yytext);
	    return 0;
	}
		YY_BREAK
	case 23:
	YY_RULE_SETUP
	{ /* hexadecimal escape sequence */
	    int result;
	    sscanf(yytext + 2, "%x", &result);
	    qputc(result);
	}
		YY_BREAK
	case 24:
	YY_RULE_SETUP
	{
	    qputc('\n');
	}
		YY_BREAK
	case 25:
	YY_RULE_SETUP
	{
	    qputc('\r');
	}
		YY_BREAK
	case 26:
	YY_RULE_SETUP
	{
	    qputc('\b');
	}
		YY_BREAK
	case 27:
	YY_RULE_SETUP
	{
	    qputc('\f');
	}
		YY_BREAK
	case 28:
	YY_RULE_SETUP
	{
	    qputc('\007');
	}
		YY_BREAK
	case 29:
	YY_RULE_SETUP
	{
	    qputc('\033');
	}
		YY_BREAK
	case 30:
	YY_RULE_SETUP
	{
	    qputc('\t');
	}
		YY_BREAK
	case 31:
	YY_RULE_SETUP
	{
	    qputc('\v');
	}
		YY_BREAK
	case 32:
	YY_RULE_SETUP
	{
	    qputc(yytext[1]);
	}
		YY_BREAK
	case 33:
	YY_RULE_SETUP
	{
	    char *yptr = yytext;
	    while(*yptr) {
	        qputc(*yptr++);
	    }
	}
		YY_BREAK
	/* single-quoted string ('...') */
	case 34:
	YY_RULE_SETUP
	{
	    qstring_index = 0;
	    BEGIN(sq_str);
	}
		YY_BREAK
	case 35:
	YY_RULE_SETUP
	{ /* saw closing quote - all done */
	    BEGIN(INITIAL);
	    qputc('\0');
	    cfg_yylval = cfg_qstring;
	    return CFGT_STR;
	}
		YY_BREAK
	case 36:
	YY_RULE_SETUP
	{
	    qputc('\n');
	    cfg->line++;
	}
		YY_BREAK
	case 37:
	YY_RULE_SETUP
	{ /* allow continuing on next line */
	    /* no-op */
	    cfg->line++;
	}
		YY_BREAK
	case 38:
	YY_RULE_SETUP
	{
	    qputc(yytext[1]);
	}
		YY_BREAK
	case 39:
	YY_RULE_SETUP
	{
	    qputc(yytext[0]);
	    qputc(yytext[1]);
	}
		YY_BREAK
	case 40:
	YY_RULE_SETUP
	{
	    char *cp = yytext;
	    while(*cp != '\0') {
	        qputc(*cp++);
	    }
	}
		YY_BREAK
	case YY_STATE_EOF(sq_str):
	{
	    cfg_error(cfg, _("unterminated string constant"));
	    return 0;
	}
		YY_BREAK
	case YY_STATE_EOF(INITIAL):
	case YY_STATE_EOF(comment):
	case YY_STATE_EOF(dq_str):
	{
	             if( string_scan_state != 0 || cfg_include_stack_ptr <= 0 )
	                 {
	                 return EOF;
	                 }
	
	             else
	                 {
	                 yy_delete_buffer( YY_CURRENT_BUFFER );
	                 fclose(cfg_yyin);
	                 cfg_yyin = 0;
	                 --cfg_include_stack_ptr;
	                 yy_switch_to_buffer(
	                      cfg_include_stack[cfg_include_stack_ptr].state );
	                 free(cfg->filename);
	                 cfg->filename = cfg_include_stack[cfg_include_stack_ptr].filename;
	                 cfg->line = cfg_include_stack[cfg_include_stack_ptr].line;
	                 }
	}
		YY_BREAK
	case 41:
	YY_RULE_SETUP
	{
	    char *var;
	    char *e;
	    yytext[strlen(yytext) - 1] = 0;
	    e = strchr(yytext+2, ':');
	    if(e && e[1] == '-')
	        *e = 0;
	    else
	        e = 0;
	    var = getenv(yytext+2);
	    if(!var && e)
	        var = e+2;
	    if(!var)
	        var = "";
	    cfg_yylval = var;
	    return CFGT_STR;
	}
		YY_BREAK
	/* an unquoted string
	  * a slash can't be followed by another slash (c++
	  * comment) or an asterisk (C multi-line comment)
	  */
	case 42:
	YY_RULE_SETUP
	{
	    cfg_yylval = yytext;
	    return CFGT_STR;
	 }
		YY_BREAK
	case 43:
	YY_RULE_SETUP
	ECHO;
		YY_BREAK
	
	case YY_END_OF_BUFFER:
		{
		/* Amount of text matched not including the EOB char. */
		int yy_amount_of_matched_text = (int) (yy_cp - yytext_ptr) - 1;

		/* Undo the effects of YY_DO_BEFORE_ACTION. */
		*yy_cp = yy_hold_char;
		YY_RESTORE_YY_MORE_OFFSET

		if ( yy_current_buffer->yy_buffer_status == YY_BUFFER_NEW )
			{
			/* We're scanning a new file or input source.  It's
			 * possible that this happened because the user
			 * just pointed yyin at a new source and called
			 * yylex().  If so, then we have to assure
			 * consistency between yy_current_buffer and our
			 * globals.  Here is the right place to do so, because
			 * this is the first action (other than possibly a
			 * back-up) that will match for the new input source.
			 */
			yy_n_chars = yy_current_buffer->yy_n_chars;
			yy_current_buffer->yy_input_file = yyin;
			yy_current_buffer->yy_buffer_status = YY_BUFFER_NORMAL;
			}

		/* Note that here we test for yy_c_buf_p "<=" to the position
		 * of the first EOB in the buffer, since yy_c_buf_p will
		 * already have been incremented past the NUL character
		 * (since all states make transitions on EOB to the
		 * end-of-buffer state).  Contrast this with the test
		 * in input().
		 */
		if ( yy_c_buf_p <= &yy_current_buffer->yy_ch_buf[yy_n_chars] )
			{ /* This was really a NUL. */
			yy_state_type yy_next_state;

			yy_c_buf_p = yytext_ptr + yy_amount_of_matched_text;

			yy_current_state = yy_get_previous_state();

			/* Okay, we're now positioned to make the NUL
			 * transition.  We couldn't have
			 * yy_get_previous_state() go ahead and do it
			 * for us because it doesn't know how to deal
			 * with the possibility of jamming (and we don't
			 * want to build jamming into it because then it
			 * will run more slowly).
			 */

			yy_next_state = yy_try_NUL_trans( yy_current_state );

			yy_bp = yytext_ptr + YY_MORE_ADJ;

			if ( yy_next_state )
				{
				/* Consume the NUL. */
				yy_cp = ++yy_c_buf_p;
				yy_current_state = yy_next_state;
				goto yy_match;
				}

			else
				{
				yy_cp = yy_c_buf_p;
				goto yy_find_action;
				}
			}

		else switch ( yy_get_next_buffer() )
			{
			case EOB_ACT_END_OF_FILE:
				{
				yy_did_buffer_switch_on_eof = 0;

				if ( yywrap() )
					{
					/* Note: because we've taken care in
					 * yy_get_next_buffer() to have set up
					 * yytext, we can now set up
					 * yy_c_buf_p so that if some total
					 * hoser (like flex itself) wants to
					 * call the scanner after we return the
					 * YY_NULL, it'll still work - another
					 * YY_NULL will get returned.
					 */
					yy_c_buf_p = yytext_ptr + YY_MORE_ADJ;

					yy_act = YY_STATE_EOF(YY_START);
					goto do_action;
					}

				else
					{
					if ( ! yy_did_buffer_switch_on_eof )
						YY_NEW_FILE;
					}
				break;
				}

			case EOB_ACT_CONTINUE_SCAN:
				yy_c_buf_p =
					yytext_ptr + yy_amount_of_matched_text;

				yy_current_state = yy_get_previous_state();

				yy_cp = yy_c_buf_p;
				yy_bp = yytext_ptr + YY_MORE_ADJ;
				goto yy_match;

			case EOB_ACT_LAST_MATCH:
				yy_c_buf_p =
				&yy_current_buffer->yy_ch_buf[yy_n_chars];

				yy_current_state = yy_get_previous_state();

				yy_cp = yy_c_buf_p;
				yy_bp = yytext_ptr + YY_MORE_ADJ;
				goto yy_find_action;
			}
		break;
		}

	default:
		YY_FATAL_ERROR(
			"fatal flex scanner internal error--no action found" );
	} /* end of action switch */
		} /* end of scanning one token */
	} /* end of yylex */


/* yy_get_next_buffer - try to read in a new buffer
 *
 * Returns a code representing an action:
 *	EOB_ACT_LAST_MATCH -
 *	EOB_ACT_CONTINUE_SCAN - continue scanning from current position
 *	EOB_ACT_END_OF_FILE - end of file
 */

static int yy_get_next_buffer()
	{
	register char *dest = yy_current_buffer->yy_ch_buf;
	register char *source = yytext_ptr;
	register int number_to_move, i;
	int ret_val;

	if ( yy_c_buf_p > &yy_current_buffer->yy_ch_buf[yy_n_chars + 1] )
		YY_FATAL_ERROR(
		"fatal flex scanner internal error--end of buffer missed" );

	if ( yy_current_buffer->yy_fill_buffer == 0 )
		{ /* Don't try to fill the buffer, so this is an EOF. */
		if ( yy_c_buf_p - yytext_ptr - YY_MORE_ADJ == 1 )
			{
			/* We matched a single character, the EOB, so
			 * treat this as a final EOF.
			 */
			return EOB_ACT_END_OF_FILE;
			}

		else
			{
			/* We matched some text prior to the EOB, first
			 * process it.
			 */
			return EOB_ACT_LAST_MATCH;
			}
		}

	/* Try to read more data. */

	/* First move last chars to start of buffer. */
	number_to_move = (int) (yy_c_buf_p - yytext_ptr) - 1;

	for ( i = 0; i < number_to_move; ++i )
		*(dest++) = *(source++);

	if ( yy_current_buffer->yy_buffer_status == YY_BUFFER_EOF_PENDING )
		/* don't do the read, it's not guaranteed to return an EOF,
		 * just force an EOF
		 */
		yy_current_buffer->yy_n_chars = yy_n_chars = 0;

	else
		{
		int num_to_read =
			yy_current_buffer->yy_buf_size - number_to_move - 1;

		while ( num_to_read <= 0 )
			{ /* Not enough room in the buffer - grow it. */
#ifdef YY_USES_REJECT
			YY_FATAL_ERROR(
"input buffer overflow, can't enlarge buffer because scanner uses REJECT" );
#else

			/* just a shorter name for the current buffer */
			YY_BUFFER_STATE b = yy_current_buffer;

			int yy_c_buf_p_offset =
				(int) (yy_c_buf_p - b->yy_ch_buf);

			if ( b->yy_is_our_buffer )
				{
				int new_size = b->yy_buf_size * 2;

				if ( new_size <= 0 )
					b->yy_buf_size += b->yy_buf_size / 8;
				else
					b->yy_buf_size *= 2;

				b->yy_ch_buf = (char *)
					/* Include room in for 2 EOB chars. */
					yy_flex_realloc( (void *) b->yy_ch_buf,
							 b->yy_buf_size + 2 );
				}
			else
				/* Can't grow it, we don't own it. */
				b->yy_ch_buf = 0;

			if ( ! b->yy_ch_buf )
				YY_FATAL_ERROR(
				"fatal error - scanner input buffer overflow" );

			yy_c_buf_p = &b->yy_ch_buf[yy_c_buf_p_offset];

			num_to_read = yy_current_buffer->yy_buf_size -
						number_to_move - 1;
#endif
			}

		if ( num_to_read > YY_READ_BUF_SIZE )
			num_to_read = YY_READ_BUF_SIZE;

		/* Read in more data. */
		YY_INPUT( (&yy_current_buffer->yy_ch_buf[number_to_move]),
			yy_n_chars, num_to_read );

		yy_current_buffer->yy_n_chars = yy_n_chars;
		}

	if ( yy_n_chars == 0 )
		{
		if ( number_to_move == YY_MORE_ADJ )
			{
			ret_val = EOB_ACT_END_OF_FILE;
			yyrestart( yyin );
			}

		else
			{
			ret_val = EOB_ACT_LAST_MATCH;
			yy_current_buffer->yy_buffer_status =
				YY_BUFFER_EOF_PENDING;
			}
		}

	else
		ret_val = EOB_ACT_CONTINUE_SCAN;

	yy_n_chars += number_to_move;
	yy_current_buffer->yy_ch_buf[yy_n_chars] = YY_END_OF_BUFFER_CHAR;
	yy_current_buffer->yy_ch_buf[yy_n_chars + 1] = YY_END_OF_BUFFER_CHAR;

	yytext_ptr = &yy_current_buffer->yy_ch_buf[0];

	return ret_val;
	}


/* yy_get_previous_state - get the state just before the EOB char was reached */

static yy_state_type yy_get_previous_state()
	{
	register yy_state_type yy_current_state;
	register char *yy_cp;

	yy_current_state = yy_start;

	for ( yy_cp = yytext_ptr + YY_MORE_ADJ; yy_cp < yy_c_buf_p; ++yy_cp )
		{
		register YY_CHAR yy_c = (*yy_cp ? yy_ec[YY_SC_TO_UI(*yy_cp)] : 1);
		if ( yy_accept[yy_current_state] )
			{
			yy_last_accepting_state = yy_current_state;
			yy_last_accepting_cpos = yy_cp;
			}
		while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
			{
			yy_current_state = (int) yy_def[yy_current_state];
			if ( yy_current_state >= 81 )
				yy_c = yy_meta[(unsigned int) yy_c];
			}
		yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
		}

	return yy_current_state;
	}


/* yy_try_NUL_trans - try to make a transition on the NUL character
 *
 * synopsis
 *	next_state = yy_try_NUL_trans( current_state );
 */

#ifdef YY_USE_PROTOS
static yy_state_type yy_try_NUL_trans( yy_state_type yy_current_state )
#else
static yy_state_type yy_try_NUL_trans( yy_current_state )
yy_state_type yy_current_state;
#endif
	{
	register int yy_is_jam;
	register char *yy_cp = yy_c_buf_p;

	register YY_CHAR yy_c = 1;
	if ( yy_accept[yy_current_state] )
		{
		yy_last_accepting_state = yy_current_state;
		yy_last_accepting_cpos = yy_cp;
		}
	while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
		{
		yy_current_state = (int) yy_def[yy_current_state];
		if ( yy_current_state >= 81 )
			yy_c = yy_meta[(unsigned int) yy_c];
		}
	yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
	yy_is_jam = (yy_current_state == 80);

	return yy_is_jam ? 0 : yy_current_state;
	}


#ifndef YY_NO_UNPUT
#ifdef YY_USE_PROTOS
static void yyunput( int c, register char *yy_bp )
#else
static void yyunput( c, yy_bp )
int c;
register char *yy_bp;
#endif
	{
	register char *yy_cp = yy_c_buf_p;

	/* undo effects of setting up yytext */
	*yy_cp = yy_hold_char;

	if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )
		{ /* need to shift things up to make room */
		/* +2 for EOB chars. */
		register int number_to_move = yy_n_chars + 2;
		register char *dest = &yy_current_buffer->yy_ch_buf[
					yy_current_buffer->yy_buf_size + 2];
		register char *source =
				&yy_current_buffer->yy_ch_buf[number_to_move];

		while ( source > yy_current_buffer->yy_ch_buf )
			*--dest = *--source;

		yy_cp += (int) (dest - source);
		yy_bp += (int) (dest - source);
		yy_current_buffer->yy_n_chars =
			yy_n_chars = yy_current_buffer->yy_buf_size;

		if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )
			YY_FATAL_ERROR( "flex scanner push-back overflow" );
		}

	*--yy_cp = (char) c;


	yytext_ptr = yy_bp;
	yy_hold_char = *yy_cp;
	yy_c_buf_p = yy_cp;
	}
#endif	/* ifndef YY_NO_UNPUT */


#ifdef __cplusplus
static int yyinput()
#else
static int input()
#endif
	{
	int c;

	*yy_c_buf_p = yy_hold_char;

	if ( *yy_c_buf_p == YY_END_OF_BUFFER_CHAR )
		{
		/* yy_c_buf_p now points to the character we want to return.
		 * If this occurs *before* the EOB characters, then it's a
		 * valid NUL; if not, then we've hit the end of the buffer.
		 */
		if ( yy_c_buf_p < &yy_current_buffer->yy_ch_buf[yy_n_chars] )
			/* This was really a NUL. */
			*yy_c_buf_p = '\0';

		else
			{ /* need more input */
			int offset = yy_c_buf_p - yytext_ptr;
			++yy_c_buf_p;

			switch ( yy_get_next_buffer() )
				{
				case EOB_ACT_LAST_MATCH:
					/* This happens because yy_g_n_b()
					 * sees that we've accumulated a
					 * token and flags that we need to
					 * try matching the token before
					 * proceeding.  But for input(),
					 * there's no matching to consider.
					 * So convert the EOB_ACT_LAST_MATCH
					 * to EOB_ACT_END_OF_FILE.
					 */

					/* Reset buffer status. */
					yyrestart( yyin );

					/* fall through */

				case EOB_ACT_END_OF_FILE:
					{
					if ( yywrap() )
						return EOF;

					if ( ! yy_did_buffer_switch_on_eof )
						YY_NEW_FILE;
#ifdef __cplusplus
					return yyinput();
#else
					return input();
#endif
					}

				case EOB_ACT_CONTINUE_SCAN:
					yy_c_buf_p = yytext_ptr + offset;
					break;
				}
			}
		}

	c = *(unsigned char *) yy_c_buf_p;	/* cast for 8-bit char's */
	*yy_c_buf_p = '\0';	/* preserve yytext */
	yy_hold_char = *++yy_c_buf_p;


	return c;
	}


#ifdef YY_USE_PROTOS
void yyrestart( FILE *input_file )
#else
void yyrestart( input_file )
FILE *input_file;
#endif
	{
	if ( ! yy_current_buffer )
		yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE );

	yy_init_buffer( yy_current_buffer, input_file );
	yy_load_buffer_state();
	}


#ifdef YY_USE_PROTOS
void yy_switch_to_buffer( YY_BUFFER_STATE new_buffer )
#else
void yy_switch_to_buffer( new_buffer )
YY_BUFFER_STATE new_buffer;
#endif
	{
	if ( yy_current_buffer == new_buffer )
		return;

	if ( yy_current_buffer )
		{
		/* Flush out information for old buffer. */
		*yy_c_buf_p = yy_hold_char;
		yy_current_buffer->yy_buf_pos = yy_c_buf_p;
		yy_current_buffer->yy_n_chars = yy_n_chars;
		}

	yy_current_buffer = new_buffer;
	yy_load_buffer_state();

	/* We don't actually know whether we did this switch during
	 * EOF (yywrap()) processing, but the only time this flag
	 * is looked at is after yywrap() is called, so it's safe
	 * to go ahead and always set it.
	 */
	yy_did_buffer_switch_on_eof = 1;
	}


#ifdef YY_USE_PROTOS
void yy_load_buffer_state( void )
#else
void yy_load_buffer_state()
#endif
	{
	yy_n_chars = yy_current_buffer->yy_n_chars;
	yytext_ptr = yy_c_buf_p = yy_current_buffer->yy_buf_pos;
	yyin = yy_current_buffer->yy_input_file;
	yy_hold_char = *yy_c_buf_p;
	}


#ifdef YY_USE_PROTOS
YY_BUFFER_STATE yy_create_buffer( FILE *file, int size )
#else
YY_BUFFER_STATE yy_create_buffer( file, size )
FILE *file;
int size;
#endif
	{
	YY_BUFFER_STATE b;

	b = (YY_BUFFER_STATE) yy_flex_alloc( sizeof( struct yy_buffer_state ) );
	if ( ! b )
		YY_FATAL_ERROR( "out of dynamic memory in yy_create_buffer()" );

	b->yy_buf_size = size;

	/* yy_ch_buf has to be 2 characters longer than the size given because
	 * we need to put in 2 end-of-buffer characters.
	 */
	b->yy_ch_buf = (char *) yy_flex_alloc( b->yy_buf_size + 2 );
	if ( ! b->yy_ch_buf )
		YY_FATAL_ERROR( "out of dynamic memory in yy_create_buffer()" );

	b->yy_is_our_buffer = 1;

	yy_init_buffer( b, file );

	return b;
	}


#ifdef YY_USE_PROTOS
void yy_delete_buffer( YY_BUFFER_STATE b )
#else
void yy_delete_buffer( b )
YY_BUFFER_STATE b;
#endif
	{
	if ( ! b )
		return;

	if ( b == yy_current_buffer )
		yy_current_buffer = (YY_BUFFER_STATE) 0;

	if ( b->yy_is_our_buffer )
		yy_flex_free( (void *) b->yy_ch_buf );

	yy_flex_free( (void *) b );
	}


#ifndef YY_ALWAYS_INTERACTIVE
#ifndef YY_NEVER_INTERACTIVE
extern int isatty YY_PROTO(( int ));
#endif
#endif

#ifdef YY_USE_PROTOS
void yy_init_buffer( YY_BUFFER_STATE b, FILE *file )
#else
void yy_init_buffer( b, file )
YY_BUFFER_STATE b;
FILE *file;
#endif


	{
	yy_flush_buffer( b );

	b->yy_input_file = file;
	b->yy_fill_buffer = 1;

#if YY_ALWAYS_INTERACTIVE
	b->yy_is_interactive = 1;
#else
#if YY_NEVER_INTERACTIVE
	b->yy_is_interactive = 0;
#else
	b->yy_is_interactive = file ? (isatty( fileno(file) ) > 0) : 0;
#endif
#endif
	}


#ifdef YY_USE_PROTOS
void yy_flush_buffer( YY_BUFFER_STATE b )
#else
void yy_flush_buffer( b )
YY_BUFFER_STATE b;
#endif

	{
	if ( ! b )
		return;

	b->yy_n_chars = 0;

	/* We always need two end-of-buffer characters.  The first causes
	 * a transition to the end-of-buffer state.  The second causes
	 * a jam in that state.
	 */
	b->yy_ch_buf[0] = YY_END_OF_BUFFER_CHAR;
	b->yy_ch_buf[1] = YY_END_OF_BUFFER_CHAR;

	b->yy_buf_pos = &b->yy_ch_buf[0];

	b->yy_at_bol = 1;
	b->yy_buffer_status = YY_BUFFER_NEW;

	if ( b == yy_current_buffer )
		yy_load_buffer_state();
	}


#ifndef YY_NO_SCAN_BUFFER
#ifdef YY_USE_PROTOS
YY_BUFFER_STATE yy_scan_buffer( char *base, yy_size_t size )
#else
YY_BUFFER_STATE yy_scan_buffer( base, size )
char *base;
yy_size_t size;
#endif
	{
	YY_BUFFER_STATE b;

	if ( size < 2 ||
	     base[size-2] != YY_END_OF_BUFFER_CHAR ||
	     base[size-1] != YY_END_OF_BUFFER_CHAR )
		/* They forgot to leave room for the EOB's. */
		return 0;

	b = (YY_BUFFER_STATE) yy_flex_alloc( sizeof( struct yy_buffer_state ) );
	if ( ! b )
		YY_FATAL_ERROR( "out of dynamic memory in yy_scan_buffer()" );

	b->yy_buf_size = size - 2;	/* "- 2" to take care of EOB's */
	b->yy_buf_pos = b->yy_ch_buf = base;
	b->yy_is_our_buffer = 0;
	b->yy_input_file = 0;
	b->yy_n_chars = b->yy_buf_size;
	b->yy_is_interactive = 0;
	b->yy_at_bol = 1;
	b->yy_fill_buffer = 0;
	b->yy_buffer_status = YY_BUFFER_NEW;

	yy_switch_to_buffer( b );

	return b;
	}
#endif


#ifndef YY_NO_SCAN_STRING
#ifdef YY_USE_PROTOS
YY_BUFFER_STATE yy_scan_string( yyconst char *yy_str )
#else
YY_BUFFER_STATE yy_scan_string( yy_str )
yyconst char *yy_str;
#endif
	{
	int len;
	for ( len = 0; yy_str[len]; ++len )
		;

	return yy_scan_bytes( yy_str, len );
	}
#endif


#ifndef YY_NO_SCAN_BYTES
#ifdef YY_USE_PROTOS
YY_BUFFER_STATE yy_scan_bytes( yyconst char *bytes, int len )
#else
YY_BUFFER_STATE yy_scan_bytes( bytes, len )
yyconst char *bytes;
int len;
#endif
	{
	YY_BUFFER_STATE b;
	char *buf;
	yy_size_t n;
	int i;

	/* Get memory for full buffer, including space for trailing EOB's. */
	n = len + 2;
	buf = (char *) yy_flex_alloc( n );
	if ( ! buf )
		YY_FATAL_ERROR( "out of dynamic memory in yy_scan_bytes()" );

	for ( i = 0; i < len; ++i )
		buf[i] = bytes[i];

	buf[len] = buf[len+1] = YY_END_OF_BUFFER_CHAR;

	b = yy_scan_buffer( buf, n );
	if ( ! b )
		YY_FATAL_ERROR( "bad buffer in yy_scan_bytes()" );

	/* It's okay to grow etc. this buffer, and we should throw it
	 * away when we're done.
	 */
	b->yy_is_our_buffer = 1;

	return b;
	}
#endif


#ifndef YY_NO_PUSH_STATE
#ifdef YY_USE_PROTOS
static void yy_push_state( int new_state )
#else
static void yy_push_state( new_state )
int new_state;
#endif
	{
	if ( yy_start_stack_ptr >= yy_start_stack_depth )
		{
		yy_size_t new_size;

		yy_start_stack_depth += YY_START_STACK_INCR;
		new_size = yy_start_stack_depth * sizeof( int );

		if ( ! yy_start_stack )
			yy_start_stack = (int *) yy_flex_alloc( new_size );

		else
			yy_start_stack = (int *) yy_flex_realloc(
					(void *) yy_start_stack, new_size );

		if ( ! yy_start_stack )
			YY_FATAL_ERROR(
			"out of memory expanding start-condition stack" );
		}

	yy_start_stack[yy_start_stack_ptr++] = YY_START;

	BEGIN(new_state);
	}
#endif


#ifndef YY_NO_POP_STATE
static void yy_pop_state()
	{
	if ( --yy_start_stack_ptr < 0 )
		YY_FATAL_ERROR( "start-condition stack underflow" );

	BEGIN(yy_start_stack[yy_start_stack_ptr]);
	}
#endif


#ifndef YY_NO_TOP_STATE
static int yy_top_state()
	{
	return yy_start_stack[yy_start_stack_ptr - 1];
	}
#endif

#ifndef YY_EXIT_FAILURE
#define YY_EXIT_FAILURE 2
#endif

#ifdef YY_USE_PROTOS
static void yy_fatal_error( yyconst char msg[] )
#else
static void yy_fatal_error( msg )
char msg[];
#endif
	{
	(void) fprintf( stderr, "%s\n", msg );
	exit( YY_EXIT_FAILURE );
	}



/* Redefine yyless() so it works in section 3 code. */

#undef yyless
#define yyless(n) \
	do \
		{ \
		/* Undo effects of setting up yytext. */ \
		yytext[yyleng] = yy_hold_char; \
		yy_c_buf_p = yytext + n; \
		yy_hold_char = *yy_c_buf_p; \
		*yy_c_buf_p = '\0'; \
		yyleng = n; \
		} \
	while ( 0 )


/* Internal utility routines. */

#ifndef yytext_ptr
#ifdef YY_USE_PROTOS
static void yy_flex_strncpy( char *s1, yyconst char *s2, int n )
#else
static void yy_flex_strncpy( s1, s2, n )
char *s1;
yyconst char *s2;
int n;
#endif
	{
	register int i;
	for ( i = 0; i < n; ++i )
		s1[i] = s2[i];
	}
#endif

#ifdef YY_NEED_STRLEN
#ifdef YY_USE_PROTOS
static int yy_flex_strlen( yyconst char *s )
#else
static int yy_flex_strlen( s )
yyconst char *s;
#endif
	{
	register int n;
	for ( n = 0; s[n]; ++n )
		;

	return n;
	}
#endif


#ifdef YY_USE_PROTOS
static void *yy_flex_alloc( yy_size_t size )
#else
static void *yy_flex_alloc( size )
yy_size_t size;
#endif
	{
	return (void *) malloc( size );
	}

#ifdef YY_USE_PROTOS
static void *yy_flex_realloc( void *ptr, yy_size_t size )
#else
static void *yy_flex_realloc( ptr, size )
void *ptr;
yy_size_t size;
#endif
	{
	/* The cast to (char *) in the following accommodates both
	 * implementations that use char* generic pointers, and those
	 * that use void* generic pointers.  It works with the latter
	 * because both ANSI C and C++ allow castless assignment from
	 * any pointer type to void*, and deal with argument conversions
	 * as though doing an assignment.
	 */
	return (void *) realloc( (char *) ptr, size );
	}

#ifdef YY_USE_PROTOS
static void yy_flex_free( void *ptr )
#else
static void yy_flex_free( ptr )
void *ptr;
#endif
	{
	free( ptr );
	}

#if YY_MAIN
int main()
	{
	yylex();
	return 0;
	}
#endif


void cfg_dummy_function(void)
{
    /* please compiler :-)
     * otherwise "defined but not used" warning
     */
    yyunput(0, 0);
}

int cfg_lexer_include(cfg_t *cfg, const char *filename)
{
    char *xfilename;

    if(cfg_include_stack_ptr >= MAX_INCLUDE_DEPTH) {
        cfg_error(cfg, _("includes nested too deeply"));
        return 1;
    }

    cfg_include_stack[cfg_include_stack_ptr].state = YY_CURRENT_BUFFER;
    cfg_include_stack[cfg_include_stack_ptr].filename = cfg->filename;
    cfg_include_stack[cfg_include_stack_ptr].line = cfg->line;
    cfg_include_stack_ptr++;

    xfilename = cfg_tilde_expand(filename);

    cfg_yyin = fopen(xfilename, "r");

    if(!cfg_yyin) {
        cfg_error(cfg, "%s: %s", xfilename, strerror(errno));
        free(xfilename);
        return 1;
    }

    cfg->filename = xfilename;
    cfg->line = 1;

    yy_switch_to_buffer(yy_create_buffer(cfg_yyin, YY_BUF_SIZE));
    return 0;
}

/* write a character to the quoted string buffer, and reallocate as
 * necessary
 */
static void qputc(char ch)
{
    if(qstring_index >= qstring_len) {
        qstring_len += CFG_QSTRING_BUFSIZ;
        cfg_qstring = (char *)realloc(cfg_qstring, qstring_len);
        assert(cfg_qstring);
        memset(cfg_qstring + qstring_index, 0, CFG_QSTRING_BUFSIZ);
    }
    cfg_qstring[qstring_index++] = ch;
}

void cfg_scan_string_begin(const char *buf)
{
    pre_string_scan_state = YY_CURRENT_BUFFER;

    /* yy_scan_string does a yy_switch_to_buffer call for us
     */
    string_scan_state = yy_scan_string(buf);
}

void cfg_scan_string_end(void)
{
    /* restore to previous state
     */
    yy_delete_buffer(string_scan_state);
    yy_switch_to_buffer(pre_string_scan_state);
    free(cfg_qstring);
    cfg_qstring = 0;
    qstring_index = qstring_len = 0;
    string_scan_state = 0;
}

static YY_BUFFER_STATE pre_fp_scan_state;
static YY_BUFFER_STATE fp_scan_state;

void cfg_scan_fp_begin(FILE *fp)
{
    pre_fp_scan_state = YY_CURRENT_BUFFER;
    fp_scan_state = yy_create_buffer(fp, YY_BUF_SIZE);
    yy_switch_to_buffer(fp_scan_state);
}

void cfg_scan_fp_end(void)
{
    /* restore to previous state
     */
    yy_delete_buffer(fp_scan_state);
    if(pre_fp_scan_state)
        yy_switch_to_buffer(pre_fp_scan_state);
    free(cfg_qstring);
    cfg_qstring = 0;
    qstring_index = qstring_len = 0;
}
