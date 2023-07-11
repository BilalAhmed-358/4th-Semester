#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define n 4

void *multiply(void *thread_number)
{

  printf("\n\n%ld THREAD WORKING :\n\n",(long)thread_number+1);
  if((long )thread_number==0)
  {
     for(int i=0;i<25;i++)
     printf("Volunteer 1 managing On day registration with %d participant .\n",i+1);
  }

  if((long )thread_number==1)
  {
     for(int i=0;i<25;i++)
     printf("Volunteer 2 handling announcements with %d participant .\n",i+1);
  }

  if((long )thread_number==2)
  {
     for(int i=0;i<25;i++)
     printf("Volunteer 3 handling sponsors with %d participant .\n",i+1);
  }

  if((long )thread_number==3)
  {
     for(int i=0;i<25;i++)
     printf("Volunteer 4 resolving queries of %d participant .\n",i+1);
  }

}

int main()
{
  pthread_t tid[n];
  
 for(long i=0;i<n;i++)
 {
   pthread_create(&tid[i],NULL,multiply,(void *)i);
 }

 for(int i=0;i<n;i++)
 {
   pthread_join(tid[i],NULL);
 }

 return(0);

}
