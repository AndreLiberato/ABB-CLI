cmake_minimum_required(VERSION 3.5)
project(Calc_TrabEDII VERSION 0.1 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

# set the compiling flags
add_compile_options(
  -g
  -Wall
  -Werror
  -Wextra
  -Wpedantic
  -ansi
  -Ofast
  -fsanitize=address,undefined
  -lm
)

add_link_options(-fsanitize=address,undefined)

### [1] Application target
## configura o diretório contendo os .hpp
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

## Cria um executável com nome "calc".
add_executable(calc)

target_sources(
  calc
  PRIVATE
    src/main.cpp
    src/BinTree.cpp
    src/util.cpp
)

# The end
