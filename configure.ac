dnl * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
dnl * This source file is part of SableVM.                            *
dnl *                                                                 *
dnl * See the file "LICENSE" for the copyright information and for    *
dnl * the terms and conditions for copying, distribution and          *
dnl * modification of this source file.                               *
dnl * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

dnl *** IMPORTANT: Uncomment the apropriate line below. ***
dnl a) uncomment for official releases.  Please update version number.
AC_INIT([sablevm], [1.13], [http://sablevm.org/])
dnl b) uncomment for development on the trunk
dnl AC_INIT([sablevm], [trunk+]esyscmd([svn info | grep ^Revision: | awk '{print $2}' | head -n 1 | xargs echo -n]), [http://sablevm.org/])
dnl c) uncomment for development on branches.  Please update branch name.
dnl AC_INIT([sablevm], [branchname+]esyscmd([svn info | grep ^Revision: | awk '{print $2}' | head -n 1 | xargs echo -n]), [http://sablevm.org/])
dnl The following code makes sure that a branch version has been
dnl selected above, when developing on a branch in a subversion working
dnl copy.
dnl
dnl If one of the svn, grep or cut command is missing, the script assumes
dnl that the version is OK.
if test -d .svn ; then
  SVN_URL=`svn info | grep ^URL\: | cut -c6- | grep -v '/sablevm/trunk$' | grep -v '/tags/'`
  if test "x$SVN_URL" != "x" ; then
    case $PACKAGE_VERSION in
      trunk+*) echo "$PACKAGE_VERSION is not an appropriate branch version"
               echo "Please uncomment appropatiate AC INIT macro in configure.ac"
               exit 1 ;;
      *+*)     ;;
      *)       echo "$PACKAGE_VERSION is not an appropriate branch version"
               echo "Please uncomment appropatiate AC INIT macro in configure.ac"
               exit 1 ;;
    esac
  fi
fi

AC_CONFIG_AUX_DIR([.])

AM_INIT_AUTOMAKE

AM_CONFIG_HEADER(src/include/config.h)
AC_CONFIG_SRCDIR([src/sablevm/sablevm.c])

AC_SUBST(LIBRELEASE, ["]AC_PACKAGE_VERSION["])
AC_SUBST(RELEASE, AC_PACKAGE_VERSION)

AC_DEFINE_UNQUOTED(_SABLEVM_PACKAGE_NAME, "AC_PACKAGE_TARNAME", package name)
AC_DEFINE_UNQUOTED(_SABLEVM_PACKAGE_VERSION, "AC_PACKAGE_VERSION", package version)

# TODO: will this parameter be useful?
#DISTCHECK_CONFIGURE_FLAGS = --with-internal-libffi

AC_DEFINE(_REENTRANT,1,link with reentrant library functions)
AC_DEFINE(_POSIX_C_SOURCE,199506L,link with POSIX library functions)

dnl should be defined on a finer grain.
AC_DEFINE(_XOPEN_SOURCE,500,link with XOpen library functions)

dnl *** uncomment to get verbose instructions with inlined engine ***
dnl AC_DEFINE(_SABLEVM_VERBOSE_INSTRUCTIONS_INLINED,1,Verbose instructions with inlined engine)

AC_DISABLE_STATIC
AC_CANONICAL_HOST

case $host in
	sparc-sun-solaris*) AC_DEFINE(_XPG4_2,1,add common BSD extensions) ;;
	*) ;;
esac

dnl magic
AC_ARG_ENABLE(magic,
	[  --enable-magic
			  put "SableVM" in every object instance header],,
	[enable_magic=no])

