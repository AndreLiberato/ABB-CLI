#ifndef BINTREE_HPP_
#define BINTREE_HPP_

#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include "node.hpp"
#include "util.hpp"

namespace tree {


  class BinTree {
    private:
      
      Node* root;  //!< The root node.
      uint64_t number_of_nodes;

      /*
      * @brief Recursively removes the node from memory with all its sub-nodes.
      * @param A pointer to a node.
      */
      void destroy_tree(Node* node);


    public:

      // @brief The class constructor.
      BinTree(Node* r=new Node())
      : root{r}, number_of_nodes{1}
      { /*empty*/ }

      // @brief The class destructor.
      ~BinTree();

      /*
       * @brief Gives the root node of the tree.
       * @return The root node of the tree.
       */
      Node* get_root();

      u_int64_t get_number_of_nodes();

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

      Node* search(Node* n, int v);

      void insert(int v);

      void remove(int v);

      Node* get_bigger_left(Node* n);

      /* 
       * @brief Prints the binary tree in a nice way.
       * @param node an Node containing the node that the tree is going to start to be printed. 
       * @param prefix a string to help indent the tree.
       * @param isLeft a bool to just to see if the node is a left one.
       */
      void print(Node* node, std::string prefix="", bool isLeft=false);

      void print_tree();

      /*
        1. int enesimoElemento (int n): retorna o n-ésimo elemento (contando a partir de 1) do percurso
          em ordem (ordem simétrica) da ABB.
      */
      Node* at(u_int64_t i);

      uint64_t position_of(int i);

      int median();

      double average(Node* n);

      void increment(Node* n, util::direction d);

      void decrement(Node* n, util::direction d);
      
      int64_t sum_nodes(Node* n, int64_t s=int64_t{0});

  };
}

#endif // BINTREE_HPP_
