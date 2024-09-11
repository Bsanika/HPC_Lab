#include <omp.h>
#include <stdio.h>

int main() {
    int numThreads = 4; 
    int sumOfSquares = 0; 

    omp_set_num_threads(numThreads);

    #pragma omp parallel reduction(+:sumOfSquares)
    {
        int threadID = omp_get_thread_num();  
        int square = threadID * threadID;     

        printf("Thread ID: %d, Square: %d\n", threadID, square);

        sumOfSquares += square;
    }

    printf("Sum of squares of thread IDs: %d\n", sumOfSquares);

    return 0;
}

