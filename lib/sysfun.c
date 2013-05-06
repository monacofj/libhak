/*  sysfun.c - Handy wrappers for common libc functions.
    
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

#include <libhak.h>
#include <libhak/sysfun.h>

#include <config.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/* LIBHAK CONVENTIONS FOR SYSTEM FUNCTIONS

   Wrapper functions shall have the same interface than the corresponding
   standard functions, and also shall behave the same on success, producing
   the same result.

   All standard library calls shall be checked with hak_syserror, marco
   and the behaviour will be determined by action taken by it.

   If there are invalid parameters prone to cause standard library failure,
   it is strongly encouraged that those be checked with hak_error macro, 
   and the behaviour will be determined by the action taken by it.

 */

#include <libhak.h>

/* On sucess, works like malloc. */

void *hak_malloc(size_t size)
{
  void *block;
  block = malloc (size);
  hak_sysfault (!block);
  return block;
}


/*  */

char * hak_strdup (const char *string)
{
  char *new_string;

  /* hak_assert (!string, hak_error_null, NULL); /\* Assert if string is non NULL. *\/ */

  new_string = strdup (string);
  hak_sysfault (!new_string);

  return new_string;
}


