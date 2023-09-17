// Gabriel Rasteli - 2136428

#include "stack.h"
#include "card.h"

#ifndef CELLS_H
#define CELLS_H

namespace cells {
  void populate_tableaus(Stack *tableaus, int n);
  void print_cells(Stack *tableaus, Card *foundations, Card *free_cells, int n);
  bool remove_free_cell(Card *free_cells, Card &card, int index);
  bool insert_free_cell(Card *free_cells, Card card, int index);
  bool insert_foundation(Card *foundations, Card card, int &foundations_completed);
}

#endif
