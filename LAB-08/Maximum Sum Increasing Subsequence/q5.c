#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Array size must be positive.\n");
        return 1;
    }

    int *A = (int *)malloc(n * sizeof(int));
    int *dp = (int *)malloc(n * sizeof(int));

    if (A == NULL || dp == NULL) {
        printf("Memory allocation failed.\n");
        free(A);
        free(dp);
        return 1;
    }

    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int max_sum = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = A[i];
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j] && dp[i] < dp[j] + A[i]) {
                dp[i] = dp[j] + A[i];
            }
        }
        if (dp[i] > max_sum) {
            max_sum = dp[i];
        }
    }

    printf("Maximum Sum Increasing Subsequence: %d\n", max_sum);

    free(A);
    free(dp);
    return 0;
}