## * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
## * This source file is part of SableVM.                            *
## *                                                                 *
## * See the file "LICENSE" for the copyright information and for    *
## * the terms and conditions for copying, distribution and          *
## * modification of this source file.                               *
## * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

bin_PROGRAMS = sablevm

sablevm_LDADD = ../libsablevm/libsablevm.la $(SVMADD)

sablevm_SOURCES = \
	sablevm.c sablevm.h

SVMCOMPILETIME = \
	$(shell date -u '+%Y-%m-%d %H:%M:%S %Z')

INCLUDES = $(SVMINCLUDE) \
	-I@top_srcdir@/src/libsablevm/include \
	-DPKGDATADIR=\"@datadir@/@PACKAGE@\" \
	-DSYSCONFDIR=\"@sysconfdir@\" \
	"-DSVMCOMPILETIME=\"$(SVMCOMPILETIME)\""
