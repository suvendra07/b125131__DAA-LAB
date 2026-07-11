#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int search_unsorted_array(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

int search_sorted_array(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    printf("   Question 1 Benchmarks   \n");
    int sizes[] = {10000, 50000, 100000, 500000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("%-12s %-22s %-22s\n", "Size (n)", "Unsorted Search (ms)", "Sorted Search (ms)");
    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int *arr = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) arr[j] = j;

        clock_t start = clock();
        search_unsorted_array(arr, n, -1);
        clock_t end = clock();
        double time_unsorted = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

        start = clock();
        search_sorted_array(arr, n, -1);
        end = clock();
        double time_sorted = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

        printf("%-12d %-22.4f %-22.4f\n", n, time_unsorted, time_sorted);
        free(arr);
    }
    return 0;
}