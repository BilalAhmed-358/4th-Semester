#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
   pid_t a,b,c;
   a=fork();
   b=fork();

   if(a==0&&b>0)
   c=fork();

   if(a>0 && b>0 )
   printf("I am Process root and my PID is %d .\n",getpid());

   if(a==0 && b>0 && c>0)
   printf("I am Process ineer node  and my PID is %d .\n",getpid());


   if( (a==0&&b==0) || (a>0&&b==0) ||  (a==0&&b>0&&c==0)  )
   printf("I am Process leaf and my PID is %d .\n",getpid());





}
