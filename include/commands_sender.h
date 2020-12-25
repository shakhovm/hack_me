//
// Created by shakhov on 24.12.20.
//

#ifndef HACKER_COMMAND_CHECKER_H
#define HACKER_COMMAND_CHECKER_H

#include <iostream>
#include <unordered_map>
#include <unistd.h>
#include "encoder_decoder.h"
#include "read_write_wrapper.h"

void check_pswd();

void commands_sender(int *p1, int *p2);

#endif //HACKER_COMMAND_CHECKER_H
