#include <pthread.h>
#include <stdio.h>

/* This is our thread function.  It is like main(), but for a thread*/
void *threadFunc(void *arg)
{
	char *str;
	int i = 0;

	str=(char*)arg;

	while(i < 110 )
	{
		usleep(1);
		printf("threadFunc says: %s at step %d\n", str, i);
		++i;
	}

	return NULL;
}

int main(void)
{
	pthread_t pth;	// this is our thread identifier
	int i = 0;

	pthread_create(&pth,NULL,threadFunc,"foo");
	
	while(i < 100)
	{
		usleep(1);
		printf("at step %d main is running...\n", i);
		++i;
	}

	printf("main waiting for thread to terminate...\n");
	pthread_join(pth,NULL);

	return 0;
}

