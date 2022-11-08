#ifndef NODE_HPP_
#define NODE_HPP_

#include <iostream>

namespace tree {

  struct Node{
    int data;           //!< The information we want to store in the node.
    Node* left;         //!< A pointer to the left node.
    Node* right;        //!< A pointer to the right node.
    uint64_t on_left;  //!< Number of nodes on the left.
    uint64_t on_right; //!< Number of nodes on the right.
    
    // Constructor of Node
    Node(const int d=int{0}, Node* l=nullptr, Node* r=nullptr, u_int64_t oL=uint64_t{0}, u_int64_t oR=uint64_t{0})
    : data{d}, left{l}, right{r}, on_left{oL}, on_right{oR}
    { /*empty*/ }

    bool has_left();

    bool has_right();
  };

}


#endif
