cmake_minimum_required(VERSION 3.16)

# Use clang++
set(CMAKE_CXX_COMPILER clang++)

project(Tugas_Iterasi_Kombinasi LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Common warnings for Clang
add_compile_options(-Wall -Wextra -Wpedantic)

# Put binaries in bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Targets
add_executable(soal_1 soal_1.cpp)
add_executable(soal_2 soal_2.cpp)
