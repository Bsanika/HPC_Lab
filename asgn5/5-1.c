#include <omp.h>
#include <stdio.h>

int main() {
    
    const char *familyMembers[] = {"Sanika", "Sarvesh", "Manaswi", "Sarthak"};
    
    int numMembers = 4; 

    omp_set_num_threads(numMembers);

    #pragma omp parallel
    {
        int threadID = omp_get_thread_num();
        printf("Family Member: %s, Thread ID: %d\n", familyMembers[threadID], threadID);
    }

    return 0;
}

