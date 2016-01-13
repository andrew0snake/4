#!/usr/local/bin/bash
for f in ./*.mp3; 
    do 
        echo "file '$f'" >> mylist.txt; 
    done

ffmpeg -f concat -i mylist.txt -c copy all_files.mp3