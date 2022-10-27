#include "BinTree.hpp"
#include <iterator>

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

BinTree::~BinTree() {
  std::cout << "Apagando árvore." << std::endl;
  destroy_tree(this->root);
}

void BinTree::destroy_tree(Node* node) {
  if(node->has_left())
    destroy_tree(node->left);

  if(node->has_right())
    destroy_tree(node->right);

  delete node;
}

Node* BinTree::getRoot() {
  return root;
}

int BinTree::visit(Node* node) {
  if(node != nullptr) 
    return node->data;
  else
    return -1; // TODO: dá pra melhorar isso!
}

void BinTree::post_order(Node* node) {
  //In postfix, first access the subtree on the left
  if (node->left != nullptr)
    post_order(node->left);

  //then on the right
  if (node->right != nullptr)
    post_order(node->right);
  
  visit(node);
}

void BinTree::pre_order(Node* node) {
  
  visit(node);

  if (node->left != nullptr)
    pre_order(node->left);

  if (node->right != nullptr)
    pre_order(node->right);
}

void BinTree::in_order(Node* node) {
  if(node->left != nullptr)
    in_order(node->left);

  visit(node);

  if(node->right != nullptr)
    in_order(node->right);
}

void BinTree::insert(int v) {
  std::cout << "Inserindo Valor: " << v << std::endl;

  Node* node_it {this->root};

  while (true) {

    if (node_it->data > v) {

      if (!node_it->has_left()) {
        node_it->left = new Node(v);
        return;
      }
      
      node_it = node_it->left;
    } else if (node_it->data < v) {

      if (!node_it->has_right()) {
        node_it->right = new Node(v);
        return;
      }

      node_it = node_it->right;
    } else {
      std::cout << "Valor já existente!" << std::endl;
      return;
    }

  }
}

Node* search(Node* n, int v) {
  if (n == nullptr) {
    return nullptr;
  } else {
    if (n->data < v) {
      search(n->left, v);
    } else if (n->data > v) {
      search(n->right, v);
    }
  }

  return n;
}

void BinTree::print(Node* node, std::string prefix, bool isLeft) {
  if(node != nullptr) {
    std::cout << "\033[0;33m" << prefix;
    std::cout << "\033[0m";

    std::cout << "\033[1;33m" << (isLeft ? "├──" : "└──" );
    std::cout << "\033[0m";

    // Print the value of the node
    std::cout << "\033[1;32m" << " " << node->data << std::endl;
    std::cout << "\033[0m";

    // Enter the next tree level - left and right branch
    print(node->left, prefix + (isLeft ? "|   " : "    "), true);
    print(node->right, prefix + (isLeft ? "|   " : "    "), false);
  }
}
