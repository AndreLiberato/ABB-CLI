#include "BinTree.hpp"

using namespace bt;

BinTree::~BinTree() {
  remove_node(root);
}

void BinTree::remove_node(Node* node) {
  if(node->left != nullptr)
    remove_node(node->left);

  if(node->right != nullptr)
    remove_node(node->right);
    
  delete node;
}

BinTree::Node* BinTree::getRoot() {
  return root;
}

std::string BinTree::visit(Node* node) {
  if(node != nullptr) 
    return node->data;
  else
    return "ERROR"; // TODO: dá pra melhorar isso!
}

bool BinTree::is_operator(char str) {
  return (
    ( str == '+' ||
      str == '-' ||
      str == '*' ||
      str == '/' ||
      str == '^' ) ? true : false);
}

std::string BinTree::from_postfix(Node* node, std::string postfix) {
  if( !postfix.empty() ) {
    if( is_operator(postfix.back()) ) {
      /* 
        * Note: To build a binary tree using postfix notation, 
        * use preorder traversal on right first
        */

      node->right = new Node();
      node->left = new Node();
      
      node->data = postfix.back();

      postfix.pop_back();
      postfix = from_postfix(node->right, postfix);
      postfix = from_postfix(node->left, postfix);
      return postfix;
    }

    else {
      node->data = postfix.back();
      postfix.pop_back();
      return postfix;
    }
  }
  return "";
}

std::string BinTree::from_prefix(Node* node, std::string prefix) {
  if( !prefix.empty() ) {
    if( is_operator( prefix.front() )) {
      /* 
        * Note: To build a binary tree using prefix notation, 
        * use preorder traversal on right first
        */

      node->left = new Node();
      node->right = new Node();

      node->data = prefix.front();

      prefix.erase(prefix.begin());

      prefix = from_prefix(node->left, prefix);
      prefix = from_prefix(node->right, prefix);

      return prefix;
    }

    else {
      node->data = prefix.front();

      prefix.erase(prefix.begin());

      return prefix;
    }
  }
  return "";
}

std::string BinTree::to_postfix(Node* node, std::string postfix) {
  //In postfix, first access the subtree on the left
  if (node->left != nullptr)
    postfix += to_postfix(node->left);
  
  //then on the right
  if (node->right != nullptr)
    postfix += to_postfix(node->right);

  //and then visit the node.
  postfix += visit(node);
  
  return postfix;
}

std::string BinTree::to_prefix(Node* node, std::string prefix) {
  prefix += visit(node);

  if (node->left != nullptr)
    prefix += to_prefix(node->left);

  if (node->right != nullptr)
    prefix += to_prefix(node->right);

  return prefix;
}

std::string BinTree::to_infix(Node* node, std::string infix) {
  // Checks if the node is a leaf or root.
  infix += (
    ((node->left == nullptr && node->right == nullptr) 
      || node == root) ? "" : "(" 
    );

  if(node->left != nullptr)
    infix += to_infix(node->left);

  infix += visit(node);

  if(node->right != nullptr)
    infix += to_infix(node->right);

  // Checks if the node is a leaf or root.
  infix += (
    ((node->left == nullptr && node->right == nullptr) 
      || node == root) ? "" : ")"
    );
  return infix;
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