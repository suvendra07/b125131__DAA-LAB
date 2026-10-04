#include <stdio.h>

#define MAXN 100

int main() {
    int n;
    printf("Enter number of keys: ");
    scanf("%d", &n);

    if (n < 0 || n > MAXN) {
        printf("Invalid number of keys. Please enter a value between 0 and %d.\n", MAXN);
        return 1;
    }

    float p[MAXN + 1], q[MAXN + 1];
    printf("Enter probabilities p for keys 1 to %d: ", n);
    for (int i = 1; i <= n; i++) {
        scanf("%f", &p[i]);
    }

    printf("Enter dummy probabilities q for 0 to %d: ", n);
    for (int i = 0; i <= n; i++) {
        scanf("%f", &q[i]);
    }

    float e[MAXN + 2][MAXN + 2];
    float w[MAXN + 2][MAXN + 2];

    for (int i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    for (int l = 1; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            e[i][j] = 1e9;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            for (int r = i; r <= j; r++) {
                float cost = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (cost < e[i][j]) {
                    e[i][j] = cost;
                }
            }
        }
    }

    printf("Minimum Expected Search Cost: %.4f\n", e[1][n]);

    return 0;
}