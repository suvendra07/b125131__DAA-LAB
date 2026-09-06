#include <stdio.h>

void reverse(int p[], int i, int j) {
    while (i < j) {
        int temp = p[i];
        p[i] = p[j];
        p[j] = temp;
        i++;
        j--;
    }
}

void solve_merge(int p[], int left, int mid, int right, int *cost) {
    int l = left, r = mid + 1;
    while (l <= mid && p[l] <= mid + 1) l++;
    while (r <= right && p[r] <= mid + 1) r++;

    if (l <= mid && r - 1 >= mid + 1) {
        *cost += (r - l);
        reverse(p, l, r - 1);
    }
}

void divide_and_conquer(int p[], int left, int right, int *cost) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    divide_and_conquer(p, left, mid, cost);
    divide_and_conquer(p, mid + 1, right, cost);
    solve_merge(p, left, mid, right, cost);
}

int main() {
    int n;
    int p[100];
    int total_cost = 0;

    printf("Enter number of elements in permutation (n): ");
    scanf("%d", &n);

    printf("Enter permutation of integers 1 to %d: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    divide_and_conquer(p, 0, n - 1, &total_cost);

    printf("\nSorted permutation: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\nTotal Cost of Reversals: %d\n", total_cost);

    return 0;
}