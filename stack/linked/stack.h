
#ifndef STACK_H
#define STACK_H


#include <stdlib.h>
#include <stdbool.h>


struct Node {
  int n;
  struct Node* next;
};

struct Stack {
  struct Node* head;
};

struct Stack Stack_create();

bool Stack_isempty(struct Stack* s);
void Stack_destroy(struct Stack* s);

void Stack_push(struct Stack* s, int n);
void Stack_pop(struct Stack* s);

int Stack_top(struct Stack* s);


#endif
