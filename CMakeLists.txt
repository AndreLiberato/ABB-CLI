cmake_minimum_required(VERSION 3.5)
project(EDB2Trab2 VERSION 0.1 LANGUAGES CXX)

# set the compiling flags
set (CMAKE_CXX_FLAGS "-Wall -g -fsanitize=address -lm")

#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 11)
#--------------------------------

### [1] Application target
# configura o diretório contendo os .h, assim você pode incluílos apenas com include "arquivo.h"
include_directories(include)

# Cria um executável com nome "keno", adiciona neste executável o seu main.cpp e o KenoBet.cpp
add_executable(arv src/main.cpp)

# define C++11 standard
set_property(TARGET arv PROPERTY CXX_STANDARD 11)

# The end
