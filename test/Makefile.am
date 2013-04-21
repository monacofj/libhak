AM_CFLAGS = -Wall -ansi --pedantic
AM_CPPFLAGS = -Wall -ansi --pedantic -I$(srcdir)/../lib

noinst_PROGRAMS = test-core

test_core_SOURCES = test-core.c
test_core_LDADD = ../lib/libhak.la

.PHONY clean-garbage:
	rm -rf $(CUSTOM_GARBAGE)
