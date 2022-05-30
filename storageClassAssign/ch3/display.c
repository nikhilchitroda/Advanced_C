#include<stdio.h>
extern int loopC;

extern void displayFunc()
{
	printf("count is: %d\n", loopC+1);
}
