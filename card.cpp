#include <iostream>
#include <string>
#include "card.h"
#include "suit.h"

Card::Card(int n, int s) {
  // n = [1 (ás), 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 (valete), 12 (dama) e 13 (rei)]
  // s = [1 (Espadas), 2 (Paus), 3 (Ouro), 4 (Copas)]
  if (n < 1 || n > 13 || s < 1 || s > 4) {
    name = -1;
    suit = Suit(-1, "");
    return;
  };
  
  std::string color = (s == 1 || s == 2) ? "Preto" : "Vermelho";
  
  name = n;
  suit = Suit(s, color);
}

void Card::Print() {
  if (name == -1 || suit.Type() == -1) return;

  std::string names[13] = {
    "Ás", "2", "3", "4", "5", "6", "7", "8", "9", "10",
    "Valete", "Dama", "Rei"
  };

  std::string suits[4] = {
    "Espadas", "Paus", "Ouro", "Copas"
  };
  
  std::cout << names[name - 1] << " de " << suits[suit.Type() - 1] << ' ' << suit.Color() << '\n';
}

Suit Card::GetSuit() {
  return suit;
}

int Card::GetName() {
  return name;
}