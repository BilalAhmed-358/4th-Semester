#include <stdio.h>
#include <omp.h>
#include <semaphore.h>
#include <unistd.h>
sem_t semlock;
int main()
{
    sem_init(&semlock, 0, 1);
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {6, 7, 8, 9, 10};
    int c[5];
    int tid;

#pragma omp parallel num_threads(5)
    {
        sem_wait(&semlock);
        tid = omp_get_thread_num();
#pragma omp critical
        c[tid] = a[tid] + b[tid];
        printf("c[%d]=%d\n", tid, c[tid]);
        alarm(5);
        sem_post(&semlock);
    }
    sem_destroy(&semlock);
}