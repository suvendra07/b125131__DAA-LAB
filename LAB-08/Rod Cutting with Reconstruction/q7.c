#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter rod length: ");
    scanf("%d", &n);

    int *price = (int *)malloc((n + 1) * sizeof(int));
    int *dp = (int *)malloc((n + 1) * sizeof(int));
    int *cuts = (int *)malloc((n + 1) * sizeof(int));

    if (price == NULL || dp == NULL || cuts == NULL) {
        printf("Memory allocation failed!\n");
        free(price);
        free(dp);
        free(cuts);
        return 1;
    }

    printf("Enter price for each length from 1 to %d: ", n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &price[i]);
    }

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int max_val = -1;
        for (int j = 1; j <= i; j++) {
            if (price[j] + dp[i - j] > max_val) {
                max_val = price[j] + dp[i - j];
                cuts[i] = j;
            }
        }
        dp[i] = max_val;
    }

    printf("Maximum obtainable revenue: %d\n", dp[n]);
    printf("Piece lengths: ");

    int temp = n;
    while (temp > 0) {
        printf("%d ", cuts[temp]);
        temp = temp - cuts[temp];
    }
    printf("\n");

    return 0;
}