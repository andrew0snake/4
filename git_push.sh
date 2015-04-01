#!/bin/tcsh
echo "git push git@github.com:andrew0snake/4.git"
`cat git_link |awk '{if (NR==3) print}'`

