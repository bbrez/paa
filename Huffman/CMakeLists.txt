cmake_minimum_required(VERSION 3.21)
project(paa)

set(CMAKE_CXX_STANDARD 20)

include_directories(src/include)
add_executable(paa src/main.cpp
        src/FrequencyMap.cpp
        src/HuffmanCode.cpp
        src/BitWriter.cpp
        src/Compressor.cpp
        src/FileReader.cpp
        src/util.cpp src/include/util.h
        src/include/HuffmanCode.h
        src/include/BitWriter.h
        src/include/Compressor.h
        src/include/FrequencyMap.h
        src/include/FileReader.h src/BitReader.cpp src/include/BitReader.h src/Decompressor.cpp src/include/Decompressor.h)
target_compile_options(paa PRIVATE -Wall -Wextra -Wpedantic -Werror)
