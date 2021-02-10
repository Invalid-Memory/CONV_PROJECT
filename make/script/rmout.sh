#!/bin/bash
if [ -d $PWD/bin ]; then
    if [ -e $PWD/bin/exec ]; then
        rm -f $PWD/bin/exec
    fi
fi