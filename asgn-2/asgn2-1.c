#include<stdio.h>
#include<omp.h>

void vector_scalar_add(int *vector,int scalar,int *res,int size)
{ 
#pragma omp parallel for
  for(int i=0;i<size;i++)
  {
  res[i]=vector[i]+scalar;
  }
}
  
  
int main()
{
int size=100000;
int vector[size],res[size];
int scalar=5;

for(int i=0;i<size;i++)
{ 
 vector[i]=i;
}
  
vector_scalar_add(vector,scalar,res,size);

printf("Result:\n");
for(int i=0;i<10;i++)
{
printf("%d ", res[i]);
}
printf("\n");

return 0;

}
