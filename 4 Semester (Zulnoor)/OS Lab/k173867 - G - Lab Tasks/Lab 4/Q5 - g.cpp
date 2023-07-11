#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
   int a,b,c,d;
   a=fork();
   b=fork();

   if( (a==0&&b>0) || (a>0&&b==0) )
   c=fork();


   if(a>0&&b==0&&c>0)
   d=fork();

   if(a>0&&b>0)
   {
    printf("I am Process 10 and my PID is %d .\n",getpid());
    wait(NULL);
   }


   if(a==0&&b>0&&c>0)
   printf("I am Process 6 and my PID is %d .\n",getpid());


   if(a>0&&b==0&&c>0&&d>0)
   printf("I am Process 18 and my PID is %d .\n",getpid());


   if(a==0&&b==0)
   printf("I am Process 4 and my PID is %d .\n",getpid());


   if(a==0&&b>0&&c==0)
   printf("I am Process 8 and my PID is %d .\n",getpid());


   if(a>0&&b==0&&c>0&&d==0)
   printf("I am Process 15 and my PID is %d .\n",getpid());


   if(a>0&&b==0&&c==0)
   printf("I am Process 21 and my PID is %d .\n",getpid());



}
