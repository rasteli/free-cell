#include <iostream>
#include <iomanip>

#include "stack.h"
#include "card.h"
#include "utils.h"

int main() {
  Card top;
  int from, to, foundations_completed = 0;
  bool insert_left, remove_left, from_stack, push_success, pop_success;
  
  // Pilhas de jogo
  Stack tableaus[4] = {
    Stack(), Stack(), Stack(), Stack(), 
  };

  // "Pilhas" de saída
  Card foundations[4] = {
    Card(), Card(), Card(), Card()
  };

  Card free_cells[4] = {
    Card(), Card(), Card(), Card()
  };

  utils::populate_tableaus(tableaus, 4);

  while (foundations_completed < 4) {
    // Limpa o console
    std::cout << "\033[2J\033[1;1H";

    utils::print_help();
    utils::print_cells(tableaus, foundations, free_cells, 4);

    std::cout << "Faça a jogada: ";
    std::cin >> from >> to;
    std::cin.ignore();

    if (from > 7 && from < 12) {
      from_stack = false;
      // <FC> Subtrai-se 8 do índice (from), pois o vetor free_cells tem 4 elementos
      // (índices de 0 a 3) e as free cells são informadas pelo usuário como um
      // inteiro no intervalo [8, 11].
      pop_success = utils::remove_free_cell(free_cells, top, from - 8);
    } else if (from >= 0 && from <= 7) {
      from_stack = true;
      
      utils::index(from, remove_left);
      pop_success = tableaus[from].Pop(top, remove_left);
    }

    if (to > 7 && to < 12) {
      // Inserindo em free cell
      // Mesma ideia que <FC>
      push_success = utils::insert_free_cell(free_cells, top, to - 8);
    } else if (to >= 0 && to <= 7) {
      // Inserindo em pilha de jogo
      utils::index(to, insert_left);
      push_success = tableaus[to].Push(top, insert_left);
    } else if (to == 12) {
      // Inserindo em pilha de saída
      push_success = utils::insert_foundation(foundations, top, foundations_completed);
    }

    if (pop_success && !push_success) {
      // Se não foi possível inserir a carta, mas foi removida, ela é retornada ao lugar de origem.
      if (from_stack) {
        tableaus[from].Push(remove_left, top);
      } else {
        // Mesma ideia que <FC>
        utils::insert_free_cell(free_cells, top, from - 8);
      }
      
      std::cout << "Pressione ENTER para continuar...";
      std::cin.get();
    }
  }

  std::cout << "---------------------------------------------------------------------\n"
            << "Você ganhou o jogo! Parabéns!";

  return 0;
}
