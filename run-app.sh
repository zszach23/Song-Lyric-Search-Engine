#!/bin/bash

###############################################################################
#
# run-app.sh
#
# A bash script to run the SongLyricSearchEngine application.
#
# To run:
#
#    bash run-tests.sh
#
###############################################################################

cd build/

source ./set-env.sh

# Run the app
./SongLyricSearchEngine

cd ..