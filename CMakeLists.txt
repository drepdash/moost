project(test_moost)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#set(CMAKE_VERBOSE_MAKEFILE True)
set(CMAKE_COLOR_MAKEFILE True)

if (UNIX)
	add_definitions("-std=c++11 -W -Wall")
endif (UNIX)

add_subdirectory(moost)
add_subdirectory(test)
