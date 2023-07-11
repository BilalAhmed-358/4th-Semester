#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#define MAXSIZE 27

void die(char *str) {
	perror(str);
	exit(1);
}

int main(void) {
	int shmid;
	key_t key;
	long long int *shm;

	key = 2211;
	
	if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shm = shmat(shmid, NULL, 0)) == (long long int*) -1)
		die("shmat");

	
        *shm=0;


        while(*shm!='*')
        sleep(1);
        
        exit(0);
}
