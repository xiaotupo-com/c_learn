# 指定 CMake 最低版本
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(array_and_pointer)

aux_source_directory(Src src_dir)

add_executable(${PROJECT_NAME} ${src_dir})