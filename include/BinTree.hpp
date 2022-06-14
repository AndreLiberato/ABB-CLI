#ifndef BINTREE_H_
#define BINTREE_H_
#include <iostream>
#include <string>

namespace bt {
  class BinTree {
    private:
      struct Node{
        std::string data; //!< The information we want to store in the node.
        Node * left;      //!< A pointer to the left node in the list.
        Node * right;     //!< A pointer to the right node in the list.

        //! Default Ctro.
        Node(const char &d=char{}, Node * l=nullptr, Node * r=nullptr)
          : data {d}, left{l}, right{r}
        { /*empty*/ }
      };

      Node * root = new Node();

    public:
      /* @brief The class constructor. */
      BinTree(Node * r=new Node())
        : root{r}
      { /*empty*/ }

      ~BinTree() {
        delete root;
      }

      Node * getRoot(){
        return root;
      }

      void from_posfix(std::string posfix){
        std::string::iterator strIt = posfix.end();
        Node * node = root;

        while(strIt > posfix.begin()) {
          node->left = new Node(*(--strIt));
          cout << "1) " << *strIt << endl;
          node->right = new Node(*(--strIt));
          cout << "2) " << *strIt << endl;
          node = node->right;
        }
      }

      std::string visit(Node * node) {
        return node->data;
      }

      std::string to_posfix(Node * node){
        if(node->left != nullptr)
          to_posfix(node->left);
        if(node->right != nullptr)
          to_posfix(node->right);
        cout << "to_posfix) " << visit(node) << endl;
        return visit(node);
      }


      /* @brief Gives the prefix representation of the tree.
       * @return An string containing the tree's representation in prefix notation. */
      std::string to_prefix(){
        return "";
      }

      /* @brief Gives the infix representation of the tree.
       * @return An string containing the tree's representation in infix notation. */
      std::string to_infix(){
        return "";
      }

  };
}

#endif // BINTREE_H_
