#include <stdio.h>
#include <pthread.h>
#include <pthread.h>
#include <omp.h>
#include <semaphore.h>

int main()
{
    int i = 0;
#pragma omp parallel num_threads(6)
    {
        // #pragma omp section
        if (omp_get_thread_num() < 3)
        {
            {
                printf("This is section 01.\n");
            }
        }
        // #pragma omp section
        if (omp_get_thread_num() >= 3)
        {
            {
                printf("This is section 02.\n");
            }
        }
    }
}