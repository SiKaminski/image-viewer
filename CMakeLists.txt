cmake_minimum_required(VERSION 3.24)
project("cpp-image-viewer" VERSION 1.0 LANGUAGES CXX)
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

add_executable(${PROJECT_NAME}
    src/utils.cpp
    src/cliflags.cpp
    src/main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

option(ENABLE_TRACING "Enable tracing output" OFF)

if(ENABLE_TRACING)
    target_compile_definitions(${PROJECT_NAME} PRIVATE TRACING=1)
endif()

target_compile_definitions(${PROJECT_NAME} PRIVATE PROJECT_NAME_STR="${PROJECT_NAME}")
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
