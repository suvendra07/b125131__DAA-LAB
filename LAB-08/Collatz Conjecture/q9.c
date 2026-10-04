#include <stdio.h>

void analyze_single(long long n) {
    long long current = n;
    int steps = 0;
    long long peak = current;

    while (current != 1) {
        if (current > peak) {
            peak = current;
        }
        if (current % 2 == 0) {
            current = current / 2;
        } else {
            current = 3 * current + 1;
        }
        steps++;
    }

    printf("Value %lld -> Steps: %d, Peak: %lld\n", n, steps, peak);
}

void analyze_range(long long a, long long b) {
    for (long long i = a; i <= b; i++) {
        analyze_single(i);
    }
}

int main() {
    long long n, a, b;
    printf("Enter single starting value: ");
    scanf("%lld", &n);
    analyze_single(n);

    printf("Enter range [a, b]: ");
    scanf("%lld %lld", &a, &b);
    analyze_range(a, b);

    return 0;
}