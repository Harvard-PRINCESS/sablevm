## * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
## * This source file is part of SableVM.                            *
## *                                                                 *
## * See the file "LICENSE" for the copyright information and for    *
## * the terms and conditions for copying, distribution and          *
## * modification of this source file.                               *
## * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

## GNU m4 & grep
M4 = @M4@
GREP = grep

SUBDIRS = include inlinability

lib_LTLIBRARIES = libsablevm.la

## We want to build libsablevm as a single library, while
## using many source files, for readability.  To do this,
## we have a single libsablevm.c source file which does
## includes the other files.  We list all the .c and .h
## files as "noinst_HEADERS" so that automake does not try
## to compile each .c file individually.

libsablevm_la_SOURCES = \
	libsablevm.c

libsablevm.c: $(noinst_HEADERS)

## We use m4 to generate some files and save ourselves
## a lot of boring typing.  It's more fun to write
## m4 macros;-)

INLINABILITY_FILES = \
	inlinability/inlined_alpha.h \
	inlinability/inlined_arm.h \
	inlinability/inlined_hppa.h \
	inlinability/inlined_i386-gcc-2.95.h \
	inlinability/inlined_i386-gcc-3.3-fp.h \
	inlinability/inlined_i386-gcc-3.3.h \
	inlinability/inlined_ia64.h \
	inlinability/inlined_m68k.h \
	inlinability/inlined_powerpc-no-reorder.h \
	inlinability/inlined_powerpc.h \
	inlinability/inlined_s390.h \
	inlinability/inlined_sparc.h \
	inlinability/inlined_x86_64.h \
	inlinability/inlinability.m4 \
	inlinability/inlinability.list

BUILT_SOURCES = \
	bootstrap.c \
	cast.c \
	cl_alloc.c \
	cl_alloc.h \
	class_file_parser.c \
	error_bits.h \
	error_classes.h \
	error_init_methods.h \
	error_instances.h \
	error_throwing.c \
	global_alloc.c \
	global_alloc.h \
	instructions_preparation_direct_threaded.c \
	instructions_preparation_inlined_threaded.c \
	instructions_preparation_switch_threaded.c \
	instructions_switch.c \
	internal_methods.c \
	method_invoke.c \
	method_invoke.h \
	native_interface.c \
	splay_tree.c \
	util.c \
	vm_args.c \
	\
	internal_methods.list \
	\
	$(INLINABILITY_FILES)


