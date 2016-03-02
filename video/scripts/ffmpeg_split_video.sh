echo "Two commands" 
time ffmpeg -v quiet -y -i input.ts -vcodec copy -acodec copy -ss 00:00:00 -t 00:30:00 -sn test1.mkv
time ffmpeg -v quiet -y -i input.ts -vcodec copy -acodec copy -ss 00:30:00 -t 01:00:00 -sn test2.mkv
echo "One command" 
time ffmpeg -v quiet -y -i input.ts -vcodec copy -acodec copy -ss 00:00:00 -t 00:30:00  -sn test3.mkv -vcodec copy -acodec copy -ss 00:30:00 -t 01:00:00 -sn test4.mkv

