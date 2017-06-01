cmake_minimum_required(VERSION 3.7)

option(BUILD_TEST "Check this if you want to build test project." OFF)

## HunterGate settings
if (BUILD_TEST)
	# Include HuntersGate file
	include("CMake/HunterGate.cmake")
	
	# Hunter settings
	HunterGate(
	    URL "https://github.com/ruslo/hunter/archive/v0.18.39.tar.gz"
	    SHA1 "a6fbc056c3d9d7acdaa0a07c575c9352951c2f6c"
	)
endif (BUILD_TEST)

## Base project settings
project(need-hug)
set(REPOSITORY_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

## Include CMake helpers
# Source group helper
if (WIN32)
	include("CMake/create_source_group.cmake")
endif (WIN32)

## Find external libraries and modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/Modules/")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_ROOT}/Modules/")

## Require modules
# Empty at the moment

## Add root as a valid include path for all projects
include_directories(${REPOSITORY_ROOT})

## Set global shared compiler optionss
set(CMAKE_CXX_FLAGS "-g -Wall -O2 -std=gnu++14")

## Add folders
add_subdirectory(need-hug-native)

## Test settings
if (BUILD_TEST)

	# Set test module naming prefix
	set(TEST_SUFFIX _test)

	# Find third party libraries using hunter
	hunter_add_package(GTest)
	find_package(GTest CONFIG REQUIRED)

	add_subdirectory(need-hug-native-test)
endif (BUILD_TEST)
	