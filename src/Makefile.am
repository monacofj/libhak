AM_CFLAGS = -Wall -ansi --pedantic
AM_CPPFLAGS = -Wall -ansi --pedantic -I$(srcdir)/../lib
bin_PROGRAMS = hak-info
hak_info_SOURCES = hak-info.c
hak_info_LDADD = ../lib/libhak.la

.PHONY clean-garbage:
	rm -rf $(CUSTOM_GARBAGE)
