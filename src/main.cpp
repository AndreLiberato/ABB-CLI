#include <iostream>
#include "BinTree.hpp"

using namespace bt;
using std::cout;
using std::endl;

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {

  BinTree * binTree = new BinTree();

  binTree->from_postfix(binTree->getRoot(), "ab*c+");
  binTree->print(binTree->getRoot());
  cout << binTree->to_postfix(binTree->getRoot()) << endl;
  cout << binTree->to_prefix(binTree->getRoot()) << endl;
  cout << binTree->to_infix(binTree->getRoot()) << endl;
  delete binTree;

  std::cout << "_________________________________" << std::endl;

  //binTree->remove_node(binTree->getRoot());
  binTree = new BinTree();
  binTree->from_postfix(binTree->getRoot(), "abc*+");
  binTree->print(binTree->getRoot());
  cout << binTree->to_postfix(binTree->getRoot()) << endl;
  cout << binTree->to_prefix(binTree->getRoot()) << endl;
  cout << binTree->to_infix(binTree->getRoot()) << endl;
  delete binTree;

  std::cout << "_________________________________" << std::endl;

  binTree = new BinTree();
  binTree->from_prefix(binTree->getRoot(), "+a*bc");
  binTree->print(binTree->getRoot());
  cout << binTree->to_postfix(binTree->getRoot()) << endl;
  cout << binTree->to_prefix(binTree->getRoot()) << endl;
  cout << binTree->to_infix(binTree->getRoot()) << endl;

  delete binTree;

  return 0;
}
