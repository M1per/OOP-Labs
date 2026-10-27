cmake_minimum_required(VERSION 3.16)
project(Lab3_Time)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(lab3
    src/main.cpp
    src/Time.cpp
)

target_include_directories(lab3 PRIVATE include)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(lab3 PRIVATE -Wall -Wextra -Wpedantic)
endif()
