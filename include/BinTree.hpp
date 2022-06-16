#ifndef BINTREE_H_
#define BINTREE_H_
#include <iostream>
#include <string>

namespace bt {
  class BinTree {
    private:
      struct Node{
        std::string data; //!< The information we want to store in the node.
        Node* left;       //!< A pointer to the left node in the list.
        Node* right;      //!< A pointer to the right node in the list.

        //! Default Ctro.
        Node(const char &d=char{}, Node * l=nullptr, Node * r=nullptr)
          : data {d}, left{l}, right{r}
        { /*empty*/ }
      };

      Node* root;  //!< The root node.

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
       * @brief Gets a string and checking if the last character is an operator.
       * @param postfix: a string containing the postfix notation.
       * @return True if last character is a operator, false otherwise.
       */
      bool is_operator(char str) {
        //std::cout << "Verificação:" << str << std::endl;
        return (
            ( str == '+' ||
              str == '-' ||
              str == '*' ||
              str == '/' ||
              str == '^' ) ? true : false);
      }

      /*
       * @brief Gets a string in postfix notation and converts it to a binary tree.
       * @param postfix: a string containing the postfix notation.
       */
      std::string from_postfix(Node* node, std::string postfix) {
        if( !postfix.empty() ) {
          if( is_operator(postfix.back()) ) {
            /* 
             * Note: To build a binary tree using postfix notation, 
             * use pre-order traversal on right first
             */

            node->right = new Node();
            node->left = new Node();

            node->data = postfix.back();

            postfix.pop_back();
            postfix = from_postfix(node->right, postfix);
            postfix = from_postfix(node->left, postfix);
            return postfix;
          }

          else {
            node->data = postfix.back();
            postfix.pop_back();
            return postfix;
          }
        }
        return "";
      }

      /*
       * @brief Gets a string in prefix notation and converts it to a binary tree.
       * @param prefix: a string containing the prefix notation.
       */
      std::string from_prefix(Node* node, std::string prefix) {
        if( !prefix.empty() ) {
          if( is_operator( prefix.front() )) {
            /* 
             * Note: To build a binary tree using prefix notation, 
             * use preorder traversal on right first
             */

            node->left = new Node();
            node->right = new Node();

            node->data = prefix.front();

            prefix.erase(prefix.begin());

            prefix = from_prefix(node->left, prefix);
            prefix = from_prefix(node->right, prefix);

            return prefix;
          }

          else {
            node->data = prefix.front();

            prefix.erase(prefix.begin());

            return prefix;
          }
        }
        return "";
      }

      /* 
       * @brief Gets a string containing the postfix notation for the tree.
       * @param postfix: just a variable to write the postfix notation in.
       * @param node an Node containing the node that the tree is going to start to be converted. 
       * @return A string containing the postfix notation.
       */
      std::string to_postfix(Node* node, std::string postfix="") {
        //In postfix, first access the subtree on the left
        if (node->left != nullptr)
          postfix += to_postfix(node->left);

        //then on the right
        if (node->right != nullptr)
          postfix += to_postfix(node->right);

        //and then visit the node.
        postfix += visit(node);

        return postfix;
      }

      /* 
       * @brief Gives the prefix representation of the tree.
       * @return An string containing the tree's representation in prefix notation.
       */
      std::string to_prefix(Node * node, std::string prefix="") {
        prefix += visit(node);

        if (node->left != nullptr)
          prefix += to_prefix(node->left);

        if (node->right != nullptr)
          prefix += to_prefix(node->right);

        return prefix;
      }

      /* 
       * @brief Gives the infix representation of the tree.
       * @return An string containing the tree's representation in infix notation. 
       */
      std::string to_infix(Node * node, std::string infix="") {
        // Checks if the node is a leaf or root.
        infix += (
            ((node->left == nullptr && node->right == nullptr) 
             || node == root) ? "" : "(" 
            );

        if(node->left != nullptr)
          infix += to_infix(node->left);

        infix += visit(node);

        if(node->right != nullptr)
          infix += to_infix(node->right);

        // Checks if the node is a leaf or root.
        infix += (
            ((node->left == nullptr && node->right == nullptr) 
             || node == root) ? "" : ")"
            );
        return infix;
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
