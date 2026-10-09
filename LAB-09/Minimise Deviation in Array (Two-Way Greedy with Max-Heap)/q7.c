#include <stdio.h>
#include <stdlib.h>

void max_heapify(int *heap, int size, int i) {
    int max_idx = i, l = 2*i + 1, r = 2*i + 2;
    if (l < size && heap[l] > heap[max_idx]) max_idx = l;
    if (r < size && heap[r] > heap[max_idx]) max_idx = r;
    if (max_idx != i) {
        int t = heap[i]; heap[i] = heap[max_idx]; heap[max_idx] = t;
        max_heapify(heap, size, max_idx);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *heap = malloc(n * sizeof(int));
    int min_val = 2147483647;
    for (int i = 0; i < n; i++) {
        int val; scanf("%d", &val);
        if (val % 2 != 0) val *= 2;
        heap[i] = val;
        if (val < min_val) min_val = val;
    }
    for (int i = (n - 2) / 2; i >= 0; i--) max_heapify(heap, n, i);
    
    int min_dev = 2147483647;
    while (1) {
        int max_val = heap[0];
        int dev = max_val - min_val;
        if (dev < min_dev) min_dev = dev;
        if (max_val % 2 != 0) break;
        
        heap[0] = max_val / 2;
        if (heap[0] < min_val) min_val = heap[0];
        max_heapify(heap, n, 0);
    }
    printf("Minimum Deviation: %d\n", min_dev);
    free(heap);
    return 0;
}