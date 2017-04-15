## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign subdir-objects

SUBDIRS = include testsuite

EXTRA_DIST = LICENSE ChangeLog.v1 configure.host libtool-version \
	src/alpha/ffi.c src/alpha/osf.S src/alpha/ffitarget.h \
	src/arm/ffi.c src/arm/sysv.S src/arm/ffitarget.h \
	src/mips/ffi.c src/mips/n32.S src/mips/o32.S \
	src/mips/ffitarget.h \
	src/m32r/ffi.c src/m32r/sysv.S src/m32r/ffitarget.h \
	src/m68k/ffi.c src/m68k/sysv.S src/m68k/ffitarget.h \
	src/powerpc/ffi.c src/powerpc/sysv.S \
	src/powerpc/linux64.S src/powerpc/linux64_closure.S \
	src/powerpc/ppc_closure.S src/powerpc/asm.h \
	src/powerpc/aix.S src/powerpc/darwin.S \
	src/powerpc/aix_closure.S src/powerpc/darwin_closure.S \
	src/powerpc/ffi_darwin.c src/powerpc/ffitarget.h \
	src/s390/ffi.c src/s390/sysv.S src/s390/ffitarget.h \
	src/sh/ffi.c src/sh/sysv.S src/sh/ffitarget.h \
	src/sh64/ffi.c src/sh64/sysv.S src/sh64/ffitarget.h \
	src/sparc/v8.S src/sparc/v9.S src/sparc/ffitarget.h \
	src/sparc/ffi.c \
	src/x86/ffi.c src/x86/sysv.S src/x86/win32.S \
	src/x86/ffi64.c src/x86/unix64.S src/x86/ffitarget.h \
	src/pa/ffi.c src/pa/linux.S src/frv/eabi.S src/frv/ffitarget.h \
	src/ia64/ffitarget.h src/ia64/unix.S src/ia64/ffi.c \
	src/ia64/ia64_flags.h

## ################################################################

##
## This section is for make and multilib madness.
##


MAKEOVERRIDES=

if CONV_ONLY_LIBFFI
noinst_LTLIBRARIES = libffi_convenience.la
else
lib_LTLIBRARIES = libffi.la
noinst_LTLIBRARIES = libffi_convenience.la
endif

libffi_la_SOURCES = src/debug.c src/prep_cif.c src/types.c \
		src/raw_api.c src/java_raw_api.c

nodist_libffi_la_SOURCES =

if MIPS_IRIX
nodist_libffi_la_SOURCES += src/mips/ffi.c src/mips/o32.S src/mips/n32.S
endif
if MIPS_LINUX
nodist_libffi_la_SOURCES += src/mips/ffi.c src/mips/o32.S
endif
if X86
nodist_libffi_la_SOURCES += src/x86/ffi.c src/x86/sysv.S
endif
if X86_WIN32
nodist_libffi_la_SOURCES += src/x86/ffi.c src/x86/win32.S
endif
if SPARC
nodist_libffi_la_SOURCES += src/sparc/ffi.c src/sparc/v8.S src/sparc/v9.S
endif
if ALPHA
nodist_libffi_la_SOURCES += src/alpha/ffi.c src/alpha/osf.S
endif
if IA64
nodist_libffi_la_SOURCES += src/ia64/ffi.c src/ia64/unix.S
endif
if M32R
nodist_libffi_la_SOURCES += src/m32r/sysv.S src/m32r/ffi.c
endif
if M68K
nodist_libffi_la_SOURCES += src/m68k/ffi.c src/m68k/sysv.S
endif
if POWERPC
nodist_libffi_la_SOURCES += src/powerpc/ffi.c src/powerpc/sysv.S src/powerpc/ppc_closure.S src/powerpc/linux64.S src/powerpc/linux64_closure.S
endif
if POWERPC_AIX
nodist_libffi_la_SOURCES += src/powerpc/ffi_darwin.c src/powerpc/aix.S src/powerpc/aix_closure.S
endif
if POWERPC_DARWIN
nodist_libffi_la_SOURCES += src/powerpc/ffi_darwin.c src/powerpc/darwin.S src/powerpc/darwin_closure.S
endif
if ARM
nodist_libffi_la_SOURCES += src/arm/sysv.S src/arm/ffi.c
endif
if FRV
nodist_libffi_la_SOURCES += src/frv/eabi.S src/frv/ffi.c
endif
if S390
nodist_libffi_la_SOURCES += src/s390/sysv.S src/s390/ffi.c
endif
if X86_64
nodist_libffi_la_SOURCES += src/x86/ffi64.c src/x86/unix64.S src/x86/ffi.c src/x86/sysv.S
endif
if SH
nodist_libffi_la_SOURCES += src/sh/sysv.S src/sh/ffi.c
endif
if SH64
nodist_libffi_la_SOURCES += src/sh64/sysv.S src/sh64/ffi.c
endif
if PA
nodist_libffi_la_SOURCES += src/pa/linux.S src/pa/ffi.c
endif

libffi_convenience_la_SOURCES = $(libffi_la_SOURCES)
nodist_libffi_convenience_la_SOURCES = $(nodist_libffi_la_SOURCES)

AM_CFLAGS = -Wall -g -fexceptions

libffi_la_LDFLAGS = -version-info `grep -v '^\#' $(srcdir)/libtool-version` @NO_UNDEFINED@

AM_CPPFLAGS = -I. -I$(top_srcdir)/include -Iinclude -I$(top_srcdir)/src
AM_CCASFLAGS = $(AM_CPPFLAGS)

svnclean:
	svn st --no-ignore | grep ^I | cut -c8- | awk '{print "\"" $$0 "\""}'| xargs rm -rf
