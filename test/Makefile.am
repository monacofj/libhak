#  Makefile.am - For ad hoc tests
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

# Compiler flags

AM_CFLAGS =  @HAK_CFLAGS@
AM_CPPFLAGS = @HAK_CPPFLAGS@ -I$(srcdir)/../lib


# Don't install test programs
noinst_PROGRAMS = test-core test-sysfun

# Test sources (for now, ad hoc tests)

test_core_SOURCES = test-core.c

test_sysfun_SOURCES = test-sysfun.c

# Unless otherwise specified, all tests are linked to these

LDADD = ../lib/libhak.la 

# Clean custom garbage

.PHONY clean-garbage:
	rm -rf $(CUSTOM_GARBAGE)

