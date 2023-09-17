// Gabriel Rasteli - 2136428

#include <string>
#include "card.h"

#ifndef UTILS_H
#define UTILS_H

namespace utils {
  void index(int &input, bool &left);
  void rindex(int &input, bool &left);
  void print_help();
  std::string pretty_card(Card card);
  void wait_for_user_input();
}

#endif
