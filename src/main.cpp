#include <iostream>
#include <string>
#include "BinTree.hpp"

using namespace bt;
using std::cout;
using std::endl;

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {

  BinTree * binTree = new BinTree();
  std::string str = "ab*c+";

  binTree->from_postfix(binTree->getRoot(), str);
  binTree->print(binTree->getRoot());
  cout << "Original String:\t" << str << endl;
  cout << "Posfix notation:\t" << binTree->to_postfix(binTree->getRoot()) << endl;
  cout << "Prefix notation:\t" << binTree->to_prefix(binTree->getRoot()) << endl;
  cout << "Infix notation: \t" << binTree->to_infix(binTree->getRoot()) << endl;
  delete binTree;

  std::cout << "_________________________________" << std::endl;

  binTree = new BinTree();
  str = "abc*+";

  binTree->from_postfix(binTree->getRoot(), str);
  binTree->print(binTree->getRoot());
  cout << "Original String:\t" << str << endl;
  cout << "Posfix notation:\t" << binTree->to_postfix(binTree->getRoot()) << endl;
  cout << "Prefix notation:\t" << binTree->to_prefix(binTree->getRoot()) << endl;
  cout << "Infix notation: \t" << binTree->to_infix(binTree->getRoot()) << endl;
  delete binTree;

  // TODO: This last example don't work. Numbers here have more than one digit!
  std::cout << "_________________________________" << std::endl;

  binTree = new BinTree();
  str = "+-*^2234//12+11";

  binTree->from_prefix(binTree->getRoot(), str);
  binTree->print(binTree->getRoot());
  cout << "Original String:\t" << str << endl;
  cout << "Posfix notation:\t" << binTree->to_postfix(binTree->getRoot()) << endl;
  cout << "Prefix notation:\t" << binTree->to_prefix(binTree->getRoot()) << endl;
  cout << "Infix notation: \t" << binTree->to_infix(binTree->getRoot()) << endl;

  delete binTree;

  return 0;
}
