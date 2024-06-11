#!/bin/bash

# test create_archive
MY_TAR=../my_tar
ARCHIVE=test_archive.tar
FILE1=test_file1.txt
FILE2=test_file2.txt

# clean up
rm -f $ARCHIVE $FILE1 $FILE2

# run create_archive
$MY_TAR -cf $ARCHIVE $FILE1 $FILE2

# check for archive
if [ ! -f $ARCHIVE ]; then
    echo "Test Failed: Archive not created"
    exit 1
fi

echo "Test Passed: Archive created successfully"