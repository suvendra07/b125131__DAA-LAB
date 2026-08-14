#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int n, int key, int *comparisons) {
    int low = 0;
    int high = n - 1;
    *comparisons = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        (*comparisons)++;
        if (arr[mid] == key) {
            return mid;
        }

        (*comparisons)++;
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int ternarySearch(int arr[], int n, int key, int *comparisons) {
    int low = 0;
    int high = n - 1;
    *comparisons = 0;

    while (low <= high) {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        (*comparisons)++;
        if (arr[mid1] == key) {
            return mid1;
        }

        (*comparisons)++;
        if (arr[mid2] == key) {
            return mid2;
        }

        (*comparisons)++;
        if (key < arr[mid1]) {
            high = mid1 - 1;
        } else {
            (*comparisons)++;
            if (key > arr[mid2]) {
                low = mid2 + 1;
            } else {
                
                low = mid1 + 1;
                high = mid2 - 1;
            }
        }
    }
    return -1; 
}

int main() {
    int n = 1000000; 
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    int key = 999999; 
    int bs_comp = 0, ts_comp = 0;

    int bs_index = binarySearch(arr, n, key, &bs_comp);
    int ts_index = ternarySearch(arr, n, key, &ts_comp);

    printf("====================================================\n");
    printf("        BINARY SEARCH vs TERNARY SEARCH             \n");
    printf("====================================================\n");
    printf("Array Size (n):                 %d\n", n);
    printf("Target Element:                 %d\n\n", key);

    printf("Binary Search Result Index:     %d\n", bs_index);
    printf("Binary Search Comparison Count: %d\n\n", bs_comp);

    printf("Ternary Search Result Index:    %d\n", ts_index);
    printf("Ternary Search Comparison Count:%d\n", ts_comp);
    printf("====================================================\n");

    free(arr);
    return 0;
}