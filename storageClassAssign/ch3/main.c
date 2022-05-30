#include<stdio.h>

//create variable that shared amongest two files
float sharedVar = 5.6f;

//gloable variable for loop counter
int loopC = 5;

void displayFunc();

int main()
{
	//iterate the loop for 5times
	for(loopC=0; loopC<5; loopC++)
	{
		displayFunc();
	}
	return 0;
}
