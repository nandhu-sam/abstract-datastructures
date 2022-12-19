// Implement insertion sort function

#include <stdio.h>
#include <stdlib.h>

void printArray(float* nums, size_t n) {
  for(size_t i=0; i<n; ++i) {
    printf("%.1f ", nums[i]);
  }
  printf("\n");
}

void insertionsort(float* nums, size_t n) {
  if(n==0 || nums == NULL) {
    return;
  }
  
  for(size_t k=1; k<n; ++k) {
    float x = nums[k];
    size_t i=k;
    while(i > 0 && nums[i-1] > x) {
      nums[i] = nums[i-1];
      --i;
    }
    nums[i] = x;
  }
 
}

int main() {
  size_t n;
  printf("Enter the size of array: ");
  scanf("%zd", &n);
  float* arr = calloc(n, sizeof(float));
  
  if(arr == NULL) {
    printf("Could not allocate memory\n");
    return -1;
  }
  
  printf("Enter %zd elements: ", n);
  for(size_t i=0; i<n; ++i) {
    scanf("%f", &(arr[i]));
  }

  printf("Contents before sorting...\n");
  printArray(arr, n);
  printf("Sorting the elements...\n");
  insertionsort(arr, n);
  printf("Contents after sorting...\n");
  printArray(arr, n);

  free(arr);
  return 0;
}

