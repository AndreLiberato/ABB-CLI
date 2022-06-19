#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include "BinTree.hpp"

using namespace bt;
using std::cout;
using std::endl;

#define file_prefix_in "./data/in/prefix.in"
#define file_postfix_in "./data/in/postfix.in"

#define file_prefix_out "./data/out/prefix.out"
#define file_postfix_out "./data/out/postfix.out"
#define file_infix_out "./data/out/infix.out"
#define file_aval_out "./data/out/aval.out"

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

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {

  notation_t prefix = readFile(file_prefix_in);
  notation_t postfix = readFile(file_postfix_in);

  std::fstream fs = openFile(file_aval_out);

  notation_t prefix_from_tree;
  notation_t postfix_from_tree;
  notation_t infix_from_tree;

  for (std::string expression : postfix){
    BinTree* binTree = new BinTree();
    binTree->from_postfix(binTree->getRoot(), expression);
    binTree->print(binTree->getRoot());

    cout << "Original String:\t" << expression << endl;

    cout << "Posfix notation:\t" << binTree->to_postfix(binTree->getRoot()) << endl;
    prefix_from_tree.push_back(binTree->to_postfix(binTree->getRoot()));

    cout << "Prefix notation:\t" << binTree->to_prefix(binTree->getRoot()) << endl;
    postfix_from_tree.push_back(binTree->to_prefix(binTree->getRoot()));

    cout << "Infix notation: \t" << binTree->to_infix(binTree->getRoot()) << endl;
    infix_from_tree.push_back(binTree->to_infix(binTree->getRoot()));

    cout << "Result: \t" <<  calculator(binTree->to_postfix(binTree->getRoot())) << endl;
    fs << calculator(binTree->to_postfix(binTree->getRoot())) << "\n";
    delete binTree;

  }

  writeFile(prefix_from_tree, file_prefix_out);
  writeFile(postfix_from_tree, file_postfix_out);
  writeFile(infix_from_tree, file_infix_out);

  fs.close();

  std::cout << "_________________________________" << std::endl;

  return 0;
}
