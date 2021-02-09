#!/bin/bash
# Script to generate documentation.
#
# Go into the directory where this bash script is contained.
cd `dirname $0`

doxygen Doxyfile
open docs/html/index.html