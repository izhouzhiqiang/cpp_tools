cmake_minimum_required(VERSION 3.10)

project(mystl)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 使用正则表达式查找所有的 .cpp 文件
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/")
file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/src/*.cpp")

# 生成动态库
add_library(mystl SHARED ${SOURCES})
