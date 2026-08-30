cmake_minimum_required(VERSION 3.16)
project(yetanotherSLAM LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

add_executable(slam
        src/main.cpp
        src/dataset.cpp
        include/slam/main.h
)

target_include_directories(slam PRIVATE
        include
        ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(slam PRIVATE
        ${OpenCV_LIBS}
        Eigen3::Eigen
)

add_executable(orb_compare
        include/slam/ORB_compare.cpp
        include/slam/ORB_compare.h
)

target_include_directories(orb_compare PRIVATE
        include
        ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(orb_compare PRIVATE
        ${OpenCV_LIBS}
        Eigen3::Eigen
)