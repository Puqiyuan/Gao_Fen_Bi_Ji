/*
  Test result:
  pqy7172@debian:~/.../58_1$ ls
  a.out*  p58_1  p58_1.c
  pqy7172@debian:~/.../58_1$ gcc p58_1.c 
  pqy7172@debian:~/.../58_1$ ./a.out 
  1
  pqy7172@debian:~/.../58_1$ 
  [pqy7172@debian:0] 0:ss-local 1:bash                               0.16 100% Tue 2017-07-18 10:17
 */

#include <stdio.h>
#include <stdlib.h>				
#define maxSixe 100


typedef struct
{
	int data[maxSixe];
	int top;
	
}SqStack;


int initStack(SqStack *st)
{
	st -> top = -1;

	return 1;
}


int main(int argc, char *argv[])
{
	SqStack st;

	printf("%d\n", initStack(&st));

	return 0;
}

