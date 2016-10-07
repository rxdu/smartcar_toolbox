# Include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src/vrep_sim/vrep_lib/include)
include_directories(${PROJECT_SOURCE_DIR}/src/vrep_sim/vrep_lib/remoteApi)

# Add executables
add_executable(carsim_demo carsim_demo.cpp)
if(ENABLE_LOGGING)
    target_link_libraries(carsim_demo carsim logging)
else(ENABLE_LOGGING)
    target_link_libraries(carsim_demo carsim)
endif(ENABLE_LOGGING)