#!/bin/bash
#
# Go into the directory where this bash script is contained.
cd `dirname $0`

# Clean
./clean.sh

# Compile
mkdir -p build
cd build
cmake ..
make $*
