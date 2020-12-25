#include <string>
#include <unistd.h>
#include "../include/read_write_wrapper.h"
#include <sys/types.h>
#include <cstring>

void write(int desc, const std::string& t) {
    write(desc, t.c_str(), t.size());
}

std::string read(int desc, size_t begin_size) {
    char* new_str = new char[begin_size];
    ssize_t x = read(desc, new_str, begin_size);
    return std::string(new_str, x);
}