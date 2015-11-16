#!/usr/local/bin/bash


for i in `seq 1 10`
do 
    wget -nd -nH -w 25 --waitretry=15 -O "$i" --random-wait -A.php http://www.list-org.com/list.php?okved=51.47.35&page="$i"
    echo http://www.list-org.com/list.php?okved=51.47.35\&page="$i"
done
