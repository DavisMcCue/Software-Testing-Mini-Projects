##
# @file CMakeLists.txt
# 
# Build file for test calculator mocking exercise
#
# @author Michael J. Decker, Ph.D. <mdecke@bgsu.edu>
# @date Fall 2020
#

cmake_minimum_required(VERSION 2.8)

project(mocking_calculator)
include_directories(/usr/local/include)

add_executable(test_calculator test_calculator.cpp)
