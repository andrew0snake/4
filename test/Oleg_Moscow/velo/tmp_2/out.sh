#!/bin/bash

for i in `seq 1 14`
do
    awk '/company/ {for(i=1; i<=5; i++) {getline; print}}' $i |grep -v div >"$i"_parsed
done
