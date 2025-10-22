#!/bin/bash

BINNAME="${1%.*}"

gcc -o $BINNAME $1
