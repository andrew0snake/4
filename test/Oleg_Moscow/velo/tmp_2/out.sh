#!/bin/bash

for i in `seq 10 12`
do
#    awk '/company/ {for(i=1; i<=5; i++) {getline; print}}' $i |grep -v div >"$i"_parsed
#    cat $i |grep company > tmp;
#    awk '/company/ {for(i=0; i<=5; i++) {getline; print}}' $i >"$i"_parsed_2    
#    awk '/a href="http:\/\/www.list-org.com/ {for(i=1; i<=5; i++) {getline; print}}' $i >"$i"_parsed_2    
    sed -n /company/,+5p $i >"$i"_parsed_3
    rm source_file;
    rm tmp_file;
    cp "$i"_parsed_3 source_file;
    ./rebuild;
    cp tmp_file "$i"_parsed_4

done
