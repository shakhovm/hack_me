//
// Created by shakhov on 24.12.20.
//

#ifndef HACKER_FIRST_PROCESS_H
#define HACKER_FIRST_PROCESS_H
#include <unordered_map>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <sstream>
#include "data_base.h"

enum Commads {
      nop,
      open_file,
      close_file,
      read_file,
      write_file,
      delete_record,
      list_all,
      create_file,
      get_record

};


std::string execute_command(DataBase& db, Commads command,
                            const std::vector<std::string>& lines);

std::string commands_handler(const std::string& command, DataBase& db);

#endif //HACKER_FIRST_PROCESS_H
