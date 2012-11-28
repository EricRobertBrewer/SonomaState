#! /bin/bash

if [[ $# == 0 ]]; then
    echo "Number of files: $(ls -a | wc -l)"
else
    echo "Number of files in $1: $(ls -a $1 | wc -l)"
fi