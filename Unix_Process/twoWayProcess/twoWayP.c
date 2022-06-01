//create two way communication between the child & parent process.
//
//1. c -> p: child write number to parent using pipe1
//2. parent will read number & multiply by 5 
//3. p -> c: parent write number to child using pipe2
//4. child will read number & print to console

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
	int num=5, readP1=0, readP2=0, writeP2=0;
	int fd1[2], fd2[2];

	//create two pipe for two way process communication
	if(pipe(fd1)==-1)
        {
                printf("Error, while opening pipe1.\n");
                return 1;
        }
	if(pipe(fd2)==-1)
        {
                printf("Error, while opening pipe2.\n");
                return 2;
        }

	int id=fork();
	if(id == -1)
	{
		printf("Not able to create process using fork\n");
		return 3;
	}

	//inside of child process
	if(id == 0)
	{
		close(fd1[0]);
		close(fd2[1]);
		write(fd1[1], &num, sizeof(int));
		printf("written number: %d\n", num);
		read(fd2[0], &readP2, sizeof(int));
		printf("read from pipe2: %d\n", readP2);
		close(fd1[0]);
                close(fd2[1]);
	}
	//inside of parent process
	else
	{
		close(fd1[1]);
                close(fd2[0]);
                read(fd1[0], &readP1, sizeof(int));
                printf("read from pipe1: %d\n", readP1);
		writeP2=readP1 * 5;
		write(fd2[1], &writeP2, sizeof(int));
		printf("written number to pipe2: %d\n", writeP2);
                close(fd1[0]);
                close(fd2[1]);
	}
	return 0;
}
