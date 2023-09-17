// Gabriel Rasteli - 2136428

#include <iostream>
#include <string>
#include <iomanip>
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

void utils::populate_tableaus(Stack *tableaus, int n) {
  // pré-condição: tableaus é um vetor de pilhas de jogo de tamanho n
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
    bool left;
    int t_index, d_index;

    do {
      t_index = rand() % n;
      left = rand() % 2;
    } while(tableaus[t_index].Full(left));

    do {
      d_index = rand() % 52;
    } while(deck[d_index].GetValue() == -1);
    
    tableaus[t_index].Push(left, deck[d_index]);
    deck[d_index] = Card();
  }
}

void utils::print_help() {
  std::cout << "--------------------------------- FREE CELL ---------------------------------\n";

  std::cout << "A movimentação das cartas segue as seguintes regras:\n"
            << "  - Uma pilha de saída recebe cartas em ordem imediatamente crescente,\n"
            << "    do Ás ao Rei, todas do mesmo naipe.\n"
            << "  - Uma pilha de jogo recebe cartas com naipes de cores alternantes em\n"
            << "    ordem imediatamente decrescente.\n"
            << "  - Uma free cell recebe qualquer carta desde que não esteja já ocupada.\n"
            << "  - Toda carta de uma pilha de jogo é movida de seu topo e para ele.\n"
            << "    A ordem das pilhas de jogo segue de cima para baixo, ou seja, o topo\n"
            << "    é a carta mais acima.\n\n";

  std::cout << "Para jogar, insira o índice de onde quer tirar uma carta seguido de um espaço e o índice de onde quer colocá-la.\n"
            << "Por exemplo, se quiser mover a carta do topo da pilha 4 para a free cell 10, insira: 4 10.\n\n"
            << "O jogo é ganho quando todas as pilhas de saída forem preenchidas. Note que o estado inicial do jogo\n"
            << "é aleatório, portanto talvez não haja uma solução.\n\n";

  std::cout << "Naipes pretos: Espadas e Paus\n"
            << "Naipes vermelhos: Ouro e Copas\n\n";
}

void utils::print_cells(Stack *tableaus, Card *foundations, Card *free_cells, int n) {
  // pré-condição: tableaus é um vetor de pilhas de jogo, foundations e free_cells são
  // vetores de Cards inicializadas. Os três vetores têm tamanho n.
  // pós-condição: As células de tableaus são impressas na tela verticalmente e as
  // células de foundations e free_cells, horizontalmente.
  
  Stack aux[n];
  
  std::cout << "Pilhas de Jogo\n---------------------------------\n";

  for (int i = 0; i < n; i++)
    aux[i] = tableaus[i];

  for (int i = 0; i < max_items; i++) {
    for (int j = 0; j < n; j++) {
      for (int left = 1; left >= 0; left--) {
        std::cout << std::left << std::setw(10);

        if (aux[j].Empty(left)) {
          std::cout << "[   ]";
          continue;
        }
          
        Card top;
        aux[j].Pop(top, left);
        std::cout << pretty_card(top);
      }
    }

    std::cout << '\n';
  }

  // Índices
  for (int i = 0; i <= 7; i++)
    std::cout << "  " << std::setw(8) << i;
  
  std::cout << "\n\n";
  std::cout << "Free Cells\n---------------------------------\n";

  for (int i = 0; i < n; i++) {
    if (free_cells[i].GetValue() == -1) {
      std::cout << "[   ] ";
    } else {
      std::cout << pretty_card(free_cells[i]) << ' ';
    }
  }

  // Índices
  std::cout << '\n' << std::right
            << std::setw(3) << 8 << std::setw(6) << 9 
            << std::setw(7) << 10 << std::setw(6) << 11 
            << "\n\n";

  std::cout << "Pilhas de Saída\n---------------------------------\n";

  for (int i = 0; i < n; i++) {
    if (foundations[i].GetValue() == -1) {
      std::cout << "[   ] ";
    } else {
      std::cout << pretty_card(foundations[i]) << ' ';
    }
  }

  // Índices
  std::cout << '\n'
            << std::setw(4) << 12 << std::setw(6) << 12
            << std::setw(6) << 12 << std::setw(6) << 12
            << "\n\n";
}

std::string utils::pretty_card(Card card) {
  std::string name, suit;

  std::string names[13] = {
    "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
    "Joker", "Queen", "King"
  };

  std::string suits[4] = {
    "Espadas", "Paus", "Ouro", "Copas"
  };

  name = names[card.GetValue() - 1];
      
  // Se o nome for uma palavra (Ás, Valete, Dama ou Rei),
  // name será somente o primeiro caractere dela.
  if (card.GetValue() == 1 || card.GetValue() > 10) {
    name = name.at(0);
  }

  suit = suits[card.GetSuit().Type() - 1].at(0);

  return '[' + name + '|' + suit + "]";
}

bool utils::insert_free_cell(Card *free_cells, Card card, int index) {
  // pré-condição: free_cells é um vetor de Cards inicializadas e a free cell na posição index não está ocupada.
  // pós-condição: card é inserida em free_cells na posição index.
  
  if (free_cells[index].GetValue() != -1) {
    std::cout << "\nImpossível inserir: free cell ocupada.\n";
    return false;
  }

  free_cells[index] = card;
  return true;
}

bool utils::remove_free_cell(Card *free_cells, Card &card, int index) {
  // pré-condição: free_cells é um vetor de Cards inicializadas e a free cell na posição index não está vazia.
  // pós-condição: card é removida de free_cells na posição index.
  
  if (free_cells[index].GetValue() == -1) {
    std::cout << "\nImpossível remover: free cell vazia.\n";
    return false;
  }

  card = free_cells[index];
  free_cells[index] = Card();
  return true;
}

bool utils::insert_foundation(Card *foundations, Card card, int &foundations_completed) {
  // pré-condição: foundations é um vetor de Cards inicializadas e a carta na posição
  // em que card será inserida não é um Rei, tem mesmo naipe e valor menor em 1 que card.
  // pós-condição: card é inserida em foundations e foundations_completed é incrementado
  // em 1 se card for um Rei.
  
  int suit = card.GetSuit().Type();
  int index = suit - 1;

  Card last_card = foundations[index];
  
  if (last_card.GetValue() == 13) {
    std::cout << "\nPilha de saída cheia. Não é possível inserir.\n";
    return false;
  }

  // O valor -1 de uma carta é sentinela; quer dizer, a posição está marcada para inserção
  // como se estivesse vazia.
  if (last_card.GetValue() == -1 && card.GetValue() != 1) {
    std::cout << "\nSomente um Ás pode ser inserido em uma pilha de saída vazia.\n";
    return false;
  } else if (last_card.GetValue() != -1) {
    if (suit != last_card.GetSuit().Type()) {
      std::cout << "\nNão é possível inserir " << pretty_card(card) << " em " 
                << pretty_card(last_card) << "."
                << " Os naipes devem ser iguais.\n";

      return false;
    }

    if (card.GetValue() != last_card.GetValue() + 1) {
      std::cout << "\nNão é possível inserir " << pretty_card(card) << " em " 
                << pretty_card(last_card) << "."
                << " O valor da carta inserida deve ser maior em 1.\n";

      return false;
    }
  }

  foundations[index] = card;
  if (card.GetValue() == 13) foundations_completed++;

  return true;
}
