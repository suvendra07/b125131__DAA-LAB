#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, V;
    printf("Enter number of coins: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid number of coins.\n");
        return 1;
    }

    int *coins = malloc((size_t)n * sizeof(*coins));
    if (n > 0 && coins == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter coin values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter target amount: ");
    if (scanf("%d", &V) != 1 || V < 0) {
        printf("Invalid target amount.\n");
        free(coins);
        return 1;
    }

    long long *dp = malloc((size_t)(V + 1) * sizeof(*dp));
    if (V >= 0 && dp == NULL) {
        printf("Memory allocation failed.\n");
        free(coins);
        return 1;
    }

    for (int i = 0; i <= V; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= V; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    printf("Total number of ways: %lld\n", dp[V]);

    free(dp);
    free(coins);
    return 0;
}