cmake_minimum_required(VERSION 3.12)
project(CppJSONlize)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(test ./test.cpp)
target_include_directories(test PUBLIC ../json/include/)
target_include_directories(test PUBLIC ../include/)

