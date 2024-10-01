#!/bin/bash

# Check if file was provided as argument
if [ -z "$1" ]; then
  echo "Usage: $0 <source-file.cpp>"
  exit 1
fi

# Extract file name without extension
filename=$(basename -- "$1")
output="${filename%.*}"

# Compile the file in C++14 with debug symbols (-g)
g++ -std=c++14 -g -o "$output" "$1"

# Check if compilation was successful
if [ $? -eq 0 ]; then
  echo "Compilation successful. Executable: $output"
else
  echo "Compilation failed."
fi