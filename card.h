#include "suit.h"

#ifndef CARD_H
#define CARD_H

class Card {
  private:
    Suit suit;
    int value;

  public:
    Card(int v = -1, int s = -1);
    int GetValue();
    Suit GetSuit();
};

#endif