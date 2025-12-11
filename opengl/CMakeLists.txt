cmake_minimum_required(VERSION 3.10)

project(gfx_garden CXX C)

set(EXECUTABLE_NAME win)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${EXECUTABLE_NAME} wt.cpp src/glad.c)

target_include_directories(${EXECUTABLE_NAME} PRIVATE
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}"
)

target_link_libraries(${EXECUTABLE_NAME} PRIVATE glfw GL)