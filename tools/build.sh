#!/bin/bash

# Build script for compiling the project
echo "Starting build process..."

# Navigate to the root directory and compile
make clean && make all

if [ $? -eq 0 ]; then
    echo "Build successful!"
else
    echo "Build failed!"
    exit 1
fi
