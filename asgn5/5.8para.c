#include <stdio.h>
#include <omp.h>
#include <time.h>

int main() {
    int arr[1000000]; // large array of integers
    int sum = 0;

    // initialize array elements
    for (int i = 0; i < 1000000; i++) {
        arr[i] = i;
    }

    // calculate sum in parallel using OpenMP's reduction clause
    clock_t start_time = clock();
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < 1000000; i++) {
        sum += arr[i];
    }
    clock_t end_time = clock();

    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Parallel sum: %d\n", sum);
    printf("Parallel execution time: %f seconds\n", execution_time);

    return 0;
}
