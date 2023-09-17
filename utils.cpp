// Gabriel Rasteli - 2136428

#include <iostream>
#include <string>

#include "utils.h"
#include "card.h"

void utils::wait_for_user_input() {
  std::cout << "Pressione ENTER para continuar...";
  std::cin.get();
}

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

void utils::rindex(int &input, bool &left) {
  if (!left) input = input * 2 + 1;
  else input *= 2;
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
