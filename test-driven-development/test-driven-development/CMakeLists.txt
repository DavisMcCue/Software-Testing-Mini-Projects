##
# @file CMakeLists.txt
# 
# Build file for FizzBuzz TDD exercise
#
# @author Michael J. Decker, Ph.D. <mdecke@bgsu.edu>
# @date Fall 2020
#

cmake_minimum_required(VERSION 2.8)

project(fizzbuzz)
add_executable(test_fizzbuzz test_fizzbuzz.cpp fizzbuzz.cpp)
