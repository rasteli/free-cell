#include "suit.h"

Suit::Suit(int t, std::string c) {
  type = t;
  color = c;
}

int Suit::Type() {
  return type;
}

std::string Suit::Color() {
  return color;
}