
#include "stack.h"


struct Stack Stack_create() {
  struct Stack s;
  s.head = NULL;
  return s;
}

bool Stack_isempty(struct Stack* s) {
  return (s->head == NULL);
}


void Stack_destroy(struct Stack* s) {
  struct Node* head = s->head;
  while(head != NULL) {
    struct Node* temp = head;
    head = head->next;
    free(temp);
  }
}


void Stack_push(struct Stack* s, int n) {
  struct Node* new_node = malloc(sizeof(struct Node));
  new_node->n = n;
  new_node->next = s->head;
  s->head = new_node;
}

void Stack_pop(struct Stack* s) {
  if(!Stack_isempty(s)) {
    struct Node* temp = s->head;
    s->head = temp->next;
    free(temp);
  }
}

int Stack_top(struct Stack* s) {
  if(!Stack_isempty(s)) {
    return s->head->n;
  }
}


