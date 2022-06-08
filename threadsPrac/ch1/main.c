#include<stdio.h>
#include<pthread.h>

#define NTHREADS 10

pthread_mutex_t lock;
int counter = 0;

void* func1(void* data)
{
	int *x = (int *) data;

	pthread_mutex_lock( &lock ); 
	counter++;
	printf("message is %d, and counter: %d\n", *x, counter);
	pthread_mutex_unlock( &lock );
}

int main(void)
{
	pthread_t thread_id[NTHREADS];
	int values[NTHREADS];

	for(int i=0; i < NTHREADS; i++) 
	{
		values[i] = i;
		pthread_create( &thread_id[i], NULL, func1, &values[i]);
	}

	for(int j=0; j < NTHREADS; j++) 
	{
		pthread_join( thread_id[j], NULL); 
	}

	pthread_mutex_destroy(&lock);
	return 0;
}