noinst_HEADERS = \
	$(BUILT_SOURCES) \
	\
	class_file_parser.h \
	class_loader.c \
	class_loader.h \
	class_loader_memory_manager.c \
	class_loader_memory_manager.h \
	constants.h \
	error.c \
	fatal.c \
	fatal.h \
	gc_copying.c \
	gc_gencopy.c \
	gc_gencopy.h \
	gc_none.c \
	global_refs.c \
	global_refs.h \
	gnu_classpath_VMSystemProperties.c \
	gnu_classpath_VMSystemProperties.h \
	gnu_classpath_VMStackWalker.c \
	gnu_classpath_VMStackWalker.h \
	inlined_testing.c \
	inlined_testing.h \
	initialization.c \
	internal_methods.h \
	interpreter.c \
	interpreter.h \
	invoke_interface.c \
	invoke_interface.h \
	java_io_VMObjectStreamClass.c \
	java_io_VMObjectStreamClass.h \
	java_lang_VMRuntime.c \
	java_lang_VMRuntime.h \
	java_lang_Throwable.c \
	java_lang_Throwable.h \
	java_lang_VMClass.c \
	java_lang_VMClass.h \
	java_lang_VMClassLoader.c \
	java_lang_VMClassLoader.h \
	java_lang_VMObject.c \
	java_lang_VMObject.h \
	java_lang_VMSystem.c \
	java_lang_VMSystem.h \
	java_lang_VMThread.c \
	java_lang_VMThread.h \
	java_lang_VirtualMachine.c \
	java_lang_VirtualMachine.h \
	java_lang_reflect_Array.c \
	java_lang_reflect_Array.h \
	java_lang_reflect_Constructor.c \
	java_lang_reflect_Constructor.h \
	java_lang_reflect_Field.c \
	java_lang_reflect_Field.h \
	java_lang_reflect_Method.c \
	java_lang_reflect_Method.h \
	jnidefs.h \
	lib_init.c \
	link.c \
	link.h \
	local_refs.c \
	local_refs.h \
	native.c \
	native_interface.h \
	new_instance.c \
	new_instance.h \
	prepare.c \
	prepare.h \
	prepare_code.c \
	resolve.c \
	system.c \
	system.h \
	system_next.c \
	thread.c \
	thread.h \
	types.h \
	util.h \
	util1.c \
	util2.c \
	verifier.c \
	zip_file_reader.c \
	zip_file_reader.h \
	\
	cast.list \
	cl_alloc.list \
	error.list \
	global_alloc.list \
	method_invoke.list \
	splay_tree.list \
	two_modes.list \
	\
	internal_methods.list.head \
	\
	direct_threaded.m4 \
	inlined_threaded.m4 \
	macros.m4 \
	switch_threaded.m4 \
	\
	bootstrap.m4.c \
	cast.m4.c \
	cl_alloc.m4.c \
	cl_alloc.m4.h \
	class_file_parser.m4.c \
	error_bits.m4.h \
	error_classes.m4.h \
	error_init_methods.m4.h \
	error_instances.m4.h \
	error_throwing.m4.c \
	global_alloc.m4.c \
	global_alloc.m4.h \
	instructions.m4.c \
	instructions_preparation.m4.c \
	instructions_switch.m4.c \
	internal_methods.m4.c \
	method_invoke.m4.c \
	method_invoke.m4.h \
	native_interface.m4.c \
	splay_tree.m4.c \
	util.m4.c \
	vm_args.m4.c

class_file_parser.c: macros.m4 class_file_parser.m4.c
	rm -f $@
	$(M4) -P $^ > $@
	chmod a-w $@

bootstrap.c: macros.m4 bootstrap.m4.c
	rm -f $@
	$(M4) -P $^ > $@
	chmod a-w $@

cl_alloc.c: macros.m4 cl_alloc.m4.c cl_alloc.list
	rm -f $@
	$(M4) -P $^ > $@
	chmod a-w $@

cl_alloc.h: macros.m4 cl_alloc.m4.h cl_alloc.list
	rm -f $@
	$(M4) -P $^ > $@
	chmod a-w $@

cast.c: macros.m4 cast.m4.c cast.list
	rm -f $@
	$(M4) -P $^ > $@
	chmod a-w $@

error_bits.h: macros.m4 error_bits.m4.h error.list
	rm -f $@
	$(M4) -P $^ > $@
	chmod a-w $@

error_classes.h: macros.m4 error_classes.m4.h error.list
	rm -f $@
	$(M4) -P $^ > $@
	chmod a-w $@

error_init_methods.h: macros.m4 error_init_methods.m4.h error.list
	rm -f $@
	$(M4) -P $^ > $@
	chmod a-w $@

error_instances.h: macros.m4 error_instances.m4.h error.list
	rm -f $@
	$(M4) -P $^ > $@
	chmod a-w $@

error_throwing.c: macros.m4 error_throwing.m4.c error.list
	rm -f $@
	$(M4) -P $^ > $@
	chmod a-w $@

global_alloc.c: macros.m4 global_alloc.m4.c global_alloc.list
	rm -f $@
	$(M4) -P $^ > $@
	chmod a-w $@

global_alloc.h: macros.m4 global_alloc.m4.h global_alloc.list
	rm -f $@
	$(M4) -P $^ > $@
	chmod a-w $@

instructions_preparation_inlined_threaded.c: macros.m4 inlined_threaded.m4 two_modes.list instructions_preparation.m4.c instructions.m4.c
	rm -f $@
	$(M4) -P @inlinability_testing@ $^ > $@
	chmod a-w $@

