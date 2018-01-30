cmake_minimum_required(VERSION 3.7)

if(NOT MZ_PREFIX)
	set(MZ_PREFIX MZ_)
endif()

function(mz_add_executable EXECUTABLE_NAME PATH COMPILE_OPTIONS INTERNAL_DEPENDENCIES EXTERNAL_DEPENDENCIES EXTERNAL_INCLUDE_PATHS)

	set(${MZ_PREFIX}${EXECUTABLE_NAME}_INCLUDE ${PATH}/include CACHE PATH "Include path for module: ${EXECUTABLE_NAME}" FORCE)

	file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)
	file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

	if(WIN32)
		create_source_group("Header Files" "${PATH}/include" ${HEADERS})
		create_source_group("Source Files" "${PATH}/src" ${SOURCES})
	endif(WIN32)

	set(INCLUDE_DIRECTORIES ${PATH}/include/)
	set(LIBRARIES "${LIBRARIES}" "${EXTERNAL_DEPENDENCIES}")

	foreach(INTERNAL_DEPENDENCY ${INTERNAL_DEPENDENCIES})
		set(INCLUDE_DIRECTORIES "${INCLUDE_DIRECTORIES}" ${${INTERNAL_DEPENDENCY}_INCLUDE})
		set(LIBRARIES "${LIBRARIES}" ${INTERNAL_DEPENDENCY})
	endforeach()

	foreach(EXTERNAL_DEPENDENCY_PATH ${EXTERNAL_INCLUDE_PATHS})
		set(INCLUDE_DIRECTORIES "${INCLUDE_DIRECTORIES}" ${EXTERNAL_DEPENDENCY_PATH})
	endforeach()

	add_executable(${EXECUTABLE_NAME} ${HEADERS} ${SOURCES})
	target_include_directories(${EXECUTABLE_NAME} PUBLIC "${INCLUDE_DIRECTORIES}")
	target_link_libraries(${EXECUTABLE_NAME} ${LIBRARIES})
	target_compile_options(${EXECUTABLE_NAME} PUBLIC "${COMPILE_OPTIONS}")
endfunction(mz_add_executable)

function(mz_add_executable_test EXECUTABLE_NAME PATH COMPILE_OPTIONS INTERNAL_DEPENDENCIES EXTERNAL_DEPENDENCIES EXTERNAL_INCLUDE_PATHS)

	set(${MZ_PREFIX}${EXECUTABLE_NAME}_INCLUDE ${PATH}/test-src CACHE PATH "Include path for module: ${EXECUTABLE_NAME}" FORCE)

	file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/test-src/*.hpp)
	file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test-src/*.cpp)

	if(WIN32)
		create_source_group("Header Files" "test-src" "${HEADERS}")
		create_source_group("Source Files" "test-src" "${SOURCES}")
	endif(WIN32)

	set(INCLUDE_DIRECTORIES ${PATH}/test-src/)
	set(LIBRARIES "${LIBRARIES}" "${EXTERNAL_DEPENDENCIES}")

	foreach(INTERNAL_DEPENDENCY ${INTERNAL_DEPENDENCIES})
		set(INCLUDE_DIRECTORIES "${INCLUDE_DIRECTORIES}" ${${INTERNAL_DEPENDENCY}_INCLUDE})
		set(LIBRARIES "${LIBRARIES}" ${INTERNAL_DEPENDENCY})
	endforeach()

	foreach(EXTERNAL_DEPENDENCY_PATH ${EXTERNAL_INCLUDE_PATHS})
		set(INCLUDE_DIRECTORIES "${INCLUDE_DIRECTORIES}" ${EXTERNAL_DEPENDENCY_PATH})
	endforeach()

	add_executable(${EXECUTABLE_NAME} ${HEADERS} ${SOURCES})
	target_include_directories(${EXECUTABLE_NAME} PUBLIC "${INCLUDE_DIRECTORIES}")
	target_link_libraries(${EXECUTABLE_NAME} ${LIBRARIES})
	target_compile_options(${EXECUTABLE_NAME} PUBLIC "${COMPILE_OPTIONS}")
endfunction(mz_add_executable_test)

function(mz_add_library LIBRARY_NAME LIBRARY_TYPE PATH COMPILE_OPTIONS INTERNAL_DEPENDENCIES EXTERNAL_DEPENDENCIES EXTERNAL_INCLUDE_PATHS)

	set(${MZ_PREFIX}${LIBRARY_NAME}_INCLUDE ${PATH}/include CACHE PATH "Include path for module: ${LIBRARY_NAME}" FORCE)

	file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)
	file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

	if(WIN32)
		create_source_group("Header Files" "${PATH}/include" ${HEADERS})
		create_source_group("Source Files" "${PATH}/src" ${SOURCES})
	endif(WIN32)

	set(INCLUDE_DIRECTORIES ${PATH}/include/)
	set(LIBRARIES "${LIBRARIES}" "${EXTERNAL_DEPENDENCIES}")

	foreach(INTERNAL_DEPENDENCY ${INTERNAL_DEPENDENCIES})
		set(INCLUDE_DIRECTORIES "${INCLUDE_DIRECTORIES}" ${${INTERNAL_DEPENDENCY}_INCLUDE})
		set(LIBRARIES "${LIBRARIES}" ${INTERNAL_DEPENDENCY})
	endforeach()

	foreach(EXTERNAL_DEPENDENCY_PATH ${EXTERNAL_INCLUDE_PATHS})
		set(INCLUDE_DIRECTORIES "${INCLUDE_DIRECTORIES}" ${EXTERNAL_DEPENDENCY_PATH})
	endforeach()

	add_library(${LIBRARY_NAME} ${LIBRARY_TYPE} ${HEADERS} ${SOURCES})
	target_include_directories(${LIBRARY_NAME} PUBLIC "${INCLUDE_DIRECTORIES}")
	target_link_libraries(${LIBRARY_NAME} ${LIBRARIES})
	target_compile_options(${LIBRARY_NAME} PUBLIC "${COMPILE_OPTIONS}")
endfunction(mz_add_library)