#!/usr/local/bin/bash

mkdir renamed;
var=0;

#for i in `ls|grep -v rename.sh|grep jpg`
for i in *.jpg
    do
        echo $i;
        ((var=var+1));
        echo $var;
        mv "$i" ./renamed/"$var".jpg
    done;
    