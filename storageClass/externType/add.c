#include<stdio.h>

extern int x;
void fun()
{
	x=10;
	printf("value is: %d", x);
}
