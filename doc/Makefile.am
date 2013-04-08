
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

all-local: doxyfile.stamp 


.PHONY clean-garbage:
	rm -rf $(CUSTOM_GARBAGE)


clean-local:
	rm -rf $(top_srcdir)/doc/latex
	rm -rf $(top_srcdir)/doc/man
endif
