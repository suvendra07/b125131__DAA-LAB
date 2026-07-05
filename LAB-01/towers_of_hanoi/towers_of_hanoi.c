#include <stdio.h>

int moves = 0;

void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        moves++;
        return;
    }
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    moves++;
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    for (int i = 1; i <= 10; i++) {
        moves = 0;
        hanoi(i, 'A', 'C', 'B');
        printf("Discs: %d, Moves: %d\n", i, moves);
    }
    return 0;
}
