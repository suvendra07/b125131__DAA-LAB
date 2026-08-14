#include <stdio.h>

void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int smallest = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[smallest]) {
                smallest = j;
            }
        }
        int temp = A[i];
        A[i] = A[smallest];
        A[smallest] = temp;
    }
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {64, 25, 12, 22, 11};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    printArray(A, n);

    selectionSort(A, n);

    printf("Sorted array:   ");
    printArray(A, n);

    return 0;
}