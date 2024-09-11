#include <stdio.h>
#include <omp.h>

void print_series_2() {
    // Series of 2: 2, 4, 6, 8, 10...
    for (int i = 1; i <= 5; i++) {
        printf("Thread 1: %d\n", 2 * i);
    }
}

void print_series_4() {
    // Series of 4: 4, 8, 12, 16, 20...
    for (int i = 1; i <= 5; i++) {
        printf("Thread 2: %d\n", 4 * i);
    }
}

int main() {
    // Parallel region with two threads
    #pragma omp parallel num_threads(2)
    {
        // Thread with ID 0 will print the series of 2
        if (omp_get_thread_num() == 0) {
            print_series_2();
        }
        // Thread with ID 1 will print the series of 4
        else if (omp_get_thread_num() == 1) {
            print_series_4();
        }
    }
    
    return 0;
}

