#!/bin/sh

MKVDIR=/Users/freddie/Downloads/Media/Video/Macross_Frontier/orig_files
MP4DIR=/Users/freddie/Downloads/Media/Video/Macross_Frontier/mp4_files

for f in `cat movie_list`; do
    if [ -f "${MP4DIR}/${f}.mp4" ] ; then
	echo "converted mp4 file is already exists. skip extracting..."
    else 
	if [ -f "${MKVDIR}/${f}.mkv" ] ; then
	    if [ -d "${f}" ] ; then
		echo "directory is already exists. skip creating directory..."
	    else
		mkdir ${f}; cd ${f}
		mkvextract tracks ${MKVDIR}/${f}.mkv 1:${f}.h264 2:${f}.aac
            cd ..
	    fi;
     	else
	    echo "${f}.mkv not exists. skip extracting..."
	fi;
    fi;
done;
