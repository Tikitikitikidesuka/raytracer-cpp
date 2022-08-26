cmake_minimum_required(VERSION 3.2)
project(raytracer VERSION 1.0)

# ------------------------------------------------- #

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "-O3 -std=c++11 -Wall")

set(INCLUDE_DIRECTORY ${PROJECT_SOURCE_DIR}/include)
set(SOURCE_DIRECTORY  ${PROJECT_SOURCE_DIR}/src)

message(STATUS ${SOURCE_DIRECTORY}/*.cpp)

# ------------------------------------------------- #

include_directories(${INCLUDE_DIRECTORY})

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "${SOURCE_DIRECTORY}/*.cpp")
message(STATUS "Source files: " ${SRC_FILES})
add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})
