cmake_minimum_required(VERSION 3.14)
project(100known)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/include/opencv4/)
include_directories(include)

link_directories(/usr/local/lib/)

find_package(OpenCV REQUIRED)


add_subdirectory(SwitchChannel)
target_link_libraries(SwitchChannel ${OpenCV_LIBS})
add_subdirectory(GrayScale)
target_link_libraries(GrayScale ${OpenCV_LIBS})
add_subdirectory(Thresholding)
target_link_libraries(Thresholding ${OpenCV_LIBS})
add_subdirectory(OtsuThresholding)
target_link_libraries(OtsuThresholding ${OpenCV_LIBS})
add_subdirectory(SwitchHsvAndRgb)
target_link_libraries(SwitchHsvAndRgb ${OpenCV_LIBS})
add_subdirectory(ReduceColor)
target_link_libraries(ReduceColor ${OpenCV_LIBS})