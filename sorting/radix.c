
#include <stdio.h>
#include <stdlib.h>

static void copyToBuckets(int*    arr,
                          size_t  n,
                          int**   buckets,
                          size_t* sizes,
                          size_t  r);

static void copyToArray(int**   buckets,
                        size_t* sizes,
                        int*    arr,
                        size_t  n);

void radixsort(int* arr, size_t n);

static void printArr(int* arr, size_t n);

int main() {
  printf("Enter number of elements: ");
  size_t n;
  scanf("%zd", &n);
  int* arr = calloc(n, sizeof(int));
  printf("Enter elements\n");
  for(size_t i=0; i<n; ++i) {
    scanf("%d", &arr[i]);
  }

  printf("Elements before sorting...\n");
  printArr(arr, n);
  printf("Sorting...\n");
  radixsort(arr, n);
  printf("Elements after sorting...\n");
  printArr(arr, n);
  free(arr);
  return 0;
}


int nthdigit(int x, size_t n) {
  while(n) {
    x/= 10;
    n--;
  }
  return x%10;
}

static size_t abs_p(int n) {
  return (n<0)?(-n):(n);
}

size_t ndigits(size_t n) {
  size_t c = 0;
  while(n) {
    n = n/10;
    c++;
  }
  return c;
}

void radixsort(int* arr, size_t n) {
  size_t sizes[10];
  int* buckets[10];
  for(size_t i=0; i<10; ++i) {
    buckets[i] = calloc(n, sizeof(int));
    sizes[i] = 0;
  }

  size_t max = abs_p(arr[0]);
  for(size_t i=1; i<n; ++i) {
    if(abs_p(arr[i]) > max) {
      max = abs_p(arr[i]);
    }
  }

  max = ndigits(max);

  for(size_t pass=0; pass < max; ++pass) {
    copyToBuckets(arr, n, buckets, sizes, pass);
    copyToArray(buckets, sizes, arr, n);
  }
  
  for(size_t i=0; i<10; ++i) {
    free(buckets[i]);
  }
}


void printArr(int* arr, size_t n) {
  for(size_t i=0; i<n; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

static void copyToBuckets(int*    arr,
                          size_t  n,
                          int**   buckets,
                          size_t* sizes,
                          size_t  r)
{
  for(size_t i=0; i<n; ++i) {
    size_t b = nthdigit(arr[i], r);

    buckets[b][sizes[b]] = arr[i];
    sizes[b]++;
  }
}

static void copyToArray(int**   buckets,
                        size_t* sizes,
                        int*    arr,
                        size_t  n)
{
  size_t ptr = 0;
  for(size_t b=0; b<10; ++b) {
    for(size_t i=0; i<sizes[b]; ++i) {
      arr[ptr] = buckets[b][i];
      ptr++;
    }
    sizes[b] = 0;
  }
}

