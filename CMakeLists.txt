cmake_minimum_required(VERSION 3.2)

project(transport)

set(CMAKE_CXX_FLAGS "-Wall --std=c++14 -g")

file (GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})