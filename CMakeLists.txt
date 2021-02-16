set(CMAKE_CXX_COMPILER "/usr/bin/g++-10")
cmake_minimum_required(VERSION 3.16)
include(pico_sdk_import.cmake)
project(Audio)
# initialize the Pico SDK
pico_sdk_init()
add_subdirectory(src)