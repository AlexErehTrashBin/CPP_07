cmake_minimum_required(VERSION 3.27)

########################################
# Project setup
########################################
set(PROJECT_NAME Task07)
project(${PROJECT_NAME})

########################################
# Set up the compiler flags
########################################
set(CMAKE_CXX_FLAGS "-g -Wall")
set(CMAKE_CXX_STANDARD 23)

########################################
# Define include directories
########################################
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${COMMON_INCLUDES})

########################################
# Source files
########################################
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp ${COMMON_INCLUDES})

########################################
# Main -- separate executable
########################################
list(REMOVE_ITEM SRC_FILES ${PROJECT_SOURCE_DIR}/src/main.cpp)
# Key idea: SEPARATE OUT your main() function into its own file so it can be its
# own executable. Separating out main() means you can add this library to be
# used elsewhere (e.g linking to the test executable).

########################################
# Compile source files into a library
########################################
add_library(Task07_lib ${SRC_FILES})

########################################
# Main is separate (e.g. library client)
########################################
add_executable(Task07 ${PROJECT_SOURCE_DIR}/src/main.cpp)

########################################
# linking Main against the library
########################################
target_link_libraries(Task07 Task07_lib)


add_subdirectory(./shared/googletest)
enable_testing()

#
# Include the gtest library. gtest_SOURCE_DIR is available due to
# 'project(gtest)' above.
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

########################################
# Test files
########################################
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)

########################################
# Unit Tests
########################################
add_executable(runUnitTests ${TEST_SRC_FILES})

########################################
# Standard linking to gtest stuff.
########################################
target_link_libraries(runUnitTests gtest gtest_main)

########################################
# Extra linking for the project.
########################################
target_link_libraries(runUnitTests Task07_lib)

# This is so you can do 'make test' to see all your tests run, instead of
# manually running the executable runUnitTests to see those specific tests.
add_test(UnitTests runUnitTests)
