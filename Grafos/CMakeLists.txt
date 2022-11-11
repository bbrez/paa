cmake_minimum_required(VERSION 3.22)
project(paa2)

set(CMAKE_CXX_STANDARD 20)

include_directories(src/include)
add_executable(paa2 src/main.cpp
    src/Aresta.cpp  src/include/Aresta.h
    src/Vertice.cpp src/include/Vertice.h
    src/Grafo.cpp   src/include/Grafo.h
    src/GrafoNaoOrientado.cpp   src/include/GrafoNaoOrientado.h
    src/GrafoOrientado.cpp  src/include/GrafoOrientado.h
        src/util.cpp src/include/util.h)

target_compile_options(paa2 PRIVATE -Wall -Wextra -Wpedantic)
