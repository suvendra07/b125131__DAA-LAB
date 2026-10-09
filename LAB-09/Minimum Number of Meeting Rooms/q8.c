#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *starts = malloc(n * sizeof(int));
    int *ends = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d %d", &starts[i], &ends[i]);
    
    qsort(starts, n, sizeof(int), cmp_int);
    qsort(ends, n, sizeof(int), cmp_int);
    
    int rooms = 0, max_rooms = 0, s_ptr = 0, e_ptr = 0;
    while (s_ptr < n) {
        if (starts[s_ptr] < ends[e_ptr]) {
            rooms++;
            if (rooms > max_rooms) max_rooms = rooms;
            s_ptr++;
        } else {
            rooms--;
            e_ptr++;
        }
    }
    printf("Minimum Rooms Required: %d\n", max_rooms);
    free(starts);
    free(ends);
    return 0;
}