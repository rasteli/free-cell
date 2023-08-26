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
  Stack stacks[6] = {
    // Pilhas de jogo
    Stack(), Stack(), Stack(), Stack(), 
    // Pilhas de saída
    Stack(), Stack()
  };

  int from, to;
  bool insert_left = true;
  bool remove_left = true;

  std::cin >> from >> to;

  index(from, remove_left);
  index(to, insert_left);

  stacks[from].Push(Card(9, 3), remove_left);
  
  Card top;
  stacks[from].Pop(top, remove_left);
  stacks[to].Push(top, insert_left);

  Card top2;
  stacks[to].Pop(top2, insert_left);

  std::cout << top2.GetName();
  stacks[to].Top(top2, insert_left);

  return 0;
}
