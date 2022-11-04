#include "node.hpp"

using namespace tree;

bool Node::has_left() {
  if (this->left != nullptr)
    return true;
  return false;
}

bool Node::has_right() {
  if (this->right != nullptr)
    return true;
  return false;
}