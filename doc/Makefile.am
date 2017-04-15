## * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
## * This source file is part of SableVM.                            *
## *                                                                 *
## * See the file "LICENSE" for the copyright information and for    *
## * the terms and conditions for copying, distribution and          *
## * modification of this source file.                               *
## * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

man_MANS = sablevm.1 java-sablevm.1

EXTRA_DIST = \
	README \
	debugging.txt \
	gc_hashcode.txt \
	general.txt \
	inlinability_testing.txt \
	java-sablevm.1 \
	m4macros.txt \
	posix-cas.txt \
	sablevm.1 \
	signals_handling.txt \
	stack_layout.txt

noinst_DATA = test-gnu-make

test-gnu-make: README
	$(shell if test ! -f "$^" ; then \
		echo "ERROR: *** Your 'make' command does NOT seem to be GNU Make. ***"; \
		echo "The build system of SableVM requires GNU Make.  On many systems GNU Make"; \
		echo "is installed as 'gmake'."; \
		exit 1; \
		fi)
