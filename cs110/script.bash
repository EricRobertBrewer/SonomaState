#! /bin/bash

if [[ $# != 1 ]]; then
    echo "One argument, please."
    exit 1
fi

who | grep "^$1 " > /dev/null

if [[ $? == 0 ]]; then
    echo "$1 is online."
else
    echo "$1 is offline."
fi
