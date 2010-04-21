#!/bin/sh

for f in `cat movie_list`; do
    rm -rf ${f}
done;
