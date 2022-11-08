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

// void writeFile(notation_t expressions, std::string fileName) {
//   std::fstream fs = openFile(fileName);

//   for (std::string expression : expressions) {
//     fs << expression << std::endl;
//   }
//   fs.close();
// }

// void print(std::vector<std::string> notation) {
//   for(std::string line : notation)
//     std::cout << line << std::endl;
// }

// void check_dir(const std::filesystem::path path) {
//   if (!std::filesystem::exists(path)){
//     if (std::filesystem::create_directory(path)){
//       std::cout << "Directory data/out created success" << std::endl;
//     } else {
//       std::cout << "Directory data/out created fail" << std::endl;
//     }
//   }
// }
