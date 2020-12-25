//
// Created by shakhov on 24.12.20.
//

#ifndef HACKER_READ_WRITE_WRAPPER_H
#define HACKER_READ_WRITE_WRAPPER_H
#include <string>

void write(int desc, const std::string& t);

std::string read(int desc, size_t begin_size=256);

#endif //HACKER_READ_WRITE_WRAPPER_H