instructions_preparation_direct_threaded.c: macros.m4 direct_threaded.m4 two_modes.list instructions_preparation.m4.c instructions.m4.c
	rm -f $@
	$(M4) -P $^ > $@
	chmod a-w $@

instructions_preparation_switch_threaded.c: macros.m4 switch_threaded.m4 two_modes.list instructions_preparation.m4.c instructions.m4.c
	rm -f $@
	$(M4) -P $^ > $@
	chmod a-w $@

instructions_switch.c: macros.m4 two_modes.list instructions_switch.m4.c instructions.m4.c
	rm -f $@
	$(M4) -P $^ > $@
	chmod a-w $@

internal_methods.c: macros.m4 internal_methods.m4.c internal_methods.list
	rm -f $@
	$(M4) -P $^ > $@
	chmod a-w $@

method_invoke.c: macros.m4 method_invoke.m4.c method_invoke.list
	rm -f $@
	$(M4) -P $^ > $@
	chmod a-w $@

method_invoke.h: macros.m4 method_invoke.m4.h method_invoke.list
	rm -f $@
	$(M4) -P $^ > $@
	chmod a-w $@

native_interface.c: macros.m4 native_interface.m4.c
	rm -f $@
	$(M4) -P $^ > $@
	chmod a-w $@

splay_tree.c: macros.m4 splay_tree.m4.c splay_tree.list
	rm -f $@
	$(M4) -P $^ > $@
	chmod a-w $@

util.c: macros.m4 util.m4.c
	rm -f $@
	$(M4) -P $^ > $@
	chmod a-w $@

vm_args.c: macros.m4 vm_args.m4.c
	rm -f $@
	$(M4) -P $^ > $@
	chmod a-w $@

inlinability/inlined_%.h: macros.m4 inlinability/inlinability.m4 inlinability/inlinability.list
	rm -f $@
	$(M4) -P -Dm4svm_archname=$* $^ > $@
	chmod a-w $@

internal_methods.list : internal_methods.list.head \
    $(wildcard $(srcdir)/java_*.c) $(wildcard $(srcdir)/gnu_classpath_*.c)
	rm -f $@
	cat $< > $@
	$(GREP) -h "^Java_.*(" $^ | $(AWK) '{print $$1}' >> $@
	$(ECHO) >> $@
	$(ECHO) ":]m4svm_internal_method_end" >> $@
	$(ECHO) >> $@
	$(ECHO) "m4svm_file_tail" >> $@
	chmod a-w $@

distclean-local:
	rm -f bootstrap.c
	rm -f cast.c
	rm -f cl_alloc.c
	rm -f cl_alloc.h
	rm -f class_file_parser.c
	rm -f error_bits.h
	rm -f error_classes.h
	rm -f error_init_methods.h
	rm -f error_instances.h
	rm -f error_throwing.c
	rm -f global_alloc.c
	rm -f global_alloc.h
	rm -f inlinability/inlined_*.h
	rm -f instructions_preparation_direct_threaded.c
	rm -f instructions_preparation_inlined_threaded.c
	rm -f instructions_preparation_switch_threaded.c
	rm -f instructions_switch.c
	rm -f internal_methods.c
	rm -f method_invoke.c
	rm -f method_invoke.h
	rm -f native_interface.c
	rm -f splay_tree.c
	rm -f util.c
	rm -f vm_args.c
	rm -f internal_methods.list

libsablevm_la_LIBADD = @LIBSVMADD@

libsablevm_la_LDFLAGS = -release @LIBRELEASE@ @NO_UNDEFINED@

INCLUDES = @LIBSVMINCLUDE@ \
	-I$(srcdir)/include -I$(srcdir)/inlinability -Iinlinability \
	-DJAVA_HOME_PATH=\"$(pkglibdir)\" \
	-DBOOT_CLASS_PATH=\"$(datadir)/sablevm-classpath:$(datadir)/sablevm-classpath/libclasspath.jar:$(datadir)/sablevm-classpath/resources.jar\" \
	-DBOOT_LIBRARY_PATH=\"$(libdir)/sablevm-classpath\"
