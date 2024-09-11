#include <iostream>
#include <vector>
#include <ctime>

#define N 500 // Matrix size

void matrixMultiplicationSerial(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C) {
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

    clock_t start = clock();
    matrixMultiplicationSerial(A, B, C);
    clock_t end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time taken for serial matrix multiplication: " << time_taken << " seconds\n";
    
    return 0;
}

