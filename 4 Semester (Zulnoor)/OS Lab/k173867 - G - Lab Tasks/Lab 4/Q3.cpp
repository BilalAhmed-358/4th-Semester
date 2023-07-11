#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
int x,y,z;
x=fork();

if(x==0)
y=fork();

if(x==0&&y==0)
z=fork();

if(x==0&&y>0)
{
wait(NULL);
printf("process 1 ends.\n");
}

if(x==0&&y==0&&z>0)
{
wait(NULL);
printf("process 2 ends.\n");
}

if(x==0&&y==0&&z==0)
{
execlp("echo","echo","bash command in process 3.",(char*)0);
}

}
