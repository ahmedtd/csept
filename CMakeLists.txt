
# Specify the minimum version of CMake required to compile csept.
# Fail if the installed cmake version isn't at least 2.6
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

# Activate testing for the project
enable_testing()

# Give our project a name
project(csept)

# Set up some options before we try to find the boost libraries
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

# Try to find boost 1.46.0.  The REQUIRED keyword specifies that the build
# process should stop if a matching boost installation is not found
find_package( Boost 1.46.0 REQUIRED date_time unit_test_framework)

# Add the boost include directories to the common include directories for all
# executables
include_directories(${Boost_INCLUDE_DIRS})

# Enable pre-, post-, and invariant-tests if the option is set
set(CSEPT_PPI_TESTS ON CACHE BOOL "Compile pre-, post-, and invariant-tests")

# Perform configuration on config.h.in to enable or disable the testing
# preprocessor macros as specified above
configure_file(config.hpp.in config.hpp)

# Include the current binary directory, since this is where config.hpp is dumped
# by cmake
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# Enable unit testing by default
set(CSEPT_UNIT_TESTS ON CACHE BOOL "Compile unit tests")

# If unit testing is enabled, define a unit testing convenience function, and
# add all unit tests registered in the unittest subdirectory
if(CSEPT_UNIT_TESTS)
  add_subdirectory(unittest)
endif()
