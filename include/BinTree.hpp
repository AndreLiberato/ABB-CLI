#ifndef BINTREE_H_
#define BINTREE_H_
#include <iostream>
#include <vector>
#include <string>

namespace bt {
  class BinTree {
    private:
      struct Node{
        int data;       //!< The information we want to store in the node.
        Node * left;  //!< A pointer to the left node in the list.
        Node * right; //!< A pointer to the right node in the list.

        //! Default Ctro.
        Node(const int &d=int{}, Node * l=nullptr, Node * r=nullptr)
          : data {d}, left{l}, right{r}
        { /*empty*/ }
      };

      std::vector<Node> tree; //<! The vector representation of the tree.

    public:
      /* @brief The class constructor. */
      explicit BinTree();

      /* @brief Gives the prefix representation of the tree.
       * @return An string containing the tree's representation in prefix notation. */
      std::string to_prefix();

      /* @brief Gives the infix representation of the tree.
       * @return An string containing the tree's representation in infix notation. */
      std::string to_infix();

      // TODO: Make gets and sets.
  };
}

#endif // BINTREE_H_
