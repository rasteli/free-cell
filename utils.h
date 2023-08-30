#include "stack.h"

#ifndef UTILS_H
#define UTILS_H

namespace utils {
  void index(int &input, bool &left);
  void populate_stacks(Stack *stacks, int n);
  void print_stacks(Stack *stacks, int n);
  void print_help();
  void print_free_cells(Card *free_cells, int n);
  std::string pretty_card(Card card);
  void remove_free_cell(Card *free_cells, Card &card, int index);
  bool insert_free_cell(Card *free_cells, Card card, int index);
}

#endif
