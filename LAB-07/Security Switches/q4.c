#include <stdio.h>
#include <stdlib.h>

int canToggle(int state[], int n, int pos)
{
    if (pos == n - 1)
        return 1;

    if (state[pos + 1] == 0)
        return 0;

    for (int i = pos + 2; i < n; i++)
    {
        if (state[i] == 1)
            return 0;
    }

    return 1;
}

int main()
{
    int n;

    printf("Enter number of switches: ");
    scanf("%d", &n);

    if (n <= 0 || n > 20)
    {
        printf("Invalid input\n");
        return 0;
    }

    int totalStates = 1 << n;

    int *distance = (int *)malloc(totalStates * sizeof(int));
    int *queue = (int *)malloc(totalStates * sizeof(int));

    if (distance == NULL || queue == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }

    for (int i = 0; i < totalStates; i++)
    {
        distance[i] = -1;
    }

    int start = totalStates - 1;
    int goal = 0;

    int front = 0;
    int rear = 0;

    queue[rear++] = start;
    distance[start] = 0;

    while (front < rear)
    {
        int current = queue[front++];

        if (current == goal)
            break;

        int state[20];

        for (int i = 0; i < n; i++)
        {
            state[i] = (current >> (n - 1 - i)) & 1;
        }

        for (int pos = 0; pos < n; pos++)
        {
            if (canToggle(state, n, pos))
            {
                int newState;

                newState = current ^ (1 << (n - 1 - pos));

                if (distance[newState] == -1)
                {
                    distance[newState] = distance[current] + 1;
                    queue[rear++] = newState;
                }
            }
        }
    }

    printf("\nMinimum number of moves = %d\n",
           distance[goal]);

    long long formula = (1LL << (n + 1)) / 3;

    printf("Formula result = %lld\n", formula);

    if (distance[goal] == formula)
    {
        printf("Validation successful\n");
    }
    else
    {
        printf("Validation failed\n");
    }

    free(distance);
    free(queue);

    return 0;
}