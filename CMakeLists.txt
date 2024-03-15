cmake_minimum_required(VERSION 3.5.0)
project(technical_test_sim_cure)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(technical_test_sim_cure word_mapping.cpp main.cpp)