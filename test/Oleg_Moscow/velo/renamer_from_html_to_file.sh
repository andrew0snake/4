#!/bin/tcsh
foreach i (`ls *|grep -v *.sh`)
echo $i;
set newname=`echo $i|awk -F '.html' '{print $1}'`
echo $newname
mv $i $newname;
end


