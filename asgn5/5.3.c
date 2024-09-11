#include <omp.h>
#include <stdio.h>

int main() {
    int Aryabhatta = 10;  

    omp_set_num_threads(4);

    #pragma omp parallel private(Aryabhatta)
    {
        int threadID = omp_get_thread_num();  
        Aryabhatta = 10; 

        int result = threadID * Aryabhatta;

        printf("Thread ID: %d, Aryabhatta: %d, Result (ThreadID * Aryabhatta): %d\n", threadID, Aryabhatta, result);
    }

    return 0;
}

