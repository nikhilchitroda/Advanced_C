#include<stdio.h>

//globle variable accessible only inside this file
static double var=6;

//accessible inside the program
float value=5.6f;

//accessible inside this file only
static void print()
{
	printf("hello world!");
}

int main()
{
	//permenant variable with float type
	static float permStorage = 1.2f;

	//register int value
	register int rValue = 2;
	
	//int variable with block scope
	{
		int temp=0;
		printf("temp stored variable: %d", temp);	
	}
	return 0;
}
