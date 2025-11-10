#!/usr/bin/env bash
mkdir -p ./build/debug && cd build
# Configure the project (tell CMake to use GCC explicitly)
cmake -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ ..
# Build the project
cmake --build .

./gs