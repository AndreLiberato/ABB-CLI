#include "bin_tree.hpp"
#include "cli.hpp"
#include "util.hpp"

using namespace tree;
using namespace util;
using namespace cli;

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
  std::string entry;
  std::string command;
  std::string value;
  command_list_t command_list;
  uint64_t pos;

  Node* node;
  BinTree* tree = nullptr;
  Node* node_temp = nullptr;

  bool for_read = false;
  
  while (true) {

    std::cout << "ABB_CLI> ";

    if (!for_read) {
      std::getline(std::cin, entry);
    } else {
      if (!command_list.empty()) {
        entry = command_list.front();
        for_read = true;
        command_list.erase(command_list.begin());
      } else {
        for_read = false;
        continue;
      }
    }

    command = split(entry).front();
    value = split(entry).back();

    switch (get_command(command)) {
      case command::create:
        std::cout << "Criando árvore - Raíz com valor: " << value << std::endl;
        if (tree == nullptr) {
          node = new Node(stoi(value));
          tree = new BinTree(node);
          std::cout << "Árvore criada com sucesso" << std::endl;
        } else {
          std::cout << "ABB já instânciada" << std::endl;
        }
        break;
      case command::insert:
        tree->insert(stoi(value));
        break;
      case command::remove:
        tree->remove(stoi(value));
        break;
      case command::search:
        node_temp = tree->search(tree->get_root(), stoi(value));
        if (node_temp != nullptr and node_temp->data == stoi(value)) {
          std::cout << "Nó encontrado" << std::endl;
          tree->print(node_temp);
        } else {
          std::cout << "Nó não encontrado" << std::endl;
        }
        break;
      case command::at:
        node_temp = tree->at(stoi(value));
        if (node_temp != nullptr) {
          std::cout << "Posição " << value << ": " << node_temp->data << std::endl;
        } else {
          std::cout << "Posição não existe" << std::endl;
        }
        break;
      case command::position_of:
        pos = tree->position_of(stoi(value));
        if (pos != 0) {
          std::cout << "Nó com valor " << value << " encontra-se na posição " << pos << std::endl;
        } else {
          std::cout << "Nó não encontrado" << std::endl;
        }
        break;
      case command::median:
        std::cout << tree->median() << std::endl;
        break;
      case command::average:
        std::cout << "Média: " << tree->average(tree->get_root()) << std::endl;
        break;
      case command::is_full:
        std::cout << "Função ainda não implementada" << std::endl;
        break;
      case command::is_complete:
        std::cout << "Função ainda não implementada" << std::endl;
        break;
      case command::pre_order:
        tree->pre_order(tree->get_root());
        std::cout << std::endl;
        break;
      case command::print:
        tree->print_tree();
        break;
      case command::read:
        command_list = read_file(value);
        for_read = true;
        break;
      case command::exit:
        delete tree;
        return EXIT_SUCCESS;
        break;
      case command::none:
        std::cout << "Instrução não reconhecida" << std::endl;
        break;
    }

    entry.clear();
    command.clear();
    value.clear();
  }
  return 0;
}