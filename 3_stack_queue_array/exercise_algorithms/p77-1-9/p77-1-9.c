#include <stdio.h>
#define maxSize 999999

int BaseTrans(int N)
{
	int stack[maxSize], top = -1;

	while (N != 0)
		{
			stack[++top] = N % 2;
			N = N / 2;
		}

	printf("The binary form of this number:\n");
	while (top != -1)
		{
			printf("%d", stack[top]);
			--top;
		}
	
	printf("\n");

	return 1;
}


int main(int argc, char *argv[])
{
	int N;
	printf("Please input a number:\n");
	scanf("%d", &N);

	BaseTrans(N);
		
	return 0;
}
