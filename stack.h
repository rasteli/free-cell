#include "card.h"

#ifndef STACK_H
#define STACK_H

class Stack {
  private:
    Card items[26];
    int num_left_items;
    int num_right_items;

  public:
    Card* Items();
    void Add(Card item, bool left);
    void Remove(bool left);
    Stack();
};

#endif
