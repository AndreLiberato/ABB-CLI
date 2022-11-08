#include "cli.hpp"

using namespace cli;

std::unordered_map<std::string, command> command_list = {
  {"create", command::create},
  {"insert", command::insert},
  {"remove", command::remove},
  {"search", command::search},
  {"at", command::at},
  {"position", command::position_of},
  {"median", command::median},
  {"average", command::average},
  {"full", command::is_full},
  {"complete", command::is_complete},
  {"pre", command::pre_order},
  {"print", command::print},
  {"read", command::read},
  {"exit", command::exit},
};

std::vector<std::string> cli::split(std::string str) {
  std::vector<std::string> commands;
  std::stringstream ss(str);
  std::string word;

  while (ss >> word) {
    commands.push_back(word);
  }
  return commands;
}

command cli::get_command(std::string command) {
  if (command_list.find(command) != command_list.end())
    return command_list.at(command);
  return command::none;
}