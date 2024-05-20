# Zach Sally
# 5/19/2024
#
# ============
# | makefile |
# ============
#
###############################################################################
# SUMMARY: 
#
#   makefile used to compile the search engine program manually without CMake.
#   
#   DEPRECATED: This makefile is no longer used for building the project. It is
#   only used for running quick individual test cases in different main files.
#
###############################################################################
# TO RUN:
#
#   Within top-level directory, run the following command:
#
#	  make [MAIN=MAIN_FILE] [TEST=TEST_Number]
#
#    MAIN_FILE: The main file to compile. Default is src/main.cpp.
#    TEST_Number: The test number to compile. Default is 0.
#
###############################################################################
# USAGE:
#
#   This makefile is primarily used to run the search engine program manually
#   without CMake. This is useful for running individual test cases isolated from
#   the rest of the project rather than building and running entire project.
#
###############################################################################

###############################################################################
# Initialization
###############################################################################
TEST ?= 0
MAIN ?= src/main.cpp

###############################################################################
# Define Include Directory
###############################################################################
INCLUDE_DIR = -I./include

###############################################################################
# Define Dependencies
###############################################################################
PREREQ = $(MAIN)

# Conditionally add source files to BASE_SRC
ifeq ($(TEST), 0)
    PREREQ += src/SearchEngineConfig.cpp
endif

# Conditionally add source files to BASE_SRC
ifeq ($(TEST), 01)
    PREREQ += src/SearchEngineConfig.cpp
endif

###############################################################################
# Target Executable
###############################################################################
TARGET = engine

###############################################################################
# Compile Target
###############################################################################
$(TARGET): $(PREREQ)
	g++ $(INCLUDE_DIR) -o $@ $^

###############################################################################
# Clean Target
###############################################################################
clean:
	rm -f $(TARGET)
