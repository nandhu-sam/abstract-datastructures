// Implement bubble sort function

#include <stdio.h>
#include <stdlib.h>

void printArray(float* nums, size_t n) {
  for(size_t i=0; i<n; ++i) {
    printf("%.2f ", nums[i]);
  }
  printf("\n");
}


void bubblesort(float* nums, size_t n) {
  if(n==0 || nums == NULL) {
    return;
  }
  for(size_t k=0; k<n-1; ++k) {
    for(size_t i=0; i<(n-k-1); ++i) {
      if(nums[i] > nums[i+1]) {
        float temp = nums[i];
        nums[i] = nums[i+1];
        nums[i+1] = temp;
      }
    }
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
  bubblesort(arr, n);
  printf("Contents after sorting...\n");
  printArray(arr, n);

  free(arr);
  return 0;
}
