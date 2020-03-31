cmake_minimum_required(VERSION 3.14)
project(100known)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/include/opencv4/)
include_directories(include)

link_directories(/usr/local/lib/)

find_package(OpenCV REQUIRED)


add_subdirectory("01_SwitchChannel")
target_link_libraries("01_SwitchChannel" ${OpenCV_LIBS})
add_subdirectory("02_GrayScale")
target_link_libraries("02_GrayScale" ${OpenCV_LIBS})
add_subdirectory("03_Thresholding")
target_link_libraries("03_Thresholding" ${OpenCV_LIBS})
add_subdirectory("04_OtsuThresholding")
target_link_libraries("04_OtsuThresholding" ${OpenCV_LIBS})
add_subdirectory("05_SwitchHsvAndRgb")
target_link_libraries("05_SwitchHsvAndRgb" ${OpenCV_LIBS})
add_subdirectory("06_ReduceColor")
target_link_libraries("06_ReduceColor" ${OpenCV_LIBS})
add_subdirectory("07_AveragePooling")
target_link_libraries("07_AveragePooling" ${OpenCV_LIBS})
add_subdirectory("08_MaxPooling")
target_link_libraries("08_MaxPooling" ${OpenCV_LIBS})