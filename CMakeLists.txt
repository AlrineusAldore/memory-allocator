cmake_minimum_required(VERSION 3.26)
project(MemoryAllocator)

set(CMAKE_C_STANDARD 23)

file(GLOB_RECURSE MY_FILES src/*.c)

add_executable(MemoryAllocator ${MY_FILES})