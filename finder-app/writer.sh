#!/bin/sh

usage () {
  echo USAGE: $0 FILE STRING
}

if [ $# -lt 2 ]
then
  echo ERR: Not enough arguments
  usage
  exit 1
fi

mkdir -p ${1%/*}
echo $2 > $1
