#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, V;
    printf("Enter number of coins: ");
    scanf("%d", &n);

    int *coins = (int *)malloc(n * sizeof(int));
    if (coins == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter coin values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter target amount: ");
    scanf("%d", &V);

    int *dp = (int *)malloc((V + 1) * sizeof(int));
    if (dp == NULL) {
        printf("Memory allocation failed.\n");
        free(coins);
        return 1;
    }

    dp[0] = 0;
    for (int i = 1; i <= V; i++) {
        dp[i] = 1000000;
    }

    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                if (dp[i - coins[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
    }

    if (dp[V] >= 1000000) {
        printf("Minimum coins needed: -1\n");
    } else {
        printf("Minimum coins needed: %d\n", dp[V]);
    }

    free(dp);
    free(coins);
    return 0;
}