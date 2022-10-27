#include <cstring>
#include "util.hpp"

using namespace tree;

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
  BinTree* tree = new BinTree();

  tree->insert(7);
  tree->insert(3);
  tree->insert(5);
  tree->insert(1);

  tree->insert(11);
  tree->insert(9);
  tree->insert(13);

  tree->print(tree->getRoot());

  delete tree;

  return 0;
}