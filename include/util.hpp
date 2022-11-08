#ifndef UTIL_HPP_
#define UTIL_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <filesystem>
#include <utility>
#include "node.hpp"

namespace util {

  enum direction {
    none,
    left,
    right
  }; 

  using node_backtrack_t = std::stack<std::pair<tree::Node*, enum direction>>;
  using node_path_dir_t = std::pair<tree::Node*, enum direction>;

  using command_list_t = std::vector<std::string>;

  std::fstream open_file(std::string fileName);

  command_list_t read_file(std::string fileName);

  bool c_validate(std::string c, std::string v);

}

#endif