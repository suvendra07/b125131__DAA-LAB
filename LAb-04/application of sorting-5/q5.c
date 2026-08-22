#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Interval;

int compareIntervals(const void *a, const void *b) {
    return ((Interval*)a)->x - ((Interval*)b)->x;
}

void mergeIntervals(Interval arr[], int n) {
    qsort(arr, n, sizeof(Interval), compareIntervals);

    Interval merged[50]; // Assuming n <= 50 for simplicity
    int count = 0;
    merged[0] = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i].x <= merged[count].y) {
            if (arr[i].y > merged[count].y) {
                merged[count].y = arr[i].y;
            }
        } else {
            count++;
            merged[count] = arr[i];
        }
    }

    printf("Merged Intervals:\n");
    for (int i = 0; i <= count; i++) {
        printf("(%d, %d) ", merged[i].x, merged[i].y);
    }
    printf("\n");
}

int main() {
    Interval I[] = {{1, 3}, {2, 6}, {8, 10}, {7, 18}};
    int n = sizeof(I) / sizeof(I[0]);

    mergeIntervals(I, n);
    return 0;
}