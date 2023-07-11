#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAXSIZE 27

void die(char *str)
{
    perror(str);
    exit(1);
}

int main(void)
{
    int shmid, num, n = 5;
    key_t key;
    char *shm, *s;

    key = 2211;
    fflush(stdin);
    if ((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
        die("shmget");
    if ((shm = shmat(shmid, NULL, 0)) == (char *)-1)
        die("shmat");
    s = shm;
    putchar(*s);
    num = (int)(*s);
    *shm = '*';
    strcpy(shm, "ready");
    printf("\n");
    while (*shm != '*')
    {
        sleep(1);
    }
    printf("star received.\n"); 
    exit(0);
}
