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
	int *shm;

	key = 2211;
	fflush(stdin);
	if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shm = shmat(shmid, NULL, 0)) == (int*) -1)
		die("shmat");
    


        int n=*shm;
        printf("\nThe Number written by first program is %d .\n",n);
        *shm='r';
        *(shm+1)='e';
        *(shm+2)='a';
        *(shm+3)='d';
        *(shm+4)='y';


        while(*shm!='*')
        sleep(1);
       for(int i=1;i<=11;i++)
       {
           while(*shm!='*')
           sleep(1);
      
           *shm=i*n;
        }
	*shm = 'e';
	printf("\n");
	exit(0);

}
