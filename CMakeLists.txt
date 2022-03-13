cmake_minimum_required(VERSION 3.21)
project(paa)

set(CMAKE_CXX_STANDARD 20)

include_directories(src/include)
add_executable(paa src/main.cpp src/FrequencyMap.cpp src/include/FrequencyMap.h src/util.cpp src/include/util.h src/HuffmanCode.cpp src/include/HuffmanCode.h src/BitWriter.cpp src/include/BitWriter.h)
target_compile_options(paa PRIVATE -Wall -Wextra -Wpedantic)
