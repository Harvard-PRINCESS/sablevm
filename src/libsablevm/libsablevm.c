/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <config.h>

#include <pthread.h>
#include <signal.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ffi.h>
#include <math.h>
#include <ltdl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <zlib.h>
#include <limits.h>
#include <sys/utsname.h>
#include "time.h"
#include "sys/time.h"

#include "jnidefs.h"
#define _VIRTUAL_MACHINE
#include <jni.h>

#include "system.h"
#include "constants.h"
#include "types.h"
#include "fatal.h"
#include "thread.h"
#include "global_alloc.h"
#include "invoke_interface.h"
#include "util.h"
#include "global_refs.h"
#include "local_refs.h"
#include "cl_alloc.h"
#include "class_loader.h"
#include "class_file_parser.h"
#include "class_loader_memory_manager.h"
#include "prepare.h"
#ifdef _SABLEVM_INLINABILITY_TESTING
#  include "inlined_testing.h"
#endif
#include "link.h"
#include "interpreter.h"
#include "method_invoke.h"
#include "new_instance.h"
#include "native_interface.h"

#include "gnu_classpath_VMSystemProperties.h"
#include "gnu_classpath_VMStackWalker.h"
#include "java_io_VMObjectStreamClass.h"
#include "java_lang_VMRuntime.h"
#include "java_lang_Throwable.h"
#include "java_lang_VMClass.h"
#include "java_lang_VMClassLoader.h"
#include "java_lang_VMObject.h"
#include "java_lang_VMSystem.h"
#include "java_lang_VMThread.h"
#include "java_lang_VirtualMachine.h"
#include "java_lang_reflect_Array.h"
#include "java_lang_reflect_Constructor.h"
#include "java_lang_reflect_Field.h"
#include "java_lang_reflect_Method.h"

#include "internal_methods.h"

#include "cast.c"
#include "util1.c"
#include "util.c"
#include "system.c"
#include "fatal.c"
#include "error.c"
#include "error_throwing.c"
#include "global_alloc.c"
#include "global_refs.c"
#include "thread.c"
#include "local_refs.c"
#include "lib_init.c"
#include "gc_none.c"
#include "gc_copying.c"
#include "gc_gencopy.c"
#include "method_invoke.c"
#include "util2.c"
#include "resolve.c"
#include "class_loader_memory_manager.c"
#include "cl_alloc.c"
#include "class_file_parser.c"
#include "new_instance.c"
#include "splay_tree.c"
#include "zip_file_reader.h"
#include "zip_file_reader.c"
#include "class_loader.c"
#include "native.c"
#ifdef _SABLEVM_INLINABILITY_TESTING
#  include "inlined_testing.c"
#endif
#include "prepare_code.c"
#include "initialization.c"
#include "native_interface.c"
#include "system_next.c"
#include "interpreter.c"
#include "prepare.c"
#include "verifier.c"
#include "link.c"
#include "bootstrap.c"
#include "invoke_interface.c"

#include "gnu_classpath_VMSystemProperties.c"
#include "gnu_classpath_VMStackWalker.c"
#include "java_io_VMObjectStreamClass.c"
#include "java_lang_VMRuntime.c"
#include "java_lang_VMThread.c"
#include "java_lang_Throwable.c"
#include "java_lang_VMClass.c"
#include "java_lang_VMClassLoader.c"
#include "java_lang_VMObject.c"
#include "java_lang_VMSystem.c"
#include "java_lang_VirtualMachine.c"
#include "java_lang_reflect_Array.c"
#include "java_lang_reflect_Constructor.c"
#include "java_lang_reflect_Field.c"
#include "java_lang_reflect_Method.c"

#include "internal_methods.c"
