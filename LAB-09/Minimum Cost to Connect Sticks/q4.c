#include <stdio.h>
#include <stdlib.h>

void min_heapify(long long *heap, int size, int i) {
    int smallest = i, l = 2*i + 1, r = 2*i + 2;
    if (l < size && heap[l] < heap[smallest]) smallest = l;
    if (r < size && heap[r] < heap[smallest]) smallest = r;
    if (smallest != i) {
        long long t = heap[i]; heap[i] = heap[smallest]; heap[smallest] = t;
        min_heapify(heap, size, smallest);
    }
}

void push(long long *heap, int *size, long long val) {
    heap[(*size)++] = val;
    int i = *size - 1;
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        long long t = heap[(i - 1) / 2]; heap[(i - 1) / 2] = heap[i]; heap[i] = t;
        i = (i - 1) / 2;
    }
}

long long pop(long long *heap, int *size) {
    long long top = heap[0];
    heap[0] = heap[--(*size)];
    min_heapify(heap, *size, 0);
    return top;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    long long *heap = malloc(n * sizeof(long long));
    int size = 0;
    for (int i = 0; i < n; i++) {
        long long len; scanf("%lld", &len);
        push(heap, &size, len);
    }
    long long total_cost = 0;
    while (size > 1) {
        long long s1 = pop(heap, &size);
        long long s2 = pop(heap, &size);
        long long cost = s1 + s2;
        total_cost += cost;
        push(heap, &size, cost);
    }
    printf("Minimum Cost: %lld\n", total_cost);
    free(heap);
    return 0;
}