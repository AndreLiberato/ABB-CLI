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

u_int64_t BinTree::get_number_of_nodes() {
  return this->number_of_nodes;
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
  
  std::cout << node->data << " ";

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

  util::node_backtrack_t node_htr;
  util::node_path_dir_t history;

  while (true) {

    if (node_it->data > v) {
      this->increment(node_it, util::direction::left);

      if (!node_it->has_left()) {
        node_it->left = new Node(v);
        this->number_of_nodes++;
        break;
      }

      history = {node_it, util::direction::left};

      node_htr.push(history);

      node_it = node_it->left;
    } else if (node_it->data < v) {
      this->increment(node_it, util::direction::right);

      if (!node_it->has_right()) {
        node_it->right = new Node(v);
        this->number_of_nodes++;
        break;
      }

      history = {node_it, util::direction::right};

      node_htr.push(history);

      node_it = node_it->right;
    } else {
      std::cout << "Valor já existente!" << std::endl;
      while (!node_htr.empty()) {
        this->decrement(node_htr.top().first, node_htr.top().second);
        node_htr.pop();
      }
      break;
    }
  }
}

void BinTree::decrement(Node* n, util::direction d) {
  switch (d) {
    case util::direction::left:
      n->on_left-=1;
      break;
    case util::direction::right:
      n->on_right-=1;
      break;
    case util::direction::none:
      break;
  }
}

void BinTree::increment(Node* n, util::direction d) {
  switch (d) {
    case util::direction::left:
      n->on_left+=1;
      break;
    case util::direction::right:
      n->on_right+=1;
      break;
    case util::direction::none:
      break;
  }
}

void BinTree::remove(int v) {
  Node* node_it = this->get_root();
  Node* root = node_it;

  util::node_backtrack_t node_htr;
  util::node_path_dir_t history;

  while (true) {

    if (node_it->data > v and node_it->has_left()) {
      history = {node_it, util::direction::left};
      node_htr.push(history);
      root = node_it;
      node_it = node_it->left;
    } else if (node_it->data < v and node_it->has_right()) {
      history = {node_it, util::direction::right};
      node_htr.push(history);
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

      while (!node_htr.empty()) {
        this->decrement(node_htr.top().first, node_htr.top().second);
        node_htr.pop();
      }
      delete node_it;
      this->number_of_nodes--;
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
  if (n == nullptr || n->data == v) {
    return n;
  }

  if (n->data > v) {
    return search(n->left, v);
  }
  else {
    return search (n->right, v);
  }
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
    std::cout << "\033[1;32m" << " " << n->on_left << " " << n->data << " " << n->on_right << std::endl;
    std::cout << "\033[0m";

    // Enter the next tree level - left and right branch
    print(n->left, prefix + (isLeft ? "|   " : "    "), true);
    print(n->right, prefix + (isLeft ? "|   " : "    "), false);
  }
}

Node* BinTree::at(uint64_t i) {
  if (i > this->number_of_nodes) {
    return nullptr;
  }

  Node* node_it = this->get_root();
  
  while (true) {
    if (node_it->on_left+1 == i or (node_it->on_left == 0 and node_it->on_right == 0)) {
      return node_it;
    }

    if(i <= node_it->on_left and node_it->has_left()) {
      node_it = node_it->left;
    } else if (i >= node_it->on_right and node_it->has_right()) {
      i = i-(node_it->on_left+1);
      node_it = node_it->right;
    }
  }
  
  return nullptr;
}

uint64_t BinTree::position_of(int i) {
  Node* node_it = this->get_root();
  uint64_t pos_count {0};

  while (true) {
    if (i < node_it->data and node_it->has_left()) {
      node_it = node_it->left;
    } else if (i > node_it->data and node_it->has_right()) {
      pos_count += node_it->on_left+1;
      node_it = node_it->right;
    } else if (i == node_it->data){
      pos_count += node_it->on_left+1;
      return pos_count;
    } else {
      break;
    }
  }

  return 0;
}

int BinTree::median() {
  return this->at(floor(this->number_of_nodes/2))->data;
}

double BinTree::average(Node* n) {
  return sum_nodes(n)/(double)this->number_of_nodes;
}

int64_t BinTree::sum_nodes(Node* n, int64_t s) {
  s = n->data;

  if(n->left != nullptr)
    s += sum_nodes(n->left, s);

  if(n->right != nullptr)
    s += sum_nodes(n->right, s);

  return s;
}