#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int min3(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int main() {
    char A[MAX], B[MAX];
    printf("Enter source string: ");
    scanf("%s", A);
    printf("Enter target string: ");
    scanf("%s", B);

    int m = strlen(A);
    int n = strlen(B);
    int dp[MAX + 1][MAX + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
    }

    printf("Minimum Edit Distance: %d\n", dp[m][n]);
    printf("Traceback operations:\n");

    int i = m, j = n;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && A[i - 1] == B[j - 1]) {
            i--;
            j--;
        } else if (i > 0 && j > 0 && dp[i][j] == dp[i - 1][j - 1] + 1) {
            printf("Replace '%c' with '%c'\n", A[i - 1], B[j - 1]);
            i--;
            j--;
        } else if (i > 0 && dp[i][j] == dp[i - 1][j] + 1) {
            printf("Delete '%c'\n", A[i - 1]);
            i--;
        } else if (j > 0 && dp[i][j] == dp[i][j - 1] + 1) {
            printf("Insert '%c'\n", B[j - 1]);
            j--;
        }
    }

    return 0;
}