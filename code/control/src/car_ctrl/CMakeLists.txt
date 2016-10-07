# Include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Dependency libraries
#find_package(OpenCV REQUIRED)

# Add libraries
set(CARCON_LIB_SRC
    # state estimator
    estimator/car_state.cpp
    # controller
    controller/kin_openloop_con.cpp
)
add_library(car_ctrl STATIC ${CARCON_LIB_SRC})
if (ENABLE_LOGGING)
  add_definitions(-DENABLE_G3LOG)
  target_link_libraries(car_ctrl logging g3logger ${LCM_LIBRARIES})
else(ENABLE_LOGGING)
  target_link_libraries(car_ctrl ${LCM_LIBRARIES})
endif (ENABLE_LOGGING)

# Add executables
#add_executable(quad_motion_client motion_server/motion_client.cpp)
#target_link_libraries(quad_motion_client ${LCM_LIBRARIES})
