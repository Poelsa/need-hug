cmake_minimum_required(VERSION 3.7)

option(NH_BUILD_TEST "Check this if you want to build test project." OFF)

## Test libs
if (NH_BUILD_TEST)
	# Include HuntersGate file
	include("CMake/HunterGate.cmake")
	
	# Hunter settings
	HunterGate(
	    URL "https://github.com/ruslo/hunter/archive/v0.19.97.tar.gz"
	    SHA1 "d4fc45214ccb23a077b04ba8b50f2e8214b3a3ad"
	)
endif (NH_BUILD_TEST)

## Base project settings
project(need-hug)
set(REPOSITORY_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

## Define output folder
set(OUTPUT_FOLDER ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_FOLDER}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_FOLDER}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_FOLDER}/bin)

## Include CMake helpers
# Source group helper
if (WIN32)
	include("CMake/create_source_group.cmake")
endif (WIN32)
set(MZ_PREFIX NH_)
include("CMake/mz_project_wrapper.cmake")

## Find external cmake modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/Modules/")


## Add root as a valid include path for all projects
include_directories(${REPOSITORY_ROOT})

## Set global shared compiler options
# TODO Dont put options on global flags
if(WIN32)
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -W4 -O2 -std=c++14")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -W4 -_ITERATOR_DEBUG_LEVEL=2 -std=c++14")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE} -g -Wall -O2 -std=gnu++14 -pthread -lsfml-system")
endif()

set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_PREFIX "")

## Add folders
add_subdirectory(ext)
if(UNIX)
	find_package(SFML COMPONENTS graphics window system)
endif(UNIX)


add_subdirectory(need-hug-lib)
add_subdirectory(need-hug)


## Test settings
if (NH_BUILD_TEST)

	# Set test module naming prefix
	set(TEST_SUFFIX _test)

	# Find third party libraries using hunter
	hunter_add_package(GTest)
	find_package(GTest CONFIG REQUIRED)

	add_subdirectory(need-hug-lib-test)
endif (NH_BUILD_TEST)
