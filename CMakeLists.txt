cmake_minimum_required(VERSION 3.13)
project(Filler C)

set(CMAKE_C_STANDARD 99)
#add_definitions( "-Wall -Wextra -Werror" )
AUX_SOURCE_DIRECTORY(libft LIB)
add_executable(Filler main.c)