# Minimum version can be no higher than 3.5 as Ubuntu package management uses this version.
cmake_minimum_required(VERSION 3.5)

project (EX06-Zipcode)

set(SOURCE_PREFIX "zipcode")
set(EXEC_NAME "Zipcode")
set(CMAKE_CXX_STANDARD 11)

if(EXISTS ${CMAKE_HOME_DIRECTORY}/cs140/CMakeLists.txt)
    include(cs140/CMakeLists.txt)
else()
    add_custom_target(submodule-init ALL git submodule init COMMAND git submodule update --recursive WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
endif()