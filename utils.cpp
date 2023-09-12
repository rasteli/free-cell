#include <iostream>
#include <ctime>

#include "utils.h"
#include "stack.h"

void utils::index(int &input, bool &left) {
  // pré-condição: 0 <= input <= 7
  // pós-condição: 0 <= input <= 3 e left == true || false
  if (input % 2 == 0) {
    input /= 2;
    left = true;
  } else {
    input = (input - 1) / 2;
    left = false;
  }
}

void utils::populate_stacks(Stack *stacks, int n) {
  // pré-condição: stacks é um array de pilhas de tamanho n
  // pós-condição: as pilhas de jogo estão aleatoriamente populadas com as 52 cartas
  srand(time(0));

  int i = 0;
  Card deck[52];

  for (int j = 1; j <= 13; j++) {
    for (int k = 1; k <= 4; k++) {
      deck[i++] = Card(j, k);
    }
  }

  for (int c = 0; c < i; c++) {
    int index;
    bool left;

    do {
      index = rand() % n;
      left = rand() % 2;
    } while(stacks[index].Full(left));
    
    stacks[index].Push(left, deck[c]);
  }
}

void utils::print_stacks(Stack *stacks, int n) {
  std::cout << "Topos\n---------------------------------\n";

  for (int i = 0; i < n - 2; i++) {
    Card top;
    
    for (int left = 1; left >= 0; left--) {
      stacks[i].Top(top, left);
      std::cout << pretty_card(top) << ' ';
    }
  }

  std::cout << "\n  0     1     2     3     4     5     6     7\n\n";

  std::cout << "Saída\n---------------------------------\n";

  for (int i = 4; i < n; i++) {
    Card top;
    
    for (int left = 1; left >= 0; left--) {
      if (stacks[i].Empty(left)) {
        std::cout << "[   ] ";
      } else {
        stacks[i].Top(top, left);
        std::cout << pretty_card(top) << ' ';
      }
    }
  }

  std::cout << "\n  12    12    12    12\n\n";
}

void utils::print_help() {
  std::cout << "--------------------------------- FREE CELL ---------------------------------\n"
            << "Pretos: Espadas e Paus\n"
            << "Vermelhos: Ouro e Copas\n\n";
}

std::string utils::pretty_card(Card card) {
  std::string name, suit;

  std::string names[13] = {
    "As", "2", "3", "4", "5", "6", "7", "8", "9", "10",
    "Valete", "Dama", "Rei"
  };

  std::string suits[4] = {
    "Espadas", "Paus", "Ouro", "Copas"
  };

  name = names[card.GetName() - 1];
      
  // Se o nome for uma palavra (Ás, Valete, Dama ou Rei),
  // name será somente o primeiro caractere dela.
  if (card.GetName() == 1 || card.GetName() > 10) {
    name = name.at(0);
  }

  suit = suits[card.GetSuit().Type() - 1].at(0);

  return '[' + name + '|' + suit + "]";
}

void utils::print_free_cells(Card *free_cells, int n) {
  std::cout << "Free Cells\n---------------------------------\n";

  for (int i = 0; i < n; i++) {
    Card card = free_cells[i];

    if (card.GetName() == -1) {
      std::cout << "[   ] ";
    } else {
      std::cout << pretty_card(card) << ' ';
    }
  }

  std::cout << "\n  8     9     10     11\n\n";
}

bool utils::insert_free_cell(Card *free_cells, Card card, int index) {
  if (free_cells[index].GetName() != -1) {
    std::cout << "\nImpossível inserir: free cell ocupada.\n";
    return false;
  }

  free_cells[index] = card;
  return true;
}

void utils::remove_free_cell(Card *free_cells, Card &card, int index) {
  if (free_cells[index].GetName() == -1) {
    std::cout << "\nImpossível remover: free cell vazia.\n";
    return;
  }

  card = free_cells[index];
  free_cells[index] = Card();
}
