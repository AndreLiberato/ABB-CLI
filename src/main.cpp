#include <iostream>
using std::cout;
using std::endl;

#include "BinTree.hpp"
using bt::BinTree;
//int argc, char *argv[]
int main() {

  BinTree * binTree = new BinTree();

  binTree->from_postfix(binTree->getRoot(), "ab*c+");
  binTree->print(binTree->getRoot());
  cout << binTree->to_postfix(binTree->getRoot()) << endl;
  cout << binTree->to_infix(binTree->getRoot()) << endl;
  delete binTree;

  std::cout << "_________________________________" << std::endl;

  //binTree->remove_node(binTree->getRoot());
  binTree = new BinTree();
  binTree->from_postfix(binTree->getRoot(), "abc*+");
  binTree->print(binTree->getRoot());
  cout << binTree->to_postfix(binTree->getRoot()) << endl;
  cout << binTree->to_infix(binTree->getRoot()) << endl;
  delete binTree;

  std::cout << "_________________________________" << std::endl;

  binTree = new BinTree();
  binTree->from_prefix(binTree->getRoot(), "+-*^2234//12+11");
  binTree->print(binTree->getRoot());
  cout << binTree->to_prefix(binTree->getRoot()) << endl;
  cout << binTree->to_infix(binTree->getRoot()) << endl;

  delete binTree;

  return 0;
}
