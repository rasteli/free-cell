#include <iostream>
#include <string>

#include "stack.h"
#include "card.h"

Stack::Stack() {
  top_left = -1;
  top_right = -1;
}

bool Stack::Empty(bool left) {
  if (left) return top_left == -1;

  return top_right == -1;
}

bool Stack::Full(bool left) {
  if (left) return top_left == max_items - 1;

  return top_right == max_items - 1;
}

void Stack::Push(Card item, bool left) {
  if (Full(left)) {
    std::cout << "Pilha cheia. Não é possível inserir.\n";
    return;
  }

  std::string suit_color = item.GetSuit().Color();
  
  if (!Empty(left)) {
    Card last_item;

    Top(last_item, left);

    if (suit_color == last_item.GetSuit().Color()) return;
    if (item.GetName() + 1 != last_item.GetName()) return;
  }

  if (left) {
    items[++top_left] = item;
  } else {
    items[25 - ++top_right] = item;
  }
}

void Stack::Pop(Card &item, bool left) {
  if (Empty(left)) {
    std::cout << "Pilha vazia. Não há o que remover.\n";
    return;
  }
  
  if (left) {
    item = items[top_left--];
  } else {
    item = items[25 - top_right--];
  }
}

void Stack::Top(Card &item, bool left) {
  if (Empty(left)) {
    std::cout << "Pilha vazia. Não há elemento no topo.\n";
    return;
  }
  
  if (left) {
    item = items[top_left];
  } else {
    item = items[25 - top_right];
  }
}
