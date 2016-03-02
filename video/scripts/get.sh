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

filename=`cat $source| grep eow-title | awk -F '"' '{print $8}'`
echo "filename = "$filename;
echo $filename > filename;
echo "";

description=`cat $source|grep "action-panel-details"|awk -F "<p id\=\"eow-description\" \>" '{print $2}'|sed  's/<br \/>/ /'|sed 's/<\/p>/ /'|sed 's/<\/div>//'|sed 's/<br \/>//'|sed 's/<div id="watch-description-extras" >//'|sed 's/<\/a>//'`
echo "description = "$description;
echo $description > description;
echo "";

url_video=`cat $source|grep canonical|awk -F "canonical\" href=\"" '{print $2}'|awk -F '"' '{print $1}'` 
echo "url_video = "$url_video;
echo $url_video > url_video;
echo "";

