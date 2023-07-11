#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
   int a,b,c,d;
   a=fork();
   b=fork();

   if( (a>0 && b>0) || (a>0&&b==0) )
   c=fork();
   

   if(a>0&&b==0&&c>0)
   d=fork();


   if(a>0&&b>0&&c>0)
   {
     printf("I am Process A and my PID is %d .\n",getpid());
     wait(NULL);
   }


   if(a==0&&b>0)
   printf("I am Process B and my PID is %d .\n",getpid());

   if(a>0&&b==0&&c>0&&d>0)
   printf("I am Process C and my PID is %d .\n",getpid());


   if(a>0&&b>0&&c==0)
   printf("I am Process D and my PID is %d .\n",getpid());


   if(a==0&&b==0)
   printf("I am Process E and my PID is %d .\n",getpid());


   if(a>0&&b==0&&c>0&&d==0)
   printf("I am Process F and my PID is %d .\n",getpid());


   if(a>0&&b==0&&c==0)
   printf("I am Process G and my PID is %d .\n",getpid());





}
