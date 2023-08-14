#include <string>

#include "stack.h"
#include "card.h"

Card* Stack::Items() {
  return items;
}

void Stack::Add(Card item, bool left) {
  std::string suit_color = item.GetSuit().Color();
  Card last_item;

  if (left) {
    if (num_left_items > 0) last_item = items[num_left_items - 1];

    if (num_left_items > 0 && suit_color == last_item.GetSuit().Color()) return;
    if (num_left_items > 0 && item.GetName() > last_item.GetName()) return;

    items[num_left_items++] = item;
  } else {
    if (num_right_items > 0) last_item = items[25 - num_right_items + 1];

    if (num_right_items > 0 && suit_color == last_item.GetSuit().Color()) return;
    if (num_right_items > 0 && item.GetName() > last_item.GetName()) return;

    items[25 - num_right_items++] = item;
  }
}

void Stack::Remove(bool left) {
  if (left && num_left_items > 0) {
    items[--num_left_items] = Card(-1, -1);
  }
  
  if (!left && num_right_items > 0) {
    items[25 - --num_right_items] = Card(-1, -1);
  }
}

Stack::Stack() {
  num_left_items = 0;
  num_right_items = 0;
}
