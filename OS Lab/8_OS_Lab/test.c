#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main()
{
    int num;
    int i;
    printf("Table [PROMPT] Enter your number: ");
    scanf("%d",&num);
    #pragma omp parallel num_threads(10)
    #pragma omp for
    for (int i = 0; i < 10000; i++)
    {
        printf("Table [INFO] Thread ID: %d | %d X %d = %d \n", omp_get_thread_num(),i,num,i*num);
    }
    return 0;
}