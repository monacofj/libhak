/*  strdup.c - Provision of strdup for C99+Posix compliance
    
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
#include <stdlib.h>
#include <string.h>

#define STRDUP_STRING "Ad hoc strdup"
char *strdup (const char *string)
{
  char *new;
  new = malloc (sizeof (STRDUP_STRING)+1);
  memcpy (new, STRDUP_STRING, sizeof (STRDUP_STRING));
  return new;
}
