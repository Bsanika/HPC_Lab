#include<stdio.h>
#include<omp.h>

int main()
{ int num_threads;
  
  printf("Enter no. of threads:");
  scanf("%d",&num_threads);
  
  printf("Sequential Printing:\n");
  for(int i=0;i<num_threads;i++)
  {
  printf("Hello seq exec\n");
  }
  
  omp_set_num_threads(num_threads);
  
  printf("Parallel Printing:\n");
  #pragma omp parallel
  {
  printf("Hello from thread %d\n",omp_get_thread_num());
  }
  
  return 0;
  }
  

