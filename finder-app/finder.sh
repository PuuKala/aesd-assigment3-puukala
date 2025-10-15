#!/bin/sh

usage () {
  echo "USAGE:" $0 "FOLDER" "STRING"
}

if [ $# -lt 2 ]
then
  echo "ERR: Not enough parameters"
  usage
  exit 1
fi

if [ ! -d $1 ]
then
  echo "ERR:" $1 "not a dir"
  usage
  exit 1
fi

hitnum="$(grep -or $2 $1 | wc -l)"
# filenum="$(grep -rl $2 $1 | wc -l)"
filenum="$(find $1 -type f | wc -l)"

echo The number of files are $filenum and the number of matching lines are $hitnum
