AC_INIT([libhak], [0.1], [monaco.fj@gmail.com])
AC_PREREQ([2.65])			 dnl Required autoconf version
AC_CONFIG_AUX_DIR([build-aux])		 dnl Where to write auxiliary files
AC_CONFIG_MACRO_DIR([m4])		 dnl m4 files here
AM_INIT_AUTOMAKE([-Wall -Werror 1.11.1]) dnl Warnings as errors and version
AC_CONFIG_HEADERS([config.h])		 dnl Generate config.h
LT_INIT					 dnl Add libtool support to 'configure'




AC_LANG_C				 dnl Use C compilation tests for C 
AC_PROG_CC				 dnl Defines CC (gcc if available)

dnl Ensure we have a suitable C compiler 
dnl (Seems to add --std=gnu99, and we don't want it.)
dnl
dnl AC_PROG_CC_C99				 dnl Ensure CC supports C99
dnl if test "x$ac_cv_prog_cc_c99" = xno; then
dnl     AC_MSG_ERROR([Your compiler lacks sufficient C99 support])
dnl fi


dnl Ensure POSIX threads
dnl (Disabled while we don't need it.)
dnl
dnl AX_PTHREAD(,AC_MSG_ERROR([POSIX threads support is required]))
dnl LIBS="$PTHREAD_LIBS $LIBS"
dnl CFLAGS="$CFLAGS $PTHREAD_CFLAGS"
dnl CC="$PTHREAD_CC"


dnl Stick to ANSI + Posix

HAK_STANDARD_FLAGS="--ansi -D_POSIX_SOURCE"
CPPFLAGS="$CPPFLAGS $HAK_STANDARD_FLAGS"
AC_SUBST([HAK_STANDARD_FLAGS])


dnl Function replacements
AC_CHECK_DECLS([strdup],, HAK_ALTFUNC="$HAK_ALTFUNC -include replace/foo.h")
AC_SUBST([HAK_ALTFUNC])


AC_HEADER_STDC

dnl Check for doxygen

AC_CHECK_PROGS([DOXYGEN], [doxygen])
if test -z "$DOXYGEN";
   then AC_MSG_WARN([Doxygen not found - continuing without Doxygen support])
fi
AM_CONDITIONAL([HAVE_DOXYGEN], 
[test -n "$DOXYGEN"])AM_COND_IF([HAVE_DOXYGEN], [AC_CONFIG_FILES([doc/Doxyfile])])

dnl Substitutions

dnl AC_CONFIG_LIBOBJ_DIR([replace])
dnl AC_REPLACE_FUNCS(foo)

# TODO: Temporality removed doc/Makefile
AC_CONFIG_FILES([Makefile lib/Makefile test/Makefile src/Makefile ])
AC_OUTPUT
