cmake_minimum_required(VERSION 2.8.11)
project(smartcar_toolbox_libraries)

## Conditionally add source directories
if(ENABLE_LOGGING)
	add_subdirectory(g3log)
endif(ENABLE_LOGGING)

if(BUILD_TESTS)
	add_subdirectory(googletest)
endif(BUILD_TESTS)

## Add other source directories
#add_subdirectory(eigen)
