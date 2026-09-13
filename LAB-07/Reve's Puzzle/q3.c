#include <stdio.h>
#include <limits.h>

long long powerOfTwo(int n)
{
    long long result = 1;

    for (int i = 0; i < n; i++)
    {
        result = result * 2;
    }

    return result;
}

void hanoi3(int n, char source, char destination, char auxiliary)
{
    if (n == 0)
        return;

    hanoi3(n - 1, source, auxiliary, destination);

    printf("Move disk %d from %c to %c\n",
           n, source, destination);

    hanoi3(n - 1, auxiliary, destination, source);
}

long long solve4(int n, char source, char destination,
                 char aux1, char aux2, int printMoves)
{
    if (n == 0)
        return 0;

    if (n == 1)
    {
        if (printMoves)
        {
            printf("Move disk 1 from %c to %c\n",
                   source, destination);
        }

        return 1;
    }

    long long best = LLONG_MAX;
    int bestK = 1;

    for (int k = 1; k < n; k++)
    {
        long long small;
        long long large;
        long long total;

        small = solve4(n - k, source, aux1,
                       aux2, destination, 0);

        large = powerOfTwo(k) - 1;

        total = 2 * small + large;

        if (total < best)
        {
            best = total;
            bestK = k;
        }
    }

    if (printMoves)
    {
        solve4(n - bestK, source, aux1,
               aux2, destination, 1);

        hanoi3(bestK, source, destination, aux2);

        solve4(n - bestK, aux1, destination,
               source, aux2, 1);
    }

    return best;
}

int main()
{
    int n;
    long long moves;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    if (n <= 0 || n > 20)
    {
        printf("Invalid input\n");
        return 0;
    }

    moves = solve4(n, 'A', 'D', 'B', 'C', 0);

    printf("\nMinimum number of moves = %lld\n", moves);

    if (n <= 10)
    {
        printf("\nMove sequence:\n");

        solve4(n, 'A', 'D', 'B', 'C', 1);
    }

    return 0;
}