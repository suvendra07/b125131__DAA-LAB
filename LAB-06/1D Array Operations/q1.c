#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int find_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void find_two_largest(int arr[], int n) {
    int first = arr[0];
    int second = -1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    printf("First Largest: %d\n", first);
    if (second != -1) {
        printf("Second Largest: %d\n", second);
    } else {
        printf("Second Largest: Does not exist\n");
    }
}

double get_mean(int arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

double get_median(int arr[], int n) {
    int temp[100];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    qsort(temp, n, sizeof(int), compare);
    if (n % 2 == 0) {
        return (temp[n / 2 - 1] + temp[n / 2]) / 2.0;
    } else {
        return temp[n / 2];
    }
}

double get_std_dev(int arr[], int n) {
    double mean = get_mean(arr, n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (arr[i] - mean) * (arr[i] - mean);
    }
    return sqrt(sum / n);
}

int get_mode(int arr[], int n) {
    int max_count = 0;
    int mode = arr[0];
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            mode = arr[i];
        }
    }
    return mode;
}

int remove_duplicates(int arr[], int n) {
    int new_size = 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < new_size; j++) {
            if (arr[i] == arr[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            arr[new_size] = arr[i];
            new_size++;
        }
    }
    return new_size;
}

void reverse_array(int arr[], int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        swap(&arr[i], &arr[j]);
        i++;
        j--;
    }
}

int partition(int arr[], int n, int pivot_idx) {
    int pivot = arr[pivot_idx];
    swap(&arr[pivot_idx], &arr[n - 1]);
    int i = 0;
    for (int j = 0; j < n - 1; j++) {
        if (arr[j] >= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[n - 1]);
    return i;
}

int main() {
    int n, pivot_idx;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nMaximum: %d\n", find_max(arr, n));
    find_two_largest(arr, n);
    printf("Mean: %.2f\n", get_mean(arr, n));
    printf("Median: %.2f\n", get_median(arr, n));
    printf("Standard Deviation: %.2f\n", get_std_dev(arr, n));
    printf("Mode: %d\n", get_mode(arr, n));

    printf("Enter index of pivot to partition (0 to %d): ", n - 1);
    scanf("%d", &pivot_idx);
    int p = partition(arr, n, pivot_idx);
    printf("New position of pivot: %d\n", p);

    reverse_array(arr, n);
    printf("Reversed array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int new_n = remove_duplicates(arr, n);
    printf("Array after removing duplicates: ");
    for (int i = 0; i < new_n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}