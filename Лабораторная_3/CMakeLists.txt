cmake_minimum_required(VERSION 3.16)

project(Laboratornaya3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(Laboratornaya3
        src/main.cpp
        src/Money.cpp
        src/BankAccount.cpp
)

target_include_directories(Laboratornaya3 PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(Laboratornaya3 PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)