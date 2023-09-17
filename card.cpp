// Gabriel Rasteli - 2136428

#include <iostream>
#include <string>
#include "card.h"
#include "suit.h"

Card::Card(int v, int s) {
  // v = [1 (ás), 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 (valete), 12 (dama) e 13 (rei)]
  // s = [1 (Espadas), 2 (Paus), 3 (Ouro), 4 (Copas)]
  if (v < 1 || v > 13 || s < 1 || s > 4) {
    value = -1;
    suit = Suit();
    return;
  };
  
  value = v;
  suit = Suit(s);
}

Suit Card::GetSuit() {
  return suit;
}

int Card::GetValue() {
  return value;
}