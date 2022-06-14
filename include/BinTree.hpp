#ifndef BINTREE_H_
#define BINTREE_H_
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

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

      /* @brief Gives the index of the node's father using vector notation starting at index zero.
       * @return A non negative integer representing the index of the node's father if exists or -1 otherwise */
      int father(int index) {
        if (((index+1)/2)-1 < 0) {
          return -1;
        }
        return std::floor((index+1)/2)-1;
      }

      /* @brief Gives the index of the son to the left of the node using vector notation starting at index zero.
       * @return A non negative integer representing the index of the son to the left of the node */
      int leftSon(int index) {
        return ((index+1)*2)-1;
      }

      /* @brief Gives the index of the son to the right of the node using vector notation starting at index zero.
       * @return A non negative integer representing the index of the son to the right of the node */
      int rightSon(int index) {
        return ((index+1)*2);
      }

      void swap(int indexI, int indexJ) {
        Node aux = this->tree.at(indexI);
        this->tree.at(indexI) = this->tree.at(indexJ);
        this->tree.at(indexJ) = aux;
      }

      void up(int index) {
        int j = this->father(index);
        if (j >= 0) {
          if (this->tree.at(index).data > this->tree.at(j).data) {
            this->swap(index, j);
            this->up(j);
          }
        }
      }

      void down(int index, int treeSize) {
        int j = this->leftSon(index);
        if (j < treeSize) {
          if (j+1 < treeSize) {
            if (this->tree.at(j+1).data > this->tree.at(j).data) {
              ++j;
            }
            if (this->tree.at(index).data < this->tree.at(j).data) {
              this->swap(index, j);
              this->down(j, treeSize);
            }
          }
        }
      }

      void remove(int treeSize) {
        if (treeSize >= 0) {
          Node first = this->tree.at(0);
          this->tree.at(0) = this->tree.at(treeSize);
          --treeSize;
          this->down(1, treeSize);
        } else {
          std::cout << "Heap vazia" << std::endl;
        }
      }

      // TODO: Make gets and sets.
  };
}

#endif // BINTREE_H_
