#include <string>
#include <unistd.h>
#include "../include/read_write_wrapper.h"
#include <sys/types.h>
#include <cstring>

void write(int desc, const std::string& t) {
    write(desc, t.c_str(), t.size());
}

std::string read(int fd, size_t begin_size) {
    auto buf = new char[begin_size];

    ssize_t add_size = read(fd, buf, begin_size);

    std::string new_str(buf, add_size);
    return new_str;
}