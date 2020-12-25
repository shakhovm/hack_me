cmake_minimum_required(VERSION 3.17)
project(hacker)

set(CMAKE_CXX_STANDARD 20)

set(SRC src/data_base.cpp src/encoder_decoder.cpp src/first_process.cpp src/second_process.cpp src/read_write_wrapper.cpp src/command_checker.cpp)
set(INC include/command_checker.h include/second_process.h include/data_base.h include/first_process.h include/encoder_decoder.h include/read_write_wrapper.h)
add_executable(hacker main.cpp ${SRC} ${INC})
add_executable(example example.cpp ${SRC} ${INC} src/encoder_decoder.cpp)