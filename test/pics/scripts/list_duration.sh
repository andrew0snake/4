#!/usr/local/bin/bash

rm full_list;

for i in *.mp3 
    do
        echo $i;
        ffmpeg -i "$i" >> full_list  2>&1;
        echo "-----------------------------------------" >> full_list;
    done;
    
cat full_list|grep -e "Input" -e "Duration" > names_and_duration;
cat names_and_duration;