#include <stdio.h>
#include <pthread.h>
#include <pthread.h>
#include <omp.h>
#include <semaphore.h>

int main()
{
    int i = 0;
#pragma omp parallel for num_threads(4) sections
    {
#pragma section
        {
            for (int i = 0; i < 25; i++)
                printf("This handles On day registration.\n");
        }

#pragma section
        {
            for (int i = 0; i < 25; i++)
                printf("This handles announcements.\n");
        }

#pragma section
        {
            for (int i = 0; i < 25; i++)
                printf("This handles sponsors.\n");
        }

#pragma section
        {
            printf("This handles queries of participants.\n");
        }
    }
}