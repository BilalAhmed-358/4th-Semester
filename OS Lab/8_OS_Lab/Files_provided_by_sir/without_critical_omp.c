#include<stdio.h>
#include<omp.h>

int main()
{
int x=0;

#pragma omp parallel num_threads(300)
{
x=x+1;
}

printf("x=%d\n",x);
}
