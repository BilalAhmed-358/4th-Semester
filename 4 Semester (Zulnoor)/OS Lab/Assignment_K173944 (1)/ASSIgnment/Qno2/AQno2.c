#include<stdio.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int temp=0;
int main(void)
{
	temp = get_pid();
	printf("Process 1 is created and it is waiting \n");
	int pid_0,pid_1,pid_2,pid_3,pid_4;
	pid_0=fork();		//  Process 2 is created;
	
	if(pid_0 > 0)
	{	pid_1 = fork();		    //Process 3 is created by 1;
		if(pid_1 == 0)
		printf("\n\nProcess 3 is created and is sleep\n\n");

		if(pid_0 > 0 && pid_1 > 0)
		{	
			pid_2 = fork();		         //Process 4 is created by 1;	
			if(pid_2 == 0)
				printf("\n\nProcess 4 is created and execute file_a.sh\n\n");
			
		}
		else
		{ 	
			printf("\n\nProcess 6 is created by C\n\n");	
			pid4=fork();	//process 6 is created by 3		
		}	   	
				
	}
	else		
	{	
		printf("\n\nProcess 2 is created \n\n");
		pid_3=fork();			// Process 5  is created by 2 
		if(pid_3==0)			
		printf("\n\nProcess 5 is created \n\n");
	}
	
	
	if(pid_0 > 0 && pid_1 > 0 && pid_2 > 0)
	{
		
		wait(NULL);
	}
	 if(pid_0 == 0 && pid_3 > 0)
	{
		execl("/bin/bash","/bin/bash","maths.sh","12","2",(char*)0);


	}
	 if(pid_1 == 0 && pid_4 >0)
	{	
	
	wait(NULL);
	
	}
	 if(pid_2 == 0)
	{	
		
		execl("/bin/bash","/bin/bash","file_1.sh",(char*)0);
		
				
	}
	sleep(5);
	 if(pid_0 == 0 && pid_3 == 0)	
	{

	fflush(stdin);
	system("ifconfig | grep ether");  
	printf("\n");			// sudo apt install net-tools	
	system("date");
	
	}
 if(pid_1 == 0 && pid_4 == 0)	
	{
	printf("The grand parent pid of 6 is %d\n",a);
	printf("\n\n");
	system("date");
	}

			
	return 0;
}

