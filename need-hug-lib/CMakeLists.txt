cmake_minimum_required(VERSION 3.7)

# Root project settings
get_filename_component(FOLDER_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(MODULE_NAME ${FOLDER_NAME})
project(${MODULE_NAME})

# Include
set(EXTERNAL_INCLUDE_DIRECTORIES ${SFML_INCLUDE_DIR})

# Libraries
set(INTERNAL_LIBRARIES "")
set(EXTERNAL_LIBRARIES sfml-graphics sfml-system sfml-window)

# Set compiler options for target
set(DEBUG_OPTIONS "")
set(RELEASE_OPTIONS "")
set(COMPILE_OPTIONS $<$<CONFIG:DEBUG>:${DEBUG_OPTIONS}> $<$<CONFIG:RELEASE>:${RELEASE_OPTIONS}>)

mz_add_library("${MODULE_NAME}" STATIC "${CMAKE_CURRENT_SOURCE_DIR}" "${COMPILE_OPTIONS}" "${INTERNAL_LIBRARIES}" "${EXTERNAL_LIBRARIES}" "${EXTERNAL_INCLUDE_DIRECTORIES}")

################### TEST
if(NH_BUILD_TEST)

	# Root project settings
	set(MODULE_NAME_TEST ${MODULE_NAME}${NH_TEST_SUFFIX})
	project(${MODULE_NAME_TEST})

	# Include
	set(EXTERNAL_INCLUDE_DIRECTORIES "")

	# Libraries
	set(INTERNAL_LIBRARIES ${MODULE_NAME})
	set(EXTERNAL_LIBRARIES gtest_main)

	# Set compiler options for target
	set(DEBUG_OPTIONS "")
	set(RELEASE_OPTIONS "")
	set(COMPILE_OPTIONS $<$<CONFIG:DEBUG>:${DEBUG_OPTIONS}> $<$<CONFIG:RELEASE>:${RELEASE_OPTIONS}>)

	mz_add_executable_test("${MODULE_NAME_TEST}" "${CMAKE_CURRENT_SOURCE_DIR}" "${COMPILE_OPTIONS}" "${INTERNAL_LIBRARIES}" "${EXTERNAL_LIBRARIES}" "${EXTERNAL_INCLUDE_DIRECTORIES}")

endif(NH_BUILD_TEST)

#include json lib
add_library(json INTERFACE)
target_include_directories(json INTERFACE ${REPOSITORY_ROOT}/ext/json/)
target_sources(json INTERFACE ${REPOSITORY_ROOT}/ext/json/json.hpp)
target_link_libraries(${MODULE_NAME} json)
target_link_libraries(${MODULE_NAME_TEST} json)