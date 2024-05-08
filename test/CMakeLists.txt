
cmake_minimum_required(VERSION 3.10)  # 指定CMake的最低版本要求

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(TEST)              # 定义项目名称

# 使用正则表达式查找所有cpp文件
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/")
file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/src/*.cpp")

# 添加可执行文件，使用找到的源文件
add_executable(a.out ${SOURCES})

# 添加一个自定义命令，在目标构建完成后执行
add_custom_command(
  TARGET a.out
  POST_BUILD
  COMMAND echo "test output:"
  COMMAND echo "------------------------------"
  COMMAND $<TARGET_FILE:a.out>
  COMMAND echo "------------------------------"
  COMMENT "Running test as part of the build process"
)
