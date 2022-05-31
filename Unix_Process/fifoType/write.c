//write the array contains into the FIFO file, and another file will read the contains from file and print the sum of total values.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<errno.h>

int main()
{
	int arr[5]={1,2,3,4,5};
	if(mkfifo("myFifo.txt", 0777)==-1)
	{
		if(errno != EEXIST)
		{
			printf("not able to create the myFifo file.\n");
			return 1;
		}
	}

	int fd=open("myFifo.txt", O_WRONLY);
	if(write(fd, arr, sizeof(int)*5) == -1)
	{
		printf("not able to write into file.\n");
                return 2;
	}
	close(fd);
	return 0;
}
