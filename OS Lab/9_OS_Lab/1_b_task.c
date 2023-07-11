#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
sem_t Icecreamremaining;
typedef struct people_thread
{
    pthread_t people;
    int money;
    int id;
} people_thread;
people_thread customers[3];

void *icecreamservingroutine(void *args)
{
    people_thread index = *(people_thread *)args;
    sem_wait(&Icecreamremaining);
    /*This function will iteratively get called for each thread and will be protected by a semaphore,
    we make an assumption that each person will take 3 secs to finish his icecream and counting his money*/
    printf("Serving icecream to person %d.\n", index.id);
    printf("Counting money...\n");
    sleep(2);
    printf("Customer %d has Rs.%d/-. \n", index.id, index.money);
    printf("The icecream costs Rs.%d/-, after payment the customer has Rs.%d/- amount remaining.\n\n", 100, index.money - 100);
    if (index.id == 3)
    {
        printf("All people have finished their icereams.\n");
    }

    sem_post(&Icecreamremaining);
}
int main()
{
    sem_init(&Icecreamremaining, 0, 1);
    int i;
    for (i = 0; i < 3; i++)
    {
        customers[i].id = i + 1;
        customers[i].money = rand() % 1000;

        if (pthread_create(&customers[i].people, NULL, &icecreamservingroutine, (void *)&customers[i]) != 0)
        {
            printf("Failed to create threads.\n");
        }
    }
    for (i = 0; i < 3; i++)
    {

        if (pthread_join(customers[i].people, NULL) != 0)
        {
            printf("Failed to join threads.\n");
        }
    }
    sem_destroy(&Icecreamremaining);
}