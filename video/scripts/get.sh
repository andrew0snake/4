#!/usr/local/bin/bash
##!/bin/bash
read source;

url_image=`cat $source|grep "og:image"|awk -F '"' '{print $4}'`
echo "url of image = "$url_image
echo "";
wget --no-check-certificate $url_image -O hqdefault.jpg

keywords=`cat $source|grep keywords|awk '{if (NR==2) print}'|awk -F "keywords" '{print $2}'|awk -F '"' '{print $3}'`
echo "keywords = "$keywords;
echo $keywords > keywords;
echo "";
#cat keywords;

channel=`cat $source| grep author | grep ytplayer | awk -F "author" '{ print $2 }'|awk -F '"' '{print $3}'`
echo "channel = "$channel;
echo $channel > channel;
echo "";

filename=`cat $source| grep eow-title | awk -F '"' '{print $8}'| sed 's/&quot\;//g'`
echo "filename = "$filename;
echo $filename > filename;
echo "";

description=`cat $source|grep "action-panel-details"|awk -F "<p id\=\"eow-description\" \>" '{print $2}'|sed  's/<br \/>/ /g'|sed 's/<\/p>/ /g'|sed 's/<\/div>//g'|sed 's/<br \/>//g'|sed 's/<div id="watch-description-extras" >//g'|sed 's/<\/a>//g'|sed 's/<br \/>//g'`
echo "description = "$description;
echo $description > description;
echo "";

url_video=`cat $source|grep canonical|awk -F "canonical\" href=\"" '{print $2}'|awk -F '"' '{print $1}'` 
echo "url_video = "$url_video;
echo $url_video > url_video;
echo "";

