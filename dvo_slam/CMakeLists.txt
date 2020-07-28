cmake_minimum_required(VERSION 2.8.3)

project(dvo_slam)

#LIST(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake_modules")

#find_package(catkin REQUIRED COMPONENTS roscpp dynamic_reconfigure dvo_core dvo_ros sensor_msgs image_transport message_filters cv_bridge #visualization_msgs interactive_markers message_generation geometry_msgs)
#find_package(cmake_modules REQUIRED)
#find_package(Eigen3 REQUIRED)
#find_package(G2O REQUIRED)
#find_package(sophus REQUIRED)
#find_package(Boost REQUIRED thread)
#find_package(OpenCV 2.4.8 REQUIRED)
#find_package(TBB REQUIRED)

LIST(APPEND CMAKE_CXX_FLAGS "-std=c++17")

# eigen
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

# opencv
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# pcl
set(PCL_VERSION_MAJOR "1")
set(PCL_VERSION_MINOR "11")
set(PCL_CONFIG_DIR /usr/local/share/pcl-1.11)

find_package(PCL NAMES PCL PATHS ${PCL_CONFIG_DIR} NO_DEFAULT_PATH CONFIG REQUIRED)
include_directories( ${PCL_INCLUDE_DIRS} )
link_directories(${PCL_LIBRARY_DIRS})
add_definitions( ${PCL_DEFINITIONS} )

# boost
find_package(Boost REQUIRED) # COMPONENTS iostreams

include_directories(
  "include"
  ${G2O_INCLUDE_DIR}
  ${Boost_INCLUDE_DIRS}
)

include_directories("../dvo_core/include")
set(DVO_CORE_LIB "../dvo_core/build/libdvo_core.a")
include_directories("../sophus")

set(G2O_DIR "../g2o")
include_directories(${G2O_DIR} "${G2O_DIR}/build")
file(GLOB G2O_LIBS "${G2O_DIR}/lib/*.so")

add_library(dvo_slam
  src/keyframe_tracker.cpp
  src/keyframe_graph.cpp
  src/keyframe_constraint_search.cpp
  #src/camera_keyframe_tracking.cpp
  
  src/config.cpp
  
  src/tracking_result_evaluation.cpp
  src/local_map.cpp
  src/local_tracker.cpp
  
  src/constraints/constraint_proposal.cpp
  src/constraints/constraint_proposal_voter.cpp
  src/constraints/constraint_proposal_validator.cpp
  
  #src/serialization/map_serializer_interface.cpp
  #src/serialization/map_serializer.cpp
  
  #src/visualization/graph_visualizer.cpp
  
  src/types.cpp
)

target_link_libraries(dvo_slam
  #${G2O_CORE_LIBRARY}
  #${G2O_SOLVER_DENSE}
  #${G2O_SOLVER_EIGEN}
  #${G2O_TYPES_SLAM3D}
  ${G2O_LIBS}
  ${OpenCV_LIBS} ${PCL_LIBRARIES} boost_thread tbb 
)

#add_executable(camera_keyframe_tracker
#  src/camera_keyframe_tracker_node.cpp
#)

#target_link_libraries(camera_keyframe_tracker
#  ${PROJECT_NAME}
#)

#add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}_gencfg)
