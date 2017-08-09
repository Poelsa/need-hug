cmake_minimum_required(VERSION 3.7)

# Set names
set(NAME_OF_TEST_MODULE need-hug-lib)
set(MODULE_NAME ${NAME_OF_TEST_MODULE}${TEST_SUFFIX})
project(${MODULE_NAME})

# Find files
file(GLOB_RECURSE HEADERS include/ *.hpp)
file(GLOB_RECURSE SOURCES src/ *.cpp)

# Set include directories and libraries
set(INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/include/)
set(LIBRARIES ${NAME_OF_TEST_MODULE} GTest::main)

# Add the target
add_executable(${MODULE_NAME} ${HEADERS} ${SOURCES})
target_link_libraries(${MODULE_NAME} ${LIBRARIES})
target_include_directories(${MODULE_NAME} PUBLIC ${INCLUDE_DIRECTORIES})

# Set compiler options for target
set(DEBUG_OPTIONS "")
set(RELEASE_OPTIONS "")
target_compile_options(${MODULE_NAME} PUBLIC "$<$<CONFIG:DEBUG>:${DEBUG_OPTIONS}>")
target_compile_options(${MODULE_NAME} PUBLIC "$<$<CONFIG:RELEASE>:${RELEASE_OPTIONS}>")