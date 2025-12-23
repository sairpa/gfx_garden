cmake_minimum_required(VERSION 3.25)
project(gfx_garden VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Force standard C++

add_executable(win main.cpp tgaimage.cpp)