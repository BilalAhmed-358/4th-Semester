#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
  pid_t pid=fork();
 
 if(pid<0)
 {
   printf("Unsuccessful Child Process Creation");
   exit(0);
 } 

 if(pid>0)
 {
  wait(NULL);
  for(int i=2;i<=10;i=i+2)
  printf("%d ",i);

  printf("\nParent Ends\n");
 }

 if(pid==0)
 {
  printf("\nParent ID is %d\n",getppid());
  for(int i=1;i<=10;i=i+2)
   printf("%d ",i);

  printf("\nChild Ends\n");
 }

return(0);

}

