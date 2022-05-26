cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(21Z-EADS-TASK2-JAKUBOWSKI-MATEUSZ VERSION 0.1.0)

include(FetchContent)

add_compile_options(-g)

FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG main
)
FetchContent_MakeAvailable(googletest)

add_executable(21Z-EADS-TASK2-JAKUBOWSKI-MATEUSZ 21Z-EADS-TASK2-JAKUBOWSKI-MATEUSZ.cpp)

