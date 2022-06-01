//Ask question to user, and ..
//1. if user didn't sent answer within 5sec then, process will terminate.
//2. wrong answer will terminate the process
//3. interrupt signal will terminate the process.

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<time.h>
#include<unistd.h>

int score = 0;

void handle_alarm(int sig)
{
	if(sig == SIGALRM)
	{
		printf("\nTimes up!\n");
		printf("\nFinal score: %d\n", score);
		exit(0);
	}
}
void handle_int(int sig)
{
	if(sig == SIGINT)
	{
		printf("\nFinal score: %d\n", score);
		exit(0);
	}
}
void create_sigAction(int sig, void (*handler)(int))
{
	struct sigaction action;
	action.sa_handler=handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction (sig, &action, NULL);
}

int main()
{
	create_sigAction(SIGALRM, handle_alarm);
	create_sigAction(SIGINT, handle_int);

	int a=0, b=0, sum=0;
	srand(time(NULL));

	while(1)
	{
		a=rand()%11;
		b=rand()%11;

		alarm(5);

		printf("Multiplication of %d and %d:",a, b);
		scanf("%d", &sum);

		if((a*b)!=sum)
		{
			printf("Wrong answer!\n");
			break;
		}
		else
		{
			printf("Correct answer..\n");
			score++;
		}
	}
	printf("\nYour score is: %d\n", score);
	return 0;
}
