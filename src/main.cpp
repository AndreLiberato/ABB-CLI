#include <iostream>
using std::cout;
using std::endl;

#include "BinTree.hpp"
using bt::BinTree;

int main(int argc, char *argv[]) {

  BinTree * binTree = new BinTree();
  binTree->from_posfix(binTree->getRoot(), "ab*c+");
  binTree->print(binTree->getRoot());
  cout << binTree->to_posfix(binTree->getRoot()) << endl;
  cout << binTree->to_infix(binTree->getRoot()) << endl;
  delete binTree;

  //binTree->remove_node(binTree->getRoot());
  binTree = new BinTree();
  binTree->from_posfix(binTree->getRoot(), "abc*+");
  binTree->print(binTree->getRoot());
  cout << binTree->to_posfix(binTree->getRoot()) << endl;
  cout << binTree->to_infix(binTree->getRoot()) << endl;

  delete binTree;

  return 0;
}
