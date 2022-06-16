cmake_minimum_required(VERSION 3.5)
project(Calc_TrabEDII VERSION 0.1 LANGUAGES CXX)

# set the compiling flags
# set (CMAKE_CXX_FLAGS "-Wall -g -fsanitize=address -lm")

add_compile_options(
  -g
  -Wall
  -Werror
  -Wextra
  -Wpedantic
  -ansi
  # -Ofast
  -fsanitize=address,undefined
  # -lm
)

add_link_options(-fsanitize=address,undefined)

#--------------------------------
# This is for old cmake versions
set (CMAKE_CXX_STANDARD 11)
#--------------------------------

### [1] Application target
## configura o diretório contendo os .hpp
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# add_library(bintree)

# target_sources(
#   bintree
#   PUBLIC
#     ${CMAKE_CURRENT_SOURCE_DIR}/include/BinTree.hpp
#   PRIVATE
#     src/BinTree.cpp
# )

## Cria um executável com nome "calc".
add_executable(calc)

target_sources(
  calc
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/BinTree.hpp
    src/main.cpp
    src/BinTree.cpp
)

# target_link_libraries(
#   calc
#   PRIVATE
#     bintree
# )

# target_include_directories(calc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# The end
