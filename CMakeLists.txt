cmake_minimum_required(VERSION 3.23) #CMAKE version
project(HelloWorld) # Project name, could be anything
set(CMAKE_CXX_STANDARD 20) #C++ version
include_directories(${CMAKE_SOURCE_DIR}) #Takes care of header file
add_executable(aersp_424 main.cpp) # tells CMAKE to use all .cpp and .h files to build a binary file
