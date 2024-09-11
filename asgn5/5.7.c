#include <omp.h>
#include <stdio.h>

#define N 1000000

int main() {
    int i, total_sum_unsync = 0, total_sum_critical = 0, total_sum_atomic = 0;
    int arr[N];

    // Initialize array with values
    for (i = 0; i < N; i++) {
        arr[i] = i;
    }

    // Unsynchronized version (data race)
    double start_time_unsync = omp_get_wtime();
    #pragma omp parallel for
    for (i = 0; i < N; i++) {
        total_sum_unsync += arr[i];
    }
    double end_time_unsync = omp_get_wtime();

    // Synchronized version using critical directive
    total_sum_critical = 0;
    double start_time_critical = omp_get_wtime();
    #pragma omp parallel for
    for (i = 0; i < N; i++) {
        #pragma omp critical
        total_sum_critical += arr[i];
    }
    double end_time_critical = omp_get_wtime();

    // Synchronized version using atomic directive
    total_sum_atomic = 0;
    double start_time_atomic = omp_get_wtime();
    #pragma omp parallel for
    for (i = 0; i < N; i++) {
        #pragma omp atomic
        total_sum_atomic += arr[i];
    }
    double end_time_atomic = omp_get_wtime();

    printf("Unsynchronized total sum: %d\n", total_sum_unsync);
    printf("Unsynchronized execution time: %f seconds\n", end_time_unsync - start_time_unsync);
    printf("Synchronized total sum (critical): %d\n", total_sum_critical);
    printf("Synchronized execution time (critical): %f seconds\n", end_time_critical - start_time_critical);
    printf("Synchronized total sum (atomic): %d\n", total_sum_atomic);
    printf("Synchronized execution time (atomic): %f seconds\n", end_time_atomic - start_time_atomic);

    return 0;
}
