#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<omp.h>
int main (int argc, char *argv[]) {
int i, tid, nthreads, n = 10, N = 100000000;
double *A, *B, tResult, fResult;
time_t start, stop;
clock_t ticks;
long count;
A = (double *) malloc(N*sizeof(double));
B = (double *) malloc(N*sizeof(double));
for (i=0; i<N; i++) {
A[i] = (double)(i+1);
B[i] = (double)(i+1);
}
time(&start);
//this block use single process
for (i=0; i<N; i++)
{
fResult = fResult + A[i] + B[i];
}
//begin of parallel section
#pragma omp parallel private(tid, i,tResult) shared(n,A,B,fResult)
{
tid = omp_get_thread_num();
if (tid == 0) {
nthreads = omp_get_num_threads();
printf("Number of threads = %d\n", nthreads);
}
#pragma omp for schedule (static, n)
for (i=0; i < N; i++) {
tResult = tResult + A[i] + B[i];
}
#pragma omp for nowait
for (i=0; i < n; i++)
{
printf("Thread %d does iteration %d\n", tid, i);
}
#pragma omp critical
fResult = fResult + tResult;
}
//end of parallel section
time(&stop);
printf("%f\n",fResult);
printf("Finished in about %.0f seconds. \n", difftime(stop, start));
exit(0);
}
