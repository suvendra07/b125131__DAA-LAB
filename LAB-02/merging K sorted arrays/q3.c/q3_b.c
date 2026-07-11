#include <stdio.h>
#include <stdlib.h>

void merge_k_pairwise(int** arrays, int start_k, int end_k, int n, int* result) {
    if (start_k == end_k) {
        for (int i = 0; i < n; i++) result[i] = arrays[start_k][i];
        return;
    }
    int mid = start_k + (end_k - start_k) / 2;
    int size_left = (mid - start_k + 1) * n;
    int size_right = (end_k - mid) * n;

    int* left_res = (int*)malloc(size_left * sizeof(int));
    int* right_res = (int*)malloc(size_right * sizeof(int));

    merge_k_pairwise(arrays, start_k, mid, n, left_res);
    merge_k_pairwise(arrays, mid + 1, end_k, n, right_res);

    int i = 0, j = 0, idx = 0;
    while (i < size_left && j < size_right) {
        if (left_res[i] <= right_res[j]) result[idx++] = left_res[i++];
        else result[idx++] = right_res[j++];
    }
    while (i < size_left) result[idx++] = left_res[i++];
    while (j < size_right) result[idx++] = right_res[j++];

    free(left_res);
    free(right_res);
}

int main() {
    int k = 4, n = 5;
    int r0[] = {1, 5, 9, 13, 17};
    int r1[] = {2, 6, 10, 14, 18};
    int r2[] = {3, 7, 11, 15, 19};
    int r3[] = {4, 8, 12, 16, 20};
    int* arrays[] = {r0, r1, r2, r3};

    int result[20];
    merge_k_pairwise(arrays, 0, k - 1, n, result);

    printf("Merged Array (Method 2 - Pairwise Divide & Conquer):\n");
    for (int i = 0; i < k * n; i++) printf("%d ", result[i]);
    printf("\n");
    return 0;
}