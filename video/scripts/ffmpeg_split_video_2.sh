#!/usr/local/bin/bash
##!/bin/bash

read source

time ffmpeg -v quiet -y -i $source -vcodec copy -acodec copy -ss 00:00:00 -t 00:05:00 -sn first_part.mp4

