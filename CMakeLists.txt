cmake_minimum_required (VERSION 3.13.3)
project (turing_machine)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(turing_machine ${SOURCES})
