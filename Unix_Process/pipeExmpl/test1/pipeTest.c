//write value to pipe from child process, and read value from pipe by using parent process.

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>  

int main()
{
	int value=0, fd[2], num=0; //fd[0]=read, fd[1]=write

	if(pipe(fd)==-1)
	{
		printf("Error, while creating pipe.\n");
		return -1;
	}
        
	int id=fork();
	//child process, write some data to pipe
	if(id == 0)
	{
		close(fd[0]);
		printf("Enter data to write into pipe: ");
		scanf("%d", &value);
		write(fd[1], &value, sizeof(int));
		close(fd[1]);
	}
	//parent process, read data from pipe, and multiply its value by 3.
	else
	{
		wait(NULL);
		close(fd[1]);
		read(fd[0], &num, sizeof(int));
		printf("read value from pipe(with *3): %d\n", num*3);
		close(fd[0]);
	}
	return 0;
}
