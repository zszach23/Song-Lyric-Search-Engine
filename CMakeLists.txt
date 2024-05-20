################################################################################
# Initialize CMake
################################################################################

cmake_minimum_required(VERSION 3.10)
project(SongLyricSearchEngine)

# Define the include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

################################################################################
# Define Environment Variables
################################################################################

set(CONFIG_FILE ${CMAKE_SOURCE_DIR}/config.json)

# Generate a script to set environment variables for the runtime environment
configure_file(
  "${CMAKE_SOURCE_DIR}/set-env.sh.in"
  "${CMAKE_BINARY_DIR}/set-env.sh"
  @ONLY
)

################################################################################
# Define Dependencies
################################################################################

# Default main source file
set(MAIN src/main.cpp CACHE STRING "Main Source File (Driver)")

set(DEPENDENCIES
        # src/SearchEngine.cpp
        src/SearchEngineConfig.cpp
)

# Define the base source files
set(PREREQ ${MAIN} ${DEPENDENCIES})

################################################################################
# Create Executable Target
################################################################################

# Add the executable target
add_executable(${PROJECT_NAME} ${PREREQ})

# Ensure the correct C++ standard is used
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
)

################################################################################
# Add GoogleTest
################################################################################

# Include GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

################################################################################
# Define Tests
################################################################################

enable_testing()

# Add test source files
set(TEST_SOURCES
    ${CMAKE_SOURCE_DIR}/TestCases/testcase01.cpp
)

################################################################################
# Create Test Executable Target
################################################################################

# Create test executable
add_executable(runUnitTests ${TEST_SOURCES} ${DEPENDENCIES})

################################################################################
# Link GoogleTest to Test Executable
################################################################################

# Link test executable against GoogleTest
target_link_libraries(runUnitTests gtest gtest_main)

# Discover tests
include(GoogleTest)
gtest_discover_tests(runUnitTests)
