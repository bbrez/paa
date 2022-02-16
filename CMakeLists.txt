cmake_minimum_required(VERSION 3.21)
project(paa)

set(CMAKE_CXX_STANDARD 20)

add_executable(paa main.cpp FrequencyMap.cpp FrequencyMap.h util.cpp util.h)
