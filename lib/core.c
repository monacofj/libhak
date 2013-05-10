/*  hak_core.c - Core libhak engine.
    
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <config.h>
#include <libhak.h>

/* 
 *  Global variables. 
 */

hak_engine_t hak_engine;


/* 
 *  Public API.
 */


/* Exhibit core information about libhak.*/

void hak_info(void)
{
  printf ("%s\n", PACKAGE_STRING);
}

/* Initialize libhak engine.  */

int hak_initialize (int argc, char **argv)
{
  char *last_token, *current_token;
  int i;

  /* Command line arguments */

  hak_engine.argc = argc;

  hak_engine.argv = (char **) hak_malloc(argc * sizeof (char *));

  for (i=0; i<argc; i++)
    hak_engine.argv[i] = hak_strdup (argv[i]);

  /* Determine program invocation name (without path) */

  current_token = hak_engine.argv[0];
  last_token = current_token;
  while (*current_token != '\0')
    {
      if (*current_token == '/')
	last_token = current_token;
      current_token++;
    }
  last_token++;
  hak_engine.program_name= hak_strdup (last_token);

  /* Log symbol. */

  hak_engine.symbol_log = (char*) hak_symbols[hak_symbol_log];
  hak_engine.symbol_sysfault = (char *) hak_symbols[hak_symbol_sysfault];
  hak_engine.symbol_verify = (char *) hak_symbols[hak_symbol_verify];
  hak_engine.symbol_assert = (char *) hak_symbols[hak_symbol_assert];
  

  /* Default log stream; */

  hak_engine.logstream = stderr; /* Standard error. */

  return EXIT_SUCCESS;
}



const char *hak_replaced = HAK_REPLACED;

/* 
 * Non-public functions and variables.
 */



