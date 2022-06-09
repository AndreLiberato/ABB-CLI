cmake_minimum_required(VERSION 3.5)
project(Calc_TrabEDII VERSION 0.1 LANGUAGES CXX)

# set the compiling flags
set (CMAKE_CXX_FLAGS "-Wall -g -fsanitize=address -lm")

#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 11)
#--------------------------------

### [1] Application target
# configura o diretório contendo os .hpp,
# assim você pode incluílos apenas com include "arquivo.h"
include_directories(include)

<<<<<<< HEAD
add_executable(arv src/main.cpp)
=======
# Cria um executável com nome "calc", 
# adiciona neste executável o seu main.cpp e o KenoBet.cpp
add_executable(calc src/main.cpp)
>>>>>>> ece711bd9b51550b754c1e57b7cce0100eb65f6a

# define C++11 standard
set_property(TARGET arv PROPERTY CXX_STANDARD 11)

# The end
