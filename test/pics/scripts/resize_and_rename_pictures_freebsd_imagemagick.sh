#!/usr/local/bin/bash

mkdir resized;
var=0;

#for i in `ls|grep -v resize_pictures_freebsd_imagemagick.sh|grep -v rename.sh|grep -v resized`
for i in *.jpg
    do
        echo $i;
        convert "$i" -resize 1920x1080 resized/"${i%.jpg}_2.jpg"
        ((var=var+1));
        echo $var;
    done;
    #!/usr/local/bin/bash

mkdir renamed;
var=0;

#for i in `ls|grep -v rename.sh|grep jpg`
for i in resized/*.jpg
    do
        echo $i;
        ((var=var+1));
        echo $var;
        mv "$i" ./renamed/"$var".jpg
    done;
    
var=0;
ls -la ./renamed;