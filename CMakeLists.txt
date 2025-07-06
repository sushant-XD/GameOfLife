cmake_minimum_required(VERSION 3.5.0)
project(GAME_OF_LIFE
  VERSION 0.1.0
  DESCRIPTION "A very simple implementation of conway's game of life"
  LANGUAGES CXX
)

add_subdirectory(external/pybind11)
add_subdirectory(python_bindings)
add_subdirectory(src)

