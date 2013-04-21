# libhack.la

# Reminder:
# versioning: CURRENT:REVISION:AGE
#CURRENT The latest interface implemented.
#REVISION The implementation number of CURRENT (read: number of bugs fixed...)
#AGE The number of interfaces implemented, minus one.
#The library supports all interfaces between CURRENT − AGEand CURRENT.
#
#If you have 
#not changed the interface (bug fixes)		CURRENT : REVISION+1 : AGE
#augmented the interface (new functions)	CURRENT+1 : 0 : AGE+1
#broken old interface (e.g. removed functions) 	CURRENT+1 : 0 : 0



AM_CFLAGS = -Wall -std=c99 --pedantic
AM_CPPFLAGS = -Wall -std=c99 --pedantic
lib_LTLIBRARIES = libhak.la
libhak_la_SOURCES = hak_core.c  
libhak_la_LDFLAGS = -version-info 0:0:0
include_HEADERS = libhak.h 

.PHONY clean-garbage:
	rm -rf $(CUSTOM_GARBAGE)
