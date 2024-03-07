cmake_minimum_required(VERSION 3.23)
project(Question1)
set(CMAKE_CXX_STANDARD 20)
add_executable(Question1 Question1.cpp Sensor.h Velocity.h Temperature.h Pressure.h SensorFactory.h AerospaceControlSystem.h)
