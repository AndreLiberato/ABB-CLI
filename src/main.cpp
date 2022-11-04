#include "bin_tree.hpp"

using namespace tree;

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
  Node* root = new Node(7);
  BinTree* tree = new BinTree(root);

  //tree->insert(7);
  tree->insert(3);
  tree->insert(5);
  tree->insert(1);
  tree->insert(4);
  tree->insert(6);
  tree->insert(2);

  tree->insert(11);
  tree->insert(9);
  tree->insert(13);
  tree->insert(12);
  tree->insert(15);

  tree->print_tree();

  tree->remove(7);

  tree->print_tree();

  delete tree;

  return 0;
}