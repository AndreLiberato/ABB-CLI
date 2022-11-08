#ifndef CLI_HPP_
#define CLI_HPP_

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

namespace cli {

  enum command {
    create,
    insert,
    remove,
    search,
    at,
    position_of,
    median,
    average,
    is_full,
    is_complete,
    pre_order,
    print,
    read,
    exit,
    none
  };

  std::vector<std::string> split(std::string str);

  command get_command(std::string str);
}

#endif