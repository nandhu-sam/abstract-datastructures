
#include <stdio.h>
#include <stdlib.h>


void mergesort(float* arr, size_t n);

static void merge(float* left_arr, size_t left_size,
                  float* right_arr, size_t right_size,
                  float* out);

static void printArr(float* arr, size_t n) {
  for(size_t i=0; i<n; ++i) {
    printf("%.2f ", arr[i]);
  }
  printf("\n");
}


int main() {
  size_t n;
  printf("Enter the number of elements: ");
  scanf("%zd", &n);
  float* arr = calloc(n, sizeof(float));
  printf("Enter numbers\n");
  for(size_t i=0; i<n; ++i) {
    scanf("%f", &arr[i]);
  }
  printf("Array before sorting: ");
  printArr(arr, n);
  mergesort(arr, n);
  printf("Array after sorting: ");
  printArr(arr, n);
  free(arr);
  return 0;
}


void mergesort(float* arr, size_t n) {
  if(n <= 1) {
    return;
  }
  float* left_arr   = arr;
  size_t left_size  = n/2;
  float* right_arr  = &(arr[left_size]);
  size_t right_size = n-left_size;

  mergesort(left_arr, left_size);
  mergesort(right_arr, right_size);
  float* merged = calloc(n, sizeof(float));
  merge(left_arr, left_size, right_arr, right_size, merged);
  for(size_t i=0; i<n; ++i) {
    arr[i] = merged[i];
  }
  free(merged);
}


static void merge(float* left_arr, size_t left_size,
                  float* right_arr, size_t right_size,
                  float* out)
{
  size_t outptr, leftptr, rightptr;
  outptr = leftptr = rightptr = 0;
  while(leftptr < left_size && rightptr < right_size) {
    if(left_arr[leftptr] > right_arr[rightptr]) {
      out[outptr] = right_arr[rightptr];
      rightptr++;
      outptr++;
    }
    else {
      out[outptr] = left_arr[leftptr];
      leftptr++;
      outptr++;
    }     
  }
  
  while(leftptr < left_size) {
    out[outptr] = left_arr[leftptr];
    leftptr++;
    outptr++;
  }
  
  while(rightptr < right_size) {
    out[outptr] = right_arr[rightptr];
    rightptr++;
    outptr++;
  }
  
}
