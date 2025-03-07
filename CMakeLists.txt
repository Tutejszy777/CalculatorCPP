cmake_minimum_required(VERSION 3.10.0)
project(Calculator VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Calculator main.cpp input.cpp)


include(CTest)
enable_testing()
