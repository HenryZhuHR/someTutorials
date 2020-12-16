cmake_minimum_required(VERSION 3.19)
project(main)

include_directories("./include")

set(DIR_SRCS main.cpp LinkedList.cpp)

add_executable(main ${DIR_SRCS})