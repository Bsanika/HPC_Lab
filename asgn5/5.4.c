#include <omp.h>
#include <stdio.h>

int main() {
    int total_sum = 0;
    int n = 20;

    #pragma omp parallel for lastprivate(total_sum)
    for (int i = 1; i <= n; i++) {
        int partial_sum = 0;
        #pragma omp parallel for
        for (int j = i; j <= n; j += omp_get_num_threads()) {
            partial_sum += j;
        }
        total_sum += partial_sum;
    }

    printf("Total sum: %d\n", total_sum);

    return 0;
}
