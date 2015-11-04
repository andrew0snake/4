#!/bin/tcsh

set source=$<;

cat $source| grep company | awk -F '>' '{print $5}' | awk -F '<' '{print $1}'|perl -pi -e 's/\)/,/g'

cat $source| grep company | awk -F '>' '{print $5}' | awk -F '<' '{print $1}'|perl -pi -e 's/\)/,/g' > "$source".csv