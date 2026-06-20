cmake_minimum_required(VERSION 3.16)
project(yetanotherSLAM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew")

find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)

add_executable(yetanotherSLAM src/main.cpp)
add_executable(rotation3d src/3d_rotation.cpp)
add_executable(rotation_eigen src/3d_rotation_with_eigen.cpp)
add_executable(extrinsic_camera_matrix src/extrinsic_camera_matrix.cpp)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(yetanotherSLAM Eigen3::Eigen ${OpenCV_LIBS})
target_link_libraries(rotation3d Eigen3::Eigen ${OpenCV_LIBS})
target_link_libraries(extrinsic_camera_matrix Eigen3::Eigen ${OpenCV_LIBS})

