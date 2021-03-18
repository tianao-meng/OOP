#!/bin/bash
file1=${1}
echo ${file1}
file2=${2}
echo ${file2}
if `diff ${file1} ${file2} > /dev/null` ; then # ignore diff output, check exit status echo "same files"
    echo "Mostly the same"
else
    echo "different"
fi
