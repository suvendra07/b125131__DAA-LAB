#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    printf("Enter number of random elements (N): ");
    scanf("%d", &n);

    FILE *fp = fopen("input_heap.txt", "w");
    if (!fp) {
        printf("Error creating file.\n");
        return 1;
    }

    srand(time(0));
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", rand() % 1000);
    }
    fclose(fp);

    int *arr = (int*)malloc(n * sizeof(int));
    fp = fopen("input_heap.txt", "r");
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    heapSort(arr, n);

    fp = fopen("output_heap.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);

    printf("Random numbers generated in 'input_heap.txt'.\n");
    printf("Sorted array saved successfully in 'output_heap.txt'.\n");

    free(arr);
    return 0;
}