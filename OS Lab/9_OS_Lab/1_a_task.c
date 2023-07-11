#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

sem_t Icecreamremaining;
void *icecreamservingroutine(void *args)
{
    sem_wait(&Icecreamremaining);
    /*This function will iteratively get called for each thread and will be protected by a semaphore,
    we make an assumption that each person will take 3 secs to finish his iceream*/
    printf("Serving icecream to person %d.\n", *(int *)args);
    if (*(int *)args == 2)
    {
        printf("All people have finished their icereams.\n");
    }
    sleep(3);
    free(args);
    sem_post(&Icecreamremaining);
}
int main()
{
    pthread_t people[3];
    sem_init(&Icecreamremaining, 0, 1);
    int i;
    for (i = 0; i < 3; i++)
    {
        int *a = malloc(sizeof(int));
        *a = i;

        if (pthread_create(&people[i], NULL, &icecreamservingroutine, a) != 0)
        {
            printf("Failed to create threads.\n");
        }
    }
    for (i = 0; i < 3; i++)
    {

        if (pthread_join(people[i], NULL) != 0)
        {
            printf("Failed to join threads.\n");
        }
    }
    sem_destroy(&Icecreamremaining);
}