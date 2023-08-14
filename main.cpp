#include <iostream>
#include "stack.h"
#include "card.h"

void index(int &input, bool &left) {
  if (input % 2 == 0) {
    input /= 2;
  } else {
    input = (input - 1) / 2;
    left = false;
  }
}

int main() {
  Stack zero, one, two, three, four, five;
  Stack stacks[6] = {zero, one, two, three, four, five};

  int from, to;
  bool insert_left = true;
  bool remove_left = true;

  std::cin >> from >> to;

  index(from, remove_left);
  index(to, insert_left);

  stacks[from].Add(Card(9, 3), false);
  stacks[from].Add(Card(8, 2), false);
  
  stacks[from].Remove(remove_left);
  stacks[to].Add(Card(11, 4), insert_left);

  for (int i = 0; i < 26; i++) {
    stacks[from].Items()[i].Print();
  }

  std::cout << '\n';

  for (int i = 0; i < 26; i++) {
    stacks[to].Items()[i].Print();
  }
  
  return 0;
}