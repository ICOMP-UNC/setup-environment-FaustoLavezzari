cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project(
    "Static_C_Lib"
    VERSION 1.0.0
    DESCRIPTION "CMake C project simple static library"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 17)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.c")

add_library(${PROJECT_NAME} STATIC ${SOURCES})