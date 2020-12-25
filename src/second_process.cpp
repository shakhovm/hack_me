#include "../include/second_process.h"
#include <iostream>
#include "../include/commands_applier.h"
#include "../include/encoder_decoder.h"
#include "../include/read_write_wrapper.h"

void commands_applier(int *p1, int *p2) {
    std::string decoded_command;
    const std::string main_file = "main_file.txt";
    DataBase db(main_file);
    while (true) {
        try {
            decoded_command = decode_command( read(p2[0]), 12);
            if (decoded_command == "exit") {
                break;
            }
            std::string response = commands_handler(decoded_command, db);
            write(p1[1], response);
        } catch (std::runtime_error& e) {
            write(p1[1], e.what());
        }
    }

}

