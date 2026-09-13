#include <stdio.h>

void printStrategy(int n)
{
    printf("Shooting strategy:\n");

    if (n == 2)
    {
        printf("1 1\n");
        return;
    }

    for (int i = 2; i <= n - 1; i++)
    {
        printf("%d ", i);
    }

    for (int i = n - 1; i >= 2; i--)
    {
        printf("%d ", i);
    }

    printf("\n");
}

int main()
{
    int n;

    printf("Enter number of hiding spots: ");
    scanf("%d", &n);

    if (n <= 1)
    {
        printf("Invalid input\n");
        return 0;
    }

    printStrategy(n);

    if (n == 2)
    {
        printf("\nThe target can be guaranteed to be hit.\n");
        printf("Number of shots = 2\n");
    }
    else
    {
        printf("\nThe target can be guaranteed to be hit.\n");
        printf("Number of shots = %d\n", 2 * (n - 2));
    }

    return 0;
}