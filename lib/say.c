
/** @file: say.c
 */

#include <config.h>
#include <stdio.h>

/** @brief: just a greeings mesage */

void say_hello (void)
{
  puts ("Hello World!");
  puts ("This is " PACKAGE_STRING ".");
}
