#include <stdio.h>

#define MAX_EGGS 20
#define MAX_FLOORS 200

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int eggs, floors;
    int dp[MAX_EGGS + 1][MAX_FLOORS + 1];

    printf("Enter number of eggs: ");
    scanf("%d", &eggs);

    printf("Enter number of floors: ");
    scanf("%d", &floors);

    if (eggs <= 0 || eggs > MAX_EGGS || floors < 0 || floors > MAX_FLOORS)
    {
        printf("Invalid input\n");
        return 0;
    }

    for (int i = 1; i <= eggs; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    for (int j = 0; j <= floors; j++)
    {
        dp[1][j] = j;
    }

    for (int i = 2; i <= eggs; i++)
    {
        for (int j = 2; j <= floors; j++)
        {
            dp[i][j] = 1000000;

            for (int k = 1; k <= j; k++)
            {
                int eggBreak;
                int eggNotBreak;
                int result;

                eggBreak = dp[i - 1][k - 1];
                eggNotBreak = dp[i][j - k];

                result = 1 + max(eggBreak, eggNotBreak);

                if (result < dp[i][j])
                {
                    dp[i][j] = result;
                }
            }
        }
    }

    printf("\nMinimum number of droppings = %d\n", dp[eggs][floors]);

    return 0;
}