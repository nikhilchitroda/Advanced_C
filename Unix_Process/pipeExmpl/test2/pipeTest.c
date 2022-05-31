//calculate sum of half array from child process and write its value into pipe, 
//And another half array sum to be calculate & add its value into the read value from pipe.

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>  

int main()
{
	int sum=0, num=0,start=0, end=0, fd[2], id=0, arr[7]={1,2,3,4,5};
	int arrSize= sizeof(arr)/sizeof(int);

	if(pipe(fd)==-1)
	{
		printf("Error, while opening pipe.\n");
		return 1;
	}

	id=fork();
	if(id == -1)
	{
		printf("Not able to fork process");
		return 2;
	}

	if(id == 0)
	{
		start=0;
		end=arrSize/2;
	}
	else
	{
		wait(NULL);
		start=arrSize/2;
		end=arrSize;
	}

	for(int i=start; i<end; i++)
	{
		sum = sum + arr[i];
	}

	if(id==0)
	{
		close(fd[0]);
		write(fd[1], &sum, sizeof(int));
		printf("added sum value from child process: %d\n", sum);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		read(fd[0], &num, sizeof(int));
		printf("added sum value from parent process: %d\n", sum);
		sum = sum + num;
		printf("total sum of an array is: %d\n", sum);
		close(fd[0]);
	}
	return 0;
}
