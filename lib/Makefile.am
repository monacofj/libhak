#  Makefile.am - For libhak utility programs
#    
#    Copyright 2013  Francisco Jose Monaco   <monaco.fj@gmail.com>
#
#    This file is part of Foo. 
#
#    Foo is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    Foo is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with .  If not, see <http://www.gnu.org/licenses/>.
#


# Reminder for libhak.la versioning
#
# Versioning: CURRENT:REVISION:AGE
# CURRENT The latest interface implemented.
# REVISION The implementation number of CURRENT (read: number of bugs fixed...)
# AGE The number of interfaces implemented, minus one.
# The library supports all interfaces between CURRENT − AGE and CURRENT.
#
# If you have 
# not changed the interface (bug fixes)		CURRENT : REVISION+1 : AGE
# augmented the interface (new functions)	CURRENT+1 : 0 : AGE+1
# broken old interface (e.g. removed functions) CURRENT+1 : 0 : 0


HAK_VERSIONING=0:0:0

# Compiler flags

AM_CFLAGS =  @HAK_CFLAGS@ -DHAK_REPLACED="\"@HAK_REPLACE@\""
AM_CPPFLAGS = @HAK_CPPFLAGS@ -include ${top_srcdir}/replace/replace.h

# The libhak library.

lib_LTLIBRARIES = libhak.la				# Target
libhak_la_SOURCES = core.c  sysfun.c messages.c		# Sources
libhak_la_LDFLAGS = -version-info $(HAK_VERSIONING) 	# Linker flags
libhak_la_LIBADD = @LIBOBJS@				# Replacement functions

# The lihak headers.

nobase_include_HEADERS = libhak.h libhak/sysfun.h


# Clean custom garbage

.PHONY clean-garbage:
	rm -rf $(CUSTOM_GARBAGE)
