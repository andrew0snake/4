#!/usr/local/bin/bash

for i in `seq 1 13`
do
    echo http://www.list-org.com/list.php?okved=50.4\&page=$i;
    echo http://www.list-org.com/list.php?okved=50.4\&page=$i >> links
#    echo $i;
done

