#include <stdio.h>

int main()
{
    int n;
    int totalCoins;
    int moves;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    totalCoins = n * (n + 1) / 2; 
    moves = totalCoins / 3;

    printf("\nOriginal triangle:\n");

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }

        for (int j = 1; j <= i; j++)
        {
            printf("O ");
        }

        printf("\n");
    }

    printf("\nInverted triangle:\n");

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }

        for (int j = 1; j <= i; j++)
        {
            printf("O ");
        }

        printf("\n");
    }

    printf("\nTotal coins = %d\n", totalCoins);
    printf("Minimum number of moves = %d\n", moves);

    return 0;
}