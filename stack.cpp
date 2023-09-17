// Gabriel Rasteli - 2136428

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
  // pré-condição: pilha já inicializada, não cheia e a carta no topo da pilha 
  // tem cor diferente de item e valor maior em 1.
  // pós-condição: item é inserido na pilha.
  
  if (Full(left)) {
    std::cout << "\nPilha cheia. Não é possível inserir.\n";
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

    if (item.GetValue() + 1 != last_item.GetValue()) {
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
  // pré-condição: pilha já inicializada.
  // pós-condição: item é inserido na pilha.
  
  int index = left ? ++top_left : (25 - ++top_right);
  items[index] = item;
}

bool Stack::Pop(Card &item, bool left) {
  // pré-condição: pilha já inicializada e não vazia.
  // pós-condição: item é removido da pilha.
  
  if (Empty(left)) {
    std::cout << "\nPilha vazia. Não há o que remover.\n";
    return false;
  }

  item = left ? items[top_left--] : items[25 - top_right--];
  return true;
}

void Stack::Top(Card &item, bool left) {
  // pré-condição: pilha já inicializada e não vazia.
  // pós-condição: item recebe o valor do topo da pilha e a pilha não é alterada.
  
  if (Empty(left)) {
    std::cout << "\nPilha vazia. Não há elemento no topo.\n";
    return;
  }
  
  item = left ? items[top_left] : items[25 - top_right];
}
