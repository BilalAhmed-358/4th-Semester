#include <stdio.h>
#include <pthread.h>
#include <pthread.h>
#include <omp.h>
#include <semaphore.h>

void *A()
{
    printf("A\n");
}
void *B()
{
    printf("B\n");
}
void *C()
{
    printf("C\n");
}
void *D()
{
    printf("D\n");
}
void *E()
{
    printf("E\n");
}

int main()
{
    pthread_t p1, p2, p3, p4, p5;
    pthread_create(&p1, NULL, A, NULL);
    pthread_create(&p2, NULL, B, NULL);
    pthread_create(&p3, NULL, C, NULL);
    pthread_join(p2, NULL);
    pthread_join(p3, NULL);
    pthread_create(&p4, NULL, D, NULL);
    pthread_join(p4, NULL);
    pthread_create(&p5, NULL, E, NULL);
    pthread_join(p5, NULL);
}