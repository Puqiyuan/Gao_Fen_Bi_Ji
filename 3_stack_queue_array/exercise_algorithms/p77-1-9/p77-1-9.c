/*
  Test result:
  pqy7172@debian:~/.../p77-1-9$ make run 
  gcc -Wall p77-1-9.c -o test
  ./test
  Please input a number:
  12
  The binary form of this number:
  1100
  pqy7172@debian:~/.../p77-1-9$ 
  [pqy7172@debian:0] 0:bash                                           0.16 69% Tue 2017-09-05 20:48
 */

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
