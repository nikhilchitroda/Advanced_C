/*
 *	Compile: gcc main.c -lpthread
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//pthread_t, its predefined data-type
pthread_t pthread1;

void* funHandler(void *arg)
{
	printf("Inside of function handler!\n");
	int value= *(int *)arg;
	free(arg);
	int *ptr=(int *)malloc(sizeof(int)*1);
	*ptr= value*value;
	printf("Ptr contains: %d!\n", *ptr);
	return (void *)ptr;
}

void createThread(pthread_t* pthread_handle, int num)
{
	int rc=0;

	//pthread_attr_t, its structure
	pthread_attr_t attr;

	//initializes the thread attributes object pointed to by attr, with default attribute values.
	pthread_attr_init(&attr);

	//create the joinable thread
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	//create the varible inside HEAP memory
	int *nPtr = malloc(sizeof(int)*1);
	*nPtr=num;

	//create the joinable thread 
	rc = pthread_create(pthread_handle, &attr, funHandler, (void *)nPtr);
	if(rc != 0)
	{
		printf("Error, while creating the thread!\n");
		exit(1);
	}
}

int main()
{
	void* status=NULL;

	//user-defind function created	
	createThread(&pthread1, 9);

	//join the joinable thread & then continue main thread execution
	int rc = pthread_join(pthread1, &status);
	if(rc != 0)
	{
		printf("Error, while joining the thread!\n");
		return 1;
	}
	if(status!=NULL)
	{
		int value=*(int *)status;
		free(status);
		printf("value is: %d\n",value);
	}	
	return 0;
}
