/*  hak-info.c - Outputs basic libhak information.
    
    Copyright 2013  Monaco   <monaco.fj@gmail.com>

    This file is part of Foo. 

    Foo is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foo is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with .  If not, see <http://www.gnu.org/licenses/>. 

*/

/** @file: hak-info.c
    @description: LibHack Info
    @author: Monaco F. J.
 */

/** @brief: Libhack information */

#include <stdio.h>
#include <stdlib.h>
#include <config.h>
#include <libhak.h>

int main (int argc, char **argv)
{

  hak_initialize (argc, argv);
  hak_info ();

  printf ("Program name: %s\n", hak_engine.program_name);

  printf ("Replaced functions: %s\n", hak_replaced);

  return EXIT_SUCCESS;
}
