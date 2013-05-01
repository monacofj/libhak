
AM_CFLAGS =  @HAK_CFLAGS@
AM_CPPFLAGS = @HAK_CPPFLAGS@ -I$(srcdir)/../lib


bin_PROGRAMS = hak-info

hak_info_SOURCES = hak-info.c
hak_info_LDADD = ../lib/libhak.la

.PHONY clean-garbage:
	rm -rf $(CUSTOM_GARBAGE)
