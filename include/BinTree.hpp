#ifndef BINTREE_HPP_
#define BINTREE_HPP_

#include <iostream>
#include <string>
#include "util.hpp"

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

  class BinTree {
    private:
      
      Node* root;  //!< The root node.

      /*
      * @brief Recursively removes the node from memory with all its sub-nodes.
      * @param A pointer to a node.
      */
      void destroy_tree(Node* node);


    public:

      // @brief The class constructor.
      BinTree(Node* r=new Node())
      : root{r}
      { /*empty*/ }

      // @brief The class destructor.
      ~BinTree();

      /*
       * @brief Gives the root node of the tree.
       * @return The root node of the tree.
       */
      Node* getRoot();

      /*
       * @brief Gives the data value of the node.
       * @param node: a arbitrary node.
       * @return The data in the node.
       */
      int visit(Node* node);

      /* 
       * @brief Gets a string containing the postfix notation for the tree.
       * @param postfix: just a variable to write the postfix notation in.
       * @param node an Node containing the node that the tree is going to start to be converted. 
       * @return A string containing the postfix notation.
       */
      void post_order(Node* node);


      /* 
       * @brief Gives the prefix representation of the tree.
       * @return An string containing the tree's representation in prefix notation.
       */
      void pre_order(Node* node);

      /* 
       * @brief Gives the infix representation of the tree.
       * @return An string containing the tree's representation in infix notation. 
       */
      void in_order(Node* node);

      void insert(int v);

      /* 
       * @brief Prints the binary tree in a nice way.
       * @param node an Node containing the node that the tree is going to start to be printed. 
       * @param prefix a string to help indent the tree.
       * @param isLeft a bool to just to see if the node is a left one.
       */
      void print(Node* node, std::string prefix="", bool isLeft=false);

  };
}

#endif // BINTREE_HPP_
