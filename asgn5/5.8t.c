#include <stdio.h>
#include <omp.h>

int main() {
    int arr_size[] = {100000, 500000, 1000000, 2000000};
    int num_threads[] = {1, 2, 4, 8};

    for (int i = 0; i < 4; i++) {
        int arr[arr_size[i]];
        int sum = 0;

        // initialize array elements
        for (int j = 0; j < arr_size[i]; j++) {
            arr[j] = j;
        }

        // set number of threads
        omp_set_num_threads(num_threads[i]);

        // calculate sum in parallel using OpenMP's reduction clause
        double start_time = omp_get_wtime();
        #pragma omp parallel for reduction(+:sum)
        for (int j = 0; j < arr_size[i]; j++) {
            sum += arr[j];
        }
        double end_time = omp_get_wtime();

        double execution_time = end_time - start_time;

        printf("Array size: %d, Num threads: %d, Sum: %d, Time: %f seconds\n",
               arr_size[i], num_threads[i], sum, execution_time);
    }

    return 0;
}