case "$enable_magic" in
        no)     ;;
	yes)    AC_DEFINE(MAGIC,1,put "SableVM" in every object instance header) ;;
	*)	AC_MSG_ERROR(bad value \"${enable_magic}\" for --enable-magic) ;;
esac

dnl statistics
AC_ARG_ENABLE(statistics,
	[  --enable-statistics
			  print statistics on VM exit],,
	[enable_statistics=no])

case "$enable_statistics" in
        no)     ;;
	yes)    AC_DEFINE(STATISTICS,1,print statistics on VM exit) ;;
	*)	AC_MSG_ERROR(bad value \"${enable_statistics}\" for --enable-statistics) ;;
esac

dnl "real life" brokenness options
AC_ARG_ENABLE(real-life-brokenness,
	[  --enable-real-life-brokenness
                          enable things we don't support well and/or we don't
			  want to support (because of their broken nature)],
	[real_life_brokenness=$enableval],
	[real_life_brokenness=yes])

case "$real_life_brokenness" in
	yes)	AC_DEFINE(_SABLEVM_REAL_LIFE_BROKENNESS,1,Enable things we don't support well or don't want to support) ;;
	no)	;;
	*)	AC_MSG_ERROR("bad value \"${real_life_brokenness}\"for --enable-real-life-brokenness") ;;
esac

dnl inlinability testing (special mode - not for normal usage)
AC_ARG_ENABLE(inlinability-testing,
	[  --enable-inlinability-testing
                          special mode to catch non-inlinable instructions],
	[enable_inlinability_testing=$enableval],
	[enable_inlinability_testing=no])

case "$enable_inlinability_testing" in
	yes)	AC_SUBST(inlinability_testing,"-Dm4svm_inlinability_testing_mode=1")
		AC_DEFINE(_SABLEVM_INLINABILITY_TESTING,1,turn on inlinability testing mode machinery)
		;;
	no)	AC_SUBST(inlinability_testing,"") ;;
	*)	AC_MSG_ERROR("bad value \"${enable_inlinability_testing}\"for --enable-inlinability-testing") ;;
esac

dnl debugging features
AC_ARG_ENABLE(debugging-features,
	[  --enable-debugging-features
                          add compiler and runtime checks],,
	[enable_debugging_features=no])

case "$enable_debugging_features" in
	no)	AC_DEFINE(NDEBUG,1,turn off runtime assertions) ;;
	yes)	;;
	*)	AC_MSG_ERROR("bad value \"${enable_debugging_features}\" for --enable-debugging-features") ;;
esac

dnl signals for exceptions
AC_ARG_ENABLE(signals-for-exceptions,
	[  --disable-signals-for-exceptions
                          do not use signals to detect some exceptions
                          (NullPointerException, ArithmeticException, etc.)],,
	[if test "$enable_debugging_features" = no; then
                case $host in
			alpha*-gnu)     enable_signals_for_exceptions=yes ;;
			arm*-gnu)	enable_signals_for_exceptions=yes ;;
			hppa*-gnu)	enable_signals_for_exceptions=no ;;
			i*86-*-gnu)	enable_signals_for_exceptions=yes ;;
			i386-*-freebsd*)enable_signals_for_exceptions=yes ;;
			ia64*)		enable_signals_for_exceptions=yes ;;
			m68k*-gnu)	enable_signals_for_exceptions=yes ;;
			powerpc-*-gnu)	enable_signals_for_exceptions=yes ;;
			powerpc-apple-darwin*)
					enable_signals_for_exceptions=no ;;
			sparc*-gnu)	enable_signals_for_exceptions=yes ;;
			s390*-gnu)	enable_signals_for_exceptions=yes ;;
                        *)              enable_signals_for_exceptions=no ;;
		esac
	else
		enable_signals_for_exceptions=no
	fi])

dnl garbage collection
AC_ARG_WITH(gc,
	[  --with-gc=TYPE          use given garbage collector (none,copying,gencopy)],,
	[with_gc=copying])

