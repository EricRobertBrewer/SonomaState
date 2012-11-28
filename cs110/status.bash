#! /bin/bash

if (( $# != 1 )); then
    echo "ERROR - Usage: $0 FileName"
    exit 1
fi

ls $1 > /dev/null 2>&1
if (( $? == 0 )); then
    echo "$1 exists in this directory."
else
    echo "$1 does not exist in this directory."
fi

exit 0
