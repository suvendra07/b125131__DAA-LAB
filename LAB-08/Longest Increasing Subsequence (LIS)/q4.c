#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Length of LIS: 0\n");
        return 0;
    }

    int *A = (int *)malloc(n * sizeof(int));
    if (A == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int *dp = (int *)malloc(n * sizeof(int));
    if (dp == NULL) {
        free(A);
        printf("Memory allocation failed.\n");
        return 1;
    }

    int max_lis = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > max_lis) {
            max_lis = dp[i];
        }
    }

    printf("Length of LIS: %d\n", max_lis);

    free(dp);
    free(A);
    return 0;
}