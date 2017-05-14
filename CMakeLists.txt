cmake_minimum_required( VERSION 2.8 ) 
project( integrator )

add_definitions( -std=gnu++11 )

set( CMAKE_MODULE_PATH  ${CMAKE_CURRENT_SOURCE_DIR}/../cmake-modules )   
find_package( Eigen3 REQUIRED )
find_package( MathGL2 2.0.0 REQUIRED )
find_package( Figure REQUIRED )

message(STATUS "${EIGEN_INCLUDE_DIR}")

include_directories( ${EIGEN_INCLUDE_DIR} ${MATHGL2_INCLUDE_DIRS} ${FIGURE_INCLUDE_DIR} )
add_executable( ${PROJECT_NAME} main.cpp )
target_link_libraries( ${PROJECT_NAME} ${MATHGL2_LIBRARIES} ${FIGURE_LIBRARY} )

