#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int coord;
    int type; // +1 for start, -1 for end
} PointEvent;

int comparePointEvents(const void *a, const void *b) {
    PointEvent *p1 = (PointEvent*)a;
    PointEvent *p2 = (PointEvent*)b;
    if (p1->coord != p2->coord) return p1->coord - p2->coord;
    return p2->type - p1->type; 
}

void findMaxOverlapPoint(int left[], int right[], int n) {
    PointEvent events[2 * 50]; // Assuming n <= 50 for simplicity
    for (int i = 0; i < n; i++) {
        events[2 * i] = (PointEvent){left[i], 1};
        events[2 * i + 1] = (PointEvent){right[i], -1};
    }

    qsort(events, 2 * n, sizeof(PointEvent), comparePointEvents);

    int activeIntervals = 0, maxIntervals = 0, bestPoint = -1;
    for (int i = 0; i < 2 * n; i++) {
        activeIntervals += events[i].type;
        if (activeIntervals > maxIntervals) {
            maxIntervals = activeIntervals;
            bestPoint = events[i].coord;
        }
    }

    printf("Point p = %d lies in the maximum number of intervals (%d intervals).\n", bestPoint, maxIntervals);
}

int main() {
    int left[]  = {10, 20, 50, 15};
    int right[] = {40, 60, 90, 70};
    int n = 4;

    findMaxOverlapPoint(left, right, n);
    return 0;
}