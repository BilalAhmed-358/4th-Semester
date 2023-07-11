#include<stdio.h>
#include <sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
   int a=fork();
   if(a>0)
     printf("I am Process 6 and my PID is %d\n",getpid()); 

   if(a==0)
     printf("I am Process 9 and my PID is %d\n",getpid());
}
