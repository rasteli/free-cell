#include "stack.h"

#ifndef UTILS_H
#define UTILS_H

namespace utils {
  void index(int &input, bool &left);
  void populate_stacks(Stack *stacks, int n);
  void print_stacks(Stack *stacks, int n);
  void print_help();
}

#endif
