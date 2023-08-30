#include <iostream>

#include "stack.h"
#include "card.h"
#include "utils.h"

int main() {
  Card top;
  int from, to;
  bool insert_left, remove_left, from_stack, success;
  
  Stack stacks[6] = {
    // Pilhas de jogo
    Stack(), Stack(), Stack(), Stack(), 
    // Pilhas de saída
    Stack(), Stack()
  };

  Card free_cells[4] = {
    Card(), Card(), Card(), Card()
  };

  // n == 4, pois somente as pilhas de jogo são populadas.
  utils::populate_stacks(stacks, 4);

  while (true) {
    // Limpa o console
    std::cout << "\033[2J\033[1;1H";

    utils::print_help();
    utils::print_stacks(stacks, 4);
    utils::print_free_cells(free_cells, 4);

    std::cout << "Faça a jogada: ";
    std::cin >> from >> to;
    std::cin.ignore();

    if (from > 7 && from < 12) {
      from_stack = false;
      // <FC> Subtrai-se 8 do índice (from), pois o vetor free_cells tem 4 elementos
      // (índices de 0 a 3) e as free cells são informadas pelo usuário como um
      // inteiro no intervalo [8, 11].
      utils::remove_free_cell(free_cells, top, from - 8);
    } else if (from >= 0 && from <= 7) {
      from_stack = true;
      
      utils::index(from, remove_left);
      stacks[from].Pop(top, remove_left);
    }

    if (to > 7 && to < 12) {
      // Mesma ideia que <FC>
      success = utils::insert_free_cell(free_cells, top, to - 8);
    } else if (to >= 0 && to <= 7) {
      utils::index(to, insert_left);
      success = stacks[to].Push(top, insert_left);
    }

    if (!success) {
      // Se não foi possível inserir a carta, ela é retornada ao lugar de origem.
      if (from_stack) {
        stacks[from].Push(remove_left, top);
      } else {
        // Mesma ideia que <FC>
        utils::insert_free_cell(free_cells, top, from - 8);
      }
      
      std::cout << "Pressione ENTER para continuar...";
      std::cin.get();
    }
  }

  return 0;
}
