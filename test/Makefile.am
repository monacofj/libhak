AM_CFLAGS = -Wall -ansi --pedantic
AM_CPPFLAGS = -Wall -ansi --pedantic -I$(srcdir)/../lib
noinst_PROGRAMS = hak-test-core

hak_test_core_SOURCES = hak-test-core.c
hak_test_core_LDADD = ../lib/libhak.la

.PHONY clean-garbage:
	rm -rf $(CUSTOM_GARBAGE)
