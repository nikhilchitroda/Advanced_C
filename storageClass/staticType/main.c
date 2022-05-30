#include<stdio.h>

int table(int value)
{
	static int num=0;
	num = num + value;
	return num;
}

int main()
{
	int value=0, add=0;
	printf("No to find mulitplication table: ");
	scanf("%d", &value);
	for(int count=1; count<=10; count++)
	{
		printf("%d * %d = %d\n", value, count, table(value));
	}
}
