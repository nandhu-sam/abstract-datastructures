
#include <stdlib.h>

#include "static-stack.h"

struct Stack Stack_create(size_t length) {
  struct Stack s;
  s.size = length;
  s.top = -1;
  s.arr = malloc(length * sizeof(int));
  if(s.arr == NULL) {
    s.size = 0;
  }
  return s;
}


void Stack_destroy(struct Stack* stack) {
  free(stack->arr);
};


bool Stack_isfull(struct Stack* stack) {
  return (stack->top == stack->size - 1);
}

bool Stack_isempty(struct Stack* stack) {
  return (stack->top == -1);
}


struct Stack* Stack_push(struct Stack* stack, int n) {
  if(Stack_isfull(stack)) {
    return NULL;
  }

  (stack->top)++;
  (stack->arr)[stack->top] = n;
  return stack;
}


struct Stack* Stack_pop(struct Stack* stack) {
  if(Stack_isempty(stack)) {
    return NULL;
  }

  (stack->top)--;
  return stack;
}


int Stack_topOf(struct Stack* stack) {
  if(!(Stack_isempty(stack))) {
    return (stack->arr)[stack->top];
  }
}


