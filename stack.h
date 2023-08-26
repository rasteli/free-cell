#include "card.h"

#ifndef STACK_H
#define STACK_H

const int max_items = 13;

class Stack {
  private:
    Card items[max_items * 2];
    int top_left;
    int top_right;

  public:
    Stack();
    void Push(Card item, bool left);
    void Pop(Card &item, bool left);
    void Top(Card &item, bool left);
    bool Empty(bool left);
    bool Full(bool left);
};

#endif
