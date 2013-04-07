AC_INIT([libhak], [0.1], [monaco.fj@gmail.com])
AC_PREREQ([2.65])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([-Wall -Werror 1.11.1])
LT_INIT
AC_PROG_CC


AC_CONFIG_HEADERS([config.h])

dnl Check for doxygen

AC_CHECK_PROGS([DOXYGEN], [doxygen])
if test -z "$DOXYGEN";
   then AC_MSG_WARN([Doxygen not found - continuing without Doxygen support])
fi
AM_CONDITIONAL([HAVE_DOXYGEN], 
[test -n "$DOXYGEN"])AM_COND_IF([HAVE_DOXYGEN], [AC_CONFIG_FILES([doc/Doxyfile])])

# Test


AC_CONFIG_FILES([ Makefile lib/Makefile test/Makefile src/Makefile doc/Makefile])
AC_OUTPUT
