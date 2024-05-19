cmake_minimum_required(VERSION 3.10)
project(SongLyricSearchEngine)

# Default values for the test flag and main source file
set(TEST 0 CACHE STRING "Test flag")
set(MAIN src/main.cpp CACHE STRING "Main source file")

set(DEPENDENCIES
        # src/SearchEngine.cpp
        src/SearchEngineConfig.cpp
)

# Define the include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Define the base source files
set(PREREQ ${MAIN} ${DEPENDENCIES})

# Add the executable target
add_executable(${PROJECT_NAME} ${PREREQ})

# Ensure the correct C++ standard is used
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
)

# Add a custom target to run tests, if needed
add_custom_target(run_tests
    COMMAND ${PROJECT_NAME} ${TEST}
    DEPENDS ${PROJECT_NAME}
    COMMENT "Running tests with test flag ${TEST}"
)

# Include GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Add test source files
set(TEST_SOURCES
    TestCases/testcase01.cpp
)

# Create test executable
add_executable(runUnitTests ${TEST_SOURCES} ${DEPENDENCIES})

# Link test executable against GoogleTest
target_link_libraries(runUnitTests gtest gtest_main)

# Discover tests
include(GoogleTest)
gtest_discover_tests(runUnitTests)
