## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS=foreign

DISTCLEANFILES=ffitarget.h
EXTRA_DIST=ffi.h.in ffi_common.h

if CONV_ONLY_LIBFFI
noinst_HEADERS = ffitarget.h ffi.h
else
include_HEADERS = ffitarget.h ffi.h
endif
