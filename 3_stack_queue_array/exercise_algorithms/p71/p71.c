/*
  Test result:

  pqy7172@debian:~/.../p71$ make               
  gcc -Wall p71.c -o test  
  ./test
  Test for InitStack:         
  Init stack: OK, bottom1: -1, bottom2: 10.                                       

  Test for push operation:                                       
  push element 0: OK.                                                             
  push element 1: OK.     
  push element 2: OK.     
  push element 3: OK.     
  push element 4: OK.     
  push element 5: OK.     
  push element 6: OK.     
  push element 7: OK.     
  push element 8: OK.     
  push element 9: OK.     
  Sorry the stack is full.

  Test for pop operation: 
  Pop element 0 of stack 0: OK, value: 8.         
  Pop element 1 of stack 1: OK, value: 9.         
  Pop element 2 of stack 0: OK, value: 6.
  Pop element 3 of stack 1: OK, value: 7.
  Pop element 4 of stack 0: OK, value: 4.
  Pop element 5 of stack 1: OK, value: 5.
  Pop element 6 of stack 0: OK, value: 2.
  Pop element 7 of stack 1: OK, value: 3.
  Pop element 8 of stack 0: OK, value: 0.
  Pop element 9 of stack 1: OK, value: 1.
  The stack 0 is empty.
  pqy7172@debian:~/.../p71$
  [pqy7172@debian:0] 0:less 1:[tmux]                                  0.54 71% Thu 2017-08-03 11:15
 */


#include <stdio.h>
#include <stdlib.h>

#define maxSize 10

typedef struct
{
	int elem[maxSize];
	int top[2];
}SqStack;


int InitStack(SqStack *st)
{
	st -> top[0] = -1;
	st -> top[1] = maxSize;

	return 1;
}


int push(SqStack *st, int stNo, int x)
{
	if (st -> top[0] + 1 < st -> top[1])
		{
			if (stNo == 0)
				{
					++(st -> top[0]);
					st -> elem[st -> top[0]] = x;
					return 1;
				}

			else if (stNo == 1)
				{
					--(st -> top[1]);
					st -> elem[st -> top[1]] = x;
					return 1;
				}
			
			else
				return -1;
		}

	return 0;
}


int test_push(SqStack *st)
{
	int x[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, i, flag, stNo;
	
	for (i = 0; i <= 10; i++)
		{
			if (i % 2 == 0)
				stNo = 0;
			else
				stNo = 1;

			flag = push(st, stNo, x[i]);

			if (flag == 1)
				{
					printf("push element %d: OK.\n", x[i]);
					continue;
				}
			
			else if (flag == -1)
				{
					printf("Sorry your stNo is wrong.\n");
					break;
				}

			else if (flag == 0)
				{
					printf("Sorry the stack is full.\n");
					break;
				}
		}

	printf("\n");

	return 1;
}


int pop(SqStack *st, int stNo, int *x)
{
	if (stNo == 0)
		{
			if (st -> top[0] != -1)
				{
					*x = st -> elem[st -> top[0]];
					--(st -> top[0]);
					return 1;
				}
			else
				return 0;
			
		}
	else if (stNo == 1)
		{
			if (st -> top[1] != maxSize)
				{
					*x = st -> elem[st -> top[1]];
					++(st -> top[1]);
					return 1;
				}
			else
				return 0;
		}

	return -1;
}


int test_pop(SqStack *st)
{
	int *x = (int*)malloc(sizeof(int));
	int i, stNo, flag;

	for (i = 0; i <= 10; i++)
		{
			if (i % 2 == 0)
				stNo = 0;
			else
				stNo = 1;

			flag = pop(st, stNo, x);

			if (flag == 1)
				{
					if (stNo == 0)
						{
							printf("Pop element %d of stack 0: OK, value: %d.\n", i, *x);
							continue;
						}
					else if (stNo == 1)
						{
							printf("Pop element %d of stack 1: OK, value: %d.\n", i, *x);
							continue;
						}
					
				}

			else if (flag == 0)
				{
					if (stNo == 0)
						printf("The stack 0 is empty.\n");

					else if (stNo == 1)
						printf("The stack 1 is empty.\n");
				}

			else
				printf("The stNo is wrong.\n");
				
		}

	return 1;
}


int main(int argc, char *argv[])
{
	SqStack st;

	printf("Test for InitStack:\n");
	InitStack(&st);
	printf("Init stack: OK, bottom1: %d, bottom2: %d.\n\n",
	       st.top[0], st.top[1]);

	printf("Test for push operation:\n");
	test_push(&st);

	printf("Test for pop operation:\n");
	test_pop(&st);
	
	return 0;
}
