//This file will read the contains from FIFO file and print the sum of total values.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<errno.h>

int main()
{
	int sum =0, numA[5];

	int fd=open("myFifo.txt", O_RDONLY);
	if(read(fd, numA, sizeof(int)*5) == -1)
	{
		printf("not able to read from file.\n");
                return 1;
	}
	
	for(int i=0; i<5; i++)
		sum = sum + numA[i];
	printf("Total sum is: %d\n", sum);

	close(fd);
	return 0;
}
