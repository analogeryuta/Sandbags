#!/bin/sh

ARCH1=x86_64
ARCH2=i386

if [ ${ARCH1} = ${ARCH2} ] ; then
    echo "directory that you chosen is exist."
else
    echo "directory that you chosen is not exist."
fi;
