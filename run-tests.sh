#!/bin/bash

###############################################################################
#
# run-tests.sh
#
# A bash script to run the tests for the SongLyricSearchEngine project.
#
# To run:
#
#    bash run-tests.sh
#
###############################################################################

cd build/

source ./set-env.sh

ctest

cd ..