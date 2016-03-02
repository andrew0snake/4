ffmpeg -i inputfile.wmv  -vcodec libx264 -crf 25 -s 360x288 -vpre veryslow -acodec libmp3lame -ar 44100 -ab 56k -f flv tmp.flv
