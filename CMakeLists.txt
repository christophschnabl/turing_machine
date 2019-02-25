cmake_minimum_required (VERSION 3.13.2)
project (turing_machine)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

set (CMAKE_CXX_STANDARD 11)

add_executable(turing_machine ${SOURCES})
