/*  hak_core.c - 
    
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

#include <config.h>
#include <libhak.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Global variables. */

hak_engine_t hak_engine;


/* 
   Public API.
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

  hak_engine.argv = (char *) malloc(argc *sizeof (char *));
  for (i=0; i<argc; i++)
    hak_engine.argv[i] = strdup (argv[i]);

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
  hak_engine.program_name= strdup (last_token);


}
