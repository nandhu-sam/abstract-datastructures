// Implement selection sort function

#include <stdio.h>
#include <stdlib.h>

void printArray(float* nums, size_t n) {
  for(size_t i=0; i<n; ++i) {
    printf("%.2f ", nums[i]);
  }
  printf("\n");
}

size_t minimum(float* nums, size_t n) {
  size_t m = 0;
  for(size_t i=1; i<n; ++i) {
    if(nums[i] < nums[m]) {
      m = i;
    }
  }

  return m;
}

void selectionsort(float* nums, size_t n) {
  if(n==0 || nums == NULL) {
    return;
  }
  
  for(size_t i=0; i<n-1; ++i) {
    size_t m = minimum(&nums[i], n-i)+i;
    float temp = nums[m];
    nums[m] = nums[i];
    nums[i] = temp;
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
  selectionsort(arr, n);
  printf("Contents after sorting...\n");
  printArray(arr, n);

  free(arr);
  return 0;
}

