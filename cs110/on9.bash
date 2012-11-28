#! /bin/bash

a=$(who | grep "$1 ")

echo $a
