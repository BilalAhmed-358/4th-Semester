#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(void) {
	int pipefd[2],pipefd1[2];
	int pid;
	char buffer[32],buffer1[32];
	pipe(pipefd);
	pipe(pipefd1);
	pid = fork();

	if(pid > 0) {
		fflush(stdin);
		printf("unamed_pipe [INFO] Parent Process\n");
		write(pipefd[1],"msg is sent from parent to child",32);
		sleep(5);
		fflush(stdin);		
		read(pipefd1[0],buffer1,32);
		write(1,buffer1,32);
		printf("\n\n");
	}
	else if(pid == 0) {
		sleep(5);
		fflush(stdin);
		printf("unamed_pipe [INFO] Child Process\n");
		read(pipefd[0], buffer, sizeof(buffer));
		write(1,buffer, sizeof(buffer));
		printf("\n");
		fflush(stdin);
		write(pipefd1[1],"msg is sent from child to parent",32);
			
	}
	else {
		printf("unamed_pipe [ERROR] Error in creating child process\n");	
	}
	if(pid > 0) wait(NULL);
	return 0;
}
	
