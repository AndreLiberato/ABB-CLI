#include "bin_tree.hpp"

using namespace tree;

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

Node* BinTree::get_root() {
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

  Node* node_it = this->get_root();

  while (true) {

    if (node_it->data > v) {

      if (!node_it->has_left()) {
        node_it->left = new Node(v);
        break;;
      }
      
      node_it = node_it->left;
    } else if (node_it->data < v) {

      if (!node_it->has_right()) {
        node_it->right = new Node(v);
        break;;
      }

      node_it = node_it->right;
    } else {
      std::cout << "Valor já existente!" << std::endl;
      break;
    }

  }
}

void BinTree::remove(int v) {
  Node* node_it = this->get_root();
  Node* root = node_it;

  while (true) {

    if (node_it->data > v and node_it->has_left()) {
      root = node_it;
      node_it = node_it->left;
    } else if (node_it->data < v and node_it->has_right()) {
      root = node_it;
      node_it = node_it->right;
    } else { // encontrou o valor
      if ( !node_it->has_left() or !node_it->has_right() ) {
      if (root->has_left() and root->left->data == v) { 
        if (node_it->has_left()) {
          root->left = node_it->left;
        } else if (node_it->has_right()) {
          root->left = node_it->right;
        } else {
          root->left = nullptr;
        }
      } else if (root->has_right() and root->right->data == v) {
        if (node_it->has_left()) {
          root->right = node_it->left;
        } else if (node_it->has_right()) {
          root->right = node_it->right;
        } else {
          root->right = nullptr;
        }
      }
      std::cout << "Deletando nó com valor: " << node_it->data << std::endl;
      delete node_it;
      break;
    } else {
        int bigger_value = this->get_bigger_left(node_it)->data;
        this->remove(bigger_value);
        node_it->data = bigger_value;
        break;
      }
    }
  }
}


Node* BinTree::get_bigger_left(Node* n) {
  Node* node_it = n->left;

  if (!node_it->has_right()) {
    return n->right;
  }

  while (node_it->has_right()) {
    node_it = node_it->right;
  }
  
  return node_it;
}

Node* BinTree::search(Node* n, int v) {
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

void BinTree::print_tree() {
  print(this->get_root());
}
 
void BinTree::print(Node* n, std::string prefix, bool isLeft) {
  if(n != nullptr) {
    std::cout << "\033[0;33m" << prefix;
    std::cout << "\033[0m";

    std::cout << "\033[1;33m" << (isLeft ? "├──" : "└──" );
    std::cout << "\033[0m";

    // Print the value of the node
    std::cout << "\033[1;32m" << " " << n->data << std::endl;
    std::cout << "\033[0m";

    // Enter the next tree level - left and right branch
    print(n->left, prefix + (isLeft ? "|   " : "    "), true);
    print(n->right, prefix + (isLeft ? "|   " : "    "), false);
  }
}
