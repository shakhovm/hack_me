#include <iostream>
#include <unordered_map>
#include "../include/encoder_decoder.h"
#include "../include/read_write_wrapper.h"
#include "../include/commands_sender.h"

void check_pswd() {
    const std::string password = "m`iijrjwia";
    const std::string keys = "lkjh";
    std::cout << "Enter password: " << std::endl;
    while (true) {
        std::string pswd;
        getline(std::cin, pswd, '\n');
        if (pswd == encode_password(password, keys)) {
            std::cout << "Entered!" << std::endl;
            break;
        }
        std::cout << "Try Again:" << std::endl;
    }
}

void commands_sender(int *p1, int *p2) {

    check_pswd();
    std::string buf;
    while (true) {
        std::cout << "\033[0;33m" << "database $ " << "\033[1;39m";
        std::string command;
        getline(std::cin, command, '\n');
        try {
            write(p2[1], encode_command(command, 12));
            if (command == "exit") {
                break;
            }
            buf = read(p1[0]);
        } catch (std::runtime_error& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << buf << std::endl;
    }


}