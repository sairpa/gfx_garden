cmake_minimum_required(VERSION 3.10)

project(gfx_garden CXX)

set( TARGET ${PROJECT_NAME} )
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

# source
file( GLOB_RECURSE HPPS "${INCLUDE_PATH}/*.h" )
file( GLOB_RECURSE CPPS "${SOURCE_PATH}/*.cpp .c" )

add_executable(${PROJECT_NAME} ${CPPS} ${HPPS})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
target_compile_options( ${TARGET} PRIVATE -lglfw -lGL -lm -lpthread -lXi -ldl)