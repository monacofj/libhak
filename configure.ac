dnl  configure.ac - Libhak autoconf file.
dnl    
dnl    Copyright 2013  Francisco Jose Monaco   <monaco.fj@gmail.com>
dnl
dnl    This file is part of Foo. 
dnl
dnl    Foo is free software: you can redistribute it and/or modify
dnl    it under the terms of the GNU General Public License as published by
dnl    the Free Software Foundation, either version 3 of the License, or
dnl    (at your option) any later version.
dnl
dnl    Foo is distributed in the hope that it will be useful,
dnl    but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl    GNU General Public License for more details.
dnl
dnl    You should have received a copy of the GNU General Public License
dnl    along with .  If not, see <http://www.gnu.org/licenses/>.
dnl

AC_INIT([libhak], [0.1], [monaco.fj@gmail.com])
AC_PREREQ([2.65])			 dnl Required autoconf version
AC_CONFIG_AUX_DIR([build-aux])		 dnl Where to write auxiliary files
AC_CONFIG_MACRO_DIR([m4])		 dnl m4 files here
AM_INIT_AUTOMAKE([-Wall -Werror 1.11.1 subdir-objects]) dnl Warnings as errors and version
AC_CONFIG_HEADERS([config.h])		 dnl Generate config.h
LT_INIT					 dnl Add libtool support to 'configure'



AC_LANG_C				 dnl Use C compilation tests for C 
AC_PROG_CC				 dnl Defines CC 
if test "$GCC" != "xyes"; then
   AC_MSG_WARN([CC not $CC: you may need to manually ajust compiler options.])
fi



dnl Ensure POSIX threads
dnl (Disabled while we don't need it.)
dnl
dnl AX_PTHREAD(,AC_MSG_ERROR([POSIX threads support is required]))
dnl LIBS="$PTHREAD_LIBS $LIBS"
dnl CFLAGS="$CFLAGS $PTHREAD_CFLAGS"
dnl CC="$PTHREAD_CC"


dnl Stick to Ansi-C89/ISO-C90 + Posix

HAK_CPPFLAGS="-std=c89 -D_POSIX_SOURCE -Wall -Werror --pedantic-errors"
HAK_CFLAGS="-std=c89 -D_POSIX_SOURCE -Wall -Werror --pedantic-errors" 

CPPFLAGS="$HAK_CPPFLAGS $CPPFLAGS"
CFLAGS="$HAK_CFLAGS $CFLAGS"
AC_SUBST([HAK_CPPFLAGS])
AC_SUBST([HAK_CFLAGS])		    

dnl Function replacements for ANSI+Posix compliance.
dnl Ad hoc way (we might use Gnulib instead)

AC_CONFIG_LIBOBJ_DIR([replace])
AC_CHECK_DECLS([strdup],[],[AC_LIBOBJ(strdup)])

HAK_REPLACE=${LIBOBJS/.o/}
AC_SUBST([HAK_REPLACE])

dnl Check for doxygen

AC_CHECK_PROGS([DOXYGEN], [doxygen])
if test -z "$DOXYGEN";
   then AC_MSG_WARN([Doxygen not found - continuing without Doxygen support])
fi
AM_CONDITIONAL([HAVE_DOXYGEN], 
[test -n "$DOXYGEN"])AM_COND_IF([HAVE_DOXYGEN], [AC_CONFIG_FILES([doc/Doxyfile])])


dnl TODO: Temporality removed doc/Makefile
AC_CONFIG_FILES([Makefile lib/Makefile test/Makefile src/Makefile ])
AC_OUTPUT
