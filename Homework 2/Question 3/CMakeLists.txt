cmake_minimum_required(VERSION 3.23)
project(Question3)
set(CMAKE_CXX_STANDARD 20)
add_executable(Question3 Question3.cpp)

find_package (Threads)
target_link_libraries (Question3 Threads::Threads)
