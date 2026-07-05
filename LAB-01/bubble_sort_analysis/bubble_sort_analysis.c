#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void bubble_sort_early_exit(int arr[], int n) {
    int comparisons = 0;
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    printf("Early exit version comparisons: %d\n", comparisons);
}

void bubble_sort_full(int arr[], int n) {
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Full pass version comparisons: %d\n", comparisons);
}

int main() {
    int n = 200;
    int arr1[200];
    int arr2[200];
    srand(time(NULL));
    
    for (int i = 0; i < n; i++) {
        int val = rand() % 1000;
        arr1[i] = val;
        arr2[i] = val;
    }
    
    bubble_sort_early_exit(arr1, n);
    bubble_sort_full(arr2, n);
    return 0;
}
