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
        int id1=fork();
	int id2=fork();

	//inside of id1 as child
	if(id1==0)
	{
		if(id2==0)
		{
			printf("id1=%d and id2=%d\n", id1, id2);
		}
		else
		{
			printf("id1=%d and id2=%d\n", id1, id2);
		}
	}
	//inside of id1 as parent
	else
	{
		if(id2==0)
		{
			printf("id1=%d and id2=%d\n", id1, id2);
		}
		else
		{
			printf("id1=%d and id2=%d\n", id1, id2);
		}
	}
	return 0;
}
