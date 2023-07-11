#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 2000000000
// 10 arab iterations
int main()
{
    clock_t t;
    time_t start, stop;
    long long int i;
    printf("This file will check the time period without openmp.\nWe are taking the value of N=2000000000.\n");
    float sum = 0;
    t = clock();
    time(&start);
    #pragma omp parallel for reduction(+:sum)
    for ( i = 1; i < N; i++)
    {
        sum+=1/(float)i;
    }
    printf("%f\n",sum);
    time(&stop);
    t = clock() - t;
    // double time_taken=((double)t)/CLOCKS_PER_SEC;
    printf("It took %.0f seconds to perform this task with parallelism.\n", difftime(stop, start));
}