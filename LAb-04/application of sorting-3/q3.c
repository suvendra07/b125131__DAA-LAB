#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int binarySearchRange(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
int kSumSearch(int S[], int n, int Target) {
    qsort(S, n, sizeof(int), compare);

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int rem = Target - (S[i] + S[j]);
            int idx = binarySearchRange(S, j + 1, n - 1, rem);
            if (idx != -1) {
                printf("Found elements: %d, %d, %d summing to %d\n", S[i], S[j], S[idx], Target);
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int S[] = {10, 2, 7, 4, 5, 1, 9};
    int n = sizeof(S) / sizeof(S[0]);
    int Target = 18;

    if (!kSumSearch(S, n, Target)) {
        printf("No 3 elements sum up to %d\n", Target);
    }
    return 0;
}