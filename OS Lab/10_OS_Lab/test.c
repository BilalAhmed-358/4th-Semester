#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>
int state = 1;
void signal_handler(int NUM)
{
	int num;
	if (state == 1)
	{
		printf("Enter Number: ");
		scanf("%d", &num);
		for (int i = 1; i <= 10; i++)
		{
			printf("%d * %d = %d\n", num, i, num * i);
		}
		state = 2;
	}
	else if (state == 2)
	{
		printf("\nIGNORING\n");
		signal(SIGINT, SIG_IGN);
		state = 3;
	}
	else if (state == 3)
	{
		int power = num * num;
		printf("\n");
		for (int i = 1; i <= 10; i++)
		{
			printf("%d * %d = %d\n", power, i, power * i);
		}
		state = 4;
	}
	else if (state == 4)
	{
		printf("\nDEFAULT STATE\n");
		signal(SIGINT, SIG_DFL);
		state = 5;
	}
	else if (state == 5)
	{
		signal(SIGINT, SIG_DFL);
	}
}
int main()
{
	signal(SIGINT, signal_handler);
	while (1)
	{
		sleep(1);
		if (state == 3)
			signal(SIGINT, signal_handler);
	}
	return 0;
}