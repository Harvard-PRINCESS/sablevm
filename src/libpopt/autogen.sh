#!/bin/sh -e

#srcdir="`dirname $0`"
#test -z "$srcdir" && srcdir=.

#THEDIR="`pwd`"

#cd "$srcdir"
libtoolize --copy --force
aclocal
autoheader
automake -a -c
autoconf

echo "You can now run configure."

exit 0

if [ "$1" = "--noconfigure" ]; then 
    exit 0;
fi

cd "$THEDIR"

if [ X"$@" = X  -a "X`uname -s`" = "XLinux" ]; then
    $srcdir/configure --prefix=/usr "$@"
else
    $srcdir/configure "$@"
fi
