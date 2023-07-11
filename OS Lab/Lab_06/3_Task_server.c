#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAXSIZE 100

void die(char *str)
{
	perror(str);
	exit(1);
}
int main()
{
	char c;
	int shmid;
	key_t key;
	char *shm, *s;
	key = 2211;

	if ((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
	{
		printf("There was an error in 1.\n");
		exit(0);
	}
	if ((shm = shmat(shmid, NULL, 0)) == (char *)-1)
	{
		printf("There was an error.\n");
		exit(0);
	}
	s = shm;
	*s = '9';
	while (strcmp(shm, "ready") != 0)
	{
		sleep(1);
	}
	printf("ready\n");
	*shm = '*';
	while (*shm != '*')
	{
		sleep(1);
		putchar(*shm);
		printf("\n");
	}
	*shm = '*';
}