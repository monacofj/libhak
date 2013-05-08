/*  messages.h - Messages generated by libhak.
    
    Copyright 2013  Francisco Jose Monaco   <monaco.fj@gmail.com>

    This file is part of Libhak. 

    Libhak is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Libhak is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with .  If not, see <http://www.gnu.org/licenses/>. 

*/

#ifndef _HAK_MESSAGES_H
#define _HAK_MESSAGES_H

#include <config.h>
#include <errno.h>
#include <string.h>

/* 
   Event report functions and macros. 
*/

#ifndef HAK_SYSFAULT_FATAL
#define HAK_SYSFAULT_FATAL HAK_TRUE	
#endif

#ifndef HAK_DEBUG
#define HAK_DEBUG HAK_TRUE
#endif
#ifndef HAK_DEBUG_FATAL
#define HAK_DEBUG_FATAL HAK_FALSE	
#endif

#ifndef HAK_ASSERT_FATAL
#define HAK_ASSERT_FATAL HAK_TRUE	
#endif

/* 
   If HAD_DEVMODE, all error checks are nonfatal.  
*/

#if HAK_DEVMODE==1
#undef HAK_SYSFAULT_FATAL
#undef HAK_DEBUG
#undef HAK_DEBUG_FATAL
#undef HAK_ASSERT_FATAL
#define HAK_SYSFAULT_FATAL HAK_FALSE
#define HAK_DEBUG HAK_TRUE
#define HAK_DEBUG_FATAL HAL_FALSE
#define HAK_ASSERT_FATAL HAK_FALSE
#endif


/* #define hak_symbol_string(type) hak_engine.symbol_ ## type ? hak_engine.symbol _ ## type : "" */
#define hak_symbol_string(type) (hak_engine.symbol_ ## type ? hak_engine.symbol_ ## type : "Bar ")

/* 
   Libhak sysfault: check and report system faults (syscall faults).
  
   If 'expression' is true, report error messagem confirming errno variable,
   and optionally exit with EXIT_FAILURE.
 */

/* System fatal error. */
#define hak_sysfault_fatal(expression) do{ if (expression) {fprintf (stderr, "%s%s: %s: %d: %s\n", hak_symbol_string(sysfault),hak_engine.program_name, __FILE__, __LINE__, strerror(errno)); exit (EXIT_FAILURE);}}while(0)

/* System non-fatal error. */
#define hak_sysfault_nonfatal(expression) do{ if (expression) {fprintf (stderr,"%s%s: %s: %d: %s\n", hak_symbol_string(sysfault), hak_engine.program_name, __FILE__, __LINE__, strerror(errno));}}while(0)

/* System error: fatal if HAK_SYSFATAL is defined; non-fatal oterwise. 
   HAK_SYSFATAL is true by default. */

#if (HAK_SYSFAULT_FATAL != HAK_FALSE) 
#define hak_sysfault(expression) hak_sysfault_fatal(expression)
#else
#define hak_sysfault(expression) hak_sysfault_nonfatal(expression)
#endif	/* HAK_SYSFATAL */



/* Values of hak_engine.errno */

typedef enum 
  {
    hah_error_none=EXIT_SUCCESS, /* Success.*/
    hak_error_null		 /* Argument NULL not valid. */
  } hak_error_t;

extern const char* hak_error_messages[];

#define _hak_set_error(error_code) do{hak_engine.error = error_code;}while(0)

/* Log symbols */

typedef enum 
  {
    hak_symbol_log=0,	
    hak_symbol_sysfault,
    hak_symbol_assert,
    hak_symbol_debug
  } hak_symbol_t;

extern const char* hak_symbols[]; 

/* 
  Libhak assert: check for conditions prone to cause either runtime faults
  or incorrect results.  These may include calling a function with invalid 
  parameters (e.g. passing NULL to strdup), freeing a non-allocated memory 
  block (e.g. if using hak_malloc), and so on.

  If 'expression' is true, report a standard error message and either return
  with a predefined value, or exit with EXIT_FAILURE.

 */


/* Libhak fatal. */
#define hak_fatal_assert(expression, error_code) do{if (expression) {_hak_set_error(error_code); fprintf (stderr, "%s%s: %s: %d: %s\n", hak_symbol_string(assert), hak_engine.program_name, __FILE__, __LINE__, hak_error_messages[hak_engine.error]); exit (EXIT_FAILURE);}}while(0)

/* Libhak non-fatal. */
#define hak_nonfatal_assert(expression, error_code, return_value) do{ if (expression) {_hak_set_error(error_code); fprintf (stderr, "%s%s: %s: %d: %s\n", hak_symbol_string(assert), hak_engine.program_name, __FILE__, __LINE__, hak_error_messages[hak_engine.error]); return return_value;}}while(0)

/* Libhak error: fatal if HAK_FATAL is defined; non-fatal oterwise. 
   HAK_FATAL is true by default. */
#if (HAK_ASSERT_FATAL != HAK_FALSE) 
#define hak_assert(expression, error, value) hak_fatal_assert(expression, error)
#else
#define hak_assert(expression, error, value) hak_nonfatal_assert(expression, error, value)
#endif	/* HAK_ASSERT_FATAL */

/* 
 * Hak debug
 */

/* Libhak fatal. */
#define hak_debug_fatal(expression, error_message) do{if (expression) {fprintf (stderr, "%s%s: %s: %d: %s %s\n", hak_symbol_string(debug), hak_engine.program_name, __FILE__, __LINE__, #expression, error_message ? error_message : ""); exit (EXIT_FAILURE);}}while(0)

/* Libhak non-fatal. */
#define hak_debug_nonfatal(expression, error_message) do{ if (expression) {fprintf (stderr, "%s%s: %s: %d: %s %s\n", hak_symbol_string(debug), hak_engine.program_name, __FILE__, __LINE__, #expression, error_message ? error_message : "");}}while(0)

/* Libhak error: fatal if HAK_FATAL is defined; nonfatal oterwise.
   HAK_FATAL is true by default. */
#if (HAK_DEBUG_FATAL != HAK_FALSE)
#define hak_debug(expression, message) hak_debug_fatal(expression, message)
#else
#define hak_debug(expression, message) hak_debug_nonfatal(expression, message)
#endif	/* HAK_FATAL */

#if (HAK_DEBUG == HAK_FALSE)
#undef hak_debug_fatal
#undef hak_debug_nonfatal
#undef hak_debug
#define hak_debug_fatal(expression, errror) while(0)
#define hak_debug_nonfatal(expression, errror) while(0)
#define hak_debug(expression, errror) while(0)
#endif


/* Libhak log: general log messages (variable arguments) */
int hak_log (const char *, ...);

const char *hak_replaced;

#endif /* _HAK_MESSAGES_H */
