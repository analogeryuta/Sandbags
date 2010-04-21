#!/bin/sh

ARCH1=X86_64

if [ -d /usr/local/Library ] ; then
    for f in `cat plist-${ARCH1}`; do
	ls -lh ${f} ;
    done;
else
    ls -lh /usr/local/share ;
fi;