case "$with_gc" in
	none)		AC_DEFINE(_SABLEVM_NO_GC,1,no collector) ;;
	copying)	AC_DEFINE(_SABLEVM_COPY_GC,1,copying collector) ;;
        gencopy)        AC_DEFINE(_SABLEVM_GENCOPY_GC,1,generational copying collector) ;;
	*)		AC_MSG_ERROR(bad value \"${with_gc}\" for --with-gc) ;;
esac

dnl object layout
AC_ARG_WITH(obj-layout,
	[  --with-obj-layout=TYPE  use given object layout (bidirectional,traditional)],,
	[with_obj_layout=bidirectional])

case "$with_obj_layout" in
	traditional)	AC_DEFINE(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT,1,traditional object layout) ;;
	bidirectional)	AC_DEFINE(_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT,1,bidirectional object layout) ;;
	*)		AC_MSG_ERROR(bad value \"${with_obj_layout}\" for --with-obj-layout) ;;
esac

dnl threading flavor
AC_ARG_WITH(threading,
	[  --with-threading=TYPE   use given interpreter threading flavor
                          (inlined,direct,switch)],,
	[if test "$enable_debugging_features" = no; then
		case $host in
			alpha*-gnu)     with_threading=direct ;;
			arm*-gnu)	with_threading=direct ;;
			hppa*-gnu)	with_threading=direct ;;
			i*86-*-gnu)	with_threading=inlined ;;
			ia64*)		with_threading=direct ;;
			m68k*-gnu)	with_threading=inlined ;;
			powerpc-*)	with_threading=inlined ;;
			sparc*-gnu)	with_threading=inlined ;;
			s390*-gnu)	with_threading=direct ;;
			x86_64*-gnu)	with_threading=direct ;;
			*)		with_threading=direct ;;
		esac
	else
		with_threading=switch
	fi
	if test "$enable_inlinability_testing" = yes; then
		with_threading=inlined
	fi])

case "$with_threading" in
	switch)		AC_DEFINE(_SABLEVM_SWITCH_THREADED_INTERPRETER,1,switch threaded interpreter) ;;
	direct)		AC_DEFINE(_SABLEVM_DIRECT_THREADED_INTERPRETER,1,direct threaded interpreter) ;;
	inlined)	AC_DEFINE(_SABLEVM_INLINED_THREADED_INTERPRETER,1,inlined threaded interpreter) ;;
	*)		AC_MSG_ERROR(bad value \"${with_threading}\" for --with-threading) ;;
esac

dnl NO block reordering - disable (manually!) w/ gcc < 3.0, auto enable if inlined
AC_ARG_ENABLE(no-reorder-blocks,
	[  --disable-no-reorder-blocks
                          do not use -fno-reorder-blocks (useful with gcc 2.95)],
	[enable_no_reorder_blocks=$enableval],
	[if test "$with_threading" = inlined; then
		enable_no_reorder_blocks=yes
	fi])

dnl errors on warnings
AC_ARG_ENABLE(errors-on-warnings,
	[  --disable-errors-on-warnings
                          do not issue an error on warnings],,
	[case $PACKAGE_VERSION in
	      *+*) enable_errors_on_warnings=yes ;;
	      *) enable_errors_on_warnings=no ;;
	esac])

dnl profiling settings
AC_ARG_WITH(profiling,
	[  --with-profiling=TYPE          enable profiling (nostatic,gprof)],,
	[	with_profiling=no])

case "$with_profiling" in
	no)		AC_DEFINE(svm_static,static,[(do not) make internal functions static]) ;;
	yes|nostatic)	AC_DEFINE(svm_static,,[(do not) make internal functions static]) ;;
	gprof)		AC_DEFINE(svm_static,,[(do not) make internal functions static])
			CFLAGS="$CFLAGS -pg" ;;
	*)		AC_MSG_ERROR(bad value \"${with_profiling}\" for --with-profiling) ;;
esac

dnl which libffi to use
AC_ARG_WITH(internal-libffi,
	[  --with-internal-libffi        use built-in libffi(auto,yes,no)],,
	[dnl for Cygwin we prefer to use the internal libffi by default
	 case "$host" in
		*-*-mingw*|*-*-cygwin*) with_internal_libffi=yes ;;
	    *) with_internal_libffi=auto ;;
	 esac
	])

