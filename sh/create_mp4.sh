#!/bin/sh

MP4DIR=/Users/freddie/Downloads/Media/Video/Macross_Frontier/mp4_files
RATE=23.976

for f in `cat movie_list`; do
    if [ -f "${MP4DIR}/${f}.mp4" ] ; then
	echo "skip creating mp4 file ..."
    else
	MP4Box -new -add ${f}/${f}.h264 -add ${f}/${f}.aac -fps ${RATE} ${MP4DIR}/${f}.mp4
    fi;
done;
