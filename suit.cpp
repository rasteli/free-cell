#include <string>
#include "suit.h"

Suit::Suit(int t) {
  if (t < 1 || t > 4) {
    type = -1;
    color = "";
    return;
  }
  
  type = t;
  color = (t == 1 || t == 2) ? "Preto" : "Vermelho";
}

int Suit::Type() {
  return type;
}

std::string Suit::Color() {
  return color;
}