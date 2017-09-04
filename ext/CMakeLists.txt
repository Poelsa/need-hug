cmake_minimum_required(VERSION 3.7)


## SFML paths and libs
set(SFML_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/SFML/include)
set(SFML_OUTPUT_FOLDER ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
if(WIN32)
	set(SFML_OUTPUT_FOLDER ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}$<$<CONFIG:DEBUG>:/debug>$<$<CONFIG:RELEASE>:/release>)
endif()

if(WIN32)
	set(SFML_LIBRARIES_DEBUG ${SFML_OUTPUT_FOLDER}/sfml-system-d.lib ${SFML_OUTPUT_FOLDER}/sfml-graphics-d.lib  ${SFML_OUTPUT_FOLDER}/sfml-window-d.lib)
	set(SFML_LIBRARIES_RELEASE ${SFML_OUTPUT_FOLDER}/sfml-system.lib ${SFML_OUTPUT_FOLDER}/sfml-graphics.lib  ${SFML_OUTPUT_FOLDER}/sfml-window.lib)
else()
	set(SFML_LIBRARIES_DEBUG ${SFML_OUTPUT_FOLDER}/sfml-system.a ${SFML_OUTPUT_FOLDER}/sfml-graphics.a ${SFML_OUTPUT_FOLDER}/sfml-window.a)
	set(SFML_LIBRARIES_RELEASE ${SFML_OUTPUT_FOLDER}/sfml-system.a ${SFML_OUTPUT_FOLDER}/sfml-graphics.a  ${SFML_OUTPUT_FOLDER}/sfml-window.a)
endif()


option(SFML_BUILD_NETWORK OFF)
option(SFML_BUILD_AUDIO OFF)
option(SFML_USE_STATIC_STD_LIBS OFF)

add_subdirectory(SFML)