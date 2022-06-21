#include "util.hpp"

using notation_t = std::vector<std::string>;

bool is_operator(const char str) {
  return (
      ( str == '+' ||
        str == '-' ||
        str == '*' ||
        str == '/' ||
        str == '^' ) ? true : false);
}

std::fstream openFile(std::string fileName){
  std::fstream fs;

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

notation_t readFile(std::string fileName) {
  std::vector<std::string> eq;
  std::string line;

  std::fstream fs = openFile(fileName);

  while (std::getline(fs, line))
    eq.push_back(line);

  fs.close();

  return eq;
}

void writeFile(notation_t expressions, std::string fileName) {
  std::fstream fs = openFile(fileName);

  for (std::string expression : expressions) {
    fs << expression << std::endl;
  }
  fs.close();
}

void print(std::vector<std::string> notation) {
  for(std::string line : notation)
    std::cout << line << std::endl;
}

int calculator(std::string expression) {
  std::stack<int> result;
  int a, b;

  for (char character : expression) {
    switch (character){
      case '+':
        a = result.top();
        result.pop();
        b = result.top();
        result.pop();
        result.push(a+b);
        break;

      case '-':
        a = result.top();
        result.pop();
        b = result.top();
        result.pop();
        result.push(b-a);
        break;

      case '*':
        a = result.top();
        result.pop();
        b = result.top();
        result.pop();
        result.push(a*b);
        break;

      case '/':
        a = result.top();
        result.pop();
        b = result.top();
        result.pop();
        result.push(int(b/a));
        break;

      case '^':
        a = result.top();
        result.pop();
        b = result.top();
        result.pop();
        result.push(a^b);
        break;

      default:
        std::string c (1, character);
        result.push(atoi(&c.at(0)));
        break;
    }
  }
  return result.top();
}