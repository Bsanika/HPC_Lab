#include <stdio.h>
#include <omp.h>

#define SIZE 3

int main() {
    int matrix[SIZE][SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int vector[SIZE] = {1, 2, 3};
    int result[SIZE] = {0};
    int i, j;

    #pragma omp parallel for private(i, j) shared(matrix, vector, result)
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }

    for (i = 0; i < SIZE; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}

