cmake_minimum_required(VERSION 3.5)
set(CMAKE_OSX_ARCHITECTURES "x86_64" CACHE STRING "" FORCE)
project(CarFactory)
list(APPEND CMAKE_FRAMEWORK_PATH /Library/Frameworks)
set(CMAKE_CXX_STANDARD 11)

find_package(Imagine REQUIRED COMPONENTS Graphics)

add_executable(CarFactory
               idle.cpp
               business.cpp business.h
               manufacture.cpp manufacture.h
               utils.h utils.cpp
               graphics.h graphics.cpp)
target_link_libraries(CarFactory Imagine::Graphics)
