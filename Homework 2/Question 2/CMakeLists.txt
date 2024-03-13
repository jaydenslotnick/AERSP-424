cmake_minimum_required(VERSION 3.23)
project(Question2)
set(CMAKE_CXX_STANDARD 20)
add_executable(Question2 Question2.cpp)

find_package (Threads)
target_link_libraries (Question2 Threads::Threads)
