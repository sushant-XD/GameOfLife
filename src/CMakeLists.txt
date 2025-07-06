cmake_minimum_required(VERSION 3.5.0)

add_library(print_utils SHARED utils/print_utils.cpp)
target_include_directories(print_utils PUBLIC ${PROJECT_SOURCE_DIR}/include)
add_library(grids SHARED grids.cpp)
target_include_directories(grids PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(grids PUBLIC print_utils) 
add_executable(gameOfLife main.cpp)
target_link_libraries(gameOfLife grids print_utils)
