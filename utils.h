#include "stack.h"

#ifndef UTILS_H
#define UTILS_H

namespace utils {
  void index(int &input, bool &left);
  void populate_tableaus(Stack *tableaus, int n);
  void print_cells(Stack *tableaus, Card *foundations, Card *free_cells, int n);
  void print_help();
  std::string pretty_card(Card card);
  bool remove_free_cell(Card *free_cells, Card &card, int index);
  bool insert_free_cell(Card *free_cells, Card card, int index);
  bool insert_foundation(Card *foundations, Card card, int &foundations_completed);
}

#endif
