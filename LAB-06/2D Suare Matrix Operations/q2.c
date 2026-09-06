#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void add_matrices(int n, int a[10][10], int b[10][10], int c[10][10]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiply_matrices(int n, int a[10][10], int b[10][10], int c[10][10]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int is_zero(int n, int a[10][10]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != 0) return 0;
        }
    }
    return 1;
}

int is_symmetric(int n, int a[10][10]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) return 0;
        }
    }
    return 1;
}

void transpose(int n, int a[10][10]) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
}

double determinant(int n, double mat[10][10]) {
    double det = 1.0;
    double temp[10][10];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = mat[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int j = i + 1; j < n; j++) {
            if (fabs(temp[j][i]) > fabs(temp[pivot][i])) {
                pivot = j;
            }
        }
        if (pivot != i) {
            for (int k = 0; k < n; k++) {
                double t = temp[i][k];
                temp[i][k] = temp[pivot][k];
                temp[pivot][k] = t;
            }
            det *= -1;
        }
        if (temp[i][i] == 0) return 0;
        det *= temp[i][i];
        for (int j = i + 1; j < n; j++) {
            double factor = temp[j][i] / temp[i][i];
            for (int k = i + 1; k < n; k++) {
                temp[j][k] -= factor * temp[i][k];
            }
        }
    }
    return det;
}

void power_method(int n, double mat[10][10]) {
    double x[10], x_new[10];
    double lambda = 0;

    for (int i = 0; i < n; i++) {
        x[i] = 1.0;
    }

    for (int iter = 0; iter < 100; iter++) {
        for (int i = 0; i < n; i++) {
            x_new[i] = 0;
            for (int j = 0; j < n; j++) {
                x_new[i] += mat[i][j] * x[j];
            }
        }

        lambda = fabs(x_new[0]);
        for (int i = 1; i < n; i++) {
            if (fabs(x_new[i]) > lambda) {
                lambda = fabs(x_new[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            x[i] = x_new[i] / lambda;
        }
    }

    printf("Dominant Eigenvalue: %.2f\n", lambda);
    printf("Eigenvector: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", x[i]);
    }
    printf("\n");
}

int main() {
    int n;
    int a[10][10], b[10][10], res[10][10];
    double d_mat[10][10];

    printf("Enter matrix dimension (n): ");
    scanf("%d", &n);

    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            d_mat[i][j] = (double)a[i][j];
        }
    }

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    add_matrices(n, a, b, res);
    printf("\nMatrix Addition Result:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    multiply_matrices(n, a, b, res);
    printf("Matrix Multiplication Result:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    if (is_zero(n, a)) printf("Matrix A is a Zero Matrix\n");
    else printf("Matrix A is NOT a Zero Matrix\n");

    if (is_symmetric(n, a)) printf("Matrix A is Symmetric\n");
    else printf("Matrix A is NOT Symmetric\n");

    printf("Determinant of A: %.2f\n", determinant(n, d_mat));
    power_method(n, d_mat);

    transpose(n, a);
    printf("In-place Transpose of Matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}