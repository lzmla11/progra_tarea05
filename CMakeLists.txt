cmake_minimum_required(VERSION 3.10)

project(progra_tarea05) 

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED True) 

include_directories(include) 

add_executable(
	progra_tarea05
	src/Block.cpp
)

