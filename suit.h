// Gabriel Rasteli - 2136428

#include <string>

#ifndef SUIT_H
#define SUIT_H

class Suit {
  private:
    int type;
    std::string color;

  public:
    Suit(int t = -1);
    int Type();
    std::string Color();
};

#endif