#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int hasPairWithSum(int S1[], int S2[], int n, int x, int *out1, int *out2) {
    qsort(S2, n, sizeof(int), compare); 

    for (int i = 0; i < n; i++) { 
        int required = x - S1[i];
        int idx = binarySearch(S2, n, required); 
        if (idx != -1) {
            *out1 = S1[i];
            *out2 = S2[idx];
            return 1;
        }
    }
    return 0;
}

int main() {
    int S1[] = {12, 3, 7, 1, 19};
    int S2[] = {4, 18, 2, 8, 5};
    int n = 5;
    int x = 15;
    int val1, val2;

    if (hasPairWithSum(S1, S2, n, x, &val1, &val2)) {
        printf("Pair found: %d (from S1) + %d (from S2) = %d\n", val1, val2, x);
    } else {
        printf("No such pair exists.\n");
    }
    return 0;
}