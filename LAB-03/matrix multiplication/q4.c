#include <stdio.h>
#include <stdlib.h>

int** allocateMatrix(int size) {
    int** matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int*)malloc(size * sizeof(int));
    }
    return matrix;
}

void freeMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void addMatrix(int** A, int** B, int** C, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subMatrix(int** A, int** B, int** C, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen(int** A, int** B, int** C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int half = n / 2;

    int** A11 = allocateMatrix(half);
    int** A12 = allocateMatrix(half);
    int** A21 = allocateMatrix(half);
    int** A22 = allocateMatrix(half);

    int** B11 = allocateMatrix(half);
    int** B12 = allocateMatrix(half);
    int** B21 = allocateMatrix(half);
    int** B22 = allocateMatrix(half);

    int** P1 = allocateMatrix(half);
    int** P2 = allocateMatrix(half);
    int** P3 = allocateMatrix(half);
    int** P4 = allocateMatrix(half);
    int** P5 = allocateMatrix(half);
    int** P6 = allocateMatrix(half);
    int** P7 = allocateMatrix(half);

    int** tempA = allocateMatrix(half);
    int** tempB = allocateMatrix(half);

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    subMatrix(B12, B22, tempB, half);
    strassen(A11, tempB, P1, half);

    addMatrix(A11, A12, tempA, half);
    strassen(tempA, B22, P2, half);

    addMatrix(A21, A22, tempA, half);
    strassen(tempA, B11, P3, half);

    subMatrix(B21, B11, tempB, half);
    strassen(A22, tempB, P4, half);

    addMatrix(A11, A22, tempA, half);
    addMatrix(B11, B22, tempB, half);
    strassen(tempA, tempB, P5, half);

    subMatrix(A12, A22, tempA, half);
    addMatrix(B21, B22, tempB, half);
    strassen(tempA, tempB, P6, half);

    subMatrix(A11, A21, tempA, half);
    addMatrix(B11, B12, tempB, half);
    strassen(tempA, tempB, P7, half);

    addMatrix(P5, P4, tempA, half);
    subMatrix(tempA, P2, tempB, half);
    addMatrix(tempB, P6, tempA, half); 

    int** C12 = allocateMatrix(half);
    addMatrix(P1, P2, C12, half);

    int** C21 = allocateMatrix(half);
    addMatrix(P3, P4, C21, half);

    int** C22 = allocateMatrix(half);
    addMatrix(P1, P5, tempB, half);
    subMatrix(tempB, P3, tempB, half);
    subMatrix(tempB, P7, C22, half);

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j]             = tempA[i][j]; 
            C[i][j + half]      = C12[i][j];   
            C[i + half][j]      = C21[i][j]; 
            C[i + half][j + half]= C22[i][j]; 
        }
    }

    freeMatrix(A11, half); freeMatrix(A12, half);
    freeMatrix(A21, half); freeMatrix(A22, half);
    freeMatrix(B11, half); freeMatrix(B12, half);
    freeMatrix(B21, half); freeMatrix(B22, half);
    freeMatrix(P1, half);  freeMatrix(P2, half);
    freeMatrix(P3, half);  freeMatrix(P4, half);
    freeMatrix(P5, half);  freeMatrix(P6, half);
    freeMatrix(P7, half);
    freeMatrix(tempA, half); freeMatrix(tempB, half);
    freeMatrix(C12, half); freeMatrix(C21, half); freeMatrix(C22, half);
}

void printMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 4; 

    int** A = allocateMatrix(n);
    int** B = allocateMatrix(n);
    int** C = allocateMatrix(n);

    int valA[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int valB[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = valA[i][j];
            B[i][j] = valB[i][j];
        }
    }

    printf("Matrix A:\n");
    printMatrix(A, n);

    printf("\nMatrix B:\n");
    printMatrix(B, n);

    strassen(A, B, C, n);

    printf("\nResult Matrix C (A x B):\n");
    printMatrix(C, n);

    freeMatrix(A, n);
    freeMatrix(B, n);
    freeMatrix(C, n);

    return 0;
}