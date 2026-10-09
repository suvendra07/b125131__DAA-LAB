#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dist, fuel;
} Station;

int cmp_station(const void *a, const void *b) {
    return ((Station *)a)->dist - ((Station *)b)->dist;
}

void max_heapify(int *heap, int size, int i) {
    int max_idx = i, l = 2*i + 1, r = 2*i + 2;
    if (l < size && heap[l] > heap[max_idx]) max_idx = l;
    if (r < size && heap[r] > heap[max_idx]) max_idx = r;
    if (max_idx != i) {
        int t = heap[i]; heap[i] = heap[max_idx]; heap[max_idx] = t;
        max_heapify(heap, size, max_idx);
    }
}

void heap_push(int *heap, int *size, int val) {
    heap[(*size)++] = val;
    int i = *size - 1;
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        int t = heap[(i - 1) / 2]; heap[(i - 1) / 2] = heap[i]; heap[i] = t;
        i = (i - 1) / 2;
    }
}

int heap_pop(int *heap, int *size) {
    if (*size <= 0) return -1;
    int top = heap[0];
    heap[0] = heap[--(*size)];
    max_heapify(heap, *size, 0);
    return top;
}

int main() {
    int n, D, F;
    if (scanf("%d %d %d", &n, &D, &F) != 3) return 0;
    Station *st = malloc((n + 1) * sizeof(Station));
    for (int i = 0; i < n; i++) scanf("%d %d", &st[i].dist, &st[i].fuel);
    st[n].dist = D; st[n].fuel = 0;
    qsort(st, n, sizeof(Station), cmp_station);
    
    int *max_heap = malloc((n + 1) * sizeof(int));
    int heap_size = 0, stops = 0, cur_fuel = F, prev_pos = 0;
    
    for (int i = 0; i <= n; i++) {
        int dist_needed = st[i].dist - prev_pos;
        while (cur_fuel < dist_needed) {
            if (heap_size == 0) {
                printf("-1\n");
                free(st); free(max_heap);
                return 0;
            }
            cur_fuel += heap_pop(max_heap, &heap_size);
            stops++;
        }
        cur_fuel -= dist_needed;
        prev_pos = st[i].dist;
        heap_push(max_heap, &heap_size, st[i].fuel);
    }
    printf("Minimum Refueling Stops: %d\n", stops);
    free(st); 
    free(max_heap);
    return 0;
}