#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double r;
    double i;
} Comp;

Comp add(Comp a, Comp b) {
    Comp res = {a.r + b.r, a.i + b.i};
    return res;
}

Comp sub(Comp a, Comp b) {
    Comp res = {a.r - b.r, a.i - b.i};
    return res;
}

Comp mul(Comp a, Comp b) {
    Comp res = {a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r};
    return res;
}

void fft(Comp a[], int n, int inv) {
    if (n == 1) return;

    Comp a0[1024], a1[1024];
    for (int i = 0; i < n / 2; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }

    fft(a0, n / 2, inv);
    fft(a1, n / 2, inv);

    double ang = 2 * PI / n * (inv ? -1 : 1);
    Comp w = {1, 0};
    Comp wn = {cos(ang), sin(ang)};

    for (int i = 0; i < n / 2; i++) {
        Comp t = mul(w, a1[i]);
        a[i] = add(a0[i], t);
        a[i + n / 2] = sub(a0[i], t);
        if (inv) {
            a[i].r /= 2; a[i].i /= 2;
            a[i + n / 2].r /= 2; a[i + n / 2].i /= 2;
        }
        w = mul(w, wn);
    }
}

int main() {
    int m, n;
    double A[500], B[500];
    Comp ca[1024], cb[1024];

    printf("Enter size of vector A (m): ");
    scanf("%d", &m);
    printf("Enter elements of A: ");
    for (int i = 0; i < m; i++) scanf("%lf", &A[i]);

    printf("Enter size of vector B (n): ");
    scanf("%d", &n);
    printf("Enter elements of B: ");
    for (int i = 0; i < n; i++) scanf("%lf", &B[i]);

    int total_len = m + n - 1;
    int N = 1;
    while (N < total_len) N *= 2;

    for (int i = 0; i < N; i++) {
        ca[i].r = (i < m) ? A[i] : 0;
        ca[i].i = 0;
        cb[i].r = (i < n) ? B[i] : 0;
        cb[i].i = 0;
    }

    fft(ca, N, 0);
    fft(cb, N, 0);

    for (int i = 0; i < N; i++) {
        ca[i] = mul(ca[i], cb[i]);
    }

    fft(ca, N, 1);

    printf("\nConvolution Result Vector C: ");
    for (int i = 0; i < total_len; i++) {
        printf("%.2f ", ca[i].r);
    }
    printf("\n");

    return 0;
}