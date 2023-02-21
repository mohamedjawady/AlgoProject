cmake_minimum_required(VERSION 3.24)
project(projectalgo C)

set(CMAKE_C_STANDARD 11)

# define debug constant
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DMY_DEBUG")
add_executable(projectalgo main.c arbre/arbre.c dico/dico.c utils/utils.c utils/utils.h arbre/extras.c)
