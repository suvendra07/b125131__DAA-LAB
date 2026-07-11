#include <stdio.h>
#include <stdlib.h>

void merge3(int arr[], int low, int mid1, int mid2, int high, int dest[]) {
    int i = low, j = mid1, k = mid2, l = low;
    while ((i < mid1) && (j < mid2) && (k < high)) {
        if (arr[i] < arr[j]) {
            if (arr[i] < arr[k]) dest[l++] = arr[i++];
            else dest[l++] = arr[k++];
        } else {
            if (arr[j] < arr[k]) dest[l++] = arr[j++];
            else dest[l++] = arr[k++];
        }
    }
    while ((i < mid1) && (j < mid2)) dest[l++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
    while ((j < mid2) && (k < high)) dest[l++] = (arr[j] < arr[k]) ? arr[j++] : arr[k++];
    while ((i < mid1) && (k < high)) dest[l++] = (arr[i] < arr[k]) ? arr[i++] : arr[k++];
    while (i < mid1) dest[l++] = arr[i++];
    while (j < mid2) dest[l++] = arr[j++];
    while (k < high) dest[l++] = arr[k++];
}

void merge_sort_3way_rec(int arr[], int low, int high, int dest[]) {
    if (high - low < 2) return;
    int mid1 = low + (high - low) / 3;
    int mid2 = low + 2 * (high - low) / 3 + 1;

    merge_sort_3way_rec(dest, low, mid1, arr);
    merge_sort_3way_rec(dest, mid1, mid2, arr);
    merge_sort_3way_rec(dest, mid2, high, arr);

    merge3(dest, low, mid1, mid2, high, arr);
}

void merge_sort_3way(int arr[], int n) {
    if (n <= 1) return;
    int *f_arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) f_arr[i] = arr[i];
    merge_sort_3way_rec(f_arr, 0, n, arr);
    for (int i = 0; i < n; i++) arr[i] = f_arr[i];
    free(f_arr);
}

int main() {
    int arr[] = {45, 12, 85, 32, 89, 39, 69, 44, 42, 1, 68, 46};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    merge_sort_3way(arr, n);

    printf("\n\nSorted Array (3-Way Merge Sort):\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
    
}