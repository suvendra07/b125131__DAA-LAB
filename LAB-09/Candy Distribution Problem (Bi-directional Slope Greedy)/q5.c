#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *ratings = malloc(n * sizeof(int));
    int *candies = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &ratings[i]);
        candies[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
            candies[i] = candies[i + 1] + 1;
        }
    }
    long long total = 0;
    for (int i = 0; i < n; i++) total += candies[i];
    printf("Minimum Candies Needed: %lld\n", total);
    free(ratings);
    free(candies);
    return 0;
}