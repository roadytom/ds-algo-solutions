cmake_minimum_required(VERSION 3.16)
project(CompetitiveProgramming)

set(CMAKE_CXX_STANDARD 20)

# Put all build output (executables) inside ./build/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add each problem as a separate executable
file(GLOB_RECURSE SOURCES "problems/*.cpp")

foreach(source_file ${SOURCES})
    get_filename_component(name ${source_file} NAME_WE)
    add_executable(${name} ${source_file})
endforeach()