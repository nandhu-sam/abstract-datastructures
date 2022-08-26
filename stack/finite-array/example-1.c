
#include <stdio.h>

#include "static-stack.h"


int main() {
  /* A stack that can contain 5 elements */
  struct Stack s = Stack_create(5);

  printf("Pushing elements into the stack\n");
  for(int i=0; i<5; ++i) {
    Stack_push(&s, i);
  }

  printf("Retrieving elements from the stack\n");
  while(!Stack_isempty(&s)) {
    printf("%d (index: %d)\n", Stack_topOf(&s), s.top);
    Stack_pop(&s);
  }
  
  Stack_destroy(&s);
  printf("Finished\n");

  
};
