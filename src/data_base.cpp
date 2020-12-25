//
// Created by shakhov on 24.12.20.
//

#include "../include/data_base.h"
#include <fstream>
#include <vector>
#include <filesystem>
#include <iostream>
#include <chrono>

std::vector<std::string> DataBase::file_list() {
    std::ifstream f(file_name);
    std::vector<std::string> files;
    std::string file;
    while (f >> file) {
        files.push_back(file);
    }

    return files;
}

void DataBase::create_file(const std::string &name) {
    std::fstream f(file_name, std::ios::app);
    if ( std::filesystem::exists(name) ) {
        throw std::runtime_error("File Exists!");
    }
    std::stringstream ss;
    ss << name;
    f << ss.str() << std::endl;
    std::ofstream new_file(name);
}

void DataBase::make_record(const std::string &name, const std::string &record) {
    std::vector<std::string> records;
    std::string rec;
    std::stringstream ss;
    open_files[name]->seekg(0, std::ios::beg);
    open_files[name]->seekp(0, std::ios::beg);
    if (open_files.find(name) == open_files.end()) {
        open_file(name);
    }

    while (*open_files[name] >> rec) {
        records.push_back(rec);
    }
    auto t = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(t);
    ss << records.size() << '|';
    ss << record << '|';
    ss << end_time << '|' << "exs";
    records.push_back(ss.str());
    std::string full_str;
    for (auto& recrd: records) {
        full_str += recrd + '\n';
    }

    open_files[name]->seekg(0, std::ios::beg);
    open_files[name]->seekp(0, std::ios::beg);
    open_files[name]->clear();
    *open_files[name] << full_str;

}

void DataBase::delete_record(const std::string &name, int id) {
    if (open_files.find(name) == open_files.end()) {
        open_file(name);
    }
    open_files[name]->seekg(0, std::ios::beg);
    open_files[name]->seekp(0, std::ios::beg);
    std::vector<std::string> records;
    std::string rec;

    while (*open_files[name] >> rec) {
        std::stringstream ss;
        int ind = rec.find('|');
        int line_id;
        ss << rec.substr(0, ind);
        ss >> line_id;
        if (line_id == id) {
            int flag = rec.rfind('|');
            open_files[name]->seekp(flag + 1);
            *open_files[name] << "del";
            break;
//            records.push_back(rec.substr(flag) + "del");
        }

    }

    std::string full_str;
    for (auto& recrd: records) {
        full_str += recrd + '\n';
    }
}

int DataBase::open_file(const std::string &name) {
    if ( !std::filesystem::exists(name) ) {
        throw std::runtime_error("File does not Exist!");
    }
    auto* f = new std::fstream (name, std::ios::in | std::ios::out);
    if (!f->is_open()) {
        throw std::runtime_error("Failed to Open File!");
    }
    open_files[name] = f;
    return 0;
}

void DataBase::close_file(const std::string &name) {
    std::cout << name << std::endl;
    open_files[name]->close();
    open_files.erase(name);
}

std::string DataBase::get_record(const std::string &name, int id) {
    if (open_files.find(name) == open_files.end()) {
        open_file(name);
    }
    open_files[name]->seekg(0, std::ios::beg);
    std::string rec;

    while (*open_files[name] >> rec) {

        size_t ind = rec.find('|');
        if (ind == std::string::npos) {
            throw std::runtime_error("Bad File Content!");
        }
        int line_id;
        std::stringstream ss;
        ss << rec.substr(0, ind);
        ss >> line_id;
        std::cout << id << std::endl;
        if (line_id == id) {
            size_t flag = rec.rfind('|');
            std::string subrec = rec.substr(flag + 1);
            if (subrec == "del") {
                throw std::runtime_error("This record is deleted!");
            }
            size_t t = rec.rfind('|', flag - 1);
            if (t == std::string::npos) {
                throw std::runtime_error("Bad File Content!");
            }

            return rec.substr(ind + 1, t - ind);
        }
    }
    throw std::runtime_error("No Such Record!");
}
