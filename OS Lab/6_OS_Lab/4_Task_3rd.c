#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
	int shmid=shmget(1234,10,0666);
	int *s;
	s=(int*)shmat(shmid,NULL,0);
	printf("%d\n",*s);
	int shmid1=shmget(12345,10,0666);
	int *p;
	p=(int*)shmat(shmid1,NULL,0);
	printf("%d\n",*p);
	int i=0;
	printf("Enter n:");
	scanf("%d",&i);
	int j,fib;
	for(j=0;j<i;j++){
		fib=*s+*p;
		*s=*p;
		*p=fib;
		printf("%d\n",fib);
	}	
}

