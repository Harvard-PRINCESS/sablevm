# Makefile for popt library.

AUTOMAKE_OPTIONS = 1.4 foreign

EXTRA_DIST = autogen.sh CHANGES popt.spec \
	testit.sh test-poptrc popt.3

INCLUDES = -I. -I$(top_srcdir)

noinst_HEADERS = findme.h poptint.h system.h

noinst_PROGRAMS = test1 test2 test3
test1_SOURCES = test1.c
#test1_LDFLAGS = -all-static
test1_LDADD = $(noinst_LTLIBRARIES)
test2_SOURCES = test2.c
#test2_LDFLAGS = -all-static
test2_LDADD = $(noinst_LTLIBRARIES)
test3_SOURCES = test3.c
#test3_LDFLAGS = -all-static
test3_LDADD = $(noinst_LTLIBRARIES)

noinst_SCRIPTS = testit.sh

TESTS_ENVIRONMENT = \
test1="./test1"

# tests break, even when compiling the upstream version (!)
# TESTS = testit.sh

if CONV_ONLY_LIBPOPT
noinst_LTLIBRARIES = libpopt_convenience.la
noinst_HEADERS += popt.h
else
include_HEADERS = popt.h
noinst_LTLIBRARIES = libpopt_convenience.la
lib_LTLIBRARIES = libpopt.la
man_MANS = popt.3
libpopt_la_SOURCES = $(libpopt_convenience_la_SOURCES)
endif

libpopt_convenience_la_SOURCES = popt.c findme.c poptparse.c poptconfig.c popthelp.c

popt.lcd: Makefile.am ${libpopt_la_SOURCES} ${include_HEADERS} ${noinst_HEADERS}
	lclint -dump $@ ${libpopt_la_SOURCES}

.PHONY:	sources
sources:
	@echo $(libpopt_la_SOURCES:%=popt/%)

.PHONY: lclint
lclint:
	lclint ${DEFS} ${INCLUDES} test1.c ${libpopt_la_SOURCES}

CVSTAG = $(PACKAGE)-$(subst .,_,$(VERSION))

.PHONY: archive
archive: 
	@echo "This is $(PACKAGE)-$(VERSION)."
	@sleep 5
	@cvs -Q tag -F $(CVSTAG) .
	@rm -rf /tmp/$(PACKAGE)-$(VERSION) /tmp/$(PACKAGE)
	@cd /tmp; cvs -Q -d $(CVSROOT) export -r$(CVSTAG) $(PACKAGE) || :
	@mv /tmp/$(PACKAGE) /tmp/$(PACKAGE)-$(VERSION)
	@cd /tmp/$(PACKAGE)-$(VERSION); ./autogen.sh ; make depend; make distclean
	@cd /tmp/$(PACKAGE)-$(VERSION); ./autogen.sh --noconfigure
	@cd /tmp; tar czSpf $(PACKAGE)-$(VERSION).tar.gz $(PACKAGE)-$(VERSION)
	@rm -rf /tmp/$(PACKAGE)-$(VERSION)
	@cp /tmp/$(PACKAGE)-$(VERSION).tar.gz .
	@rm -f /tmp/$(PACKAGE)-$(VERSION).tar.gz 
	@echo " "
	@echo "The final archive is ./$(PACKAGE)-$(VERSION).tar.gz."

.PHONY: doxygen
doxygen: Doxyfile
	rm -rf doxygen
	mkdir -p doxygen
	doxygen

svnclean:
	svn st --no-ignore | grep ^I | cut -c8- | awk '{print "\"" $$0 "\""}'| xargs rm -rf
