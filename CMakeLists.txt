cmake_minimum_required(VERSION 3.6)
project(BookDatabase)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES useDatabase.cpp Book.h Book.cpp BookDatabase.h BookDatabase.cpp)
add_executable(BookDatabase ${SOURCE_FILES})