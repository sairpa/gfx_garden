cmake_minimum_required(VERSION 3.20)

project(gpu_cosa LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Force GCC (optional — only if you want to override defaults)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

# Find the required packages
find_package(OpenGL REQUIRED)
# Note: You might need 'glfw' or 'glfw3' depending on how it's installed
find_package(glfw3 REQUIRED) 

add_executable(gs g0/g01.cpp)

target_link_libraries(gs PRIVATE 
    ${OPENGL_LIBRARIES} 
    glfw
)