//Exec command practical example.

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>  

int main()
{
	int id=fork();
	//child process, will able to create myFifo file.
	if(id == 0)
	{
		execlp("mkfifo", "mkfifo", "myFifo", NULL);
		printf("This contain will not be print in console!");
	}
	//parent process, will continue its execution after child completion
	else
	{
		wait(NULL);
		printf("Success!");
	}
	return 0;
}
