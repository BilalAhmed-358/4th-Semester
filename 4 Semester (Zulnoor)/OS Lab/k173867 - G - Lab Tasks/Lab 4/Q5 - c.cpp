#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/wait.h>
int main()
{
   pid_t a,b,c;
   a=fork();

   if(a==0)
   b=fork();

   if(a==0&&b>0)
   c=fork();
  
   if(a>0)
   printf("I am Process 8 and my PID is %d \n",getpid());

  
   if(a==0&&b>0&&c>0)
   printf("I am Process 0 and my PID is %d \n",getpid());



  
   if(a==0&&b==0)
   printf("I am Process 7 and my PID is %d \n",getpid());



  
   if(a==0&&b>0&&c==0)
   printf("I am Process 2 and my PID is %d \n",getpid());



}
