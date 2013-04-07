SUBDIRS = lib src test doc
ACLOCAL_AMFLAGS = -I m4

export CUSTOM_GARBAGE = *~ \#* *.o
.PHONY clean-garbage:
	make -C src  clean-garbage
	make -C test clean-garbage
	make -C lib  clean-garbage
	make -C doc  clean-garbage
