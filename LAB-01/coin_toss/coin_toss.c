#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void simulate_coin_toss(int tosses, double bias) {
    int heads = 0;
    for (int i = 0; i < tosses; i++) {
        double toss = (double)rand() / RAND_MAX;
        if (toss < bias) {
            heads++;
        }
    }
    printf("Tosses: %d, Bias: %f, Probability: %f\n", tosses, bias, (double)heads / tosses);
}

int main() {
    srand(time(NULL));
    simulate_coin_toss(100000, 0.5);
    simulate_coin_toss(100000, 0.75);
    return 0;
}
