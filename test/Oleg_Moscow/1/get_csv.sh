#!/usr/local/bin/bash

for i in `seq 1 13`
do
    echo $i
#    cat $i| grep company | awk -F '\"\>' '{print $2 $3 $4 $5}' | awk -F '</span>' '{print $1}'
#    cat $i| grep company | awk -F '>' '{print $5}' | awk -F '<' '{print $1}'|perl -p -e 's/\)/,/g' >> full
    cat $i| grep company | awk -F '\"\>\ ' '{print $2}' | awk -F '\<\/' '{print $1}' >> full2.csv


#cat $source| grep company | awk -F '>' '{print $5}' | awk -F '<' '{print $1}'|perl -pi -e 's/\)/,/g' > "$source".csv
done

