# libhak/*.h

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


AM_CFLAGS =  @HAK_CFLAGS@ 
AM_CPPFLAGS = @HAK_CPPFLAGS@ 

nobase_include_HEADERS = libhak/sysfun.h 

.PHONY clean-garbage:
	rm -rf $(CUSTOM_GARBAGE)
