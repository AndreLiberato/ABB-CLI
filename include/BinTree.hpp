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

      Node * root;  //!< The root node.

    public:
      // @brief The class constructor.
      BinTree(Node * r=new Node('-'))
        : root{r}
      { /*empty*/ }

      // @brief The class destructor.
      ~BinTree() {
        remove_node(root);
      }

      /*
       * @brief Recursively removes the node from memory with all its sub-nodes.
       * @param A pointer to a node.
       */
      void remove_node(Node * node) {
        if(node->left != nullptr)
          remove_node(node->left);

        if(node->right != nullptr)
          remove_node(node->right);

        delete node;
      }

      /*
       * @brief Gives the root node of the tree.
       * @return The root node of the tree.
       */
      Node * getRoot() {
        return root;
      }

      /*
       * @brief Gives the data value of the node.
       * @param node: a arbitrary node.
       * @return The data in the node.
       */
      std::string visit(Node * node) {
        if(node != nullptr) 
          return node->data;
        else
          return "ERROR"; // TODO: dá pra melhorar isso!
      }

      /*
       * @brief Gets a string in posfix notation and converts it to a binary tree.
       * @param posfix: a string containing the posfix notation.
       */
      std::string from_posfix(Node * node, std::string posfix) {
        //cout << posfix << " -- " << posfix.back() << endl;
        if(!posfix.empty()) {
          if(posfix.back() == '+' || posfix.back() == '-' || posfix.back() == '*' || posfix.back() == '/') {
            node->right = new Node();
            node->left = new Node();

            node->data = posfix.back();

            posfix.pop_back();
            posfix = from_posfix(node->left, posfix);
            posfix = from_posfix(node->right, posfix);
            return posfix;
          }

          else {
            node->data = posfix.back();
            posfix.pop_back();
            return posfix;
          }
        }
        return "";
      }

      /* 
       * @TODO Ver se a implementação está correta. Tem no slide!
       * @brief Gets a string containing the posfix notation for the tree.
       * @param posfix: just a variable to write the posfix notation in.
       * @param node an Node containing the node that the tree is going to start to be converted. 
       * @return A string containing the posfix notation.
       */
      std::string to_posfix(Node * node, std::string posfix="") {
        if(node->right != nullptr)
          posfix += to_posfix(node->right);
        if(node->left != nullptr)
          posfix += to_posfix(node->left);
        posfix += visit(node);
        return posfix;
      }

      /* 
       * @brief Gives the prefix representation of the tree.
       * @return An string containing the tree's representation in prefix notation.
       */
      std::string to_prefix() {
        return "";
      }

      /* 
       * @brief Gives the infix representation of the tree.
       * @return An string containing the tree's representation in infix notation. 
       */
      std::string to_infix(Node * node, std::string posfix="") {
        // Checks if the node is a leaf or root.
        posfix += 
          (((node->left == nullptr && node->right == nullptr) || node == root) ? "" : "(");

        if(node->left != nullptr)
          posfix += to_infix(node->left);

        posfix += visit(node);

        if(node->right != nullptr)
          posfix += to_infix(node->right);

        // Checks if the node is a leaf or root.
        posfix += 
          (((node->left == nullptr && node->right == nullptr) || node == root) ? "" : ")");
        return posfix;
      }

      /* 
       * @brief Prints the binary tree in a nice way.
       * @param node an Node containing the node that the tree is going to start to be printed. 
       * @param prefix a string to help indent the tree.
       * @param isLeft a bool to just to see if the node is a left one.
       */
      void print(Node * node, std::string prefix="", bool isLeft=false) {
        if(node != nullptr) {
          std::cout << "\033[0;33m" << prefix;
          cout << "\033[0m";

          std::cout << "\033[1;33m" << (isLeft ? "├──" : "└──" );
          cout << "\033[0m";

          // Print the value of the node
          std::cout << "\033[1;32m" << " " << node->data << std::endl;
          cout << "\033[0m";

          // Enter the next tree level - left and right branch
          print(node->left, prefix + (isLeft ? "|   " : "    "), true);
          print(node->right, prefix + (isLeft ? "|   " : "    "), false);
        }
      }

  };
}

#endif // BINTREE_H_
