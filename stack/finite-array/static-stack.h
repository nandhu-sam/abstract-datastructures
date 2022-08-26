
#ifndef ADT_STATIC_STACK_H
#define ADT_STATIC_STACK_H 20220826


#include <stdbool.h>
#include <stdlib.h>


struct Stack {
  /* array holding all the values */
  int* arr;
  
  /* capacity of the above array */
  size_t size;

  /* index of top of stack */
  /* -1 indicates an empty stack */
  int top;
};



// stack constructor and destructor
struct Stack Stack_create(size_t length);
void Stack_destroy(struct Stack* stack);


// basic staus checks
bool Stack_isfull(struct Stack* stack);
bool Stack_isempty(struct Stack* stack);


// main operations
struct Stack* Stack_push(struct Stack* stack, int n);
struct Stack* Stack_pop(struct Stack* stack);


// made this because I can't return an int from Stack_pop
int Stack_topOf(struct Stack* stack);



#endif
