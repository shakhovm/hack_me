cmake_minimum_required(VERSION 3.17)
project(hack_me)

set(CMAKE_CXX_STANDARD 20)

set(SRC src/data_base.cpp src/encoder_decoder.cpp src/commands_applier.cpp src/second_process.cpp src/read_write_wrapper.cpp src/commands_sender.cpp)
set(INC include/commands_sender.h include/second_process.h include/data_base.h include/commands_applier.h include/encoder_decoder.h include/read_write_wrapper.h)
add_executable(hackme main.cpp ${SRC} ${INC})