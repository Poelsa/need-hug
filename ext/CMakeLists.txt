cmake_minimum_required(VERSION 3.7)

option(SFML_BUILD_NETWORK OFF)
option(SFML_BUILD_AUDIO OFF)
option(SFML_USE_STATIC_STD_LIBS OFF)

if(WIN32)
	set(SFML_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/ext/SFML/include" CACHE PATH "" FORCE)
	# set(SFML_LIBRARIES sfml-graphics.lib sfml-system.lib sfml-window.lib CACHE PATH "" FORCE) # TODO meraz
	
	add_subdirectory(SFML)
	add_subdirectory(googletest)

else()
	add_subdirectory(googletest)
	find_package(SFML REQUIRED COMPONENTS graphics window system)
endif(WIN32)
