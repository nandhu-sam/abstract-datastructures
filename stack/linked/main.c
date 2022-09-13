

#include <stdlib.h>
#include <stdio.h>

#include "stack.h"


int main() {
  struct Stack s = Stack_create();
  Stack_push(&s, 1);
  Stack_push(&s, 2);

  while(!Stack_isempty(&s)) {
    printf("%d ", Stack_top(&s));
    Stack_pop(&s);
  }

  printf("Done\n");
}
