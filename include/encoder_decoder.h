//
// Created by shakhov on 24.12.20.
//

#ifndef HACKER_ENCODER_DECODER_H
#define HACKER_ENCODER_DECODER_H
#include <string>


std::string encode_command(const std::string& command, int k);

std::string decode_command(const std::string& command, int k);

std::string encode_password(const std::string& command, const std::string& keys);

#endif //HACKER_ENCODER_DECODER_H
