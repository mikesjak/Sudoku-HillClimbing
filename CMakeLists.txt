cmake_minimum_required(VERSION 3.24)
project(Semestral_Work)

set(CMAKE_CXX_STANDARD 17)

add_executable(Semestral_Work main.cpp solver.cpp grid.cpp grid.h solver.h CHillClimber.h)
