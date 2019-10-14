cmake_minimum_required(VERSION 3.12)
project(opencv_clion_test)

set(CMAKE_CXX_STANDARD 11)
set(OpenCV_DIR "C:\\work\\tools\\opencv\\opencv37\\build-ming64\\install")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(opencv_clion_test main.cpp)
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

# linking

target_link_libraries(opencv_clion_test ${OpenCV_LIBS})