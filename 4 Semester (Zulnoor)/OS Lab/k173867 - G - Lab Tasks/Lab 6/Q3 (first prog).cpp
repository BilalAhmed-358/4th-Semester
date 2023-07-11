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
	
	if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shm = shmat(shmid, NULL, 0)) == (int*) -1)
		die("shmat");

	
       int num=rand()%1000;       

        *shm=num;
         
        while(*shm==num)
        sleep(1);

        for(int i=0;i<5;i++)
        printf("%c",*(shm+i));
        printf("\n\n\n");


        *shm='*';

        while(*shm!='e')
        {
          
           if(*shm=='*')
           sleep(1);
           if(*shm=='e')
           break;
           printf("%d\n",*shm);
           *shm='*';
         }

	exit(0);

}
