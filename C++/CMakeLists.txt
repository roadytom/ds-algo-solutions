cmake_minimum_required(VERSION 3.20)
project(cp)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)   # gives -std=c++23 instead of -std=gnu++23

# debug.hpp lives at <project>/algo/debug.hpp, so the project root
# needs to be on the include path for #include "algo/debug.hpp" to resolve
include_directories(${CMAKE_SOURCE_DIR})

# only in Debug builds — Release stays clean
add_compile_definitions($<$<CONFIG:Debug>:LOCAL>)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE SOURCES "*.cpp")
list(FILTER SOURCES EXCLUDE REGEX ".*/kactl-main/.*")
list(FILTER SOURCES EXCLUDE REGEX ".*/\\.venv/.*")
list(FILTER SOURCES EXCLUDE REGEX ".*/algorithms/.*")

foreach(src ${SOURCES})
    file(RELATIVE_PATH rel ${CMAKE_SOURCE_DIR} ${src})
    string(REPLACE "/" "_" name ${rel})
    string(REPLACE ".cpp" "" name ${name})
    add_executable(${name} ${src})
endforeach()
