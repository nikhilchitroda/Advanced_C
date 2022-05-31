//Print first five number using child process &
//next five numbers using parent process.

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	int num = 0;

	//create new process
        int id=fork();
	if(id == 0)
	{
		num = 0;
	}
	else
	{
		//wait for child process to terminate & then start parent process.
		wait(NULL);
		num = 5;
	}
	
	//loop iteration
	for(int i=1; i<6; i++)
	{
		printf("%d", num + i);
	}
	
	//if parent process then add new line
	if(id != 0)
	{
		printf("\n");
	}

	return 0;
}
