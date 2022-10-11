#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define LEFT (num + 4) % 5
#define RIGHT (num + 1) % 5

enum {EATING, HUNGRY, THINKING} state[5];
int arr[] = {0, 1, 2, 3, 4};

sem_t phil[5];

void test(int num)
{
	if (state[num] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
		state[num] = EATING;
	 	
		sleep(1);
	 	
		printf("Philosopher %d takes chopsticks %d and %d\n",
		              num + 1, num, num + 1);
	 
		printf("Philosopher %d is eating\n", num + 1);
		sem_post(&phil[num]);
	}
}

void take_chopstick(int num)
{
	
	state[num] = HUNGRY;
	
	printf("Philosopher %d is hungry\n", num + 1);
	
	test(num);
 	
	sem_wait(&phil[num]);
}

void put_chopstick(int num)
{
	
	state[num] = THINKING;
	
	printf("Philosopher %d puts chopticks %d and %d down\n", num + 1, num, num + 1);
	
	printf("Philosopher %d is thinking\n", num + 1);
	
	test(LEFT);
	
	test(RIGHT);
}

void* philosopher(void* i)
{
	printf("Philosopher %d is thinking\n", *((int*) i) + 1);
			
	while (1) {
		sleep(1);
		
		take_chopstick(*((int*) i));
		
    		sleep(1);
		        
        	put_chopstick(*((int*) i));
	}
}

void main()
{
	printf("Consider 5 philosophers and 5 chopsticks\n");
	pthread_t tid[5];
	for (int i=0; i<5; i++)
		sem_init(&phil[i], 0, 0); 
	for (int i=0; i<5; i++)
		pthread_create(&tid[i], NULL, philosopher, &arr[i]);
	for (int i=0; i<5; i++)
    		pthread_join(tid[i], NULL);
    for (int i=0; i<5; i++)
        sem_destroy(&phil[i]);
}