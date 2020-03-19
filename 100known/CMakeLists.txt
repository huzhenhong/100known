cmake_minimum_required(VERSION 3.14)
project(100known)

set(CMAKE_CXX_STANDARD 14)

include_directories(include/)
include_directories(/usr/local/include/opencv4/)

link_directories(/usr/local/lib/)

find_package(OpenCV REQUIRED)


add_subdirectory(SwitchChannel)
target_link_libraries(SwitchChannel ${OpenCV_LIBS})
add_subdirectory(GrayScale)
target_link_libraries(GrayScale ${OpenCV_LIBS})