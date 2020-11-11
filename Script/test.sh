#!/bin/sh
# Author : Ashish Bhusal
# Copyright (c) Ashish Bhusal

if [ "$1" != "" ]; then
    file="$1"
else 
	echo "Provide the file name"
	exit 0
fi
input="input.txt"
output="output.txt"
expected="expected.txt"
g++ $file
./a.out < $input > $output
echo "Expected:-"
cat < $expected
echo "Actual:-"
cat < $output
temp=$(diff -BZ $output $expected)
if [ "$temp" = "" ]; then
	echo "Success"
else
	echo "Failed!!!"
fi