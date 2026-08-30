#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Enter number of random elements (N): ");
    scanf("%d", &n);

    FILE *fp = fopen("input_quick.txt", "w");
    if (!fp) {
        printf("Error opening file.\n");
        return 1;
    }

    srand(time(0));
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", rand() % 1000);
    }
    fclose(fp);

    int *arr = (int*)malloc(n * sizeof(int));
    fp = fopen("input_quick.txt", "r");
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    quickSort(arr, 0, n - 1);

    fp = fopen("output_quick.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);

    printf("Random numbers generated in 'input_quick.txt'.\n");
    printf("Sorted array saved successfully in 'output_quick.txt'.\n");

    free(arr);
    return 0;
}