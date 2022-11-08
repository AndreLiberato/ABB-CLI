#include "util.hpp"

std::fstream util::open_file(std::string fileName){
  std::fstream fs;
  std::cout << "TESTE: " << fileName << std::endl;
  fs.open(fileName);

  if(!fs.is_open()) {
    fs.clear();
    fs.open(fileName, std::ios::out); //Create file.
    fs.close();
    fs.open(fileName);
    std::cout << "Arquivo " << fileName << " criado" << std::endl; 
  }

  return fs;
}

util::command_list_t util::read_file(std::string fileName) {
  std::vector<std::string> eq;
  std::string line;

  std::fstream fs = util::open_file(fileName);

  while (std::getline(fs, line))
    eq.push_back(line);

  fs.close();

  return eq;
}

bool util::c_validate(std::string c, std::string v) {
  if (c == v) {
    return false;
  } else {
    return true;
  }
}