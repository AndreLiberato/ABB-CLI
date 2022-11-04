#ifndef NODE_HPP_
#define NODE_HPP_

#include <iostream>

namespace tree {

  struct Node{
    int data;           //!< The information we want to store in the node.
    Node* left;         //!< A pointer to the left node.
    Node* right;        //!< A pointer to the right node.
    uint8_t nodesLeft;  //!< Number of nodes on the left.
    uint8_t nodesRight; //!< Number of nodes on the right.
    
    // Constructor of Node
    Node(const int d=int{}, Node* l=nullptr, Node* r=nullptr, uint8_t nL=uint8_t{}, uint8_t nR=uint8_t{})
    : data{d}, left{l}, right{r}, nodesLeft{nL}, nodesRight{nR}
    { /*empty*/ }

    bool has_left();

    bool has_right();
  };

}


#endif
