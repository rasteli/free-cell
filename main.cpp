#include <iostream>

#include "stack.h"
#include "card.h"
#include "utils.h"

int main() {
  Stack stacks[6] = {
    // Pilhas de jogo
    Stack(), Stack(), Stack(), Stack(), 
    // Pilhas de saída
    Stack(), Stack()
  };

  // n == 4, pois somente as pilhas de jogo são populadas.
  utils::populate_stacks(stacks, 4);

  while (true) {
    // Limpa o console
    std::cout << "\033[2J\033[1;1H";

    utils::print_help();
    utils::print_stacks(stacks, 4);

    int from, to;
    bool insert_left, remove_left;

    std::cout << "Faça a jogada: ";
    std::cin >> from >> to;
    std::cin.ignore();

    utils::index(from, remove_left);
    utils::index(to, insert_left);

    Card top;

    stacks[from].Pop(top, remove_left);
    bool push_success = stacks[to].Push(top, insert_left);

    if (!push_success) {
      // Se não foi possível inserir a carta, ela é retornada à pilha de origem.
      stacks[from].Push(remove_left, top);
      
      std::cout << "Pressione ENTER para continuar...";
      std::cin.get();
    }
  }

  return 0;
}
