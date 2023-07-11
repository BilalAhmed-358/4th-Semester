#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
int main()
{
    while(1)
    printf("%d\n", rand()%3);
}