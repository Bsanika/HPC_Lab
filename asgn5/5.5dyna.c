#include <omp.h>
#include <iostream>
#include <vector>
#include <ctime>

#define N 500// Matrix size

void matrixMultiplicationDynamic(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C) {
    #pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    std::vector<std::vector<int>> A(N, std::vector<int>(N, 1));
    std::vector<std::vector<int>> B(N, std::vector<int>(N, 2));
    std::vector<std::vector<int>> C(N, std::vector<int>(N, 0));

    double start = omp_get_wtime();
    matrixMultiplicationDynamic(A, B, C);
    double end = omp_get_wtime();

    double time_taken = end - start;
    std::cout << "Time taken for matrix multiplication with dynamic scheduling: " << time_taken << " seconds\n";

    return 0;
}

