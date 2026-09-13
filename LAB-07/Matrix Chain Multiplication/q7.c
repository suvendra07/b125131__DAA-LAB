#include <stdio.h>
#include <limits.h>

#define MAX 50

long long dp[MAX][MAX];
int split[MAX][MAX];

void printOrder(int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
        return;
    }

    printf("(");

    printOrder(i, split[i][j]);
    printOrder(split[i][j] + 1, j);

    printf(")");
}

int main()
{
    int n;
    int p[MAX];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    if (n <= 0 || n >= MAX)
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter %d dimensions:\n", n + 1);

    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
        split[i][i] = 0;
    }

    for (int length = 2; length <= n; length++)
    {
        for (int i = 1; i <= n - length + 1; i++)
        {
            int j = i + length - 1;

            dp[i][j] = LLONG_MAX;

            for (int k = i; k < j; k++)
            {
                long long cost;

                cost = dp[i][k]
                     + dp[k + 1][j]
                     + (long long)p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    printf("\nMinimum number of scalar multiplications = %lld\n",
           dp[1][n]);

    printf("Best parenthesization = ");
    printOrder(1, n);
    printf("\n");

    return 0;
}