#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

/*We are assuming that each batch contains 10 customers
Each customer has to:
i) weigh his luggage (takes 4 seconds)
ii) get it checked (takes 7 seconds)
iii) get a boarding pass (takes 3 seconds)*/

/*
    We also make an assumption that At a given time 5 boarding terminals are available for custumers.
*/

sem_t terminal;
void *boarding_routine(void *args)
{
    sem_wait(&terminal);
    int index = *(int *)args;
    printf("PASSENGER %d arrived at the boarding terminal.\n\n", index);
    printf("PASSENGER %d arrived at weighing his/her luggage...\n\n", index);
    sleep(4);
    printf("PASSENGER %d getting his/her luggage checked...\n\n", index);
    sleep(7);
    printf("PASSENGER %d receiving his/her boarding pass...\n\n", index);
    sleep(3);
    sem_post(&terminal);
}
int main()
{
    pthread_t passengers[10];
    sem_init(&terminal, 0, 5);
    int i;
    for (i = 0; i < 10; i++)
    {
        int *a = malloc(sizeof(int));
        *a = i + 1;
        if (pthread_create(&passengers[i], NULL, &boarding_routine, (void *)a) != 0)
        {
            printf("Couldn't create thread %d\n.", i);
        }
    }
    for (i = 0; i < 10; i++)
    {
        if (pthread_join(passengers[i], NULL) != 0)
        {
            printf("Couldn't join thread %d\n.", i);
        }
    }
    sem_destroy(&terminal);
}