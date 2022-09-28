
#include <stdio.h>
#include <assert.h>
#include "circ-list.h"

int main() {


  struct CircList s = CircList_create();
  int n;
  printf("Enter number of elements: ");
  scanf("%d", &n);
  for(int i=0; i<n; ++i) {
    int x;
    printf("Enter element %d: ", i+1);
    scanf("%d", &x);
    CircList_enqueue(&s, x);
  }

  printf("Listing elements in the queue...\n");
  
  while(!CircList_isempty(&s)) {
    printf("%d ", CircList_top(&s));
    CircList_dequeue(&s);
    
  }
  printf("\n");
  return 0;
}
