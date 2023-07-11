#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#define Max_car 4
// max 3 cars can use a lane at a point
sem_t mutex;

void clrscr()
{
    system("@cls||clear");
}
void *thread(void *arg)
{
	sem_wait(&mutex);
	printf("Currently %d car(s) using the lane.\n", *(int*)arg);
	sleep(2* *(int*)arg);
	printf("Lane clear.\n");
	sleep(1);
	sem_post(&mutex);
}

int main()
{
	int route;
	sem_init(&mutex, 0, 1);
	// creating a semaphore
	pthread_t t1, t2;
	// creating 2 roads in the form of threads i.e. North-to-South and East-to-West
	printf("Enter 1 for East-to-West or 2 for North-to-South.\nOr any other value to exit\n");
	fflush(stdin);
	scanf("%d", &route);
	if (route == 1)
	{
		// East-to-West route engaged
		printf("Engaging the East-to-West lane.\n");
		int* car_no = malloc(sizeof(int)); 
		*car_no= rand()%Max_car;
		pthread_create(&t1, NULL, thread, car_no);
		pthread_join(t1, NULL);
	}
	else if (route == 2)
	{
		// North-to-South route engaged
		printf("Engaging the North-to-South lane.\n");
		int* car_no = malloc(sizeof(int)); 
		*car_no= rand()%Max_car;
		pthread_create(&t2, NULL, thread, car_no);
		pthread_join(t2, NULL);
	}
	else
	{
		sem_destroy(&mutex);
		printf("Choose a valid option and re-engage the traffic system.\nExiting program...\n");
		sleep(2);
		exit(1);
	}

	sem_destroy(&mutex);
	// clrscr();
	main();
	return 0;
}
