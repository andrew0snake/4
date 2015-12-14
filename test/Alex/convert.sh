#!/bin/bash

#for i in `cat string|sed -e 's/\(.\)/\1\n/g'`
#do 
#    echo "'"$i"'";
#done

rm string_converted;
rm string_tmp;

foo=`cat string`
for (( i=0; i<${#foo}; i++ )); 
do
   echo "'"${foo:$i:1}"'";
   echo $i;
   echo "'"${foo:$i:1}"'">>string_tmp;
done

cat string_tmp |perl -pi -e 's/\n/,/g' > string_converted;
rm string_tmp;


