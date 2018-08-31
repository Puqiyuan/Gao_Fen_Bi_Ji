/*
  Test result:
  pqy7172@debian:~/.../58_3$ ls
  a.out*  p58_3  p58_3.c
  pqy7172@debian:~/.../58_3$ gcc p58_3.c 
  pqy7172@debian:~/.../58_3$ ./a.out 
  After push 5 and 3:
  3 5 
  After push 5, 3, and 10
  10 3 5 
  pqy7172@debian:~/.../58_3$ 
  [pqy7172@debian:0] 0:ss-local 1:bash                               0.27 100% Tue 2017-07-18 11:40
 */


#include <stdio.h>
#include <stdlib.h>                                                              
#define maxSize 100


typedef struct          
{
        int data[maxSize];
        int top;      
}SqStack;


int initStack(SqStack *st)
{
	st -> top = -1;

	return 1;
}


int display(SqStack st)
{
	int index = st.top;

	for (; index >= 0; index--)
		printf("%d ", st.data[index]);

	printf("\n");

	return 1;
}


int push(SqStack *st, int x)
{
	if (st -> top == maxSize - 1)
		return 0;

	++(st -> top);
	st -> data[st -> top] = x;

	return 1;
}


int main(int argc, char *argv[])
{
	SqStack st;
	int x = 5;
	
	initStack(&st);

	push(&st, x);

	x = 3;
	push(&st, x);
	
	printf("After push 5 and 3:\n");
	display(st);

	x = 10;
	push(&st, x);
	printf("After push 5, 3, and 10\n");
	display(st);
		
	return 0;
}