case "$with_internal_libffi" in
	yes|no|auto)	;;
	*)		AC_MSG_ERROR(bad value \"${with_internal_libffi}\" for --with-internal-libffi) ;;
esac

dnl which libpopt to use
AC_ARG_WITH(internal-libpopt,
	[  --with-internal-libpopt        use built-in libpopt(auto,yes,no)],,
	[	with_internal_libpopt=auto])

case "$with_internal_libpopt" in
	yes|no|auto)	;;
	*)		AC_MSG_ERROR(bad value \"${with_internal_libpopt}\" for --with-internal-libpopt) ;;
esac

dnl which jikes to use in javac-sablevm
AC_ARG_WITH(jikes,
	[  --with-jikes=/path/to/jikes	use specified jikes as javac],,
	[	with_jikes=jikes])
AC_MSG_CHECKING(for jikes)
case "$with_jikes" in
	yes|no|jikes)
	    AC_PATH_PROG(JIKES, "jikes")
            if test "X$JIKES" = "X"; then
		JIKES=jikes
            fi
	    ;;
	/*|*\$*_prefix*) AC_MSG_RESULT(Will use $JIKES.); JIKES=$with_jikes ;;
	*)  AC_MSG_ERROR(bad value \"${with_jikes}\" for --with-jikes) ;;
esac
AC_SUBST(JIKES, $JIKES)

dnl which fastjar to use in jar-sablevm
AC_ARG_WITH(fastjar,
	[  --with-fastjar=/path/to/fastjar use specified fastjar],,
	[	with_fastjar=fastjar])
AC_MSG_CHECKING(for fastjar)
case "$with_fastjar" in
	yes|no|fastjar)
	    AC_PATH_PROG(FASTJAR, "fastjar")
            if test "X$FASTJAR" = "X"; then
		FASTJAR=fastjar
            fi
	    ;;
	/*|*\$*_prefix*) AC_MSG_RESULT(Will use $FASTJAR.); FASTJAR=$with_fastjar ;;
	*)  AC_MSG_ERROR(bad value \"${with_fastjar}\" for --with-fastjar) ;;
esac
AC_SUBST(FASTJAR, $FASTJAR)

dnl Checks for programs.
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

AC_LIBTOOL_DLOPEN
AC_PROG_LIBTOOL

dnl Checks for libraries.
LIBSVMADD="-lm -lltdl -lz"
AC_CHECK_LIB(ltdl,lt_dlinit,echo -n,echo ***ERROR: libltdl is missing; exit 1)
AC_CHECK_LIB(m,fmod,echo -n,echo ***ERROR: libm is missing; exit 1)
AC_CHECK_LIB(z,inflate,echo -n,echo ***ERROR: zlib/libz is missing; exit 1)

dnl Check if -lrt is needed
case $host in
	*-sun-solaris*)
	    dnl we should call AC_CHECK_LIB here, but what symbol should we look up?
	    LIBSVMADD="$LIBSVMADD -lrt"
	    ;;
	*)  ;;
esac

dnl Check what is the right library for threads
case $host in
	*-freebsd*)
	    dnl No thread library to link
	    ;;
	*)
	    AC_CHECK_LIB(pthread,pthread_self,echo -n,echo ***ERROR: libpthread is missing; exit 1)
	    LIBSVMADD="$LIBSVMADD -lpthread"
	    ;;
esac

dnl Check libffi availability and use internal if none found
if test "$with_internal_libffi" = "auto"; then
  AC_CHECK_LIB(ffi,ffi_prep_cif,
         [with_internal_libffi=no2],
	 [echo "system-wide libffi is missing, use the built-in one"
	  with_internal_libffi=yes])
fi
case "$with_internal_libffi" in
	no)	AC_CHECK_LIB(ffi,ffi_prep_cif,echo -n,echo ***ERROR: libffi is missing; exit 1)
		LIBSVMADD="$LIBSVMADD -lffi";;
	no2)	LIBSVMADD="$LIBSVMADD -lffi";; dnl we already checked the lib above
	yes)	ac_configure_args="$ac_configure_args --enable-convenience-only-libffi"
		LIBSVMADD="$LIBSVMADD ../libffi/libffi_convenience.la"
		LIBSVMINCLUDE="-I../libffi -I../libffi/include"
		AC_MSG_CHECKING(which libffi to use)
		AC_MSG_RESULT(internal.)
	;;
esac
AC_MSG_CHECKING(which libffi to use)
case "$with_internal_libffi" in
	no*) AC_MSG_RESULT(system-wide.);;
	yes) AC_MSG_RESULT(internal.);;
esac

dnl Check libpopt availability and use internal if none found
if test "$with_internal_libpopt" = "auto"; then
  AC_CHECK_LIB(popt,poptGetContext,
         [with_internal_libpopt=no2],
	 [echo "system-wide libpopt is missing, use the built-in one"
	  with_internal_libpopt=yes])
fi
case "$with_internal_libpopt" in
	no)	AC_CHECK_LIB(popt,poptGetContext,echo -n,echo ***ERROR: libpopt is missing; exit 1)
		LIBSVMADD="$LIBSVMADD -lpopt";;
	no2)	LIBSVMADD="$LIBSVMADD -lpopt";;dnl we already checked the lib above
	yes)	ac_configure_args="$ac_configure_args --enable-convenience-only-libpopt"
		SVMADD="$LIBSVMADD ../libpopt/libpopt_convenience.la"
		SVMINCLUDE='-I../libpopt -I$(srcdir)/../libpopt'
	;;
esac
AC_MSG_CHECKING(which libpopt to use)
case "$with_internal_libpopt" in
	no*) AC_MSG_RESULT(system-wide.);;
	yes) AC_MSG_RESULT(internal.);;
esac

dnl we *always* have to configure subdirs, for explanation see:
dnl http://docs.biostat.wustl.edu/cgi-bin/info2html?(automake.info.gz)Conditional%2520Subdirectories
dnl "Any directory listed in `DIST_SUBDIRS' and `SUBDIRS' must be configured."
AC_CONFIG_SUBDIRS(src/libffi)
AC_CONFIG_SUBDIRS(src/libpopt)

AM_CONDITIONAL(CONV_LIBFFI, test "$with_internal_libffi" = "yes")
AM_CONDITIONAL(CONV_LIBPOPT, test "$with_internal_libpopt" = "yes")

AC_SUBST(LIBSVMADD, $LIBSVMADD)
AC_SUBST(LIBSVMINCLUDE, $LIBSVMINCLUDE)
AC_SUBST(SVMADD, $SVMADD)
AC_SUBST(SVMINCLUDE, $SVMINCLUDE)


dnl Check whether -no-undefined is required
case "$host" in
	*-*-mingw*|*-*-cygwin*) AC_SUBST(NO_UNDEFINED, -no-undefined) ;;
	*) ;;
esac

dnl Check which m4 we should use
if test "x$M4" = "x"; then 
    AC_PATH_PROG(M4, "gm4")
    if test "x$M4" = "x"; then
        AC_PATH_PROG(M4, "m4")
    fi
fi

if test "x$M4" = "x"; then
    AC_MSG_WARN('Unable to find operational m4 preprocessor. You might be unable to regenerate some source files.')
    M4=m4
else
    echo -n | $M4 -P || \
    (AC_MSG_WARN('Unable to find operational GNU-compatible m4 preprocessor. You might be unable to regenerate some source files.') )
fi

AC_SUBST(M4)


dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([errno.h fcntl.h stdlib.h string.h sys/time.h unistd.h ctype.h],
	echo -n,echo ***ERROR: missing header file; exit 1)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T
AC_HEADER_TIME
AC_CHECK_TYPE(siginfo_t,
              has_siginfo=yes; AC_DEFINE(_SABLEVM_HAS_SIGINFO, 1, siginfo_t is supported),
              has_siginfo=no, 
              [
#include <signal.h>
])

dnl Handle signals for exceptions based on the availability of siginfo_t.
if test "$has_siginfo" = no; then
	enable_signals_for_exceptions=no
	AC_MSG_WARN([siginfo is not available; use of signals has been disabled])
fi

case "$enable_signals_for_exceptions" in
	no)	;;
	yes)	AC_DEFINE(_SABLEVM_SIGNALS_FOR_EXCEPTIONS,1,use signals to detect exceptions) ;;
	*)	AC_MSG_ERROR(bad value \"${enable_signals_for_exceptions}\" for --enable-signals-for-exceptions) ;;
esac

dnl Checks for library functions.
if test x$cross_compiling = xno ; then
    AC_FUNC_MALLOC
fi
AC_FUNC_MMAP
AC_CHECK_FUNCS([getcwd gettimeofday memmove memset munmap strchr],
	echo -n,echo ***ERROR: missing library function; exit 1)

dnl GCC specific options
if test "$GCC" = "yes"; then
	CFLAGS="$CFLAGS -Wall -fno-gcse -fno-strict-aliasing"

	if test "$enable_no_reorder_blocks" = "yes"; then
			CFLAGS="$CFLAGS -fno-reorder-blocks -finline-limit=60000"
	fi

dnl -fverbose-asm -save-temps -fstack-check -funroll-loops

dnl	CFLAGS="$CFLAGS -fverbose-asm -save-temps"

    	if test "$with_threading" = "switch"; then
		CFLAGS="$CFLAGS -std=iso9899:1990 -pedantic"
	fi

	if test "$enable_debugging_features" = "yes"; then
		if test "$enable_errors_on_warnings" = "yes"; then
			CFLAGS="$CFLAGS -Werror"
		fi
		CFLAGS="$CFLAGS -O0 -W \
			-fno-builtin -Wshadow \
			-Wpointer-arith -Wbad-function-cast \
			-Wundef -Wcast-align -Wwrite-strings \
			-Wsign-compare -Wstrict-prototypes \
			-Wmissing-prototypes \
			-Wmissing-declarations \
			-Wnested-externs -Wlong-long"

	elif test "$enable_errors_on_warnings" = "yes"; then
	     enforce_errors_on_warnings=no
	     case $PACKAGE_VERSION in
		  *+*)
			case $host in
			     i*86*-*-gnu)   enforce_errors_on_warnings=yes ;;
			     powerpc-*-gnu) enforce_errors_on_warnings=yes ;;
			esac
			;;
	     esac
	     if test "$enforce_errors_on_warnings" = "yes"; then
		CFLAGS="$CFLAGS -Werror"
	     fi
	fi

    	if test "$with_threading" = "inlined"; then
		CFLAGS="$CFLAGS -O2"
	fi

	case $host in
	     powerpc-apple-darwin*) CFLAGS="$CFLAGS -no-cpp-precomp"
                                    CPPFLAGS="$CPPFLAGS -D__powerpc__"
				    ;;
	esac

	case $host in
	     *-freebsd*) dnl SableVM in FreeBSD ports has all three:
                         dnl -D__XSI_VISIBLE -D__BSD_VISIBLE -D_P1003_1B_VISIBLE
                         dnl however -D__BSD_VISIBLE seems sufficient
			 CFLAGS="$CFLAGS -pthread -D__BSD_VISIBLE"
			 ;;
	esac
fi

dnl check whether __func__ is available
AC_MSG_CHECKING([for __func__ availability])
AC_COMPILE_IFELSE(AC_LANG_PROGRAM([
    #include <stdio.h>
    void func() { printf("%s", __func__); }]),
    [AC_MSG_RESULT([yes])
     AC_DEFINE(HAVE___func__, 1, Whether __func__ is available)],
    [AC_MSG_RESULT([no])]
)

dnl Detect __clear_cache availability

AC_MSG_CHECKING([for __clear_cache availability])
AC_LINK_IFELSE(AC_LANG_PROGRAM([
#include <unistd.h>
extern void __clear_cache (char *beg, char *end);
void func(void) {
  char i = 0;
  __clear_cache(&i, (&i)+sizeof(i));
}]),
    [AC_MSG_RESULT([yes])
     AC_DEFINE(HAS_SYSTEM_CLEAR_CACHE,1,Whether __clear_cache is available)],
    [AC_MSG_RESULT([no])]
)

dnl -Wid-clash-LEN -Wlarger-than-LEN -Wredundant-decls -Wconversion -Wcast-qual
dnl -Wmissing-noreturn -Wtraditional -Waggregate-return -ansi -pedantic  -Wunreachable-code

AC_CONFIG_FILES([
	Makefile
	doc/Makefile
	doc/java-sablevm.1
	doc/sablevm.1
	src/Makefile
	src/include/Makefile
	src/libsablevm/Makefile
	src/libsablevm/include/Makefile
	src/libsablevm/inlinability/Makefile
	src/sablevm/Makefile
])

AC_OUTPUT
