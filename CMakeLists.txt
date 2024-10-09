cmake_minimum_required(VERSION 3.20)

set(NAME "clang_coverage")
project(${NAME} CXX)

if(${COVERAGE})
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fprofile-instr-generate -fcoverage-mapping")
    SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -fprofile-instr-generate")
    SET(COVERAGE_FILE "coverage-%m-%p.profraw")
endif()

find_package(Catch2 REQUIRED)
include(CTest)
include(Catch)

add_subdirectory(cov1)
add_subdirectory(cov2)
