## * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
## * This source file is part of SableVM.                            *
## *                                                                 *
## * See the file "LICENSE" for the copyright information and for    *
## * the terms and conditions for copying, distribution and          *
## * modification of this source file.                               *
## * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

include_HEADERS = jni.h jni_system_specific.h

JAVA_HOME=$(DESTDIR)$(pkglibdir)
install-data-hook:
	mkdir -p $(JAVA_HOME)/include
	for f in $(include_HEADERS) ; do \
	  rm -f $(JAVA_HOME)/include/$$f ; \
	  $(LN_S) $(includedir)/$$f $(JAVA_HOME)/include/$$f ; \
	done

uninstall-hook:
	-(cd $(JAVA_HOME)/include && rm -f $(include_HEADERS))
	-rmdir $(JAVA_HOME)/include
