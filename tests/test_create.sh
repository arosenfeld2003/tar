#!/bin/bash

# test create_archive
MY_TAR=./my_tar
ARCHIVE=test_archive.tar
FILE1=test_file1.txt
FILE2=test_file2.txt

# clean up
rm -f $ARCHIVE $FILE1 $FILE2

# Create test files
echo "This is a test file 1" > $FILE1
echo "This is a test file 2" > $FILE2

echo $MY_TAR
# run create_archive
$MY_TAR -cf $ARCHIVE $FILE1 $FILE2

# check for archive
if [ ! -f $ARCHIVE ]; then
    echo "Test Failed: Archive not created"
    exit 1
fi

echo "Test Passed: Archive created successfully"