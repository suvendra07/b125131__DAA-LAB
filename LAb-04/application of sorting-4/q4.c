#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;
    int type;
} Event;

int compareEvents(const void *a, const void *b) {
    Event *e1 = (Event*)a;
    Event *e2 = (Event*)b;
    if (e1->time != e2->time) return e1->time - e2->time;
    return e1->type - e2->type; 
}

void findMaxAttendanceTime(int a[], int b[], int n) {
    Event events[2 * 50];// Assuming n <= 50 for simplicity
    for (int i = 0; i < n; i++) {
        events[2 * i] = (Event){a[i], 1};
        events[2 * i + 1] = (Event){b[i], -1};
    }

    qsort(events, 2 * n, sizeof(Event), compareEvents);

    int currentPeople = 0, maxPeople = 0, peakTime = -1;
    for (int i = 0; i < 2 * n; i++) {
        currentPeople += events[i].type;
        if (currentPeople > maxPeople) {
            maxPeople = currentPeople;
            peakTime = events[i].time;
        }
    }

    printf("Peak Attendance: %d people at time t = %d\n", maxPeople, peakTime);
}

int main() {
    int entry[] = {1, 2, 10, 5, 8};
    int exit[]  = {4, 7, 15, 12, 9};
    int n = 5;

    findMaxAttendanceTime(entry, exit, n);
    return 0;
}