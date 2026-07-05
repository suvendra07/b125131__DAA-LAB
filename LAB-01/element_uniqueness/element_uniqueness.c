#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

bool check_duplicates(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            return true;
        }
    }
    return false;
}

int main() {
    int arr[] = {45, 12, 78, 34, 12, 89, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    if (check_duplicates(arr, n)) {
        printf("Duplicates exist in the array.\n");
    } else {
        printf("All elements are unique.\n");
    }
    return 0;
}
