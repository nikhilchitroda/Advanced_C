#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mLock;

int a=5;
char *str="name is, nikhil!";

void* funHand(void *arg)
{
	char *ptr=(char *)arg;
	printf("string is: %s\n", ptr);
	pthread_mutex_lock(&mLock);
	printf("a value before inc: %d\n", a);
	a++;
	printf("a value after inc: %d\n", a);
	pthread_mutex_unlock(&mLock);
	pthread_exit((void *)ptr);
}

int main()
{
	pthread_t th1;
	void *status=NULL;

	pthread_create(&th1, NULL, funHand, (void *)str);

	pthread_join(th1, &status);
	printf("string from main: %s\n", (char *)status);

	pthread_mutex_destroy(&mLock);
	return 0;
}
