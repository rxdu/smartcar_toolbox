# Include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../vrep_sim/vrep_lib/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../vrep_sim/vrep_lib/remoteApi)

# Dependency libraries
#find_package(OpenCV REQUIRED)

# Add libraries
set(CARSIM_LIB_SRC
    car_sim_client.cpp
    car_sim_controller.cpp
)
add_library(carsim STATIC ${CARSIM_LIB_SRC})
if (ENABLE_LOGGING)
	add_definitions(-DNON_MATLAB_PARSING -DMAX_EXT_API_CONNECTIONS=255 -DENABLE_G3LOG)
	target_link_libraries(carsim vrep_sim car_ctrl logging ${LCM_LIBRARIES})
else (ENABLE_LOGGING)
	add_definitions(-DNON_MATLAB_PARSING -DMAX_EXT_API_CONNECTIONS=255)
	target_link_libraries(carsim vrep_sim car_ctrl ${LCM_LIBRARIES})
endif (ENABLE_LOGGING)

