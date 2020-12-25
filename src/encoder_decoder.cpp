#include "../include/encoder_decoder.h"

std::string encode_command(const std::string& command, int k) {
    std::string new_command(command.size(), ' ');
    int maxchar = static_cast<int>(std::numeric_limits<char>::max());
    for (size_t i = 0; i < command.size(); ++i) {
        new_command[i] =(static_cast<int>(command[i]) + k) % maxchar;
    }
    return new_command;
}

std::string decode_command(const std::string& command, int k) {
    std::string new_command(command.size(), ' ');
    int maxchar = static_cast<int>(std::numeric_limits<char>::max());

    for (size_t i = 0; i < command.size(); ++i) {
        new_command[i] = ((static_cast<int>(command[i]) - k) % maxchar + maxchar) % maxchar;
    }
    return new_command;
}

std::string encode_password(const std::string& command, const std::string& keys) {
    std::string new_command = command;
    for (size_t i = 0; i < command.size(); ++i ) {
        for (const auto& key: keys) {
            new_command[i] ^= key;
        }
    }
    return new_command;
}
