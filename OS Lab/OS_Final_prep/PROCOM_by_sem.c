#include <stdio.h>
#include <pthread.h>
#include <pthread.h>
#include <omp.h>
#include <semaphore.h>

sem_t volunteer;
pthread_t volun[4];
void *Registration()
{
    sem_wait(&volunteer);
    for (int i = 0; i < 25; i++)
    {
        printf("Doing registration %d.\n", i);
    }

    sem_post(&volunteer);
}
void *Announcement()
{
    sem_wait(&volunteer);
    for (int i = 0; i < 25; i++)
    {
        printf("Doing Announcement %d.\n", i);
    }

    sem_post(&volunteer);
}
void *Sponsors()
{
    sem_wait(&volunteer);
    for (int i = 0; i < 25; i++)
    {
        printf("Doing Sponsors %d.\n", i);
    }

    sem_post(&volunteer);
}
void *Queries()
{
    sem_wait(&volunteer);
    for (int i = 0; i < 25; i++)
    {
        printf("Doing Queries %d.\n", i);
    }

    sem_post(&volunteer);
}
int main()
{
    sem_init(&volunteer, 0, 4);
    pthread_create(&volun[0], NULL, Registration, NULL);
    pthread_create(&volun[1], NULL, Announcement, NULL);
    pthread_create(&volun[2], NULL, Sponsors, NULL);
    pthread_create(&volun[3], NULL, Queries, NULL);
    for (int i = 0; i < 4; i++)
    {
        pthread_join(volun[i], NULL);
    }

    sem_destroy(&volunteer);
}