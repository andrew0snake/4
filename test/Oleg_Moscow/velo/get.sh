#!/usr/local/bin/bash
i=37

for i in `seq 71 100`
do
    echo i=$i
    echo "http://www.list-org.com/list.php?okved=52.48.23&page="$i
    #wget -r --no-parent -l 0 "http://www.list-org.com/list.php?okved=52.48.23&page="$i -O $i
    konqueror "http://www.list-org.com/list.php?okved=52.48.23&page="$i
    #firefox "http://www.list-org.com/list.php?okved=52.48.23&page="$i
done