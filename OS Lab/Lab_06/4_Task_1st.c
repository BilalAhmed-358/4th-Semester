#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>


int main(){
	int shmid=shmget(1234,10,0666|IPC_CREAT);
	int *s;

	s=(int*)shmat(shmid,NULL,0);
	*s=0;
	
}