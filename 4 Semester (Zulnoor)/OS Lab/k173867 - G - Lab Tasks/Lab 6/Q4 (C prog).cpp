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
	int shmida,shmidb;
	key_t keya,keyb;
	long long int *shma,*shmb;

	keya = 2211;
	
	if((shmida = shmget(keya, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shma = shmat(shmida, NULL, 0)) == (long long int*) -1)
		die("shmat");

	keyb = 2233;
	
	if((shmidb = shmget(keyb, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shmb = shmat(shmidb, NULL, 0)) == (long long int*) -1)
		die("shmat");
  
	long long int a,b,sum,n=rand()%100;
        printf("%d th fibonacci number is %lld .\n%d th fibonacci number is %lld .\n",1,*shma,2,*shmb);

         for(int i=0;i<n;i++)
	 {

            a=*shma;
            b=*shmb;
            sum=a+b;
            *shma=*shmb;
            *shmb=sum;
            printf("%d th fibonacci number is %lld .\n",i+3,sum);    

	 }

         *shma='*';
         *shmb='*';
         printf("\n");

         exit(0);

}
