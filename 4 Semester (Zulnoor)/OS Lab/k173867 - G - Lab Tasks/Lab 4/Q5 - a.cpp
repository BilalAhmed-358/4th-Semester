#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
   int a,b,c;

   a=fork();

   if(a>0)
   b=fork();

   if(b==0 && a>0 )
   c=fork();

   if( a>0 && b>0)
	printf("I am Process 1 and my PID is %d\n",getpid());

   if( a==0)
	printf("I am Process 5 and my PID is %d\n",getpid());

   if( a>0 && b==0 && c>0 )
	printf("I am Process 3 and my PID is %d\n",getpid());

   if( a>0 && b==0 && c==0 )
	printf("I am Process 4 and my PID is %d\n",getpid());

}

