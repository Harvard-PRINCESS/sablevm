## * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
## * This source file is part of SableVM.                            *
## *                                                                 *
## * See the file "LICENSE" for the copyright information and for    *
## * the terms and conditions for copying, distribution and          *
## * modification of this source file.                               *
## * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SUBDIRS = doc src

pkgdata_DATA = LICENSE AUTHORS LGPL-2.1

EXTRA_DIST = .indent.pro LICENSE java-sablevm.tmpl javac-sablevm.tmpl jar-sablevm.tmpl \
    ChangeLog INSTALL-DEVEL LGPL-2.1

DISTCHECK_CONFIGURE_FLAGS = --with-internal-libffi --with-internal-libpopt

bin_SCRIPTS = java-sablevm javac-sablevm jar-sablevm

CLEANFILES = java-sablevm javac-sablevm jar-sablevm ChangeLog

# for path substitution in the script we need to get "bindir" from make time
# and NOT install time!
BUILT_SOURCES = java-sablevm javac-sablevm jar-sablevm

java-sablevm: java-sablevm.tmpl Makefile
	rm -f $@
	( SABLEVM_BIN=`echo "sablevm" | sed 's|^.*/||;$(transform)'` ; \
	  cat $@.tmpl | \
	    sed s/SABLEVM_BINARY/`echo @bindir@/$$SABLEVM_BIN | sed 's/\\//\\\\\\//g'`/g | \
	    sed s/SABLEVM_CLASSDIR/`echo @datadir@/sablevm-classpath | sed 's/\\//\\\\\\//g'`/g \
	  > $@ )
	chmod a-w $@

javac-sablevm: javac-sablevm.tmpl Makefile
	rm -f $@
	( cat $@.tmpl | \
	    sed s/SABLEVM_CLASSDIR/`echo @datadir@/sablevm-classpath | sed 's/\\//\\\\\\//g'`/g | \
	    sed s/JIKES_BINARY/`echo @JIKES@ | sed 's/\\//\\\\\\//g'`/g \
	  > $@ )
	chmod a-w $@

jar-sablevm: jar-sablevm.tmpl Makefile
	rm -f $@
	( cat $@.tmpl | \
	    sed s/SABLEVM_CLASSDIR/`echo @datadir@/sablevm-classpath | sed 's/\\//\\\\\\//g'`/g | \
	    sed s/FASTJAR_BINARY/`echo @FASTJAR@ | sed 's/\\//\\\\\\//g'`/g \
	  > $@ )
	chmod a-w $@
ChangeLog:
	svn log -v $(srcdir) > $@

indent:
	find . -print | grep -v src/libpopt/ | grep -v src/libffi/ | \
	grep \\.[ch]$$ | \
	awk ' \
	{print "indent " $$1 " -o " $$1 ".indented && \
	if cmp -s " $$1 " " $$1 ".indented; \
	then rm " $$1 ".indented; \
	else mv " $$1 ".indented " $$1 "; \
	echo " $$1 "; \
	fi"} \
	' | \
	sh

svnclean:
	svn st --no-ignore | grep ^I | cut -c8- | awk '{print "\"" $$0 "\""}'| xargs rm -rf

JAVA_HOME=$(DESTDIR)$(pkglibdir)
install-exec-hook:
	-mkdir -p $(JAVA_HOME)
	-cd $(JAVA_HOME) && mkdir bin jre &>/dev/null
	-cd $(JAVA_HOME) && rm -f bin/java bin/javac bin/jar
	-unlink $(JAVA_HOME)/jre/bin &>/dev/null
	if test ! -L $(JAVA_HOME)/jre/bin; then rm -rf $(JAVA_HOME)/jre/bin; fi
	$(LN_S) ../../../bin/`echo "java-sablevm" | sed 's|^.*/||;$(transform)'` $(JAVA_HOME)/bin/java
	$(LN_S) ../../../bin/`echo "javac-sablevm" | sed 's|^.*/||;$(transform)'` $(JAVA_HOME)/bin/javac
	$(LN_S) ../../../bin/`echo "jar-sablevm" | sed 's|^.*/||;$(transform)'` $(JAVA_HOME)/bin/jar	
	$(LN_S) ../bin $(JAVA_HOME)/jre/bin
	-touch $(JAVA_HOME)/bin/jdb

uninstall-hook:
	-cd $(JAVA_HOME) && rm -f bin/java bin/javac bin/jdb
	-unlink $(JAVA_HOME)/jre/bin &>/dev/null
	-cd $(JAVA_HOME) && rmdir bin jre
	-rmdir $(JAVA_HOME) &>/dev/null

distcheck-hook:
	@echo hook is empty
