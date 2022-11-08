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

// using std::cout;
// using std::endl;

// #define file_prefix_in "./data/in/prefix.in"
// #define file_postfix_in "./data/in/postfix.in"

// #define file_out_dir "./data/out"
// #define file_prefix_out "./data/out/prefix.out"
// #define file_postfix_out "./data/out/postfix.out"
// #define file_infix_out "./data/out/infix.out"
// #define file_aval_out "./data/out/aval.out"

// void writeFile(notation_t expressions, std::string fileName);

// void print(std::vector<std::string> notation);

// void check_dir(const std::filesystem::path path);

#endif