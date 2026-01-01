cmake_minimum_required(VERSION 3.10)
project(MathExample)
set(CMAKE_C_STANDARD 11)

include_directories(include)

file(GLOB_RECURSE SRC_FILES 
    "src/arithmetic/*.c"
    "src/number_theory/*.c" 
    "src/statistics/*.c"
)

add_library(math_utils STATIC ${SRC_FILES})

add_executable(main main.c)
target_link_libraries(main math_utils)