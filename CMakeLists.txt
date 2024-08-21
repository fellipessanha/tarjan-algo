cmake_minimum_required(VERSION 3.5.0)
project(tarjan-algo VERSION 0.1.0 LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES
    src/main.cc
    src/graph.cc
    src/node.cc
    src/util.cc
)

set(DCMAKE_EXPORT_COMPILE_COMMANDS=1)

add_executable(tarjan-algo.out ${SOURCES})

target_include_directories(tarjan-algo.out PRIVATE ${PROJECT_SOURCE_DIR}/include)