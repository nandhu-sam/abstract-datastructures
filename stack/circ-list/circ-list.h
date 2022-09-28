

#ifndef CIRC_LIST_H
#define CIRC_LIST_H

#include <stdbool.h>


struct Node {
  struct Node* prev;
  struct Node* next;
  int item;
};


struct CircList {
  struct Node* head;
};


struct CircList CircList_create();
bool CircList_isempty(struct CircList* s);

void CircList_enqueue(struct CircList*, int item);
void CircList_dequeue(struct CircList*);
int CircList_top(struct CircList* s);
  

#endif
