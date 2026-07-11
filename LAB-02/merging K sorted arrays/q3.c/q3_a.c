#include <stdio.h>
#include <stdlib.h>

void merge_two(int a[], int size_a, int b[], int size_b, int res[]) {
    int i = 0, j = 0, idx = 0;
    while (i < size_a && j < size_b) {
        if (a[i] <= b[j]) res[idx++] = a[i++];
        else res[idx++] = b[j++];
    }
    while (i < size_a) res[idx++] = a[i++];
    while (j < size_b) res[idx++] = b[j++];
}

void merge_k_sequential(int arrays[4][5], int k, int n, int result[]) {
    int current_size = n;
    for (int i = 0; i < n; i++) result[i] = arrays[0][i];

    int *temp = (int*)malloc(k * n * sizeof(int));
    for (int i = 1; i < k; i++) {
        merge_two(result, current_size, arrays[i], n, temp);
        current_size += n;
        for (int j = 0; j < current_size; j++) result[j] = temp[j];
    }
    free(temp);
}

int main() {
    int k = 4, n = 5;
    int arrays[4][5] = {
        {1, 5, 9, 13, 17},
        {2, 6, 10, 14, 18},
        {3, 7, 11, 15, 19},
        {4, 8, 12, 16, 20}
    };
    int result[20];
    merge_k_sequential(arrays, k, n, result);

    printf("Merged Array (Method 1 - Sequential):\n");
    for (int i = 0; i < k * n; i++) printf("%d ", result[i]);
    printf("\n");
    return 0;
}