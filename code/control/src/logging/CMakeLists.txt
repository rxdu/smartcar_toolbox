# Include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Dependency libraries
#find_package(OpenCV REQUIRED)

# Add libraries
set(LOGGING_LIB_SRC
    # logging
    logging_helper.cpp
)
add_library(logging STATIC ${LOGGING_LIB_SRC})
target_link_libraries(logging g3logger ${LCM_LIBRARIES})
    
# Add executables
add_executable(test_logging tests/test_logging.cpp)
target_link_libraries(test_logging logging -pthread)
