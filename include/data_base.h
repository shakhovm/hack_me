//
// Created by shakhov on 24.12.20.
//

#ifndef HACKER_DATA_BASE_H
#define HACKER_DATA_BASE_H

#include <string>
#include <vector>
#include <unordered_map>
#include <map>

class DataBase {
    std::string file_name;
    std::map<std::string, std::fstream*> open_files;
public:
    explicit DataBase(const std::string& file_name) : file_name(file_name){}
    ~DataBase() = default;
    std::vector<std::string> file_list();
    int open_file(const std::string &name);
    void close_file(const std::string &name);
    void create_file(const std::string &name);
    void make_record(const std::string &name, const std::string &record);
    void delete_record(const std::string &name, int id);
    std::string get_record(const std::string &name, int id);
};


#endif //HACKER_DATA_BASE_H
