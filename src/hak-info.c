/** @file: hak-info.c
    @description: LibHack Info
    @author: Monaco F. J.
 */

/** @brief: Libhack information */

#include <stdio.h>
#include <config.h>

int main (void)
{
  printf ("%s\n", PACKAGE_STRING);
  return 0;
}
