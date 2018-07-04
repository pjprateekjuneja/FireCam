cmake_minimum_required(VERSION 2.8.12)

project(demo)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
SET ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )
add_executable(demo firstcv.cpp bgextract.cpp bgextract.h canfil.cpp canfil.h grafil.cpp grafil.h help.cpp help.h negfil.cpp negfil.h sepfil.cpp sepfil.h static_pic.cpp static_pic.h videosurv.cpp videosurv.h videocap.cpp videocap.h frameconv.cpp frameconv.h)
target_link_libraries(demo -lpthread -lm ${OpenCV_LIBS})   
