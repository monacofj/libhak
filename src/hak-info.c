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

  return EXIT_SUCCESS;
}
