cmake_minimum_required(VERSION 3.7)

project(need-hug CXX)

## TODO meraz
option(NH_BUILD_TEST "Check this if you want to build test project." OFF)

## TODO meraz
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a;.so;.lib;.dll")
set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_PREFIX "")

set(CXX_STANDARD_REQUIRED ON)

## Test settings
if(NH_BUILD_TEST)
	set(NH_TEST_SUFFIX _test) # Set test module naming prefix
endif(NH_BUILD_TEST)

## Base project settings
set(REPOSITORY_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

## Define output folder
set(OUTPUT_FOLDER ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_FOLDER}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_FOLDER}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_FOLDER}/bin)

## Include CMake helpers
# Source group helper
if(WIN32)
	include("CMake/create_source_group.cmake")
endif(WIN32)
set(MZ_PREFIX NH_)
include("CMake/mz_project_wrapper.cmake")

## Find external cmake modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/Modules/")

## Add root as a valid include path for all projects
include_directories(${REPOSITORY_ROOT}) # TODO meraz, maybe not keep this.

## Set global shared compiler options
# TODO Dont put options on global flags
if(WIN32)
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -W4 -O2")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -W4 -_ITERATOR_DEBUG_LEVEL=2")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE} -g -Wall -O2 -std=gnu++14 -pthread -lsfml-system")
endif()

## Add 3pps
add_subdirectory(ext)

## TODO meraz
# enable_testing()

## TODO meraz
add_subdirectory(need-hug-lib)
add_subdirectory(need-hug)
