#include <string>

#ifndef SUIT_H
#define SUIT_H

class Suit {
  private:
    int type;
    std::string color;

  public:
    Suit(int t = -1, std::string c = "");
    int Type();
    std::string Color();
};

#endif