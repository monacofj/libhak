#  Makefile.am - For libhak documentation
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

# Do it all only if doxygen is installed.

if HAVE_DOXYGEN		

# Original files.
#
# directory = $(top_srcdir)/doc/man/man3/
# dist_man_MANS = $(directory)/man_page_1.3 $(directory)/man_page_2.3
# $(directory)/man_page_1.3: doxyfile.stamp
# $(directory)/man_page_2.3: doxyfile.stamp

# Uncommend the following 4 lines for PDF
#
# TODO: make distcheck is failing. 
#
PDF_DIR = $(top_srcdir)/doc/latex
BUILD_PDF = make -C $(PDF_DIR)
dist_doc_DATA = $(PDF_DIR)/refman.pdf
$(PDF_DIR)/refman.pdf : doxyfile.stamp 


# This is the rule to build the documentation source file from the source code.
#
# Doxygen will produce a lot of documentation source files. Which one do we 
# check to verify if it is newer than the source code? We can rely on an
# artifice here: doxyfile.stamp is the one file representing the whole of the
# documentation source files.


doxyfile.stamp: Doxyfile.in 
	$(DOXYGEN) Doxyfile
	$(BUILD_PDF)
	echo Timestamp > doxyfile.stamp


CLEANFILES = doxyfile.stamp

install-data-local: doxyfile.stamp 


.PHONY clean-garbage:
	rm -rf $(CUSTOM_GARBAGE)

clean-local:
	rm -rf $(top_srcdir)/doc/latex
	rm -rf $(top_srcdir)/doc/man


endif
