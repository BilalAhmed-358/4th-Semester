#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
int x,g_parent,counter=0;
g_parent=getppid();
x=fork();
while(counter<5)
printf("%d\n",++counter);

if(x>0)
wait(NULL);

if(x==0)
{
sleep(3);
printf("Grand Parent ID: %d\n",g_parent);
execlp("gedit","gedit",(char*)0);
}

}
