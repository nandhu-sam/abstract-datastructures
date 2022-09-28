
#include <stdlib.h>

#include "circ-list.h"

struct CircList CircList_create() {
  struct CircList s;
  s.head = NULL;
  return s;
}

bool CircList_isempty(struct CircList* s) {
  return s->head == NULL;
}


void CircList_enqueue(struct CircList* s, int item) {
  struct Node* new_node = malloc(sizeof(struct Node));
  new_node->item = item;
  new_node->next = (s->head == NULL)?(new_node):(s->head);
  new_node->prev = (s->head == NULL)?(new_node):(s->head->prev);

  new_node->prev->next = new_node;
  new_node->next->prev = new_node;

  if(s->head == NULL) {
    s->head = new_node;
  }
}

void CircList_dequeue(struct CircList* s) {
  if(!CircList_isempty(s)) {
    struct Node* p = s->head;
    if(p->next == p) {
      s->head = NULL;
    }
    else {
      p->prev->next = p->next;
      p->next->prev = p->prev;
      s->head = p->next;
    }
    
    free(p);
  }
}

int CircList_top(struct CircList* s) {
  return s->head->item;
}
