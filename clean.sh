#!/bin/bash
#
# Script to clean the tree from all compiled files.

cd `dirname $0`

# Remove the dedicated output directories
rm -rf build/*
rm -rf bin/*

# We're done!
echo Cleaned up the project!
