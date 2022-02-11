cmake_minimum_required(VERSION 2.8)
project(my_stl)

# Put the build information in the directory that uses it

#Enables testing for this directoyr and below
#enable_testing()
# enables creations/submission of dashbards (cdash).  Calls enable_testing()
include(CTest)

option(BUILD_UNIT_TESTS "Build unit tests for my_stl" OFF)

# include/link search path
include_directories(src/set/ src/stack src/string)
#link_directories(/usr/local/lib)

# for current directory and below
add_definitions(-fPIC -std=c++0x -g -O0)

# will need to use foo or something as do not have permission to install
set(CMAKE_INSTALL_PREFIX "/usr/local")

add_subdirectory(src)

# BULID_TESTING will avoid building them, but if do not want them in ctest (not reported as not run)
if(BUILD_UNIT_TESTS)
    add_subdirectory(test)
endif()

# Simple cpack, then show srcML version
set(CPACK_PACKAGE_NAME "my_stl") 
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
# needs to be last...
include(CPack)
