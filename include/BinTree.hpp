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

      Node * root;

    public:
      /* @brief The class constructor. */
      BinTree(Node * r=new Node('-'))
        : root{r}
      { /*empty*/ }

      ~BinTree() {
        remove_node(root);
      }

      /* @brief Recursively removes the node from memory with all its sub-nodes.
       * @param A pointer to a node. */
      void remove_node(Node * node){
        if(node->left != nullptr)
          remove_node(node->left);

        if(node->right != nullptr)
          remove_node(node->right);

        delete node;
      }

      Node * getRoot(){
        return root;
      }

      void from_posfix(std::string posfix){
        if(posfix != "") {
          std::string::iterator strIt = posfix.end();
          Node * node = root;
          node->data = *(--strIt);
          while(strIt > posfix.begin()) {
            node->left = new Node(*(--strIt));
            node->right = new Node(*(--strIt));
            node = node->right;
          }
        }
      }

      std::string visit(Node * node) {
        return node->data;
      }

      std::string to_posfix(Node * node, std::string posfix=""){ // TODO: acho que a arvore está ao contrário. Ver no slide o codigo!
        if(node->left != nullptr)
          posfix += to_posfix(node->right);
        if(node->right != nullptr)
          posfix += to_posfix(node->left);
        posfix += visit(node);
        return posfix;
      }


      void print(Node * node, std::string prefix="", bool isLeft=false) {
        if(node != nullptr) {
          std::cout << prefix;

          std::cout << "\033[1;33m" << (isLeft ? "├──" : "└──" );
          cout << "\033[0m";

          // print the value of the node
          std::cout << "\033[1;32m" << " " << node->data << std::endl;
          cout << "\033[0m";

          // enter the next tree level - left and right branch
          print(node->left, prefix + (isLeft ? "|   " : "    "), true);
          print(node->right, prefix + (isLeft ? "|   " : "    "), false);
        }
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
