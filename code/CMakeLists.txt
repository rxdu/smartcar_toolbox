cmake_minimum_required(VERSION 2.8.11)
project(smartcar_toolbox)

#list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

## Put all binary files into /bin and libraries into /lib
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

## Choose to enable g3log or not: on/off
set(ENABLE_G3LOG off)

if(ENABLE_G3LOG)
	message( "-- Enable logging with g3log -- Yes" )
	message( "-- Deafult log directory: srcl_ctrl/control/log " )
	include_directories(${CMAKE_SOURCE_DIR}/libraries/g3log_srcl/src)
else(ENABLE_G3LOG)
	message( "-- Enable logging with g3log -- No" )
endif(ENABLE_G3LOG)

set(BUILD_TESTS off)

## Config eigen include directories
include_directories(${CMAKE_SOURCE_DIR}/libraries/)

## Add source directories
add_subdirectory(control)
add_subdirectory(libraries)
