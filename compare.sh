#!/bin/bash

# Check if two arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 file1 file2"
    exit 1
fi

# Assign arguments to variables
file1=$1
file2=$2

# Compare the files using diff and output the results
diff --strip-trailing-cr $file1 $file2