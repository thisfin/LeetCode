cmake_minimum_required(VERSION 3.17)
project(LeetCode)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(src DIR_SRCS) # 扫描目录

add_executable(LeetCode main.cpp ${DIR_SRCS})
