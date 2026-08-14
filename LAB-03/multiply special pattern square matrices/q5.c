#include <stdio.h>
#include <stdlib.h>

int** allocateMatrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }
    return matrix;
}

void freeMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void multiplySpecial(int** A, int** B, int** C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int half = n / 2;

    int** A1 = allocateMatrix(half);
    int** A2 = allocateMatrix(half);
    int** B1 = allocateMatrix(half);
    int** B2 = allocateMatrix(half);

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A1[i][j] = A[i][j];
            A2[i][j] = A[i][j + half];
            B1[i][j] = B[i][j];
            B2[i][j] = B[i][j + half];
        }
    }

    int** A_add = allocateMatrix(half);
    int** B_add = allocateMatrix(half);
    int** A_sub = allocateMatrix(half);
    int** B_sub = allocateMatrix(half);

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A_add[i][j] = A1[i][j] + A2[i][j];
            B_add[i][j] = B1[i][j] + B2[i][j];
            A_sub[i][j] = A1[i][j] - A2[i][j];
            B_sub[i][j] = B1[i][j] - B2[i][j];
        }
    }

    int** P1 = allocateMatrix(half);
    int** P2 = allocateMatrix(half);

    multiplySpecial(A_add, B_add, P1, half);
    multiplySpecial(A_sub, B_sub, P2, half);

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            int c1 = (P1[i][j] + P2[i][j]) / 2;
            int c2 = (P1[i][j] - P2[i][j]) / 2;

            C[i][j] = c1;
            C[i][j + half] = c2;
            C[i + half][j] = c2;
            C[i + half][j + half] = c1;
        }
    }

    freeMatrix(A1, half);
    freeMatrix(A2, half);
    freeMatrix(B1, half);
    freeMatrix(B2, half);
    freeMatrix(A_add, half);
    freeMatrix(B_add, half);
    freeMatrix(A_sub, half);
    freeMatrix(B_sub, half);
    freeMatrix(P1, half);
    freeMatrix(P2, half);
}

int main() {
    int n = 4;
    int** A = allocateMatrix(n);
    int** B = allocateMatrix(n);
    int** C = allocateMatrix(n);

    int valA[4][4] = {
        {1, 2, 3, 4},
        {2, 1, 4, 3},
        {3, 4, 1, 2},
        {4, 3, 2, 1}
    };

    int valB[4][4] = {
        {5, 6, 7, 8},
        {6, 5, 8, 7},
        {7, 8, 5, 6},
        {8, 7, 6, 5}
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = valA[i][j];
            B[i][j] = valB[i][j];
        }
    }

    multiplySpecial(A, B, C, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    freeMatrix(A, n);
    freeMatrix(B, n);
    freeMatrix(C, n);

    return 0;
}