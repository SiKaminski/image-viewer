cmake_minimum_required(VERSION 3.24)
project(cpp-image-viewer VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED)

add_executable(cpp-image-viewer
    src/main.cpp
)

target_link_libraries(cpp-image-viewer PRIVATE SDL3::SDL3)

target_compile_options(cpp-image-viewer PRIVATE -Wall -Wextra -Wpedantic)
