#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define n 4

struct start_end_numbers
{
 long thread_number;
 long st;
 long en;
} ;

void *multiply(void *t)
{
   printf("\n\n%ld THREAD WORKING : \n\n",((struct start_end_numbers*)t)->thread_number+1);
   for(long i=((struct start_end_numbers*)t)->st;i<=((struct start_end_numbers*)t)->en;i++)
   printf("5 * %ld = %ld\n",i,5*i);
}

int main()
{
  pthread_t tid[n];
  struct start_end_numbers * t[4];

  for(int i=0;i<4;i++)
  t[i]=(struct start_end_numbers *)malloc(sizeof(struct start_end_numbers));

  for(int i=0;i<4;i++)
 { 
   t[i]->thread_number=i;
   t[i]->st=(250*i)+1;
   t[i]->en=250*(i+1);
 }


 for(long i=0;i<n;i++)
 {
   pthread_create(&tid[i],NULL,multiply,(void *)t[i]);
 }

 for(int i=0;i<n;i++)
 {
   pthread_join(tid[i],NULL);
 }

 return(0);

}
