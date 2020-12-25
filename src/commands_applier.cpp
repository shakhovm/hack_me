//
// Created by shakhov on 24.12.20.
//

#include "../include/commands_applier.h"



static std::unordered_map<std::string, Commads> main_commands = {
        {"open", open_file},
        {"close", close_file},
        {"select", read_file},
        {"delete", delete_record},
        {"list", list_all},
        {"write", write_file},
        {"create", create_file},
        {"get", get_record }
};


std::string execute_command(DataBase& db, Commads command,
                            const std::vector<std::string>& lines) {
    switch (command) {
        case open_file:
            db.open_file(lines[1]);
            break;

        case close_file:
            db.close_file(lines[1]);
            break;

        case create_file:
            db.create_file(lines[1]);
            break;

        case write_file: {
            std::ostringstream imploded;
            std::copy(lines.begin() + 2, lines.end(),
                      std::ostream_iterator<std::string>(imploded, " "));
            db.make_record(lines[1], imploded.str());
            break;
        }
        case list_all: {
            auto file_list = db.file_list();
            std::string files;
            for (const auto& file: file_list) {
                files += file + '\n';
            }
            return files;
        }
        case get_record: {
            int s = -1;
            std::stringstream ss(lines[2]);
            ss >> s;
            return db.get_record(lines[1], s);
        }

        case delete_record: {
            int s = -1;
            std::stringstream ss(lines[2]);
            ss >> s;
            db.delete_record(lines[1], s);
            break;
        }
        default:
            return "bad command!";
    }
    return "Success";
}

std::string commands_handler(const std::string& command, DataBase& db) {
    std::vector<std::string> lines;

    boost::split( lines, command, boost::is_any_of(" "));
    if (lines.empty()) {
        return "";
    }

    std::string main_command = lines[0];
    if (main_commands.find(main_command) == main_commands.end()) {
        return "bad command!";
    }

    try {
        return execute_command(db, main_commands[main_command], lines);
    } catch (std::runtime_error& e) {
        return e.what();
    }

}
