cmake_minimum_required(VERSION 3.15)
project(MyDB LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# // Add main source files
add_executable(juliedb
    src/main.cpp
    src/storage/pager.cpp
)

target_include_directories(juliedb PRIVATE ${CMAKE_SOURCE_DIR}/src)
