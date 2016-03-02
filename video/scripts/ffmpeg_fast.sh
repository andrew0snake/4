ffmpeg -i first_part.mp4 -codec:v libx264  -preset fast  -vf scale=-1:1080 -threads 8 -codec:a libfaac -b:a 196k output.mp4

