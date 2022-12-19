#include <stdio.h>
#include <stdlib.h>

void quicksort(float* arr, size_t n);
static size_t partition(float* arr, size_t n);

static void printArr(float* arr, size_t n) {
  for(size_t i=0; i<n; ++i) {
    printf("%.2f ", arr[i]);
  }
  printf("\n");
}

static void swap(float* x1, float* x2) {
    float temp = *x1;
    *x1 = *x2;
    *x2 = temp;
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
    printArr(arr, n);
    printf("Sorting the elements...\n");
    quicksort(arr, n);
    printf("Contents after sorting...\n");
    printArr(arr, n);

    free(arr);
    return 0;

}

void quicksort(float* arr, size_t n) {
    if(n<2) {
        return;
    }
    
    size_t pivot = partition(arr, n);
    float* small_arr  = arr;
    size_t small_size = pivot;
    float* large_arr  = &arr[pivot+1];
    size_t large_size = (n-pivot)-1;
    quicksort(small_arr, small_size);
    quicksort(large_arr, large_size);
}


static size_t partition(float* arr, size_t n) {
    size_t pivot, left, right;
    pivot = 0;
    left  = 1;
    right = n-1;

    while(left < right) {
        // right to left scan
        while(arr[right] >= arr[pivot] && pivot != right) {
            --right;
        }

        if(right == pivot) break;
        swap(&arr[pivot], &arr[right]);
        pivot = right;

        // left to right scan
        while(arr[left] < arr[pivot] && pivot != left) {
            ++left;
        }
        if(left == pivot) break;
        swap(&arr[pivot], &arr[left]);
        pivot = left;
    }

    return pivot;
}

