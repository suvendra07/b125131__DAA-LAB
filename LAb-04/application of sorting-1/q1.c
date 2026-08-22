#include <stdio.h>
#include <stdlib.h>

typedef enum { RED = 0, BLUE = 1, YELLOW = 2 } Color;

typedef struct {
    int number;
    Color color;
} Item;

const char* getColorName(Color c) {
    if (c == RED) return "Red";
    if (c == BLUE) return "Blue";
    return "Yellow";
}

void stableColorSort(Item arr[], int n) {
    Item output[50]; // Assuming n <= 50 for simplicity
    int count[3] = {0, 0, 0};

    for (int i = 0; i < n; i++) {
        count[arr[i].color]++;
    }
    count[1] += count[0];
    count[2] += count[1];
    for (int i = n - 1; i >= 0; i--) {
        int c = arr[i].color;
        output[count[c] - 1] = arr[i];
        count[c]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    Item arr[] = {
        {10, BLUE}, {12, RED}, {15, YELLOW}, {20, RED},
        {25, BLUE}, {30, RED}, {35, YELLOW}
    };
    int n = sizeof(arr) / sizeof(arr[0]);

    stableColorSort(arr, n);

    printf("Sorted Items (by Color stably):\n");
    for (int i = 0; i < n; i++) {
        printf("{Number: %d, Color: %s}\n", arr[i].number, getColorName(arr[i].color));
    }
    return 0;
}