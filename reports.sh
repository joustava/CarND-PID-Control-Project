#!/bin/bash
# Script to generate Cppcheck reports.
#
# Go into the directory where this bash script is contained.
cd `dirname $0`

cppcheck --enable=all --inconclusive --library=posix -I ./include/ ./src ./app --xml 2> ./reports/errors.xml
cppcheck-htmlreport --file=./reports/errors.xml --report-dir=./reports --source-dir=. --title=PID_Controller
open ./reports/index.html