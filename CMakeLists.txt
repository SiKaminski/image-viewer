cmake_minimum_required(VERSION 3.24)
project(cpp-image-viewer VERSION 1.0 LANGUAGES CXX)
find_package(SDL3 CONFIG QUIET)

if(NOT SDL3_FOUND)
    message(STATUS "SDL3 not found... Building from source")
    include(FetchContent)
    FetchContent_Declare(
        SDL
        GIT_REPOSITORY https://github.com/libsdl-org/SDL
        GIT_TAG "release-3.2.16"
    )
    FetchContent_MakeAvailable(SDL)
else()
    find_package(SDL3 REQUIRED)
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp-image-viewer
    src/main.cpp
)

target_include_directories(cpp-image-viewer PRIVATE include)
target_link_libraries(cpp-image-viewer PRIVATE SDL3::SDL3)

target_compile_options(cpp-image-viewer PRIVATE -Wall -Wextra -Wpedantic)
