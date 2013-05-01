

# We want libhak to work with ansi-compliant C code.
AM_CFLAGS = -Wall  --pedantic
AM_CPPFLAGS = -Wall  --pedantic -I$(srcdir)/../lib

noinst_PROGRAMS = test-core test-sysfun

test_core_SOURCES = test-core.c
test_core_LDADD = ../lib/libhak.la

test_sysfun_SOURCES = test-sysfun.c
test_sysfun_LDADD = ../lib/libhak.la @LIBOBJS@


.PHONY clean-garbage:
	rm -rf $(CUSTOM_GARBAGE)

