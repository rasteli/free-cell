#include "suit.h"

#ifndef CARD_H
#define CARD_H

class Card {
  private:
    Suit suit;
    int name;

  public:
    Card(int n = -1, int s = -1);
    void Print();
    int GetName();
    Suit GetSuit();
};

#endif