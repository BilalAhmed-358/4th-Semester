#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
	char *str = "This is a string\n";
	int id[2];
	if (pipe(id) == -1)
	{
		printf("The pipe couldn't be created, Aborting the program.\n");
		return 0;
	}
	int fork_child = fork();
	if (fork_child == 0)
	{
		close(id[0]);
		char message[100]={"This is a message send by the child.\0"};
		write(id[1],message,sizeof(message));
		close(id[1]);
	}
	else
	{
		wait(NULL);
		close(id[1]);
		char read_message[100];
		read(id[0],read_message,sizeof(read_message));
		printf("%s\n",read_message);
		close(id[0]);
	}
}
