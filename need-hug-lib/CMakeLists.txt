cmake_minimum_required(VERSION 3.7)

# Root project settings
set(MODULE_NAME need-hug-lib)
project(${MODULE_NAME})

# Set the files used in the target
file(GLOB_RECURSE HEADERS include/ *.hpp)
file(GLOB_RECURSE SOURCES src/ *.cpp)

set(INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/include/ ${SFML_INCLUDE_DIR})
set(LIBRARIES $<$<CONFIG:DEBUG>:${SFML_LIBRARIES_DEBUG}> $<$<CONFIG:RELEASE>:${SFML_LIBRARIES_RELEASE}>)

# Add the target
add_library(${MODULE_NAME} STATIC ${HEADERS} ${SOURCES})
target_include_directories(${MODULE_NAME} PUBLIC "${INCLUDE_DIRECTORIES}")
target_link_libraries(${MODULE_NAME} ${LIBRARIES})

# Set compiler options for target
set(DEBUG_OPTIONS "")
set(RELEASE_OPTIONS "")
target_compile_options(${MODULE_NAME} PUBLIC "$<$<CONFIG:DEBUG>:${DEBUG_OPTIONS}>")
target_compile_options(${MODULE_NAME} PUBLIC "$<$<CONFIG:RELEASE>:${RELEASE_OPTIONS}>")