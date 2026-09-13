#include <stdio.h>
#include <stdlib.h>

struct Event
{
    int year;
    int type;
};

int compare(const void *a, const void *b)
{
    struct Event *e1 = (struct Event *)a;
    struct Event *e2 = (struct Event *)b;

    if (e1->year != e2->year)
        return e1->year - e2->year;

    return e1->type - e2->type;
}

int main()
{
    int n;

    printf("Enter number of scientists: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    struct Event *events = (struct Event *)malloc(2 * n * sizeof(struct Event));

    if (events == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }

    printf("Enter birth year and death year of each scientist:\n");

    for (int i = 0; i < n; i++)
    {
        int birth, death;

        scanf("%d %d", &birth, &death);

        if (birth > death)
        {
            printf("Invalid input\n");
            free(events);
            return 0;
        }

        events[2 * i].year = birth;
        events[2 * i].type = 1;

        events[2 * i + 1].year = death;
        events[2 * i + 1].type = 0;
    }

    qsort(events, 2 * n, sizeof(struct Event), compare);

    int alive = 0;
    int maximum = 0;
    int bestYear = 0;

    for (int i = 0; i < 2 * n; i++)
    {
        if (events[i].type == 0)
        {
            alive--;
        }
        else
        {
            alive++;

            if (alive > maximum)
            {
                maximum = alive;
                bestYear = events[i].year;
            }
        }
    }

    printf("\nYear with maximum scientists alive = %d\n", bestYear);
    printf("Maximum number of scientists alive = %d\n", maximum);

    free(events);

    return 0;
}