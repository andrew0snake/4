#!/bin/bash

rm *_parsed;
rm *_parsed_2;
rm full;

for i in `seq 1 96`
do
#    awk '/company/ {for(i=1; i<=5; i++) {getline; print}}' $i |grep -v div >"$i"_parsed
#    cat $i |grep company > tmp;
#    awk '/company/ {for(i=0; i<=5; i++) {getline; print}}' $i >"$i"_parsed_2    
#    awk '/a href="http:\/\/www.list-org.com/ {for(i=1; i<=5; i++) {getline; print}}' $i >"$i"_parsed_2    
    sed -n /company/,+5p $i >"$i"_parsed
    rm source_file;
    rm tmp_file;
    cp "$i"_parsed source_file;
    ./rebuild;
    cp tmp_file "$i"_parsed_2

done

#for i in `seq 1 9`
#do
#    sed -n /company/,+5p 0$i >0"$i"_parsed
#    rm source_file;
#    rm tmp_file;
#    cp 0"$i"_parsed source_file;
#    ./rebuild;
#    cp tmp_file 0"$i"_parsed_2
#done#!/bin/bash

for i in `seq 1 9`
do 
    mv "$i"_parsed_2 0"$i"_parsed_2;
done

cat *_parsed_2 >> full;

sed '/^$/d' full > tmp
rm full;
mv tmp full;

cat full |grep -v "Поиск по наименованию" > tmp
rm full;
mv tmp full;

cat full |grep -v "Поиск по ИНН" > tmp
rm full;
mv tmp full;