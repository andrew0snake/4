ffmpeg -i 1.mp4 -codec:v libx264 -profile:v high -preset slower -b:v 1000k -vf scale=-1:1920 -threads 8 -codec:a libfaac -b:a 196k output.mp4

