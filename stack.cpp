#include <iostream>
#include <string>

#include "stack.h"
#include "card.h"
#include "utils.h"

Stack::Stack() {
  top_left = -1;
  top_right = -1;
}

bool Stack::Empty(bool left) {
  return (left ? top_left : top_right) == - 1;
}

bool Stack::Full(bool left) {
  return (left ? top_left : top_right) == max_items - 1;
}

bool Stack::Push(Card item, bool left) {
  if (Full(left)) {
    std::cout << "Pilha cheia. Não é possível inserir.\n";
    return false;
  }

  if (!Empty(left)) {
    std::string suit_color = item.GetSuit().Color();
    Card last_item = left ? items[top_left] : items[25 - top_right];

    if (suit_color == last_item.GetSuit().Color()) {
      std::cout << "\nNão é possível inserir " << utils::pretty_card(item) << " em " 
                << utils::pretty_card(last_item) << "."
                << " As cores dos naipes devem ser diferentes.\n";

      return false;
    }

    if (item.GetName() + 1 != last_item.GetName()) {
      std::cout << "\nNão é possível inserir " << utils::pretty_card(item) << " em " 
                << utils::pretty_card(last_item) << "."
                << " O valor da carta inserida deve ser menor em 1.\n";

      return false;
    }
  }

  int index = left ? ++top_left : (25 - ++top_right);
  items[index] = item;

  return true;
}

void Stack::Push(bool left, Card item) {
  int index = left ? ++top_left : (25 - ++top_right);
  items[index] = item;
}

bool Stack::Push(Card item) {
  int suit = item.GetSuit().Type();
  // Inserir na pilha à esquerda se o naipe for Espadas ou Ouro.
  bool left = suit == 1 || suit == 3;

  if (Full(left)) {
    std::cout << "Pilha cheia. Não é possível inserir.\n";
    return false;
  }

  if (Empty(left) && item.GetName() != 1) {
    std::cout << "\nSomente um Ás pode ser inserido em uma pilha de saída vazia.\n";
    return false;
  } else if (!Empty(left)) {
    Card last_item = left ? items[top_left] : items[25 - top_right];

    if (suit != last_item.GetSuit().Type()) {
      std::cout << "\nNão é possível inserir " << utils::pretty_card(item) << " em " 
                << utils::pretty_card(last_item) << "."
                << " Os naipes devem ser iguais.\n";

      return false;
    }

    if (item.GetName() != last_item.GetName() + 1) {
      std::cout << "\nNão é possível inserir " << utils::pretty_card(item) << " em " 
                << utils::pretty_card(last_item) << "."
                << " O valor da carta inserida deve ser maior em 1.\n";

      return false;
    }
  }

  int index = left ? ++top_left : (25 - ++top_right);
  items[index] = item;

  return true;
}

void Stack::Pop(Card &item, bool left) {
  if (Empty(left)) {
    std::cout << "Pilha vazia. Não há o que remover.\n";
    return;
  }

  item = left ? items[top_left--] : items[25 - top_right--];
}

void Stack::Top(Card &item, bool left) {
  if (Empty(left)) {
    std::cout << "Pilha vazia. Não há elemento no topo.\n";
    return;
  }
  
  item = left ? items[top_left] : items[25 - top_right];
}
