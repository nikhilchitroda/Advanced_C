#include<stdio.h>

void addNum(int value)
{
	static int num=0;
	num = num + value;
	printf("%d ", num);
}

int main()
{
	addNum(25);
	addNum(15);
	addNum(30);
}
