/*
  Test result:
  pqy7172@debian:~/.../59_1$ ls
  a.out*  p59_1  p59_1.c
  pqy7172@debian:~/.../59_1$ gcc p59_1.c 
  pqy7172@debian:~/.../59_1$ ./a.out 
  After push 5 and 3:
  3 5 
  After push 5, 3, and 10
  10 3 5 
  The first time pop:
  10
  The second time pop:
  3
  The third time pop:
  5
  The stack is empty.
  pqy7172@debian:~/.../59_1$ 
  [pqy7172@debian:0] 0:ss-local 1:bash                               0.16 100% Tue 2017-07-18 12:03
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


int isEmpty(SqStack st) 
{                       
        if (st.top == -1)                       
                return 1;                       

        return 0;       
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


int pop(SqStack *st, int *x)
{
	if (st -> top == -1)
		{
			printf("underflow\n");
			return 0;
		}

	*x = st -> data[st -> top];

	--(st -> top);

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

	pop(&st, &x);
	printf("The first time pop:\n");
	printf("%d\n", x);

	pop(&st, &x);
	printf("The second time pop:\n");
	printf("%d\n", x);

	pop(&st, &x);
	printf("The third time pop:\n");
	printf("%d\n", x);

	if (isEmpty(st))
		printf("The stack is empty.\n");

	else
		printf("The stack is not empty.\n");
	
	return 0;
}
