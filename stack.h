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

    bool Push(Card item, bool left); // Inserção pelo usuário
    void Push(bool left, Card item); // Inserção aleatória (início de jogo)

    bool Pop(Card &item, bool left);
    void Top(Card &item, bool left);
    
    bool Empty(bool left);
    bool Full(bool left);
};

#endif
