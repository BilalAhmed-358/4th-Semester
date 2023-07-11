#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define n 4

void *multiply(void *thread_number)
{

  printf("\n\nThread %ld working \n\n",(long)thread_number+1);
  if((long )thread_number==0)
  {
     for(int j=1;j<=10;j++)
     printf("5  * %d = %d\n",j,5*j);
  }

  if((long )thread_number==1)
  {
     for(int j=1;j<=10;j++)
     printf("6  * %d = %d\n",j,6*j);
  }

  if((long )thread_number==2)
  {
     for(int j=1;j<=10;j++)
     printf("7  * %d = %d\n",j,7*j);
  }

  if((long )thread_number==3)
  {
     for(int j=1;j<=10;j++)
     printf("8  * %d = %d\n",j,8*j);
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
